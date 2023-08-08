/**
==============================================================================

  @file ClockTools.c

  This file provides clock initialization for starting SDCC clocks at boot.

  Copyright (c) 2016-2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================


==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockTools.c#6 $

  when      who     what, where, why
  --------  ------  ------------------------------------------------------
  02/08/17  vphan   Support QUP V3 clock set frequency
  11/11/16  vphan   Initial SDM845 revision, branched from MSM8998.

==============================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include "HALclkHWIO.h"
#include "ClockBSP.h"
#include "ClockBSPExtern.h"
#include "ClockDriver.h"

/*=========================================================================
      Data
==========================================================================*/

struct Clock_QUPClock
{
  ClockDomainNodeType      *pDomain;
  HAL_clk_RegisterMaskType  VoteReg;
};

const struct Clock_QUPClock Clock_QUPClocks[CLK_QUPV3_NUM_CLKS] = 
{
  [CLK_QUPV3_WRAP0_S0] = { &ClockDomain_GCC_GCCQUPV3WRAP0S0, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S0_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S1] = { &ClockDomain_GCC_GCCQUPV3WRAP0S1, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S1_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S2] = { &ClockDomain_GCC_GCCQUPV3WRAP0S2, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S2_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S3] = { &ClockDomain_GCC_GCCQUPV3WRAP0S3, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S3_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S4] = { &ClockDomain_GCC_GCCQUPV3WRAP0S4, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S4_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S5] = { &ClockDomain_GCC_GCCQUPV3WRAP0S5, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S5_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S6] = { &ClockDomain_GCC_GCCQUPV3WRAP0S6, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S6_CLK_ENA) },
  [CLK_QUPV3_WRAP0_S7] = { &ClockDomain_GCC_GCCQUPV3WRAP0S7, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP0_S7_CLK_ENA) },

  [CLK_QUPV3_WRAP1_S0] = { &ClockDomain_GCC_GCCQUPV3WRAP1S0, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S0_CLK_ENA) },
  [CLK_QUPV3_WRAP1_S1] = { &ClockDomain_GCC_GCCQUPV3WRAP1S1, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S1_CLK_ENA) },
  [CLK_QUPV3_WRAP1_S2] = { &ClockDomain_GCC_GCCQUPV3WRAP1S2, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S2_CLK_ENA) },
  [CLK_QUPV3_WRAP1_S3] = { &ClockDomain_GCC_GCCQUPV3WRAP1S3, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S3_CLK_ENA) },
  [CLK_QUPV3_WRAP1_S4] = { &ClockDomain_GCC_GCCQUPV3WRAP1S4, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S4_CLK_ENA) },
  [CLK_QUPV3_WRAP1_S5] = { &ClockDomain_GCC_GCCQUPV3WRAP1S5, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_1, QUPV3_WRAP1_S5_CLK_ENA) },

  [CLK_QUPV3_WRAP2_S0] = { &ClockDomain_GCC_GCCQUPV3WRAP2S0, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S0_CLK_ENA) },
  [CLK_QUPV3_WRAP2_S1] = { &ClockDomain_GCC_GCCQUPV3WRAP2S1, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S1_CLK_ENA) },
  [CLK_QUPV3_WRAP2_S2] = { &ClockDomain_GCC_GCCQUPV3WRAP2S2, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S2_CLK_ENA) },
  [CLK_QUPV3_WRAP2_S3] = { &ClockDomain_GCC_GCCQUPV3WRAP2S3, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S3_CLK_ENA) },
  [CLK_QUPV3_WRAP2_S4] = { &ClockDomain_GCC_GCCQUPV3WRAP2S4, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S4_CLK_ENA) },
  [CLK_QUPV3_WRAP2_S5] = { &ClockDomain_GCC_GCCQUPV3WRAP2S5, HAL_CLK_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE_2, QUPV3_WRAP2_S5_CLK_ENA) },
};

struct Clock_SDCCClock
{
  ClockDomainNodeType *pDomain;
  uint32 nApps;
  uint32 nAHB;
};

const struct Clock_SDCCClock Clock_SDCCClocks[CLK_SDC_NUM_CLKS] = 
{ 
  { 0 },
  { 0 },
  { &ClockDomain_GCC_GCCSDCC2APPS, HWIO_ADDR(GCC_SDCC2_APPS_CBCR), HWIO_ADDR(GCC_SDCC2_AHB_CBCR) },
  { 0 },
  { &ClockDomain_GCC_GCCSDCC4APPS, HWIO_ADDR(GCC_SDCC4_APPS_CBCR), HWIO_ADDR(GCC_SDCC4_AHB_CBCR) },
  { 0 }
};


const uint32 Clock_SDCLegacyMapping[CLOCK_BOOT_PERF_NUM] =
{
  0,       /* PERF NONE           */
  25000,   /* NOMINAL - 25MHz     */
  50000,   /* MAX - 50MHz         */
  400      /* DEFAULT - At 400KHz */
};


void Clock_SetVotableClock( uintnt nVoteRegs, uintnt nField, boolean bEnable )
{
  uintnt nRegVal = inp32( nVoteRegs );

  if ( bEnable )
  {
    nRegVal |= nField;
  }
  else
  {
    nRegVal &= ~(nField);
  }
  outp32 ( nVoteRegs, nRegVal );
}

/* ============================================================================
**  Function : Clock_SetQUPV3Frequency
** ============================================================================
*/
/*!
    Set QUP V3 clock frequency.

    @param 
      eClock   - QUPV3 index 
      nFreqHz  - Clock frequency in Hz

    @return
    TRUE -- Set frequency success
    FALSE -- Set frequency failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_SetQUPV3Frequency(ClockQUPV3Type eClock, uint32 nFreqHz)
{
  const struct Clock_QUPClock *pQUP;
  uint32 nFreqKHz = nFreqHz / 1000;
  
  if (eClock >= CLK_QUPV3_NUM_CLKS)
  {
    return FALSE;
  }

  pQUP = &Clock_QUPClocks[eClock];
  if (!pQUP->pDomain)
  {
    return FALSE;
  }

  if (!Clock_SetDomainFreq(pQUP->pDomain, nFreqKHz))
  {
    return FALSE;
  }

  Clock_SetVotableClock(pQUP->VoteReg.nAddr, pQUP->VoteReg.nMask, TRUE);
  return TRUE;
}

/* ============================================================================
**  Function : Clock_DisableQUPV3Clock
** ============================================================================
*/
/*!
    Disable QUP V3 clock.

    @param 
      eClock   - QUPV3 index 

    @return
      TRUE -- Disable success
      FALSE -- Disable failed.

    @dependencies
      None.

    @sa None
*/
boolean Clock_DisableQUPV3Clock(ClockQUPV3Type eClock)
{
  const struct Clock_QUPClock *pQUP;

  if (eClock >= CLK_QUPV3_NUM_CLKS)
  {
    return FALSE;
  }

  pQUP = &Clock_QUPClocks[eClock];
  if (!pQUP->pDomain)
  {
    return FALSE;
  }

  Clock_SetVotableClock(pQUP->VoteReg.nAddr, pQUP->VoteReg.nMask, FALSE);
  return TRUE;
}

/* ============================================================================
**  Function : Clock_SetSDCClockFrequencyExt
** ============================================================================
*/
/*!
    Configure SDC clock to a specific perf level.

    @param eClockPerfLevel   -  [IN] Clock frequency level
           eClock            -  [IN] SDC clock to configure
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
uint32 Clock_SetSDCClockFrequencyExt
(
  uint32 nFreqKHz,
  ClockSDCType eClock
)
{
  const struct Clock_SDCCClock *pSDCC;

  if (eClock >= CLK_SDC_NUM_CLKS)
  {
    return FALSE;
  }

  pSDCC = &Clock_SDCCClocks[eClock];
  if (!pSDCC->pDomain)
  {
    return FALSE;
  }

  if (!Clock_SetDomainFreq(pSDCC->pDomain, nFreqKHz))
  {
    return FALSE;
  }

  if (!Clock_ToggleClock(pSDCC->nApps, CLK_TOGGLE_ENABLE) ||
      !Clock_ToggleClock(pSDCC->nAHB, CLK_TOGGLE_ENABLE))
  {
    return FALSE;
  }

  return TRUE;
}


/* ============================================================================
**  Function : Clock_SetSDCClockFrequency
** ============================================================================
*/
/*!
    Configure SDC clock to a specific perf level.

    @param eClockPerfLevel   -  [IN] SDC Clock perf level
           eClock            -  [IN] SDC clock to configure
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_SetSDCClockFrequency
(
  ClockBootPerfLevelType ePerfLevel,
  ClockSDCType eClock
)
{
  if(ePerfLevel >= CLOCK_BOOT_PERF_NUM) return FALSE;
 
  return Clock_SetSDCClockFrequencyExt( Clock_SDCLegacyMapping[ePerfLevel], eClock);

} /* END Clock_SetSDCClockFrequency */


/* ============================================================================
**  Function : Clock_EnableUSB
** ============================================================================
*/
/*!
  Enable/Disable USB clocks.
*/
static boolean Clock_EnableUSB (boolean bEnable)
{
  Clock_CBCRtoggleType eToggle = bEnable ? CLK_TOGGLE_ENABLE : CLK_TOGGLE_DISABLE;

  /* Don't poll this clock since it sources from PHY which may not be out of reset yet */
  HWIO_OUTF(GCC_USB3_PRIM_PHY_PIPE_CBCR, CLK_ENABLE, bEnable);

  if( !Clock_ToggleClock(HWIO_GCC_AGGRE_USB3_PRIM_AXI_CBCR_ADDR, eToggle)) return FALSE;
  if( !Clock_ToggleClock(HWIO_GCC_USB30_PRIM_MASTER_CBCR_ADDR, eToggle)) return FALSE;
  if( !Clock_ToggleClock(HWIO_GCC_USB30_PRIM_SLEEP_CBCR_ADDR, eToggle)) return FALSE;
  if( !Clock_ToggleClock(HWIO_GCC_USB3_PRIM_PHY_AUX_CBCR_ADDR, eToggle)) return FALSE;
  if( !Clock_ToggleClock(HWIO_GCC_USB3_PRIM_PHY_COM_AUX_CBCR_ADDR, eToggle)) return FALSE;
  if( !Clock_ToggleClock(HWIO_GCC_CFG_NOC_USB3_PRIM_AXI_CBCR_ADDR, eToggle)) return FALSE;

  return TRUE;
}

/* ============================================================================
**  Function : Clock_InitUSB
** ============================================================================
*/
/*!
    Configure USB clocks.

    @param None.
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_InitUSB(void)
{
  if (!Clock_SetDomainFreq(&ClockDomain_GCC_GCCUSB30PRIMMASTER, 200000))
  {
    return FALSE;
  }

  return Clock_EnableUSB(TRUE);

} /* END Clock_InitUSB */


/* ============================================================================
**  Function : Clock_USB30_PipeClkSrcSel
** ============================================================================
*/
/*!
    Select USB3 PIPE clock source.

    @param eSrc -  [IN] Clock source choice for the USB3.0 PHY
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.
    @dependencies  None.
    @sa None
*/
boolean Clock_USB30_PipeClkSrcSel(ClockUSB30PipeClkSrcType eSrc)
{
  return TRUE;
}  /* END Clock_USB30_PipeClkSrcSel */


/* ============================================================================
**  Function : Clock_Usb30EnableSWCollapse
** ============================================================================
*/
/*!
    Enable SW Collapse for USB30

    @param Enable/Disable.
    @return
    TRUE always

    @dependencies
    None.

    @sa None
   */
boolean Clock_Usb30EnableSWCollapse(boolean enable)
{
  /* Enable/Disable SW PowerCollapse for USB30 */
  HWIO_OUTF(GCC_USB30_PRIM_GDSCR, SW_COLLAPSE, enable ? 1:0 );
  return TRUE;
}


/* ============================================================================
**  Function : Clock_Usb30GetSWCollapse
** ============================================================================
*/
/*!
    Returns the status of SW Collapse for USB30

    @param None
    @return
    TRUE if enabled
    FALSE if disabled

    @dependencies
    None.

    @sa None
*/
boolean Clock_Usb30GetSWCollapse(void)
{
  uint8 sw_collapse = HWIO_INF(GCC_USB30_PRIM_GDSCR, SW_COLLAPSE);
  return (sw_collapse ? TRUE : FALSE);	
}


/* ============================================================================
**  Function : Clock_DisableUSB
** ============================================================================
*/
/*!
    Disable USB clocks.

    @param None.
    @return
    TRUE -- Disable was successful.
    FALSE -- Disable failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_DisableUSB(void)
{
  return Clock_EnableUSB(FALSE);

} /* END Clock_DisableUSB */


/* ========================================================================
**  Function : Clock_UFSInit
** ======================================================================*/
/*!
    Get the requested clock frequency in hertz.

    @param
      ePerfLevel [in]  - Performance level

    @return
      True - Success init UFS clocks

    @dependencies
    None.

    @sa None
*/

boolean Clock_UFSInit( ClockBootPerfLevelType ePerfLevel )  
{
  static ClockBootPerfLevelType eCurrLevel = CLOCK_BOOT_PERF_NONE;
  Clock_CBCRtoggleType enable;

  /* Don't switch performance level if it has been set previously */
  if ( eCurrLevel == ePerfLevel )
  {
    return TRUE;
  }
  eCurrLevel = ePerfLevel;

  if(ePerfLevel >= CLOCK_BOOT_PERF_NUM) return FALSE;

  if ( ePerfLevel == CLOCK_BOOT_PERF_NONE )
  {
    /* Disable UFS clocks before disabling the power domain. */
    enable = CLK_TOGGLE_DISABLE;
  }
  else
  {
    /* Enable UFS clocks after enabling the power domain. */
    enable = CLK_TOGGLE_ENABLE;

    Clock_PowerDomainEnable( HWIO_GCC_UFS_PHY_GDSCR_ADDR );
  }

  Clock_ToggleClock(HWIO_GCC_AGGRE_UFS_PHY_AXI_CBCR_ADDR, enable);

  Clock_ToggleClock(HWIO_GCC_UFS_PHY_AHB_CBCR_ADDR, enable);
  Clock_ToggleClock(HWIO_GCC_UFS_PHY_AXI_CBCR_ADDR, enable);
  Clock_ToggleClock(HWIO_GCC_UFS_PHY_ICE_CORE_CBCR_ADDR, enable);
  Clock_ToggleClock(HWIO_GCC_UFS_PHY_PHY_AUX_CBCR_ADDR, enable);
  Clock_ToggleClock(HWIO_GCC_UFS_PHY_UNIPRO_CORE_CBCR_ADDR, enable);

  HWIO_OUTF(GCC_UFS_PHY_TX_SYMBOL_0_CBCR, CLK_ENABLE, enable);
  HWIO_OUTF(GCC_UFS_PHY_RX_SYMBOL_0_CBCR, CLK_ENABLE, enable);
  HWIO_OUTF(GCC_UFS_PHY_RX_SYMBOL_1_CBCR, CLK_ENABLE, enable);

  if ( ePerfLevel == CLOCK_BOOT_PERF_NONE )
  {
    Clock_PowerDomainDisable( HWIO_GCC_UFS_PHY_GDSCR_ADDR );
  }

  /* Configure UFS clock sources */
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCUFSPHYAXI);
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCUFSPHYICECORE);
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCUFSPHYUNIPROCORE);

  return TRUE;
}


/* ============================================================================
**  Function : Clock_SetQSPIFrequency
** ============================================================================
*/
/*!
    Set QSPI clock frequency.  Clocks will turn off if request frequency is zero

    @param nFreqKHz - Clock frequency in KHz

    @return - Frequency that clock has been match and set to.

    @dependencies
    None.

    @sa None
*/
uint32 Clock_SetQSPIFrequency( uint32 nFreqKHz )
{
  /* Turn clock off */
  if ( nFreqKHz == 0 )
  {
    Clock_ToggleClock(HWIO_GCC_QSPI_CNOC_PERIPH_AHB_CBCR_ADDR, CLK_TOGGLE_DISABLE);
    Clock_ToggleClock(HWIO_GCC_QSPI_CORE_CBCR_ADDR, CLK_TOGGLE_DISABLE);
    return 0;
  }

  Clock_SetDomainFreq(&ClockDomain_GCC_GCCQSPICORE, nFreqKHz);

  Clock_ToggleClock(HWIO_GCC_QSPI_CNOC_PERIPH_AHB_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_QSPI_CORE_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  if (!ClockDomain_GCC_GCCQSPICORE.pActiveMuxConfig)
  {
    return 0;
  }

  return ClockDomain_GCC_GCCQSPICORE.pActiveMuxConfig->nFreqHz / 1000;
}

