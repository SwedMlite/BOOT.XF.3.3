//============================================================================
/**
  Copyright (c) 2015-2019 Qualcomm Technologies, Inc. All rights reserved.
  Portions Copyright (c) 2007 - 2013 Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php
  
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 */
//============================================================================

#include <Protocol/EFIHALIOMMUProtocol.h>
#include <Library/DebugLib.h>
#include "HALIOMMUReg.h"
#include "HALIOMMULib.h"

/* Forward function declarations */
void _HAL_IOMMU_protocol_init(HAL_IOMMU_fptable_t **p_fp_table);
void _HAL_IOMMU_protocol_deinit(void);
static EFI_STATUS HAL_IOMMU_Dummy_Client(void);

EFI_HAL_IOMMU_PROTOCOL HAL_IOMMUProtocol = 
{
    HAL_IOMMU_REVISION,
    _HAL_IOMMU_protocol_init,
    _HAL_IOMMU_protocol_deinit,
};

void _HAL_IOMMU_protocol_init(HAL_IOMMU_fptable_t **p_fp_table)
{
    static HAL_IOMMU_fptable_t hal_iommu_fp_table =
    {
        hal_iommu_domain_create,
        hal_iommu_domain_delete,
        hal_iommu_domain_attach_device,
        hal_iommu_domain_detach_device,
        hal_iommu_domain_configure,
        hal_iommu_flush_domain,
        hal_iommu_flush_domain_va_list,
        hal_iommu_register_fault_handler,
        hal_iommu_configure_bypass_domain,
    };
    
    // install function pointer table
    *p_fp_table = &hal_iommu_fp_table;
}

void _HAL_IOMMU_protocol_deinit(void)
{
    // TODO
    return;
}

EFI_STATUS
EFIAPI
HAL_IOMMUDxeEntryPoint(
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
   EFI_HANDLE  handle = NULL;
   EFI_STATUS  status;

   // Publish the HAL_IOMMU Protocol
   status = gBS->InstallMultipleProtocolInterfaces( &handle, 
         &gEfiHalIommuProtocolGuid, 
         (void **)&HAL_IOMMUProtocol, NULL );
   if (EFI_SUCCESS != status)
   {
      return status;
   }
   
   // Register BootExitServices Callback function
   //TODO
   
   // Invoke dummy client and return
   return HAL_IOMMU_Dummy_Client();
}

static EFI_STATUS HAL_IOMMU_Dummy_Client(void)
{
   return EFI_SUCCESS;
}

HAL_IOMMUResult_t IDIOM_domain_lookup(void**p_domain_local, void *client_handle)
{
    HAL_IOMMUResult_t ret = HAL_IOMMU_ERR_OK;
	/* Input Validation */
    if( !client_handle || !p_domain_local ) {
        return HAL_IOMMU_ERR_NULL_POINTER;
    }
    
	return ret;	
}
