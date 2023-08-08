/** @file
 * Lib interface for SMP Kernel protocol interface in UEFI
 *  
 * Copyright (c) 2017 - 2019 Qualcomm Technologies Inc. All rights reserved.
 * 
 * Portions Copyright (c) 2008-2014 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
**/

/*=============================================================================
                              EDIT HISTORY

 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 02/21/18   yg      Initial version

=============================================================================*/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <PiDxe.h>
#include <Library/HobLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/EFIKernelInterface.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/KernelLib.h>

static EFI_KERNEL_PROTOCOL  *KernIntf = NULL;

/********************************************************************************
     Interrupt
********************************************************************************/
VOID RegisterIntrHandler (UINT32 Vector, IntrHandler Handler, VOID *Arg)
{
  if (KernIntf)
    KernIntf->Interrupt->RegisterIntrHandler (Vector, Handler, Arg);
}

KStatus MaskInterrupt (UINT32 Vector)
{
  if (KernIntf)
    return KernIntf->Interrupt->MaskInterrupt (Vector);

  return ERR_NOT_READY;
}

KStatus UnmaskInterrupt (UINT32 Vector)
{
  if (KernIntf)
    return KernIntf->Interrupt->UnmaskInterrupt (Vector);

  return ERR_NOT_READY;
}

KStatus ConfigureInterrupt (UINT32 Vector, enum IntrConfig Config, VOID* Arg)
{
  if (KernIntf)
  {
    if (KernIntf->Version < EFI_KERNEL_PROTOCOL_VER_INTR_CONFIG)
      return ERR_NOT_VALID;
    return KernIntf->Interrupt->ConfigureInterrupt (Vector, Config, Arg);
  }

  return ERR_NOT_READY;
}

/********************************************************************************
     Event
********************************************************************************/
Event* EventInit (OPTIONAL UINT64 Id, BOOLEAN InitialStatus, UINT32 Flags)
{
  if (KernIntf)
    return KernIntf->Event->EventInit (Id, InitialStatus, Flags);

  return 0;
}

VOID EventDestroy (Event *Evt)
{
  if (KernIntf)
    KernIntf->Event->EventDestroy (Evt);
}

BOOLEAN EventInitialized (Event *Evt)
{
  if (KernIntf)
    return KernIntf->Event->EventInitialized (Evt);

  return FALSE;
}

KStatus EventWaitTimeout (Event *Evt, TimeDuration Tm)
{
  if (KernIntf)
    return KernIntf->Event->EventWaitTimeout (Evt, Tm);

  return ERR_NOT_READY;
}

KStatus EventWait (Event *Evt)
{
  if (KernIntf)
    return KernIntf->Event->EventWait (Evt);

  return ERR_NOT_READY;
}

KStatus EventSignal (Event *Evt, BOOLEAN Reschedule)
{
  if (KernIntf)
    return KernIntf->Event->EventSignal (Evt, Reschedule);

  return ERR_NOT_READY;
}

KStatus EventUnsignal (Event *Evt)
{
  if (KernIntf)
    return KernIntf->Event->EventUnsignal (Evt);

  return ERR_NOT_READY;
}

BOOLEAN EventGetSignalState (Event *Evt)
{
  if (KernIntf)
    return KernIntf->Event->EventGetSignalState (Evt);

  return 0;
}

/********************************************************************************
     Mutex
********************************************************************************/
Mutex* MutexInit (OPTIONAL UINT64 Id)
{
  if (KernIntf)
    return KernIntf->Mutex->MutexInit (Id);

  return 0;
}

VOID MutexDestroy (Mutex *Mtx)
{
  if (KernIntf)
    return KernIntf->Mutex->MutexDestroy (Mtx);
}

KStatus MutexAcquire (Mutex *Mtx)
{
  if (KernIntf)
    return KernIntf->Mutex->MutexAcquire (Mtx);

  return ERR_NOT_READY;
}

KStatus MutexAcquireTimeout (Mutex *Mtx, TimeDuration Tm)
{
  if (KernIntf)
    return KernIntf->Mutex->MutexAcquireTimeout (Mtx, Tm);

  return ERR_NOT_READY;
}

KStatus MutexRelease (Mutex *Mtx)
{
  if (KernIntf)
    return KernIntf->Mutex->MutexRelease (Mtx);

  return ERR_NOT_READY;
}

BOOLEAN IsMutexHeld (Mutex *Mtx)
{
  if (KernIntf)
    return KernIntf->Mutex->IsMutexHeld (Mtx);

  return FALSE;
}

/********************************************************************************
     Semaphore
********************************************************************************/

Semaphore* SemInit (OPTIONAL UINT64 Id, UINT32 Cnt)
{
  if (KernIntf)
    return KernIntf->Sem->SemInit (Id, Cnt);

  return 0;
}

VOID SemDestroy (Semaphore * Sem)
{
  if (KernIntf)
    KernIntf->Sem->SemDestroy (Sem);
}

INT32 SemPost (Semaphore * Sem, BOOLEAN Resched)
{
  if (KernIntf)
    return KernIntf->Sem->SemPost (Sem, Resched);

  return ERR_NOT_READY;
}

KStatus SemWait (Semaphore *Sem)
{
  if (KernIntf)
    return KernIntf->Sem->SemWait (Sem);

  return ERR_NOT_READY;
}

KStatus SemTryWait (Semaphore *Sem)
{
  if (KernIntf)
    return KernIntf->Sem->SemTryWait (Sem);

  return ERR_NOT_READY;
}

KStatus SemTimedWait (Semaphore * Sem, TimeDuration Tm)
{
  if (KernIntf)
    return KernIntf->Sem->SemTimedWait (Sem, Tm);

  return ERR_NOT_READY;
}

/********************************************************************************
     Spinlock
********************************************************************************/

Spinlock* SpinLockInit (UINT64 Id OPTIONAL)
{
  if (KernIntf)
    return KernIntf->Spinlock->SpinLockInit (Id);

  return 0;
}

BOOLEAN SpinLockHeld (Spinlock* Spl)
{
  if (KernIntf)
    return KernIntf->Spinlock->SpinLockHeld (Spl);

  return FALSE;
}

INTN SpinTryLock (Spinlock* Spl)
{
  if (KernIntf)
    return KernIntf->Spinlock->SpinTryLock (Spl);

  return ERR_NOT_READY;
}
VOID SpinLock (Spinlock* Spl)
{
  if (KernIntf)
    KernIntf->Spinlock->SpinLock (Spl);
}

VOID SpinUnlock (Spinlock* Spl)
{
  if (KernIntf)
    KernIntf->Spinlock->SpinUnlock (Spl);
}

/********************************************************************************
     Thread
********************************************************************************/

Thread* ThreadCreate (CONST CHAR8 *Name, ThreadStartRoutine Entry, VOID *Arg, INT32 Priority, UINT64 StackSize)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadCreate (Name, Entry, Arg, Priority, StackSize);

  return 0;
}

KStatus ThreadResume (Thread * Thr)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadResume (Thr);

  return ERR_NOT_READY;
}


VOID ThreadExit (INT32 Retcode)
{
  if (KernIntf)
    KernIntf->Thread->ThreadExit (Retcode);
}

Thread* GetCurrentThread (VOID)
{
  if (KernIntf)
    return KernIntf->Thread->GetCurrentThread ();

  return 0;
}

INT32 ThreadGetCurrCpu (Thread* Thr)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadGetCurrCpu (Thr);

  return ERR_NOT_READY;
}

INT32 ThreadGetPinnedCpu (Thread* Thr)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadGetPinnedCpu (Thr);

  return ERR_NOT_READY;
}

VOID ThreadSetCurrCpu (Thread* Thr, INT32 Cpu)
{
  // Not for external consumption..!!
}

VOID ThreadSetPinnedCpu (Thread* Thr, INT32 Cpu)
{
  if (KernIntf)
    KernIntf->Thread->ThreadSetPinnedCpu (Thr, Cpu);
}

VOID ThreadSetName (CONST CHAR8 *Name)
{
  if (KernIntf)
    KernIntf->Thread->ThreadSetName (Name);
}

VOID ThreadSetPriority (INT32 Priority)
{
  if (KernIntf)
    KernIntf->Thread->ThreadSetPriority (Priority);
}

VOID ThreadSleep (TimeDuration Delay)
{
  if (KernIntf)
    KernIntf->Thread->ThreadSleep (Delay);
  else
    gBS->Stall (Delay * 1000);
}

KStatus ThreadDetach (Thread *Thr)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadDetach (Thr);

  return ERR_NOT_READY;
}

KStatus ThreadJoin (Thread *Thr, INT32* Retcode, TimeDuration Timeout)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadJoin (Thr, Retcode, Timeout);

  return ERR_NOT_READY;
}

KStatus ThreadDetachAndResume (Thread *Thr)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadDetachAndResume (Thr);

  return ERR_NOT_READY;
}

ThreadStats* ThreadGetStats (Thread *Thr, ThreadStats* Tsp)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_THR_CPU_STATS)
      return KernIntf->Thread->ThreadGetStats (Thr, Tsp);
    else
      return NULL; // Old Core UEFI image doesn't support real thread stats
  }

  return 0;
}

UINT64 ThreadGetTimeStamp (VOID)
{
  if (KernIntf)
    return KernIntf->Thread->ThreadGetTimeStamp ();

  return 0;
}


/********************************************************************************
     Timer
********************************************************************************/

Timer* TimerInit (VOID)
{
  if (KernIntf)
    return KernIntf->Timer->TimerInit ();

  return 0;
}

VOID TimerSetOneshot (Timer *Tmr, TimeDuration Delay, TimerCallback Cb, VOID *Arg)
{
  if (KernIntf)
    KernIntf->Timer->TimerSetOneshot (Tmr, Delay, Cb, Arg);
}

VOID TimerSetPeriodic (Timer *Tmr, TimeDuration Period, TimerCallback Cb, VOID *Arg)
{
  if (KernIntf)
    KernIntf->Timer->TimerSetPeriodic (Tmr, Period, Cb, Arg);
}

VOID CancelTimer (Timer *Tmr)
{
  if (KernIntf)
    KernIntf->Timer->CancelTimer (Tmr);
}


/********************************************************************************
      MPCore
********************************************************************************/

UINT32 MpcoreGetMaxCpuCount (VOID)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreGetMaxCpuCount ();

  return 1;
}

UINT32 MpcoreGetAvailCpuCount (VOID)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreGetAvailCpuCount ();

  return 1;
}

/* Initialize any cores deferred initialization. Mask can be 0 in which case
 * all defered cores will be initialized, otherwise the cores with mask 0 will
 * not be initialized
 * Returns how many cores got initialized */
UINT32 MpcoreInitDeferredCores (UINT32 CpuMask OPTIONAL)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreInitDeferredCores (CpuMask);

  return 0;
}

UINT32 MpcoreGetCurrCpu (VOID)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreGetCurrCpu ();

  return 0;
}

UINT32 MpcoreIsCpuActive (UINT32 Cpu)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreIsCpuActive (Cpu);

  return 0;
}

UINT32 MpcoreGetActiveMask (VOID)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreGetActiveMask ();

  return 1;
}

UINT32 MpcoreGetOnlineMask (VOID)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreGetOnlineMask ();

  return 1;
}

VOID MpcoreShutdownScheduler (VOID)
{
  if (KernIntf)
    KernIntf->MpCpu->MpcoreShutdownScheduler ();
}

VOID MpcorePowerOffCpu (UINT32 CpuMask)
{
  if (KernIntf)
    KernIntf->MpCpu->MpcorePowerOffCpu (CpuMask);
}

VOID MpcorePowerOnCpu (UINT32 CpuMask)
{
  if (KernIntf)
    KernIntf->MpCpu->MpcorePowerOnCpu (CpuMask);
}

INT32 MpcoreSleepCpu  (UINTN DurationMs)
{
  if (KernIntf)
    return KernIntf->MpCpu->MpcoreSleepCpu (DurationMs);

  return 0;
}

EFI_STATUS RegisterDevicePowerTransitionCallback (PwrTxnNotifyFn CbFn, VOID* Arg)
{
  if (KernIntf)
    return KernIntf->MpCpu->RegisterPwrTransitionNotify (CbFn, Arg);

  return EFI_UNSUPPORTED;
}

EFI_STATUS UnRegisterDevicePowerTransitionCallback (PwrTxnNotifyFn CbFn)
{
  if (KernIntf)
    return KernIntf->MpCpu->UnRegisterPwrTransitionNotify (CbFn);

  return EFI_UNSUPPORTED;
}

CpuSchedStats* MpCoreGetCpuSchedStats (UINT32 Cpu, CpuSchedStats* Csp)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_THR_CPU_STATS)
      return KernIntf->MpCpu->MpcoreGetCpuSchedStats (Cpu, Csp);
    else
      return NULL;
  }

  return 0;
}

/********************************************************************************
      WatchDog
********************************************************************************/
EFI_STATUS WatchDogEnable (VOID)
{
  if (KernIntf)
    return KernIntf->WDog->WdogEnable ();

  return EFI_UNSUPPORTED;
}

VOID WatchDogDisable (VOID)
{
  if (KernIntf)
    KernIntf->WDog->WdogDisable ();
}

EFI_STATUS WatchDogSetBiteTimeout (UINT32 Timeoutms)
{
  if (KernIntf)
    return KernIntf->WDog->WdogSetBiteTimeout (Timeoutms);

  return EFI_UNSUPPORTED;
}

VOID WatchDogForcePet (VOID)
{
  if (KernIntf)
    KernIntf->WDog->WdogForcePet ();
}

VOID WatchDogForceBite (VOID)
{
  if (KernIntf)
    KernIntf->WDog->WdogFirceBite ();
}

EFI_STATUS WatchDogSetPetTimerPeriod (UINT32 TimerPeriodms)
{
  if (KernIntf)
    return KernIntf->WDog->WdogSetPetTimerPeriod (TimerPeriodms);

  return EFI_UNSUPPORTED;
}

/********************************************************************************
      Miscellaneous
********************************************************************************/
UINT32 GetKernelLibVersion (VOID)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LIB_VER_API)
      return KernIntf->GetLibVersion();
    else
      return (1 << 16);  // return version as 1.0
  }

  return 0;
}

/********************************************************************************
      Legacy lock prototypes
********************************************************************************/
#define ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
VOID* InitLegacyLock (OPTIONAL CONST CHAR8 *LockStrID);
VOID* InitLegacyRecursiveLock (OPTIONAL CONST CHAR8 *LockStrID);
VOID  DestroyLegacyLock (VOID* Handle);
VOID  LegacyLock (VOID* Handle);
VOID  LegacyUnLock (VOID* Handle);
#endif

/********************************************************************************
      Simple and Recursive Locks
********************************************************************************/

EFI_STATUS InitLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                     OUT LockHandle** LockHandlePtr)
{
  if (LockHandlePtr == NULL)
    return EFI_INVALID_PARAMETER;
  else
    *LockHandlePtr = NULL;

  if ((KernIntf != NULL) && (KernIntf->Lock != NULL))
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LOCK_API)
    {
      EFI_STATUS Status;
      Status = KernIntf->Lock->InitLock (LockStrID, LockHandlePtr);
      if (Status != EFI_SUCCESS)
        DEBUG ((EFI_D_ERROR, "Lockinit failed %r\r\n", Status));
      return Status;
    }
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    else
    {
      DEBUG ((EFI_D_ERROR, "Running on older version, using local lib for Locks\r\n"));
      *LockHandlePtr = InitLegacyLock (LockStrID);
      if (*LockHandlePtr != NULL)
        return EFI_SUCCESS;
    }
#endif
  }

  return EFI_UNSUPPORTED;
}

EFI_STATUS InitRecursiveLock (IN  CONST CHAR8 *LockStrID   OPTIONAL,
                              OUT LockHandle** LockHandlePtr)
{
  if (LockHandlePtr == NULL)
    return EFI_INVALID_PARAMETER;
  else
    *LockHandlePtr = NULL;

  if ((KernIntf != NULL) && (KernIntf->Lock != NULL))
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LOCK_API)
    {
      EFI_STATUS Status;
      Status = KernIntf->Lock->InitRecursiveLock (LockStrID, LockHandlePtr);
      if (Status != EFI_SUCCESS)
        DEBUG ((EFI_D_ERROR, "Lockinit failed %r\r\n", Status));
      return Status;
    }
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    else
    {
      DEBUG ((EFI_D_ERROR, "Running on older version, using local lib for Locks\r\n"));
      *LockHandlePtr = InitLegacyRecursiveLock (LockStrID);
      if (*LockHandlePtr != NULL)
        return EFI_SUCCESS;
    }
#endif
  }

  return EFI_UNSUPPORTED;
}

VOID DestroyLock (LockHandle* Handle)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LOCK_API)
      return KernIntf->Lock->DestroyLock (Handle);
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    else
    {
      //DEBUG ((EFI_D_ERROR, "Running on older version, using local lib for Locks\r\n"));
      DestroyLegacyLock (Handle);
    }
#endif
  }
}

VOID AcquireLock (LockHandle* Handle)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LOCK_API)
      return KernIntf->Lock->AcquireLock (Handle);
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    else
    {
      LegacyLock (Handle);
    }
#endif
  }
}

VOID ReleaseLock (LockHandle* Handle)
{
  if (KernIntf)
  {
    if (KernIntf->Version >= EFI_KERNEL_PROTOCOL_VER_LOCK_API)
      return KernIntf->Lock->ReleaseLock (Handle);
#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    else
    {
      LegacyUnLock (Handle);
    }
#endif
  }
}

/********************************************************************************
      Setup functions
********************************************************************************/
EFI_STATUS
EFIAPI
KernelLibInit (VOID)
{
  EFI_STATUS Status = EFI_NOT_FOUND;
  
  if (KernIntf != NULL)
    return EFI_SUCCESS;

  Status = gBS->LocateProtocol (&gEfiKernelProtocolGuid, NULL, (VOID **)&KernIntf);

  if ((Status != EFI_SUCCESS) || (KernIntf == NULL))
    DEBUG ((EFI_D_INFO, "Multithreading is NOT enabled\r\n"));

#ifndef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
    if ((Status == EFI_SUCCESS) && (KernIntf != NULL) &&
        (KernIntf->Version < EFI_KERNEL_PROTOCOL_VER_LOCK_API))
      return EFI_NOT_SUPPORTED;
#endif

  /* Return success regardless. We can't have a constructor function fail,
   * which could potentially lead to a crash */
  return EFI_SUCCESS;
}

EFI_KERNEL_PROTOCOL*
GetKernelIntfPtr (VOID)
{
  return KernIntf;
}

/********************************************************************************
      Miscellaneous helper functions
********************************************************************************/
#define SMP_MAX_CPUS      8
static CpuSchedStats OldStats[SMP_MAX_CPUS], CurrStat;
static UINT64 LastTs;

EFI_STATUS GetCpuLoad (UINT32(*CpuLoadArray)[16])
{
  UINT32 CpuCnt, i;
  CpuSchedStats *Csp;
  UINT64 SamplingPeriod, BusyPercent, IdleTime, BusyTime, CurrTs, ActiveCpuMask;

  if (CpuLoadArray == NULL)
    return EFI_INVALID_PARAMETER;

  CpuCnt = MpcoreGetAvailCpuCount();

  ActiveCpuMask = MpcoreGetActiveMask ();

  CurrTs = ThreadGetTimeStamp ();

  for (i = 0; i < CpuCnt; ++i)
  {
    if ((ActiveCpuMask & (1 << i)) == 0)
    {
      (*CpuLoadArray)[i] = 0;
      continue;
    }

    Csp = MpCoreGetCpuSchedStats (i, &CurrStat);

    if (Csp == NULL)
      continue;

    /* Convert accumulated duration to idle since last sample */
    IdleTime = Csp->IdleTime - OldStats[i].IdleTime;
    
    /* Since our last TS is not in sync with when Sched updates the IdleTime
     * we might incur wrong offset based on sampling sequence */
    SamplingPeriod = CurrTs - LastTs;

    BusyTime = (SamplingPeriod - IdleTime) * 100;
    if (SamplingPeriod < IdleTime)
      BusyTime = 0;

    BusyPercent = BusyTime / SamplingPeriod;

    (*CpuLoadArray)[i] = BusyPercent;

    OldStats[i] = *Csp;
  }

  LastTs = CurrTs;

  return EFI_SUCCESS;
}

#ifdef ENABLE_LEGACY_CLIENT_SIDE_LOCK_FUNCTIONS
/********************************************************************************
        TODO: Deprecated Lib functions, Delete after one target generation
********************************************************************************/

#define FLAG_RECURSIVE_LOCK   (1  << 0)
#define FLAG_NAMED_LOCK       (1  << 1)

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

VOID* 
InitLegacyLock (OPTIONAL CONST CHAR8 *LockStrID)
{
  LockType *LockPtr;
  UINT64 LockID;
  Mutex* MLockPtr;
  CONST CHAR8* Sptr = LockStrID;

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
  }

  MLockPtr = MutexInit (LockID);

  if (MLockPtr == NULL)
    return NULL;

  LockPtr = AllocatePool (sizeof(*LockPtr));

  if (LockPtr == 0)
    return LockPtr;

  SetMem (LockPtr, sizeof(*LockPtr), 0);

  LockPtr->Sig = 'L' | ('o' << 8) | ('c' << 16) | ('k' << 24);

  LockPtr->MutexPtr = MLockPtr;

  if (LockID)
    LockPtr->Flags = FLAG_NAMED_LOCK;

  return LockPtr;
}

VOID
DestroyLegacyLock (VOID* Handle)
{
  LockType *LockPtr = (LockType *)Handle;
 
  if (Handle == 0)
    return;
 
  // Leave named locks alone, somebody might be using this actively still
  if ((LockPtr->Flags & FLAG_NAMED_LOCK) == 0)
  {
    if (LockPtr->MutexPtr != NULL)
    {
      if (IsMutexHeld(LockPtr->MutexPtr))
        MutexRelease (LockPtr->MutexPtr);
      MutexDestroy (LockPtr->MutexPtr);
    }
  }
 
  FreePool (LockPtr);
}

VOID* 
InitLegacyRecursiveLock (OPTIONAL CONST CHAR8 *LockStrID)
{
  LockType *LockPtr;

  LockPtr = InitLegacyLock (LockStrID);

  if (LockPtr)
    LockPtr->Flags = LockPtr->Flags | FLAG_RECURSIVE_LOCK;

  return LockPtr;
}

VOID 
LegacyLock (VOID* Handle)
{
  LockType *LockPtr = (LockType *)Handle;

  if (Handle == 0)
    return;

  if ((LockPtr->Flags & FLAG_RECURSIVE_LOCK) == 0)
  {
    MutexAcquire (LockPtr->MutexPtr);
    return;
  }

  if (IsMutexHeld(LockPtr->MutexPtr))
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

  MutexAcquire (LockPtr->MutexPtr);
  LockPtr->NestLevel = 1;
}

VOID 
LegacyUnLock (VOID* Handle)
{
  LockType *LockPtr = (LockType *)Handle;

  if (Handle == 0)
    return;

  if ((LockPtr->Flags & FLAG_RECURSIVE_LOCK) == 0)
  {
    MutexRelease (LockPtr->MutexPtr);
    return;
  }

  if (IsMutexHeld(LockPtr->MutexPtr))
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
  MutexRelease (LockPtr->MutexPtr);
}
#endif

