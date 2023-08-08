/*! \file
 *  \n
 *  \brief  pm_rtc_driver.c
 *  \details  
 *  \n &copy; Copyright 2010-2018 Qualcomm Technologies, Incorporated, All Rights Reserved
 */

/* =======================================================================
                             Edit History
  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/drivers/rtc/src/pm_rtc_driver.c#3 $
$Author: pwbldsvc $
$DateTime: 2019/06/17 18:09:44 $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
11/12/17    aab     Moved common Register address defination to driver file  
08/20/14    al      Updating comm lib 
08/29/14    al      KW fixes
05/20/14    al      Architecture update
05/09/14    va      Using common debug and assert Marco
08/01/13    al      New arch
========================================================================== */
/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_rtc_driver.h"
#include "hw_module_type.h"
#include "CoreVerify.h"
#include "pm_utils.h"

/*===========================================================================

                        STATIC VARIABLES 

===========================================================================*/

/* Static global variable to store the RTC data */
static pm_rtc_data_type * pm_rtc_data_arr[PM_MAX_NUM_PMICS];

static pm_rtc_register_info_type rtc_reg[1] =
{
    {
      .base_address = 0x6000, 
      .peripheral_offset = 0x100, 
      .rw_status1 = 0x08, 
      .rtc_en_ctl = 0x46, 
      .alrm_en_ctl = 0x46, 
      .int_latched_clr = 0x14, 
      .wdata0 = 0x40, 
      .wdata1 = 0x41, 
      .wdata2 = 0x42, 
      .wdata3 = 0x43, 
      .time_adj = 0x44, 
      .rdata0 = 0x48, 
      .rdata1 = 0x49, 
      .rdata2 = 0x4A, 
      .rdata3 = 0x4B, 
      .alrm_data0 = 0x40, 
      .alrm_data1 = 0x41, 
      .alrm_data2 = 0x42, 
      .alrm_data3 = 0x43, 
      .alarm_status1 = 0x08, 
      .int_rt_sts = 0x10, 
      .int_set_type = 0x11, 
      .int_polarity_high = 0x12, 
      .int_polarity_low = 0x13, 
      .int_en_set = 0x15, 
      .int_en_clr = 0x16, 
      .int_latched_sts = 0x18, 
      .int_pending_sts = 0x19, 
      .int_priority = 0x1B
    }
};


/*===========================================================================

                        FUNCTION DEFINITIONS

===========================================================================*/
void pm_rtc_driver_init(pm_comm_info_type * comm_ptr, peripheral_info_type * peripheral_info, uint8 pmic_index)
{
  pm_rtc_data_type * rtc_ptr = NULL;

  rtc_ptr = pm_rtc_data_arr[pmic_index];


  if (NULL == rtc_ptr)
    {
      pm_malloc(sizeof(pm_rtc_data_type), (void * *) &rtc_ptr);
      pm_rtc_data_arr[pmic_index] = rtc_ptr;
    }

  if (rtc_ptr != NULL)
    {
      /* Assign Comm ptr */
      rtc_ptr->comm_ptr = comm_ptr;

      /* RTC Register Info - Obtaining Data through dal config */
      rtc_ptr->rtc_reg_table = rtc_reg;
      CORE_VERIFY_PTR(rtc_ptr->rtc_reg_table);

      //rtc_ptr->num_of_peripherals = (uint32)PM_MAX_NUM_RTC;
      rtc_ptr->num_of_peripherals = pm_target_information_get_periph_count_info(PM_PROP_RTC_NUM, pmic_index);
      CORE_VERIFY(rtc_ptr->num_of_peripherals != 0);
    }
}


pm_rtc_data_type * pm_rtc_get_data(uint8 pmic_index)
{
  if (pmic_index < PM_MAX_NUM_PMICS)
    {
      return pm_rtc_data_arr[pmic_index];
    }

  return NULL;
}


uint8 pm_rtc_get_num_peripherals(uint8 pmic_index)
{
  if ((pmic_index < PM_MAX_NUM_PMICS) && (pm_rtc_data_arr[pmic_index] != NULL))
    {
      return pm_rtc_data_arr[pmic_index]->num_of_peripherals;
    }

  return 0;
}


