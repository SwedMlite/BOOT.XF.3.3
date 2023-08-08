/*=============================================================================

                         SBL1 Hardware Initialization

GENERAL DESCRIPTION
  This file does basic hardware initialization at power up.

Copyright 2011-2019 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/

/*=============================================================================

                            EDIT HISTORY FOR MODULE

This section contains comments describing changes made to the module.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/Library/XBLLoaderLib/sbl1_hw.c#12 $

when       who       what, where, why
--------   ---       ----------------------------------------------------------
01/22/19   yps       Relocate DDR stuct
06/07/18   daison    Removed boot_ddr_test call (moved it to after pimem init call)
02/13/18   gk	     Port changes from boot.xf.2.0 and boot.xf.2.2
01/17/18   yps       remove sbl1_ddr_set_default_params
09/28/17   jaychoi   Added hs_phy_nondrive_mode_set call in sbl1_hw_init
05/09/17   sj        added dead battery charging logic in ramdump case also
05/05/17   rp        Moved boot_ddr_set_params outside of dload_mode check and passing dload mode as parameter
04/27/17   rp        Added dload mode parameter for ddr_initialize_device
04/24/17   ds        bot_log updates
04/06/17   kpa       ensure pm_device_init gets loaded in dload mode, port updates from 8998
03/07/17   ds        Added sbl1_pm_aop_pre_init_wrapper
02/08/17   ds        Set ddr struct whitelist
11/07/16   kpa       Added sbl1_do_ddr_training
09/19/16   kpa       enable call to boot_check_device_temp
07/05/16   kpa       Update for sdm845 hwio
06/02/16   rp        Load training data from flash directly into DDR_STRUCT instead of using an intermediate buffer
05/04/16   rp        Rename ddr training APIs
05/03/16   rp        Move ddr_remapper before training
02/18/16   aab       Added a call to boot_pm_system_init();
11/16/15   plc       Make PIMEM noncacheable for now
10/22/15   plc       Replaced tlb invalidate with generic EL-agnostic call
10/13/15   plc       Sync some changes from 8996 tip
10/07/15   plc       Changes to enable DDR on RUMI, and skip DDR on Virtio
08/25/15   plc       Bring up to date with 8996 tip
08/07/15   plc       Stub out Tsens temperature check for 8998 presi virtio
07/23/15   sds       Call boot_ICB_Config_PostInit() after training.
07/15/15   aab       Moved pm_sbl_chg_init() call right after pm_driver_init(). This API is used to do weak battery charging.
05/31/15   aab       Replace pm_oem_init() with pm_sbl_chg_init()
04/20/15   aks       Added support for Voltage Sensors
03/27/15   kpa       Added boot_pm_device_programmer_init
03/04/15   kpa       Reduce DDR freq to 200Mhz for Deviceprogrammer
03/04/15   kpa       Do not initialize pImem during dload mode boot, reset AOSS_CC_RESET_STATUS
02/20/15   kpa       Update boot logs for pmic driver
02/18/15   kpa       Rename sbl1_hw_pmic_init to sbl1_hw_pre_ddr_init. Add railway driver.
02/11/15   kpa       Enable Pimem.
02/03/15   wek       Skip ddr training for device programmer.
01/27/15   kpa       Added sbl1_ddr_set_default_params
01/27/15   jjo       Enable tsens init.
01/05/15   kpa       Temporarily stub out pimem and tsens init.
10/14/14   kpa       Move pm_device_init into sbl1_hw_pmic_init() for pmic
                     image loading support
05/07/14   kedara    Branch for 8996 and include HALbootHWIO.h instead of msmhwioreg.h
03/21/14   ck        Added logic to save reset_status_register to imem cookies before clearing
03/18/14   ck        Updated boot_hw_reset calls as they now take a reset type parameter
03/14/14   ck        Moved boot_busywait_init to sbl1_main_ctl as it needs to be done before boot logger init
03/03/14   ck        Removing SpmiInit and SpmiCfg from sbl1_hw_init per SPMI team as PMIC driver does this now
02/18/14   ck        Added logic to sbl1_hw_init to clear PMIC_ABNORMAL_RESIN_STATUS
10/17/13   ck        Temp zeroing of ddr training memory location until ddr team delivers
08/07/13   sr        Removed boot_ddr_debug call .
07/26/13   rj        Calling i2C init to fix eeprom init issue
07/11/13   rj        Calling boot_pre_ddr_clock_init after CDT configuration is
                     done to dynamically detect ddr and setup the clock plan
06/18/13   sl        Call boot_ddr_debug()
06/06/13   dh        Backup gcc reset status then clear it
06/14/13   dh        Only load ddr training data if sbl is not in dload mode
05/21/13   yp        Turn on vibrator when device power up in normal mode.
04/04/13   dh        Move boot_DALSYS_InitMod to early sbl1_main_ctl
04/02/13   dh        Use boot_dload_is_dload_mode_set instead of uefi dump cookie
                     to determin if device is in dload mode
04/11/13   sl        Relocate boot_ddr_test() call
04/03/13   sl        Call Clock API to get DDR speed
03/21/13   dh        Add memory barrier in boot_ddr_post_init
03/07/12   jz        Cleanup logging
12/13/12   jz        Change clock frequency back to MAX after DDR training is done
12/04/12   dh        Move boot_Tsens_Init to sbl1_hw_init
11/26/12   dh        Skip DDR training if UEFI dload cookie is set
11/12/12   sl        Enable DDR Test Framework
11/05/12   dh        Move thermal management code to common file
10/09/12   dh        Add boot_ICB_Segments_Init right after ddr init to configure
                     bimc slave address range
                     Add boot_SpmiCfg_Init before boot_SpmiBus_Init
10/09/12   dh        Only enable fast debug feature if FEATURE_BOOT_FAST_DEBUG
                     is defined
09/26/12   jz        Compile out boot_debug_mode_enter for Virtio testing
09/25/12   dh        Added pm_driver_init to allow PMIC API usage and pm_oem_init
                   to allow customer to call PMIC API in boot for
                   their desirable PMIC configurations.
08/30/12   dh        Add boot log for clock and pmic functions
08/16/12   AJC       Added boot_debug_mode_enter for FASTDEBUG feature
08/01/12   dh        Add sbl1_hw_deinit
07/23/12   dh        Add sbl1_set_ddr_training_data and sbl1_wait_for_ddr_training
07/16/12   dh        Move spmi and pmic init to sbl1_hw_init
06/18/12   dh        Switch to boot external driver api for tsensor and bus API
06/11/12   dh        Add sbl1_check_device_temp, check temp at the beginning of
                     sbl1_hw_init
06/08/12   dh        Add ICB_Config_Init in sbl1_hw_init
05/29/12   dh        Move boot_clock_init to sbl1_hw_init_secondary
                     Add boot_busywait_init in sbl1_hw_init
                     Remove gpio init from sbl1_hw_init_secondary since it must be
                     called after smem is available.
                     Rename sbl1_clk_regime_ram_dump_init to sbl1_hw_dload_init
05/08/12   dh        Add clock init api
10/18/11   dh        Initial revision
=============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "boot_comdef.h"
#include "boot_sbl_if.h"
#include "sbl1_hw.h"
#include "sbl1_mc.h"
#include "boothw_target.h"
#include "boot_dload.h"
#include "boot_logger.h"
#include "boot_config_data.h"
#include "boot_util.h"
#include "boot_thermal_management.h"
#include "boot_extern_clk_interface.h"
#include "boot_extern_ddr_interface.h"
#include "boot_extern_pmic_interface.h"
#include "boot_extern_dal_interface.h"
#include "boot_extern_tlmm_interface.h"
#include "boot_extern_bus_interface.h"
#include "boot_extern_tsensor_interface.h"
#include "boot_extern_pimem_interface.h"
#include "boot_extern_power_interface.h"
#include "boot_extern_vsense_interface.h"
#include "boot_shared_imem_cookie.h"
#include "string.h"
#include <boot_cache_mmu.h>
#include "HALbootHWIO.h"
#include "boot_profiler.h"
#include <boot_page_table_armv8.h>
#include "ddr_drivers.h"
#include "icb_sdi.h"
#include "boot_visual_indication.h"
#include "boot_fastcall_tz.h"
#include "boot_extern_platforminfo_interface.h"
#include "boot_whitelist_prot.h"
#include "boot_extern_qusb_ldr_interface.h"

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/

/* Writing a 1 clears corresponding bit field */
#define AOSS_CC_RESET_STATUS_CLEAR_VAL 0xF

/* backed up AOSS_CC_RESET_STATUS for ramdump */
static uint32 reset_status_register = 0;



/*=============================================================================

                              FUNCTION DEFINITIONS

=============================================================================*/

static void sbl1_save_ddr_training_data(bl_shared_data_type *bl_shared_data)
{
  uint32 ddr_params_training_data_size = 0;
  void* ddr_training_data_ptr = NULL;
  uint32 start_time = boot_log_get_time();

  data_sync_barrier();

  ddr_training_data_ptr =
    boot_ddr_params_get_training_data(&ddr_params_training_data_size);

  BL_VERIFY((ddr_training_data_ptr != NULL) &&
                   (ddr_params_training_data_size != 0),
                   BL_ERR_NULL_PTR_PASSED|BL_ERROR_GROUP_BOOT);

  /*Save the updated training data to storage device */
  sbl1_save_ddr_training_data_to_partition(ddr_training_data_ptr,
                                           ddr_params_training_data_size,
                                           0);
  ddr_params_training_data_size = 0;
  ddr_training_data_ptr = NULL;
  ddr_training_data_ptr = boot_ddr_params_get_data_buffer(&ddr_params_training_data_size, 1);
  
  if((ddr_training_data_ptr != NULL) && (ddr_params_training_data_size != 0))
  {
      /*Save the updated training data to storage device */
      sbl1_save_ddr_training_data_to_partition(ddr_training_data_ptr,
                                           ddr_params_training_data_size,
                                           SIZE_128KB);
  }

  ddr_params_training_data_size = 0;
  ddr_training_data_ptr = NULL;
  ddr_training_data_ptr = boot_ddr_params_get_data_buffer(&ddr_params_training_data_size, 2);

  if((ddr_training_data_ptr != NULL) && (ddr_params_training_data_size != 0))
  {
      /*Save the updated training data to storage device */
      sbl1_save_ddr_training_data_to_partition(ddr_training_data_ptr,
                                           ddr_params_training_data_size,
                                           SIZE_192KB);
  }

  boot_log_delta_time(start_time,"sbl1_save_ddr_training_data");
}

/*===========================================================================

**  Function :  sbl1_ddr_init

** ==========================================================================
*/
/*!
*
* @brief
*   Initialize DDR device.
* *
* @par Dependencies
*  Following Api's need to be called first:
*    sbl1_hw_init : To have ddr clocks setup.
*    sbl1_ddr_set_params : To have DDR config parameters setup.
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_ddr_init(bl_shared_data_type *bl_shared_data)
{

  ddr_info sbl1_ddr_info;
  icbcfg_error_type icb_config_post_init;
  DalPlatformInfoPlatformType platform;
  
  platform = boot_DalPlatformInfo_Platform();
  
  /* Initialize DDR */
  boot_ddr_initialize_device(boot_clock_get_ddr_speed(), boot_dload_is_dload_mode_set());

  if(!boot_dload_is_dload_mode_set())
  {
    /* Apply any workarounds needed post init */
    boot_ddr_post_init();
  }
  /* Configure DDR slave segments address range */
  sbl1_ddr_info = boot_ddr_get_info();
  boot_ICB_Segments_Init( "/dev/icbcfg/boot", &sbl1_ddr_info);

  boot_ddr_remapper();
  icb_sdi_save();

  /*ICB post config api will configure any settings done after DDR/memmap is finalized. */
  BL_VERIFY((icb_config_post_init=boot_ICB_Config_PostInit("/dev/icbcfg/boot")) == ICBCFG_SUCCESS,
           (uint16)icb_config_post_init|BL_ERROR_GROUP_ICB);

} /* sbl1_ddr_init() */


/*===========================================================================

**  Function :  sbl1_do_ddr_training

** ==========================================================================
*/
/*!
*
* @brief
*   Train DDR if applicable.
* *
* @par Dependencies
*  Following Api's need to be called first:
*    sbl1_ddr_init : To setup ddr.
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_do_ddr_training(bl_shared_data_type *bl_shared_data)
{
  #ifndef FEATURE_DEVICEPROGRAMMER_IMAGE
    boolean ddr_save_training_required = FALSE;
  #endif

  DalPlatformInfoPlatformType platform;
  
  platform = boot_DalPlatformInfo_Platform();

  if ((platform != DALPLATFORMINFO_TYPE_RUMI) &&
      (platform != DALPLATFORMINFO_TYPE_VIRTIO))
  {
#ifdef FEATURE_DEVICEPROGRAMMER_IMAGE
      /* Skip DDR training for Device Programmer, and lower clock speed */
      boot_Clock_SetBIMCSpeed(200000);
#else
    if (boot_ddr_params_is_training_required())
    {
      /* Do DDR training */
        boot_log_message("do_ddr_training, Start");
        boot_log_start_timer();

        if(!boot_dload_is_dload_mode_set())
        {
          boot_enable_led(DDR_TRAINING_LED, TRUE);
          if (boot_ddr_do_phy_training_restore())
          {
            boot_ddr_do_phy_training_init();
            ddr_save_training_required = boot_ddr_post_training();            
          }
          boot_enable_led(DDR_TRAINING_LED, FALSE);
        }

        boot_log_stop_timer("do_ddr_training, Delta");

        if(ddr_save_training_required)
        {
          /* Training is done, save to ddr training partition */
          /* Save ddr training data to storage device if it is updated */
          sbl1_save_ddr_training_data(bl_shared_data);

        }
    }
#endif
  }
  boot_ddr_post_setup();
} /* sbl1_do_ddr_training() */


/*===========================================================================

**  Function :  sbl1_hw_init

** ==========================================================================
*/
/*!
*
* @brief
*   This function performs hardware initialization.
*
*   Only common hardware that is needed for flash
*   initialization is initialized here.
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_init()
{
  TsensResultType status;
  uint32 start_time = boot_log_get_time();

  /* Initialize temperature sensor */
  status = boot_Tsens_Init();
  BL_VERIFY(status == TSENS_SUCCESS,(uint16)status|BL_ERROR_GROUP_TSENS);

  /* Check the temperature */
  boot_check_device_temp();

  /* Put High Speed QUSB2 PHY in non-drive mode. */
  boot_qusb_ldr_utils_hs_phy_nondrive_mode_set();

  /* Calling here to ensure eeprom init goes fine for CDT read */
  boot_pre_i2c_clock_init();
  boot_log_delta_time(start_time,"sbl1_hw_init");

} /* sbl1_hw_init() */


/*===========================================================================

**  Function :  sbl1_hw_deinit

** ==========================================================================
*/
/*!
*
* @brief
*   This function deinit the hardware that's not needed beyond sbl1
*
* @param[in] bl_shared_data Pointer to shared data
*
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_deinit()
{

  /* Call clock exit boot to disable unneeded clock*/
  BL_VERIFY(boot_clock_exit_boot() == TRUE,BL_ERR_DISABLE_CLOCK_FAIL|BL_ERROR_GROUP_BOOT);

} /* sbl1_hw_deinit() */


/*===========================================================================

**  Function :  sbl1_hw_dload_init

** ==========================================================================
*/
/*!
*
* @brief
*   This function initializes the necessary clocks for dload
*   We only do so when auth is disabled
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_dload_init(bl_shared_data_type *bl_shared_data)
{
  boot_dload_clock_init();
}


/*===========================================================================

**  Function :  sbl1_hw_init_secondary

** ==========================================================================
*/
/*!
*
* @brief
*   This function performs secondary hardware initialization.
*
*   DDR is initialized here. This needs to be done after trustzone is loaded.
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_init_secondary( bl_shared_data_type *bl_shared_data )
{
  /* First save gcc reset status to shared IMEM, then clear it */
  reset_status_register = HWIO_IN(AOSS_CC_RESET_STATUS);

  if (boot_shared_imem_cookie_ptr)
  {
    boot_shared_imem_cookie_ptr->reset_status_register = reset_status_register;
  }

  HWIO_OUT(AOSS_CC_RESET_STATUS,AOSS_CC_RESET_STATUS_CLEAR_VAL);

  /* note for future, this needs to happen post ddr set param and set default param
   otherwise we will not be able to detect if we are in 2nd pass or not
   */
  HWIO_OUTF(AOSS_CC_RESET_FSM_CTRL, FIRST_PASS_COMPLETE, 0x0);

  BL_VERIFY((boot_clock_init() == TRUE), BL_ERR_CPU_CLK_INIT_FAIL|BL_ERROR_GROUP_BOOT);

} /* sbl1_hw_init_secondary() */

/*===========================================================================

**  Function :  sbl1_hw_pre_ddr_init

** ==========================================================================
*/
/*!
*
* @brief
*  Initialize PMIC and railway driver. API used for hw initialization that
*  must occur before DDR init.
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*    This Api needs to be called :
*  Before: sbl1_ddr_init
*
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_pre_ddr_init( bl_shared_data_type *bl_shared_data )
{
   pm_err_flag_type pm_device_init, pm_driver_init, pm_sbl_chg_init,pm_devprog_init;
   uint32 start_time;

  if (bl_shared_data->build_type == SBL_BUILD_SBL ||
      bl_shared_data->build_type == SBL_BUILD_DDRDEBUGIMAGE )
  {
    /* load second stage devcfgdata via xblconfig */
    extern void devcfgManagerInit();
    start_time = boot_log_get_time();	
    devcfgManagerInit();
    boot_log_delta_time(start_time,"devcfg init");

    /* Initialize the pmic */
    start_time = boot_log_get_time();
    BL_VERIFY((pm_device_init=boot_pm_device_init()) == PM_ERR_FLAG__SUCCESS, (uint16)pm_device_init|BL_ERROR_GROUP_PMIC);
    BL_VERIFY((pm_driver_init=boot_pm_driver_init()) == PM_ERR_FLAG__SUCCESS, (uint16)pm_driver_init|BL_ERROR_GROUP_PMIC);
    BL_VERIFY((pm_sbl_chg_init=boot_pm_sbl_chg_init()) == PM_ERR_FLAG__SUCCESS, (uint16)pm_sbl_chg_init|BL_ERROR_GROUP_PMIC);
    boot_log_delta_time(start_time,"pmic XBL init");

    /* Calibrate the voltage sensors */
	start_time = boot_log_get_time();	
    BL_VERIFY((boot_vsense_init() == TRUE), BL_ERR_VSENS_INIT_FAIL|BL_ERROR_GROUP_BOOT);
    /*Initialize railway driver */
    boot_railway_init();
    /* Call CPR init to settle the voltages to the recommended levels*/
    boot_cpr_init();
	boot_log_delta_time(start_time,"vsense_railway_cpr init");

    /* Pmic post initialization */
    boot_pm_system_init();

  }
  else
  {
    /* Initialize the pmic */
    start_time = boot_log_get_time();	  
    BL_VERIFY(((pm_devprog_init=boot_pm_device_programmer_init()) == PM_ERR_FLAG__SUCCESS), (uint16)pm_devprog_init|BL_ERROR_GROUP_PMIC);
    boot_log_delta_time(start_time,"pmic DevPrg init");	
  }

}

/*===========================================================================

**  Function :  sbl1_hw_get_reset_status

** ==========================================================================
*/
/*!
*
* @brief
*   This function returns the value of reset status register saved from this boot
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
uint32 sbl1_hw_get_reset_status( void )
{
   return reset_status_register;
}  /* sbl1_hw_get_reset_status */

/*===========================================================================

**  Function :  sbl1_ddr_set_params

** ==========================================================================
*/
/*!
*
* @brief
*   Set DDR configuration parameters
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*    This Api needs to be called :
*  Before: sbl1_ddr_init
*  After: boot_config_data_table_init
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_ddr_set_params(  bl_shared_data_type *bl_shared_data  )
{
  uint32 ddr_cdt_params_size = 0;
  struct cdt_info *config_data_table_info;
  uint8 *ddr_cdt_params_ptr;
  ddr_info ddr_type_info;
  icbcfg_error_type icb_config_Init;
  DalPlatformInfoPlatformType platform;
  uint32 ddr_params_training_data_size = 0;
  void* ddr_training_data_ptr = NULL;
  
  /* Get the size of training data */
  ddr_training_data_ptr = boot_ddr_params_get_training_data(&ddr_params_training_data_size);
  whitelst_tbl_entry_type ddr_struct_whitelist[] = {{(uint64)ddr_training_data_ptr,ddr_params_training_data_size},{0,0}};
  platform = boot_DalPlatformInfo_Platform();
  
  /*Initialize param only during cold boot, for download mode preserve the content */
  if(!boot_dload_is_dload_mode_set() && platform != DALPLATFORMINFO_TYPE_VIRTIO)
  {
    /* If a DDR CDB was found in flashed CDT, overwrite the previously shared
       default compiled DDR CDT configurations with DDR driver*/
    if (boot_cdt_contains_ddr_cdb())
    {
      /* Extract ddr data block from configuration data table(CDT) */
      config_data_table_info =
                        bl_shared_data->sbl_shared_data->config_data_table_info;

      ddr_cdt_params_ptr =
                        boot_get_config_data_block(config_data_table_info->cdt_ptr,
                                                 CONFIG_DATA_BLOCK_INDEX_V1_DDR,
                                                 &ddr_cdt_params_size);

      /* Make sure cdt param size is valid */
      BL_VERIFY((ddr_cdt_params_size <= CONFIG_DATA_TABLE_MAX_SIZE) &&
            (ddr_cdt_params_ptr != NULL),  BL_ERR_CDT_PARAMS_SIZE_INVALID|BL_ERROR_GROUP_BOOT );

      /* Copy CDT DDR paramters to shared IMEM */
      qmemcpy((void*)SHARED_IMEM_BOOT_CDT_BASE,
              ddr_cdt_params_ptr,
              ddr_cdt_params_size);

    }
	
    /* Pass ddr training data to DDR driver */
    if (PcdGet32 (PcdBuildType) != SBL_BUILD_DEVICEPROGRAMMER_DDR)
    {
      BL_VERIFY(boot_set_active_img_whitelist_table(ddr_struct_whitelist),BL_ERR_IMG_SECURITY_FAIL|BL_ERROR_GROUP_SECURITY);
      sbl1_load_ddr_training_data();
    }
  }

  /*Initialize param only during cold boot, for download mode preserve the content */
  if(platform != DALPLATFORMINFO_TYPE_VIRTIO)
  {
    /* Get the ddr type by reading the cdt */
    ddr_type_info = boot_ddr_get_info();

    /* Initialize the pre ddr clock */
    BL_VERIFY((boot_pre_ddr_clock_init(ddr_type_info.ddr_type) == TRUE), BOOT_PRE_DDR_CLK_INIT_FAIL|BL_ERROR_GROUP_BOOT);

    /*ICB config api will configure address range for NOCs */
    BL_VERIFY((icb_config_Init=boot_ICB_Config_Init("/dev/icbcfg/boot")) == ICBCFG_SUCCESS, (uint16)icb_config_Init|BL_ERROR_GROUP_ICB);
  }
} /* sbl1_ddr_set_params() */

/*===========================================================================

**  Function :  sbl1_load_ddr_training_data

** ==========================================================================
*/
/*!
*
* @brief
*   If ddr training is required, read the ddr training data from partition
*   and pass it to ddr driver.
*
* @param[in]
*   None
*
* @par Dependencies
*   Must be called before sbl1_ddr_init
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_load_ddr_training_data()
{

  uint32 ddr_params_training_data_size = 0;
  void* ddr_training_data_ptr = NULL;
  boot_boolean success = FALSE;

  /*Read the ddr partition if ddr training is required and not in dload mode */
  if((boot_ddr_params_is_training_required() == TRUE) &&
     (!boot_dload_is_dload_mode_set()))
  {
    /* Get the size of training data */
    ddr_training_data_ptr = boot_ddr_params_get_training_data(&ddr_params_training_data_size);
	
	BL_VERIFY(((ddr_training_data_ptr != NULL) && (ddr_params_training_data_size != 0)), BL_ERR_NULL_PTR_PASSED|BL_ERROR_GROUP_BOOT);

   /* Read the ddr training data out, we use
     SCL_DDR_TRAINING_DATA_BUF_BASE which is tz base as a temporary buffer */
    sbl1_load_ddr_training_data_from_partition(ddr_training_data_ptr,
                                               ddr_params_training_data_size);


    /* Pass the training data to DDR driver */
    success = boot_ddr_params_set_training_data((void *)ddr_training_data_ptr,
                                               ddr_params_training_data_size);

    BL_VERIFY(success, BL_ERR_PASS_DDR_TRAINING_DATA_TO_DDR_DRIVER_FAIL|BL_ERROR_GROUP_DDR);
  }
}

/*===========================================================================

**  Function :  sbl1_pm_aop_pre_init_wrapper

** ==========================================================================
*/
/*!
*
* @brief
*   Do pre init procedure for AOP.
*
* @param[in]
*   bl_shared_data Pointer to shared data
*
* @par Dependencies
*   Must be called before loading AOP
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_pm_aop_pre_init_wrapper( bl_shared_data_type *bl_shared_data )
{
  BL_VERIFY((boot_pm_aop_pre_init()==PM_ERR_FLAG__SUCCESS),BL_ERROR_GROUP_DDR);
}

/*===========================================================================

**  Function :  sbl1_hw_play_vibr

** ==========================================================================
*/
/*!
*
* @brief
*   This function calls PMIC API to play power on vibration
*
* @param[in] bl_shared_data Pointer to shared data
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*/
void sbl1_hw_play_vibr(bl_shared_data_type *bl_shared_data)
{
  
  pm_err_flag_type pm_vib_on;

  if(!boot_dload_is_dload_mode_set())
  {
  	/*turn on vibrator*/
    pm_vib_on=boot_pm_vib_on();
	BL_VERIFY(pm_vib_on == PM_ERR_FLAG__SUCCESS || pm_vib_on == PM_ERR_FLAG_FEATURE_NOT_SUPPORTED,(uint16)pm_vib_on|BL_ERROR_GROUP_PMIC);
  }
  
}
