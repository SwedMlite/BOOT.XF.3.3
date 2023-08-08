/** @file FwESRT.c

   Functions to maintain the ESRT , including ESRT header and ESRT entry .

  Copyright (c) 2012-2018 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

**/
/*=============================================================================
                              EDIT HISTORY
  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.



 when           who         what, where, why
 --------       ---         -----------------------------------------------
 2018/07/20     gparam      KW Fixes
 2018/05/31     prema       Change to use different format to print GUID
 2018/05/28     prema       FAT to NV migration for ESRT data storage
 2018/05/25     prema       Updated System Firmware Resource GUIDs for 8180 
 2018/04/23     prema       Handled to update ESRT info when DPP is inaccessible
                            and DPP corruption, and not to bail out.
 2018/02/15     prema       Using ChipInfo protocol to get PlatformInfo
                            instead of harcoded chip information
 2018/02/13     prema       Added check to handle 850 chipset in CapsuleUpdate
 2018/01/31     prema       Updated System Firmware Resource GUIDs for 845
 2017/07/13     gpavithr    Changes to silent error logs when DPP media is not available
 2017/07/07     hhovale     Change to not skip SystemFmpCapsuleImageTypeIdGuid update 
                            when DPP not found.
 2017/06/01     gparam      Change to initialize cached ESRT data every time when
                            a system firmware update is attempted.
 2017/05/12     gparam      Removed the use of dynamic PCD and used boot-time variable instead
 2017/05/08     gparam      Changes to centralize ESRT update to DPP to the end of
                            SetImage API
 2017/04/18     gparam      Changes to centralize the recording of update status
                            in DPP for future use
 2017/04/18     gparam      Changed the update status from internal type to
                            standard ones defined in EDK headers + Removed
                            unused/redundant definitions/parameters
 2017/04/18     gparam      Change to update PCD containing SystemFirmware GUID list
                            with the currently active SystemFirmware GUID read from DPP
 2017/03/15     gparam      Corrected the ESRT read from DPP to honor the ESRT
                            provision backup file which will be present if device
                            resets/reboots between update of ESRT GUID.
 2017/02/27     pkn         Added changes required to support new update type - FWCLASS_GUID
 2017/02/24     gparam      Changes to correct the prefilled known SystemFirmware
                            GUIDs for the default Qualcomm form-factors
 2017/02/22     gparam      Added the default 8998 specific system firmware GUIDs and
                            removed 8996 GUID
 2017/02/13     gpavithr    Changes to use ESRTDxe inplace of local functions
                            to directly create and/or operate on ESRT table
 2017/02/01     pkn         Move ESRT system firmware GUID provisioned in DPP to a separate DPP file
 2016/08/29     ltg         Replace EFI_PLATFORMINFO_TYPE_MTP_MSM with EFI_PLATFORMINFO_TYPE_MTP
 2/15/04/16     mic         Use updated DppProtocol
 2015/03/31     mic         Added 8994 platform types
 2013/06/11     rsb         Added 8074 platform types
 2013/04/11     rsb         Added 8084 platform types
 2012/12/11     mic         Fixed KW warnings
 2012/11/30     mic         Added ESRT entry print function
 2012/11/09     jmb         Adding CBH platform
 2012/10/21     mic         Code review
 2012/10/03     ash         Fixed version matching for 8064 platforms.
 2012/09/19     rsb         Added 8974 platform types
 2012/08/14     ash         Added 8064 WB292 and V1 variants.
 2012/06/21     rs          Adding support for FPDT ACPI table
 2012/06/21     mic         Set the default ESRT FW ver/lowest support version/last attempt version to 0
 2012/06/05     rs          Enhanced lowest supported version check
 2012/05/09     rsb         Platform run-time type detection for FW Resource GUID
 2012/05/07     jd          Migrated to DPP Protocol.
 2012/02/01     mic         Initial version

=============================================================================*/
#include <Uefi.h>
#include <Protocol/EsrtManagement.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BootConfig.h>

#include <Include/Library/FwCommonLib.h>
#include <Include/Library/QcomLib.h>

#include <Pi/PiDxeCis.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/BlockIo.h>
#include <Protocol/FirmwareVolume2.h>
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFIDpp.h>

#include <Guid/GlobalVariable.h>

#include "FwEsrt.h"
#include "FwCapsule.h"
#include "FwPayloadEntry.h"

#define DEFAULT_ESRT_CAPSULE_FLAGS            (CAPSULE_FLAGS_PERSIST_ACROSS_RESET | CAPSULE_FLAGS_INITIATE_RESET)
#define ESRT_FWENTRY_PROVISIONING_FILE_NAME   L"ESRT_SYS_FWEntry.PROVISION"

#define ESRT_FWENTRY_PROVISIONING_NV_NAME     L"ESRT_SYS_FWEntry"

#define ESRT_PROVISIONING_DATA_TYPE           L"QCOM"

/*global variable*/
UINT16                  *esrtfwentryfilename  = ESRT_FWENTRY_PROVISIONING_FILE_NAME;

UINT16                  *esrtfwentryNVname    = ESRT_FWENTRY_PROVISIONING_NV_NAME;

UINT16                  *ProvisiondataType    = ESRT_PROVISIONING_DATA_TYPE;

const EFI_SYSTEM_RESOURCE_ENTRY DefaultEsrtEntry = {
  QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_GUID,
  FW_TYPE_SYSTEM,
  0x0,
  0x0,
  DEFAULT_ESRT_CAPSULE_FLAGS,
  0x0,
  LAST_ATTEMPT_STATUS_SUCCESS
};
EFI_SYSTEM_RESOURCE_ENTRY esrt_ent = {
  QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_GUID,
  FW_TYPE_SYSTEM,
  0x0,
  0x0,
  DEFAULT_ESRT_CAPSULE_FLAGS,
  0x0,
  LAST_ATTEMPT_STATUS_SUCCESS
};
EFI_GUID                  ESRT_guid = QCOM_FW_UPDATE_ESRT_GUID;

/* The list of System Firmware Resource GUIDs that apply for each type of platform, the order must
   match the QCOM_FW_RESOURCE_TYPE. */
const EFI_GUID qcomFwResourceGUIDs_UFS[] =
{
    QCOM_FW_UPDATE_SYSTEM_FW_8180_MTP_UFS_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_8180_CLS_UFS_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_8180_QRD_UFS_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_GUID
};

const EFI_GUID qcomFwResourceGUIDs_SPINOR[] =
{
    QCOM_FW_UPDATE_SYSTEM_FW_8180_MTP_SPINOR_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_8180_CLS_SPINOR_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_8180_QRD_SPINOR_GUID,
    QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_GUID
};
EFI_GUID  *qcomFwResourceGUIDs = NULL;

/**
  Return if this FMP is a system FMP or a device FMP, based upon FmpImageInfo.

  @param[in] FmpImageInfo A pointer to EFI_FIRMWARE_IMAGE_DESCRIPTOR

  @return TRUE  It is a system FMP.
  @return FALSE It is a device FMP.
**/
EFI_STATUS 
UpdateVarSystemFmpCapsuleImageTypeIdGuid (
  IN EFI_GUID  SystemFwGuid
  )
{
  EFI_STATUS Status         = EFI_SUCCESS;
  GUID      *Guid           = NULL;
  UINTN      Count          = 0;
  UINTN      Index          = 0;
  GUID      *NewGuidList    = NULL;
  UINTN      NewGuidListSize = sizeof(GUID);
  VOID      *GuidBuffer     = NULL;
  UINTN      GuidBufferSize = 0;

  Status = GetEfiGlobalVariable2 (
             L"SystemFmpCapsuleImageTypeIdGuid",
             &GuidBuffer,
             &GuidBufferSize
             );
  if (!EFI_ERROR(Status) &&
      (GuidBuffer != NULL)) {

    Guid = (GUID *)GuidBuffer;
    Count = GuidBufferSize/sizeof(GUID);

    for (Index = 0; Index < Count; Index++) {
      if (CompareGuid(&SystemFwGuid, (Guid + Index))) {
        return EFI_SUCCESS;
      }
    }
  } else {
    Status = EFI_SUCCESS;
  }

  NewGuidListSize = (Count + 1) * sizeof(GUID);
  NewGuidList = AllocateZeroPool(NewGuidListSize);
  if (NewGuidList == NULL) {
    DEBUG ((EFI_D_ERROR, "FmpDxe: Allocating new SystemFmpCapsuleImageTypeIdGuid failed\n"));
    return EFI_OUT_OF_RESOURCES;
  }

  CopyMem(
    NewGuidList,
    Guid,
    (Count * (sizeof(GUID)))
    );
  CopyMem(
    (NewGuidList + Count),
    &SystemFwGuid,
    sizeof(GUID)
    );

  //
  // Update New Repository
  //
  Status = gRT->SetVariable(
    L"SystemFmpCapsuleImageTypeIdGuid",
    &gEfiGlobalVariableGuid,
    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
    NewGuidListSize,
    NewGuidList
    );

  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_ERROR, "FmpDxe: Setting of new GUID list in SystemFmpCapsuleImageTypeIdGuid failed with error %r\n", Status));
    return Status;
  }

  return EFI_SUCCESS;
}

/**
 * Function to print ESRT entry
 *
 * @param ent  - ESRT entry
 * @DebugLevel - Debug level
 *
 * @return : EFI_STATUS
 */
EFI_STATUS
QcomPrintEsrtEntry(
  IN EFI_SYSTEM_RESOURCE_ENTRY  *ent,
  IN UINTN                      DebugLevel
  )
{

  DEBUG((DebugLevel,"    Esrt info:\n"));
  DEBUG((DebugLevel,"    ====================================\n"));

  DEBUG((DebugLevel,"    GUID                     : "));
  FwCommonPrintGuid(ent->FwClass,DebugLevel,FALSE);
  DEBUG((DebugLevel,"\n"));

  DEBUG((DebugLevel,"    FwType                   : 0x%x\n", ent->FwType));
  DEBUG((DebugLevel,"    FwVersion                : 0x%x\n", ent->FwVersion));
  DEBUG((DebugLevel,"    Lowest supported version : 0x%x\n", ent->LowestSupportedFwVersion));
  DEBUG((DebugLevel,"    Capsuleflag              : 0x%x\n", ent->CapsuleFlags));
  DEBUG((DebugLevel,"    Last attempt ver         : 0x%x\n", ent->LastAttemptVersion));
  DEBUG((DebugLevel,"    Last attempt status      : 0x%x\n", ent->LastAttemptStatus));

  DEBUG((DebugLevel,"    ====================================\n"));

  return EFI_SUCCESS;
}

/**
* Get the ESRT entry info
*
* @param  ent         - Copy of current ESRT entry
* @return EFI_STATUS
**/
EFI_STATUS
QcomGetEsrtEntryCache(
  OUT EFI_SYSTEM_RESOURCE_ENTRY  *ent
  )
{
  if(ent == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  CopyMem ((VOID *)ent, (VOID*)&esrt_ent, sizeof (esrt_ent));

  return EFI_SUCCESS;
}

/**
 *  Check if ESRT header is installed in UEFI System table
 *
 * @param SystemTable -UEFI system table
 *
 * @return BOOLEAN
 */
BOOLEAN
QcomIsEsrtHeaderInstalledInSysTbl(
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_CONFIGURATION_TABLE *pcfg_table = NULL;
  UINTN                    cs_cnt     = 0;
  UINTN                    i          = 0;

  if (SystemTable == NULL)
  {
    return FALSE;
  }

  cs_cnt =SystemTable->NumberOfTableEntries;
  pcfg_table=SystemTable->ConfigurationTable;

  for ( i = 0; i < cs_cnt; i++)
  {
    if(CompareGuid((GUID*)&ESRT_guid,(GUID*)&pcfg_table->VendorGuid))
    {
      return TRUE;
    }
    pcfg_table++;
  }

    return FALSE;
}

/**
 * Read ESRT entry info from storage
 *
 * @param buf       - out buffer
 * @param esrtSize  - out buffer size
 *
 * @return EFI_STATUS
 */
EFI_STATUS
QcomRead_EsrtEntryFromStorage(
  IN OUT EFI_SYSTEM_RESOURCE_ENTRY  **buf,
  IN OUT UINTN                      *esrtSize
  )
{
  UINTN                      esrtFwClassSize        = sizeof (EFI_GUID);
  UINTN                      esrtFwEntrySize        = 0;
  EFI_STATUS                 Status                 = EFI_SUCCESS;
  EFI_DPP_PROTOCOL          *DppProtocol            = NULL;

  if((buf == NULL) ||
     (esrtSize == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *buf = NULL;
  Status = gBS->LocateProtocol(&gEfiDppProtocolGuid,
                               NULL,
                               (VOID**)&DppProtocol);
  if(EFI_ERROR(Status))
  {
    DEBUG((EFI_D_ERROR,"LocateProtocol(DPP) returned : %r. Returning alternative error %r\n", Status, EFI_NO_MEDIA));
    Status = EFI_NO_MEDIA;
    goto QcomRead_EsrtEntryFromStorageExit;
  }

  Status = DppProtocol->GetDPP(DppProtocol,ProvisiondataType,esrtfwentryfilename,NULL,&esrtFwEntrySize);
  HANDLE_ERROR_LABEL(Status,DppProtocol->GetDPP,QcomRead_EsrtEntryFromStorageExit);

  if((esrtFwClassSize + esrtFwEntrySize) != sizeof(EFI_SYSTEM_RESOURCE_ENTRY))
  {
    Status = EFI_BAD_BUFFER_SIZE;
    DEBUG((EFI_D_ERROR,"Incorrect provision file size (%d + %d)!. Expected: %d\n", esrtFwClassSize, esrtFwEntrySize, sizeof(EFI_SYSTEM_RESOURCE_ENTRY)));
    goto QcomRead_EsrtEntryFromStorageExit;
  }

  *esrtSize = esrtFwClassSize + esrtFwEntrySize;

  Status = gBS->AllocatePool(EfiBootServicesData,*esrtSize,(VOID **)buf);
  HANDLE_ERROR_LABEL(Status,AllocatePool (EfiBootServicesData),QcomRead_EsrtEntryFromStorageExit);

  /* Get the Firmware Resource GUID for the curent platform. */
  Status = QcomGetFwGuidForPlatform(&((*buf)->FwClass));
  if (Status != EFI_SUCCESS)
  {
    DEBUG((EFI_D_ERROR,"Failed to find FW GUID for current device: %r. Using default GUID.\n", Status));
    CopyGuid(&((*buf)->FwClass), &DefaultEsrtEntry.FwClass);
    Status = EFI_SUCCESS;
  }

  Status = DppProtocol->GetDPP(DppProtocol,ProvisiondataType,esrtfwentryfilename,((char *)*buf + esrtFwClassSize),&esrtFwEntrySize);
  HANDLE_ERROR_LABEL(Status,GetDPP (Fw Entry File),QcomRead_EsrtEntryFromStorageExit);

  return EFI_SUCCESS;

QcomRead_EsrtEntryFromStorageExit:

  if(*buf != NULL)
  {
    gBS->FreePool(*buf);
    *buf = NULL;
  }
  return Status;
}

/**
 * Delete ESRT entry info from storage.
 *
 * @return EFI_STATUS
 */
EFI_STATUS
QcomDelete_EsrtEntryFromStorage(
  VOID
  )
{
  EFI_STATUS                 Status                 = EFI_SUCCESS;
  EFI_DPP_PROTOCOL          *DppProtocol            = NULL;

  Status = gBS->LocateProtocol(&gEfiDppProtocolGuid,
                               NULL,
                               (VOID**)&DppProtocol);
  if(EFI_ERROR(Status))
  {
    DEBUG((EFI_D_ERROR,"LocateProtocol(DPP) returned : %r. Returning alternative error %r\n", Status, EFI_NO_MEDIA));
    Status = EFI_NO_MEDIA;
    goto QcomDelete_EsrtEntryFromStorageExit;
  }

  Status = DppProtocol->DeleteItemDPP(DppProtocol,ProvisiondataType,esrtfwentryfilename);
  HANDLE_ERROR_LABEL(Status,DppProtocol->DeleteItemDPP,QcomDelete_EsrtEntryFromStorageExit);

QcomDelete_EsrtEntryFromStorageExit:

  return Status;
}


/**
 * Read ESRT entry info from NV
 *
 * @param buf       - out buffer
 * @param esrtSize  - out buffer size
 *
 * @return EFI_STATUS
 */
EFI_STATUS
QcomRead_EsrtEntryFromNV(
  IN OUT EFI_SYSTEM_RESOURCE_ENTRY  **buf,
  IN OUT UINTN                      *esrtSize
  )
{
  UINTN                      esrtFwClassSize        = sizeof (EFI_GUID);
  UINTN                      esrtFwEntrySize        = 0;
  EFI_STATUS                 Status                 = EFI_SUCCESS;
  VOID                      *fwEntryBuffer          = NULL;

  if((buf == NULL) ||
     (esrtSize == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = GetVariable2(esrtfwentryNVname,&gQcomTokenSpaceGuid, &fwEntryBuffer, &esrtFwEntrySize);
  HANDLE_ERROR_LABEL(Status,GetVariable2,QcomRead_EsrtEntryFromNVExit);

  if (NULL == fwEntryBuffer)
  {
      Status = EFI_LOAD_ERROR;
      DEBUG((EFI_D_ERROR,"GetVariable2 returned invalid output buffer\n"));
      goto QcomRead_EsrtEntryFromNVExit;
  }

  if((esrtFwClassSize + esrtFwEntrySize) != sizeof(EFI_SYSTEM_RESOURCE_ENTRY))
  {
    Status = EFI_BAD_BUFFER_SIZE;
    DEBUG((EFI_D_ERROR,"Incorrect provision NV size (%d + %d)!. Expected: %d\n", esrtFwClassSize, esrtFwEntrySize, sizeof(EFI_SYSTEM_RESOURCE_ENTRY)));
    goto QcomRead_EsrtEntryFromNVExit;
  }

  *esrtSize = esrtFwClassSize + esrtFwEntrySize;

  Status = gBS->AllocatePool(EfiBootServicesData,*esrtSize,(VOID **)buf);
  HANDLE_ERROR_LABEL(Status,AllocatePool (EfiBootServicesData),QcomRead_EsrtEntryFromNVExit);

  /* Get the Firmware Resource GUID for the curent platform. */
  Status = QcomGetFwGuidForPlatform(&((*buf)->FwClass));
  if (Status != EFI_SUCCESS)
  {
    DEBUG((EFI_D_ERROR,"Failed to find FW GUID for current device: %r. Using default GUID.\n", Status));
    CopyGuid(&((*buf)->FwClass), &DefaultEsrtEntry.FwClass);
    Status = EFI_SUCCESS;
  }

  CopyMem(((char *)*buf + esrtFwClassSize), fwEntryBuffer, esrtFwEntrySize);

  gBS->FreePool(fwEntryBuffer);
  fwEntryBuffer = NULL;

  return EFI_SUCCESS;

QcomRead_EsrtEntryFromNVExit:

  if (fwEntryBuffer != NULL)
  {
    gBS->FreePool(fwEntryBuffer);
    fwEntryBuffer = NULL;
  }

  if(*buf != NULL)
  {
    gBS->FreePool(*buf);
    *buf = NULL;
  }
  return Status;
}

/**
 * Write ESRT entry info into storage.
 *
 * @param inBuf           - buffer
 *
 * @return EFI_STATUS
 */
EFI_STATUS
QcomWrite_EsrtEntryToNV(
  IN EFI_SYSTEM_RESOURCE_ENTRY  *inBuf
  )
{
  UINTN              esrtFwEntrySize          = (sizeof (EFI_SYSTEM_RESOURCE_ENTRY) - sizeof (EFI_GUID));
  EFI_STATUS         Status                   = EFI_SUCCESS;
  static BOOLEAN     skipVariableFlush        = FALSE;

  if(inBuf == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  Status = gRT->SetVariable(
    esrtfwentryNVname,
    &gQcomTokenSpaceGuid,
    EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS,
    esrtFwEntrySize,
    ((char *)inBuf + sizeof(EFI_GUID))
    );
  HANDLE_ERROR_LABEL(Status,gRT->SetVariable,QcomWrite_EsrtEntryToNVExit);

  if (skipVariableFlush == FALSE)
  {
    /* On successful write to variable services, trigger a flush
       to ensure it is written to disk without requring a reset. */
    Status = FlushVariableServices();
  
    if (EFI_NOT_FOUND == Status)
    {
      /* Skip further attempts to flush assuming that flush
         operation is either not supported or not ready during
         early stage of development */
      skipVariableFlush = TRUE;
      DEBUG((EFI_D_WARN,"FlushVariableServices returned %r. Will skip future calls to FlushVariableServices\n", Status));
    }
    else if (EFI_ERROR(Status))
    {
      HANDLE_ERR_CONTINUE (Status,FlushVariableServices);
    }
    Status = EFI_SUCCESS; // Clear error if any was returned by FlushVariableServices
  }

QcomWrite_EsrtEntryToNVExit:

  return Status;
}

/**
 * This Function try to update ESRT in both DPP and system table
 *
 * @param  ent            - Copy of new ESRT entry to update in cache and DPP
 *
 * @return EFI_STATUS
 */

EFI_STATUS
QcomUpdateEsrtEntry(
  IN EFI_SYSTEM_RESOURCE_ENTRY  *ent
  )
{

  EFI_STATUS Status   = EFI_SUCCESS;
  UINTN      esrtSize = 0;

  /* Do not update the current version in ESRT cache to the new version
     as it needs a reboot to really take effect. Till then, any query to
     cache should return the current version as the version of the
     firmware which processed the current update */
  esrt_ent.LastAttemptVersion = ent->LastAttemptVersion;
  esrt_ent.LowestSupportedFwVersion = ent->LowestSupportedFwVersion;
  esrt_ent.LastAttemptStatus  = ent->LastAttemptStatus;

  DEBUG((EFI_D_INFO,"  Updated cached ESRT:\n"));
  QcomPrintEsrtEntry(&esrt_ent,EFI_D_WARN);

  /*update ESRT in DPP*/
  esrtSize = sizeof(EFI_SYSTEM_RESOURCE_ENTRY);
  DEBUG((EFI_D_WARN,"  Writing System ESRT Entry to persistent storage...\n"));
  Status = QcomWrite_EsrtEntryToNV(ent);
  if(EFI_ERROR(Status))
  {
    DEBUG((EFI_D_WARN,"QcomWrite_EsrtEntryToNV failed with error: %r. Ignoring and proceeding...\n", Status));
    Status = EFI_SUCCESS;
  }

  return Status;
}

/**
 *  Find if the given Firmware Resource GUID matches a known type
 *  used for Qualcomm platforms.
 *
 * @param FwResourceGuid - Pointer to GUID to match against known platform types
 * @param bFound         - Pointer to output boolean set to TRUE if a match is found,
 *                         or FALSE otherwise.
 *
 * @return EFI_STATUS
 */

EFI_STATUS
IsFwGuidKnownType(
  IN EFI_GUID *FwResourceGuid,
  OUT BOOLEAN *bFound
  )
{
   EFI_STATUS Status      = EFI_SUCCESS;
   UINTN      i           = 0;
   EFI_GUID   unknownGUID = QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_GUID;

   if ((FwResourceGuid == NULL) || (bFound == NULL))
   {
      return EFI_INVALID_PARAMETER;
   }

   *bFound = FALSE;

   for (i = 0; CompareGuid(&qcomFwResourceGUIDs[i], &unknownGUID); i++)
   {
      if (CompareGuid(FwResourceGuid, &qcomFwResourceGUIDs[i]) == TRUE)
      {
         *bFound = TRUE;
         break;
      }
   }

   return Status;
}

/**
 *  Find the Firmware Resource GUID for the device platform.
 *
 * @param FwResourceGuid - Pointer to GUID that is modified to correspond to the current
 *                         platform type.
 *
 * @return EFI_STATUS
 */

EFI_STATUS
QcomGetFwGuidForPlatform(
  OUT EFI_GUID *FwResourceGuid
  )
{
  EFI_STATUS                           Status                = EFI_SUCCESS;
  EFI_CHIPINFO_PROTOCOL               *mChipInfoProtocol     = NULL;
  EFI_PLATFORMINFO_PROTOCOL           *pPlatformInfoProtocol = NULL;
  EFI_PLATFORMINFO_PLATFORM_INFO_TYPE  platformInfo;
  EFIChipInfoIdType                    eId                   = EFICHIPINFO_ID_UNKNOWN;
  EFIChipInfoVersionType               nChipVersion          = 0;

  if (FwResourceGuid == NULL)
  {
     return EFI_INVALID_PARAMETER;
  }

  DEBUG((EFI_D_WARN,"Retrieving FW GUID for the current platform\n"));

  Status = gBS->LocateProtocol (&gEfiChipInfoProtocolGuid,
                                NULL,
                                (VOID **) &mChipInfoProtocol
                               );
  if(EFI_ERROR(Status))
  {
    DEBUG((EFI_D_ERROR,"LocateProtocol(CHIPINFO_PROTOCOL) returned Status:%r\n", Status));
    goto QcomGetFwGuidForPlatformExit;
  }

  Status = mChipInfoProtocol->GetChipId( mChipInfoProtocol,
                                                     &eId);
  HANDLE_ERROR_LABEL(Status,mChipInfoProtocol->GetChipId,QcomGetFwGuidForPlatformExit);

  Status = mChipInfoProtocol->GetChipVersion( mChipInfoProtocol,
                                                 &nChipVersion);
  HANDLE_ERROR_LABEL(Status,mChipInfoProtocol->GetChipVersion,QcomGetFwGuidForPlatformExit);

  // Get the platform info protocol.  It is used to map rows and scan columns to
  // specific keys which can vary per platform.
  Status = gBS->LocateProtocol ( &gEfiPlatformInfoProtocolGuid,
                                 NULL,
                                 (VOID **)&pPlatformInfoProtocol
                                );
  if(EFI_ERROR(Status))
  {
    DEBUG((EFI_D_ERROR,"LocateProtocol(PLATFORMINFO_PROTOCOL) returned Status:%r\n", Status));
    goto QcomGetFwGuidForPlatformExit;
  }

  ZeroMem(&platformInfo, sizeof(platformInfo));

  Status = pPlatformInfoProtocol->GetPlatformInfo( pPlatformInfoProtocol,
                                                  &platformInfo);
  HANDLE_ERROR_LABEL(Status,pPlatformInfoProtocol->GetPlatformInfo,QcomGetFwGuidForPlatformExit);

  if ((EFICHIPINFO_ID_SDM1000 == eId) ||
      (EFICHIPINFO_ID_SCX8180 == eId))
  {
	EFI_STATUS         Status;
	CHAR8              DestBuffer[128];
	CHAR8*             PlatTypePtr;
	CHAR8*             ChipNamePtr;
	CHAR8*             ChipVerPtr;
  
	Status = GetPlatformStrings (DestBuffer, sizeof(DestBuffer),
                               &PlatTypePtr, &ChipNamePtr, &ChipVerPtr);

    DEBUG((EFI_D_WARN,"Platform: %a %a\n", ChipNamePtr, PlatTypePtr));

    /* Detected 8180 */
    if (platformInfo.platform == EFI_PLATFORMINFO_TYPE_MTP)
    {
      /* 8180 MTP platform */
      CopyMem(FwResourceGuid, &qcomFwResourceGUIDs[QCOM_FW_UPDATE_SYSTEM_FW_8180_MTP_TYPE], sizeof(EFI_GUID));
    }
    else if (platformInfo.platform == EFI_PLATFORMINFO_TYPE_CLS)
    {
      /* 8180 CLS platform */
      CopyMem(FwResourceGuid, &qcomFwResourceGUIDs[QCOM_FW_UPDATE_SYSTEM_FW_8180_CLS_TYPE], sizeof(EFI_GUID));
    }
    else if (platformInfo.platform == EFI_PLATFORMINFO_TYPE_QRD)
    {
      /* 8180 QRD platform */
      CopyMem(FwResourceGuid, &qcomFwResourceGUIDs[QCOM_FW_UPDATE_SYSTEM_FW_8180_QRD_TYPE], sizeof(EFI_GUID));
    }
    else
    {
      /* Unknown 8180 platform */
      DEBUG((EFI_D_WARN,"System firmware GUID not known for current platform (%a:%d). Using default firmware GUID.\n", PlatTypePtr, platformInfo.platform));
      CopyMem(FwResourceGuid, &qcomFwResourceGUIDs[QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_TYPE], sizeof(EFI_GUID));
    }
  }
  else
  {
    /* Unknown chipset */
    DEBUG((EFI_D_WARN,"Platform: Unknown chipset: %d\n", eId));
    CopyMem(FwResourceGuid, &qcomFwResourceGUIDs[QCOM_FW_UPDATE_SYSTEM_FW_UNKNOWN_TYPE], sizeof(EFI_GUID));
  }

QcomGetFwGuidForPlatformExit:

  return Status;
}

/**
 * Entry function for ESRT maintainence. 
 * This should be called before calling any other
 * function in this file
 *
 * Note: This function should not skip ESRT population on
 * intermediate errors as this will affect the firmware
 * being advertized in the system. Atleast some default
 * value should be used to derive a system firmware GUID
 *
 * @return EFI_STATUS
 **/
EFI_STATUS
QcomESRTPhaseMain(
  )
{
  EFI_STATUS                  Status             = EFI_SUCCESS;
  EFI_SYSTEM_RESOURCE_ENTRY  *buf                = NULL;
  UINTN                       esrtSize           = 0;
  BOOLEAN                     bIsESRTFromDPP     = FALSE;
  BOOLEAN                     bUpdateESRTNV      = FALSE;
  EFI_GUID                    QcomFwPlatformGuid;

  if (boot_from_spi_nor())
  {
    qcomFwResourceGUIDs = (EFI_GUID *)&qcomFwResourceGUIDs_SPINOR;
  }
  else if (boot_from_ufs())
  {
    qcomFwResourceGUIDs = (EFI_GUID *)&qcomFwResourceGUIDs_UFS;
  }
  else
  {
    DEBUG((EFI_D_WARN,"Error: Unsupported system memory type detected.\n"));
    return EFI_UNSUPPORTED;
  }

  /*Read ESRT entry from NV*/
  esrtSize = sizeof(EFI_SYSTEM_RESOURCE_ENTRY);

  /* Read ESRT from storage that is used to provision the ESRT from external source.
     If the same is present, use it as the one for the device. Delete it later after the
     contents are validated and updated in NV. */
  Status = QcomRead_EsrtEntryFromStorage(&buf, &esrtSize);
  if(Status == EFI_SUCCESS)
  {
    DEBUG((EFI_D_WARN,"\nSystem ESRT provision file found in DPP. Using the same to update internal ESRT data...\n"));
    bIsESRTFromDPP = TRUE;
    bUpdateESRTNV = TRUE;
  }
  else
  {
    DEBUG((EFI_D_WARN,"\nReading System ESRT Entry from NV...\n"));
    Status = QcomRead_EsrtEntryFromNV(&buf, &esrtSize);
  }

  if(Status != EFI_SUCCESS)
  {
    // Update this variable again as there is a possibility of this being set to wrong value
    // if the ESRT entry read function fails
    esrtSize = sizeof(EFI_SYSTEM_RESOURCE_ENTRY);

    if (Status == EFI_NO_MEDIA || Status == EFI_NOT_FOUND)
    {
      DEBUG((EFI_D_WARN,"System ESRT Entry not found. Attempting to generate one...\n"));
    }
    else
    {
      DEBUG((EFI_D_WARN,"System ESRT Entry read from NV failed with error: %r. Attempting to generate one...\n", Status));
    }
    Status = EFI_SUCCESS;

    if(buf != NULL)
    {
      gBS->FreePool(buf);
      buf = NULL;
    }

    CopyMem(&esrt_ent, &DefaultEsrtEntry, sizeof(esrt_ent));

    /* Write the initial DPP ESRT entry using the correct Firmware Resource GUID assigned to the
       given platform type. If it fails getting the platform type, the esrt_ent already contains
       UNKNOWN platform GUID. */
    Status = QcomGetFwGuidForPlatform(&QcomFwPlatformGuid);
    if (Status == EFI_SUCCESS)
    {
      CopyMem(&(esrt_ent.FwClass), &QcomFwPlatformGuid, sizeof(EFI_GUID));
    }
    else
    {
      DEBUG((EFI_D_ERROR,"Failed to find FW GUID for current device: %r. Using default GUID.\n", Status));
    }

    bUpdateESRTNV = TRUE;
  }
  else
  {
    CopyMem(&esrt_ent,(VOID*)buf,esrtSize);
  }

  if (TRUE == bUpdateESRTNV)
  {
    DEBUG((EFI_D_WARN,"Writing System ESRT Entry to NV...\n"));
    Status = QcomWrite_EsrtEntryToNV(&esrt_ent);
    if(Status != EFI_SUCCESS)
    {
      DEBUG((EFI_D_WARN,"Failed to Update ESRT in NV. Ignoring and proceeding\n"));
      Status = EFI_SUCCESS;
    }
  }

  if (bIsESRTFromDPP)
  {
    // Ignore the error as we do not plan to take any action on it
    QcomDelete_EsrtEntryFromStorage();
  }

  Status = UpdateVarSystemFmpCapsuleImageTypeIdGuid(esrt_ent.FwClass);
  if(Status != EFI_SUCCESS)
  {
    DEBUG((EFI_D_WARN,"Failed to Update SystemFmpCapsuleImageTypeIdGuid \n"));
    Status = EFI_SUCCESS;
  }
  else
  {
    DEBUG((EFI_D_INFO,"SystemFmpCapsuleImageTypeIdGuid update success or not required\n"));
  } 

  if(buf != NULL)
  {
    gBS->FreePool(buf);
    buf = NULL;
  }

  return Status;
}
