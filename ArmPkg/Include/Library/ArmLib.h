/** @file

  Copyright (c) 2015, 2016 Qualcomm Technologies, Inc. All rights reserved.<BR>
  Portions Copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
  Portions Copyright (c) 2011 - 2016, ARM Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __ARM_LIB__
#define __ARM_LIB__

#include <Uefi/UefiBaseType.h>

#ifdef MDE_CPU_ARM
  #include <Chipset/ArmV7.h>
#elif defined(MDE_CPU_AARCH64)
  #include <Chipset/AArch64.h>
#else
 #error "Unknown chipset."
#endif

#define EFI_MEMORY_CACHETYPE_MASK   (EFI_MEMORY_UC | EFI_MEMORY_WC | \
                                     EFI_MEMORY_WT | EFI_MEMORY_WB | \
                                     EFI_MEMORY_UCE)

/**
 * The UEFI firmware must not use the ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_* attributes.
 *
 * The Non Secure memory attribute (ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_*) should only
 * be used in Secure World to distinguished Secure to Non-Secure memory.
 */
typedef enum {
  ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED = 0,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_UNCACHED_UNBUFFERED,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_BACK,

  // On some platforms, memory mapped flash region is designed as not supporting
  // shareable attribute, so WRITE_BACK_NONSHAREABLE is added for such special
  // need.
  // Do NOT use below two attributes if you are not sure.
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK_NONSHAREABLE,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_BACK_NONSHAREABLE,

  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_THROUGH,
  ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE
#if defined (QCOM_EDK2_PATCH)
  ,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH_XN=16,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH_XN_RO,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK_XN,
  ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK_XN_RO,
  ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_UNCACHED_UNBUFFERED_XN,
  ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED_XN,
#endif
} ARM_MEMORY_REGION_ATTRIBUTES;

#define IS_ARM_MEMORY_REGION_ATTRIBUTES_SECURE(attr) ((UINT32)(attr) & 1)

typedef struct {
  EFI_PHYSICAL_ADDRESS          PhysicalBase;
  EFI_VIRTUAL_ADDRESS           VirtualBase;
  UINT64                        Length;
  ARM_MEMORY_REGION_ATTRIBUTES  Attributes;
} ARM_MEMORY_REGION_DESCRIPTOR;

typedef VOID (*CACHE_OPERATION)(VOID);
typedef VOID (*LINE_OPERATION)(UINTN);

//
// ARM Processor Mode
//
typedef enum {
  ARM_PROCESSOR_MODE_USER       = 0x10,
  ARM_PROCESSOR_MODE_FIQ        = 0x11,
  ARM_PROCESSOR_MODE_IRQ        = 0x12,
  ARM_PROCESSOR_MODE_SUPERVISOR = 0x13,
  ARM_PROCESSOR_MODE_ABORT      = 0x17,
  ARM_PROCESSOR_MODE_HYP        = 0x1A,
  ARM_PROCESSOR_MODE_UNDEFINED  = 0x1B,
  ARM_PROCESSOR_MODE_SYSTEM     = 0x1F,
  ARM_PROCESSOR_MODE_MASK       = 0x1F
} ARM_PROCESSOR_MODE;

//
// ARM Cpu IDs
//
#define ARM_CPU_IMPLEMENTER_MASK          (0xFFU << 24)
#define ARM_CPU_IMPLEMENTER_ARMLTD        (0x41U << 24)
#define ARM_CPU_IMPLEMENTER_DEC           (0x44U << 24)
#define ARM_CPU_IMPLEMENTER_MOT           (0x4DU << 24)
#define ARM_CPU_IMPLEMENTER_QUALCOMM      (0x51U << 24)
#define ARM_CPU_IMPLEMENTER_MARVELL       (0x56U << 24)

#define ARM_CPU_PRIMARY_PART_MASK         (0xFFF << 4)
#define ARM_CPU_PRIMARY_PART_CORTEXA5     (0xC05 << 4)
#define ARM_CPU_PRIMARY_PART_CORTEXA7     (0xC07 << 4)
#define ARM_CPU_PRIMARY_PART_CORTEXA8     (0xC08 << 4)
#define ARM_CPU_PRIMARY_PART_CORTEXA9     (0xC09 << 4)
#define ARM_CPU_PRIMARY_PART_CORTEXA15    (0xC0F << 4)

//
// ARM MP Core IDs
//
#define ARM_CORE_AFF0         0xFF
#define ARM_CORE_AFF1         (0xFF << 8)
#define ARM_CORE_AFF2         (0xFF << 16)
#define ARM_CORE_AFF3         (0xFFULL << 32)

#define ARM_CORE_MASK         ARM_CORE_AFF0
#define ARM_CLUSTER_MASK      ARM_CORE_AFF1
#define GET_CORE_ID(MpId)     ((MpId) & ARM_CORE_MASK)
#define GET_CLUSTER_ID(MpId)  (((MpId) & ARM_CLUSTER_MASK) >> 8)
#define GET_MPID(ClusterId, CoreId)   (((ClusterId) << 8) | (CoreId))
#define PRIMARY_CORE_ID       (PcdGet32(PcdArmPrimaryCore) & ARM_CORE_MASK)

UINTN
EFIAPI
ArmDataCacheLineLength (
  VOID
  );

UINTN
EFIAPI
ArmInstructionCacheLineLength (
  VOID
  );

UINTN
EFIAPI
ArmCacheWritebackGranule (
  VOID
  );

UINTN
EFIAPI
ArmIsArchTimerImplemented (
  VOID
  );

UINTN
EFIAPI
ArmReadIdPfr0 (
  VOID
  );

UINTN
EFIAPI
ArmReadIdPfr1 (
  VOID
  );

UINTN
EFIAPI
ArmCacheInfo (
  VOID
  );

BOOLEAN
EFIAPI
ArmIsMpCore (
  VOID
  );

VOID
EFIAPI
ArmInvalidateDataCache (
  VOID
  );


VOID
EFIAPI
ArmCleanInvalidateDataCache (
  VOID
  );

VOID
EFIAPI
ArmCleanDataCache (
  VOID
  );

VOID
EFIAPI
ArmInvalidateInstructionCache (
  VOID
  );

VOID
EFIAPI
ArmInvalidateDataCacheEntryByMVA (
  IN  UINTN   Address
  );

VOID
EFIAPI
ArmCleanDataCacheEntryToPoUByMVA (
  IN  UINTN   Address
  );

VOID
EFIAPI
ArmInvalidateInstructionCacheEntryToPoUByMVA (
  IN  UINTN   Address
  );

VOID
EFIAPI
ArmCleanDataCacheEntryByMVA (
IN  UINTN   Address
);

VOID
EFIAPI
ArmCleanInvalidateDataCacheEntryByMVA (
  IN  UINTN   Address
  );

VOID
EFIAPI
ArmInvalidateDataCacheEntryBySetWay (
  IN  UINTN  SetWayFormat
  );

VOID
EFIAPI
ArmCleanDataCacheEntryBySetWay (
  IN  UINTN  SetWayFormat
  );

VOID
EFIAPI
ArmCleanInvalidateDataCacheEntryBySetWay (
  IN  UINTN   SetWayFormat
  );

VOID
EFIAPI
ArmEnableDataCache (
  VOID
  );

#if defined (QCOM_EDK2_PATCH)
BOOLEAN
EFIAPI
ArmDataCacheEnabled (
  VOID
  );
#endif

VOID
EFIAPI
ArmDisableDataCache (
  VOID
  );

VOID
EFIAPI
ArmEnableInstructionCache (
  VOID
  );

VOID
EFIAPI
ArmDisableInstructionCache (
  VOID
  );

VOID
EFIAPI
ArmEnableMmu (
  VOID
  );

VOID
EFIAPI
ArmDisableMmu (
  VOID
  );

VOID
EFIAPI
ArmEnableCachesAndMmu (
  VOID
  );

VOID
EFIAPI
ArmDisableCachesAndMmu (
  VOID
  );

VOID
EFIAPI
ArmEnableInterrupts (
  VOID
  );

UINTN
EFIAPI
ArmDisableInterrupts (
  VOID
  );

BOOLEAN
EFIAPI
ArmGetInterruptState (
  VOID
  );

VOID
EFIAPI
ArmEnableAsynchronousAbort (
  VOID
  );

UINTN
EFIAPI
ArmDisableAsynchronousAbort (
  VOID
  );

VOID
EFIAPI
ArmEnableIrq (
  VOID
  );

UINTN
EFIAPI
ArmDisableIrq (
  VOID
  );

VOID
EFIAPI
ArmEnableFiq (
  VOID
  );

UINTN
EFIAPI
ArmDisableFiq (
  VOID
  );

BOOLEAN
EFIAPI
ArmGetFiqState (
  VOID
  );

/**
 * Invalidate Data and Instruction TLBs
 */
VOID
EFIAPI
ArmInvalidateTlb (
  VOID
  );

#if defined (QCOM_EDK2_PATCH)
VOID
EFIAPI
ArmInvalidateInstructionAndDataTlb (
  VOID
  );
#endif

VOID
EFIAPI
ArmUpdateTranslationTableEntry (
  IN  VOID     *TranslationTableEntry,
  IN  VOID     *Mva
  );

VOID
EFIAPI
ArmSetDomainAccessControl (
  IN  UINT32  Domain
  );

VOID
EFIAPI
ArmSetTTBR0 (
  IN  VOID  *TranslationTableBase
  );

VOID
EFIAPI
ArmSetTTBCR (
  IN  UINT32 Bits
  );

VOID *
EFIAPI
ArmGetTTBR0BaseAddress (
  VOID
  );

BOOLEAN
EFIAPI
ArmMmuEnabled (
  VOID
  );

VOID
EFIAPI
ArmEnableBranchPrediction (
  VOID
  );

VOID
EFIAPI
ArmDisableBranchPrediction (
  VOID
  );

VOID
EFIAPI
ArmSetLowVectors (
  VOID
  );

VOID
EFIAPI
ArmSetHighVectors (
  VOID
  );

VOID
EFIAPI
ArmDataMemoryBarrier (
  VOID
  );

VOID
EFIAPI
ArmDataSynchronizationBarrier (
  VOID
  );

VOID
EFIAPI
ArmInstructionSynchronizationBarrier (
  VOID
  );

VOID
EFIAPI
ArmWriteVBar (
  IN  UINTN   VectorBase
  );

UINTN
EFIAPI
ArmReadVBar (
  VOID
  );

VOID
EFIAPI
ArmWriteAuxCr (
  IN  UINT32    Bit
  );

UINT32
EFIAPI
ArmReadAuxCr (
  VOID
  );

VOID
EFIAPI
ArmSetAuxCrBit (
  IN  UINT32    Bits
  );

VOID
EFIAPI
ArmUnsetAuxCrBit (
  IN  UINT32    Bits
  );

VOID
EFIAPI
ArmCallSEV (
  VOID
  );

VOID
EFIAPI
ArmCallWFE (
  VOID
  );

VOID
EFIAPI
ArmCallWFI (

  VOID
  );

UINTN
EFIAPI
ArmReadMpidr (
  VOID
  );

UINTN
EFIAPI
ArmReadMidr (
  VOID
  );

UINT32
EFIAPI
ArmReadCpacr (
  VOID
  );

VOID
EFIAPI
ArmWriteCpacr (
  IN  UINT32   Access
  );

VOID
EFIAPI
ArmEnableVFP (
  VOID
  );

/**
  Get the Secure Configuration Register value

  @return   Value read from the Secure Configuration Register

**/
UINT32
EFIAPI
ArmReadScr (
  VOID
  );

/**
  Set the Secure Configuration Register

  @param Value   Value to write to the Secure Configuration Register

**/
VOID
EFIAPI
ArmWriteScr (
  IN  UINT32   Value
  );

UINT32
EFIAPI
ArmReadMVBar (
  VOID
  );

VOID
EFIAPI
ArmWriteMVBar (
  IN  UINT32   VectorMonitorBase
  );

UINT32
EFIAPI
ArmReadSctlr (
  VOID
  );

UINTN
EFIAPI
ArmReadHVBar (
  VOID
  );

VOID
EFIAPI
ArmWriteHVBar (
  IN  UINTN   HypModeVectorBase
  );


//
// Helper functions for accessing CPU ACTLR
//

UINTN
EFIAPI
ArmReadCpuActlr (
  VOID
  );

VOID
EFIAPI
ArmWriteCpuActlr (
  IN  UINTN Val
  );

VOID
EFIAPI
ArmSetCpuActlrBit (
  IN  UINTN    Bits
  );

VOID
EFIAPI
ArmUnsetCpuActlrBit (
  IN  UINTN    Bits
  );

//
// Accessors for the architected generic timer registers
//

#define ARM_ARCH_TIMER_ENABLE           (1 << 0)
#define ARM_ARCH_TIMER_IMASK            (1 << 1)
#define ARM_ARCH_TIMER_ISTATUS          (1 << 2)

UINTN
EFIAPI
ArmReadCntFrq (
  VOID
  );

VOID
EFIAPI
ArmWriteCntFrq (
  UINTN   FreqInHz
  );

UINT64
EFIAPI
ArmReadCntPct (
  VOID
  );

UINTN
EFIAPI
ArmReadCntkCtl (
  VOID
  );

VOID
EFIAPI
ArmWriteCntkCtl (
  UINTN   Val
  );

UINTN
EFIAPI
ArmReadCntpTval (
  VOID
  );

VOID
EFIAPI
ArmWriteCntpTval (
  UINTN   Val
  );

UINTN
EFIAPI
ArmReadCntpCtl (
  VOID
  );

VOID
EFIAPI
ArmWriteCntpCtl (
  UINTN   Val
  );

UINTN
EFIAPI
ArmReadCntvTval (
  VOID
  );

VOID
EFIAPI
ArmWriteCntvTval (
  UINTN   Val
  );

UINTN
EFIAPI
ArmReadCntvCtl (
  VOID
  );

VOID
EFIAPI
ArmWriteCntvCtl (
  UINTN   Val
  );

UINT64
EFIAPI
ArmReadCntvCt (
  VOID
  );

UINT64
EFIAPI
ArmReadCntpCval (
  VOID
  );

VOID
EFIAPI
ArmWriteCntpCval (
  UINT64   Val
  );

UINT64
EFIAPI
ArmReadCntvCval (
  VOID
  );

VOID
EFIAPI
ArmWriteCntvCval (
  UINT64   Val
  );

UINT64
EFIAPI
ArmReadCntvOff (
  VOID
  );

VOID
EFIAPI
ArmWriteCntvOff (
  UINT64   Val
  );

#endif // __ARM_LIB__
