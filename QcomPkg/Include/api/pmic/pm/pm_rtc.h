#ifndef __PM_UEFI_RTC_H__
#define __PM_UEFI_RTC_H__

/*===========================================================================

PMIC RTC SERVICES HEADER FILE

DESCRIPTION
This file contains functions prototypes and variable/type/constant 
declarations for the RTC services developed for the Qualcomm Power
Management IC.

Copyright (c) 2003 - 2019 QUALCOMM Technologies Incorporated, All Rights Reserved.
===========================================================================*/

/*===========================================================================

EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
4/30/19    cg	   Restructuring the APIs
05/21/15   al      Adding API to read RTC alarm and interrupt
05/20/14   al      Architecture update
02/08/13   al      Changing pm_dev_ to pm_ and fixed warnings
07/27/12   al	   Renamed all Enums,added device index and resource index
04/28/11   dy      Include PMIC version check
03/23/11   dy      Port to PMIC UEFI
10/20/09   jtn     Move init function prototype to pm_device_init_i.h
10/23/08   jtn     Added API pm_hal_rtc_prescaler_reset()
06/18/07   cng     Added meta comments to miscellaneous RTC APIs
05/31/06   Vish    Fixed LINT warnings.
05/03/05   Vish    Modified pm_hal_rtc_get_time() to read RTC time even in
the case when RTC was not running.
01/19/05   Vish    Updated function header for pm_hal_rtc_get_time().
01/28/04   rmd     Added initial support for multiple PMIC models/tiers.
11/07/03   Vish    Added the task of clearing the alarm trigger condition
within pm_hal_rtc_disable_alarm() so that the master
RTC alarm interrupt could be cleared afterward.
10/02/03   Vish    Added pm_hal_rtc_get_alarm_time() and 
pm_hal_rtc_get_alarm_status().
09/23/03   Vish    Changed all pm_rtc_xxx variables/fns to pm_hal_rtc_xxx.
09/13/03   Vish    Created.
===========================================================================*/

/*===========================================================================
INCLUDE FILES FOR MODULE
===========================================================================*/
#include "pm_err_flags.h"
#include "com_dtypes.h"
#include "pm_resources_and_types.h"

/* =========================================================================
TYPE DEFINITIONS
========================================================================= */
// RTC time struct used for setting and retrieving current time and also for
// setting the alarm time
typedef struct 
{
  uint32 sec;
  uint32 msec;
} pm_rtc_time_type;


// RTC periph type
typedef enum 
{
  PM_RTC_RW, 
  PM_RTC_ALARM, 
  PM_RTC_TIMER, 
  PM_RTC_INVALID_TYPE, 
} pm_rtc_periph_type;


/* =========================================================================
FUNCTION PROTOTYPES
========================================================================= */

/*===========================================================================
FUNCTION  pm_rtc_enable_status                                 EXTERNAL FUNCTION

DESCRIPTION
This function gets the RTC enable status

PARAMETERS
@param[in] : pmic_chip
@param[in] : enable_status

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_INVALID_PARAMETER     -> NULL pointer provided for 
start_time_ptr.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.      
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.

===========================================================================*/
pm_err_flag_type 
pm_rtc_enable_status(uint32 pmic_index, boolean * enable_status);

/*===========================================================================
FUNCTION  pm_rtc_enable                                  EXTERNAL FUNCTION

DESCRIPTION
This function enable/disable RTC timer.

PARAMETERS
@param[in] : pmic_chip
@param[in] : enable

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_enable(uint32 pmic_index, boolean enable);

/*===========================================================================
FUNCTION  pm_rtc_set_time_raw                                 EXTERNAL FUNCTION

DESCRIPTION
This function set RTC timer to desired time.

PARAMETERS
@param[in] : pmic_chip
@param[in] : start_time
             refer enum pm_rtc_time_type

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_set_time_raw(uint32 pmic_index, pm_rtc_time_type * start_time);

/*===========================================================================
FUNCTION  pm_rtc_get_time_raw                                 EXTERNAL FUNCTION

DESCRIPTION
This function gets the current RTC tick.

PARAMETERS
@param[in] : pmic_chip
@param[in] : *time_ptr
              refer enum pm_rtc_time_type


RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_get_time_raw(uint32 pmic_index, pm_rtc_time_type * time_ptr);

/*===========================================================================
FUNCTION  pm_rtc_set_time_adj                                 EXTERNAL FUNCTION

DESCRIPTION
This function gets the current RTC time.

PARAMETERS
@param[in] : pmic_chip
@param[in] : time_adjust
             
RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_set_time_adjust(uint32 pmic_index, uint8 time_adjust);

/*===========================================================================
FUNCTION  pm_rtc_alarm_enable_status                                 EXTERNAL FUNCTION

DESCRIPTION
This function gets the RTC alarm status.

PARAMETERS
@param[in] : pmic_chip
@param[in] : *enabled

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_alarm_enable_status(uint32 pmic_chip, boolean * enabled);

/*===========================================================================
FUNCTION  pm_rtc_alarm_enable                                 EXTERNAL FUNCTION

DESCRIPTION
This function enable /disable RTC timer.

PARAMETERS
@param[in] : pmic_chip
@param[in] : enable
             
RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_alarm_enable(uint8 pmic_chip, boolean enable);

/*===========================================================================
FUNCTION  pm_rtc_alarm_set_time                                 EXTERNAL FUNCTION

DESCRIPTION
This function set alarm to time given by parameter set_time after current RTC time.

PARAMETERS
@param[in] : pmic_chip
@param[in] : *set_time:
             refer to  enum pm_rtc_time_type
             
RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_alarm_set_time(uint8 pmic_chip, pm_rtc_time_type * set_time);

/*===========================================================================
FUNCTION  pm_rtc_irq_enable                                 EXTERNAL FUNCTION

DESCRIPTION
This function enable /disable rtc IRQ .

PARAMETERS
@param[in] : pmic_chip
@param[in] : periph_index:
             refer enum pm_rtc_perph_index
@param[in] : enable


RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_irq_enable(uint32 pmic_chip, pm_rtc_periph_type periph_index, boolean enable);

/*===========================================================================
FUNCTION  pm_rtc_irq_clear                                 EXTERNAL FUNCTION

DESCRIPTION
This function clears the rtc irq.

PARAMETERS
@param[in] : pmic_chip
@param[in] : periph_index:
             refer enum pm_rtc_perph_index

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_irq_clear(uint32 pmic_chip, pm_rtc_periph_type periph_index);

/*===========================================================================
FUNCTION  pm_rtc_irq_set_trigger                                 EXTERNAL FUNCTION

DESCRIPTION
This function configures the RTC for IRQ.

PARAMETERS
@param[in] : pmic_chip
@param[in] : periph_index:
             refer enum pm_rtc_perph_index
@param[in] : type:  
             Type of IRQ trigger. Refer enum pm_irq_trigger_type 

RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_irq_set_trigger(uint32 pmic_chip, pm_rtc_periph_type periph_index, pm_irq_trigger_type trigger);

/*===========================================================================
FUNCTION  pm_rtc_irq_status                                 EXTERNAL FUNCTION

DESCRIPTION
This function gets the RTC IRQ status.

PARAMETERS
@param[in] : pmic_chip
@param[in] : periph_index:
             refer enum pm_rtc_perph_index
@param[in] : type:  
             Type of IRQ status to read. Refer enum pm_irq_status_type 
@param[out]: status:  
             IRQ status.
             
RETURN VALUE
Type: pm_err_flag_type
- Possible values:
- PM_ERR_FLAG_SUCCESS               -> Operation succeeded.
- PM_ERR_FLAG_BUS_ERR           -> Communication with PM chip failed.
- PM_ERR_FLAG_FEATURE_NOT_SUPPORTED -> Feature not available on this 
version of the PMIC.           

===========================================================================*/
pm_err_flag_type 
pm_rtc_irq_status(uint32 pmic_chip, pm_rtc_periph_type periph_index, pm_irq_status_type type, boolean * status);

/*===========================================================================*/
#endif // __PM_RTC_H__


