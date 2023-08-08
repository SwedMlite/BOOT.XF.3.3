/** @file
  This file includes utility functions for loading and mounting FV's

  Copyright (c) 2017-2019, Qualcomm Technologies, Inc. All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
  Portions copyright (c) 2004 - 2008, Intel Corporation. All rights reserved.
  
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php
  
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 
**/

/*=============================================================================
                              EDIT HISTORY


 when       who      what, where, why
 --------   ---      ----------------------------------------------------------
 03/21/19   md       Add API's to support recursive FV loading and Desired FV 
                     from Partion/Buffer 
 08/20/18   yw       add MountFvPartition() GUID parameter
 07/23/18   kpa      Connect on FV handles after mounting from partition
 12/01/17   kpa      Update to use ReadFromPartitionWithAttrib instead 
                     of ReadFromFvPartition
 09/08/17   kpa      Initial Revision
=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/
#include <Uefi.h>

#include <Library/IoLib.h>
#include <Library/PcdLib.h>
#include <Library/BaseMemoryLib.h>
#include <Pi/PiFirmwareVolume.h>
#include <Pi/PiFirmwareFile.h>
#include <Library/UncachedMemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/ArmLib.h>
#include <Library/PcdLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DevicePathLib.h>
#include <Library/ExtractGuidedSectionLib.h>
#include <Protocol/FirmwareVolumeBlock.h>
#include <Guid/FileSystemVolumeLabelInfo.h>
#include <Guid/LzmaDecompress.h>
#include "QcomLib.h"
#include <Library/GuidedFvLib.h>
#include <Library/QcomBdsLib.h>
#include <MemRegionInfo.h>
#include <Library/UefiCfgLib.h>
#include <Library/UefiLib.h>
#include <Library/MountFvLib.h>
#include <Library/PrintLib.h>
#include <Protocol/EFIPIL.h>
#include <Include/api/boot/boot_elf_header.h>


/* Check if Image loaded in Buffer is an ELF image */
/* Returns TRUE if there is an ELF image loaded */
BOOLEAN IsMountFvELFImage(IN VOID *ReadBuffer)
{
  Elf32_Ehdr *ehdr;
  ehdr = ReadBuffer;
  return((ehdr->e_ident[ELFINFO_MAG0_INDEX] == ELFINFO_MAG0 &&
          ehdr->e_ident[ELFINFO_MAG1_INDEX] == ELFINFO_MAG1 &&
          ehdr->e_ident[ELFINFO_MAG2_INDEX] == ELFINFO_MAG2 &&
          ehdr->e_ident[ELFINFO_MAG3_INDEX] == ELFINFO_MAG3 )? TRUE: FALSE);
 
}

EFI_STATUS
AuthAndMountFVFromBuffer(IN  VOID          *ReadBuffer,
                         IN  UINTN          BufferSize,
                         IN  EFI_GUID      *MountFVFileGUID  OPTIONAL)
{
  EFI_STATUS Status;
  VOID    *FvBase = NULL; 
  EFI_PIL_PROTOCOL  *PILProtocol = NULL;

  if (ReadBuffer == NULL || BufferSize == 0)
     return EFI_INVALID_PARAMETER; 

  /* Check it is an EFL-FV or just a FV */
  /* If it is an ELF-FV, we first authenticate and then mount if authentication passes. */
  if (IsMountFvELFImage(ReadBuffer))
  {
      Status = gBS->LocateProtocol (&gEfiPilProtocolGuid,NULL, (VOID **) &PILProtocol);
      if ((EFI_SUCCESS != Status) || (NULL == PILProtocol))
      {
         DEBUG((EFI_D_WARN, "Could not verify if the image is ELF-FV or simple FV because PILProtocol is not avaiable. \n"));
         return Status;
      }

      Status = PILProtocol->AuthELFFVImageFromBuffer(ReadBuffer, &FvBase);
      if (EFI_ERROR(Status))
      {
        DEBUG((EFI_D_WARN, "Authentication failed for ELF-FV image read from partition. \n"));
        return EFI_VOLUME_CORRUPTED;
      }
      else
       ReadBuffer = FvBase;
   }
   
  Status = ProcessAndMountFvImageFile (ReadBuffer, BufferSize, MountFVFileGUID);
  if (EFI_ERROR(Status))
    return Status;
  
  Status = ConnectByProtocol(&gEfiFirmwareVolumeBlockProtocolGuid);

  return Status;
}


/**
  This function mounts a FV (firmware volume) passed in as an argument.  
  It locates the partition containing the FV and loads the data. if needed it is
  decompressed and then mounted.
  require either partition GUID or name, return error if giveing both.

  @param[in]  PartitionGuid              Partition GUID of the FV to be mounted
  @param[in]  FvPartitionName            String name of the FV to be mounted
  @param[out] None
  
  @retval  EFI_SUCCESS          The Firmware volume is found and successfully mounted.
  @retval  EFI_NOT_FOUND        Firmware volume not found.
  @retval  EFI_OUT_OF_RESOURCES There were not enough resources to allocate the 
                                output data buffer or complete the operations.
  @retval  EFI_ACCESS_DENIED    The firmware volume containing the searched 
                                firmware file is configured to disallow reads.
**/
EFI_STATUS 
AuthAndMountFvFromPartition (IN  EFI_GUID          *PartitionGuid,
                             IN  CONST CHAR8       *FvPartitionName,
                             IN  EFI_GUID          *MountFVFileGUID  OPTIONAL)
{
  EFI_STATUS    Status = EFI_NOT_FOUND;
  VOID  *ReadBuffer = NULL;
  UINTN  ImageSize = 0;
  CHAR16  *PartitionLabel = NULL;
  UINTN LabelLen;
  
  if ((FvPartitionName == NULL && PartitionGuid == NULL) || 
      (FvPartitionName != NULL && PartitionGuid != NULL))
  {
    DEBUG ((EFI_D_WARN, " Error: MountFvPartition requires EITHER Fv name OR Guid.\r\n"));
    return EFI_INVALID_PARAMETER;
  }
  
  if (FvPartitionName != NULL)
  {
      LabelLen = AsciiStrSize (FvPartitionName);
      
      PartitionLabel = AllocatePool (LabelLen * sizeof(*PartitionLabel));
      if (PartitionLabel == NULL)
        return EFI_OUT_OF_RESOURCES;

      AsciiStrToUnicodeStrS (FvPartitionName, PartitionLabel, LabelLen);
  }

  Status = ReadFromPartition (PartitionGuid, PartitionLabel, &ReadBuffer, &ImageSize, 0);

  if (PartitionLabel)
    FreePool (PartitionLabel);

  if (EFI_ERROR(Status))
  {
    DEBUG ((EFI_D_WARN, "Failed to read from specified partition\n"));
    return Status;
  }
  
  Status = AuthAndMountFVFromBuffer (ReadBuffer, ImageSize, MountFVFileGUID);

  FreePages (ReadBuffer, ImageSize / EFI_PAGE_SIZE);

  if (EFI_ERROR(Status))
    return Status;

  if (FvPartitionName != NULL)
    DEBUG ((EFI_D_WARN, "Successfully loaded FV from partition label: %a \n", FvPartitionName));
  else
    DEBUG ((EFI_D_WARN, "Successfully loaded FV from Partition with Guid: %g\n", PartitionGuid));

  return Status;
}


EFI_STATUS
MountDesiredFVFromBuffer(IN VOID *Buffer, 
                         IN UINTN BufferSize,
                         IN  EFI_GUID *DesiredFvGuid,
                         IN EFI_GUID *DesiredFVFileGUID)
{
   EFI_STATUS    Status = EFI_NOT_FOUND;

   if (Buffer == NULL || DesiredFVFileGUID == NULL || DesiredFvGuid == NULL)
     return EFI_INVALID_PARAMETER;

   Status = AuthAndMountFVFromBuffer(Buffer, BufferSize, DesiredFVFileGUID); 
   if (Status != EFI_SUCCESS) 
     return Status;

   /* If we have mounted the desired FV then exit */
   if(GuidedFvIsMounted(DesiredFvGuid))
     return EFI_SUCCESS;

   return EFI_NOT_FOUND;
}


EFI_STATUS
MountDesiredFVFromPartition(IN  CONST CHAR8 *FvPartitionName, 
                            IN  EFI_GUID *PartitionGuid, 
                            IN  EFI_GUID *DesiredFvGuid,
                            IN  EFI_GUID *DesiredFVFileGUID)
{
   EFI_STATUS    Status = EFI_NOT_FOUND;

   if (FvPartitionName == NULL && PartitionGuid == NULL)
   {
      DEBUG ((EFI_D_WARN, " Error: MountDesiredFvPartition requires Either Fv name OR Guid.\r\n"));
      return EFI_INVALID_PARAMETER;
   }
   
   /* If we have already mounted the partition then no need to mount again */
   if (GuidedFvIsMounted(PartitionGuid))
     return EFI_SUCCESS;

   /* If not then Mount FV from partition */
   Status = AuthAndMountFvFromPartition(PartitionGuid, FvPartitionName, DesiredFVFileGUID);
   if (EFI_ERROR(Status))
     return Status;
   
    /* If we have already mounted the desired FV then exit */
   if (GuidedFvIsMounted(DesiredFvGuid))
     return EFI_SUCCESS;

   return EFI_NOT_FOUND;
}


