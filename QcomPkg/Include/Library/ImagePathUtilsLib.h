/** @file ImagePathUtils.h
   
  Library routines for Extract image from file path functionality

  Copyright (c) 2019 Qualcomm Technologies, Inc. All rights reserved.
   
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 07/08/19   ka      Initial version

=============================================================================*/
#ifndef __IMAGEPATHUTILSLIB_H__
#define __IMAGEPATHUTILSLIB_H__

#include <Uefi.h>
#include <Library/BaseLib.h>

/**
  Extract File name from input Filepath.

  @param  FilePath           Full path of source file
  @param  ImageName          Start of Image/File Name in the input path

  @retval EFI_SUCCESS         Status if the operation was success else error code.

**/
EFI_STATUS
GetImageNameFromPath (
  IN  CHAR8 *FilePath,
  OUT CHAR8 **ImageName
  );

/**
  Print CallBack Driver name.

 @param  NotifyFuncAddress         Address to find PE/COFF image name.

**/
VOID
PrintNotifyFnFileName (
  IN  UINTN  NotifyFuncAddress
  );
  
/**
  Api to populate ExitBootServices performance logging info.

  The api queries variable "ForceEnableEbsPerfLogs" to check if
  logging is enabled. The flag value is accordingly updated in 
  buffer pointed to by HOB.
    
  @param  None

  @retval EFI_SUCCESS         Success if the operation was success
                              else error code.

**/
VOID
EFIAPI
UpdateEbsPerfLogFlag (
  VOID
  );
  
/**
  Create hob for ExitBootServices performance data.

  Note: A HOB needs to be created in SEC to pass on the address of
    buffer that shall be used to hold the Flag value to enable/disable
    Ebs (ExitBootServices) performance logging. The Flag value is read
    from storage variable in platformBdsLib and populated to a buffer.
    It is later consumed by Dxe core via getting the buffer address through
    HOB. A HOB needed to be used for lack of other better option.
    
  @param  None

  @retval EFI_SUCCESS         Success if the operation was success
                              else error code.

**/
EFI_STATUS 
EbsPerfInfoHobInit ( 
  VOID 
);
  
#endif /* __IMAGEPATHUTILSLIB_H__ */
