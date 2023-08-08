/** @file CprhDxe.c

  This file implements CPRH EFI protocol interface.

  Copyright (c) 2017-2018, Qualcomm Technologies, Inc. All rights 
  reserved. 

**/

/*=========================================================================
      Include Files
==========================================================================*/

#include <Uefi.h>

#include <Library/CPR.h>
#include <Library/UefiLib.h>
#include <Library/QcomLib.h>
#include <Library/DebugLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/EFIHWIO.h>
#include <Protocol/EFILimits.h>
#include <Protocol/EFIDisplayPwr.h>
#include <Protocol/EFIDALSYSProtocol.h>
/*=========================================================================
      Globals and prototypes
==========================================================================*/
/* Dependencies for CPR */
boolean DispPwrInit                         = FALSE;

//ToDo: Enable Limits dependency when Limits driver is enabled.
boolean LimitsInit                          = FALSE;

/* Interface for Display Protocol status access */
EFI_DISPLAY_POWER_PROTOCOL *DispPwrProto = NULL;
VOID *DisplayPowerNotificationToken = NULL;
EFI_EVENT DisplayPowerNotificationEvent = (EFI_EVENT)NULL;

/* Interface for Limits Protocol status access */
EFI_LIMITS_PROTOCOL *LimitsProto            = NULL;
VOID *LimitsNotificationToken               = NULL;
EFI_EVENT LimitsNotificationEvent           = (EFI_EVENT)NULL;

VOID
LimitsInstalledNotification(
    IN EFI_EVENT   Event,
    IN VOID        *Context
    )
{
    EFI_STATUS              Status;
    Status = gBS->LocateProtocol(&gEfiLimitsProtocolGuid,
                                  NULL,
                                  (VOID**) &LimitsProto);
    ASSERT_EFI_ERROR(Status);

    LimitsInit = TRUE;

    if (LimitsInit && DispPwrInit)
        cpr_init();
}

VOID
DisplayPowerInstalledNotification(
    IN EFI_EVENT   Event,
    IN VOID        *Context
    )
{
    EFI_STATUS              Status;

    Status = gBS->LocateProtocol(&gEfiDisplayPowerStateProtocolGuid,
                                  NULL,
                                  (VOID**) &DispPwrProto);
    ASSERT_EFI_ERROR(Status);

    DispPwrInit = TRUE;

    if (LimitsInit && DispPwrInit)
        cpr_init();
}

VOID CPRMapRegions(VOID)
{
    EFI_HWIO_PROTOCOL *HWIOProtocol = NULL;
    EFI_STATUS Status = EFI_SUCCESS;
    UINT64 BaseAddr = 0x00630000;

    Status = gBS->LocateProtocol(&gEfiHwioProtocolGuid, NULL,
                                 (void**)&HWIOProtocol);
    if ((EFI_SUCCESS != Status) || (HWIOProtocol == NULL))
    {
        DEBUG((EFI_D_ERROR, "ERROR: Failed to locate HWIO Protocol: 0x%08x\n",
                    Status));
        ASSERT_EFI_ERROR(Status);
        return;
    }

    Status = HWIOProtocol->MapRegion(HWIOProtocol, "MMCX_CPR3",
            (UINT8**)&(BaseAddr));

    if ((EFI_SUCCESS != Status))
    {
        DEBUG((EFI_D_ERROR, "ERROR: Failed to MapRegion: 0x%08x\n",
                    BaseAddr));
    }
    ASSERT_EFI_ERROR (Status);
}

/**
 * Entry point for the CPR DXE driver.
 */
EFI_STATUS
EFIAPI
CPRDxeEntryPoint(
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
    )
{
    EFI_STATUS  Status = EFI_SUCCESS;
    DALSYS_InitMod(NULL);

    /* Map MMCX CPR region */
    CPRMapRegions();

    /* Locate Limits protocol */
    Status = gBS->LocateProtocol(&gEfiLimitsProtocolGuid,
                                  NULL,
                                  (VOID**) &LimitsProto);
    if (EFI_ERROR(Status))
    {
        Status = gBS->CreateEvent(EVT_NOTIFY_SIGNAL, TPL_CALLBACK,
                                LimitsInstalledNotification,
                                NULL, &LimitsNotificationEvent);
        ASSERT_EFI_ERROR (Status);

        Status = gBS->RegisterProtocolNotify(&gEfiLimitsProtocolGuid,
                                    LimitsNotificationEvent,
                                    (VOID *)&LimitsNotificationToken);
        ASSERT_EFI_ERROR (Status);
    }
    else
    {
        LimitsInit = TRUE;
    }

    /* Locate Display Power protocol */
    Status = gBS->LocateProtocol(&gEfiDisplayPowerStateProtocolGuid,
                                  NULL,
                                  (VOID**) &DispPwrProto);
    if (EFI_ERROR(Status))
    {
        Status = gBS->CreateEvent(EVT_NOTIFY_SIGNAL, TPL_CALLBACK,
                                DisplayPowerInstalledNotification,
                                NULL, &DisplayPowerNotificationEvent);
        ASSERT_EFI_ERROR (Status);

        Status = gBS->RegisterProtocolNotify(&gEfiDisplayPowerStateProtocolGuid,
                                    DisplayPowerNotificationEvent,
                                    (VOID *)&DisplayPowerNotificationToken);
        ASSERT_EFI_ERROR (Status);
    }
    else
    {
        DispPwrInit = TRUE;
    }

    if (LimitsInit && DispPwrInit)
        cpr_init();

    return Status;
}
