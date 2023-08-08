/*! @file ChargerExProtocol.c

*  CHARGER EXTENDED MODULE RELATED DECLARATION
*  This file contains functions and variable declarations to support 
*  the Charger Extended module.
*
*  Copyright (c) 2016-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
*  Qualcomm Technologies Inc Proprietary and Confidential.
*/

/*===========================================================================

EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     --------------------------------------------------------------------------
07/31/19   dc      Updated APIs and return values
10/04/16   sm      New File
===========================================================================*/

/*===========================================================================

INCLUDE FILES FOR MODULE

===========================================================================*/

/**
  ChargerEx NULL Protocol interfaces
 */
#include <Include/Protocol/EFIChargerEx.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_CHARGER_EX_PROTOCOL ChargerExProtocolImplementation;

/*===========================================================================
EXTERNAL FUNCTION DECLARATIONS
===========================================================================*/
/**
EFI_ChargerExInit()

@brief
Initializes charger Extended module
*/
EFI_STATUS ChargerExInitialize( IN EFI_HANDLE         ImageHandle,
                                IN EFI_SYSTEM_TABLE   *SystemTable )
{
  EFI_STATUS Status = EFI_SUCCESS;
  
  Status  = gBS->InstallMultipleProtocolInterfaces(
                 &ImageHandle,      
                 &gChargerExProtocolGuid,
                 &ChargerExProtocolImplementation,
                 NULL
                 );

  return Status;
}

/**
EFI_ChargerExGetChargerPresence()

@brief
 Returns charger presence status
 */
EFI_STATUS
EFIAPI
EFI_ChargerExGetChargerPresence
(
  OUT BOOLEAN  *pChargerPresent
)
{
  if(NULL == pChargerPresent)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pChargerPresent = TRUE;
  return EFI_SUCCESS;
}


/**
EFI_ChargerExGetBatteryPresence ()

@brief
Get battery presence status SCHG
*/
EFI_STATUS
EFIAPI
EFI_ChargerExGetBatteryPresence
(
  OUT BOOLEAN  *pBatteryPresent
)
{
  if(NULL == pBatteryPresent)
  {
    return EFI_INVALID_PARAMETER;
  }
  *pBatteryPresent = TRUE;
  return EFI_SUCCESS;
}

/**
EFI_ChargerExGetBatteryVoltage ()

@brief
Returns battery voltage
*/
EFI_STATUS
EFIAPI
EFI_ChargerExGetBatteryVoltage
(
  OUT UINT32  *pBatteryVoltage
)
{
  if(NULL == pBatteryVoltage)
  {
    return EFI_INVALID_PARAMETER;
  }
  *pBatteryVoltage = 3700;
  return EFI_SUCCESS;
}

/**
EFI_ChargerExIsOffModeCharging ()

@brief
Returns if device needs to go for off mode charging
*/
EFI_STATUS
EFIAPI
EFI_ChargerExIsOffModeCharging
(
  OUT BOOLEAN *bOffModeCharging
)
{
  if(NULL == bOffModeCharging)
  {
    return EFI_INVALID_PARAMETER;
  }

  *bOffModeCharging = FALSE;
  return EFI_SUCCESS;
}

/**
EFI_ChargerExIsPowerOk ()

@brief
Returns if battery voltage is good to process with SW flash
*/
EFI_STATUS
EFIAPI
EFI_ChargerExIsPowerOk
(
  IN  EFI_CHARGER_EX_POWER_TYPE PowerType,
  OUT VOID                      *pPowerTypeInfo
)
{
  EFI_CHARGER_EX_FLASH_INFO *pFlashInfo = NULL;
  if(NULL == pPowerTypeInfo)
  {
    return EFI_INVALID_PARAMETER;
  }

  pFlashInfo = (EFI_CHARGER_EX_FLASH_INFO *)pPowerTypeInfo;
  pFlashInfo->BattCurrVoltage = 3700;
  pFlashInfo->bCanFlash = TRUE;

  return EFI_SUCCESS;
}


/**
Charger External UEFI Protocol implementation
*/
EFI_CHARGER_EX_PROTOCOL ChargerExProtocolImplementation = 
{
    CHARGER_EX_REVISION,
    EFI_ChargerExGetChargerPresence,
    EFI_ChargerExGetBatteryPresence,
    EFI_ChargerExGetBatteryVoltage,
    EFI_ChargerExIsOffModeCharging,
    EFI_ChargerExIsPowerOk,
};

