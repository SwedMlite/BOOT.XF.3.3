/*=======================================================================*//**
 * @file        qusb_phy_settings.c
 * @author:     kameya
 * @date        19-Jan-2016
 *
 * @brief       QUSB (Qualcomm High-Speed USB) High Speed(HS) and 
 *              Super Speed (SS) PHY settings.
 *
 * @details     This file contains settings of the HS PHY.
 *
 * @note        
 *
 * 
*//*========================================================================*/
//============================================================================
/**
  Copyright (c) 2016-2018 Qualcomm Technologies, Inc. All rights reserved.
  Portions Copyright (c) 2007 - 2013 Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php
  
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 */
//============================================================================
// ===========================================================================
// 
//                            EDIT HISTORY FOR FILE
//   This section contains comments describing changes made to the module.
//   Notice that changes are listed in reverse chronological order.
// 
// 
// when          who     what, where, why
// ----------   -----    ----------------------------------------------------------
// 2017-06-06    pm      Updated SS Phy sequence for primary port from Latest HPG 
// 2017-04-26    amitg   Updated QUSB2 Phy confirguration for Host mode low speed devices
// 2017-03-30    pm      Added Configuration for Secondary Core
// 2016-01-19    kameya  First Draft
// 
// ===========================================================================

//----------------------------------------------------------------------------
// Include Files
//----------------------------------------------------------------------------
#include "comdef.h" // basic types as byte word uint32 etc
#include "../../Include/HalusbHWIO.h"

#include "UsbSharedLib.h"


//----------------------------------------------------------------------------
// Static Variable Definitions
//----------------------------------------------------------------------------


//============================================================================
// QUSB High-Speed Primary PHY Configuration Array
//============================================================================

static const qusb_phy_cfg_type qusb_dci_hs_phy_cfg[] = 
  {
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 0  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 1  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 2  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 3  
    //--------------------------------------------------------------------------------------
    { HWIO_USB2PHY_USB_PHY_PARAMETER_OVERRIDE_X0_ADDR,  (0x61) }, // 4  
    { HWIO_USB2PHY_USB_PHY_PARAMETER_OVERRIDE_X1_ADDR,  (0x43) }, // 5  
    { HWIO_USB2PHY_USB_PHY_PARAMETER_OVERRIDE_X2_ADDR,  (0x2E) }, // 6  
    { HWIO_USB2PHY_USB_PHY_PARAMETER_OVERRIDE_X3_ADDR,  (0x03) }, // 7  
    //--------------------------------------------------------------------------------------
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 8  
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 9  
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 10 
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 11 
    //--------------------------------------------------------------------------------------
  };

//============================================================================
// QUSB Super-Speed Primary PHY Configuration Array
//============================================================================
// cm_usb3_dp_con_USB3_Config_for_Kona_1.02 on May 13, 2019
static const qusb_phy_cfg_type qusb_dci_ss_phy_cfg_common[] =
{
  { HWIO_USB3_DP_PHY_USB3_DP_COM_POWER_DOWN_CTRL_ADDR,                            (0x01) }, // 0  
  { HWIO_USB3_DP_PHY_USB3_PCS_POWER_DOWN_CONTROL_ADDR,                            (0x01) }, // 1  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_EN_CENTER_ADDR,                         (0x01) }, // 2  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_PER1_ADDR,                              (0x31) }, // 3  
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_PER2_ADDR,                              (0x01) }, // 4  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_STEP_SIZE1_MODE0_ADDR,                  (0xDE) }, // 5  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_STEP_SIZE2_MODE0_ADDR,                  (0x07) }, // 6  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_STEP_SIZE1_MODE1_ADDR,                  (0xDE) }, // 7  
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SSC_STEP_SIZE2_MODE1_ADDR,                  (0x07) }, // 8  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SYSCLK_BUF_ENABLE_ADDR,                     (0x0A) }, // 9  
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_CMN_IPTRIM_ADDR,                            (0x20) }, // 10 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_CP_CTRL_MODE0_ADDR,                         (0x06) }, // 11 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_CP_CTRL_MODE1_ADDR,                         (0x06) }, // 12 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_PLL_RCTRL_MODE0_ADDR,                       (0x16) }, // 13 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_PLL_RCTRL_MODE1_ADDR,                       (0x16) }, // 14 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_PLL_CCTRL_MODE0_ADDR,                       (0x36) }, // 15 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_PLL_CCTRL_MODE1_ADDR,                       (0x36) }, // 16 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_SYSCLK_EN_SEL_ADDR,                         (0x1A) }, // 17 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_LOCK_CMP_EN_ADDR,                           (0x04) }, // 18 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_LOCK_CMP1_MODE0_ADDR,                       (0x14) }, // 19 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_LOCK_CMP2_MODE0_ADDR,                       (0x34) }, // 20 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_LOCK_CMP1_MODE1_ADDR,                       (0x34) }, // 21 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_LOCK_CMP2_MODE1_ADDR,                       (0x82) }, // 22 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DEC_START_MODE0_ADDR,                       (0x82) }, // 23 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DEC_START_MODE1_ADDR,                       (0x82) }, // 24 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START1_MODE0_ADDR,                 (0xAB) }, // 25 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START2_MODE0_ADDR,                 (0xEA) }, // 26 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START3_MODE0_ADDR,                 (0x02) }, // 27 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START1_MODE1_ADDR,                 (0xAB) }, // 28 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START2_MODE1_ADDR,                 (0xEA) }, // 29 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_DIV_FRAC_START3_MODE1_ADDR,                 (0x02) }, // 30 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_VCO_TUNE_MAP_ADDR,                          (0x02) }, // 31 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_VCO_TUNE1_MODE0_ADDR,                       (0x24) }, // 32 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_VCO_TUNE1_MODE1_ADDR,                       (0x24) }, // 33 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_VCO_TUNE2_MODE1_ADDR,                       (0x02) }, // 34 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_HSCLK_SEL_ADDR,                             (0x01) }, // 35 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_CORECLK_DIV_MODE1_ADDR,                     (0x08) }, // 36 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE0_ADDR,            (0xCA) }, // 37 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE0_ADDR,            (0x1E) }, // 38 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE1_ADDR,            (0xCA) }, // 39 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE1_ADDR,            (0x1E) }, // 40 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_COM_BIN_VCOCAL_HSCLK_SEL_ADDR,                  (0x11) }, // 41 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_RES_CODE_LANE_TX_ADDR,                      (0x60) }, // 42 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_RES_CODE_LANE_RX_ADDR,                      (0x60) }, // 43 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_RES_CODE_LANE_OFFSET_TX_ADDR,               (0x11) }, // 44 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_RES_CODE_LANE_OFFSET_RX_ADDR,               (0x02) }, // 45 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_LANE_MODE_1_ADDR,                           (0xD5) }, // 46 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_RCV_DETECT_LVL_2_ADDR,                      (0x12) }, // 47 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXA_PI_QEC_CTRL_ADDR,                           (0x40) }, // 48 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SO_GAIN_ADDR,                          (0x06) }, // 49 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_FASTLOCK_FO_GAIN_ADDR,                 (0x2F) }, // 50 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SO_SATURATION_AND_ENABLE_ADDR,         (0x7F) }, // 51 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_FASTLOCK_COUNT_LOW_ADDR,               (0xFF) }, // 52 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_FASTLOCK_COUNT_HIGH_ADDR,              (0x0F) }, // 53 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_PI_CONTROLS_ADDR,                      (0x99) }, // 54 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SB2_THRESH1_ADDR,                      (0x04) }, // 55 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SB2_THRESH2_ADDR,                      (0x08) }, // 56 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SB2_GAIN1_ADDR,                        (0x05) }, // 57 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_UCDR_SB2_GAIN2_ADDR,                        (0x05) }, // 58 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_VGA_CAL_CNTRL1_ADDR,                        (0x54) }, // 59 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_VGA_CAL_CNTRL2_ADDR,                        (0x0C) }, // 60 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_EQU_ADAPTOR_CNTRL2_ADDR,                 (0x0F) }, // 61 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_EQU_ADAPTOR_CNTRL3_ADDR,                 (0x4A) }, // 62 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_EQU_ADAPTOR_CNTRL4_ADDR,                 (0x0A) }, // 63 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_IDAC_TSETTLE_LOW_ADDR,                   (0xC0) }, // 64 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_IDAC_TSETTLE_HIGH_ADDR,                  (0x00) }, // 65 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_EQ_OFFSET_ADAPTOR_CNTRL1_ADDR,           (0x77) }, // 66 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_SIGDET_CNTRL_ADDR,                          (0x04) }, // 67 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_SIGDET_DEGLITCH_CNTRL_ADDR,                 (0x0E) }, // 68 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_00_LOW_ADDR,                        (0xFF) }, // 69 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_00_HIGH_ADDR,                       (0x7F) }, // 70 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_00_HIGH2_ADDR,                      (0x7F) }, // 71 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_00_HIGH3_ADDR,                      (0x7F) }, // 72 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_00_HIGH4_ADDR,                      (0x97) }, // 73 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_01_LOW_ADDR,                        (0xDC) }, // 74 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_01_HIGH_ADDR,                       (0xDC) }, // 75 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_01_HIGH2_ADDR,                      (0x5C) }, // 76 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_01_HIGH3_ADDR,                      (0x7B) }, // 77 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_RX_MODE_01_HIGH4_ADDR,                      (0xB4) }, // 78 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_DFE_EN_TIMER_ADDR,                          (0x04) }, // 79 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_DFE_CTLE_POST_CAL_OFFSET_ADDR,              (0x38) }, // 80 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_AUX_DATA_TCOARSE_TFINE_ADDR,                (0xA0) }, // 81 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_DCC_CTRL1_ADDR,                             (0x0C) }, // 82 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_GM_CAL_ADDR,                                (0x1F) }, // 83 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXA_VTH_CODE_ADDR,                              (0x10) }, // 84 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_RES_CODE_LANE_TX_ADDR,                      (0x60) }, // 85 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_RES_CODE_LANE_RX_ADDR,                      (0x60) }, // 86 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_RES_CODE_LANE_OFFSET_TX_ADDR,               (0x11) }, // 87 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_RES_CODE_LANE_OFFSET_RX_ADDR,               (0x02) }, // 88 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_LANE_MODE_1_ADDR,                           (0xD5) }, // 89 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_RCV_DETECT_LVL_2_ADDR,                      (0x12) }, // 90 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_TXB_PI_QEC_CTRL_ADDR,                           (0x54) }, // 91 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SO_GAIN_ADDR,                          (0x06) }, // 92 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_FASTLOCK_FO_GAIN_ADDR,                 (0x2F) }, // 93 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SO_SATURATION_AND_ENABLE_ADDR,         (0x7F) }, // 94 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_FASTLOCK_COUNT_LOW_ADDR,               (0xFF) }, // 95 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_FASTLOCK_COUNT_HIGH_ADDR,              (0x0F) }, // 96 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_PI_CONTROLS_ADDR,                      (0x99) }, // 97 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SB2_THRESH1_ADDR,                      (0x04) }, // 98 
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SB2_THRESH2_ADDR,                      (0x08) }, // 99 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SB2_GAIN1_ADDR,                        (0x05) }, // 100
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_UCDR_SB2_GAIN2_ADDR,                        (0x05) }, // 101
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_VGA_CAL_CNTRL1_ADDR,                        (0x54) }, // 102
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_VGA_CAL_CNTRL2_ADDR,                        (0x0C) }, // 103
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_EQU_ADAPTOR_CNTRL2_ADDR,                 (0x0F) }, // 104
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_EQU_ADAPTOR_CNTRL3_ADDR,                 (0x4A) }, // 105
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_EQU_ADAPTOR_CNTRL4_ADDR,                 (0x0A) }, // 106
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_IDAC_TSETTLE_LOW_ADDR,                   (0xC0) }, // 107
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_IDAC_TSETTLE_HIGH_ADDR,                  (0x00) }, // 108
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_EQ_OFFSET_ADAPTOR_CNTRL1_ADDR,           (0x77) }, // 109
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_SIGDET_CNTRL_ADDR,                          (0x04) }, // 110
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_SIGDET_DEGLITCH_CNTRL_ADDR,                 (0x0E) }, // 111
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_00_LOW_ADDR,                        (0x7F) }, // 112
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_00_HIGH_ADDR,                       (0xFF) }, // 113
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_00_HIGH2_ADDR,                      (0x7F) }, // 114
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_00_HIGH3_ADDR,                      (0x7F) }, // 115
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_00_HIGH4_ADDR,                      (0x97) }, // 116
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_01_LOW_ADDR,                        (0xDC) }, // 117
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_01_HIGH_ADDR,                       (0xDC) }, // 118
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_01_HIGH2_ADDR,                      (0x5C) }, // 119
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_01_HIGH3_ADDR,                      (0x7B) }, // 120
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_RX_MODE_01_HIGH4_ADDR,                      (0xB4) }, // 121
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_DFE_EN_TIMER_ADDR,                          (0x04) }, // 122
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_DFE_CTLE_POST_CAL_OFFSET_ADDR,              (0x38) }, // 123
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_AUX_DATA_TCOARSE_TFINE_ADDR,                (0xA0) }, // 124
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_DCC_CTRL1_ADDR,                             (0x0C) }, // 125
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_GM_CAL_ADDR,                                (0x1F) }, // 126
  { HWIO_USB3_DP_PHY_USB3_QSERDES_RXB_VTH_CODE_ADDR,                              (0x10) }, // 127
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_PCS_LOCK_DETECT_CONFIG1_ADDR,                           (0xD0) }, // 128
  { HWIO_USB3_DP_PHY_USB3_PCS_LOCK_DETECT_CONFIG2_ADDR,                           (0x07) }, // 129
  { HWIO_USB3_DP_PHY_USB3_PCS_LOCK_DETECT_CONFIG3_ADDR,                           (0x20) }, // 130
  { HWIO_USB3_DP_PHY_USB3_PCS_LOCK_DETECT_CONFIG6_ADDR,                           (0x13) }, // 131
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_PCS_REFGEN_REQ_CONFIG1_ADDR,                            (0x21) }, // 132
  { HWIO_USB3_DP_PHY_USB3_PCS_RX_SIGDET_LVL_ADDR,                                 (0xA9) }, // 133
  { HWIO_USB3_DP_PHY_USB3_PCS_CDR_RESET_TIME_ADDR,                                (0x0A) }, // 134
  { HWIO_USB3_DP_PHY_USB3_PCS_ALIGN_DETECT_CONFIG1_ADDR,                          (0x88) }, // 135
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_PCS_ALIGN_DETECT_CONFIG2_ADDR,                          (0x13) }, // 136
  { HWIO_USB3_DP_PHY_USB3_PCS_PCS_TX_RX_CONFIG_ADDR,                              (0x0C) }, // 137
  { HWIO_USB3_DP_PHY_USB3_PCS_EQ_CONFIG1_ADDR,                                    (0x4B) }, // 138
  { HWIO_USB3_DP_PHY_USB3_PCS_EQ_CONFIG5_ADDR,                                    (0x10) }, // 139
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_DP_PHY_USB3_PCS_USB3_LFPS_DET_HIGH_COUNT_VAL_ADDR,                  (0xF8) }, // 140
  { HWIO_USB3_DP_PHY_USB3_PCS_USB3_RXEQTRAINING_DFE_TIME_S2_ADDR,                 (0x07) }, // 141
  { QUSB_HWIO_ADDR_END,                                                           (0x00) }, // 142                                                       (0x00) }, // 142
};

static const uint32 qusb_dci_hs_phy_cfg_size = (sizeof(qusb_dci_hs_phy_cfg)/sizeof(qusb_phy_cfg_type));
static const uint32 qusb_dci_ss_phy_cfg_common_size = (sizeof(qusb_dci_ss_phy_cfg_common)/sizeof(qusb_phy_cfg_type));


//============================================================================
// QUSB Super-Speed Secondary PHY Configuration Array
//============================================================================
//Move to usbsharedlib.c

