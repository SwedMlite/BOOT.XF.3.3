/** @file ChargerLibTarget.c

  Provide access to Charger Libraries

  Copyright (c) 2018-2019, Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when         who     what, where, why
 --------     ---     ---------------------------------------------------------
05/30/19      mr      Disable Sink DAM
05/20/19      mr      Move image display functionality from Chargerlib to ChargerApp
03/05/2019    pbitra  Fixed die temp values and channel passed to ADC
01/12/2019    vr      Fix issue where charging is disabled in unknown battery cases
01/12/2019    vr      Moved HW Jeita config to PmicDxe after batt therm (from profile) is read
06/29/2018    dc      Support USB Charger Type Logging
06/29/2018    dc      Support Input Current Status API & Log
06/13/2018    cs      need to also set CBLPWR to edge trigger to avoid device reboot with usb inserted
05/14/2018    ra      Support for Debug Accessory Mode
03/26/2018    va      Initial revision
=============================================================================*/

/*===========================================================================*/
/*                  INCLUDE FILES                                            */
/*===========================================================================*/
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/QcomLib.h>
#include "Library/SerialPortShLib.h"
#include <Library/QcomTargetLib.h>
#include <api/pmic/pm/pm_uefi.h>
#include <Library/QcomBaseLib.h>
#include <PrintShLib.h>
#include <Library/UefiCfgLib.h>

#include <Library/BaseMemoryLib.h>
#include "string.h"

#include <api/pmic/charger/ChargerLibCommon.h>
#include "../Library/ChargerLib/ChargerLibTarget.h"


/**
  Protocol Dependencies
*/
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFIPmicFg.h>
#include <Protocol/EFIPmicSchg.h>
//#include <Protocol/EFIPmicUsb.h>
#include <Protocol/EFIPmicVersion.h>
#include <Protocol/EFIPmicPwrOn.h>
#include <Protocol/EFIVariableServices.h>
#include <Protocol/EFITsens.h>
#include <Protocol/EFIPmicRTC.h>
#include <Protocol/EFIUsbfnChgSrv.h>
#include <Protocol/EFIPmicRgbLed.h>
#include <Protocol/EFIUsbInitProtocol.h>


/*===========================================================================*/
/*                  TYPEDEF AND MACRO DEFINITIONS                            */
/*===========================================================================*/
#define BATTERY_EMULATOR_UPPER_THRSHOLD_MV  4450
#define BATTERY_EMULATOR_LOWER_THRSHOLD_MV  3450
#define BATTERY_EMULATOR_BATT_ID            1500
#define BATTERY_EMULATOR_TEMP_C             23
#define BATTERY_EMULATOR_SOC                99

#define VBATT_TOLERANCE                     5 //Battery upper voltage tolerance limit.

#define UNKNOWN_BATT_SHUTDOWN               0
#define UNKNOWN_BATT_BOOT_TO_HLOS           1
#define UNKNOWN_BATT_CONSERVATIVE_CHARGING  2
#define UNKNOWN_BATT_REGULAR_CHARGING       3

#define DEBUG_BOARD_LOWVBAT_SHUTDOWN        0
#define DEBUG_BOARD_LOWVBAT_NOCHARGE        1
#define DEBUG_BOARD_BOOT_TO_HLOS            2

#define CHARGER_COOL_OFF_PERIOD_DEFAULT     300000 //5minutes=1000millisec*60*5=300000 milli sec
#define BOOT_THRESHOLD_VOLT                 3600

#define TWO_SECONDS                         2000000 /*2seconds = 2000000 uSec*/

#define FIVE_SEC_IN_MILLI_SEC               5000
#define TIMEOUT_WAIT_FOR_KEY                0x01

#define MAX_3000_MA                         3000
#define MAX_1500_MA                         1500

#define THERMAL_TIMEOUT_NOTSET              0
#define MIN_TO_SEC                          60

#define MAX_THERMAL_WAIT_PERIOD_IN_MINS     60

#define USB_3_IUSB_MAX                      900 //IUSB_MAX for USB 3.0 port
#define USB_2_IUSB_MAX                      500 //IUSB_MAX for USB 2.0 port
#define FCC_CONSERVE_CHG                    500
#define USB_ENUM_WAIT_DURATION              500 /*500 milliseconds*/

#define MAX_EMERGENCY_SHUTDOWN_COUNT        3

#define THERMAL_TIMEOUT_NOTSET              0
#define MIN_TO_SEC                          60

#define MAX_THERMAL_WAIT_PERIOD_IN_MINS     60

/*===========================================================================*/
/*                  FUNCTIONS PROTOTYPES                                     */
/*===========================================================================*/
void ChargerLibTarget_HWInit(chargerlib_cfgdata_type *pChargerLibConfig);
EFI_STATUS ChargerLibTarget_ConfigureUsbCurrentSetting( VOID );
EFI_STATUS ChargerLibTarget_PrintDCInStatus();
EFI_STATUS ChargerLibTarget_GetBatteryType(ChgBattType *pBatteryType);
EFI_STATUS ChargerLibTarget_GetUsbcPortType(CHARGERLIB_CHG_USBC_SINK_TYPE *pUsbcPortType);

/*===========================================================================*/
/*                  LOCAL VARIABLE DECLARATIONS                              */
/*===========================================================================*/
STATIC EFI_QCOM_PMIC_SCHG_PROTOCOL          *PmicSchgProtocol  = NULL;
STATIC EFI_QCOM_PMIC_FG_BASIC_PROTOCOL      *PmicFgProtocol    = NULL;
STATIC EFI_QCOM_PMIC_PWRON_PROTOCOL         *PmicPwronProtocol = NULL;
STATIC EFI_ADC_PROTOCOL                     *AdcProtocol       = NULL;
STATIC EFI_USBFN_CHG_SRV_PROTOCOL           *UsbChgSrvProtocol = NULL;
//STATIC EFI_QCOM_PMIC_USB_PROTOCOL           *PmicUsbProtocol   = NULL;
STATIC EFI_USB_INIT_PROTOCOL                *UsbInitProtocol = NULL;

EFI_BATTERY_CHARGER_INFO_TYPE           ChargerInfo = {0};
EFI_BATTERY_GAUGE_INFO_TYPE             BatteryGaugeInfo = {0};
chargerlib_cfgdata_type                 gChargerLibTargetCfgData = {0};


extern EFI_GUID gQcomPmicPwrOnProtocolGuid;
extern EFI_GUID gQcomPmicUsbProtocolGuid;
//extern EFI_GUID gEfiUsbfnChgSrvProtocolGuid;

STATIC EFI_PLATFORMINFO_PLATFORM_TYPE  PlatformType;
STATIC BOOLEAN                         gChargingEnabled = FALSE;
STATIC BOOLEAN                         gStartControllerCalled = FALSE;
STATIC BOOLEAN                         gProfileLoadCalled = FALSE;

STATIC CHARGERLIB_EVENT_DISP_IMAGE_TYPE gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_NONE;

STATIC CONST CHARGERLIB_HW_CONFIG_INFO ChargerLibHwConfigTable[CHARGERLIB_PLATFORM_HW_CONFIG_MAX]= {
  {EfiBatteryChargerNone,         0x00010000, EfiBatteryGaugeNone,       0x00010000}, //NONE
  {EfiBatteryChargerQcomPmicSchg, 0x00010000, EfiBatteryGaugeQcomPmicFg, 0x00010000}, //PMIC
};

STATIC CONST CHARGERLIB_PLATFORM_HW_CONFIG_INFO ChargerLibPlatformHwInfo[]=
{
  {EFI_PLATFORMINFO_TYPE_MTP,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_FLUID,   NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_QRD,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_HDK,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_CHI,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_SBC,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_LIQUID,  NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_PMIC},
  {EFI_PLATFORMINFO_TYPE_RUMI,    NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_NONE},
  {EFI_PLATFORMINFO_TYPE_CDP,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_NONE},
  {EFI_PLATFORMINFO_TYPE_CLS,     NULL,   CHARGERLIB_PLATFORM_HW_CONFIG_NONE},
};

/*===========================================================================*/
/*                 FUNCTION DEFINITIONS                                      */
/*===========================================================================*/
/**
  Initialize ChargerLib Target functon Library functions

  @param none

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_INVALID_PARAMETER: A Parameter was incorrect.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_NOT_READY:         The physical device is busy or not ready to
                         process this request.
*/
EFI_STATUS ChargerLibTarget_Init( chargerlib_cfgdata_type *pChargerLibTargetConfig )
{
  EFI_STATUS                  Status         = EFI_SUCCESS;
  ChgBattType                 battType  = CHG_BATT_TYPE_INVALID;
  BOOLEAN                     bDbgBoard = FALSE;
  EfiAdcDeviceChannelType     AdcChannel = {0};
  EfiAdcResultType            AdcResult = {0};

  CopyMemS(&gChargerLibTargetCfgData, sizeof(chargerlib_cfgdata_type), pChargerLibTargetConfig , sizeof(chargerlib_cfgdata_type));

  Status |= GetPlatformType(&PlatformType);
  if(EFI_SUCCESS != Status)
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting platform type  \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  /* Enable USB and DCIN PON triggers to be certain and avoid bad use case*/
  Status = ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_PON1_REDGE_PON, FALSE);
  Status |= ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_CBLPWR_FEDGE_PON, FALSE);

  if(Status != EFI_SUCCESS)
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error locating Pwron Protocol = %r \r\n", __FUNCTION__, Status));
  }

  ChargerLibTarget_HWInit(pChargerLibTargetConfig);

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
    case EfiBatteryGaugeQcomPmicFg:
      /* Locate FG Protocol */
      if (!PmicFgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicFgProtocolGuid,
                                      NULL,
                                     (VOID **)&PmicFgProtocol );
      }

      /* Initialize FG Protocol */
      if((EFI_SUCCESS == Status ) && ( NULL != PmicFgProtocol))
      {
        Status |= PmicFgProtocol->FgBasicGetPmicInfo(&BatteryGaugeInfo.BatteryGaugePmicInfo);
        if(EFI_SUCCESS != Status)
        {
          CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to get PmicIndex for Fuel Gauge : 0x%08X \r\n", __FUNCTION__, Status));
          return Status;
        }

        gChargerLibTargetCfgData.fg_cfg_data.FgDbgCfg =  *(EFI_PM_FG_DEBUG_CFGDATA_TYPE *)&gChargerLibTargetCfgData.dbg_cfg_Data;

        Status |= PmicFgProtocol->FgBasicInit(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex,
                                              &gChargerLibTargetCfgData.fg_cfg_data);
        if(EFI_SUCCESS != Status)
        {
          CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to initialize Fuel Gauge: 0x%08X  \r\n", __FUNCTION__, Status));
          return Status;
        }

        Status = ChargerLibTarget_GetBatteryType(&battType);
        if (EFI_SUCCESS != Status)
        {
          CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Coulen't retrieve battery type, assuming real battery = %r \r\n", __FUNCTION__, Status));
          Status = EFI_SUCCESS;
      }
        else
        {
          bDbgBoard = (battType == CHG_BATT_TYPE_DEBUG_BOARD) ? TRUE : FALSE;
        }
      }
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;

  }

  /* Use ADC to scale the JEITA and AFP values */
  /* Locate ADC Protocol */
  if (!AdcProtocol)
  {
    Status |= gBS->LocateProtocol(&gEfiAdcProtocolGuid,
      NULL,
      (VOID **)&AdcProtocol);
  }
  if ((EFI_SUCCESS == Status) && (NULL != AdcProtocol))
  {

    /* Getting ADC scaled value for PMIC die temp */
    Status = AdcProtocol->GetChannel(EFI_ADC_INPUT_CHG_TEMP, sizeof(EFI_ADC_INPUT_CHG_TEMP), &AdcChannel);
    if (EFI_SUCCESS != Status)
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to get the channel for EFI_ADC_INPUT_CHG_TEMP : 0x%08X \r\n", __FUNCTION__, Status));
      return Status;
    }
    /* ADC scaled code for Pmic die temp Hot Limit. The temp needs to be passed in milli deg */
    Status = AdcProtocol->AdcProcessConversionResultInverse(&AdcChannel, (pChargerLibTargetConfig->schg_cfg_data.SchgSkinDieTemp.ChargerHotInC * 1000), &AdcResult);
    if (EFI_SUCCESS != Status)
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to get ADC scaling code for PMIC die hot temp : 0x%08X \r\n", __FUNCTION__, Status));
      return Status;
    }
    gChargerLibTargetCfgData.schg_cfg_data.SchgSkinDieTemp.ChargerHotInC = AdcResult.nCode;

    /* ADC scaled code for Pmic die temp Too hot Limit. The temp needs to be passed in milli deg  */
    Status = AdcProtocol->AdcProcessConversionResultInverse(&AdcChannel, (pChargerLibTargetConfig->schg_cfg_data.SchgSkinDieTemp.ChargerTooHotInC * 1000), &AdcResult);
    if (EFI_SUCCESS != Status)
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to get ADC scaling code for PMIC die too hot temp : 0x%08X \r\n", __FUNCTION__, Status));
      return Status;
    }
    gChargerLibTargetCfgData.schg_cfg_data.SchgSkinDieTemp.ChargerTooHotInC = AdcResult.nCode;

  }


  /* Initialize Charger and Gauge HW */
  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      /* Locate SCHG Protocol */
      if (!PmicSchgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicSchgProtocolGuid,
                                       NULL,
                                      (VOID **)&PmicSchgProtocol );
      }

      if ((EFI_SUCCESS == Status) && (NULL != PmicSchgProtocol))
      {
          Status = PmicSchgProtocol->SchgGetPmicInfo(&ChargerInfo.ChargerPmicInfo);
          if (EFI_SUCCESS != Status)
          {
              CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to get PmicIndex for SCHG : 0x%08X \r\n", __FUNCTION__, Status));
              return Status;
          }

          gChargerLibTargetCfgData.schg_cfg_data.SchgDbgCfg = *(EFI_PM_SCHG_DEBUG_CFGDATA_TYPE *)&gChargerLibTargetCfgData.dbg_cfg_Data;

          /* Initialize SCHG Protocol */
          Status = PmicSchgProtocol->SchgInit(ChargerInfo.ChargerPmicInfo.PmicIndex, gChargerLibTargetCfgData.schg_cfg_data, bDbgBoard);
          if (EFI_SUCCESS != Status)
          {
              CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to initialize SCHG : 0x%08X \r\n", __FUNCTION__, Status));
          }

          /* Enable/Disable Debug Accessory Mode and FMB (Factory Mode Boot) */
          Status  = PmicSchgProtocol->EnDebugAccessoryMode(ChargerInfo.ChargerPmicInfo.PmicIndex,
                        gChargerLibTargetCfgData.schg_cfg_data.EnDebugAccessMode,
                        gChargerLibTargetCfgData.schg_cfg_data.EnFMB);

          /* Set the Debug Accessory Mdoe ICL */
          Status |= ChargerLib_SetDAMICL(gChargerLibTargetCfgData.schg_cfg_data.DAMSelIcl3AorFMB);
          if (EFI_SUCCESS != Status)
          {
              CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a  Factory mode config failed, Status : %r \r\n", __FUNCTION__, Status));
          }
      }
      break;

    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

/**
  Get Battery Status Information
  @param[out] BattStatusInfo  refer EFI_PM_FG_BATT_STATUS_INFO
  This function gets the battery status, battery SOC, Charge current, battery voltage
  and battery temperature from Fuel Gauge

  @param[out] BatteryStatus  see chargerlib_batt_status_info for more details

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_GetBatteryStatus(chargerlib_batt_status_info *pBatteryStatus)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_FG_BATT_STATUS_INFO BatteryStatus = {0};

  if(NULL == pBatteryStatus)
  {
    return EFI_INVALID_PARAMETER;
  }

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
    case EfiBatteryGaugeQcomPmicFg:
      Status = PmicFgProtocol->GetBatteryStatus(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex,
                                                (EFI_PM_FG_BATT_STATUS_INFO *)&BatteryStatus);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  if(EFI_SUCCESS == Status)
  {
    if (sizeof(chargerlib_batt_status_info) >= sizeof(EFI_PM_FG_BATT_STATUS_INFO))
    {
  CopyMemS(pBatteryStatus, sizeof(chargerlib_batt_status_info), &BatteryStatus, sizeof(EFI_PM_FG_BATT_STATUS_INFO));
    }
    else
    {
      Status = EFI_BAD_BUFFER_SIZE;
    }
  }
  /* Hardcoded battery temperature as batt therm (from profile) is not read yet*/
  if (!gProfileLoadCalled)
  {
    pBatteryStatus->BatteryTemperature = 25;
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib::%a BatteryTemp might be off as batt therm pull up (from profile) is not read yet \r\n", __FUNCTION__));
  }

  return Status;
}

/**
  Get Battery Status Information
  @param[out] BattStatusInfo  refer EFI_PM_FG_BATT_STATUS_INFO
  This function gets the battery status, battery SOC, Charge current, battery voltage
  and battery temperature from Fuel Gauge

  @param[out] BatteryStatus  see chargerlib_batt_status_info for more details

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_GetBatteryProfileStatus(chargerlib_batt_profile_status *ProfileSts)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if(!ProfileSts)
  {
    return EFI_INVALID_PARAMETER;
  }

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
    case EfiBatteryGaugeQcomPmicFg:
      /* Locate FG Protocol */
      if (!PmicFgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicFgProtocolGuid,
                                      NULL,
                                     (VOID **)&PmicFgProtocol );
        if(Status != EFI_SUCCESS || NULL == PmicFgProtocol)
          return EFI_DEVICE_ERROR;
      }
      Status = PmicFgProtocol->GetBattProfileStatus(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex,
                                                    (EFI_PM_FG_BATT_PROFILE_STATUS *)ProfileSts);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_LoadProfile(OPTIONAL chargerlib_batt_profile_data *pBattProfileInfo)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
  case EfiBatteryGaugeQcomPmicFg:
    if (!PmicFgProtocol)
    {
      Status |= gBS->LocateProtocol( &gQcomPmicFgProtocolGuid,
                                    NULL,
                                   (VOID **)&PmicFgProtocol );
    }
    /* Initialize FG Protocol */
    if((EFI_SUCCESS == Status ) && ( NULL != PmicFgProtocol))
    {
      Status |= PmicFgProtocol->FgExtendedInit(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex,
                                               (EFI_PM_FG_BATT_PROFILE_DATA *)pBattProfileInfo);
      if(EFI_SUCCESS != Status)
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed to initialize Fuel Gauge: 0x%08X  \r\n", __FUNCTION__, Status));
        return Status;
      }
    }
    break;

  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  gProfileLoadCalled = TRUE;

  return Status;

}

/**
  Enable charger

  @param[in] Enable  TRUE  - Enable Charging
                     FALSE - Disable Charging

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_ChargerEnable(BOOLEAN Enable)
{
  EFI_STATUS Status = EFI_SUCCESS;
  BOOLEAN    BatteryPresent = FALSE;

  Status = ChargerLibTarget_GetBatteryPresence(&BatteryPresent);
  if (BatteryPresent)
  {
    switch (ChargerInfo.ChargerHW)
    {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->EnableCharger(ChargerInfo.ChargerPmicInfo.PmicIndex, Enable);
      if( EFI_SUCCESS != Status )
        return Status;

      gChargingEnabled = Enable;

        /* make sure to turn Off Charging Led if charging is getting disabled */
      if(!Enable && gChargerLibTargetCfgData.charger_led_config)
          ChargerLibTarget_LedOn(FALSE);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
    }
  }

  return Status;
}

/**
  Set charger max current

  @param[in] MaxCurrent  Max current for charger in mA

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_SetMaxUsbCurrent(UINT32 MaxCurrent)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->SetUsbMaxCurrent(ChargerInfo.ChargerPmicInfo.PmicIndex, MaxCurrent);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

/**
  Set Battery FCC Max current

  @param[in] FccMaxCurrent  Max current for charger in mA

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_SetFccMaxCurrent(UINT32 FccMaxCurrent)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->SetFccMaxCurrent(ChargerInfo.ChargerPmicInfo.PmicIndex, FccMaxCurrent);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_WasChargerReinserted(BOOLEAN *pChargerReinserted)
{
  EFI_STATUS Status = EFI_SUCCESS;
  //boolean aicl_done = FALSE;

  if(!pChargerReinserted)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pChargerReinserted = FALSE;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->ChgrSourceReinserted(ChargerInfo.ChargerPmicInfo.PmicIndex, pChargerReinserted);
      break;
    default:
      break;
  }

  if(EFI_SUCCESS == Status)
  {
    if(TRUE == *pChargerReinserted)
    {
      Status = ChargerLibTarget_ConfigureUsbCurrentSetting();
    }
  }
  else
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error checking Charger re-insertion status, Status: 0x%08X\n",__FUNCTION__, Status));
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_ReRunAicl( VOID )
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      /*
      Status = PmicSchgProtocol->RerunAicl(ChargerInfo.ChargerPmicInfo.PmicIndex);
      */
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

/**
  Set Battery Floating Max Voltage

  @param[in] VddMaxVoltage  Max Voltage for Charger in mV

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_SetFvMaxVoltage(UINT32 VddMaxVoltage)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->SetFvMaxVoltage(ChargerInfo.ChargerPmicInfo.PmicIndex, VddMaxVoltage);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

/**
  Get Charger/Power Path

  @param[out] Powerpath

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_INVALID_PARAMETER: Parameter is invalid.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
//EFI_STATUS ChargerLibTarget_GetPowerPath(CHARGERLIB_ATTACHED_CHGR_TYPE *PowerPath)
//{
//  EFI_STATUS Status = EFI_SUCCESS;
//
//  switch (ChargerInfo.ChargerHW)
//  {
//  case EfiBatteryChargerQcomPmicSchg:
//    Status = PmicSchgProtocol->GetPowerPath(ChargerInfo.ChargerPmicInfo.PmicIndex, (PM_SCHG_POWER_PATH_TYPE *)PowerPath);
//    break;
//  default:
//    Status = EFI_UNSUPPORTED;
//    break;
//  }
//
//  return Status;
//}

EFI_STATUS ChargerLibTarget_GetChargingPath(CHARGERLIB_ATTACHED_CHGR_TYPE *ChargingPath)
{
  EFI_STATUS Status = EFI_SUCCESS;
  BOOLEAN IsInputValid = FALSE;

  if (!ChargingPath)
  {
    return EFI_INVALID_PARAMETER;
  }
  *ChargingPath = CHARGERLIB_ATTACHED_CHGR__NONE;
  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->UsbinValid(ChargerInfo.ChargerPmicInfo.PmicIndex, &IsInputValid);
    if(Status != EFI_SUCCESS)
    {
      break;
    }
    if (IsInputValid)
    {
      *ChargingPath = CHARGERLIB_ATTACHED_CHGR__USB;
    }
    else
    {
      Status = PmicSchgProtocol->DcinValid(ChargerInfo.ChargerPmicInfo.PmicIndex, &IsInputValid);
      if(Status != EFI_SUCCESS)
      {
        break;
      }
      if (IsInputValid)
      {
        *ChargingPath = CHARGERLIB_ATTACHED_CHGR__DCIN;
      }
      else
      {
        *ChargingPath = CHARGERLIB_ATTACHED_CHGR__NONE;
      }
    }
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

/**
  Get Battery Presence

  @param[out] BatteryPresence

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_INVALID_PARAMETER: Parameter is invalid.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_GetBatteryPresence(BOOLEAN *BatteryPresence)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
         if(!PmicSchgProtocol)
         {
           Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid, NULL, (VOID **)&PmicSchgProtocol);
         }

         if((NULL == PmicSchgProtocol ) || (Status != EFI_SUCCESS))
           return EFI_DEVICE_ERROR;

         Status = PmicSchgProtocol->IsBatteryPresent(ChargerInfo.ChargerPmicInfo.PmicIndex, BatteryPresence);
         break;
    default:
         Status = EFI_UNSUPPORTED;
         break;
  }

  return Status;
}

/**
  Gets charger port type

  @param[out] pPortType  Charger port type

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_GetPortType(CHARGERLIB_CHGR_PORT_TYPE *pPortType)
{
  EFI_STATUS                  Status = EFI_SUCCESS;
  EFI_PM_SCHG_CHGR_PORT_TYPE  PortType;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status  = PmicSchgProtocol->GetChargerPortType(ChargerInfo.ChargerPmicInfo.PmicIndex, &PortType);
      *pPortType = (CHARGERLIB_CHGR_PORT_TYPE)PortType;

      CHARGER_FILE_UART_DEBUG((EFI_D_WARN,"ChargerLib:: %a Charger Port type = %d \r\n", __FUNCTION__, PortType));

      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}


EFI_STATUS ChargerLibTarget_HandleNoChargeAndWait(void)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if (TRUE == gChargerLibTargetCfgData.no_charge_and_wait)
  {
    /*Disable Charging */
    Status = ChargerLibTarget_ChargerEnable(FALSE);
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Charging Disabled \r\n", __FUNCTION__));
  }
  else
  {
    ChargerLibTarget_ForceSysShutdown(CHGAPP_RESET_AFP);
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_EnableAfpMode(void)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->EnableAfpMode(ChargerInfo.ChargerPmicInfo.PmicIndex);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetBatteryID(INT32 *pBatteryID)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_BATTERY_ID battery_id = { 0 };

  if(NULL == pBatteryID)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pBatteryID = 0;

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
  case EfiBatteryGaugeQcomPmicFg:
    Status = PmicFgProtocol->GetBatteryId(&battery_id);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  if (EFI_SUCCESS == Status)
  {
    *pBatteryID = (INT32)battery_id.BattId;
  }

  CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a BATT_ID_2 = %d \r\n", __FUNCTION__, *pBatteryID));

  return Status;
}

EFI_STATUS ChargerLibTarget_GetBatteryType(ChgBattType *pBatteryType)
{
  EFI_STATUS Status = EFI_SUCCESS;
  INT32      battery_id = 0;

  if(NULL == pBatteryType)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pBatteryType = CHG_BATT_TYPE_INVALID;

  Status = ChargerLibTarget_GetBatteryID(&battery_id);
  if(EFI_SUCCESS != Status)
  {
    return Status;
  }

  /*Check if battery ID is within real battery range*/
  if((battery_id >= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.SmartBatteryIdMin) &&
     (battery_id <= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.SmartBatteryIdMax))
   {
     *pBatteryType = CHG_BATT_TYPE_SMART;
   }
   else if((battery_id >= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.RegularBatteryIdMin) &&
     (battery_id <= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.RegularBatteryIdMax))
   {
     *pBatteryType = CHG_BATT_TYPE_NORMAL;
   }
   else if((battery_id >= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.DebugBoardBatteryIdMin) &&
     (battery_id <= gChargerLibTargetCfgData.fg_cfg_data.FgBattIdCfg.DebugBoardBatteryIdMax))
   {
     *pBatteryType = CHG_BATT_TYPE_DEBUG_BOARD;
   }
   else
   {
     *pBatteryType = CHG_BATT_TYPE_UNKNOWN;
   }

   CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Battery type = %d \r\n", __FUNCTION__, *pBatteryType));

  return Status;
}

EFI_STATUS ChargerLibTarget_UsbSuspend(BOOLEAN Enable)
{
  EFI_STATUS Status = EFI_SUCCESS;

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a ChargerLib UsbSuspend = %d \r\n", __FUNCTION__, Enable));

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->UsbSuspend(ChargerInfo.ChargerPmicInfo.PmicIndex, Enable);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_DcinSuspend(BOOLEAN Suspend)
{
  EFI_STATUS Status = EFI_SUCCESS;

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a ChargerLib DcinSuspend = %d \r\n", __FUNCTION__, Suspend));

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->DcinSuspend(ChargerInfo.ChargerPmicInfo.PmicIndex, Suspend);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_DcinSetPowerLimit(UINT32 PowerInMicroW)
{
  EFI_STATUS Status = EFI_SUCCESS;

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a ChargerLib powerInMicroW = %d w\r\n", __FUNCTION__, PowerInMicroW));

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->SetDcinPower(ChargerInfo.ChargerPmicInfo.PmicIndex, PowerInMicroW);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetDebugBoardAction(CHARGERLIB_ERROR_ACTION_TYPE *pDebugBoardAction)
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINT32     DebugBoardBehaviour = gChargerLibTargetCfgData.debug_board_behavior;

  chargerlib_batt_status_info  BatteryStatus;

  if (!pDebugBoardAction)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = ChargerLibTarget_GetBatteryStatus(&BatteryStatus);
  if( EFI_SUCCESS != Status )
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting battery status = %r \r\n", __FUNCTION__, Status));
    return Status;
  }

  /*ignore return type to allow continued booting*/
  ChargerLibTarget_UsbSuspend(TRUE);
  //suspend dcin
  ChargerLibTarget_DcinSuspend(TRUE);

  if(BatteryStatus.BatteryVoltage < gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv)
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Debug board voltage = %d mV is below Threshold = %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv));

    switch(DebugBoardBehaviour)
    {
      case DEBUG_BOARD_LOWVBAT_SHUTDOWN:
        Status = ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_PON1_REDGE_PON, TRUE);
        Status |= ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_CBLPWR_FEDGE_PON, TRUE);
        *pDebugBoardAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
        //display red debug icon
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_DEBUG_LOW_SYMBOL;
        break;
      case DEBUG_BOARD_LOWVBAT_NOCHARGE:
        *pDebugBoardAction = CHARGERLIB_ERROR_ACTION_DEBUG_BOARD_WAIT;
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_DEBUG_LOW_SYMBOL;
        break;
      case DEBUG_BOARD_BOOT_TO_HLOS:
        *pDebugBoardAction = CHARGERLIB_ERROR_ACTION_DEBUG_BOARD_GOOD_TO_BOOT;
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_DEBUG_BOOT_SYMBOL;
        break;
      default:
        break;
    }
  }
  else
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a: Debug board voltage = %d mV is above Threshold = %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv));
    *pDebugBoardAction = CHARGERLIB_ERROR_ACTION_DEBUG_BOARD_GOOD_TO_BOOT;
  }

  return EFI_SUCCESS;
}


EFI_STATUS ChargerLibTarget_ConservativeCharging( void )
{
  EFI_STATUS Status = EFI_SUCCESS;

  /*set conservative parameter */
  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Enabling Conservative charging \r\n", __FUNCTION__));
  Status = ChargerLibTarget_SetFvMaxVoltage(gChargerLibTargetCfgData.schg_cfg_data.ChgFvMax - gChargerLibTargetCfgData.conserv_chg_fv_delta);
  Status |= ChargerLibTarget_SetFccMaxCurrent(FCC_CONSERVE_CHG);

  return Status;
}

EFI_STATUS ChargerLibTarget_GetUnknownBatteryAction(CHARGERLIB_ERROR_ACTION_TYPE *pUnknownBatteryAction)
{
  EFI_STATUS Status               = EFI_SUCCESS;
  UINT32     UnknownBattBehaviour = gChargerLibTargetCfgData.unknown_battery_behavior;
  chargerlib_batt_status_info  BatteryStatus;

  switch (UnknownBattBehaviour)
  {
    case UNKNOWN_BATT_SHUTDOWN:
      *pUnknownBatteryAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN_USB_DC_PON_DISABLED;
      break;
    case UNKNOWN_BATT_BOOT_TO_HLOS:
    /*Boot to HLOS if battery more than threshold. Else shutdown */
      Status = ChargerLibTarget_GetBatteryStatus(&BatteryStatus);
      if( EFI_SUCCESS != Status )
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting battery status = %r \r\n", __FUNCTION__, Status));
        return Status;
      }

      /*ignore return type to allow continued booting*/
      ChargerLibTarget_UsbSuspend(TRUE);
      //suspend dcin
      ChargerLibTarget_DcinSuspend(TRUE);

      if(BatteryStatus.BatteryVoltage > gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv)
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a: Unknown battery detected, voltage = %d mV is above Threshold = %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv));
        *pUnknownBatteryAction = CHARGERLIB_ERROR_ACTION_GOOD_TO_BOOT;
      }
      else
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a: Unknown battery detected, shutting down. Voltage = %d mV is below Threshold = %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv));
        Status = ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_PON1_REDGE_PON, TRUE);
        Status |= ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_CBLPWR_FEDGE_PON, TRUE);
        *pUnknownBatteryAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
      }

      break;
    case UNKNOWN_BATT_CONSERVATIVE_CHARGING:
      ChargerLibTarget_ConservativeCharging();
      break;
    case UNKNOWN_BATT_REGULAR_CHARGING:
      *pUnknownBatteryAction = CHARGERLIB_ERROR_ACTION_START_CHARGING;
      break;
    default:
      ChargerLibTarget_GetDebugBoardAction( pUnknownBatteryAction );
      break;
  }

  return Status;
}


/*This API initiates different types of reset */
EFI_STATUS ChargerLibTarget_ForceSysShutdown(ChgAppSysShutdownType ShutdownType)
{
  EFI_STATUS Status = EFI_SUCCESS;

  EFI_RESET_TYPE   ResetType = EfiResetPlatformSpecific;

  /* This is not needed since HW default is UFP */
  // Get the PMIC USB charger protocol if not already available.
  /*if (NULL == PmicUsbProtocol) {
    Status = gBS->LocateProtocol(&gQcomPmicUsbProtocolGuid, NULL, (void**)&PmicUsbProtocol);
    if (EFI_ERROR(Status))
    {
      PmicUsbProtocol = NULL;
      CHARGER_DEBUG(( EFI_D_WARN, "ChargerLib:: %a Failed to open PMIC USB protocol Status = %r \r\n", __FUNCTION__, Status));
    }
  }

  if(PmicUsbProtocol)
  {*/
    /* PMi8998 auto powers on upon shutdown with Type-A to C cable attached */
    //Status |= PmicUsbProtocol->UsbCSetPortRole(EFI_PM_USB_TYPEC_ROLE_UFP);

    /* delay before shutting down in order to ensure that VBUS discharges well below the 1V coarse detect threshold accuracy. */
    //gBS->Stall(20000); //stall 20mS
  //}

  switch (ShutdownType)
  {
  case CHGAPP_RESET_SHUTDOWN:
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHGAPP_RESET_SHUTDOWN.\r\n", __FUNCTION__));
    ResetType = EfiResetShutdown;
    break;
  case CHGAPP_RESET_AFP:
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHGAPP_RESET_AFP.\r\n", __FUNCTION__));
    if (EFI_SUCCESS != ChargerLibTarget_EnableAfpMode())
    {
      /*if AFP not supported then enable USB as edge PON trigger and issue shut down */
      Status = ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_PON1_REDGE_PON, TRUE);
      Status |= ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_CBLPWR_FEDGE_PON, TRUE);

      ResetType = EfiResetCold;
    }
    break;
  case CHGAPP_RESET_COLD:
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHGAPP_RESET_COLD.\r\n", __FUNCTION__));
    ResetType = EfiResetCold;
    break;
  /* Ship mode is not supported on LA
  case CHGAPP_RESET_SHIPMODE:
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHGAPP_RESET_TO_SHIPMODE.\r\n", __FUNCTION__));
    if (EFI_SUCCESS != ChargerLibTarget_EnableShipMode())
    {
      *if Ship mode not supported then disable USB as PON trigger and issue shut down *
      if (NULL != PmicPwronProtocol)
      {
        Status |= PmicPwronProtocol->SetPonTrigger(PM_DEVICE_0, EFI_PM_PON_TRIGGER_DC_CHG, FALSE);
        Status |= PmicPwronProtocol->SetPonTrigger(PM_DEVICE_0, EFI_PM_PON_TRIGGER_USB_CHG, FALSE);
      }
      ResetType = EfiResetShutdown;
    }
    break;
  */

  case CHGAPP_RESET_SHUTDOWN_USB_DC_PON_DISABLED:
     /*Disable USB as PON trigger and issue shut down */
     Status = ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_PON1_REDGE_PON, TRUE);
     Status |= ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_CBLPWR_FEDGE_PON, TRUE);
     ResetType = EfiResetShutdown;
    break;
  case CHGAPP_RESET_NONE:
  case CHGAPP_RESET_INVALID:
  default:
    /*Do nothing*/
    return Status;
  }

  /* Reset  Device*/
  gRT->ResetSystem(ResetType, EFI_SUCCESS, 0, NULL);

  return Status;
}

EFI_STATUS ChargerLibTarget_GetThermalStatus( ChargerLibThermalStatus *ThermalStatus)
{
  EFI_STATUS Status = EFI_SUCCESS;
  INT32 CurrTemp = 0;
  STATIC ChargerLibThermalStatus ThermalSts = CHARGERLIB_THERMAL_INIT; /* Start with Init */
  if((NULL == PmicFgProtocol ) || (NULL == ThermalStatus))
    return EFI_DEVICE_ERROR;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = ChargerLibTarget_GetTSensTemp(&CurrTemp);
      if (Status != EFI_SUCCESS)
      {
        CHARGER_FILE_UART_DEBUG((EFI_D_WARN,"ChargerLib:: %a Failed = %r \r\n", __FUNCTION__, Status));
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_STATUS_MAX;/*Updated output params*/
        return Status;
      }
    break;

    default:
      Status = EFI_UNSUPPORTED;
      break;
  }
  /*  Handle if any Error */
  if(EFI_ERROR(Status))
    return Status;

  switch(ThermalSts)
  {
    case CHARGERLIB_THERMAL_INIT:
    case CHARGERLIB_THERMAL_OK:
      if (CurrTemp >= gChargerLibTargetCfgData.thermal_configs.tsens_extreme_Temp)
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_CRITICAL;/*Updated output params*/
      }
      else if (CurrTemp >= gChargerLibTargetCfgData.thermal_configs.tsens_high_temp )
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_HIGH;
      }
      else
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_OK;
      }
    break;

    case CHARGERLIB_THERMAL_HIGH:
      if (CurrTemp >= gChargerLibTargetCfgData.thermal_configs.tsens_extreme_Temp)
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_CRITICAL;/*Updated output params*/
      }
      else if ((CurrTemp > gChargerLibTargetCfgData.thermal_configs.tsens_low_temp) && (CurrTemp < gChargerLibTargetCfgData.thermal_configs.tsens_extreme_Temp))
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_HIGH;
      }
      else if (CurrTemp <= gChargerLibTargetCfgData.thermal_configs.tsens_low_temp)
      {
        *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_OK;
      }
      else
      {
        CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a Error = %d ThermalSts = %d \r\n", __FUNCTION__, CurrTemp, ThermalSts));
      }
    break;

    case CHARGERLIB_THERMAL_CRITICAL:
      /*should not hit this use case as it is already hanlded by then */
      *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_CRITICAL;/*Updated output params*/
    break;

    case CHARGERLIB_THERMAL_HIGH_TIMEOUT:
      /*should not hit this use case as it is already hanlded by then */
      *ThermalStatus = ThermalSts = CHARGERLIB_THERMAL_HIGH_TIMEOUT;/*Updated output params*/
    break;

    default:
    break;
  }

  CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a CurrTsensTemp = %d ThermalStatus = %d\r\n", __FUNCTION__, CurrTemp, *ThermalStatus));

  return Status;
}


EFI_STATUS ChargerLibTarget_GetTSensTemp( INT32 *TSensTemp)
{
  EFI_STATUS Status = EFI_SUCCESS;
  INT32 nTempDeciDegC = 0, nTempDegC = 0;

  STATIC EFI_TSENS_PROTOCOL *Tsens = NULL;

  if(NULL == Tsens)
  {
    Status = gBS->LocateProtocol(&gEfiTsensProtocolGuid, NULL, (VOID**)&Tsens);
    if (Status != EFI_SUCCESS)
    {
      CHARGER_FILE_UART_DEBUG((EFI_D_WARN,"ChargerLib:: %a TSENS Protocol Locate Failed %r \r\n", __FUNCTION__, Status));
      return Status;
    }
  }

  /* Loop if current temperature of device is greater than max */
  Status = Tsens->GetMaxTemp(&nTempDeciDegC);
  if (EFI_SUCCESS != Status)
  {
    CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a TSENS Protocol GetMaxTemp Failed = %r \r\n", __FUNCTION__, Status));
    /* break and exit to AFP ??*/
    return Status;
  }

  /*Temp is divide by 10 in C*/
  nTempDegC = nTempDeciDegC / 10;

  *TSensTemp  = nTempDegC;

  return Status;
}

EFI_STATUS ChargerLibTarget_DumpSram(BOOLEAN bDumpExplicit)
{
  EFI_STATUS    Status = EFI_SUCCESS;
  STATIC UINT32 pastTimeinS = 0;
  UINT32        CurrTimeinS = 0;
  STATIC EFI_QCOM_PMIC_RTC_PROTOCOL  *PmicRtcProtocol = NULL;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      if(!RETAIL)
      {
        if(gChargerLibTargetCfgData.fg_cfg_data.FgSramDbgCfg.DumpSram == TRUE)
        {
          if (NULL == PmicRtcProtocol)
          {
            Status = gBS->LocateProtocol(&gQcomPmicRtcProtocolGuid,
                                         NULL,
                                         (VOID **)&PmicRtcProtocol);
          }
          if (EFI_SUCCESS == Status && NULL!= PmicRtcProtocol)
          {
            Status |= PmicRtcProtocol->GetTimeValueRaw(PM_DEVICE_0, &CurrTimeinS);
          }
          CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a GetTimeValueRaw Status = %r CurrTimeinS = %d S pastTimeinS = %d S \r\n", __FUNCTION__, Status, CurrTimeinS, pastTimeinS));

          if(NULL == PmicFgProtocol)
            return EFI_DEVICE_ERROR;

          /* If call for explicit dump then dump immediately */
          if(TRUE == bDumpExplicit)
          {
            Status |= PmicFgProtocol->DumpFgSram(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex);
          }
          else if((CurrTimeinS - pastTimeinS) >= gChargerLibTargetCfgData.fg_cfg_data.FgSramDbgCfg.DumpSramDuration)
          {
            Status |= PmicFgProtocol->DumpFgSram(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex);
            pastTimeinS = CurrTimeinS; /* Update pastTime for next round */
          }
          else{ /* skip dumps as use case now */}
        }
        else
        {
          //CHARGER_DEBUG(( EFI_D_WARN, "PmicDxe:: %s Disabled \r\n",__FUNCTION__));
        }
      }
    break;

    default:
      Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_DumpChargerPeripheral()
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      if((TRUE == gChargerLibTargetCfgData.dbg_cfg_Data.enable_charger_fg_Dump ) && ( !RETAIL))
      {
        if( EFI_SUCCESS == Status )
        {
          if(NULL != PmicFgProtocol)
            Status = PmicFgProtocol->DumpPeripheral();

          if(NULL != PmicSchgProtocol)
            Status |= PmicSchgProtocol->DumpPeripheral();
        }
      }
    break;

    default:
      Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetHwJeitaStatus(CHARGERLIB_HW_JEITA_STATUS *pHwJeitaStatus)
{
  EFI_STATUS  Status = EFI_SUCCESS;
  EFI_PM_SCHG_BATT_TEMP_STATUS HwJeitaStatus = { 0 };

  if (!pHwJeitaStatus)
    return EFI_INVALID_PARAMETER;

  if (!gProfileLoadCalled)
    return EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status |= PmicSchgProtocol->GetHwJeitaStatus(ChargerInfo.ChargerPmicInfo.PmicIndex, &HwJeitaStatus);
    break;

  default:
    break;
  }

  if (Status == EFI_SUCCESS)
  {
    pHwJeitaStatus->JeitaHardHot = HwJeitaStatus.jeitaHardHot;
    pHwJeitaStatus->JeitaSoftHot = HwJeitaStatus.jeitaSoftHot;
    pHwJeitaStatus->JeitaHardCold = HwJeitaStatus.jeitaHardCold;
    pHwJeitaStatus->JeitaSoftCold = HwJeitaStatus.jeitaSoftCold;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetBatteryTempStatus(CHARGERLIB_BATT_TEMP_STATUS *pBattTempStatus)
{
  //Battery temperature outside of operational range, extreme cold or hot condition (below -15 , above 70 degree, configurable) (AFP) -- BatteryTemperatureOutOfRangeError
  EFI_STATUS Status      = EFI_SUCCESS;
  CHARGERLIB_HW_JEITA_STATUS   HwJeitaStatus = {0};
  chargerlib_batt_status_info  BatteryStatus = {0};

  if (!pBattTempStatus)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pBattTempStatus = ChargerLib_Batt_Temp_Normal;

  Status = ChargerLibTarget_GetBatteryStatus(&BatteryStatus);
  if(EFI_SUCCESS != Status )
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib::%a Error getting battery status = %r \r\n", __FUNCTION__, Status));
    return Status;
  }
  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib::%a BatteryTemp = %d C \r\n", __FUNCTION__, BatteryStatus.BatteryTemperature));

  Status = ChargerLibTarget_GetHwJeitaStatus( &HwJeitaStatus );
  if((TRUE == HwJeitaStatus.JeitaHardCold) || (TRUE == HwJeitaStatus.JeitaHardHot))
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib::%a BatteryTemp out-of-range = %d C \r\n",__FUNCTION__, BatteryStatus.BatteryTemperature));
    *pBattTempStatus = ChargerLib_Batt_Temp_OutsideChargingRange;
  }

  if(( BatteryStatus.BatteryTemperature < gChargerLibTargetCfgData.fg_cfg_data.HwJeitaThreshold.JeitaCriticalTempLowLimit) ||
     ( BatteryStatus.BatteryTemperature > gChargerLibTargetCfgData.fg_cfg_data.HwJeitaThreshold.JeitaCriticalTempHighLimit))
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a BatteryTemp = %d C, Operational Range lower limit = %d, upper limit = %d \r\n",
                __FUNCTION__, BatteryStatus.BatteryTemperature, gChargerLibTargetCfgData.fg_cfg_data.HwJeitaThreshold.JeitaCriticalTempLowLimit,
                  gChargerLibTargetCfgData.fg_cfg_data.HwJeitaThreshold.JeitaCriticalTempHighLimit));

    *pBattTempStatus = ChargerLib_Batt_Temp_OutsideOperationalRange;
  }

  if(EFI_SUCCESS != Status)
  {
    *pBattTempStatus = ChargerLib_Batt_Temp_Invalid;
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib::%a BatteryTemp invalid = %r \r\n",__FUNCTION__, Status));
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetBatteryVoltageStatus(CHARGERLIB_VBATT_STATUS *pBatteryVoltageStatus)
{
  EFI_STATUS                   Status      = EFI_SUCCESS;
  STATIC UINT32                EmergencyShutdownCounter = 0;
  chargerlib_batt_status_info  BatteryStatus = {0};

  if (!pBatteryVoltageStatus)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pBatteryVoltageStatus = ChargerLib_VBatt_Normal;

  Status = ChargerLibTarget_GetBatteryStatus(&BatteryStatus);
  if( EFI_SUCCESS != Status )
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting battery status = %r \r\n", __FUNCTION__, Status));
    return Status;
  }

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Battery voltage = %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage));

  /* Return status if vbatt is good */
  if ((UINT32)BatteryStatus.BatteryVoltage > (gChargerLibTargetCfgData.schg_cfg_data.ChgFvMax + gChargerLibTargetCfgData.batt_volt_lim_high_delta))
  {
    EmergencyShutdownCounter = 0;

    Status = ChargerLibTarget_GetBatteryStatus(&BatteryStatus);
    if( EFI_SUCCESS != Status )
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting battery status = %r \r\n", __FUNCTION__, Status));
      return Status;
    }

    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Current Battery voltage =  %d mV \r\n", __FUNCTION__, BatteryStatus.BatteryVoltage));

    /* Check for High Voltage Limit */
    if (((UINT32)(BatteryStatus.BatteryVoltage - VBATT_TOLERANCE)) > (gChargerLibTargetCfgData.schg_cfg_data.ChgFvMax + gChargerLibTargetCfgData.batt_volt_lim_high_delta))
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Current Battery voltage too high %d mV, Threshold = %d mV  \r\n", __FUNCTION__,
                                BatteryStatus.BatteryVoltage, (gChargerLibTargetCfgData.schg_cfg_data.ChgFvMax + gChargerLibTargetCfgData.batt_volt_lim_high_delta)));
      *pBatteryVoltageStatus = ChargerLib_VBatt_TooHigh;
    }
  }
  /* Check for vbatt below emergency shutdown limit */
  else if ((UINT32)BatteryStatus.BatteryVoltage < gChargerLibTargetCfgData.emergency_shutdown_vbatt)
  {
    if(BatteryStatus.ChargeCurrent > 0) /* Battery is discharging */
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Current BattVoltage = %d mV is below EmergencyShutdownVbatt = %d mV ", __FUNCTION__,
                    BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.emergency_shutdown_vbatt));
    CHARGER_DEBUG((EFI_D_WARN, " EmergencyShutdownCounter = %d \r\n", EmergencyShutdownCounter));
      if(EmergencyShutdownCounter >= MAX_EMERGENCY_SHUTDOWN_COUNT)
      {
        *pBatteryVoltageStatus = ChargerLib_VBatt_BelowThreshold;
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a EmergencyShutdownCounter Exceeded : \r\n", __FUNCTION__ ));
    CHARGER_DEBUG((EFI_D_WARN, " Curr Battery voltage = %d mV is below threshold = %d mV \r\n",
          BatteryStatus.BatteryVoltage, gChargerLibTargetCfgData.emergency_shutdown_vbatt ));
      }
      else
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a EmergencyShutdownCounter = %d \r\n", __FUNCTION__, EmergencyShutdownCounter));
      }
      EmergencyShutdownCounter++;
    }
    else
    {
      EmergencyShutdownCounter = 0;
    }
  }
  else
  {
    EmergencyShutdownCounter = 0;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_EnableHWJeita(BOOLEAN Enable)
{
  EFI_STATUS Status = EFI_SUCCESS;

  /* For 8250, HW Jeita will be enabled from PmicDxe after battery therm (from profile) is read.
     Battery profile contains batt therm pull-up, which is required for converting JEITA thresholds
     from degree C to ADC code based on batt therm pull-up */

  return Status;
}

EFI_STATUS ChargerLibTarget_GetSdpMaxCurrent(UINT32 *pSdpMaxCurrent)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_USBFN_CHG_SRV_SPEED_TYPE                SdpSpeed = USB_CHG_SPD_UNKNOWN;

  if(NULL == pSdpMaxCurrent)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pSdpMaxCurrent = USB_2_IUSB_MAX;

  if (!UsbInitProtocol)
  {
    Status = gBS->LocateProtocol(&gEfiUsbInitProtocolGuid, NULL, (VOID **)&UsbInitProtocol);
  }

  if (!UsbChgSrvProtocol)
  {
    Status |= gBS->LocateProtocol(&gEfiUsbfnChgSrvProtocolGuid, NULL, (VOID **)&UsbChgSrvProtocol);
  }

  if((EFI_SUCCESS == Status) && (NULL != UsbInitProtocol) && (NULL != UsbChgSrvProtocol))
  {
    if((FALSE == gStartControllerCalled))
    {
      Status |= UsbInitProtocol->StartController(UsbInitProtocol, 0, EFI_USB_PERIPHERAL_MODE);

      Status |= UsbChgSrvProtocol->StartController(UsbChgSrvProtocol);

      if(EFI_SUCCESS == Status)
      {
        /* Store Enumeration done state, since we will need to call StopController in case of any error and charger swap*/
        gStartControllerCalled = TRUE;
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a success from StartController API, Status: %r \r\n", __FUNCTION__, Status));
      }
      else
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a error from StartController API, Status: %r \r\n", __FUNCTION__, Status));
      }
    }
    else
    {
      WaitForTimeoutNoKey (USB_ENUM_WAIT_DURATION);
    }

    Status |= UsbChgSrvProtocol->GetSpeed(UsbChgSrvProtocol, &SdpSpeed);
    if(EFI_SUCCESS == Status)
    {/*If Status is not success, SDP */
      if(USB_CHG_SPD_SUPER == SdpSpeed)
      {
        *pSdpMaxCurrent = USB_3_IUSB_MAX;
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHARGERLIB_CHG_PORT_SDP_CHARGER 3.0 Detected, ChargerCurrent = %d mA \r\n", __FUNCTION__, *pSdpMaxCurrent));
        return Status;
      }
    }
    else
    {
       CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a error getting SDP Speed, Status: : %r \r\n", __FUNCTION__, Status));
    }
  }
  else
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a error locating UsbChgSrv Protocol, Status: : %r \r\n", __FUNCTION__, Status));
    /*if the protocol is not supported, we will fall back to USB2.0 and return SUCCESS*/
    Status = EFI_SUCCESS;
  }

  *pSdpMaxCurrent = USB_2_IUSB_MAX;
  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a CHARGERLIB_CHG_PORT_SDP_CHARGER 2.0 Detected, ChargerCurrent = %d mA \r\n", __FUNCTION__, *pSdpMaxCurrent));

  return Status;
}


EFI_STATUS ChargerLibTarget_GetChgWdogStatus( CHARGERLIB_CHG_WDOG_STS_TYPE *pChgWdogSts)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if(NULL == pChgWdogSts)
    return EFI_INVALID_PARAMETER;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      /* Locate SCHG Protocol */
      if (!PmicSchgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicSchgProtocolGuid,
                                      NULL,
                                     (VOID **)&PmicSchgProtocol );
      }

      if((EFI_SUCCESS == Status) && (NULL != PmicSchgProtocol))
      {
        Status = PmicSchgProtocol->GetChgWdogStatus(ChargerInfo.ChargerPmicInfo.PmicIndex, (EFI_PM_SCHG_WDOG_STS_TYPE *)pChgWdogSts);
      }
      break;
    default:
      return EFI_UNSUPPORTED;
      break;

  }

  return Status;
}

EFI_STATUS ChargerLibTarget_InitializeCharging( VOID )
{
  EFI_STATUS Status = EFI_SUCCESS;
  CHARGERLIB_CHG_WDOG_STS_TYPE  ChgWdogSts = CHARGERLIB_CHG_WDOG_STS_INVALID;
  EFI_SCHG_HVDCP_CFGDATA_TYPE pSchgHvdcpDataType = {0};
  pSchgHvdcpDataType.bEnHvdcp = FALSE;

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Entry \r\n", __FUNCTION__));

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      if (!PmicSchgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicSchgProtocolGuid,
                                       NULL,
                                      (VOID **)&PmicSchgProtocol );
      }

      if((EFI_SUCCESS != Status) || (NULL == PmicSchgProtocol))
      {
        return EFI_UNSUPPORTED;
      }
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  Status = PmicSchgProtocol->ConfigHvDcp(PM_DEVICE_1, &pSchgHvdcpDataType);

  /* Disable HVDCP or QC 2.0 3.0 detection in UEFI */
  if(Status != EFI_SUCCESS)
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Disable HVDCP failed %r \r\n", __FUNCTION__, Status));
  }

  Status = ChargerLibTarget_GetChgWdogStatus(&ChgWdogSts);
  if((EFI_SUCCESS == Status) && (CHARGERLIB_CHG_WDOG_STS_BITE_CHARGING_DISABLED == ChgWdogSts))
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a WDOG Bite happened, Toggling charging command to re-enable charging. \r\n", __FUNCTION__));
    Status = PmicSchgProtocol->SetChargeCmdBit(PM_DEVICE_1, FALSE);
    if(EFI_SUCCESS == Status)
    gChargingEnabled = FALSE;
  }

  /* Set USB ICL mode and Re-Run APSD if needed on UEFI Charging */
  Status |= ChargerLibTarget_ConfigureUsbCurrentSetting();

  if( FALSE == gChargingEnabled )
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Enabling charging \r\n", __FUNCTION__));
    Status |= ChargerLibTarget_ChargerEnable(TRUE);
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_EnableWdog(BOOLEAN Enable)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->EnableChgWdog(ChargerInfo.ChargerPmicInfo.PmicIndex, Enable);
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_PetChgWdog( VOID )
{
  EFI_STATUS Status = EFI_SUCCESS;
  CHARGERLIB_CHG_WDOG_STS_TYPE ChgWdogSts;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      Status = PmicSchgProtocol->PetChgWdog(ChargerInfo.ChargerPmicInfo.PmicIndex);
      Status |= PmicSchgProtocol->GetChgWdogStatus(ChargerInfo.ChargerPmicInfo.PmicIndex, (EFI_PM_SCHG_WDOG_STS_TYPE *)&ChgWdogSts);

      if ( Status == EFI_SUCCESS && ChgWdogSts == CHARGERLIB_CHG_WDOG_STS_BITE_CHARGING_DISABLED )
      {
        Status = PmicSchgProtocol->SetChargeCmdBit(ChargerInfo.ChargerPmicInfo.PmicIndex, FALSE);
        Status |= PmicSchgProtocol->SetChargeCmdBit(ChargerInfo.ChargerPmicInfo.PmicIndex, TRUE);

        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Charger Wdog bites, toggling charging cmd to re-enable charger, Status = %r\n",__FUNCTION__, Status));
      }
      break;
    default:
      Status = EFI_UNSUPPORTED;
      break;
  }

  return Status;
}

/**
  Charger Lib Exit

  @return
  EFI_SUCCESS:           Function returned successfully.
  EFI_DEVICE_ERROR:      The physical device reported an error.
  EFI_UNSUPPORTED:       No Library function linked
*/
EFI_STATUS ChargerLibTarget_Exit( VOID )
{
  EFI_STATUS     Status      = EFI_SUCCESS;

  switch (BatteryGaugeInfo.BatteryGaugeHW)
  {
    case EfiBatteryGaugeQcomPmicFg:
      if(!RETAIL)
      {
        if(gChargerLibTargetCfgData.dbg_cfg_Data.enable_charger_fg_Dump)
          ChargerLibTarget_DumpChargerPeripheral();
      }

      /* Explicit dump during exit */
      ChargerLibTarget_DumpSram(TRUE);

      if(NULL != PmicFgProtocol)
      {
        Status  = PmicFgProtocol->FgBasicExit(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex);
          Status |= PmicFgProtocol->FgExtendedExit(BatteryGaugeInfo.BatteryGaugePmicInfo.PmicIndex);
        }
      if(NULL != PmicSchgProtocol)
      {
        Status = PmicSchgProtocol->SchgExit(ChargerInfo.ChargerPmicInfo.PmicIndex);
      }
        /* Turn Off Charging Led */
      if(gChargerLibTargetCfgData.charger_led_config)
      {
        /* Make sure to Turn Off LED during exit */
        ChargerLibTarget_LedOn(FALSE);
      }
      /* This is to make sure wdog actions are taken in terms of charger app skips charging as SBL have enabled charger wdog */
      if(CHARGERLIB_CHG_WDOG_LEAVE_ENABLED_ON_EXIT == gChargerLibTargetCfgData.enable_charger_wdog)
      { //Pet the watchdog if feature is enabled, before booting to HLOS
        ChargerLibTarget_PetChgWdog();
      }
      else
      { /* Disable Charger Watchdog before booting to HLOS*/
        ChargerLibTarget_EnableWdog( FALSE );
      }

    break;

    default:
      Status = EFI_UNSUPPORTED;
    break;
  }

  if(TRUE == gStartControllerCalled)
  {
    if (!UsbChgSrvProtocol)
    {
      Status |= gBS->LocateProtocol(&gEfiUsbfnChgSrvProtocolGuid, NULL, (VOID **)&UsbChgSrvProtocol);
    }

    Status |= UsbChgSrvProtocol->StopController(UsbChgSrvProtocol);

    if (!UsbInitProtocol)
    {
      Status |= gBS->LocateProtocol(&gEfiUsbInitProtocolGuid, NULL, (VOID **)&UsbInitProtocol);
    }

    Status |= UsbInitProtocol->StopController(UsbInitProtocol, 0, EFI_USB_PERIPHERAL_MODE);

    if(EFI_SUCCESS != Status)
    {
      CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error checking Charger re-insertion status, Status: 0x%08X\n",__FUNCTION__, Status));
    }

    gStartControllerCalled = FALSE;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_GetChargingStatus(BOOLEAN *pChargingEnabled)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_SCHG_CHARGING_STATUS ChargingSts = {0};

  if(!pChargingEnabled)
    return EFI_INVALID_PARAMETER;

  *pChargingEnabled = FALSE;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      /* Locate SCHG Protocol */
      if (!PmicSchgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicSchgProtocolGuid,
                                      NULL,
                                     (VOID **)&PmicSchgProtocol );
      }

      if((EFI_SUCCESS == Status ) && (NULL != PmicSchgProtocol))
      {
        Status |= PmicSchgProtocol->GetChargingStatus(ChargerInfo.ChargerPmicInfo.PmicIndex, &ChargingSts);
      }
      if(EFI_SUCCESS == Status )
      {
        *pChargingEnabled = ChargingSts.bChargingEnabled;
      }
      break;

    default:
      break;
  }
  return Status;
}

EFI_STATUS ChargerLibTarget_PrintDCInStatus()
{
  EFI_STATUS Status = EFI_SUCCESS;
  EfiAdcResultType AdcResult = { 0 };

  Status = ChargerLibTarget_GetADCReading(ADC_INPUT_DC_IN, sizeof(ADC_INPUT_DC_IN), &AdcResult);

  if (EFI_ERROR(Status))
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: Failed to get ADC reading from ADC_INPUT_DC_IN!\n", __FUNCTION__));
    return Status;
  }

  CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: DCInVoltage = %d\n", __FUNCTION__, AdcResult.nPhysical));

  Status = ChargerLibTarget_GetADCReading(ADC_INPUT_DC_IN_I, sizeof(ADC_INPUT_DC_IN_I), &AdcResult);
  if (EFI_ERROR(Status))
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: Failed to get ADC reading from ADC_INPUT_DC_IN_I!\n", __FUNCTION__));
    return Status;
  }

  CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: DCInCurrent = %d\n", __FUNCTION__, AdcResult.nPhysical));
  return Status;
}

EFI_STATUS ChargerLibTarget_GetADCReading(CONST CHAR8 *pszInputName, UINT32 uInputNameSize, EfiAdcResultType *pEfiAdcResult)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EfiAdcDeviceChannelType channel;

  if (NULL == pszInputName || NULL == pEfiAdcResult)
  {
    return EFI_INVALID_PARAMETER;
  }

  if (!AdcProtocol)
  {
    Status = gBS->LocateProtocol(&gEfiAdcProtocolGuid,
      NULL,
      (VOID**)&AdcProtocol);
  }

  if ((EFI_ERROR(Status)) || (NULL == AdcProtocol))
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: Failed to load ADC Protocol!\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  Status = AdcProtocol->GetChannel(pszInputName, uInputNameSize, &channel);
  if (EFI_ERROR(Status))
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: Failed to get ADC Channel!\n", __FUNCTION__ ));
    return EFI_DEVICE_ERROR;
  }

  Status = AdcProtocol->AdcRead(&channel, pEfiAdcResult);
  if ((EFI_ERROR(Status)) || (EFI_ADC_RESULT_INVALID == pEfiAdcResult->eStatus))
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a: Failed to read ADC Channel!\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_SetUSbICLMode(CHARGERLIB_USB_ICL_MODE_TYPE IclModeType)
{
  EFI_STATUS Status = EFI_SUCCESS;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      /* Locate SCHG Protocol */
      if (!PmicSchgProtocol)
      {
        Status |= gBS->LocateProtocol( &gQcomPmicSchgProtocolGuid,
                                      NULL,
                                     (VOID **)&PmicSchgProtocol );
      }

      if( EFI_SUCCESS == Status )
      {
        Status = PmicSchgProtocol->SetUsbIclMode(ChargerInfo.ChargerPmicInfo.PmicIndex, (EFI_PM_SCHG_USB_ICL_MODE_TYPE) IclModeType);
      }
      break;
    default:
      break;
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_ConfigureUsbCurrentSetting( VOID )
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINT32     MaxCurrent = 0;
  CHARGERLIB_CHGR_PORT_TYPE PortType = CHARGERLIB_CHG_PORT_INVALID;
  CHARGERLIB_USB_ICL_MODE_TYPE IclModeType = CHARGERLIB_USB_ICL_MODE_INVALID;
  CHARGERLIB_CHG_USBC_SINK_TYPE UsbcSinkType = CHARGERLIB_CHG_USBC_SINK_NONE;

  Status = ChargerLibTarget_GetUsbcPortType(&UsbcSinkType);
  Status |= ChargerLibTarget_GetPortType(&PortType);

  if(EFI_SUCCESS == Status)
  {
    if(CHARGERLIB_CHG_PORT_SDP_CHARGER == PortType)
    {
      Status = ChargerLibTarget_GetSdpMaxCurrent(&MaxCurrent);
    if (USB_3_IUSB_MAX == MaxCurrent)
    {
      IclModeType = CHARGERLIB_USB_ICL_MODE_SDP_3_0;
    }
    else
    {
      IclModeType = CHARGERLIB_USB_ICL_MODE_SDP_2_0;
    }
    }
    else
    {
      IclModeType = CHARGERLIB_USB_ICL_MODE_WALL_CHARGERS;
    }
  }

  CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a Setting ICL MOde to:  %d \r\n", __FUNCTION__, IclModeType));
  Status = ChargerLibTarget_SetUSbICLMode(IclModeType);

  if(Status != EFI_SUCCESS)
  {
    CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a Failed to configure ICL\r\n", __FUNCTION__));
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_LedOn( BOOLEAN bLedOn)
{
  EFI_STATUS Status = EFI_SUCCESS;
  STATIC EFI_QCOM_PMIC_RGB_LED_PROTOCOL *PmicRgbLedProtocol = NULL;
  static BOOLEAN ledOnStatus = FALSE;

  switch (ChargerInfo.ChargerHW)
  {
    case EfiBatteryChargerQcomPmicSchg:
      if (!PmicRgbLedProtocol)
      {
        Status = gBS->LocateProtocol(&gQcomPmicRgbLedProtocolGuid, NULL, (VOID **)&PmicRgbLedProtocol);
      }
      if ((Status != EFI_SUCCESS) || (NULL == PmicRgbLedProtocol))
      {
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Protocol Failed = %r \r\n", __FUNCTION__, Status));
        return EFI_DEVICE_ERROR;
      }
      if (bLedOn == TRUE)
      {
        /* Check if LED has already been turned on */
        if (ledOnStatus != bLedOn)
        {
          /* Change Led state irrespective of charging status called to make sure of charging status */
          Status |= PmicRgbLedProtocol->ConfigRgbLed(PM_DEVICE_2, EFI_PM_RGB_1, EFI_PM_RGB_LED_RED, EFI_PM_RGB_DIM_LEVEL_MID, bLedOn);
          /*  Handle if any Error */
          if (Status != EFI_SUCCESS)
          {
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed = %r \r\n", __FUNCTION__, Status));
            return Status;
          }
          else
          {
            ledOnStatus = TRUE;
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a LED TURNED ON = %r \r\n", __FUNCTION__, Status));
          }
        }
      }
      else
      {
        /* Turn OFF LED irrespective of charging status */
        Status |= PmicRgbLedProtocol->ConfigRgbLed(PM_DEVICE_2, EFI_PM_RGB_1, EFI_PM_RGB_LED_RED, EFI_PM_RGB_DIM_LEVEL_MID, bLedOn);
        /*  Handle if any Error */
        if (Status != EFI_SUCCESS)
        {
          CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Failed = %r \r\n", __FUNCTION__, Status));
          return Status;
        }
        else
        {
          ledOnStatus = FALSE;
          CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a LED TURNED OFF = %r \r\n", __FUNCTION__, Status));
        }
      }
      break;

    default:
      Status = EFI_UNSUPPORTED;
    break;
  }
  return Status;
}

EFI_STATUS ChargerLibTarget_SetDcinCurrent(UINT32 DcinCurrentInmA)
{
  EFI_STATUS Status = EFI_SUCCESS;

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a ChargerLib Current = %d mA\r\n", __FUNCTION__, DcinCurrentInmA));

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    Status = PmicSchgProtocol->SetDcinCurrent(ChargerInfo.ChargerPmicInfo.PmicIndex, DcinCurrentInmA);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  return Status;
}

EFI_STATUS ChargeLibTarget_IsDcinValid(BOOLEAN* pIsValid)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if (!pIsValid)
  {
    return EFI_INVALID_PARAMETER;
  }

  if (!PmicSchgProtocol)
  {
    Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid,
      NULL,
      (VOID **)&PmicSchgProtocol);

    if((Status != EFI_SUCCESS) || (NULL == PmicSchgProtocol ))
    {
      CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a pmicSchgProtocol Failed = %r \r\n", __FUNCTION__, Status));
      return EFI_DEVICE_ERROR;
    }
  }

  Status = PmicSchgProtocol->DcinValid(ChargerInfo.ChargerPmicInfo.PmicIndex, pIsValid);

  return Status;
}


void ChargerLibTarget_HWInit(chargerlib_cfgdata_type *pChargerLibConfig)
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINT32  plat_index = 0;
  CHARGERLIB_PLATFORM_HW_CONFIG_TYPE config_index = CHARGERLIB_PLATFORM_HW_CONFIG_INVALID;
  UINT32  HwInfoSize = (UINT32)(sizeof(ChargerLibPlatformHwInfo)/sizeof(CHARGERLIB_PLATFORM_HW_CONFIG_INFO));

  //Initialize Charger and Battery GaugeInfo
  ChargerInfo.ChargerHW           = EfiBatteryChargerNone;
  ChargerInfo.Version             = 0x00010000;
  BatteryGaugeInfo.BatteryGaugeHW = EfiBatteryGaugeNone;
  BatteryGaugeInfo.Version        = 0x00010000;

  //Read Flag from Config Item to see if we need override the setting
  if (pChargerLibConfig->plat_hw_cfg_override < CHARGERLIB_PLATFORM_HW_CONFIG_INVALID)
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Charger PlatHWConfig = %d, (overrided by CFG item)\r\n",
                   __FUNCTION__, pChargerLibConfig->plat_hw_cfg_override));

    config_index = pChargerLibConfig->plat_hw_cfg_override;

    ChargerInfo.ChargerHW =           ChargerLibHwConfigTable[config_index].charger_hw_type;
    ChargerInfo.Version =             ChargerLibHwConfigTable[config_index].charger_hw_version;
    BatteryGaugeInfo.BatteryGaugeHW = ChargerLibHwConfigTable[config_index].gauge_hw_type;
    BatteryGaugeInfo.Version        = ChargerLibHwConfigTable[config_index].gauge_hw_version;
  }
  else
  {
    //Assign HWInfo Type based on the table
    for (plat_index = 0; plat_index < HwInfoSize; plat_index++)
    {
      if (ChargerLibPlatformHwInfo[plat_index].PlatformType == PlatformType)
      {
        //Execute HW Config Detect Function if available
        if (ChargerLibPlatformHwInfo[plat_index].pHwConfigDetectFunc != NULL)
        {
          Status = ChargerLibPlatformHwInfo[plat_index].pHwConfigDetectFunc(&ChargerInfo, &BatteryGaugeInfo);
          if (EFI_SUCCESS != Status)
          {
              CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a ERROR: Platform HW detection function failed %r \r\n",
                   __FUNCTION__, Status));
          }
        }
        //Else, perform static assignment
        else
        {
          config_index = ChargerLibPlatformHwInfo[plat_index].StaticHwConfigIndex;
          if (config_index < CHARGERLIB_PLATFORM_HW_CONFIG_INVALID)
          {
            ChargerInfo.ChargerHW =           ChargerLibHwConfigTable[config_index].charger_hw_type;
            ChargerInfo.Version =             ChargerLibHwConfigTable[config_index].charger_hw_version;
            BatteryGaugeInfo.BatteryGaugeHW = ChargerLibHwConfigTable[config_index].gauge_hw_type;
            BatteryGaugeInfo.Version        = ChargerLibHwConfigTable[config_index].gauge_hw_version;
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a PlatformType = %d has Static PlatHWConfig = %d \r\n",
                           __FUNCTION__, PlatformType, config_index));
          }
          else
          {
            CHARGER_DEBUG((EFI_D_ERROR, "ChargerLib:: %a ERROR: Invalid Static Platform HW assignment \r\n",
                           __FUNCTION__, Status));
          }
        }
        break;
      }
    }
  }

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a PlatformType = %d: ChargerHW = %d, GaugeHW = %d \r\n",
                 __FUNCTION__, PlatformType, ChargerInfo.ChargerHW, BatteryGaugeInfo.BatteryGaugeHW));

  return;
}

EFI_STATUS ChargerLibTarget_IsChargingSupported(BOOLEAN *pChargingSupported)
{
  EFI_STATUS Status = EFI_SUCCESS;
  //Checking Configuration
  if ((EfiBatteryChargerNone == ChargerInfo.ChargerHW) ||
      (EfiBatteryGaugeNone == BatteryGaugeInfo.BatteryGaugeHW))
  {
    *pChargingSupported = FALSE;
  }
  else
  {
    *pChargingSupported = TRUE;
  }
  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a PlatformType = %d: ChargerHW = %d, GaugeHW = %d \r\n",
                 __FUNCTION__, PlatformType, ChargerInfo.ChargerHW, BatteryGaugeInfo.BatteryGaugeHW));

  //Add HW Validation here in the future

  CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Support Charging = %d\r\n", __FUNCTION__, *pChargingSupported));
  return Status;
}


EFI_STATUS ChargerLibTarget_SetPon1Trigger(EFI_PM_PON_OPTION_BIT_TYPE bit_type, BOOLEAN bFlag )
{
  EFI_STATUS Status = EFI_SUCCESS;

  /* Enable USB and DCIN PON triggers to be certain and avoid bad use case*/
  if (!PmicPwronProtocol)
  {
    Status |= gBS->LocateProtocol(&gQcomPmicPwrOnProtocolGuid, NULL, (VOID **)&PmicPwronProtocol);
  }

  if((Status == EFI_SUCCESS) && (NULL != PmicPwronProtocol))
  {
    Status |= PmicPwronProtocol->EnableEdgePonTrigger(PM_DEVICE_0, bit_type, bFlag);
  }
  else
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error locating Pwron Protocol = %r \r\n", __FUNCTION__, Status));
  }

  return Status;
}

EFI_STATUS ChargerLibTarget_DAMConnectSts(BOOLEAN *DAMConnectSts)
{
    EFI_STATUS Status = EFI_SUCCESS;

    if (!DAMConnectSts)
    {
        return EFI_INVALID_PARAMETER;
    }

    if (!PmicSchgProtocol)
    {
        Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid,
            NULL,
            (VOID **)&PmicSchgProtocol);
        if ((Status != EFI_SUCCESS) || (NULL == PmicSchgProtocol))
        {
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a pmicSchgProtocol Failed = %r \r\n", __FUNCTION__, Status));
            return EFI_DEVICE_ERROR;
        }
    }

    Status |= PmicSchgProtocol->GetDAMConnectSts(ChargerInfo.ChargerPmicInfo.PmicIndex, DAMConnectSts);
    return Status;
}

EFI_STATUS ChargerLibTarget_GetErrorAction( CHARGERLIB_CHARGING_ERROR_TYPES  ChargingErrorType, CHARGERLIB_ERROR_ACTION_TYPE *pErrorAction)
{
  EFI_STATUS  Status = EFI_SUCCESS;
  chargerlib_batt_status_info BatteryStatus = {0};

  if(!pErrorAction)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pErrorAction = CHARGERLIB_ERROR_ACTION_NONE;

  Status = ChargerLib_GetBatteryStatus(&BatteryStatus);
  if( EFI_SUCCESS != Status )
  {
    CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Error getting battery status = %r \r\n", __FUNCTION__, Status));
    return Status;
  }

  switch (ChargingErrorType)
  {
    case CHARGERLIB_CHARGING_ERROR_NONE:
    case CHARGERLIB_CHARGING_ERROR_TSENSE_OK:
        /* No Action just continue */
        break;
    case CHARGERLIB_CHARGING_ERROR_TSENSE_CRITICAL:
        // case ChargerLib_ChargingError_TsensCritical:
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_TSENS_CRITICAL_SYMBOL;
    case CHARGERLIB_CHARGING_ERROR_BATT_TEMP_OUTSIDE_OPERATIONAL_RANGE:
        *pErrorAction = CHARGERLIB_ERROR_ACTION_CRITICAL_SHUTDOWN;
        break;
    case CHARGERLIB_CHARGING_ERROR_BATTERY_NOT_DETECTED:
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_NOBATTERY;
        *pErrorAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
        break;
    case CHARGERLIB_CHARGING_ERROR_LOW_VBATT:
        /* Emergency Low VBatt shutdown */
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_NOBATTERY;
        *pErrorAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN_USB_DC_PON_DISABLED;
        break;
    case CHARGERLIB_CHARGING_ERROR_TSENSE_TIMEOUT:
        gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_TSENS_THERMAL_SYMBOL;
    case CHARGERLIB_CHARGING_ERROR_ADC_ERROR:
    case CHARGERLIB_CHARGING_ERROR_FG_ERROR:
    case CHARGERLIB_CHARGING_ERROR_VBATT_OUTSIDE_RANGE:
    case CHARGERLIB_CHARGING_ERROR_CHARGING_TIMEOUT:
    case CHARGERLIB_DEVICE_ERROR:
        *pErrorAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
        break;
    case CHARGERLIB_CHARGING_ERROR_CHARGING_SOURCE_NOT_DETECTED:
        if(gChargerLibTargetCfgData.soc_based_boot == TRUE)
        {
          if(BatteryStatus.StateOfCharge < gChargerLibTargetCfgData.boot_to_hlos_threshold_in_soc)
          {
            gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_NOCHARGER;
            *pErrorAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
          }
          else
          {//if already reached threshold,it's not an error and goot to boot
            *pErrorAction = CHARGERLIB_ERROR_ACTION_GOOD_TO_BOOT;
          }
        }
        else
        {
          if(BatteryStatus.BatteryVoltage < gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv)
          {
            gDispImage = CHARGERLIB_EVENT_DISP_IMAGE_NOCHARGER;
            *pErrorAction = CHARGERLIB_ERROR_ACTION_SHUTDOWN;
          }
          else
          {//if already reached threshold,it's not an error and goot to boot
            *pErrorAction = CHARGERLIB_ERROR_ACTION_GOOD_TO_BOOT;
          }
        }
        break;
    case CHARGERLIB_CHARGING_ERROR_BATT_TEMP_OUTSIDE_CHARGING_RANGE:
        if(gChargerLibTargetCfgData.soc_based_boot == TRUE)
        {
          if(BatteryStatus.StateOfCharge < gChargerLibTargetCfgData.boot_to_hlos_threshold_in_soc)
          {
            *pErrorAction = CHARGERLIB_ERROR_ACTION_NO_CHARGE_WAIT;
          }
          else
          {//if already reached threshold,it's not an error and goot to boot
            *pErrorAction = CHARGERLIB_ERROR_ACTION_GOOD_TO_BOOT;
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Temp outside charging range good soc boot to hlos \r\n", __FUNCTION__));
          }
        }
        else
        {
          if(BatteryStatus.BatteryVoltage < gChargerLibTargetCfgData.boot_to_hlos_threshold_in_mv)
          {
            *pErrorAction = CHARGERLIB_ERROR_ACTION_NO_CHARGE_WAIT;
          }
          else
          {//if already reached threshold,it's not an error and goot to boot
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a Temp outside charging range good vbatt boot to hlos \r\n", __FUNCTION__));
            *pErrorAction = CHARGERLIB_ERROR_ACTION_GOOD_TO_BOOT;
          }
        }
        break;
    case CHARGERLIB_CHARGING_ERROR_TSENSE_HIGH:
        *pErrorAction = CHARGERLIB_ERROR_ACTION_TSENSE_HIGH_WAIT;
        break;
    case CHARGERLIB_CHARGING_ERROR_DEBUG_BOARD:
        Status = ChargerLibTarget_GetDebugBoardAction(pErrorAction);
        break;
    case CHARGERLIB_CHARGING_ERROR_UNKNOWN_BATTERY:
        Status = ChargerLibTarget_GetUnknownBatteryAction(pErrorAction);
        break;
     default:
        *pErrorAction = CHARGERLIB_ERROR_ACTION_STOP_CHARGING;
        CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a default action stop charging %d \r\n", __FUNCTION__, *pErrorAction));
        break;
  }

  return Status;
}


EFI_STATUS ChargerLibTarget_SetDAMIcl(DAM_SEL_ICL DAMIcl)
{
    EFI_STATUS Status = EFI_SUCCESS;

    if (!PmicSchgProtocol)
    {
        Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid,
            NULL,
            (VOID **)&PmicSchgProtocol);

        if ((Status != EFI_SUCCESS) || (NULL == PmicSchgProtocol))
        {
            CHARGER_DEBUG((EFI_D_WARN, "ChargerLib:: %a pmicSchgProtocol Failed = %r \r\n", __FUNCTION__, Status));
            return EFI_DEVICE_ERROR;
        }
    }

    Status |= PmicSchgProtocol->SetDAMIcl(ChargerInfo.ChargerPmicInfo.PmicIndex, DAMIcl);
    return Status;
}


EFI_STATUS ChargerLibTarget_GetChargerInputStatus(CHARGERLIB_CHARGER_INPUT_STATUS *pChargerInputStatus)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_SCHG_ICL_STATUS pmschg_icl_status = {0};

  //NULL Check
  if(pChargerInputStatus == NULL)
    return EFI_INVALID_PARAMETER;

  //Reset Parameter
  pChargerInputStatus->bAiclDone = FALSE;
  pChargerInputStatus->ICLMaxMa = 0;
  pChargerInputStatus->ICLfinalMa = 0;

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    if (!PmicSchgProtocol)
    {
      Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid,
                                   NULL,
                                   (VOID **)&PmicSchgProtocol);

      if((Status != EFI_SUCCESS) || (NULL == PmicSchgProtocol ))
      {
        CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a pmicSchgProtocol Failed = %r \r\n", __FUNCTION__, Status));
        return EFI_DEVICE_ERROR;
      }
    }
    Status = PmicSchgProtocol->GetIclStatus(ChargerInfo.ChargerPmicInfo.PmicIndex, &pmschg_icl_status);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  if(Status == EFI_SUCCESS)
  {
    pChargerInputStatus->bAiclDone = (pmschg_icl_status.aicl_done > 0)? TRUE:FALSE;
    pChargerInputStatus->ICLMaxMa = pmschg_icl_status.max_icl_status;
    pChargerInputStatus->ICLfinalMa = pmschg_icl_status.final_icl_status;
  }
  return Status;
}

EFI_STATUS ChargerLibTarget_GetUsbcPortType(CHARGERLIB_CHG_USBC_SINK_TYPE *pUsbcPortType)
{
  EFI_STATUS Status = EFI_SUCCESS;
  EFI_PM_SCHG_TYPEC_PORT_STATUS UsbcStatus;

  //NULL Check
  if(pUsbcPortType == NULL)
    return EFI_INVALID_PARAMETER;

  //Reset Parameter
  *pUsbcPortType = CHARGERLIB_CHG_USBC_SINK_NONE;

  switch (ChargerInfo.ChargerHW)
  {
  case EfiBatteryChargerQcomPmicSchg:
    if (!PmicSchgProtocol)
    {
      Status = gBS->LocateProtocol(&gQcomPmicSchgProtocolGuid,
                                   NULL,
                                   (VOID **)&PmicSchgProtocol);

      if((Status != EFI_SUCCESS) || (NULL == PmicSchgProtocol ))
      {
        CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a pmicSchgProtocol Failed = %r \r\n", __FUNCTION__, Status));
        return EFI_DEVICE_ERROR;
      }
    }
    Status = PmicSchgProtocol->GetPortState(ChargerInfo.ChargerPmicInfo.PmicIndex, &UsbcStatus);
    break;
  default:
    Status = EFI_UNSUPPORTED;
    break;
  }

  if(Status == EFI_SUCCESS)
  {
    switch (UsbcStatus.dfp_curr_adv)
    {
    case EFI_PM_SCHG_TYPEC_DFP_CURR_ADV_3A:
      *pUsbcPortType = CHARGERLIB_CHG_USBC_SINK_3P0A;
      break;
    case EFI_PM_SCHG_TYPEC_DFP_CURR_ADV_1P5A:
      *pUsbcPortType = CHARGERLIB_CHG_USBC_SINK_1P5A;
      break;
    case EFI_PM_SCHG_TYPEC_DFP_CURR_ADV_STD:
      *pUsbcPortType = CHARGERLIB_CHG_USBC_SINK_DFAULT;
      break;
    default:
      *pUsbcPortType = CHARGERLIB_CHG_USBC_SINK_NONE;
      break;
    }
  }

  CHARGER_FILE_UART_DEBUG((EFI_D_WARN,"ChargerLib:: %a Charger Usbc Sink Port type = %d \r\n", __FUNCTION__, *pUsbcPortType));

  return Status;
}

EFI_STATUS ChargerLibTarget_GetDisplayImageType(CHARGERLIB_EVENT_DISP_IMAGE_TYPE *pDispImage)
{
  EFI_STATUS Status = EFI_SUCCESS;

  if(NULL == pDispImage)
  {
    return EFI_INVALID_PARAMETER;
  }

  *pDispImage = gDispImage;

  CHARGER_DEBUG((EFI_D_WARN,"ChargerLib:: %a Display Image type = %d \r\n", __FUNCTION__, *pDispImage));

  return Status;
}

