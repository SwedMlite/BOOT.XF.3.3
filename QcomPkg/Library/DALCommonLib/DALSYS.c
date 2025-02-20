/** @file DALSYS.c

  Copyright (c) 2010-2011,2014,2016,2018 Qualcomm Technologies, Inc. All rights reserved.
  DALSYS common library

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/13/18   ak      Remove DALSYS_MemRegionAlloc
 01/25/18   vk      Remove busywait from common file
 11/30/16   vk      Move memcpy_s here
 08/11/14   sho     Creation

=============================================================================*/

#include "DALStdDef.h"
#include "DALStdErr.h"
#include "DALSysCmn.h"
#include "DALSys.h"
#include "DALReg.h"
#include <Uefi.h>
#include <Library/CacheMaintenanceLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include "string.h"

/*-------------------------------------------------------------------
 Constant Definitions 
 ------------------------------------------------------------------*/
#define ALIGN_MASK      0x00000001f
#define ALIGN_UP( s )   (((DALSYSMemAddr)(s) + ALIGN_MASK) & ~(ALIGN_MASK))
#define ADD_SIZE_FOR_PADDING(s)  ((s) + ALIGN_MASK) 

#define PID             0xB000000D

/*-------------------------------------------------------------------
 Structure Definitions 
 ------------------------------------------------------------------*/
typedef struct 
{
   INHERIT_DALSYS_BASE_OBJ();
   DALSYSCallbackFunc    cbFunc;
   DALSYSCallbackFuncCtx cbFuncCtx;
}
_DALSYSEventObj;

typedef struct 
{
   DALSYSMemObjBase BaseObj;
   void *pMemRegion;
}
_DALSYSMemObj;

/*-------------------------------------------------------------------
 Variable Definitions 
 ------------------------------------------------------------------*/

/*-------------------------------------------------------------------
 Function Definitions 
 ------------------------------------------------------------------*/
DALResult
DALSYS_EventCreate(uint32 dwEvtAttrib, DALSYSEventHandle *phEvent,
                   DALSYSEventObj *pEventObj)
{
   _DALSYSEventObj *_pEventObj = (_DALSYSEventObj *)pEventObj;
   // only support statically pre-allocated object
   if((_pEventObj == NULL) || (phEvent == NULL ))
   {   
      DEBUG(( EFI_D_ERROR, "Event object 0x%x or Event handle 0x%x is NULL\n", 
             _pEventObj, phEvent ));
      return DAL_ERROR;
   }

   // only support callback event
   if(dwEvtAttrib & DALSYS_EVENT_ATTR_CALLBACK_EVENT)
   {
      _pEventObj->dwObjInfo = 0;
      DALSYSCMN_SET_OBJECT_ID(_pEventObj->dwObjInfo,DALSYSCMN_EVENT_OBJECT_ID);
      DALSYSCMN_SET_CALLBACK_EVENT_BIT(_pEventObj->dwObjInfo);
   }
   else
   {
      DEBUG(( EFI_D_ERROR, "Attempt to create a non-callback event; dwEvtAttrib 0x%x\n", 
             dwEvtAttrib ));
      return DAL_ERROR;
   }

   *phEvent = (DALSYSEventHandle)_pEventObj;
   return DAL_SUCCESS;
}

DALResult
DALSYS_EventCtrlEx(DALSYSEventHandle hEvent, uint32 dwCtrl, uint32 dwParam,
                   void *pPayload, uint32 dwPayloadSize)
{
   DALResult nErr = DAL_ERROR;
   _DALSYSEventObj *pEventObj = (_DALSYSEventObj *) DALSYSCMN_HANDLE_TO_OBJECT(hEvent);
   if(pEventObj)
   {
      switch(dwCtrl)
      {
         case DALSYS_EVENT_CTRL_TRIGGER:
            if(DALSYSCMN_IS_EVENT_A_CALLBACK(pEventObj->dwObjInfo))
            {
                if(pEventObj->cbFunc)
                {
                    pEventObj->cbFunc(pEventObj->cbFuncCtx,
                                dwParam,pPayload,dwPayloadSize);
                    nErr = DAL_SUCCESS;
                }
            }
            break;

         default:
            nErr = DAL_SUCCESS;
            break;
      }
   }
   return nErr;
}

DALResult
DALSYS_SetupCallbackEvent(DALSYSEventHandle hEvent, DALSYSCallbackFunc cbFunc,
                          DALSYSCallbackFuncCtx cbFuncCtx)
{
  _DALSYSEventObj *pEventObj = (_DALSYSEventObj *) DALSYSCMN_HANDLE_TO_OBJECT(hEvent);

   if(pEventObj && DALSYSCMN_IS_EVENT_A_CALLBACK(pEventObj->dwObjInfo))
   {
      pEventObj->cbFunc = cbFunc;
      pEventObj->cbFuncCtx = cbFuncCtx;
      return DAL_SUCCESS;
   }
   DEBUG(( EFI_D_ERROR, "Attempt to setup a callback func in a non-callback event\n" ));
   return DAL_ERROR;
}

void
DALSYS_LogEvent(DALDEVICEID DeviceId, uint32 dwLogEventType, 
      const char * pszLog, ...)
{
   uint32 dwEFILogEventType;

   switch (dwLogEventType)
   {
      case DALSYS_LOGEVENT_WARNING:
         dwEFILogEventType = EFI_D_WARN;
         break;

      case DALSYS_LOGEVENT_INFO:
         dwEFILogEventType = EFI_D_INFO;
         break;

      case DALSYS_LOGEVENT_FATAL_ERROR:
         ASSERT_EFI_ERROR (0);
         // fall-thru if ASSERT is disabled

      default:
         dwEFILogEventType = EFI_D_ERROR;
         break;
   }
   DEBUG ((dwEFILogEventType, "DALLOG Device [0x%x]: %a\n",
           DeviceId, pszLog ));
}
                             

DALResult
DALSYS_MemInfo(DALSYSMemHandle hMem, DALSYSMemInfo *pMemInfo)
{
    _DALSYSMemObj *pMemObj = (_DALSYSMemObj *)DALSYSCMN_HANDLE_TO_OBJECT(hMem);
    if(pMemObj)
    {
        pMemInfo->VirtualAddr  = pMemObj->BaseObj.VirtualAddr;
        pMemInfo->PhysicalAddr = pMemObj->BaseObj.PhysicalAddr;
        pMemInfo->dwLen        = pMemObj->BaseObj.dwLen;
        pMemInfo->dwMappedLen  = pMemObj->BaseObj.dwLen;
        DALSYSCMN_GET_ATTRIB(pMemObj->BaseObj.dwObjInfo,pMemInfo->dwProps);
        return DAL_SUCCESS;
    }
    return DAL_ERROR;
}

DALResult
DALSYS_CacheCommand(uint32 CacheCmd, DALSYSMemAddr VirtualAddr, uint32 dwLen)
{
   switch(CacheCmd)
   {
      case DALSYS_CACHE_CMD_INVALIDATE:
         InvalidateDataCacheRange( (void *)VirtualAddr, dwLen );
         break;
      case DALSYS_CACHE_CMD_CLEAN:
         WriteBackDataCacheRange( (void *)VirtualAddr, dwLen );
         break;
      case DALSYS_CACHE_CMD_FLUSH:
         WriteBackInvalidateDataCacheRange( (void *)VirtualAddr, dwLen);
         break;
      default:
         DEBUG(( EFI_D_ERROR, "Invalid cache command 0x%x\n", CacheCmd ));
         return DAL_ERROR;
   }

   return DAL_SUCCESS;
}


UINTN DALSYS_memscpy(VOID * Destination, UINTN DestLength, VOID * Source, UINTN SrcLength)
{
  if(DestLength >= SrcLength) {
    CopyMem(Destination, Source, SrcLength);
    return SrcLength;
  }

  CopyMem(Destination, Source, DestLength);
    return DestLength;
}

VOID * DALSYS_memset(VOID * buffer, UINT8 value, UINTN length)
{
   // length and value parameters are ordered different in SetMem API
   return SetMem( buffer, length, value );
}
