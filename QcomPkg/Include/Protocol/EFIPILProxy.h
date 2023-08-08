/*===============================================================================
  Copyright (c) 2019 Qualcomm Technologies, Inc.  All Rights Reserved.

  FILE:         EFIPILProxy.h
  DESCRIPTION:  PIL Notification Events

                The PIL proxy protocol enables a subsystem owner to receive
                notification events for various stages of the PIL process.
                For example, a subsytem may require that certain resources have
                a proxy vote from the CPU subsystem prior to sending a PIL start
                to TZ. By registering for the PIL_PROXY_PRE_START event, the
                subystem owner can make the required resources votes.

                See QcomPkg.dec for various gPILProxyXXXGuid definitions for
                the subsystems.

  REVISION HISTORY
  when       who         what, where, why
  --------   ---         --------------------------------------------------------
  03/28/19    ai         initial version
================================================================================*/

#ifndef __EFI_PIL_PROXY_H__
#define __EFI_PIL_PROXY_H__

#define EFI_PIL_PROXY_PROTOCOL_VERSION    0x0000000000010000

/* PIL events sent to PilProxyHandleEvent function */
#define PIL_EVENT_PRE_AUTH_AND_RESET      0x00000001    /* Event sent before TZ_PIL_AUTH_RESET */
#define PIL_EVENT_POST_AUTH_AND_RESET     0x00000002    /* Event sent after TZ_PIL_AUTH_RESET */
#define PIL_EVENT_POST_LOAD               0x00000004    /* Event sent after TZ_PIL_AUTH_RESET */

typedef struct _PIL_EVENT_PRE_AUTH_AND_RESET_PARAM
{
    UINTN   RegionStart;
    UINTN   RegionSize;
} PIL_EVENT_PRE_AUTH_AND_RESET_PARAM;

/* See DESCRIPTION at the top of the file.
 *
 * The PILProxyHandleEvent function receives various PIL events.
 * Arguments:
 *   PILEvent -- See PIL_EVENT_XXX
 *   PILEventCtxt -- Depending on the event, an optional event context may be provided.
 */
typedef
EFI_STATUS
(EFIAPI *EFI_PIL_PROXY_HANDLE_EVENT) (
   UINT32                           PILEvent,
   VOID*                            PILEventCtxt
   );

typedef struct _EFI_PIL_PROXY_PROTOCOL {
   UINT64                           Revision;
   EFI_PIL_PROXY_HANDLE_EVENT       PilProxyHandleEvent;
} EFI_PIL_PROXY_PROTOCOL;

#endif // __EFI_PIL_PROXY_H__
