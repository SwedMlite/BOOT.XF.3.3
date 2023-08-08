/*=============================================================================
 
  File: MDPSystemBoot.c
 
  Source file for MDP functions
  
 
  Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/
#include <api/boot/boot_logger.h>
#include <api/systemdrivers/busywait.h>
#include <api/boot/boot_cache.h>
#include "MDPSystem.h"
#include <api/dal/DALSys.h>
#include "MDPLib_i.h"
#include "MDPPlatformLib.h"
#include <Library/PrintLib.h>
#include "SecBoot_util.h"
#include "stdio.h"
#include <Library/PrintLib.h>
#include "msmhwiobase.h"

/*=========================================================================
     Default Defines
==========================================================================*/

#define MAX_DEBUG_MESSAGE_LENGTH  0x100

/*=========================================================================
     Local Static Variables
==========================================================================*/
static UINTN  FBMemory   =  0;
static UINT32 uMemLength =  0;

static const sMDSS_BaseAddressMappings asMDSS_BaseAddressMappings[MDSS_BASEADDRESSMAPINGS_MAX] = {  
    {EFICHIPINFO_FAMILY_SM8250, (uintPtr)0x0AE00000},
};

/*=========================================================================
     Local Static Functions
==========================================================================*/

/*=========================================================================
      Public APIs
==========================================================================*/


/****************************************************************************
*
** FUNCTION: MDP_Log_Message()
*/
/*!
* \brief
*   This function will perform the logging of Debug messages
*
* \param [in] uLogType   - Log level
*        [in] pLogString -  Log String
*
* \retval void
*
****************************************************************************/
void MDP_Log_Message(MDP_LogLevel uLogType, char *pLogString, ...)
{
  CHAR8    buffer[MAX_DEBUG_MESSAGE_LENGTH];
  VA_LIST  marker;

  //Ignore Info level output
  if (MDP_LOGLEVEL_INFO > uLogType)
  {
    //
    // Convert the DEBUG() message to a Unicode String
    //
    VA_START(marker, pLogString);
    AsciiVSPrint(buffer, MAX_DEBUG_MESSAGE_LENGTH, pLogString, marker);
    VA_END(marker);

    boot_log_message(buffer);
  }
  
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
  qmemset(pBuffer, 0, uLength);
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
void MDP_OSAL_MEMCPY(void *pDest, void * pSrc, UINTN uLength)
{
  qmemcpy(pDest, pSrc, uLength);
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
  qmemset(pBuffer, uValue, uLength);
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_SYSMEM_Init()
*/
/*!
* \brief
*   Initialize memory starting address and size
*
* \retval void
*
****************************************************************************/
void MDP_OSAL_SYSMEM_Init(void)
{
    if (FBMemory == 0)
    {
       /*
        * FBMemory should be populated at MDP_GetDisplayBootConfig()
        * if not, use default FB memory
        */
       FBMemory   = RAMDUMP_FRAME_BUFFER_ADDRESS;
    }

    uMemLength = RAMDUMP_ALLOC_POOL_SIZE;
}

/****************************************************************************
*
** FUNCTION: MDP_OSAL_CALLOC()
*/
/*!
* \brief
*   Allocate memory from frame buffer.
*   NOTE:
*      memory will be reclaimed by frame buffer.
*      Flicking will happen if memory still used while frame buffer is BLTed.
*
* \param [in] uLength   - Requested size of memory to be allocated
*
* \retval point to the block of allocated memory
*
****************************************************************************/
void* MDP_OSAL_CALLOC(UINTN uLength)
{
    void *pBuffer           = NULL;

    /*
     * This function allocated memory out of frame buffer (display reserved).
     * FBMemory increased with uLength at every allocation and always point to next
     * available memory. CALLOC only used during panel initialization time. Once pass
     * initialization, memory allocated will be reclaimed and used as frame buffer.
     */
 
    if (FBMemory == 0)
    {
       if (MDP_STATUS_OK != MDP_GetDisplayBootConfig(&FBMemory, &uMemLength, NULL))
       {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDP_OSAL_CALLOC: Falied to retrieve FrameBuffer from IMEM\n");
       }
    }

    if (FBMemory)
    {
       uLength += 7;
       uLength &= ~0x07; /* 8 bytes alignement */

       if (uMemLength >= uLength)
       {
          pBuffer = (VOID *)FBMemory;
          FBMemory += uLength;
          uMemLength -= uLength;
          qmemset(pBuffer, 0, uLength);
       }
       else
       {
         MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDP_OSAL_CALLOC: Error, mem=%x len=%d\n", FBMemory, uMemLength);
       }
    }
    return pBuffer;
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
  DALSYS_Free(pBuffer);
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
  busywait((uint32)(uDelayMs)* 1000);
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
  busywait((uint32)(uDelayUs));
}

/*=========================================================================
        Stub Function, no implement in XBL RAM Dump mode
==========================================================================*/

/****************************************************************************
*
** FUNCTION: MDP_SetupMMUSIDs()
*/
/*!
* \brief
*   Helper to program Display MMU SID to bypass
*
* \param uMMUSidMask - Platform MMU Sid Mask
*
* \retval MDP_STATUS_OK on success
*
****************************************************************************/
MDP_Status MDP_SetupMMUSIDs(uint32 uMMUSidMask)
{
  return MDP_STATUS_OK;
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

   uint32               uCount;
   uintPtr              pPhyAddr = 0;

   //Search for correct chip family
   for(uCount = 0; uCount< MDSS_BASEADDRESSMAPINGS_MAX; uCount++)
   {
      if(asMDSS_BaseAddressMappings[uCount].sEFIChipSetFamily == sEFIChipSetFamily)
      {
         pPhyAddr = asMDSS_BaseAddressMappings[uCount].uMDSSBaseAddress;
         break;   
      }
   }
   return pPhyAddr;
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
  return MDP_STATUS_OK;
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
   dcache_flush_region((void *)pBuffer, uBufferSize);
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
  return MDP_STATUS_OK;
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
  return MDP_STATUS_OK;
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
  return EFI_SUCCESS;
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
  return EFI_SUCCESS;
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
  return EFI_SUCCESS;
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
  return 0;
}

/****************************************************************************
*
** FUNCTION: I2CDriver_Init()
*/
/*!
* \brief
*  Initialize the I2C handles to write to I2C bus.
*
* \param  [in]  pPanelConfig - Panel information.
*
* \retval MDP_STATUS_OK if I2C is initialized successfully.
*
****************************************************************************/
MDP_Status I2CDriver_Init(MDP_Panel_AttrType *pPanelConfig)
{
  return MDP_STATUS_OK;
}


/****************************************************************************
*
** FUNCTION: I2CDriver_Deinit()
*/
/*!
* \brief
*  Deinitialize the I2C Core.
*
* \param  [in]  pPanelConfig - Panel information
*
* \retval void
*
****************************************************************************/
void I2CDriver_Deinit(MDP_Panel_AttrType *pPanelConfig)
{
  return;
}

/****************************************************************************
*
** FUNCTION: I2CPanelSendCommandSequence()
*/
/*!
* \brief
*   Send I2C command sequence.
*
* \param  [in]  pPanelConfig    - Panel information
* \param  [in]  eCommand        - Init/Term commands
* \param  [in]  pCustomCommand  - Custom command
* \param  [in]  uFlags          - Reserved
*
* \retval MDP_STATUS_OK if I2C command sequence is successfully sent.
*
****************************************************************************/
MDP_Status I2CPanelSendCommandSequence(MDP_Panel_AttrType  *pPanelInfo, 
                                       MdpPanelCommandType  eCommand, 
                                       void                *pCustomCommand, 
                                       uint32               uFlags)
{ 
  return MDP_STATUS_OK;

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
  return MDP_STATUS_OK;
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
UINT32     MDP_GetTimerCountMS(void)
{
  return 0;
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
  return 0;
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
  return MDP_STATUS_OK;
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
  return MDP_STATUS_OK;
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
  return MDP_STATUS_OK;
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
  return MDP_STATUS_OK;
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
  MDP_Status          eStatus                = MDP_STATUS_OK;

  if ((NULL == pFrameBufferAddr) ||
      (NULL == pFrameBuffersSize))
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    DISPLAY_BOOT_CONFIG *pDisplayBootConfig = (DISPLAY_BOOT_CONFIG*)IMEM_DISPLAY_BOOT_CONFIG_ADDR;
    UINT8               *pBuf               = (UINT8 *)IMEM_DISPLAY_BOOT_CONFIG_ADDR;
    UINT8                uCRC8;
    UINT8                uMagicId;

    uMagicId   = ((pDisplayBootConfig->uHeader >> DISPLAY_BOOT_HEADER_ID_SHIFT) & DISPLAY_BOOT_HEADER_ID_MASKT);

    /* keep original checksum of IMEM */
    uCRC8  = ((pDisplayBootConfig->uHeader >> DISPLAY_BOOT_HEADER_CHECKSUM_SHIFT) & DISPLAY_BOOT_HEADER_CHECKSUM_MASK);

    /* replace checksum with 0 before calculation */
    pDisplayBootConfig->uHeader &= ~(DISPLAY_BOOT_HEADER_CHECKSUM_MASK << DISPLAY_BOOT_HEADER_CHECKSUM_SHIFT);

    /*
     * since IMEM may boot up with random value before configured by uefi display,
     * check both magic Id and checksum value at ramdump in case of system crash
     * before uefi dispaly be started yet (such as SBL)
     */
    if ((uMagicId  != DISPLAY_BOOT_HEADER_ID) ||
        (uCRC8 != MDPCRC8Calculation(pBuf, sizeof(DISPLAY_BOOT_CONFIG))))
    {
      /*
       * In case system crash before DisplayDxe be executed which
       * means IMEM also is not populated
       * use default FB memory
       */
     *pFrameBufferAddr  = RAMDUMP_FRAME_BUFFER_ADDRESS; /* only support 32 bit address currently */ 
     *pFrameBuffersSize = RAMDUMP_FRAME_BUFFER_SIZE;
      FBMemory          = RAMDUMP_FRAME_BUFFER_ADDRESS; /* pouplate local FBMemory used by OSAL_CALLOC */
    }
    else
    {
      UINT32 uFBAddr = pDisplayBootConfig->uFBAddress1; /* only support 32 bit address currently */
      UINT32 uFBSize = (((pDisplayBootConfig->uHeader >> DISPLAY_BOOT_HEADER_FRAMEBUFFER1SIZE_SHIFT) &
                        DISPLAY_BOOT_HEADER_FRAMEBUFFER1SIZE_MASK) << 20);/* Convert from Mb to Bytes */

      /* Validate FrameBufferAddr and FrameBufferSize */
      if ((0 == uFBAddr) ||
          (0 == uFBSize))
      {
        eStatus = MDP_STATUS_NOT_SUPPORTED;
      }
      else
      {
        *pFrameBufferAddr  = uFBAddr;
        *pFrameBuffersSize = uFBSize << 20; /* MByte to Byte */
         FBMemory          = uFBAddr;       /* populate local FBMemory used by OSAL_CALLOC */
      }

      /* Get platform ID */
      if (NULL != pPlatformID)
      {
        *pPlatformID = (pDisplayBootConfig->uHeader >> DISPLAY_BOOT_HEADER_PLATFORMID_SHIFT) & DISPLAY_BOOT_HEADER_PLATFORMID_MASK;
      }
    }
  }

  return eStatus;
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
  return MDP_STATUS_NOT_SUPPORTED;
}

