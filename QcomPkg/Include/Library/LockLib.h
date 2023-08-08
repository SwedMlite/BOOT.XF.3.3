/** @file
  Lock lib to make API's re-entrant
   
  Copyright (c) 2017 - 2019 Qualcomm Technologies Inc. All rights reserved.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 07/16/19   yg      Updated interface
 07/24/17   yg      Initial version

=============================================================================*/

#include <Uefi.h>

#include <Library/BaseLib.h>

#ifndef ___LOCK_LIB_H__
#define ___LOCK_LIB_H__

/********************************************************************************
  This lock lib interface header file only exists to satisfy simplicity of
  dependency for Open source Dxe core sources. Alongwith this header file,
  NULL implementation of LockLib serves as the implementation of this Lib
  interface when the multithreading is disabled.
  This interface should still be kept in sync to the duplicated interface 
  prototypes in KernelLib.h, since KernelLib.h interface supercedes this
  locklib interface.
********************************************************************************/

/* Initialize lock lib, not a must, but the modules that would like to see
 * if the locks are indeed functional can call this API to see if the framework
 * is available.
 *
 * Returns TRUE  : If lock framework is available
 *         FALSE : If the framework is not available, all API's become stubs */
BOOLEAN InitLockLib (VOID);

struct LockType;
typedef struct LockType LockHandle;

/*  NOTE for LockID:
 *
 *  LockStrID of 0 results always into a new private lock. ie lib linked to multiple
 *  images will have NO relation between them, they will have their own each
 *  lock. 0 should be used only for the case where the lock is linked to a lib
 *  that's already guaranteed to have just 1 instance in the system.
 *
 *  LockStrID of non 0 value results into fetching the existing lock in the pool with
 *  the same ID. If a lock with that ID doesn't exist, it will be created, and
 *  any subsequent lock init with same ID will return that lock. This way of
 *  non 0 ID can be used in Lib's that get linked to multiple drivers, thus have
 *  multiple copies of libs in the system, but need a common lock for a shared
 *  resource protection.
 *
 * */

/* Use for any non recursive functions. If the thread tries to lock when it
 * already has locked, would result into crash */
EFI_STATUS  InitLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                      OUT LockHandle** LockHandlePtr);

EFI_STATUS  InitRecursiveLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                               OUT LockHandle** LockHandlePtr);

VOID DestroyLock (LockHandle* Handle);

VOID AcquireLock (LockHandle* Handle);

VOID ReleaseLock (LockHandle* Handle);

/* If lock creation doesn't succeed when multithreading is enabled then
 * return error. When multithreading is disabled, then UNSUPPORTED error
 * return is not real error condition that need to be worried about, in which
 * case all API's would be just stub functions */
#define LOCK_CREATE_FAIL(x)   (((x) != EFI_SUCCESS) && ((x) != EFI_UNSUPPORTED))

#endif  /* ___LOCK_LIB_H__ */
