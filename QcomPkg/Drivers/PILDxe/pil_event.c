/*===============================================================================
  Copyright (c) 2019 Qualcomm Technologies, Inc.  All Rights Reserved.

  FILE:         pil_event.c

  DESCRIPTION:  See EFIPILProxy.h

  REVISION HISTORY
  when       who         what, where, why
  --------   ---         --------------------------------------------------------
  07/15/19   as         add PIL_EVENT_POST_LOAD
  03/28/19   ai         initial version
================================================================================*/

#include<pil_log.h>
#include<pil_loader.h>
#include<pil_config.h>
#include<pil_event.h>
#include<Protocol/EFIPILProxy.h>
#include<Protocol/EFIScm.h>
#include<Library/UefiLib.h>
#include<Library/QcomLib.h>
#include<Library/TimerLib.h>
#include<Library/PrintLib.h>
#include<Library/QcomBaseLib.h>
#include<Library/GuidedFvLib.h>
#include<Library/MountFvLib.h>
#include<Library/BaseMemoryLib.h>
#include<Library/DxeServicesTableLib.h>
#include<Library/MemoryAllocationLib.h>
#include<Library/UefiBootServicesTableLib.h>
#include<Library/UncachedMemoryAllocationLib.h>

PIL_STATUS PilSendEvent(PIL_SUBSYS_CTX_TYPE* Ctx, UINT32 PilEventId, VOID* PilEventCtxt)
{
    PIL_SUBSYS_CFG_TYPE     *Cfg = NULL;
    EFI_PIL_PROXY_PROTOCOL  *pPILProxyProtocol = NULL;
    EFI_STATUS              Status;

    ASSERT(Ctx != NULL);
    ASSERT_FAIL_PIL_RETURN(Ctx != NULL, PIL_INVALID_PARAM, PIL_INVALID_PARAM);

    ASSERT((Cfg = Ctx->Cfg) != NULL);
    ASSERT_FAIL_PIL_RETURN(Cfg != NULL, PIL_INVALID_PARAM, PIL_INVALID_PARAM);

    if(IsZeroGuid(&Cfg->ProxyGuid))
    {
      PIL_INFO_CFG(Cfg, "No ProxyGuid defined!\n");
      return PIL_SUCCESS;
    }

    Status = gBS->LocateProtocol(&Cfg->ProxyGuid, NULL, (VOID**)&pPILProxyProtocol);
    if (EFI_ERROR(Status) || (pPILProxyProtocol == NULL))
    {
      PIL_INFO_CFG(Cfg, "No ProxyGuid protocol found!\n");
      return PIL_SUCCESS;
    }

    switch(PilEventId)
    {
      case PIL_EVENT_PRE_AUTH_AND_RESET:
      case PIL_EVENT_POST_AUTH_AND_RESET:
      case PIL_EVENT_POST_LOAD:
        Status = pPILProxyProtocol->PilProxyHandleEvent(PilEventId, PilEventCtxt);
        if (EFI_SUCCESS != Status) {
            PIL_ERROR_CFG(Cfg, "Failed to call PIL Proxy HandleEvent\n");
            return Status;
        }
        PIL_INFO_CFG(Cfg, "Successfully called PIL Proxy HandleEvent\n");
        break;

      default:
        PIL_ERROR_CFG(Cfg, "Unknown PILEventId: %u\n", PilEventId);
    }

    return PIL_SUCCESS;
}
