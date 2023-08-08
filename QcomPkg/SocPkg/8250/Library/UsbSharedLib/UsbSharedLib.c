/*=======================================================================*//**
 * @file        UsbSharedInit.c
 * @author:     pmahajan
 * @date        03-feb-2017
 *
 * @brief       USB common & shared USB core init implementation.
 *
 * @details     This file contains API's the Init sequence for HS and SS core implementation.
 *
 * @note        
 *              Copyright 2017 QUALCOMM Technologies Incorporated.
 *              All Rights Reserved.
 *              Qualcomm Confidential and Proprietary
 * 
*//*========================================================================*/

// ===========================================================================
// 
//                            EDIT HISTORY FOR FILE
//   This section contains comments describing changes made to the module.
//   Notice that changes are listed in reverse chronological order.
// 
// 
// when          who     what, where, why
// ----------   -----    ----------------------------------------------------------
// 03/30/17     pm       Added configuration for sec Clock and core
// 02/03/17     pm       Initial revision
// 
// ===========================================================================

//----------------------------------------------------------------------------
// Include Files
//----------------------------------------------------------------------------
#include "DALSys.h"    // To get phy settings
#include "qusb_log.h"
#include "qusb_dci_common.h"
#include "UsbSharedLib.h"
#include "HalusbHWIO.h"

#include <stdio.h>
#include <string.h>

#define USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US         (10000)

boolean qusb_dci_ss_lane_phy_override     = FALSE;
boolean qusb_dci_ss_phy_no_csr_reset      = FALSE;

#define QUSB_DCI_HS_PHY_SEC_CFG_ARRAY_ENTRY_CNT (sizeof(qusb_dci_hs_phy_sec_cfg)/sizeof(qusb_phy_cfg_type))
#define QUSB_DCI_SS_PHY_SEC_COMMON_CFG_ARRAY_ENTRY_CNT (sizeof(qusb_dci_ss_phy_sec_cfg_common)/sizeof(qusb_phy_cfg_type))

//============================================================================
// QUSB High-Speed Secondary PHY Configuration Array
//============================================================================
static const qusb_phy_cfg_type qusb_dci_hs_phy_sec_cfg[] = 
  {
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 0  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 1  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 2  
    { QUSB_HWIO_ADDR_EMPTY,                         (0x00) }, // 3  
    //--------------------------------------------------------------------------------------
    { HWIO_USB2PHY_SEC_USB_PHY_PARAMETER_OVERRIDE_X0_ADDR,  (0x61) }, // 4  
    { HWIO_USB2PHY_SEC_USB_PHY_PARAMETER_OVERRIDE_X1_ADDR,  (0x43) }, // 5  
    { HWIO_USB2PHY_SEC_USB_PHY_PARAMETER_OVERRIDE_X2_ADDR,  (0x2E) }, // 6  
    { HWIO_USB2PHY_SEC_USB_PHY_PARAMETER_OVERRIDE_X3_ADDR,  (0x03) }, // 7  
    //--------------------------------------------------------------------------------------
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 8  
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 9  
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 10 
    { QUSB_HWIO_ADDR_END,                           (0x00) }, // 11 
    //--------------------------------------------------------------------------------------
  };

// cm_pcie_usb3_uni_USB3_Config_for_Huracan_Kona_1.03 on April 26, 2019 
static const qusb_phy_cfg_type qusb_dci_ss_phy_sec_cfg_common[] =
{
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_POWER_DOWN_CONTROL_ADDR,                  (0x01) }, // 0  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SYSCLK_EN_SEL_ADDR,                             (0x1A) }, // 1  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_BIN_VCOCAL_HSCLK_SEL_ADDR,                      (0x11) }, // 2  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_HSCLK_SEL_ADDR,                                 (0x01) }, // 3  
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DEC_START_MODE0_ADDR,                           (0x82) }, // 4  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START1_MODE0_ADDR,                     (0xAB) }, // 5  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START2_MODE0_ADDR,                     (0xEA) }, // 6  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START3_MODE0_ADDR,                     (0x02) }, // 7  
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE0_ADDR,                (0xCA) }, // 8  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE0_ADDR,                (0x1E) }, // 9  
  { HWIO_USB3_UNI_PHY_QSERDES_COM_CP_CTRL_MODE0_ADDR,                             (0x06) }, // 10 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_PLL_RCTRL_MODE0_ADDR,                           (0x16) }, // 11 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_PLL_CCTRL_MODE0_ADDR,                           (0x36) }, // 12 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_VCO_TUNE1_MODE0_ADDR,                           (0x24) }, // 13 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_LOCK_CMP2_MODE0_ADDR,                           (0x34) }, // 14 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_LOCK_CMP1_MODE0_ADDR,                           (0x14) }, // 15 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_LOCK_CMP_EN_ADDR,                               (0x04) }, // 16 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SYSCLK_BUF_ENABLE_ADDR,                         (0x0A) }, // 17 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_VCO_TUNE2_MODE1_ADDR,                           (0x02) }, // 18 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_VCO_TUNE1_MODE1_ADDR,                           (0x24) }, // 19 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_CORECLK_DIV_MODE1_ADDR,                         (0x08) }, // 20 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DEC_START_MODE1_ADDR,                           (0x82) }, // 21 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START1_MODE1_ADDR,                     (0xAB) }, // 22 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START2_MODE1_ADDR,                     (0xEA) }, // 23 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_DIV_FRAC_START3_MODE1_ADDR,                     (0x02) }, // 24 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_LOCK_CMP2_MODE1_ADDR,                           (0x82) }, // 25 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_LOCK_CMP1_MODE1_ADDR,                           (0x34) }, // 26 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_CP_CTRL_MODE1_ADDR,                             (0x06) }, // 27 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_PLL_RCTRL_MODE1_ADDR,                           (0x16) }, // 28 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_PLL_CCTRL_MODE1_ADDR,                           (0x36) }, // 29 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE1_ADDR,                (0xCA) }, // 30 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE1_ADDR,                (0x1E) }, // 31 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_CMN_IPTRIM_ADDR,                                (0x20) }, // 32 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_EN_CENTER_ADDR,                             (0x01) }, // 33 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_PER1_ADDR,                                  (0x31) }, // 34 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_PER2_ADDR,                                  (0x01) }, // 35 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_STEP_SIZE1_MODE1_ADDR,                      (0xDE) }, // 36 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_STEP_SIZE2_MODE1_ADDR,                      (0x07) }, // 37 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_STEP_SIZE1_MODE0_ADDR,                      (0xDE) }, // 38 
  { HWIO_USB3_UNI_PHY_QSERDES_COM_SSC_STEP_SIZE2_MODE0_ADDR,                      (0x07) }, // 39 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_COM_VCO_TUNE_MAP_ADDR,                              (0x02) }, // 40 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_00_HIGH4_ADDR,                           (0xB8) }, // 41 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_00_HIGH3_ADDR,                           (0xFF) }, // 42 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_00_HIGH2_ADDR,                           (0xBF) }, // 43 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_00_HIGH_ADDR,                            (0x7F) }, // 44 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_00_LOW_ADDR,                             (0x7F) }, // 45 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_01_HIGH4_ADDR,                           (0xB4) }, // 46 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_01_HIGH3_ADDR,                           (0x7B) }, // 47 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_01_HIGH2_ADDR,                           (0x5C) }, // 48 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_01_HIGH_ADDR,                            (0xDC) }, // 49 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_MODE_01_LOW_ADDR,                             (0xDC) }, // 50 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_PI_CONTROLS_ADDR,                           (0x99) }, // 51 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SB2_THRESH1_ADDR,                           (0x04) }, // 52 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SB2_THRESH2_ADDR,                           (0x08) }, // 53 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SB2_GAIN1_ADDR,                             (0x05) }, // 54 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SB2_GAIN2_ADDR,                             (0x05) }, // 55 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_FASTLOCK_FO_GAIN_ADDR,                      (0x2F) }, // 56 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_FASTLOCK_COUNT_LOW_ADDR,                    (0xFF) }, // 57 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_FASTLOCK_COUNT_HIGH_ADDR,                   (0x0F) }, // 58 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SO_SATURATION_AND_ENABLE_ADDR,              (0x7F) }, // 59 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_FO_GAIN_ADDR,                               (0x08) }, // 60 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_VGA_CAL_CNTRL1_ADDR,                             (0x54) }, // 61 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_VGA_CAL_CNTRL2_ADDR,                             (0x0C) }, // 62 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_EQU_ADAPTOR_CNTRL2_ADDR,                      (0x0F) }, // 63 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_EQU_ADAPTOR_CNTRL3_ADDR,                      (0x4A) }, // 64 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_EQU_ADAPTOR_CNTRL4_ADDR,                      (0x0A) }, // 65 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_DFE_EN_TIMER_ADDR,                               (0x04) }, // 66 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_EQ_OFFSET_ADAPTOR_CNTRL1_ADDR,                (0x47) }, // 67 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_OFFSET_ADAPTOR_CNTRL2_ADDR,                   (0x80) }, // 68 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_SIGDET_CNTRL_ADDR,                               (0x04) }, // 69 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_SIGDET_DEGLITCH_CNTRL_ADDR,                      (0x0E) }, // 70 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_IDAC_TSETTLE_HIGH_ADDR,                       (0x00) }, // 71 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_RX_IDAC_TSETTLE_LOW_ADDR,                        (0xC0) }, // 72 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_DFE_CTLE_POST_CAL_OFFSET_ADDR,                   (0x38) }, // 73 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_UCDR_SO_GAIN_ADDR,                               (0x04) }, // 74 
  { HWIO_USB3_UNI_PHY_QSERDES_RX_DCC_CTRL1_ADDR,                                  (0x0C) }, // 75 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_RX_GM_CAL_ADDR,                                     (0x1F) }, // 76 
  { HWIO_USB3_UNI_PHY_QSERDES_TX_RCV_DETECT_LVL_2_ADDR,                           (0x12) }, // 77 
  { HWIO_USB3_UNI_PHY_QSERDES_TX_LANE_MODE_1_ADDR,                                (0xD5) }, // 78 
  { HWIO_USB3_UNI_PHY_QSERDES_TX_LANE_MODE_2_ADDR,                                (0x82) }, // 79 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_QSERDES_TX_PI_QEC_CTRL_ADDR,                                (0x40) }, // 80 
  { HWIO_USB3_UNI_PHY_QSERDES_TX_RES_CODE_LANE_OFFSET_TX_ADDR,                    (0x11) }, // 81 
  { HWIO_USB3_UNI_PHY_QSERDES_TX_RES_CODE_LANE_OFFSET_RX_ADDR,                    (0x02) }, // 82 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_LOCK_DETECT_CONFIG1_ADDR,                 (0xD0) }, // 83 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_LOCK_DETECT_CONFIG2_ADDR,                 (0x07) }, // 84 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_LOCK_DETECT_CONFIG3_ADDR,                 (0x20) }, // 85 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_LOCK_DETECT_CONFIG6_ADDR,                 (0x13) }, // 86 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_RCVR_DTCT_DLY_P1U2_L_ADDR,                (0xE7) }, // 87 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_RCVR_DTCT_DLY_P1U2_H_ADDR,                (0x03) }, // 88 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_RX_SIGDET_LVL_ADDR,                       (0xA9) }, // 89 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_TX_RX_CONFIG_ADDR,                    (0x0C) }, // 90 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_USB3_RXEQTRAINING_DFE_TIME_S2_ADDR,       (0x07) }, // 91 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_USB3_LFPS_DET_HIGH_COUNT_VAL_ADDR,        (0xF8) }, // 92 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_CDR_RESET_TIME_ADDR,                      (0x0A) }, // 93 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_ALIGN_DETECT_CONFIG1_ADDR,                (0x88) }, // 94 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_ALIGN_DETECT_CONFIG2_ADDR,                (0x13) }, // 95 
  //--------------------------------------------------------------------------------------
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_EQ_CONFIG1_ADDR,                          (0x4B) }, // 96 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_EQ_CONFIG5_ADDR,                          (0x10) }, // 97 
  { HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_REFGEN_REQ_CONFIG1_ADDR,                  (0x21) }, // 98 
  { QUSB_HWIO_ADDR_END,                                                           (0x00) }, // 99
};


// ===========================================================================
/**
 * @function    usb_shared_lib_process_phy_reg_array
 * 
 * @brief   This function reads from array which define list of hwio writes for
 *          USB PHY
 * 
 * @param   cfg_array   - array holding address and value of HW register
 *          start_index     - starting index for array processing
 *          array_entry_cnt - number of entries in the array
 * 
 * @return  None
 * 
 */
// ===========================================================================
static void usb_shared_lib_process_phy_reg_array
  (
    const qusb_phy_cfg_type* phy_table,
    uint32        start_index, 
    uint32        array_entry_cnt
  )
  {
    uint32 index = start_index;
  
    if ( (NULL == phy_table)
        || (0 == array_entry_cnt) )
    {
      usb_shared_error_log(QUSB_DCI_PHY_REG_ARRAY_PROCESS__FAIL_LOG, 0, (uint32)phy_table);
      usb_shared_uart_log_error("Process_Array: Null Parameter Passed", (uint32)phy_table);
    }
    else
    {
      usb_shared_error_log(QUSB_DCI_PHY_REG_ARRAY_PROCESS__START_LOG, 0, start_index);

      for (; index < array_entry_cnt; index++)
      {
        if (QUSB_HWIO_ADDR_END == phy_table[index].address)
        {
          break;
        }
  
        if (QUSB_HWIO_ADDR_EMPTY == phy_table[index].address)
        {
          continue;
        }
        
        out_dword(phy_table[index].address, phy_table[index].value);
      }
    }
    usb_shared_error_log(QUSB_DCI_PHY_REG_ARRAY_PROCESS____END_LOG, 0, index);
  
}

//============================================================================

/**
* @function USB_SHARED_HS_PHY_INIT
*
* @brief    API used to initialize the High Speed Primary PHY 
*
*/
//============================================================================
boolean usb_shared_hs_phy_init()
{
  const char *hs_phy_cfg_prop_name = "hs_phy_cfg";
  DALSYSPropertyVar dal_hs_phy;
  const char *hs_phy_cfg_size_prop_name = "hs_phy_cfg_size";
  DALSYSPropertyVar dal_hs_phy_size;

  
  DALResult result;
  DALSYS_PROPERTY_HANDLE_DECLARE(hs_phy_cfg_h);

  usb_shared_uart_log_info("usb_shared_hs_phy_init: ++");
  
  /* get handle to hs phy settings */
  result = DALSYS_GetDALPropertyHandleStr("QUSB_PORT_PRIM", hs_phy_cfg_h);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_hs_phy_init: DALSYS_GetDALPropertyHandleStr Failed", result);
     return FALSE;
  }
  
  /* get hs phy cfg */
  result = DALSYS_GetPropertyValue(hs_phy_cfg_h, hs_phy_cfg_prop_name, 0, &dal_hs_phy);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_hs_phy_init: get hs phy cfg Failed", result);
     return FALSE;
  }

  /* get hs phy cfg size*/
  result = DALSYS_GetPropertyValue(hs_phy_cfg_h, hs_phy_cfg_size_prop_name, 0, &dal_hs_phy_size);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_hs_phy_init: get hs phy cfg size Failed", result);
     return FALSE;
  }
  usb_shared_uart_log_error("usb_shared_hs_phy_init: hs phy cfg size", dal_hs_phy_size.Val.dwVal);
    
  // Set UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
  // >> USB_PHY_CFG0[1] = 1; UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
  HWIO_USB2PHY_USB_PHY_CFG0_OUTM(HWIO_USB2PHY_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_SHFT);

  // Set the POR signal = 1 ; active high 
  // >> USB_PHY_UTMI_CTRL5[1] = 1 ; POR 
  HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_POR_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_POR_SHFT);

  // Set all strapping options:
  // >> Select reference clock frequency. FSEL[6:4] = 000; for 19.2MHz clock 
  //    USB_PHY_HS_PHY_CTRL_COMMON0[6:4] = 000; FSEL (Note: This control with register is not needed for default settings) 
  //    usb2phy_fsel[2:0]= 000, At the chip top, the usb2phy_fsel I/O need be tied off to 000 for default settings. 
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_FSEL_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_FSEL_SHFT);

  // Selects the PLL bandwidth, PLLBTUNE=1
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_PLLBTUNE_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_PLLBTUNE_SHFT);

  // >> Select reference clock source. REFCLKSEL[1:0] = 10; select the CLKCORE input 
  //    USB_PHY_REFCLK_CTRL[1:0] = 10; REFCLK_SEL 
  HWIO_USB2PHY_USB_PHY_REFCLK_CTRL_OUTM(HWIO_USB2PHY_USB_PHY_REFCLK_CTRL_REFCLK_SEL_BMSK, 0x2 << HWIO_USB2PHY_USB_PHY_REFCLK_CTRL_REFCLK_SEL_SHFT);

  // Select external VBUS valid by setting VBUSVLDEXTSEL0 to 1
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_VBUSVLDEXTSEL0_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON1_VBUSVLDEXTSEL0_SHFT);

  // VBUSVLDEXT0 is set to 1. This make VBUS signal valid.  Note, the VBUS and ID are not used in the femtoPHY.  
  // They are used in PMI and information needs to transferred from PMI to AOSS via the SPMI interface
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL1_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL1_VBUSVLDEXT0_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL1_VBUSVLDEXT0_SHFT);

  // Change to REXT (1), default is using EFUSE (0)
  HWIO_USB2PHY_USB_PHY_RTUNE_SEL_OUTM(HWIO_USB2PHY_USB_PHY_RTUNE_SEL_RTUNE_SEL_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_RTUNE_SEL_RTUNE_SEL_SHFT);

  // Set Parameter Override (if needed)
  usb_shared_lib_process_phy_reg_array(
      (const qusb_phy_cfg_type*) dal_hs_phy.Val.pStruct,
      0,
      (const uint32) dal_hs_phy_size.Val.dwVal);

  // Set VREGBYPASS = 1; The internal VREG18 is not used and bypassed. It requires VDDH= 1.8V power supply from outside 
  // >> USB_PHY_HS_PHY_CTRL_COMMON2[0] = 1; VREGBYPASS 
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON2_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON2_VREGBYPASS_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON2_VREGBYPASS_SHFT);

  // Set ATERESET = 0 or tie ATERESET with POR: PHYCLOCK is available after atereset is deasserted
  HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_ATERESET_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_ATERESET_SHFT);

  // Set TESTDATAOUTSEL to 0
  HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_TESTDATAOUTSEL_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_TESTDATAOUTSEL_SHFT);

  // Set TESTCLK = 0
  HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_TOGGLE_2WR_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_TEST1_TOGGLE_2WR_SHFT);

  // Set VATESTENB = 00
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_VATESTENB_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL_COMMON0_VATESTENB_SHFT);

  // Set TESTDATAIN bits to zero until PHYCLOCK is available  
  HWIO_USB2PHY_USB_PHY_HS_PHY_TEST0_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_TEST0_TESTDATAIN_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_TEST0_TESTDATAIN_SHFT);

  // This sets USB2_SUSPEND_N_SEL = 1.  Set suspendm = 1; until PHYCLOCK is available by setting USB2_SUSPEND_N_SEL and USB2_SUSPEND_N  
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_SHFT);

  // Set USB2_SUSPEND_N = 1
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SHFT);

  // Set sleepm = 1; until PHY CLOCK is available
  HWIO_USB2PHY_USB_PHY_UTMI_CTRL0_OUTM(HWIO_USB2PHY_USB_PHY_UTMI_CTRL0_SLEEPM_BMSK, 0x1 << HWIO_USB2PHY_USB_PHY_UTMI_CTRL0_SLEEPM_SHFT);

  // Set POR = 0; release the POR from high to low
  // >> USB_PHY_UTMI_CTRL5[1] = 0; POR 
  HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_POR_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_UTMI_CTRL5_POR_SHFT);

  // This sets USB2_SUSPEND_N_SEL = 0.  This de-selects from sw override   
  HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_SHFT);

  usb_shared_delay_us(20);

  // Set UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
  // >> USB_PHY_CFG0[1] = 0; UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
  HWIO_USB2PHY_USB_PHY_CFG0_OUTM(HWIO_USB2PHY_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_BMSK, 0x0 << HWIO_USB2PHY_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_SHFT);

  usb_shared_delay_us(20);
    
  return TRUE;

}


//============================================================================

/**
* @function USB_SHARED_HS_PHY_INIT_SEC
*
* @brief    API used to initialize the High Speed Secondary PHY 
*
*/
//============================================================================
boolean usb_shared_hs_phy_init_sec()
{
    usb_shared_uart_log_info("usb_shared_hs_phy_init_sec: ++");

    // Set UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
    // >> USB_PHY_CFG0[1] = 1; UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
    HWIO_USB2PHY_SEC_USB_PHY_CFG0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_SHFT);

    // Set the POR signal = 1 ; active high 
    // >> USB_PHY_UTMI_CTRL5[1] = 1 ; POR 
    HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_POR_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_POR_SHFT);
    
    // Set all strapping options:
    // >> Select reference clock frequency. FSEL[6:4] = 000; for 19.2MHz clock 
    //    USB_PHY_HS_PHY_CTRL_COMMON0[6:4] = 000; FSEL (Note: This control with register is not needed for default settings) 
    //    usb2phy_fsel[2:0]= 000, At the chip top, the usb2phy_fsel I/O need be tied off to 000 for default settings. 
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_FSEL_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_FSEL_SHFT);

    // Selects the PLL bandwidth, PLLBTUNE=1
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_PLLBTUNE_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_PLLBTUNE_SHFT);
    
    // >> Select reference clock source. REFCLKSEL[1:0] = 10; select the CLKCORE input 
    //    USB_PHY_REFCLK_CTRL[1:0] = 10; REFCLK_SEL 
    HWIO_USB2PHY_SEC_USB_PHY_REFCLK_CTRL_OUTM(HWIO_USB2PHY_SEC_USB_PHY_REFCLK_CTRL_REFCLK_SEL_BMSK, 0x2 << HWIO_USB2PHY_SEC_USB_PHY_REFCLK_CTRL_REFCLK_SEL_SHFT);
    
    // Select external VBUS valid by setting VBUSVLDEXTSEL0 to 1
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_VBUSVLDEXTSEL0_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON1_VBUSVLDEXTSEL0_SHFT);
    
    // VBUSVLDEXT0 is set to 1. This make VBUS signal valid.  Note, the VBUS and ID are not used in the femtoPHY.  
    // They are used in PMI and information needs to transferred from PMI to AOSS via the SPMI interface
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL1_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL1_VBUSVLDEXT0_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL1_VBUSVLDEXT0_SHFT);
    
    // Change to REXT (1), default is using EFUSE (0)
    HWIO_USB2PHY_SEC_USB_PHY_RTUNE_SEL_OUTM(HWIO_USB2PHY_SEC_USB_PHY_RTUNE_SEL_RTUNE_SEL_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_RTUNE_SEL_RTUNE_SEL_SHFT);

    // Set Parameter Override (if needed)
    usb_shared_lib_process_phy_reg_array(
      (const qusb_phy_cfg_type*) qusb_dci_hs_phy_sec_cfg,
      0,
      QUSB_DCI_HS_PHY_SEC_CFG_ARRAY_ENTRY_CNT);


    // Set VREGBYPASS = 1; The internal VREG18 is not used and bypassed. It requires VDDH= 1.8V power supply from outside 
    // >> USB_PHY_HS_PHY_CTRL_COMMON2[0] = 1; VREGBYPASS 
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON2_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON2_VREGBYPASS_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON2_VREGBYPASS_SHFT);

    // Set ATERESET = 0 or tie ATERESET with POR: PHYCLOCK is available after atereset is deasserted
    HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_ATERESET_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_ATERESET_SHFT);
    
    // Set TESTDATAOUTSEL to 0
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_TESTDATAOUTSEL_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_TESTDATAOUTSEL_SHFT);
    
    // Set TESTCLK = 0
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_TOGGLE_2WR_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST1_TOGGLE_2WR_SHFT);

    // Set VATESTENB = 00
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_VATESTENB_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL_COMMON0_VATESTENB_SHFT);

    // Set TESTDATAIN bits to zero until PHYCLOCK is available  
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST0_TESTDATAIN_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_TEST0_TESTDATAIN_SHFT);
    
    // This sets USB2_SUSPEND_N_SEL = 1.  Set suspendm = 1; until PHYCLOCK is available by setting USB2_SUSPEND_N_SEL and USB2_SUSPEND_N  
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_SHFT);

    // Set USB2_SUSPEND_N = 1
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SHFT);
    
    // Set sleepm = 1; until PHY CLOCK is available
    HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL0_SLEEPM_BMSK, 0x1 << HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL0_SLEEPM_SHFT);

    // Set POR = 0; release the POR from high to low
    // >> USB_PHY_UTMI_CTRL5[1] = 0; POR 
    HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_OUTM(HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_POR_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_UTMI_CTRL5_POR_SHFT);

    // This sets USB2_SUSPEND_N_SEL = 0.  This de-selects from sw override   
    HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_OUTM(HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_HS_PHY_CTRL2_USB2_SUSPEND_N_SEL_SHFT);

    usb_shared_delay_us(20);

    // Set UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
    // >> USB_PHY_CFG0[1] = 0; UTMI_PHY_CMN_CNTRL_OVERRIDE_EN
    HWIO_USB2PHY_SEC_USB_PHY_CFG0_OUTM(HWIO_USB2PHY_SEC_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_BMSK, 0x0 << HWIO_USB2PHY_SEC_USB_PHY_CFG0_UTMI_PHY_CMN_CTRL_OVERRIDE_EN_SHFT);

    usb_shared_delay_us(20);

    return TRUE;
}

//============================================================================
/**
* @function USB_SHARED_HS_PHY_INIT
*
* @brief API used to initialize the High Speed RUMI PHY
*
* @Note : 
*
* @param    core_num
*               1st core (primary) = 0, 2nd = 1, etc
*           port_num
*               If core supports multiple ports, 0..4. (0 default)
*
* @return   None
*
*/
//============================================================================
boolean usb_shared_hs_phy_rumi_init(uint32 core_num, uint32 phy_num)
{
// RUMI Phy Base Address for primary, sec and MP controllers
// Subject to change per RUMI release
#define RUMI_PHY_PRIM                            (USB3_PRI_USB30_PRIM_BASE + 0x00120000)  // 0x0A720000
#define RUMI_PHY_SEC                             (USB3_2ND_USB30_PRIM_BASE + 0x00120000)  // 0x0A920000
      
#define HWIO_HS2_EMU_VERSION_OFFS                (0x00000000)
#define HWIO_HS2_LOCAL_RESET_REG_OFFS            (0x00000004)
#define HWIO_HS2_CLK_STATUS_OFFS                 (0x00000010)
#define HWIO_HS2_CLK_STATUS_SEL_OFFS             (0x00000014)
#define HWIO_HS2_IMEM_DELAY_CTRL_OFFS            (0x00000100)
#define HWIO_HS2_IMEM_DELAY_MIN_DELAY_OFFS       (0x00000104)
#define HWIO_HS2_USB_CLK_CTRL_OFFS               (0x00000020)
#define HWIO_HS2_USB_CLK_STATUS_OFFS             (0x00000024)
#define HWIO_HS2_QRBTC_CONTROL_OFFS              (0x00000028)
#define HWIO_HS2_QRBTC_CONTROL_OE_OFFS           (0x0000002c)
#define HWIO_HS2_USB30_CTRL_OFFS                 (0x00000034)
#define HWIO_HS2_USB30_STATUS_OFFS               (0x00000038)
#define HWIO_HS2_USB_PIPE3_CLK_CTRL_OFFS         (0x0000003c)
#define HWIO_HS2_USB30_IRQ0_DELAY_FROM_RISE_OFFS (0x00000040)
#define HWIO_HS2_USB30_IRQ1_DELAY_FROM_RISE_OFFS (0x00000044)
#define HWIO_HS2_USB30_IRQ_DELAY_CTRL_OFFS       (0x00000048)
#define HWIO_HS2_USB30_IRQ0_DELAY_FROM_FALL_OFFS (0x00000060)
#define HWIO_HS2_USB30_IRQ1_DELAY_FROM_FALL_OFFS (0x00000064)
#define HWIO_HS2_SETUP_VERSION_OFFS              (0x00000050)
#define HWIO_HS2_USB_UNIPHY_CLK_CTRL_OFFS        (0x00000054)
#define HWIO_HS2_ROM_STRING_SIZE_OFFS            (0x00010004)

#define USB_RUMI_PHY_INIT_RETRY_COUNT_MAX        (5)

  uint32        phy_base         = RUMI_PHY_PRIM;
  const uint32  UTMI_MMCM_SHIFT  = 0x000001E0;
  uint32        retry_count;
  uint32        utmi_khz;
  
  // PHY number is not used since target does not support multi-port
  (void)phy_num;

  switch (core_num)
  {
    case 0:   phy_base = RUMI_PHY_PRIM;   break;
    case 1:   phy_base = RUMI_PHY_SEC;    break;
    default:
    {
      usb_shared_uart_log_error("RUMI USB PHY invalid core", core_num);
    }
    break;
  }

  for (retry_count = 0; retry_count < USB_RUMI_PHY_INIT_RETRY_COUNT_MAX; retry_count++)
  {
    usb_shared_uart_log_error("RUMI PHY INIT:", retry_count);

    // Put everything in Reset except the PHY
    usb_shared_uart_log_error("RUMI PHY INIT", 0);
    out_dword(phy_base + HWIO_HS2_LOCAL_RESET_REG_OFFS, 0xFFF0);
    usb_shared_delay_us(500);
    out_dword(phy_base + HWIO_HS2_LOCAL_RESET_REG_OFFS, 0xFFF3);
    usb_shared_delay_us(500); 
    out_dword(phy_base + HWIO_HS2_LOCAL_RESET_REG_OFFS, 0xFFF0);

    // Shifting ULPI/UTMI clock MMCM
    out_dword(phy_base + HWIO_HS2_USB_CLK_CTRL_OFFS, 0x00100000);
    usb_shared_delay_us(500);
    out_dword(phy_base + HWIO_HS2_USB_CLK_CTRL_OFFS, 0x00000000);
    usb_shared_delay_us(500);
    out_dword(phy_base + HWIO_HS2_USB_CLK_CTRL_OFFS, UTMI_MMCM_SHIFT);
    usb_shared_delay_us(500);

    usb_shared_uart_log_error("UTMI MMCM clock shift value set", UTMI_MMCM_SHIFT);

    // Shifting PIPE3 clock MMCM - Not used since only USB2 supported on RUMI
    out_dword(phy_base + HWIO_HS2_USB_PIPE3_CLK_CTRL_OFFS, 0x00100000);
    usb_shared_delay_us(500);
    out_dword(phy_base + HWIO_HS2_USB_PIPE3_CLK_CTRL_OFFS, 0x00000000);
    usb_shared_delay_us(500);
    out_dword(phy_base + HWIO_HS2_USB_PIPE3_CLK_CTRL_OFFS, 0x00000004);
    usb_shared_delay_us(500);

    // Clear the other Resets */
    out_dword(phy_base + HWIO_HS2_LOCAL_RESET_REG_OFFS, 0x0);
    usb_shared_delay_us(500);

    // Put clock selector to read UTMI clock */
    out_dword(phy_base + HWIO_HS2_CLK_STATUS_SEL_OFFS, 0x00000009);
    usb_shared_delay_us(500);
    utmi_khz = in_dword(phy_base + HWIO_HS2_CLK_STATUS_OFFS);
    usb_shared_uart_log_error("UTMI CLK @ PAD (KHz):", utmi_khz);

    // Try until 60Mhz
    if (60 == (utmi_khz / 1000))
    {
      break;
    }
  }
  
  return TRUE;
}

//============================================================================

/**
* @function USB_SHARED_SS_PHY_INIT
*
* @brief    API used to initialize the Super Speed Primary PHY 
*
*/
//============================================================================
boolean usb_shared_ss_phy_init(uint32 usb_ss_phy_lane)
{
  uint32 qusb_timeout=0x0;
  const char *ss_phy_cfg_prop_name = "ss_phy_cfg";
  const char *ss_phy_cfg_size_prop_name = "ss_phy_cfg_size";
  DALSYSPropertyVar dal_ss_phy;
  DALSYSPropertyVar dal_ss_phy_size;

  DALResult result;
  DALSYS_PROPERTY_HANDLE_DECLARE(ss_phy_cfg_h);

  usb_shared_error_log(QUSB_SS_PHY_INIT_LOG, 0, 0);
  usb_shared_uart_log_info("usb_shared_ss_phy_init: ++");

  // If USB SS PHY is disabled on the fuse, then return FALSE, so caller can fallback to USB2 PHY only mode
  if (HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_INM(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_BMSK))
  {
    usb_shared_uart_log_error("usb3_ss_phy_disabled", 0);
    return FALSE;
  }

  /* get handle to ss phy settings */
  result = DALSYS_GetDALPropertyHandleStr("QUSB_PORT_PRIM", ss_phy_cfg_h);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_ss_phy_init: DALSYS_GetDALPropertyHandleStr Failed", result);
     return FALSE;
  }

  /* get ss phy cfg */
  result = DALSYS_GetPropertyValue(ss_phy_cfg_h, ss_phy_cfg_prop_name, 0, &dal_ss_phy);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_ss_phy_init: get ss phy cfg Failed", result);
     return FALSE;
  }
  /* get ss phy cfg size */
  result = DALSYS_GetPropertyValue(ss_phy_cfg_h, ss_phy_cfg_size_prop_name, 0, &dal_ss_phy_size);
  if (result != DAL_SUCCESS)
  {
     usb_shared_error_log(DCI_DAL_ERROR_LOG, 0, __LINE__);
     usb_shared_uart_log_error("usb_shared_ss_phy_init: get ss phy cfg size Failed", result);
     return FALSE;
  }

  usb_shared_uart_log_error("usb_shared_ss_phy_init: ss phy cfg size", dal_ss_phy_size.Val.dwVal);

  usb_shared_lib_process_phy_reg_array(
    (const qusb_phy_cfg_type*) dal_ss_phy.Val.pStruct,
    0,
    (const uint32) dal_ss_phy_size.Val.dwVal);

  // Override Type-C lane detection  override
  HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_OUTM(
    HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_SW_PORTSELECT_BMSK, 
    usb_ss_phy_lane << HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_SW_PORTSELECT_SHFT);
  
  HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_OUTM(
    HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_SW_PORTSELECT_MUX_BMSK,
    0x1 << HWIO_USB3_DP_PHY_USB3_DP_COM_TYPEC_CTRL_SW_PORTSELECT_MUX_SHFT);

  usb_shared_delay_us(100);

  HWIO_USB3_DP_PHY_USB3_DP_COM_SW_RESET_OUT(0x00);
  HWIO_USB3_DP_PHY_USB3_PCS_SW_RESET_OUT(0x0);
  HWIO_USB3_DP_PHY_USB3_PCS_START_CONTROL_OUT(0x3);

  usb_shared_delay_us(100);

  /* Poll PHYSTATUS field of Register USB3_PHY_PCS_STATUS to Go LOW after reset*/
  while(HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS1_INM(
        HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS1_PHYSTATUS_BMSK))
  {
    usb_shared_delay_us(100);
    if (qusb_timeout++ > 100)
    {
        USB_SHARED_ASSERT(DCI_SS_PHY_RESET_ERROR_LOG);
        usb_shared_uart_log_error("ssusb_phy_init_timeout", 0);
        return FALSE;
    }
  }

  if (usb_ss_phy_lane == 0)
  {
    usb_shared_uart_log_error("ssusb_phy_init_success_lane_A", usb_ss_phy_lane);
  }
  else
  {
    usb_shared_uart_log_error("ssusb_phy_init_success_lane_B", usb_ss_phy_lane);
  }
  usb_shared_uart_log_info("usb_shared_ss_phy_init: --");
  return TRUE;
}


//============================================================================

/**
* @function USB_SHARED_SS_PHY_INIT_SEC
*
* @brief    API used to initialize the Super Speed Secondary PHY 
*
*/
//============================================================================
boolean usb_shared_ss_phy_init_sec()
{
  uint32 qusb_timeout=0x0;

  usb_shared_error_log(QUSB_SS_PHY_INIT_LOG, 0, 0);
  usb_shared_uart_log_info("usb_shared_ss_phy_init_sec: ++");

  usb_shared_lib_process_phy_reg_array(
    (const qusb_phy_cfg_type*) qusb_dci_ss_phy_sec_cfg_common,
    0,
    QUSB_DCI_SS_PHY_SEC_COMMON_CFG_ARRAY_ENTRY_CNT);

  usb_shared_delay_us(100);

  HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_SW_RESET_OUT(0x0);
  HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_START_CONTROL_OUT(0x3);

  usb_shared_delay_us(100);

  /* Poll PHYSTATUS field of Register USB3_PHY_PCS_STATUS to Go LOW after reset*/
  while(HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS1_INM(
        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS1_PHYSTATUS_BMSK))
  {
    usb_shared_delay_us(100);
    if (qusb_timeout++ > 100)
    {
        USB_SHARED_ASSERT(DCI_SS_PHY_RESET_ERROR_LOG);
        usb_shared_uart_log_error("p2_ssusb_phy_init_timeout", 0);
        return FALSE;
    }
  }
  
  usb_shared_uart_log_error("p2_ssusb_phy_init_success", 0);

  usb_shared_uart_log_info("usb_shared_ss_phy_init_sec: --");
  return TRUE;
}


//============================================================================
/**
* @function usb_shared_poll_ss_phy_training
*
* @brief    Polls USB SS PHY for training
*
*/
//============================================================================
void usb_shared_poll_ss_phy_training(void)
{
#ifdef USB_RETRAINING
  uint32 loop_count = USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US;
  
  // Add Gen2 USB enumeration on some type_c USB combo Super Speed Plus compatibilty
  if (HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS2_INM(
    HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS2_RX_EQUALIZATION_IN_PROGRESS_BMSK))
  {
    usb_shared_uart_log_error("usb3_rx_training_in_progress", 0);

    for (; loop_count; loop_count--)
    {
      if (0 == HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS2_INM(
        HWIO_USB3_DP_PHY_USB3_PCS_PCS_STATUS2_RX_EQUALIZATION_IN_PROGRESS_BMSK))
      {
        HWIO_USB3_DP_PHY_USB3_PCS_INSIG_SW_CTRL3_OUT(0x08);
        HWIO_USB3_DP_PHY_USB3_PCS_INSIG_MX_CTRL3_OUT(0x08);

        // Wait 1us
        usb_shared_delay_us(1);

        HWIO_USB3_DP_PHY_USB3_PCS_INSIG_SW_CTRL3_OUT(0x00);
        HWIO_USB3_DP_PHY_USB3_PCS_INSIG_MX_CTRL3_OUT(0x00);

        usb_shared_uart_log_error("usb3_rx_training_done_in_us", USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US - loop_count);
        break;
      }
      usb_shared_delay_us(1);
    }
    
    if (0 == loop_count)
    {
      usb_shared_uart_log_error("usb3_rx_training_timeout", USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US);
    }
  }
#endif
}


//============================================================================
/**
* @function usb_shared_poll_ss_phy_training_sec
*
* @brief    Polls USB SS PHY for training
*
*/
//============================================================================
void usb_shared_poll_ss_phy_training_sec(void)
{
#ifdef USB_RETRAINING
  uint32 loop_count = USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US;
  
  // Add Gen2 USB enumeration workaround on thunderbolt v2 type_c USB combo
  if (HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS2_INM(
    HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS2_RX_EQUALIZATION_IN_PROGRESS_BMSK))
  {
    usb_shared_uart_log_error("usb3_2nd_rx_training_in_progress", 0);

    for (; loop_count; loop_count--)
    {
      if (0 == HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS2_INM(
        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_PCS_STATUS2_RX_EQUALIZATION_IN_PROGRESS_BMSK))
      {
        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_INSIG_SW_CTRL3_OUT(0x08);
        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_INSIG_MX_CTRL3_OUT(0x08);

        // Wait 1us
        usb_shared_delay_us(1);

        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_INSIG_SW_CTRL3_OUT(0x00);
        HWIO_USB3_UNI_PHY_PCIE_USB3_UNI_PCS_INSIG_MX_CTRL3_OUT(0x00);

        usb_shared_uart_log_error("usb3_2nd_rx_training_done_in_us", USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US - loop_count);
        break;
      }
      usb_shared_delay_us(1);
    }
    
    if (0 == loop_count)
    {
      usb_shared_uart_log_error("usb3_2nd_rx_training_timeout", USB_SHARED_POLL_SS_PHY_TRAINING_TIMEOUT_US);
    }
  }
#endif
}


//============================================================================
/**
* @function  usb_dci_get_chip_serial_number
*
* @brief Call API to uint32 unique MSM serial string
*
* @Note : None
*
* @param  None 
*
* @return uint32: Chip serial number
*
*/
//============================================================================
uint32 usb_dci_get_chip_serial_number(void)
{
  return HWIO_SERIAL_NUM_IN;
}

//============================================================================
/** 
 * API is used to add chip serial number to the string and return 
 * Product String Descriptor
 * 
 * @param pointer to product string
 *              Pointer to the buffer to be updated with Product string desc
 *              Length of the buffer
 *
 * @return Appended string length
 */ 
 //============================================================================
uint32 usb_get_product_str_desc_with_chip_serial(char* product_str, char* prod_str_desc, uint32 desc_len)
{
  char    chip_serial_str[QUSB_FD_PRODUCT_STRING_LENGTH_MAX];
  uint32  chip_serial;
  uint32  str_desc_index;
  uint32  str_desc_size;
  uint32  chip_str_len;
  uint32  chip_str_index;

  if ((NULL == product_str)||(NULL == prod_str_desc) )
  {
    // String is NULL;
    return 0;
  }

  chip_serial = usb_dci_get_chip_serial_number();
  
  chip_str_len = snprintf(chip_serial_str, sizeof(chip_serial_str), "%s_SN:%08X", product_str, chip_serial);

  if (chip_str_len >= sizeof(chip_serial_str))
  {
    // Chip Seiral is too long to fit
    return 0;
  }

  // "ASCII string size" X 2 (UNICODE) 
  //   + 2 (1 byte SIZE and 1 byte STRING DESC TYPE ENUM)
  str_desc_size = (chip_str_len * 2) + 2;

  if (str_desc_size >= desc_len)
  {
    // Destination buffer over flow
    return 0;    
  }

  str_desc_index = 0;
  prod_str_desc[str_desc_index++] = (char)str_desc_size;
  prod_str_desc[str_desc_index++] = USB_DESCTYPE_STRING;

  for (chip_str_index = 0; chip_str_index < chip_str_len; chip_str_index++)
  {
    prod_str_desc[str_desc_index++] = chip_serial_str[chip_str_index];
    prod_str_desc[str_desc_index++] = 0x0;  
  }

  return str_desc_size;
}


//============================================================================
/**
* @function  usb_shared_is_eud_active
*
* @brief Returns status whether EUD is active 
*        and has already initialized High Speed PHY
*
* @Note : None
*
* @param  None 
*
* @return boolean: TRUE is EUD is active, FALSE otherwise
*
*/
//============================================================================
boolean usb_shared_is_eud_active(void)
{
  // If UEFI cannot access EUD_EN2, please check if XBL_SEC allowed
  // READ permission
  boolean is_eud_active = HWIO_EUD_EUD_EN2_INM(
    HWIO_EUD_EUD_EN2_EUD_EN2_BMSK) 
    >> HWIO_EUD_EUD_EN2_EUD_EN2_SHFT;

  if (is_eud_active)
  {
    usb_shared_uart_log_error("usb_eud_is_active", 1);
  }
  
  return is_eud_active;
}


