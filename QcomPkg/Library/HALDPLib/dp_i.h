#ifndef _DP_I_H
#define _DP_I_H

/*=============================================================================
 
  File: dp_i.h
 
  Internal header file for DP Host
  
 
 Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
 =============================================================================*/

/*---------------------------------------------------------------------------------------------------------------------
 * Include Files
 *-------------------------------------------------------------------------------------------------------------------*/
#include "dp_types.h"
#include "dp_host.h"
#include "dp_spec.h"
#include "hal_dp.h"
#include "dp_system.h"
#include "edid.h"

/* -------------------------------------------------------------------------------------------------------------------- */
#define DISP_OSAL_Malloc(x1, x2)           MDP_OSAL_CALLOC(x1)
#define DISP_OSAL_Free(x1)                 MDP_OSAL_FREE(x1)
#define DISP_OSAL_MemZero(x1, x2)          MDP_OSAL_MEMZERO(x1, x2)
#define DISP_OSAL_MemSet(x1, x2, x3)       MDP_OSAL_MEMSET(x1, x2, x3)
#define DISP_OSAL_MemCpyEx(x1, l1, x2, l2) MDP_OSAL_MEMCPY(x1, x2, l2)

#define DISP_OSAL_LOG(fmt, ...)            MDP_Log_Message(MDP_LOGLEVEL_ERROR, fmt, ##__VA_ARGS__)
#define DISP_OSAL_LOG_WARN(fmt, ...)       MDP_Log_Message(MDP_LOGLEVEL_ERROR, fmt, ##__VA_ARGS__)
#define DISP_OSAL_LOG_INFO(fmt, ...)       MDP_Log_Message(MDP_LOGLEVEL_INFO, fmt, ##__VA_ARGS__)

/* --------------------------------------------------------------------------------------------------------------------
Enumerated types
---------------------------------------------------------------------------------------------------------------------*/

/* Dirty bits to indicate which configuration is changed and needs to be applied to hardware */
typedef enum
{
   DP_DIRTYFIELD_NONE                             = 0,
   DP_DIRTYFIELD_PANELMODE                        = DP_BIT(0),        /* Panel Mode has changed                    */
   DP_DIRTYFIELD_LINK_RATE                        = DP_BIT(1),        /* Desired Link rate changed                 */
   DP_DIRTYFIELD_SINK_ATTRIB                      = DP_BIT(2),        /* Sink attributes changed                   */
   DP_DIRTYFIELD_TU_PARAMETERS                    = DP_BIT(3),        /* TU related parameters changed             */
   DP_DIRTYFIELD_MAINLINK_PACKET                  = DP_BIT(4),        /* Main link attributes changed              */
   DP_DIRTYFIELD_STREAM_ATTRIB                    = DP_BIT(5),        /* Stream attributes changed                 */
   DP_DIRTYFIELD_LANE_NUMBER                      = DP_BIT(6),        /* Desired Lane Number changed               */
   DP_DIRTYFIELD_DPCD_CONFIG                      = DP_BIT(7),        /* DPCD config changed                       */
   DP_DIRTYFIELD_HPD_POLARITY                     = DP_BIT(8),        /* HPD Polarity changed                      */   
   DP_DIRTYFIELD_BPC                              = DP_BIT(8),        /* Bit depth changed                         */
} DP_DeviceDirtyFieldType;


/* Link training status types */
typedef enum
{    
   DP_LINK_TRAINING_STATUS_NONE                   = 0,
   DP_LINK_TRAINING_STATUS_CLK_RECOVERY_DONE      = DP_BIT(0),        /* clock recovery is done                    */
   DP_LINK_TRAINING_STATUS_CHANNEL_EQ_DONE        = DP_BIT(1),        /* Channel equalization is done              */
   DP_LINK_TRAINING_STATUS_SYMBOL_LOCKED          = DP_BIT(2),        /* Symbol is locked                          */
   DP_LINK_TRAINING_STATUS_INTERLANE_ALIGN_DONE   = DP_BIT(3),        /* Inter-lane align is done                  */ 
   DP_LINK_TRAINING_STATUS_MAX,
   DP_LINK_TRAINING_STATUS_32BIT                  = 0x7FFFFFFF
} DP_LinkTrainingStatusType;


/* --------------------------------------------------------------------------------------------------------------------
** Macros and Struct
---------------------------------------------------------------------------------------------------------------------*/
#define MAX_AUX_CMD_BUFFER                         144

#define DPHOST_GET_DEVICE_CTX(_deviceId_)          (&(gDpSharedData.sDeviceCtx[((_deviceId_)<DP_DEVICE_MAX)?(_deviceId_):DP_DEVICE_ID_ALT_MODE_0]))

#define DP_EDID_START_ADDRESS                      (0x50)   //Start address of Display Port EDID base blocks.
#define DP_EDID_BLOCK_SIZE                         (0x80)   //Each page size in the EDID ROM
#define DP_EDID_MAX_NUM_OF_BLOCKS                  (0x80)   //Maximum number of pages for EDID structure
#define DP_EDID_MAX_BUF_SIZE                       (DP_EDID_BLOCK_SIZE * DP_EDID_MAX_NUM_OF_BLOCKS)
#define DP_EDID_EXT_BLOCK_NUM_OFFSET               (0x7E)
#define DP_EDID_SEGMENT_ADDRESS                    (0x30)

/* Link rates supported by DP Host */
#define DP_LINK_SYMBOL_RATE_KHZ_PER_LANE_162MBps   162000
#define DP_LINK_SYMBOL_RATE_KHZ_PER_LANE_270MBps   270000
#define DP_LINK_SYMBOL_RATE_KHZ_PER_LANE_540MBps   540000
#define DP_LINK_SYMBOL_RATE_KHZ_PER_LANE_810MBps   810000
#define DP_PLL_OUTPUT_RATE_810MHZ                  810
#define DP_PLL_OUTPUT_RATE_1350MHZ                 1350

#define DP_MAX_RESOLUTION_WIDTH                    4096
#define DP_MAX_RESOLUTION_HEIGHT                   4096
#define DP_MAX_REFRESH_RATE_HZ                     120


#define MAX_DP_PANEL_MODE                          16

/* Get the color info from DP_PixelFormatType */
#define DPHOST_GETPIXELFMT(_pixelFmt_)             (gsDPPixelFormatInfo[((_pixelFmt_)<DP_PIXEL_FORMAT_MAX)?(_pixelFmt_):DP_PIXEL_FORMAT_NONE])
#define DPHOST_GETCTX_FROM_HANDLE(hHandle)         ((DP_DeviceCtxType*) hHandle)

/* --------------------------------------------------------------------------------------------------------------------
** Preprocessor Definitions and Constants
** ----------------------------------------------------------------------------------------------------------------- */

/* color info */
typedef struct 
{
   uint32                   uBitsPerPixel;                      /* Bits per pixel                                   */
   uint32                   uBitsPerComponent;                  /* Bits per each color component (R/G/B, Y/U/V)     */
} DP_PixelFormat_Info;

/* Present Device context for DP device */
typedef struct 
{
  DP_DeviceIDType           eDeviceID;                          /* Which DP device in case there should be multiple */
  bool32                    bInitialized;                       /* Is device handle initialized                     */
  uint32                    uNumLanes;                          /* Number of lanes enabled : 1, 2 or 4              */
  uint32                    uLinkRateInKhz;                     /* Link rate                                        */
  uint32                    uPixelClkInKhz;                     /* Pixel clk                                        */
  bool32                    bSynchronousClk;                    /* Are pixel clk and link clk in synchronous mode   */
  bool32                    bEnableSSCMode;                     /* Enable spread spectrum clocking (downspread)     */
  uint32                    uModeIndex;                         /* Present mode                                     */
  bool32                    bPluggedIn;                         /* Is external display connected                    */
  bool32                    bInvertedPlug;                      /* USB type-C plug orientation (TRUE:porselect = 1) */
  bool32                    bEDIDObtained;                      /* Has EDID been read from display                  */ 
  uint32                    uNumModes;                          /* Number of modes supported by display             */
  DP_PanelInfoType          sPanelInfo[MAX_DP_PANEL_MODE];      /* Panel info for all the display modes             */
  DP_DPCDSinkCapType        sSinkDPCDCap;                       /* Sink capabilities read from DPCD                 */
  DP_LinkTrainingType       eLinkTrainingType;                  /* Type of link training requested by user          */
  uint32                    uVoltageSwingLevel;                 /* Current voltage swing level set to Sink          */
  uint32                    uPreEmphasisLevel;                  /* Current pre-emphasis level set to Sink           */
  uint32                    uMaxVoltSwingLvl;                   /* Max voltage swing level supported by sink        */
  uint32                    uMaxPreemphLvl;                     /* Max pre-emphasis level supported by sink         */
  uint32                    uDirtyBits;                         /* Which config has changed                         */
  uint8                     uAUXCmdBuffer[MAX_AUX_CMD_BUFFER];  /* Shared buffer for AUX Cmd Buffer                 */
  uint32                    uAUXCmdBufferCurrentSize;           /* Current queued Command size in Cmd buffer        */
  uint32                    uAUXNumOfTransaction;               /* Current number of AUX Transaction                */
  DP_TransactionModeType    eAUXTransactionTypeInQueue;         /* Current AUX Transaction type in CMD FIFO         */
  uint32                    uMaxAUXCmdFifoLen;                  /* The Max AUX CMD FIFO length                      */
  DP_EDIDDataType           *sSinkEDIDData;                     /* DP sink EDID data                                */
  uint8                     auEDIDCache[DP_EDID_MAX_BUF_SIZE];  /* DP Sink EDID data                                */
  uint32                    uEDIDDataLength;                    /* Length of EDID data                              */
  EDID_VendorInfoType       sVendorInfo;                        /* Vendor specific info                             */
  uint32                    uSinkCount;                         /* Sink count on connected port                     */
  bool32                    bCPReady;                           /* Indicate when all Sink devices are CP-capable    */
  DP_ControllerIDType       eControllerID;                      /* DP controller index                              */
  bool32                    bLinkLost;                          /* Link lost                                        */
  uint32                    uBitDepth;                          /* Sink device bit depth                            */
} DP_DeviceCtxType;

/* Transfer Unit related params */
typedef struct
{
   uint32                   uVisWidth;                          /* Screen width                                     */
   uint32                   uPixelClockInKhz;                   /* Pixel clock freq in Khz                          */
   uint32                   uLinkClockInKhz;                    /* Link clock freq in Khz                           */
   uint32                   uNumberOfLanes;                     /* Number of Lanes in use                           */
   uint32                   uBPP;                               /* Bits per pixel                                   */
} DP_TUSizePararmType;

/* Device context for all the devices */
typedef struct 
{
  bool32                    bInitialized;                       /* Flag indicating if DP driver is initialized      */
  DP_DeviceCtxType          sDeviceCtx[DP_DEVICE_MAX];          /* Present context of this device                   */
} DP_DeviceDataType;


/*---------------------------------------------------------------------------------------------------------------------
 * Global Data Definitions
 *-------------------------------------------------------------------------------------------------------------------*/
extern DP_PixelFormat_Info                    gsDPPixelFormatInfo[DP_PIXEL_FORMAT_MAX];
extern DP_DeviceDataType                      gDpSharedData;




/**********************************************************************************************************************

FUNCTION: DP_LinkTraining()
   
   This function will read from AUX/I2c channel 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   eLinkTrainingType                -[in ] The type of Link training
   uFlags                           -[in ] Reserved

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_LinkTraining(DP_DeviceCtxType         *pDeviceCtx,
                          DP_LinkTrainingType       eLinkTrainingType,
                          DP_FlagsType              uFlags);


/**********************************************************************************************************************

FUNCTION: DP_ReadSinkDPCDCap()
   
   This function will read Sink Capability Data from DPCD over AUX Channel

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psDPCDSinkCap                    -[out] Pointer to DPCD Sink Capability Data struct.

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_ReadSinkDPCDCap(DP_DeviceCtxType    *pDeviceCtx,
                             DP_DPCDSinkCapType  *psDPCDSinkCap);

/**********************************************************************************************************************

FUNCTION: DP_ReadSinkDPCDStatus()
   
   This function will read Sink Status Raw Data from DPCD over AUX Channel

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psDPCDSinkStatus                 -[out] Pointer to DPCD Sink Status Data struct.

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_ReadSinkDPCDStatus(DP_DeviceCtxType       *pDeviceCtx,
                                DP_DPCDSinkStatusType  *psDPCDSinkStatus);

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDLink()
   
   This function will Write the link setting to panel DPCD 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDLink(DP_DeviceCtxType    *pDeviceCtx);

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDTrainingPattern()
   
   This function will select the training pattern for link training to panel DPCD 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   eTraingPattern                   -[in ] Link Training pattern 

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDTrainingPattern(DP_DeviceCtxType               *pDeviceCtx,
                                          DP_DPCDTrainingPatternSetType   eTraingPattern);

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDLevels()
   
   This function will select the training Voltage Swing Level and Pre-emphasis Level.

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   uDesiredVoltageSwingLevel        -[in ] The desired Voltage Swing level for link training
   uDesiredPreEmphasisLevel         -[in ] The desired pre-emphasis level for link training

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDLevels(DP_DeviceCtxType    *pDeviceCtx,
                                 uint32               uDesiredVoltageSwingLevel,
                                 uint32               uDesiredPreEmphasisLevel);

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDPower()

   This function will set the sink power state. i.e Power on/off for main link or AUX

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   ePowerState                      -[in ] Sink power state to be set

Return:
   DP_Status

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDPower(DP_DeviceCtxType      *pDeviceCtx,
                                DP_DPCDPowerStateType  ePowerState);

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDDownSpreadEnabled()
   
   This function will indicate that downspread has been enabled on host side.

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDDownSpreadEnabled(DP_DeviceCtxType    *pDeviceCtx);

/**********************************************************************************************************************

FUNCTION: DP_ParseSinkEDID()
   
   This function will parse the EDID info from the Raw EDID Data. 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context

Return:
   DP_Status

**********************************************************************************************************************/
DP_Status  DP_ParseSinkEDID(DP_DeviceCtxType    *pDeviceCtx);

/**********************************************************************************************************************

FUNCTION: DP_ReadSinkEDIDRaw()

   This function will read EDID Raw Data from Sink over I2c.

Parameters:
   pDeviceCtx                         -[in] Pointer to device context

Return:
   DP_Status

**********************************************************************************************************************/
DP_Status  DP_ReadSinkEDIDRaw(DP_DeviceCtxType    *pDeviceCtx);

/**********************************************************************************************************************

FUNCTION: DP_CalculateTU()
   
   This function will calculate the TU based the the lane #, link clock, pixel clock, color format. 

Parameters:
   psDisplayInfo                    -[in ] Panel info
   psTUConfig                       -[out] The TU parameters 

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_CalculateTU(DP_TUSizePararmType             *psDisplayInfo,
                         HAL_DP_TUConfigType             *psTUConfig);

/**********************************************************************************************************************

FUNCTION: DP_CalculateLink()
   
   This function will Calculate the Link settings, such as clock freq, number of lane needed.

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psDPCDSinkCap                    -[in ] Pointer to sink DPCD capabilites
   psPanelInfo                      -[in ] Pointer to panel info corresponding to current mode
   pPixClkInfo                      -[out] Pointer to pixel clock info (dividers, etc.)

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_CalculateLink(DP_DeviceCtxType         *pDeviceCtx,
                            DP_DPCDSinkCapType       *psDPCDSinkCap,
                            DP_PanelInfoType         *psPanelInfo,
                            DP_PixelClk_Info         *pPixClkInfo);

/**********************************************************************************************************************

FUNCTION: DP_CalculateMisc0()
   
   This function will calculate the MISCO value according to DP Spec 

Parameters:
   eColorFormat                     -[in ] Sink color format

Return: 
   uint8 Misc0 value 

**********************************************************************************************************************/
uint8  DP_CalculateMisc0(DP_PixelFormatType eColorFormat );

/**********************************************************************************************************************

FUNCTION: DP_ClientWrite()
   
   This API allows users to send the DP command out to DP Panels. 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   pWritePacket                     -[out] Command package to be sent out to DP panels

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_Host_ClientWrite(DP_DeviceCtxType    *pDeviceCtx,
                              DP_WritePacketType  *psWritePacket);

/**********************************************************************************************************************

FUNCTION: DP_Host_ClientRead()
   
   This function will read from AUX/I2c channel 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psReadPacket                     -[out] the read packet

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_Host_ClientRead(DP_DeviceCtxType    *pDeviceCtx,
                             DP_ReadPacketType   *psReadPacket);


/**********************************************************************************************************

FUNCTION: DP_CheckTrainingResult()
   
   This function will get the max (among all lanes) drive setting requested by the sink 

Parameters:
   pDeviceCtx                         -[in ] Pointer to device context
   psDPCDSinkStatus                   -[in ] Pointer to DPCP sink status
   eTrainingType                      -[in ] type of link training done

Return: 
   bool32                             - TRUE = training successful 

************************************************************************************************************/
bool32  DP_CheckTrainingResult(DP_DeviceCtxType            *pDeviceCtx,
                               DP_DPCDSinkStatusType       *psDPCDSinkStatus,
                               DP_LinkTrainingStatusType    eTrainingType);
#endif // _DP_I_H
