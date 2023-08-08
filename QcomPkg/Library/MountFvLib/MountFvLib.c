/** @file
  This file includes methods for Parsing and enumerating FV in memory

  Copyright (c) 2019, Qualcomm Technologies, Inc. All Rights Reserved.
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
 03/27/19   yg       Created new file
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
#include <Library/MountFvLib.h>
#include <Library/QcomBdsLib.h>
#include <MemRegionInfo.h>
#include <Library/UefiCfgLib.h>
#include <Library/UefiLib.h>

extern EFI_GUID gEfiToolsFvPartitionTypeGuid;
extern EFI_GUID gToolsfvFileGuid;

// #define ENABLE_LOCAL_DEBUG_LOGS

#define FVB_DEVICE_SIGNATURE        SIGNATURE_32('_','F','V','B')
#define GET_OCCUPIED_SIZE(ActualSize, Alignment) \
  (ActualSize) + (((Alignment) - ((ActualSize) & ((Alignment) - 1))) & ((Alignment) - 1))

//
// UEFI Specification structures for FV LBA cache, device path and FVB device format
//
typedef struct {
  UINTN                       Base;
  UINTN                       Length;
} LBA_CACHE;

typedef struct {
  MEMMAP_DEVICE_PATH          MemMapDevPath;
  EFI_DEVICE_PATH_PROTOCOL    EndDevPath;
} FV_MEMMAP_DEVICE_PATH;

typedef struct {
  MEDIA_FW_VOL_DEVICE_PATH    FvDevPath;
  EFI_DEVICE_PATH_PROTOCOL    EndDevPath;
} FV_PIWG_DEVICE_PATH;

typedef struct {
  UINTN                                 Signature;
  EFI_HANDLE                            Handle;
  EFI_DEVICE_PATH_PROTOCOL              *DevicePath;
  EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL    FwVolBlockInstance;
  UINTN                                 NumBlocks;
  LBA_CACHE                             *LbaCache;
  UINT32                                FvbAttributes;
  EFI_PHYSICAL_ADDRESS                  BaseAddress;
  UINT32                                AuthenticationStatus;
} EFI_FW_VOL_BLOCK_DEVICE;


/* original DstBuffer allocated to decode guided section */
VOID*              OrigDstBuffer = NULL;
UINT32             OrigDstBufferPage = 0;

//
// Global data structures and variables
//
FV_MEMMAP_DEVICE_PATH mFvMemmapDevicePathTemplate = {
  {
    {
      HARDWARE_DEVICE_PATH,
      HW_MEMMAP_DP,
      {
        (UINT8)(sizeof (MEMMAP_DEVICE_PATH)),
        (UINT8)(sizeof (MEMMAP_DEVICE_PATH) >> 8)
      }
    },
    EfiMemoryMappedIO,
    (EFI_PHYSICAL_ADDRESS) 0,
    (EFI_PHYSICAL_ADDRESS) 0,
  },
  {
    END_DEVICE_PATH_TYPE,
    END_ENTIRE_DEVICE_PATH_SUBTYPE,
    {
      END_DEVICE_PATH_LENGTH,
      0
    }
  }
};

FV_PIWG_DEVICE_PATH mFvPIWGDevicePathTemplate = {
  {
    {
      MEDIA_DEVICE_PATH,
      MEDIA_PIWG_FW_VOL_DP,
      {
        (UINT8)(sizeof (MEDIA_FW_VOL_DEVICE_PATH)),
        (UINT8)(sizeof (MEDIA_FW_VOL_DEVICE_PATH) >> 8)
      }
    },
    { 0 }
  },
  {
    END_DEVICE_PATH_TYPE,
    END_ENTIRE_DEVICE_PATH_SUBTYPE,
    {
      END_DEVICE_PATH_LENGTH,
      0
    }
  }
};

EFI_FW_VOL_BLOCK_DEVICE  mFwVolBlock = {
  FVB_DEVICE_SIGNATURE,
  NULL,
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  0,
  NULL,
  0,
  0,
  0
};

EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL *FwVolBlkProtocol = NULL;

/**
  This routine produces a firmware volume block protocol on a given
  buffer.
  Function used from /MdeModulePkg/Core/Dxe/FwVolBlock.c

  @param  BaseAddress            base address of the firmware volume image
  @param  Length                 length of the firmware volume image
  @param  ParentHandle           handle of parent firmware volume, if this image
                                 came from an FV image file and section in another firmware
                                 volume (ala capsules)

  @retval EFI_VOLUME_CORRUPTED   Volume corrupted.
  @retval EFI_OUT_OF_RESOURCES   No enough buffer to be allocated.
  @retval EFI_SUCCESS            Successfully produced a FVB protocol on given
                                 buffer.

**/
EFI_STATUS
MountFVFromBuffer (
  IN EFI_PHYSICAL_ADDRESS   BaseAddress,
  IN UINT64                 Length,
  IN EFI_HANDLE             ParentHandle,
  IN UINT32                 AuthenticationStatus
  )
{
  EFI_FW_VOL_BLOCK_DEVICE       *FvbDev;
  EFI_FIRMWARE_VOLUME_HEADER    *FwVolHeader;
  UINTN                         BlockIndex;
  UINTN                         BlockIndex2;
  UINTN                         LinearOffset;
  UINT32                        FvAlignment;
  EFI_FV_BLOCK_MAP_ENTRY        *PtrBlockMapEntry;
  EFI_STATUS                    Status;

  FvAlignment = 0;
  FwVolHeader = (EFI_FIRMWARE_VOLUME_HEADER *)(UINTN) BaseAddress;
  //
  // Validate FV Header, if not as expected, return
  //
  if (FwVolHeader->Signature != EFI_FVH_SIGNATURE)
    return EFI_VOLUME_CORRUPTED;

  //
  // Get FvHeader alignment
  //
  FvAlignment = 1 << ((FwVolHeader->Attributes & EFI_FVB2_ALIGNMENT) >> 16);
  //
  // FvAlignment must be greater than or equal to 8 bytes of the minimum FFS alignment value.
  //
  if (FvAlignment < 8)
    FvAlignment = 8;

  if ((UINTN)BaseAddress % FvAlignment != 0)
    //
    // FvImage buffer is not at its required alignment.
    //
    return EFI_VOLUME_CORRUPTED;


  Status = gBS->LocateProtocol(&gEfiFirmwareVolumeBlockProtocolGuid,
                               NULL,
                               (VOID**) &FwVolBlkProtocol);
  ASSERT_EFI_ERROR (Status);

  CopyMem(&mFwVolBlock.FwVolBlockInstance, FwVolBlkProtocol, sizeof(EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL));

  //
  // Allocate EFI_FW_VOL_BLOCK_DEVICE
  //
  FvbDev = AllocateCopyPool (sizeof (EFI_FW_VOL_BLOCK_DEVICE), &mFwVolBlock);
  if (FvbDev == NULL)
    return EFI_OUT_OF_RESOURCES;

  FvbDev->BaseAddress   = BaseAddress;
  FvbDev->FvbAttributes = FwVolHeader->Attributes;
  FvbDev->FwVolBlockInstance.ParentHandle = ParentHandle;
  if (ParentHandle != NULL)
    FvbDev->AuthenticationStatus = AuthenticationStatus;

  //
  // Init the block caching fields of the device
  // First, count the number of blocks
  //
  FvbDev->NumBlocks = 0;
  for (PtrBlockMapEntry = FwVolHeader->BlockMap;
       PtrBlockMapEntry->NumBlocks != 0;
       PtrBlockMapEntry++)
  {
    FvbDev->NumBlocks += PtrBlockMapEntry->NumBlocks;
  }
  //
  // Second, allocate the cache
  //
  FvbDev->LbaCache = AllocatePool (FvbDev->NumBlocks * sizeof (LBA_CACHE));
  if (FvbDev->LbaCache == NULL)
  {
    FreePool (FvbDev);
    return EFI_OUT_OF_RESOURCES;
  }

  //
  // Last, fill in the cache with the linear address of the blocks
  //
  BlockIndex = 0;
  LinearOffset = 0;
  for (PtrBlockMapEntry = FwVolHeader->BlockMap;
       PtrBlockMapEntry->NumBlocks != 0; PtrBlockMapEntry++)
  {
    for (BlockIndex2 = 0; BlockIndex2 < PtrBlockMapEntry->NumBlocks; BlockIndex2++)
    {
      FvbDev->LbaCache[BlockIndex].Base = LinearOffset;
      FvbDev->LbaCache[BlockIndex].Length = PtrBlockMapEntry->Length;
      LinearOffset += PtrBlockMapEntry->Length;
      BlockIndex++;
    }
  }

  //
  // Judge whether FV name guid is produced in Fv extension header
  //
  if (FwVolHeader->ExtHeaderOffset == 0)
  {
    //
    // FV does not contains extension header, then produce MEMMAP_DEVICE_PATH
    //
    FvbDev->DevicePath = (EFI_DEVICE_PATH_PROTOCOL *) AllocateCopyPool (sizeof (FV_MEMMAP_DEVICE_PATH), &mFvMemmapDevicePathTemplate);
    if (FvbDev->DevicePath == NULL) 
    {
      FreePool (FvbDev);
      return EFI_OUT_OF_RESOURCES;
    }
    ((FV_MEMMAP_DEVICE_PATH *) FvbDev->DevicePath)->MemMapDevPath.StartingAddress = BaseAddress;
    ((FV_MEMMAP_DEVICE_PATH *) FvbDev->DevicePath)->MemMapDevPath.EndingAddress   = BaseAddress + FwVolHeader->FvLength - 1;
  } else {
    //
    // FV contains extension header, then produce MEDIA_FW_VOL_DEVICE_PATH
    //
    FvbDev->DevicePath = (EFI_DEVICE_PATH_PROTOCOL *) AllocateCopyPool (sizeof (FV_PIWG_DEVICE_PATH), &mFvPIWGDevicePathTemplate);
    if (FvbDev->DevicePath == NULL) 
    {
      FreePool (FvbDev);
      return EFI_OUT_OF_RESOURCES;
    }
    CopyGuid (
      &((FV_PIWG_DEVICE_PATH *)FvbDev->DevicePath)->FvDevPath.FvName,
      (GUID *)(UINTN)(BaseAddress + FwVolHeader->ExtHeaderOffset)
      );
  }

  //
  //
  // Attach FvVolBlock Protocol to new handle
  //
  Status = gBS->InstallMultipleProtocolInterfaces (
             &FvbDev->Handle,
             &gEfiFirmwareVolumeBlockProtocolGuid,     &FvbDev->FwVolBlockInstance,
             &gEfiDevicePathProtocolGuid,              FvbDev->DevicePath,
             NULL
             );

  return Status;

}

EFI_STATUS PerformGuidedSectionDecode (
    FfsFileInfo                   *FfsFileInfoPtr,
    OUT VOID                     **OutputBuffer,
    OUT UINTN                     *OutSizePtr
  )
{
  EFI_STATUS                              Status;
  UINT32                                  DstBufferSize = 0;
  VOID                                    *ScratchBuffer;
  UINT32                                  ScratchBufferSize;
  VOID                                    *DstBuffer = NULL;
  UINT16                                  SectionAttribute;
  UINT32                                  AuthenticationStatus;
  EFI_COMMON_SECTION_HEADER              *Section;

  if ((OutputBuffer == NULL) || (FfsFileInfoPtr == NULL) || (FfsFileInfoPtr->SectionPtr == NULL))
    return EFI_INVALID_PARAMETER;

  Section = (EFI_COMMON_SECTION_HEADER*)FfsFileInfoPtr->SectionPtr;

  *OutputBuffer = NULL;
  Status = EFI_NOT_FOUND;

  if (Section->Type != EFI_SECTION_GUID_DEFINED)
    return EFI_INVALID_PARAMETER;

  Status = ExtractGuidedSectionGetInfo (Section,
                                        &DstBufferSize,
                                        &ScratchBufferSize,
                                        &SectionAttribute);

  if (EFI_ERROR (Status))
  {
    //
    // GetInfo failed
    //
    DEBUG ((EFI_D_ERROR, "Decompress GetInfo Failed - %r\n", Status));
    return EFI_NOT_FOUND;
  }
  //
  // Allocate destination buffer, extra one page for adjustment
  //
  DstBuffer = (VOID *)(UINTN)AllocatePages (EFI_SIZE_TO_PAGES (DstBufferSize));
  if (DstBuffer == NULL)
    return EFI_OUT_OF_RESOURCES;

  //
  // Allocate scratch buffer
  //
  ScratchBuffer = (VOID *)(UINTN)AllocatePages (EFI_SIZE_TO_PAGES (ScratchBufferSize));
  if (ScratchBuffer == NULL)
    return EFI_OUT_OF_RESOURCES;

  //
  // Call decompress function
  //
  Status = ExtractGuidedSectionDecode (
                Section,
                &DstBuffer,
                ScratchBuffer,
                &AuthenticationStatus
                );

  FreePages (ScratchBuffer, EFI_SIZE_TO_PAGES (ScratchBufferSize));

  if (EFI_ERROR (Status))
  {
    //
    // Decompress failed
    //
    DEBUG ((EFI_D_ERROR, "Decompress Failed - %r\n", Status));
    return EFI_NOT_FOUND;
  }

  if (OutSizePtr)
    *OutSizePtr = DstBufferSize;
  *OutputBuffer = DstBuffer + 8;

#ifdef ENABLE_LOCAL_DEBUG_LOGS
  DEBUG ((EFI_D_ERROR, "Decompress Complete - %p\n", DstBuffer));
#endif

  return EFI_NOT_FOUND;
}

#define FV_CONTEXT_SIGNATURE    ('F' | ('v' << 8) | ('C' << 16) | ('t' << 24))

struct __FVContext
{
  UINT32 Signature;
  UINT32 Filler;
  VOID* FvBufferPtr;
  VOID* FvBufferEndPtr;
  VOID* CurrentFfsFilePtr;
  VOID* NextFfsFilePtr;
};

FVContext FvContexts[MAX_FV_CONTEXTS];
UINT8 FvCtxtStatus[MAX_FV_CONTEXTS];

VOID FreeFvContext (FVContext* Ctxt)
{
  int i;

  for (i = 0; i < MAX_FV_CONTEXTS; ++i)
  {
    if (&FvContexts[i] == Ctxt)
    {
      FvCtxtStatus[i] = 0;
      Ctxt->Signature = 0;
      Ctxt->Filler = 0;
      Ctxt->FvBufferPtr = 0;
      Ctxt->FvBufferEndPtr = 0;
      Ctxt->CurrentFfsFilePtr = 0;
      Ctxt->NextFfsFilePtr = 0;
      return;
    }
  }
}

FVContext* AllocateFvContext (VOID)
{
  int i;

  for (i = 0; i < MAX_FV_CONTEXTS; ++i)
  {
    if (FvCtxtStatus[i] == 0)
    {
      FvCtxtStatus[i] = 1;
      return &FvContexts[i];
    }
  }
  return NULL;
}

VOID CloseFVFile (FVContext* CtxtPtr)
{
  FreeFvContext (CtxtPtr);
}

FVContext* OpenFVFile (VOID * FVBuffer, UINTN BufferSize, UINTN* OPTIONAL FvSizePtr)
{
  EFI_FIRMWARE_VOLUME_HEADER     *FvHeader;
  VOID                           *FvEndPtr, *FfsFilePtr;
  FVContext                      *CtxtPtr;

  if (FVBuffer == NULL)
    return NULL;

  FvHeader = (EFI_FIRMWARE_VOLUME_HEADER*)FVBuffer;

  if (FvHeader->Signature != EFI_FVH_SIGNATURE)
    return NULL;

  // Header is 8 bytes smaller than the struct size
  if ((FvHeader->HeaderLength > (2 * sizeof(EFI_FIRMWARE_VOLUME_HEADER))) ||
      (FvHeader->HeaderLength & 0x1))
    return NULL;

  if (CalculateSum16 ((UINT16*)FvHeader, FvHeader->HeaderLength) != 0)
    return NULL;

  FvEndPtr = (VOID*)((UINTN)FVBuffer + FvHeader->FvLength);

  if (FvHeader->FvLength > BufferSize)
    return NULL;

  CtxtPtr = AllocateFvContext ();

  if (CtxtPtr == 0)
    return NULL;

  if (FvSizePtr)
    *FvSizePtr = FvHeader->FvLength;

  // FfsFile Header is located after FV Header
  FfsFilePtr = (VOID*)((UINTN)FvHeader + (UINTN)FvHeader->HeaderLength);

  CtxtPtr->Signature = FV_CONTEXT_SIGNATURE;
  CtxtPtr->FvBufferPtr = FVBuffer;
  CtxtPtr->FvBufferEndPtr = FvEndPtr;
  CtxtPtr->CurrentFfsFilePtr = FfsFilePtr;
  CtxtPtr->NextFfsFilePtr = 0;

  return CtxtPtr;
}

FfsFileInfo* GetFfsFileInfo (EFI_FFS_FILE_HEADER  *FfsPtr, UINTN FfsFileHdrSize, VOID* FfsEndPtr, FfsFileInfo* FileInfoPtr)
{
   EFI_COMMON_SECTION_HEADER     *Section;
   UINT32 SectionSize, HeaderSize;

   // FFS header checksum already verified so should already be valid
   if (FfsFileHdrSize == sizeof (EFI_FFS_FILE_HEADER2))
     Section = (EFI_COMMON_SECTION_HEADER*)(((EFI_FFS_FILE_HEADER2*)FfsPtr) + 1);
   else
     Section = (EFI_COMMON_SECTION_HEADER*)(FfsPtr + 1);

   FileInfoPtr->FileNameGuid = FfsPtr->Name;
   FileInfoPtr->FileType = FfsPtr->Type;
   FileInfoPtr->Attributes = FfsPtr->Attributes;
   FileInfoPtr->UIFileName[0] = 0;
   FileInfoPtr->FileSize = 0;
   FileInfoPtr->ROFileDataPtr = NULL;
   FileInfoPtr->SectionPtr = NULL;

   while ((VOID*)Section < FfsEndPtr)
   {
     VOID* PayloadPtr;

     if (IS_SECTION2 (Section))
     {
       SectionSize = SECTION2_SIZE (Section);
       PayloadPtr = (VOID*)(((EFI_COMMON_SECTION_HEADER2 *)Section) + 1);
       HeaderSize = sizeof(EFI_COMMON_SECTION_HEADER2);
     }
     else
     {
       SectionSize = SECTION_SIZE (Section);
       PayloadPtr = (VOID*)(Section + 1);
       HeaderSize = sizeof(EFI_COMMON_SECTION_HEADER);
     }

#ifdef ENABLE_LOCAL_DEBUG_LOGS
     DEBUG ((EFI_D_ERROR, "Section %09lX Type - %x Size : %x\n", Section, Section->Type, SectionSize));
#endif

     switch (Section->Type)
     {
       case EFI_SECTION_USER_INTERFACE:
         {
           UINTN CopiedChars;
           UnicodeStrnToAsciiStrS ((CONST CHAR16*)PayloadPtr,  sizeof(FileInfoPtr->UIFileName) - 1, FileInfoPtr->UIFileName, sizeof(FileInfoPtr->UIFileName), &CopiedChars);
         }
         break;

       // Data payload types
       case EFI_SECTION_GUID_DEFINED:
         FileInfoPtr->Attributes |= FFS_FILE_ATTRIBUTE_COMPRESSED;
         // Continue to common code with rest of cases
       case EFI_SECTION_PE32:
       case EFI_SECTION_RAW:
       case EFI_SECTION_FIRMWARE_VOLUME_IMAGE:
          FileInfoPtr->FileSize = SectionSize - HeaderSize;
          FileInfoPtr->ROFileDataPtr = PayloadPtr;
          FileInfoPtr->SectionPtr = Section;
          break;

       case EFI_FV_FILETYPE_FFS_PAD:
          return NULL;

       case EFI_SECTION_DXE_DEPEX:
          break;

       default:
        DEBUG ((EFI_D_ERROR, "Unknown section type - %X\n", Section->Type));
     }

     // Move to next section
     SectionSize = (SectionSize + 3) & ~3;
     Section = (EFI_COMMON_SECTION_HEADER*)((UINTN)Section + SectionSize);

     if (SectionSize == 0)
       return NULL;
   }

   return FileInfoPtr;
}

FfsFileInfo* GetNextFileFromFV (FVContext* Ctxt, FfsFileInfo* FileInfoPtr, UINT8 OPTIONAL GetFileType)
{
  EFI_FFS_FILE_HEADER  *FfsPtr;
  UINT32 FfsSize;
  VOID *FvEndPtr, *FfsEndPtr;
  UINT8 HeaderChecksum;
  UINTN HeaderSize;

  if ((Ctxt == 0) || (Ctxt->Signature != FV_CONTEXT_SIGNATURE) || (FileInfoPtr == 0))
    return NULL;

  // NOTE: Since operating on the source buffer of the container FV, don't
  // align the absolute value of pointer for FFS to 8, instead align the
  // byte offset wrt original FV address, which will have same effect as 
  // absolute pointer aligned to 8 bytes. This doesn't apply for a FV copied
  // out to new buffer

  // If we already traversed through, then advance to next file
  if (Ctxt->NextFfsFilePtr != 0)
    Ctxt->CurrentFfsFilePtr = Ctxt->NextFfsFilePtr;

  FfsPtr = Ctxt->CurrentFfsFilePtr;
  FvEndPtr = Ctxt->FvBufferEndPtr;

  while ((VOID*)FfsPtr < FvEndPtr)
  {
    VOID *FfsHdrEnd;

    FfsHdrEnd = (VOID*)((UINTN)FfsPtr + sizeof (EFI_FFS_FILE_HEADER));

    // Make sure the FFS header is still within the buffer limits
    if (FfsHdrEnd >= FvEndPtr)
      return NULL;

    if (IS_FFS_FILE2 (FfsPtr))
    {
      HeaderSize = sizeof (EFI_FFS_FILE_HEADER2);
      HeaderChecksum = CalculateSum8 ((UINT8 *) FfsPtr, HeaderSize);
      FfsSize = FFS_FILE2_SIZE (FfsPtr);
    }
    else
    {
      HeaderSize = sizeof (EFI_FFS_FILE_HEADER);
      HeaderChecksum = CalculateSum8 ((UINT8 *) FfsPtr, HeaderSize);
      FfsSize = FFS_FILE_SIZE (FfsPtr);
    }

    HeaderChecksum = (UINT8) (HeaderChecksum - FfsPtr->State - FfsPtr->IntegrityCheck.Checksum.File);

    if (HeaderChecksum != 0)
       return NULL;
    
    if ((FfsSize == 0) || (FfsPtr->Type == 0xFF))
      return NULL;

#ifdef ENABLE_LOCAL_DEBUG_LOGS
    DEBUG ((EFI_D_ERROR, "FFS type - %x, Sz : %X\n", FfsPtr->Type, FfsSize));
#endif

    FfsEndPtr = (VOID*)((UINTN)FfsPtr + FfsSize);

    if (FfsEndPtr > FvEndPtr)
      return NULL;

    // This serves the purpose of aligning the FFS to 8 bytes boundary as stated in above note
    FfsSize = (FfsSize + 7) & ~7;
    Ctxt->NextFfsFilePtr = (VOID*)((UINTN)FfsPtr + FfsSize);

    if ((FfsPtr->Type != EFI_FV_FILETYPE_FFS_PAD) && ((GetFileType == 0) || (FfsPtr->Type == GetFileType)))
    {
      Ctxt->CurrentFfsFilePtr = FfsPtr;

      // Got to the FFS file of interest
      // now process all section entries to get the FFS File info
      return GetFfsFileInfo (FfsPtr, HeaderSize, FfsEndPtr, FileInfoPtr);
    }

    // Goto next FFS File
    FfsPtr = (EFI_FFS_FILE_HEADER*)Ctxt->NextFfsFilePtr;
  }
  return NULL;
}


/**
  Process the buffer to obtain the decompressed buffer and use that to produce the
  FVB protocol on the buffer.
  Parts of the function used from MdeModulePkg/Core/Dxe/Dispatcher/Dispatcher.c
  Parts of the function used from EmbeddedPkg/Library/PrePiLib/FwVol.c

  @param  Buffer                The FV buffer to be processed

  @retval EFI_OUT_OF_RESOURCES  No enough memory or other resource.
  @retval EFI_VOLUME_CORRUPTED  Corrupted volume.
  @retval EFI_SUCCESS           Function successfully returned.
  @retval EFI_INVALID_PARAMETER Invalid parameters

**/

/* Open FV, traverse through all FFS files, looking for FV
 *
 *  FV Contains bunch of FFS files
 *      Each FFS file can be any file type
 *      Each FFS file contains bunch of sections (which file specific meta data set)
 *        Each section represents either data, file name GUID, UI name etc
 *
 *
 * */

EFI_STATUS
ProcessAndMountFvImageFile (IN  VOID        *Buffer,
                            OUT UINTN        BufferSize,
                            IN  EFI_GUID    *MountFvFileGuid OPTIONAL)
{
  FVContext*     FvCtxt;
  FfsFileInfo    FfsFileInfo, *FfsFileInfoPtr;
  VOID *OutBuffer;
  UINTN OutSize = 0, ActualFvSize = 0;
  EFI_STATUS Status;
  
  if (Buffer == NULL || BufferSize == 0)
    return EFI_INVALID_PARAMETER;

  FvCtxt = OpenFVFile (Buffer, BufferSize, &ActualFvSize);

  if (FvCtxt == NULL)
    return EFI_INVALID_PARAMETER;

  FfsFileInfoPtr = GetNextFileFromFV (FvCtxt, &FfsFileInfo, 0);

  while (FfsFileInfoPtr)
  {
#ifdef ENABLE_LOCAL_DEBUG_LOGS
    DEBUG ((EFI_D_ERROR, "File : %g\n", &FfsFileInfoPtr->FileNameGuid));
    DEBUG ((EFI_D_ERROR, "File Size : %d (0x%X)\n", FfsFileInfoPtr->FileSize, FfsFileInfoPtr->FileSize));
    DEBUG ((EFI_D_ERROR, "File Type : %x\n", FfsFileInfoPtr->FileType));
    DEBUG ((EFI_D_ERROR, "File UI Name : %a\n", FfsFileInfoPtr->UIFileName));
    DEBUG ((EFI_D_ERROR, "File Ptr : %p\n\n", FfsFileInfoPtr->ROFileDataPtr));
#endif

    if (FfsFileInfoPtr->Attributes & FFS_FILE_ATTRIBUTE_COMPRESSED)
    {
       PerformGuidedSectionDecode (FfsFileInfoPtr, &OutBuffer, &OutSize);
       Status = MountFVFromBuffer ((EFI_PHYSICAL_ADDRESS) (UINTN) OutBuffer,
                                   (UINT64)OutSize,
                                    NULL,
                                    0);
       ProcessAndMountFvImageFile (OutBuffer, OutSize, MountFvFileGuid);
    }

    if (MountFvFileGuid)
    {
      if (CompareGuid (MountFvFileGuid, &FfsFileInfoPtr->FileNameGuid))
        ProcessAndMountFvImageFile ((VOID*)FfsFileInfoPtr->ROFileDataPtr, FfsFileInfoPtr->FileSize, MountFvFileGuid);

      // If we don't need to drill down further, return from here or continue
      // to recursively process all FV's in the FV
      // CloseFVFile (FvCtxt);
      // return EFI_SUCCESS;
    }

    FfsFileInfoPtr = GetNextFileFromFV (FvCtxt, &FfsFileInfo, 0);
  }

#ifdef ENABLE_LOCAL_DEBUG_LOGS
  DEBUG ((EFI_D_ERROR, "Done processing FV\n"));
#endif

  CloseFVFile (FvCtxt);

  return EFI_SUCCESS;
}

