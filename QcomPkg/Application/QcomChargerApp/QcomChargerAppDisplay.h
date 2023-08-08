/** @file QcomChargerAppDisplay.c

  Helper functions for displaying images on screen

  Copyright (c) 2019, Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================

                        EDIT HISTORY


when        who     what, where, why
--------    ---     -----------------------------------------------------------
03/14/19    pbitra  Initial revision

=============================================================================*/

#ifndef __QCOMCHARGERAPPDISPLAY_H__
#define __QCOMCHARGERAPPDISPLAY_H__


#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/QcomLib.h>
#include <Library/BMPLib.h>
#include "Library/SerialPortShLib.h"
#include <Library/QcomTargetLib.h>
#include <Library/FuseControlLib.h>
#include <api/pmic/pm/pm_uefi.h>

/**
  Protocol Dependencies
*/
#include <Protocol/EFIQcomCharger.h>
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFIPmicFg.h>
#include <Protocol/EFIPmicVersion.h>
#include <Protocol/EFIPmicPwrOn.h>
#include <Protocol/EFIVariableServices.h>
#include <Protocol/EFITsens.h>
#include <Protocol/EFIPmicRTC.h>

#include <Protocol/EFIDisplayPwr.h>
#include <Protocol/EFIDisplayPwrCtrl.h>
#include <Protocol/EFIClock.h>

#include <Protocol/GraphicsOutput.h>

#include <Library/UefiLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/ParserLib.h>
#include <Library/BaseMemoryLib.h>
#include <Guid/FileSystemInfo.h>
#include <Guid/FileInfo.h>

#include "DDIPlatformInfo.h"
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/EFIDisplayUtils.h>


/*
This file will implement the functions to setup timer and implment the timer callback,
also it implement functions to register for key and LPM events and callback functions for key events and LPM events.
It also implement functions to turn display on/off, and render charging/battery images.
*/

#define CHARGER_BATTERY_SYMBOL_NOBATTERY            "battery_symbol_NoBattery.bmp"
#define CHARGER_BATTERY_SYMBOL_NOCHARGER            "battery_symbol_Nocharger.bmp"
#define CHARGER_BATTERY_SYMBOL_ABOVE_THRESHOLD      "battery_symbol_Soc10.bmp"
#define CHARGER_BATTERY_SYMBOL_LOWBATTERYCHARGING   "battery_symbol_LowBatteryCharging.bmp"
#define CHARGER_BATTERY_SYMBOL_LOWBATTERY           "battery_symbol_LowBattery.bmp"
#define CHARGER_TSENS_THERMAL_SYMBOL                "tsens_thermal_symbol.bmp"
#define CHARGER_TSENS_CRITICAL_SYMBOL               "tsens_thermal_err_symbol.bmp"
#define CHARGER_BATTERY_SYMBOL_DEBUG_BOARD_BOOT     "battery_symbol_DebugBoot.bmp"
#define CHARGER_BATTERY_SYMBOL_DEBUG_BOARD_STAY     "battery_symbol_DebugStay.bmp"


#define ANIM_TIMER_DURATION           5000000 /*500 milli sec*/
#define SEVEN_SEC_WAIT                70000000 /*tick is 100ns; 100 * 70000000 = 7sec*/
#define SEVEN_SEC                     7
#define ENTER_LPM                     TRUE
#define EXIT_LPM                      FALSE

typedef enum _CHGAPP_DISP_ANIM_IMG{
  CHGAPP_DISP_ANIM_IMG_LOW_BATTERY,
  CHGAPP_DISP_ANIM_IMG_LOW_BATT_CHARGING,
  CHGAPP_DISP_ANIM_IMG_NUM_MAX = 0x7fffffff
}CHGAPP_DISP_ANIM_IMG_NUM;


/******************************************************************************
            LOCAL FUNCTIONS
******************************************************************************/

EFI_STATUS QcomChargerAppDisplay_DispBattSymbol(EFI_QCOM_CHARGER_DISP_IMAGE_TYPE DispImage, BOOLEAN ClearScreen);


#endif  /* __QCOMCHARGERAPPDISPLAY_H__ */

