/*! \file pm_sbl_boot.c
*  \n
*  \brief This file contains PMIC device initialization function where initial PMIC
*  \n SBL settings are configured through the PDM auto-generated code.
*  \n
*  \n &copy; Copyright 2013-2019 Qualcomm Technologies Inc, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/target/sdm8250_pm855_pm855b/system/src/pm_sbl_boot.c#11 $
$Author: pwbldsvc $
$DateTime: 2019/10/14 19:17:11 $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
08/07/19   yps     Free pmic config buffer after pmic initialization
05/07/18   pxm     Remove pm_config_wlan_active_and_retention_level and auto power on check on PM855B
06/05/17   aab     Updated pm_config_wlan_active_and_retention_level() 
12/05/17   aab     Added support to log number of SPMI transaction
11/19/17   aab     Updated check to support RUMI with out PMIC.      
07/21/17   czq     Use Spare reg PON_PERPH_RB_SPARE instead of PON_DVDD_RB_SPARE
07/10/17   sv      Updated auto power on check API.
05/15/17   aab     Updated pm_sbl_chg_init() to call updated temp monitoring function
02/17/17   pxm     Called function to check if auto power on. 
01/11/17   pxm     add support for PBS triggered AFP
12/27/16   al      Porting fix to set LDO5 voltage with micro volt's.  
10/21/16   akm     Added pm_get_pon_reason_history, pm_pbs_header_info_init in pm_sbl_pre_config
10/07/16   aab     Call pm_sbl_config_skin_temp_threshold() for targets that require charging
09/13/16   aab     Updated logging text 
08/25/16   pxm     Config skin temperature threshold for all target
07/31/16   aab     Added num spmi transaction conditional logging
07/14/16   aab     Updated to support target with out PMI8998
06/02/16   aab     Updated pm_device_programmer_init()
03/23/16   aab     Updated pm_config_ssc_active_and_retention_level()
02/18/16   aab     Updated pm_sbl_chg_init()
02/18/16   aab     Added pm_system_init()
02/18/16   aab     Renamed pm_set_ssc_active_and_retention_levels_mv()  to pm_config_ssc_active_and_retention_level() 
02/05/16   aab     Added pm_set_ssc_active_and_retention_levels_mv()
01/25/16   aab     Updated pm_device_init() and pm_sbl_chg_init()to support RUMI targets with out PMIC 
12/22/15   aab     Added Support for PMI8998 SBL Charging
12/10/15   aab     Added Cx/Mx pvs_retention_data[]  
12/04/15   aab     Updated to support msm8998
10/14/15   aab     Branch from 8996 target
========================================================================== */
/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_err_flags.h"
#include "pm_boot.h"
#include "pm_ldo.h"
#include "pm_sbl_boot.h"
#include "pm_device.h"
#include "pm_config_sbl.h"
#include "pm_config_sbl_test.h"
#include "pm_app_pon.h"
#include "pm_app_chgr.h"
#include "pm_app_chgr_common.h"
#include "pm_pbs_info.h"
#include "pm_target_information.h"
#include "pm_sbl_boot_target.h"
#include "pm_log_utils.h"
#include "pm_pbs.h"
#include "pm_schg_chgr.h"
#include "pm_bmd.h"
#include "DALDeviceId.h"
#include "DDIPlatformInfo.h"
#include "DDIChipInfo.h"
#include "pmio_pon.h"
#include "CoreVerify.h"
#include "railway.h"

/*===========================================================================

                     PROTOTYPES 

===========================================================================*/
static pm_err_flag_type pm_sbl_pre_config(void);
static pm_err_flag_type pm_sbl_target_detect(void);
static pm_err_flag_type pm_config_wlan_active_and_retention_level(void);


/*===========================================================================

                        GLOBALS and TYPE DEFINITIONS 

===========================================================================*/
static boolean pm_ram_image_loaded_flag = FALSE;
static boolean pm_get_pon_history_flag = TRUE;
static pm_sbl_specific_data_type      *sbl_param_ptr     = NULL;
static pm_sbl_schg_specific_data_type *sbl_chg_param_ptr = NULL;

/*===========================================================================

                        FUNCTION DEFINITIONS 

===========================================================================*/
pm_err_flag_type 
pm_device_init ( void )
{
   static pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
   uint32 initial_num_spmi_transn = pm_get_num_spmi_transaction(0);

   err_flag |= pm_device_setup();
   if( (pm_is_target_pre_silicon() == TRUE) && (pm_is_pmic_present(PMIC_A) == FALSE) )
   {
      pm_log_message("Bootup: No PMIC on RUMI Target");
      return err_flag = PM_ERR_FLAG_SUCCESS;
   }

   pm_target_information_init();
   pm_comm_info_init();

   err_flag |= pm_device_pre_init();

   err_flag |= pm_pon_init();

   err_flag |= pm_pbs_info_rom_init();  /* Read PBS INFO for the pmic rom devices */

   err_flag |= pm_sbl_pre_config(); /* SBL Pre Configuration */

   err_flag |= pm_sbl_config(); /* SBL Configuration */
   if (err_flag == PM_ERR_FLAG_SUCCESS)
   {
      pm_ram_image_loaded_flag = TRUE;
   }

   err_flag |= pm_sbl_config_test(); /* SBL Configuration validation, only executes complete code if spare reg 0x88F bit 0 is set*/

   err_flag |= pm_pbs_info_ram_init();  /* Read PBS INFO for the pmic ram devices */

   err_flag |= pm_pbs_ram_version_validation_test(); /* PBS RAM Version validation, only executes complete code if spare reg 0x88F bit 0 is set*/
   
   err_flag |= pm_device_post_init(); /* Initialize PMIC with the ones PDM can not perform */

   err_flag |= pm_psi_free_config_buffer(); /* Free config buffer*/

  //Write to Spare bit for pm_device_init_status
   if(err_flag == PM_ERR_FLAG_SUCCESS)
   {
      err_flag = pm_comm_write_byte_mask(PMIC_A_SLAVEID_PRIM, PMIO_PON_PERPH_RB_SPARE_ADDR, PON_PERPH_RB_SPARE_DEVICE_INIT_MASK,PON_PERPH_RB_SPARE_DEVICE_INIT_MASK); 
   }

   pm_log_message("Device Init # SPMI Transn: %d", pm_get_num_spmi_transaction(initial_num_spmi_transn));
   return err_flag; /* NON ZERO return means an ERROR */
}



pm_err_flag_type
pm_sbl_chg_init (void)
{
   pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
   boolean debug_board_present = FALSE;
   uint32 device_index = PMIC_B; //PM855B
   DalPlatformInfoPlatformType platform_type = DALPLATFORMINFO_TYPE_UNKNOWN;
   pm_model_type pmic_model = PMIC_IS_UNKNOWN;

   if (pm_is_target_pre_silicon() == TRUE)
   {
      pm_log_message("Bootup: No Charging support on RUMI Target");
      return err_flag = PM_ERR_FLAG_SUCCESS; 
   }

   if(FALSE == pm_driver_init_status())
   {
      return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
   }

   uint32 initial_num_spmi_transn = pm_get_num_spmi_transaction(0);
   platform_type = DalPlatformInfo_Platform();
   pmic_model = pm_get_pmic_model(device_index);
   if( ((platform_type == DALPLATFORMINFO_TYPE_MTP)
     || (platform_type == DALPLATFORMINFO_TYPE_FLUID)
     || (platform_type == DALPLATFORMINFO_TYPE_LIQUID)
     || (platform_type == DALPLATFORMINFO_TYPE_QRD)
     || (platform_type == DALPLATFORMINFO_TYPE_HDK)) &&
        (pmic_model == PMIC_IS_PM855B))
   {
      err_flag |= pm_sbl_chg_pre_init();

      err_flag |= pm_bmd_enable(device_index, TRUE);
      if(err_flag != PM_ERR_FLAG_SUCCESS )
      {
         return err_flag;
      }
      CORE_VERIFY_PTR(sbl_chg_param_ptr);
      err_flag |= pm_sbl_fake_batt_id_range_config(device_index, sbl_chg_param_ptr);// If 7.5k battery id needs to charge then the default fake battery range needs to modified  
      if(err_flag != PM_ERR_FLAG_SUCCESS )
      {
         return err_flag;
      }

      // NOTE: Do NOT access FG SRAM before we checking battery missing status, otherwise we will suffer FG polling timeout
      boolean battery_missing = TRUE;
      err_flag = pm_bmd_get_battery_missing_rt_status(device_index, PM_BMD_BAT_MISS_STS_DEB, &battery_missing);
      if(battery_missing)
      {
         pm_log_message("battery missing");
         err_flag |= pm_sbl_boot_without_battery_config(device_index);
         return err_flag;
      }
      
      err_flag |= pm_sbl_get_debug_board_presence(device_index, sbl_chg_param_ptr, &debug_board_present);//Check debug board presence

      if(err_flag != PM_ERR_FLAG_SUCCESS || debug_board_present)
      {
         //BOOTUP: Since Debug Board is used 
		 //USB Charging should be disabled
		 err_flag |= pm_schg_chgr_enable_charging(device_index, FALSE);
         return err_flag;
      }

      // Configure and enable AFP
      err_flag |= pm_sbl_config_afp(device_index);
      err_flag |= pm_sbl_config_chg_parameters(device_index);
      err_flag |= pm_sbl_config_charger_and_skin_temp_threshold(device_index);

      err_flag |= pm_sbl_chg_check_weak_battery_status(device_index);
      if(err_flag != PM_ERR_FLAG_SUCCESS)
      {
         pm_log_message("ERROR: pm_sbl_chg_check_weak_battery_status()");
      }

      err_flag |= pm_sbl_chg_post_init();  
   }

   pm_log_message("CHG Init # SPMI Transn: %d", pm_get_num_spmi_transaction(initial_num_spmi_transn));

   return err_flag;
}

pm_err_flag_type
pm_device_programmer_init (void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  
  if( (pm_is_target_pre_silicon() == TRUE) && (pm_is_pmic_present(PMIC_A) == FALSE) )
  {
     pm_log_message("Bootup: No PMIC on RUMI Target");
     return err_flag = PM_ERR_FLAG_SUCCESS;
  }

  err_flag |= pm_device_setup();
  pm_target_information_init();
  pm_comm_info_init();

  err_flag |= pm_pon_init();
    
  return err_flag;
}



static pm_err_flag_type
pm_sbl_pre_config(void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

  if (sbl_param_ptr == NULL)
  {
     sbl_param_ptr = (pm_sbl_specific_data_type*)pm_target_information_get_specific_info(PM_PROP_SBL_SPECIFIC_DATA);
  }
  CORE_VERIFY_PTR(sbl_param_ptr);

  if (sbl_chg_param_ptr == NULL)
  {
     sbl_chg_param_ptr = (pm_sbl_schg_specific_data_type*)pm_target_information_get_specific_info(PM_PROP_SBL_CHG_SPECIFIC_DATA);
  }
  CORE_VERIFY_PTR(sbl_chg_param_ptr);

  err_flag |= pm_log_pon_reasons();

  err_flag |= pm_sbl_target_detect();

  err_flag = pm_pbs_header_info_init();
  	
  pm_pbs_get_pon_reason_hist_dataset();

  if(pm_get_pon_history_flag == TRUE)
  {
    pm_pon_parse_pon_reason_history(PMIC_A);
  }
  return err_flag;
}


pm_err_flag_type
pm_sbl_target_detect(void) /* SBL Target detect */
{
   static pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS; 

   return err_flag;
}


pm_err_flag_type pm_system_init(void)
{
    pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

    /* 
     * If default wlan solution is not applicable, set rfclk2_config_flag as TRUE in pm_config_target.c
     */
    if(FALSE == sbl_param_ptr->rfclk2_config_flag)
    {
        err_flag = pm_config_wlan_active_and_retention_level();
    }

    return err_flag;
}

static pm_err_flag_type 
pm_config_wlan_active_and_retention_level(void)
{
    pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

    return err_flag;
}

pm_err_flag_type
pm_target_specific_device_setup(void)
{
    pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

    DalPlatformInfoPlatformType platform_type = DALPLATFORMINFO_TYPE_UNKNOWN;

    platform_type = DalPlatformInfo_Platform();

      if (platform_type == DALPLATFORMINFO_TYPE_CDP)
      {
         //Increase SPMI DRV Strength
         pm_comm_write_byte(0x0, 0x640, 0x3);

         pm_comm_write_byte(0x2, 0x640, 0x3);
         pm_comm_write_byte(0x4, 0x640, 0x3);
         pm_comm_write_byte(0x6, 0x640, 0x3);
         pm_comm_write_byte(0x8, 0x640, 0x3);
         pm_comm_write_byte(0xA, 0x640, 0x3);

         //Increase master clk and data drv strength for masters
         pm_comm_write_byte(0x0, 0x740, 0x3);
         pm_comm_write_byte(0x0, 0x741, 0x3);
         pm_comm_write_byte(0x8, 0x740, 0x3);
         pm_comm_write_byte(0x8, 0x741, 0x3);
         pm_comm_write_byte(0x8, 0x7DA, 0x3);

         //set sclk div 0 to keep it at 19.2MHz clk
         pm_comm_write_byte(0x8, 0x7E5, 0x0);
      }

    return err_flag;
}
