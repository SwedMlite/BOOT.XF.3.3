/** @file
  Capsule library runtime support.

  Copyright (c) 2017, Qualcomm Technologies, Inc. All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
  Portions Copyright (c) 2016 - 2017, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/15/17   gparam  Changed TPL type from NOTIFY to CALLBACK + Added NULL check
                    around global pointer in virtuall address callback
 02/22/17   gparam  Initial revision

=============================================================================*/

#include <PiDxe.h>

#include <Guid/FmpCapsule.h>
#include <Guid/SystemResourceTable.h>
#include <Guid/EventGroup.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>

#include <Protocol/BlockIo.h>

#include "DxeCapsuleQcom.h"

extern EFI_SYSTEM_RESOURCE_TABLE *mEsrtTable;
extern BOOLEAN                   mIsVirtualAddrConverted;
extern VOID                      *CapsuleStorageHeader;
extern EFI_BLOCK_IO_PROTOCOL     *CapsuleBlkIo;

extern SCATTERGATHERLIST_ARRAY_HEADER *mScatterGatherHeader;
EFI_EVENT                 mDxeRuntimeCapsuleLibVirtualAddressChangeEvent  = NULL;

/**
  Convert EsrtTable physical address to virtual address.

  @param[in] Event      Event whose notification function is being invoked.
  @param[in] Context    The pointer to the notification function's context, which
                        is implementation-dependent.
**/
VOID
EFIAPI
DxeCapsuleLibVirtualAddressChangeEvent (
  IN  EFI_EVENT   Event,
  IN  VOID        *Context
  )
{
  UINTN                    Index;
  EFI_CONFIGURATION_TABLE  *ConfigEntry;

  //
  // Get Esrt table first
  //
  ConfigEntry = gST->ConfigurationTable;
  for (Index = 0; Index < gST->NumberOfTableEntries; Index++) {
    if (CompareGuid(&gEfiSystemResourceTableGuid, &ConfigEntry->VendorGuid)) {
      break;
    }
    ConfigEntry++;
  }

  //
  // If no Esrt table installed in Configure Table
  //
  if (Index < gST->NumberOfTableEntries) {
    //
    // Search Esrt to check given capsule is qualified
    //
    mEsrtTable = (EFI_SYSTEM_RESOURCE_TABLE *) ConfigEntry->VendorTable;

    //
    // Update protocol pointer to Esrt Table.
    //
    gRT->ConvertPointer (0x00, (VOID**) &(mEsrtTable));
  }

  // Update other global pointers used during runtime services
  gRT->ConvertPointer(0x00, (VOID**) &mScatterGatherHeader);

  gRT->ConvertPointer(0x00, (VOID**) &CapsuleStorageHeader);

  if (NULL != CapsuleBlkIo) {
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo->Media);
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo->Reset);
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo->ReadBlocks);
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo->WriteBlocks);
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo->FlushBlocks);
    gRT->ConvertPointer(0x00, (VOID**) &CapsuleBlkIo); // TODO: Giri: Check if this has to be the first to get converted before the above set of access to this variable
  }
  
  mIsVirtualAddrConverted = TRUE;
}

/**
  The constructor function hook VirtualAddressChange event to use ESRT table as capsule routing table.

  @param  ImageHandle   The firmware allocated handle for the EFI image.
  @param  SystemTable   A pointer to the EFI System Table.

  @retval EFI_SUCCESS   The constructor successfully .
**/
EFI_STATUS
EFIAPI
DxeRuntimeCapsuleLibConstructor (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS     Status;

  //
  // Make sure we can handle virtual address changes.
  //
  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_CALLBACK,
                  DxeCapsuleLibVirtualAddressChangeEvent,
                  NULL,
                  &gEfiEventVirtualAddressChangeGuid,
                  &mDxeRuntimeCapsuleLibVirtualAddressChangeEvent
                  );
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}

/**
  The destructor function closes the VirtualAddressChange event.

  @param  ImageHandle   The firmware allocated handle for the EFI image.
  @param  SystemTable   A pointer to the EFI System Table.

  @retval EFI_SUCCESS   The destructor completed successfully.
**/
EFI_STATUS
EFIAPI
DxeRuntimeCapsuleLibDestructor (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS    Status;

  //
  // Close the VirtualAddressChange event.
  //
  Status = gBS->CloseEvent (mDxeRuntimeCapsuleLibVirtualAddressChangeEvent);
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}
