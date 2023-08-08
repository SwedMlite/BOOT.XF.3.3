/**
==============================================================================

  @file ClockDriver.c

  Clock driver functions for PLL and clock management

  Copyright (c) 2017,2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================
*/


/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "ClockBoot.h"
#include "HALclkHWIO.h"
#include "busywait.h"
#include "ClockDriver.h"
#include "ClockBSP.h"
#include "ChipInfo.h"

/*=========================================================================
      Macro Definitions
==========================================================================*/
/*
 *  PLL register offsets.
 */
#if defined(HWIO_GCC_GPLL0_MODE_ADDR)
  #define GPLL_OFFS(x)  (HWIO_ADDR(GCC_GPLL0_##x) - HWIO_ADDR(GCC_GPLL0_MODE))
  #define GPLL_FMSK(x,m)  HWIO_FMSK(GCC_GPLL0_##x, m)
  #define GPLL_SHFT(x,m)  HWIO_SHFT(GCC_GPLL0_##x, m)
#else
  #error "No BASE PLL definitions found in HWIO."
#endif


/* HW_CTL bit mask */
#define CLK_HW_CTL_MSK 0x2

/*
 * Definitions for configuring the PLL in FSM Mode
 */
#define CLOCK_PLL_BIAS_COUNT_VAL  (0x0 << GPLL_SHFT(MODE, PLL_BIAS_COUNT))
#define CLOCK_PLL_LOCK_COUNT_VAL  (0x0 << GPLL_SHFT(MODE, PLL_LOCK_COUNT))

/*
 * CLOCK_PLL_INIT_TIME_US
 *
 * Init time in microseconds after de-asserting PLL reset (normal mode).
 */
#define CLOCK_PLL_INIT_TIME_US 5

/*
 * CLOCK_PLL_WARMUP_TIME_US
 *
 * Warm-up time in microseconds after turning on the PLL.
 */
#define CLOCK_PLL_WARMUP_TIME_US 25

/*
 * PLL lock timeout (2x max locking time).
 */
#define CLOCK_PLL_LOCK_TIMEOUT_US 200

/*
 * NOT_2D / NOT_N_MINUS_M
 *
 * Macros to return the inverted value of the 2D field or (N - M)
 * in a type 1 mux structure.  Used to prepare the value for writing
 * to the hardware register field.
 */
#define NOT_2D(mux)         (~(mux)->nN)
#define NOT_N_MINUS_M(mux)  (~((mux)->nN - (mux)->nM))

/*
 * HALF_DIVIDER
 *
 * Macro to return the normalized half divider for a given mux structure.
 * NOTE: Expecting (2 * divider) value as input.
 */
#define HALF_DIVIDER(mux)  ((mux)->nDiv2x ? (((mux)->nDiv2x) - 1) : 0)

/*
 * Common root clock command fields/masks (*_CMD_RCGR)
 */
#define CLOCK_CMD_CGR_ROOT_OFF_FMSK                                  0x80000000
#define CLOCK_CMD_CGR_ROOT_EN_FMSK                                   0x00000002
#define CLOCK_CMD_CFG_UPDATE_FMSK                                    0x00000001
#define CLOCK_CMD_CFG_UPDATE_SHFT                                    0

/*
 * Common root clock configuration registers and their relative offset to
 * the first register (*_CMD_CGR)
 */
#define CLOCK_CMD_REG_OFFSET                                         0
#define CLOCK_CFG_REG_OFFSET                                         0x4
#define CLOCK_M_REG_OFFSET                                           0x8
#define CLOCK_N_REG_OFFSET                                           0xC
#define CLOCK_D_REG_OFFSET                                           0x10

/*
 * Common root clock config fields/masks (*_CFG_RCGR)
 */
#define CLOCK_CFG_RCGR_MODE_FMSK                                      0x00003000
#define CLOCK_CFG_RCGR_MODE_SHFT                                      0xc
#define CLOCK_CFG_RCGR_SRC_SEL_FMSK                                   0x00000700
#define CLOCK_CFG_RCGR_SRC_SEL_SHFT                                   0x8
#define CLOCK_CFG_RCGR_SRC_DIV_FMSK                                   0x0000001F
#define CLOCK_CFG_RCGR_SRC_DIV_SHFT                                   0

#define CLOCK_CFG_CFG_DUAL_EDGE_MODE_VAL                             0x2
#define CLOCK_CFG_CFG_BYPASS_MODE_VAL                                0x0

/*
 * CLOCK_PLL_MODE_*
 *
 * Definitions for configuring the PLLn_MODE register.
 */
#define CLOCK_PLL_MODE_ACTIVE  \
  (GPLL_FMSK(MODE, PLL_OUTCTRL)  | \
   GPLL_FMSK(MODE, PLL_RESET_N))

#define PLL_OPMODE_STANDBY 0
#define PLL_OPMODE_RUN     1

/*=========================================================================
      Globals
==========================================================================*/

Clock_RailwayType ClockRailway =
{
  "vddcx",
  0,
  0,
  "vdda_ebi",
  0,
  0
};

uintnt aPllVoteAddrList[CLOCK_MASTER_MAX_SIZE] = {
  [CLOCK_MASTER_APCS] = HWIO_ADDR(GCC_APCS_PLL_BRANCH_ENA_VOTE),
  [CLOCK_MASTER_RPMH] = HWIO_ADDR(GCC_SPARE_PLL_BRANCH_ENA_VOTE),
  [CLOCK_MASTER_AOSS] = HWIO_ADDR(GCC_RPM_PLL_BRANCH_ENA_VOTE),
};


/*===========================================================================
                      FUNCTION DECLARATIONS
===========================================================================*/ 

/* ============================================================================
**  Function : Clock_EnablePLL
** ============================================================================
*/
/*!
    Enable a PLL.  If it is voteable, it will be set for FSM mode
    and voted for using the vote register. Doesn't configure the PLL.

    @param pSource -  [IN] PLL configuration structure
    @param eVoteMaster - [IN] Master who is voting for this PLL
    @param pConfig -  [IN] PLL frequency configuration
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/

static boolean Clock_EnablePLL( ClockSourceNodeType *pSource, ClockMasterType eVoteMaster, const ClockSourceFreqConfigType *pConfig )
{
  uint64 nModeAddr, nVoteAddr, nVoteMask;
  uint32 nModeVal,  nTimeout = 0;

  if (!pSource || eVoteMaster >= CLOCK_MASTER_MAX_SIZE)
  {
    return FALSE;
  }

  nModeAddr = pSource->HALSource.nAddr;
  nVoteAddr = pSource->HALSource.VoterRegister.nAddr;
  nVoteMask = pSource->HALSource.VoterRegister.nMask;

  /*
   * If the PLL is FSM voteable, vote on behalf of domain master
   */
  if (nVoteAddr && aPllVoteAddrList[eVoteMaster])
  {

    nVoteAddr = aPllVoteAddrList[eVoteMaster];
  }

  Clock_ConfigurePLL(pSource, pConfig);

  /*
   * Enable the PLL. If there is an address for a voting register, then the
   * PLL is in FSM voteable mode. In this case, the enable sequence is
   * handled in hardware, guided by the BIAS and LOCK counts.
   */
  if (nVoteAddr != 0)
  {
    /* Vote the PLL On */
    outpdw(nVoteAddr, inpdw(nVoteAddr) | nVoteMask);

    /*
     * Wait for the PLL to go active.
     */
    while ((inpdw(nModeAddr) & GPLL_FMSK(MODE, PLL_ACTIVE_FLAG)) == 0)
    {
      if (nTimeout++ >= CLOCK_PLL_LOCK_TIMEOUT_US)
      {
        return FALSE;
      }
      busywait(1);
    }
  }
  /*
   * If there is no voting reg, then it is a non-voted PLL.
   * We follow the usual PLL enable sequence.
   */
  else if (pSource->nReferenceCount == 0)
  {
    /*
     * Set OPMODE to 0
     */
    outpdw(nModeAddr + GPLL_OFFS(OPMODE), 0);

    /*
     * Assert the reset_n field to put the PLL in standby state.
     */
    nModeVal = inpdw(nModeAddr);
    nModeVal |= GPLL_FMSK(MODE, PLL_RESET_N);
    outpdw(nModeAddr, nModeVal);

    /*
     * Set OPMODE to Run State
     */
    outpdw(nModeAddr + GPLL_OFFS(OPMODE), PLL_OPMODE_RUN);
    busywait(CLOCK_PLL_WARMUP_TIME_US);

    /*
     * Wait for the PLL to lock within the given timeout period
     */
    while ((inpdw(nModeAddr) & GPLL_FMSK(MODE, PLL_LOCK_DET)) == 0)
    {
      if (nTimeout++ >= CLOCK_PLL_LOCK_TIMEOUT_US)
      {
        return FALSE;
      }

      busywait(1);
    }

    /*
     * Finally, Assert the PLL Output control bit.
     */
    nModeVal |= GPLL_FMSK(MODE, PLL_OUTCTRL);
    outpdw(nModeAddr, nModeVal);
  }

  return TRUE;
}


/* ============================================================================
**  Function : Clock_DisablePLL
** ============================================================================
*/
/*!
    PLL shutdown. When in the off state, the bias is off and draws no power.
    This procedure results in calibration being required upon the next enable.

    @param pSource -  [IN] PLL configuration structure
    @param eVoteMaster - [IN] Master who is voting for this PLL
    @return
    TRUE -- The PLL was succesfully disabled.
    FALSE -- Disable failed.

    @dependencies None.

    @sa None.
*/
static boolean Clock_DisablePLL( ClockSourceNodeType *pSource, ClockMasterType eVoteMaster )
{
  uint64 nModeAddr, nVoteAddr;
  uint32 nModeVal;
  uint32 nVoteMask;
  uintnt nVoteVal = 0x0;

  if (!pSource || eVoteMaster >= CLOCK_MASTER_MAX_SIZE)
  {
    return FALSE;
  }

  if (pSource->nFlags & CLOCK_FLAG_DO_NOT_DISABLE)
  {
    return TRUE;
  }

  nModeAddr = pSource->HALSource.nAddr;
  nVoteAddr = pSource->HALSource.VoterRegister.nAddr;
  nVoteMask = pSource->HALSource.VoterRegister.nMask;
  nModeVal = inpdw(nModeAddr);

  /*
   * If the PLL is FSM voteable, vote on behalf of domain master
   */
  if (nVoteAddr && aPllVoteAddrList[eVoteMaster])
  {
    nVoteAddr = aPllVoteAddrList[eVoteMaster];
  }

  /* Read current mode value. */
  nModeVal  = inp32(nModeAddr);

  if (nModeVal & GPLL_FMSK(MODE, PLL_VOTE_FSM_ENA))
  {
    if(nVoteAddr != 0)
    {
      nVoteVal = inp32(nVoteAddr);
      nVoteVal = (nVoteVal & ~nVoteMask);
      outp32(nVoteAddr, nVoteVal);
      return TRUE;
    }
    return FALSE;
  }
  else if (pSource->nReferenceCount == 1)
  {
    /* De-assert the OUTCTL field. */
    nModeVal &= ~GPLL_FMSK(MODE, PLL_OUTCTRL);
    outp32(nModeAddr, nModeVal);

    /* Wait 2 ticks of the output main clock. */
    busywait(1);

    /*
     * Assert the reset_n field to put the PLL in standby state.
     */
    nModeVal |= GPLL_FMSK(MODE, PLL_RESET_N);
    outpdw(nModeAddr, nModeVal);

    /*
     * Set OPMODE to STANDBY
     */
    outpdw(nModeAddr + GPLL_OFFS(OPMODE), PLL_OPMODE_STANDBY);

  }
  return TRUE;
}


/* =========================================================================
**  Function : Clock_ConfigurePLL
** =========================================================================*/
/**
  Configures a PLL.

  @param pSource -  [IN] PLL configuration structure
  @param pConfig -  [IN] PLL frequency configuration

*/
boolean Clock_ConfigurePLL(ClockSourceNodeType *pSource, const ClockSourceFreqConfigType *pConfig)
{
  uint64 nModeAddr, nVoteAddr;
  uint32 nUserCtlVal, nModeVal = 0;
  uint32 nVoteMask, nOddDiv, nEvenDiv;
  const ClockSourceFreqConfigType *pCalConfig;
  const HAL_clk_SourceRegSettingsType *pRegSettings;
  const HAL_clk_PLLConfigType *pHALConfig;

  if (!pSource)
  {
    return FALSE;
  }

  nModeAddr = pSource->HALSource.nAddr;
  nVoteAddr = pSource->HALSource.VoterRegister.nAddr;
  nVoteMask = pSource->HALSource.VoterRegister.nMask;
  nModeVal = inp32(nModeAddr);
  
  /*
   * If the PLL is locked, return
   */
  if (nModeVal & GPLL_FMSK(MODE, PLL_LOCK_DET))
  {
    pSource->nFlags |= CLOCK_FLAG_INITIALIZED;
    return TRUE;
  }

  /*
   * Clear all bits to put PLL in reset, bypass and output disabled.
   */
  outpdw(nModeAddr, 0x0);

  pRegSettings = Clock_GetSourceRegSettings(pSource);
  if (pRegSettings)
  {
    outpdw( nModeAddr + GPLL_OFFS(USER_CTL),      pRegSettings->nUserCtl );
    outpdw( nModeAddr + GPLL_OFFS(USER_CTL_U),    pRegSettings->nUserCtl1);
    outpdw( nModeAddr + GPLL_OFFS(USER_CTL_U1),   pRegSettings->nUserCtl2);
    outpdw( nModeAddr + GPLL_OFFS(CONFIG_CTL),    pRegSettings->nConfigCtl );
    outpdw( nModeAddr + GPLL_OFFS(CONFIG_CTL_U),  pRegSettings->nConfigCtl1);
    outpdw( nModeAddr + GPLL_OFFS(CONFIG_CTL_U1), pRegSettings->nConfigCtl2);
    outpdw( nModeAddr + GPLL_OFFS(TEST_CTL),      pRegSettings->nTestCtl );
    outpdw( nModeAddr + GPLL_OFFS(TEST_CTL_U),    pRegSettings->nTestCtl1);
    outpdw( nModeAddr + GPLL_OFFS(TEST_CTL_U1),   pRegSettings->nTestCtl2);
  }

  if(pConfig == NULL)
  {
    pConfig = Clock_GetSourceFreqConfig(pSource, 0);
  }

  /*
   * Unused PLLs may not have any frequency configurations. In this case,
   * return early without configuring the frequency-specific portion. Still
   * configure the CONFIG/TEST_CTL settings, since even though the PLL won't
   * be used for anything, out-of-date settings will still trigger APT test
   * failures.
   */
  if (!pConfig)
  {
    pSource->nFlags |= CLOCK_FLAG_INITIALIZED;
    return TRUE;
  }

  pHALConfig = &pConfig->HALConfig;

  /*
   * Program L, L fractional and CAL_L
   */
  outpdw(nModeAddr + GPLL_OFFS(L_VAL), pHALConfig->nL);
  outpdw(nModeAddr + GPLL_OFFS(ALPHA_VAL), pHALConfig->nFracVal);

  pCalConfig = Clock_GetSourceCalConfig(pSource);
  if (pCalConfig)
  {
    outpdw(nModeAddr + GPLL_OFFS(CAL_L_VAL), pCalConfig->HALConfig.nL);
  }

  /*
   * Get the UserCtlVal value and clear out fields we will configure.
   */
  nUserCtlVal = inpdw(nModeAddr + GPLL_OFFS(USER_CTL));
  nUserCtlVal &= ~(GPLL_FMSK(USER_CTL, PRE_DIV_RATIO)       |
                   GPLL_FMSK(USER_CTL, POST_DIV_RATIO_EVEN) |
                   GPLL_FMSK(USER_CTL, POST_DIV_RATIO_ODD));

  /*
   * Program the pre-div value (div-1 to div-2).
   */
  if (pHALConfig->nPreDiv <= 2 && pHALConfig->nPreDiv > 0)
  {
    nUserCtlVal |= ((pHALConfig->nPreDiv - 1) << GPLL_SHFT(USER_CTL, PRE_DIV_RATIO));
  }

  nOddDiv = pHALConfig->PostDivs.Lucid.nOdd;
  nEvenDiv = pHALConfig->PostDivs.Lucid.nEven;
  if (nEvenDiv > 0)
  {
    nEvenDiv--;
  }

  nUserCtlVal |= ((nOddDiv) << GPLL_SHFT(USER_CTL, POST_DIV_RATIO_ODD));
  nUserCtlVal |= ((nEvenDiv) << GPLL_SHFT(USER_CTL, POST_DIV_RATIO_EVEN));

  /* Enable any outputs for this PLL */
  nUserCtlVal |= GPLL_FMSK(USER_CTL, PLLOUT_MAIN);
  if (pSource->nConfigMask & CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE)
  {
    nUserCtlVal |= GPLL_FMSK(USER_CTL, PLLOUT_EVEN);
  }
  if (pSource->nConfigMask & CLOCK_CONFIG_PLL_ODD_OUTPUT_ENABLE)
  {
    nUserCtlVal |= GPLL_FMSK(USER_CTL, PLLOUT_ODD);
  }

  /*
   * Finally program the PLL_USER_CTL register.
   */
  outpdw(nModeAddr + GPLL_OFFS(USER_CTL), nUserCtlVal);


  /* 
   * If there is an address for a voting register, then the PLL is in
   * FSM voteable mode. In this case, the enable sequence is handled in
   * hardware, guided by the BIAS and LOCK counts.
   */

  if (nVoteAddr != 0)
  {
    /*
     * Put the FSM in reset.
     */
    nModeVal |= GPLL_FMSK(MODE, PLL_VOTE_FSM_RESET);
    outpdw(nModeAddr, nModeVal);

    /*
     * Program the FSM portion of the mode register.
     */
    nModeVal &= ~GPLL_FMSK(MODE, PLL_BIAS_COUNT);
    nModeVal &= ~GPLL_FMSK(MODE, PLL_LOCK_COUNT);
    nModeVal |= CLOCK_PLL_BIAS_COUNT_VAL;
    nModeVal |= CLOCK_PLL_LOCK_COUNT_VAL;
    nModeVal |= GPLL_FMSK(MODE, PLL_VOTE_FSM_ENA);
    /*
     * Finally program the Mode register.
     */
    outpdw(nModeAddr, nModeVal);

    /*
     * Take the FSM out of reset.
     */
    nModeVal &= ~GPLL_FMSK(MODE, PLL_VOTE_FSM_RESET);
    outpdw(nModeAddr, nModeVal);
  }

  /* Release the PLL from reset */
  nModeVal |= GPLL_FMSK(MODE, PLL_RESET_N);
  outpdw(nModeAddr, nModeVal);

  if (pSource->nConfigMask & CLOCK_CONFIG_PLL_MAIN_OUTPUT_HW_CTL)
  {
    nModeVal |= GPLL_FMSK(MODE, OUT_MAIN_HW_CTL);
  }
  if (pSource->nConfigMask & CLOCK_CONFIG_PLL_EVEN_OUTPUT_HW_CTL)
  {
    nModeVal |= GPLL_FMSK(MODE, OUT_EVEN_HW_CTL);
  }
  if (pSource->nConfigMask & CLOCK_CONFIG_PLL_ODD_OUTPUT_HW_CTL)
  {
    nModeVal |= GPLL_FMSK(MODE, OUT_ODD_HW_CTL);
  }

  outpdw(nModeAddr, nModeVal);

  pSource->nFlags |= CLOCK_FLAG_INITIALIZED;
  return TRUE;
}


/* =========================================================================
**  Function : Clock_IsBSPSupported
** =========================================================================*/
/**
  See ClockDriver.h
*/

boolean Clock_IsBSPSupported
(
  const ClockHWVersionType *pHWVersion
)
{
  uint32                   nHWVersion, nHWMaxVersion, nHWMinVersion;

  /*-----------------------------------------------------------------------*/
  /* Validate argument pointer is usable.                                  */
  /*-----------------------------------------------------------------------*/

  if (pHWVersion == NULL)
  {
    return FALSE;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate chip family. If not provided then we do not check.           */
  /*-----------------------------------------------------------------------*/

  if ((pHWVersion->eChipInfoFamily != 0) &&
      (pHWVersion->eChipInfoFamily != ChipInfo_GetChipFamily()))
  {
    return FALSE;
  }

  /*-----------------------------------------------------------------------*/
  /* Get the actual hardware revision.                                     */
  /*-----------------------------------------------------------------------*/

  nHWVersion = ChipInfo_GetChipVersion();

  nHWMinVersion =
    CHIPINFO_VERSION(pHWVersion->Min.nMajor, pHWVersion->Min.nMinor);
  nHWMaxVersion =
    CHIPINFO_VERSION(pHWVersion->Max.nMajor, pHWVersion->Max.nMinor);

  /*-----------------------------------------------------------------------*/
  /* No chip version data implies support in all HW versions.              */
  /*-----------------------------------------------------------------------*/

  if ((nHWMinVersion == 0) && (nHWMaxVersion == 0))
  {
    return TRUE;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate the HW version falls within the min/max.                     */
  /*-----------------------------------------------------------------------*/

  if ((nHWVersion >= nHWMinVersion) && (nHWVersion < nHWMaxVersion))
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}


/* =========================================================================
**  Function : Clock_GetSourceFreqConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

const ClockSourceFreqConfigType *Clock_GetSourceFreqConfig
(
  ClockSourceNodeType *pSource,
  uint32               nMinFreqKHz
)
{
  const ClockSourceFreqConfigType *pConfig;
  uint32 nMinFreqHz = nMinFreqKHz * 1000;
  uint32 i;

  for (i = 0; i < pSource->nBSPLen; i++)
  {
    pConfig = &pSource->aBSP[i];
    if (pConfig->nFreqHz >= nMinFreqHz &&
        Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      return pConfig;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_GetSourceCalConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

const ClockSourceFreqConfigType *Clock_GetSourceCalConfig
(
  ClockSourceNodeType *pSource
)
{
  const ClockSourceFreqConfigType *pCalConfig;
  uint32 i;

  for (i = 0; i < pSource->nCalibrationFreqConfigLen; i++)
  {
    pCalConfig = &pSource->pCalibrationFreqConfig[i];
    if (Clock_IsBSPSupported(&pCalConfig->HWVersion))
    {
      return pCalConfig;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_GetSourceRegSettings
** =========================================================================*/
/**
  See ClockDriver.h
*/

const HAL_clk_SourceRegSettingsType *Clock_GetSourceRegSettings
(
  ClockSourceNodeType *pSource
)
{
  const ClockSourceRegSettingsType *pRegSettings;
  uint32 i;

  for (i = 0; i < pSource->nRegSettingsLen; i++)
  {
    pRegSettings = &pSource->pRegSettings[i];
    if (Clock_IsBSPSupported(&pRegSettings->HWVersion))
    {
      return &pRegSettings->HALSettings;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_GetDomainFrequency
** =========================================================================*/
/**
  See ClockDriver.h
*/

uint32 Clock_GetDomainFrequency
(
  ClockDomainNodeType *pDomain
)
{
  if (!pDomain->pActiveMuxConfig)
  {
    return 0;
  }

  return pDomain->pActiveMuxConfig->nFreqHz;
}


/* =========================================================================
**  Function : Clock_GetDomainFreqConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

const ClockMuxConfigType *Clock_GetDomainFreqConfig
(
  ClockDomainNodeType *pDomain, 
  uint32               nMinFreqKHz
)
{
  ClockMuxConfigType *pConfig;
  uint32 nMinFreqHz = nMinFreqKHz * 1000;
  uint32 i;

  for (i = 0; i < pDomain->nBSPLen; i++)
  {
    pConfig = &pDomain->aBSP[i];
    if (pConfig->nFreqHz >= nMinFreqHz &&
        Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      return pConfig;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_GetDomainFMaxConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockMuxConfigType *Clock_GetDomainFMaxConfig
(
  ClockDomainNodeType *pDomain, 
  rail_voltage_level   eCorner
)
{
  ClockMuxConfigType *pConfig;
  uint32 i;

  for (i = pDomain->nBSPLen - 1; i >= 0; i--)
  {
    pConfig = &pDomain->aBSP[i];
    if (pConfig->eVRegLevel <= eCorner &&
        Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      return pConfig;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_SetDomainFreqConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

boolean Clock_SetDomainFreqConfig(ClockDomainNodeType *pDomain, const ClockMuxConfigType *pConfig)
{
  if (!Clock_EnableSource(pConfig->pSource, pDomain->eMaster, pConfig->pSourceFreqConfig))
  {
    return FALSE;
  }

  if (!Clock_ConfigMux(&pDomain->HALDomain, &pConfig->HALConfig))
  {
    return FALSE;
  }

  if (pDomain->pActiveMuxConfig)
  {
    Clock_DisableSource(pDomain->pActiveMuxConfig->pSource, pDomain->eMaster);
  }

  pDomain->pActiveMuxConfig = pConfig;
  return TRUE;
}


/* =========================================================================
**  Function : Clock_SetDomainFreq
** =========================================================================*/
/**
  See ClockDriver.h
*/

boolean Clock_SetDomainFreq(ClockDomainNodeType *pDomain, uint32 nMinFreqKHz)
{
  const ClockMuxConfigType *pConfig;

  pConfig = Clock_GetDomainFreqConfig(pDomain, nMinFreqKHz);
  if (!pConfig)
  {
    return FALSE;
  }

  return Clock_SetDomainFreqConfig(pDomain, pConfig);
}


/* =========================================================================
**  Function : Clock_SetDomainFMax
** =========================================================================*/
/**
  See ClockDriver.h
*/

boolean Clock_SetDomainFMax (ClockDomainNodeType *pDomain, rail_voltage_level eCorner)
{
  ClockMuxConfigType *pConfig;

  pConfig = Clock_GetDomainFMaxConfig(pDomain, eCorner);
  if (!pConfig)
  {
    return FALSE;
  }

  return Clock_SetDomainFreqConfig(pDomain, pConfig);
}


/* =========================================================================
**  Function : Clock_SetDomainBootFMax
** =========================================================================*/
/**
  See ClockDriver.h
*/

void Clock_SetDomainBootFMax (ClockDomainNodeType *pDomain)
{
  if (!Clock_SetDomainFMax(pDomain, RAIL_VOLTAGE_LEVEL_NOM))
  {
    while(1);
  }
}


void Clock_ConfigDivider(HAL_clk_DividerDescType    *pHALDivider, uint32 nDiv)
{
  uintnt nAddr;
  uint32 nVal;

  nAddr = pHALDivider->nAddr;

  /*
   * Sanity check
   */
  if (nAddr == 0)
  {
    return;
  }

  nVal = inpdw(nAddr);
  if (nDiv <= 1)
  {
    nDiv = 0;
  }
  else
  {
    nDiv--;
  }

  /*
   * Clear previous divider value.
   */
  nVal &= ~HAL_CLK_CDIVR_CLK_DIV_FMSK;

  /*
   * Set divider value.
   */
  nVal |= ((nDiv << HAL_CLK_CDIVR_CLK_DIV_SHFT)
                  & HAL_CLK_CDIVR_CLK_DIV_FMSK);

  /*
   * Write final value.
   */
  outpdw(nAddr, nVal);

}
/* =========================================================================
**  Function : Clock_ConfigMux
** =========================================================================*/
/**
  See ClockDriver.h
*/

boolean Clock_ConfigMux (HAL_clk_ClockDomainDescType *pDomain, const HAL_clk_ClockMuxConfigType *pConfig)
{
  uintnt nCmdRCGRAddr, nCfgRCGRAddr;
  uint32 nCmdRCGRVal,  nCfgRCGRVal;
  uintnt nMAddr, nNAddr, nDAddr;
  uint32 nTimeout = 0;

  nCmdRCGRAddr = pDomain->nCGRAddr;
  nCmdRCGRVal  = inp32(nCmdRCGRAddr);
  nCfgRCGRAddr = nCmdRCGRAddr + CLOCK_CFG_REG_OFFSET; 
  nCfgRCGRVal  = inp32(nCfgRCGRAddr);

  /* Clear the fields. */
  nCfgRCGRVal &= ~(CLOCK_CFG_RCGR_SRC_SEL_FMSK |
                  CLOCK_CFG_RCGR_SRC_DIV_FMSK |
                  CLOCK_CFG_RCGR_MODE_FMSK);

  /* Program the source and divider values. */
  nCfgRCGRVal |= (pConfig->nMuxSel << CLOCK_CFG_RCGR_SRC_SEL_SHFT)
                  & CLOCK_CFG_RCGR_SRC_SEL_FMSK;
  nCfgRCGRVal |= ((HALF_DIVIDER(pConfig) << CLOCK_CFG_RCGR_SRC_DIV_SHFT)
                  & CLOCK_CFG_RCGR_SRC_DIV_FMSK);

  /* Set MND counter mode depending on if it is in use. */
  if (pConfig->nM != 0 && (pConfig->nM < pConfig->nN))
  {
    nMAddr = nCmdRCGRAddr + CLOCK_M_REG_OFFSET;
    nNAddr = nCmdRCGRAddr + CLOCK_N_REG_OFFSET;
    nDAddr = nCmdRCGRAddr + CLOCK_D_REG_OFFSET;

    outp32(nMAddr, pConfig->nM);
    outp32(nNAddr, NOT_N_MINUS_M(pConfig));
    outp32(nDAddr, NOT_2D(pConfig));

    nCfgRCGRVal |= ((CLOCK_CFG_CFG_DUAL_EDGE_MODE_VAL << CLOCK_CFG_RCGR_MODE_SHFT)
                    & CLOCK_CFG_RCGR_MODE_FMSK);
  }

  /* Write the final CFG register value. */
  outp32(nCfgRCGRAddr, nCfgRCGRVal);

  /* Trigger the update. */
  nCmdRCGRVal |= CLOCK_CMD_CFG_UPDATE_FMSK;
  outp32(nCmdRCGRAddr, nCmdRCGRVal);

  /* Wait until update finishes. */
  while ( inp32(nCmdRCGRAddr) & CLOCK_CMD_CFG_UPDATE_FMSK )
  {
    if ( nTimeout++ >= CLOCK_UPDATE_TIMEOUT_US )
    {
      return FALSE;
    }

    busywait(1);
  }

  return TRUE;
}

  
/* =========================================================================
**  Function : Clock_ToggleClock
** =========================================================================*/
/*!
    Enable/Disable a Clock and poll for CLK_OFF BIT. 

    @param CBCR_addr - Address of the CBCR register
           enable :-  enable/disable the CBCR 
    TRUE -- CBCR programming successful.
    FALSE -- CBCR programming failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_ToggleClock(uintnt CBCR_addr, Clock_CBCRtoggleType toggle_clk)
{
  uintnt CBCR_value;
  
  if(toggle_clk >= NUM_CLK_TOGGLE_TYPES) return FALSE;

  CBCR_value = inp32(CBCR_addr);
  
  if(toggle_clk == CLK_TOGGLE_ENABLE)  
  {
    CBCR_value = CBCR_value | CLK_ENABLE_MSK;
    outp32(CBCR_addr, CBCR_value);  

    /* Poll clock status if the clock is not under HW control */
    if ( (CBCR_value & CLK_HW_CTL_MSK) != CLK_HW_CTL_MSK )
    {
      do
      {
        CBCR_value = inp32(CBCR_addr);
      }while((CBCR_value & CLK_OFF_MSK) != 0);
    }  
  }
  else
  {
    CBCR_value = CBCR_value & ~CLK_ENABLE_MSK;
    outp32(CBCR_addr, CBCR_value);  
  }
  return TRUE;
}


/* ===========================================================================
**  Clock_PowerDomainEnable
** ======================================================================== */

boolean Clock_PowerDomainEnable ( uintnt nGDSCRAddr )
{
  uint32 nVal;
  uintnt nTimeout = 0;

  if( nGDSCRAddr == 0 )
  {
    return FALSE;
  }

  nVal  = inp32(nGDSCRAddr);

  /*
   * Clear the SW PD collapse bit
   */
  nVal &= ~CLK_GDSCR_SW_COLLAPSE_MSK;
  outp32(nGDSCRAddr, nVal);

  /*
   * Wait for PD ON
   */
  while( !(inp32(nGDSCRAddr) & CLK_GDSCR_PWR_ON_MSK) )
  {
    if (nTimeout++ >= CLK_GDSCR_TIMEOUT_US)
    {
      return FALSE;
    }
    busywait(1);
  }
  return TRUE;

} /* END Clock_PowerDomainEnable */


/* ===========================================================================
**  Clock_PowerDomainDisable
** ======================================================================== */

boolean Clock_PowerDomainDisable ( uintnt nGDSCRAddr )
{
  uintnt nVal;

  /* Sanity check */
  if(nGDSCRAddr == 0)
  {
    return FALSE;
  }

  nVal  = inp32(nGDSCRAddr);

  /* Set the SW PD collapse bit */
  nVal |= CLK_GDSCR_SW_COLLAPSE_MSK;
  outp32(nGDSCRAddr, nVal);

  return TRUE;
} /* END Clock_PowerDomainDisable */


/*=========================================================================
      Functions
==========================================================================*/

/* ============================================================================
**  Function : Clock_RailwayCfg
** ============================================================================
*/
/*!
    Return a pointer to the Railway configuration data.

   @param  None

   @retval a pointer to the Railway configuration data

*/
Clock_RailwayType *Clock_RailwayConfig( void )
{
  return &ClockRailway;
}


/* ============================================================================
**  Function : Clock_EnableSource
** ============================================================================
*/

boolean Clock_EnableSource (ClockSourceNodeType *pSource, ClockMasterType eVoteMaster, const ClockSourceFreqConfigType *pConfig )
{
  boolean bResult = TRUE;

  if (pSource && eVoteMaster < CLOCK_MASTER_MAX_SIZE)
  {
    if (pSource->aMasterRefCounts[eVoteMaster] == 0)
    {
      bResult = Clock_EnablePLL(pSource, eVoteMaster, pConfig);
    }
    pSource->aMasterRefCounts[eVoteMaster]++;
    pSource->nReferenceCount++;
  }

  return bResult;
}


/* ============================================================================
**  Function : Clock_DisableSource
** ============================================================================
*/

boolean Clock_DisableSource (ClockSourceNodeType *pSource, ClockMasterType eVoteMaster )
{
  boolean bResult = TRUE;

  if (pSource && eVoteMaster < CLOCK_MASTER_MAX_SIZE)
  {
    if (pSource->aMasterRefCounts[eVoteMaster] == 1)
    {
      bResult = Clock_DisablePLL(pSource, eVoteMaster);
    }

    if (pSource->nReferenceCount > 0 &&
        pSource->aMasterRefCounts[eVoteMaster] > 0)
    {
      pSource->nReferenceCount--;
      pSource->aMasterRefCounts[eVoteMaster]--;
    }
  }

  return bResult;
}


/* ============================================================================
**  Function : Clock_ToggleEnableList
** ============================================================================
*/
void Clock_ToggleEnableList( uint64* pList )
{
  uint32 i = 0;

  /* Enable list clocks */
  while ( pList[i] != 0 )
  {
    Clock_ToggleClock( pList[i], CLK_TOGGLE_ENABLE );
    i++;
  }
}


/* ============================================================================
**  Function : Clock_OverrideMMCXArc
** ============================================================================
  This function overrides the MMCX ARC state to allow Display clocks to be turned on.
  Requirements : MMCX needs to be enabled by direct PMIC writes in boot for this override to be used.
*/
boolean Clock_OverrideMMCXArc( boolean ena )
{
  if(ena)
  {
    HWIO_OUTI(RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm,8, 0xffffffff);
    HWIO_OUTI(RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm,8, 0xffffffff);
  }
  else
  {
    HWIO_OUTI(RPMH_ARC_SW_OVERRIDE_PWR_CTRL_MASK_RMm, 8, 0x00000000);
    HWIO_OUTI(RPMH_ARC_SW_OVERRIDE_PWR_CTRL2_MASK_RMm, 8, 0x00000000);
  }
  return TRUE;
}

