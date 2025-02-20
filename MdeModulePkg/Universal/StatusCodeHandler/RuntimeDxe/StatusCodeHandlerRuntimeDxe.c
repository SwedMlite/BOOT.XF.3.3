/** @file
  Status Code Handler Driver which produces general handlers and hook them
  onto the DXE status code router.

  Copyright (c) 2017-2018 Qualcomm Technologies, Inc.  All Rights Reserved
  Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "StatusCodeHandlerRuntimeDxe.h"

EFI_EVENT                 mVirtualAddressChangeEvent = NULL;
EFI_EVENT                 mExitBootServicesEvent     = NULL;
EFI_RSC_HANDLER_PROTOCOL  *mRscHandlerProtocol       = NULL;

/**
  Unregister status code callback functions only available at boot time from
  report status code router when exiting boot services.

  @param  Event         Event whose notification function is being invoked.
  @param  Context       Pointer to the notification function's context, which is
                        always zero in current implementation.

**/
VOID
EFIAPI
UnregisterBootTimeHandlers (
  IN EFI_EVENT        Event,
  IN VOID             *Context
  )
{
  if (FeaturePcdGet (PcdStatusCodeUseSerial)) {
    mRscHandlerProtocol->Unregister (SerialStatusCodeReportWorker);
  }
}

/**
  Virtual address change notification call back. It converts global pointer
  to virtual address.

  @param  Event         Event whose notification function is being invoked.
  @param  Context       Pointer to the notification function's context, which is
                        always zero in current implementation.

**/
VOID
EFIAPI
VirtualAddressChangeCallBack (
  IN EFI_EVENT        Event,
  IN VOID             *Context
  )
{
  //
  // Convert memory status code table to virtual address;
  //
  EfiConvertPointer (
    0,
    (VOID **) &mRtMemoryStatusCodeTable
    );
}

/**
  Dispatch initialization request to sub status code devices based on 
  customized feature flags.
 
**/
VOID
InitializationDispatcherWorker (
  VOID
  )
{
  EFI_PEI_HOB_POINTERS              Hob;
  EFI_STATUS                        Status;
  MEMORY_STATUSCODE_PACKET_HEADER   *PacketHeader;
  MEMORY_STATUSCODE_RECORD          *Record;
  UINTN                             Index;
  UINTN                             MaxRecordNumber;

  //
  // If enable UseSerial, then initialize serial port.
  // if enable UseRuntimeMemory, then initialize runtime memory status code worker.
  //
  if (FeaturePcdGet (PcdStatusCodeUseSerial)) {
    //
    // Call Serial Port Lib API to initialize serial port.
    //
    Status = SerialPortInitialize ();
    ASSERT_EFI_ERROR (Status);
  }
  if (FeaturePcdGet (PcdStatusCodeUseMemory)) {
    Status = RtMemoryStatusCodeInitializeWorker ();
    ASSERT_EFI_ERROR (Status);
  }

  //
  // Replay Status code which saved in GUID'ed HOB to all supported devices. 
  //
  if (FeaturePcdGet (PcdStatusCodeReplayIn)) {
    // 
    // Journal GUID'ed HOBs to find all record entry, if found, 
    // then output record to support replay device.
    //
    Hob.Raw   = GetFirstGuidHob (&gMemoryStatusCodeRecordGuid);
    if (Hob.Raw != NULL) {
      PacketHeader = (MEMORY_STATUSCODE_PACKET_HEADER *) GET_GUID_HOB_DATA (Hob.Guid);
      Record = (MEMORY_STATUSCODE_RECORD *) (PacketHeader + 1);
      MaxRecordNumber = (UINTN) PacketHeader->RecordIndex;
      if (PacketHeader->PacketIndex > 0) {
        //
        // Record has been wrapped around. So, record number has arrived at max number.
        //
        MaxRecordNumber = (UINTN) PacketHeader->MaxRecordsNumber;
      }
      for (Index = 0; Index < MaxRecordNumber; Index++) {
        //
        // Dispatch records to devices based on feature flag.
        //
        if (FeaturePcdGet (PcdStatusCodeUseSerial)) {
          SerialStatusCodeReportWorker (
            Record[Index].CodeType,
            Record[Index].Value,
            Record[Index].Instance,
            NULL,
            NULL
            );
        }
        if (FeaturePcdGet (PcdStatusCodeUseMemory)) {
          RtMemoryStatusCodeReportWorker (
            Record[Index].CodeType,
            Record[Index].Value,
            Record[Index].Instance,
            NULL,
            NULL
            );
        }
      }
    }
  }
}

/**
  Entry point of DXE Status Code Driver.

  This function is the entry point of this DXE Status Code Driver.
  It initializes registers status code handlers, and registers event for EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE.

  @param  ImageHandle       The firmware allocated handle for the EFI image.
  @param  SystemTable       A pointer to the EFI System Table.
  
  @retval EFI_SUCCESS       The entry point is executed successfully.

**/
EFI_STATUS
EFIAPI
StatusCodeHandlerRuntimeDxeEntry (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS                Status;

  Status = gBS->LocateProtocol (
                  &gEfiRscHandlerProtocolGuid,
                  NULL,
                  (VOID **) &mRscHandlerProtocol
                  );
  ASSERT_EFI_ERROR (Status);

  //
  // Dispatch initialization request to supported devices
  //
  InitializationDispatcherWorker ();

  if (FeaturePcdGet (PcdStatusCodeUseSerial)) {
    mRscHandlerProtocol->Register (SerialStatusCodeReportWorker, TPL_HIGH_LEVEL);
  }
  if (FeaturePcdGet (PcdStatusCodeUseMemory)) {
    mRscHandlerProtocol->Register (RtMemoryStatusCodeReportWorker, TPL_HIGH_LEVEL);
  }

  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
#if defined (QCOM_EDK2_PATCH)
                  TPL_CALLBACK,
#else				  
                  TPL_NOTIFY,
#endif
                  UnregisterBootTimeHandlers,
                  NULL,
                  &gEfiEventExitBootServicesGuid,
                  &mExitBootServicesEvent
                  );

  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
#if defined (QCOM_EDK2_PATCH)
                  TPL_CALLBACK,
#else				  
                  TPL_NOTIFY,
#endif
                  VirtualAddressChangeCallBack,
                  NULL,
                  &gEfiEventVirtualAddressChangeGuid,
                  &mVirtualAddressChangeEvent
                  );
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}
