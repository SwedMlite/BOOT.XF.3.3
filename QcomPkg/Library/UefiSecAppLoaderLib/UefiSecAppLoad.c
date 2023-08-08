/******************************************************************//**
 * @file UefiSecAppLoad.c
 *
 * @brief UefiSecAppLoaderLib functions
 *
 * Copyright (c) 2018 by Qualcomm Technologies, Inc. 
 * All Rights Reserved.
 *
 *********************************************************************/
/*=======================================================================
                        Edit History

when       who     what, where, why
--------   ----    --------------------------------------------------- 
03/08/18   ai      Load UefiSecApp TA from raw partition 
========================================================================*/

#include <Library/UefiSecAppLoaderLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/EFIQseecom.h>

#define UEFISECAPP_PARTITION_GUID \
    { 0xBE8A7E08, 0x1B7A, 0x4CAE, { 0x99, 0x3A, 0xD5, 0xB7, 0xFB, 0x55, 0xB3, 0xC2 } }

/**
 * Load UefiSecApp TA 
 */
EFI_STATUS LoadUefiSecApp (VOID)
{
  EFI_STATUS              Status      = EFI_SUCCESS;
  QCOM_QSEECOM_PROTOCOL   *Qseecom    = NULL; 
  EFI_GUID                UefiSecAppPartitionGuid = UEFISECAPP_PARTITION_GUID;
  UINT32                  HandleId    = 0;
 
  /* Get handle to TzeLoaderProtocol */ 
  Status = gBS->LocateProtocol(&gQcomQseecomProtocolGuid, NULL, (VOID **)&Qseecom); 
  if(EFI_ERROR(Status)) 
  { 
    DEBUG ((EFI_D_ERROR, "Unable to locate QseeCom protocol: %r\n", Status));  
    return Status; 
  } 

  Status = Qseecom->QseecomStartAppByGuid(Qseecom, &UefiSecAppPartitionGuid, &HandleId); 
  if (EFI_ERROR(Status)) 
  { 
    DEBUG ((EFI_D_ERROR, "LoadImageFromPartition(UefiSecApp) : 0x%r\n", Status)); 
    return Status;
  } 
  
  return Status; 
}

