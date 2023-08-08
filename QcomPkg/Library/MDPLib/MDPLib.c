/*=============================================================================
 
  File: MDPLIb.c
 
  Source file for MDP functions
  
 
  Copyright (c) 2013-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#include <Library/PcdLib.h>
#include "MDPLib.h"
#include "MDPLib_i.h"
#include "MDPSystem.h"
#include "MDPPlatformLib.h"
#include "DisplayUtils.h"
#include "ExternalDisplayDriver.h"
#include "DPInterface.h"


/*=========================================================================
     Default Defines
==========================================================================*/
/* Default MDPInit Flags */
#define DEAFAULT_MDP_INIT_FLAGS                  (HAL_MDP_INIT_FLAGS_VBIF_CONFIGURATION |\
                                                  HAL_MDP_INIT_FLAGS_DISABLE_INTERRUPTS |\
                                                  HAL_MDP_INIT_FLAGS_CLEAR_INTERRUPTS)

/* Smart transfer time margin is 2ms for worst case */                                                
#define MDP_SMART_TRANSFER_TIME_MARGIN            0.002

/*=========================================================================
     Local Static Variables
==========================================================================*/


/*=========================================================================
     Local Static Functions
==========================================================================*/


/* Function to detect the presence of external display
 */
static bool32 MDPDetectExtPlugin(MDP_Display_IDType eDisplayId, MDP_Panel_AttrType  *pPanelInfo, uint32 Flags);


/* Read UEFI variable DISABLEDISPLAY
 */
static bool32 MDPPlatformGetDisableDisplay(void);

/* Set MDSS base address
 */
static MDP_Status MDPPlatformSetMdssBase(EFIChipInfoFamilyType sEFIChipSetFamily);

/* Configuration parameters that are required to correctly setup the
   DSC related configuration like topology flags and resolution info
   for each compression encoder. 
 */
static void MDPSetupDSCProperty(MDP_Panel_AttrType *pPanelInfo);

/* Configuration default GPIO states
*/
static MDP_Status MDPSetGPIOState(MDP_Panel_AttrType *pDisplayInfo);

/* Get the highest bankbit based on DDR Type
*/
static uint32 MDPGetHighestBankBit();

/* Get the total bandwidth of all display devices and core clock value
*/
static MDP_Status MDPGetAggregatedCoreAndBandwidth(uint32 *pMaxCoreClock, uint64 *pBandwidth);

/* Get refresh rate based on interface type
*/
static uint32 MDPGetRefreshRate(MDP_Panel_AttrType *pDisplayInfo, uint32 *pRefreshRate);

/*=========================================================================
     Globals
==========================================================================*/
extern uint8         *gpDSIInitSequenceBuffer;
extern uint8         *gpDSITermSequenceBuffer;
extern uint8         *gpDSIDscPpsBuffer;
extern uint8         *gpI2CInitSequenceBuffer;
extern uint8         *gpI2CTermSequenceBuffer;
MDP_HwPrivateInfo     gsMDPHwPrivateInfo;
MDP_Panel_AttrType    gDisplayInfo[MDP_DISPLAY_MAX];

/* SMR Mask for MDP to route all MDP SIDs to a single Context Bank (from sid.mapping in ipcat)
 * MMU SID Masks and chip set family mapping
 */
static const sChip_MMUSidMasks asChip_MMUSidMasks[MDSS_BASEADDRESSMAPINGS_MAX] = {  
    {EFICHIPINFO_FAMILY_SM8250, 0x402},               // for SM8250 (Kona) family
};
static MDP_Status FindPlatformMMUSidMask (EFIChipInfoFamilyType	sEFIChipSetFamily, uint32 *pMMUSidMask);


/*=========================================================================
      Public APIs
==========================================================================*/

/****************************************************************************
*
** FUNCTION: MDPSWRenderEnabled()
*/
/*!
* \brief
*     Helper to get / set SW Render status
*
* \retval None 
*
****************************************************************************/ 
void MDPSWRenderStatus(bool32 *pStatus, MDP_SWRenderStatus_Type eFlag)
{
  static bool32 bSWRender = TRUE;

  if (NULL != pStatus)
  {
    if (MDP_SW_RENDER_STATUS_SET == eFlag)
    {
      bSWRender = *pStatus;
    }
    else
    {
      *pStatus = bSWRender;
    }
  }
}

/****************************************************************************
*
** FUNCTION: MDPInit()
*/
/*!
* \brief
*   This function will perform the basic initialization and detection of the MDP core
*
* \param [out] pMDPInitParams   - Information regarding the hardware core
*        [in]  uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPInit(MDP_InitParamsType *pMDPInitParams, uint32 uFlags)
{
  MDP_Status          eStatus             = MDP_STATUS_OK;
  MDP_HwPrivateInfo  *psMDPHwPrivateInfo  = MDP_GETPRIVATEINFO();
  uint32              uMMUSidMask         = 0;

  MDP_LOG_FUNC_ENTRY("MDPInit", 0x00);

  MDP_OSAL_MEMZERO(psMDPHwPrivateInfo, sizeof(MDP_HwPrivateInfo));

  psMDPHwPrivateInfo->sEFIChipSetId = EFICHIPINFO_ID_UNKNOWN;

  if ((NULL == gpDSIInitSequenceBuffer ) ||
      (NULL == gpDSITermSequenceBuffer ))
  {
    gpDSIInitSequenceBuffer = (uint8*)MDP_OSAL_CALLOC(MDP_DSI_COMMAND_BUFFER_SIZE);
    gpDSITermSequenceBuffer = (uint8*)MDP_OSAL_CALLOC(MDP_DSI_COMMAND_BUFFER_SIZE);
  }

  if (NULL == gpDSIDscPpsBuffer )
  {
    gpDSIDscPpsBuffer = (uint8*)MDP_OSAL_CALLOC(MDP_DSI_DSC_PPS_TOTAL_PACKET_SIZE);
  }

  // Initialize I2C command buffer
  if ((NULL == gpI2CInitSequenceBuffer) || 
      (NULL == gpI2CTermSequenceBuffer))
  {
    gpI2CInitSequenceBuffer = (uint8*)MDP_OSAL_CALLOC(MDP_I2C_COMMAND_BUFFER_SIZE);
    gpI2CTermSequenceBuffer = (uint8*)MDP_OSAL_CALLOC(MDP_I2C_COMMAND_BUFFER_SIZE);
  }

  if ((NULL == gpDSIInitSequenceBuffer ) ||
      (NULL == gpDSITermSequenceBuffer ) || 
      (NULL == gpI2CInitSequenceBuffer)  ||
      (NULL == gpI2CTermSequenceBuffer)  ||
      (NULL == gpDSIDscPpsBuffer ))
  {
    eStatus = MDP_STATUS_NO_RESOURCES;
  }
  else if (NULL == pMDPInitParams)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    MDPPlatformParams     sPlatformParams;
    bool32                bSWRender  = FALSE;
    MDP_Display_IDType    eDisplayId = MDP_DISPLAY_PRIMARY;
    uint32                uNumValidDisplays = 0;

    if (MDP_INIT_FLAG_MINIMAL_INIT & uFlags)
    {
      //For minimal init do not clear the display context as it will be reused later.
    }
    else
    {
      // Default case is complete intialization, clear the display context.
      MDP_OSAL_MEMZERO(&gDisplayInfo, sizeof(gDisplayInfo));
    }

    // Need to know if the platform is hardware accelerated first. If it is not then we have to skip initialization of all HW.
    MDP_OSAL_MEMZERO(&sPlatformParams, sizeof(MDPPlatformParams));

    for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId <= MDP_DISPLAY_SECONDARY; eDisplayId++)
    {
      if (FALSE == pMDPInitParams->aSupportedDisplays[eDisplayId])
      {
        continue;
      }
      else if (MDP_STATUS_OK != (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_SW_RENDERER, &sPlatformParams)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPPlatformConfigure(MDPPLATFORM_CONFIG_SW_RENDERER) failed!\n");
        continue;
      }
      else
      {
        uNumValidDisplays++;
      }
    }

    if ((0    == uNumValidDisplays)  ||
        (TRUE == sPlatformParams.sPlatformInfo.bSWRender))
    {
      // Update SW Render flag
      bSWRender = TRUE;
    }
    
    // Update SW render status
    MDPSWRenderStatus(&bSWRender, MDP_SW_RENDER_STATUS_SET);

    // 
    // Start hardware initialization, fall back to SW renderer in this path if key hardware functions fail
    //
    if (FALSE == bSWRender)
    {

      //Get the platform Chip ID and catch in gsMDPHwPrivateInfo
      if (MDP_STATUS_OK == (eStatus = MDPPlatformConfigure(MDP_DISPLAY_PRIMARY, MDPPLATFORM_CONFIG_GETPLATFORMINFO, &sPlatformParams)))
      {
        psMDPHwPrivateInfo->sEFIChipSetId     = sPlatformParams.sPlatformInfo.sEFIChipSetId;
        psMDPHwPrivateInfo->sEFIChipSetFamily = sPlatformParams.sPlatformInfo.sEFIChipSetFamily;
        psMDPHwPrivateInfo->eEFIPlatformInfo  = sPlatformParams.sPlatformInfo.sEFIPlatformType.platform;
      }
        
      // Hardware path
      //
      if (MDP_STATUS_OK != eStatus)
      {
        // Platform detection failed, cannot continue propagate error to caller
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: Failed to detect platform ID!\n");
      } 
      else if (TRUE == Display_Utils_CheckPanelSkip())
      {
        //Panel override was set, either skip is forced by override 
        //or this panel is not supported in bootloader
        //Fall back to SW render mode
        bSWRender = TRUE;
      }
      else if (MDP_STATUS_OK != (eStatus = MDPSetCoreClock(0x0)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: Failed to setup MDP core clocks!\n");

        // Fall back to SW render mode
        bSWRender = TRUE;            
      }
      //Set MDSS base address
      else if (MDP_STATUS_OK != (eStatus = MDPPlatformSetMdssBase(sPlatformParams.sPlatformInfo.sEFIChipSetFamily)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: MDPPlatformSetMdssBase() failed!\n");   
            
        // Fall back to SW render mode
        bSWRender = TRUE;
      }
      else
      {
        HAL_MDP_InitConfigType sInitConfig;

        /* Initialize highest bank bit based on DDR type */
        MDP_OSAL_MEMZERO(&sInitConfig, sizeof(sInitConfig));
        sInitConfig.uGpuHighestMemoryBankBit = MDPGetHighestBankBit();

        if (HAL_MDSS_STATUS_SUCCESS != HAL_MDP_Init(&sInitConfig, DEAFAULT_MDP_INIT_FLAGS))
        {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: HAL_MDP_Init() failed!\n");

          // Fall back to SW render mode
          bSWRender = TRUE;
          eStatus = MDP_STATUS_HW_ERROR;
        }
        // Initialize the HW private info 
        else if (MDP_STATUS_OK != (eStatus = MDPInitHwPrivateInfo(psMDPHwPrivateInfo)))
        {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: MDPInitHwPrivateInfo() failed!\n");

          // Fall back to SW render mode
          bSWRender = TRUE;
        }
        else if (HAL_MDSS_STATUS_SUCCESS != HAL_MDP_TrafficCtrl_Init(NULL, 0))
        {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: HAL_MDP_TrafficCtrl_Init() failed!\n");  

          // Fall back to SW render mode
          bSWRender = TRUE;
          eStatus = MDP_STATUS_HW_ERROR;
        }
        else
        {
          // Hardware detected
          // - Setup based on the hardware configuration
              
          ExtDisp_AttrType   sExtDispAttr;
            
          // Populate the input parameters
          pMDPInitParams->uMDPVersionMajor    = psMDPHwPrivateInfo->sMDPVersionInfo.uMajorVersion;
          pMDPInitParams->uMDPVersionMinor    = psMDPHwPrivateInfo->sMDPVersionInfo.uMinorVersion;
          pMDPInitParams->uMDPVersionRevision = psMDPHwPrivateInfo->sMDPVersionInfo.uReleaseVersion;

          //For continuous splash feature, since frame buffer memory is shared between UEFI
          //and kernel, the MMU context need to be updated to enable sharing.
          //Ensure MMU is initialized only once when the DisplayDxe is loaded
          //to avoid multiple stream faults with dynamic SID programming.   

          if (MDP_INIT_FLAG_MMU_INIT & uFlags)
          {
            if (MDP_STATUS_OK != FindPlatformMMUSidMask(sPlatformParams.sPlatformInfo.sEFIChipSetFamily, &uMMUSidMask))
            {
              MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: Failed to find MMU SID mask for this platform!\n");
            }
            else if (MDP_STATUS_OK != MDP_SetupMMUSIDs(uMMUSidMask))
            {
              MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: Failed to setup MMU SIDs!\n");
            }
          }
              
          // Check the external display configuration.
          if (ExtDisp_SupportedByPlatform(&sExtDispAttr))
          {
            gDisplayInfo[MDP_DISPLAY_EXTERNAL].ePhysConnect          = sExtDispAttr.ePhysConnect;                
            pMDPInitParams->aSupportedDisplays[MDP_DISPLAY_EXTERNAL] = TRUE;
          }

          // If DISABLEDISPLAY variable is set, then disable primary display
          // Note: Make sure to check if external display is supported before proceeding
          if(TRUE == pMDPInitParams->aSupportedDisplays[MDP_DISPLAY_EXTERNAL])
          {
            if(TRUE == MDPPlatformGetDisableDisplay())
            {
              // DISABLEDISPLAY variable is set. Disable primary display
              pMDPInitParams->aSupportedDisplays[MDP_DISPLAY_PRIMARY]  = FALSE;
            }
          }
        }
      }
    }

    // Platform is configured for SW renderer, or hardware detection failed
    if (TRUE == bSWRender)
    {
      // Populate the input parameters
      pMDPInitParams->uMDPVersionMajor                         = 0;
      pMDPInitParams->uMDPVersionMinor                         = 0;
      pMDPInitParams->uMDPVersionRevision                      = 0;
      pMDPInitParams->aSupportedDisplays[MDP_DISPLAY_EXTERNAL] = FALSE;

      // Tell platform layer we are in SW render mode to by pass any hardware configuration
      MDP_OSAL_MEMZERO(&sPlatformParams, sizeof(MDPPlatformParams));
      sPlatformParams.sPlatformInfo.bSWRenderOverrride = TRUE;

      for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId <= MDP_DISPLAY_SECONDARY; eDisplayId++)
      {
        if (FALSE == pMDPInitParams->aSupportedDisplays[eDisplayId])
        {
          continue;
        }
        else if (MDP_STATUS_OK != (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_SW_RENDERER, &sPlatformParams)))
        {
          MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: MDPPlatformConfigure(MDPPLATFORM_CONFIG_SW_RENDERER) failed!\n");
        }
      }
    }
  }
  MDP_LOG_FUNC_EXIT("MDPInit()");   

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPPower()
*/
/*!
* \brief
*   This function will power up and initialize the interface needed for a particular display.
*
* \param [in] eDisplayId       - The display to initialize
*        [in] pMDPPowerParams  - Power configuration
*        [in] uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPPower(MDP_Display_IDType eDisplayId, MDP_PowerParamsType *pMDPPowerParams, uint32 uFlags)
{
    MDP_Status eStatus = MDP_STATUS_OK;

    MDP_LOG_FUNC_ENTRY("MDPPower()", eDisplayId);    

    if (NULL == pMDPPowerParams)
    {
      eStatus = MDP_STATUS_BAD_PARAM;
    }
    else if (TRUE == Display_Utils_CheckPanelSkip())
    {
      //Panel override was set, either skip is forced by override 
      //or this panel is not supported in bootloader
      // Fall back to SW render mode
    }
    else if (TRUE == pMDPPowerParams->bPowerOn)
    {
        MDPPlatformParams sPlatformParams;

        MDP_OSAL_MEMZERO(&sPlatformParams, sizeof(MDPPlatformParams));

        sPlatformParams.sPowerConfig.uFlags = uFlags;

        // Power up the respective displays
        if (MDP_STATUS_OK != (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_POWERUP, &sPlatformParams)))
        {
            MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPPlatformConfigure(MDPPLATFORM_CONFIG_POWERUP) failed!\n");   
        }
    }
    else if (FALSE == pMDPPowerParams->bPowerOn)
    {
        MDPPlatformParams sPlatformParams;

        MDP_OSAL_MEMZERO(&sPlatformParams, sizeof(MDPPlatformParams));

        sPlatformParams.sPowerConfig.uFlags = uFlags;

        // Power down the respective displays
        if (MDP_STATUS_OK != (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_POWERDOWN, &sPlatformParams)))
        {
            MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPPlatformConfigure(MDPPLATFORM_CONFIG_POWERDOWN) failed!\n");   
        }

        /* Update core clock and bandwidth */
        if (MDP_STATUS_OK != MDPUpdateCoreClockAndBandwidth(eDisplayId, 0, 0, FALSE))
        {
          MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPUpdateCoreClockAndBandwidth failed!\n");
        }        
    }

    MDP_LOG_FUNC_EXIT("MDPPower()");    

    return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPDetect()
*/
/*!
* \brief
*   This function will detect the presence of a display and supported modes.
*
* \param [in] eDisplayId       - The display to initialize
*        [in] MDPDetectParams  - Information regarding the hardware core
*        [in] uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPDetect(MDP_Display_IDType eDisplayId, MDP_DetectParamType *pMDPDetectParams, uint32 uFlags )
{
    MDP_Status           eStatus        = MDP_STATUS_OK;
    MDPPlatformPanelType eSelectedPanel = MDPPLATFORM_PANEL_NONE;

    MDP_LOG_FUNC_ENTRY("MDPDetect()", eDisplayId);
    
    if ((NULL == pMDPDetectParams) ||
        (eDisplayId >= MDP_DISPLAY_MAX))
    {
      eStatus = MDP_STATUS_BAD_PARAM;
    }
    else
    {
        MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

        // Handle each display
        switch (eDisplayId)
        {
        case MDP_DISPLAY_PRIMARY:
        case MDP_DISPLAY_SECONDARY:
            {              
              if (MDP_STATUS_OK == MDPDetectPanel(eDisplayId, pDisplayInfo))
              {
                 pMDPDetectParams->bDisplayDetected          = pDisplayInfo->bDetected;
                 pMDPDetectParams->uSupportedModes           = 1; // Only 1 mode is supported
                 pMDPDetectParams->aModeList[0].bInterlaced  = FALSE;
                 pMDPDetectParams->aModeList[0].uModeIndex   = 0;
                 pMDPDetectParams->aModeList[0].uWidth       = pDisplayInfo->uDisplayWidth;
                 pMDPDetectParams->aModeList[0].uHeight      = pDisplayInfo->uDisplayHeight;
                 eSelectedPanel                              = pDisplayInfo->eSelectedPanel;
                 
                 switch (pDisplayInfo->ePhysConnect)
                 {
                 case MDP_DISPLAY_CONNECT_PRIMARY_DSI_VIDEO:
                 case MDP_DISPLAY_CONNECT_PRIMARY_DSI_CMD:
                 case MDP_DISPLAY_CONNECT_SECONDARY_DSI_VIDEO:
                 case MDP_DISPLAY_CONNECT_SECONDARY_DSI_CMD:                
                    pMDPDetectParams->aModeList[0].uRefreshRate = pDisplayInfo->uAttrs.sDsi.uRefreshRate;

                    /* If DSC is enable setup MDP structures for DSC */
                    if (TRUE == pDisplayInfo->uAttrs.sDsi.bDSCEnable)
                    {
                      if (pDisplayInfo->uAttrs.sDsi.uDSCProfileID < MDP_DSC_PROFILEID_MAX)
                      {
                        MDPSetupDSCProperty(pDisplayInfo);
                      }
                      else
                      {
                        eStatus = MDP_STATUS_BAD_PARAM;
                      }
                    }
                    break;
                  case  MDP_DISPLAY_CONNECT_EDP:
                    if (MDP_STATUS_OK == (eStatus = DPDriver_Open(eDisplayId, uFlags)))
                    {
                        /*
                         * both width and height are 0 means use timing from edid
                         * here will assign both xx->aModeList[0].uWidth and xx->aModeList[0].uHeight
                         * with correct value from edid so that both pMode->HorizontalResolution and
                         * pMode->VerticalResolution can inherit correct value to set up frame buffer
                         * correctly at DisplayDxe_SetMode later
                         */
                        if ((0 == pDisplayInfo->uDisplayWidth) && 
                            (0 == pDisplayInfo->uDisplayHeight))
                        {
                           MDP_Panel_AttrType    sMode;

                           MDP_OSAL_MEMZERO(&sMode, sizeof(MDP_Panel_AttrType));
                           eStatus = DPDriver_GetModeInfo(&sMode);
                           if (MDP_STATUS_OK == eStatus)
                           {
                              pMDPDetectParams->aModeList[0].uWidth  = sMode.uDisplayWidth;
                              pMDPDetectParams->aModeList[0].uHeight = sMode.uDisplayHeight;
                           }
                        }
                    }
                    break;
                 default:
                    break;
                 }
              }

              if (MDP_STATUS_OK != eStatus)
              {
                MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: Panel detection failed. Selecting SWRender mode!\n");

                if (MDP_DISPLAY_CONNECT_EDP == pDisplayInfo->ePhysConnect)
                {
                  // Landscape mode
                  pMDPDetectParams->aModeList[0].uWidth  = MDP_DEFAULT_RESOLUTION_WIDTH;
                  pMDPDetectParams->aModeList[0].uHeight = MDP_DEFAULT_RESOLUTION_HEIGHT;
                }
                else
                {
                  // Portrait mode - swap width & height
                  pMDPDetectParams->aModeList[0].uWidth  = MDP_DEFAULT_RESOLUTION_HEIGHT;
                  pMDPDetectParams->aModeList[0].uHeight = MDP_DEFAULT_RESOLUTION_WIDTH;
                }

                pDisplayInfo->bSWRenderer              = TRUE;
                eStatus                                = MDP_STATUS_OK;
              }
            }
            break;

        case MDP_DISPLAY_EXTERNAL:
            {
              if (!MDPDetectExtPlugin(eDisplayId, pDisplayInfo, uFlags))
              {
                MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: External monitor not detected!\n");
              }
              else
              {
                MDP_Panel_AttrType    sMode;
                uint32                i;

                // DP detected 
                pDisplayInfo->bDetected            = TRUE;
                pDisplayInfo->uNumInterfaces       = MDP_INTERFACE_SINGLE;
                
                pMDPDetectParams->bDisplayDetected = TRUE;
                
                // Enumerate all modes
                for (i = 0; i < MDP_DISPLAY_MAX_MODES; i++)
                {
                  MDP_OSAL_MEMZERO(&sMode, sizeof(MDP_Panel_AttrType));
                  sMode.eDisplayId  = eDisplayId;
                  sMode.uModeId     = i;
                  if (MDP_STATUS_OK == ExtDisp_GetModeInfo(&sMode))
                  {
                    pMDPDetectParams->aModeList[i].uModeIndex   = i;
                    pMDPDetectParams->aModeList[i].uWidth       = sMode.uDisplayWidth;
                    pMDPDetectParams->aModeList[i].uHeight      = sMode.uDisplayHeight;
                    pMDPDetectParams->aModeList[i].uRefreshRate = sMode.uRefreshRate;
                    pMDPDetectParams->aModeList[i].bInterlaced  = FALSE;
                    pMDPDetectParams->uSupportedModes++;
                    MDP_Log_Message(MDP_LOGLEVEL_INFO, "MDPDetect: index=%d w=%d h=%d frate=%x\n",i, sMode.uDisplayWidth, sMode.uDisplayHeight, sMode.uRefreshRate); 
                  }
                  else
                  {
                    break;
                  }
                }
              }          
            }
            break;
        default:
            eStatus = MDP_STATUS_BAD_PARAM;
            break;
        }
    }
    
    MDP_LOG_FUNC_EXIT("MDPDetect()");    

    return eStatus;
}



/****************************************************************************
*
** FUNCTION: MDPSetMode()
*/
/*!
* \brief
*   This function setup the display for a particular mode.
*
* \param [in] eDisplayId       - The display to initialize
*        [in] MDPSetModeParams - Mode setup parameters
*        [in] uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPSetMode(MDP_Display_IDType eDisplayId, MDP_SetModeParamType *pMDPSetModeParams, uint32 uFlags )
{
  MDP_Status           eStatus      = MDP_STATUS_OK;
  MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

  MDP_LOG_FUNC_ENTRY("MDPSetMode()", eDisplayId); 

  if ((NULL == pMDPSetModeParams)     ||
      (eDisplayId >= MDP_DISPLAY_MAX))
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if (TRUE == Display_Utils_CheckPanelSkip())
  {
    /* Panel override was set, either skip is forced by override,
     * or this panel is not supported in bootloader.
     * Fall back to SW render mode, but cache the buffer information to pass to the kernel.
     */
    MDP_OSAL_MEMCPY(&pDisplayInfo->sFrameBuffer, &pMDPSetModeParams->sSurfaceInfo, sizeof(MDPSurfaceInfo));

    eStatus = MDP_STATUS_OK;
  }
  else if (TRUE != pDisplayInfo->bDetected)
  {
    eStatus = MDP_STATUS_NOT_SUPPORTED;
  }
  else if (TRUE == pDisplayInfo->bSWRenderer)
  {
    // Cache the current mode and surface information
    pDisplayInfo->uModeId  = pMDPSetModeParams->uModeIndex;
    MDP_OSAL_MEMCPY(&pDisplayInfo->sFrameBuffer, &pMDPSetModeParams->sSurfaceInfo, sizeof(MDPSurfaceInfo));

    // Display is in software rendering mode, don't initialize hardware and continue
    eStatus = MDP_STATUS_OK;
  }
  else
  {
    // Setup GPIOs (Low and high list)
    if (MDP_STATUS_OK != (eStatus = MDPSetGPIOState(pDisplayInfo)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPSetGPIOState Failed!\n");
    }

    // Setup MDP control paths
    if (MDP_STATUS_OK != (eStatus = MDPSetupPipe(pDisplayInfo, &pMDPSetModeParams->sSurfaceInfo)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPSetupPipe Failed!\n");
    }
    else if (MDP_STATUS_OK != (eStatus = MDPPanelInit(eDisplayId, pMDPSetModeParams->uModeIndex, pDisplayInfo)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPPanelInit Failed!\n");
    }
    else
    {
      // Dynamically update core clock and bandwidth to meet requirement of fps > 60Hz
      if (MDP_STATUS_OK != MDPUpdateCoreClockAndBandwidth(eDisplayId, pMDPSetModeParams->sSurfaceInfo.uWidth, pMDPSetModeParams->sSurfaceInfo.uHeight, TRUE))
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPUpdateCoreClockAndBandwidth Failed!\n");
      }
      
      if (MDP_STATUS_OK != (eStatus = MDPStartPipe(pDisplayInfo))) // Kick start the displays
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPStartPipe Failed!\n");
      }
      else
      {
        // Cache the current mode and surface information
        pDisplayInfo->uModeId  = pMDPSetModeParams->uModeIndex;
        pDisplayInfo->bModeSet = TRUE;
        MDP_OSAL_MEMCPY(&pDisplayInfo->sFrameBuffer, &pMDPSetModeParams->sSurfaceInfo, sizeof(MDPSurfaceInfo));

        // If DSI video transfer should be on during DCS transactions then send command for sending the init sequence.
        if (TRUE == pDisplayInfo->uAttrs.sDsi.bForceCmdInVideoHS)
        {
          if (MDP_STATUS_OK != MDPPanelSendCommandSequence(pDisplayInfo, MDP_PANEL_COMMAND_INIT, NULL, 0))
          {
            MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPPanelSendCommandSequence() failed to send INIT sequence!\n");
            pDisplayInfo->uInitFailures++;
          }
          /* If DSC is enabled then send the PPS command to the panel */
          if (TRUE == pDisplayInfo->uAttrs.sDsi.bDSCEnable) 
          {
            if (MDP_STATUS_OK != MDPPanelSendCommandSequence(pDisplayInfo, MDP_PANEL_COMMAND_PPS, NULL, 0))
            {
              MDP_Log_Message (MDP_LOGLEVEL_WARN, "DisplayDxe: MDPPanelSendCommandSequence() failed to send INIT sequence!\n");
              pDisplayInfo->uInitFailures++;
            }
          }
        }
      }
    }
  }
  
  MDP_LOG_FUNC_EXIT("MDPSetMode()"); 

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPSetProperty()
*/
/*!
* \brief
*   This function will configure a specific property of the display
*
* \param [in] eDisplayId       - The display to initialize
*        [in] eProperty        - The particular property to set
*        [in] MDPSetModeParams - Mode setup parameters
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPSetProperty(MDP_Display_IDType eDisplayId, MDP_Display_Property eProperty, MDP_PropertiesParamType *pMDPPropertiesParams)
{
  MDP_Status           eStatus      = MDP_STATUS_OK;

  MDP_LOG_FUNC_ENTRY("MDPSetProperty()", eProperty);        
    
  if (eDisplayId >= MDP_DISPLAY_MAX)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

    switch (eProperty)
    {
    case MDP_DISPLAY_PROPERTY_BACKLIGHT:
      {
        MDPPlatformParams  sPlatformParams;
        uint32             uDefaultBacklightLevel = pMDPPropertiesParams->uBacklightLevel;
        
        // Here, if default backlight level (non zero unsigned integer) is defined by panelcfg XML tags (<BacklightDefault>..</BacklightDefault>), 
        // then it will override default pcd backlight level 
        // Check if input backlight level is out of range
        if(uDefaultBacklightLevel > MDP_DISPLAY_MAX_BRIGHTNESS)
        {
          // Validate backlight level defined by panelcfg XML
          if((pDisplayInfo->sBacklightConfig.uLevel > 0)&&
             (pDisplayInfo->sBacklightConfig.uLevel <= MDP_DISPLAY_MAX_BRIGHTNESS))
          {
            // Override the PCD defualt backlight level 
            uDefaultBacklightLevel = pDisplayInfo->sBacklightConfig.uLevel;
          }
          else
          {
            // Either We haven't defined backlight in panelcfg, or defined backlight value is invalid
            uDefaultBacklightLevel = PcdGet32(PcdBacklightLevel);
          }
        }
        
        // Setup any other display parameters
        MDP_OSAL_MEMZERO(&sPlatformParams, sizeof(MDPPlatformParams));
        
        // Configure backlight parameters. 
        sPlatformParams.sBacklightConfig.bEnable                        = TRUE;
        sPlatformParams.sBacklightConfig.eBacklightType                 = pDisplayInfo->sBacklightConfig.eBacklightType;
        sPlatformParams.sBacklightConfig.uBacklightCntrl.eBacklightCtrl = pDisplayInfo->sBacklightConfig.uBacklightCntrl.eBacklightCtrl;
        sPlatformParams.sBacklightConfig.uLevel                         = uDefaultBacklightLevel;
        sPlatformParams.sBacklightConfig.uNumBits                       = pDisplayInfo->sBacklightConfig.uNumBits;
        
        // Backlight control type specific functionality
        switch (pDisplayInfo->sBacklightConfig.eBacklightType)
        {
          case MDP_PANEL_BACKLIGHTTYPE_I2C:
            {
              // Setup backlight I2C configuration 
              MDP_OSAL_MEMCPY(&sPlatformParams.sBacklightConfig.uBacklightCntrl.sI2CConfig, &pDisplayInfo->uAttrs.sDsi.sI2CConfig, sizeof(MDP_I2C_Configuration));
            }
            break;

          default:
            break;
        }

        if (MDP_STATUS_OK == (eStatus = MDPPlatformConfigure(eDisplayId, MDPPLATFORM_CONFIG_SETBACKLIGHT, &sPlatformParams)))
        {
          // Cache current backlight level
          pDisplayInfo->uBacklightLevel = uDefaultBacklightLevel;
        }
      }
      break;

    case MDP_DISPLAY_PROPERTY_FIRMWAREENV:
      {
        UINT32 uFrameBufferAddr;
        UINT32 uFrameBufferSize;
      
        if(MDP_STATUS_OK != (eStatus = MDP_SaveFirmwareEnvironmentVariable(eDisplayId)))
        {
          MDP_Log_Message (MDP_LOGLEVEL_WARN, "MDPSystem: MDP_SaveFirmwareEnvironmentVariable failed.\n");
        }

        /* Functions below can fail but we can continue */
        if (EFI_SUCCESS != Display_Utils_GetContinuousSplashInfo(&uFrameBufferAddr, &uFrameBufferSize))
        {
          MDP_Log_Message (MDP_LOGLEVEL_WARN, "MDPSystem: Display_Utils_GetContinuousSplashInfo failed.\n");
        }
        else if (MDP_STATUS_OK != MDP_SetDisplayBootConfig(uFrameBufferAddr, uFrameBufferSize)) 
        {        
          MDP_Log_Message (MDP_LOGLEVEL_WARN, "MDPSystem: MDP_SetDisplayBootConfig failed.\n");
        }
      }
      break;  

    case MDP_DISPLAY_PROPERTY_MODE_INFO:
      {
         MDP_HwPrivateInfo *psMDPHwPrivateInfo = MDP_GETPRIVATEINFO();
         uint32             ModeIndex          =  pMDPPropertiesParams->sModeParams.uModeIndex;

         switch (eDisplayId)
         {
           case MDP_DISPLAY_PRIMARY:
           case MDP_DISPLAY_SECONDARY:
             /*
              * if edp is the primary dispay
              * populated the mode # 0 timing into PanelInfo
              */
              if (pDisplayInfo->ePhysConnect ==  MDP_DISPLAY_CONNECT_EDP)
              {
                 /* both width and height are 0 means panle timing is derived from edid */
                 if (pDisplayInfo->uDisplayWidth == 0 &&
                     pDisplayInfo->uDisplayHeight == 0)
                 {
                    /* invalid xml file, use panel timing from EDID */
                    pDisplayInfo->eDisplayFlags |= MDP_PANEL_FLAG_TIMING_FROM_EDID;

                    eStatus = DPDriver_GetModeInfo(pDisplayInfo);      /* populated PanelInfo from edid */
                 }
              }
              break;
            case MDP_DISPLAY_EXTERNAL:
              /*
               * External monitor supports more than one mode,
               * populated the selected mode timing info PanelInfo
               */
               pDisplayInfo->uModeId = ModeIndex;
               eStatus = ExtDisp_GetModeInfo(pDisplayInfo); /* populate panelInfo from edid */
            break;
            default:
            break;   
         }

         // Check if we need Dual pipe for this panel
         if ((NULL != psMDPHwPrivateInfo->pDeviceCaps) &&
             (pDisplayInfo->uDisplayWidth > psMDPHwPrivateInfo->pDeviceCaps->pResolutionCaps->uMaxLayerWidthPx))
         {
             pDisplayInfo->uNumMixers = MDP_DUALPIPE_NUM_MIXERS;
         }
      }
      break;

    case MDP_DISPLAY_PROPERTY_POWER_STATE:
      {
        /* Cache the current display power state information */
        pDisplayInfo->bDisplayPwrState  =  pMDPPropertiesParams->bDisplayPwrState;
        break;
      }
    case MDP_DISPLAY_PROPERTY_ABL_INTERFACE_INIT:
      {
        /* Initialize Display context which will be used to create panel configuration string for ABL later */
        Display_Utils_Initialize(pMDPPropertiesParams->pSupportedDisplayList);
        
        break;
      }
    case MDP_DISPLAY_PROPERTY_SURFACE_RECT:
      {
         if (TRUE == pDisplayInfo->bModeSet)
         {
           MDPSurfaceInfo *pSurfaceInfo = NULL;

           /* Only pass a surface if it is valid, otherwise NULL means the surface address programming is unchanged */
           if ((MDP_PIXEL_FORMAT_NONE != pMDPPropertiesParams->sModeParams.sSurfaceInfo.ePixelFormat) &&
               (pMDPPropertiesParams->sModeParams.sSurfaceInfo.uWidth > 0)                            &&
               (pMDPPropertiesParams->sModeParams.sSurfaceInfo.uHeight > 0))
            {
               pSurfaceInfo =  &pMDPPropertiesParams->sModeParams.sSurfaceInfo;
            }
            
           /* Configure a new source surface and/or cropping rectangle */
           if (EFI_SUCCESS != (eStatus = MDPSetupSourcePipe(pDisplayInfo, pSurfaceInfo, &pMDPPropertiesParams->sModeParams.sRectInfo)))
           {
               MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: Error configuring a new surface/rect %r\n", eStatus);
           }
         }
         else
         {
           MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: Unable to change surface/rect.  Mode has not been set.\n");
         }
      }
      break;
    default:
      eStatus = MDP_STATUS_BAD_PARAM;
      break;
    }
  }

  MDP_LOG_FUNC_EXIT("MDPSetProperty()");

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPGetProperty()
*/
/*!
* \brief
*   This function will retrieve a specific property of the display
*
* \param  [in] eDisplayId           - The display to initialize
*         [in] eProperty            - The particular property to set
*         [in] pMDPPropertiesParams - Property parameters
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPGetProperty(MDP_Display_IDType eDisplayId, MDP_Display_Property eProperty, MDP_PropertiesParamType *pMDPPropertiesParams)
{
  MDP_Status           eStatus      = MDP_STATUS_OK;

  MDP_LOG_FUNC_ENTRY("MDPGetProperty()", eProperty);

  if (eDisplayId >= MDP_DISPLAY_MAX)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

    switch (eProperty)
    {
      case MDP_DISPLAY_PROPERTY_BACKLIGHT:
      {
        /* Retrieve the current cached backlight level */
        pMDPPropertiesParams->uBacklightLevel  =  pDisplayInfo->uBacklightLevel;
        break;
      }
    
      case MDP_DISPLAY_PROPERTY_POWER_STATE:
      {
        /* Retrieve the current cached display state information */
        pMDPPropertiesParams->bDisplayPwrState  =  pDisplayInfo->bDisplayPwrState;
        break;
      }

      case MDP_DISPLAY_PROPERTY_MODE_INFO:
      {
        /* Retrieve the current cached display mode information */
        pMDPPropertiesParams->sModeParams.uModeIndex = pDisplayInfo->uModeId;
        MDP_OSAL_MEMCPY(&pMDPPropertiesParams->sModeParams.sSurfaceInfo, &pDisplayInfo->sFrameBuffer, sizeof(MDPSurfaceInfo));
        break;
      }

      case MDP_DISPLAY_PROPERTY_DETECTION_INFO:
      {
        /* Retrieve the current cached display detection information */
        pMDPPropertiesParams->bDisplayDetected = pDisplayInfo->bDetected;      
        break;
      }

      case MDP_DISPLAY_PROPERTY_DISPLAY_CONFIG:
      {
        /* Update display configuration info */
        eStatus = MDPDetectPanel(eDisplayId, pDisplayInfo);
        break;
      }

      default:
      { 
        eStatus = MDP_STATUS_BAD_PARAM;
        break;
      }
    }
  }

  MDP_LOG_FUNC_EXIT("MDPGetProperty()");

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPDeInit()
*/
/*!
* \brief
*   This function will de-initializes the panel interfaces
*
* \param [in]  eDisplayId       - Display to de-initialize
* \param [in]  uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPDeInit(MDP_Display_IDType eDisplayId, uint32 uFlags)
{
  MDP_Status           eStatus      = MDP_STATUS_OK;

  MDP_LOG_FUNC_ENTRY("MDPDeInit()", eDisplayId);

  if (eDisplayId >= MDP_DISPLAY_MAX)
  {
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else 
  {
    MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

    if(TRUE == pDisplayInfo->bSWRenderer)
    {
      /* do nothing if display is in SW rendering mode, skip HW configuration */
    }
    else
    {
      /* Handle interface specific differences */
      switch (pDisplayInfo->ePhysConnect)
      {
        case MDP_DISPLAY_CONNECT_PRIMARY_DSI_VIDEO:
        case MDP_DISPLAY_CONNECT_PRIMARY_DSI_CMD:      
        case MDP_DISPLAY_CONNECT_SECONDARY_DSI_VIDEO:
        case MDP_DISPLAY_CONNECT_SECONDARY_DSI_CMD:
          
          /* If DSI video transfer should be on during DCS transactions then send command for sending the termination sequence. */
          if (TRUE == pDisplayInfo->uAttrs.sDsi.bForceCmdInVideoHS)
          {
            if (MDP_STATUS_OK != MDPPanelSendCommandSequence(pDisplayInfo, MDP_PANEL_COMMAND_TERM, NULL, 0))
            {
              MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: MDPPanelSendCommandSequence() failed to send TERM sequence!\n");
            }
          }
          break;
          
         default:
          break;
      }

      /* Turn off the display timing engines */
      if (MDP_STATUS_OK != (eStatus = MDPStopPipe(pDisplayInfo)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPPanelDeInit() failed! Status: %d\n", eStatus);      
      }
    
    
      /* Turn off the display controller and panel */
      if (MDP_STATUS_OK != (eStatus = MDPPanelDeInit(pDisplayInfo)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPPanelDeInit() failed! Status: %d\n", eStatus);  
      }

      /* Halt all Vbif AXI */
      if (HAL_MDSS_STATUS_SUCCESS != HAL_MDP_Term(0))
      {
        MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: HAL_MDP_Term() failed!\n");
        eStatus = MDP_STATUS_HW_ERROR;
      }
    }
  }

  MDP_LOG_FUNC_EXIT("MDPDeInit()");

  return eStatus;
}



/****************************************************************************
*
** FUNCTION: MDPTerm()
*/
/*!
* \brief
*   This function will deinitialize the MDP core and free all resources.
*
* \param [in]  uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPTerm(uint32 uFlags)
{
  MDP_Panel_AttrType  *pDisplayInfo = NULL;
  MDP_Status           eStatus      = MDP_STATUS_OK;

  MDP_LOG_FUNC_ENTRY("MDPTerm()", 0x00);

  /* Turn off core clock */
  if (MDP_STATUS_OK != (eStatus = MDPDisableClocks(MDP_CLOCKTYPE_CORE)))
  {
    MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDP Disable Core Clock failed with Status(%d)!\n", eStatus);
  }

  if (NULL != (pDisplayInfo = MDP_GET_DISPLAYINFO(MDP_DISPLAY_PRIMARY)))
  {
    /* Turn off dsi0 clock */
    if (MDP_STATUS_OK != (eStatus = MDPDisableClocks(MDP_CLOCKTYPE_DSI0)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDP Disable Dsi0 Clock failed with Status(%d)!\n", eStatus);
    }

    /* Turn off dsi1 clock */
    if (MDP_STATUS_OK != (eStatus = MDPDisableClocks(MDP_CLOCKTYPE_DSI1)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDP Disable Dsi1 Clock failed with Status(%d)!\n", eStatus);
    }
  }

  if (NULL != (pDisplayInfo = MDP_GET_DISPLAYINFO(MDP_DISPLAY_EXTERNAL)))
  {
    /* Turn off hdmi clock */
    if (MDP_STATUS_OK != (eStatus = MDPDisableClocks(MDP_CLOCKTYPE_HDMI)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDP Disable HDMI Clock failed with Status(%d)!\n", eStatus);
    }

    /* Turn off dp clock */
    if (MDP_STATUS_OK != (eStatus = MDPDisableClocks(MDP_CLOCKTYPE_DP)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDP Disable DP Clock failed with Status(%d)!\n", eStatus);
    }
  }

  MDP_LOG_FUNC_EXIT("MDPTerm()");

  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDPExitBoot()
*/
/*!
* \brief
*   This function performs house cleaning before UEFI exit
*
* \param [in]  uFlags           - Reserved
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPExitBoot(uint32 uFlags)
{
  MDP_Panel_AttrType  *pDisplayInfo         = NULL;
  MDP_Status           eStatus              = MDP_STATUS_OK;
  bool32               bSeamlessSplash      = TRUE;
  MDP_Display_IDType   eDisplayId           = MDP_DISPLAY_PRIMARY;

  /* If seamless splash is not required, turn off the display before leaving */
  MDP_PowerParamsType  sPowerParams;

  for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId <= MDP_DISPLAY_EXTERNAL; eDisplayId++)
  {
    if (FALSE == MDP_SUPPORTED_DISPLAY(eDisplayId))
    {
      continue;
    }
    else
    {
      pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);

      if (MDP_PANEL_FLAG_DISABLE_SEAMLESS_SPLASH &  pDisplayInfo->eDisplayFlags)
      {
        bSeamlessSplash = FALSE;
      }

      if ((FALSE == bSeamlessSplash) &&
          (TRUE  == pDisplayInfo->bDisplayPwrState))
      {
        MDP_OSAL_MEMZERO(&sPowerParams, sizeof(MDP_PowerParamsType));
        sPowerParams.bPowerOn = FALSE;

        // DeInit the panel interfaces before exiting
        if (MDP_STATUS_OK != (eStatus = MDPDeInit(eDisplayId, 0x0)))
        {
          MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPExitBoot: Display deInit failed with status(%d)!\n", eStatus);
        }

        // Turn off MDP powers before exiting
        if (MDP_STATUS_OK != (eStatus = MDPPower(eDisplayId, &sPowerParams, 0x0)))
        {
           MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPExitBoot: Disable common display panel power failed with status(%d)!\n", eStatus);
        }

        // Turn off MDP powers before exiting
        if (MDP_STATUS_OK != (eStatus = MDPPower(eDisplayId, &sPowerParams, POWERCONFIG_FLAGS_PANEL_POWER)))
        {
          MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPExitBoot: Disable specific display panel power failed with status(%d)!\n", eStatus);
        }        
      }

      if (NULL != pDisplayInfo->uAttrs.sDsi.pInitBuffer)
      {
        MDP_OSAL_FREE(pDisplayInfo->uAttrs.sDsi.pInitBuffer);
        pDisplayInfo->uAttrs.sDsi.pInitBuffer = NULL;
      }

      if (NULL != pDisplayInfo->uAttrs.sDsi.pTermBuffer)
      {
        MDP_OSAL_FREE(pDisplayInfo->uAttrs.sDsi.pTermBuffer);
        pDisplayInfo->uAttrs.sDsi.pTermBuffer = NULL;
      }

      if (NULL != pDisplayInfo->uAttrs.sDsi.pDSCPpsBuffer)
      {
        MDP_OSAL_FREE(pDisplayInfo->uAttrs.sDsi.pDSCPpsBuffer);
        pDisplayInfo->uAttrs.sDsi.pDSCPpsBuffer = NULL;
      }
    }
  }

  if (FALSE == bSeamlessSplash)
  {
    // Turn off MDP clocks before exiting
    if (MDP_STATUS_OK != (eStatus = MDPTerm(0x0)))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPExitBoot: Turn off MDP clocks failed with Status(%d)!\n", eStatus);    
    }
  }

  if (NULL != gpDSIInitSequenceBuffer)
  {
    MDP_OSAL_FREE(gpDSIInitSequenceBuffer);
    gpDSIInitSequenceBuffer = NULL;
  }

  if (NULL != gpDSITermSequenceBuffer)
  {
    MDP_OSAL_FREE(gpDSITermSequenceBuffer);
    gpDSITermSequenceBuffer = NULL;
  }

  if (NULL != gpDSIDscPpsBuffer)
  {
    MDP_OSAL_FREE(gpDSIDscPpsBuffer);
    gpDSIDscPpsBuffer = NULL;
  }

  if (NULL != gpI2CInitSequenceBuffer)
  {
    MDP_OSAL_FREE(gpI2CInitSequenceBuffer);
    gpI2CInitSequenceBuffer = NULL;
  }

  if (NULL != gpI2CTermSequenceBuffer)
  {
    MDP_OSAL_FREE(gpI2CTermSequenceBuffer);
    gpI2CTermSequenceBuffer = NULL;
  }
  
  // Store display pll codes
  Display_Utils_StorePLLCodes();
  
  return MDP_STATUS_OK;
}

/****************************************************************************
*
** FUNCTION: MDPSetCoreClock()
*/
/*!
* \brief
*   This function will setup the MDP core clock, enable footswitch, and restore TZ of register access
*
* \param [in]  uFlags           
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPSetCoreClock(uint32 uFlags)
{
  MDP_Status eStatus = MDP_STATUS_OK;

  MDP_LOG_FUNC_ENTRY("MDPSetCoreClock()", 0x00);

  /* Turn on the core clock */
  if (MDP_STATUS_OK != (eStatus = MDPSetupClocks(MDP_CLOCKTYPE_CORE, NULL)))
  {
     MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPSetupClocks() failed!\n");
  }

  MDP_LOG_FUNC_EXIT("MDPSetCoreClock()");

  return eStatus;
}


/****************************************************************************
*
** FUNCTION: MDPCalculateCoreClockAndBandwidth()
*/
/*!
* \brief
*   calculate core clock and bandwidth
*
* \param [in]  eDisplayId          -  the specific display device        
*        [in]  uSrcWidthPixels     -  source width in pixels 
*        [in]  uSrcHeightPixels    -  source height in pixels
*        [in]  uRefreshRate        -  refresh rate in Hz 
*        [out] pCoreClock          -  pointer to store core clock value
*        [out] pBandwidth          -  pointer to store bandwidth value
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPCalculateCoreClockAndBandwidth(MDP_Display_IDType eDisplayId, uint32 uSrcWidthPixels, uint32 uSrcHeightPixels, uint32 uRefreshRate, uint32 *pCoreClock, uint64 *pBandwidth)
{
  MDP_Status                eStatus                  = MDP_STATUS_OK;
  uint32                    uNewCoreClk              = 0;
  MDP_Panel_AttrType       *pDisplayInfo             = MDP_GET_DISPLAYINFO(eDisplayId);
  uint32                    uCoreClockFloor          = MDPGetMinCoreClock();

  if ((NULL == pDisplayInfo) ||
      (NULL == pCoreClock)   ||
      (NULL == pBandwidth))
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPCalculateCoreClockAndBandwidth invalid parameter!\n");
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else if (0 == uRefreshRate)
  {
    /* In case of MDPPower(off) will enter this branch */
    pDisplayInfo->sDynamicResourceConfig.uCoreClock = 0;
    pDisplayInfo->sDynamicResourceConfig.uBandwidth = 0;
  }
  else
  {
    float  fSmartTransferTimeMargin = MDP_SMART_TRANSFER_TIME_MARGIN;
    float  fNewTransferTime         = (1.0 / uRefreshRate) - fSmartTransferTimeMargin;
    
    if (0 < fNewTransferTime)
    {
      uint32 uDstWidthActive          = pDisplayInfo->uDisplayWidth;
      uint32 uDstHeightActive         = pDisplayInfo->uDisplayHeight;
      uint32 uDstHeightTotal          = uDstHeightActive + 
                                        pDisplayInfo->sActiveTiming.uVsyncPulseWidthLns +
                                        pDisplayInfo->sActiveTiming.uVsyncBackPorchLns +
                                        pDisplayInfo->sActiveTiming.uVsyncFrontPorchLns;
      uint32 uBytePerPixel            = MDP_GET_PIXELFMTMAP(pDisplayInfo->eColorFormat).uBitsPerPixel / 8; 
      uint64 uBandwidth;
      uint32 uNewRefreshRate          = (uint32)(1.0 / fNewTransferTime);
      uint64 uBandwidthFloor;

      /* The worst case of the core clock value */  
      uNewCoreClk = (uDstWidthActive + pDisplayInfo->sActiveTiming.uHsyncFrontPorchDclk + pDisplayInfo->sActiveTiming.uHsyncBackPorchDclk + pDisplayInfo->sActiveTiming.uHsyncPulseWidthDclk) * uDstHeightTotal * uNewRefreshRate;

      /* Handle dual pipe here */
      if (2 == pDisplayInfo->uNumMixers)
      {
        uNewCoreClk /= 2;
      }

      /* Limit the Core Clock to be alwasys larger than the floor value */
      if (uNewCoreClk < uCoreClockFloor)
      {
        uNewCoreClk = uCoreClockFloor;
      }

      /* Calculate bandwidth value for this specific display */
      uBandwidth      = (uint64)((uint64)uSrcWidthPixels *  uSrcHeightPixels * uBytePerPixel * uNewRefreshRate);
      uBandwidthFloor = uNewCoreClk * uBytePerPixel * 1.05;
      if (uBandwidth < uBandwidthFloor)
      {
        uBandwidth = uBandwidthFloor;
      }

      /* Pass data back to caller */
      *pCoreClock = uNewCoreClk;
      *pBandwidth = uBandwidth;
    }
    else
    {
      *pCoreClock = 0;
      *pBandwidth = 0;
       eStatus    = MDP_STATUS_NO_RESOURCES;
    }
  }

  return eStatus; 
}


/****************************************************************************
*
** FUNCTION: MDPUpdateCoreClockAndBandwidth()
*/
/*!
* \brief
*   Wrapper to update both bandwidth and core clock
*
* \param [in]  eDisplayId         -  the specific display device        
*        [in]  uSrcWidthPixels    -  source width in pixels
*        [in]  uSrcHeightPixels   -  source height in pixels
*        [in]  bPowerOn           -  flag to indicate whethre it is in power process
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPUpdateCoreClockAndBandwidth(MDP_Display_IDType eDisplayId, uint32 uSrcWidthPixels, uint32 uSrcHeightPixels, bool32 bPowerOn)
{
  MDP_Status                eStatus         = MDP_STATUS_OK;
  MDP_Panel_AttrType       *pDisplayInfo    = MDP_GET_DISPLAYINFO(eDisplayId);
  uint32                    uAggregatedCoreClock;
  uint64                    uAggregatedBandwidth;

  if (NULL == pDisplayInfo)
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPUpdateCoreClockAndBandwidth: invalid parameter\n");
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    if (FALSE == bPowerOn)
    {
      pDisplayInfo->sDynamicResourceConfig.uCoreClock = 0;
      pDisplayInfo->sDynamicResourceConfig.uBandwidth = 0;
    }
    else
    {
      uint32 uRefreshRate;
      uint32 uTmpCoreClock;
      uint64 uTmpBandwidth;

      if (MDP_STATUS_OK != MDPGetRefreshRate(pDisplayInfo, &uRefreshRate))
      {
        uRefreshRate = 60;
      }

      if (MDP_STATUS_OK != (eStatus = MDPCalculateCoreClockAndBandwidth(eDisplayId, uSrcWidthPixels, uSrcHeightPixels, uRefreshRate, &uTmpCoreClock, &uTmpBandwidth)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPUpdateCoreClockAndBandwidth: MDPCalculateCoreClockAndBandwidth failed\n");
      }
      else
      {
        /* Save calculated value to this specific display device */
        pDisplayInfo->sDynamicResourceConfig.uCoreClock = uTmpCoreClock;
        pDisplayInfo->sDynamicResourceConfig.uBandwidth = uTmpBandwidth;
      }
    }

    /* Update clock and bandwidth in both power on/off cases */
    if (MDP_STATUS_OK == eStatus)
    {
      /* Loop all panels, get the maximal core clock and total bandwidth that can satify all panels/devices */
      if (MDP_STATUS_OK != (eStatus = MDPGetAggregatedCoreAndBandwidth(&uAggregatedCoreClock, &uAggregatedBandwidth)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPUpdateCoreClockAndBandwidth: MDPGetAggregatedCoreAndBandwidth failed\n");
      }
      else if (MDP_STATUS_OK != (eStatus = MDPUpdateDynamicClocks(MDP_DYNAMIC_CLOCKTYPE_CORE, uAggregatedCoreClock)))
      {
         MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPUpdateCoreClockAndBandwidth: MDPUpdateDynamicClocks failed!\n");
      }
      else if (MDP_STATUS_OK != (eStatus = MDPUpdateDynamicBandwidth(uAggregatedBandwidth)))
      {
        MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPUpdateCoreClockAndBandwidth: MDPUpdateDynamicBandwidth failed!\n");
      }
    }
  }

  return eStatus;
}


#ifdef MDP_ENABLE_PROFILING 
/****************************************************************************
*
** FUNCTION: MDPProfiler()
*/
/*!
* \brief
*   This function performs the profiling of functions 
*
* \param [in]  pFuncName        - Function name
* \param [in]  uParam1          - Display ID, Property or Mode info depending on the function  
* \param [in]  bEntry           - Function entry or exit. True - entry; False - exit;
*
* \retval MDP_Status
*
****************************************************************************/
MDP_Status  MDPProfiler(uint8 *pFuncName, uint32 uParam1, bool32 bEntry)
{
  MDP_Status      eStatus     =  MDP_STATUS_OK; 
  static uint32   uStartTime;
  static uint32   uTotalDriverTime;

  /* Function entry */
  if (bEntry)
  {
    /* Start time */   
    uStartTime = MDP_GetTimerCountUS();
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLibProfile: Entry[%a][%d]\n", pFuncName, uParam1);  
  }    
  else 
  {
    /* Function exit */ 
    uint32          uEndTime;
    uint32          uTotalFuncTime = 0;   

    /* End time */ 
    uEndTime = MDP_GetTimerCountUS();
    /* Function execution time(ms) */ 
    uTotalFuncTime = (uEndTime - uStartTime);   
    /* Total driver execution time(ms) */
    uTotalDriverTime += uTotalFuncTime;

    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLibProfile: Exit[%a][%dus function time][%dus total time]\n", pFuncName, uTotalFuncTime, uTotalDriverTime);
  }

  return eStatus;
}
#endif


/*=========================================================================
     Local Static Variables
==========================================================================*/

static bool32 MDPDetectExtPlugin(MDP_Display_IDType eDisplayId, MDP_Panel_AttrType  *pPanelInfo, uint32 Flags)
{
  bool32     bDetected   = FALSE;
  MDP_Status eStatus       = MDP_STATUS_OK;

  if (NULL == pPanelInfo)
  {      
   MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPDetectExtPlugin: Null pointer passed\n");  
  }
  else
  {
    eStatus =  ExtDisp_Init(eDisplayId, Flags);
    if(MDP_STATUS_OK == eStatus)
    {
      // Get Valid Mode information for mode at Index 0
      if (ExtDisp_IsDisplayPlugged(eDisplayId))
      {
        pPanelInfo->eDisplayId    = MDP_DISPLAY_EXTERNAL;
        pPanelInfo->ePhysConnect  = gDisplayInfo[MDP_DISPLAY_EXTERNAL].ePhysConnect;
        bDetected                 = TRUE;

        // Clear the GPIO list with 0xFF to signify an empty list.
        // External display has not implemented the parser to clear default fields
        MDP_OSAL_MEMSET(&pPanelInfo->uDefaultGPIOState, 0xFF, sizeof(pPanelInfo->uDefaultGPIOState));
      }
      else
      {
        ExtDisp_Close(eDisplayId);
      }
    }    
  }
  
  return bDetected;
}


/****************************************************************************
*
** FUNCTION: MDPPlatformGetDisableDisplay()
*/
/*!
* \brief
*   Returns TRUE if DISABLEDISPLAY is set and FALSE otherwise
*
*
* \retval bool32
*
****************************************************************************/
static bool32 MDPPlatformGetDisableDisplay(void)
{
  UINT32       uValue        =  0;
  bool32       bDisableDisp  = FALSE; 
  MDP_Status   eStatus       = MDP_STATUS_OK;

  eStatus =  MDP_Display_GetVariable_Integer (L"DISABLEDISPLAY", &uValue);

  if ((MDP_STATUS_OK ==  eStatus) &&
      (uValue         >  0))
  {
    bDisableDisp = TRUE;
  }
  
  return bDisableDisp;
}

/****************************************************************************
*
** FUNCTION: MDPPlatformSetMdssBase()
*/
/*!
* \brief
*   Set MDSS base address
*
*
* \retval MDP_Status
*
****************************************************************************/
static MDP_Status MDPPlatformSetMdssBase(EFIChipInfoFamilyType  sEFIChipSetFamily)
{
  MDP_Status                          Status  = MDP_STATUS_OK;
  HAL_MDP_SWMappedHWBaseAddressesType sMDSSAddress;

  MDP_OSAL_MEMZERO(&sMDSSAddress, sizeof(sMDSSAddress));

  sMDSSAddress.uMdpAddress = MDP_MDSS_HWIOBaseAddr((uint32)sEFIChipSetFamily); /* retrieve mdss base addr */

  if (sMDSSAddress.uMdpAddress == 0)
  {
     Status  = MDP_STATUS_FAILED;
     MDP_Log_Message(MDP_LOGLEVEL_ERROR, "DisplayDxe: Error!!! falied to allocate MDSS base addr\n", sMDSSAddress.uMdpAddress);
  }
  else
  {
     // Setup the HAL base address
     HAL_MDSS_SetBaseAddress(&sMDSSAddress);
  }

  return Status;
}

/****************************************************************************
*
** FUNCTION: FindPlatformMMUSidMask()
*/
/*!
* \brief
*   Find MMUSidMask according to the platform
*
*
* \retval MDP_Status
*
****************************************************************************/
static MDP_Status FindPlatformMMUSidMask (EFIChipInfoFamilyType	eEFIChipSetFamily, uint32 *pMMUSidMask)
{
  MDP_Status Status = MDP_STATUS_NOT_SUPPORTED;

  if (NULL == pMMUSidMask)
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPLib: FindPlatformMMUSidMask - Ivalid pMMuSidMask!\n");
    Status = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    for(uint32 uCount = 0; uCount< MDSS_BASEADDRESSMAPINGS_MAX; uCount++)
    {
      if(asChip_MMUSidMasks[uCount].sEFIChipSetFamily == eEFIChipSetFamily)
      {
        *pMMUSidMask = asChip_MMUSidMasks[uCount].uSidMask;
        Status	    = MDP_STATUS_OK;
        break; 	
      }
    }
  }
  return Status;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: MDPSetupDSCProperty()
**
** DESCRIPTION:
**   Configuration parameters that are required to correctly setup the
**   DSC related configuration like topology flags and resolution info
**   for each compression encoder.
**
** ---------------------------------------------------------------------- */
void MDPSetupDSCProperty(MDP_Panel_AttrType *pPanelInfo)
{
  HAL_MDP_DSCInfoType             sDSCInfo;
  HAL_MDP_DSCConfigType           sDSCConfig;
  uint32                          uCount;
  uint32                          uDSCEngineCount = 1;
  
  MDP_OSAL_MEMZERO(&sDSCInfo, sizeof(HAL_MDP_DSCInfoType));
  MDP_OSAL_MEMZERO(&sDSCConfig, sizeof(HAL_MDP_DSCConfigType));
  MDP_OSAL_MEMZERO(pPanelInfo->uAttrs.sDsi.pDSCPpsBuffer, MDP_DSI_DSC_PPS_TOTAL_PACKET_SIZE);

  pPanelInfo->uAttrs.sDsi.uDSCBpc              = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].uBitsPerComponent;
  pPanelInfo->uAttrs.sDsi.uDSCBpp              = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].uBitsPerPixel;
  pPanelInfo->uAttrs.sDsi.uDSCCompressionRatio = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].uCompressionRatio;
  pPanelInfo->uAttrs.sDsi.bDSCLayerMixSplit    = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].bLMSplitEnable;
  pPanelInfo->uAttrs.sDsi.bDSCBlockPred        = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].bBlockPredEnable;
  pPanelInfo->uAttrs.sDsi.uDSCEncodersNum      = gDscProfileModes[pPanelInfo->uAttrs.sDsi.uDSCProfileID].uEncodersNum;

  sDSCInfo.pDSCEncoderPacket = &pPanelInfo->uAttrs.sDsi.sDSCEncPktType;

  /* Setup the EncParams */
  /* Configure the start address where the HAL will create the PPS command payload data */
  sDSCInfo.pDSCEncoderPacket->pPacketData    = pPanelInfo->uAttrs.sDsi.pDSCPpsBuffer + MDP_DSI_DSC_HEADER_SIZE + MDP_DSI_DSC_XML_HEADER_SIZE;
  sDSCInfo.pDSCEncoderPacket->pEncoderParams = &pPanelInfo->uAttrs.sDsi.sDSCEncParams;

  /* Populate DSC Version */
  sDSCInfo.pDSCEncoderPacket->pEncoderParams->uDSCVersionMajor = pPanelInfo->uAttrs.sDsi.uDSCMajor;
  sDSCInfo.pDSCEncoderPacket->pEncoderParams->uDSCVersionMinor = pPanelInfo->uAttrs.sDsi.uDSCMinor;
  sDSCInfo.pDSCEncoderPacket->pEncoderParams->uDSCVersionScr   = pPanelInfo->uAttrs.sDsi.uDSCScr;

  /* Determine the type of DSC encoder configuration */
  sDSCInfo.pDSCEncoderCfg                         = &pPanelInfo->uAttrs.sDsi.sDSCEncCfg;
  sDSCInfo.pDSCEncoderCfg->pEncoderParams         = &pPanelInfo->uAttrs.sDsi.sDSCEncParams;
  sDSCInfo.pDSCEncoderCfg->bUserProvidedEncParams = FALSE;

  sDSCInfo.pDSCEncoderCfg->eCompressionRatio      = pPanelInfo->uAttrs.sDsi.uDSCCompressionRatio;

  /* Configure the Slice Width and height */
  sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceHeight = pPanelInfo->uAttrs.sDsi.uDSCSliceHeight;
  sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth  = pPanelInfo->uAttrs.sDsi.uDSCSliceWidth;

  sDSCInfo.pDSCEncoderCfg->pEncoderParams->uBitsPerComponent =  pPanelInfo->uAttrs.sDsi.uDSCBpc; 
  sDSCInfo.pDSCEncoderCfg->pEncoderParams->uBitsPerPixel     = pPanelInfo->uAttrs.sDsi.uDSCBpp;
  sDSCInfo.pDSCEncoderCfg->pEncoderParams->bBlockPredEnable  = pPanelInfo->uAttrs.sDsi.bDSCBlockPred;

  if ((0 == sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceHeight) ||
      (sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceHeight > pPanelInfo->uDisplayHeight))
  {
    /* Default Slice height to 16*/
    sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceHeight = 16;
    MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPSetupDSCProperty: Slice Height not defined in XML, use default\n");
  }

  if ((0 == sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth) ||
      (sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth > pPanelInfo->uDisplayWidth))
  {
    /* Default slice width is half of the panel width */
    sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth = pPanelInfo->uDisplayWidth / 2;
    MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPLib: MDPSetupDSCProperty: Slice Width not defined in XML, use default\n");
  }

  if (MDP_INTERFACE_SINGLE == pPanelInfo->uNumInterfaces)
  {
    if (0 == pPanelInfo->uAttrs.sDsi.bDSCLayerMixSplit)
    {
      /* Single encoder and single dsi Based on the profile id setup the following */
      sDSCInfo.pDSCEncoderCfg->bPingPongSplitMUXActive    = 0;
      sDSCInfo.pDSCEncoderCfg->bSplitDispActive           = 0;
      sDSCInfo.pDSCEncoderCfg->bSplitMuxActive            = 0;
      sDSCInfo.pDSCEncoderCfg->uInputFrameHeightInPixels  = pPanelInfo->uDisplayHeight;
      sDSCInfo.pDSCEncoderCfg->uInputFrameWidthInPixels   = pPanelInfo->uDisplayWidth;

    }
    else
    {
      /* Place holder when we implement the 2.5k Panel with DSC with dual pipe/mixer */
      /* Single DSI interface, Layer Mixer Split Config */

      sDSCInfo.pDSCEncoderCfg->bPingPongSplitMUXActive = 0;
      sDSCInfo.pDSCEncoderCfg->bSplitDispActive        = 0;

      if (1 == pPanelInfo->uAttrs.sDsi.uDSCEncodersNum)
      {
        sDSCInfo.pDSCEncoderCfg->bSplitMuxActive       = 0;
        pPanelInfo->uAttrs.sDsi.uDSC3DMux              = 1;     /* use 3D mux */
        uDSCEngineCount                                = 1;
      }
      else
      {
        sDSCInfo.pDSCEncoderCfg->bSplitMuxActive       = 1;
        uDSCEngineCount                                = 2;
      }

      sDSCInfo.pDSCEncoderCfg->uInputFrameHeightInPixels = pPanelInfo->uDisplayHeight;

      /* Total Width is multiplied by 2 */
      sDSCInfo.pDSCEncoderCfg->uInputFrameWidthInPixels = pPanelInfo->uDisplayWidth;
    }

  }
  else if (MDP_INTERFACE_DUAL == pPanelInfo->uNumInterfaces)
  {
    if (pPanelInfo->eDisplayFlags & MDP_PANEL_FLAG_ENABLE_QUAD_PIPE)
    {
      sDSCInfo.pDSCEncoderCfg->bPingPongSplitMUXActive   = 0;
      sDSCInfo.pDSCEncoderCfg->bSplitMuxActive           = 0;
      sDSCInfo.pDSCEncoderCfg->uInputFrameHeightInPixels = pPanelInfo->uDisplayHeight;
      sDSCInfo.pDSCEncoderCfg->uInputFrameWidthInPixels  = pPanelInfo->uDisplayWidth;

      if (pPanelInfo->uAttrs.sDsi.uDSCEncodersNum == MDP_QUADPIPE_NUM_MIXERS)
      {
        pPanelInfo->uAttrs.sDsi.uDSC3DMux                 = 0;
        uDSCEngineCount                                   = 4;
        sDSCInfo.pDSCEncoderCfg->bSplitDispActive         = 0;
        sDSCInfo.pDSCEncoderCfg->bSplitMuxActive          = 1;
        sDSCInfo.pDSCEncoderCfg->uInputFrameWidthInPixels = pPanelInfo->uDisplayWidth / 2;
      }
    }
    /* Place holder when we implement 4k Panel with DSC */
    else
    {
      /* Single Pipe Config(one encoder) -> each DSI  */   
      sDSCInfo.pDSCEncoderCfg->bPingPongSplitMUXActive = 0;
      sDSCInfo.pDSCEncoderCfg->bSplitDispActive        = 1;
      sDSCInfo.pDSCEncoderCfg->bSplitMuxActive         = 0;

      sDSCInfo.pDSCEncoderCfg->uInputFrameHeightInPixels = pPanelInfo->uDisplayHeight;
      sDSCInfo.pDSCEncoderCfg->uInputFrameWidthInPixels  = pPanelInfo->uDisplayWidth;

      /* Need to setup both the DSC encoders and the split mux  */
      uDSCEngineCount                                    = 2;
    }
  }

  if ((MDP_DISPLAY_CONNECT_PRIMARY_DSI_VIDEO == pPanelInfo->ePhysConnect) ||
      ( MDP_DISPLAY_CONNECT_SECONDARY_DSI_VIDEO == pPanelInfo->ePhysConnect))
  {
    sDSCInfo.pDSCEncoderCfg->eInterfaceMode = HAL_MDP_INTERFACE_MODE_VIDEO;
  }
  else if ((MDP_DISPLAY_CONNECT_PRIMARY_DSI_CMD == pPanelInfo->ePhysConnect) ||
           (MDP_DISPLAY_CONNECT_SECONDARY_DSI_CMD == pPanelInfo->ePhysConnect))
  {
    sDSCInfo.pDSCEncoderCfg->eInterfaceMode = HAL_MDP_INTERFACE_MODE_COMMAND;
  }

  sDSCConfig.pDSCEncoderCfg                                   = sDSCInfo.pDSCEncoderCfg;

  /* Calculate the DSC configuration settings for HAL */
  HAL_MDP_DSC_GetPropery(0, &sDSCInfo, 0x00);

  if (0 == pPanelInfo->uAttrs.sDsi.uDSCSlicePerPacket)
  {
    /* If DSIDSCSlicePerPacket is not set in panel xml file, then use the default calculated value of that,
     * otherwise use the value of DSIDSCSlicePerPacket from panel xml file */
    pPanelInfo->uAttrs.sDsi.uDSCSlicePerPacket = sDSCInfo.pDSCEncoderCfg->uSlicePerPacket;
  }
  else if (0 != sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth)
  {
    if (pPanelInfo->uAttrs.sDsi.uDSCSlicePerPacket > (pPanelInfo->uDisplayWidth / sDSCInfo.pDSCEncoderCfg->pEncoderParams->uSliceWidth))
    {
      /* If the value of DSIDSCSlicePerPacket from panel xml is out of range, then use the default calculated value as well. */
      pPanelInfo->uAttrs.sDsi.uDSCSlicePerPacket = sDSCInfo.pDSCEncoderCfg->uSlicePerPacket;
    }
  }

  for (uCount = 0; uCount < uDSCEngineCount; uCount++)
  {
    /* Commit the DSC registers */
    HAL_MDP_DSC_Setup(uCount + 1, &sDSCConfig, 0x00);
  }
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: MDPSetGPIOState()
**
** DESCRIPTION:
**   Configuration default GPIO states
**
** ---------------------------------------------------------------------- */
static MDP_Status MDPSetGPIOState(MDP_Panel_AttrType *pDisplayInfo)
{
  MDP_Status    eStatus     = MDP_STATUS_OK;
  
  for (uint32 uGPIOState = 0;uGPIOState <= 1;uGPIOState++)
  {
    MDPPlatformParams sPlatformConfig;

    MDP_OSAL_MEMZERO(&sPlatformConfig, sizeof(MDPPlatformParams));
    sPlatformConfig.sGPIOState.eGPIOType = MDPPLATFORM_GPIOTYPE_TLMM;
    sPlatformConfig.sGPIOState.pGPIOList = (uint32*)&(pDisplayInfo->uDefaultGPIOState[uGPIOState]);
    sPlatformConfig.sGPIOState.uListSize = MDP_MAX_GPIO_LIST_ENTRIES;
    sPlatformConfig.sGPIOState.uState = uGPIOState;

    if (MDP_STATUS_OK != MDPPlatformConfigure(pDisplayInfo->eDisplayId, MDPPLATFORM_CONFIG_SETGPIOSTATE, &sPlatformConfig))
    {
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "DisplayDxe: Failed to configure list of GPIOs to %d\n", uGPIOState);
      eStatus = MDP_STATUS_FAILED;
      break;
    }
  }
  return eStatus;
}

/* ---------------------------------------------------------------------- */
/**
** FUNCTION: MDPGetHighestBankBit()
**
** DESCRIPTION:
**   Get the highest bankbit based on DDR Type
**
** ---------------------------------------------------------------------- */
static uint32 MDPGetHighestBankBit()
{
  uint32 uHighestBankBit;
  uint32 uDDRType = MDP_GetDDRType();
  
  switch (uDDRType)
  {
    case 4:
      uHighestBankBit = 15;
      break;
    case 5:
      uHighestBankBit = 16;
      break;
    default:
      uHighestBankBit = 16;
      MDP_Log_Message(MDP_LOGLEVEL_WARN, "WARNING: unsupported uDDRType=%d, use DDR5 as default\n", uDDRType);
      break;
  }

  return uHighestBankBit;
}

/****************************************************************************
*
** FUNCTION: MDPGetAggregatedCoreAndBandwidth()
*/
/*!
* \brief
*    Loop all the panels and get the largest core clock value 
*
* \param [out]    pMaxCoreClock - pointer to store maximal core clock         
*        [out]    pBandwidth    - pointer to store total bandwidth  
* \retval         MDP_Status
*
****************************************************************************/
static MDP_Status MDPGetAggregatedCoreAndBandwidth(uint32 *pMaxCoreClock, uint64 *pBandwidth)
{
  MDP_Display_IDType eDisplayId;
  uint32             uMaxCoreClock     = 0;
  uint64             uTotalBandwidth   = 0;
  MDP_Status         eStatus           = MDP_STATUS_OK;

  if ((NULL == pMaxCoreClock) ||
      (NULL == pBandwidth))
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPGetAggregatedCoreAndBandwidth: invalid parameter");
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    /* Loop all the panels and get the largest core clock value */
    for (eDisplayId = MDP_DISPLAY_PRIMARY; eDisplayId < MDP_DISPLAY_MAX; eDisplayId++)
    {
      MDP_Panel_AttrType  *pDisplayInfo = MDP_GET_DISPLAYINFO(eDisplayId);
      
      if (NULL == pDisplayInfo)
      {
        continue;
      }
      else if ((0 == pDisplayInfo->sDynamicResourceConfig.uCoreClock) ||
               (0 == pDisplayInfo->sDynamicResourceConfig.uBandwidth))
      {
        continue;
      }
      else
      { 
        uTotalBandwidth += pDisplayInfo->sDynamicResourceConfig.uBandwidth;

        /* Get the max core clock of all displays */
        if (pDisplayInfo->sDynamicResourceConfig.uCoreClock > uMaxCoreClock)
        {
          uMaxCoreClock = pDisplayInfo->sDynamicResourceConfig.uCoreClock;
        }
      }
    }
    
    *pMaxCoreClock = uMaxCoreClock;
    *pBandwidth    = uTotalBandwidth;
  }
  
  return eStatus;
}

/****************************************************************************
*
** FUNCTION: MDPRoundUpQ1616()
*/
/*!
* \brief
*    round up the Q16.16 format data  
*
* \param [in]    data    - Q16.16 format data that needs be round up         
* \retval                  the rounded up value
*
****************************************************************************/
static uint32 MDPRoundUpQ1616(uint32 data)
{
  return ((data + 0x8000) >> 16);
}
/****************************************************************************
*
** FUNCTION: MDPGetAggregatedCoreAndBandwidth()
*/
/*!
* \brief
*    Loop all the panels and get the largest core clock value 
*
* \param [in]    pDisplayInfo    - the specific display device         
*        [out]   pRefreshRate    - pointer to store refresh rate 
* \retval                          MDP_Status
*
****************************************************************************/
static uint32 MDPGetRefreshRate(MDP_Panel_AttrType *pDisplayInfo, uint32 *pRefreshRate)
{
  MDP_Status                eStatus         = MDP_STATUS_OK;

  if (NULL == pDisplayInfo ||
     (NULL == pRefreshRate))
  {
    MDP_Log_Message(MDP_LOGLEVEL_ERROR, "MDPGetRefreshRate: parameter is NULL\n");
    eStatus = MDP_STATUS_BAD_PARAM;
  }
  else
  {
    /* Get refresh rate according to different phy connect type */
    switch(pDisplayInfo->ePhysConnect)
    {
      case MDP_DISPLAY_CONNECT_PRIMARY_DSI_VIDEO:
      case MDP_DISPLAY_CONNECT_PRIMARY_DSI_CMD:
      case MDP_DISPLAY_CONNECT_SECONDARY_DSI_VIDEO:
      case MDP_DISPLAY_CONNECT_SECONDARY_DSI_CMD:
        *pRefreshRate = MDPRoundUpQ1616(pDisplayInfo->uAttrs.sDsi.uRefreshRate);
         break;

      case MDP_DISPLAY_CONNECT_DP:
      case MDP_DISPLAY_CONNECT_DP_1:
      case MDP_DISPLAY_CONNECT_EDP:
        *pRefreshRate = MDPRoundUpQ1616(pDisplayInfo->uAttrs.sDp.uRefreshRate);
         break;
      default:
        *pRefreshRate = 60;
         MDP_Log_Message(MDP_LOGLEVEL_WARN, "MDPGetRefreshRate: Invalid interface, ePhysConnect=%d, set refresh rate to 60Hz for default\n", pDisplayInfo->ePhysConnect);
         break;
    }
  }

  return eStatus;
}

