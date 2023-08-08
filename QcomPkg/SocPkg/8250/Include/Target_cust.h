#ifndef _TARGET_CUST_H
#define _TARGET_CUST_H

/*===========================================================================

                                Target_cust
                                Header File

GENERAL DESCRIPTION
  This header file contains target specific declarations and definitions

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright 2018-2019 by Qualcomm Technologies, Inc.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who          what, where, why
--------   --------     ----------------------------------------------------------
03/27/19   c_vkuppa     Align buffer to cache line length
01/22/19   yps         Clean unused definitions
08/29/18   msantos     Added SBL crash dump region
07/30/18   ds          Initial version for SM8250 with memory map update
============================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "../Include/Soc_cust.h"

/*===========================================================================
              DEFINES FOR TARGET (equivalent to <target>.builds src)
===========================================================================*/

#define SECURE_REGION                    0x14699000
#define SECURE_REGION_SIZE               0x15000

// OEM_MISC - BOOT_IMEM_END - 16 KB (12 KB + 4 KB reserved)
#define SCL_MULTI_IMAGE_CODE_BASE        (SCL_BOOT_IMEM_BASE_ADDR + SCL_BOOT_IMEM_XBL_END - SIZE_16KB)
#define SCL_MULTI_IMAGE_TOTAL_SIZE       SIZE_12KB

#define SCL_BOOTROM_MEMORY_REGION        (SIZE_84KB)
#define SCL_BOOT_IMEM_START_XBL_UNUSED   (SCL_BOOTROM_MEMORY_REGION)

/*===========================================================================
                 Defines to support enhanced boot logging
============================================================================*/
#define BOOT_LOGGER_BOOT_CONFIG_FUSE_ADDRESS           HWIO_BOOT_CONFIG_ADDR
#define BOOT_LOGGER_JTAG_ID_FUSE_ADDRESS               HWIO_JTAG_ID_ADDR
#define BOOT_LOGGER_OEM_ID_FUSE_ADDRESS                HWIO_OEM_ID_ADDR
#define BOOT_LOGGER_SERIAL_NUM_FUSE_ADDRESS            HWIO_SERIAL_NUM_ADDR
#define BOOT_LOGGER_OEM_CONFIG_ROW_0_FUSE_ADDRESS      HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR
#define BOOT_LOGGER_OEM_CONFIG_ROW_1_FUSE_ADDRESS      HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR 
#define BOOT_LOGGER_FEATURE_CONFIG_ROW_0_FUSE_ADDRESS  HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR
#define BOOT_LOGGER_FEATURE_CONFIG_ROW_1_FUSE_ADDRESS  HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR
#define BOOT_LOGGER_PBL_VERSION                        (HWIO_FEATURE_CONFIG14_INM(HWIO_FEATURE_CONFIG14_APPS_PBL_PATCH_VERSION_BMSK)>>HWIO_FEATURE_CONFIG14_APPS_PBL_PATCH_VERSION_SHFT)

#endif  /* _TARGET_CUST_H */
