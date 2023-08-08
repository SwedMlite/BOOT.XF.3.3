/*=============================================================================
 
  File: MDPSystem.c
 
  Source file for MDP functions
  
 
  Copyright (c) 2011-2020 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/
#include <Uefi.h>
#include <scm_sip_interface.h>
#include <Library/UefiLib.h>
#include <Library/ArmLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/PcdLib.h>
#include <Library/PrintLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UncachedMemoryAllocationLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Library/UefiCfgLib.h>
#include <Library/RamPartitionTableLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/GuidedFvLib.h>
#include <Library/KernelLib.h>
#include <Library/OfflineCrashDump.h>
#include <Protocol/EFIHALIOMMUProtocol.h>
#include <Protocol/EFIDDRGetConfig.h>
#include <Protocol/EFIHWIO.h>
#include <Protocol/EFIPIL.h>
#include <Protocol/EFIScm.h>
#include <DDRDetails.h>
#include "MDPSystem.h"
#include "HALhwio.h"
#include "MDPLib_i.h"
#include "MDPSystem.h"
#include "MDPPlatformLib.h"
#include "DisplayUtils.h"
#include "msmhwiobase.h"

/*=========================================================================
     Default Defines
==========================================================================*/
// Maximum debug output string length
#define DISP_MAX_DEBUG_MESSAGE_LENGTH   100

// .DevObjectName for MDP in Settings\SMMU\iort.h
#define MMU_SID_MDP_OBJECT_NAME         "\\_SB_.MDP"

// ARID value for MDP: .SIDMappings[0].InputBase for MDP in Settings\SMMU\iort.h
#define MMU_SID_MDP_ARID                0

/* -----------------------------------------------------------------------
** Types
** ----------------------------------------------------------------------- */

/*=========================================================================
     Local Static Variables
==========================================================================*/

/*=========================================================================
     Local Static Functions
==========================================================================*/
/*
Ramdump enable/disable detection
*/
static bool32 MDP_RamdumpEnabled(void);

/*
Reserved memory allocation
*/
static MDP_Status MDPAllocateReservedMemory(EFIChipInfoFamilyType eChipId, uint64 *pReservedMemoryAddress, uint64 *pReservedMemorySize);

/* Locks used to prevent re-entrance */
static MDP_LockInfo sLockInfo;

/* Flag to set multi thread state */
static bool32 bDisplayMultiThreadded = FALSE;

/* Query number of DDR channels for the platform */
static void GetMaxDDRChannels(uint32 *pNumChannels);

/*=========================================================================
      Public APIs
==========================================================================*/
extern EFI_GUID gQcomTokenSpaceGuid;

/****************************************************************************
*
** FUNCTION: MDP_Log_Message()
*/
/*!
* \brief
*   This function will perform the logging of Debug messages
*
* \param [in] uLogType   - Log level
*        [in] pLogString - Log String
*
* \retval void
*
****************************************************************************/
void MDP_Log_Message(MDP_LogLevel uLogType, char *pLogString, ...)
{
  CHAR8    buffer[DISP_MAX_DEBUG_MESSAGE_LENGTH];
  VA_LIST  marker;
  UINT32   uLogLevel;
  switch (uLogType)
  {
  case MDP_LOGLEVEL_INFO:
    uLogLevel = EFI_D_INFO;
    break;
  case MDP_LOGLEVEL_WARN:
    uLogLevel = EFI_D_WARN;
    break;
  case MDP_LOGLEVEL_ERROR:
  default:
    uLogLevel = EFI_D_ERROR;
    break;
  }
  //
  // Convert the DEBUG() message to a Unicode String
  //
  VA_START (marker, pLogString);
  AsciiVSPrint(buffer, DISP_MAX_DEBUG_MESSAGE_LENGTH, pLogString, marker);
  VA_END (marker);

  DEBUG ((uLogLevel, buffer));
}

/****************************************************************************
*
** FUNCTION: MDP_ReadUnaligned_U32()
*/
/*!
* \brief
* This function reads the uint16 values from aligned boundary and packs them into uint32
*
* if pSrc is at offset of 1 or 3 from the uint32 aligned address
*            reads uint16 from aligned (pSrc -1) address and extracts the LSB 
*            reads next uint16 addresses and 
*            reads the next +1 uint16 address and extracts the MSB
*            Packs these into uint32 pDest address
*
*if pSrc is at offset 2 from the the uint32 aligned address
*            reads uint16 from aligned (pSrc -1) address 
*            reads next uint16 addresses 
*            Packs these into uint32 pDest addr
*
* Otherwise pSrc is on aligned address boundary

*
* \param [in] pDest   - pointer to Uint32
*        [in] pSrc    - pointer to Uint8 
*
* \retval void
*
****************************************************************************/
void MDP_ReadUnaligned_U32(uint32 *pDest, uint8 * pSrc)
{
    // if pSrc is at offset of 1 or 3 from the uint32 aligned address
    if (0 != ((UINTN)pSrc & 0x1) ) 
    {
        uint16 *pTemp = (uint16*)((uint8 *)(pSrc) - 1); 

         // Pack these into uint32 pDest address
        *pDest = (uint8)(*(pTemp + 2) &  0xff) << 24 | (uint16)(*(pTemp + 1) << 16) | (uint8)(*pTemp >> 8); 
    } 
    // if pSrc is at offset 2 from the the uint32 aligned address
    else if (0 != ((UINTN)(pSrc) & 0x2) )
    { 
       uint16 *pTemp = (uint16*)pSrc; 

       // Packs these into uint32 pDest addr
       *pDest =((uint16)*(pTemp + 1) << 16) | (uint16)*pTemp ;
    }
    // Otherwise pSrc is on aligned address boundary
    else 
    {
        *pDest = *(uint32 *)pSrc; 
    }
}


/****************************************************************************
*
** FUNCTION: MDP_OSAL_MB()
*/
/*!
* \brief
*   This function creates a hardware memory barrier (fence) that prevents the CPU from 
*  re-ordering read and write operations.
*
* \param void
*        
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_MB(void)
{
    ArmDataMemoryBarrier();
}


/****************************************************************************
*
** FUNCTION: MDP_OSAL_MB_Ex()
*/
/*!
* \brief
*   Flush cache lines
*
* \param [in] pBuffer       - Pointer to block of memory allocated
* \param [in] uBufferSize   - memory size
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_MB_Ex(void* pBuffer, uint32 uBufferSize)
{
    ArmDataMemoryBarrier();  /* same as MB */
}


/****************************************************************************
*
** FUNCTION: MDP_SetFirmwareEnvironmentVariable()
*/
/*!
* \brief
*   Program the platform environment variable
*
* \param [in] pVariableNpFirmwareEnvInfoame - Environment variable 
*
* \retval MDP_STATUS_OK on success
*
****************************************************************************/
MDP_Status MDP_SetFirmwareEnvironmentVariable(void *pValue, UINT32 uSize)
{
  MDP_Status    eStatus            = MDP_STATUS_OK;
  EFI_GUID      sOutputGUID        = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  const CHAR16  sPlatformEnvName[] = L"UEFIDisplayInfo";

  
  if (EFI_SUCCESS != gRT->SetVariable((CHAR16*)&sPlatformEnvName, &sOutputGUID,
                                      EFI_VARIABLE_RUNTIME_ACCESS | EFI_VARIABLE_BOOTSERVICE_ACCESS,
                                      uSize,
                                      (void*)pValue))
  {
    DEBUG ((EFI_D_WARN, "MDPSystem: Failed to update UEFI Environment variable (UEFIDisplayInfo)!\n"));  
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDP_GetEnvironmentVariable()
*/
/*!
* \brief
*   Helper to retrieve a system environment variable.
*
* \param [in]  pVariableName - Environment variable name
*        [out] pValue        - Variable storage
*        [in]  uSize         - Size of the environment variable
*
* \retval MDP_STATUS_OK on success
*
****************************************************************************/
MDP_Status MDP_GetEnvironmentVariable(CHAR16 *pVariableName, void *pValue, UINT32 uSize)
{
  MDP_Status eStatus      = MDP_STATUS_OK;
  UINT32     uAttributes  = 0;
  UINT8      uStorage[MDP_OSAL_MAX_ENVVAR_SIZE];
  UINTN      uStorageSize = MDP_OSAL_MAX_ENVVAR_SIZE;  

  if (uSize > MDP_OSAL_MAX_ENVVAR_SIZE)
  {
   eStatus = MDP_STATUS_FAILED;  
  }
  else if (EFI_SUCCESS == gRT->GetVariable((CHAR16*)pVariableName, 
                                      &gQcomTokenSpaceGuid,
                                      &uAttributes,
                                      (UINTN*)&uStorageSize,
                                      (void*)uStorage))
  {
    MDP_OSAL_MEMCPY(pValue, &uStorage, uSize);
  }
  else
  {
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_GetBootServiceVariableSize()
*/
/*!
* \brief
*   Helper to retrieve data size for system variable from the QcomTokenSpace GUID.
*
* \param [in]  pVariableName - Environment variable name
*        [out] puSize        - Size of the environment variable
*
* \retval EFI_STATUS
*
****************************************************************************/
EFI_STATUS MDP_GetBootServiceVariableSize(CHAR16 *pVariableName, UINTN *puSize)
{
  void       *pValue       = NULL;
  UINTN       uSize        = 0;
  EFI_STATUS  eStatus;

  if ((NULL == pVariableName) ||
      (NULL == puSize))
  {
    eStatus = EFI_INVALID_PARAMETER;
  }
  else
  {
    /* 
    * GetVariable call with NULL pointer for data will return the actual size
    * and EFI_BUFFER_TOO_SMALL error, if the variable exists
    */
    eStatus = gRT->GetVariable(pVariableName, 
                              &gQcomTokenSpaceGuid,
                               0,
                              &uSize,
                               pValue);

    if (EFI_BUFFER_TOO_SMALL == eStatus)
    {
      /* This is the expected result. Set the size and update return status */
      *puSize = uSize;
      eStatus = EFI_SUCCESS;
    }
    else
    {
      DEBUG((EFI_D_INFO, "MDPSystem: Failed to get size for variable <%s>. Error: %r\n", pVariableName, eStatus));
    }
    
  }
  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_GetBootServiceVariable()
*/
/*!
* \brief
*   Helper to retrieve a system environment variable from the QcomTokenSpace GUID.
*
* \param 
*        [in]   pVariableName - Environment variable name
*        [out]  pValue        - Variable storage
*        [out]  uSize         - Size of the environment variable
*
* \retval EFI_STATUS
*
****************************************************************************/
EFI_STATUS MDP_GetBootServiceVariable(CHAR16 *pVariableName, void *pValue, UINTN *puSize)
{
  UINT32     uAttributes  = 0;
  EFI_STATUS eStatus;

  if ((NULL == pVariableName) ||
      (NULL == pValue)        ||
      (NULL == puSize))
  {
    DEBUG((EFI_D_ERROR, "MDPSystem: Null parameter\n"));
    eStatus = EFI_INVALID_PARAMETER;
  }
  else if (EFI_SUCCESS != (eStatus = gRT->GetVariable(pVariableName,
                                                     &gQcomTokenSpaceGuid,
                                                     &uAttributes,
                                                      puSize,
                                                      pValue)))
  {
    /* No error message if variable not found */
    if (EFI_NOT_FOUND != eStatus)
    {
      DEBUG((EFI_D_WARN, "MDPSystem: Failed to get variable <%s>. Error: %r\n", pVariableName, eStatus));
    }
  }

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDP_SetBootServiceVariable()
*/
/*!
* \brief
*   Helper to set a system environment variable using the QcomTokenSpace GUID.
*
* \param [in]  pVariableName - Environment variable name
*        [in]  pValue        - Variable storage
*        [in]  uSize         - Size of the environment variable
*        [in]  uFlags        - the MDP variable flags
*
* \retval EFI_STATUS
*
****************************************************************************/
EFI_STATUS MDP_SetBootServiceVariable(CHAR16 *pVariableName, void *pValue, UINTN uSize, UINT32 uFlags)
{
  EFI_STATUS eStatus     = EFI_SUCCESS;
  UINT32     uAttributes = 0;

  if ((NULL == pVariableName) ||
      (NULL == pValue))
  {
    DEBUG((EFI_D_WARN, "MDPSystem: Null parameter\n"));
    eStatus = EFI_INVALID_PARAMETER;
  }
  else
  {
    uAttributes = EFI_VARIABLE_RUNTIME_ACCESS | EFI_VARIABLE_BOOTSERVICE_ACCESS;

    if (uFlags & MDP_VARIABLE_FLAG_NON_VOLATILE)
    {
      uAttributes |= EFI_VARIABLE_NON_VOLATILE;
    }

    if (EFI_SUCCESS != (eStatus = gRT->SetVariable(pVariableName,
                                                  &gQcomTokenSpaceGuid,
                                                   uAttributes,
                                                   uSize,
                                                   pValue)))
    {
      DEBUG((EFI_D_WARN, "MDPSystem: Failed to set variable <%s>. Error: %r\n", pVariableName, eStatus));
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_GetDDRType()
*/
/*!
* \brief
*   retrieve DDR details info from system
*
* \retval UINT32
*
****************************************************************************/
UINT32 MDP_GetDDRType(void)
{
  EFI_DDRGETINFO_PROTOCOL      *pDDRProtocol = NULL;
  ddr_details_entry             sDDRDetails;
  UINT32                        uDDRType = 0;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiDDRGetInfoProtocolGuid, NULL, (void **)&pDDRProtocol))
  {
    DEBUG((EFI_D_WARN, "MDP_GetDDRType: Unable to locate DDRGETINFO protocol.\n"));
  }
  else
  {
    if (EFI_SUCCESS != pDDRProtocol->GetDDRDetails(pDDRProtocol, &sDDRDetails)) 
    {
      DEBUG((EFI_D_WARN, "MDP_GetDDRType: Unable to get DDR Details\n"));
    }
    else
    {
      if (sDDRDetails.device_type == DDR_TYPE_LPDDR1)
      {
          uDDRType = 1;
      }
      else if ((sDDRDetails.device_type == DDR_TYPE_LPDDR2) ||
               (sDDRDetails.device_type == DDR_TYPE_PCDDR2))
      {
          uDDRType = 2;
      }     
      else if ((sDDRDetails.device_type == DDR_TYPE_LPDDR3) ||
               (sDDRDetails.device_type == DDR_TYPE_PCDDR3))
      {
          uDDRType = 3;
      }   
      else if ((sDDRDetails.device_type == DDR_TYPE_LPDDR4) ||
               (sDDRDetails.device_type == DDR_TYPE_LPDDR4X))
      {
          uDDRType = 4;
      }        
      else if ((sDDRDetails.device_type == DDR_TYPE_LPDDR5) ||
               (sDDRDetails.device_type == DDR_TYPE_LPDDR5X))
      {
          uDDRType = 5;
      }
    }
  }

  return uDDRType;
}

/****************************************************************************
*
** FUNCTION: MDP_SetupMMUSIDs()
*/
/*!
* \brief
*   Helper to program Display MMU SID to bypass
*
* \param uMMuSidMask : Platform MMU Sid mask
*
* \retval MDP_STATUS_OK on success
*
****************************************************************************/
MDP_Status MDP_SetupMMUSIDs(uint32 uMMUSidMask)
{
  MDP_Status                   eStatus        = MDP_STATUS_FAILED;
  EFI_HAL_IOMMU_PROTOCOL      *pIOMMUProtocol = NULL;
  HAL_IOMMU_fptable_t         *pSMMUTable     = NULL;
  void                        *pMDPDomain     = NULL;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiHalIommuProtocolGuid, NULL, (void **)&pIOMMUProtocol))
  {
    DEBUG((EFI_D_WARN, "MDPLib: Unable to locate IOMMU protocol.\n"));
  }
  else
  {
    pIOMMUProtocol->_HAL_IOMMU_protocol_init((HAL_IOMMU_fptable_t **)&pSMMUTable);
    if (NULL == pSMMUTable) {
      DEBUG((EFI_D_WARN, "MDPLib: Unable to initialize IOMMU protocol.\n"));
    }
    else if (HAL_IOMMU_ERR_OK != pSMMUTable->domain_create_func(&pMDPDomain))
    {
      DEBUG((EFI_D_WARN, "MDPLib: Unable to create domain in IOMMU\n"));
    }
    else if (HAL_IOMMU_ERR_OK != pSMMUTable->config_bypass_domain_func(pMDPDomain,
                                                                       HAL_IOMMU_AARCH64_NON_CCA_DOMAIN_TYPE))
    {
      DEBUG((EFI_D_WARN, "MDPLib: Unable to configure bypass domain in IOMMU\n"));
    }
    else if (HAL_IOMMU_ERR_OK != pSMMUTable->domain_attach_func(pMDPDomain,
                                                                (void *) MMU_SID_MDP_OBJECT_NAME,
                                                                MMU_SID_MDP_ARID,
                                                                uMMUSidMask))
    {
      DEBUG((EFI_D_WARN, "MDPLib: Unable to attach MDP to IOMMU\n"));
    }
    else
    {
      eStatus = MDP_STATUS_OK;
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_MDSS_HWIOBaseAddr()
*/
/*!
* \brief
*   Retrieve MDSS base Address
*
* \retval MDSS HWIO base address
*
****************************************************************************/
uintPtr MDP_MDSS_HWIOBaseAddr(EFIChipInfoFamilyType  sEFIChipSetFamily)
{
   uint32               eStatus  = MDP_STATUS_OK;
   uint32              *pVirtAddr = 0;
   EFI_HWIO_PROTOCOL   *HWIOProtocol;

   eStatus = gBS->LocateProtocol(&gEfiHwioProtocolGuid, NULL, (void**)&HWIOProtocol);
   if ((EFI_SUCCESS != eStatus) || 
       (HWIOProtocol == NULL))
   {
      DEBUG ((EFI_D_ERROR, "ERROR: Failed to locate HWIO Protocol: Status=%d\n", eStatus));
   }
   else
   {
      eStatus = HWIOProtocol->MapRegion(HWIOProtocol, "MDSS", (UINT8**) &pVirtAddr);
      if (EFI_SUCCESS != eStatus)
      {
        DEBUG ((EFI_D_ERROR, "ERROR: Failed to map MDSS base address: Status=%d\n", eStatus));
      }
   }
   return (uintPtr)pVirtAddr;
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_MEMZERO()
*/
/*!
* \brief
*   Fills a target buffer with 0 value
*
* \param [in] pBuffer   - The memory to set
*        [in] uLength   - The number of bytes to set
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_MEMZERO(void *pBuffer, UINTN uLength)
{
  gBS->SetMem(pBuffer, uLength, 0x0);
}


/****************************************************************************
*
** FUNCTION: MDP_OSAL_MEMCPY()
*/
/*!
* \brief
*   Copies a source buffer to a destination buffer
*
* \param [in] pDest   - The pointer to the destination buffer of the memory copy
*        [in] pSrc    - The pointer to the source buffer of the memory copy.
*        [in] uLength - The number of bytes to copy from SourceBuffer to DestinationBuffer.

*
* \retval void
*
****************************************************************************/
void MDP_OSAL_MEMCPY(void *pDest, void *pSrc, UINTN uLength)
{
  CopyMem(pDest, pSrc, uLength);
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_MEMSET()
*/
/*!
* \brief
*   Fills a target buffer with a byte value
*
* \param [in] pBuffer - The memory to set
*        [in] uLength - The number of bytes to set
*        [in] uValue  - The value with which to fill Length bytes of Buffer
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_MEMSET(void  *pBuffer,  UINT8  uValue, UINTN  uLength)
{
  gBS->SetMem(pBuffer, uLength, uValue);
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_CALLOC()
*/
/*!
* \brief
*   Allocate memory from local heap
*
* \param [in] uLength   - Requested size of memory to be allocated
*
* \retval point to the block of allocated memory
*
****************************************************************************/
void* MDP_OSAL_CALLOC(UINTN uLength)
{
  return UncachedAllocateZeroPool(uLength);
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_FREE()
*/
/*!
* \brief
*   Free allocated memory from local heap
*
* \param [in] pBuffer   - Pointer to block of memory allocated
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_FREE(void* pBuffer)
{
  UncachedSafeFreePool(pBuffer);
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_DELAYMS()
*/
/*!
* \brief
*   This function will sleep for a given time in milliseconds
*
* \param [in] uDelayMs   - Sleep time in milliseconds
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_DELAYMS(UINTN uDelayMs)
{
  if (TRUE == bDisplayMultiThreadded)
  {
    ThreadSleep (uDelayMs);
  }
  else
  {
    gBS->Stall((uint32)(uDelayMs)* 1000);
  }
}


/****************************************************************************
*
** FUNCTION: MDP_OSAL_DELAYUS()
*/
/*!
* \brief
*   This function will sleep for a given time in microsecond
*
* \param [in] uDelayUs   - Sleep time in microsecond
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_DELAYUS(UINTN uDelayUs)
{
  gBS->Stall((uint32)(uDelayUs));
}


/****************************************************************************
*
** FUNCTION: MDP_SaveFirmwareEnvironmentVariable()
*/
/*!
* \brief
*   This function will save display info into UEFI environment variable
*
* \param [in] eDisplayId        - Display ID
*
* \retval void
*
****************************************************************************/
MDP_Status MDP_SaveFirmwareEnvironmentVariable(MDP_Display_IDType eDisplayId)
{
  MDP_Status          eStatus          = MDP_STATUS_OK;
  MDP_Panel_AttrType *pDisplayInfo     = MDP_GET_DISPLAYINFO(eDisplayId);
  MDPSurfaceInfo     *pFrameBufferInfo = &pDisplayInfo->sFrameBuffer;
  uint32              uBacklightLevel  = pDisplayInfo->uBacklightLevel;
  MDPPlatformParams   sPlatformParams;

  if (MDP_STATUS_OK == (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_GETPLATFORMINFO, &sPlatformParams)))
  {
    UINT32                      FrameBufferSize       = 0;
    UINT8                       uHighestBankBit       = 0;           // 0 is defined to be error value with GFX
    UINT32                      uMaxDDRChannels       = 0;           // 0 is defined to be error value 
    CHAR8*                      MemLabel              = "Display Reserved";
    MemRegionInfo               DisplayMemRegionInfo;
    MDPFirmwareEnvType          sFirmwareEnvInfo;
    DisplaySplashBufferInfoType sSplashInfo;
    EFI_STATUS Status;
    
    MDP_OSAL_MEMZERO(&sFirmwareEnvInfo, sizeof(MDPFirmwareEnvType));
    MDP_OSAL_MEMZERO(&sSplashInfo, sizeof(DisplaySplashBufferInfoType));

    // Get the Display region.
    Status = GetMemRegionInfoByName(MemLabel, &DisplayMemRegionInfo);
    if (Status != EFI_SUCCESS)
    {
      DEBUG((EFI_D_WARN, "MDPLib: Could not find the Display memory region. Defaulting to 8MB.\n"));
      FrameBufferSize = 0x00800000; /* Default to 8MB */
    }
    else
    {
      FrameBufferSize = DisplayMemRegionInfo.MemSize;
    }

    if (EFI_SUCCESS != (Status = GetHighestBankBit(&uHighestBankBit)))
    {
      DEBUG((EFI_D_WARN, "MDPLib: GetHighestBankBit failed.\n"));
    }

#if 0 // Enable this block once GetMaxDDRChannels is available in RamPartitionLib
    if (EFI_SUCCESS != (Status = GetMaxDDRChannels(&uMaxDDRChannels)))
    {
      //Set it to 0 to use default value
      uMaxDDRChannels = 0;
      DEBUG((EFI_D_WARN, "MDPLib: GetMaxDDRChannels failed.\n"));
    }
#endif

    // Populate firmware environment information
    sFirmwareEnvInfo.uVersionInfo = (MDP_FIRMWARE_ENV_VERSION_MAGIC << 16) |
                                    (MDP_FIRMWARE_ENV_VERSION_MAJOR << 8) |
                                    (MDP_FIRMWARE_ENV_VERSION_MINOR);
    sFirmwareEnvInfo.uPlatformId      = sPlatformParams.sPlatformInfo.sEFIPlatformType.platform;
    sFirmwareEnvInfo.uChipsetId       = sPlatformParams.sPlatformInfo.sEFIChipSetId;
    sFirmwareEnvInfo.uPlatformVersion = 0; // Reserved
                                           // Frame buffer information comes from the currently cached frame buffer
    sFirmwareEnvInfo.uFrameBufferAddress      = (UINTN)pFrameBufferInfo->pPlane0Offset;
    // We report the frame buffer size as the carve out memory size which is sum of PcdFrameBufferSize and PcdHDMISize
    sFirmwareEnvInfo.uFrameBufferSize         = FrameBufferSize;
    sFirmwareEnvInfo.uFrameBufferPixelDepth   = (8 * pFrameBufferInfo->uPlane0Stride) / pFrameBufferInfo->uWidth;
    sFirmwareEnvInfo.uFrameBufferImagePxWidth = pFrameBufferInfo->uWidth;
    sFirmwareEnvInfo.uFrameBufferImagePxHeight= pFrameBufferInfo->uHeight;
    sFirmwareEnvInfo.uFrameBufferImageStride  = pFrameBufferInfo->uPlane0Stride;
    sFirmwareEnvInfo.uHighestBankBit          = uHighestBankBit;
    sFirmwareEnvInfo.uMaxDDRChannels          = uMaxDDRChannels;

    // Populate panel information
    if (MDP_SUPPORTED_DISPLAY(eDisplayId))
    {
      // Allocate any required reserved regions, if not allocated already.
      if (0 == pDisplayInfo->uReservedAllocationSize)
      {
        if (MDP_STATUS_OK == MDPAllocateReservedMemory(sPlatformParams.sPlatformInfo.sEFIChipSetFamily, &sFirmwareEnvInfo.uReservedMemoryAddress, &sFirmwareEnvInfo.uReservedMemorySize))
        {
          // Keep track of the allocation size so we don't allocate it again
          pDisplayInfo->uReservedAllocationSize = sFirmwareEnvInfo.uReservedMemorySize;
        }
        else
        {
          // Reset values on failure.
          sFirmwareEnvInfo.uReservedMemoryAddress = 0x0;
          sFirmwareEnvInfo.uReservedMemorySize    = 0x0;
        }
      }
    }

    // If panel configuration has provided the panel id, then override panel id with this value
    // This is required when panel supports multiple modes with same panel id, by overriding 
    // the panel id for a particular configuration HLOS can identify that specifc mode of panel
    if (MDP_DISPLAY_PRIMARY == eDisplayId)
    {
      sFirmwareEnvInfo.uPrimaryPanelId               = (0 != pDisplayInfo->uPanelId) ? pDisplayInfo->uPanelId : sPlatformParams.sPlatformInfo.uPrimaryPanelId;
      sFirmwareEnvInfo.uPrimaryPanelFlags            = MDP_FIRMWARE_ENV_FLAG_DISPLAY_INITIALIZED;
      sFirmwareEnvInfo.uPrimaryPanelBacklightLevel   = uBacklightLevel;
    }
    else if (MDP_DISPLAY_SECONDARY == eDisplayId)
    {
      sFirmwareEnvInfo.uSecondaryPanelId             = (0 != pDisplayInfo->uPanelId) ? pDisplayInfo->uPanelId : sPlatformParams.sPlatformInfo.uPrimaryPanelId;
      sFirmwareEnvInfo.uSecondaryPanelFlags          = MDP_FIRMWARE_ENV_FLAG_DISPLAY_INITIALIZED;
      sFirmwareEnvInfo.uSecondaryPanelBacklightLevel = uBacklightLevel;
    }

    eStatus = MDP_SetFirmwareEnvironmentVariable(&sFirmwareEnvInfo, sizeof(sFirmwareEnvInfo));

    //Set frame buffer variable for ABL
    sSplashInfo.uVersion   = DISPLAY_SPLASH_BUFFER_INFO_TYPE_VERSION;
    sSplashInfo.uFrameAddr = (UINTN)pFrameBufferInfo->pPlane0Offset;
    sSplashInfo.uFrameSize = FrameBufferSize - MDP_MAX_PLLCODES_SIZE;

    //Save the info in Display ABL
    Display_Utils_SetContinuousSplashInfo(sSplashInfo.uFrameAddr, sSplashInfo.uFrameSize);

    MDP_SetBootServiceVariable(DISPVAR_SPLASH_BUFFER_INFO, &sSplashInfo, sizeof(sSplashInfo), 0);
    
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDPAcquireLockOrFail()
*/
/*!
* \brief
*   This function will try to get the specified lock.
*
* The function will acquire the lock if not already acquired
* It will return FAIL if lock is already acquired
*
* \param  eLock              - Lock to acquire
*
* \retval MDP_STATUS_OK      - Lock acquired successfully
* \retval MDP_STATUS_FAILED  - Failed to acquire Lock
*
****************************************************************************/
MDP_Status  MDPAcquireLockOrFail(MDP_Lock_Type eLock)
{
  MDP_Status eStatus = MDP_STATUS_OK;

  if (MDP_LOCK_TYPE_MAX <= eLock)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    volatile uint32 *pLock = &sLockInfo.uLock[eLock];

    if (*pLock)
    {
      // Failed to acquire lock
      eStatus = MDP_STATUS_FAILED;
    }
    else
    {
      *pLock = 1;
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDPReleaseLock()
*/
/*!
* \brief
*   This function will release the specified lock.
*
* \param  eLock          - Lock to release
*
* \retval MDP_STATUS_OK  - Lock released successfully
*
****************************************************************************/
MDP_Status  MDPReleaseLock(MDP_Lock_Type eLock)
{
  MDP_Status eStatus = MDP_STATUS_OK;

  if (MDP_LOCK_TYPE_MAX <= eLock)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    volatile uint32 *pLock = &sLockInfo.uLock[eLock];

    // Always be able to release
    *pLock = 0;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_GetConfigValue()
*/
/*!
* \brief
*   Get config value created by parsing the platform config file
*
* \param [in] Key         - Pointer to ASCII parameter to search for in config file
*        [in] Value       - On input pointer to buffer used to return value
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_GetConfigValue(IN CHAR8* Key, IN OUT UINT32* Value)
{
  MDP_Status eStatus = MDP_STATUS_OK;

  if (EFI_SUCCESS != GetConfigValue(Key, Value))
  {
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_GetTimerCountMS()
*/
/*!
* \brief
*    Running time in mS based on the Arch Timer Counter.
*    This could get wrapped around based on the resolution and Speed.So
*    use with caution.
*    If the Timer is 32 bit running at 19.2 MHz, it would wrap around, to 0
*    after 223 Sec
*
* \param NONE  - Log level
*
* \retval Timer count
*
****************************************************************************/
UINT32  MDP_GetTimerCountMS(void)
{
  return GetTimerCountms();
}

/****************************************************************************
*
** FUNCTION: MDP_GetTimerCountUS()
*/
/*!
* \brief
*    Running time in uS based on the Arch Timer Counter.
*    This could get wrapped around based on the resolution and Speed.So
*    use with caution.
*    If the Timer is 32 bit running at 19.2 MHz, it would wrap around, to 0
*    after 223 Sec
*
* \param NONE  - Log level
*
* \retval Timer count
*
****************************************************************************/
UINT32     MDP_GetTimerCountUS(void)
{
  return GetTimerCountus();
}

/****************************************************************************
*
** FUNCTION: MDP_SetMultiThreadState()
*/
/*!
* \brief
*   This function will set multithreadded state to be enabled or not.
*
* \param [in]  bEnable            - Multithreadded state.
*
* \retval None
*
****************************************************************************/
MDP_Status MDP_SetMultiThreadState(bool32 bEnable)
{
  MDP_Status  eStatus          = MDP_STATUS_OK;
  UINT32      uMultiThreadded  = 0;

  if (EFI_SUCCESS != GetConfigValue ("EnableDisplayThread", &uMultiThreadded))
  {
    eStatus = MDP_STATUS_NOT_SUPPORTED;
  }
  else if (0 == uMultiThreadded)
  {
    eStatus = MDP_STATUS_NOT_SUPPORTED;
  }
  else
  {
    bDisplayMultiThreadded = bEnable;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_Display_SetVariable()
*/
/*!
* \brief
*   Function to set the display variable.
*
  @param[in]  pVariableName              The variable name that need to set.
  @param[in]  pVariableValue             The variable value.
  @param[in]  uDataLength                The length of the variable value.
  @param[in]  uFlags                     The flag to set variable.
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_Display_SetVariable(CHAR16 *pVariableName, UINT8 *pVariableValue, UINTN uDataLength, UINTN uFlags)
{
  MDP_Status  eStatus = MDP_STATUS_OK;

  if (EFI_SUCCESS != Display_Utils_SetVariable(pVariableName, pVariableValue, uDataLength, uFlags))
  {
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_Display_GetVariable()
*/
/*!
* \brief
*   Function to get the display variable.
*
  @param[in]   pVariableName              The variable name that need to get.
  @param[out]  pVariableValue             The variable value.
  @param[out]  pDataLength                The length of the variable value.
  @param[in]   uFlags                     The flag to get variable.
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_Display_GetVariable(CHAR16 *pVariableName, UINT8 *pVariableValue, UINTN *pDataLength, UINTN uFlags)
{
  MDP_Status  eStatus = MDP_STATUS_OK;

  if (EFI_SUCCESS != Display_Utils_GetVariable(pVariableName, pVariableValue, pDataLength, uFlags))
  {
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_Display_SetVariable_Integer()
*/
/*!
* \brief
*   Function to set the display variable.
*
  @param[in]  pVariableName              The variable name that need to set.
  @param[in]  uVariableValue             The variable value.
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_Display_SetVariable_Integer(CHAR16 *pVariableName, UINT32 uVariableValue)
{
  MDP_Status  eStatus       = MDP_STATUS_OK;
  CHAR8       VarValue[64]  =  "";

  AsciiSPrint (VarValue, sizeof(VarValue), "%x", uVariableValue);

  if (EFI_SUCCESS  != Display_Utils_SetVariable(pVariableName, (UINT8 *)VarValue, AsciiStrLen (VarValue), 0))
  {
    eStatus = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_Display_GetVariable_Integer()
*/
/*!
* \brief
*   Function to get the display variable.
*
  @param[in]   pVariableName              The variable name that need to get.
  @param[out]  pVariableValue             The variable value.
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_Display_GetVariable_Integer(CHAR16 *pVariableName, UINT32 *pVariableValue)
{
  MDP_Status  eStatus       = MDP_STATUS_OK;
  CHAR8       VarValue[64]  =  "";
  UINTN       uVarLength    =  sizeof(VarValue) / sizeof(CHAR8);

  if ((EFI_SUCCESS  == Display_Utils_GetVariable(pVariableName, (UINT8 *)VarValue, &uVarLength, 0)) &&
      (uVarLength  > 0))
  {
    *pVariableValue = AsciiStrHexToUintn(VarValue);
  }
  else
  {
    *pVariableValue = 0;
    eStatus         = MDP_STATUS_FAILED;
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDP_MountFv()
*/
/*!
* \brief
*   Mount fv for display.
*
* \param [in]  gFvNameGuid        - The fv name guid
*        [in]  pFvName            - The fv name
*
* \retval EFI_STATUS
*
****************************************************************************/
EFI_STATUS MDP_MountFv(EFI_GUID gFvNameGuid, CHAR16 *pFvName)
{
  EFI_STATUS         eStatus       = EFI_SUCCESS;
  EFI_PIL_PROTOCOL  *pPILProtocol  = NULL;

  if (GuidedFvIsMounted(&gFvNameGuid))
  {
    // Do nothing here if imagefv is already mounted.
  }
  else
  {
    eStatus = gBS->LocateProtocol (&gEfiPilProtocolGuid, NULL, (VOID **) &pPILProtocol);

    if ((EFI_SUCCESS  != eStatus) ||
        (NULL         == pPILProtocol))
    {
      DEBUG ((EFI_D_WARN, "MDPLib: Locate pil protocol failed with status(%d)!\r\n", eStatus));
    }
    else
    {
      eStatus = pPILProtocol->ProcessPilImage(pFvName);
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDPAllocateReservedMemory()
*/
/*!
* \brief
*   This function will allocate a reserved memory region. Target specific
*
* \param [in]  eChipId                 - Chipset family
*        [out] pReservedMemoryAddress  - pointer to the allocated memory address
*        [out] pReservedMemorySize     - pointer to the allocated memory size
*
* \retval MDP_Status PcdReservedMemory alignment
*
****************************************************************************/
static MDP_Status MDPAllocateReservedMemory(EFIChipInfoFamilyType eChipId, uint64 *pReservedMemoryAddress, uint64 *pReservedMemorySize)
{
  MDP_Status       eStatus        = MDP_STATUS_OK;
  uint32           uMemSize       = 0;
  uint32           uMemAlignment  = 0;

  if ((NULL == pReservedMemoryAddress) ||
      (NULL == pReservedMemorySize))
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if ((0 == uMemSize)    ||
           (0 == uMemAlignment))
  {
    //No need to allocate memory
    eStatus = MDP_STATUS_OK;
  }
  else
  {
    UINTN   uReservedMemorySize       = 0;
    UINTN   uReservedMemoryAlignment  = 0;
    void   *pMemoryAddress            = NULL;

    switch (eChipId)
    {
    case EFICHIPINFO_FAMILY_MSM8998:
      uReservedMemorySize       = MDP_MEGA(uMemSize);
      uReservedMemoryAlignment  = MDP_KILOBYTES(uMemAlignment);
      break;
    default:
      uReservedMemorySize       = 0;
      uReservedMemoryAlignment  = 0;
      break;
    }

    if (uReservedMemorySize > 0)
    {
      UINTN uPages = EFI_SIZE_TO_PAGES(uReservedMemorySize);

      /* Allocate reserved memory */
      if (NULL == (pMemoryAddress = AllocateAlignedReservedPages(uPages, uReservedMemoryAlignment)))
      {
        DEBUG((EFI_D_ERROR, "MDPAllocateReservedMemory() failed to allocate %d bytes (%d pages).\n", uReservedMemorySize, uPages));
        eStatus = MDP_STATUS_BAD_PARAM;
      }
      else
      {
        /* Update the memory size after a successful allocation */
        uReservedMemorySize = EFI_PAGES_TO_SIZE(uPages);
        DEBUG((EFI_D_INFO, "MDPAllocateReservedMemory() allocated %d bytes.\n", uReservedMemorySize));
      }
    }

    *pReservedMemoryAddress = (uint64)pMemoryAddress;
    *pReservedMemorySize    = uReservedMemorySize;
  }

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDP_GetDisplayBootConfig()
*/
/*!
* \brief
*   This function will get display boot config from IMEM
*
* \param [out] pFrameBufferAddr  : pointer to the buffer that store framebuffer address
*        [out] pFrameBuffersSize : pointer to the buffer that store framebuffer size
*        [out] pPlatformID       : pointer to the Platform ID
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status MDP_GetDisplayBootConfig(UINTN *pFrameBufferAddr, UINT32 *pFrameBuffersSize, uint8 *pPlatformID)
{
  return MDP_STATUS_NOT_SUPPORTED;
}

/****************************************************************************
*
** FUNCTION: MDP_SetDisplayBootConfig()
*/
/*!
* \brief
*   This function will set display boot config to IMEM, only 32 bit address supported
*
* \param [in] uFrameBuffer1Addr: framebuffer address
         [in] uFrameBuffers1Size: framebuffer size in bytes
*s
* \retval None
*
****************************************************************************/
MDP_Status MDP_SetDisplayBootConfig(UINT32 uFrameBuffer1Addr, UINT32 uFrameBuffers1Size)
{
  MDP_Status           eStatus                = MDP_STATUS_OK;
  UINT32               uFrameBuffers1SizeMB   = uFrameBuffers1Size >> 20;

  if ((0 == uFrameBuffer1Addr) ||
      (0 == uFrameBuffers1Size))
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if (sizeof(DISPLAY_BOOT_CONFIG) > DISPLAY_BOOT_IMEM_SIZE)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
    MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDP_SetDisplayBootCOnfig: size=%d too big\n", sizeof(DISPLAY_BOOT_CONFIG));
  }
  else if (uFrameBuffers1SizeMB > DISPLAY_BOOT_HEADER_FRAMEBUFFER1SIZE_MASK)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    UINT32               i;
    DISPLAY_BOOT_CONFIG *pDisplayBootConfig  = (DISPLAY_BOOT_CONFIG*)IMEM_DISPLAY_BOOT_CONFIG_ADDR;
    UINT8                uCRC8;

    /* memset not supported on iMEM region */
    for (i = 0 ; i < sizeof(DISPLAY_BOOT_CONFIG); i++)
    {
       ((UINT8*)pDisplayBootConfig)[i] = 0;       
    }           

    /* Construct header ID*/
    pDisplayBootConfig->uHeader      = (DISPLAY_BOOT_HEADER_ID << DISPLAY_BOOT_HEADER_ID_SHIFT);

    /* Only size1 field is used for now */
    if (TRUE == MDP_RamdumpEnabled())
    {
       pDisplayBootConfig->uHeader   |= ((uFrameBuffers1SizeMB & DISPLAY_BOOT_HEADER_FRAMEBUFFER1SIZE_MASK) << DISPLAY_BOOT_HEADER_FRAMEBUFFER1SIZE_SHIFT);
    }

    pDisplayBootConfig->uFBAddress1  = uFrameBuffer1Addr;

    /* add platform id to header */
   if ((TRUE == MDP_SUPPORTED_DISPLAY(MDP_DISPLAY_PRIMARY)) &&
       (TRUE == MDP_SUPPORTED_DISPLAY(MDP_DISPLAY_SECONDARY)))
   {
     pDisplayBootConfig->uHeader    |= ((MDP_BOOT_PLATFORMID_DUAL_PANEL & DISPLAY_BOOT_HEADER_PLATFORMID_MASK) << DISPLAY_BOOT_HEADER_PLATFORMID_SHIFT);
   }

    /* add uCRC8 to header */
    uCRC8 = MDPCRC8Calculation((UINT8*)pDisplayBootConfig, sizeof(DISPLAY_BOOT_CONFIG));

    /* populate checksum */
    pDisplayBootConfig->uHeader     |= ((uCRC8 & DISPLAY_BOOT_HEADER_CHECKSUM_MASK) << DISPLAY_BOOT_HEADER_CHECKSUM_SHIFT);
  }


  return eStatus;
}

/****************************************************************************
*
** FUNCTION: GetMaxDDRChannels()
*/
/*!
* \brief
*   This function will query DDR channel info from DDRGetInfo protocol
*
* \param [out] pNumChannels   - Number of DDR channels
*
* \retval void
*
****************************************************************************/
static void GetMaxDDRChannels(uint32 *pNumChannels)
{
  EFI_DDRGETINFO_PROTOCOL        *pDDRInfoProtocol = NULL;
  struct ddr_details_entry_info   DDRInfo;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiDDRGetInfoProtocolGuid, NULL, (void **)&pDDRInfoProtocol))
  {
    DEBUG((EFI_D_WARN, "MDPLib: Unable to locate DDRInfo protocol.\n"));
  }
  else if (EFI_SUCCESS != pDDRInfoProtocol->GetDDRDetails(pDDRInfoProtocol, &DDRInfo))
  {
    DEBUG((EFI_D_WARN, "MDPLib: GetDDRDetails failed\n"));
  }
  else
  {
    //GetDDRDetails was successful
    *pNumChannels = DDRInfo.num_channels;
  }
}

/****************************************************************************
*
** FUNCTION: MDP_RamdumpEnabled()
*/
/*!
* \brief
*   This function will query TZ tofind out mem dump is enabled or not
*
*
* \retval bool32
*
****************************************************************************/
static bool32 MDP_RamdumpEnabled()
{
  QCOM_SCM_PROTOCOL *pQcomScmProtocol            = NULL;
  bool32 bMemDumpAllowed                         = FALSE;
  EFI_STATUS eStatus                             = EFI_SUCCESS;
  uint64 uParameters[SCM_MAX_NUM_PARAMETERS];
  uint64 uResults[SCM_MAX_NUM_RESULTS];
  tz_security_allows_mem_dump_rsp_t *pSysCallRsp = (tz_security_allows_mem_dump_rsp_t*)uResults;


  MDP_OSAL_MEMZERO(uParameters, sizeof(uParameters));
  MDP_OSAL_MEMZERO(uResults, sizeof(uResults));

  /* Locate QCOM_SCM_PROTOCOL */
  eStatus = gBS->LocateProtocol(&gQcomScmProtocolGuid,
                                NULL,
                                (VOID **)&pQcomScmProtocol
                               );
  if(EFI_ERROR(eStatus))
  {
    DEBUG(( EFI_D_ERROR, "MDP_RamdumpEnabled: Locate SCM Protocol failed, Status =  (0x%x)\r\n", eStatus));
  }
  else
  {
     // Make SCM call to query if ram dump is supported on this target.
     eStatus = pQcomScmProtocol->ScmSipSysCall (pQcomScmProtocol,
                                               TZ_DUMP_SECURITY_ALLOWS_MEM_DUMP_ID,
                                               TZ_DUMP_SECURITY_ALLOWS_MEM_DUMP_ID_PARAM_ID,
                                               uParameters,
                                               uResults
                                               );

     if(EFI_ERROR(eStatus))
     {
        DEBUG(( EFI_D_ERROR, "MDP_RamdumpEnabled: ScmSipSysCall failed.  Status: %x\n", eStatus));
     }
     else if (pSysCallRsp->common_rsp.status == 1)
     {
        bMemDumpAllowed = TRUE;
     }
     else
     {
        DEBUG(( EFI_D_ERROR, "MDP_RamdumpEnabled: Call to SCM for memory dump query failed.  Status: %x\n", pSysCallRsp->common_rsp.status));
     }
  }

  return bMemDumpAllowed;
}
