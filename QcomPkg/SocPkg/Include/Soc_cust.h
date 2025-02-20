#ifndef _SOC_CUST_H
#define _SOC_CUST_H

/*===========================================================================

                                SOC_CUST
                                Header File

GENERAL DESCRIPTION
  This header file contains soc specific declarations and definitions

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright 2018-2020 by Qualcomm Technologies, Inc.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.


when       who          what, where, why
--------   --------     ----------------------------------------------------------
04/21/20   rama         Added OEM HYP base and size
08/07/19   yps          Removed temp buffer for pmic config,devcfg and hash 
07/11/19   yps          Updated SBL pIMEM and DDR base address
06/11/19   vk           Initial version branched from SOC
============================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/

/*===========================================================================
              DEFINES FOR TARGET (equivalent to <target>.builds src)
===========================================================================*/

#include "../../XBLLoader/Include/SizeInfo.h"

#define SCL_IMEM_BASE                    0x14680000
#define SCL_IMEM_SIZE                    SIZE_256KB

#define EXCEPTION_HANDLER_SIZE            SIZE_128B
#define EXCEPTION_HANDLER_NUM             16
#define SCL_SBL1_VECTOR_TABLE_SIZE       (EXCEPTION_HANDLER_NUM * EXCEPTION_HANDLER_SIZE)

/* SBL crash dump region defines */
#define BOOT_CRASH_DUMP_DATA_SIZE        (sizeof(boot_crash_dump_type))
#define BOOT_CRASH_DUMP_DATA_DUMP_ADDR   DDR_MEM_BASE_1
#define SCL_SBL1_DDR_DUMP_ADDR           (BOOT_CRASH_DUMP_DATA_DUMP_ADDR + BOOT_CRASH_DUMP_DATA_SIZE)
#define SCL_BOOT_IMEM_DUMP_ADDR          (SCL_SBL1_DDR_DUMP_ADDR + SCL_SBL1_DDR_SIZE)
#define SHARED_IMEM_DUMP_ADDR            (SCL_BOOT_IMEM_DUMP_ADDR + SCL_BOOT_IMEM_BASE_SIZE)

/* AOP region defines */
#define SCL_AOP_CODE_RAM_BASE            0x0B000000
#define SCL_AOP_CODE_RAM_SIZE            0x18000

#define SCL_AOP_DATA_RAM_BASE            0x0B0E0000
#define SCL_AOP_DATA_RAM_SIZE            0x8000

#define SCL_AOP_MSG_RAM0_BASE            0x0C300000
#define SCL_AOP_MSG_RAM1_BASE            SCL_AOP_MSG_RAM0_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM2_BASE            SCL_AOP_MSG_RAM1_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM3_BASE            SCL_AOP_MSG_RAM2_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM4_BASE            SCL_AOP_MSG_RAM3_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM5_BASE            SCL_AOP_MSG_RAM4_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM6_BASE            SCL_AOP_MSG_RAM5_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM7_BASE            SCL_AOP_MSG_RAM6_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM8_BASE            SCL_AOP_MSG_RAM7_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM9_BASE            SCL_AOP_MSG_RAM8_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM10_BASE           SCL_AOP_MSG_RAM9_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM11_BASE           SCL_AOP_MSG_RAM10_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM12_BASE           SCL_AOP_MSG_RAM11_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM13_BASE           SCL_AOP_MSG_RAM12_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM14_BASE           SCL_AOP_MSG_RAM13_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAM15_BASE           SCL_AOP_MSG_RAM14_BASE + SIZE_64KB
#define SCL_AOP_MSG_RAMX_SIZE            SIZE_1KB

/* BOOT IMEM region defines */
#define SCL_BOOT_IMEM_BASE_ADDR          0x14800000
#define SCL_BOOT_IMEM_BASE_SIZE          SIZE_1_5_MB
#define SCL_BOOT_IMEM_XBL_END            (SCL_BOOT_IMEM_BASE_SIZE - SIZE_512KB)

#define SCL_SBL1_IMAGE_BASE              (SCL_BOOT_IMEM_BASE_ADDR + SCL_BOOT_IMEM_START_XBL_UNUSED)
#define SCL_SBL1_IMAGE_SIZE              0xC5000 // 788KB
#define SCL_SBL1_TOTAL_SIZE              SCL_SBL1_IMAGE_SIZE
                                         
/* XBL Loader DDR DSF Driver memory map defines */
#define SCL_SBL1_DDR_SHRM_STRUCT_BASE    0x9060000
#define SCL_SBL1_DDR_SHRM_STRUCT_SIZE    SIZE_4KB
#define SCL_SBL1_DDR_DSF_CFG_BUF_BASE    SCL_AOP_CODE_RAM_BASE
#define SCL_SBL1_DDR_DSF_CFG_BUF_SIZE    SIZE_64KB


/* Training data size needs to be defined to be used during ramdump */
#define SCL_DDR_TRAINING_DATA_BUF_SIZE   SIZE_24KB

/* Cache flush table before XBL Loader mmu initialization */
#define SBL_IMEM_RANGES_TABLE  \
    {\
     {SCL_SBL1_OCIMEM_DATA_BASE,    SCL_SBL1_OCIMEM_DATA_SIZE},\
     {SCL_BOOT_IMEM_BASE_ADDR,     SCL_BOOT_IMEM_BASE_SIZE}\
    }

/* XBL Loader TCM memory map defines */


#define SCL_SBL1_CODE_BASE               SCL_SBL1_IMAGE_BASE
                                         
#define SCL_SBL1_VECTOR_BASE             SCL_SBL1_CODE_BASE
#define SCL_SBL1_VECTOR_SIZE             0x00000020
                                         
#define SCL_SBL1_STACK_SIZE              SIZE_12KB

#define SCL_TZ_OCIMEM_BUFFER             SIZE_184KB
                                         
#define SCL_SYSTEM_DEBUG_BASE            (SCL_IMEM_BASE + SCL_TZ_OCIMEM_BUFFER)
#define SCL_SYSTEM_DEBUG_SIZE            SIZE_20KB

#define SCL_SYSTEM_DEBUG_CO_RO_BASE      (SCL_SYSTEM_DEBUG_BASE)
#define SCL_SYSTEM_DEBUG_CO_RO_SIZE      SIZE_10KB
#define SCL_SYSTEM_DEBUG_DATA_BASE       (SCL_SYSTEM_DEBUG_BASE + SCL_SYSTEM_DEBUG_CO_RO_SIZE)
#define SCL_SYSTEM_DEBUG_DATA_SIZE       (SCL_SYSTEM_DEBUG_SIZE - SCL_SYSTEM_DEBUG_CO_RO_SIZE)


                                         
#define SCL_SBL1_OCIMEM_DATA_BASE        (SCL_IMEM_BASE + SCL_TZ_OCIMEM_BUFFER + SCL_SYSTEM_DEBUG_SIZE)
// TBD: To reduce SCL_SBL1_OCIMEM_DATA_SIZE size further
#define SCL_SBL1_OCIMEM_DATA_SIZE        SIZE_24KB

#define SHARED_IMEM_SIZE                 SIZE_4KB
#define SHARED_IMEM_BASE                 (SCL_IMEM_BASE + SCL_IMEM_SIZE - SHARED_IMEM_SIZE)
#define SHARED_IMEM_BOOT_BASE            SHARED_IMEM_BASE
#define SHARED_IMEM_BOOT_SIZE            200
#define SHARED_IMEM_USB_BASE             (SHARED_IMEM_BOOT_BASE + SHARED_IMEM_BOOT_SIZE)
#define SHARED_IMEM_USB_SIZE             200
#define SHARED_IMEM_BOOT_CDT_BASE        (SHARED_IMEM_USB_BASE + SHARED_IMEM_USB_SIZE)
#define SHARED_IMEM_BOOT_CDT_SIZE        0x0000400
#define SHARED_IMEM_DDR_BASE             (SHARED_IMEM_BOOT_CDT_BASE + SHARED_IMEM_BOOT_CDT_SIZE)
#define SHARED_IMEM_DDR_SIZE             200
#define SHARED_IMEM_HLOS_BASE            (SHARED_IMEM_DDR_BASE + SHARED_IMEM_DDR_SIZE)
#define SHARED_IMEM_HLOS_SIZE            200
#define SHARED_IMEM_RPM_BASE             (SHARED_IMEM_HLOS_BASE + SHARED_IMEM_HLOS_SIZE)
#define SHARED_IMEM_RPM_SIZE             8
#define SHARED_IMEM_QDSS_BASE            (SHARED_IMEM_RPM_BASE + SHARED_IMEM_RPM_SIZE)
#define SHARED_IMEM_QDSS_SIZE            12
#define SHARED_IMEM_SECUREMSM_BASE       (SHARED_IMEM_QDSS_BASE + SHARED_IMEM_QDSS_SIZE)
#define SHARED_IMEM_SECUREMSM_SIZE       512
#define SHARED_IMEM_PERIPHERAL_DEBUG_BASE (SHARED_IMEM_SECUREMSM_BASE + SHARED_IMEM_SECUREMSM_SIZE)
#define SHARED_IMEM_PERIPHERAL_DEBUG_SIZE 24
#define SHARED_IMEM_PIL_BASE             (SHARED_IMEM_PERIPHERAL_DEBUG_BASE + SHARED_IMEM_PERIPHERAL_DEBUG_SIZE)
#define SHARED_IMEM_PIL_SIZE             200
#define SHARED_IMEM_TZ_BASE              (SHARED_IMEM_PIL_BASE + SHARED_IMEM_PIL_SIZE)
#define SHARED_IMEM_TZ_SIZE              128
#define SHARED_IMEM_OEM_BASE             (SHARED_IMEM_TZ_BASE + SHARED_IMEM_TZ_SIZE)
#define SHARED_IMEM_OEM_SIZE             100
#define SHARED_IMEM_SDI_BASE             (SHARED_IMEM_OEM_BASE + SHARED_IMEM_OEM_SIZE)
#define SHARED_IMEM_SDI_SIZE             32
#define SHARED_IMEM_MODEM_BASE           (SHARED_IMEM_SDI_BASE + SHARED_IMEM_SDI_SIZE)
#define SHARED_IMEM_MODEM_SIZE           4
#define SHARED_IMEM_UNUSED_SPACE_BASE    (SHARED_IMEM_MODEM_BASE + SHARED_IMEM_MODEM_SIZE)
#define SHARED_IMEM_UNUSED_SPACE_SIZE    1152
#define SHARED_IMEM_BOOTROM_BASE         (SHARED_IMEM_UNUSED_SPACE_BASE + SHARED_IMEM_UNUSED_SPACE_SIZE)
#define SHARED_IMEM_BOOTROM_SIZE         100

#define SIZE_14GB                          0x380000000
#define DDR_MEM_BASE_1                     0x80000000
#define DDR_MEM_SIZE_1                     SIZE_14GB
#define DDR_MEM_BASE_2                     0x800000000
#define DDR_MEM_SIZE_2                     SIZE_32GB


#define SCL_DDR_pIMEM_BASE               0x80E00000
#define SCL_DDR_pIMEM_SIZE               SIZE_80MB

#define SCL_pIMEM_BASE                   0x1C000000

#define SCL_pIMEM_SIZE                   SIZE_16MB
#define SCL_pIMEM_MINIMUM_SIZE           SIZE_2MB

/* SBL's DDR section is shared by Loader DDR Data and Ramdump */
#define SCL_SBL1_DDR_BASE                0x80700000
#define SCL_SBL1_DDR_SIZE                SIZE_1MB

#define SCL_SBL1_DDR_DATA_BASE           SCL_SBL1_DDR_BASE
#define SCL_SBL1_DDR_DATA_SIZE           SIZE_16KB
#define SCL_SBL1_DDR_ZI_BASE             (SCL_SBL1_DDR_DATA_BASE + SCL_SBL1_DDR_DATA_SIZE)  
#define SCL_SBL1_DDR_ZI_SIZE             SIZE_172KB

#define SCL_RAMDUMP_TOTAL_SIZE           (SCL_SBL1_DDR_SIZE - SCL_SBL1_DDR_DATA_SIZE-SCL_SBL1_DDR_ZI_SIZE)
#define SCL_RAMDUMP_CODE_BASE            (SCL_SBL1_DDR_BASE + SCL_SBL1_DDR_DATA_SIZE+SCL_SBL1_DDR_ZI_SIZE)
#define SCL_RAMDUMP_CODE_SIZE            SIZE_392KB
#define SCL_RAMDUMP_DLOAD_BUFFERS_BASE   (SCL_RAMDUMP_CODE_BASE + SCL_RAMDUMP_CODE_SIZE)
#define SCL_RAMDUMP_DLOAD_BUFFERS_SIZE   SIZE_60KB
#define SCL_RAMDUMP_DATA_BASE            (SCL_RAMDUMP_DLOAD_BUFFERS_BASE + SCL_RAMDUMP_DLOAD_BUFFERS_SIZE)
#define SCL_RAMDUMP_DATA_SIZE  (SCL_RAMDUMP_TOTAL_SIZE - SCL_RAMDUMP_CODE_SIZE - SCL_RAMDUMP_DLOAD_BUFFERS_SIZE)
#define SCL_LOADERTEST_TOTAL_SIZE        (SCL_LOADERTEST_CODE_SIZE + SCL_LOADERTEST_DATA_SIZE)
#define SCL_LOADERTEST_CODE_BASE         SCL_XBL_CORE_CODE_BASE
#define SCL_LOADERTEST_CODE_SIZE         SIZE_2MB
#define SCL_LOADERTEST_DATA_BASE         (SCL_XBL_CORE_CODE_BASE + SCL_LOADERTEST_CODE_SIZE)
#define SCL_LOADERTEST_DATA_SIZE         SIZE_2MB
/* Only boot log size is needed as base addresses are automatically placed
   in DDR_ZI */
#define SCL_SBL1_DDR_BOOT_LOG_META_INFO_SIZE    SCL_SBL1_BOOT_LOG_META_INFO_SIZE
#define SCL_SBL1_DDR_BOOT_LOG_BUF_SIZE          SIZE_8KB
#define SCL_SBL1_DDR_BOOT_TIME_MARKER_BUF_SIZE  SIZE_256B

#define SCL_SHARED_RAM_BASE              0x80900000
#define SCL_SHARED_RAM_SIZE              SIZE_2MB

#define SCL_AOP_BASE                     0x80800000
#define SCL_AOP_SIZE                     0x80000

#define SCL_QSEE_CODE_BASE               SCL_IMEM_BASE
#define SCL_QSEE_TOTAL_SIZE              SIZE_100KB
#define SCL_TZ_STAT_BASE                 0x80B00000
#define SCL_TZ_STAT_BASE_SIZE            SIZE_1MB


// QTI_MISC 
//#define SCL_MULTI_IMAGE_QTI_CODE_BASE    (SCL_QSEE_CODE_BASE + SCL_QSEE_TOTAL_SIZE - SIZE_32KB)
#define SCL_MULTI_IMAGE_QTI_CODE_BASE    0x8fff8000
#define SCL_MULTI_IMAGE_QTI_TOTAL_SIZE   SIZE_12KB

// SECDATA
#define SCL_SECDATA_BASE                 0x808FF000
#define SCL_SECDATA_TOTAL_SIZE           SIZE_4KB

#define SCL_DEVICEPROG_ZI_BASE           SCL_QSEE_CODE_BASE
#define SCL_DEVICEPROG_ZI_SIZE           SCL_QSEE_TOTAL_SIZE

#define SCL_QHEE_CODE_BASE                  0x80000000
#define SCL_QHEE_TOTAL_SIZE                 SIZE_6MB
#define SCL_QHEE_CODE_BASE_2                0xA0000000
#define SCL_QHEE_TOTAL_SIZE_2               SIZE_12KB
#define SCL_QHEE_CODE_BASE_3                0xB0400000
#define SCL_QHEE_TOTAL_SIZE_3               SIZE_8KB
#define SCL_QHEE_CODE_BASE_4                0x80600000
#define SCL_QHEE_TOTAL_SIZE_4               SIZE_12KB

#define SCL_APPSBL_CODE_BASE                0x8EC00000
#define SCL_APPSBL_TOTAL_SIZE               0x0F00000
#define SCL_XBL_CORE_CODE_BASE              0x9FC00000
#define SCL_XBL_CORE_CODE_BASE2             0x80200000
#define SCL_XBL_CORE_TOTAL_SIZE             0x0F00000
#define SCL_SBL1_BOOT_LOG_META_INFO_SIZE    64
#define SCL_SBL1_BOOT_TIME_MARKER_BUF_SIZE  64
#define SCL_SBL1_BOOT_LOG_BUF_SIZE          SIZE_4KB
#define SBL1_DEBUG_COOKIE_ADDR              (SHARED_IMEM_PERIPHERAL_DEBUG_BASE + 0x10)
#define SBL1_DEBUG_COOKIE_VAL               0x53444247
#define SCL_APSS_REGION_FOR_ABL_BASE        0x96600000
#define SCL_APSS_REGION_FOR_ABL_SIZE        SIZE_150MB

#define SCL_IRAM_BASE  SCL_BOOT_IMEM_BASE_ADDR
#define SCL_IRAM_SIZE  SCL_BOOT_IMEM_BASE_SIZE

#define SCL_MODEM_EFS_RAM_SIZE 0x0300000

#define IMAGE_KEY_EMMCBLD_IMG_DEST_ADDR SCL_SBL1_CODE_BASE+80
#define IMAGE_KEY_DEVICEPROGRAMMER_IMG_DEST_ADDR SCL_SBL1_CODE_BASE+80

/* IPA Ramdump memory regions */
#define SCL_IPA_IU_BASE    0x01EA0000
#define SCL_IPA_IU_SIZE    0x9F00
#define SCL_IPA_SRAM_BASE  0x01E50000
#define SCL_IPA_SRAM_SIZE  0x4B20
#define SCL_IPA_MBOX_BASE  0x01EC2000
#define SCL_IPA_MBOX_SIZE  0x100
#define SCL_IPA_GSI_BASE   0x01E06000 
#define SCL_IPA_GSI_SIZE   0x1500
#define SCL_IPA_HRAM_BASE  0x01E60000
#define SCL_IPA_HRAM_SIZE  0xB9B0
#define SCL_IPA_SEQ_BASE   0x01E81000
#define SCL_IPA_SEQ_SIZE   0x300


// SHRM memory that needs to be dumped
#define SCL_SHRM_MEM_SHRM_BASE 0x09060000
#define SCL_SHRM_MEM_SHRM_SIZE SIZE_64KB

//DCC SRAM that needs to be dumped
#define SCL_DCC_LL_SRAM_BASE 0x01028000
#define SCL_DCC_LL_SRAM_SIZE 0x18000

//DCC DCC_CFG that needs to be dumped
#define SCL_DCC_CFG       0x01023000
#define SCL_DCC_CFG_SIZE  0x1000

// CPUCPFW address range
#define SCL_CPUCPFW_BASE 0x18500000
#define SCL_CPUCPFW_SIZE 0x10000
#define SCL_CPUCPFW_DDR_BASE 0x86200000
#define SCL_CPUCPFW_DDR_SIZE SIZE_1MB

#define BOOT_OEM_HYP_BASE 0xB0400000
#define BOOT_OEM_HYP_SIZE 0x9000000


#define CACHE_LINE_LENGTH_BYTES (64)

/*===========================================================================
                Defines to support PMIC image loading 
===========================================================================*/

/*   PMIC config size  */
#define SCL_PMIC_CONFIG_SIZE  SIZE_64KB

#define HASH_SEGMENT_SIZE SIZE_24KB

/*===========================================================================
                      FEATURE DEFINES USED ACROSS DRIVERS
===========================================================================*/

#define DDR_XO_SPEED_IN_KHZ 19200
#define BOOT_TEMP_CHECK_THRESHOLD_DEGC
#undef  FEATURE_USE_PBL_SECBOOT_API
#define FEATURE_EMPTY_L1_PAGE_TABLE

/* Enablement flag for boot debug feature */
#define BOOT_CRASHDUMP_FEATURE

/* Enablement flag for asynchronous uart output */
#define BOOT_ASYNC_UART_FEATURE

/* Enablement flags for boot profiler feature below */
#define BOOT_PROFILER_FEATURE  /* Enable boot profiler overall feature can
                                  remove/comment out to completely disable */

/* Set current profiler level
   0 - Profiling messges only
   1 - High level debug messages and level 0
   2 - Low level debug messages and levels 1 and 0 */
#define BOOT_PROFILER_LEVEL 0

/* Enable boot profiler for boot code
   Uncomment the following to enable */
//#define SBL_PROFILER_FEATURE

/* Driver team must define macros which map to boot_profiler* macros. 
   These driver-defined macros to be defined in "[driver]_profile.h".
   After driver has defined and placed these, uncomment the following
   lines to enable for any particular driver(commented out by default) */
//#define EFS_PROFILER_FEATURE

//#define DAL_PROFILER_FEATURE

//#define TLMM_PROFILER_FEATURE

//#define APT_PROFILER_FEATURE

//#define HOTPLUG_PROFILER_FEATURE

//#define SMEM_PROFILER_FEATURE

//#define PLATFORMINFO_PROFILER_FEATURE

//#define PMIC_PROFILER_FEATURE

//#define CLK_PROFILER_FEATURE

//#define VSENSE_PROFILER_FEATURE

//#define HSUSB_PROFILER_FEATURE

//#define BUSYWAIT_PROFILER_FEATURE

//#define BUS_PROFILER_FEATURE

//#define DDR_PROFILER_FEATURE

//#define FLASH_PROFILER_FEATURE

//#define CRYPTO_PROFILER_FEATURE

//#define SECBOOT_PROFILER_FEATURE

//#define UART_PROFILER_FEATURE

//#define POWER_PROFILER_FEATURE

//#define LIMITS_PROFILER_FEATURE

//#define SECIMG_AUTH_PROFILER_FEATURE

#endif  /* _SOC_CUST_H */
