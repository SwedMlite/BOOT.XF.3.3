/** @file SampleApp.c

   Copyright (c) 2019 Qualcomm Technologies, Inc. All rights
   reserved.

 **/

#include <Uefi.h>

#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>


/**
 *
 */
EFI_STATUS EFIAPI
SampleAppInitialize(
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *EFI_SYSTEM_TABLE
  )
{
  return EFI_SUCCESS;
}
