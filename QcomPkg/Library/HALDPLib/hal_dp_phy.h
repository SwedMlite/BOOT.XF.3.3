#ifndef _HAL_DP_PHY_H_
#define _HAL_DP_PHY_H_

/*=============================================================================
 
  File: hal_dp_phy.h
 
  Header file for DP PHY hardware functionality 
   
  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/


/* -----------------------------------------------------------------------
** Includes
** ----------------------------------------------------------------------- */
#include "dp_system.h"

/* -----------------------------------------------------------------------
** Macros
** ----------------------------------------------------------------------- */

#ifdef MDP_PRESIL
#define DP_PHY_REGWRITE(_a_,_d_) DP_LOG_MESSAGE_WARN("DP_PHY_REGWRITE A:0x%08X D:0x%08X\n", (_a_), (_d_))
#else
#define DP_PHY_REGWRITE(_a_,_d_) out_dword((_a_),(_d_))
#endif

#define DP_PHY_REGREAD(_a_) in_dword((_a_))


/*--------------------------------------------------------------------------------------------
 *   Data Type Defines
 *--------------------------------------------------------------------------------------------*/


/*!
 * \struct HAL_DP_PeSwConfigType
 *
 *  Input info to config PHY Voltage Swing level and pre-emphasis level
 *
 */
typedef struct
{
  uint32                            uLaneSwingLevel;                   /**< Lane voltage swing level                  */
  uint32                            uPreemphasisLevel;                 /**< Lane pre-emphasis level                   */
  bool32                            bSwingNotsupported;                /**< requested swing level not supported       */
  bool32                            bPreemphNotSupported;              /**< requested preemphasis level not supported */
} HAL_DP_PeSwConfigType;

/*!
 * \struct _HAL_DP_PllConfigType
 *
 *  Input info to config PLL 
 *
 */
typedef struct
{
   uint32                           uNumLanes;                        /* Number of lanes                        */
   uint32                           uLinkRateMbps;                    /* DP Link rate (per lane) in Mbps        */
   uint32                           uPixelClkMNDInputMhz;             /* input clk freq to pixel clk MND        */
   uint32                           uVoltSwingLevel;                  /* Lane voltage swing level               */
   uint32                           uPreemphasisLevel;                /* Lane pre-emphasis level                */
   bool32                           bInvertedPlug;                    /* Cable plugged in reverse orientation   */
   bool32                           bReversePhyDataPath;              /* PHY data path reverse of type-c spec   */
   uint32                           uFlags;                           /* PLL config options, e.g, SSC mode 
                                                                          see HAL_DP_PllConfigFlagType          */
} HAL_DP_PllConfigType;

/*!
 * \struct HAL_DP_PeSwPairType
 *
 *  pre-emphasis and voltage swing 
 *
 */
typedef struct
{
  uint32 uPreEmphasis;
  uint32 uVoltageSwing;
}HAL_DP_PeSwPairType;

/*!
* \struct HAL_DP_AuxPhyCfgType
*
*  PHY settings for AUX 
*
*/
typedef struct
{
  uint32 *pDPAuxPhyCfg1Index;                                          /* Config Index for DP_PHY_AUX_CFG1 register*/
}HAL_DP_AuxPhyCfgType;

/*!
* \struct HAL_DP_PhyPllFunctionTable
*
* Defines the DP/PLL function table for functions to config PHY and PLL
*/
typedef struct
{
    bool32              (*HAL_DP_PHY_Config)          (DP_DeviceIDType       eDPPhyId, 
                                                       HAL_DP_PllConfigType *pDPPhyConfigInfo);    

    void                (*HAL_DP_PHY_Reset)           (DP_DeviceIDType eDPPhyId);    

    void                (*HAL_DP_PHY_AUX_Init)        (DP_DeviceIDType eDPPhyId);

    HAL_MDSS_ErrorType  (*HAL_DP_PHY_SetupPeSw)       (DP_DeviceIDType        eDPPhyId, 
                                                       HAL_DP_PeSwConfigType *pPeSwConfig);

    void                (*HAL_DP_PHY_GetMaxPeSwLevel) (DP_DeviceIDType  eDPPhyId, 
                                                       uint32          *uMaxPreemphLvl,
                                                       uint32          *uMaxVoltSwingLvl);

    HAL_MDSS_ErrorType  (*HAL_DP_PHY_AUXConfig)       (DP_DeviceIDType       eDPPhyId,
                                                       HAL_DP_AuxPhyCfgType *pAuxPhyCfg);

    void                (*HAL_DP_PHY_SetPHYMode)      (DP_DeviceIDType eDPPhyId,
                                                       bool32          bDPMode);
} HAL_DP_PhyPllFunctionTable;

/*--------------------------------------------------------------------------------------------
 *   Function prototypes
 *--------------------------------------------------------------------------------------------*/


/****************************************************************************
*
** FUNCTION: HAL_DP_PhyFxnsInit()
*/
/*!
* \DESCRIPTION
*   Initialize DP PHY/PLL function table
*
* \retval None
*
****************************************************************************/
void HAL_DP_PhyFxnsInit(void);

/****************************************************************************
*
** FUNCTION: HAL_DP_SetupPHYPeSwLevel()
*/
/*!
* \brief
*        Set up DP Lane Pre Emphasis and voltage swing level
*
* \param [in]     eDeviceId   - DP Device ID
* \param [in/out] pPeSwConfig - Pre-emphasis/Swing level settings.
*
* \retval  HAL_MDSS_ErrorType
*
*****************************************************************************/
HAL_MDSS_ErrorType HAL_DP_SetupPHYPeSwLevel(DP_DeviceIDType        eDeviceId,
                                            HAL_DP_PeSwConfigType *pPeSwConfig);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_Config()
*/
/*!
* \DESCRIPTION
*           Configure DP PHY and PLL 
*
* \param [in]   eDeviceId             - DP Device ID
* \param [in]   HAL_DP_PllConfigType  - DP PHY PLL config info
*
* \retval boolean  
*
****************************************************************************/
bool32 HAL_DP_PHY_Config(DP_DeviceIDType       eDeviceId,
                         HAL_DP_PllConfigType *pDPPllConfigInfo);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_Reset()
*/
/*!
* \DESCRIPTION
*           Reset DP PHY
*
* \param [in]     eDeviceId   - DP Device ID
*
* \retval   
*
****************************************************************************/
void HAL_DP_PHY_Reset(DP_DeviceIDType eDeviceId);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_AUX_Init()
*/
/*!
* \DESCRIPTION
*           Configure DP AUX PHY
*
* \param [in]     eDeviceId   - DP Device ID
*
* \retval   
*
****************************************************************************/
void HAL_DP_PHY_AUX_Init(DP_DeviceIDType eDeviceId);

/*********************************************************************************************
*
** FUNCTION: HAL_DP_PHY_GetMaxPeSwLevel()
*/
/*!
* \brief
*        Get max supported DP Lane Pre Emphasis and voltage swing levels
*
* \param [in]    eDeviceId        - DP Device ID
* \param [out]   uMaxPreemphLvl   - max Pre-emphasis level supported.
* \param [out]   uMaxVoltSwingLvl - max voltage swing level supported.
*
* \retval  void
*
**********************************************************************************************/
HAL_MDSS_ErrorType HAL_DP_PHY_GetMaxPeSwLevel(DP_DeviceIDType  eDeviceId,
                                              uint32          *uMaxPreemphLvl,
                                              uint32          *uMaxVoltSwingLvl);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_Power()
*/
/*!
* \DESCRIPTION
*           Power on/off DP PHY
*
* \param [in]     eDeviceId - DP Device ID
* \param [in]     bPowerOn  - TRUE: power on, FALSE: power off
*
* \retval   
*
****************************************************************************/
void HAL_DP_PHY_Power(DP_DeviceIDType eDeviceId,
                      bool32          bPowerOn);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_AUXConfig()
*/
/*!
* \DESCRIPTION
*           Power on/off DP PHY
*
* \param [in]     eDeviceId  - DP Device ID
* \param [in]     pAuxPhyCfg - Aux configuration
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
HAL_MDSS_ErrorType HAL_DP_PHY_AUXConfig(DP_DeviceIDType       eDeviceId,
                                        HAL_DP_AuxPhyCfgType *pAuxPhyCfg);

/****************************************************************************
*
** FUNCTION: HAL_DP_PHY_SetPHYMode()
*/
/*!
* \DESCRIPTION
*           Set the QMP PHY Mode to DP or USB3
*
* \param [in]     eDeviceId - DP Device ID
* \param [in]     bDPMode   - TRUE: DP mode, FALSE: USB3 Mode
*
* \retval
*
****************************************************************************/
void HAL_DP_PHY_SetPHYMode(DP_DeviceIDType eDeviceId,
                           bool32          bDPMode);


/* Function table initialization for 1.2.0 */
void HAL_DP_1_2_0_PhyFxnsInit(HAL_DP_PhyPllFunctionTable* pFxnTable);
void HAL_DP_AltMode_1_2_0_PhyFxnsInit(HAL_DP_PhyPllFunctionTable* pFxnTable);

#endif  /* #define _HAL_DP_PHY_H_ */
