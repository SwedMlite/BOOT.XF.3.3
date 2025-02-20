#ifndef __PM_PBS_DRIVER_H__
#define __PM_PBS_DRIVER_H__

/*! \file  pm_pbs_driver.h
 *  
 *  \brief  This file contains the pmic PBS driver definitions for SBL1 boot.
 *  \details  This file contains the pm_pbs_ram_image_load & pm_pbs_ram_image_verify
 *  API definitions for SBl1 boot and also definitions for  other helper functions
 *  used in PBS driver.
 *  
 *  &copy; Copyright 2014-2018 QUALCOMM Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This document is created by a code generator, therefore this section will
  not contain comments describing changes made to the module.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/drivers/pbs/src/pm_pbs_driver.h#3 $
$Author: pwbldsvc $
$DateTime: 2019/06/17 18:09:44 $
when         who     what, where, why
----------   ---     ---------------------------------------------------------- 
07/16/2014     akm     Comm change Updates
12/18/2013   aab     Updated pm_pbs_ram_image_load() and  pm_pbs_ram_image_verify()  
03/20/2013   kt      Moving and renaming the file to pm_pbs_driver.h 
                     from pm_pbs.h.
10/19/2012   umr     PBS Core Driver.
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include "pm_err_flags.h"
#include "pmio_pbs_core.h"
#include "hw_module_type.h"
#include "device_info.h"
#include "busywait.h"
#include "pm_comm.h"

/*===========================================================================

                        TYPE DEFINITIONS 

===========================================================================*/
typedef enum
{
  PM_PBS_TYPE_RAM,
  PM_PBS_TYPE_ROM, // Also called PBS_OTP
  PM_PBS_TYPE_INVALID,
} pm_pbs_type;
/** 
  @struct pm_pbs_ram_data_type
  @brief The RAM image format type used to load the complete PBS 
         RAM image during PMIC device initialization.
 */
typedef struct  
{
  char word1; /* Val */
  char word2; /* Offset, Condition  */
  char word3; /* Base Addr, Test Mask */
  char word4; /* Command + SlaveID */
}pm_pbs_ram_data_type;

/** 
  @enum pm_pbs_access_type
  @brief Different modes that can be configured to access PBS 
         ROM/RAM.
 */
typedef enum
{
  PM_PBS_ACCESS_READ_SINGLE,
  PM_PBS_ACCESS_WRITE_SINGLE,
  PM_PBS_ACCESS_READ_BURST,
  PM_PBS_ACCESS_WRITE_BURST,
  PM_PBS_ACCESS_INVALID
}pm_pbs_access_type;

/** 
  @struct pm_pbs_custom_seq_data_type
  @brief The config type required for PBS custom sequences which 
         can be added in RAM. 
 */
typedef struct  
{
  uint32  max_num_seqs;      /* Max num of sequences that can be added */
  uint16  ram_start_addr;    /* PBS RAM addr from where the sequences can be added */
  uint16  poff_trig_id;      /* POFF PBS client */
  uint16  poff_otp_addr;     /* POFF OTP address */
  uint16  warmreset_trig_id; /* Warm reset PBS client */
  uint16  warmreset_otp_addr;/* Warm reset OTP address */
}pm_pbs_custom_seq_data_type;

/*=========================================================================
      Function Definitions
==========================================================================*/
/** 
 * @name pm_pbs_ram_image_load 
 *  
 * @brief This function is called to load complete RAM image to 
 *        PBS RAM. This function is currently called during PMIC
 *        device initialization to load the PBS RAM data.
 * 
 * @param[in]  pmic_chip. Primary PMIC chip: 0. Secondary PMIC Chip: 1
 * @param[in]  data: Pointer to PBS RAM data. 
 * @param[in]  size: Size of PBS RAM data. 
 *
 * @return  pm_err_flag_type
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *          else SPMI errors.
 */
pm_err_flag_type
pm_pbs_ram_image_load(uint32 slave_id, pm_pbs_ram_data_type *data, unsigned size);

/** 
 * @name pm_pbs_ram_image_verify 
 *  
 * @brief This function is called to verify whether complete RAM image
 *        is loaded correctly to PBS RAM.
 * 
 * @param[in]  slave_id. Primary PMIC chip: 0. Secondary PMIC 
 *       Chip: 1
 * @param[in]  data: Pointer to expected PBS RAM data to compare the
 *             read data against. 
 * @param[in]  size: Size of PBS RAM data. 
 *
 * @return  pm_err_flag_type
 *          PM_ERR_FLAG_DATA_VERIFY_ERR = if the data is not
 *          loaded correctly to PBS RAM.
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *          else SPMI errors.
 */
pm_err_flag_type
pm_pbs_ram_image_verify(uint32 slave_id, pm_pbs_ram_data_type *data, unsigned size);

/** 
 * @name pm_pbs_disable_access 
 *  
 * @brief This function disables access to PBS ROM/RAM. 
 *
 * NOTE: We need to call this function at the end of each PBS ROM/RAM read/write.
 *  
 * @param[in]  slave_id. Primary PMIC chip: Secondary PMIC Chip:
 * @param[in] pbs_type RAM or ROM
 *
 * @return  pm_err_flag_type 
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *          else SPMI ERROR.
 *  
 * @dependencies none
 */
pm_err_flag_type 
pm_pbs_disable_access(uint32 slave_id, pm_pbs_type pbs_type);

/** 
 * @name pm_pbs_config_access 
 *  
 * @brief This function configures access type to PBS ROM/RAM. 
 *        The PBS ROM/RAM can be accessed in READ SINGLE, WRITE
 *        SINGLE, READ BURST and WRITE BURST modes.
 *  
 * @param[in]  slave_id. Primary PMIC chip. Secondary PMIC Chip:
 * @param[in]  addr: PBS address for which the access has to 
 *             configured.
 * @param[in]  access_type: The mode at which you want to access 
 *             PBS ROM/RAM address. Refer to pm_pbs_access_type
 *             enum above for more details.
 * @param[in] pbs_type RAM or ROM
 *
 * @return  pm_err_flag_type 
 *          PM_ERR_FLAG_FEATURE_NOT_SUPPORTED = Invalid access
 *          type.
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *          else SPMI ERROR.
 *  
 * @dependencies none
 */
pm_err_flag_type 
pm_pbs_config_access(uint32 slave_id, uint16 addr, pm_pbs_access_type access_type, pm_pbs_type pbs_type);

/** 
 * @name pm_pbs_get_mem_info 
 *  
 * @brief This function gets PBS RAM memory information
 *  
 * @param[in]  slave_id. Primary PMIC chip: Secondary PMIC Chip:
 *
 * @return  pm_err_flag_type 
 *          PM_ERR_FLAG_FEATURE_NOT_SUPPORTED = Invalid access
 *          type.
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *          else SPMI ERROR.
 *  
 * @dependencies none
 *  */
pm_err_flag_type
pm_pbs_get_mem_info(uint32 slave_id, uint16 *pbs_start_addr,
                         uint16 *otp_size, uint16 *pbs_size);

#endif // __PM_PBS_DRIVER_H__
