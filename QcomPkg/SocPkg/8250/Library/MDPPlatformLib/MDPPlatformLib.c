/*=============================================================================
 
  File: MDPPlatformLib.c
 
  MDP platform specific functions
  
  Copyright (c) 2011-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/EFIPmicGpio.h>
#include <Protocol/EFIPmicClkBuff.h>
#include <Protocol/EFITlmm.h>
#include <Protocol/EFIPmicLpg.h>
#include <Protocol/EFIPmicGpio.h>
#include <Protocol/EFIPmicVreg.h>
#include <Protocol/EFIPmicWled.h>
#include <Protocol/EFIPmicIbb.h>
#include <Protocol/EFIPmicLab.h>
#include "DDIChipInfo.h"
#include "MDPTypes.h"
#include "MDPPlatformLib.h"
#include "MDPPlatformLibPanelConfig.h"
#include "MDPSystem.h"
#include "MDPPeripherals.h"
#include "DisplayUtils.h"
#include "npa.h"
#include "pmapp_npa.h"
#include "DDITlmm.h"
#include "HALDSILib.h"

/* -----------------------------------------------------------------------
** Defines
** ----------------------------------------------------------------------- */
#define HDK_DISP_DSI_STATUS_GPIO              51      // HDK display dsi / hdmi mode status gpio
#define RB5_DISP_MODE_SWITCH_GPIO             27      // RB5 display mode switch gpio


/* -----------------------------------------------------------------------
** Local functions
** ----------------------------------------------------------------------- */

/* Platform detection 
 */
static MDP_Status ReadPlatformIDAndChipID(EFI_PLATFORMINFO_PLATFORM_INFO_TYPE *pPlatformInfo, EFIChipInfoIdType *pChipSetId, EFIChipInfoFamilyType *pChiSetFamily);
static MDP_Status DynamicDSIPanelDetection(MDPPlatformPanelInfo *pPlatformPanel, uint32 *puPanelID, PlatformDSIDetectParams *pPanelList, uint32 uPanelCnt);

/* General helper functions
 */
static MDP_Status SetupPlatformPanelConfig(MDP_Display_IDType eDisplayId, MDPPlatformPanelInfo *pPlatformPanel, MDPPlatformInfo *pPlatformInfo, MDPPlatformInfo *pMDPPlatformInfo);
static MDP_Status GetPanelXmlConfig(MDP_Display_IDType eDisplayId, MDPPlatformPanelInfo *pPlatformPanel);
static MDP_Status FindPanelIndex(MDPPlatformPanelInfo *pPlatformPanel);
static MDP_Status SetDefaultGPIOState(GpioStateType *pGPIOList);
static EFI_STATUS GetDisplayGpioValue(uint32 uGpioNum, TLMM_ValueType *pGpioValue);

/* External display default functions
 */
extern MDP_Status ExternalPanel_Default_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
extern MDP_Status ExternalPanel_Default_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
extern bool32     DP_USBPlugInvertedOrientation(void);

/*===========================================================================
 Local Configuration Definitions
 ===========================================================================*/

/*
* Dummy panel configuration, default fallback mode.
*
*/
const static int8 dummy_xmldata[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"    <PanelName>VirtioDSI</PanelName>"
"    <PanelDescription>DSI Model (640x480 24bpp)</PanelDescription>"
"    <Group id=\"Active Timing\">"
"        <HorizontalActive>640</HorizontalActive>"
"        <HorizontalFrontPorch>13</HorizontalFrontPorch>"
"        <HorizontalBackPorch>14</HorizontalBackPorch>"
"        <HorizontalSyncPulse>15</HorizontalSyncPulse>"
"        <HorizontalSyncSkew>0</HorizontalSyncSkew>"
"        <HorizontalLeftBorder>0</HorizontalLeftBorder>"
"        <HorizontalRightBorder>0</HorizontalRightBorder>"
"        <VerticalActive>480</VerticalActive>"
"        <VerticalFrontPorch>11</VerticalFrontPorch>"
"        <VerticalBackPorch>12</VerticalBackPorch>"
"        <VerticalSyncPulse>13</VerticalSyncPulse>"
"        <VerticalSyncSkew>0</VerticalSyncSkew>"
"        <VerticalTopBorder>0</VerticalTopBorder>"
"        <VerticalBottomBorder>0</VerticalBottomBorder>"
"        <InvertDataPolarity>False</InvertDataPolarity>"
"        <InvertVsyncPolairty>False</InvertVsyncPolairty>"
"        <InvertHsyncPolarity>False</InvertHsyncPolarity>"
"        <BorderColor>0x0</BorderColor>"   
"    </Group>"
"    <Group id=\"Display Interface\">"
"        <InterfaceType>8</InterfaceType>"
"        <InterfaceColorFormat>3</InterfaceColorFormat>"
"    </Group>"
"    <Group id=\"DSI Interface\">"
"        <DSIChannelId>1</DSIChannelId>"
"        <DSIVirtualId>0</DSIVirtualId>"
"        <DSIColorFormat>36</DSIColorFormat>"
"        <DSITrafficMode>0</DSITrafficMode>"
"        <DSILanes>3</DSILanes>"
"        <DSIHsaHseAfterVsVe>False</DSIHsaHseAfterVsVe>"
"        <DSILowPowerModeInHFP>False</DSILowPowerModeInHFP>"
"        <DSILowPowerModeInHBP>False</DSILowPowerModeInHBP>"
"        <DSILowPowerModeInHSA>False</DSILowPowerModeInHSA>"
"        <DSILowPowerModeInBLLPEOF>False</DSILowPowerModeInBLLPEOF>"
"        <DSILowPowerModeInBLLP>False</DSILowPowerModeInBLLP>"
"        <DSIRefreshRate>0x3c0000</DSIRefreshRate>"
"    </Group>"
"        <DisplayPrimaryFlags>0x2</DisplayPrimaryFlags>"
"    <DSIInitSequence>"
"    32 00 00\n"
"    </DSIInitSequence>";

#ifdef MDP_PRESIL
/*
* Writeback panel configuration
*
*/
const static int8 writeback_xmldata[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"    <PanelName>VirtioDSI</PanelName>"
"    <PanelDescription>DSI Model (640x480 24bpp)</PanelDescription>"
"    <Group id=\"Active Timing\">"
"        <HorizontalActive>640</HorizontalActive>"
"        <HorizontalFrontPorch>13</HorizontalFrontPorch>"
"        <HorizontalBackPorch>14</HorizontalBackPorch>"
"        <HorizontalSyncPulse>15</HorizontalSyncPulse>"
"        <HorizontalSyncSkew>0</HorizontalSyncSkew>"
"        <HorizontalLeftBorder>0</HorizontalLeftBorder>"
"        <HorizontalRightBorder>0</HorizontalRightBorder>"
"        <VerticalActive>480</VerticalActive>"
"        <VerticalFrontPorch>11</VerticalFrontPorch>"
"        <VerticalBackPorch>12</VerticalBackPorch>"
"        <VerticalSyncPulse>13</VerticalSyncPulse>"
"        <VerticalSyncSkew>0</VerticalSyncSkew>"
"        <VerticalTopBorder>0</VerticalTopBorder>"
"        <VerticalBottomBorder>0</VerticalBottomBorder>"
"        <InvertDataPolarity>False</InvertDataPolarity>"
"        <InvertVsyncPolairty>False</InvertVsyncPolairty>"
"        <InvertHsyncPolarity>False</InvertHsyncPolarity>"
"        <BorderColor>0x0</BorderColor>"
"    </Group>"
"    <Group id=\"Display Interface\">"
"        <InterfaceType>13</InterfaceType>"
"        <InterfaceColorFormat>3</InterfaceColorFormat>"
"    </Group>";
#endif

/***************************************************************************
Dynamic panel detect list:
    -- first entry contains default panel

At SDM845 panel detection base on platform subtype
   -- use Truly 2k panel
       --- dual dsi (without dsc) video and cmd mode
       --- single dsi with DSC video and cmd mode

***************************************************************************/
static PlatformDSIDetectParams uefiPanelList[] = { 
    // Panel #0 - BOE 2k single dsc Command Mode Panel (1440x2880 24bpp) ID:0x8000
    {  
      0x06,                                                  // uCmdType
      0x05,                                                  // total number of retry on failures
      {
        {{0xDA, 0x00},                                       // address to read ID1
        {0xD2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }, 
        {{0xDB, 0x00},                                       // address to read ID2
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        },
        {{0xDC, 0x00},                                       // address to read ID3
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }
      },
      0,                                                     // Lane remap order {0, 1, 2, 3}
      NULL,                                                  // psPanelCfg (panel configuration)
      0,                                                     // uPanelCfgSize
      MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD,             // eSelectedPanel
      0                                                      // uFlags
    },
    // Panel #1 - BOE 2k single dsc video Mode Panel (1440x2880 24bpp) ID:0x8012
    {
      0x06,                                                  // uCmdType
      0x05,                                                  // total number of retry on failures
      {
        {{0xDA, 0x00},                                       // address to read ID1
        {0xD2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }, 
        {{0xDB, 0x00},                                       // address to read ID2
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        },
        {{0x00, 0x00},                                       // address to read ID3
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }
      },
      0,                                                     // Lane remap order {0, 1, 2, 3}
      NULL,                                                  // psPanelCfg (panel configuration)
      0,                                                     // uPanelCfgSize
      MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_VIDEO,             // eSelectedPanel
      0                                                      // uFlags
    },
    /* Panel #2 - truly lcd 1080p cmd */
    {  
      0x06,                                                  // uCmdType
      0x05,                                                  // total number of retry on failures
      {
        {{0xDA, 0x00},                                       // address to read ID1
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }, 
        {{0xDB, 0x00},                                       // address to read ID2
        {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        },
        {{0xFE, 0x00},                                       // address to read ID3
        {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }
      },
      0,                                                     // Lane remap order {0, 1, 2, 3}
      NULL,                                                  // psPanelCfg (panel configuration)
      0,                                                     // uPanelCfgSize
      MDPPLATFORM_SEC_PANEL_TRULY_1080P_CMD,			           // eSelectedPanel
      0                                                      // uFlags
    },
    /* Panel #3 - sharp 4k lcd cmd */
    {
      0x06,                                                  // uCmdType
      0x05,                                                  // total number of retry on failures
      {
        {{0xDA, 0x00},                                       // address to read ID1
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        },
        {{0xDB, 0x00},                                       // address to read ID2
        {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        },
        {{0xDC, 0x00},                                       // address to read ID3
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}     // expected readback
        }
      },
      0,                                                     // Lane remap order {0, 1, 2, 3}
      NULL,
      0,
      MDPPLATFORM_PANEL_SHARP_4K_DSC_CMD,                    // eSelectedPanel
      0                                                      // uFlags
    },
};


/*
 * List of supported panels. The ones with XML data have UEFI support and the rest are only supported by kernel.  These are applicable for fastboot overrides of the
 * panel configuration.
 */
const PanelDTInfoType fastBootPanelList[] =
{
  /*Supported Panels*/
  /*4k cmd*/
  PANEL_CREATE_ENTRY("sharp_4k_dsc_cmd",        MDPPLATFORM_PANEL_SHARP_4K_DSC_CMD,             "qcom,mdss_dsi_sharp_4k_dsc_cmd:",            DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI,                                DISP_MODE_DUAL_DSI,                                   DISP_MODE_DUAL_DSI),
  /*4k video*/
  PANEL_CREATE_ENTRY("sharp_4k_dsc_vid",        MDPPLATFORM_PANEL_SHARP_4K_DSC_VIDEO,           "qcom,mdss_dsi_sharp_4k_dsc_video:",          DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI,                                DISP_MODE_DUAL_DSI,                                   DISP_MODE_DUAL_DSI),
  
  
  /*Truly 2k NT35597 dsc cmd */
  PANEL_CREATE_ENTRY("truly_wqxga_dsc_cmd",     MDPPLATFORM_PANEL_TRULY_WQXGA_DSC_CMD,          "qcom,mdss_dsi_nt35597_dsc_cmd_truly:",        DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_1,  DISP_TIMING_CONFIG_NONE,   PLL_OVERRIDE_PLL1, DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,         DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,            DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1 | DISP_MODE_DSC_MERGE),
  
  /*Truly 2k NT35597 dsc video */
  PANEL_CREATE_ENTRY("truly_wqxga_dsc_vid",     MDPPLATFORM_PANEL_TRULY_WQXGA_DSC_VIDEO,        "qcom,mdss_dsi_nt35597_dsc_video_truly:",      DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_1,  DISP_TIMING_CONFIG_NONE,   PLL_OVERRIDE_PLL1, DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,         DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,            DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1 | DISP_MODE_DSC_MERGE),
  
  
  /*Truly 2k NT35597 cmd*/
  PANEL_CREATE_ENTRY("truly_wqxga_dual_cmd",    MDPPLATFORM_PANEL_TRULY_WQXGA_DUALDSI_CMD,      "qcom,mdss_dsi_nt35597_truly_wqxga_cmd:",       DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI,                                DISP_MODE_DUAL_DSI | DISP_MODE_PING_PONG_SPLIT,      DISP_MODE_DUAL_DSI),
  
  /*Truly 2k NT35597 video*/
  PANEL_CREATE_ENTRY("truly_wqxga_dual_vid",    MDPPLATFORM_PANEL_TRULY_WQXGA_DUALDSI_VIDEO,    "qcom,mdss_dsi_nt35597_wqxga_video_truly:",     DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI,                                DISP_MODE_DUAL_DSI | DISP_MODE_PING_PONG_SPLIT,      DISP_MODE_DUAL_DSI),

  /* BOE amoled wqhd dsc cmd */
  PANEL_CREATE_ENTRY("boe_amoled_wqhd_dsc_cmd", MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD,      "qcom,mdss_dsi_sw43404_amoled_wqhd_cmd:",       DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /* BOE amoled wqhd dsc video */
  PANEL_CREATE_ENTRY("boe_amoled_wqhd_dsc_vid", MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_VIDEO,    "qcom,mdss_dsi_sw43404_amoled_wqhd_video:",     DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /* BOE amoled fhd dsc cmd */
  PANEL_CREATE_ENTRY("boe_amoled_fhd_dsc_cmd", MDPPLATFORM_PANEL_BOE_AMOLED_FHD_DSC_CMD,      "qcom,mdss_dsi_sw43404_fhd_plus_cmd:",       DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /* Sharp 1080p cmd */
  PANEL_CREATE_ENTRY("sharp_1080p_cmd",         MDPPLATFORM_PANEL_SHARP_1080P_CMD,              "qcom,mdss_dsi_sharp_1080p_cmd:",               DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /* Truly 1080p cmd */
  PANEL_CREATE_ENTRY("truly_1080p_cmd",         MDPPLATFORM_PANEL_TRULY_1080P_CMD,              "qcom,mdss_dsi_nt35695b_truly_fhd_cmd:",        DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /* Truly 1080p vid */
  PANEL_CREATE_ENTRY("truly_1080p_vid",         MDPPLATFORM_PANEL_TRULY_1080P_VIDEO,            "qcom,mdss_dsi_nt35695b_truly_fhd_video:",      DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),
  
  /* Primary Sharp 1080p cmd */
  PANEL_CREATE_ENTRY("pri_sharp_cmd",           MDPPLATFORM_PRI_PANEL_SHARP_1080P_CMD,          "qcom,mdss_dsi_sharp_1080p_cmd:",               DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),
  /* Secondary Truly 1080p */
  PANEL_CREATE_ENTRY("sec_truly_cmd",           MDPPLATFORM_SEC_PANEL_TRULY_1080P_CMD,          "qcom,mdss_dsi_nt35695b_truly_fhd_cmd:",        DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_PLL1, DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,         DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,           DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1),
  PANEL_CREATE_ENTRY("sec_truly_vid",           MDPPLATFORM_SEC_PANEL_TRULY_1080P_VIDEO,        "qcom,mdss_dsi_nt35695b_truly_fhd_video:",      DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_PLL1, DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,         DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1,           DISP_MODE_SINGLE_DSI | DISP_MODE_USE_DSI1),

  /* NT36860 wqhd dsc cmd */
  PANEL_CREATE_ENTRY("nt36860_wqhd_dsc_cmd",    MDPPLATFORM_PANEL_NT36860_WQHD_DSC_CPHY_CMD,         "qcom,mdss_dsi_nt36860_dsc_cmd:",               DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  PANEL_CREATE_ENTRY("nt36860_wqhd_dsc_vid",    MDPPLATFORM_PANEL_NT36860_WQHD_DSC_CPHY_VIDEO,         "qcom,mdss_dsi_nt36860_dsc_vid:",               DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI,                              DISP_MODE_SINGLE_DSI,                                DISP_MODE_SINGLE_DSI),

  /*Simulation panels */
  /*sim video*/
  PANEL_CREATE_ENTRY("sharp_wqhd_dsc_cmd",        MDPPLATFORM_PANEL_SHARP_WQHD_DSC_CMD_PANEL,               "qcom,mdss_dsi_sharp_qsync_wqhd_cmd:",                     DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

  PANEL_CREATE_ENTRY("sharp_wqhd_dsc_vid",        MDPPLATFORM_PANEL_SHARP_WQHD_DSC_VIDEO_PANEL,               "qcom,mdss_dsi_sharp_qsync_wqhd_video:",                     DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

  PANEL_CREATE_ENTRY("sim_vid_panel",             MDPPLATFORM_PANEL_SIM_VIDEO_PANEL,               "qcom,mdss_dsi_sim_video:",                     DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),
  /*sim dualdsi video*/ 
  PANEL_CREATE_ENTRY("sim_dual_vid_panel",        MDPPLATFORM_PANEL_SIM_DUALDSI_VIDEO_PANEL,       "qcom,mdss_dsi_dual_sim_video:",                DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER),
  /*sim CMD*/
  PANEL_CREATE_ENTRY("sim_cmd_panel",             MDPPLATFORM_PANEL_SIM_CMD_PANEL,                 "qcom,mdss_dsi_sim_cmd:",                       DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),
  /*sim dualdsi CMD*/
  PANEL_CREATE_ENTRY("sim_dual_cmd_panel",        MDPPLATFORM_PANEL_SIM_DUALDSI_CMD_PANEL,         "qcom,mdss_dsi_dual_sim_cmd:",                  DISP_INTF_DSI, DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER),

 /* sim single dsc  with dsc compression 3.75 cmd */
 PANEL_CREATE_ENTRY("sim_dsc_375_cmd_panel",      MDPPLATFORM_PANEL_SIM_DSC_375_CMD_PANEL,      "qcom,mdss_dsi_sim_dsc_375_cmd:",               DISP_INTF_DSI,  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

 /* sim dual dsi with dsc compression 3.75 cmd */
 PANEL_CREATE_ENTRY("sim_dual_dsc_375_cmd_panel", MDPPLATFORM_PANEL_SIM_DUAL_DSC_375_CMD_PANEL, "qcom,mdss_dsi_dual_sim_dsc_375_cmd:",          DISP_INTF_DSI,  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER),

  PANEL_CREATE_ENTRY("dsi_sim_dsc_10b_cmd",       MDPPLATFORM_PANEL_DSI_SIM_DSC_10B_CMD_PANEL,  "qcom,mdss_dsi_sim_dsc_10b_cmd:",               DISP_INTF_DSI,  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

  /* external bridge 1080p video */
  PANEL_CREATE_ENTRY("ext_bridge_1080p_vid",      MDPPLATFORM_PANEL_EXT_BRIDGE_1080P_VIDEO,     "qcom,mdss_dsi_ext_bridge_1080p:",              DISP_INTF_DSI,  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

  /* external bridge 4k video */
  PANEL_CREATE_ENTRY("ext_bridge_4k_vid",         MDPPLATFORM_PANEL_EXT_BRIDGE_4K_VIDEO,        "qcom,mdss_dsi_ext_bridge_4k_video:",           DISP_INTF_DSI,  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,  DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_SINGLE_DSI | DISP_MODE_SKIP_BOOTLOADER),

  /*End of Table, DO NOT ADD PANEL BELOW THIS*/
  PANEL_CREATE_ENTRY("",                          MDPPLATFORM_PANEL_NONE,                       "",                                             DISP_INTF_NONE,                                  DISP_TOPOLOGY_CONFIG_NONE,  DISP_TIMING_CONFIG_NONE, PLL_OVERRIDE_NONE, DISP_MODE_NONE,                                    DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER,     DISP_MODE_DUAL_DSI   | DISP_MODE_SKIP_BOOTLOADER),
};

/*===========================================================================
Function Definitions
===========================================================================*/

/**********************************************************************************************
*
* FUNCTION: PlatformClientInit()
*
* DESCRIPTION:
*   Initialize NPA client.
*
***********************************************************************************************/
MDP_Status PlatformClientInit(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status    Status = MDP_STATUS_OK;

  NPAClientName aNPAClientName[MDP_DISPLAY_MAX] =
  {
    /* Both primary and secondary display are sharing the same NPA nodes */
    {MDP_DISPLAY_PRIMARY,  PMIC_NPA_GROUP_ID_DISP_PRIM_AMOLED,     "DisplayPrim"},
    {MDP_DISPLAY_PRIMARY,  PMIC_NPA_GROUP_ID_DISP_PRIM_AMOLED,     "DisplaySec"},
    {MDP_DISPLAY_EXTERNAL, PMIC_NPA_GROUP_ID_DISP_EXT_DP,          "DisplayExt"},
  };

  if (eDisplayId >= MDP_DISPLAY_MAX )
  {
    DEBUG ((EFI_D_ERROR, "DisplayDxe: Unsupported Display ID for power init.\n"));
    Status =  MDP_STATUS_FAILED;
  }
  else if (NULL == pPowerParams->sNPAClient[eDisplayId])
  {
    if ((eDisplayId != aNPAClientName[eDisplayId].eMapDisplayId) &&
        (NULL       != pPowerParams->sNPAClient[aNPAClientName[eDisplayId].eMapDisplayId]))
    {
      pPowerParams->sNPAClient[eDisplayId] = pPowerParams->sNPAClient[aNPAClientName[eDisplayId].eMapDisplayId];
    }
    else
    {
      pPowerParams->sNPAClient[eDisplayId] = npa_create_sync_client(aNPAClientName[eDisplayId].cResourceName, aNPAClientName[eDisplayId].cClientName, NPA_CLIENT_REQUIRED); 

      if (NULL == pPowerParams->sNPAClient[eDisplayId])
      {
        DEBUG ((EFI_D_ERROR, "DisplayDxe: Failed to retrieve NPA Display Handle for Display ID %x.\n", eDisplayId ));
        Status =  MDP_STATUS_FAILED;
      }
    }
  }

  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_CheckOverride()
*
* DESCRIPTION:
*   Check if the panel was overridden by ABL (apps boot loader) and if so check 
*   if the overridden panel is supported by this platform.
*
*   This function has 1 of 3 outcomes
*   1. Panel is supported by both bootloader & kernel 
*      - Set matching xmlconfig
*   2. panel is only supported in kernel 
*      - Return dummyconfig, since sw rendering was already selected during initialization in this scenario
*   3. panel override is not set or the panel is not supported by bootloader & kernel
*      - Return FALSE to trigger panel detection
*
***********************************************************************************************/
static bool32 Panel_CheckOverride(MDP_Display_IDType eDisplayId, MDPPlatformPanelInfo *pPlatformPanel, MDPPlatformInfo *pPlatformInfo)
{
  Display_UtilsParamsType* pDisplayOverride = Display_Utils_GetParams();
  bool32                   bRet             = FALSE;
  PanelOverrideParams *pPanelParams;

  if (MDP_DISPLAY_PRIMARY == eDisplayId)
  {
    pPanelParams = &pDisplayOverride->sPrimary;
  }
  else
  {
    pPanelParams = &pDisplayOverride->sSecondary;
  }

  if ((NULL == pDisplayOverride))
  {
    /* do nothing */
  }
  else if ((pDisplayOverride->uFlags & (DISP_MODE_SKIP_BOOTLOADER | DISP_MODE_PANEL_NONE)))
  {
	/* panel select "none" */
        bRet = TRUE;
        pPlatformInfo->bSWRender = TRUE;
  }
  else if ((NULL != pPanelParams->psDTInfo)        &&
      (MDPPLATFORM_PANEL_NONE < pPanelParams->psDTInfo->ePanel))
  {
    // Lookup panel
    int32 i = PANEL_LIST_LENGTH(fastBootPanelList) - 1;

    while (0 <= i)
    {
      if (pPanelParams->psDTInfo->ePanel == fastBootPanelList[i].ePanel)
      {
        // Match found
        bRet = TRUE;
        pPlatformPanel->eSelectedPanel = fastBootPanelList[i].ePanel;

        if (pDisplayOverride->uFlags & DISP_MODE_SKIP_BOOTLOADER)
        {
          pPlatformInfo->bSWRender = TRUE;
          DEBUG((EFI_D_ERROR, "DisplayDxe: Panel override <%a> in skip mode\n", pPanelParams->shortName));
        }
        else
        {
          DEBUG((EFI_D_ERROR, "DisplayDxe: Panel override <%a>\n", pPanelParams->shortName));
        }
        break;
      }
      i--;
    }
  }
  else if(NULL == pPanelParams->psDTInfo)
  {
    uint32 uShortNameLen = AsciiStrLen(pPanelParams->shortName);
    if(uShortNameLen > 0)
    {
      /*panel not found in panel list, but shortName is not empty, still consider it as override*/
      pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_NONE;
      pPlatformInfo->bSWRender       = TRUE;
      bRet                           = TRUE;
    }
    else
    {
      /* using default panel if shortName is empty, actually the logic will never enter this branch, 
       * if shortName is empty, pDisplayOverride will be NULL.
       */
      pPlatformInfo->bSWRender = FALSE;
      bRet                     = FALSE;
    }
  }

  return bRet;
}
  

/**********************************************************************************************
*
* FUNCTION: DynamicDSIPanelDetection()
*
* DESCRIPTION:
*   Detect DSI panels by doing a DSI read specific to each panels.
*   This function could be used as sample for OEM to detect DSI panels, 
*   it is not a complete implementation of all possible combinations of read
*   commands that could be needed for this detection.
*   
*   Return success only if a DSI panel was correctly detected and the information 
*   is updated in pPlatformParams->sPlatformPanel
*
***********************************************************************************************/
static MDP_Status DynamicDSIPanelDetection(MDPPlatformPanelInfo *pPlatformPanel, uint32 *puPanelID, PlatformDSIDetectParams *pPanelList, uint32 uPanelCnt)
{
  MDP_Status             Status                = MDP_STATUS_NOT_SUPPORTED;
  bool32                 bDumpPanelId          = FALSE;
  MDP_Display_IDType     eDisplayId            = MDP_DISPLAY_PRIMARY;

  if (MDP_STATUS_OK == DSIDriver_MinimalInit())          // do minimal DSI init
  {
    uint8       panelID[PLATFORM_PANEL_ID_MAX_COMMANDS];
    uint32      uPanelIndex;
    bool32      bMatch         = FALSE;
    uint32      uPrevClkConfig = 0; 

    // go through all possible panels
    for (uPanelIndex = 0; uPanelIndex < uPanelCnt; uPanelIndex++)
    {
      uint8     readback[DSI_READ_READBACK_SIZE];
      uint32    readSize                          = sizeof(readback);
      int       iCommandIndex                     = 0;
      uint32    uClkConfig                        = (MDPPLATFORM_PANEL_DETECT_FLAG_CLOCK_FORCEHS & 
                                                     pPanelList[uPanelIndex].uFlags);

      // Check if there is any change in the clock config and set it accordingly
      if (uPrevClkConfig != uClkConfig)
      {
        if (MDP_STATUS_OK != DSIDriver_ConfigClockLane(uClkConfig))
        {
          DEBUG((EFI_D_ERROR, "Display: DSIDriver_ConfigClockLane failed\n"));
        }
        
        uPrevClkConfig = uClkConfig;
      }

      // Reprogram the DSI lane swap based on remap order
      if (MDP_STATUS_OK != DSIDriver_RemapLane(pPanelList[uPanelIndex].uLaneRemapOrder))
      {
        DEBUG((EFI_D_WARN, "Display: DSIDriver_RemapLane failed\n"));
      }

      // Allow debug option to scan panel registers (used to help generate a uniquie panel ID for detection)
      if (TRUE == bDumpPanelId)
      {
        DsiPanelDumpRegisters();
        // Dump just once
        bDumpPanelId = FALSE;
      }

      // clear the panel ID
      MDP_OSAL_MEMZERO(panelID, PLATFORM_PANEL_ID_MAX_COMMANDS);

      // for each possible panel ID read
      for(iCommandIndex = 0; iCommandIndex<PLATFORM_PANEL_ID_MAX_COMMANDS; iCommandIndex++)
      {
        uint32         uRetryCount = 0;

        // if read command is 0, then stop reading panel ID
        if ((0 == pPanelList[uPanelIndex].panelIdCommands[iCommandIndex].address[0]) &&
            (0 == pPanelList[uPanelIndex].panelIdCommands[iCommandIndex].address[1]) )
        {
          break;
        }
        // DSI read
        bMatch = FALSE;

        uRetryCount = 0;
        do
        {
          // clear the readback buffer
          MDP_OSAL_MEMZERO(&readback[0], readSize);
          readSize = sizeof(readback);
          Status = DSIDriver_Read(eDisplayId,
                                  pPanelList[uPanelIndex].uCmdType,
                                  pPanelList[uPanelIndex].panelIdCommands[iCommandIndex].address, 
                                  sizeof(pPanelList[uPanelIndex].panelIdCommands[iCommandIndex].address), 
                                  readback, 
                                  &readSize);

          uRetryCount++;
        } while((uRetryCount < pPanelList[uPanelIndex].uTotalRetry) && 
               ((MDP_STATUS_OK != Status)                           ||
                (0 == readSize)));

        if ((uRetryCount <= pPanelList[uPanelIndex].uTotalRetry) &&
            (0 != readSize))
        {
          // Read was successful, now check the data is what we expect
          if (0 == CompareMem(readback, pPanelList[uPanelIndex].panelIdCommands[iCommandIndex].expectedReadback, readSize))
          {
            panelID[iCommandIndex] = readback[0];    // store the first byte of readback as panel ID
            bMatch                 = TRUE;                       // mark one panel ID matched
          }
        }

        // if any panel ID is not matched, then go to detect next panel in the list
        if(FALSE == bMatch)
        {
          break;
        }
      }

      // if all panel IDs are matched for a specific panel, store settings and stop
      if(TRUE == bMatch)
      {
        // store matched panel configuration xml data

        pPlatformPanel->eSelectedPanel  = pPanelList[uPanelIndex].eSelectedPanel;

        // return the final combined panel ID
        *puPanelID = (panelID[0]<<16) | (panelID[1]<<8) | (panelID[2]);
        Status     = MDP_STATUS_OK;
        DEBUG((EFI_D_WARN, "Detected panel id:%08x\n", *puPanelID));
        break;
      }
      else
      {
        DEBUG((EFI_D_WARN, "Dynamic-Detected panel Failed\n"));
        Status = MDP_STATUS_FAILED;
      }
    }

    // Close the DSI context opened in DSIDriver_MinimalInit()
    DSIDriver_Close(eDisplayId);
  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: PlatformConfigRemap()
*
* DESCRIPTION:
*   Remapping of the platform configuration enumeration based on platform properties.
*
***********************************************************************************************/
static MDPPlatformConfigType PlatformConfigRemap(MDPPlatformInfo *pPlatformConfig, MDPPlatformConfigType eConfig)
{
  MDPPlatformConfigType eRemappedConfig;

  // In SW render mode bypass all configuration that manipulate the hardware
  if ((NULL !=  pPlatformConfig) && 
      (TRUE == pPlatformConfig->bSWRender))
  {
    switch (eConfig)
    {
      case MDPPLATFORM_CONFIG_POWERUP:
      case MDPPLATFORM_CONFIG_POWERDOWN:
      case MDPPLATFORM_CONFIG_SETBACKLIGHT:
      case MDPPLATFORM_CONFIG_RESETPANEL:
      case MDPPLATFORM_CONFIG_SETGPIOSTATE:
        
        // In SW render mode don't execute these hardware configurations
        eRemappedConfig = MDPPLATFORM_CONFIG_BYPASS;
        
        break;
     default:
      
        // Default mapping (output = input)
        eRemappedConfig = eConfig;
        
        break;
   }
 }
 else
 {
    // Default mapping (output = input)
    eRemappedConfig = eConfig;
 }

 return eRemappedConfig;
}


/**********************************************************************************************
*
* FUNCTION: MDPPlatformConfigure()
*
* DESCRIPTION:
*   The function is used to configure display, control power and brightness etc.
*
***********************************************************************************************/
MDP_Status MDPPlatformConfigure(MDP_Display_IDType eDisplayId, MDPPlatformConfigType eConfig, MDPPlatformParams *pPlatformParams)
{
  MDP_Status               eStatus               = MDP_STATUS_OK;
  MDPPlatformConfigType    ePlatformConfig;

  /* Static information, initial once during the first call */
  static MDPPlatformInfo         sPlatformInfo;
  static Panel_PowerCtrlParams   sPanelPowerCtrl;
  static MDPPlatformPanelInfo    sPlatformPanel[MDP_DISPLAY_MAX];
  MDPPlatformPanelFunctionTable *pMDPSupportPanelFunctions = MDP_GET_PANELFUNC(eDisplayId);

  // Get remapped platform configuration enum
  ePlatformConfig = PlatformConfigRemap(&sPlatformInfo, eConfig);

  switch (ePlatformConfig)
  {
  case MDPPLATFORM_CONFIG_INIT:
    MDP_OSAL_MEMZERO(&sPlatformInfo,              sizeof(MDPPlatformInfo));
    MDP_OSAL_MEMZERO(&sPanelPowerCtrl,            sizeof(Panel_PowerCtrlParams));
    MDP_OSAL_MEMZERO(sPlatformPanel,              sizeof(MDPPlatformPanelInfo)*MDP_DISPLAY_MAX);
    MDP_OSAL_MEMZERO(&gMDPSupportPanelFunctions,  sizeof(MDPPlatformPanelFunctionTable)*MDP_DISPLAY_MAX);
  
    // Read the platform ID once
    if (MDP_STATUS_OK == ReadPlatformIDAndChipID(&sPlatformInfo.sEFIPlatformType, &sPlatformInfo.sEFIChipSetId, &sPlatformInfo.sEFIChipSetFamily))
    {
      UINT32 uPanelOverride = 0;  

      // Read the display panel ID override, it will be checked later during detection
      if ((MDP_STATUS_OK  == MDP_Display_GetVariable_Integer (PANEL_OVERRIDE_STRINGNAME, &uPanelOverride)) &&
          (uPanelOverride  > 0))
      {
        sPlatformInfo.uPanelIdOverride = (uint32) uPanelOverride;
      }
    }
    break;
  
  case MDPPLATFORM_CONFIG_SW_RENDERER:
  
    if (NULL == pPlatformParams)
    {
      eStatus = MDP_STATUS_BAD_PARAM;
    }
    /* Setup display panel configurations according to CDT */
    else if (MDP_STATUS_OK != SetupPlatformPanelConfig(eDisplayId, &sPlatformPanel[eDisplayId], &sPlatformInfo, &pPlatformParams->sPlatformInfo))
    {
      eStatus = MDP_STATUS_FAILED;
    }
    else if (TRUE == sPlatformInfo.bSWRender)
    {
      // SW Render mode is enabled already, just return the status
      pPlatformParams->sPlatformInfo.bSWRender = TRUE;
    }
    else if ((EFI_PLATFORMINFO_TYPE_UNKNOWN == sPlatformInfo.sEFIPlatformType.platform)           ||
             (EFI_PLATFORMINFO_TYPE_VIRTIO  == sPlatformInfo.sEFIPlatformType.platform)           ||
             (TRUE                          == pPlatformParams->sPlatformInfo.bSWRenderOverrride) ||
             (TRUE                          == PcdGetBool(PcdDisplayForceSwRenderer))             ||
             (MDPPLATFORM_PANEL_NONE        == sPlatformPanel[eDisplayId].eSelectedPanel))
    {
      // Force SW render mode for emulation and unknown platforms
      pPlatformParams->sPlatformInfo.bSWRender = TRUE;
      // Store that an override has been requested by the caller
      sPlatformInfo.bSWRenderOverrride         = pPlatformParams->sPlatformInfo.bSWRenderOverrride;
      // Cache that SW Rendering is enabled
      sPlatformInfo.bSWRender                  = TRUE;
      DEBUG((EFI_D_ERROR, "DisplayDxe: SW renderer mode enabled!\n"));
    }
    else
    {
      // Force SW render mode off
      sPlatformInfo.bSWRender                  = FALSE;
      // Report SW render mode is disabled
      pPlatformParams->sPlatformInfo.bSWRender = FALSE;
    }
    break;
  case MDPPLATFORM_CONFIG_GETPANELCONFIG:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        // Retrieve panel configuration (could be dependent on the interface)
        switch (eDisplayId)
        {
        case MDP_DISPLAY_PRIMARY:
        case MDP_DISPLAY_SECONDARY:
          {
            uint32                    uPanelID   = 0;
            PlatformDSIDetectParams  *pPanelList = &uefiPanelList[0];
            uint32                    uPanelCnt  = PANEL_LIST_LENGTH(uefiPanelList);

            if (TRUE == sPlatformInfo.bSWRender)
            {
              pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8 *)dummy_xmldata;
              pPlatformParams->sPlatformPanel.uConfigSize     = sizeof (dummy_xmldata);
              pPlatformParams->sPlatformPanel.eSelectedPanel  = sPlatformPanel[eDisplayId].eSelectedPanel;
            }
            else
            {
              if ((TRUE          == sPlatformPanel[eDisplayId].bDetectPanel) &&
                  (MDP_STATUS_OK == DynamicDSIPanelDetection(&sPlatformPanel[eDisplayId], &uPanelID, pPanelList, uPanelCnt)))
              {
                /* Detected */
                sPlatformPanel[eDisplayId].uPanelId       = uPanelID;
                sPlatformInfo.uPrimaryPanelId = uPanelID;

                /*
                 * need redo mapping eSelectedPanle to uSelectedPanleIndex in case of newer
                 * eSelectedPanel detected 
                 */
                if (MDP_STATUS_OK != FindPanelIndex(&sPlatformPanel[eDisplayId]))
                {
                  DEBUG((EFI_D_WARN, "DisplayDxe: FindPanelIndex: No Panel Id=%d found\n", sPlatformPanel[eDisplayId].eSelectedPanel));
                }

                /* Save the panel functions into pMDPSupportPanelFunctions according to the panel detected for each display id */
                MDP_OSAL_MEMCPY(pMDPSupportPanelFunctions, &(sMDPPlatformPanelFunction[sPlatformPanel[eDisplayId].uSelectedPanelIndex]), sizeof(MDPPlatformPanelFunctionTable));
      
                /* If NULL is set for pMDPPlatformPanelGpio, then use the default panel gpio table */
                if (NULL == pMDPSupportPanelFunctions->pMDPPlatformPanelGpio)
                {
                  pMDPSupportPanelFunctions->pMDPPlatformPanelGpio = &sDefaultMDPPanelGpio;
                }
              }

              // Get the panel xml configurations.
              if ((FALSE == sPlatformInfo.bSWRender) &&
                  (MDP_STATUS_OK == GetPanelXmlConfig(eDisplayId, &sPlatformPanel[eDisplayId])))
              {
                /* Copy the panel configurations to pPlatformParams->sPlatformPanel */
                MDP_OSAL_MEMCPY(&pPlatformParams->sPlatformPanel, &sPlatformPanel[eDisplayId], sizeof(MDPPlatformPanelInfo));
              }
              else
              {
                pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8 *)dummy_xmldata;
                pPlatformParams->sPlatformPanel.uConfigSize     = sizeof (dummy_xmldata);
                pPlatformParams->sPlatformPanel.eSelectedPanel  = sPlatformPanel[eDisplayId].eSelectedPanel;
              }
            }
          }
          break;
  
        case MDP_DISPLAY_EXTERNAL: 
          switch (PcdGet32(PcdExtDisplayType))
          {
            case PCD_EXTERNAL_DISPLAY_DP:
              pPlatformParams->sDPConfig.bInvertPlugPolarity = DP_USBPlugInvertedOrientation();
              
              // For Nazgul, DP Phy lane to pad connection is the reverse of DP alt mode over usb type-c spec defined mapping
              pPlatformParams->sDPConfig.bReversePhyDataPath = TRUE;
              break;
          
            default:
              break;
          }
          break;
  
        default:
          break;
        }
      }
    }
    break;
  
  case MDPPLATFORM_CONFIG_POWERUP:
    {
      switch (eDisplayId)
      {
      case MDP_DISPLAY_PRIMARY:
      case MDP_DISPLAY_SECONDARY:
        // Config based on the platform
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
        case EFI_PLATFORMINFO_TYPE_MTP:
        case EFI_PLATFORMINFO_TYPE_QRD:
        case EFI_PLATFORMINFO_TYPE_HDK:
        {
          /* Check for common power or panel specific power,
           * Common Power : pPlatformParams is NULL or uFlags is 0x0,
           * Panel Power  : uFlags is set to panel specific power flag.
           */
          if ((NULL                          != pPlatformParams) &&
              (POWERCONFIG_FLAGS_PANEL_POWER  & pPlatformParams->sPowerConfig.uFlags))
          {
            switch (sPlatformPanel[eDisplayId].uPanelId)
            {
            default:
              // OEM to populate panel specific power up.
              break;
            }
          }
          else
          {
            // Primary Power Sequence
            if (NULL != pMDPSupportPanelFunctions->pPanel_PowerUp)
            {
              if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_PowerUp(eDisplayId, &sPanelPowerCtrl)))
              {
                DEBUG((EFI_D_WARN, "DisplayDxe: Primary Power Up Sequence failed (%d)\n", eStatus));
              }
            }
          
            if (NULL != pMDPSupportPanelFunctions->pPanel_Peripheral_Power)
            {
              if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_Peripheral_Power(eDisplayId, &sPanelPowerCtrl, TRUE)))
              {
                DEBUG((EFI_D_WARN, "DisplayDxe: Secondary Power Up Sequence failed (%d)\n", eStatus));
              }
            }
          }
          break;

        }
        default:
          break;
        }
        break;

      case MDP_DISPLAY_EXTERNAL:
        // Config based on the platform
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
        case EFI_PLATFORMINFO_TYPE_MTP:
        case EFI_PLATFORMINFO_TYPE_QRD:
        case EFI_PLATFORMINFO_TYPE_HDK:
          if ((NULL                          != pPlatformParams) &&
              (POWERCONFIG_FLAGS_PANEL_POWER  & pPlatformParams->sPowerConfig.uFlags))
          {
            // Do nothing for external panel specific power.
          }
          else
          {
            eStatus = ExternalPanel_Default_PowerUp(eDisplayId, &sPanelPowerCtrl);
          }
          break;

        default:
          break;
        }
        break;

      default:
        break;
      }
    }
    break;
    case MDPPLATFORM_CONFIG_GETPANELDTINFO:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        pPlatformParams->psPanelDTInfo = (PanelDTInfoType*)&fastBootPanelList;
      }
      break;
  
    }
    case MDPPLATFORM_CONFIG_GETPANELLIST:
      {
        if (NULL == pPlatformParams)
        {
          eStatus = MDP_STATUS_BAD_PARAM;
        }
        else
        {
          uint32 i = 0;
          
          while (MDPPLATFORM_PANEL_NONE != fastBootPanelList[i].ePanel)
          {
            //Copy Panel ID
            pPlatformParams->sPanelList.ePanel[i] = fastBootPanelList[i].ePanel;
            i++; 
          }
  
          pPlatformParams->sPanelList.uCount = i;
        }
      }
      break;
    
  case MDPPLATFORM_CONFIG_GETPANELSUPPORTFLAGS:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        //Lookup panel
        int32 i = PANEL_LIST_LENGTH(fastBootPanelList) - 1;
        while (0 <= i)
        {
          if (pPlatformParams->sPanelSupport.ePanel == fastBootPanelList[i].ePanel)
          {
            if ((DISP_TOPOLOGY_CONFIG_NONE == pPlatformParams->sPanelSupport.uModeIndex) ||
                (pPlatformParams->sPanelSupport.uModeIndex > DISPLAY_MODE_MAX))
            {
              pPlatformParams->sPanelSupport.uFlags = fastBootPanelList[i].uModeFlags[0];
            }
            else
            {
              pPlatformParams->sPanelSupport.uFlags = fastBootPanelList[i].uModeFlags[pPlatformParams->sPanelSupport.uModeIndex-1];
            }
            break;
          }
          i--;
        }
      }
    }
    break;
  case MDPPLATFORM_CONFIG_POWERDOWN:
    {
      // Handle power down
      switch (eDisplayId)
      {
      case MDP_DISPLAY_PRIMARY:
      case MDP_DISPLAY_SECONDARY:
  
        // Config based on the platform
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
        case EFI_PLATFORMINFO_TYPE_MTP:
        case EFI_PLATFORMINFO_TYPE_QRD:
        case EFI_PLATFORMINFO_TYPE_HDK:
          /* Check for common power or panel specific power,
           * Common Power : pPlatformParams is NULL or uFlags is 0x0,
           * Panel Power  : uFlags is set to panel specific power flag.
           */
          if ((NULL                          != pPlatformParams) &&
              (POWERCONFIG_FLAGS_PANEL_POWER  & pPlatformParams->sPowerConfig.uFlags))
          {
            switch (sPlatformPanel[eDisplayId].uPanelId)
            {
            default:
              // OEM to populate panel specific power down.
              break;
            }
          }
          else
          {
            if (NULL != pMDPSupportPanelFunctions->pPanel_PowerDown)
            {
              if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_PowerDown(eDisplayId, &sPanelPowerCtrl)))
              {
                DEBUG((EFI_D_WARN, "DisplayDxe: Primary Power Down Sequence failed (%d)\n", eStatus));
              }
            }

            /* Secondary Power Sequence */
            if (NULL != pMDPSupportPanelFunctions->pPanel_Peripheral_Power)
            {
              if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_Peripheral_Power(eDisplayId, &sPanelPowerCtrl, FALSE)))
              {
                DEBUG((EFI_D_WARN, "DisplayDxe: Secondary Power Down Sequence failed (%d)\n", eStatus));
              }
            }

            sPanelPowerCtrl.bBacklightEnabled = FALSE; /* wled is turned off */
          }
          break;

        default:
          break;
        }
        break;

      case MDP_DISPLAY_EXTERNAL:
        // Config based on the platform
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
        case EFI_PLATFORMINFO_TYPE_MTP:
        case EFI_PLATFORMINFO_TYPE_QRD:
        case EFI_PLATFORMINFO_TYPE_HDK:
          if ((NULL                          != pPlatformParams) &&
              (POWERCONFIG_FLAGS_PANEL_POWER  & pPlatformParams->sPowerConfig.uFlags))
          {
            // Do nothing for external panel specific power.
          }
          else
          {
            eStatus = ExternalPanel_Default_PowerDown(eDisplayId, &sPanelPowerCtrl);
          }
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
    }
    break;

  case MDPPLATFORM_CONFIG_SETBACKLIGHT:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        // Handle backlight level
        switch (eDisplayId)
        {
        case MDP_DISPLAY_PRIMARY:
        case MDP_DISPLAY_SECONDARY:
          switch (sPlatformInfo.sEFIPlatformType.platform)
          {
          case EFI_PLATFORMINFO_TYPE_CDP:
          case EFI_PLATFORMINFO_TYPE_MTP:
          case EFI_PLATFORMINFO_TYPE_QRD:
          case EFI_PLATFORMINFO_TYPE_HDK:

            if (FALSE == sPanelPowerCtrl.bBacklightEnabled)
            {
              if (NULL != pMDPSupportPanelFunctions->pPanel_Brightness_Enable)
              {
                if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_Brightness_Enable(eDisplayId, &sPanelPowerCtrl)))
                {
                  DEBUG((EFI_D_WARN, "MDPPlatformConfig: Backlight enabled failed\n"));
                }
              }

              sPanelPowerCtrl.bBacklightEnabled = TRUE;
            }

            if (NULL != pMDPSupportPanelFunctions->pPanel_Brightness_Level)
            {
              if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_Brightness_Level(eDisplayId, &pPlatformParams->sBacklightConfig)))
              {
                DEBUG((EFI_D_WARN, "MDPPlatformConfig: Backlight level control failed\n"));
              }
            }
            break;

          default:
            break;
          }
          break;
        case MDP_DISPLAY_EXTERNAL:
          eStatus = MDP_STATUS_NOT_SUPPORTED;
          break;
        default:
          break;
        }
      }
    }
    break;

  case MDPPLATFORM_CONFIG_GETPANELID:
    {
    }
    break;

  case MDPPLATFORM_CONFIG_GETPLATFORMINFO:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        //
        // Return platform information
        //
        MDP_OSAL_MEMCPY(&pPlatformParams->sPlatformInfo, &sPlatformInfo, sizeof(MDPPlatformInfo));
      }
    }
    break;

  case MDPPLATFORM_CONFIG_RESETPANEL:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
         if (pPlatformParams->sPlatformPanelReset.uResetGpio == 0)
         {
           sPanelPowerCtrl.uResetGpio                      = pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->uDispResetGpio;
           pPlatformParams->sPlatformPanelReset.uResetGpio = pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->uDispResetGpio;
         }
         else 
         {
           sPanelPowerCtrl.uResetGpio = pPlatformParams->sPlatformPanelReset.uResetGpio;
         }
         switch (eDisplayId)
         {
         case MDP_DISPLAY_PRIMARY:
         case MDP_DISPLAY_SECONDARY:
  
           // Config based on the platform
           switch (sPlatformInfo.sEFIPlatformType.platform)
           {
           case EFI_PLATFORMINFO_TYPE_CDP:
           case EFI_PLATFORMINFO_TYPE_MTP:
           case EFI_PLATFORMINFO_TYPE_QRD:
           case EFI_PLATFORMINFO_TYPE_HDK:

             if (NULL != pMDPSupportPanelFunctions->pPanel_Reset)
             {
               if (MDP_STATUS_OK != (eStatus = pMDPSupportPanelFunctions->pPanel_Reset(&pPlatformParams->sPlatformPanelReset)))
               {
                DEBUG((EFI_D_WARN, "MDPPlatformConfig: Panel reset failed (%d)\n", eStatus));
               }
             }
             break;
           default:
             break;
           }
  
           break;
         case MDP_DISPLAY_EXTERNAL:
           eStatus = MDP_STATUS_NOT_SUPPORTED;
           break;
         default:
           break;
         }
      }
    }
    break;

  case MDPPLATFORM_CONFIG_SETGPIOSTATE:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        eStatus = SetDefaultGPIOState(&pPlatformParams->sGPIOState);
      }
    }
    break;

  case MDPPLATFORM_CONFIG_GETPANELXMLINFO:
    {
      if (NULL == pPlatformParams)
      {
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        // Return the raw xml information if it is within range.
        if (pPlatformParams->sPanelXMLInfo.uIndex >= PANEL_LIST_LENGTH(uefiPanelList))
        {
          eStatus = MDP_STATUS_FAILED;
        }
        else if (TRUE == sPlatformInfo.bSWRender)
        {
          pPlatformParams->sPanelXMLInfo.pPanelXMLConfig = (int8 *)dummy_xmldata;
          pPlatformParams->sPanelXMLInfo.uPanelXMLSize   = sizeof (dummy_xmldata);
        }
        else
        {
          MDPPlatformPanelInfo sPlatformPanelInfo;

          MDP_OSAL_MEMZERO(&sPlatformPanelInfo, sizeof(MDPPlatformPanelInfo));
          sPlatformPanelInfo.eSelectedPanel = uefiPanelList[pPlatformParams->sPanelXMLInfo.uIndex].eSelectedPanel;
          if (MDP_STATUS_OK != FindPanelIndex(&sPlatformPanelInfo))
          {
              DEBUG((EFI_D_WARN, "DisplayDxe: GETPANELXMLINFO: FindPanelIndex: No Panel Id=%d found\n", sPlatformPanelInfo.eSelectedPanel));
          }

          if (MDP_STATUS_OK == GetPanelXmlConfig(eDisplayId, &sPlatformPanelInfo))
          {
            pPlatformParams->sPanelXMLInfo.pPanelXMLConfig = (int8*)sPlatformPanelInfo.pPanelXMLConfig;
            pPlatformParams->sPanelXMLInfo.uPanelXMLSize   = sPlatformPanelInfo.uConfigSize;
          }
          else
          {
            pPlatformParams->sPanelXMLInfo.pPanelXMLConfig = (int8 *)dummy_xmldata;
            pPlatformParams->sPanelXMLInfo.uPanelXMLSize   = sizeof (dummy_xmldata);
          }
        }
      }
    }
    break;

  case MDPPLATFORM_CONFIG_BYPASS:
    {
      // SW Render Bypass mode
      eStatus = MDP_STATUS_OK;
    }
    break; 

  default:
    eStatus = MDP_STATUS_BAD_PARAM;
    break;
  }
  
  return eStatus;
}


/*===========================================================================
Private Function Definitions
===========================================================================*/

/**********************************************************************************************
*
* FUNCTION: ReadPlatformIDAndChipID()
*
* DESCRIPTION:
*   Read the platform info.
*
***********************************************************************************************/
static MDP_Status ReadPlatformIDAndChipID(EFI_PLATFORMINFO_PLATFORM_INFO_TYPE *pPlatformInfo, EFIChipInfoIdType *pChipSetId, EFIChipInfoFamilyType *pChipSetFamily)
{
  MDP_Status                           eStatus                = MDP_STATUS_OK;
  EFI_PLATFORMINFO_PROTOCOL            *hPlatformInfoProtocol;
  EFI_CHIPINFO_PROTOCOL                *hChipInfoProtocol;

  if (EFI_SUCCESS == gBS->LocateProtocol(&gEfiPlatformInfoProtocolGuid,
                                         NULL,
                                         (VOID **)&hPlatformInfoProtocol))
  {
    if (EFI_SUCCESS != hPlatformInfoProtocol->GetPlatformInfo(hPlatformInfoProtocol, pPlatformInfo))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: gEfiPlatformInfoProtocolGuid->GetPlatformInfo() failed.\n"));

      eStatus = MDP_STATUS_FAILED;
    }
  }
  else
  {
    DEBUG((EFI_D_WARN, "DisplayDxe: gEfiPlatformInfoProtocolGuid protocol failed.\n"));

    eStatus = MDP_STATUS_FAILED;
  }

  if (EFI_PLATFORMINFO_TYPE_UNKNOWN == pPlatformInfo->platform)
  {
    pPlatformInfo->platform = EFI_PLATFORMINFO_TYPE_VIRTIO;
  }

  // Read the chipset ID
  if (EFI_SUCCESS == gBS->LocateProtocol(&gEfiChipInfoProtocolGuid,
                                         NULL,
                                         (VOID **)&hChipInfoProtocol))
  {
    if (EFI_SUCCESS != hChipInfoProtocol->GetChipId(hChipInfoProtocol, pChipSetId))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: gEfiChipInfoProtocolGuid->GetChipId() failed. \n"));

      eStatus = MDP_STATUS_FAILED;
    }

    if (EFI_SUCCESS != hChipInfoProtocol->GetChipFamily(hChipInfoProtocol, pChipSetFamily))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: gEfiChipInfoProtocolGuid->GetChipFamily() failed. \n"));

      eStatus = MDP_STATUS_FAILED;
    }
  }
  else
  {
    DEBUG((EFI_D_WARN, "DisplayDxe: gEfiChipInfoProtocolGuid protocol failed.\n"));

    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}


/**********************************************************************************************
*
* FUNCTION: SetDefaultGPIOState()
*
* DESCRIPTION:
*   The function toggles a list of GPIO's based on the requested configuration.
*
****************************************************************************/
static MDP_Status SetDefaultGPIOState(GpioStateType *pGPIOList)
{
  MDP_Status          eStatus = MDP_STATUS_OK;

  if ((NULL == pGPIOList) ||
      (NULL == pGPIOList->pGPIOList))
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    // Handle each type of GPIO differently
    switch (pGPIOList->eGPIOType)
    {
      case MDPPLATFORM_GPIOTYPE_TLMM:
         {
           EFI_TLMM_PROTOCOL   *TLMMProtocol;        

           if (EFI_SUCCESS == gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void**)&TLMMProtocol))
           {
             uint32 uCount;          

             // Loop the list to configure all GPIOs.
             for (uCount=0;uCount<pGPIOList->uListSize;uCount++)
             {
                // Only try to program GPIOs that are within range, TLMM Macro (EFI_GPIO_CFG) supports up to 0x3FF
                if (pGPIOList->pGPIOList[uCount] < 0x3FF) 
                {
                  uint32 uValue = (pGPIOList->uState>0)?GPIO_HIGH_VALUE:GPIO_LOW_VALUE;
                  
                  // Setup GPIO
                  if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(pGPIOList->pGPIOList[uCount], 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA), TLMM_GPIO_ENABLE))
                  {
                    DEBUG((EFI_D_ERROR, "DisplayDxe: Error configuring TLMM GPIO%d\n", uCount));

                  }

                  // Setup Output
                  if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(pGPIOList->pGPIOList[uCount], 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA), uValue))
                  {
                    DEBUG((EFI_D_ERROR, "DisplayDxe: Error configuring TLMM GPIO%d\n", uCount));
                  }              
                }
             }
           }
           else
           {
             eStatus = MDP_STATUS_NO_RESOURCES;
           }
         }
         break;
      default:
          // Others (PMIC, PMI) not supported
         break;
    }
  }
  return eStatus;
}

/**********************************************************************************************
*
* FUNCTION: FindPanelIndex()
*
* DESCRIPTION:
*   The function convert panel id into Index to panel table index
*
***********************************************************************************************/
static MDP_Status FindPanelIndex(MDPPlatformPanelInfo *pPlatformPanel)
{
    MDP_Status eStatus                        = MDP_STATUS_NO_RESOURCES;
    MDPPlatformPanelFunctionTable *panelTable = sMDPPlatformPanelFunction;
    UINT32  uIndex                            = 0;
  
    for (uIndex = 0; uIndex < MDPPLATFORM_PANEL_MAX; uIndex++)
    {
        if (panelTable == NULL)
        {
             break;
        }
        else if (panelTable->ePanelSelected == pPlatformPanel->eSelectedPanel)
        {
             pPlatformPanel->uSelectedPanelIndex = uIndex;
             eStatus     = MDP_STATUS_OK;
             break;
        }
        panelTable++;
    }
    return eStatus;
}


/**********************************************************************************************
*
* FUNCTION: GetPanelXmlConfig()
*
* DESCRIPTION:
*   The function can get the panel xml configurations.
*
***********************************************************************************************/
static MDP_Status GetPanelXmlConfig (MDP_Display_IDType eDisplayId, MDPPlatformPanelInfo *pPlatformPanel)
{
  MDP_Status                     eStatus                   = MDP_STATUS_OK;
  UINT32                         uRetSize                  = 0;
  UINT8                         *pFileBuffer               = NULL;
  UINT32                         uBufferSize               = 0;
  MDPPlatformPanelFunctionTable *pMDPSupportPanelFunctions = MDP_GET_PANELFUNC(eDisplayId);

  if ((NULL                  == pPlatformPanel) ||
      (MDPPLATFORM_PANEL_MAX <= pPlatformPanel->uSelectedPanelIndex))
  {
    eStatus = MDP_STATUS_NO_RESOURCES;
  }
  else if (NULL == pMDPSupportPanelFunctions->pPanelXml)
  {
    eStatus = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != Display_Utils_LoadFile(pMDPSupportPanelFunctions->pPanelXml,
                                                &pFileBuffer,
                                                &uBufferSize,
                                                &uRetSize,
                                                0))
  {
    eStatus = MDP_STATUS_FAILED;
  }
  else if (NULL != pFileBuffer)
  {
    pPlatformPanel->pPanelXMLConfig = (int8 *)pFileBuffer;
    pPlatformPanel->uConfigSize     = uRetSize;
  }
  else
  {
    /* Read null from the file, just return with fail status */
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}


/**********************************************************************************************
*
* FUNCTION: SetupPlatformPanelConfig()
*
* DESCRIPTION:
*   The function can get the display panel that is being used.
*
***********************************************************************************************/
static MDP_Status SetupPlatformPanelConfig(MDP_Display_IDType    eDisplayId,
                                           MDPPlatformPanelInfo *pPlatformPanel,
                                           MDPPlatformInfo      *pPlatformInfo,
                                           MDPPlatformInfo      *pMDPPlatformInfo)
{
  MDP_Status               eStatus    = MDP_STATUS_OK;
  PlatformDSIDetectParams *pPanelList = NULL;
  uint32                   uPanelCnt  = 0;
  uint32                   uPanelID   = 0;

  if ((NULL == pPlatformPanel) ||
      (NULL == pPlatformInfo)  ||
      (NULL == pMDPPlatformInfo))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: The platform panel info is NULL\n"));
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if (TRUE == pPlatformInfo->bPanelInitialized[eDisplayId])
  {
    // Panel has already been initialized once, only save the selected panel.
     pMDPPlatformInfo->eSelectedPanel = pPlatformPanel->eSelectedPanel;
  }
  else
  {
    // Parse sub-revision specific info to determine the platform type
    MDPPlatformPanelFunctionTable *pMDPSupportPanelFunctions = MDP_GET_PANELFUNC(eDisplayId);

    if (TRUE == Panel_CheckOverride(eDisplayId, pPlatformPanel, pPlatformInfo))
    {
      // Use configuration set by panel override
    }
    else if (TRUE == pPlatformInfo->bSWRender)
    {
      // Use dummy panel for sw rendering
      pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_NONE;
    }
    else
    {
      // Report the proper information depending on the display.
      switch (pPlatformInfo->sEFIPlatformType.platform)
      {
      case EFI_PLATFORMINFO_TYPE_MTP:
        /* version 0x10000 is Trinity (Kona APQ) version 0x20000 is Morpheus (Kona Fusion) */
        if ((0x1 == pPlatformInfo->sEFIPlatformType.subtype) &&
            ((0x10000 == pPlatformInfo->sEFIPlatformType.version) ||
             (0x20000 == pPlatformInfo->sEFIPlatformType.version) ||
			 (0x30000 == pPlatformInfo->sEFIPlatformType.version)))
        {
          pPlatformInfo->bSWRender          = TRUE;
          pPlatformPanel->eSelectedPanel    = MDPPLATFORM_PANEL_NONE;
          break;
        }
        /* Fall through to CDP case */

      case EFI_PLATFORMINFO_TYPE_CDP:
        if ((EFI_PLATFORMINFO_TYPE_CDP == pPlatformInfo->sEFIPlatformType.platform) &&
            (0x10001 == pPlatformInfo->sEFIPlatformType.version))  /* version = 1.1 */
        {
           /* CDP with LCD pmic chip */
           pPanelList = &uefiPanelList[3]; // Panel #3 - Sharp 4k DSC DSI cmd Mode Panel (2160x3840 24bpp) ID:0x8056
        }
        else               
        {
           /* others, default to CDP with amoled pmic chip */
           pPanelList = &uefiPanelList[0]; // Panel #0 - boe amoled DSC DSI cmd Mode Panel (1440x2880 24bpp) ID:0x8056
        }

        uPanelCnt  = PANEL_LIST_LENGTH(uefiPanelList);

        // If the panel ID override is enabled and within range, force that panel configuration.
        if ((pPlatformInfo->uPanelIdOverride & PANEL_OVERRIDE_ENABLE_MASK) &&
            (PANEL_OVERRIDE_PANELID(pPlatformInfo->uPanelIdOverride) < uPanelCnt))
        {
          pPanelList                     = &uefiPanelList[PANEL_OVERRIDE_PANELID(pPlatformInfo->uPanelIdOverride)];
          DEBUG((EFI_D_ERROR, "DisplayDxe: Panel override enabled (Index: %d ID:0x%x)\n", PANEL_OVERRIDE_PANELID(pPlatformInfo->uPanelIdOverride), uPanelID));
        }
        else
        {
          // No override and it is not SW render - select default panel for power up and trigger dynamic detection
          pPlatformPanel->bDetectPanel   = TRUE;
        }

        pPlatformPanel->eSelectedPanel   = pPanelList->eSelectedPanel;
        uPanelID                         = ((pPanelList->panelIdCommands[1].expectedReadback[0] << 8) |
                                             pPanelList->panelIdCommands[2].expectedReadback[0]);
        pPlatformPanel->uPanelId         = uPanelID;
        pPlatformInfo->uPrimaryPanelId   = uPanelID;
        break;

      case EFI_PLATFORMINFO_TYPE_QRD:
        if (0x03 == pPlatformInfo->sEFIPlatformType.subtype)
        {
          TLMM_ValueType  eGpioValue = GPIO_HIGH_VALUE;

          if ((EFI_SUCCESS     == GetDisplayGpioValue(RB5_DISP_MODE_SWITCH_GPIO, &eGpioValue)) &&
              (GPIO_LOW_VALUE  == eGpioValue))
          {
            // Select 1080p mode if the display mode GPIO is low
            pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_EXT_BRIDGE_1080P_VIDEO;
          }
          else
          {
            // Select 4k mode if the display mode GPIO is high
            pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_EXT_BRIDGE_4K_VIDEO;
          }
        }
        else
        {
          pPlatformPanel->eSelectedPanel   = MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD;
        }
        break;

      case EFI_PLATFORMINFO_TYPE_HDK:
        {
          TLMM_ValueType  eGpioValue = GPIO_HIGH_VALUE;

          if ((EFI_SUCCESS     == GetDisplayGpioValue(HDK_DISP_DSI_STATUS_GPIO, &eGpioValue)) &&
              (GPIO_LOW_VALUE  == eGpioValue))
          {
            // Select dsi panel if the DSIStatus GPIO is low
            pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD;
          }
          else
          {
            pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_NONE;
          }
        }
        break;

      case EFI_PLATFORMINFO_TYPE_RUMI:
      default:
        pPlatformPanel->eSelectedPanel = MDPPLATFORM_PANEL_NONE;
          break;
        }
     } 
     
     if (MDP_STATUS_OK != FindPanelIndex(pPlatformPanel))
     {
       DEBUG((EFI_D_WARN, "DisplayDxe: FindPanelIndex: No Panel Id=%d found\n", pPlatformPanel->eSelectedPanel));
     }
     
     /* Save the panel functions into pMDPSupportPanelFunctions according to the panel detected for each display id */
     MDP_OSAL_MEMCPY(pMDPSupportPanelFunctions, &(sMDPPlatformPanelFunction[pPlatformPanel->uSelectedPanelIndex]), sizeof(MDPPlatformPanelFunctionTable));
     
     /* If NULL is set for pMDPPlatformPanelGpio, then use the default panel gpio table */
     if (NULL == pMDPSupportPanelFunctions->pMDPPlatformPanelGpio)
     {
       pMDPSupportPanelFunctions->pMDPPlatformPanelGpio = &sDefaultMDPPanelGpio;
     }
     
     pPlatformInfo->bPanelInitialized[eDisplayId]  = TRUE;
     pMDPPlatformInfo->eSelectedPanel              = pPlatformPanel->eSelectedPanel;
   }

   return eStatus;
}


/**********************************************************************************************
*
* FUNCTION: GetDisplayGpioValue()
*
* DESCRIPTION:
*   The function can get the display gpio value.
*
***********************************************************************************************/
static EFI_STATUS GetDisplayGpioValue(uint32 uGpioNum, TLMM_ValueType *pGpioValue)
{
  EFI_STATUS           eStatus       = EFI_SUCCESS;
  EFI_TLMM_PROTOCOL   *TLMMProtocol  = NULL;

  if ((NULL         ==  pGpioValue) ||
      (EFI_SUCCESS  !=  gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol)))
  {
    DEBUG((EFI_D_WARN, "DisplayDxe: Invalid gpio value parameter or Locate TLMM protocol failed!\n"));
    eStatus = EFI_INVALID_PARAMETER;
  }
  else
  {
    UINT32 uGpioConfig = (UINT32)EFI_GPIO_CFG(uGpioNum, 0, GPIO_INPUT, GPIO_NO_PULL, GPIO_2MA);

    if (EFI_SUCCESS != (eStatus = TLMMProtocol->ConfigGpio(uGpioConfig, TLMM_GPIO_ENABLE)))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure display GPIO(%d) failed with status(%d)!\n", uGpioNum, eStatus));
    }

    if (EFI_SUCCESS != (eStatus = TLMMProtocol->GpioIn(uGpioConfig, pGpioValue)))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Get display GPIO(%d) value failed with status(%d)!\n", uGpioNum, eStatus));
    }
  }

  return eStatus;
}


#ifdef __cplusplus
}
#endif
