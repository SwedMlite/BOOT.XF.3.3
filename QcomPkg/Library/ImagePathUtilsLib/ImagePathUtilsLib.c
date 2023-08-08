/**
  @file ImagePathUtilsLib.c
 
  @brief  Extract image name from given file path functionality
 
  Copyright (c) 2019 by Qualcomm Technologies, Inc.
  All Rights Reserved.
**/
 
/*=======================================================================
                        Edit History

 when       who     what, where, why
 --------   ----    --------------------------------------------------- 
 07/08/19   kpa     Updates for feature support, enable feature via variable
 06/20/19   am      Initial version

========================================================================*/

#include <Library/QcomBaseLib.h>
#include <Library/ImagePathUtilsLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>

#include <Pi/PiFirmwareFile.h>
#include <Pi/PiBootMode.h>
#include <Pi/PiHob.h>

#include <Library/HobLib.h>


STATIC volatile BOOLEAN EnableEbsPerfFlag = FALSE;
extern CHAR8 * GetImageName (IN UINTN FaultAddress, OUT UINTN *ImageBase, OUT UINTN *PeCoffSizeOfHeaders);

extern EFI_GUID gEbsPerfInfoHobGuid;

/**
  Extract File name from input Filepath.

  @param  FilePath           Full path of source file
  @param  ImageName          Start of Image/File Name in the input path

  @retval EFI_SUCCESS         Status if the operation was success else error code.

**/
EFI_STATUS
ImagePathUtilsLibInit (
  VOID
  )
{
  STATIC BOOLEAN InitFlag = FALSE;
  EFI_HOB_GUID_TYPE             *GuidHob;
  VOID **EbsPerfLogDataOffset ;
  BOOLEAN *EbsPerfLogDataPtr;

  if(InitFlag == TRUE)
    return EFI_SUCCESS;
  
  InitFlag = TRUE;
  
  /* Retrieve GUID HOB data that contains the EBS perf log info ptr. */
  GuidHob = GetFirstGuidHob (&gEbsPerfInfoHobGuid);
  if (GuidHob != NULL) 
  {
    EbsPerfLogDataOffset = GET_GUID_HOB_DATA (GuidHob);
    EbsPerfLogDataPtr = (BOOLEAN *)*EbsPerfLogDataOffset;

    if (*EbsPerfLogDataPtr == TRUE)
      EnableEbsPerfFlag = TRUE;
    else
      EnableEbsPerfFlag = FALSE;

  }
  return EFI_SUCCESS;
}

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
  )
{
  CHAR8*    pLastMatch = NULL;
  
  if (FilePath == NULL || ImageName == NULL)
    return EFI_INVALID_PARAMETER;    
 
  *ImageName = NULL;
  pLastMatch = FilePath;
  while (*pLastMatch != '\0')
  {
    if ((*pLastMatch == L'\\' || *pLastMatch == L'/') && ( *(pLastMatch + 1) != '\0'))
      *ImageName = pLastMatch + 1;
    ++pLastMatch;
  }

  return EFI_SUCCESS;
}

/**
  Print CallBack Driver name.

 @param  NotifyFuncAddress         Address to find PE/COFF image name.

**/
VOID
PrintNotifyFnFileName (
  IN  UINTN  NotifyFuncAddress
  )
{
  EFI_STATUS Status;
  CHAR8 *NotifyFnImagePath, *NotifyFnFileName;
  UINTN ImageBase;
  UINTN PeCoffSizeofHeader;

  ImagePathUtilsLibInit();
  
  if (EnableEbsPerfFlag == FALSE)
    return;
  
  NotifyFnImagePath = GetImageName (NotifyFuncAddress, &ImageBase, &PeCoffSizeofHeader);
  if ((NotifyFnImagePath != NULL) && (!RETAIL))
  {
     DEBUG((EFI_D_WARN, " - 0x%x [%5d] ", NotifyFuncAddress, GetTimerCountms ()));
     
     Status = GetImageNameFromPath(NotifyFnImagePath, &NotifyFnFileName);
     if (Status != EFI_SUCCESS)
     { 
       DEBUG((EFI_D_WARN, "\nWarn: Could not extract Filename\n"));
       return;
     }
    
    DEBUG((EFI_D_WARN, "%a\n", NotifyFnFileName));
  }
  
}

/**
  Api to populate ExitBootServices performance logging info.

  The api queries variable "EnableEbsPerfLogs" to check if
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
  )
{
  EFI_HOB_GUID_TYPE             *GuidHob;
  VOID **EbsPerfLogDataOffset ;
  BOOLEAN *EbsPerfLogDataPtr;
  
  EFI_STATUS Status;  
  BOOLEAN   EnableEbsPerfLogsVar = FALSE;
  UINTN     VarSize = sizeof (EnableEbsPerfLogsVar);  

  /* Retrieve GUID HOB data that contains the EBS perf log info ptr. */
  GuidHob = GetFirstGuidHob (&gEbsPerfInfoHobGuid);
  if (GuidHob != NULL) 
  {
    EbsPerfLogDataOffset = GET_GUID_HOB_DATA (GuidHob);
    EbsPerfLogDataPtr = (BOOLEAN *)*EbsPerfLogDataOffset;

    /* Logging disabled by default */
    *EbsPerfLogDataPtr = FALSE;

    /* if the variable EnableEbsPerfLogs exists, do what the variable tells.
       assume variabledxe is loaded already */
    Status = gRT->GetVariable (L"EnableEbsPerfLogs", &gQcomTokenSpaceGuid,
                               NULL, &VarSize, (UINT8*)&EnableEbsPerfLogsVar);
    
    if (Status == EFI_SUCCESS)
    {
      if (EnableEbsPerfLogsVar)
        *EbsPerfLogDataPtr = TRUE;
    }
  }
}

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
)
{
  VOID *DataPtr = NULL;  

  DataPtr =  (VOID *)AllocateZeroPool(sizeof(UINT32));  

  if(DataPtr !=NULL)
  {
    /*Since HOB cannot be updated later in DXE, we pass 
      just the address of allocated buffer
    */
    BuildGuidDataHob (
      &gEbsPerfInfoHobGuid,
      &DataPtr,
      sizeof (VOID *) );

    return EFI_SUCCESS;
  }
  
  return EFI_ABORTED; 
}
