/**
==============================================================================
  @file ClockAOP.c

  Clock functions for enable and share data to AOP.

  Copyright (c) 2017,2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================
*/


/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "HALclkHWIO.h"
#include "ClockBSP.h"
#include "ClockBSPExtern.h"
#include "ClockDriver.h"
#include "boot_util.h"
#include "smem.h"
#include "ddr_drivers.h"
#include "busywait.h"
#include "CoreMsgRam.h"
#include "HALclkPLLSettings.h"

/*=========================================================================
                       MACRO DEFINITIONS
==========================================================================*/
#define CLOCK_SMEM_VERSION 2

/*
 * Max PLUTO lock time. Max lock time with calibration is expected to be 275us.
 */
#define PLUTO_PLL_LOCK_TIMEOUT_US 600


/*=========================================================================
      Data
==========================================================================*/

uint64 ClockAOPList[] =
{
  HWIO_ADDR(AOSS_CC_AOP_RO_CBCR),
  HWIO_ADDR(AOSS_CC_PWR_MUX_CTRL_CBCR),
  HWIO_ADDR(AOSS_CC_WCSS_TS_CBCR),
  HWIO_ADDR(AOSS_CC_TSENS_HW_CBCR),
  HWIO_ADDR(AOSS_CC_IBI_CTRL0_CBCR),
  HWIO_ADDR(AOSS_CC_IBI_CTRL1_CBCR),
  HWIO_ADDR(AOSS_CC_IBI_CTRL2_CBCR),
  HWIO_ADDR(AOSS_CC_IBI_CTRL3_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_AO_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_MEM_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_TS_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_TS_AO_CBCR),
  //HWIO_ADDR(AOSS_CC_SWAO_BUS_CBCR),
  0,
};


typedef struct
{
  uint16  nVersion;         /* A version number to verify matching XBL and RPM data structures */
  uint16  nBootCPOffset;    /* Offset to boot CP table address */
} Clock_SMEMInfoType;

/*
 * Clock configure performance levels for inform AOP during initialize
 */
extern ClockCfgCPType Clock_PerfData;

static ddr_clock_plan MCPlan;


/*=========================================================================
      Function Prototypes
==========================================================================*/
boolean Clock_ConfigAOP( void );

/*===========================================================================
                      FUNCTION DECLARATIONS
===========================================================================*/

/* =========================================================================
**  Function : Clock_EnableAOPPLL1
** =========================================================================*/
/**
  Enable AOP_PLL1.
*/

static boolean Clock_EnableAOPPLL1
(
  void
)
{
  ClockSourceNodeType *pSource = &ClockSource_AOSSCC_AOSSCCPLL1;
  const HAL_clk_SourceRegSettingsType *pRegSettings;
  uint32 nTimeout = 0;
  uint32 nK = 0;

  pRegSettings = Clock_GetSourceRegSettings(pSource);
  if (pRegSettings)
  {
    HWIO_OUT(AOSS_CC_PLL1_USER_CTL,      pRegSettings->nUserCtl);
    HWIO_OUT(AOSS_CC_PLL1_USER_CTL_U,    pRegSettings->nUserCtl1);
    HWIO_OUT(AOSS_CC_PLL1_CONFIG_CTL,    pRegSettings->nConfigCtl);
    HWIO_OUT(AOSS_CC_PLL1_CONFIG_CTL_U,  pRegSettings->nConfigCtl1);
    HWIO_OUT(AOSS_CC_PLL1_CONFIG_CTL_U1, pRegSettings->nConfigCtl2);
    HWIO_OUT(AOSS_CC_PLL1_CONFIG_CTL_U2, pRegSettings->nConfigCtl3);
    HWIO_OUT(AOSS_CC_PLL1_TEST_CTL,      pRegSettings->nTestCtl);
    HWIO_OUT(AOSS_CC_PLL1_TEST_CTL_U,    pRegSettings->nTestCtl1);
    HWIO_OUT(AOSS_CC_PLL1_TEST_CTL_U1,   pRegSettings->nTestCtl2);
    HWIO_OUT(AOSS_CC_PLL1_TEST_CTL_U2,   pRegSettings->nTestCtl3);
  }

  /*
   * Apply 2 point calibration to the PLL
   */
  nK = (HWIO_INF(QFPROM_CORR_CALIB_ROW2_MSB, AOSS_K_15_14) << 14) |
       HWIO_INF(QFPROM_CORR_CALIB_ROW2_LSB, AOSS_K_13_0);
  if (nK)
  {
    HWIO_OUTF(AOSS_CC_PLL1_CONFIG_CTL_U2, TEMPCOMP_K_DEFAULT, nK);
    HWIO_OUTF(AOSS_CC_PLL1_TEST_CTL_U1,
              FORCE_DCO_PCAL_VALUE,
              HWIO_INF(QFPROM_CORR_CALIB_ROW2_MSB, AOSS_DCOPCODE));
    HWIO_OUTF(AOSS_CC_PLL1_TEST_CTL_U1, DISABLE_DCO_PCAL, 1);
    HWIO_OUTF(AOSS_CC_PLL1_TEST_CTL_U1,
              FORCE_TDO_PCAL_VALUE, 
              HWIO_INF(QFPROM_CORR_CALIB_ROW2_MSB, AOSS_TDOPCODE));
    HWIO_OUTF(AOSS_CC_PLL1_TEST_CTL_U1, DISABLE_TDO_PCAL, 1);
  }

  HWIO_OUT(AOSS_CC_PLL1_L_VAL, 0xA );

  /* Select internal DCO (internally generated 38.4MHz) for output. */
  HWIO_OUTF(AOSS_CC_PLL1_USER_CTL_U, INTERNAL_CLOCK_SELECTION, 2);

  /* Enable the PLL. */
  HWIO_OUTF(AOSS_CC_PLL1_OPMODE, PLL_OPMODE, 1);
  HWIO_OUTF(AOSS_CC_PLL1_MODE, PLL_RESET_N, 1);
  HWIO_OUTF(AOSS_CC_PLL1_MODE, PLL_CLK_XO_PRESENT, 1);

  /* Wait for lock, after which the PLL will be calibrated. */
  while (HWIO_INF(AOSS_CC_PLL1_MODE, PLL_LOCK_DET) == 0)
  {
    if (nTimeout++ >= PLUTO_PLL_LOCK_TIMEOUT_US)
    {
      return FALSE;
    }

    busywait(1);
  }

  /* Enable outputs. */
  HWIO_OUTF(AOSS_CC_PLL1_USER_CTL, POST_DIV_RATIO_EVEN, 1); /* div-2 */
  HWIO_OUTF(AOSS_CC_PLL1_USER_CTL, PLLOUT_MAIN, 1);
  HWIO_OUTF(AOSS_CC_PLL1_USER_CTL, PLLOUT_EVEN, 1);

  /* Switch to the internally generated clock and enable the outputs. */
  HWIO_OUTF(AOSS_CC_PLL1_MODE, PLL_OUTCTRL, 1);
  HWIO_OUTF(AOSS_CC_PLL1_MODE, PLL_CLOCK_SELECT, 1);

  pSource->nReferenceCount += 1;
  pSource->nFlags |= CLOCK_FLAG_INITIALIZED;
  return TRUE;

} /* END Clock_EnableAOPPLL1 */


/* ============================================================================
**  Function : Clock_ConfigDDRModeForAOP
** ============================================================================
*/
/*!
    This function ensures DDR clocks are left in a state valid for the first
    HW switch. Transitioning from SW to HW mode only works in specific cases,
    which are documented in this table provided by Chaitanya Emmela...

    SW         |  HW      |
    --------------------------------------------
    DDRCC      |  DDRCC   |   OK
    DDRCC      |  GCC     |   OK
    GCC (RCG0) |  GCC     |   NOT OK
    GCC (RCG1) |  GCC     |   OK
    GCC        |  DDRCC   |   NOT OK

  @param
    None
    
  @return
    None
   
  @dependencies
    None.

*/
boolean Clock_ConfigDDRModeForAOP( void )
{
  uint32 nIndex;

  /* DDR frequency scaling currently not supported on RUMI. */
  if (RUMI_CHECK() == TRUE)
  {
    return TRUE;
  }

  /*
   * If we're already in DDRCC mode, then we're already safe.
   */
  if ( MCPlan.state[Clock_PerfData.nDDR].mode != DDRCC )
  {
    /*
     * If we're not in DDRCC, but there's a valid DDRCC level enabled in the
     * plan, then switch to the lowest DDRCC level. This is required because
     * the first HW switch cannot be from GCC -> DDRCC.
     */
    for ( nIndex = 0; nIndex < MCPlan.num_levels; nIndex++ )
    {
      if ( (MCPlan.state[nIndex].freq_enable==TRUE) && (MCPlan.state[nIndex].mode==DDRCC) )
      {
        return Clock_SetBIMCSpeed( MCPlan.state[nIndex].freq_khz );
      }
    }

    /*
     * If there are no DDRCC levels enabled in the plan, then make sure to
     * leave on GCC RCG1, since the first HW switch cannot be from RCG0.
     */
    if( HWIO_INF(GCC_DDRMC_CH0_CBCR, CLK_ENABLE) == 1 )
    {
      return Clock_SetBIMCSpeed( MCPlan.state[Clock_PerfData.nDDR].freq_khz );
    }
  }

  return TRUE;
}


/* ============================================================================
**  Function : Clock_ShareDataToAOP
** ============================================================================
*/
/*!
    This function is used for saving clock configure performance levels into SMEM
  for sharing with AOP.  AOP needs the know current performance level settings in
  XBL, so it can put the same initial vote during AOP initialize.
  
  @param
    None
    
  @return
    None
   
  @dependencies
    None.

*/
boolean Clock_ShareDataToAOP( void )
{
  Clock_SMEMInfoType* pSMEMInfo;
  uint32 nTip, nSize;
  uint32 smem_size = sizeof(Clock_SMEMInfoType) + sizeof(ClockCfgCPType);
  void *pSMEM = smem_alloc(SMEM_CLOCK_INFO, smem_size);

  if(pSMEM == NULL) return FALSE;

  /* Store smem address in msg_ram since there is no smem driver in AOP */
  msg_ram_set_smem_address((uint32)SMEM_CLOCK_INFO, (uint32)pSMEM);

  /* Store SMEMInfo */
  pSMEMInfo = pSMEM;
  pSMEMInfo->nVersion = CLOCK_SMEM_VERSION;
  pSMEMInfo->nBootCPOffset = sizeof(Clock_SMEMInfoType);

  /* Store BootCfgCP info */
  nTip = sizeof(Clock_SMEMInfoType);
  nSize = sizeof(ClockCfgCPType);
  qmemscpy( (pSMEM+nTip), nSize, &Clock_PerfData, nSize);
  nTip += nSize;

  if ( nTip == smem_size )
    return TRUE;
  else
    return FALSE;
}


/* ============================================================================
**  Function : Clock_ConfigAOP
** ============================================================================
*/
/*!
    This function is used for config all necessary clocks, PLLs and saving 
  clock performance settings and DDR info into shared memory (SMEM) for sharing 
  with AOP.
  
  @param
    None
    
  @return
    None
   
  @dependencies
    None.

*/
boolean Clock_ConfigAOP( void )
{
  uint32 i;

  /* Needed to put OPMODE under SW control. */
  HWIO_OUTF(AOSS_CC_PLL0_MODE_SEL, SELECT_BIT0, 1);
  HWIO_OUTF(AOSS_CC_PLL1_MODE_SEL, SELECT_BIT0, 1);

  /* Enable AOP PLL1 */
  if ( Clock_EnableAOPPLL1() == FALSE ) return FALSE;
  /* Select AOP PLL1 as the source for AOP_PLL0 */
  HWIO_OUTF( AOSS_CC_PLL_CLK_SEL, PLL0_CLK_REF_SEL, 1);

  if (!Clock_EnableSource(&ClockSource_AOSSCC_AOSSCCPLL0, CLOCK_MASTER_AOSS, NULL))
  {
    return FALSE;
  }

  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCAOP);
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCSWAO);
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCEUDAT);
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCIBI);

  /* Configure all PLLs before handle to AOP */
  for (i = 0; i < ClockBSP.nNumSources; i++)
  {
    if (!Clock_ConfigurePLL(ClockBSP.aSources[i], NULL))
    {
      return FALSE;
    }
  }

  /* Switch all AOP XO source clocks to AOP PLL1 */ 
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCRO);
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCSPMIAODSER);
  Clock_SetDomainBootFMax(&ClockDomain_AOSSCC_AOSSCCSWAOTS);

  // Enabling SWAO before QDSS is unnecessary, and a problem for 
  // AOP deep sleep.
  // Clock_PowerDomainEnable( HWIO_AOSS_CC_SWAO_GDSCR_ADDR );

  Clock_ToggleEnableList( ClockAOPList );

  /* Configure DDR mode before handle to AOP */
  MCPlan = ddr_clock_query(MC_CLOCK_PLAN);
  if ( !Clock_ConfigDDRModeForAOP() ) return FALSE;

  /* Store config data to SMEM for sharing with AOP */
  return Clock_ShareDataToAOP();

}

