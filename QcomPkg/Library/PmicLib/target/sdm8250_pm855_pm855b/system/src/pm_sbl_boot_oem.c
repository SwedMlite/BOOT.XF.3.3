/*! \file pm_sbl_boot_oem.c
*  \n
*  \brief This file contains PMIC device initialization function where initial PMIC
*  \n SBL settings are configured through the PDM auto-generated code.
*  \n
*  \n &copy; Copyright 2015-2019 QUALCOMM Technologies Incorporated, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/target/sdm8250_pm855_pm855b/system/src/pm_sbl_boot_oem.c#16 $
$Author: pwbldsvc $
$DateTime: 2020/01/26 23:37:00 $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
02/01/18   aab     Updated PMI_CLK_DIST_ADDR to be VREG_SP
12/22/17   pxm     Change SRAM access to DMA support
09/28/17   pxm     Remove the code which turning off L24A for EUD check.
09/13/17   aab     Added target specific fn: pm_spmi_tgt_vrm_init()
07/10/17   pxm     Loader to provide OTP Read API for VBAT,IBAT Gain offset
06/13/17   czq     Configure BATT_ID bias delay.
04/06/17   aab	   Updated pm_driver_post_init(): Turn off EUD Rail if VBUS is detected 
03/07/17   ds	   Removed the call to pm_aop_pre_init()
01/16/17   aab     Updated pm_driver_post_init() to support SDM845
06/01/16   aab     Updated pm_driver_post_init() to add RF_CLK Drive strength configuration if CDP is detected
04/29/15   aab     Updated pm_device_post_init() 
12/04/15   aab     Updated to support MSM8998 target 
12/04/15   aab     Creation
========================================================================== */
/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_sbl_boot_target.h"
#include "pm_pon.h"
#include "pm_app_pon.h"
#include "pm_sbl_boot.h"
#include "pm_device.h"
#include "pm_comm.h"
#include "pm_utils.h"
#include "pm_schg_usb.h"
#include "DDIChipInfo.h"
#include "ChipInfo.h"
#include "pm_sdam_driver.h"
#include <stdio.h>
#include "boot_logger.h"
#include "CoreVerify.h"
#include "pm_ldo.h"
#include "pm_bob.h"
#include "DALDeviceId.h"
#include "DDIPlatformInfo.h"
#include "DDIChipInfo.h"
#include "pm_app_vreg.h"
#include "pm_target_information.h"
#include "pm_clk.h"
#include "pm_fg_adc_rr.h"
#include "pm_fg_sram.h"
#include "pm_pbs_driver.h"
#include "pm_version.h"
#include "pm_pbs_info.h"
#include "pm_log_utils.h"
#include "pm_fg_sram.h"
#include "boothw_target.h"
#include "DDIPlatformInfo.h"
#include "SpmiCfg.h"


/*===========================================================================

                        TYPE DEFINITIONS 

===========================================================================*/
#define PM_VREG_SP_SID    0
#define PM_VREG_SP_ADDR   0x3E00
#define REVID_SBL_ID_0    0x150
#define REVID_SBL_ID_1    0x151

#define PM_SDCARD_DET_MGPI_INDEX 4

#define OTP_VERSION_LSB_ADDR     0x160
#define OTP_VERSION_MSB_ADDR     0x161
#define PON_RESET_N_CTL_ADDR     0x899
#define ASSERT_RESET_N           0x0
#define PMX_55_PRIMARY_SLAVE_ID  0x8

#define BOB_SLAVE_ID             0x5
#define BOB_RGB_HR_FORCE_EN_REG  0xA032
#define RGB_HR_FORCE_EN          0x40
#define RGB_HR_FORCE_EN_MASK     0x40

#define SDAM1_MEM_127       127
#define BYTE_CNT            1 
#define SKIP_BOB_RGB_HR     0x1
#define CLEAR_SKIP_SETTING  0x0

#define SDAM1_MEM_127_REG         0xB0BF
#define CDP_PLATFORM              0x1
#define NON_CDP_PLATFORM          0x0
#define PM_SDAM_SLAVE_ID          0x0


static pm_sdam_reg_info_type sdam_reg =
{
  .base_address      = 0xB000,
  .peripheral_offset = 0x100,
  .trig_busy_ret     = 0x0043,
};

/*===========================================================================

                        FUNCTION DEFINITIONS 

===========================================================================*/

pm_err_flag_type
pm_device_pre_init(void)
{
  uint32                slave_id        = 0;
  uint32                num_of_sdam     = 0;
  peripheral_info_type  peripheral_info;
  pm_comm_info_type*    comm_info       = NULL;
  pm_err_flag_type      err_flag        = PM_ERR_FLAG_SUCCESS;
  pm_sbl_specific_data_type *config_param_ptr = NULL;

  config_param_ptr = (pm_sbl_specific_data_type*)
            pm_target_information_get_specific_info(PM_PROP_SBL_SPECIFIC_DATA);
  CORE_VERIFY_PTR(config_param_ptr);

  // This is used by PSI as a scratch register to check for which
  // configuration to load for swire map
  if ( config_param_ptr->swire_cfg.supported &&
       config_param_ptr->swire_cfg.swire_map < PM_SWIRE_MAP_INVALID )
  {
    err_flag |= pm_comm_write_byte_mask(5, 0xDC5F, 0x3,
                         (uint8)config_param_ptr->swire_cfg.swire_map);
  }
  if(err_flag != PM_ERR_FLAG_SUCCESS)
  {
    return err_flag;
  }
  
  //Clear PBS_RET for each sdam
  for(uint8 i = 0; i < PM_MAX_NUM_PMICS; i++)
  {
    num_of_sdam = 0;

    err_flag = pm_get_slave_id(i, 0, &slave_id);
  
    if(err_flag != PM_ERR_FLAG_SUCCESS)
  {
    err_flag = PM_ERR_FLAG_SUCCESS;
    continue;
  }
      
    num_of_sdam = 
    pm_target_information_get_periph_count_info(PM_PROP_SDAM_NUM, i);

    //Since poipu has an smb configuration as well check for smb and make sdam as 0

    comm_info = pm_comm_get_comm_info(i, 0);
    if(comm_info == NULL)
    {
      CORE_VERIFY(0);
    }
 
    for(uint8 j = 0; j < num_of_sdam; j++)
    {
      memset(&peripheral_info, 0, sizeof(peripheral_info_type));
  
      peripheral_info.base_address = (sdam_reg.base_address) + 
                                     (j * sdam_reg.peripheral_offset);
            
    err_flag = pm_comm_write_byte(comm_info->slave_id, peripheral_info.base_address + sdam_reg.trig_busy_ret,0x00);
    if(err_flag != PM_ERR_FLAG_SUCCESS)
      {
        return err_flag;
      }
    }
  }
  
  if ( config_param_ptr->rfclk2_config_flag )
  {
    err_flag |= pm_comm_write_byte(0, 0x5547, 0x0); // Do NOT follow pin control
    err_flag |= pm_comm_write_byte(0, 0x5548, 0x80);  // Enable pull down for RF_CLK2 peripheral
  }
  
  /* For CDP, PSI will use this flag to skip S8C_RC trim sequence */
  if (DALPLATFORMINFO_TYPE_CDP == DalPlatformInfo_Platform())
  {
    err_flag |= pm_comm_write_byte(PM_SDAM_SLAVE_ID, SDAM1_MEM_127_REG, CDP_PLATFORM);
  }
  else
  {
    err_flag |= pm_comm_write_byte(PM_SDAM_SLAVE_ID, SDAM1_MEM_127_REG, NON_CDP_PLATFORM);
  }

  return err_flag; 
}


pm_err_flag_type
pm_device_post_init ( void )
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  DALResult              eResult = DAL_SUCCESS ;
  uint8 SBL_ID_0 = 0;
  uint8 SBL_ID_1 = 0;

  uint8 otp_version_lsb = 0;
  uint8 otp_version_msb = 0;

  DalPlatformInfoPlatformInfoType platform_info; 
  static DalDeviceHandle          *phPlatformInfo = NULL;;
  
  if (phPlatformInfo == NULL)
  {
    eResult = DAL_DeviceAttach(DALDEVICEID_PLATFORMINFO, &phPlatformInfo);
    if (eResult != DAL_SUCCESS)
    {
      CORE_VERIFY(0);
    }
  }
  
  err_flag |= pm_comm_read_byte(0, REVID_SBL_ID_1, &SBL_ID_1);
  err_flag |= pm_comm_read_byte(0, REVID_SBL_ID_0, &SBL_ID_0);
  if(err_flag != PM_ERR_FLAG_SUCCESS )
  {
    return err_flag;
  }
  pm_log_message("PSI: b0x%02x_v0x%02x", SBL_ID_1, SBL_ID_0);
  
  DalPlatformInfo_GetPlatformInfo(phPlatformInfo, &platform_info);  

  //These configurations is only used for development phones
  //and should be commented out for production phones
  err_flag |= pm_app_pon_pshold_cfg(PM_APP_PON_CFG_HARD_RESET);

  //PON KPDPWR PON Reset configuration
  err_flag |= pm_app_pon_reset_cfg(PM_APP_PON_RESET_SOURCE_KPDPWR,
                                   PM_APP_PON_CFG_WARM_RESET, 10256, 2000);

  //PON RESIN_AND_KPDPWR PON Reset configuration
  err_flag |= pm_app_pon_reset_cfg(PM_APP_PON_RESET_SOURCE_RESIN_AND_KPDPWR,
                                  PM_APP_PON_CFG_DVDD_HARD_RESET, 10256, 2000);

  err_flag |= pm_app_pon_reset_init();

  /*check for valid PON keypress */
  err_flag |= pm_app_pwrkey_long_press_check(PM_PON_PWRKEY_DBNC_CHK_AT_LOADER);

  if(platform_info.fusion == TRUE)
  {
    err_flag |= pm_comm_read_byte(PMX_55_PRIMARY_SLAVE_ID, OTP_VERSION_MSB_ADDR, &otp_version_msb);
    err_flag |= pm_comm_read_byte(PMX_55_PRIMARY_SLAVE_ID, OTP_VERSION_LSB_ADDR, &otp_version_lsb);

    /*For OTP 0x0b0x14 run the WA*/
    if ((otp_version_msb == 0x14) && (otp_version_lsb == 0x00))
    {
       /*WA for SDX55 OTP Warmreset issue pull pon_reset_n low at boot*/
       err_flag |= pm_comm_write_byte(PMX_55_PRIMARY_SLAVE_ID, PON_RESET_N_CTL_ADDR, ASSERT_RESET_N);
    }
  }
  
  /*Enable L5C via PBS Vote, required for RF_CAL on huracan, to be removed once added in PSI */
  err_flag |= pm_comm_write_byte(0x5, 0x4449, 0xC0);

  return err_flag;

}




pm_err_flag_type
pm_driver_pre_init (void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

  return err_flag;
}

pm_err_flag_type
pm_driver_post_init(void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

  err_flag |= pm_app_vreg_clear_ocp_status();

  pm_register_data_type skip_bob_rgb_hr = SKIP_BOB_RGB_HR;

  /* when MTP is detected changing RFCLK1 DRV to 2x for Wailua(PMIC_A)
     to counter RFCLK signal integrity issue which caused EVM issue.*/
  if (DALPLATFORMINFO_TYPE_MTP == DalPlatformInfo_Platform())
  {
    err_flag |= pm_clk_drv_strength(PMIC_A, PM_CLK_RF_1, PM_CLK_DRV_STRENGTH_2X);
  }

  /*SW WA: for CDP 1.x prevent BOM transfer becase of PBS trigger to set RGB HR on BOB*/
  if ((DALPLATFORMINFO_TYPE_CDP == DalPlatformInfo_Platform())
      && (ChipInfo_GetChipVersion() < CHIPINFO_VERSION(2, 0)))
  {
    err_flag |= pm_sdam_mem_write(PMIC_A, PM_SDAM_1, SDAM1_MEM_127, BYTE_CNT, &skip_bob_rgb_hr);
    /*keep BOB_CFG HR enabled*/
    err_flag = pm_comm_write_byte_mask(BOB_SLAVE_ID, BOB_RGB_HR_FORCE_EN_REG, RGB_HR_FORCE_EN_MASK, RGB_HR_FORCE_EN);

  }
  else
  {
    /*clear SDAM register to prevent unwanted behaviour from junk values*/
    skip_bob_rgb_hr = CLEAR_SKIP_SETTING;

    err_flag |= pm_sdam_mem_write(PMIC_A, PM_SDAM_1, SDAM1_MEM_127, BYTE_CNT, &skip_bob_rgb_hr);
  }

      return err_flag;
}

pm_err_flag_type
pm_sbl_chg_pre_init (void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

  /*  Start battery id conversion in continuous mode.
    Next image (UEFI) would need to stop this mode */
  err_flag |= pm_sbl_set_batt_id_forced_mode(TRUE);

  if (PMIC_IS_PM855B == pm_get_pmic_model(PMIC_B))
  {
    err_flag |= pm_comm_write_byte_mask(2, 0x1189, 0x03, 0x01);  // [FTRIM] Change VPH tracking threshold to 200mV

    pm_pbs_info_type pbs_info;
    err_flag |= pm_get_pbs_info(PMIC_B, &pbs_info);
    if (PM_ERR_FLAG_SUCCESS != err_flag)
    {
      return err_flag;
    }

    if (1 == pbs_info.fab_id) // FAB_ID 1: SMIC, 2: TSMC
    {
      err_flag |= pm_comm_write_byte(2, 0x13C1, 0x04); // [FTRIM] For 7V, 0.8MHz
      err_flag |= pm_comm_write_byte(2, 0x13C2, 0x08); // [FTRIM] For 9V, 1.0MHz
      err_flag |= pm_comm_write_byte(2, 0x13C3, 0x08); // [FTRIM] For 12V, 1.2MHz
    }
  }

  return err_flag;
}


pm_err_flag_type
pm_sbl_chg_post_init ( void )
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;

  if (PMIC_IS_PM855B == pm_get_pmic_model(PMIC_B))
  {
    err_flag |= pm_comm_write_byte_mask(2, 0x1189, 0x03, 0x00);  // [FTRIM] Change VPH tracking threshold to 100mV
  }

  return err_flag;
}


pm_err_flag_type
pm_spmi_tgt_vrm_init ( SpmiBusCfg_Ppid *pm_vrm_rsrc_arr,
                       uint32 *vrm_cfg_index,
                       uint8 vrm_rsrc_arr_size )
{
  pm_err_flag_type err_flag   = PM_ERR_FLAG_SUCCESS;

  if (*vrm_cfg_index >= vrm_rsrc_arr_size)
  {
    return err_flag = PM_ERR_FLAG_INVALID_PARAMETER;
  }

  pm_vrm_rsrc_arr[*vrm_cfg_index].slaveId = PM_VREG_SP_SID;
  pm_vrm_rsrc_arr[*vrm_cfg_index].address = PM_VREG_SP_ADDR;
  (*vrm_cfg_index)++;

  return err_flag;
}


pm_err_flag_type
pm_tgt_mgpi_cfg ( SpmiBusCfg_MgpiPortCfg **mgpi_port_cfg_ptr )
{
  pm_err_flag_type err_flag   = PM_ERR_FLAG_SUCCESS;

  if(NULL == mgpi_port_cfg_ptr)
  {
    return PM_ERR_FLAG_INVALID_PARAMETER;
  }

  DalPlatformInfoPlatformType platform_type = DalPlatformInfo_Platform();
  if(DALPLATFORMINFO_TYPE_QRD == platform_type)
  {
    if(NULL == mgpi_port_cfg_ptr[PM_SDCARD_DET_MGPI_INDEX])
    {
      return PM_ERR_FLAG_INVALID_PARAMETER;
    }

    SpmiBusCfg_MgpiPortCfg sd_config = *mgpi_port_cfg_ptr[PM_SDCARD_DET_MGPI_INDEX];
    sd_config.negEdgeEn = TRUE;
    sd_config.muxSelEn = TRUE;

    if ( SpmiCfg_ConfigureMgpiPort(&sd_config) != SPMI_SUCCESS )
    {
      return PM_ERR_FLAG_BUS_ERR;
    }
  }

  return err_flag;
}

pm_err_flag_type pm_tgt_aop_pre_init(void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  return err_flag;
}