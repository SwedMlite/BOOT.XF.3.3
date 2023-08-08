/*! @file PmicRtcProtocol.c 

*  PMIC-RTC MODULE RELATED DECLARATION
*  This file contains functions and variable declarations to support 
*  the PMIC RTC module.
*
*  Copyright (c) 2011 - 2019 Qualcomm Technologies, Inc.  All Rights Reserved.
*  Qualcomm Technologies Proprietary and Confidential.
*/

/*===========================================================================

EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
4/30/19    cg      Restructuring the APis
05/21/15   al      Adding API to read RTC ALARM OK and Exipred status
06/09/14   al      Arch update
13/12/13   aa      PmicLib Dec Addition
11/22/13   va      PmicLib Dec Addition
02/08/13   al      Fixed warnings
01/22/13   al	   Added SetTimeValueRaw 
10/25/12   al      File renamed 
10/23/12   al	   Updating copyright info 
02/27/12   al      Commented out to compile for 8960 and 8974.
03/20/11   dy      New file.
===========================================================================*/

/*===========================================================================

INCLUDE FILES FOR MODULE

===========================================================================*/
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include "pm_uefi.h"
#include "PmicRtcConversions.h"
#include "pm_rtc.h"
#include "Protocol/EFIPmicRTC.h"

/*===========================================================================
LOCAL VARIABLE DEFINITIONS
===========================================================================*/
static EFI_PM_RTC_DISPLAY_TYPE pm_app_rtc_current_display_mode = EFI_PM_RTC_24HR_MODE;

/*===========================================================================
FUNCTION DEFINITIONS
===========================================================================*/
/**
EFI_PmicRTCGetDisplayMode ()

@brief
GetDisplayMode implementation of EFI_QCOM_PMIC_RTC_PROTOCOL
*/
EFI_STATUS 
EFIAPI 
EFI_PmicRTCGetDisplayMode
(
  IN  UINT32                  PmicDeviceIndex, 
  OUT EFI_PM_RTC_DISPLAY_TYPE * ModePtr
)
{
  *ModePtr = pm_app_rtc_current_display_mode;

  return EFI_SUCCESS;
}


/**
EFI_PmicRTCSetDisplayMode ()

@brief
SetDisplayMode implementation of EFI_QCOM_PMIC_RTC_PROTOCOL
*/
EFI_STATUS
EFIAPI 
EFI_PmicRTCSetDisplayMode
(
  IN UINT32 PmicDeviceIndex, 
  IN EFI_PM_RTC_DISPLAY_TYPE Mode
)
{
  if (Mode >= EFI_PM_RTC_INVALID_MODE)
    {
      return EFI_DEVICE_ERROR;
    }

  pm_app_rtc_current_display_mode = Mode;

  return EFI_SUCCESS;
}


/**
EFI_PmicRTCSetTimeValue()

@brief
SetTimeValue implementation of EFI_QCOM_PMIC_RTC_PROTOCOL
*/
EFI_STATUS 
EFIAPI 
EFI_PmicRTCSetTimeValue
(
  IN UINT32                  PmicDeviceIndex, 
  OUT EFI_PM_RTC_JULIAN_TYPE * CurrentTimePtr
)
{
  return EFI_UNSUPPORTED;
}


/*Get RTC time Raw */
EFI_STATUS 
EFIAPI 
EFI_PmicRTCGetTimeValueRaw
(
  IN UINT32  PmicDeviceIndex, 
  OUT UINT32 * TimeValueSeconds
)
{
  pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;
  pm_rtc_time_type time;

  if (TimeValueSeconds == NULL)
    {
      return EFI_INVALID_PARAMETER;
    }

  errFlag = pm_rtc_get_time_raw(PmicDeviceIndex, &time);

  if (errFlag == PM_ERR_FLAG_SUCCESS)
    {
      *TimeValueSeconds = time.sec;
    }
  else 
    {
      return EFI_DEVICE_ERROR;
    }

  return EFI_SUCCESS;
}


/*Set RTC time Raw */
EFI_STATUS 
EFIAPI 
EFI_PmicRTCSetTimeValueRaw
(
  IN UINT32 PmicDeviceIndex, 
  IN UINT32 TimeValueSeconds
)
{
  return EFI_UNSUPPORTED;
}


/*get Alarm status*/
EFI_STATUS 
EFIAPI 
EFI_PmicRTCAlarmEnableStatus
(
  IN  UINT32  PmicDeviceIndex, 
  OUT BOOLEAN * Enabled
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

  if (NULL == Enabled)
    {
      return EFI_INVALID_PARAMETER;
    }

  errFlag = pm_rtc_alarm_enable_status(PmicDeviceIndex, Enabled);

  Status = (errFlag == PM_ERR_FLAG_SUCCESS) ? EFI_SUCCESS: EFI_DEVICE_ERROR;

  return Status;
}


/*read the alarm status*/
EFI_STATUS 
EFIAPI 
EFI_PmicRTCAlarmExpireStatus
(
  IN  UINT32   PmicDeviceIndex, 
  OUT BOOLEAN * ExpireStatus
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

  if (NULL == ExpireStatus)
    {
      return EFI_INVALID_PARAMETER;
    }

  errFlag = pm_rtc_irq_status(PmicDeviceIndex, PM_RTC_ALARM, PM_IRQ_STATUS_RT, ExpireStatus);

  Status = (errFlag == PM_ERR_FLAG_SUCCESS) ? EFI_SUCCESS: EFI_DEVICE_ERROR;

  return Status;
}


/*Enable/Disable alarm*/
EFI_STATUS
EFIAPI 
EFI_PmicRTCAlarmEnable
(
  IN UINT32 PmicDeviceIndex, 
  IN BOOLEAN Enable
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

  errFlag = pm_rtc_alarm_enable(PmicDeviceIndex, (boolean) Enable);

  Status = (errFlag == PM_ERR_FLAG_SUCCESS) ? EFI_SUCCESS: EFI_DEVICE_ERROR;

  return Status;
}


/*Set Alarm time */
EFI_STATUS 
EFIAPI 
EFI_PmicRTCAlarmSetTime
(
  IN UINT32               PmicDeviceIndex, 
  IN EFI_PM_RTC_TIME_TYPE * SetAlarmTime
)
{
  EFI_STATUS Status = EFI_SUCCESS;
  pm_err_flag_type errFlag = PM_ERR_FLAG_SUCCESS;

  errFlag = pm_rtc_alarm_set_time(PmicDeviceIndex, (pm_rtc_time_type *) SetAlarmTime);

  Status = (errFlag == PM_ERR_FLAG_SUCCESS) ? EFI_SUCCESS: EFI_DEVICE_ERROR;

  return Status;
}


/**
PMIC Client Device UEFI Protocol implementation
*/
EFI_QCOM_PMIC_RTC_PROTOCOL PmicRtcProtocolImplementation =
{
  PMIC_RTC_REVISION, 
  EFI_PmicRTCGetDisplayMode, 
  EFI_PmicRTCSetDisplayMode, 
  EFI_PmicRTCSetTimeValue, 
  EFI_PmicRTCGetTimeValueRaw, 
  EFI_PmicRTCSetTimeValueRaw, 
  EFI_PmicRTCAlarmEnableStatus, 
  EFI_PmicRTCAlarmExpireStatus, 
  EFI_PmicRTCAlarmSetTime, 
  EFI_PmicRTCAlarmEnable, 
};


