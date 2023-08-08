#ifndef PM_RTC_DRIVER__H
#define PM_RTC_DRIVER__H

/*! \file
*  \n
*  \brief  pm_rtc_driver.h
*  \details  This file contains functions prototypes and variable/type/constant
*  declarations for supporting RTC pin services for the Qualcomm
*  PMIC chip set.
*  \n &copy;  Copyright (c) 2013-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
*/

/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/drivers/rtc/src/pm_rtc_driver.h#3 $
$Author: pwbldsvc $
$DateTime: 2019/06/17 18:09:44 $
when		 who      what, where, why
--------	 ---      ----------------------------------------------------------
4/30/19       cg       removing the unused registers
05/21/15      al       Adding RTC alarm and interrupt registers
08/20/14      al       Updating comm lib 
11/22/13      va       PmicLib Dec Addition
08/01/13      al       New arch
========================================================================== */

/*===========================================================================
INCLUDE FILES FOR MODULE
===========================================================================*/
#include "pm_rtc.h"
#include "pm_target_information.h"

/*===================================================================
               DEFINITIONS
====================================================================*/
typedef struct 
{
  pm_register_address_type base_address;
  pm_register_address_type peripheral_offset;
  pm_register_address_type rw_status1;              //0x08    
  pm_register_address_type rtc_en_ctl;              //0x46    
  pm_register_address_type alrm_en_ctl;             //0x46             
  pm_register_address_type int_latched_clr;         //0x14    
  pm_register_address_type wdata0;                  //0x40            
  pm_register_address_type wdata1;                  //0x41            
  pm_register_address_type wdata2;                  //0x42            
  pm_register_address_type wdata3;                  //0x43     
  pm_register_address_type time_adj;                //0x44
  pm_register_address_type rdata0;                  //0x48             
  pm_register_address_type rdata1;                  //0x49             
  pm_register_address_type rdata2;                  //0x4A            
  pm_register_address_type rdata3;                  //0x4B           
  pm_register_address_type alrm_data0;              //0x40            
  pm_register_address_type alrm_data1;              //0x41           
  pm_register_address_type alrm_data2;              //0x42            
  pm_register_address_type alrm_data3;              //0x43           
  pm_register_address_type alarm_status1;           //0x08   
  pm_register_address_type int_rt_sts;              //0x10
  pm_register_address_type int_set_type;            //0x11
  pm_register_address_type int_polarity_high;       //0x12
  pm_register_address_type int_polarity_low;        //0x13
  pm_register_address_type int_en_set;              //0x15
  pm_register_address_type int_en_clr;              //0x16
  pm_register_address_type int_latched_sts;         //0x18
  pm_register_address_type int_pending_sts;         //0x19
  pm_register_address_type int_priority;            //0x1B

} pm_rtc_register_info_type;


typedef struct 
{
  pm_comm_info_type * comm_ptr;
  pm_rtc_register_info_type * rtc_reg_table;
  uint8           num_of_peripherals;

} pm_rtc_data_type;


/*************************************
NOTE: Initializer IMPLEMENTATION
**************************************/
void pm_rtc_driver_init(pm_comm_info_type * comm_ptr, peripheral_info_type * peripheral_info, uint8 pmic_index);

pm_rtc_data_type * pm_rtc_get_data(uint8 pmic_index);

uint8 pm_rtc_get_num_peripherals(uint8 pmic_index);

#endif //PM_RTC_DRIVER__H

