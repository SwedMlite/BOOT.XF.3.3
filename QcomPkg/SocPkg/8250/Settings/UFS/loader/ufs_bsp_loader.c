/**********************************************************************
* ufs_bsp_loader.c
*
* Board support file for XBL Loader
*
* Copyright (c) 2013-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
* Qualcomm Technologies Proprietary and Confidential.
* 
*
**********************************************************************/

/*=======================================================================
                        Edit History

YYYY-MM-DD   who     what, where, why
---------------------------------------------------------------------- 
2019-10-15   jt      Remove UFS 3.0 support
2019-09-10   jt      Add dcache_clean for ufs_bsp_cache_op
2019-07-22   jt      Add SMMU configuration API 
2019-02-01   jt      Add UFS 3.0 support 
2018-11-29   jt      Add ufs_bsp_volt_set  
2019-01-14   yps     Added dcache inval for ufs_bsp_cache_op
2018-11-01   jt      Mask off lowest 2 bits for SOC emulation type  
2018-09-24   jt      Move PHY settings to its own file 
2018-09-05   jt      Restructure PHY initialization 
2018-07-24   jt      HPG updates for Hana v2 
2018-05-30   jt      HPG v7.0 PHY updates for Hana/Poipu 
2018-04-26   jt      More PHY init updates for Hana/Poipu 
2018-04-11   jt      Additional PHY init updates for Hana/Poipu  
2018-02-13   jt      PHY init updates for Hana/Poipu 
2018-01-25   vk      Remove UEFI libs
2017-07-31   jt      Add log function 
2017-06-20   jt      Enable clocks for RUMI  
2017-06-06   jt      Adapt for Hana
2017-04-08   jt      Add GCC reset for silicon 
2017-02-10   jt      Update PHY init sequence for Hynix part  
2017-01-25   jt      Add UFS device reset
2016-11-01   jt      Add reset function 
2016-10-21   jt      Enable HS for RUMI 
2016-09-14   jt      AANG RUMI PHY init updates  
2016-08-22   jt      PHY init updates from 8998v2 
2016-07-22   jt      Adapt for Napali 
2015-06-15   rh      Disable the PHY from decoding the LCC sequence
2015-02-12   rh      8996 V1 PHY workaround
2014-09-17   rh      Adapted for 8996 
2014-07-16   rh      Adding cache operation
2014-06-02   rh      PHY init adjustment
2014-03-24   rh      Adapt the BSP file for 8994
2013-10-30   rh      Clock regime function cleanup
2013-10-30   rh      More accurate delay added
2013-06-19   rh      Initial creation
===========================================================================*/

#include <Uefi.h>
#include <Library/PcdLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseLib.h>


#include "HALbootHWIO.h"
#include <boot_cache_mmu.h>
#include <HALhwio.h>

#include "../inc/ufs_osal.h"
#include "../inc/ufs_bsp.h"
#include "../inc/ufs_phy_hwio_v2.h"
#include "../inc/aang_phy_hwio.h"
#include "../inc/hwio_tlmm_ufs.h"
#include "../inc/ufs_phy_sequence.h"
#include "ClockBoot.h"
#include "DDIPlatformInfo.h"

#include "boot_cache.h"
#include "DALSys.h"
#include "boot_logger.h"

/* Clock regime clock offset mapping */
#define HWIO_GCC_UFS_BCR_OUT(v)        \
        out_dword(HWIO_GCC_UFS_PHY_BCR_ADDR,v)

#define UFS_PHY_PCS_READY_TIMEOUT           1000
#define REQUEST_LIST_BUFFER_SIZE            4096  
//__attribute__((section(".bss.BOOT_OCIMEM_PAGE_TABLE_ZONE"))) char ALIGN(4*1024) transfer_request_list_buf[REQUEST_LIST_BUFFER_SIZE];      
char transfer_request_list_buf[REQUEST_LIST_BUFFER_SIZE];      

DalPlatformInfoPlatformType g_platform;

void ufs_bsp_clk_set (uint8_t hostid, uint32_t mode)
{
   (void) hostid;

   if (mode == UFS_CLOCK_MODE_OFF) {
      (void) Clock_UFSInit (CLOCK_BOOT_PERF_NONE);
   }
   else if (mode == UFS_CLOCK_MODE_ON) {
      (void) Clock_UFSInit (CLOCK_BOOT_PERF_NOMINAL);
   }
}

void ufs_bsp_enable_symbol_clk (void)
{
}

/* A utility function to get the sleep timetick */
static uint32 Clock_GetSclkTimetick()
{
   uint32_t curr_count;
   uint32_t last_count;  
   
   /*Grab current time count*/
   curr_count = HWIO_IN(MPM_SLEEP_TIMETICK_COUNT_VAL);
   
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      return curr_count;
   }
   
   
   /*Keep grabbing the time until a stable count is given*/
   do 
   {
     last_count = curr_count;
     curr_count = HWIO_IN(MPM_SLEEP_TIMETICK_COUNT_VAL);
   } while (curr_count != last_count &&
            g_platform != DALPLATFORMINFO_TYPE_RUMI &&
            g_platform != DALPLATFORMINFO_TYPE_VIRTIO );
   
   return curr_count;
}

// Maximum delay is 134s
void ufs_bsp_busy_wait(uint32_t us)
{
   uint32_t pause_cycle = us * 32 / 1000 + us * 768 / 1000000;
   uint32_t now;

   // Need to check if there is a case of wrapping around
   now = Clock_GetSclkTimetick();
   while( Clock_GetSclkTimetick() - now <= pause_cycle);
}

uint32_t ufs_bsp_get_mphy_init_item_table (struct ufs_mphy_init_item **itm)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      *itm = ufs_bsp_mphy_init_table_rumi;
      return sizeof(ufs_bsp_mphy_init_table_rumi)/sizeof(struct ufs_mphy_init_item);
   }
   else {
      *itm = ufs_bsp_mphy_init_table;
      return sizeof(ufs_bsp_mphy_init_table)/sizeof(struct ufs_mphy_init_item);
   }
}

uint32_t ufs_bsp_get_mphy_init_2_lane_item_table (struct ufs_mphy_init_item **itm)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      *itm = ufs_bsp_mphy_2_lane_init_table_rumi;
      return sizeof(ufs_bsp_mphy_2_lane_init_table_rumi)/sizeof(struct ufs_mphy_init_item);
   }
   else {
      *itm = ufs_bsp_mphy_2_lane_init_table;
      return sizeof(ufs_bsp_mphy_2_lane_init_table)/sizeof(struct ufs_mphy_init_item);
   }
}

uint32_t ufs_bsp_get_mphy_init_end_item_table (struct ufs_mphy_init_item **itm)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      return 0; 
   }
   else {
      *itm = ufs_bsp_mphy_init_end_table;
      return sizeof(ufs_bsp_mphy_init_end_table)/sizeof(struct ufs_mphy_init_item);
   }
}

// Start the PHY and wait for the PHY to be ready
ufs_bsp_err_type ufs_bsp_mphy_start (uint8_t hostid)
{
   int32_t tout = UFS_PHY_PCS_READY_TIMEOUT;
   uint32_t base_addr = ufs_bsp_get_reg_baseaddress(hostid); 

   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      out_dword(base_addr + HWIO_UFS_PHY_PHY_START_OFFS, 1);
      ufs_bsp_busy_wait (10);

      while (in_dword(base_addr + HWIO_QSERDES_COM_RESET_SM_OFFS) != 0x3d) {
         if (tout-- == 0) {
            return UFS_BSP_DEVICE_ERROR;
         }
         ufs_bsp_busy_wait (1);
      }
   }
   else
   {
      HWIO_REG_OUTM (base_addr, UFS_MEM_UFS_PHY_PHY_START_OFFS, 1, 1);
      ufs_bsp_busy_wait (10);

      while (!(HWIO_REG_IN(base_addr, UFS_MEM_UFS_PHY_PCS_READY_STATUS_OFFS) & 0x01)) {
         if (tout-- == 0) {
            return UFS_BSP_DEVICE_ERROR;
         }
         ufs_bsp_busy_wait (1);
      }
   }

   return UFS_BSP_NO_ERROR;
}

void ufs_bsp_post_link_init (uint8_t hostid)
{
   (void) hostid;
}

void ufs_bsp_reset (uint8_t hostid)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {

      // Reset and sleep 50 ms
      out_dword(HWIO_GE_DUT_RESET_REG_ADDR, 0x5f); 
      ufs_bsp_busy_wait (50000);

      // Release reset and sleep 50 ms
      out_dword(HWIO_GE_DUT_RESET_REG_ADDR, 0x0);
      ufs_bsp_busy_wait (50000);

      // Clock frequencies used
      out_dword(HWIO_GE_DUT_CLK_STATUS_SEL_REG_ADDR, 0x1);

      // Reset ICE fuses
      out_dword(HWIO_GE_DUT_UFS_ICE_CTRL_REG_ADDR, 0x0);
   }
   else
   {
      if (hostid == 0) {
         out_dword(HWIO_GCC_UFS_PHY_BCR_ADDR, 1);
         ufs_bsp_busy_wait(500);
         out_dword(HWIO_GCC_UFS_PHY_BCR_ADDR, 0); 
      }

   }
}

void ufs_bsp_device_reset (uint8_t hostid)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      return;
   }

   if (hostid == 0) {
      out_dword(HWIO_TLMM_UFS_RESET_ADDR, 0); 
      ufs_bsp_busy_wait(10); 
      out_dword(HWIO_TLMM_UFS_RESET_ADDR, 1); 
      ufs_bsp_busy_wait(10); 
   }

}

void ufs_bsp_cache_op (void *addr, uint32_t len, uint32_t op) 
{
   if (op & FLUSH) {
      dcache_flush_region(addr, len);
   }
   if (op & INVAL) {
      dcache_inval_region(addr, len);
   }
   if (op & CLEAN) {
      dcache_clean_region(addr, len); 
   }
}

void ufs_bsp_memory_barrier ()
{
  data_mem_barrier();
}

void *ufs_bsp_allocate_norm_buf (size_t size)
{
   (void) size;
   void *mem = transfer_request_list_buf;
   return mem;
}

void  ufs_bsp_free_norm_buf (void *pmem)
{
   (void) pmem;
}

void *ufs_bsp_allocate_xfer_buf (size_t size)
{
   (void) size;
   void *mem = transfer_request_list_buf;
   return mem;
}

void  ufs_bsp_free_xfer_buf (void *pmem)
{
   (void) pmem;
}

void ufs_bsp_get_platform_config (ufs_bsp_config_item *itm)
{
   uint32_t soc_emulation_type = 0; 

   // __FIX__SDM845:  substitute non DAL platforminfo api
   g_platform = DalPlatformInfo_Platform();

   /* If DAL API doesn't work, query the SOC emulation type register */
   if (g_platform == DALPLATFORMINFO_TYPE_UNKNOWN) 
   {
      soc_emulation_type = in_dword(0x01fc8004) & 0x3; 

      /* 0 = Silicon, 1 = RUMI, 2 = Veloce, 3 = Virtio */
      if (soc_emulation_type == 1) 
      {
         g_platform = DALPLATFORMINFO_TYPE_RUMI; 
      }
   }

   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      itm->slow_xfer = 1;
      itm->core_skip = 0;
   }
   else {
      /* VIRTIO or Silicon */
      itm->slow_xfer = 0;
      itm->core_skip = 0; 
   }
}

uintptr_t ufs_bsp_get_reg_baseaddress (uint8_t hostid)
{
   if (0 == hostid) 
   {
      return (uintptr_t) 0x1d80000;
   }
   else
   {
      return 0x0; 
   }
}

boolean ufs_bsp_get_dal_config(ufs_dal_config_item *itm)
{
   DALSYSPropertyVar dal_prop; 
   DALSYS_PROPERTY_HANDLE_DECLARE(hUfsProps);

   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      itm->enable_hs = 1;
      itm->gear = 1;
      itm->num_lanes = 1; 
   }
   else
   {
      /* Get the DAL property handle and DAL config values */
      if ((NULL == itm) || 
          (DAL_SUCCESS != DALSYS_GetDALPropertyHandleStr("/core/storage/ufs", hUfsProps)))
      {
         return FALSE; 
      }

      if (DAL_SUCCESS != DALSYS_GetPropertyValue(hUfsProps, "EnableHighSpeed", 0, &dal_prop))
      {
         return FALSE; 
      }
      itm->enable_hs = dal_prop.Val.dwVal; 

      if (DAL_SUCCESS != DALSYS_GetPropertyValue(hUfsProps, "NumGears", 0, &dal_prop))
      {
         return FALSE; 
      }
      itm->gear = dal_prop.Val.dwVal; 

      if (DAL_SUCCESS != DALSYS_GetPropertyValue(hUfsProps, "NumLanes", 0, &dal_prop))
      {
         return FALSE; 
      }
      itm->num_lanes = dal_prop.Val.dwVal;
   }

   return TRUE; 
}

void ufs_bsp_log_error(char *str)
{
   boot_log_message(str); 
}

ufs_bsp_err_type ufs_bsp_volt_set(uint8_t hostid, ufs_bsp_volt_mode mode)
{
   (void)hostid;
   (void)mode; 

   return UFS_BSP_ERR_FEATURE_UNSUPPORTED; 
}

ufs_bsp_err_type ufs_bsp_configure_smmu()
{
   return UFS_BSP_ERR_FEATURE_UNSUPPORTED; 
}
