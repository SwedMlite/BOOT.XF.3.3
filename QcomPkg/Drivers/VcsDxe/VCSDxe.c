/** @file VcsDxe.c

  This file implements vcs EFI protocol interface.
  Copyright (c) 2017 - 2019 Qualcomm Technologies, Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/14/19    richaa      Created.

=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Protocol/EFIDALSYSProtocol.h>
#include <Protocol/EFIVcs.h>
#include "DALDeviceId.h"
#include "DDIVCS.h"
#include <Library/QcomTargetLib.h>
#include <Library/QcomLib.h>
#include <voltage_level.h>


/*=========================================================================
      Type Definitions
==========================================================================*/


/*=========================================================================
      Function Prototypes
==========================================================================*/

EFI_STATUS EFI_GetBootCorner(IN EFI_VCS_PROTOCOL *This,
                          IN CONST CHAR8 *szName, OUT UINT32 *pLevel);


/*=========================================================================
      Data Declarations
==========================================================================*/

// Clock Public Protocol
static EFI_VCS_PROTOCOL VcsProtocol =
{
   EFI_VCS_PROTOCOL_VERSION,
   EFI_GetBootCorner  
};


static DalDeviceHandle *hVcs = NULL;

DALProps gDALModStringDeviceInfoList = {NULL, 0 ,0 , NULL};

/*==============================================================================

                     GLOBAL VARIABLES FOR THIS MODULE

==============================================================================*/
extern DALREG_DriverInfo DALVCS_DriverInfo;

static DALREG_DriverInfo * DALDriverInfoArr[1] = { &DALVCS_DriverInfo };

static DALSYSConfig DALSYSModConfig =
   {
      {0, NULL},              // string device info
      {1, DALDriverInfoArr}   // numeric driver info
   };
   
/*=========================================================================
      Functions
==========================================================================*/


/**

  This functions gets the boot corner for the voltage rails

  @param  This      [in]        The EFI_VCS_PROTOCOL instance.
  @param  szName    [in]        String name of the rail
  @param  pLevel    [out]       Pointer for the rail voltage level

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS EFI_GetBootCorner
(IN EFI_VCS_PROTOCOL *This,
IN CONST CHAR8 *szName, 
OUT UINT32 *pLevel)
{
  DALResult eResult;

  if (szName == NULL || pLevel == NULL)
  {
    return EFI_INVALID_PARAMETER;
  }

  eResult = DalVcs_GetBootCorner(hVcs,szName, pLevel);

  if(eResult == DAL_SUCCESS)
  {
     return EFI_SUCCESS;
  }
  else
  {
     //for now, just return one common error condition
     //there is no one-to-one mapping from DAL return code to
     //EFI API return codes.
     return EFI_PROTOCOL_ERROR;
  }
}


/**
  VCS DXE driver entry point.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/

EFI_STATUS
EFIAPI
VcsDxeEntryPoint (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_HANDLE  handle = NULL;
  EFI_STATUS  status;
  DALResult   eResult;

  // Init DALSys
  DALSYS_InitMod(&DALSYSModConfig);

  //Attach to the VCS DAL
  eResult = DAL_DeviceAttach(DALDEVICEID_VCS, &hVcs);
  if(eResult == DAL_SUCCESS)
  {
   
      // Publish the DALSYS Protocol
       status = gBS->InstallMultipleProtocolInterfaces(
                    &handle,
                    &gEfiVcsProtocolGuid,
                    (void **)&VcsProtocol,
                     NULL );
  }
  else
  {
    DALSYS_DeInitMod();
    status = EFI_PROTOCOL_ERROR;
  }

  return status;
}

