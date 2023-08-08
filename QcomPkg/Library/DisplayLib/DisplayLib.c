/*=============================================================================
 
  File: XBLLoaderDisplayLib.c
 
  Source file for XBL Loader Display functions
  
 
  Copyright (c) 2016-2020 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/
#include <api/boot/boot_cache.h>
#include "DisplayLib.h"
#include "MDPLib.h"
#include "MDPSystem.h"
#include "MDPPlatformLib.h"

/*=========================================================================
     Default Defines
==========================================================================*/

#define DISPLAY_DEFAULT_MDP_FORMAT      MDP_PIXEL_FORMAT_ARGB_8888_32BPP
#define DISPLAY_DEFAULT_BYTES_PER_PIXEL 4
#define DISPLAY_MAX_SOURCEWIDTH         1920
#define DISPLAY_MAX_SOURCEHEIGHT        1080
#define DISPLAY_DEFALUT_BACKLIGHT_LEVEL 50
              
/*=========================================================================
     Local Static Variables
==========================================================================*/

/* Local context for storing display state 
 */


/*=========================================================================
     Local Static Functions
==========================================================================*/
/* Display Blit function */
static void DisplayDxeBltInternal(
  UINT8   *pSrc,
  UINT8   *pDst,
  UINTN    uSrcX,
  UINTN    uSrcY,
  UINTN    uSrcWidth,
  UINTN    uSrcHeight,
  UINTN    uSrcStride,
  UINTN    uDstX,
  UINTN    uDstY,
  UINTN    uDstStride,
  UINTN    uBytesPerPixel
  );

/*=========================================================================
     Globals
==========================================================================*/
/* Supported display list - TRUE: Enabled, FALSE: Disabled. */
bool32 gSupportedDisplayList[MDP_DISPLAY_MAX] =
{
  TRUE,   // MDP_DISPLAY_PRIMARY
  FALSE,  // MDP_DISPLAY_SECONDARY
  FALSE,  // MDP_DISPLAY_EXTERNAL
  FALSE,  // MDP_DISPLAY_EXTERNAL2
  FALSE,  // MDP_DISPLAY_EXTERNAL3
  FALSE,  // MDP_DISPLAY_EXTERNAL4
  FALSE,  // MDP_DISPLAY_EXTERNAL5
  FALSE   // MDP_DISPLAY_EXTERNAL6
};

/*=========================================================================
      Public APIs
==========================================================================*/
void MDP_OSAL_SYSMEM_Init(void);


/****************************************************************************
*
** FUNCTION: DisplayInitialize()
*/
/*!
* \brief
*   This function will initialize the display and return the frame buffer that is currently being scanned out from.
*
* \param [out] pFrameBufferInfo   - Information regarding the display frame buffer
*        [in]  uFlags             - Reserved
*
* \retval EFI_STATUS
*
****************************************************************************/

MDP_Status DisplayInitialize(
  DisplayLibBufferInfoType     *pFrameBufferInfo,
  uint32                        uFlags)
{
  MDP_Status                eStatus          = MDP_STATUS_OK;
  UINTN                     uFrameBufferAddr = 0;
  UINT32                    uFrameBufferSize = 0;
  uint8                     uPlatformID      = 0;


  if (NULL == pFrameBufferInfo)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if (MDP_STATUS_OK != (eStatus = MDP_GetDisplayBootConfig(&uFrameBufferAddr, &uFrameBufferSize, &uPlatformID)))
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Displaylib: MDP_GetDisplayBootConfig failed!\n");
  }
  else
  {
    MDP_InitParamsType       sInitParam;
    MDPPlatformParams        sPlatformParams;

    // Clear out global structures
    MDP_OSAL_MEMZERO(&sInitParam,       sizeof(MDP_InitParamsType));
    MDP_OSAL_MEMZERO(&sPlatformParams,  sizeof(MDPPlatformParams));

    MDP_OSAL_SYSMEM_Init();

    // Pass the platform ID queried from the IMEM boot configuration
    sPlatformParams.sPlatformInfo.uPlatformID = uPlatformID;

    // MDP platform configuration init
    if (MDP_STATUS_OK != (eStatus = MDPPlatformConfigure(MDP_DISPLAY_PRIMARY, MDPPLATFORM_CONFIG_INIT, &sPlatformParams)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayLib: MDPPlatformConfigure(MDPPLATFORM_CONFIG_INIT) failed! Returned %d\n", eStatus);
    }
    else
    {
      MDP_OSAL_MEMCPY(&sInitParam.aSupportedDisplays, &gSupportedDisplayList, sizeof(sInitParam.aSupportedDisplays));

      // Initialize the MDP 
      if (MDP_STATUS_OK != MDPInit(&sInitParam, 0x0))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayLib: MDP init failed!\n");
        eStatus = MDP_STATUS_HW_ERROR;
      }
      else
      {
        MDP_PowerParamsType      sPowerParams;
        MDP_DetectParamType      sDetectParams;
        MDP_PropertiesParamType  sDisplayProp;
        VOID                    *pFBuf;
        UINTN                    uFBSize;
        MDP_Display_IDType       eDisplayId;

        MDP_OSAL_MEMZERO(&sDisplayProp, sizeof(MDP_PropertiesParamType));
        MDP_OSAL_MEMZERO(&sPowerParams, sizeof(MDP_PowerParamsType));
        MDP_OSAL_MEMZERO(&sDetectParams, sizeof(MDP_DetectParamType));

        //
        // Zero out the maximum size of frame buffer.
        // NOTE:
        //    the first RAMDUMP_ALLOC_POOL_SIZE is used as dsi cmd buffer to initialize
        //    panel before frame buffer is actived BLTed. Once panel initialized, those
        //    memory will be re claimed by frame buffer and BLT will start.
        //
        pFBuf = (VOID *)uFrameBufferAddr;
        uFBSize = DISPLAY_MAX_SOURCEWIDTH * DISPLAY_MAX_SOURCEHEIGHT * DISPLAY_DEFAULT_BYTES_PER_PIXEL;
        MDP_OSAL_MEMZERO(pFBuf,  uFBSize);

        sPowerParams.bPowerOn         = TRUE;
        sDisplayProp.bDisplayPwrState = TRUE;

        // If the primary / secondary display is supported initialize it
        for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId <= MDP_DISPLAY_SECONDARY; eDisplayId++)
        {
          if (FALSE == MDP_SUPPORTED_DISPLAY(eDisplayId))
          {
            continue;
          }
          else if (MDP_STATUS_OK != MDPPower(eDisplayId, &sPowerParams, 0x0))
          {
            MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Displaylib: Common display panel power up failed!\n");
            eStatus = MDP_STATUS_HW_ERROR;
          }
          else if ((MDP_STATUS_OK != MDPDetect(eDisplayId, &sDetectParams, 0x0)) ||
                   (TRUE != sDetectParams.bDisplayDetected))
          {
            MDP_Log_Message(MDP_LOGLEVEL_ERROR, "Displaylib: Display panel detect failed!\n");
            eStatus = MDP_STATUS_HW_ERROR;
          }
          else if (MDP_STATUS_OK != MDPPower(eDisplayId, &sPowerParams, POWERCONFIG_FLAGS_PANEL_POWER))
          {
            MDP_Log_Message(MDP_LOGLEVEL_INFO, "Displaylib: Specific display panel power up failed!\n");
            eStatus = MDP_STATUS_HW_ERROR;
          }
          // Set the display power state to on 
          else if (MDP_STATUS_OK != MDPSetProperty(eDisplayId, MDP_DISPLAY_PROPERTY_POWER_STATE, &sDisplayProp))
          {
            eStatus = MDP_STATUS_HW_ERROR;
          }
        }

        VOID                    *pFrameBufferBase;
        MDP_SetModeParamType     sModeParams;
        uint32                   uWidth = sDetectParams.aModeList[0].uWidth;
        uint32                   uHeight = sDetectParams.aModeList[0].uHeight;
        UINTN                    uFrameBufferSize = 0;

        if ((uWidth * uHeight) > (DISPLAY_MAX_SOURCEWIDTH *  DISPLAY_MAX_SOURCEHEIGHT))
        {
          // Portrait mode panel 
          if (uHeight > uWidth)
          {
            // Clamp the width to Max height and height to Max Width to maintain the portrait aspect ratio 
            uWidth = DISPLAY_MAX_SOURCEHEIGHT;
            uHeight = DISPLAY_MAX_SOURCEWIDTH;
          }
          // Landscape mode panel
          else
          {
            uWidth = DISPLAY_MAX_SOURCEWIDTH;
            uHeight = DISPLAY_MAX_SOURCEHEIGHT;
          }
        }

        //////////////////////////
        // Allocate frame buffer  Clear the frame buffer//
        /////////////////////////
        pFrameBufferBase = (VOID *)uFrameBufferAddr;
        uFrameBufferSize = uWidth * uHeight * DISPLAY_DEFAULT_BYTES_PER_PIXEL;

        // Setup the mode params
        MDP_OSAL_MEMZERO(&sModeParams, sizeof(MDP_SetModeParamType));
        sModeParams.sSurfaceInfo.ePixelFormat     = DISPLAY_DEFAULT_MDP_FORMAT;
        sModeParams.sSurfaceInfo.uWidth           = uWidth;
        sModeParams.sSurfaceInfo.uHeight          = uHeight;
        sModeParams.sSurfaceInfo.pPlane0Offset    = pFrameBufferBase;
        sModeParams.sSurfaceInfo.uPlane0Stride    = uWidth * DISPLAY_DEFAULT_BYTES_PER_PIXEL;
        sModeParams.uModeIndex = 0;

        pFrameBufferInfo->pBufferAddr = sModeParams.sSurfaceInfo.pPlane0Offset;
        pFrameBufferInfo->uWidth      = sModeParams.sSurfaceInfo.uWidth;
        pFrameBufferInfo->uHeight     = sModeParams.sSurfaceInfo.uHeight;
        pFrameBufferInfo->uStride     = sModeParams.sSurfaceInfo.uPlane0Stride;

        // If the primary / secondary display is supported initialize it
        for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId <= MDP_DISPLAY_SECONDARY; eDisplayId++)
        {
          if (FALSE == MDP_SUPPORTED_DISPLAY(eDisplayId))
          {
            continue;
          }
          else if (MDP_STATUS_OK == MDPSetMode(eDisplayId, &sModeParams, 0x0))
          {
            MDP_PropertiesParamType  sDisplayProp;

            //
            // Setup the default backlight level
            //
            MDP_OSAL_MEMZERO(&sDisplayProp, sizeof(MDP_PropertiesParamType));
            sDisplayProp.uBacklightLevel = DISPLAY_DEFALUT_BACKLIGHT_LEVEL;

            MDPSetProperty(eDisplayId, MDP_DISPLAY_PROPERTY_BACKLIGHT, &sDisplayProp);
          }
          else
          {
            eStatus = MDP_STATUS_HW_ERROR;
          }
        }

        //
        // No need to re initialize whole frame buffer.
        // just initialize the first RAMDUMP_ALLOC_POOL_SIZE of frame buffer
        // where is used as dsi cmd buffer to initialize panel before
        //
        MDP_OSAL_MEMZERO(pFrameBufferBase, RAMDUMP_ALLOC_POOL_SIZE);
      }
    }
  }

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: DisplayBlt()
*/
/*!
* \brief
*   This function will perform BLT operation between Blt buffer and frame buffer.
*
*  \param [in] pFrameBufferInfo   - Frame buffer info
*         [in] uFrameBufferRoiX   - X coordinate of destination for the BltBuffer.
*         [in] uFrameBufferRoiY   - Y coordinate of destination for the BltBuffer.
[in] eBltOperation      - Operation to perform on BlitBuffer and frame buffer
*         [in] pBltBufferInfo     - Blt buffer info, it should be always in ARGB8888.
*         [in] uBLTRoiX           - X coordinate of source for the BltBuffer.
*         [in] uBLTRoiY           - Y coordinate of source for the BltBuffer.
*         [in] uRoiWidth          - Width of rectangle in BltBuffer in pixels.
*         [in] uRoiHeight         - Hight of rectangle in BltBuffer in pixels.
*         [in] uFlags             - Reserved
*
* \retval EFI_STATUS
*
****************************************************************************/
MDP_Status DisplayBlt(
  DisplayLibBufferInfoType     *pFrameBufferInfo,
  uint32                        uFrameBufferRoiX,
  uint32                        uFrameBufferRoiY,
  DisplayLibBltOperationType    eBltOperation,
  DisplayLibBufferInfoType     *pBltBufferInfo,
  uint32                        uBLTRoiX,
  uint32                        uBLTRoiY,
  uint32                        uRoiWidth,
  uint32                        uRoiHeight,
  uint32                        uFlags)
{
  MDP_Status        eStatus = MDP_STATUS_OK;

  switch (eBltOperation)
  {
  case DISPLAY_BLT_BUFFERTOFRAME:
  {
    uint8 *pSrcBuffer = (uint8*)pBltBufferInfo->pBufferAddr;
    uint8 *pDstBuffer = (uint8*)pFrameBufferInfo->pBufferAddr;

    if (((uFrameBufferRoiX + uRoiWidth)  > pFrameBufferInfo->uWidth) ||
        ((uFrameBufferRoiY + uRoiHeight) > pFrameBufferInfo->uHeight)||
        ((uBLTRoiX         + uRoiWidth)  > pBltBufferInfo->uWidth)   ||
        ((uBLTRoiY         + uRoiHeight) > pBltBufferInfo->uHeight))
    {
      return MDP_STATUS_BAD_PARAM;
    }

    DisplayDxeBltInternal(pSrcBuffer,
                          pDstBuffer,
                          uBLTRoiX,
                          uBLTRoiY,
                          uRoiWidth,
                          uRoiHeight,
                          pBltBufferInfo->uStride,
                          uFrameBufferRoiX,
                          uFrameBufferRoiY,
                          pFrameBufferInfo->uStride,
                          DISPLAY_DEFAULT_BYTES_PER_PIXEL);

    eStatus = MDP_STATUS_OK;
  }
  break;

  case DISPLAY_BLT_FRAMETOBLTBUFFER:
  {
    uint8 *pDstBuffer = (uint8*)pBltBufferInfo->pBufferAddr;
    uint8 *pSrcBuffer = (uint8*)pFrameBufferInfo->pBufferAddr;

    if (((uFrameBufferRoiX + uRoiWidth)  > pFrameBufferInfo->uWidth) ||
        ((uFrameBufferRoiY + uRoiHeight) > pFrameBufferInfo->uHeight)||
        ((uBLTRoiX         + uRoiWidth)  > pBltBufferInfo->uWidth)   ||
        ((uBLTRoiY         + uRoiHeight) > pBltBufferInfo->uHeight))
    {
      return MDP_STATUS_BAD_PARAM;
    }

    DisplayDxeBltInternal(pSrcBuffer,
                          pDstBuffer,
                          uFrameBufferRoiX,
                          uFrameBufferRoiY,
                          uRoiWidth,
                          uRoiHeight,
                          pFrameBufferInfo->uStride,
                          uBLTRoiX,
                          uBLTRoiY,
                          pBltBufferInfo->uStride,
                          DISPLAY_DEFAULT_BYTES_PER_PIXEL);

    eStatus = MDP_STATUS_OK;
  }
  break;

  case DISPLAY_BLT_FRAMEFILL:
  {
    uint32  SrcPixel   = *(uint32*)pBltBufferInfo->pBufferAddr;
    uint32 *pDstBuffer = (uint32*)pFrameBufferInfo->pBufferAddr;;
    uint32  DstStride;
    uint32  x, y;

    if (((uFrameBufferRoiX + uRoiWidth)  > pFrameBufferInfo->uWidth) ||
        ((uFrameBufferRoiY + uRoiHeight) > pFrameBufferInfo->uHeight))
    {
      return MDP_STATUS_BAD_PARAM;
    }


    /* Video buffer stride in bytes, consider padding as well */
    DstStride = pFrameBufferInfo->uStride;

    /* Adjust Destination location */
    pDstBuffer = (uint32*)(((uint8*)pDstBuffer) + (uFrameBufferRoiY * DstStride) + uFrameBufferRoiX * DISPLAY_DEFAULT_BYTES_PER_PIXEL);

    /* Do the actual blitting */
    for (y = 0; y < uRoiHeight; y++)
    {
      for (x = 0; x < uRoiWidth; x++)
      {
        pDstBuffer[x] = SrcPixel;
      }
      /* Increment by stride number of bytes */
      pDstBuffer = (uint32*)((uint8*)pDstBuffer + DstStride);
    }
    eStatus = MDP_STATUS_OK;
  }
  break;

  case DISPLAY_BLT_FRAMETOFRAME:
  {
    uint8 *pSrcBuffer = (uint8*)pFrameBufferInfo->pBufferAddr;
    uint8 *pDstBuffer = (uint8*)pFrameBufferInfo->pBufferAddr;

    if (((uBLTRoiX         + uRoiWidth)  > pFrameBufferInfo->uWidth)  ||
        ((uBLTRoiY         + uRoiHeight) > pFrameBufferInfo->uHeight) ||
        ((uFrameBufferRoiX + uRoiWidth)  > pFrameBufferInfo->uWidth)  ||
        ((uFrameBufferRoiY + uRoiHeight) > pFrameBufferInfo->uHeight))
    {
      return MDP_STATUS_BAD_PARAM;
    }

    DisplayDxeBltInternal(pSrcBuffer,
                          pDstBuffer,
                          uBLTRoiX,
                          uBLTRoiY,
                          uRoiWidth,
                          uRoiHeight,
                          pFrameBufferInfo->uStride,
                          uFrameBufferRoiX,
                          uFrameBufferRoiY,
                          pFrameBufferInfo->uStride,
                          DISPLAY_DEFAULT_BYTES_PER_PIXEL);

    eStatus = MDP_STATUS_OK;

  }
  break;

  default:
    eStatus = MDP_STATUS_BAD_PARAM;
    break;
  }

  return eStatus;
}
/**********************************************************************************************************************
Local Functions
**/

/**
Display DXE Internal Blit function

@param  pSrc              Pointer(non NULL) to source buffer.
@param  pdst              Pointer(non NULL) to destination buffer.

@param  uSrcX             X coordinate of source.
@param  uSrcY             Y coordinate of source.
@param  uSrcWidth         Width of source rectangle in pixels.
@param  uSrcHeight        Height of source rectangle in pixels.
@param  uSrcStride        Stride of source rectangle in bytes.

@param  uDstX             X coordinate of destination.
@param  uDstY             Y coordinate of destination.
@param  uDstStride        Stride of destination rectangle in bytes.

@param  uBytesPerPixel    Number of bytes per pixel.
**/

static void DisplayDxeBltInternal(
  UINT8   *pSrc,
  UINT8   *pDst,
  UINTN    uSrcX,
  UINTN    uSrcY,
  UINTN    uSrcWidth,
  UINTN    uSrcHeight,
  UINTN    uSrcStride,
  UINTN    uDstX,
  UINTN    uDstY,
  UINTN    uDstStride,
  UINTN    uBytesPerPixel
  )
{
  UINT32 uI = 0;
  UINT32 uSrcWidthBytes = uSrcWidth * uBytesPerPixel;

  /* move src pointer to start of src rectangle */
  pSrc += (uSrcY * uSrcStride) + (uSrcX * uBytesPerPixel);

  /* move dest pointer to start of dest rectangle */
  pDst += (uDstY * uDstStride) + (uDstX * uBytesPerPixel);

  /* Blit Operation
  *
  *  We use MDP_OSAL_MEMCPY which invokes Neon memcpy (kr_memcpy.asm)
  *  This memcpy supports overlapped src and dst buffers but copying may not be optimal in the overlap case
  */
  for (uI = 0; uI < uSrcHeight; ++uI)
  {
    MDP_OSAL_MEMCPY((void*)pDst, (void*)pSrc, uSrcWidthBytes);

    pDst += uDstStride;
    pSrc += uSrcStride;
  }
}
