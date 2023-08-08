/**********************************************************************
* ufs_bsp_core.c
*
* Board support file for XBL core
*
* Copyright (c) 2013-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
* Qualcomm Technologies Proprietary and Confidential.
* 
*
**********************************************************************/

/*=======================================================================
                        Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/UFS/core/ufs_bsp_core.c#9 $
$DateTime: 2019/10/16 11:57:00 $

YYYY-MM-DD   who     what, where, why
---------------------------------------------------------------------- 
2019-10-15   jt      Remove UFS 3.0 support  
2019-09-24   jt      Add sleep voltage mode
2019-07-22   jt      Add SMMU configuration API 
2019-02-27   jt      Add UFS 3.0 support  
2018-11-01   jt      Mask off lowest 2 bits for SOC emulation type 
2018-09-24   jt      Move PHY settings to its own file 
2018-09-05   jt      Restructure PHY initialization 
2018-07-24   jt      HPG updates for Hana v2 
2018-06-21   jt      Only do cache management if CCA disabled
2018-06-04   jt      Add ability to turn clocks off/on
2018-05-30   jt      HPG v7.0 PHY updates for Hana/Poipu   
2018-02-13   jt      PHY init updates for Hana/Poipu 
2017-07-31   jt      Add log function 
2017-06-06   jt      Adapt for Hana
2017-04-08   jt      Turn on flags to skip actions in core  
2017-01-25   jt      Add UFS device reset 
2016-11-01   jt      Add reset function 
2016-10-21   jt      Enable HS for RUMI
2016-09-14   jt      AANG RUMI PHY init updates  
2016-08-22   jt      PHY init updates from 8998v2 
2016-07-22   jt      Adapted for Napali 
2015-06-15   rh      Disable the PHY from decoding the LCC sequence
2014-09-17   rh      Adapted for 8996 
2013-10-30   rh      Clock regime function cleanup
2013-10-30   rh      More accurate delay added
2013-06-19   rh      Initial creation
===========================================================================*/

#include <Uefi.h>
#include <HALhwio.h>
#include <Library/PcdLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UncachedMemoryAllocationLib.h>
#include <Library/SynchronizationLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiCfgLib.h>
#include <Protocol/EFIHWIO.h>
#include <Protocol/EFIClock.h>
#include <Protocol/LoadedImage.h> 
#include <Protocol/EFIPlatformInfo.h> 
#include <Protocol/EFIHALIOMMUProtocol.h>

#include <Library/PcdLib.h>
#include <Library/ArmLib.h>

#include "DDIPlatformInfo.h"
#include "../inc/ufs_osal.h"
#include "../inc/ufs_bsp.h"
#include "../inc/ufs_phy_hwio_v2.h"
#include "../inc/ufs_phy_sequence.h"
#include "../inc/aang_phy_hwio.h"
#include "../inc/hwio_tlmm_ufs.h"
#include "HALbootHWIO.h"

#include "npa.h"
#include "pmapp_npa.h"

#define UFS_PHY_PCS_READY_TIMEOUT      0xffffff

BOOLEAN UFSClocksInited = FALSE; 
EFI_CLOCK_PROTOCOL *hUFS_Clock = NULL;
DalPlatformInfoPlatformType g_platform;
enum hal_iommu_bypass_domain_type cca_flag = HAL_IOMMU_DOMAIN_TYPE_INVALID;

static UFS_CLOCK_LIST ufs_clocks_array[] = 
{
   {
      {"gcc_ufs_phy_axi_clk", 0, 0}, 
      {"gcc_ufs_phy_ice_core_clk", 0, 0}, 
      {"gcc_ufs_phy_unipro_core_clk", 0, 0},
      {"gcc_aggre_ufs_phy_axi_clk", 0, 0}, 
      {"gcc_ufs_phy_ahb_clk", 0, 0}, 
      {"gcc_ufs_phy_phy_aux_clk", 0, 0}, 
      {"gcc_ufs_phy_tx_symbol_0_clk", 0, 0},
      {"gcc_ufs_phy_rx_symbol_0_clk", 0, 0},
      {"gcc_ufs_phy_rx_symbol_1_clk", 0, 0}
   } 
};

void ufs_bsp_clk_set (uint8_t hostid, uint32_t mode)
{
   EFI_STATUS eResult = EFI_SUCCESS;
   UINT8 i = 0; 
   UINT8 num_clocks = sizeof(UFS_CLOCK_LIST) / sizeof(UFS_CLOCK_INFO);
   UFS_CLOCK_INFO *cur_clock = NULL; 
   UFS_CLOCK_INFO *clock_list = NULL; 

   if (NULL == hUFS_Clock)
   {
      eResult = gBS->LocateProtocol(&gEfiClockProtocolGuid, NULL, (VOID **)&hUFS_Clock);
      if ((EFI_SUCCESS != eResult) || (NULL == hUFS_Clock))
      {
          hUFS_Clock = NULL;
          ASSERT_EFI_ERROR(eResult);
      }
   }

   if (NULL != hUFS_Clock) 
   {
      clock_list = (UFS_CLOCK_INFO *)&ufs_clocks_array[hostid]; 
      for (i = 0; i < num_clocks; i++) 
      {
         cur_clock = clock_list + i; 
         if (cur_clock->clock_id == 0) 
         {
            eResult = hUFS_Clock->GetClockID(hUFS_Clock, cur_clock->clock_name,
                                             &cur_clock->clock_id);
            if (EFI_SUCCESS != eResult)
            {
               ASSERT_EFI_ERROR(eResult);
            }
         }

         if (UFS_CLOCK_MODE_OFF == mode) 
         {
            eResult = hUFS_Clock->DisableClock(hUFS_Clock, cur_clock->clock_id);
            if (EFI_SUCCESS != eResult)
            {
               ASSERT_EFI_ERROR(eResult);
            }
         }
         else if (UFS_CLOCK_MODE_ON == mode)
         {
            eResult = hUFS_Clock->EnableClock(hUFS_Clock, cur_clock->clock_id);          
            if (EFI_SUCCESS != eResult)
            {
               ASSERT_EFI_ERROR(eResult);
            }

            if (cur_clock->freq != 0) 
            {
               eResult = hUFS_Clock->SetClockFreqHz(hUFS_Clock, cur_clock->clock_id, cur_clock->freq, 
                                                    EFI_CLOCK_FREQUENCY_HZ_AT_MOST, &cur_clock->freq);          
               if (EFI_SUCCESS != eResult)
               {
                  ASSERT_EFI_ERROR(eResult);
               }
            }
         }
      }
   }
}    

void ufs_bsp_cache_op (void *addr, uint32_t len, uint32_t op) 
{
   if (cca_flag == HAL_IOMMU_DOMAIN_TYPE_INVALID) {
      if (GetConfigValue ("EnableUfsIOC", &cca_flag) != EFI_SUCCESS)
      {
         cca_flag = HAL_IOMMU_AARCH64_NON_CCA_DOMAIN_TYPE;
      }
   }

   if (cca_flag != HAL_IOMMU_AARCH64_CCA_DOMAIN_TYPE) {
      if (op & FLUSH) {
         WriteBackInvalidateDataCacheRange (addr, len);
      }

      if (op & INVAL) {
         InvalidateDataCacheRange (addr, len);
      }

      if (op & CLEAN) {
         WriteBackDataCacheRange (addr, len);
      }
   }
}

void ufs_bsp_busy_wait(uint32_t us)
{
   gBS->Stall(us);
}

void ufs_bsp_memory_barrier ()
{
   ArmDataMemoryBarrier();
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

void ufs_bsp_post_link_init (uint8_t hostid)
{
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      return;
   }

   HWIO_REG_OUT(ufs_bsp_get_reg_baseaddress(hostid), UFS_MEM_UFS_PHY_LINECFG_DISABLE_OFFS, 0x02);   
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

void *ufs_bsp_allocate_norm_buf (size_t size)
{
    VOID *mem;
    EFI_STATUS            status;
    status=gBS->AllocatePool(EfiBootServicesData,size,(VOID**)&mem);

    if (EFI_SUCCESS != status)
    {
        DEBUG((EFI_D_ERROR, "UFS: Allocate memory of size 0x%x     [FAILED]\n",size));
        return NULL;
    }
    return mem;
}

void  ufs_bsp_free_norm_buf (void *pmem)
{
    if ( pmem == NULL )
        return;

    gBS->FreePool(pmem);
}

void *ufs_bsp_allocate_xfer_buf (size_t size)
{
    return UncachedAllocatePool(size);
}

void  ufs_bsp_free_xfer_buf (void *pmem)
{
    if ( pmem == NULL )
        return;

    UncachedFreePool(pmem);
}

void ufs_bsp_get_platform_config (ufs_bsp_config_item *itm)
{
   EFI_STATUS                          eResult = EFI_SUCCESS;
   EFI_PLATFORMINFO_PROTOCOL           *hPlatformInfoProtocol;
   EFI_PLATFORMINFO_PLATFORM_INFO_TYPE PlatformInfo;
   uint32_t soc_emulation_type = 0;
   
   eResult = gBS->LocateProtocol(&gEfiPlatformInfoProtocolGuid, NULL,
     (VOID **) &hPlatformInfoProtocol);
   if (eResult != EFI_SUCCESS)
   {
     DEBUG((EFI_D_WARN, "Error: Failed to locate PlatformInfo protocol.\n"));
     goto ConfigEnd;
   }
   
   eResult = hPlatformInfoProtocol->GetPlatformInfo(hPlatformInfoProtocol,
     &PlatformInfo);
   if (eResult != EFI_SUCCESS)
   {
     DEBUG((EFI_D_WARN, "Error: GetPlatformInfo failed.\n"));
     goto ConfigEnd;
   }
   
   if (PlatformInfo.platform >= EFI_PLATFORMINFO_NUM_TYPES)
   {
     DEBUG((EFI_D_WARN, "Error: Unknown platform type (%d)\n", PlatformInfo.platform));
     eResult = EFI_PROTOCOL_ERROR;
     goto ConfigEnd; 
   }

   if (PlatformInfo.platform == EFI_PLATFORMINFO_TYPE_RUMI) {
   	g_platform = DALPLATFORMINFO_TYPE_RUMI;
   }

ConfigEnd:
   if (eResult != EFI_SUCCESS) {
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
      itm->core_skip = 1; 
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
   if (g_platform == DALPLATFORMINFO_TYPE_RUMI) {
      itm->enable_hs = 1; 
      itm->gear = 1;
      itm->num_lanes = 1; 
   }

   return TRUE; 
}

void ufs_bsp_log_error(char *str)
{
   DEBUG ((EFI_D_ERROR, "%a\n", str)); 
}

ufs_bsp_err_type ufs_bsp_volt_set(uint8_t hostid, ufs_bsp_volt_mode mode)
{
   static npa_client_handle client_handle = NULL;

   if (hostid == 0) {
      if (client_handle == NULL) {
         client_handle = npa_create_sync_client(PMIC_NPA_GROUP_ID_UFS0, "ufs0", NPA_CLIENT_REQUIRED); 
      }
   }
   else {
      return UFS_BSP_ERR_INVALID_PARAM;
   }

   if (client_handle == NULL) {
      return UFS_BSP_ERR_PMIC;
   }

   /* Turn all UFS regulators ON */
   if (mode == UFS_BSP_REGULATORS_ON) {
      ;
   }
   /* Lower Vcc to 0V for UFS device sleep */
   else if (mode == UFS_BSP_REGULATORS_SLEEP) {
      npa_issue_required_request(client_handle, PMIC_NPA_MODE_ID_GENERIC_STANDBY);
   }
   else {
      return UFS_BSP_ERR_FEATURE_UNSUPPORTED; 
   }

   return UFS_BSP_NO_ERROR;
}

ufs_bsp_err_type ufs_bsp_configure_smmu()
{
   EFI_STATUS Status = EFI_SUCCESS;
   static boolean configure_completed = FALSE; 
   static HAL_IOMMU_fptable_t *fp_table = NULL;
   VOID *ufs_card_domain_hdl, *ufs_mem_domain_hdl;
   EFI_HAL_IOMMU_PROTOCOL *Iommu = NULL;

   if (configure_completed) {
      return UFS_BSP_NO_ERROR; 
   }

   /* Locate UEFI IOMMU protocol */
   if (fp_table == NULL) {
      Status = gBS->LocateProtocol(&gEfiHalIommuProtocolGuid,
                                   NULL,
                                   (VOID **)&Iommu);
      if (Status != EFI_SUCCESS) {
         DEBUG((EFI_D_ERROR, "UFS IOMMU LocateProtocol failed 0x%x\n", Status));
         return UFS_BSP_DEVICE_ERROR;
      }

      Iommu->_HAL_IOMMU_protocol_init(&fp_table);
   }

   if (cca_flag == HAL_IOMMU_DOMAIN_TYPE_INVALID) {
      if (GetConfigValue ("EnableUfsIOC", &cca_flag) != EFI_SUCCESS)
      {
         cca_flag = HAL_IOMMU_AARCH64_NON_CCA_DOMAIN_TYPE;
      }
   }

   /* Create Domain for UFS card */
   if (HAL_IOMMU_ERR_OK != fp_table->domain_create_func(&ufs_card_domain_hdl)) {
      DEBUG((EFI_D_ERROR, "UFS card IOMMU domain create failed\n"));
      return UFS_BSP_DEVICE_ERROR;
   }

   /* Attach UFS card to the domain */
   if (HAL_IOMMU_ERR_OK != fp_table->config_bypass_domain_func(ufs_card_domain_hdl, cca_flag))
   {
      DEBUG((EFI_D_ERROR, "UFS card IOMMU domain configure failed\n"));
      return UFS_BSP_ERR_FEATURE_UNSUPPORTED;
   }

   if (HAL_IOMMU_ERR_OK != fp_table->domain_attach_func(ufs_card_domain_hdl, (void *)"\\_SB_.UFS0", 0x0, 0x0))
   {
      DEBUG((EFI_D_ERROR, "UFS card IOMMU domain attach ARID 0x0 failed\n"));
      return UFS_BSP_DEVICE_ERROR;
   }

   /* Create Domain for embedded UFS */
   if (HAL_IOMMU_ERR_OK != fp_table->domain_create_func(&ufs_mem_domain_hdl)) {
      DEBUG((EFI_D_ERROR, "UFS IOMMU domain create failed\n"));
      return UFS_BSP_DEVICE_ERROR;
   }

   /* Attach embedded UFS to the domain */
   if (HAL_IOMMU_ERR_OK != fp_table->config_bypass_domain_func(ufs_mem_domain_hdl, cca_flag))
   {
      DEBUG((EFI_D_ERROR, "UFS IOMMU domain configure failed\n"));
      return UFS_BSP_ERR_FEATURE_UNSUPPORTED;
   }

   if (HAL_IOMMU_ERR_OK != fp_table->domain_attach_func(ufs_mem_domain_hdl, (void *)"\\_SB_.UFS0", 0x10, 0x0))
   {
      DEBUG((EFI_D_ERROR, "UFS IOMMU domain attach ARID 0x10 failed\n"));
      return UFS_BSP_DEVICE_ERROR;
   }

   configure_completed = TRUE; 

   return UFS_BSP_NO_ERROR;
}
