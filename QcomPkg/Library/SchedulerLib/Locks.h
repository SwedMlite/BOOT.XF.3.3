/** @file
  Simple and Recursive Locks prototypes.
   
  Copyright (c) 2019 Qualcomm Technologies Inc. All rights reserved.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 06/12/19   yg      Initial version

=============================================================================*/

#include <Uefi.h>

#include <Protocol/EFIKernelInterface.h>

EFI_STATUS  InitLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                      OUT LockHandle** LockHandlePtr);

EFI_STATUS  InitRecursiveLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                               OUT LockHandle** LockHandlePtr);

VOID DestroyLock (LockHandle* Handle);

VOID AcquireLock (LockHandle* Handle);

VOID ReleaseLock (LockHandle* Handle);

