/*! \file pm_app_pon_log.c
*  
*  \brief Implementation file for PON APP level logger APIs.
*    
*  &copy; Copyright 2016-2019 QUALCOMM Technologies Incorporated, All Rights Reserved
*/
/*===================================================================
EDIT HISTORY FOR MODULE
 This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.

$Date  2018/07/02 $ 
$Change  16554216 $

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/app/pon/src/pm_app_pon_log.c#6 $
$Author: pwbldsvc $
$DateTime: 2019/10/14 19:17:11 $
when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
01/10/17   aab     Updated PON logging Text
09/13/16   aab     Updated PON logging
08/03/16   akm     Creation
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_pon.h"
#include "pm_pbs_info.h"
#include "pm_device.h"
#include "LoaderUtils.h"
#include "pm_app_pon.h"
#include "pmio_pon.h"
#include "pm_err_flags.h"
#include "device_info.h"
#include "hw_module_type.h"
#include "pm_config_target.h"
#include "pm_sbl_boot_target.h"
#include "pm_pon_target.h"
#include "pm_target_information.h"
#include "CoreVerify.h"
#include "pm_log_utils.h"
#include <string.h> 

/*===========================================================================

                     Global Variables

===========================================================================*/
typedef struct
{
  uint8 pon_reason1;
  uint8 pon_reason2;
  uint8 poff_reason1;
  uint8 poff_reason2;
  uint8 warm_reset_reason1;
  uint8 warm_reset_reason2;
  uint8 soft_reset_reason1;
  uint8 soft_reset_reason2;
}pm_reason_status_type;

typedef struct
{
  uint8 pon_reason1;
  uint8 reserved1;
  uint8 warm_reset_reason1;
  uint8 reserved2;
  uint8 on_reason;
  uint8 poff_reason1;
  uint8 reserved3;
  uint8 off_reason;
}pm_pon_gen2_reason_status_type;

typedef struct
{
  uint8 fault_reason1;
  uint8 fault_reason2;
  uint8 s3_reset_reason;
  uint8 soft_reset_reason1;
}pm_pon_gen2_fault_status_type;

#define PON_REASON_SIZE 16
#define PON_POS_INVALID 0xFF
#define PON_TEMP_BUFF_LENG 96

/*===========================================================================

                   Function Prototypes

===========================================================================*/

static pm_err_flag_type pm_app_log_verbose_pon_reason_gen2(void);
static uint8 find_first_non_zero_bit(uint8 reason1, uint8 reason2);

extern pm_err_flag_type pm_pbs_mem_get_dataset_size(uint32  pmic_index, uint32* dataset_size, pm_pbs_header_dataset_type dataset_type);

/*===========================================================================

                   API Implementation

===========================================================================*/

pm_err_flag_type
pm_log_pon_reasons(void)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  pm_model_type pmic_model = PMIC_IS_INVALID;
  uint8 pmic_index = 0;
  uint8 sid_index = 0;
  uint32 pon_peripheral_index = 8;
  uint64 pon_reasons = 0x00;
  uint64 fault_reasons = 0x00;
  peripheral_info_type pon_peripheral_info;

  memset(&pon_peripheral_info, 0, sizeof(peripheral_info_type));
  pon_peripheral_info.base_address = pon_peripheral_index * 0x0100;

  //Log PON reasons for all PMIC
  for (pmic_index = 0; pmic_index < PM_MAX_NUM_PMICS; pmic_index++)
  {
    pmic_model = pm_get_pmic_model(pmic_index);
    if((pmic_model != PMIC_IS_INVALID) && (pmic_model != PMIC_IS_UNKNOWN))
    {
      //Get PON perepheral type and perepheral sub type for each valid PMIC on target
      sid_index = pmic_index * 2;
      pm_get_peripheral_info(sid_index, &pon_peripheral_info);

      if(pon_peripheral_info.peripheral_subtype < PM_HW_MODULE_PON_LV_PON_GEN2_PRIMARY)
      {
        continue;
      }

      pon_reasons = 0x00;
      err_flag |= pm_pon_get_all_pon_reasons(pmic_index, &pon_reasons);
      if(err_flag != PM_ERR_FLAG_SUCCESS)
      {
        return err_flag;
      }

      fault_reasons = 0x00;
      err_flag |= pm_pon_get_fault_reasons(pmic_index, &fault_reasons);
      if(err_flag != PM_ERR_FLAG_SUCCESS)
      {
        return err_flag;
      }
      pm_log_message("PM %d=0x%llx:0x%llx ", pmic_index, (uint64)pon_reasons, (uint64)fault_reasons);
    }
  }

  // If primary PMIC is later then GEN2, then parse the PON reason.
  // TODO: PMIC_A is not always primary PMIC index
  sid_index = pm_get_primary_pmic_index() * PM_MAX_NUM_SLAVE_IDS_PER_PMIC;
  pm_get_peripheral_info(sid_index, &pon_peripheral_info);
  if(pon_peripheral_info.peripheral_subtype >= PM_HW_MODULE_PON_LV_PON_GEN2_PRIMARY)
  { //PON GEN2
    err_flag |= pm_app_log_verbose_pon_reason_gen2();
  }

  return err_flag;
}

pm_err_flag_type 
pm_app_log_verbose_pon_reason_gen2(void)
{
  uint8 pon_on_bit_num = 0;
  uint8 pon_off_bit_num = 0;
  uint8 other_off_bit_num = 0;
  uint8 fault_bit_num = 0;
  uint8 s3_reset_bit_num = 0;
  uint8 warm_reset_bit_num = 0;
  uint64 pon_reasons = 0x00;
  uint64 fault_reason = 0x00;
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  pm_pon_gen2_reason_status_type *reasons_ptr = 0;
  pm_pon_gen2_fault_status_type *fault_reasons_ptr = 0;
  uint8 pmic_index = pm_get_primary_pmic_index();
  uint8 sid_index = 0;
  uint32 pon_peripheral_index = 8;
  peripheral_info_type pon_peripheral_info;
  char power_on_str[] = "POWER ON by";
  char power_off_str[] = "POWER OFF by";
  char *pon_off_reasons[PON_REASON_SIZE] =      {"KPDPWR",
                                                 "RESIN",
                                                 "KPDPWR_AND_RESIN",
                                                 "GP2","GP1",
                                                 "PMIC_WD",
                                                 "PS_HOLD",
                                                 "SOFT"};
  char *warm_reset_reasons[PON_REASON_SIZE] =   {"KPDPWR",
                                                 "RESIN",
                                                 "KPDPWR_AND_RESIN",
                                                 "GP2","GP1",
                                                 "PMIC WD",
                                                 "PS_HOLD",
                                                 "SOFT"};
  char *pon_on_reasons[PON_REASON_SIZE] =       {"KPDPWR",
                                                 "CBLPWR",
                                                 "PON1",
                                                 "USB_CHG",
                                                 "DC_CHG",
                                                 "RTC",
                                                 "SMPL", 
                                                 "HARD_RESET"};
  char *fault_reasons[PON_REASON_SIZE] =        {"AVDD_RB",
                                                 "UVLO",
                                                 "OVLO",
                                                 "MBG_FAULT",
                                                 "GP_FAULT3",
                                                 "GP_FAULT2",
                                                 "GP_FAULT1",
                                                 "GP_FAULT0",
                                                 "OTST3",
                                                 "RESTART_PON",
                                                 "PBS_NACK",
                                                 "PBS_WD_TO",
                                                 "FAULT_N"};
  char *s3_reset_reasons[PON_REASON_SIZE] =     {"KPDPWR_ANDOR_RESIN",
                                                 "PBS_NACK",
                                                 "PBS_WATCHDOG_TO",
                                                 "FAULT_N"};
  char *other_off_reasons[PON_REASON_SIZE] =    {"IMM_XVDD_SD",
                                                 "RAW_DVDD_SHD",
                                                 "RAW_XVDD_SHD"};

  memset(&pon_peripheral_info, 0, sizeof(peripheral_info_type));
  pon_peripheral_info.base_address = pon_peripheral_index * 0x0100;

  err_flag |= pm_pon_get_all_pon_reasons(pmic_index, &pon_reasons);
  reasons_ptr = (pm_pon_gen2_reason_status_type*)(&pon_reasons);

  err_flag |= pm_pon_get_fault_reasons(pmic_index, &fault_reason);
  if(err_flag != PM_ERR_FLAG_SUCCESS)
  {
    return err_flag;
  }
  fault_reasons_ptr = (pm_pon_gen2_fault_status_type*) (&fault_reason);

  //ON Reason
  if((uint8)reasons_ptr->on_reason & PMIO_PON_GEN2_ON_REASON_PON_SEQ_BMSK)
  {
    if((uint8)reasons_ptr->pon_reason1 & PMIO_PON_PON_REASON1_HARD_RESET_BMSK)
    {
      pon_on_bit_num = find_first_non_zero_bit((uint8)reasons_ptr->poff_reason1, 0);
      if(pon_on_bit_num != PON_POS_INVALID)
      {
        pm_log_message("HARD RESET by %s", pon_off_reasons[pon_on_bit_num]);
      }
    }
    else
    {
      pon_on_bit_num = find_first_non_zero_bit((uint8)reasons_ptr->pon_reason1, 0);

      if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_POFF_SEQ_BMSK)
      {
        pon_off_bit_num = find_first_non_zero_bit((uint8)reasons_ptr->poff_reason1, 0);
        if((pon_off_bit_num != PON_POS_INVALID) && (pon_on_bit_num != PON_POS_INVALID))
        {
          pm_log_message("%s %s, %s %s", power_on_str, pon_on_reasons[pon_on_bit_num], power_off_str, pon_off_reasons[pon_off_bit_num]);
        }
      }
      else if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_FAULT_SEQ_BMSK)
      {
        if((PMIO_PON_GEN2_FAULT_REASON2_FAULT_N_BMSK & fault_reasons_ptr->fault_reason2) != 0)
        {
          // FAULT_REASON2
          // For the scenario of FAULT triggerred from non-primary PMIC, iterate the following PMICs to find out the fault reason
          fault_bit_num = 0;
          for (pmic_index = 1; pmic_index < PM_MAX_NUM_PMICS; pmic_index++)
          {
            sid_index = pmic_index * 2;
            pm_get_peripheral_info(sid_index, &pon_peripheral_info);
            if((pon_peripheral_info.peripheral_type != PM_HW_MODULE_PON) ||
              (pon_peripheral_info.peripheral_subtype < PM_HW_MODULE_PON_LV_PON_GEN2_PRIMARY))
            {
              // in case the PMIC doesn't have PON peripheral or old PON peripheral.
              continue;
            }

            fault_reason = 0x00;
            if(pm_is_pmic_present(pmic_index) == FALSE)
            {
              continue;
            }
            err_flag |= pm_pon_get_fault_reasons(pmic_index, &fault_reason);
            if(err_flag != PM_ERR_FLAG_SUCCESS)
            {
              return err_flag;
            }

            fault_reasons_ptr = (pm_pon_gen2_fault_status_type*) (&fault_reason);
            if((PMIO_PON_GEN2_FAULT_REASON2_FAULT_N_BMSK & fault_reasons_ptr->fault_reason2) != 0)
            {
              continue;
            }
            else
            {
              fault_bit_num = find_first_non_zero_bit((uint8)fault_reasons_ptr->fault_reason1, (uint8)fault_reasons_ptr->fault_reason2);
              if((fault_bit_num != PON_POS_INVALID) && (pon_on_bit_num != PON_POS_INVALID))
              {
                pm_log_message("%s %s, POWER OFF due to FAULT %s of PM %d", power_on_str, pon_on_reasons[pon_on_bit_num], fault_reasons[fault_bit_num], pmic_index);
                break;
              }
            }
          }
        }
        else
        {
          fault_bit_num = find_first_non_zero_bit((uint8)fault_reasons_ptr->fault_reason1, (uint8)fault_reasons_ptr->fault_reason2);
          if((fault_bit_num != PON_POS_INVALID) && (pon_on_bit_num != PON_POS_INVALID))
          {
            pm_log_message("%s %s, POWER OFF due to FAULT %s", power_on_str, pon_on_reasons[pon_on_bit_num], fault_reasons[fault_bit_num]);
          }
        }
      }
      else if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_S3_RESET_BMSK)
      {
        s3_reset_bit_num = find_first_non_zero_bit((uint8)fault_reasons_ptr->s3_reset_reason, 0);
        if((s3_reset_bit_num != PON_POS_INVALID) && (pon_on_bit_num != PON_POS_INVALID))
        {
          pm_log_message("%s %s, %s S3 reset %s", power_on_str, pon_on_reasons[pon_on_bit_num], power_off_str, s3_reset_reasons[s3_reset_bit_num]);
        }
      }
      else if((uint8)fault_reasons_ptr->soft_reset_reason1 != 0x00)
      {
        pm_log_message("SOFT_RESET_REASON1:SOFT");
      }
      else
      {
        if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_IMM_XVDD_SD_BMSK)
        {
          other_off_bit_num = 0;
        }
        else if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_RAW_DVDD_SHD_BMSK)
        {
          other_off_bit_num = 1;
        }
        else if((uint8)reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_RAW_XVDD_SHD_BMSK)
        {
          other_off_bit_num = 2;
        }
        if((other_off_bit_num != PON_POS_INVALID) && (pon_on_bit_num != PON_POS_INVALID))
        {
          pm_log_message("%s %s,%s %s", power_on_str, pon_on_reasons[pon_on_bit_num], power_off_str, other_off_reasons[other_off_bit_num]);
        }
      }
    }
  }
  else
  {
    warm_reset_bit_num = find_first_non_zero_bit((uint8)reasons_ptr->warm_reset_reason1, 0);
    if(warm_reset_bit_num != PON_POS_INVALID)
    {
      pm_log_message("WARM reset by %s", warm_reset_reasons[warm_reset_bit_num]);
    }
  }

  return err_flag;
}

/*
 * This API returns past two PON reason history for given PMIC index.
 *
 * @param pmic_device_index [in]: pmic index. Like PMIC_A, PMIC_B...
 * @param history [out]: Used to carry out the pon history of required pmic. Should be non-NULL
 *
 * @return error flag if any error taking place.
 */
pm_err_flag_type pm_pon_get_pon_reason_history(uint8 pmic_device_index, pon_reason_hist_type* history)
{
  pm_err_flag_type err_flag  = PM_ERR_FLAG_SUCCESS;
  pm_model_type pmic_model   = PMIC_IS_INVALID;
  uint32 pon_dataset_size    = 0;
  uint8 copy_data_count      = 0;
  uint64 pon_history_temp    = 0;

  if(NULL == history)
  {
    return PM_ERR_FLAG_INVALID_PARAMETER;
  }

  // Read pon history reason from SDAM for required PMIC,
  // but currently PBS populate pon history for primary PMIC only
  pmic_model =  pm_get_pmic_model(pmic_device_index);
  if ((pmic_device_index >= PM_MAX_NUM_PMICS) || (pmic_model == PMIC_IS_INVALID) || (pmic_model == PMIC_IS_UNKNOWN))
  {
    return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
  }

  pm_pbs_mem_get_dataset_size(pmic_device_index, &pon_dataset_size, PM_PBS_HEADER_PON_REASON_DATASET);
  uint32 pon_hist_dataset[pon_dataset_size];
  DALSYS_memset(pon_hist_dataset, 0,  pon_dataset_size * sizeof(uint32));

  // Get pon history dataset
  pm_pbs_ram_dataset_read(pmic_device_index, pon_hist_dataset, pon_dataset_size, PM_PBS_HEADER_PON_REASON_DATASET);

  // Start from 2 to skip BOOT1 pon reason, which can be read from register directly
  for(copy_data_count = 2; copy_data_count < NO_OF_PON_RSN_PER_PMIC; copy_data_count += 2) // each history contain 8 bytes
  {
    // conbine two continuous 32bit length dataset to get 64bit pon history data
    pon_history_temp = (uint64)pon_hist_dataset[copy_data_count + 1] << 32 | pon_hist_dataset[copy_data_count];

    // hist_reasons[] data structure is 64 bit length and follow the data order defined in SDAMM_regmaps sheet
    // so we can transform from uint64 raw data directly
    history->hist_reasons[(copy_data_count / 2) - 1] = *(pon_sdam_reasons_data_type *)&pon_history_temp;
  }

  return err_flag;
}

/*
 * This API parse and log PON reason history for given PMIC index.
 *
 * @param pmic_device_index [in]: pmic index. Like PMIC_A, PMIC_B...
 * @param history [out]: Used to carry out the pon history of required pmic. Should be non-NULL
 *
 * @return error flag if any error taking place.
 */
pm_err_flag_type pm_pon_parse_pon_reason_history(uint8 pmic_device_index)
{
  pm_err_flag_type err_flag = PM_ERR_FLAG_SUCCESS;
  pm_model_type pmic_model  = PMIC_IS_INVALID;
  uint64 pon_now_reasons = 0x00;
  pm_pon_gen2_reason_status_type *pon_now_reasons_ptr = 0;
  pon_reason_hist_type history;
  char pon_log_buffer[PON_TEMP_BUFF_LENG];
  uint8 len_temp = 0;
  uint8 pon_reasons_num = 0;
  uint8 warm_reset_reasons_num = 0;
  uint8 on_reasons_num = 0;
  uint8 poff_reasons_num = 0;
  uint8 off_reasons_num = 0;
  uint8 fault1_reasons_num = 0;
  uint8 fault2_reasons_num = 0;
  uint8 s3_reset_reasons_num = 0;

  char *pon_reasons[PON_REASON_SIZE] = {"KPD", "CBL", "PON1", "USB", "DC", "RTC", "SMPL", "HARD"};
  char *warm_reset_reasons[PON_REASON_SIZE] = {"KPD", "RES", "COMBO", "GP2", "GP1", "WD", "PS", "SOFT"};
  char *on_reasons[PON_REASON_SIZE] = {"PON", "WARM"};
  char *poff_reasons[PON_REASON_SIZE] = {"KPD", "RES", "COMBO", "GP2", "GP1", "WD", "PS", "SOFT"};
  char *off_reasons[PON_REASON_SIZE] = {"POFF", "FLT", "S3", "IMM", "DVDD", "XVDD"};
  char *fault1_reasons[PON_REASON_SIZE] = {"AVDD", "UVLO", "OVLO", "MBG", "GP3", "GP2", "GP1", "GP0"};
  char *fault2_reasons[PON_REASON_SIZE] = {"OTST", "RST", "PBS", "WD", "FLT_N"};
  char *s3_reset_reasons[PON_REASON_SIZE] = {"KPD", "NACK", "WD", "FLT_N"};

  pmic_model = pm_get_pmic_model(pmic_device_index);
  if ((pmic_device_index >= PM_MAX_NUM_PMICS) || (pmic_model == PMIC_IS_INVALID) || (pmic_model == PMIC_IS_UNKNOWN))
  {
    return PM_ERR_FLAG_FEATURE_NOT_SUPPORTED;
  }

  /* Get latest pon reason to check off reason */
  err_flag |= pm_pon_get_all_pon_reasons(pmic_device_index, &pon_now_reasons);
  pon_now_reasons_ptr = (pm_pon_gen2_reason_status_type*)(&pon_now_reasons);

  if(pon_now_reasons_ptr->off_reason & PMIO_PON_GEN2_OFF_REASON_RAW_XVDD_SHD_BMSK)
  {
    // when BOOT1(latest boot) PON_OFF_REASON is RAW_XVDD_SHD, we will get invalid data from pbs
    return err_flag;
  }

  err_flag |= pm_pon_get_pon_reason_history(pmic_device_index, &history);
  
  /* only parse BOOT2(2nd) and BOOT3(oldest) pon reason history */
  for(int i = 0; i < PON_HISTORY_COUNT; i++)
  {
    DALSYS_memset(pon_log_buffer, 0,  PON_TEMP_BUFF_LENG);
    len_temp = qsnprintf(pon_log_buffer, PON_TEMP_BUFF_LENG, "PM%c_%d", 'A' + pmic_device_index, i + 2);

    if(history.hist_reasons[i].pon_reason1)
    {
      pon_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].pon_reason1, 0);
      if(pon_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " PON:%s", pon_reasons[pon_reasons_num]);
      }
    }

    if(history.hist_reasons[i].warm_reset_reasons1)
    {
      warm_reset_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].warm_reset_reasons1, 0);
      if(warm_reset_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " WR:%s", warm_reset_reasons[warm_reset_reasons_num]);
      }
    }

    if(history.hist_reasons[i].on_reason)
    {
      on_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].on_reason, 0);
      if(on_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " ON:%s", on_reasons[on_reasons_num]);
      }
    }

    if(history.hist_reasons[i].poff_reasons1)
    {
      poff_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].poff_reasons1, 0);
      if(poff_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " POFF:%s", poff_reasons[poff_reasons_num]);
      }
    }

    if(history.hist_reasons[i].off_reason)
    {
      off_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].off_reason, 0);
      if(off_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " OFF:%s", off_reasons[off_reasons_num]);
      }
    }

    if(history.hist_reasons[i].fault_reason1)
    {
      fault1_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].fault_reason1, 0);
      if(fault1_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " FAULT1:%s", fault1_reasons[fault1_reasons_num]);
      }
    }

    if(history.hist_reasons[i].fault_reason2)
    {
      fault2_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].fault_reason2, 0);
      if(fault2_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " FAULT2:%s", fault2_reasons[fault2_reasons_num]);
      }
    }

    if(history.hist_reasons[i].s3_reset_reason)
    {
      s3_reset_reasons_num = find_first_non_zero_bit(history.hist_reasons[i].s3_reset_reason, 0);
      if(s3_reset_reasons_num != PON_POS_INVALID)
      {
        len_temp += qsnprintf(pon_log_buffer + len_temp, PON_TEMP_BUFF_LENG - len_temp, " S3:%s", s3_reset_reasons[s3_reset_reasons_num]);
      }
    }

    pm_log_message("%s", pon_log_buffer);

    /* if BOOT2 pon reason PON_OFF_REASON is RAW_XVDD_SHD, then BOOT3 history is invalid data */
    if((i == 0) && (history.hist_reasons[i].off_reason & PMIO_PON_GEN2_OFF_REASON_RAW_XVDD_SHD_BMSK))
    {
      break; // ignore the BOOT3 history
    }
  }

  return err_flag;
}

/*
 * Some reasons contain 2 8 bits registers, that's why we have 2 reasons as input parameters here.
 * For example, FAULT reason has reason1 and reason2
 */
uint8 find_first_non_zero_bit(uint8 reason1, uint8 reason2)
{
  uint16 i = 0x8000;
  uint8 pon_on_bit_num = 0;
  uint16 reasons = ((reason1 << 8) | reason2);

  for (pon_on_bit_num = 0; pon_on_bit_num < 16; pon_on_bit_num++)
  {
    if((reasons & i) != 0)
    {
      break;
    }
    i = (i >> 1);
  }

  if(16 == pon_on_bit_num)
  {
    return PON_POS_INVALID;
  }

  return pon_on_bit_num;
}
