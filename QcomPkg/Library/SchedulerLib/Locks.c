/** @file
  Recursive Locks implementation to provide for the protocol.
   
  Copyright (c) 2017, 2019 Qualcomm Technologies Inc. All rights reserved.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 07/24/17   yg      Initial version

=============================================================================*/

#include <Uefi.h>

#include "list.h"
#include "interrupts.h"
#include "kernel/spinlock.h"
#include "kernel/thread.h"
#include "kernel/mutex.h"
#include "kernel/timer.h"
#include "kernel/semaphore.h"
#include "kernel/event.h"
#include "kernel/wait.h"
#include "StWrappers.h"
#include "Locks.h"

#include <Protocol/EFIKernelInterface.h>

#define FLAG_RECURSIVE_LOCK   (1  << 0)
#define FLAG_NAMED_LOCK       (1  << 1)

#define LOCK_OPTION_RECURSIVE  (1 << 1)

typedef struct 
{
   UINT32     Sig;
   UINT32     Flags;
   Mutex     *MutexPtr;
   UINTN      NestLevel;
   UINT32     MaxNest;
   UINT32     InactivityCnt;
} 
LockType;

STATIC EFI_STATUS InitLockInternal (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                                    OUT LockHandle** LockHandlePtr,
                                    IN  UINT32       Option)
{
  LockType *LockPtr;
  UINT64 LockID;
  Mutex* MLockPtr;
  CONST CHAR8* Sptr = LockStrID;

  if (LockHandlePtr == 0)
    return EFI_INVALID_PARAMETER;

  LockID = 0;

  if (LockStrID)
  {
    UINTN i;
    for (i=0; i<8; ++i)
    {
      LockID = LockID | (((UINT64)(*Sptr)) << (i * 8));
      if (*Sptr == 0)
        break;
      ++Sptr;
    }
    if ((i >= 8) && (*Sptr != 0))
      return EFI_BAD_BUFFER_SIZE;
  }

  MLockPtr = init_mutex (LockID);

  if (MLockPtr == NULL)
    return EFI_OUT_OF_RESOURCES;

  /* Use scheduler heap since Sec heap will not be appropriate during
   * dxe stage */
  LockPtr = malloc (sizeof(*LockPtr));

  if (LockPtr == 0)
    return EFI_OUT_OF_RESOURCES;

  memset (LockPtr, 0, sizeof(*LockPtr));

  LockPtr->Sig = 'L' | ('o' << 8) | ('c' << 16) | ('k' << 24);

  LockPtr->MutexPtr = MLockPtr;

  if (LockID)
    LockPtr->Flags = FLAG_NAMED_LOCK;

  if (Option & LOCK_OPTION_RECURSIVE)
    LockPtr->Flags = LockPtr->Flags | FLAG_RECURSIVE_LOCK;

  *LockHandlePtr = (LockHandle*)LockPtr;

  return EFI_SUCCESS;
}

VOID DestroyLock (LockHandle* Handle)
{
  LockType *LockPtr = (LockType *)Handle;
 
  if (Handle == 0)
    return;
 
  // Leave named locks alone, somebody might be using these
  if ((LockPtr->Flags & FLAG_NAMED_LOCK) == 0)
  {
    if (LockPtr->MutexPtr != NULL)
    {
      if (mutex_held(LockPtr->MutexPtr))
        mutex_release (LockPtr->MutexPtr);
      mutex_destroy (LockPtr->MutexPtr);
    }
  }
 
  free (LockPtr);
}

EFI_STATUS InitLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                     OUT LockHandle** LockHandlePtr)
{
   return InitLockInternal (LockStrID, LockHandlePtr, 0);
}

EFI_STATUS InitRecursiveLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                              OUT LockHandle** LockHandlePtr)
{
   return InitLockInternal (LockStrID, LockHandlePtr, LOCK_OPTION_RECURSIVE);
}

VOID AcquireLock (LockHandle* Handle)
{
  LockType *LockPtr = (LockType *)Handle;

  if (Handle == 0)
    return;

  if ((LockPtr->Flags & FLAG_RECURSIVE_LOCK) == 0)
  {
    mutex_acquire (LockPtr->MutexPtr);
    return;
  }

  if (mutex_held(LockPtr->MutexPtr))
  {
    if (LockPtr->NestLevel == 0)
      LockPtr->NestLevel = 1;

    LockPtr->NestLevel++;

    if (LockPtr->MaxNest < LockPtr->NestLevel)
      LockPtr->MaxNest = LockPtr->NestLevel;

    if (LockPtr->NestLevel > 1)
    {
      ++LockPtr->InactivityCnt;
      return;
    }
  }

  mutex_acquire (LockPtr->MutexPtr);
  LockPtr->NestLevel = 1;
}

VOID ReleaseLock (LockHandle* Handle)
{
  LockType *LockPtr = (LockType *)Handle;

  if (Handle == 0)
    return;

  if ((LockPtr->Flags & FLAG_RECURSIVE_LOCK) == 0)
  {
    mutex_release (LockPtr->MutexPtr);
    return;
  }

  if (mutex_held(LockPtr->MutexPtr))
  {
    if (LockPtr->NestLevel == 0)
      while (1);

    --LockPtr->NestLevel;
    if (LockPtr->NestLevel > 0)
      return;
  }
  else
  {
    /* Shouldn't have happened */
    while (1);
  }
  mutex_release (LockPtr->MutexPtr);
}

