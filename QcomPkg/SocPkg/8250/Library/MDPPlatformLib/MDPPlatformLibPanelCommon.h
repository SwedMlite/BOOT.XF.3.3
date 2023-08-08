/*=============================================================================

  File: MDPPlatformLibPanelCommon.h

  MDP platform specific types

  Copyright (c) 2018 - 2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifndef __MDP_PLATFORM_LIB_PANEL_COMMON__H__
#define __MDP_PLATFORM_LIB_PANEL_COMMON__H__

#include "MDPTypes.h"
#include "MDPPlatformLib.h"
#include "npa.h"
/* -----------------------------------------------------------------------
** Defines
** ----------------------------------------------------------------------- */

#define DP_PLUG_INVERTED_POLARITY         FALSE   // set to TRUE if USB type-c cable is plugged in reverse

#define PCD_PANEL_TYPE_OEM                1

#define DSI_READ_ADDRESS_SIZE             2
#define DSI_READ_READBACK_SIZE            8
#define DSI_WRITE_BACKLIGHT_SIZE          3

#define PLATFORM_PANEL_ID_MAX_COMMANDS    3       // maximum panel ID read commands

#define PANEL_LIST_MAX_COUNT              16      // maximum number of panels supported

/* PMIC Device Indices
 */
#define PMIC_PMI_DEV_INDEX                2       // PMIC interface device (IBB/LAB, GPIO,  WLED)

#define PMIC_IBBLAB_READYTIME             25      // Maximum of milliseconds to wait for IBB/LAB to stabilize (Can be up to 8.8ms +/-16%)

/* SM8250 Main Panel default platform specific defines
 */
#define Default_DISP_LCD_REG_EN           61       //GPIO for LCD internal boost power
#define Default_DISP_LCD_BKLT_EN          60       //GPIO for backlight enable

/* Helper macro for supported panels table entry PanelDTInfoType
 */
#define PANEL_CREATE_ENTRY(_name_,_id_,_dtlable_,_interface_,_cfg_,_timing_,_pll_, _top0_, _top1_, _top2_)     \
                                          {(_name_),                            \
                                           (_id_),                              \
                                           (_dtlable_),                         \
                                           (_interface_),                       \
                                           (_cfg_),                             \
                                           (_timing_),                          \
                                           (_pll_),                             \
                                           {(_top0_), (_top1_), (_top2_)}}

#define PANEL_LIST_LENGTH(_LIST_)         (sizeof(_LIST_)/sizeof((_LIST_)[0]))

/* Macro to do round up of (x / y) to nearest integer
 */
#define DISP_DIV_ROUND_UP(x, y) (((x) + (y/2)) / (y))

/* Panel command ID list for dynamic panel detection
 */
typedef struct {
  uint8      address[DSI_READ_ADDRESS_SIZE];                                          // DCS command for panel ID
  uint8      expectedReadback[DSI_READ_READBACK_SIZE];                                // expected readback
} PlatformPanelIDCommandInfo;

/* Dynamic panel ID detection entry
 */
typedef struct {
  uint8                         uCmdType;                                             // data type for panel ID DSI read
  uint32                        uTotalRetry;                                          // number of retry if DSI read fails
  PlatformPanelIDCommandInfo    panelIdCommands[PLATFORM_PANEL_ID_MAX_COMMANDS];      // commands for panel ID and expected readback
  uint32                        uLaneRemapOrder;                                      // Lane remap order
  int8                         *psPanelCfg;                                           // pointer to the panel configuration
  uint32                        uPanelCfgSize;                                        // size of panel configuration data
  MDPPlatformPanelType          eSelectedPanel;                                       // index of the selected panel
  uint32                        uFlags;                                               // flags to set clock config for now, can set other config in future
} PlatformDSIDetectParams;

/* Panel backlight DCS command
 */
typedef struct {
  uint8      uCmdType;                                                                // DCS command type for backlight control
  uint8      command[DSI_WRITE_BACKLIGHT_SIZE];                                       // DCS command for backlight control
} PlatformPanelBacklightControl;

/* Power configuration
 */
typedef struct
{
  npa_client_handle             sNPAClient[MDP_DISPLAY_MAX];                          // NPA client handles for power control of panels.
  npa_client_handle             sTouchNPAClient;                          			  // NPA client handles for power control of Touch.
  MDP_PmicModuleControlType     ePMICSecondaryPower[MDP_DISPLAY_MAX];                 // Configuration for PMIC based secondary power source
  MDPPlatformLABIBBModeType     eOLEDPowerMode;                                       // Swire or spmi mode
  uint32                        uResetGpio;
  bool32                        bBacklightEnabled;
} Panel_PowerCtrlParams;

/* NPA Client info
 */
typedef struct
{
  MDP_Display_IDType            eMapDisplayId;   /* The re-mapped display id for NPA client */
  char*                         cResourceName;   /* The NPA resource name */
  char*                         cClientName;     /* The NPA client name */
} NPAClientName;

/* Panel support map type
 */
typedef struct
{
  MDPPlatformPanelType          ePanel;          /* Panel ID */
  int8                         *pPanelXMLConfig; /* Matching XML configuration */
  uint32                        uConfigSize;     /* Size of XML configuration */
  uint32                        uOverrideFlags;  /* Panel config flags from DisplayOverideFlagType */
} PanelMappingType;

/* Display TE gpio type
 */
typedef enum {
  MDP_TE_GPIO_66 = 0x0,
  MDP_TE_GPIO_67,
  MDP_TE_GPIO_68,
  MDP_TE_GPIO_122,
  MDP_TE_GPIO_124,
  MDP_TE_GPIO_MAX
} MDPTeGpioType;

/* Display TE gpio function type
 */
typedef struct
{
  uint32 uGpioNum;
  uint32 uGpioFunc;
} MDPPlatformTeGpioFunctionType;

/* Display panel gpio type
 */
typedef struct
{
  uint32                uDispResetGpio;  /* Display reset gpio */
  MDPTeGpioType         eDispTeGpio;     /* Display te gpio */
  uint32                uDispModeGpio;   /* Display mode gpio */
} MDPPlatformPanelGpioType;

/* Panel power / brightness control function type
 */
typedef struct
{
  /* The default panel selected when setting up platform panel configuration.
   */
  MDPPlatformPanelType      ePanelSelected; 

  /* The display gpio used by the panel selected.
   */
  MDPPlatformPanelGpioType *pMDPPlatformPanelGpio;

  /* The name of the configuration xml file for the panel selected.
   */
  CHAR8                    *pPanelXml;

  /* Panel power up function 
   * – Enable all rails, gpios necessary to start driving the panel.
   */
  MDP_Status (*pPanel_PowerUp)            (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);

  /* Panel power down function
   * – Disable all rails, gpios, and backlight to put the peripheral in to the lowest power state.
   */
  MDP_Status (*pPanel_PowerDown)          (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
  
  /* Panel reset
   * – Toggling the panels reset pin to reset the peripheral back to a idle state.
   */
  MDP_Status (*pPanel_Reset)              (MDPPlatformPanelResetInfo *pResetInfo);

  /* Panel peripheral function (Optional)
   * – Secondary power up to enable any auxiliary power supplies like IBB/LAB bias voltages.
   */
  MDP_Status (*pPanel_Peripheral_Power)   (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp);

  /* Panel brightness enable (Optional)
   * – Configuration of the components required to drive the brightness,
   *   but should leave output level as 0% at exit of this function.
   */
  MDP_Status (*pPanel_Brightness_Enable)  (MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);

  /* Panel brightness level (Optional)
   * – Configure the brightness level of the panel.
   */
  MDP_Status (*pPanel_Brightness_Level)   (MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig);
} MDPPlatformPanelFunctionTable;

/* The platform client init common function
 */
MDP_Status PlatformClientInit(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);

MDP_Status Panel_Power_LCD_REG_Required(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);

/* Default panel gpio table */
extern MDPPlatformPanelGpioType sDefaultMDPPanelGpio;

/* MDP supported panel functions for each display id */
extern MDPPlatformPanelFunctionTable gMDPSupportPanelFunctions[];

/* Helper to return the display panel function table */
#define MDP_GET_PANELFUNC(_id_)  (&gMDPSupportPanelFunctions[((_id_)<MDP_DISPLAY_MAX)?(_id_):0])

#endif // __MDP_PLATFORM_LIB_PANEL_COMMON__H__
