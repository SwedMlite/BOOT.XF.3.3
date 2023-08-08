/*=============================================================================
 
  File: MDPPlatformLibPanelConfig.h

  MDP platform specific types

  Copyright (c) 2018 - 2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifndef __MDP_PLATFORM_LIB_PANEL_CONFIG__H__
#define __MDP_PLATFORM_LIB_PANEL_CONFIG__H__

#include "MDPPlatformLibPanelCommon.h"



/* Default platform panel functions - From MDPPlatformLibPanelCommon.c */
extern MDP_Status Panel_Default_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
extern MDP_Status Panel_Default_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
extern MDP_Status Panel_Default_Peripheral_Power(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp);
extern MDP_Status Panel_Default_Brightness_Enable(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
extern MDP_Status Panel_Default_Brightness_Level(MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig);
extern MDP_Status Panel_Default_Reset(MDPPlatformPanelResetInfo *pResetInfo);


/* 
 *  Macro definition with 1 parameter to simplify sMDPPlatformPanelFunction
 *  Refer to MDPPlatformPanelFunctionTable for each item meaning
 */
#define MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(_panelselection_)\
{\
  (_panelselection_),\
  NULL,\
  NULL,\
  NULL,\
  NULL,\
  NULL,\
  NULL,\
  NULL,\
  NULL\
}

/* 
 *  Macro definition with 3 parameter to simplify sMDPPlatformPanelFunction
 *  Refer to MDPPlatformPanelFunctionTable for each item meaning
 */
#define MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(_panelselection_, _panelgpio_, _xmlconfig_)\
{\
  (_panelselection_),\
  (_panelgpio_),\
  (_xmlconfig_),\
  Panel_Default_PowerUp,\
  Panel_Default_PowerDown,\
  Panel_Default_Reset,\
  Panel_Default_Peripheral_Power,\
  Panel_Default_Brightness_Enable,\
  Panel_Default_Brightness_Level\
}

/* 
 *  Macro definition with 3 parameter to simplify sMDPPlatformPanelFunction
 *  Refer to MDPPlatformPanelFunctionTable for each item meaning
 *  The Peripheral_Power / Brightness_Enable / Brightness_Level are set to NULL by default.
 */
#define MDP_PLATFORM_PANEL_FUNCTION_ENTRY3(_panelselection_, _panelgpio_, _xmlconfig_)\
{\
  (_panelselection_),\
  (_panelgpio_),\
  (_xmlconfig_),\
  Panel_Default_PowerUp,\
  Panel_Default_PowerDown,\
  Panel_Default_Reset,\
  NULL,\
  NULL,\
  NULL\
}


/* MDPPlatformPanelFunctionTable Definition :
 * typedef struct
 * {
 *   // The default panel selected when setting up platform panel configuration.
 *   MDPPlatformPanelType      ePanelSelected;
 *
 *   // The display gpio used by the panel selected.
 *   MDPPlatformPanelGpioType *pMDPPlatformPanelGpio;
 * 
 *   // The name of the configuration xml file for the panel selected.
 *   CHAR8                    *pPanelXml;
 *
 *   // Panel power up function
 *   MDP_Status (*pPanel_PowerUp)           (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
 *
 *   // Panel power down function
 *   MDP_Status (*pPanel_PowerDown)         (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
 *
 *   // Panel reset function
 *   MDP_Status (*pPanel_Reset)             (MDPPlatformPanelResetInfo *pResetInfo);
 *
 *   // Panel peripheral power function
 *   MDP_Status (*pPanel_Peripheral_Power)  (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp);
 *
 *   // Panel brightness enable function
 *   MDP_Status (*pPanel_Brightness_Enable) (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
 *
 *   // Panel brightness level control function
 *   MDP_Status (*pPanel_Brightness_Level)  (MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig);
 * } MDPPlatformPanelFunctionTable;
 */
MDPPlatformPanelFunctionTable sMDPPlatformPanelFunction[MDPPLATFORM_PANEL_MAX] =
{
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_NONE),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_VIDEO_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_DUALDSI_VIDEO_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_CMD_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_DUALDSI_CMD_PANEL),

  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_WQXGA_DSC_CMD, NULL, "Panel_truly_wqxga_dsc_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_WQXGA_DSC_VIDEO, NULL, "Panel_truly_wqxga_dsc_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_WQXGA_DUALDSI_CMD, NULL, "Panel_truly_wqxga_dual_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_WQXGA_DUALDSI_VIDEO, NULL, "Panel_truly_wqxga_dual_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_SHARP_4K_DSC_CMD, NULL, "Panel_sharp_4k_dsc_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_SHARP_4K_DSC_VIDEO, NULL, "Panel_sharp_4k_dsc_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SHARP_4K_EDP),// EDP is Not used
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_SHARP_1080P_CMD, NULL, "Panel_sharp_1080p_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_1080P_CMD, NULL, "Panel_truly_1080p_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_TRULY_1080P_VIDEO, NULL, "Panel_truly_1080p_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD, NULL, "Panel_boe_amoled_wqhd_dsc_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_VIDEO, NULL, "Panel_boe_amoled_wqhd_dsc_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_BOE_AMOLED_FHD_DSC_CMD, NULL, "Panel_boe_amoled_fhd_dsc_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY3(MDPPLATFORM_PRI_PANEL_SHARP_1080P_CMD, NULL, "Panel_primary_sharp_1080p_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY3(MDPPLATFORM_SEC_PANEL_TRULY_1080P_CMD, (&(MDPPlatformPanelGpioType){128, MDP_TE_GPIO_67, 0}), "Panel_secondary_truly_1080p_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY3(MDPPLATFORM_SEC_PANEL_TRULY_1080P_VIDEO, (&(MDPPlatformPanelGpioType){128, MDP_TE_GPIO_67, 0}), "Panel_secondary_truly_1080p_vid.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_AUO_1080P_EDP),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_DSC_375_CMD_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SIM_DUAL_DSC_375_CMD_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SHARP_WQHD_DSC_CMD_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_SHARP_WQHD_DSC_VIDEO_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_DSI_SIM_DSC_10B_CMD_PANEL),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_EXT_BRIDGE_1080P_VIDEO),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY1(MDPPLATFORM_PANEL_EXT_BRIDGE_4K_VIDEO),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_NT36860_WQHD_DSC_CPHY_CMD, NULL, "Panel_nt36860_wqhd_dsc_cmd.xml"),
  MDP_PLATFORM_PANEL_FUNCTION_ENTRY2(MDPPLATFORM_PANEL_NT36860_WQHD_DSC_CPHY_VIDEO, NULL, "Panel_nt36860_wqhd_dsc_vid.xml"),
};

#endif // __MDP_PLATFORM_LIB_PANEL_CONFIG__H__

