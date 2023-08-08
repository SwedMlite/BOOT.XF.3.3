/*! \file pm_gpio_driver.c
 *  \n
 *  \brief  
 *  \details  
 *  \n &copy; Copyright 2012-2019 QUALCOMM Technologies Incorporated, All Rights Reserved
 */

/* =======================================================================
                             Edit History
  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/drivers/gpio/src/pm_gpio_driver.c#3 $

$Author: pwbldsvc $
$DateTime: 2019/06/17 18:09:44 $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
08/25/17    aab     Updated to support SDX24.  Moved common Reg def to driver file
08/14/15   aab     Updated to support New GPIO peripheral
07/16/14   akm     Comm change Updates
03/31/14   akm     Updated to the latest PMIC driver architecture   
03/25/13   aab     Creation
========================================================================== */
/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_gpio_driver.h"
#include "CoreVerify.h"
#include "pm_target_information.h"
#include "pm_version.h"
#include "device_info.h"
#include "pm_utils.h"
#include "hw_module_type.h"
/*===========================================================================

                        STATIC VARIABLES 

===========================================================================*/

/* Static global variable to store the GPIO data */
static pm_gpio_data_type *pm_gpio_data_arr[PM_MAX_NUM_PMICS];

static pm_gpio_register_info_type gpio_reg[1] =
{
  { .base_address      = 0xC000,
    .peripheral_offset = 0x100,
    .status            = 0x08,
    .int_rt_sts        = 0x10,
    .int_set_type      = 0x11,
    .int_polarity_high = 0x12,
    .int_polarity_low  = 0x13,
    .int_latched_clr   = 0x14,
    .int_en_set        = 0x15,
    .int_en_clr        = 0x16,
    .int_latched_sts   = 0x18,
    .int_pending_sts   = 0x19,
    .int_mid_sel       = 0x1A,
    .int_priority      = 0x1B,
    .mode_ctl          = 0x40,
    .dig_vin_ctl       = 0x41,
    .dig_pull_ctl      = 0x42,
    .dig_in_dtest_sel  = 0x43,
    .dig_out_src_ctl   = 0x44,
    .dig_out_drv_ctl   = 0x45,
    .en_ctl            = 0x46
  }
};


/*===========================================================================

                        FUNCTION DEFINITIONS

===========================================================================*/
void pm_gpio_driver_init(pm_comm_info_type *comm_ptr, peripheral_info_type *peripheral_info, uint32 pmic_index)
{
    pm_gpio_data_type *gpio_ptr = NULL;

    gpio_ptr=pm_gpio_get_data(pmic_index);    
    
    if (gpio_ptr == NULL)
    {
        pm_malloc( sizeof(pm_gpio_data_type), (void**)&gpio_ptr);
                                                    
        /* Assign Comm ptr */
        gpio_ptr->comm_ptr = comm_ptr;
        
        /* LDO Register Info - Obtaining Data through dal config */
        gpio_ptr->gpio_register = gpio_reg;
        
        CORE_VERIFY_PTR(gpio_ptr->gpio_register);
        
        /* Num of peripherals cannot be 0 if this driver init gets called */
        gpio_ptr->num_of_peripherals = pm_target_information_get_periph_count_info(PM_PROP_GPIO_NUM, pmic_index);

        CORE_VERIFY(gpio_ptr->num_of_peripherals != 0);

        pm_gpio_data_arr[pmic_index] = gpio_ptr;
    }
}

pm_gpio_data_type* pm_gpio_get_data(uint32 pmic_index)
{
  if(pmic_index < PM_MAX_NUM_PMICS)
  {
      return pm_gpio_data_arr[pmic_index];
  }

  return NULL;
}

uint8 pm_gpio_get_num_peripherals(uint32 pmic_index)
{
  if((pmic_index < PM_MAX_NUM_PMICS) && 
      (pm_gpio_data_arr[pmic_index] != NULL))
  {
      return pm_gpio_data_arr[pmic_index]->num_of_peripherals;
  }

  return 0;
}
