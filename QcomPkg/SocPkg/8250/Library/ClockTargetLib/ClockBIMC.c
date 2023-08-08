/**
==============================================================================

  @file ClockBIMC.c

  This file provides clock BIMC/DDR settings.

  Copyright (c) 2016-2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================


==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockBIMC.c#8 $

  when      who     what, where, why
  --------  ------  ------------------------------------------------------
  11/11/16  vphan   Initial SDM845 revision, branched from MSM8998.

==============================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include "ClockBoot.h"
#include "HALclkHWIO.h"
#include "ClockBSP.h"
#include "ClockBSPExtern.h"
#include "ClockDriver.h"
#include "ddr_drivers.h"
#include "ddr_common.h"
#include "railway.h"
#include "boot_util.h"
#include "busywait.h"
#include "pm_smps.h"
#include "pm_version.h"

/*=========================================================================
      Macro Definitions
==========================================================================*/
#define CLOCK_ERROR -1
#define CLOCK_XO_FREQ_KHZ 19200

/*
 * HALF_DIVIDER
 *
 * Macro to return the normalized half divider for a given mux structure.
 * NOTE: Expecting (2 * divider) value as input.
 */
#define HALF_DIVIDER(mux)  ((mux)->nDiv2x ? (((mux)->nDiv2x) - 1) : 0)

#define PMIC_VDDQ PMIC_C
#define PMIC_VDDQ_SMPS PM_SMPS_7


/*=========================================================================
      Function Prototypes
==========================================================================*/

/*=========================================================================
      Data
==========================================================================*/

static uint32 nMaxDDRLevels = 0;

static FREQ_STATE* pMCCfg = NULL;
static vddq_state* pVddqCfg = NULL;

/* The current rate of the DRR clock in kHz */
static uint32 nDDRSpeedKHz = 200000;
static uint8 nDDRCurrDomain = 0;
static uint8 nDDRNextDomain = 1;

/*
 * Clock configure performance levels for inform AOP during initialize
 */
extern ClockCfgCPType Clock_PerfData;

typedef struct ClockDDRDomain
{
  ClockDomainNodeType *pDomain;
  uint32               nCBCRAddr;
} ClockDDRDomainType;

static ClockDDRDomainType Clock_DDRDomains[2] =
{
  { &ClockDomain_GCC_GCCDDRMCCH0ROOT, HWIO_GCC_DDRMC_CH0_CBCR_ADDR },
  { &ClockDomain_GCC_GCCDDRMCCH1ROOT, HWIO_GCC_DDRMC_CH1_CBCR_ADDR },
};


/*=========================================================================
      Function Definitions
=========================================================================*/

/* ============================================================================
**  Function : Clock_MapCorner
** ============================================================================
*/
/**
  Due to memory constraint, we cannot use voltage code in MC/SHUB table.
  This driver is used for convert voltage corner to railway corner

  @params
     rail - VOLTAGE_RAIL value
  @return
    railway corner value

  @dependencies
    None.

  @sa
    None
*/
railway_corner Clock_MapCorner( VOLTAGE_RAIL rail )
{
  switch (rail)
  {
    case VDD_RET:   return RAILWAY_RETENTION;
    case MIN_SVS:   return RAILWAY_SVS_MIN;
    case LOW_SVS:   return RAILWAY_SVS_LOW;
    case SVS:       return RAILWAY_SVS;
    case SVS_L1:    return RAILWAY_SVS_HIGH;
    case NOMINAL:   return RAILWAY_NOMINAL;
    case TURBO:     return RAILWAY_TURBO;
    case TURBO_L1:  return RAILWAY_SUPER_TURBO;
    default:        return RAILWAY_NO_REQUEST;
  };
}

/* =========================================================
**  Function : Clock_DDRSpeed()
** =======================================================*/
/* 
 * @param None
 * @return The clock rate of DDR in kHz
 */
uint32 Clock_DDRSpeed()
{
  return nDDRSpeedKHz;
}


/* =========================================================================
**  Function : Clock_FindBIMCLevel
** =========================================================================*/
/*!
    Find the table line that meets or exceeds the request.

    @param -  nFreqHz [in] Frequency to search for in the table
    @param -  pConfigTable [in] Table to search
    @param -  nTableLimit [in] Length of table 
    @return - index to the table row to be used.

    @dependencies
    None.

    @sa None
*/
uint32 Clock_FindBIMCLevel
( 
  uint32 nFreqKHz,
  FREQ_STATE *pDDRConfig
)
{
  uint32 index;

  /* Start with index-1 since index-0 is for DDR power collapsed */
  for(index = 1; (index < nMaxDDRLevels) && (pDDRConfig[index].freq_khz != 0); index++)
  {
    if( (pDDRConfig[index].freq_enable) && (pDDRConfig[index].freq_khz >= nFreqKHz) )
    {
      return index;
    }
  }

  /* If not found, return index of highest enable clock plan in the table */
  if ( index == nMaxDDRLevels )
  {
    for ( index = nMaxDDRLevels-1; index > 0; index-- )
    {
      if ( pDDRConfig[index].freq_enable == TRUE )
        return index;
    }
  }

  return 0;
}


/* =========================================================================
**  Function : Clock_SetBIMCSpeed
** =========================================================================*/
/*!
    Switch DDR and the related BIMC roots to the requested frequency

    @param -  nFreqHz [in] Frequency to search for in the table
    @return - FALSE on fail, TRUE on success

    @dependencies
    None.

    @sa None
*/
boolean Clock_SetBIMCSpeed(uint32 nFreqKHz )
{
  railway_corner    vdda, vddcx;
  uint32            nCurrKHz, nCurrLvlIdx, nNewLvlIdx; 
  Clock_RailwayType *pClockRailway = Clock_RailwayConfig();
  FREQ_STATE       *pCurrDDRCfg;
  FREQ_STATE       *pNewDDRCfg;
  ClockDDRDomainType *pCurDomain, *pNextDomain;
  pm_err_flag_type pm_status;

  /* Do nothing if Cx or VDDA_EBI railways is not supported */
  if ( (RAIL_NOT_SUPPORTED_BY_RAILWAY == pClockRailway->nCxRailId) ||
       (RAIL_NOT_SUPPORTED_BY_RAILWAY == pClockRailway->nEBIRailId) )
    return TRUE;

  /* Get MC configure data */
  if ( pMCCfg == NULL)
  {
    ddr_clock_plan DDRQuery = ddr_clock_query(MC_CLOCK_PLAN);

    /* Spin in while-loop for error if number of DDR levels is not matching */
    nMaxDDRLevels = DDRQuery.num_levels;
    pMCCfg = DDRQuery.state;
  }

  /* Get VDDQ configuration */
  if (pVddqCfg == NULL)
  {
    ddr_vddq_plan DDRVddqQuery = ddr_clock_query_vddq_plan(VDDQ_CLOCK_PLAN);
    if(nMaxDDRLevels != DDRVddqQuery.num_levels)
    {
      return FALSE;
    }
    pVddqCfg = DDRVddqQuery.vddq_state;
  }

  /* Find current level */
  nCurrKHz = Clock_DDRSpeed();
  nCurrLvlIdx = Clock_FindBIMCLevel ( nCurrKHz, pMCCfg );
  pCurrDDRCfg = &pMCCfg[nCurrLvlIdx];

  /* Find new level */
  nNewLvlIdx = Clock_FindBIMCLevel ( nFreqKHz, pMCCfg );
  pNewDDRCfg = &pMCCfg[nNewLvlIdx];
  nFreqKHz = pMCCfg[nNewLvlIdx].freq_khz;

  /*
   * When transitioning from DDRCC -> GCC, HW requires that we always
   * reset back to CH0.
   */
  if (pCurrDDRCfg->mode == DDRCC && pNewDDRCfg->mode == GCC)
  {
    nDDRCurrDomain = 1;
    nDDRNextDomain = 0;
  }

  /* Find current and next domains. */
  pCurDomain = &Clock_DDRDomains[nDDRCurrDomain];
  pNextDomain = &Clock_DDRDomains[nDDRNextDomain];

  // Change VDDA_EBI rail if increase
  if ( pMCCfg[nCurrLvlIdx].vdda < pMCCfg[nNewLvlIdx].vdda )
  {
    vdda = Clock_MapCorner( pMCCfg[nNewLvlIdx].vdda );
    railway_corner_vote( pClockRailway->EBIVoter, vdda);
    railway_transition_rails();
  }

  if (pVddqCfg[nCurrLvlIdx].vddq < pVddqCfg[nNewLvlIdx].vddq)
  {
    pm_status = pm_smps_volt_level(PMIC_VDDQ,  PMIC_VDDQ_SMPS, pVddqCfg[nNewLvlIdx].vddq, TRUE);
    if (pm_status != PM_ERR_FLAG_SUCCESS)
    {
      return FALSE;
    }
  }

  /* 
   * Vote for higher voltage before the switch if the new frequency is more
   * than the current frequency.
   */
  if ( nCurrKHz < nFreqKHz )
  {
    vddcx = Clock_MapCorner( pMCCfg[nNewLvlIdx].vddcx );
    /* CPU and Buses are running at NOMINAL or higher.  Do not scale voltage below NOMINAL */
    if ( vddcx >= RAILWAY_NOMINAL )
    {
      // Change VDD_CX rail
      railway_corner_vote(pClockRailway->CxVoter, vddcx);
      railway_transition_rails();
    }
  }

  /* Set new frequency on the next (unused) domain. */
  if (pNewDDRCfg->mode == GCC)
  {
    Clock_ToggleClock(pNextDomain->nCBCRAddr, CLK_TOGGLE_ENABLE);
    if (!Clock_SetDomainFreq(pNextDomain->pDomain, nFreqKHz))
    {
      return FALSE;
    }
  }

  /* Trigger switch to new frequency and next domain. */
  ddr_pre_clock_switch( nCurrKHz, nFreqKHz);
  ddr_clock_switch( nCurrKHz, nFreqKHz);
  ddr_post_clock_switch( nCurrKHz, nFreqKHz);

  /* Park old RCG and disable old CBC. */
  if (pCurrDDRCfg->mode == GCC)
  {
    Clock_SetDomainFreq(pCurDomain->pDomain, CLOCK_XO_FREQ_KHZ);
    Clock_ToggleClock(pCurDomain->nCBCRAddr, CLK_TOGGLE_DISABLE);
  }

  /* 
   * Vote for lower voltage after the switch if the new frequency is less
   * than the current frequency.
   */
  if ( nCurrKHz > nFreqKHz )
  {
    /* CPU and Buses are running at NOMINAL or higher.  Do not scale voltage below NOMINAL */
    vddcx = Clock_MapCorner( pNewDDRCfg->vddcx );
    if ( vddcx < RAILWAY_NOMINAL )
    {
      vddcx = RAILWAY_NOMINAL;
    }

    railway_corner_vote(pClockRailway->CxVoter, vddcx);
    railway_transition_rails();
  }

  if (pVddqCfg[nCurrLvlIdx].vddq > pVddqCfg[nNewLvlIdx].vddq)
  {
    pm_status = pm_smps_volt_level(PMIC_VDDQ,  PMIC_VDDQ_SMPS, pVddqCfg[nNewLvlIdx].vddq, TRUE);
    if(pm_status != PM_ERR_FLAG_SUCCESS)
    {
      return FALSE;
    }
  }

  // Change VDDA_EBI rail if decrease
  if ( pMCCfg[nCurrLvlIdx].vdda > pMCCfg[nNewLvlIdx].vdda )
  {
    vdda = Clock_MapCorner( pMCCfg[nNewLvlIdx].vdda );
    railway_corner_vote( pClockRailway->EBIVoter, vdda );
    railway_transition_rails();
  }

  Clock_PerfData.nDDR = nNewLvlIdx;
  nDDRSpeedKHz = nFreqKHz;

  /*
   * Swap the current/next GCC domains.
   */
  if (pNewDDRCfg->mode == GCC)
  {
    nDDRCurrDomain ^= 1;
    nDDRNextDomain ^= 1;
  }

  return TRUE;
}

