/**
==============================================================================

  @file ClockCPU.c

  This file provides clock initialization for the Apps CPU.

  Copyright (c) 2016-2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================


==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockCPU.c#10 $

  when      who     what, where, why
  --------  ------  ------------------------------------------------------
  11/11/16  vphan   Initial SDM845 revision, branched from MSM8998.

==============================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include "HALclkHWIO.h"
#include "ClockBSP.h"
#include "ClockBSPExtern.h"
#include <HALcomdef.h>
#include <HALhwio.h>
#include <busywait.h>
#include "HALclkPLLSettings.h"
#include "ClockDriver.h"
#include "ChipInfo.h"

/*=========================================================================
      Macro Definitions
==========================================================================*/
#define OPMODE_OFFS         (HWIO_SILVER_PLL_OPMODE_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define GFMUX_OFFS          (HWIO_SILVER_CFG_GFMUX_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define USER_CTL_OFFS       (HWIO_SILVER_PLL_USER_CTL_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define CONFIG_CTL_LO_OFFS  (HWIO_SILVER_PLL_CONFIG_CTL_LO_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define CONFIG_CTL_HI_OFFS  (HWIO_SILVER_PLL_CONFIG_CTL_HI_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define CONFIG_CTL_U1_OFFS  (HWIO_SILVER_PLL_CONFIG_CTL_U1_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define TEST_CTL_LO_OFFS    (HWIO_SILVER_PLL_TEST_CTL_LO_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define TEST_CTL_HI_OFFS    (HWIO_SILVER_PLL_TEST_CTL_HI_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define TEST_CTL_U1_OFFS    (HWIO_SILVER_PLL_TEST_CTL_U1_ADDR - HWIO_SILVER_PLL_MODE_ADDR)
#define L_VAL_OFFS          (HWIO_SILVER_PLL_L_VAL_ADDR - HWIO_SILVER_PLL_MODE_ADDR)

/*
 * Use FREQ_LOCK_DET instead of PLL_LOCK_DET due to Zonda workarounds. Zonda
 * has a HW bug that means it doesn't lock reliably, and the current workaround
 * set set STAY_IN_CFA completely breaks PLL_LOCK_DET. But polling FREQ_LOCK_DET
 * is apparently good enough according to the HW team, so do that for now. 
 */
#define LOCK_DET_BMSK       HWIO_SILVER_PLL_MODE_FREQ_LOCK_DET_BMSK

#define MODE_CTL_MSK        0x7
#define GFMUX_SRC_SEL_BMSK  0x3


/*=========================================================================
      Function Prototypes
==========================================================================*/
static boolean Clock_EnableAppsPLL(ClockAPCSCfgType *pConfig, uintnt nPLLModeAddr, 
                                   boolean bConfigOnly);
static boolean Clock_DisableAppsPLL(uintnt nPLLModeAddr);

/*=========================================================================
      Data
==========================================================================*/

/* The current rate of the APPS cluster 0 clock in KHz */
static uint32 Clock_APPSCL0SpeedKHz = 1190400;

static ClockAPCSCfgType CPU_Cfg_V1 = {APCS_SOURCE_AG_EARLY,   73,     0,        0,      1401600 };
static ClockAPCSCfgType L3_Cfg_V1  = {APCS_SOURCE_AG_EARLY,   64,     0,        0,      1228800 };
static ClockAPCSCfgType CPU_Cfg_V2 = {APCS_SOURCE_AG_EARLY,   79,     0,        0,      1516800 };
static ClockAPCSCfgType L3_Cfg_V2  = {APCS_SOURCE_AG_EARLY,   69,     0,        0,      1324800 };


/*=========================================================================
      Function Definitions
==========================================================================*/

/* ========================================================================
**  Function : Clock_GetAPSSCL0SpeedKHz
** ======================================================================*/
/*
    Description: Configure CPU clock source

    @param
      None.

    @return
      Frequency of APPS cluster zero in KHZ.

    @dependencies
      None.

    @sa
      None.
*/

uint32 Clock_GetAPSSCL0SpeedKHz(void)
{
  return Clock_APPSCL0SpeedKHz;
}


/* ========================================================================
**  Function : Clock_ConfigAPSSClock
** ======================================================================*/
/*
    Description: Configure CPU clock or L3 clock

    @param
      ClkCfg - Clock configuration
      nModeAddr - Clock mode address

    @return
      TRUE -- Initialization was successful.
      FALSE -- Initialization failed.

    @dependencies
      None.

    @sa None
*/
boolean Clock_ConfigAPSSClock( ClockAPCSCfgType *ClkCfg, uintnt nModeAddr )
{
  uint32 nRegVal;

  if ( ClkCfg == NULL ) return FALSE;

  /* Used Agera PLL */
  if ( (ClkCfg->nCPUSource == APCS_SOURCE_AG_EARLY) || 
       (ClkCfg->nCPUSource == APCS_SOURCE_AG_MAIN) )
  {
    /* Temporary switch to GPLL0 if APCS PLL is running */
    if ( (inp32(nModeAddr) & LOCK_DET_BMSK) != 0 )
    {
      nRegVal = inp32(nModeAddr+GFMUX_OFFS) & ~GFMUX_SRC_SEL_BMSK | APCS_SOURCE_GPLL0_MAIN;
      outp32( (nModeAddr+GFMUX_OFFS), nRegVal );
      while( ( inp32(nModeAddr+GFMUX_OFFS) & APCS_SOURCE_GPLL0_MAIN_STATUS_MASK) == 0)
      { /* Wait for the switch to complete before disabling Apps PLL */ }
      if ( !Clock_DisableAppsPLL(nModeAddr) ) return FALSE;
    }

    if ( !Clock_EnableAppsPLL(ClkCfg, nModeAddr, FALSE) ) return FALSE;
    nRegVal = inp32(nModeAddr+GFMUX_OFFS) & ~GFMUX_SRC_SEL_BMSK | ClkCfg->nCPUSource;
    outp32( (nModeAddr+GFMUX_OFFS), nRegVal );
  }
  else if ( ClkCfg->nCPUSource == APCS_SOURCE_GPLL0_MAIN )
  {
    nRegVal = inp32(nModeAddr+GFMUX_OFFS) & ~GFMUX_SRC_SEL_BMSK | APCS_SOURCE_GPLL0_MAIN;
    outp32( (nModeAddr+GFMUX_OFFS), nRegVal );
    while( ( inp32(nModeAddr+GFMUX_OFFS) & APCS_SOURCE_GPLL0_MAIN_STATUS_MASK) == 0);
    { /* Wait for the switch to complete before disabling Apps PLL */ }
    Clock_DisableAppsPLL( nModeAddr );
  }
  else /* XO - Ref clk */
  {
    nRegVal = inp32(nModeAddr+GFMUX_OFFS) & ~GFMUX_SRC_SEL_BMSK;
    outp32( (nModeAddr+GFMUX_OFFS), nRegVal );
    Clock_DisableAppsPLL( nModeAddr );
  }

  return TRUE;
}


/* ============================================================================
**  Function : Clock_SetCPUPerfLevel
** ============================================================================
*/
/**
  Configure A53 CPU to a specific perf level.

  @param eCPUPerfLevel [in] - CPU performance level.

  @return
  TRUE -- CPU configuration to perf level was successful.
  FALSE -- Configuration failed.

  @dependencies
  None.

  @sa
  Clock_Init.
*/
boolean Clock_SetCPUPerfLevel(ClockBootPerfLevelType eCPUPerfLevel)
{
  static ClockBootPerfLevelType eCurrLevel = CLOCK_BOOT_PERF_NONE;
  ClockAPCSCfgType AppsPLLDefault = { APCS_SOURCE_AG_EARLY, 34, 0, 0, 652800 };
  ClockAPCSCfgType* CPU_Cfg = NULL;
  ClockAPCSCfgType* L3_Cfg = NULL;

  /* Requirement:  Apps needs 300 MHz GPLL0 for low voltage corners */
  if (!Clock_SetDomainFreq(&ClockDomain_GCC_GCCCPUSSGPLL0, 300000)) return FALSE;

  /* Set CPU speed */
  if ( eCurrLevel == eCPUPerfLevel ) return TRUE;
  if( eCPUPerfLevel >= CLOCK_BOOT_PERF_NUM ) return FALSE;

  eCurrLevel = eCPUPerfLevel;

  if (ChipInfo_GetChipVersion() < CHIPINFO_VERSION(2, 0))
  {
    CPU_Cfg = &CPU_Cfg_V1;
    L3_Cfg = &L3_Cfg_V1;
  }
  else
  {
    CPU_Cfg = &CPU_Cfg_V2;
    L3_Cfg = &L3_Cfg_V2;
  }

  if ( Clock_ConfigAPSSClock(CPU_Cfg, HWIO_SILVER_PLL_MODE_ADDR) == FALSE ) return FALSE;
  Clock_APPSCL0SpeedKHz = CPU_Cfg->nFreqKHz;

  /* Set L3 speed */
  if ( Clock_ConfigAPSSClock(L3_Cfg, HWIO_L3_PLL_MODE_ADDR) == FALSE ) return FALSE;

  
  /* If the silver cluster PLL is not on, set it up as this is a pre-requisite for the OSM FSM. */
  if( (HWIO_IN( SILVER_PLL_MODE ) & (~MODE_CTL_MSK)) != 0x7 )
  {
    Clock_EnableAppsPLL(&AppsPLLDefault, HWIO_SILVER_PLL_MODE_ADDR, FALSE);
  }

  /* Set Gold PLL  up as this is a pre-requisite for the OSM in HLOS. */
  /* At this moment, the gold rail is not powered.  We will defer the PLL lock into */
  /* TZ when the gold rail is powered, and the first gold core is unclamped. */
  Clock_EnableAppsPLL(&AppsPLLDefault, HWIO_GOLD_PLL_MODE_ADDR, TRUE);
  Clock_EnableAppsPLL(&AppsPLLDefault, HWIO_GOLDPLUS_PLL_MODE_ADDR, TRUE);
  /* Initialize GOLD MUX to be 300 MHz */
  HWIO_OUT(GOLD_CFG_GFMUX, APCS_SOURCE_GPLL0_MAIN);
  HWIO_OUT(GOLDPLUS_CFG_GFMUX, APCS_SOURCE_GPLL0_MAIN);
  return TRUE;
}



/* ============================================================================
**  Function : Clock_SetPLLOpModeToRun
** ============================================================================
    Set PLL OPMODE to run and wait for it to lock.
*/
static boolean Clock_SetPLLOpModeToRun (uintnt nPLLModeAddr)
{
  uint32 nTimeout = 500;

  outp32(nPLLModeAddr + OPMODE_OFFS, 1);

  while (((inp32(nPLLModeAddr) & LOCK_DET_BMSK) == 0) && nTimeout)
  {
    busywait(1);
    nTimeout--;
  }

  if (nTimeout == 0)
  {
    outp32(nPLLModeAddr + OPMODE_OFFS, 0);
    busywait(10);
    return FALSE;
  }

  return TRUE;

}


/* ============================================================================
**  Function : Clock_EnableAppsPLL
** ============================================================================
    Configure and enable a high frequency Apps PLL.

    @param
      pConfig -  [IN] PLL configuration structure
      nPLLModeAddr - [IN] PLL base address (MODE address)
      bConfigOnly [IN] - Do not lock the PLL, just configure it.

    @return
      TRUE -- Initialization was successful.
      FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
static boolean Clock_EnableAppsPLL
(
  ClockAPCSCfgType *pConfig,
  uintnt           nPLLModeAddr,
  boolean          bConfigOnly
)
{
  uint32 nUserCtlVal;
  uint32 nTestCtlVal, nTestCtlUVal, nTestCtlU1Val;
  uint32 nConfigCtlVal, nConfigCtlUVal, nConfigCtlU1Val;

  if ( (pConfig == NULL) || (pConfig->nLVal==0) || (nPLLModeAddr==0) ) return FALSE;

  /* Return failed if PLL is already enabled */
  if ( (inp32(nPLLModeAddr) & LOCK_DET_BMSK) != 0 ) return FALSE;

  if (ChipInfo_GetChipVersion() < CHIPINFO_VERSION(2, 0))
  {
    nUserCtlVal     = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_USER_CTL;
    nConfigCtlVal   = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_CONFIG_CTL;
    nConfigCtlUVal  = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_CONFIG_CTL_U;
    nConfigCtlU1Val = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_CONFIG_CTL_U1;
    nTestCtlVal     = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_TEST_CTL;
    nTestCtlUVal    = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_TEST_CTL_U;
    nTestCtlU1Val   = HAL_CLK_APSS_CC_APSS_CC_PLL0_V1_TEST_CTL_U1;
  }
  else
  {
    nUserCtlVal     = HAL_CLK_APSS_CC_APSS_CC_PLL0_USER_CTL;
    nConfigCtlVal   = HAL_CLK_APSS_CC_APSS_CC_PLL0_CONFIG_CTL;
    nConfigCtlUVal  = HAL_CLK_APSS_CC_APSS_CC_PLL0_CONFIG_CTL_U;
    nConfigCtlU1Val = HAL_CLK_APSS_CC_APSS_CC_PLL0_CONFIG_CTL_U1;
    nTestCtlVal     = HAL_CLK_APSS_CC_APSS_CC_PLL0_TEST_CTL;
    nTestCtlUVal    = HAL_CLK_APSS_CC_APSS_CC_PLL0_TEST_CTL_U;
    nTestCtlU1Val   = HAL_CLK_APSS_CC_APSS_CC_PLL0_TEST_CTL_U1;
  }

  nUserCtlVal |= HWIO_FMSK(SILVER_PLL_USER_CTL, PLLOUT_LV_EARLY_ENABLE);
  nUserCtlVal |= HWIO_FMSK(SILVER_PLL_USER_CTL, PLLOUT_LV_MAIN_ENABLE);

  /* Assume all CPU PLLs share the same values and just use the ones from PLL0. */
  outp32( (nPLLModeAddr+USER_CTL_OFFS),       nUserCtlVal);
  outp32( (nPLLModeAddr+CONFIG_CTL_LO_OFFS),  nConfigCtlVal);
  outp32( (nPLLModeAddr+CONFIG_CTL_HI_OFFS),  nConfigCtlUVal);
  outp32( (nPLLModeAddr+CONFIG_CTL_U1_OFFS),  nConfigCtlU1Val);
  outp32( (nPLLModeAddr+TEST_CTL_LO_OFFS),    nTestCtlVal);
  outp32( (nPLLModeAddr+TEST_CTL_HI_OFFS),    nTestCtlUVal);
  outp32( (nPLLModeAddr+TEST_CTL_U1_OFFS),    nTestCtlU1Val);

  outp32( (nPLLModeAddr+L_VAL_OFFS), pConfig->nLVal );

  if( bConfigOnly == FALSE) 
  {
    /* Enable PLL */
    outp32( nPLLModeAddr, 0x2 ); // Set BYPASSNL
    busywait(5);
    outp32( nPLLModeAddr, 0x6 ); // Set RESET_N

    /* Zonda PLLs don't lock reliably. HW debug in progress. Keep retrying in case of failure. */
    while(!Clock_SetPLLOpModeToRun(nPLLModeAddr));

    outp32( nPLLModeAddr, 0x7 ); // Set OUTCTRL
  }

  return TRUE;

} /* END Clock_EnableAppsPLL */

/* ============================================================================
**  Function : Clock_DisableAppsPLL
** ============================================================================
    Turn off the Apps PLL.

    @param
      pConfig -  [IN] PLL configuration structure

    @return
      void

    @dependencies
    None.

    @sa None
*/
static boolean Clock_DisableAppsPLL
(
  uintnt nPLLModeAddr
)
{
  outp32( nPLLModeAddr, 0 );
  
  /* Set to standby mode */
  outp32(nPLLModeAddr + OPMODE_OFFS, 0);

  return TRUE;
}

/* ============================================================================
**  Function : Clock_LMhInit
** ============================================================================
*/
/*  Initialize for the current limiter calibration.
 *  Power on A57 at Turbo Voltage(A57 operation and stability is not a requirement)
    L2 headswitch needs to be closed as well.

    @param nA57uV  -  [IN] requested voltage in microvolts
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_LMhInit( uint32 nA57uV )
{

  return TRUE;
}

/* ============================================================================
**  Function : Clock_LMhPreCalibration
** ============================================================================
*/
/*  Set the A57 cores at the maximum clock rate.

    @param  nFreqKHz : The frequency to set in KHz
    @return : rounded freqeuncy that was set, or 0 on failure in kHz.

    @dependencies
    None.

    @sa None
*/
uint32 Clock_LMhPreCalibration( uint32 nFreqKHz )
{
  return 0;
}

/* ============================================================================
**  Function : Clock_LMhDeInit
** ============================================================================
*/
/*  Disable the PLL, turn of the L2 head switch, power off the rail.

    @param  None.
    @return
    TRUE -- Success.
    FALSE -- Reserved, not used.

    @dependencies
    None.

    @sa None
*/
boolean Clock_LMhDeInit( void )
{
  return TRUE;
} /* Clock_LMhDeInit */
