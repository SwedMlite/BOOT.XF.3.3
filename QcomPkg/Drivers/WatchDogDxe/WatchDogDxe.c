/*===============================================================================
  Copyright (c) 2018 Qualcomm Technologies, Inc.  All Rights Reserved.
  
  FILE:         WatchDogDxe.c
  DESCRIPTION:    
  
  REVISION HISTORY
  when       who         what, where, why
  --------   ---         --------------------------------------------------------
  04/13/18   yw         initial version

================================================================================*/

#include <Protocol/EFIWatchDog.h>
#include <UefiInfoBlk.h>
#include <Library/PcdLib.h>
#include <Library/QcomLib.h>
#include <Library/UefiLib.h>
#include <Library/KernelLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/WatchdogLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

#define WDOG_TIMEOUT_IN_SECS                25 // in sec
#define WDOG_PET_TIME_IN_SECS                2 // in sec

STATIC     EFI_EVENT  PetTimerEvent;
STATIC     EFI_EVENT  ExitBootServicesEvent;

STATIC VOID EFI_WDT_Enable(VOID)
{    
    return WatchDogEnable();
}

STATIC VOID EFI_WDT_Disable(VOID)
{    
    return WatchDogDisable();
}

STATIC EFI_STATUS EFI_WDT_SetBiteTimer(IN UINT32 TimeInSec)
{    
    return WatchDogSetBiteTimer(TimeInSec);
}

STATIC VOID EFI_WDT_ResetCounter(VOID)
{    
    return ResetWatchDogCounter();
}

STATIC EFI_STATUS EFI_WDT_DoReset(VOID)
{    
    return DoWatchDogReset();
}


STATIC 
enum HandlerStatus WdgPetTimerCallback (IN Timer* Timer, IN TimeDuration Duration, IN VOID *Arg)
{
    ResetWatchDogCounter();
    return HANDLER_NO_RESCHEDULE;
}

STATIC 
VOID
WdogVariableNotificationCb(IN EFI_EVENT Timer, IN VOID  *Context)
{
    BOOLEAN ForceDisableHWWdog = FALSE;
    EFI_STATUS Status;
    UINTN VarSize;
    
    Status = gRT->GetVariable (L"ForceDisableHWWdog", &gQcomTokenSpaceGuid,
                               NULL, &VarSize, &ForceDisableHWWdog);
                              
    if (Status == EFI_SUCCESS && ForceDisableHWWdog)
    {
        DEBUG((EFI_D_WARN, "Force disable HW watchdog and pet timer %r\n", Status));
        
        WatchDogDisable();
        gBS->SetTimer (PetTimerEvent, TimerCancel, 0);
        gBS->CloseEvent(PetTimerEvent);
    }
    return;
}

Timer* WdtTimer;

STATIC 
EFI_STATUS RegisterWdgPetTimer()
{
  WdtTimer = TimerInit ();
  if (WdtTimer == NULL) 
      return EFI_UNSUPPORTED;
  
  TimerSetPeriodic (WdtTimer, SEC_TO_MSEC(WDOG_PET_TIME_IN_SECS), WdgPetTimerCallback, 0);
  
  return EFI_SUCCESS;
}

STATIC
VOID DisableWdogAndPetTimerCb()
{
    WatchDogDisable();
    gBS->SetTimer (PetTimerEvent, TimerCancel, 0);
    gBS->CloseEvent(PetTimerEvent);
}

/**
  WatchDog protocol defination
  
**/
STATIC EFI_WATCHDOG_PROTOCOL WatchDogProtocol =
{
   .Version      = EFI_WATCHDOG_PROTOCOL_VER_V1,
   .Enable       = EFI_WDT_Enable,
   .Disable      = EFI_WDT_Disable,
   .SetBiteTimer = EFI_WDT_SetBiteTimer,
   .ResetCounter = EFI_WDT_ResetCounter,
   .Reset        = EFI_WDT_DoReset
};


/**
  The Entry Point for watchdog module. 

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurred when executing this entry point.

**/
 
EFI_STATUS EFIAPI 
WatchDogDxeEntry
(
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
    
    EFI_HANDLE Handle = NULL;
    EFI_STATUS Status;
    UefiInfoBlkType *InfoBlkPtr;
    VOID       *Registration;
    EFI_EVENT  Evt;
    
    InfoBlkPtr = (UefiInfoBlkType*)GetInfoBlkPtr();
    ASSERT (InfoBlkPtr != NULL);
    
    if (InfoBlkPtr->ForceDisableHWWdog || PcdGetBool(ForceDisableHWWdog) == TRUE) 
    {
        DEBUG((EFI_D_WARN, "ForceDisableHWWdog is set\n"));
        HWWdogDisabled = TRUE;
        return EFI_UNSUPPORTED;
    }
    
    /* start pet timmer */
    Status = RegisterWdgPetTimer();
    if (EFI_ERROR(Status)) {
        DEBUG((EFI_D_ERROR, "Failed to register WDOG pet timer\n"));
        return Status;
    }
    
    /* setup wdog timeout to 25 sec */
    Status = WatchDogSetBiteTimer(SEC_TO_MSEC(WDOG_TIMEOUT_IN_SECS));
    if (EFI_ERROR(Status)) {
        DEBUG((EFI_D_ERROR, "Failed to set WDOG bite timer\n"));
        return Status;
    }
    
    WatchDogEnable();
    
    /* Register for variable protocol notify callback */
    Evt = EfiCreateProtocolNotifyEvent(&gEfiVariableServicesProtocolGuid,
                                        TPL_CALLBACK,
                                        WdogVariableNotificationCb,
                                        NULL,
                                        &Registration);
    if (Evt == NULL)
    {
      DEBUG((EFI_D_WARN, "Could not register Wdog variable callback\n"));
      return EFI_DEVICE_ERROR; 
    }
    
    /* set callback to disable wdog before jump to hlos */
    Status = gBS->CreateEventEx(EVT_NOTIFY_SIGNAL,
                       TPL_CALLBACK,
                       DisableWdogAndPetTimerCb,
                       NULL,
                       &gEfiEventExitBootServicesGuid,
                       &ExitBootServicesEvent);
    if(EFI_ERROR(Status)) {
        DEBUG((EFI_D_WARN, "Failed to register exit boot service callback\n"));
        return Status;
    }

    Status = gBS->InstallMultipleProtocolInterfaces(
                    &Handle,
                    &gEfiWatchDogProtocolGuid,
                    (VOID **)&WatchDogProtocol,
                    NULL );
    if (EFI_ERROR(Status)) {
        DEBUG((EFI_D_WARN, "Failed to install watchdog protocol\n"));
        return Status; 
    }
    
    return EFI_SUCCESS;
}