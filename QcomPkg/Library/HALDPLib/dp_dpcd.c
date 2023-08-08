/*=====================================================================================================================
 
  File: dp_dpcd.c
 
  Source file for DP EDID read and parse related functionality 
   
  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=======================================================================================================================*/


/*---------------------------------------------------------------------------------------------------------------------
 * Include Files
 *-------------------------------------------------------------------------------------------------------------------*/
#include "dp_i.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------------------------------------
 * Defines
 *-------------------------------------------------------------------------------------------------------------------*/
#define DPCD_CAP_LEN                               16
#define DPCD_CAP_START_ADDRESS                     0

#define DPCD_LINK_STATUS_LEN                       6
#define DPCD_LINK_STATUS_START_ADDRESS             0x202

#define DPCD_LINKCONFIG_LEN                        2
#define DPCD_LINKCONFIG_START_ADDRESS              0x100

#define DPCD_TRAINING_PATTERN_SET_LEN              1
#define DPCD_TRAINING_PATTERN_SET_START_ADDRESS    0x102

#define DPCD_TRAINING_LANE_SET_LEN                 4
#define DPCD_TRAINING_LANE_SET_START_ADDRESS       0x103

#define DPCD_LINK_DOWNSPREAD_CTRL_LEN              1
#define DPCD_LINK_DOWNSPREAD_CTRL_ADDRESS          0x107

#define DPCD_SET_POWER_STATE_LEN                   1
#define DPCD_SET_POWER_STATE_START_ADDRESS         0x600



#define DPCD_SINK_STATUS_LEN                       8
#define DPCD_SINK_STATUS_ADDRESS                   0x200
#define DPCD_SINK_STATUS_SINK_COUNT_MASK           0x3F
#define DPCD_SINK_STATUS_CP_READY_MASK             0x40
/* Max loop count to poll if sink link status is stable*/
#define DPCD_LINK_STATUS_CHECK_UPDATE_LOOP         100
/*---------------------------------------------------------------------------------------------------------------------
 * Function pre-declarations
 *-------------------------------------------------------------------------------------------------------------------*/
static DP_Status  DP_ParseSinkDPCDCap(
  DP_DPCDSinkCapRawDataType       *psDPCDCapRawData,
  DP_DPCDSinkCapType              *psDPCDSinkCap);

static DP_Status  DP_ParseSinkDPCDStatus(
  DP_DPCDSinkStatusRawDataType    *psDPCDSinkStatusRawData,
  DP_DPCDSinkStatusType           *psDPCDSinkStatus);

static DP_Status  DP_ReadSinkStatus(
  DP_DeviceCtxType                *pDeviceCtx);

/**********************************************************************************************************************

FUNCTION: DP_ParseSinkDPCDCap()
   
   This function will parse the DPCD Capability from the Raw Data. 

Parameters:
   psDPCDCapRawData                 -[out] Raw data buffer containing DPCD data.
   psDPCDSinkCap                    -[out] Pointer to DPCD Sink Capability.

Return: 
   DP_Status 

**********************************************************************************************************************/
static DP_Status  DP_ParseSinkDPCDCap(DP_DPCDSinkCapRawDataType       *psDPCDCapRawData,
                                      DP_DPCDSinkCapType              *psDPCDSinkCap)
{
  DP_Status                       eStatus        = DP_STATUS_SUCCESS;

  DP_OSAL_MemSet((char*)psDPCDSinkCap, 0, sizeof(DP_DPCDSinkCapType));

  /* Byte 0: DPCD_REV */
  switch(psDPCDCapRawData->uDPCDRevision )
  {
    case  DPCD_SPEC_REV_MAJOR_1_0:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_1_0;
      break;
    }
    case  DPCD_SPEC_REV_MAJOR_1_1:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_1_1;
      break;
    }
    case  DPCD_SPEC_REV_MAJOR_1_2:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_1_2;
      break;
    }
    case  DPCD_SPEC_REV_MAJOR_1_3:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_1_3;
      break;
    }
    case  DPCD_SPEC_REV_MAJOR_1_4:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_1_4;
      break;
    }
    default:
    {
      psDPCDSinkCap->eDPCDMajorRev = DP_DPCD_MAJORREV_NONE;
      break;
    }
  }
      
  /* Byte 1: MAX_LINK_RATE */
  if (0 == psDPCDCapRawData->uMaxLinkRate)
  {
    uint32 i = 0;
    /* 
     * Special case for eDP
     * The supported link rates are in Bytes 0x10-0x1f
     * The rates are in multiples of 200Khz
     */
    for (i = 0;i < 8;i ++)
    {
      psDPCDSinkCap->uSupportedLinkRatesInKhz[i] = psDPCDCapRawData->uSupportedRates[i] * 20;

      /* If the next entry is zero, then this is the maximum supported link rate */
      if ((i < 7) &&
          (0 == psDPCDCapRawData->uSupportedRates[i + 1]))
      {
        psDPCDSinkCap->uMaxLinkRateInKhz = psDPCDSinkCap->uSupportedLinkRatesInKhz[i];
      }
    }
  }
  else
  {
    /* DP rates in multiples of 270 Khz */
    psDPCDSinkCap->uMaxLinkRateInKhz = psDPCDCapRawData->uMaxLinkRate * 27000;
  }

  /* Byte 2: MAX_LANE_COUNT */
  psDPCDSinkCap->uMaxLaneCount = psDPCDCapRawData->uMaxLaneCount & 0x1F;
  
  if (psDPCDCapRawData->uMaxLaneCount & 0x80)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_ENHANCED_FRAME;
  }
  if (psDPCDCapRawData->uMaxLaneCount & 0x40)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_TRAININGPATTERN3;
  }
  if (psDPCDCapRawData->uMaxLaneCount & 0x20)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_POST_LT_ADJ_REQ;
  }

  /*Byte 3: MAX_DOWNSPREAD */
  if (psDPCDCapRawData->uMaxDownSpread & 0x01)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_MAX_DOWNSPREAD_0_5;
  }
  if (psDPCDCapRawData->uMaxDownSpread & 0x40)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_NO_AUX_HANDSHAKE;
  }
  if (psDPCDCapRawData->uMaxDownSpread & 0x80)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_TRAININGPATTERN4;
  }

  /* Byte 4: NORP */
  psDPCDSinkCap->uNumofRXPorts  = (psDPCDCapRawData->uNumofReceiverPorts & 0x1) + 1;

  if (psDPCDCapRawData->uNumofReceiverPorts & 0x20)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_5V_DP_PWR;
  }

  if (psDPCDCapRawData->uNumofReceiverPorts & 0x40)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_12V_DP_PWR;
  }

  if (psDPCDCapRawData->uNumofReceiverPorts & 0x80)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_18V_DP_PWR;
  } 

  /* Byte 5: DOWNSTREAMPORT_PRESENT */
  if (psDPCDCapRawData->uDownStreamPortPresent & 0x01)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_DWN_STRM_PORT_PRESENT;
  }
  
  switch((psDPCDCapRawData->uDownStreamPortPresent >> 1) & 0x03)
  {
    case  DPCD_SPEC_DWN_STRM_PORT_TYPE_DISPLAYPORT:
    {
      psDPCDSinkCap->eDwnStreamPortType = DP_DPCD_DOWNSTREAMPORTTYPE_DISPLAYPORT;
      break;
    }
    case  DPCD_SPEC_DWN_STRM_PORT_TYPE_VGA_DVI_I:
    {
      psDPCDSinkCap->eDwnStreamPortType = DP_DPCD_DOWNSTREAMPORTTYPE_VGA_DVI_I;
      break;
    }
    case  DPCD_SPEC_DWN_STRM_PORT_TYPE_DVI_HDMI:
    {
      psDPCDSinkCap->eDwnStreamPortType = DP_DPCD_DOWNSTREAMPORTTYPE_DVI_HDMI;
      break;
    }
    case  DPCD_SPEC_DWN_STRM_PORT_TYPE_OTHERS:
    {
      psDPCDSinkCap->eDwnStreamPortType = DP_DPCD_DOWNSTREAMPORTTYPE_OTHER;
      break;
    }
    default:
    {
      psDPCDSinkCap->eDwnStreamPortType = DP_DPCD_DOWNSTREAMPORTTYPE_NONE;
      break;
    }
  }
  if (psDPCDCapRawData->uDownStreamPortPresent & 0x08)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_FOMRAT_CONVERSION;
  }
  if (psDPCDCapRawData->uDownStreamPortPresent & 0x10)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_DETAILED_CAP_INFO_AVAILABLE;
  }

  /* Byte 6: MAIN_LINK_CHANNEL_CODING */  

  /* Byte 7: DOWN_STREAM_PORT_COUNT */
  psDPCDSinkCap->uNumOfDownStreamPorts = psDPCDCapRawData->uDownStreamPortCount & 0x0F;
  if (psDPCDCapRawData->uDownStreamPortCount & 0x40)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_MSA_TIMING_PAR_IGNORED;
  }
  if (psDPCDCapRawData->uDownStreamPortCount&0x80)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_OUI;
  }

  /* Byte 8: RECEIVE_PORT0_CAP_0 */
  if (psDPCDCapRawData->uReceivePort0Cap0 & 0x02)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_PORT0_EDID_PRESENTED;
  }
  if (psDPCDCapRawData->uReceivePort0Cap0 & 0x04)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_PORT0_USED_FOR_2ND_STREAM;
  }

  /* Byte 9: RECEIVE_PORT0_CAP_1 */
  psDPCDSinkCap->uRXPort0BufferSize  = (psDPCDCapRawData->uReceivePort0Cap1 + 1) * 32;

  /* Byte 10: RECEIVE_PORT1_CAP_0 */
  if (psDPCDCapRawData->uReceivePort1Cap0 & 0x02)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_PORT1_EDID_PRESENTED;
  }
  if (psDPCDCapRawData->uReceivePort1Cap0 & 0x04)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_PORT1_USED_FOR_2ND_STREAM;
  }

  /*Byte 11: RECEIVE_PORT1_CAP_1 */
  psDPCDSinkCap->uRXPort1BufferSize            = (psDPCDCapRawData->uReceivePort1Cap1 + 1) * 32;

  /*Byte 12: I2C speed control */
  switch(psDPCDCapRawData->uI2CSpeedControlCap)
  {
    case  DPCD_SPEC_I2C_SPEED_CTRL_1KBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_1KBPS;
      break;
    }
    case  DPCD_SPEC_I2C_SPEED_CTRL_5KBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_5KBPS;
      break;
    }
    case  DPCD_SPEC_I2C_SPEED_CTRL_10KBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_10KBPS;
      break;
    }
    case  DPCD_SPEC_I2C_SPEED_CTRL_100KBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_100KBPS;
      break;
    }
    case  DPCD_SPEC_I2C_SPEED_CTRL_400KBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_400KBPS;
      break;
    }
    case  DPCD_SPEC_I2C_SPEED_CTRL_1MBPS:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_1MBPS;
      break;
    }
    default:
    {
      psDPCDSinkCap->eI2CSpeedCtrl = DP_DPCD_I2CSPEEDCTRL_NONE;
      break;
    }
  }

  /* Byte 13: eDP_CONFIGURATION_CAP is eDP specific */  
  if (psDPCDCapRawData->uEDPConfigurationCap & 0x01)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_ASSR;
  }
  if (psDPCDCapRawData->uEDPConfigurationCap & 0x02)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_FORCE_ENHANCED_FRAME;
  }

  /* Byte 14: TRAINING_AUX_RD_INTERVAL */
  if ((psDPCDCapRawData->uTrainingAUXRdInterval & 0x7F) == 0)
  {
    psDPCDSinkCap->uTrainingIntervalInUs      = 400;    /* for channel equalization */
  }
  else
  {
    psDPCDSinkCap->uTrainingIntervalInUs      = (psDPCDCapRawData->uTrainingAUXRdInterval & 0x7F) * 4000; /* for channel equalization */
  }

  if (psDPCDCapRawData->uTrainingAUXRdInterval & 0x80)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_EXTENDED_RECEIVER_FIELD;
  }

  /* Byte 15: ADAPTER_CAP */
  if (psDPCDCapRawData->uAdapterCap & 0x01)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_VGA_FORCE_LOAD_SENSE;
  }
  if (psDPCDCapRawData->uAdapterCap & 0x02)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_ALTERNATE_I2C_PATTERN;
  }

#if 0 //#TODO#IMPLEMENT - These dpcd caps do not belong here. They need to be read from different offsets.
  /* Byte 16: DPRX_FEATURE_ENUMERATION_LIST */
  if (psDPCDCapRawData->uFeatureEnumerationList & 0x01)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_GTC;
  }
  if (psDPCDCapRawData->uFeatureEnumerationList & 0x04)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_AV_SYNC;
  }
  if (psDPCDCapRawData->uFeatureEnumerationList & 0x08)
  {
    psDPCDSinkCap->eDPCDCap    |= DP_DPCD_CAP_SUPPORT_VSC_SDP;
  }

  /* Byte 17: EXTENDED_DPRX_SLEEP_WAKE_TIMEOUT_REQUEST */
  if (0 == psDPCDCapRawData->uSleepWakeTimeout)
  {
    psDPCDSinkCap->uSleepWakeTimeoutInMs = 1;
  }
  else
  {
    psDPCDSinkCap->uSleepWakeTimeoutInMs = psDPCDCapRawData->uSleepWakeTimeout * 20;
  }  
#endif
  return eStatus;
}


/**********************************************************************************************************************

FUNCTION: DP_ParseSinkDPCDStatus()
   
   This function will parse the DPCD Status from the Raw Data. 

Parameters:
   psDPCDSinkStatusRawData          -[in ] Raw data buffer containing DPCD Status data.
   psDPCDSinkStatus                 -[out] Pointer to DPCD sink Status.

Return: 
   DP_Status 

**********************************************************************************************************************/
static DP_Status  DP_ParseSinkDPCDStatus(DP_DPCDSinkStatusRawDataType    *psDPCDSinkStatusRawData,
                                         DP_DPCDSinkStatusType           *psDPCDSinkStatus)
{
  DP_Status                       eStatus        = DP_STATUS_SUCCESS;

  DP_OSAL_MemSet((char*)psDPCDSinkStatus, 0, sizeof(DP_DPCDSinkStatusType));

  /* Byte 0x202: LANE0_1_STATUS */
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x01)
  {
    psDPCDSinkStatus->eLaneStatus[0] |= DP_DPCD_LANE_STATUS_CR_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x02)
  {
    psDPCDSinkStatus->eLaneStatus[0] |= DP_DPCD_LANE_STATUS_CHANNEL_EQ_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x04)
  {
    psDPCDSinkStatus->eLaneStatus[0] |= DP_DPCD_LANE_STATUS_SYMBOL_LOCKED;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x10)
  {
    psDPCDSinkStatus->eLaneStatus[1] |= DP_DPCD_LANE_STATUS_CR_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x20)
  {
    psDPCDSinkStatus->eLaneStatus[1] |= DP_DPCD_LANE_STATUS_CHANNEL_EQ_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus0_1  & 0x40)
  {
    psDPCDSinkStatus->eLaneStatus[1] |= DP_DPCD_LANE_STATUS_SYMBOL_LOCKED;
  }

  /* Byte 0x203: LANE2_3_STATUS */
  if (psDPCDSinkStatusRawData->uLaneStatus2_3  & 0x01)
  {
    psDPCDSinkStatus->eLaneStatus[2] |= DP_DPCD_LANE_STATUS_CR_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus2_3 & 0x02)
  {
    psDPCDSinkStatus->eLaneStatus[2] |= DP_DPCD_LANE_STATUS_CHANNEL_EQ_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus2_3 & 0x04)
  {
    psDPCDSinkStatus->eLaneStatus[2] |= DP_DPCD_LANE_STATUS_SYMBOL_LOCKED;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus2_3 & 0x10)
  {
    psDPCDSinkStatus->eLaneStatus[3] |= DP_DPCD_LANE_STATUS_CR_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus2_3 & 0x20)
  {
    psDPCDSinkStatus->eLaneStatus[3] |= DP_DPCD_LANE_STATUS_CHANNEL_EQ_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneStatus2_3 & 0x40)
  {
    psDPCDSinkStatus->eLaneStatus[3] |= DP_DPCD_LANE_STATUS_SYMBOL_LOCKED;
  }

  /* Byte 0x204: LANE_ALIGN_STATUS_UPDATED */
  if (psDPCDSinkStatusRawData->uLaneAlignStatusUpdated & 0x01)
  {
    psDPCDSinkStatus->eLinkStatusBitArray |= DP_DPCD_BIT_STATUS_INTERLANE_ALIGN_DONE;
  }
  if (psDPCDSinkStatusRawData->uLaneAlignStatusUpdated & 0x40)
  {
    psDPCDSinkStatus->eLinkStatusBitArray |= DP_DPCD_BIT_STATUS_PORT_STATUS_CHANGED;
  }
  if (psDPCDSinkStatusRawData->uLaneAlignStatusUpdated & 0x80)
  {
    psDPCDSinkStatus->eLinkStatusBitArray |= DP_DPCD_BIT_STATUS_LINK_STATUS_UPDATED;
  }

  /* Byte 0x205: SINK_STATUS */
  if (psDPCDSinkStatusRawData->uSinkStatus & 0x01)
  {
    psDPCDSinkStatus->eLinkStatusBitArray |= DP_DPCD_BIT_STATUS_PORT_0_IN_SYNC;
  }
  if (psDPCDSinkStatusRawData->uSinkStatus & 0x02)
  {
    psDPCDSinkStatus->eLinkStatusBitArray |= DP_DPCD_BIT_STATUS_PORT_1_IN_SYNC;
  }

  /* Byte 0x206: ADJUST_REQUEST_LANE0_1 */
  psDPCDSinkStatus->uVoltageSwingLevel[0]   = (psDPCDSinkStatusRawData->uAdjustRequestLane0_1)      & 0x3;
  psDPCDSinkStatus->uPreEmphasisLevel[0]    = (psDPCDSinkStatusRawData->uAdjustRequestLane0_1 >> 2) & 0x3;
  psDPCDSinkStatus->uVoltageSwingLevel[1]   = (psDPCDSinkStatusRawData->uAdjustRequestLane0_1 >> 4) & 0x3;
  psDPCDSinkStatus->uPreEmphasisLevel[1]    = (psDPCDSinkStatusRawData->uAdjustRequestLane0_1 >> 6) & 0x3;

  /* Byte 0x207: ADJUST_REQUEST_LANE2_3 */
  psDPCDSinkStatus->uVoltageSwingLevel[2]   = (psDPCDSinkStatusRawData->uAdjustRequestLane2_3)      & 0x3;
  psDPCDSinkStatus->uPreEmphasisLevel[2]    = (psDPCDSinkStatusRawData->uAdjustRequestLane2_3 >> 2) & 0x3;
  psDPCDSinkStatus->uVoltageSwingLevel[3]   = (psDPCDSinkStatusRawData->uAdjustRequestLane2_3 >> 4) & 0x3;
  psDPCDSinkStatus->uPreEmphasisLevel[3]    = (psDPCDSinkStatusRawData->uAdjustRequestLane2_3 >> 6) & 0x3;

  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_ReadSinkDPCDCap()
   
   This function will read Sink Capability Data from DPCD over AUX Channel

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psDPCDSinkCap                    -[out] Pointer to DPCD Sink Capability Data struct.

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_ReadSinkDPCDCap(DP_DeviceCtxType    *pDeviceCtx,
                              DP_DPCDSinkCapType  *psDPCDSinkCap)
{
  DP_Status                       eStatus        = DP_STATUS_SUCCESS;  
  DP_DPCDSinkCapRawDataType       sDPCDCapRawData;
  DP_ReadPacketType               sReadPacket;
  uint32                          uReadIdx;
  uint8                           uSinkStatus[DPCD_SINK_STATUS_LEN];

  /*Read DPCD Data*/
  sReadPacket.eTransactionType     = DP_TRANSACTION_MODE_AUX;
  sReadPacket.puReadDataBuffer     = (uint8*)&sDPCDCapRawData;
  sReadPacket.uAddress             = DPCD_CAP_START_ADDRESS;
  sReadPacket.uReadSize            = 1;
  sReadPacket.uBytesRead           = 0;
  sReadPacket.bQueueOnly           = FALSE;

  /* Some dongles can only return DCDP byte by byte */
  for (uReadIdx = 0; uReadIdx < sizeof(DP_DPCDSinkCapRawDataType); uReadIdx++)
  {
    if (DP_STATUS_SUCCESS != (eStatus = DP_Host_ClientRead(pDeviceCtx, &sReadPacket)))
    {
      break;
    }
    sReadPacket.puReadDataBuffer++;
    sReadPacket.uAddress++;
  }

  if (DP_STATUS_SUCCESS != eStatus)
  {
    DP_LOG_MESSAGE_ERROR("DP_ReadDPCDSinkCap: Read Failed, eStatus=0x%x.",eStatus);
  }
  else if (sReadPacket.uBytesRead != sReadPacket.uReadSize)
  {
    eStatus  = DP_STATUS_FAILED_RESOURCE_FAILED;
    DP_LOG_MESSAGE_ERROR("DP_ReadDPCDSinkCap: Bytes Read(%d) is not expected.",sReadPacket.uBytesRead);
  }
  else
  {
    eStatus = DP_ParseSinkDPCDCap(&sDPCDCapRawData, psDPCDSinkCap);
  }

  /* Read Sink status */
  sReadPacket.puReadDataBuffer  = (uint8*)&uSinkStatus;
  sReadPacket.uAddress          = DPCD_SINK_STATUS_ADDRESS;
  sReadPacket.uReadSize         = DPCD_SINK_STATUS_LEN;
  if (DP_STATUS_SUCCESS != (eStatus = DP_Host_ClientRead(pDeviceCtx, &sReadPacket)))
  {
    DP_LOG_MESSAGE_ERROR("DP_ReadSinkDPCDCap: Read address(0x%x) Failed, eStatus=0x%x\n", sReadPacket.uAddress, eStatus);
  }
  else
  {
    pDeviceCtx->uSinkCount =  uSinkStatus[0] & DPCD_SINK_STATUS_SINK_COUNT_MASK;
    pDeviceCtx->bCPReady   = (uSinkStatus[0] & DPCD_SINK_STATUS_CP_READY_MASK) ? TRUE : FALSE;
  }

  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_ReadSinkDPCDStatus()
   
   This function will read Sink Status Raw Data from DPCD over AUX Channel

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   psDPCDSinkStatus                 -[out] Pointer to DPCD Sink Status Data struct.

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_ReadSinkDPCDStatus(DP_DeviceCtxType      *pDeviceCtx,
                                 DP_DPCDSinkStatusType *psDPCDSinkStatus)
{
  DP_Status                       eStatus             = DP_STATUS_SUCCESS;
  bool32                          bLinkStatusUpdated  = FALSE;
  uint32                          uLoopCount          = DPCD_LINK_STATUS_CHECK_UPDATE_LOOP;
  DP_DPCDSinkStatusRawDataType    sDPCDSinkStatusRawData;
  DP_ReadPacketType               sReadPacket;

  /*Read DPCD Data*/
  sReadPacket.eTransactionType     = DP_TRANSACTION_MODE_AUX;
  sReadPacket.puReadDataBuffer     = (uint8*)&sDPCDSinkStatusRawData;
  sReadPacket.uAddress             = DPCD_LINK_STATUS_START_ADDRESS;
  sReadPacket.uReadSize            = sizeof(DP_DPCDSinkStatusRawDataType);
  sReadPacket.uBytesRead           = 0;
  sReadPacket.bQueueOnly           = FALSE;

  while (uLoopCount--)
  {
    if (DP_STATUS_SUCCESS != (eStatus = DP_Host_ClientRead(pDeviceCtx, &sReadPacket)))
    {
      DP_LOG_MESSAGE_ERROR("DP_ReadSinkDPCDStatus: Read Failed, eStatus=0x%x.", eStatus);
    }
    else if (sReadPacket.uBytesRead != sReadPacket.uReadSize)
    {
      eStatus = DP_STATUS_FAILED_RESOURCE_FAILED;
      DP_LOG_MESSAGE_ERROR("DP_ReadSinkDPCDStatus: Bytes Read(0x%x) is not expected.", sReadPacket.uBytesRead);
    }
    else
    {
      eStatus = DP_ParseSinkDPCDStatus(&sDPCDSinkStatusRawData, psDPCDSinkStatus);
    }

    if (psDPCDSinkStatus->eLinkStatusBitArray & DP_DPCD_BIT_STATUS_LINK_STATUS_UPDATED)
    {
      bLinkStatusUpdated = TRUE;
    }
    else
    {
      /* If there is no link status update, link status is stable, we can return */
      bLinkStatusUpdated = FALSE;
      break;
    }
  }
  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDLink()
   
   This function will Write the link setting to panel DPCD 

Parameters:
   pDeviceCtx                       -[in] Pointer to device context

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_WriteSinkDPCDLink(DP_DeviceCtxType    *pDeviceCtx)
{
  DP_Status                 eStatus       = DP_STATUS_SUCCESS; 
  DP_WritePacketType        sWritePacket;
  uint8                     uWriteBuffer[2];
  uint32                    i;

  /*
   * For eDP 1.4+, the panel will report supported bit rates as a Table as opposed to just the max bit rate
   * on previous spec revisions. In this case, we set the selected link rate on DPCD register 0x115. For all 
   * other cases, the link rate is set on DPCD register 0x100.
   */

  /* LINK_BW_SET */
  if (DP_DEVICE_ID_EDP == pDeviceCtx->eDeviceID)
  {
    sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
    sWritePacket.puWriteData         = uWriteBuffer;
    sWritePacket.uAddress            = 0x115;
    sWritePacket.uWriteDataSize      = 1;
    sWritePacket.uBytesWritten       = 0;
    sWritePacket.bQueueOnly          = FALSE;

    /* Find the index in the list of supported rates */
    for (i = 0;i < 8;i++)
    {
      if (pDeviceCtx->sSinkDPCDCap.uSupportedLinkRatesInKhz[i] == pDeviceCtx->uLinkRateInKhz)
      {
        uWriteBuffer[0] = i;
        eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);
        if (DP_STATUS_SUCCESS != eStatus)
        {
          DP_LOG_MESSAGE_ERROR( "DP_WriteSinkDPCDLink: Write Failed, eStatus=0x%x.",eStatus);
        }
      }
    }

    /* LINK_RATE_SET */
    // Reset byte zero in the buffer for the next command
    uWriteBuffer[0] = 0;
  }    
  switch(pDeviceCtx->uLinkRateInKhz)
  {
    case 162000:
    {
      uWriteBuffer[0] = DPCD_SPEC_MAX_LINK_RATE_1_62GBPS;
      break;
    }
    case 270000:
    {
      uWriteBuffer[0] = DPCD_SPEC_MAX_LINK_RATE_2_7GBPS;
      break;
    }
    case 540000:
    {
      uWriteBuffer[0] = DPCD_SPEC_MAX_LINK_RATE_5_4GBPS;
      break;
    }
    case 810000:
    {
      uWriteBuffer[0] = DPCD_SPEC_MAX_LINK_RATE_8_1GBPS;
      break;
    }
    default:
    {
      eStatus         = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
      DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDLink: Invalid input parameter.");
      break;
    }
  }
  
  if (DP_STATUS_SUCCESS == eStatus )
  {
    /* LANE_COUNT_SET */
    
    uWriteBuffer[1] = (uint8) pDeviceCtx->uNumLanes;
    
    if (pDeviceCtx->sSinkDPCDCap.eDPCDCap & DP_DPCD_CAP_SUPPORT_ENHANCED_FRAME)
    {
      uWriteBuffer[1] |= DPCD_SPEC_EN_ENHANCED_FRAME_BMSK ;
    }

    /*Write DPCD Data*/
    sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
    sWritePacket.puWriteData         = uWriteBuffer;
    sWritePacket.uAddress            = DPCD_LINKCONFIG_START_ADDRESS;
    sWritePacket.uWriteDataSize      = DPCD_LINKCONFIG_LEN;
    sWritePacket.uBytesWritten       = 0;
    sWritePacket.bQueueOnly          = FALSE;
    
    eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);

    if (DP_STATUS_SUCCESS != eStatus)
    {
      DP_LOG_MESSAGE_ERROR( "DP_WriteSinkDPCDLink: Write Failed, eStatus=0x%x.",eStatus);
    }

    if (TRUE == pDeviceCtx->bEnableSSCMode)
    {
      eStatus = DP_WriteSinkDPCDDownSpreadEnabled(pDeviceCtx);
    }
  }

  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDTrainingPattern()
   
   This function will select the training pattern for link training to panel DPCD 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   eTraingPattern                   -[in ] Link Training pattern 

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_WriteSinkDPCDTrainingPattern(DP_DeviceCtxType              *pDeviceCtx,
                                           DP_DPCDTrainingPatternSetType  eTraingPattern)
{
  DP_Status                 eStatus       = DP_STATUS_SUCCESS; 
  uint8                     uWriteBuffer  = 0;
  DP_WritePacketType        sWritePacket;

  switch(eTraingPattern)
  {
    case DP_DPCD_TRAININGPATTERNSET_NONE:
    {
      uWriteBuffer = DPCD_SPEC_TRAINING_PATTERN_NONE;
      break;
    }
    case DP_DPCD_TRAININGPATTERNSET_PATTERN1:
    {
      uWriteBuffer = DPCD_SPEC_TRAINING_PATTERN_1;      
      /* Disable scrambling as this sequence is not scrambled */
      uWriteBuffer |= DPCD_SPEC_SCRAMBLING_DISABLE_BMSK;      
      break;
    }
    case DP_DPCD_TRAININGPATTERNSET_PATTERN2:
    {
      uWriteBuffer = DPCD_SPEC_TRAINING_PATTERN_2;      
      /* Disable scrambling as this sequence is not scrambled */
      uWriteBuffer |= DPCD_SPEC_SCRAMBLING_DISABLE_BMSK;
      break;
    }
    case DP_DPCD_TRAININGPATTERNSET_PATTERN3:
    {
      uWriteBuffer = DPCD_SPEC_TRAINING_PATTERN_3;      
      /* Disable scrambling as this sequence is not scrambled */
      uWriteBuffer |= DPCD_SPEC_SCRAMBLING_DISABLE_BMSK;
      break;
    }    
    case DP_DPCD_TRAININGPATTERNSET_PATTERN4:
    {
      uWriteBuffer = DPCD_SPEC_TRAINING_PATTERN_4;
      /* Disable scrambling as this sequence is not scrambled */
      uWriteBuffer |= DPCD_SPEC_SCRAMBLING_DISABLE_BMSK;
      break;
    }    
    default:
    {
      eStatus = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
      DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDTrainingPattern: Invalid input parameter");
      break;
    }
  }

  if (DP_STATUS_SUCCESS == eStatus)
  {
    /* Write DPCD Data */
    sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
    sWritePacket.puWriteData         = &uWriteBuffer;
    sWritePacket.uAddress            = DPCD_TRAINING_PATTERN_SET_START_ADDRESS;
    sWritePacket.uWriteDataSize      = DPCD_TRAINING_PATTERN_SET_LEN;
    sWritePacket.uBytesWritten       = 0;
    sWritePacket.bQueueOnly          = FALSE;
    
    eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);

    if (DP_STATUS_SUCCESS != eStatus)
    {
      DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDTrainingPattern: Write Failed, eStatus=0x%x.", eStatus);
    }
  }

  return eStatus;
}

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
DP_Status  DP_WriteSinkDPCDLevels(DP_DeviceCtxType   *pDeviceCtx,
                                  uint32              uDesiredVoltageSwingLevel,
                                  uint32              uDesiredPreEmphasisLevel)
{
  DP_Status                eStatus     = DP_STATUS_SUCCESS;  
  DP_WritePacketType       sWritePacket;
  uint8                    uWriteBuffer[4];       

  uWriteBuffer[0]    = uDesiredVoltageSwingLevel & 0x3;
  uWriteBuffer[0]   |= (uDesiredPreEmphasisLevel << 3) & 0x18;
  
  if (pDeviceCtx->uMaxVoltSwingLvl == uDesiredVoltageSwingLevel)
  {
    uWriteBuffer[0] |= DPCD_SPEC_MAX_SWING_REACHED_BMSK;
  }
  if (pDeviceCtx->uMaxPreemphLvl == uDesiredPreEmphasisLevel)
  {
    uWriteBuffer[0] |= DPCD_SPEC_MAX_PRE_EMPHASIS_REACHED_BMSK;
  }

  /* Use same config for lanes 1-4 */
  uWriteBuffer[3] = uWriteBuffer[0];
  uWriteBuffer[2] = uWriteBuffer[0];
  uWriteBuffer[1] = uWriteBuffer[0];

  /* Write DPCD Data */
  sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
  sWritePacket.puWriteData         = uWriteBuffer;
  sWritePacket.uAddress            = DPCD_TRAINING_LANE_SET_START_ADDRESS;
  sWritePacket.uWriteDataSize      = DPCD_TRAINING_LANE_SET_LEN;
  sWritePacket.uBytesWritten       = 0;
  sWritePacket.bQueueOnly          = FALSE;
  
  eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);

  if (DP_STATUS_SUCCESS!= eStatus)
  {
    DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDLevels: Write Failed, eStatus=0x%x.", eStatus);
  }

  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_WriteSinkDPCDDownSpreadEnabled()
   
   This function will indicate that downspread has been enabled on host side.

Parameters:
   pDeviceCtx                       -[in] Pointer to device context

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status DP_WriteSinkDPCDDownSpreadEnabled(DP_DeviceCtxType    *pDeviceCtx)
{
  DP_Status                eStatus      = DP_STATUS_SUCCESS;  
  uint8                    uWriteBuffer = 0x10;    // Bit 4: SPREAD_AMP
  DP_WritePacketType       sWritePacket;

  sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
  sWritePacket.puWriteData         = &uWriteBuffer;
  sWritePacket.uAddress            = DPCD_LINK_DOWNSPREAD_CTRL_ADDRESS;
  sWritePacket.uWriteDataSize      = DPCD_LINK_DOWNSPREAD_CTRL_LEN;
  sWritePacket.uBytesWritten       = 0;
  sWritePacket.bQueueOnly          = FALSE;
  
  eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);

  if (DP_STATUS_SUCCESS != eStatus)
  {
    DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDDownSpreadEnabled: Write Failed, eStatus=0x%x.", eStatus);
  }

  return eStatus;
}



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
                                DP_DPCDPowerStateType  ePowerState)
{
  DP_Status                eStatus     = DP_STATUS_SUCCESS;  
  DP_WritePacketType       sWritePacket;
  uint8                    uWriteBuffer;

  switch (ePowerState)
  {
    case DP_DPCD_POWERSTATE_D0:
    {
      uWriteBuffer = DPCD_SPEC_POWER_STATE_D0;
      break;
    }
    case DP_DPCD_POWERSTATE_D3:
    {
      uWriteBuffer = DPCD_SPEC_POWER_STATE_D3;
      break;
    }
    case DP_DPCD_POWERSTATE_LINK_D3_AUX_D0:
    {
      uWriteBuffer = DPCD_SPEC_POWER_STATE_LINK_D3_AUX_D0;
      break;
    }
    default:
    {
      eStatus      = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
      DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDPower: Invalid input parameter ");
      break;
    }
  }

  if (DP_STATUS_SUCCESS == eStatus)
  {
    /*Write DPCD Data*/
    sWritePacket.eTransactionType    = DP_TRANSACTION_MODE_AUX;
    sWritePacket.puWriteData         = &uWriteBuffer;
    sWritePacket.uAddress            = DPCD_SET_POWER_STATE_START_ADDRESS;
    sWritePacket.uWriteDataSize      = DPCD_SET_POWER_STATE_LEN;
    sWritePacket.uBytesWritten       = 0;
    sWritePacket.bQueueOnly          = FALSE;
    
    eStatus = DP_Host_ClientWrite(pDeviceCtx, &sWritePacket);

    if (DP_STATUS_SUCCESS != eStatus)
    {
      DP_LOG_MESSAGE_ERROR("DP_WriteSinkDPCDPower: Write Failed, eStatus=0x%x\n", eStatus);
    }
        
  }

  return eStatus;
}


/**********************************************************************************************************************

FUNCTION: DP_ReadSinkStatus()

This function will read sink status register for sink count and CP readiness. 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context

Return:
DP_Status

**********************************************************************************************************************/
DP_Status  DP_ReadSinkStatus(DP_DeviceCtxType      *pDeviceCtx)
{
  DP_Status                       eStatus       = DP_STATUS_SUCCESS;  
  uint8                           uSinkStatus[DPCD_SINK_STATUS_LEN];
  DP_ReadPacketType               sReadPacket;
  DP_DPCDSinkStatusType           sSinkDPCDStatus;

  /*Read DPCD Data*/
  sReadPacket.eTransactionType     = DP_TRANSACTION_MODE_AUX;
  sReadPacket.puReadDataBuffer     = (uint8*)&uSinkStatus;
  sReadPacket.uAddress             = DPCD_SINK_STATUS_ADDRESS;
  sReadPacket.uReadSize            = DPCD_SINK_STATUS_LEN;
  sReadPacket.uBytesRead           = 0;
  sReadPacket.bQueueOnly           = FALSE;

  if (DP_STATUS_SUCCESS != (eStatus = DP_Host_ClientRead(pDeviceCtx, &sReadPacket)))
  {
    DP_LOG_MESSAGE_ERROR("DP_ReadSinkStatus: Read address(0x%x) Failed, eStatus=0x%x.", sReadPacket.uAddress, eStatus);
  }
  else
  {
    pDeviceCtx->uSinkCount  =  uSinkStatus[0] & DPCD_SINK_STATUS_SINK_COUNT_MASK;
    pDeviceCtx->bCPReady    = (uSinkStatus[0] & DPCD_SINK_STATUS_CP_READY_MASK)?TRUE:FALSE;
  }

  DP_OSAL_MemSet(&sSinkDPCDStatus, 0, sizeof(sSinkDPCDStatus));

  if (DP_STATUS_SUCCESS != (eStatus = DP_ReadSinkDPCDStatus(pDeviceCtx, &sSinkDPCDStatus)))
  {
    /* Failed to read link status DPCD, treat it as link lost */
    pDeviceCtx->bLinkLost = TRUE;
    DP_LOG_MESSAGE_ERROR("DP_ReadSinkStatus: DP_ParseSinkDPCDStatus Failed, eStatus=0x%x.", eStatus);
  }
  else
  {
    if ((TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_CHANNEL_EQ_DONE))   &&
        (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_SYMBOL_LOCKED))     &&
        (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_CLK_RECOVERY_DONE)) &&
        (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_INTERLANE_ALIGN_DONE)))
    {
      pDeviceCtx->bLinkLost = FALSE;
    }
    else
    {
      pDeviceCtx->bLinkLost = TRUE;
    }
  }

  return eStatus;
}


#ifdef __cplusplus
}
#endif

