/** @file
  Stub Lock lib Implementation
   
  Copyright (c) 2017, 2019 Qualcomm Technologies Inc. All rights reserved.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 07/24/17   yg      Initial version

=============================================================================*/

#include <Uefi.h>

#include <Library/BaseLib.h>
#include <Library/LockLib.h>

EFI_STATUS InitLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                     OUT LockHandle** LockHandlePtr)
{
  return EFI_UNSUPPORTED;
}

EFI_STATUS InitRecursiveLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                              OUT LockHandle** LockHandlePtr)
{
  return EFI_UNSUPPORTED;
}

VOID DestroyLock (LockHandle* Handle)
{
}

VOID AcquireLock (LockHandle* Handle)
{
}

VOID ReleaseLock (LockHandle* Handle)
{
}

BOOLEAN 
InitLockLib (VOID)
{
  return FALSE;
}

