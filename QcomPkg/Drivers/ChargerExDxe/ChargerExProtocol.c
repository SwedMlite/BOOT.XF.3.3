/*! @file ChargerExProtocol.c

*  CHARGER EXTENDED MODULE RELATED DECLARATION
*  This file contains functions and variable declarations to support 
*  the Charger Extended module.
*
*  Copyright (c) 2017 -2019 Qualcomm Technologies, Inc.  All Rights Reserved.
*  Qualcomm Technologies Inc Proprietary and Confidential.
*/

/*===========================================================================

EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     --------------------------------------------------------------------------
05/27/19   sg      Boot to HLOS directly if POFF is due to Pmic FAULT
01/09/19   vr      Change Non-Error log level from Warning to Info
01/09/19   vr      Updated IsOffModeCharging API for mtp to not return offmodecharging true when mtp does not support charging
09/05/18   cs      Updated for presil RUmi
06/18/18   sb      Updated IsOffModeCharging API for CLS
06/05/18   sb      added cable pon detection for off-mode charging
03/15/18   ra      Add missing field for IsPowerOk
02/09/18   ra      Hardcoding values for bring up
03/03/16   va      Adding offmode, flash APIs to contained for ABL, making open source and local header copies
12/16/16   sm      Added changes to return EFI_UNSUPPORTED Status for CDP and RUMI Platforms
11/09/16   cs      modified charger present API also to detect DCIn. 
09/09/16   sm      Added Status success check after locating protocol. 
05/31/16   sm      New File
===========================================================================*/

/*===========================================================================

INCLUDE FILES FOR MODULE

===========================================================================*/

#include <Library/UefiLib.h>
/**
  PMIC Lib interfaces
 */
#include <Include/Protocol/EFIQcomCharger.h>
#include <Include/Protocol/EFIPmicUsb.h>
#include <Include/Protocol/EFIChargerEx.h>
#include <Include/Protocol/EFIPmicPwrOn.h>

#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/EFIPlatformInfo.h>
#include <Library/QcomLib.h>

/*-------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * ----------------------------------------------------------------------*/
extern EFI_GUID gQcomPmicUsbProtocolGuid;
EFI_CHARGER_EX_PROTOCOL ChargerExProtocolImplementation;

STATIC EFI_QCOM_CHARGER_PROTOCOL    *pQcomChargerProtocol = NULL;
STATIC EFI_QCOM_PMIC_PWRON_PROTOCOL *pPmicPwRonProtocol   = NULL;

/*-------------------------------------------------------------------------
 * Type Declarations
 * ----------------------------------------------------------------------*/

#define PM_DEVICE_0 0 /* PMIC index */
#define PON_OFF_REASON_FAULT_SEQ_MASK 0x40

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
  
  Status = gBS->InstallMultipleProtocolInterfaces(
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
  EFI_STATUS                           Status = EFI_SUCCESS;
  STATIC EFI_QCOM_PMIC_USB_PROTOCOL   *PmicUsbProtocol   = NULL;
  BOOLEAN                              DcInValid = FALSE;
  EFI_PLATFORMINFO_PLATFORM_TYPE       PlatformType;

  if (!pChargerPresent)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_WARN, "ChargerExProtocol:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  if((EFI_PLATFORMINFO_TYPE_CDP == PlatformType) || (EFI_PLATFORMINFO_TYPE_RUMI == PlatformType) 
    || (EFI_PLATFORMINFO_TYPE_CLS == PlatformType))
  {
    DEBUG(( EFI_D_WARN, "ChargerExProtocol:: %a CDP/RUMI/CLS (%d) Platform detected. No Battery information available. \r\n", __FUNCTION__, PlatformType));
    return EFI_UNSUPPORTED;
  }

  if (!PmicUsbProtocol)
  {
    Status = gBS->LocateProtocol( &gQcomPmicUsbProtocolGuid,
                                  NULL,
                                 (VOID **)&PmicUsbProtocol );

    if((EFI_SUCCESS != Status) || (NULL == PmicUsbProtocol))
    {
      return EFI_DEVICE_ERROR;
    }
  }

  Status = PmicUsbProtocol->GetChargerPresence(pChargerPresent);

  if (EFI_SUCCESS != Status)
  {
    return Status;
  }

  if (!pQcomChargerProtocol)
  {
    Status = gBS->LocateProtocol(&gQcomChargerProtocolGuid, NULL, (VOID **)&pQcomChargerProtocol);

    if ((EFI_SUCCESS != Status) || (NULL == pQcomChargerProtocol))
    {
      return EFI_DEVICE_ERROR;
    }
  }

  Status = pQcomChargerProtocol->IsDcInValid(&DcInValid);

  if (EFI_SUCCESS == Status)
  {
    (*pChargerPresent) |= DcInValid;
  } 

  return Status;
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
  EFI_STATUS                      Status = EFI_SUCCESS;

  EFI_PLATFORMINFO_PLATFORM_TYPE  PlatformType;
  
  if (!pBatteryPresent)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_WARN, "ChargerExProtocol:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  if((EFI_PLATFORMINFO_TYPE_CDP == PlatformType) || (EFI_PLATFORMINFO_TYPE_RUMI == PlatformType) 
    || (EFI_PLATFORMINFO_TYPE_CLS == PlatformType))
  {
    DEBUG(( EFI_D_WARN, "ChargerExProtocol:: %a CDP/RUMI/CLS (%d) Platform detected. No Battery information available. \r\n", __FUNCTION__, PlatformType));
    return EFI_UNSUPPORTED;
  }

  if(!pQcomChargerProtocol)
  {
    Status = gBS->LocateProtocol( &gQcomChargerProtocolGuid, NULL, (VOID **)&pQcomChargerProtocol );

    if((EFI_SUCCESS != Status) || (NULL == pQcomChargerProtocol))
    {
      return EFI_DEVICE_ERROR;
    }
  }
  
  Status = pQcomChargerProtocol->GetBatteryPresence(pBatteryPresent);
  
  return Status;
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
  EFI_STATUS                      Status = EFI_SUCCESS;

  EFI_PLATFORMINFO_PLATFORM_TYPE  PlatformType;

  if (!pBatteryVoltage)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_WARN, "ChargerExProtocol:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  if((EFI_PLATFORMINFO_TYPE_CDP == PlatformType) || (EFI_PLATFORMINFO_TYPE_RUMI == PlatformType) 
    || (EFI_PLATFORMINFO_TYPE_CLS == PlatformType))
  {
    DEBUG(( EFI_D_WARN, "ChargerExProtocol:: %a CDP/RUMI/CLS (%d) Platform detected. No Battery information available. \r\n", __FUNCTION__, PlatformType));
    return EFI_UNSUPPORTED;
  }

  if(!pQcomChargerProtocol)
  {
    Status = gBS->LocateProtocol( &gQcomChargerProtocolGuid, NULL, (VOID **)&pQcomChargerProtocol );

    if(EFI_SUCCESS != Status || NULL == pQcomChargerProtocol)
    {
      return EFI_DEVICE_ERROR;
    }
  }

  Status = pQcomChargerProtocol->GetBatteryVoltage(pBatteryVoltage);

  return Status;
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
  EFI_STATUS Status         = EFI_SUCCESS;

  BOOLEAN    ChargerPresent = FALSE;
  BOOLEAN    IsWarmReset    = FALSE;
  BOOLEAN    IsColdBoot     = FALSE;
  BOOLEAN    BatteryPresent = FALSE;
  BOOLEAN    IsChargingSupported = FALSE;
  UINT64     AllPonReasons = 0x00;
  char*		 Pon_off_reason = NULL;
  UINT64     AllFaultReasons = 0x00;
  char*      Pon_fault_reason = NULL;
  EFI_PM_PON_REASON_TYPE PonReasonType;
  EFI_PLATFORMINFO_PLATFORM_TYPE       PlatformType;

  if(NULL == bOffModeCharging)
    return EFI_INVALID_PARAMETER;

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_WARN, "ChargerExProtocol:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  if((EFI_PLATFORMINFO_TYPE_CDP == PlatformType) || (EFI_PLATFORMINFO_TYPE_RUMI == PlatformType))
  {
    DEBUG(( EFI_D_WARN, "ChargerExProtocol:: %a CDP/RUMI (%d) Platform detected. No Battery information available. \r\n", __FUNCTION__, PlatformType));
    return EFI_UNSUPPORTED;
  }

  if (!pQcomChargerProtocol)
  {
    Status = gBS->LocateProtocol(&gQcomChargerProtocolGuid, NULL, (VOID **)&pQcomChargerProtocol);

    if ((EFI_SUCCESS != Status) || (NULL == pQcomChargerProtocol))
    {
      return EFI_DEVICE_ERROR;
    }
  }

  Status = pQcomChargerProtocol->IsChargingSupported(&IsChargingSupported);
  if (EFI_SUCCESS != Status)
  {
    return EFI_DEVICE_ERROR;
  }
  else if (!IsChargingSupported)
  {
    *bOffModeCharging = FALSE;
    return Status;
  }

  if(!pPmicPwRonProtocol)
  {
    Status |= gBS->LocateProtocol( &gQcomPmicPwrOnProtocolGuid, NULL, (VOID **)&pPmicPwRonProtocol);
    if(EFI_SUCCESS != Status || NULL == pPmicPwRonProtocol)
    {
      return EFI_DEVICE_ERROR;
    }
  }
  
  Status |= pPmicPwRonProtocol->GetPonReason(PM_DEVICE_0, &PonReasonType);
  if(Status != EFI_SUCCESS)
    return EFI_DEVICE_ERROR;
  
  Status |= pPmicPwRonProtocol->GetAllPonReasons(PM_DEVICE_0, &AllPonReasons);
  if(Status != EFI_SUCCESS)
    return EFI_DEVICE_ERROR;
  
  Pon_off_reason = (char *)&AllPonReasons;

  Status |= pPmicPwRonProtocol->GetAllFaultReasons(PM_DEVICE_0, &AllFaultReasons);
  if(Status != EFI_SUCCESS)
    return EFI_DEVICE_ERROR;

  Pon_fault_reason = (char *)&AllFaultReasons;

  if(Pon_off_reason[7] & PON_OFF_REASON_FAULT_SEQ_MASK)
  {
    DEBUG((EFI_D_INFO, "ChargerExProtocol:: %a POFF due to Pmic Fault. PON_FAULT_REASON1 = 0x%02X, PON_FAULT_REASON2 = 0x%02X \r\n", 
					__FUNCTION__, Pon_fault_reason[0], Pon_fault_reason[1]));
    DEBUG((EFI_D_INFO, "ChargerExProtocol:: %a Off mode charging false \r\n", __FUNCTION__));
    *bOffModeCharging = FALSE;
	return EFI_SUCCESS;
  }  
  
  if(EFI_PLATFORMINFO_TYPE_CLS == PlatformType)
  {
    if(PonReasonType.KPDPWR || PonReasonType.HARD_RESET)
    {
      *bOffModeCharging = FALSE;
    }
    else
    {
      DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a Off mode charging true \r\n", __FUNCTION__));
      *bOffModeCharging = TRUE;
      DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a HARD_RESET = %d .KPDPWR = %d PON1 = %d USB_CHG = %d CBLPWR = %d \r\n", __FUNCTION__, PonReasonType.HARD_RESET, PonReasonType.KPDPWR, 
                      PonReasonType.PON1, PonReasonType.USB_CHG, PonReasonType.CBLPWR));
    }
    return EFI_SUCCESS;
  }
  else
  {
    /* Get Battery Presence, Charger Presence, Voltage */
    Status |=  EFI_ChargerExGetBatteryPresence(&BatteryPresent);
    Status |= pPmicPwRonProtocol->WarmResetStatus(PM_DEVICE_0, &IsWarmReset); /* Need PON API abstracted (no index)*/
    Status |= EFI_ChargerExGetChargerPresence(&ChargerPresent);

    IsColdBoot = !IsWarmReset;

    if(Status == EFI_SUCCESS)
    {
      if((IsColdBoot) 
        && (BatteryPresent) 
        && (ChargerPresent)                   /* If not warm reset and charger,battery present */
        && (!PonReasonType.HARD_RESET) 
        && (!PonReasonType.KPDPWR) /* If not Hard reset and not a Powery key boot */
        && (PonReasonType.PON1 || PonReasonType.USB_CHG || PonReasonType.CBLPWR))       /* if PON1 or USB triggered PON or cable PON
                                                                                         * SYS_OK signal is now routed to CBLPWR instead of PON1 due to hardware bug */
      {
        DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a Off mode charging true \r\n", __FUNCTION__));
        *bOffModeCharging = TRUE;
      }
      else
      {
        DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a HARD_RESET = %d .KPDPWR = %d PON1 = %d USB_CHG = %d CBLPWR = %d \r\n", __FUNCTION__, PonReasonType.HARD_RESET, PonReasonType.KPDPWR, 
                        PonReasonType.PON1, PonReasonType.USB_CHG, PonReasonType.CBLPWR));
        DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a IsColdBoot = %d BatteryPresent = %d ChargerPresent = %d \r\n", __FUNCTION__, IsColdBoot, BatteryPresent, ChargerPresent));
        DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a Off mode charging False \r\n", __FUNCTION__));
       *bOffModeCharging = FALSE;
      }
    }
  }
  return Status;
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
  IN  EFI_CHARGER_EX_POWER_TYPE   PowerType,
  OUT VOID                       *pPowerTypeInfo
)
{
  EFI_STATUS Status                = EFI_SUCCESS;
  EFI_CHARGER_EX_FLASH_INFO *pFlashInfo = NULL;
  UINT32     SwFlashBattMinVoltage = 0;
  UINT32     BatteryCurrentVoltage = 0;
  BOOLEAN    BatteryPresent        = FALSE;
  BOOLEAN    ChargerPresent        = FALSE;
  EFI_PLATFORMINFO_PLATFORM_TYPE       PlatformType;

  if(!pPowerTypeInfo)
    return EFI_INVALID_PARAMETER;

  pFlashInfo = (EFI_CHARGER_EX_FLASH_INFO *)pPowerTypeInfo;

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_WARN, "ChargerExProtocol:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  if((EFI_PLATFORMINFO_TYPE_CDP == PlatformType) || (EFI_PLATFORMINFO_TYPE_RUMI == PlatformType))
  {
    DEBUG(( EFI_D_WARN, "ChargerExProtocol:: %a CDP/RUMI (%d) Platform detected. No Battery information available. \r\n", __FUNCTION__, PlatformType));
    return EFI_UNSUPPORTED;
  }
  else if(EFI_PLATFORMINFO_TYPE_CLS == PlatformType)
  {
    pFlashInfo = (EFI_CHARGER_EX_FLASH_INFO *)pPowerTypeInfo;
    pFlashInfo->bCanFlash = TRUE;
    return EFI_SUCCESS;
  }

  switch(PowerType)
  {
    case EFI_CHARGER_EX_POWER_FLASH_BATTERY_VOLTAGE_TYPE:
      pFlashInfo = (EFI_CHARGER_EX_FLASH_INFO *)pPowerTypeInfo;
      /* Get Battery Presence, Charger Presence, Voltage */
      Status =  EFI_ChargerExGetBatteryPresence(&BatteryPresent);
      Status |= EFI_ChargerExGetChargerPresence(&ChargerPresent);
      Status |= EFI_ChargerExGetBatteryVoltage(&BatteryCurrentVoltage);

      if(EFI_SUCCESS == Status)
      {
        pFlashInfo->BattCurrVoltage = BatteryCurrentVoltage;
      }

      if(!pQcomChargerProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomChargerProtocolGuid, NULL, (VOID **)&pQcomChargerProtocol );
        if(EFI_SUCCESS != Status || NULL == pQcomChargerProtocol)
        {
          return EFI_DEVICE_ERROR;
        }
      }

      Status |= pQcomChargerProtocol->GetChargerConfig(EFI_QCOM_CHARGER_CONFIG_KEY_SW_FLASH_VOLTAGE, &SwFlashBattMinVoltage);

      if(Status == EFI_SUCCESS)
      {
        pFlashInfo->BattRequiredVoltage = SwFlashBattMinVoltage;
        /* If battery not present but still device boot up have debug board */
        if(!BatteryPresent || (BatteryPresent  && (BatteryCurrentVoltage > SwFlashBattMinVoltage)))
        {
          pFlashInfo->bCanFlash = TRUE;
        }
        else
        {
          DEBUG(( EFI_D_INFO, "ChargerExProtocol:: %a SwFlashBattMinVoltage = %d mV\r\n", __FUNCTION__,SwFlashBattMinVoltage));
          pFlashInfo->bCanFlash = FALSE;
        }
      }
    break;
    default:
    break;
  }

  return Status;
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

