/*=============================================================================
 
  File: MDPPlatformLib.c
 
  MDP platform specific functions
  
  Copyright (c) 2016-2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include <PlatformInfo.h>
#include <Library/PcdLib.h>
#include <api/pmic/pm/pm_lcdb.h>
#include <api/pmic/pm/pm_wled.h>
#include <api/pmic/pm/pm_ldo.h>
#include <api/pmic/pm/pm_smps.h>
#include <api/pmic/pm/pm_boot.h>
#include <api/pmic/pm/pm_version.h>
#include "MDPTypes.h"
#include "MDPPlatformLib.h"
#include "MDPSystem.h"
#include "DDITlmm.h"
#include "pmapp_npa.h"
#include "npa.h"
#include "boot_extern_platforminfo_interface.h"
#include "HALDSILib.h"

/* -----------------------------------------------------------------------
** Defines
** ----------------------------------------------------------------------- */
#define PCD_PANEL_TYPE_OEM                1

#define DSI_READ_ADDRESS_SIZE             2
#define DSI_READ_READBACK_SIZE            8

#define PLATFORM_PANEL_ID_MAX_COMMANDS    3       // maximum panel ID read commands

// PMIC Device Indices
#define PMIC_A                    0       // PMIC device (Vreg, LDO, ect)
#define PMIC_A                    0       // PMIC device (Vreg, LDO, ect)
#define PMIC_PMI_DEV_INDEX                1       // PMIC interface device (IBB/LAB, GPIO,  WLED)

#define PMIC_IBBLAB_READYTIME             25      // Maximum of milliseconds to wait for IBB/LAB to stabilize (Can be up to 8.8ms +/-16%)

/* SM8250 Main Panel CDP specific defines
*/
#define CDP_DISP_RESET_GPIO                75      // GPIO number for LCD0_RESET
#define CDP_DISP_TE_GPIO                   66      // GPIO number for TE
#define CDP_DISP_MODE_SEL                  46      // GPIO for panel mode select 0 = Dual Port, 1 = Single Port (DSC)
#define CDP_DISP_LCD_REG_EN                61      // GPIO for LCD internal boost power
#define CDP_DISP_LCD_BKLT_EN               60      // GPIO for backlight enable
#define CDP_SEC_DISP_RESET_GPIO            128     // GPIO number for LCD0_RESET on secondary display
#define CDP_SEC_DISP_TE_GPIO               67      // GPIO number for TE on secondary display

#define DSI_WRITE_BACKLIGHT_SIZE           3

#define DISP_DIV_ROUND_UP(x, y) (((x) + (y/2)) / (y))

// Get reset gpio based on display id
#define GET_CDP_DISP_RESET_GPIO(_displayId_)  (((_displayId_) == MDP_DISPLAY_SECONDARY) ? CDP_SEC_DISP_RESET_GPIO : CDP_DISP_RESET_GPIO)

// Get te gpio based on display id
#define GET_CDP_DISP_TE_GPIO(_displayId_)     (((_displayId_) == MDP_DISPLAY_SECONDARY) ? CDP_SEC_DISP_TE_GPIO : CDP_DISP_TE_GPIO)

/* -----------------------------------------------------------------------
** Types
** ----------------------------------------------------------------------- */

/* Panel command ID list for dynamic panel detection
*/

typedef struct {
  uint8      address[DSI_READ_ADDRESS_SIZE];                                        // DCS command for panel ID
  uint8      expectedReadback[DSI_READ_READBACK_SIZE];                              // expected readback
} PlatformPanelIDCommandInfo;

/* Dynamic panel ID detection entry 
 */
typedef struct {
  uint8                         uCmdType;                                             // data type for panel ID DSI read
  uint32                        uTotalRetry;                                          // number of retry if DSI read fails
  PlatformPanelIDCommandInfo    panelIdCommands[PLATFORM_PANEL_ID_MAX_COMMANDS];      // commands for panel ID and expected readback
  uint32                        uLaneRemapOrder;                                      // Lane remap order
  const int8                   *psPanelCfg;                                           // pointer to the panel configuration
  uint32                        uPanelCfgSize;                                        // size of panel configuration data
  uint32                        uFlags;                                               // flags to set clock config for now, can set other config in future
} PlatformDSIDetectParams;

/* Power configuration 
 */
typedef struct
{
  MDP_PmicModuleControlType     ePMICSecondaryPower[MDP_DISPLAY_MAX];                 // Configuration for PMIC based secondary power source
} Panel_PowerCtrlParams;
/* NPA Client info
*/
typedef struct
{
  char*                         cResourceName;
  char*                         cClientName;
}NPAClientName;


/* Panel backlight DCS command
 */ 
typedef struct {
  uint8      uCmdType;                                                                // DCS command type for backlight control
  uint8      command[DSI_WRITE_BACKLIGHT_SIZE];                                       // DCS command for backlight control
} PlatformPanelBacklightControl;

/* -----------------------------------------------------------------------
** Local functions
** ----------------------------------------------------------------------- */

/* Platform detection 
*/
static MDP_Status ReadPlatformIDAndChipID(EFI_PLATFORMINFO_PLATFORM_INFO_TYPE *pPlatformInfo, EFIChipInfoIdType *pChipSetId, EFIChipInfoFamilyType *pChiSetFamily);


/* 8998 Main Panel CDP Functions
*/
static MDP_Status Panel_CDP_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
static MDP_Status Panel_CDP_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
static MDP_Status Panel_CDP_Reset(MDP_Display_IDType eDisplayId);
static MDP_Status Panel_CDP_BacklightLevel(MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig);
static MDP_Status Panel_CDP_PeripheralPower(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp);
static void Panel_IBBLAB_WaitForReady();

/* Main Panel CDP/MTP Functions
*/


/* General helper functions */
MDP_Status SetDefaultGPIOState(GpioStateType *pGPIOList);


/*===========================================================================
 Local Configuration Definitions
 ===========================================================================*/
/******************************************************************
 *               Primary Sharp 1080p Cmd Panel                    *
 *                                                                *
 *                   1080x1920                                    *
 *                   Single-DSI(DSI0)                             *
 *                   Command mode                                 *
 ******************************************************************/
const static int8 Primary_Sharp_1080p_cmd_xmldata[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"<PanelDescription>Sharp DSI Command Mode Panel (1080x1920 24bpp)</PanelDescription>"
"<Group id=\"Active Timing\">"
" <HorizontalActive>1080</HorizontalActive>"
" <HorizontalFrontPorch>0</HorizontalFrontPorch>"
" <HorizontalBackPorch>0</HorizontalBackPorch>"
" <HorizontalSyncPulse>0</HorizontalSyncPulse>"
" <HorizontalSyncSkew>0</HorizontalSyncSkew>"
" <HorizontalLeftBorder>0</HorizontalLeftBorder>"
" <HorizontalRightBorder>0</HorizontalRightBorder>"
" <VerticalActive>1920</VerticalActive>"
" <VerticalFrontPorch>0</VerticalFrontPorch>"
" <VerticalBackPorch>0</VerticalBackPorch>"
" <VerticalSyncPulse>0</VerticalSyncPulse>"
" <VerticalSyncSkew>0</VerticalSyncSkew>"
" <VerticalTopBorder>0</VerticalTopBorder>"
" <VerticalBottomBorder>0</VerticalBottomBorder>"
" <InvertDataPolarity>False</InvertDataPolarity>"
" <InvertVsyncPolairty>False</InvertVsyncPolairty>"
" <InvertHsyncPolarity>False</InvertHsyncPolarity>"
" <BorderColor>0x0</BorderColor>"
"</Group>"
"<Group id=\"Display Interface\">"
" <InterfaceType>9</InterfaceType>"
" <InterfaceColorFormat>3</InterfaceColorFormat>"
"</Group>"
"<Group id=\"DSI Interface\">"
" <DSIChannelId>2</DSIChannelId>"
" <DSIVirtualId>0</DSIVirtualId>"
" <DSIColorFormat>36</DSIColorFormat>"
" <DSITrafficMode>1</DSITrafficMode>"
" <DSILanes>4</DSILanes>"
" <DSIRefreshRate>0x3C0000</DSIRefreshRate>"
" <DSICmdSwapInterface>False</DSICmdSwapInterface>"
" <DSICmdUsingTrigger>False</DSICmdUsingTrigger>"
" <DSIEnableAutoRefresh>True</DSIEnableAutoRefresh>"
" <DSIAutoRefreshFrameNumDiv>2</DSIAutoRefreshFrameNumDiv>"
" <DSITECheckEnable>True</DSITECheckEnable>"
" <DSITEUsingDedicatedTEPin>True</DSITEUsingDedicatedTEPin>"
" <DSITEvSyncStartPos>1920</DSITEvSyncStartPos>"
" <DSITEvSyncInitVal>1920</DSITEvSyncInitVal>"
" <DSIControllerMapping>"
"  00\n"
" </DSIControllerMapping>"
"</Group>"
"<DSIInitSequence>"
" 15 BB 10\n"
" 15 B0 03\n"
" 05 11 00\n"
" FF 78\n"
" 15 51 FF\n"
" 15 53 24\n"
" 15 FF 23\n"
" 15 08 05\n"
" 15 46 90\n"
" 15 FF 10\n"
" 15 FF F0\n"
" 15 92 01\n"
" 15 FF 10\n"
" 15 35 00\n"
" 05 29 00\n"
" FF 28\n"
"</DSIInitSequence>"
"<DSITermSequence>"
" 05 28\n"
" 05 10\n"
"</DSITermSequence>"
"<TLMMGPIODefaultHigh units='hex list'>0x2E 0x3D</TLMMGPIODefaultHigh>"
"<Group id='Backlight Configuration'>"
" <BacklightType>3</BacklightType>"
"</Group>\n";


/******************************************************************
 *               Secondary Truly 1080p Cmd Panel                  *
 *                                                                *
 *                   1080x1920                                    *
 *                   Single-DSI(DSI1)                             *
 *                   Command mode                                 *
 ******************************************************************/
const static int8 Secondary_Truly_1080p_cmd_xmldata[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"<PanelName>NT35695b</PanelName>"
"<PanelDescription>Truly FHD Command Mode Panel (1080x1920 24bpp)</PanelDescription>"
"<Group id=\"Active Timing\">"
" <HorizontalActive>1080</HorizontalActive>"
" <HorizontalFrontPorch>120</HorizontalFrontPorch>"
" <HorizontalBackPorch>60</HorizontalBackPorch>"
" <HorizontalSyncPulse>12</HorizontalSyncPulse>"
" <HorizontalSyncSkew>0</HorizontalSyncSkew>"
" <HorizontalLeftBorder>0</HorizontalLeftBorder>"
" <HorizontalRightBorder>0</HorizontalRightBorder>"
" <VerticalActive>1920</VerticalActive>"
" <VerticalFrontPorch>12</VerticalFrontPorch>"
" <VerticalBackPorch>2</VerticalBackPorch>"
" <VerticalSyncPulse>2</VerticalSyncPulse>"
" <VerticalSyncSkew>0</VerticalSyncSkew>"
" <VerticalTopBorder>0</VerticalTopBorder>"
" <VerticalBottomBorder>0</VerticalBottomBorder>"
" <InvertDataPolarity>False</InvertDataPolarity>"
" <InvertVsyncPolairty>False</InvertVsyncPolairty>"
" <InvertHsyncPolarity>False</InvertHsyncPolarity>"
" <BorderColor>0x0</BorderColor>"
"</Group>"
"<Group id=\"Display Interface\">"
" <InterfaceType>11</InterfaceType>"
" <InterfaceColorFormat>3</InterfaceColorFormat>"
"</Group>"
"<Group id=\"DSI Interface\">"
" <DSIChannelId>2</DSIChannelId>"
" <DSIVirtualId>0</DSIVirtualId>"
" <DSIColorFormat>36</DSIColorFormat>"
" <DSITrafficMode>1</DSITrafficMode>"
" <DSILanes>4</DSILanes>"
" <DSIRefreshRate>0x3C0000</DSIRefreshRate>"
" <DSICmdSwapInterface>False</DSICmdSwapInterface>"
" <DSICmdUsingTrigger>False</DSICmdUsingTrigger>"
" <DSIEnableAutoRefresh>True</DSIEnableAutoRefresh>"
" <DSIAutoRefreshFrameNumDiv>2</DSIAutoRefreshFrameNumDiv>"
" <DSITECheckEnable>True</DSITECheckEnable>"
" <DSITEUsingDedicatedTEPin>True</DSITEUsingDedicatedTEPin>"
" <DSITEvSyncStartPos>1920</DSITEvSyncStartPos>"
" <DSITEvSyncInitVal>1920</DSITEvSyncInitVal>"
" <DSITEvSyncSelect>1</DSITEvSyncSelect>"
" <DSIControllerMapping>"
"  01\n"
" </DSIControllerMapping>"
"</Group>"
"<DSIInitSequence>"
" 15 FF 20\n"
" 15 FB 01\n"
" 15 00 01\n"
" 15 01 55\n"
" 15 02 45\n"
" 15 03 55\n"
" 15 05 50\n"
" 15 06 A8\n"
" 15 07 AD\n"
" 15 08 0C\n"
" 15 0B AA\n"
" 15 0C AA\n"
" 15 0E B0\n"
" 15 0F B3\n"
" 15 11 28\n"
" 15 12 10\n"
" 15 13 01\n"
" 15 14 4A\n"
" 15 15 12\n"
" 15 16 12\n"
" 15 30 01\n"
" 15 72 11\n"
" 15 58 82\n"
" 15 59 00\n"
" 15 5A 02\n"
" 15 5B 00\n"
" 15 5C 82\n"
" 15 5D 80\n"
" 15 5E 02\n"
" 15 5F 00\n"
" 15 FF 24\n"
" 15 FB 01\n"
" 15 00 01\n"
" 15 01 0B\n"
" 15 02 0C\n"
" 15 03 89\n"
" 15 04 8A\n"
" 15 05 0F\n"
" 15 06 10\n"
" 15 07 10\n"
" 15 08 1C\n"
" 15 09 00\n"
" 15 0A 00\n"
" 15 0B 00\n"
" 15 0C 00\n"
" 15 0D 13\n"
" 15 0E 15\n"
" 15 0F 17\n"
" 15 10 01\n"
" 15 11 0B\n"
" 15 12 0C\n"
" 15 13 89\n"
" 15 14 8A\n"
" 15 15 0F\n"
" 15 16 10\n"
" 15 17 10\n"
" 15 18 1C\n"
" 15 19 00\n"
" 15 1A 00\n"
" 15 1B 00\n"
" 15 1C 00\n"
" 15 1D 13\n"
" 15 1E 15\n"
" 15 1F 17\n"
" 15 20 00\n"
" 15 21 01\n"
" 15 22 00\n"
" 15 23 40\n"
" 15 24 40\n"
" 15 25 6D\n"
" 15 26 40\n"
" 15 27 40\n"
" 15 29 D8\n"
" 15 2A 2A\n"
" 15 4B 03\n"
" 15 4C 11\n"
" 15 4D 10\n"
" 15 4E 01\n"
" 15 4F 01\n"
" 15 50 10\n"
" 15 51 00\n"
" 15 52 80\n"
" 15 53 00\n"
" 15 54 07\n"
" 15 55 25\n"
" 15 56 00\n"
" 15 58 07\n"
" 15 5B 43\n"
" 15 5C 00\n"
" 15 5F 73\n"
" 15 60 73\n"
" 15 63 22\n"
" 15 64 00\n"
" 15 67 08\n"
" 15 68 04\n"
" 15 7A 80\n"
" 15 7B 91\n"
" 15 7C d8\n"
" 15 7D 60\n"
" 15 93 06\n"
" 15 94 06\n"
" 15 8A 00\n"
" 15 9B 0F\n"
" 15 B3 C0\n"
" 15 B4 00\n"
" 15 B5 00\n"
" 15 B6 21\n"
" 15 B7 22\n"
" 15 B8 07\n"
" 15 B9 07\n"
" 15 Ba 22\n"
" 15 Bd 20\n"
" 15 Be 07\n"
" 15 Bf 07\n"
" 15 C1 6D\n"
" 15 C4 24\n"
" 15 E3 00\n"
" 15 EC 00\n"
" 15 FF 10\n"
" 15 BB 10\n"
" 15 35 00\n"
" 05 11 00\n"
" FF 78\n"
" 05 29 00\n"
" FF 78\n"
"</DSIInitSequence>"
"<DSITermSequence>"
" 05 28\n"
" 05 10\n"
"</DSITermSequence>"
"<TLMMGPIODefaultHigh>0x2E 0x3D</TLMMGPIODefaultHigh>"
"<Group id='Backlight Configuration'>"
" <BacklightType>3</BacklightType>"
" <DisplayResetInfo>0 10 1000 10000 0</DisplayResetInfo>"
"</Group>\n";


/******************************************************************
 *                   Sharp 5.5" 4k Panel                          *
 *                                                                *
 *                   nt35950 DDIC                                 *
 *                   2160x3840                                    *
 *                   Dual-DSI(DSI0 and DSI1)                      *
 *                   Video mode DSC                               *
 ******************************************************************/
const static int8 boe_amoled_wqhd_dsc_vid[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"<PanelName>BOE AMOLED</PanelName>"
"<PanelDescription>BOE Single DSI Video Mode AMOLED Panel with DSC (1440x2880 24bpp)</PanelDescription>"
"<Group id=\"Active Timing\">"
" <HorizontalActive>1440</HorizontalActive>"
" <HorizontalFrontPorch>10</HorizontalFrontPorch>"
" <HorizontalBackPorch>10</HorizontalBackPorch>"
" <HorizontalSyncPulse>12</HorizontalSyncPulse>"
" <HorizontalSyncSkew>0</HorizontalSyncSkew>"
" <HorizontalLeftBorder>0</HorizontalLeftBorder>"
" <HorizontalRightBorder>0</HorizontalRightBorder>"
" <VerticalActive>2880</VerticalActive>"
" <VerticalFrontPorch>10</VerticalFrontPorch>"
" <VerticalBackPorch>10</VerticalBackPorch>"
" <VerticalSyncPulse>1</VerticalSyncPulse>"
" <VerticalSyncSkew>0</VerticalSyncSkew>"
" <VerticalTopBorder>0</VerticalTopBorder>"
" <VerticalBottomBorder>0</VerticalBottomBorder>"
" <InvertDataPolarity>False</InvertDataPolarity>"
" <InvertVsyncPolairty>False</InvertVsyncPolairty>"
" <InvertHsyncPolarity>False</InvertHsyncPolarity>"
" <BorderColor>0x0</BorderColor>"
"</Group>"
"<Group id=\"Display Interface\">"
" <InterfaceType>8</InterfaceType>"
" <InterfaceColorFormat>3</InterfaceColorFormat>"
"</Group>"
"<Group id=\"DSI Interface\">"
" <DSIChannelId>1</DSIChannelId>"
" <DSIVirtualId>0</DSIVirtualId>"
" <DSIColorFormat>36</DSIColorFormat>"
" <DSITrafficMode>1</DSITrafficMode>"
" <DSILanes>4</DSILanes>"
  " <DSIHsaHseAfterVsVe>False</DSIHsaHseAfterVsVe>\n"
  " <DSILowPowerModeInHFP>False</DSILowPowerModeInHFP>\n"
  " <DSILowPowerModeInHBP>False</DSILowPowerModeInHBP>\n"
  " <DSILowPowerModeInHSA>False</DSILowPowerModeInHSA>\n"
  " <DSILowPowerModeInBLLPEOF>True</DSILowPowerModeInBLLPEOF>\n"
  " <DSILowPowerModeInBLLP>True</DSILowPowerModeInBLLP>\n"
" <DSIRefreshRate>0x3C0000</DSIRefreshRate>"
" <DSIDSCEnable>True</DSIDSCEnable>"
" <DSIDSCMajor>1</DSIDSCMajor>"
" <DSIDSCMinor>1</DSIDSCMinor>"
" <DSIDSCScr>0</DSIDSCScr>"
" <DSIDSCProfileID>7</DSIDSCProfileID>"
" <DSIDSCSliceWidth>720</DSIDSCSliceWidth>"
" <DSIDSCSliceHeight>720</DSIDSCSliceHeight>"
" <DSIControllerMapping>"
"  00"
" </DSIControllerMapping>"
"</Group>"
"<DSIInitSequence>"
" 07 01 00\n"
" 39 B0 A5 00\n"
" 39 B2 00 5D 04 80 49\n"
" 15 3D 10\n"
" 15 36 00\n"
" 15 55 0C\n"
" 39 F8 00 08 10 08 2D 00 00 2D\n"
" 39 51 00 00\n"
" FF 3C\n"
" 05 11 00\n"
" FF 50\n"
" 39 B0 34 04\n"
" 39 C1 00 00 00 46\n"
" 0A 11 00 00 89 30 80 0B 40 05 A0 02 D0 02 D0 02 D0 02 00 02 68 00 20 4E A8 00 0A 00 0C 00 23 00 1C 18 00 10 F0 03 0C 20 00 06 0B 0B 33 0E 1C 2A 38 46 54 62 69 70 77 79 7B 7D 7E 01 02 01 00 09 40 09 BE 19 FC 19 FA 19 F8 1A 38 1A 78 1A B6 2A F6 2B 34 2B 74 3B 74 6B F4 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00\n"
" 05 29 00\n"
" FF 78\n"
"</DSIInitSequence>"
"<DSITermSequence>"
" 05 28\n"
" 05 10\n"
"</DSITermSequence>"
"<Group id='Backlight Configuration'>"
" <BacklightType>3</BacklightType>"
" <BacklightBitWidth>10</BacklightBitWidth>"
" <DisplayResetInfo>0 10 1000 10000 0</DisplayResetInfo>"
"</Group>";


/*
* Dummy panel configuration, default fallback mode.
*
*/
const static int8 dummy_xmldata[] =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
"    <PanelName>VirtioDSI</PanelName>"
"    <PanelDescription>DSI Model (640x480 24bpp)</PanelDescription>"
"    <Group id=\"Active Timing\">"
"        <HorizontalActive units=\"Dot Clocks\">640</HorizontalActive>"
"        <HorizontalFrontPorch units=\"Dot Clocks\">13</HorizontalFrontPorch>"
"        <HorizontalBackPorch units=\"Dot Clocks\">14</HorizontalBackPorch>"
"        <HorizontalSyncPulse units=\"Dot Clocks\">15</HorizontalSyncPulse>"
"        <HorizontalSyncSkew units=\"Dot Clocks\">0</HorizontalSyncSkew>"
"        <HorizontalLeftBorder units=\"Dot Clocks\">0</HorizontalLeftBorder>"
"        <HorizontalRightBorder units=\"Dot Clocks\">0</HorizontalRightBorder>"
"        <VerticalActive units=\"Dot Clocks\">480</VerticalActive>"
"        <VerticalFrontPorch units=\"Lines\">11</VerticalFrontPorch>"
"        <VerticalBackPorch units=\"Lines\">12</VerticalBackPorch>"
"        <VerticalSyncPulse units=\"Lines\">13</VerticalSyncPulse>"
"        <VerticalSyncSkew units=\"Lines\">0</VerticalSyncSkew>"
"        <VerticalTopBorder units=\"Lines\">0</VerticalTopBorder>"
"        <VerticalBottomBorder units=\"Lines\">0</VerticalBottomBorder>"
"        <InvertDataPolarity>False</InvertDataPolarity>"
"        <InvertVsyncPolairty>False</InvertVsyncPolairty>"
"        <InvertHsyncPolarity>False</InvertHsyncPolarity>"
"        <BorderColor>0x0</BorderColor>"   
"    </Group>"
"    <Group id=\"Display Interface\">"
"        <InterfaceType units=\"QDI_DisplayConnectType\">8</InterfaceType>"
"        <InterfaceColorFormat units=\"QDI_PixelFormatType\">3</InterfaceColorFormat>"
"    </Group>"
"    <Group id=\"DSI Interface\">"
"        <DSIChannelId units=\"DSI_Channel_IDType\">1</DSIChannelId>"     
"        <DSIVirtualId units=\"DSI_Display_VCType\">0</DSIVirtualId>"     
"        <DSIColorFormat units=\"DSI_ColorFormatType\">36</DSIColorFormat>"     
"        <DSITrafficMode units=\"DSI_TrafficModeType\">0</DSITrafficMode>"
"        <DSILanes units=\"integer\">2</DSILanes>"
"        <DSIHsaHseAfterVsVe units=\"Bool\">False</DSIHsaHseAfterVsVe>"
"        <DSILowPowerModeInHFP units=\"Bool\">False</DSILowPowerModeInHFP>"
"        <DSILowPowerModeInHBP units=\"Bool\">False</DSILowPowerModeInHBP>"
"        <DSILowPowerModeInHSA units=\"Bool\">False</DSILowPowerModeInHSA>"
"        <DSILowPowerModeInBLLPEOF units=\"Bool\">False</DSILowPowerModeInBLLPEOF>"
"        <DSILowPowerModeInBLLP units=\"Bool\">False</DSILowPowerModeInBLLP>"
"        <DSIRefreshRate>0x3c0000</DSIRefreshRate>" 
"    </Group>"
"        <DisplayPrimaryFlags>0x2</DisplayPrimaryFlags>"
"    <DSIInitSequence>"
"    32 00 00\n"
"    </DSIInitSequence>";

/*===========================================================================
Function Definitions
===========================================================================*/

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: PlatformClientInit()
** 
** DESCRIPTION:
**        Initialize NPA client
**
*//* -------------------------------------------------------------------- */
static MDP_Status PlatformClientInit(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status    eStatus = MDP_STATUS_OK;

  return eStatus;
}



/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_CDP_PowerUp()
** 
** DESCRIPTION:
**        Panel power up sequence for CDP
**
*/ /* -------------------------------------------------------------------- */
static MDP_Status Panel_CDP_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status          eStatus        = MDP_STATUS_OK;
  DALGpioSignalType   uGPIOCfg       = 0;
  uint32              uResetGpio     = GET_CDP_DISP_RESET_GPIO(eDisplayId);
  uint32              uTeGpio        = GET_CDP_DISP_TE_GPIO(eDisplayId);

  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_LOW_VALUE);
  Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);

  if (MDP_STATUS_OK != (eStatus =  PlatformClientInit(eDisplayId, pPowerParams)))
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayLib: Failed to initialize handle for Primary display NPA node.\n");
  }
  else
  {
    DALGpioSignalType uGPIOCfg = 0;

    /* LDO1, LDO2 for DSI PHY/PLL are already turned on by system driver.*/

    /*Turn on LDO14 for V_LCD_VDDI_1P8 which is used by panel */
    if (PM_ERR_FLAG__SUCCESS != pm_ldo_volt_level(PMIC_A, PM_LDO_14, 1800000, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error configuring LDO to 1.8V\n");
    }

    if (PM_ERR_FLAG__SUCCESS != pm_ldo_volt_level(PMIC_C, PM_LDO_11, 3296000, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error configuring LDO to 3.3V\n");
    }
    if (PM_ERR_FLAG__SUCCESS != pm_ldo_volt_level(PMIC_A, PM_LDO_9, 1200000, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error configuring LDO to 1.8V\n");
    }
    
    if (PM_ERR_FLAG__SUCCESS != pm_ldo_volt_level(PMIC_A, PM_LDO_5, 880000, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error configuring LDO to 1.8V\n");
    }
    
    if (PM_ERR_FLAG__SUCCESS != pm_ldo_sw_enable(PMIC_A, PM_LDO_14, PM_ON, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error enabling LDO14\n");
    }

    if (PM_ERR_FLAG__SUCCESS != pm_ldo_sw_enable(PMIC_C, PM_LDO_11, PM_ON, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error enabling LDO11\n");
    }

    if (PM_ERR_FLAG__SUCCESS != pm_ldo_sw_enable(PMIC_A, PM_LDO_9, PM_ON, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error enabling LDO3\n");
    }
    
    if (PM_ERR_FLAG__SUCCESS != pm_ldo_sw_enable(PMIC_A, PM_LDO_5, PM_ON, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error enabling LDO5\n");
    }
    
    /* only support single dsi mode */
    uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(CDP_DISP_MODE_SEL, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_HIGH_VALUE);

    Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);

    MDP_OSAL_DELAYMS(10);   /* delay 10ms for panel to reset (from panel spec) */

    uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG(uTeGpio, 1, DAL_GPIO_INPUT, DAL_GPIO_NO_PULL, DAL_GPIO_LOW_VALUE);
    Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);
  }

  return eStatus;
}


/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_CDP_PowerDown()
** 
** DESCRIPTION:
**        Panel power down sequence for CDP
**
*/ /* -------------------------------------------------------------------- */
static MDP_Status Panel_CDP_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status          eStatus      = MDP_STATUS_OK;
  DALGpioSignalType   uGPIOCfg     = 0;  
  uint32              uResetGpio   = GET_CDP_DISP_RESET_GPIO(eDisplayId);

  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_LOW_VALUE);
  eStatus  = Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);

  return eStatus;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_CDP_Reset()
** 
** DESCRIPTION:
**        Panel reset sequence for CDP
**
*/ /* -------------------------------------------------------------------- */
MDP_Status Panel_CDP_Reset(MDP_Display_IDType eDisplayId)
{
  MDP_Status          eStatus     = MDP_STATUS_OK;
  DALGpioSignalType   uGPIOCfg    = 0;
  uint32              uResetGpio   = GET_CDP_DISP_RESET_GPIO(eDisplayId);

  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_LOW_VALUE);
  Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);
    
  MDP_OSAL_DELAYMS(10);

  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_HIGH_VALUE);
  Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);

  MDP_OSAL_DELAYMS(10);
  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_LOW_VALUE);
  Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);

  MDP_OSAL_DELAYMS(10);
    
  uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(uResetGpio, 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_16MA, DAL_GPIO_HIGH_VALUE);
  Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);
  MDP_OSAL_DELAYMS(10);
  return eStatus;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_CDP_PeripheralPower()
** 
** DESCRIPTION:
**        Secondary power sequence for other PMIC modules such as IBB/LAB
**
*/ /* -------------------------------------------------------------------- */
static MDP_Status Panel_CDP_PeripheralPower(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp)
{
  MDP_Status                    eStatus = MDP_STATUS_OK;
   
   if (MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_LCD == pPowerParams->ePMICSecondaryPower[eDisplayId])
   {
      if (TRUE == bPowerUp)
      {
         if (PM_ERR_FLAG__SUCCESS != pm_lcdb_set_output_volt(PMIC_C, 5500,-5500, TRUE))
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Lcdb 5.5V failed\n");
         }

         if (PM_ERR_FLAG__SUCCESS != pm_lcdb_config_enable_ctrl(PMIC_C, PM_LCDB_ENABLE_CTL_MODULE_EN, TRUE))
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Lcdb Enable failed\n");
         }

         // Wait for IBB/LAB to become ready
         Panel_IBBLAB_WaitForReady();

        /************************************************************************
         *  Enable brightness power source
         ************************************************************************/
         if (PM_ERR_FLAG__SUCCESS != pm_wled_enable_modulator(PMIC_C, PM_MODULATOR_TYPE_A,TRUE))
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled EnableModulatorA failed\n");
         }

         if (PM_ERR_FLAG__SUCCESS != pm_wled_set_led_duty_cycle(PMIC_C, PM_MODULATOR_TYPE_A,0x1ff))  /* duty cycle is 12 bits */
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled SetLedDutyCycle failed\n");
         }

         if (PM_ERR_FLAG__SUCCESS != pm_wled_modulator_src_sel(PMIC_C, PM_MODULATOR_TYPE_A, PM_MODULATOR_SRC_DRV_HIGH))
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled ModulatorSrcSelect failed\n");
         }

         if (PM_ERR_FLAG__SUCCESS != pm_wled_enable_module(PMIC_C, 0, TRUE))
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled EnableWled failed\n");
         }
   
         if (PM_ERR_FLAG__SUCCESS != pm_wled_enable_current_sink(PMIC_C, PM_WLED_LED1|PM_WLED_LED2|PM_WLED_LED3))
           {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled EnableCurrentSink failed\n");
         }
     }
     else
     {
       // ********** Brightness Power-down Sequence **********
       // Power down
           if (PM_ERR_FLAG__SUCCESS !=   pm_lcdb_config_enable_ctrl(PMIC_C, PM_LCDB_ENABLE_CTL_MODULE_EN, FALSE))
           {
             MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Error to disable LCDB\n");
           }

           if (PM_ERR_FLAG__SUCCESS != pm_wled_enable_current_sink(PMIC_C, PM_WLED_NONE))
           {
               MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled EnableCurrentSink failed\n");
           }
   
           if (PM_ERR_FLAG__SUCCESS != pm_wled_enable_module(PMIC_C, 0, FALSE))
           {
             MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled EnableWled failed\n");
           }

     }
   }
   else
   {
      /* do nothing for amoled panel */
   }

    return eStatus;
}


/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_CDP_BacklightLevel()
**
** DESCRIPTION:
**
*/ /* -------------------------------------------------------------------- */
static MDP_Status Panel_CDP_BacklightLevel(MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig)
{
  MDP_Status                    eStatus = MDP_STATUS_OK;

  if (MDP_PANEL_BACKLIGHTTYPE_PMIC == pBacklightConfig->eBacklightType)
  {
    // Configure the power grid based on the module type
    switch (pBacklightConfig->uBacklightCntrl.eBacklightCtrl)
    {
      case MDP_PMIC_BACKLIGHT_CONTROLTYPE_WLED:
      {

        uint32 uWLEDValue = (0xFFF * pBacklightConfig->uLevel) / 100; // Calculate duty cycle based on 12 bit mode

        if (PM_ERR_FLAG__SUCCESS != pm_wled_set_led_duty_cycle(PMIC_C, PM_MODULATOR_TYPE_A, uWLEDValue))  /* PM_WLED_ALL */
        {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: Wled pm_wled_set_led_duty_cycle failed\n");
        }
      }
        break;
      default:
        break;
    }
  }
  else if (MDP_PANEL_BACKLIGHTTYPE_DSI == pBacklightConfig->eBacklightType)
  {
     if (pBacklightConfig->uNumBits > 16)
     {
       MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Backlight dcs bit width is not available\n");
       eStatus = MDP_STATUS_BAD_PARAM;
     }
     else
     {
       PlatformPanelBacklightControl panelBacklightControl = {
         0x00,
         {0x51, 0x00, 0x00}, // Using standard MIPI DCS commands to control brightness
       };

       if (pBacklightConfig->uNumBits > 8)
       {
         // Calculate brightness
         panelBacklightControl.uCmdType   = 0x39; // Use dcs long write type, e.g. 10bits: first byte is bits 0:7, the second byte is bits 8:9.
         panelBacklightControl.command[1] = DISP_DIV_ROUND_UP(((1 << pBacklightConfig->uNumBits) - 1) * pBacklightConfig->uLevel, 100) &  0xFF;
         panelBacklightControl.command[2] = DISP_DIV_ROUND_UP(((1 << pBacklightConfig->uNumBits) - 1) * pBacklightConfig->uLevel, 100) >> 0x08;
       }
       else
       {
         // Default to calculate brightness based on 8 bit mode
         panelBacklightControl.uCmdType   = 0x15; // Use dcs short write type as only needs one byte.
         panelBacklightControl.command[1] = DISP_DIV_ROUND_UP(0xFF * pBacklightConfig->uLevel, 100) & 0xFF;
       }

       eStatus = DSIDriver_Write(eDisplayId,
                                 panelBacklightControl.uCmdType,
                                 panelBacklightControl.command,
                                 sizeof(panelBacklightControl.command));
       if (MDP_STATUS_OK != eStatus)
       {
         MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Backlight brightness DCS command send failed\n");
       }
    }
  }
  else
  {
    // Nothing to do for other configurations
  }

  return eStatus;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: Panel_IBBLAB_WaitForReady()
** 
** DESCRIPTION:
**  Polling loop to wait for IBB/LAB modules to be ready.
**  VDISN, VDISP will reach the proper voltage upon ready.
**/
static void Panel_IBBLAB_WaitForReady()
{

  boolean lcdbStatus;
  
  uint32                uCount;

  for (uCount = 0; uCount < PMIC_IBBLAB_READYTIME; uCount++)
  {
    if (PM_ERR_FLAG__SUCCESS == pm_lcdb_vreg_ok(PMIC_C, &lcdbStatus)) 
    {
      if (lcdbStatus)
      {
        break;
      }
      else if (PMIC_IBBLAB_READYTIME == (uCount + 1))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: LAB/IBB GetStatus(LabVregOk) failed after %dms\n", PMIC_IBBLAB_READYTIME);
      }

      // Wait 1ms between checks
      MDP_OSAL_DELAYMS(1);
    }
    else
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxeBoot: IBB/LAB GetStatus() Failed\n");
      break;
    }
  }
}

MDP_Status MDPPlatformConfigure(MDP_Display_IDType eDisplayId, MDPPlatformConfigType eConfig, MDPPlatformParams *pPlatformParams)
{
  MDP_Status  eStatus  = MDP_STATUS_OK;

  /* Static information, initial once during the first call */
  static MDPPlatformInfo        sPlatformInfo;
  static Panel_PowerCtrlParams  sPanelPowerCtrl;
  static uint32                 uHardwareVersionMinor = 0;

  switch (eConfig)
  {
  case MDPPLATFORM_CONFIG_INIT:
    MDP_OSAL_MEMZERO(&sPlatformInfo,    sizeof(MDPPlatformInfo));
    MDP_OSAL_MEMZERO(&sPanelPowerCtrl,  sizeof(Panel_PowerCtrlParams));

    // Read the platform ID once
    if (MDP_STATUS_OK == ReadPlatformIDAndChipID(&sPlatformInfo.sEFIPlatformType, &sPlatformInfo.sEFIChipSetId, &sPlatformInfo.sEFIChipSetFamily))
    {
      UINT32 uPanelOverride = 0;

      // Read the display panel ID override
      if ((MDP_STATUS_OK  == MDP_Display_GetVariable_Integer (PANEL_OVERRIDE_STRINGNAME, &uPanelOverride)) &&
          (uPanelOverride  > 0))
      {
        sPlatformInfo.uPanelIdOverride = (uint32) uPanelOverride;
      }

      // Parse sub-revision specific info to determine the platform type
      uHardwareVersionMinor = sPlatformInfo.sEFIPlatformType.version & 0xFF;
    }

    /* Enable VDDMM so that MMCX Arc can be configured */
    if (PM_ERR_FLAG__SUCCESS != pm_smps_volt_level(PMIC_C, PM_SMPS_4, 752*1000, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error set VDDMM level \n");
    }
    if (PM_ERR_FLAG__SUCCESS != pm_smps_sw_enable(PMIC_C, PM_SMPS_4, PM_ON, TRUE))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error enable VDDMM\n");
    }

    // Store the platform specific ID
    sPlatformInfo.uPlatformID = pPlatformParams->sPlatformInfo.uPlatformID;

    switch (sPlatformInfo.sEFIPlatformType.platform)
    {
    case EFI_PLATFORMINFO_TYPE_CDP:
      // Default to enable primary display
      MDP_SUPPORTED_DISPLAY(MDP_DISPLAY_PRIMARY) = TRUE;

      if (MDP_BOOT_PLATFORMID_DUAL_PANEL == sPlatformInfo.uPlatformID)
      {
        // On the dual panel platform reference multiple displays are supported.
        MDP_SUPPORTED_DISPLAY(MDP_DISPLAY_SECONDARY) = TRUE;
      }
      break;

    default:
      // Enable primary display
      MDP_SUPPORTED_DISPLAY(MDP_DISPLAY_PRIMARY) = TRUE;
      break;
    }
    break;
  
  case MDPPLATFORM_CONFIG_SW_RENDERER:

    if ((EFI_PLATFORMINFO_TYPE_UNKNOWN == sPlatformInfo.sEFIPlatformType.platform) ||
        (EFI_PLATFORMINFO_TYPE_VIRTIO  == sPlatformInfo.sEFIPlatformType.platform) ||
        (EFI_PLATFORMINFO_TYPE_RUMI    == sPlatformInfo.sEFIPlatformType.platform) ||
        (TRUE == PcdGetBool(PcdDisplayForceSwRenderer)))
    {
      // Treat unknown platforms as a SW model only
      pPlatformParams->sPlatformInfo.bSWRender = TRUE;
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxeBoot: SW renderer only\n");
    }
    else
    {
      pPlatformParams->sPlatformInfo.bSWRender = FALSE;
    }
    break;
  case MDPPLATFORM_CONFIG_GETPANELCONFIG:
    {
      pPlatformParams->sPlatformPanel.uDefaultVendor   = 0;
      pPlatformParams->sPlatformPanel.uDefaultRevision = 0;
      pPlatformParams->sPlatformPanel.uPanelId         = 0;

      // Retrieve panel configuration (could be dependent on the interface)
      switch (eDisplayId)
      {
      case MDP_DISPLAY_PRIMARY:
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
        case EFI_PLATFORMINFO_TYPE_MTP:
        case EFI_PLATFORMINFO_TYPE_QRD:
          if (MDP_BOOT_PLATFORMID_DUAL_PANEL == sPlatformInfo.uPlatformID)
          {
            // Primary sharp 1080p command mode panel
            pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8 *)Primary_Sharp_1080p_cmd_xmldata;
            pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(Primary_Sharp_1080p_cmd_xmldata);
            pPlatformParams->sPlatformPanel.eSelectedPanel  = MDPPLATFORM_PRI_PANEL_SHARP_1080P_CMD;
          }
          else
          {
            // default to boe amoled wqhd ds cmd Mode
            pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8 *)boe_amoled_wqhd_dsc_vid;
            pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(boe_amoled_wqhd_dsc_vid);
            pPlatformParams->sPlatformPanel.eSelectedPanel  = MDPPLATFORM_PANEL_BOE_AMOLED_WQHD_DSC_CMD;
            pPlatformParams->sPlatformPanel.uPanelId        = 0x00008056;
            sPlatformInfo.uPrimaryPanelId                   = 0x00008056;
          }
          break;

        default:
          pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8*)dummy_xmldata;
          pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(dummy_xmldata);
          break;
        }
        break;

      case MDP_DISPLAY_SECONDARY:
        switch (sPlatformInfo.sEFIPlatformType.platform)
        {
        case EFI_PLATFORMINFO_TYPE_CDP:
          // Secondary truly 1080p command mode panel
          pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8 *)Secondary_Truly_1080p_cmd_xmldata;
          pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(Secondary_Truly_1080p_cmd_xmldata);
          pPlatformParams->sPlatformPanel.eSelectedPanel  = MDPPLATFORM_SEC_PANEL_TRULY_1080P_CMD;
          break;

        default:
          pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8*)dummy_xmldata;
          pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(dummy_xmldata);
          break;
        }
        break;

      case MDP_DISPLAY_EXTERNAL:
          pPlatformParams->sPlatformPanel.pPanelXMLConfig = (int8*)dummy_xmldata;
          pPlatformParams->sPlatformPanel.uConfigSize     = sizeof(dummy_xmldata);
          break;
      default:
        break;
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
          sPanelPowerCtrl.ePMICSecondaryPower[eDisplayId] = MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED;  // OLED Power Configuration (IBB/LAB)

          /* Check for common power or panel specific power,
           * Common Power : pPlatformParams is NULL or uFlags is 0x0,
           * Panel Power  : uFlags is set to panel specific power flag.
           */
          if ((NULL                          != pPlatformParams) &&
              (POWERCONFIG_FLAGS_PANEL_POWER  & pPlatformParams->sPowerConfig.uFlags))
          {
            switch (sPlatformInfo.uPrimaryPanelId)
            {
            default:
              // OEM to populate panel specific power up.
              break;
            }
          }
          else
          {
            /*
             * Ramdump mode Primary Power Sequence:
             * MDPPLATFORM_CONFIG_POWERDOWN is not be called at both enter and exit ramdump mode
             * Therefore panel power down is called first before power up panel to obey panel
             * power up sequence
             */
            if (MDP_STATUS_OK != (eStatus = Panel_CDP_PowerDown(eDisplayId, &sPanelPowerCtrl)))
            {
              MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Ramdump: Panel_PowerDown: Primary Power Down Sequence Failed (%d)\n", eStatus);
            }
            else if (MDP_STATUS_OK != (eStatus = Panel_CDP_PeripheralPower(eDisplayId, &sPanelPowerCtrl, FALSE)))  // Secondary Power Sequence
            {
              MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Ramdump: Panel_PowerDown: Secondary Power Down Sequence Failed (%d)\n", eStatus);
            }

            MDP_OSAL_DELAYMS(10);   /* delay 10ms to allow power grid to settle */

            // Primary Power Sequence
            if (MDP_STATUS_OK != (eStatus = Panel_CDP_PowerUp(eDisplayId, &sPanelPowerCtrl)))
            {
              MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayLib: Primary Power Up Sequence Failed (%d)\n", eStatus);
            }
            else if (MDP_STATUS_OK != (eStatus = Panel_CDP_PeripheralPower(eDisplayId, &sPanelPowerCtrl, TRUE)))  // Secondary Power Sequence
            {
              MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayLib: Secondary Power Up Sequence Failed (%d)\n", eStatus);
            }
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
        case EFI_PLATFORMINFO_TYPE_QRD:
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

  case MDPPLATFORM_CONFIG_POWERDOWN:
    {
       MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxeBoot: Power Down not supported in this mode\n");
    }
    break;
  case MDPPLATFORM_CONFIG_SETBACKLIGHT:
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
          eStatus = Panel_CDP_BacklightLevel(eDisplayId, &pPlatformParams->sBacklightConfig);
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
    break;
  case MDPPLATFORM_CONFIG_GETPANELID:
    {
    }
    break;
  case MDPPLATFORM_CONFIG_GETPLATFORMINFO:
    {
      //
      // Return platform information
      //
      MDP_OSAL_MEMCPY(&pPlatformParams->sPlatformInfo, &sPlatformInfo, sizeof(MDPPlatformInfo));
    }
    break;
  case MDPPLATFORM_CONFIG_RESETPANEL:
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
          eStatus = Panel_CDP_Reset(eDisplayId);
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
    break;

  case MDPPLATFORM_CONFIG_SETGPIOSTATE:
    {
      eStatus = SetDefaultGPIOState(&pPlatformParams->sGPIOState);
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

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: ReadPlatformIDAndChipID()
** 
** DESCRIPTION:
**
*/ /* -------------------------------------------------------------------- */
static MDP_Status ReadPlatformIDAndChipID(EFI_PLATFORMINFO_PLATFORM_INFO_TYPE *pPlatformInfo, EFIChipInfoIdType *pChipSetId, EFIChipInfoFamilyType *pChipSetFamily)
{
  DalPlatformInfoPlatformInfoType      dalPlatformInfo;
  DALResult                            eDalStatus = DAL_SUCCESS;
  MDP_Status                           eStatus    = MDP_STATUS_OK;

  MDP_OSAL_MEMZERO(&dalPlatformInfo,	sizeof(DalPlatformInfoPlatformInfoType));

  eDalStatus = boot_DalPlatformInfo_PlatformInfo(&dalPlatformInfo);
  if (eDalStatus != DAL_SUCCESS)
  {
     MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Ramdump:Display:ReadPlatformIDAndChipId: Failed\n");

     eStatus    = MDP_STATUS_FAILED;
  }
  else
  {
    pPlatformInfo->platform = (EFI_PLATFORMINFO_PLATFORM_TYPE)dalPlatformInfo.platform;
    pPlatformInfo->version  = dalPlatformInfo.version;
    pPlatformInfo->subtype  = dalPlatformInfo.subtype;
    pPlatformInfo->fusion   = dalPlatformInfo.fusion;

    eDalStatus = boot_DalPlatformInfo_ChipId(pChipSetId);
    eDalStatus = boot_DalPlatformInfo_ChipFamily(pChipSetFamily);
  }


  return eStatus;
}

/****************************************************************************
*
** FUNCTION: SetDefaultGPIOState()
*/
/*!
* \brief
*   The \b SetDefaultGPIOState function toggles a list of GPIO's based on the requested configuration
**
* \retval MDP_Status
*
****************************************************************************/
MDP_Status SetDefaultGPIOState(GpioStateType *pGPIOList)
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
      uint32              uCount;

      // Loop the list to configure all GPIOs.
      for (uCount = 0;uCount < pGPIOList->uListSize;uCount++)
      {
        // Only try to program GPIOs that are within range, TLMM Macro (EFI_GPIO_CFG) supports up to 0x3FF
        if (pGPIOList->pGPIOList[uCount] < 0x3FF)
        {

          DALGpioSignalType   uGPIOCfg = 0;
          uint32              uValue  = (pGPIOList->uState > 0) ? DAL_GPIO_HIGH_VALUE : DAL_GPIO_LOW_VALUE;

          uGPIOCfg = (DALGpioSignalType)DAL_GPIO_CFG_OUT(pGPIOList->pGPIOList[uCount], 0, DAL_GPIO_OUTPUT, DAL_GPIO_NO_PULL, DAL_GPIO_2MA, uValue);
          Tlmm_ConfigGpioGroup(DAL_TLMM_GPIO_ENABLE, &uGPIOCfg, 1);
        }
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

#ifdef __cplusplus
}
#endif
