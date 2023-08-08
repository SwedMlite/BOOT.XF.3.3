/*===============================================================================
  Copyright (c) 2019 Qualcomm Technologies, Inc.  All Rights Reserved.

  FILE:         pil_event.h
  DESCRIPTION:  See EFIPILProxy.h

  REVISION HISTORY
  when       who         what, where, why
  --------   ---         --------------------------------------------------------
  03/28/19    ai         initial version

================================================================================*/

#ifndef __PIL_EVENT_H__
#define __PIL_EVENT_H__

#include<elf.h>
#include<pil_tz.h>

PIL_STATUS PilSendEvent(PIL_SUBSYS_CTX_TYPE*, UINT32 PILEvent, VOID* PILEventCtxt);

#endif //__PIL_EVENT_H__
