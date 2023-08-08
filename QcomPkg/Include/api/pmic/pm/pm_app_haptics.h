#ifndef __PM_APP_HAPTICS_H__
#define __PM_APP_HAPTICS_H__

/*! \file  pm_app_haptics.h 
*  \n
*  \brief   PMIC-HAPTICS MODULE RELATED DECLARATION
*  \details  This file contains functions prototypes and variable/type/constant
*  declarations for supporting HAPTICS motor driver for the Qualcomm PMIC 
*  chip set.
*
*
*  \n &copy; Copyright 2017-2019 QUALCOMM Technologies Inc, All Rights Reserved
*/

/* =======================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
04/28/17   aab     Creation
========================================================================== */

/*===========================================================================
                INCLUDE FILES FOR MODULE
===========================================================================*/
#include "com_dtypes.h"
#include "pm_err_flags.h"
#include "pm_resources_and_types.h"
#include "pm_gpio.h"


/* pm_haptics_app_config is introduced to identify whether VDD_HAP is connected to VPH_PWR
 * or external boost. If connecting to external boost, the external boost is usually enable/disabled
 * by PMIC GPIO. For example, on Kona, VDD_HAP is connected to external boost which is enabled by GPIO5B.
 * in this case, external_boost_vdd = true, pmic_index_gpio = PMIC_B, gpio_index = PM_GPIO_5.
 */
typedef struct
{
  uint8 haptics_pmic;                     // pmic index of haptics peripheral
  boolean is_external_boost_vdd;          // is haptics vdd connected to VPH_PWR or external boost
  uint8 haptics_gpio_pmic;           // pmic index of GPIO which is used to enable external boost
  pm_gpio_perph_index gpio;  // GPIO number for external boost enable pin
} pm_haptics_app_config;

/*=============================================================================
                    LOCAL VARIABLE DEFINITIONS
=============================================================================*/


/*===========================================================================

                 HAPTICS DRIVER FUNCTION DEFINITIONS

===========================================================================*/


/*===========================================================================
FUNCTION pm_app_haptics_vib_ctrl

DESCRIPTION
  This function enables/disables vibrator .

PARAMETERS
   1) Name: enable
      - pm_on_off_type to enable/disable vibrator.
      - Valid Inputs PM_ON/PM_OFF

RETURN VALUE
  return value type: pm_err_flag_type.
    PM_ERR_FLAG_INVALID_PARAMETER  = Input Parameter is out of range.
    PM_ERR_FLAG_SUCCESS           = SUCCESS.

DEPENDENCIES
  Call the functions listed below before calling this function:
  1) pm_driver_init()

===========================================================================*/
pm_err_flag_type pm_app_haptics_vib_ctrl(pm_on_off_type state);

#endif  //__PM_APP_HAPTICS_H__

