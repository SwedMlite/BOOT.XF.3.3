/*
==============================================================================

FILE:         HALclkZonda5lpePLL.c

DESCRIPTION:
  This file contains the clock HAL code for the Zonda PLL control.
  These PLLs are of the Zonda PLL variety.

==============================================================================

                             Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/HALclkSharedLib/HALclkZonda5lpePLL.c#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
08/02/19   ra      Created

==============================================================================
    Copyright (c) 2010-2019 QUALCOMM Technologies Incorporated.All Rights Reserved.
	QUALCOMM Proprietary and Confidential.
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include "stdbool.h"
#include "stdint.h"
#include "HALhwio.h"
#include "HALclkGenericPLL.h"
#include "HALclkZonda5lpePLL.h"
#include "ChipInfoDefs.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/


/*
 * HAL_CLK_PLL_MODE_*
 *
 * Definitions for configuring the PLLn_MODE register.
 */
#define HAL_CLK_PLL_MODE_ACTIVE  \
  (HWIO_FMSK(PLL_MODE, OUTCTRL)  | \
   HWIO_FMSK(PLL_MODE, BYPASSNL) | \
   HWIO_FMSK(PLL_MODE, RESET_N))

/*
 * Definitions for configuring the PLL in FSM Mode
 */
#define HAL_CLK_PLL_BIAS_COUNT_VAL   (0x6 << HWIO_SHFT(PLL_MODE, BIAS_COUNT))
#define HAL_CLK_PLL_LOCK_COUNT_VAL   (0x0 << HWIO_SHFT(PLL_MODE, LOCK_COUNT))

/*
 * HAL_CLK_PLL_INIT_TIME_US
 *
 * Init time in microseconds after de-asserting PLL reset (normal mode).
 */
#define HAL_CLK_PLL_INIT_TIME_US 5

/*
 * HAL_CLK_PLL_WARMUP_TIME_US
 *
 * Warm-up time in microseconds after turning on the PLL.
 */
#define HAL_CLK_PLL_WARMUP_TIME_US 50

/*
 * HAL_CLK_LOCK_TIMEOUT_US
 *
 * Timeout in usec for PLL_LOCK_DET to get set.
 * For Zonda, this is 50us worst-case lock time.
 */
#define HAL_CLK_LOCK_TIMEOUT_US 50


/* ============================================================================
**    Data Declarations
** ==========================================================================*/

/*
 * HAL_clk_Zonda5lpePLLControl
 *
 * Control function array for the Zonda PLLs.
 */
HAL_clk_SourceControlType HAL_clk_Zonda5lpePLLControl =
{
  .Enable           = HAL_clk_Zonda5lpePLLEnable,
  .Disable          = HAL_clk_Zonda5lpePLLDisable,
  .IsEnabled        = HAL_clk_Zonda5lpePLLIsEnabled,
  .Config           = HAL_clk_Zonda5lpePLLConfig,
  .ConfigPLL        = HAL_clk_Zonda5lpePLLConfigPLL,
  .DetectPLLConfig  = HAL_clk_Zonda5lpePLLDetectPLLConfig,
  .EnableVote       = HAL_clk_Zonda5lpePLLEnableVote,
  .DisableVote      = HAL_clk_Zonda5lpePLLDisableVote,
  .IsVoteEnabled    = HAL_clk_Zonda5lpePLLIsVoteEnabled,
  .IsPLLConfigEqual = HAL_clk_Zonda5lpePLLIsPLLConfigEqual,
  .IsCalibrated     = HAL_clk_Zonda5lpePLLIsCalibrated,
  .SetCalConfig     = HAL_clk_Zonda5lpePLLSetCalConfig,
  .SetRegSettings   = HAL_clk_Zonda5lpePLLSetRegSettings,
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/* ===========================================================================
**  HAL_clk_Zonda5lpePLLEnableVote
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLEnableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;
  boolean     bResult;

  /*
   * Set the appropriate bit.
   */
  nVal = inpdw(pSource->VoterRegister.nAddr) | pSource->VoterRegister.nMask;
  outpdw(pSource->VoterRegister.nAddr, nVal);

  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_ACTIVE_FLAG),
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_Zonda5lpePLLEnableVote */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLDisableVote
**
** ======================================================================== */

static void HAL_clk_Zonda5lpePLLDisableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;

  /*
   * Clear the appropriate bit.
   */
  nVal = inpdw(pSource->VoterRegister.nAddr) & ~pSource->VoterRegister.nMask;
  outpdw(pSource->VoterRegister.nAddr, nVal);

} /* END HAL_clk_Zonda5lpePLLDisableVote */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLIsVoteEnabled
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLIsVoteEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  /*
   * Check the appropriate bit.
   */
  if (inpdw(pSource->VoterRegister.nAddr) & pSource->VoterRegister.nMask)
  {
    return TRUE;
  }

  return FALSE;

} /* END HAL_clk_Zonda5lpePLLIsVoteEnabled */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLPostDivToHW
**
** ======================================================================== */

static uint32_t HAL_clk_Zonda5lpePLLPostDivToHW (uint32_t nDivider)
{
  switch (nDivider)
  {
    case 0:
    case 1:   return 0; /* Divide-by-1 */
    case 2:   return 1; /* Divide-by-2 */
    case 4:   return 3; /* Divide-by-4 */
    case 8:   return 2; /* Divide-by-8 */
    default:
      return 0;
  }

} /* END HAL_clk_Zonda5lpePLLPostDivToHW */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLPostDivFromHW
**
** ======================================================================== */

static uint32_t HAL_clk_Zonda5lpePLLPostDivFromHW (uint32_t nDivider)
{
  switch (nDivider)
  {
    case 0:   return 1; /* Divide-by-1 */
    case 1:   return 2; /* Divide-by-2 */
    case 2:   return 8; /* Divide-by-8 */
    case 3:   return 4; /* Divide-by-4 */
    default:
      return 1;
  }

} /* END HAL_clk_Zonda5lpePLLPostDivFromHW */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLEnable
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLEnable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32_t nModeVal;
  boolean     bResult;
  uint32_t nTimeout         = 10;
  uint32_t nChipFamily      = HAL_clk_GetChipFamily();
  uint32_t nChipVersion     = HAL_clk_GetChipVersion();
  boolean     bAffectedVersion = FALSE;
  boolean     bAffectedFamily  = FALSE;

  /*
   * Check if PLL is already enabled and return
   */
  if (HAL_clk_Zonda5lpePLLIsEnabled(pSource))
  {
    return TRUE;
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * De-assert PLL bypass.
   * This latches L and Alpha values.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, BYPASSNL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Wait for PLL init time
   */
  HAL_clk_BusyWait(HAL_CLK_PLL_INIT_TIME_US);

  /*
   * De-assert PLL reset.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, RESET_N);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Wait for the PLL warm-up time.
   */
  HAL_clk_BusyWait(HAL_CLK_PLL_WARMUP_TIME_US);
  
  /*
   * Set desired operational mode.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);
  
  
  /*
   * Workaround required for V1 of SM8250 and SDX55 Zonda PLL Locking issue.
   * Must wait a minimum of 500 us.  Check the Chip Version and the chip family.
   */
  if ( nChipVersion < CHIPINFO_VERSION(2,0) )
  {
    bAffectedVersion = TRUE;
  }
  
  if ( ((nChipFamily == CHIPINFO_FAMILY_SM8250) ||
        (nChipFamily == CHIPINFO_FAMILY_SDX55)))
  {
    bAffectedFamily = TRUE;
  }

  /*
   * Wait for the PLL to lock within the timeout period.
   */
  bResult = FALSE;

  /*
   * Check if CFA mode is enabled.  If so, we should poll on the frequency lock detect
   * rather than the normal lock detect.
   */
  if ( HWIO_FMSK(PLL_TEST_CTL, STAY_IN_CFA) == 0x1 )
  {
    bResult =
      HAL_clk_ValidateRegSetTimeout(
        HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
        HWIO_FMSK(PLL_MODE, FREQ_LOCK_DET),
        HAL_CLK_LOCK_TIMEOUT_US);
  }
  else
  {
    /*
     * Check for affected chips.  Apply the recommended workaround for PLL
     * locking issue.
     */
    if ( bAffectedFamily && bAffectedVersion )
    {
      while ( nTimeout != 0 )
      {
        /*
         * V1 Workaround for HW issue locking the PLL in less than 500us.
         * Wait for prescribed time before checking if the PLL is locked.
         * Call ValidateRegSetTimeout API with wait time of 0, since we're 
         * enforcing a 500us wait time.  We'll timeout after 5 tries.
         */
        HAL_clk_BusyWait(500);
        bResult =
          HAL_clk_ValidateRegSetTimeout(
            HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
            HWIO_FMSK(PLL_MODE, LOCK_DET),
            0);
            
        if ( bResult == FALSE )
        {
          /*
           * Reset the OPMODE to try again.
           */
          HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_STANDBY);
          HAL_clk_BusyWait(HAL_CLK_PLL_WARMUP_TIME_US);
          HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);
        }
        else
        {
          break;
        }
      
        nTimeout--;
      }    
    }
    else
    {
      /*
       * Normal lock detect for PLL.
       */
      bResult =
        HAL_clk_ValidateRegSetTimeout(
          HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
          HWIO_FMSK(PLL_MODE, LOCK_DET),
          HAL_CLK_LOCK_TIMEOUT_US);    
    }    
  }


  /*
   * Return immediately if the lock detect failed.
   */
  if (!bResult)
  {
    return FALSE;
  }

  /*
   * Put the PLL in active mode
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, OUTCTRL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  return TRUE;

} /* END HAL_clk_Zonda5lpePLLEnable */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLDisable
**
** ======================================================================== */

static void HAL_clk_Zonda5lpePLLDisable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32_t nModeVal;

  /*
   * The Zonda PLL's only support full enable/disable mode.
   */
  if (eMode != HAL_CLK_SOURCE_DISABLE_MODE_NORMAL)
  {
    return;
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * First clear the output enable bit
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, OUTCTRL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Put the PLL in off state
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, RESET_N) |
                HWIO_FMSK(PLL_MODE, BYPASSNL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

} /* END HAL_clk_Zonda5lpePLLDisable */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLIsEnabled
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLIsEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nModeVal;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Check whether the PLL is enabled.
   */
  return ((nModeVal & HAL_CLK_PLL_MODE_ACTIVE) == HAL_CLK_PLL_MODE_ACTIVE);

} /* END HAL_clk_Zonda5lpePLLIsEnabled */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLConfig
**
** ======================================================================== */

static void HAL_clk_Zonda5lpePLLConfig
(
  HAL_clk_SourceDescType   *pSource,
  HAL_clk_SourceConfigType  eConfig
)
{
  /*
   * Take action.
   */
  switch (eConfig)
  {
    case HAL_CLK_CONFIG_PLL_FSM_MODE_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, FSM_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_FSM_MODE_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, FSM_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_AUX2_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_AUX2_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_AUX_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_AUX_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_TEST_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_LV_TEST_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EARLY_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, LVEARLY_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EARLY_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, LVEARLY_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, LVMAIN_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, LVMAIN_EN, 0);
      break;

    default:
      break;
  }

} /* END HAL_clk_Zonda5lpePLLConfig */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLConfigPLLNormal
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLConfigPLLNormal
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  uint32_t nModeVal;
  uint32_t nUserVal;
  boolean     bPLLEnabled = FALSE;
  uint32_t nPLLInFSMMode = 0;
  uint16_t nFracVal = 0;

  /*
   * Check PLL FSM mode.
   */
  nPLLInFSMMode = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource) &
    HWIO_FMSK(PLL_MODE, FSM_EN);

  /*
   * Check PLL mode.
   */
  bPLLEnabled = HAL_clk_Zonda5lpePLLIsEnabled(pSource);

  /*
   * Disable the PLL.
   */
  if (bPLLEnabled)
  {
    HAL_clk_Zonda5lpePLLDisable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Disable FSM Mode
   */
  if (nPLLInFSMMode != 0)
  {
    nModeVal &= ~HWIO_FMSK(PLL_MODE, FSM_EN);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);
  }

  /*
   * Program L/Alpha values.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_L_VAL, pSource, pConfig->nL);

  /*
   * Get the CONFIG value and clear out fields we will configure.
   */
  nUserVal  =  HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  nUserVal &= ~(HWIO_FMSK(PLL_USER_CTL, FRAC_ALPHA_MN_MODE) |
                HWIO_FMSK(PLL_USER_CTL, PLL_FRAC_MODE_ENABLE) |
                HWIO_FMSK(PLL_USER_CTL, CLK_REF_PRE_DIV) |
                HWIO_FMSK(PLL_USER_CTL, CLK_POST_DIV));

  /*
   * Program the pre-div value (div-1 to div-2).
   */
  if (pConfig->nPreDiv <= 2 && pConfig->nPreDiv > 0)
  {
    nUserVal |= HWIO_FVAL(PLL_USER_CTL, CLK_REF_PRE_DIV, (pConfig->nPreDiv - 1));
  }

  /*
   * Program the post-div value.
   */
  nUserVal |= HWIO_FVAL(PLL_USER_CTL, CLK_POST_DIV,
    HAL_clk_Zonda5lpePLLPostDivToHW(pConfig->PostDivs.Zonda.nMain));

  /*
   *  Check fractional output or integer output.
   */
  if (pConfig->eFracMode == HAL_CLK_PLL_FRAC_MODE_MN)
  {
    /*
     * MN Mode
     */
    nFracVal = (uint16_t)(pConfig->nFracVal & 0x0000FFFF);
    nFracVal |= (uint16_t)((pConfig->nFracVal & 0xFFFF0000) >> 8);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, PLL_FRAC_MODE_ENABLE);
  }
  else
  {
    /*
     * Default to Alpha mode
     */
    nFracVal = (uint16_t)pConfig->nFracVal;
    nUserVal &= ~HWIO_FMSK(PLL_USER_CTL, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL, PLL_FRAC_MODE_ENABLE);
  }
    
    
  HAL_CLK_PLL_HWIO_OUT(PLL_ALPHA_VAL, pSource, nFracVal);


  /*
   * Enable MAIN_OUT_ENA bit.
   */
  nUserVal |= HWIO_FMSK(PLL_USER_CTL, LVMAIN_EN);

  /*
   * Finally program the USER_CTL register.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL, pSource, nUserVal);

  /*
   * If there is an address for a voting register, then the PLL is in
   * FSM voteable mode. In this case, the enable sequence is handled in
   * hardware, guided by the BIAS and LOCK counts.
   */
  if (nPLLInFSMMode)
  {
    /*
     * Put the FSM in reset.
     */
    nModeVal |= HWIO_FMSK(PLL_MODE, FSM_RES);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

    /*
     * Program the FSM portion of the mode register.
     */
    nModeVal &= ~HWIO_FMSK(PLL_MODE, BIAS_COUNT);
    nModeVal &= ~HWIO_FMSK(PLL_MODE, LOCK_COUNT);

    nModeVal |= HAL_CLK_PLL_BIAS_COUNT_VAL;
    nModeVal |= HAL_CLK_PLL_LOCK_COUNT_VAL;

    nModeVal |= HWIO_FMSK(PLL_MODE, FSM_EN);
    /*
     * Finally program the Mode register.
     */
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

    /*
     * Take the FSM out of reset.
     */
    nModeVal &= ~HWIO_FMSK(PLL_MODE, FSM_RES);
    HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);
  }

  /*
   * Enable the PLL if it was on before.
   */
  if (bPLLEnabled && nPLLInFSMMode == 0)
  {
    HAL_clk_Zonda5lpePLLEnable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  return TRUE;

} /* END HAL_clk_Zonda5lpePLLConfigPLLNormal */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLConfigPLLSlew
**
**  Returns:
**    boolean - TRUE if successfully configured.
**              FALSE if unable to detect that the PLL successfully locked.
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLConfigPLLSlew
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  boolean bResult;

  /*
   * Program L value.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_L_VAL, pSource, pConfig->nL);

  /*
   * Wait for 11 or more PLL clk_ref ticks for PLL_LOCK_DET to transition to 0.
   * When using a reference clock of XO, the wait requirement is 570 ns.
   */
  HAL_clk_BusyWait(1);

  /*
   * Check if CFA mode is enabled.  If so, we should poll on the frequency lock detect
   * rather than the normal lock detect.
   */
  if ( HWIO_FMSK(PLL_TEST_CTL, STAY_IN_CFA) == 0x1 )
  {
    bResult =
      HAL_clk_ValidateRegSetTimeout(
        HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
        HWIO_FMSK(PLL_MODE, FREQ_LOCK_DET),
        HAL_CLK_LOCK_TIMEOUT_US);
  }
  else
  {
    /*
     * Wait for the PLL to lock during the expected timeout period.
     */
    bResult =
      HAL_clk_ValidateRegSetTimeout(
        HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
        HWIO_FMSK(PLL_MODE, LOCK_DET),
        HAL_CLK_LOCK_TIMEOUT_US);
  }

  return bResult;

} /* END HAL_clk_Zonda5lpePLLConfigPLLSlew */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLConfigPLL
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLConfigPLL
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  HAL_clk_SourceConfigMode     eMode
)
{
  boolean bResult = FALSE;

  switch (eMode)
  {
    case HAL_CLK_SOURCE_CONFIG_MODE_NORMAL:
      bResult = HAL_clk_Zonda5lpePLLConfigPLLNormal(pSource, pConfig);
      break;
    case HAL_CLK_SOURCE_CONFIG_MODE_SLEW:
      bResult = HAL_clk_Zonda5lpePLLConfigPLLSlew(pSource, pConfig);
      break;
    default:
      bResult = FALSE;
      break;
  }

  return bResult;

} /* END HAL_clk_Zonda5lpePLLConfigPLL */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLDetectPLLConfig
**
** ======================================================================== */

static void HAL_clk_Zonda5lpePLLDetectPLLConfig
(
  HAL_clk_SourceDescType *pSource,
  HAL_clk_PLLConfigType  *pConfig
)
{
  uint32_t nConfigVal;
  uint32_t nMode;
  uint32_t nPostDiv;

  /*
   * Clear all config values not modified in this function.
   */
  pConfig->nMode = 0;

  /*
   * Read current L and Alpha values.
   */
  nMode = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);

  /*
   * Check to see if fractional value is enabled
   */
  pConfig->nFracVal = HAL_CLK_PLL_HWIO_IN(PLL_ALPHA_VAL, pSource);
  if ( nMode & HWIO_FMSK(PLL_USER_CTL, PLL_FRAC_MODE_ENABLE) )
  {
    if ( nMode & HWIO_FMSK(PLL_USER_CTL, FRAC_ALPHA_MN_MODE) )
    {
      pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_MN;
    }
    else
    {
      pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_ALPHA;
    }
  }
  else
  {
    pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_UNKNOWN;
  }

  /*
   * Read current L-Val
   */
  pConfig->nL = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pSource);

  /*
   * Determine the oscillator source.
   */
  pConfig->nSource = 0;

  /*
   * Get the pre and post dividers.
   */
  nConfigVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  pConfig->nPreDiv = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, CLK_REF_PRE_DIV))
                      >> (HWIO_SHFT(PLL_USER_CTL, CLK_REF_PRE_DIV))) + 1;
  nPostDiv  = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, CLK_POST_DIV))
                          >> HWIO_SHFT(PLL_USER_CTL, CLK_POST_DIV));
  nPostDiv = HAL_clk_Zonda5lpePLLPostDivFromHW(nPostDiv);
  pConfig->PostDivs.Zonda.nMain = nPostDiv;

} /* END HAL_clk_Zonda5lpePLLDetectPLLConfig */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLIsPLLConfigEqual
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLIsPLLConfigEqual
(
  const HAL_clk_PLLConfigType  *pConfigA,
  const HAL_clk_PLLConfigType  *pConfigB
)
{
  uint32_t nMainDivA, nMainDivB;

  if (HAL_clk_GenericIsPLLConfigEqual(pConfigA, pConfigB))
  {
    /* Treat div-0 and div-1 as the same thing. */
    nMainDivA = MAX(1, pConfigA->PostDivs.Zonda.nMain);
    nMainDivB = MAX(1, pConfigB->PostDivs.Zonda.nMain);

    if (nMainDivA == nMainDivB)
    {
      return TRUE;
    }
  }

  return FALSE;

} /* END HAL_clk_Zonda5lpePLLIsPLLConfigEqual */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLIsCalibrated
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLIsCalibrated
(
  HAL_clk_SourceDescType *pSource
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_Zonda5lpePLLIsCalibrated */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLSetCalConfig
**
** ======================================================================== */

static boolean HAL_clk_Zonda5lpePLLSetCalConfig
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_Zonda5lpePLLSetCalConfig */


/* ===========================================================================
**  HAL_clk_Zonda5lpePLLSetRegSettings
**
** ======================================================================== */

static void HAL_clk_Zonda5lpePLLSetRegSettings
(
  HAL_clk_SourceDescType              *pSource,
  const HAL_clk_SourceRegSettingsType *pmSettings
)
{
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL,    pSource, pmSettings->nConfigCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U,  pSource, pmSettings->nConfigCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U1, pSource, pmSettings->nConfigCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL,      pSource, pmSettings->nTestCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U,    pSource, pmSettings->nTestCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U1,   pSource, pmSettings->nTestCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL,      pSource, pmSettings->nUserCtl);

} /* END HAL_clk_Zonda5lpePLLSetRegSettings */

