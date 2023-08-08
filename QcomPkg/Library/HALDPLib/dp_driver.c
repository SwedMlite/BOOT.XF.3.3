/*=============================================================================

  File: dpdriver.c

  DP Panel driver

  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/


/* -----------------------------------------------------------------------
** Includes
** ----------------------------------------------------------------------- */
#include "MDPLib_i.h"
#include "dp_i.h"
#include "dp_driver.h"
#include "DPInterface.h"

/* -----------------------------------------------------------------------
** Global variables
** ----------------------------------------------------------------------- */
DPDriverConfigType gDPDriverConfig[DP_DEVICE_NUM];

/* -----------------------------------------------------------------------
** Macro defines
** ----------------------------------------------------------------------- */

/* -----------------------------------------------------------------------
** Local Prototypes
** ----------------------------------------------------------------------- */

/* -----------------------------------------------------------------------
** Local functions
** ----------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: GetDPDeviceID()
**
** DESCRIPTION:
**   Map MDP_Display_IDType to DP_DeviceIDType
**
*//* -------------------------------------------------------------------- */
static DP_DeviceIDType GetDPDeviceID(MDP_Display_IDType eDisplayId)
{
  DP_DeviceIDType eDeviceID = DP_DEVICE_ID_NONE;

  switch (eDisplayId)
  {
  case MDP_DISPLAY_PRIMARY:
    eDeviceID = DP_DEVICE_ID_EDP;
    break;
  case MDP_DISPLAY_EXTERNAL:
    eDeviceID = DP_DEVICE_ID_DP;
    break;
  case MDP_DISPLAY_EXTERNAL2:
    eDeviceID = DP_DEVICE_ID_ALT_MODE_0;
    break;
  case MDP_DISPLAY_EXTERNAL3:
    eDeviceID = DP_DEVICE_ID_ALT_MODE_1;
    break;
  default:
    break;
  }

  return eDeviceID;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: GetDPDriverContext()
**
** DESCRIPTION:
**   Get local context for DP Driver
**
*//* -------------------------------------------------------------------- */
static DPDriverConfigType* GetDPDriverContext(MDP_Display_IDType eDisplayId)
{
  DPDriverConfigType *pContext  = NULL;
  DP_DeviceIDType     eDeviceID = GetDPDeviceID(eDisplayId);

  if (DP_DEVICE_ID_NONE < eDeviceID &&
      DP_DEVICE_MAX     > eDeviceID)
  {
    pContext = &gDPDriverConfig[eDeviceID - 1];
  }

  return pContext;
}



/* ---------------------------------------------------------------------- */
/**
** FUNCTION: DPDriver_Open()
**
** DESCRIPTION:
**   Initialize DP panel to use display.
**
*//* -------------------------------------------------------------------- */
MDP_Status DPDriver_Open(MDP_Display_IDType eDisplayId, uint32 uFlags)
{
  MDP_Status               eStatus          = MDP_STATUS_OK;
  DP_HostOpenConfigType    sOpenConfig      = { 0 };
  DPDriverConfigType      *pDPConfig        = NULL;

  // Save DP displayID 
  sOpenConfig.eDeviceID           = GetDPDeviceID(eDisplayId);

  if (NULL == (pDPConfig = GetDPDriverContext(eDisplayId)))
  {
    eStatus = MDP_STATUS_NOT_SUPPORTED;
    DP_LOG_MESSAGE_ERROR("DPDriver_Open: Invalid display ID [%d]\n", eDisplayId);
  }
  else
  {
    pDPConfig->eDisplayId           = eDisplayId;
    sOpenConfig.bReadDPCD           = TRUE;
    sOpenConfig.bReadEDID           = TRUE;
    sOpenConfig.uLaneSwingLevel     = DPCD_SPEC_MIN_VOLTAGE_SWING_LEVEL;
    sOpenConfig.uPreemphasisLevel   = DPCD_SPEC_MIN_PRE_EMPHASIS_LEVEL;
    sOpenConfig.bEnableSSCMode      = FALSE;

    if (uFlags & DPINTERFACE_PLUG_INVERTED)    // USB type-C plug orientation
    {
         sOpenConfig.bInverted      = TRUE;
    }
    else
    {
         sOpenConfig.bInverted      = FALSE;
    }

    sOpenConfig.bSkipHotPlugDetect  = TRUE;    // Skip GPIO based HPD

    // Initialize the host side 
    if (DP_STATUS_SUCCESS != DP_Host_Open(&pDPConfig->hDPHandle, &sOpenConfig))
    {
      eStatus = MDP_STATUS_FAILED;
      DP_LOG_MESSAGE_ERROR("DPDriver_Open: DP_Host_Open failed, eStatus =%d\n", eStatus);
    }
    else if (DP_STATUS_SUCCESS != DP_Host_QueryPanelInfo(pDPConfig->hDPHandle))
    {
      DP_Host_Close(pDPConfig->hDPHandle);
      eStatus = MDP_STATUS_FAILED;
      DP_LOG_MESSAGE_ERROR("DPDriver_Open: DP_Host_QueryPanelInfo failed, eStatus =%d\n", eStatus);
    }
  }

  return eStatus;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: DPDriver_IsDisplayPlugged()
**
** DESCRIPTION:
**   check DP panel is plugged in.
**
*//* -------------------------------------------------------------------- */
bool32 DPDriver_IsDisplayPlugged(MDP_Display_IDType eDisplayId)
{
  bool32                     bPluggedIn  = FALSE;
  DP_GetPropertyParamsType   sPropData;
  DPDriverConfigType         *pDPConfig  = GetDPDriverContext(eDisplayId);

  if ((NULL              != pDPConfig) &&
      (DP_STATUS_SUCCESS == DP_Host_GetProperty(pDPConfig->hDPHandle, DP_GETPROPERTY_CONNECTION_STATUS, &sPropData)))
  {   
    bPluggedIn = sPropData.bPluggedIn;
  }   
      
  return bPluggedIn;
}

 /* ----------------------------------------------------------------------
 ** FUNCTION: DPDriver_Term()
 **
 ** DESCRIPTION:
 **    Close the DP Host driver
 **
 -------------------------------------------------------------------- */
MDP_Status DPDriver_Term(MDP_Display_IDType eDisplayId)
{
  MDP_Status               eStatus   = MDP_STATUS_OK;
  DPDriverConfigType      *pDPConfig = GetDPDriverContext(eDisplayId);
  
  // Close DP host driver
  if (NULL != pDPConfig)
  {
    if (DP_STATUS_SUCCESS != DP_Host_Close(pDPConfig->hDPHandle))
    {
      eStatus = MDP_STATUS_FAILED;
      DP_LOG_MESSAGE_ERROR("DPDriver_Term: DP_Host_Close failed, eStatus =%d\n", eStatus);
    }

    DP_OSAL_MemSet(pDPConfig, 0x00, sizeof(DPDriverConfigType));
  }

  return eStatus;
}

/* ----------------------------------------------------------------------
** FUNCTION: DPDriver_SetMode()
**
** DESCRIPTION:
**    Set a panel mode
**
-------------------------------------------------------------------- */
MDP_Status DPDriver_SetMode(MDP_Panel_AttrType *pPanelInfo, uint32 uFlags)
{
  DP_Status                eStatus       = DP_STATUS_SUCCESS;
  DPDriverConfigType      *pDPConfig     = NULL;
  DP_SetPropertyParamsType sPropertyData = { 0 };

  if ((NULL == pPanelInfo)                                               ||
      (NULL == (pDPConfig = GetDPDriverContext(pPanelInfo->eDisplayId))) ||
      (NULL == pDPConfig->hDPHandle))
  {
    DP_LOG_MESSAGE_ERROR("DPDriver_SetMode: Invalid input \n");
    eStatus = DP_STATUS_FAILED_RESOURCE_NOT_READY;
  }
  else
  {
    uint32 uLinkRate   = 0;      // Default: Get from DPCD
    uint32 uNumLanes   = 0;      // Default: Calculate as needed
    uint32 uModeIndex  = 0;      // Default: First mode 

    if (pPanelInfo->eDisplayFlags & MDP_PANEL_FLAG_TIMING_FROM_EDID)
    {
      /* timing from panel edid */
       uModeIndex = pPanelInfo->uModeId;
    }
    else
    {
      /* timing from panel xml file */
      if (0 != pPanelInfo->uAttrs.sDp.uLinkRateInKhz)
      {
        uLinkRate = pPanelInfo->uAttrs.sDp.uLinkRateInKhz;
      }

      /* Override number of lanes  */
      if (0 != pPanelInfo->uAttrs.sDp.uNumberOfLanes)
      {
        uNumLanes = pPanelInfo->uAttrs.sDp.uNumberOfLanes;
      }

      if (NULL != pPanelInfo)
      {
        /*
         * Custom Mode information
         */
        DP_SetPropertyParamsType       sDPProp;

        DP_OSAL_MemSet(&sDPProp, 0x00, sizeof(DP_SetPropertyParamsType));

        sDPProp.sPanelInfo.uModeIndex               = 0;
        sDPProp.sPanelInfo.uVisibleWidthInPixels    = pPanelInfo->uDisplayWidth;
        sDPProp.sPanelInfo.uVisibleHeightInPixels   = pPanelInfo->uDisplayHeight;
        sDPProp.sPanelInfo.bInterlaced              = pPanelInfo->sActiveTiming.bInterlaced;
        sDPProp.sPanelInfo.uHsyncPulseInPixels      = pPanelInfo->sActiveTiming.uHsyncPulseWidthDclk;
        sDPProp.sPanelInfo.uHsyncFrontPorchInPixels = pPanelInfo->sActiveTiming.uHsyncFrontPorchDclk;
        sDPProp.sPanelInfo.uHsyncBackPorchInPixels  = pPanelInfo->sActiveTiming.uHsyncBackPorchDclk;
        sDPProp.sPanelInfo.bHSyncActiveLow          = pPanelInfo->sActiveTiming.uHsyncInvertSignal;
        sDPProp.sPanelInfo.uVsyncPulseInLines       = pPanelInfo->sActiveTiming.uVsyncPulseWidthLns;
        sDPProp.sPanelInfo.uVsyncFrontPorchInLines  = pPanelInfo->sActiveTiming.uVsyncFrontPorchLns;
        sDPProp.sPanelInfo.uVsyncBackPorchInLines   = pPanelInfo->sActiveTiming.uVsyncBackPorchLns;
        sDPProp.sPanelInfo.bVSyncActiveLow          = pPanelInfo->sActiveTiming.uVsyncInvertSignal;
        sDPProp.sPanelInfo.uRefreshRate             = pPanelInfo->uAttrs.sDp.uRefreshRate;
        sDPProp.sPanelInfo.uPclkFreq                = (uint32)((pPanelInfo->uDisplayWidth +
                                                       pPanelInfo->sActiveTiming.uHsyncFrontPorchDclk +
                                                       pPanelInfo->sActiveTiming.uHsyncBackPorchDclk +
                                                       pPanelInfo->sActiveTiming.uHsyncPulseWidthDclk) *
                                                      (uint64) (pPanelInfo->uDisplayHeight +
                                                       pPanelInfo->sActiveTiming.uVsyncFrontPorchLns +
                                                       pPanelInfo->sActiveTiming.uVsyncBackPorchLns +
                                                       pPanelInfo->sActiveTiming.uVsyncPulseWidthLns) *
                                                       pPanelInfo->uAttrs.sDp.uRefreshRate / 0x10000);

        DP_LOG_MESSAGE_INFO("DPDriver_SetMode: ndx=%d pclk=%d w=%d hfp=%d bfp=%d h=%d vfp=%d vbp=%d, frate=%x\n",
                               sDPProp.sPanelInfo.uModeIndex,
                               sDPProp.sPanelInfo.uPclkFreq,
                               sDPProp.sPanelInfo.uVisibleWidthInPixels,
                               sDPProp.sPanelInfo.uHsyncFrontPorchInPixels,
                               sDPProp.sPanelInfo.uHsyncBackPorchInPixels,
                               sDPProp.sPanelInfo.uVisibleHeightInPixels,
                               sDPProp.sPanelInfo.uVsyncFrontPorchInLines,
                               sDPProp.sPanelInfo.uVsyncBackPorchInLines,
                               sDPProp.sPanelInfo.uRefreshRate);

        if (MDP_PIXEL_FORMAT_RGB_101010_30BPP == pPanelInfo->eColorFormat)
        {
          sDPProp.sPanelInfo.eColorFormat = DP_PIXEL_FORMAT_RGB_101010_30BPP;
        }
        else if (MDP_PIXEL_FORMAT_RGB_666_18BPP == pPanelInfo->eColorFormat)
        {
          sDPProp.sPanelInfo.eColorFormat = DP_PIXEL_FORMAT_RGB_666_18BPP;
        }
        else
        {
          sDPProp.sPanelInfo.eColorFormat = DP_PIXEL_FORMAT_RGB_888_24BPP;
        }
     
        // Set the mode
        eStatus = DP_Host_SetProperty(pDPConfig->hDPHandle, DP_SETPROPERTY_SET_PANEL_INFO, &sDPProp);
        if (DP_STATUS_SUCCESS != eStatus)
        {
          DP_LOG_MESSAGE_ERROR("DPDriver_SetModeInfo: failed to set panel info\n");
        }
      }
    }

    if (0 != uLinkRate)
    {
      sPropertyData.uLinkRate = uLinkRate;
      if(DP_STATUS_SUCCESS != (eStatus = DP_Host_SetProperty(pDPConfig->hDPHandle, DP_SETPROPERTY_SET_LINK_RATE, &sPropertyData)))
      {
        DP_LOG_MESSAGE_ERROR("DPDriver_SetMode: failed to set link rate\n");
      }
    }

    if (0 != uNumLanes)
    {
       sPropertyData.uLaneNumber = uNumLanes;
       if (DP_STATUS_SUCCESS != (eStatus = DP_Host_SetProperty(pDPConfig->hDPHandle, DP_SETPROPERTY_SET_LANE_NUMBER, &sPropertyData)))
       {
         DP_LOG_MESSAGE_ERROR("DPDriver_SetMode: failed to set link rate\n");
       }
    }

    sPropertyData.uModeIndex = uModeIndex;
    if (DP_STATUS_SUCCESS != (eStatus = DP_Host_SetProperty(pDPConfig->hDPHandle, DP_SETPROPERTY_SET_PANEL_MODE_INDEX, &sPropertyData)))
    {
         DP_LOG_MESSAGE_ERROR("DPDriver_SetMode: failed to set Mode Index\n");
    }

    if (DP_STATUS_SUCCESS == eStatus)
    {
      eStatus = DP_Host_Commit(pDPConfig->hDPHandle);
    }

    if (DP_STATUS_FAILED_LINK_TRAINING == eStatus)
    {
      /* Link training failed
      *  TODO: Check if we can Reduce bit rate (support could be added in the future) and succeed
      */
    }
  }

  if (eStatus == DP_STATUS_SUCCESS)
  {
     return MDP_STATUS_OK;
  }
  else
  {
     return MDP_STATUS_FAILED;
  }
}

/* ----------------------------------------------------------------------
** FUNCTION: DPDriver_GetModeInfo()
**
** DESCRIPTION:
**    Get DP panel mode info.
**
-------------------------------------------------------------------- */
MDP_Status DPDriver_GetModeInfo(MDP_Panel_AttrType *pPanelInfo)
{
  MDP_Status                      eStatus   = MDP_STATUS_OK;
  DPDriverConfigType             *pDPConfig = NULL;

  if ((NULL == pPanelInfo)                                               ||
      (NULL == (pDPConfig = GetDPDriverContext(pPanelInfo->eDisplayId))) ||
      (NULL == pDPConfig->hDPHandle))
  {
    eStatus = MDP_STATUS_FAILED;
  }
  else
  {
    DP_GetPropertyParamsType       sDPProp;

    DP_OSAL_MemSet(&sDPProp, 0x00, sizeof(DP_GetPropertyParamsType));
    sDPProp.sPanelInfo.uModeIndex = pPanelInfo->uModeId;
    //Query the mode
     if (DP_STATUS_SUCCESS == DP_Host_GetProperty(pDPConfig->hDPHandle, DP_GETPROPERTY_GET_MODE_INFO, &sDPProp))
     {
       pPanelInfo->uDisplayWidth                          = sDPProp.sPanelInfo.uVisibleWidthInPixels;
       pPanelInfo->uDisplayHeight                         = sDPProp.sPanelInfo.uVisibleHeightInPixels;
       pPanelInfo->uRefreshRate                           = sDPProp.sPanelInfo.uRefreshRate;

       DP_LOG_MESSAGE_INFO("DPDriver_GetModeInfo: paneInfo: ID=%d ndx=%d pclk=%d w=%d h=%d frate=%x\n", pPanelInfo->eDisplayId, pPanelInfo->uModeId, sDPProp.sPanelInfo.uPclkFreq, pPanelInfo->uDisplayWidth, pPanelInfo->uDisplayHeight, pPanelInfo->uRefreshRate);


      if (DP_PIXEL_FORMAT_RGB_101010_30BPP == sDPProp.sPanelInfo.eColorFormat)
      {
        pPanelInfo->eColorFormat = MDP_PIXEL_FORMAT_RGB_101010_30BPP;
      }
      else if (DP_PIXEL_FORMAT_RGB_666_18BPP == sDPProp.sPanelInfo.eColorFormat)
      {
        pPanelInfo->eColorFormat = MDP_PIXEL_FORMAT_RGB_666_18BPP;
      }
      else
      {
        pPanelInfo->eColorFormat = MDP_PIXEL_FORMAT_RGB_888_24BPP;
      }

       pPanelInfo->sActiveTiming.uDataEnInvertSignal      = FALSE;
       pPanelInfo->sActiveTiming.uHsyncPulseWidthDclk     = sDPProp.sPanelInfo.uHsyncPulseInPixels;
       pPanelInfo->sActiveTiming.uHsyncFrontPorchDclk     = sDPProp.sPanelInfo.uHsyncFrontPorchInPixels;
       pPanelInfo->sActiveTiming.uHsyncBackPorchDclk      = sDPProp.sPanelInfo.uHsyncBackPorchInPixels;
       pPanelInfo->sActiveTiming.uHsyncSkewDclk           = 0;         
       pPanelInfo->sActiveTiming.uHsyncInvertSignal       = sDPProp.sPanelInfo.bHSyncActiveLow;
       pPanelInfo->sActiveTiming.uVsyncPulseWidthLns      = sDPProp.sPanelInfo.uVsyncPulseInLines;
       pPanelInfo->sActiveTiming.uVsyncFrontPorchLns      = sDPProp.sPanelInfo.uVsyncFrontPorchInLines;
       pPanelInfo->sActiveTiming.uVsyncBackPorchLns       = sDPProp.sPanelInfo.uVsyncBackPorchInLines;
       pPanelInfo->sActiveTiming.uVsyncInvertSignal       = sDPProp.sPanelInfo.bVSyncActiveLow;
     }
     else
     {
       eStatus = MDP_STATUS_FAILED;
     }

  }

  return eStatus;
}


