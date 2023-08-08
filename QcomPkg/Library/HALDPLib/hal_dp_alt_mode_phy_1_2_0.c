/*===========================================================================

FILE:         hal_dp_alt_mode_phy_1_2_0.c

DESCRIPTION:  
  This file contains the programming for the DP Phy/PLL (v1.2.0 7nm).

  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------
** Includes
** ----------------------------------------------------------------------- */
#include "hal_dp_i.h"
#include "hal_dp_phy.h"
#include "hal_dp_phy_1_2_0_hwio.h"
#include "hal_dp_phy_qmp_pll_7nm.h"
#include "dp_system.h"

/* -----------------------------------------------------------------------
** Macros
** ----------------------------------------------------------------------- */

#define DP_PREEMPHASIS_LEVEL_NUM               3
#define DP_VOLTAGESWING_LEVEL_NUM              3
#define DP_AUX_CFG_SETTINGS_LEN                4


/* -----------------------------------------------------------------------
** Structure definitions
** ----------------------------------------------------------------------- */



/* -----------------------------------------------------------------------
** Static Variables
** ----------------------------------------------------------------------- */

/* Pre-emphasis and Voltage swing combinations supported by hardware */
static HAL_DP_PeSwPairType aPeSwPair[DP_VOLTAGESWING_LEVEL_NUM][DP_PREEMPHASIS_LEVEL_NUM] =
{
  { { 0x20, 0x2f }, { 0x2B, 0x2F }, { 0x34, 0x36 } }, /* SW0_PE0, SW0_PE1, SW0_PE2  */
  { { 0x20, 0x31 }, { 0x2B, 0x3E }, { 0x32, 0x3F } }, /* SW1_PE0, SW1_PE1, SW1_PE2  */
  { { 0x20, 0x39 }, { 0x2B, 0x3F }, { 0x2B, 0x3F } }, /* SW2_PE0, SW2_PE1, N/A     */
};

/*DP_PHY_AUX_CFG1 register settings */
static uint32 aAuxPhyCfg1Setting[DP_AUX_CFG_SETTINGS_LEN] = { 0x20, 0x13, 0x23, 0x1d };


/* -----------------------------------------------------------------------
** Function Prototypes
** ----------------------------------------------------------------------- */
static HAL_MDSS_ErrorType HAL_DP_AltMode_Phy_Poll_PhyReady(DP_DeviceIDType eDeviceId, uint32);
static HAL_MDSS_ErrorType HAL_DP_AltMode_Phy_Poll_CReady(DP_DeviceIDType eDeviceId);
HAL_MDSS_ErrorType HAL_DP_AltMode_1_2_0_PHY_SetupPeSw(DP_DeviceIDType eDeviceId, HAL_DP_PeSwConfigType *pPeSwConfig);

/* -----------------------------------------------------------------------
** Private Functions
** ----------------------------------------------------------------------- */

/****************************************************************************
*
** FUNCTION: HAL_DP_AltMode_GetRegBaseOffset()
*/
/*!
* \brief   
*     Get DP register address offset for a give DP device ID.
*
* \param [in]  eDeviceId - DP device ID
*
* \retval - register base offset
*
****************************************************************************/
uintPtr HAL_DP_AltMode_GetRegBaseOffset(DP_DeviceIDType  eDeviceId)
{
  uintPtr   uOffset;

  switch (eDeviceId)
  {
  case DP_DEVICE_ID_ALT_MODE_0:
    {
      uOffset = 0;
      break;
    }

  case DP_DEVICE_ID_ALT_MODE_1:
    {
      uOffset = (AHB2PHY_SOUTH_USB3_DP_PHY_SECUSB3_DP_PHY_SECCM_USB3_DP_CON_SW_REG_BASE - AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_USB3_DP_COM_USB3_DP_COM_REG_BASE);
      break;
    }

  default:
    {
      //No hardware support for other DP device IDs
      uOffset        = 0;
      break;
    }
  }

  return uOffset;
}

/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_Phy_Pll_Config()
*/
/*!
* \DESCRIPTION
*     Programs Phy/Pll registers.
*
* \param [in]  eDeviceId         - DP device ID
* \param [in]  pDPPllConfigInfo  - Config to apply
*
* \retval HAL_DP_StatusType
*
**********************************************************************************************/
static HAL_MDSS_ErrorType HAL_DP_AltMode_Phy_Pll_Config(DP_DeviceIDType       eDeviceId,
                                                        HAL_DP_PllConfigType *pDPPllConfigInfo)
{
  HAL_MDSS_ErrorType    eStatus     = HAL_MDSS_STATUS_SUCCESS;
  uintPtr               uOffset     = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);
  bool32                bPortSelect = pDPPllConfigInfo->bInvertedPlug;
  uintPtr               uQmpPllBase = 0;

  DP_LOG_MESSAGE_INFO("HAL_DP_Phy_pll_Config: portSel=%d\n", bPortSelect);

  /*
   * NOTE: SW_PORTSELECT (bit 0) of USB3_DP_COM_TYPE_CTRL is shared with usb driver 
   */
  if (FALSE == bPortSelect)
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_ADDR,     0x02);
  }
  else
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_ADDR,     0x03);
  }
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_SWI_CTRL_ADDR,         0x00);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_SW_RESET_ADDR,         0x00);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_POWER_DOWN_CTRL_ADDR,  0x01);

  // Power up PLL, L0/1/2/3, AUX, ungated all clocks, power up all analog blocks
  if (4 == pDPPllConfigInfo->uNumLanes)
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR,           0x7d);
  }
  else
  {
    if (FALSE == bPortSelect)
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR,         0x75);
    }
    else
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR,         0x6d);
    }
  }

  if (FALSE == bPortSelect)
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_MODE_ADDR,         0x5c);
  }
  else
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_MODE_ADDR,         0x4c);
  }

  uQmpPllBase = uOffset + AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_COM_DP_QSERDES_COM_USB3_DP_QMP_PLL_REG_BASE;
  
  /* Configure QMP PLL */
  eStatus = HAL_DP_PHY_Qmp_Pll_7nm_Config(uQmpPllBase, pDPPllConfigInfo);

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_TX0_TX1_LANE_CTL_ADDR,             0x05);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_TX2_TX3_LANE_CTL_ADDR,             0x05);

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TRANSCEIVER_BIAS_EN_ADDR,     0x1A);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_VMODE_CTRL1_ADDR,             0x40);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_PRE_STALL_LDO_BOOST_EN_ADDR,  0x30);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_INTERFACE_SELECT_ADDR,        0x3d);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_CLKBUF_ENABLE_ADDR,           0x0f);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_RESET_TSYNC_EN_ADDR,          0x03);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TRAN_DRVR_EMP_EN_ADDR,        0x03);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_PARRATE_REC_DETECT_IDLE_EN_ADDR, 0x00);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_INTERFACE_MODE_ADDR,       0x00);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR, 0x1A); EMP
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_RES_CODE_LANE_TX_ADDR,        0x60); // 0x11);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_BAND_ADDR,                 0x04);

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TRANSCEIVER_BIAS_EN_ADDR,     0x1A);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_VMODE_CTRL1_ADDR,             0x40);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_PRE_STALL_LDO_BOOST_EN_ADDR,  0x30);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_INTERFACE_SELECT_ADDR,        0x3d);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_CLKBUF_ENABLE_ADDR,           0x0f);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_RESET_TSYNC_EN_ADDR,          0x03);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TRAN_DRVR_EMP_EN_ADDR,        0x03);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_PARRATE_REC_DETECT_IDLE_EN_ADDR, 0x00);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_INTERFACE_MODE_ADDR,       0x00);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR,      0x1A); EMP
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_RES_CODE_LANE_TX_ADDR,        0x60); //0x11);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_BAND_ADDR,                 0x04);

  /*new*/
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_RES_CODE_LANE_OFFSET_RX_ADDR, 0x07);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_RCV_DETECT_LVL_2_ADDR,        0x00);

  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_UCDR_FASTLOCK_FO_GAIN_ADDR,   0x21);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_RX_EQU_ADAPTOR_CNTRL2_ADDR,   0x0);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_RX_EQU_ADAPTOR_CNTRL3_ADDR,   0x0);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_RX_EQU_ADAPTOR_CNTRL4_ADDR,   0x0);

  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_RX_EQ_OFFSET_ADAPTOR_CNTRL1_ADDR, 0x00);
  //DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_RX1_RX_EQ_OFFSET_ADAPTOR_CNTRL2_ADDR, 0x00);

  /*new*/

  //AUX clock setting  - #TODO# IMPLEMENT vco div
  // DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_VCO_DIV_ADDR,                      pSettings[DP_PHY_DP_PHY_VCO_DIV]);

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x01);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x05);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x01);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x09);

  // Check if power up is done
  eStatus = HAL_DP_AltMode_Phy_Poll_CReady(eDeviceId);

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x19);
  if (HAL_MDSS_STATUS_SUCCESS == eStatus)
  {
    eStatus = HAL_DP_AltMode_Phy_Poll_PhyReady(eDeviceId, HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_STATUS_TSYNC_DONE_BMSK);
  }

  if (4 == pDPPllConfigInfo->uNumLanes)
  {
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_HIGHZ_DRVR_EN_ADDR,         0x10);
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TRANSCEIVER_BIAS_EN_ADDR,   0x3f);
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_HIGHZ_DRVR_EN_ADDR,         0x10);
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TRANSCEIVER_BIAS_EN_ADDR,   0x3f);
  }
  else if (2 == pDPPllConfigInfo->uNumLanes)
  {
    if (FALSE == bPortSelect)
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_HIGHZ_DRVR_EN_ADDR,       0x10);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TRANSCEIVER_BIAS_EN_ADDR, 0x3f);
    }
    else
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_HIGHZ_DRVR_EN_ADDR,       0x10);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TRANSCEIVER_BIAS_EN_ADDR, 0x3f);
    }
  }
  else if (1 == pDPPllConfigInfo->uNumLanes)
  {
    if (FALSE == bPortSelect)
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_HIGHZ_DRVR_EN_ADDR,       0x13);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TRANSCEIVER_BIAS_EN_ADDR, 0x3e);
    }
    else
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_HIGHZ_DRVR_EN_ADDR,       0x13);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TRANSCEIVER_BIAS_EN_ADDR, 0x3e);
    }
  }

  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_POL_INV_ADDR,              0x0a);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_POL_INV_ADDR,              0x0a);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x18);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_CFG_ADDR,                          0x19);

  if (HAL_MDSS_STATUS_SUCCESS == eStatus)
  {
    eStatus = HAL_DP_AltMode_Phy_Poll_PhyReady(eDeviceId, HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_STATUS_TSYNC_DONE_BMSK);
  }

  if (HAL_MDSS_STATUS_SUCCESS == eStatus)
  {
    // Configure pre-emphasis & driver strength - these may be changed during link training
    HAL_DP_PeSwConfigType  sPeSwConfig;

    sPeSwConfig.uLaneSwingLevel   = pDPPllConfigInfo->uVoltSwingLevel;
    sPeSwConfig.uPreemphasisLevel = pDPPllConfigInfo->uVoltSwingLevel;
    if (HAL_MDSS_STATUS_SUCCESS != HAL_DP_AltMode_1_2_0_PHY_SetupPeSw(eDeviceId, &sPeSwConfig))
    {
      eStatus = HAL_MDSS_DSI_FAILED_INVALID_INPUT_PARAMETER;
    }
  }

  if (HAL_DP_PLLCONFIG_FLAG_ASYNC & pDPPllConfigInfo->uFlags)
  {
    // Program external PLL to output pDPPllConfigInfo->uPixelClkMNDInputMhz - no support presently
    eStatus = HAL_MDSS_STATUS_FAILED_NOT_SUPPORTED;
  }

  return eStatus;
}


/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_Phy_Poll_PhyReady()
*/
/*!
* \DESCRIPTION
*     poll if Phy PLL status is ready.
*
* \param [in]   eDeviceId  - DP device ID
* \param [in]   uReadyMask - Ready mask to test against
* \param [out]  None
*
* \retval HAL_DP_StatusType
*
**********************************************************************************************/
static HAL_MDSS_ErrorType HAL_DP_AltMode_Phy_Poll_PhyReady(DP_DeviceIDType eDeviceId,
                                                           uint32          uReadyMask)
{
  HAL_MDSS_ErrorType    eStatus            = HAL_MDSS_STATUS_SUCCESS;
  uintPtr               uOffset            = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);
  uint32                uNumReadsRemaining = HAL_DP_PLL_POLL_MAX_READS;
  uint32                uStatus            = 0;

  /* Poll PHY_READY */
  do
  {
    HAL_DP_SLEEP_US(HAL_DP_PLL_POLL_TIMEOUT);  /* delay */
    uStatus = DP_PHY_REGREAD(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_STATUS_ADDR) & uReadyMask;
    uNumReadsRemaining--;
  } while ((!uStatus) && (uNumReadsRemaining));

  if (0 == (uReadyMask & uStatus))
  {
    eStatus = HAL_MDSS_DP_STATUS_FAILED;
  }
  return eStatus;
}

/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_Phy_Poll_CReady()
*/
/*!
* \DESCRIPTION
*     poll if C_Ready PLL status is ready.
*
* \param [in]  eDeviceId - DP device ID
* \param [out] None
*
* \retval HAL_DP_StatusType
*
**********************************************************************************************/
static HAL_MDSS_ErrorType HAL_DP_AltMode_Phy_Poll_CReady(DP_DeviceIDType eDeviceId)
{
  uintPtr uOffset  = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);
  uint32  uPllBase = AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_COM_DP_QSERDES_COM_USB3_DP_QMP_PLL_REG_BASE;

  return HAL_DP_PHY_Qmp_Pll_7nm_Poll_Cready(uOffset + uPllBase);
}

/* -----------------------------------------------------------------------
** Public Functions
** ----------------------------------------------------------------------- */

/****************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_PHY_Config()
*/
/*!
* \DESCRIPTION
*   Configure DP PHY and PLL based on desired rates
*
* \param [in]  eDeviceId        - DP device ID
* \param [in]  pDPPllConfigInfo - DP PHY PLL config info
*
* \retval boolean  TRUE = success, FALSE = fail
*
****************************************************************************/
bool32 HAL_DP_AltMode_1_2_0_PHY_Config(DP_DeviceIDType       eDeviceId,
                                       HAL_DP_PllConfigType *pDPPllConfigInfo)
{
  bool32      bStatus    = FALSE;
  uintPtr     uOffset    = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);

  /* program DP PLL and PHY */
  bStatus = (HAL_MDSS_STATUS_SUCCESS == HAL_DP_AltMode_Phy_Pll_Config(eDeviceId,
                                                                    pDPPllConfigInfo));

  if (!bStatus)
  {
    /* Requested settings not supported or config failed : Power down */
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR, 0x02);  // Power down whole DP PHY
  }

  return bStatus;
}


/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_0_PHY_Reset()
*/
/*!
* \brief
*        Reset and initialize DP PHY 
*
* \param [in]  eDeviceId - DP device ID
*
* \retval 
*
**********************************************************************************************/
void HAL_DP_AltMode_1_2_0_PHY_Reset(DP_DeviceIDType eDeviceId)
{
  //#TODO#IMPLEMENT
}

/****************************************************************************
*
** FUNCTION: HAL_DP_AltMode_PHY_SetPHYMode()
*/
/*!
* \DESCRIPTION
*           Set the QMP PHY Mode to DP or USB3
*
* \param [in]  eDeviceId - DP device ID
* \param [in]  bDPMode   - TRUE: DP mode,  FALSE: USB3 Mode
*
* \retval
*
****************************************************************************/
void HAL_DP_AltMode_1_2_0_PHY_SetPHYMode(DP_DeviceIDType eDeviceId,
                                         bool32          bDPMode)
{
  uintPtr               uOffset     = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);

  if (bDPMode)
  {
    // USB3 disabled and DP enabled
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_PHY_MODE_CTRL_ADDR, 0x02);
  }
  else
  {
    // USB3 enabled and DP disabled
    DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_USB3_DP_COM_PHY_MODE_CTRL_ADDR, 0x1);
  }
}
/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_PHY_AUX_Init()
*/
/*!
* \brief
*        Initialize DP AUX PHY 
*
* \param [in]  eDeviceId - DP device ID
*
* \retval 
*
**********************************************************************************************/
void HAL_DP_AltMode_1_2_0_PHY_AUX_Init(DP_DeviceIDType eDeviceId)
{
  uintPtr               uOffset     = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);

  // Power on
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR, 0x02);  // Power down whole DP PHY
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_PD_CTL_ADDR, 0x7d);  // Power on DP PHY

  // #TODO#VERIFY - already done during qmp pll init
  // Turn on BIAS current for PHY/PLL
  // DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_COM_BIAS_EN_CLKBUFLR_EN_ADDR, 0x3f);

  // Recommended settings
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG1_ADDR, 0x13);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG2_ADDR, 0x04);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG3_ADDR, 0x00);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG4_ADDR, 0x0a);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG5_ADDR, 0x26);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG6_ADDR, 0x0a);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG7_ADDR, 0x03);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG8_ADDR, 0xBB);
  DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG9_ADDR, 0x03);

}

/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_PHY_SetupPeSw()
*/
/*!
* \brief
*        Set up DP Lane Pre Emphasis and voltage swing level
*
* \param [in]     eDeviceId   - DP device ID
* \param [in/out] pPeSwConfig - Pre-emphasis/Swing level settings.
*
* \retval  HAL_MDSS_ErrorType
*
**********************************************************************************************/
HAL_MDSS_ErrorType HAL_DP_AltMode_1_2_0_PHY_SetupPeSw(DP_DeviceIDType        eDeviceId, 
                                                      HAL_DP_PeSwConfigType *pPeSwConfig)
{
  HAL_MDSS_ErrorType  eStatus       = HAL_MDSS_STATUS_FAILED_NOT_SUPPORTED;
  uintPtr             uOffset       = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);

  pPeSwConfig->bPreemphNotSupported = FALSE;
  pPeSwConfig->bSwingNotsupported   = FALSE;

  if (pPeSwConfig->uPreemphasisLevel >= DP_PREEMPHASIS_LEVEL_NUM)
  {
    pPeSwConfig->bPreemphNotSupported = TRUE;
  }
  else if (pPeSwConfig->uLaneSwingLevel >= DP_VOLTAGESWING_LEVEL_NUM)
  {
    pPeSwConfig->bSwingNotsupported   = TRUE;
  }
  else
  {
    uint32 uPreEmphasisReg  = aPeSwPair[pPeSwConfig->uLaneSwingLevel][pPeSwConfig->uPreemphasisLevel].uPreEmphasis;
    uint32 uVoltageSwingReg = aPeSwPair[pPeSwConfig->uLaneSwingLevel][pPeSwConfig->uPreemphasisLevel].uVoltageSwing;

    if (0 == uPreEmphasisReg)
    {
      pPeSwConfig->bSwingNotsupported   = TRUE;
    }
    else
    {

      DP_LOG_MESSAGE_INFO("HAL_DP_AltMode_1_2_0_Phy_SetupPeSw: pe=%x sw=%x, pl=%d sl=%d\n", uPreEmphasisReg, uVoltageSwingReg, pPeSwConfig->uPreemphasisLevel, pPeSwConfig->uLaneSwingLevel);

      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_DRV_LVL_ADDR,       uVoltageSwingReg);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX0_TX_EMP_POST1_LVL_ADDR, uPreEmphasisReg);

      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_DRV_LVL_ADDR,       uVoltageSwingReg);
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_QSERDES_TX1_TX_EMP_POST1_LVL_ADDR,  uPreEmphasisReg);

      eStatus = HAL_MDSS_STATUS_SUCCESS;
    }
  }

  return eStatus;
}

/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_PHY_GetMaxPeSwLevel()
*/
/*!
* \brief
*        Get max supported DP Lane Pre Emphasis and voltage swing levels
*
* \param [in]  eDeviceId        - DP device ID
* \param [out] uMaxPreemphLvl   - max Pre-emphasis level supported.
* \param [out] uMaxVoltSwingLvl - max voltage swing level supported.
*
* \retval  void
*
**********************************************************************************************/
void HAL_DP_AltMode_1_2_0_PHY_GetMaxPeSwLevel(DP_DeviceIDType  eDeviceId,
                                              uint32          *uMaxPreemphLvl,
                                              uint32          *uMaxVoltSwingLvl)
{
  *uMaxPreemphLvl   = DP_PREEMPHASIS_LEVEL_NUM - 1;
  *uMaxVoltSwingLvl = DP_VOLTAGESWING_LEVEL_NUM - 1;
}

/*********************************************************************************************
*
** FUNCTION: HAL_DP_AltMode_1_2_0_PHY_AUXConfig()
*/
/*!
* \brief
*        Config AUX PHY registers
*
* \param [in] eDeviceId  - DP device ID
* \param [in] pAuxPhyCfg - AUX PHY settings.
*
* \retval  HAL_MDSS_ErrorType
*
**********************************************************************************************/
HAL_MDSS_ErrorType HAL_DP_AltMode_1_2_0_PHY_AUXConfig(DP_DeviceIDType       eDeviceId,
                                                      HAL_DP_AuxPhyCfgType *pAuxPhyCfg)
{
  HAL_MDSS_ErrorType eStatus = HAL_MDSS_STATUS_FAILED_NOT_SUPPORTED;
  uintPtr            uOffset = HAL_DP_AltMode_GetRegBaseOffset(eDeviceId);

  if ((NULL != pAuxPhyCfg) &&
      (NULL != pAuxPhyCfg->pDPAuxPhyCfg1Index))
  {
    if (*pAuxPhyCfg->pDPAuxPhyCfg1Index < DP_AUX_CFG_SETTINGS_LEN)
    {
      DP_PHY_REGWRITE(uOffset + HWIO_AHB2PHY_SOUTH_USB3_DP_PHY_DP_DP_PHY_AUX_CFG1_ADDR, aAuxPhyCfg1Setting[*pAuxPhyCfg->pDPAuxPhyCfg1Index]);

      eStatus = HAL_MDSS_STATUS_SUCCESS;
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: HAL_DP_AltMode_PhyFxnsInit()
*/
/*!
* \DESCRIPTION
*   Initialize DP PHY/PLL function table
*
* \param [in]  pFxnTable - Pointer to DP PHY function table
*
* \retval None
*
****************************************************************************/
void HAL_DP_AltMode_1_2_0_PhyFxnsInit(HAL_DP_PhyPllFunctionTable *pFxnTable)
{
  pFxnTable->HAL_DP_PHY_Config          = HAL_DP_AltMode_1_2_0_PHY_Config;
  pFxnTable->HAL_DP_PHY_Reset           = HAL_DP_AltMode_1_2_0_PHY_Reset;
  pFxnTable->HAL_DP_PHY_AUX_Init        = HAL_DP_AltMode_1_2_0_PHY_AUX_Init;
  pFxnTable->HAL_DP_PHY_SetupPeSw       = HAL_DP_AltMode_1_2_0_PHY_SetupPeSw;
  pFxnTable->HAL_DP_PHY_GetMaxPeSwLevel = HAL_DP_AltMode_1_2_0_PHY_GetMaxPeSwLevel;
  pFxnTable->HAL_DP_PHY_AUXConfig       = HAL_DP_AltMode_1_2_0_PHY_AUXConfig;
  pFxnTable->HAL_DP_PHY_SetPHYMode      = HAL_DP_AltMode_1_2_0_PHY_SetPHYMode;
}


#ifdef __cplusplus
}
#endif

