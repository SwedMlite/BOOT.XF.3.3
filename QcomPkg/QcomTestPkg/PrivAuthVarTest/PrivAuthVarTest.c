/** @file PrivAuthVarTest.c
   
  Tests for Private Authenticated Variables.

  Copyright (c) 2018, Qualcomm Technologies Inc. All rights reserved.
  Portions Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php
  
  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 04/04/18   ai      Initial Revision

=============================================================================*/

#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/QcomLib.h>
#include <Guid/ImageAuthentication.h>
#include "db.h"
#include "nulldb.h"
#include "payload.h"

extern EFI_GUID gEfiGlobalVariableGuid;

/**
  The user Entry Point for Application. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.  
  @param[in] SystemTable    A pointer to the EFI System Table.
  
  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
PrivAuthVarTestMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status     = EFI_SUCCESS;
  UINT8 VarData         = 0;
  UINTN VarDataSize     = sizeof(VarData);
  UINT8 IsDbConfigured  = 0;

  UINT32 Attributes = (EFI_VARIABLE_RUNTIME_ACCESS | 
                       EFI_VARIABLE_BOOTSERVICE_ACCESS |
                       EFI_VARIABLE_NON_VOLATILE |
                       EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS);
                       /* EFI_VARIABLE_APPEND_WRITE */

  AsciiPrint("Checking db... ");
  Status = gRT->GetVariable(EFI_IMAGE_SECURITY_DATABASE,
      &gEfiImageSecurityDatabaseGuid, NULL, &VarDataSize, &VarData);
  if (Status == EFI_BUFFER_TOO_SMALL)
  {
    AsciiPrint("pass\n");
    IsDbConfigured = 1;
  }
  else
  {
    AsciiPrint("not configured\n");
    IsDbConfigured = 0;
  }

  if (IsDbConfigured == 0)
  {
    AsciiPrint("Configuring db\n");
    Status = gRT->SetVariable(EFI_IMAGE_SECURITY_DATABASE, 
        &gEfiImageSecurityDatabaseGuid, Attributes,
        signed_db_len, signed_db); 
    if (Status != EFI_SUCCESS)
    {
      AsciiPrint("ERR! - %r\n", Status);
      goto Exit;
    } 
    (VOID)FlushVariableServices(); 
    gRT->ResetSystem (EfiResetCold, EFI_SUCCESS, 0, NULL);
  }  

  AsciiPrint("Adding private authenticated variable\n");
  Status = gRT->SetVariable(L"pav", &gEfiGlobalVariableGuid,
      Attributes, signed_payload_len, signed_payload); 
  if (Status != EFI_SUCCESS)
  {
    AsciiPrint("ERR! - %r\n", Status);
    goto Exit;
  } 
    
Exit:
  return Status;
}

