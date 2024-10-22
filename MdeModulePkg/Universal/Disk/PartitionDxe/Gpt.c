/** @file
  Decode a hard disk partitioned with the GPT scheme in the UEFI 2.0
  specification.

  Caution: This file requires additional review when modified.
  This driver will have external input - disk partition.
  This external input must be validated carefully to avoid security issue like
  buffer overflow, integer overflow.

  PartitionInstallGptChildHandles() routine will read disk partition content and
  do basic validation before PartitionInstallChildHandle().

  PartitionValidGptTable(), PartitionCheckGptEntry() routine will accept disk
  partition content and validate the GPT table and GPT entry.

Copyright (c) 2018 Qualcomm Technologies, Inc. All rights reserved.
Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/


#include "Partition.h"

#if defined (QCOM_EDK2_PATCH)
#define MAX_NUMBER_OF_PARTITIONS 128
#define MAX_PARTITION_SIZE       128
#define GPT_HEADER_SIZE           1
#endif // QCOM_EDK2_PATCH 


/**
  Install child handles if the Handle supports GPT partition structure.

  Caution: This function may receive untrusted input.
  The GPT partition table header is external input, so this routine
  will do basic validation for GPT partition table header before return.

  @param[in]  BlockIo     Parent BlockIo interface.
  @param[in]  DiskIo      Disk Io protocol.
  @param[in]  Lba         The starting Lba of the Partition Table
  @param[out] PartHeader  Stores the partition table that is read

  @retval TRUE      The partition table is valid
  @retval FALSE     The partition table is not valid

**/
BOOLEAN
PartitionValidGptTable (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_LBA                     Lba,
  OUT EFI_PARTITION_TABLE_HEADER  *PartHeader
  );

/**
  Check if the CRC field in the Partition table header is valid
  for Partition entry array.

  @param[in]  BlockIo     Parent BlockIo interface
  @param[in]  DiskIo      Disk Io Protocol.
  @param[in]  PartHeader  Partition table header structure

  @retval TRUE      the CRC is valid
  @retval FALSE     the CRC is invalid

**/
BOOLEAN
PartitionCheckGptEntryArrayCRC (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader
  );


/**
  Restore Partition Table to its alternate place
  (Primary -> Backup or Backup -> Primary).

  @param[in]  BlockIo     Parent BlockIo interface.
  @param[in]  DiskIo      Disk Io Protocol.
  @param[in]  PartHeader  Partition table header structure.

  @retval TRUE      Restoring succeeds
  @retval FALSE     Restoring failed

**/
BOOLEAN
PartitionRestoreGptTable (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader
  );


/**
  This routine will check GPT partition entry and return entry status.

  Caution: This function may receive untrusted input.
  The GPT partition entry is external input, so this routine
  will do basic validation for GPT partition entry and report status.

  @param[in]    PartHeader    Partition table header structure
  @param[in]    PartEntry     The partition entry array
  @param[out]   PEntryStatus  the partition entry status array 
                              recording the status of each partition

**/
VOID
PartitionCheckGptEntry (
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader,
  IN  EFI_PARTITION_ENTRY         *PartEntry,
  OUT EFI_PARTITION_ENTRY_STATUS  *PEntryStatus
  );


/**
  Checks the CRC32 value in the table header.

  @param  MaxSize   Max Size limit
  @param  Size      The size of the table
  @param  Hdr       Table to check

  @return TRUE    CRC Valid
  @return FALSE   CRC Invalid

**/
BOOLEAN
PartitionCheckCrcAltSize (
  IN UINTN                 MaxSize,
  IN UINTN                 Size,
  IN OUT EFI_TABLE_HEADER  *Hdr
  );


/**
  Checks the CRC32 value in the table header.

  @param  MaxSize   Max Size limit
  @param  Hdr       Table to check

  @return TRUE      CRC Valid
  @return FALSE     CRC Invalid

**/
BOOLEAN
PartitionCheckCrc (
  IN UINTN                 MaxSize,
  IN OUT EFI_TABLE_HEADER  *Hdr
  );


/**
  Updates the CRC32 value in the table header.

  @param  Size   The size of the table
  @param  Hdr    Table to update

**/
VOID
PartitionSetCrcAltSize (
  IN UINTN                 Size,
  IN OUT EFI_TABLE_HEADER  *Hdr
  );


/**
  Updates the CRC32 value in the table header.

  @param  Hdr    Table to update

**/
VOID
PartitionSetCrc (
  IN OUT EFI_TABLE_HEADER *Hdr
  );

/**
  Install child handles if the Handle supports GPT partition structure.

  Caution: This function may receive untrusted input.
  The GPT partition table is external input, so this routine
  will do basic validation for GPT partition table before install
  child handle for each GPT partition.

  @param[in]  This       Calling context.
  @param[in]  Handle     Parent Handle.
  @param[in]  DiskIo     Parent DiskIo interface.
  @param[in]  DiskIo2    Parent DiskIo2 interface.
  @param[in]  BlockIo    Parent BlockIo interface.
  @param[in]  BlockIo2   Parent BlockIo2 interface.
  @param[in]  DevicePath Parent Device Path.

  @retval EFI_SUCCESS           Valid GPT disk.
  @retval EFI_MEDIA_CHANGED     Media changed Detected.
  @retval other                 Not a valid GPT disk.

**/
EFI_STATUS
PartitionInstallGptChildHandles (
  IN  EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN  EFI_HANDLE                   Handle,
  IN  EFI_DISK_IO_PROTOCOL         *DiskIo,
  IN  EFI_DISK_IO2_PROTOCOL        *DiskIo2,
  IN  EFI_BLOCK_IO_PROTOCOL        *BlockIo,
  IN  EFI_BLOCK_IO2_PROTOCOL       *BlockIo2,
  IN  EFI_DEVICE_PATH_PROTOCOL     *DevicePath
  )
{
  EFI_STATUS                   Status;
  UINT32                       BlockSize;
  EFI_LBA                      LastBlock;
  MASTER_BOOT_RECORD           *ProtectiveMbr;
  EFI_PARTITION_TABLE_HEADER   *PrimaryHeader;
  EFI_PARTITION_TABLE_HEADER   *BackupHeader;
  EFI_PARTITION_ENTRY          *PartEntry;
  EFI_PARTITION_ENTRY          *Entry;
  EFI_PARTITION_ENTRY_STATUS   *PEntryStatus;
  UINTN                        Index;
  EFI_STATUS                   GptValidStatus;
  HARDDRIVE_DEVICE_PATH        HdDev;
  UINT32                       MediaId;
  EFI_PARTITION_INFO_PROTOCOL  PartitionInfo;
#if defined (QCOM_EDK2_PATCH)
  EFI_STATUS                  ProtectiveMbrValidStatus = EFI_SUCCESS;
  BOOLEAN                     UpdateBackupGpt = FALSE;
  EFI_PARTITION_TABLE_HEADER  *PartHdr;
#endif //QCOM_EDK2_PATCH

  ProtectiveMbr = NULL;
  PrimaryHeader = NULL;
  BackupHeader  = NULL;
  PartEntry     = NULL;
  PEntryStatus  = NULL;
#if defined (QCOM_EDK2_PATCH)
  PartHdr       = NULL;
#endif //QCOM_EDK2_PATCH

  BlockSize     = BlockIo->Media->BlockSize;
  LastBlock     = BlockIo->Media->LastBlock;
  MediaId       = BlockIo->Media->MediaId;

  DEBUG ((EFI_D_INFO, " BlockSize : %d \n", BlockSize));
  DEBUG ((EFI_D_INFO, " LastBlock : %lx \n", LastBlock));

  GptValidStatus = EFI_NOT_FOUND;

  //
  // Allocate a buffer for the Protective MBR
  //
#if defined (QCOM_EDK2_PATCH)
  ProtectiveMbr = AllocateZeroPool (BlockSize);
#else
  ProtectiveMbr = AllocatePool (BlockSize);
#endif //QCOM_EDK2_PATCH

  if (ProtectiveMbr == NULL) {
    return EFI_NOT_FOUND;
  }

  //
  // Read the Protective MBR from LBA #0
  //
  Status = DiskIo->ReadDisk (
                     DiskIo,
                     MediaId,
                     0,
                     BlockSize,
                     ProtectiveMbr
                     );
  if (EFI_ERROR (Status)) {
    GptValidStatus = Status;
    goto Done;
  }

  //
  // Verify that the Protective MBR is valid
  //
  for (Index = 0; Index < MAX_MBR_PARTITIONS; Index++) {
    if (ProtectiveMbr->Partition[Index].BootIndicator == 0x00 &&
        ProtectiveMbr->Partition[Index].OSIndicator == PMBR_GPT_PARTITION &&
        UNPACK_UINT32 (ProtectiveMbr->Partition[Index].StartingLBA) == 1
        ) {
      break;
    }
  }
  if (Index == MAX_MBR_PARTITIONS) {
#if defined (QCOM_EDK2_PATCH)
    //
    // Go ahead and validate the GPT despite MBR validation failure.
    // Update MBR if GPT validation passes.
    //
  	DEBUG ((EFI_D_INFO, " Protective MBR validation might be needed. \n"));
  	ProtectiveMbrValidStatus = EFI_NOT_FOUND;
#else
    goto Done;
#endif //QCOM_EDK2_PATCH
  }

  //
  // Allocate the GPT structures
  //
  PrimaryHeader = AllocateZeroPool (sizeof (EFI_PARTITION_TABLE_HEADER));
  if (PrimaryHeader == NULL) {
    goto Done;
  }

  BackupHeader = AllocateZeroPool (sizeof (EFI_PARTITION_TABLE_HEADER));
  if (BackupHeader == NULL) {
    goto Done;
  }

  //
  // Check primary and backup partition tables
  //
  if (!PartitionValidGptTable (BlockIo, DiskIo, PRIMARY_PART_HEADER_LBA, PrimaryHeader)) {
    DEBUG ((EFI_D_INFO, " Not Valid primary partition table\n"));

    if (!PartitionValidGptTable (BlockIo, DiskIo, LastBlock, BackupHeader)) {
      DEBUG ((EFI_D_INFO, " Not Valid backup partition table\n"));
      goto Done;
    } else {
      DEBUG ((EFI_D_INFO, " Valid backup partition table\n"));
      DEBUG ((EFI_D_INFO, " Restore primary partition table by the backup\n"));

      if (!PartitionRestoreGptTable (BlockIo, DiskIo, BackupHeader)) {
        DEBUG ((EFI_D_INFO, " Restore primary partition table error\n"));
      }

      if (PartitionValidGptTable (BlockIo, DiskIo, BackupHeader->AlternateLBA, PrimaryHeader)) {
        DEBUG ((EFI_D_INFO, " Restore backup partition table success\n"));
      }
    }
 
#if defined (QCOM_EDK2_PATCH)
    } else {
  	if (PrimaryHeader->AlternateLBA != LastBlock) {
      //
      // Update Primary GPT with the last LBA of memory as the backup LBA
      // and then update Backup GPT
      //
      DEBUG ((EFI_D_ERROR, " Valid primary but incorrect AlternateLBA.\n"));
      UpdateBackupGpt = TRUE;

      PartHdr   = AllocateZeroPool (BlockSize);
  	  if (PartHdr == NULL) {
        goto Done;
      }

      PrimaryHeader->AlternateLBA = LastBlock;
      PrimaryHeader->LastUsableLBA = PrimaryHeader->AlternateLBA - (((MAX_NUMBER_OF_PARTITIONS * MAX_PARTITION_SIZE) / BlockSize) + GPT_HEADER_SIZE);
      PartitionSetCrc ((EFI_TABLE_HEADER *) PrimaryHeader);
      CopyMem (PartHdr, PrimaryHeader, sizeof (EFI_PARTITION_TABLE_HEADER));


      Status = DiskIo->WriteDisk (
                     DiskIo,
                     BlockIo->Media->MediaId,
                     MultU64x32 (PrimaryHeader->MyLBA, BlockIo->Media->BlockSize),
                     BlockSize,
					 PartHdr);
  	  if (EFI_ERROR (Status)) {
        DEBUG ((EFI_D_ERROR, " Update primary partition table error\n"));
      }      

    } else if (!PartitionValidGptTable (BlockIo, DiskIo, PrimaryHeader->AlternateLBA, BackupHeader)) {
      //
      // Update invalid Backup GPT with the Primary GPT
      //
      DEBUG ((EFI_D_ERROR, " Valid primary and !Valid backup partition table\n"));
      UpdateBackupGpt = TRUE;
    } else if (PrimaryHeader->PartitionEntryArrayCRC32 != BackupHeader->PartitionEntryArrayCRC32) {
      //
      // Update Backup GPT if the CRC does not match. 
      // This helps in identifying partition array changes
      //
      DEBUG ((EFI_D_ERROR, " Backup GPT CRC does not match with Primary GPT CRC. \n"));
      UpdateBackupGpt = TRUE;
    }
    
    if (UpdateBackupGpt == TRUE) {
      DEBUG ((EFI_D_ERROR, " Restore backup partition table by the primary\n"));
     
      if (!PartitionRestoreGptTable (BlockIo, DiskIo, PrimaryHeader)) {
        DEBUG ((EFI_D_ERROR, " Restore  backup partition table error\n"));
      }

      if (PartitionValidGptTable (BlockIo, DiskIo, PrimaryHeader->AlternateLBA, BackupHeader)) {
        DEBUG ((EFI_D_ERROR, " Restore backup partition table success\n"));
      }
    }

  }
#else  //QCOM_EDK2_PATCH
  } else if (!PartitionValidGptTable (BlockIo, DiskIo, PrimaryHeader->AlternateLBA, BackupHeader)) {
    DEBUG ((EFI_D_INFO, " Valid primary and !Valid backup partition table\n"));
    DEBUG ((EFI_D_INFO, " Restore backup partition table by the primary\n"));
    if (!PartitionRestoreGptTable (BlockIo, DiskIo, PrimaryHeader)) {
      DEBUG ((EFI_D_INFO, " Restore backup partition table error\n"));
    }

    if (PartitionValidGptTable (BlockIo, DiskIo, PrimaryHeader->AlternateLBA, BackupHeader)) {
      DEBUG ((EFI_D_INFO, " Restore backup partition table success\n"));
    }

  }
#endif //QCOM_EDK2_PATCH

  DEBUG ((EFI_D_INFO, " Valid primary and Valid backup partition table\n"));

  //
  // Read the EFI Partition Entries
  //
  PartEntry = AllocatePool (PrimaryHeader->NumberOfPartitionEntries * PrimaryHeader->SizeOfPartitionEntry);
#if defined (QCOM_EDK2_PATCH)
  DEBUG ((EFI_D_INFO, "SizeOfPartitionEntry = %d\n", PrimaryHeader->SizeOfPartitionEntry));
#endif //QCOM_EDK2_PATCH

  if (PartEntry == NULL) {
    DEBUG ((EFI_D_ERROR, "Allocate pool error\n"));
    goto Done;
  }

  Status = DiskIo->ReadDisk (
                     DiskIo,
                     MediaId,
                     MultU64x32(PrimaryHeader->PartitionEntryLBA, BlockSize),
                     PrimaryHeader->NumberOfPartitionEntries * (PrimaryHeader->SizeOfPartitionEntry),
                     PartEntry
                     );
  if (EFI_ERROR (Status)) {
    GptValidStatus = Status;
    DEBUG ((EFI_D_ERROR, " Partition Entry ReadDisk error\n"));
    goto Done;
  }

  DEBUG ((EFI_D_INFO, " Partition entries read block success\n"));

  DEBUG ((EFI_D_INFO, " Number of partition entries: %d\n", PrimaryHeader->NumberOfPartitionEntries));

  PEntryStatus = AllocateZeroPool (PrimaryHeader->NumberOfPartitionEntries * sizeof (EFI_PARTITION_ENTRY_STATUS));
  if (PEntryStatus == NULL) {
    DEBUG ((EFI_D_ERROR, "Allocate pool error\n"));
    goto Done;
  }

  //
  // Check the integrity of partition entries
  //
  PartitionCheckGptEntry (PrimaryHeader, PartEntry, PEntryStatus);

  //
  // If we got this far the GPT layout of the disk is valid and we should return true
  //
  GptValidStatus = EFI_SUCCESS;

  //
  // Create child device handles
  //
  for (Index = 0; Index < PrimaryHeader->NumberOfPartitionEntries; Index++) {
    Entry = (EFI_PARTITION_ENTRY *) ((UINT8 *) PartEntry + Index * PrimaryHeader->SizeOfPartitionEntry);
    if (CompareGuid (&Entry->PartitionTypeGUID, &gEfiPartTypeUnusedGuid) ||
        PEntryStatus[Index].OutOfRange ||
        PEntryStatus[Index].Overlap ||
        PEntryStatus[Index].OsSpecific
        ) {
      //
      // Don't use null EFI Partition Entries, Invalid Partition Entries or OS specific
      // partition Entries
      //
      continue;
    }

    ZeroMem (&HdDev, sizeof (HdDev));
    HdDev.Header.Type      = MEDIA_DEVICE_PATH;
    HdDev.Header.SubType   = MEDIA_HARDDRIVE_DP;
    SetDevicePathNodeLength (&HdDev.Header, sizeof (HdDev));

    HdDev.PartitionNumber  = (UINT32) Index + 1;
    HdDev.MBRType          = MBR_TYPE_EFI_PARTITION_TABLE_HEADER;
    HdDev.SignatureType    = SIGNATURE_TYPE_GUID;
    HdDev.PartitionStart   = Entry->StartingLBA;
    HdDev.PartitionSize    = Entry->EndingLBA - Entry->StartingLBA + 1;
    CopyMem (HdDev.Signature, &Entry->UniquePartitionGUID, sizeof (EFI_GUID));

    ZeroMem (&PartitionInfo, sizeof (EFI_PARTITION_INFO_PROTOCOL));
    PartitionInfo.Revision = EFI_PARTITION_INFO_PROTOCOL_REVISION;
    PartitionInfo.Type     = PARTITION_TYPE_GPT;
    if (CompareGuid (&Entry->PartitionTypeGUID, &gEfiPartTypeSystemPartGuid)) {
      PartitionInfo.System = 1;
    }
    CopyMem (&PartitionInfo.Info.Gpt, Entry, sizeof (EFI_PARTITION_ENTRY));

    DEBUG ((EFI_D_INFO, " Index : %d\n", (UINT32) Index));
    DEBUG ((EFI_D_INFO, " Start LBA : %lx\n", (UINT64) HdDev.PartitionStart));
    DEBUG ((EFI_D_INFO, " End LBA : %lx\n", (UINT64) Entry->EndingLBA));
    DEBUG ((EFI_D_INFO, " Partition size: %lx\n", (UINT64) HdDev.PartitionSize));
    DEBUG ((EFI_D_INFO, " Start : %lx", MultU64x32 (Entry->StartingLBA, BlockSize)));
    DEBUG ((EFI_D_INFO, " End : %lx\n", MultU64x32 (Entry->EndingLBA, BlockSize)));

    Status = PartitionInstallChildHandle (
               This,
               Handle,
               DiskIo,
               DiskIo2,
               BlockIo,
               BlockIo2,
               DevicePath,
               (EFI_DEVICE_PATH_PROTOCOL *) &HdDev,
               &PartitionInfo,
               Entry->StartingLBA,
               Entry->EndingLBA,
               BlockSize
#if defined (QCOM_EDK2_PATCH)
               ,
               &Entry->PartitionTypeGUID,
               Entry
#endif //QCOM_EDK2_PATCH
               );
  }
  
#if defined (QCOM_EDK2_PATCH)
  if (ProtectiveMbrValidStatus == EFI_NOT_FOUND) {
    //
    // Write valid Protective MBR
    //
    DEBUG ((EFI_D_INFO, "Write valid Protective MBR\n"));

    ProtectiveMbr->Signature = MBR_SIGNATURE;
    ProtectiveMbr->Partition[0].BootIndicator = 0x00;
    ProtectiveMbr->Partition[0].OSIndicator = PMBR_GPT_PARTITION;
    ProtectiveMbr->Partition[0].StartingLBA[0] = 1;

   	Status = DiskIo->WriteDisk (
                     DiskIo,
                     BlockIo->Media->MediaId,
                     0,
                     BlockIo->Media->BlockSize,
                     ProtectiveMbr
                     );
                         
    if (EFI_ERROR (Status)) {
      GptValidStatus = Status;
    }
  }
#endif //QCOM_EDK2_PATCH

  DEBUG ((EFI_D_INFO, "Prepare to Free Pool\n"));

Done:
  if (ProtectiveMbr != NULL) {
    FreePool (ProtectiveMbr);
  }
  if (PrimaryHeader != NULL) {
    FreePool (PrimaryHeader);
  }
  if (BackupHeader != NULL) {
    FreePool (BackupHeader);
  }
  if (PartEntry != NULL) {
    FreePool (PartEntry);
  }
  if (PEntryStatus != NULL) {
    FreePool (PEntryStatus);
  }
#if defined (QCOM_EDK2_PATCH)
  if (PartHdr != NULL) {
    FreePool (PartHdr);
  }
#endif //QCOM_EDK2_PATCH
  return GptValidStatus;
}

/**
  This routine will read GPT partition table header and return it.

  Caution: This function may receive untrusted input.
  The GPT partition table header is external input, so this routine
  will do basic validation for GPT partition table header before return.

  @param[in]  BlockIo     Parent BlockIo interface.
  @param[in]  DiskIo      Disk Io protocol.
  @param[in]  Lba         The starting Lba of the Partition Table
  @param[out] PartHeader  Stores the partition table that is read

  @retval TRUE      The partition table is valid
  @retval FALSE     The partition table is not valid

**/
BOOLEAN
PartitionValidGptTable (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_LBA                     Lba,
  OUT EFI_PARTITION_TABLE_HEADER  *PartHeader
  )
{
  EFI_STATUS                  Status;
  UINT32                      BlockSize;
  EFI_PARTITION_TABLE_HEADER  *PartHdr;
  UINT32                      MediaId;

  BlockSize = BlockIo->Media->BlockSize;
  MediaId   = BlockIo->Media->MediaId;
  PartHdr   = AllocateZeroPool (BlockSize);

  if (PartHdr == NULL) {
    DEBUG ((EFI_D_ERROR, "Allocate pool error\n"));
    return FALSE;
  }
  //
  // Read the EFI Partition Table Header
  //
  Status = DiskIo->ReadDisk (
                     DiskIo,
                     MediaId,
                     MultU64x32 (Lba, BlockSize),
                     BlockSize,
                     PartHdr
                     );
  if (EFI_ERROR (Status)) {
    FreePool (PartHdr);
    return FALSE;
  }

  if ((PartHdr->Header.Signature != EFI_PTAB_HEADER_ID) ||
      !PartitionCheckCrc (BlockSize, &PartHdr->Header) ||
      PartHdr->MyLBA != Lba ||
      (PartHdr->SizeOfPartitionEntry < sizeof (EFI_PARTITION_ENTRY))
      ) {
    DEBUG ((EFI_D_INFO, "Invalid efi partition table header\n"));
    FreePool (PartHdr);
    return FALSE;
  }

  //
  // Ensure the NumberOfPartitionEntries * SizeOfPartitionEntry doesn't overflow.
  //
  if (PartHdr->NumberOfPartitionEntries > DivU64x32 (MAX_UINTN, PartHdr->SizeOfPartitionEntry)) {
    FreePool (PartHdr);
    return FALSE;
  }

  CopyMem (PartHeader, PartHdr, sizeof (EFI_PARTITION_TABLE_HEADER));
  if (!PartitionCheckGptEntryArrayCRC (BlockIo, DiskIo, PartHeader)) {
    FreePool (PartHdr);
    return FALSE;
  }

  DEBUG ((EFI_D_INFO, " Valid efi partition table header\n"));
  FreePool (PartHdr);
  return TRUE;
}

/**
  Check if the CRC field in the Partition table header is valid
  for Partition entry array.

  @param[in]  BlockIo     Parent BlockIo interface
  @param[in]  DiskIo      Disk Io Protocol.
  @param[in]  PartHeader  Partition table header structure

  @retval TRUE      the CRC is valid
  @retval FALSE     the CRC is invalid

**/
BOOLEAN
PartitionCheckGptEntryArrayCRC (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader
  )
{
  EFI_STATUS  Status;
  UINT8       *Ptr;
  UINT32      Crc;
  UINTN       Size;

  //
  // Read the EFI Partition Entries
  //
  Ptr = AllocatePool (PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry);
  if (Ptr == NULL) {
    DEBUG ((EFI_D_ERROR, " Allocate pool error\n"));
    return FALSE;
  }

  Status = DiskIo->ReadDisk (
                    DiskIo,
                    BlockIo->Media->MediaId,
                    MultU64x32(PartHeader->PartitionEntryLBA, BlockIo->Media->BlockSize),
                    PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry,
                    Ptr
                    );
  if (EFI_ERROR (Status)) {
    FreePool (Ptr);
    return FALSE;
  }

  Size    = PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry;

  Status  = gBS->CalculateCrc32 (Ptr, Size, &Crc);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "CheckPEntryArrayCRC: Crc calculation failed\n"));
    FreePool (Ptr);
    return FALSE;
  }

  FreePool (Ptr);

  return (BOOLEAN) (PartHeader->PartitionEntryArrayCRC32 == Crc);
}


/**
  Restore Partition Table to its alternate place
  (Primary -> Backup or Backup -> Primary).

  @param[in]  BlockIo     Parent BlockIo interface.
  @param[in]  DiskIo      Disk Io Protocol.
  @param[in]  PartHeader  Partition table header structure.

  @retval TRUE      Restoring succeeds
  @retval FALSE     Restoring failed

**/
BOOLEAN
PartitionRestoreGptTable (
  IN  EFI_BLOCK_IO_PROTOCOL       *BlockIo,
  IN  EFI_DISK_IO_PROTOCOL        *DiskIo,
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader
  )
{
  EFI_STATUS                  Status;
  UINTN                       BlockSize;
  EFI_PARTITION_TABLE_HEADER  *PartHdr;
  EFI_LBA                     PEntryLBA;
  UINT8                       *Ptr;
  UINT32                      MediaId;

  PartHdr   = NULL;
  Ptr       = NULL;

  BlockSize = BlockIo->Media->BlockSize;
  MediaId   = BlockIo->Media->MediaId;

  PartHdr   = AllocateZeroPool (BlockSize);

  if (PartHdr == NULL) {
    DEBUG ((EFI_D_ERROR, "Allocate pool error\n"));
    return FALSE;
  }

  PEntryLBA = (PartHeader->MyLBA == PRIMARY_PART_HEADER_LBA) ? \
                             (PartHeader->LastUsableLBA + 1) : \
                             (PRIMARY_PART_HEADER_LBA + 1);

  CopyMem (PartHdr, PartHeader, sizeof (EFI_PARTITION_TABLE_HEADER));

  PartHdr->MyLBA              = PartHeader->AlternateLBA;
  PartHdr->AlternateLBA       = PartHeader->MyLBA;
  PartHdr->PartitionEntryLBA  = PEntryLBA;
  PartitionSetCrc ((EFI_TABLE_HEADER *) PartHdr);

  Status = DiskIo->WriteDisk (
                     DiskIo,
                     MediaId,
                     MultU64x32 (PartHdr->MyLBA, (UINT32) BlockSize),
                     BlockSize,
                     PartHdr
                     );
  if (EFI_ERROR (Status)) {
    goto Done;
  }

  Ptr = AllocatePool (PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry);
  if (Ptr == NULL) {
    DEBUG ((EFI_D_ERROR, " Allocate pool error\n"));
    Status = EFI_OUT_OF_RESOURCES;
    goto Done;
  }

  Status = DiskIo->ReadDisk (
                    DiskIo,
                    MediaId,
                    MultU64x32(PartHeader->PartitionEntryLBA, (UINT32) BlockSize),
                    PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry,
                    Ptr
                    );
  if (EFI_ERROR (Status)) {
    goto Done;
  }

  Status = DiskIo->WriteDisk (
                    DiskIo,
                    MediaId,
                    MultU64x32(PEntryLBA, (UINT32) BlockSize),
                    PartHeader->NumberOfPartitionEntries * PartHeader->SizeOfPartitionEntry,
                    Ptr
                    );

Done:
  FreePool (PartHdr);

  if (Ptr != NULL) {
    FreePool (Ptr);
  }

  if (EFI_ERROR (Status)) {
    return FALSE;
  }

  return TRUE;
}

/**
  This routine will check GPT partition entry and return entry status.

  Caution: This function may receive untrusted input.
  The GPT partition entry is external input, so this routine
  will do basic validation for GPT partition entry and report status.

  @param[in]    PartHeader    Partition table header structure
  @param[in]    PartEntry     The partition entry array
  @param[out]   PEntryStatus  the partition entry status array 
                              recording the status of each partition

**/
VOID
PartitionCheckGptEntry (
  IN  EFI_PARTITION_TABLE_HEADER  *PartHeader,
  IN  EFI_PARTITION_ENTRY         *PartEntry,
  OUT EFI_PARTITION_ENTRY_STATUS  *PEntryStatus
  )
{
  EFI_LBA              StartingLBA;
  EFI_LBA              EndingLBA;
  EFI_PARTITION_ENTRY  *Entry;
  UINTN                Index1;
  UINTN                Index2;

  DEBUG ((EFI_D_INFO, " start check partition entries\n"));
  for (Index1 = 0; Index1 < PartHeader->NumberOfPartitionEntries; Index1++) {
    Entry = (EFI_PARTITION_ENTRY *) ((UINT8 *) PartEntry + Index1 * PartHeader->SizeOfPartitionEntry);
    if (CompareGuid (&Entry->PartitionTypeGUID, &gEfiPartTypeUnusedGuid)) {
      continue;
    }

    StartingLBA = Entry->StartingLBA;
    EndingLBA   = Entry->EndingLBA;
    if (StartingLBA > EndingLBA ||
        StartingLBA < PartHeader->FirstUsableLBA ||
        StartingLBA > PartHeader->LastUsableLBA ||
        EndingLBA < PartHeader->FirstUsableLBA ||
        EndingLBA > PartHeader->LastUsableLBA
        ) {
      PEntryStatus[Index1].OutOfRange = TRUE;
      continue;
    }

    if ((Entry->Attributes & BIT1) != 0) {
      //
      // If Bit 1 is set, this indicate that this is an OS specific GUID partition. 
      //
      PEntryStatus[Index1].OsSpecific = TRUE;
    }

    for (Index2 = Index1 + 1; Index2 < PartHeader->NumberOfPartitionEntries; Index2++) {
      Entry = (EFI_PARTITION_ENTRY *) ((UINT8 *) PartEntry + Index2 * PartHeader->SizeOfPartitionEntry);
      if (CompareGuid (&Entry->PartitionTypeGUID, &gEfiPartTypeUnusedGuid)) {
        continue;
      }

      if (Entry->EndingLBA >= StartingLBA && Entry->StartingLBA <= EndingLBA) {
        //
        // This region overlaps with the Index1'th region
        //
        PEntryStatus[Index1].Overlap  = TRUE;
        PEntryStatus[Index2].Overlap  = TRUE;
        continue;
      }
    }
  }

  DEBUG ((EFI_D_INFO, " End check partition entries\n"));
}


/**
  Updates the CRC32 value in the table header.

  @param  Hdr    Table to update

**/
VOID
PartitionSetCrc (
  IN OUT EFI_TABLE_HEADER *Hdr
  )
{
  PartitionSetCrcAltSize (Hdr->HeaderSize, Hdr);
}


/**
  Updates the CRC32 value in the table header.

  @param  Size   The size of the table
  @param  Hdr    Table to update

**/
VOID
PartitionSetCrcAltSize (
  IN UINTN                 Size,
  IN OUT EFI_TABLE_HEADER  *Hdr
  )
{
  UINT32  Crc;

  Hdr->CRC32 = 0;
  gBS->CalculateCrc32 ((UINT8 *) Hdr, Size, &Crc);
  Hdr->CRC32 = Crc;
}


/**
  Checks the CRC32 value in the table header.

  @param  MaxSize   Max Size limit
  @param  Hdr       Table to check

  @return TRUE      CRC Valid
  @return FALSE     CRC Invalid

**/
BOOLEAN
PartitionCheckCrc (
  IN UINTN                 MaxSize,
  IN OUT EFI_TABLE_HEADER  *Hdr
  )
{
  return PartitionCheckCrcAltSize (MaxSize, Hdr->HeaderSize, Hdr);
}


/**
  Checks the CRC32 value in the table header.

  @param  MaxSize   Max Size limit
  @param  Size      The size of the table
  @param  Hdr       Table to check

  @return TRUE    CRC Valid
  @return FALSE   CRC Invalid

**/
BOOLEAN
PartitionCheckCrcAltSize (
  IN UINTN                 MaxSize,
  IN UINTN                 Size,
  IN OUT EFI_TABLE_HEADER  *Hdr
  )
{
  UINT32      Crc;
  UINT32      OrgCrc;
  EFI_STATUS  Status;

  Crc = 0;

  if (Size == 0) {
    //
    // If header size is 0 CRC will pass so return FALSE here
    //
    return FALSE;
  }

  if ((MaxSize != 0) && (Size > MaxSize)) {
    DEBUG ((EFI_D_ERROR, "CheckCrc32: Size > MaxSize\n"));
    return FALSE;
  }
  //
  // clear old crc from header
  //
  OrgCrc      = Hdr->CRC32;
  Hdr->CRC32  = 0;

  Status      = gBS->CalculateCrc32 ((UINT8 *) Hdr, Size, &Crc);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "CheckCrc32: Crc calculation failed\n"));
    return FALSE;
  }
  //
  // set results
  //
  Hdr->CRC32 = Crc;

  //
  // return status
  //
  DEBUG_CODE_BEGIN ();
    if (OrgCrc != Crc) {
      DEBUG ((EFI_D_ERROR, "CheckCrc32: Crc check failed\n"));
    }
  DEBUG_CODE_END ();

  return (BOOLEAN) (OrgCrc == Crc);
}
