/** @file PILProxyDxe.c

  PIL proxy vote driver for all subsystem

  Copyright (c) 2019,  Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when         who     what, where, why
 --------     ---     -----------------------------------------------------------
 03/28/19     ai      Initial revision 
 10/30/19     yw      unify cdspdxe and npudxe,changing to general proxy vote for all subsystem,
                      adding unvote timer for 3 sec delay
 
=============================================================================*/
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/EFIPILProxy.h>
#include <scm_sip_interface.h>

/* unvote in 3 sec */
#define	UNVOTE_DELAY	3000000U

/*===========================================================================*/
/*                  FUNCTIONS PROTOTYPES FOR TARGET LIB                      */
/*===========================================================================*/

extern EFI_STATUS PILProxyVote(UINT32);
extern EFI_STATUS PILProxyUnvote(UINT32);

/*===========================================================================*/
/*                  FUNCTIONS DEFINITIONS                                    */
/*===========================================================================*/

VOID EFIAPI	PILProxyUnvoteCb(
	IN  EFI_EVENT                Event,
	IN  VOID                     *Context
    )
{
	EFI_STATUS  Status;
	UINT32		SubsysId = (UINT32)Context;
	
	Status = PILProxyUnvote(SubsysId);
	if (EFI_ERROR (Status)) 
	{
		DEBUG(( EFI_D_ERROR, "PILProxyUnvoteCb: failed to unvote for proc 0x%x\n\n", SubsysId));
	}
	
	gBS->CloseEvent ( Event );
}

EFI_STATUS PilProxyHandleEvent (
   UINT32                           PILEvent,
   UINT32                   		SubsysId
   )
{
  EFI_STATUS 	Status = EFI_SUCCESS;
  EFI_EVENT		UnvoteTimer;	

  switch(PILEvent)
  {
    case PIL_EVENT_PRE_AUTH_AND_RESET:
      Status = PILProxyVote(SubsysId);
      break;

    case PIL_EVENT_POST_AUTH_AND_RESET:

	  Status = gBS->CreateEvent (
                  EVT_TIMER | EVT_NOTIFY_SIGNAL,
                  TPL_CALLBACK,
                  PILProxyUnvoteCb,
                  (VOID*)((UINTN)SubsysId),
                  &UnvoteTimer
                  );
				  
	  if (EFI_ERROR (Status))
          break;

	  Status = gBS->SetTimer (
                  UnvoteTimer,
                  TimerRelative,
                  UNVOTE_DELAY
                  );
				  
	  if (EFI_ERROR (Status))
          break;
				  
      break;

    default:
      /* return success for unhandled events */
      break;
  }

  return Status;
}

EFI_STATUS PilProxyHandleEvent_Adsp (
   UINT32                           PILEvent,
   VOID*                            PILEventCtxt
   )
{
	return PilProxyHandleEvent(PILEvent, TZ_PIL_AUTH_QDSP6_PROC);
}

EFI_STATUS PilProxyHandleEvent_Cdsp (
   UINT32                           PILEvent,
   VOID*                            PILEventCtxt
   )
{
	return PilProxyHandleEvent(PILEvent, TZ_PIL_AUTH_CDSP_PROC);
}

EFI_STATUS PilProxyHandleEvent_Slpi (
   UINT32                           PILEvent,
   VOID*                            PILEventCtxt
   )
{
	return PilProxyHandleEvent(PILEvent, TZ_PIL_AUTH_SSC_PROC);
}

EFI_STATUS PilProxyHandleEvent_Npu (
   UINT32                           PILEvent,
   VOID*                            PILEventCtxt
   )
{
	return PilProxyHandleEvent(PILEvent, TZ_PIL_AUTH_NPU_PROC);
}

/**
  PIL proxy protocol definition

**/
STATIC EFI_PIL_PROXY_PROTOCOL mCdspPilProxyProtocol =
{
   EFI_PIL_PROXY_PROTOCOL_VERSION,
   PilProxyHandleEvent_Cdsp
};

STATIC EFI_PIL_PROXY_PROTOCOL mNpuPilProxyProtocol =
{
   EFI_PIL_PROXY_PROTOCOL_VERSION,
   PilProxyHandleEvent_Npu
};

STATIC EFI_PIL_PROXY_PROTOCOL mAdspPilProxyProtocol =
{
   EFI_PIL_PROXY_PROTOCOL_VERSION,
   PilProxyHandleEvent_Adsp
};

STATIC EFI_PIL_PROXY_PROTOCOL mSlpiPilProxyProtocol =
{
   EFI_PIL_PROXY_PROTOCOL_VERSION,
   PilProxyHandleEvent_Slpi
};



/*

  PILProxyDxeEntry ()

  @brief
  Initialize Proxy Driver
 */
EFI_STATUS PILProxyDxeEntry
(
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
)
{
  EFI_HANDLE mHandle = NULL;
  EFI_STATUS         Status   = EFI_LOAD_ERROR;

  Status = gBS->InstallMultipleProtocolInterfaces(
                    &mHandle,
                    &gPILProxyCDSPGuid,
                    (VOID **)&mCdspPilProxyProtocol,
					&gPILProxyNPUSSGuid,
                    (VOID **)&mNpuPilProxyProtocol,
					&gPILProxyAdspGuid,
                    (VOID **)&mAdspPilProxyProtocol,
					&gPILProxySlpiGuid,
                    (VOID **)&mSlpiPilProxyProtocol,
                    NULL );
  if (EFI_ERROR(Status))
    return Status;

  return EFI_SUCCESS;
}
