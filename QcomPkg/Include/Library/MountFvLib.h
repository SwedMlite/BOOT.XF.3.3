/** @file MountFvLib.h

  FvUtils lib to parse FV in memory and mount
   
  Copyright (c) 2017-2019, Qualcomm Technologies, Inc. All rights reserved. 
  Qualcomm Technologies Proprietary and Confidential.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/28/19   yg      Modified interface
 03/21/19   md      Add API's to support recursive FV loading and Desired FV 
                    from Partion/Buffer
 08/20/18   yw      add MountFvPartition() GUID support
 09/08/17   kpa     Initial Revision

=============================================================================*/

#include <Uefi.h>

#include <Library/BaseLib.h>

#ifndef __MOUNTFV_LIB_H__
#define __MOUNTFV_LIB_H__

/*=============================================================================
  
             In memory FV parsing and mounting routines
  
 =============================================================================*/

/******************************************************************************
 *
 *    Auxilliary functions to get fine control over traversing with
 *    in memory FV. If the need is not complex, use the simpler routine
 *    ProcessAndMountFvImageFile instead of these.
 *
 ******************************************************************************/

#define FFS_FILE_ATTRIBUTE_COMPRESSED    (1 << 30)

#define MAX_FFS_FILE_SIZE_CHARS           32

/* If not multiple contexts are opened at the same time, this defines
 * how many levels deep does the lib recurse into */
#define MAX_FV_CONTEXTS                   4

typedef struct __FfsFileInfo
{
  EFI_GUID     FileNameGuid;
  UINT32       FileSize;
  UINT32       FileType;
  CHAR8        UIFileName[MAX_FFS_FILE_SIZE_CHARS];
  CONST VOID*  ROFileDataPtr;
  CONST VOID*  SectionPtr;
  UINT32       Attributes;
}FfsFileInfo;

struct __FVContext;
typedef struct __FVContext FVContext;

/*
 *  Open the FV Buffer context. If the FV is valid, FvSizePtr can return
 *  the actual size of the FV contained
 * */
FVContext* 
OpenFVFile (IN  VOID       *FVBuffer, 
            IN  UINTN       BufferSize, 
            OUT UINTN      *FvSizePtr OPTIONAL);

/*
 * Close the FV context
 * */
VOID 
CloseFVFile (IN FVContext* Ctxt);

/*
 * Get Next file in the FV (First file if calling for the first time).
 * */
FfsFileInfo*
GetNextFileFromFV (IN     FVContext          *Ctxt, 
                   IN OUT FfsFileInfo        *FileInfoPtr, 
                   IN     UINT8               FilterFileType OPTIONAL);

/*
 *  Decode or decompress the image if the attributes returns with
 *  FFS_FILE_ATTRIBUTE_COMPRESSED Memory will be allocated internally
 *  using AllocatePages
 * */
EFI_STATUS
PerformGuidedSectionDecode (IN  FfsFileInfo      *FfsFileInfoPtr,
                            OUT VOID            **OutputBuffer,
                            OUT UINTN            *OutSizePtr);

/*
 * Mount the FV that's in the buffer. The buffer cannot be released once mount happens.
 * */
EFI_STATUS
MountFVFromBuffer (IN EFI_PHYSICAL_ADDRESS   BaseAddress,
                   IN UINT64                 Length,
                   IN EFI_HANDLE             ParentHandle,
                   IN UINT32                 AuthenticationStatus);

/******************************************************************************
 *
 * Recommended routine to use in this interface, unless a very fine grained
 * control is required.
 *
 ******************************************************************************/
/*
 *  Process the FV ImageFile in memory recursively and mount all of them. To avoid
 *  Installing empty container FV's, only the compressed FV's are mounted. To mount
 *  the uncompressed use above descreet API's to achieve the same.
 *  If the MountFvFileGuid is not NULL, then only the Specified FV with the file Guid
 *  will be mounted (again only if its compressed).
 * */
EFI_STATUS
ProcessAndMountFvImageFile (IN   VOID            *Buffer,
                            OUT  UINTN            BufferSize,
                            IN   EFI_GUID        *MountFvFileGuid OPTIONAL);


/*=============================================================================
  
             FV mounting managing utility routines
  
 =============================================================================*/
/**
  This function mounts  FV (firmware volume) from Buffer.
  If needed it is decompressed and then mounted recursively

  @param[in]  ReadBuffer         Buffer where FV is loaded
  @param[in]  BufferSize         Buffer size
  @param[in]  MountFVFileGUID    Optional FVFile Guid (FFS Name) to mount
  
  @retval  EFI_SUCCESS           The Firmware volume is found and successfully mounted.
  @retval  EFI_NOT_FOUND         Firmware volume not found.
  @ret_val EFI_INVALID_PARAMETER Input parameter missing. 
**/
EFI_STATUS
AuthAndMountFVFromBuffer(IN  VOID          *ReadBuffer,
                         IN  UINTN          BufferSize,
                         IN  EFI_GUID      *MountFVFileGUID  OPTIONAL);


/**
  This function mounts  FV (firmware volume) from data read from a partition specified
  either by its type GUID or label.
  If needed it is decompressed and then mounted recursively.

  @param[in]  PartitionGuid       Partition Type Guid
  @param[in]  FvPartitionName     Partition label
  @param[in]  MountFVFileGUID     Optional FVFile Guid (FFS Name) to mount
  
  @retval  EFI_SUCCESS            The Firmware volume is found and successfully mounted.
  @retval  EFI_NOT_FOUND          Firmware volume not found.
  @ret_val EFI_INVALID_PARAMETER  Input parameter missing. 
**/
EFI_STATUS
AuthAndMountFvFromPartition (IN  EFI_GUID          *PartitionGuid,
                             IN  CONST CHAR8       *FvPartitionName,
                             IN  EFI_GUID          *MountFVFileGUID  OPTIONAL);

/**
  This function mounts a desired FV (firmware volume) passed as an argument from Buffer.
  The buffer might contain recursive FV as well which in that case the buffer will have Filesystem 
  data loaded. If needed it is decompresses and then mounted.

  @param[in]  Buffer              Buffer where FV is loaded
  @param[in]  BufferSize          Buffer size
  @param[in]  DesiredFvGuid       GUID of desired FV to be mounted
  @param[in]  DesiredFVFileGUID   Optional FVFile Guid (FFS Name) to mount if recursive (stops further recursion on finding this file)
  
  @retval  EFI_SUCCESS            The Firmware volume is found and successfully mounted.
  @retval  EFI_NOT_FOUND          Firmware volume not found.
  @ret_val EFI_INVALID_PARAMETER  Input parameter missing. 
**/
EFI_STATUS
MountDesiredFVFromBuffer(IN VOID     *Buffer, 
                         IN UINTN     BufferSize,
                         IN EFI_GUID *DesiredFvGuid,
                         IN EFI_GUID *DesiredFVFileGUID);

/**
  This function mounts a desired FV (firmware volume) passed as an argument from Partition.
  The Partition might contain recursive FV as well which in that case the buffer will have Filesystem 
  data loaded. If needed it is decompresses and then mounted.

  @param[in]  FvPartitionName     String name of the FV to be mounted
  @param[in]  PartitionGuid       Partition GUID of the FV to be mounted
  @param[in]  DesiredFvGuid       GUID of desired FV to be mounted
  @param[in]  DesiredFVFileGUID   Optional FVFile Guid (FFS Name) to mount if recursive (stops further recursion on finding this file)

  @retval  EFI_SUCCESS           The Firmware volume is found and successfully mounted.
  @ret_val EFI_INVALID_PARAMETER Input parameter missing. 
**/
EFI_STATUS
MountDesiredFVFromPartition(IN  CONST CHAR8   *FvPartitionName, 
                            IN  EFI_GUID      *PartitionGuid, 
                            IN  EFI_GUID      *DesiredFvGuid,
                            IN  EFI_GUID      *DesiredFVFileGUID);

#endif /* __MOUNTFV_LIB_H__ */

