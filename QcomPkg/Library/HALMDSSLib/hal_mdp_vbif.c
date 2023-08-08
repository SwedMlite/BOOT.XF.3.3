/*! \file */

/*
===========================================================================

FILE:        hal_mdp_vbif.c

DESCRIPTION: Configures VBIF settings for MDSS.
  
===========================================================================
  Copyright (c) 2016-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

===========================================================================
*/

/* -----------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------- */

#include "hal_mdp_i.h"

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------------------------------------------------------------------
 * Local defines 
 * ------------------------------------------------------------------------------------ */



/* -------------------------------------------------------------------------------------
 * Static data declarations and functions
 * ------------------------------------------------------------------------------------ */
    
   
static HAL_MDSS_ErrorType HAL_MDP_VBif_QOSRemapper(HAL_MDP_VbifId  eVbifId,
                                                   HAL_MDP_VBIF_ClientIDType eClientId);
/****************************************************************************
*
** FUNCTION: HAL_MDP_Get_Vbif_BaseOffset()
*/
/*!
* \brief
*     Returns offset of the VBIF
*
* \param [in] eVbifId         - VBIF block ID
*
* \retval uintPtr
*
****************************************************************************/
static uintPtr HAL_MDP_Get_Vbif_BaseOffset(HAL_MDP_VbifId  eVbifId)
{
    uintPtr   uRegOffset = 0x0;

    if ((uint32)eVbifId >= HAL_MDP_GET_VBIF_COUNT())
    {
        HAL_MDP_ASSERT();
    }
    else
    {
        uRegOffset = uMDPVbifRegBaseOffset[eVbifId];
    }
    return uRegOffset;
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_Config_ClockGating()
*/
/*!
* \brief
*     Configures clock gating on the VBIF
*
* \param [in] bEnableGating  - TRUE: enable clock gating AXI & Test Bus Domain; otherwise disable;
* \param [in] uFlags         - reserved
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_Config_ClockGating(
                              HAL_MDP_VbifId eVbifId,
                              bool32         bEnableGating,
                              uint32         uFlags )
{
   uint32  uRegValue       = 0;
   uint32  uAxiForceOn     = 0;
   uint32  uTestBusForceOn = 0;
   uintPtr uRegOffset      = 0;

   uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

   if (FALSE == bEnableGating)
   {
     uAxiForceOn     = 1;
     uTestBusForceOn = 1;
   }
   
   uRegValue = HWIO_OUT_FLD(uRegValue, VBIF, VBIF_CLKON_FORCE_ON, uAxiForceOn);
   uRegValue = HWIO_OUT_FLD(uRegValue, VBIF, VBIF_CLKON_FORCE_ON_TESTBUS, uTestBusForceOn);
   uRegValue = HWIO_OUT_FLD(uRegValue, VBIF, VBIF_CLKON_HYSTERESIS_VALUE, 0);
   
   out_dword(HWIO_VBIF_VBIF_CLKON_ADDR + uRegOffset, uRegValue);

   return HAL_MDSS_STATUS_SUCCESS;
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_BurstLimitsConfig()
*/
/*!
* \brief
*     Configures Vbif burst size limits
*
* \param [in] uReadBurst     - Maximum read burst size
* \param [in] uReadOT        - Maximum read outstanding transactions (OT)
* \param [in] uWriteBurst    - Maximum write burst size
* \param [in] uWriteOT       - Maximum write outstanding transition (OT)
* \param [in] uFlags         - reserved
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_BurstLimitsConfig(
                              HAL_MDP_VbifId eVbifId,
                              uint32         uReadBurst,
                              uint32         uReadOT,                              
                              uint32         uWriteBurst,
                              uint32         uWriteOT,
                              uint32         uFlags )
{
   uint32  uRegValue = 0;
   uintPtr uRegOffset = 0;

   uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

   // Configure VBIF max read/write burst size
   uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_DDR_OUT_MAX_BURST, DDR_OUT_MAX_WR_BURST, uWriteBurst);
   uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_DDR_OUT_MAX_BURST, DDR_OUT_MAX_RD_BURST, uReadBurst);

   out_dword(HWIO_VBIF_VBIF_DDR_OUT_MAX_BURST_ADDR + uRegOffset, uRegValue);


   if (HAL_MDP_VBIF_0 == eVbifId)
   {
       // Configure VBIF RD OT
       if (0 != uReadOT)
       {
          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C0, uReadOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C1, uReadOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C2, uReadOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C3, uReadOT);         
          out_dword(HWIO_VBIF_VBIF_IN_RD_LIM_CONF0_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF1, IN_RD_LIM_C4, uReadOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF1, IN_RD_LIM_C5, uReadOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF1, IN_RD_LIM_C6, uReadOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF1, IN_RD_LIM_C7, uReadOT);         
          out_dword(HWIO_VBIF_VBIF_IN_RD_LIM_CONF1_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF2, IN_RD_LIM_C8,  uReadOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF2, IN_RD_LIM_C9,  uReadOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF2, IN_RD_LIM_C10, uReadOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF2, IN_RD_LIM_C11, uReadOT);            
          out_dword(HWIO_VBIF_VBIF_IN_RD_LIM_CONF2_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF3, IN_RD_LIM_C12, uReadOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF3, IN_RD_LIM_C13, uReadOT);   
          out_dword(HWIO_VBIF_VBIF_IN_RD_LIM_CONF3_ADDR + uRegOffset, uRegValue);   
       }

       // Configure VBIF WR OT
       if (0 != uWriteOT)
       {
          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C0, uWriteOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C1, uWriteOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C2, uWriteOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C3, uWriteOT);         
          out_dword(HWIO_VBIF_VBIF_IN_WR_LIM_CONF0_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF1, IN_WR_LIM_C4, uWriteOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF1, IN_WR_LIM_C5, uWriteOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF1, IN_WR_LIM_C6, uWriteOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF1, IN_WR_LIM_C7, uWriteOT);         
          out_dword(HWIO_VBIF_VBIF_IN_WR_LIM_CONF1_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF2, IN_WR_LIM_C8,  uWriteOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF2, IN_WR_LIM_C9,  uWriteOT);   
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF2, IN_WR_LIM_C10, uWriteOT);      
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF2, IN_WR_LIM_C11, uWriteOT);            
          out_dword(HWIO_VBIF_VBIF_IN_WR_LIM_CONF2_ADDR + uRegOffset, uRegValue);

          uRegValue = 0;
          uRegValue =  HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF3, IN_WR_LIM_C12, uWriteOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF3, IN_WR_LIM_C13, uWriteOT);   
          out_dword(HWIO_VBIF_VBIF_IN_WR_LIM_CONF3_ADDR + uRegOffset, uRegValue);   
       }
    }   
    else 
    {
       // Configure VBIF RD OT
       if (0 != uReadOT)
       {
          uRegValue = 0;
          uRegValue =  HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C0, uReadOT);
          uRegValue |= HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_RD_LIM_CONF0, IN_RD_LIM_C1, uReadOT);   
          out_dword(HWIO_VBIF_VBIF_IN_RD_LIM_CONF0_ADDR + uRegOffset, uRegValue);
       }

       // Configure VBIF WR OT
       if (0 != uWriteOT)
       {
          uRegValue = 0;
          uRegValue =  HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C0, uWriteOT);
          uRegValue = HWIO_OUT_FLD(uRegValue, VBIF_VBIF_IN_WR_LIM_CONF0, IN_WR_LIM_C1, uWriteOT);   
          out_dword(HWIO_VBIF_VBIF_IN_WR_LIM_CONF0_ADDR + uRegOffset, uRegValue);    
       }
    }

   return HAL_MDSS_STATUS_SUCCESS;
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_AoooCtrlConfig()
*/
/*!
* \brief
*     Enable/Disable SW controlling AOOOWR/RD signals on AXI protocol.
*
* \param [in] bEnable - TRUE: enable SW controlling AOOOWR/RD siganls; otherwise disable;
* \param [in] uFlags  - reserved
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_AoooCtrlConfig(
                              HAL_MDP_VbifId eVbifId,
                              bool32         bEnable,
                              uint32         uFlags )
{
    uintPtr uRegOffset = 0;

    uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

   if (TRUE == bEnable)
   {
       out_dword(HWIO_VBIF_VBIF_OUT_AXI_AOOO_EN_ADDR + uRegOffset, HWIO_VBIF_VBIF_OUT_AXI_AOOO_EN_RMSK);
       out_dword(HWIO_VBIF_VBIF_OUT_AXI_AOOO_ADDR + uRegOffset, HWIO_VBIF_VBIF_OUT_AXI_AOOO_RMSK);
   }
   else
   {
       out_dword(HWIO_VBIF_VBIF_OUT_AXI_AOOO_EN_ADDR + uRegOffset, 0);
       out_dword(HWIO_VBIF_VBIF_OUT_AXI_AOOO_ADDR + uRegOffset, 0);
   }
   
   return HAL_MDSS_STATUS_SUCCESS;
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_AMEMTYPE_CONF()
*/
/*!
* \brief
*       set VBIF_OUT_AXI_AMEMTYPE_CONF0 to 0x33333333 to work with new SMMU
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_AMEMTYPE_CONF(
                              HAL_MDP_VbifId eVbifId)
{
    uintPtr uRegOffset = 0;

    uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

    out_dword(HWIO_VBIF_VBIF_OUT_AXI_AMEMTYPE_CONF0_ADDR + uRegOffset, 0x33333333);
    out_dword(HWIO_VBIF_VBIF_OUT_AXI_AMEMTYPE_CONF1_ADDR + uRegOffset, 0x00333333);
    out_dword(HWIO_VBIF_VBIF_OUT_AXI_ASHARED_ADDR + uRegOffset, 0);

    return HAL_MDSS_STATUS_SUCCESS;
}



/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_RoundRobinQoSArbiConfig()
*/
/*!
* \brief
*     Enable/Disable Round-Robin Arbiter with QoS signal.
*
* \param [in] bEnable - TRUE: Round-Robin Arbiter with QoS signal; otherwise disable;
* \param [in] uFlags  - reserved
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_RoundRobinQoSArbiConfig(
                              HAL_MDP_VbifId eVbifId,
                              bool32         bEnable,
                              uint32         uFlags )
{
    uintPtr uRegOffset = 0;

    uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

   if (TRUE == bEnable)
   {
       out_dword(HWIO_VBIF_VBIF_ROUND_ROBIN_QOS_ARB_ADDR + uRegOffset, (HWIO_VBIF_VBIF_ROUND_ROBIN_QOS_ARB_RR_QOS_EN_BMSK |
                                                                             HWIO_VBIF_VBIF_ROUND_ROBIN_QOS_ARB_MMU_RR_QOS_EN_BMSK) );
   }
   else
   {
       out_dword(HWIO_VBIF_VBIF_ROUND_ROBIN_QOS_ARB_ADDR + uRegOffset, 0);
   }
   
   return HAL_MDSS_STATUS_SUCCESS;
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_VBif_QOSSetup()
*/
/*!
* \brief
*     VBIF QOS setup
*
* \retval None
*
****************************************************************************/
HAL_MDSS_ErrorType HAL_MDP_VBif_QOSSetup(HAL_MDP_VbifId eVbifId,
                                         uint32         uFlags )
{
   HAL_MDSS_ErrorType            eStatus     = HAL_MDSS_STATUS_SUCCESS;

   if (HAL_MDP_VBIF_0 == eVbifId)
   {
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_VIG0);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_VIG1);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_VIG2);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_VIG3);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_DMA0);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_DMA1);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_DMA2);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_DMA3);
      HAL_MDP_VBif_QOSRemapper(eVbifId, HAL_MDP_VBIF_CLIENT_DSIDMA);
   }

   return eStatus;

}

/****************************************************************************
*
** FUNCTION: HAL_MDP_VBif_QOSRemapper()
*/
/*!
* \brief
*     Recommended HW default settings for VBIF QOS remappers.
*
* \retval None
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_VBif_QOSRemapper(HAL_MDP_VbifId  eVbifId,
                                                   HAL_MDP_VBIF_ClientIDType eClientId)
{
  uintPtr                 uRegOffset = 0;
  HAL_MDSS_ErrorType      eStatus    = HAL_MDSS_STATUS_SUCCESS;

  
  uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

  //Read existing values 
  if (HAL_MDP_VBIF_0 == eVbifId)
  {
    uint32 uVBIFQOSRemap_000L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_000_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_000H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_000_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_001L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_001_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_001H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_001_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_010L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_010_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_010H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_010_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_011L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_011_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_011H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_011_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_100L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_100_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_100H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_100_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_101L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_101_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_101H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_101_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_110L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_110_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_110H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_110_ADDR + uRegOffset);  
    uint32 uVBIFQOSRemap_111L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_111_ADDR + uRegOffset);
    uint32 uVBIFQOSRemap_111H = in_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_111_ADDR + uRegOffset);  
    
    // TODO: Add support for 3rd bit 
   
    // Apply settings based on VBIF client ID..
    /*
     * Clients 0-7 are in the low tables, Clients 8-13 are in the high tables
     * NOTE: 8 levels -- level 7 is illegal
     * remapping:
     *        level 7 --> 6
     *        level 6 --> 6
     *        level 5 --> 5
     *        level 4 --> 5
     *        level 3 --> 4
     *        level 2 --> 4
     *        level 1 --> 3
     *        level 0 --> 3
     */
    switch (eClientId)
    {
       case HAL_MDP_VBIF_CLIENT_VIG0:     
           uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                    QOS_REMAP_000_C0, 3);
           uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                    QOS_REMAP_001_C0, 3);
           uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                    QOS_REMAP_010_C0,4);
           uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                    QOS_REMAP_011_C0, 4);
           uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                    QOS_REMAP_100_C0, 5);
           uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                    QOS_REMAP_101_C0, 5);
           uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                    QOS_REMAP_110_C0, 6);
           uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                    VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                    QOS_REMAP_111_C0, 6);

       break;
       case HAL_MDP_VBIF_CLIENT_DMA0:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C1, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C1, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C1, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C1, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C1, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C1, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C1, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C1, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_CURSOR0:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C2, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C2, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C2, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C2, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C2, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C2, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C2, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C2, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_VIG1:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C4, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C4, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C4, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C4, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C4, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C4, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C4, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C4, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_DMA1:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C5, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C5, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C5, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C5, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C5, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C5, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C5, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C5, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_WB2:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C6, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C6, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C6, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C6, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C6, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C6, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C6, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C6, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_DSIDMA:
        uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C7, 3);
        uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C7, 3);
        uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C7, 4);
        uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C7, 4);
        uVBIFQOSRemap_100L = HWIO_OUT_FLD(uVBIFQOSRemap_100L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C7, 5);
        uVBIFQOSRemap_101L = HWIO_OUT_FLD(uVBIFQOSRemap_101L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C7, 5);
        uVBIFQOSRemap_110L = HWIO_OUT_FLD(uVBIFQOSRemap_110L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C7, 6);
        uVBIFQOSRemap_111L = HWIO_OUT_FLD(uVBIFQOSRemap_111L,
                                 VBIF_VBIF_XINL_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C7, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_VIG2:
        uVBIFQOSRemap_000H = HWIO_OUT_FLD(uVBIFQOSRemap_000H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C8, 3);
        uVBIFQOSRemap_001H = HWIO_OUT_FLD(uVBIFQOSRemap_001H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C8, 3);
        uVBIFQOSRemap_010H = HWIO_OUT_FLD(uVBIFQOSRemap_010H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C8, 4);
        uVBIFQOSRemap_011H = HWIO_OUT_FLD(uVBIFQOSRemap_011H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C8, 4);
        uVBIFQOSRemap_100H = HWIO_OUT_FLD(uVBIFQOSRemap_100H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C8, 5);
        uVBIFQOSRemap_101H = HWIO_OUT_FLD(uVBIFQOSRemap_101H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C8, 5);
        uVBIFQOSRemap_110H = HWIO_OUT_FLD(uVBIFQOSRemap_110H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C8, 6);
        uVBIFQOSRemap_111H = HWIO_OUT_FLD(uVBIFQOSRemap_111H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C8, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_DMA2:
        uVBIFQOSRemap_000H = HWIO_OUT_FLD(uVBIFQOSRemap_000H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C9, 3);
        uVBIFQOSRemap_001H = HWIO_OUT_FLD(uVBIFQOSRemap_001H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C9, 3);
        uVBIFQOSRemap_010H = HWIO_OUT_FLD(uVBIFQOSRemap_010H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C9, 4);
        uVBIFQOSRemap_011H = HWIO_OUT_FLD(uVBIFQOSRemap_011H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C9, 4);
        uVBIFQOSRemap_100H = HWIO_OUT_FLD(uVBIFQOSRemap_100H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C9, 5);
        uVBIFQOSRemap_101H = HWIO_OUT_FLD(uVBIFQOSRemap_101H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C9, 5);
        uVBIFQOSRemap_110H = HWIO_OUT_FLD(uVBIFQOSRemap_110H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C9, 6);
        uVBIFQOSRemap_111H = HWIO_OUT_FLD(uVBIFQOSRemap_111H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C9, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_CURSOR1:
        uVBIFQOSRemap_000H = HWIO_OUT_FLD(uVBIFQOSRemap_000H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C10, 3);
        uVBIFQOSRemap_001H = HWIO_OUT_FLD(uVBIFQOSRemap_001H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C10, 3);
        uVBIFQOSRemap_010H = HWIO_OUT_FLD(uVBIFQOSRemap_010H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C10, 4);
        uVBIFQOSRemap_011H = HWIO_OUT_FLD(uVBIFQOSRemap_011H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C10, 4);
        uVBIFQOSRemap_100H = HWIO_OUT_FLD(uVBIFQOSRemap_100H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C10, 5);
        uVBIFQOSRemap_101H = HWIO_OUT_FLD(uVBIFQOSRemap_101H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C10, 5);
        uVBIFQOSRemap_110H = HWIO_OUT_FLD(uVBIFQOSRemap_110H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C10, 6);
        uVBIFQOSRemap_111H = HWIO_OUT_FLD(uVBIFQOSRemap_111H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C10, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_VIG3:
        uVBIFQOSRemap_000H = HWIO_OUT_FLD(uVBIFQOSRemap_000H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C12, 3);
        uVBIFQOSRemap_001H = HWIO_OUT_FLD(uVBIFQOSRemap_001H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C12, 3);
        uVBIFQOSRemap_010H = HWIO_OUT_FLD(uVBIFQOSRemap_010H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C12, 4);
        uVBIFQOSRemap_011H = HWIO_OUT_FLD(uVBIFQOSRemap_011H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C12, 4);
        uVBIFQOSRemap_100H = HWIO_OUT_FLD(uVBIFQOSRemap_100H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C12, 5);
        uVBIFQOSRemap_101H = HWIO_OUT_FLD(uVBIFQOSRemap_101H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C12, 5);
        uVBIFQOSRemap_110H = HWIO_OUT_FLD(uVBIFQOSRemap_110H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C12, 6);
        uVBIFQOSRemap_111H = HWIO_OUT_FLD(uVBIFQOSRemap_111H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C12, 6);
       break;
       case HAL_MDP_VBIF_CLIENT_DMA3:
        uVBIFQOSRemap_000H = HWIO_OUT_FLD(uVBIFQOSRemap_000H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_000,
                                 QOS_REMAP_000_C13, 3);
        uVBIFQOSRemap_001H = HWIO_OUT_FLD(uVBIFQOSRemap_001H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_001,
                                 QOS_REMAP_001_C13, 3);
        uVBIFQOSRemap_010H = HWIO_OUT_FLD(uVBIFQOSRemap_010H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_010,
                                 QOS_REMAP_010_C13, 4);
        uVBIFQOSRemap_011H = HWIO_OUT_FLD(uVBIFQOSRemap_011H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_011,
                                 QOS_REMAP_011_C13, 4);
        uVBIFQOSRemap_100H = HWIO_OUT_FLD(uVBIFQOSRemap_100H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_100,
                                 QOS_REMAP_100_C13, 5);
        uVBIFQOSRemap_101H = HWIO_OUT_FLD(uVBIFQOSRemap_101H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_101,
                                 QOS_REMAP_101_C13, 5);
        uVBIFQOSRemap_110H = HWIO_OUT_FLD(uVBIFQOSRemap_110H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_110,
                                 QOS_REMAP_110_C13, 6);
        uVBIFQOSRemap_111H = HWIO_OUT_FLD(uVBIFQOSRemap_111H,
                                 VBIF_VBIF_XINH_QOS_RP_REMAP_111,
                                 QOS_REMAP_111_C13, 6);
       break;
       default:
       break; 
    }

    //write into the registers
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_000_ADDR + uRegOffset, uVBIFQOSRemap_000L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_000_ADDR + uRegOffset, uVBIFQOSRemap_000H);      
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_001_ADDR + uRegOffset, uVBIFQOSRemap_001L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_001_ADDR + uRegOffset, uVBIFQOSRemap_001H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_010_ADDR + uRegOffset, uVBIFQOSRemap_010L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_010_ADDR + uRegOffset, uVBIFQOSRemap_010H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_011_ADDR + uRegOffset, uVBIFQOSRemap_011L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_011_ADDR + uRegOffset, uVBIFQOSRemap_011H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_100_ADDR + uRegOffset, uVBIFQOSRemap_100L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_100_ADDR + uRegOffset, uVBIFQOSRemap_100H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_101_ADDR + uRegOffset, uVBIFQOSRemap_101L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_101_ADDR + uRegOffset, uVBIFQOSRemap_101H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_110_ADDR + uRegOffset, uVBIFQOSRemap_110L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_110_ADDR + uRegOffset, uVBIFQOSRemap_110H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_111_ADDR + uRegOffset, uVBIFQOSRemap_111L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_RP_REMAP_111_ADDR + uRegOffset, uVBIFQOSRemap_111H);    

    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_000_ADDR + uRegOffset, uVBIFQOSRemap_000L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_000_ADDR + uRegOffset, uVBIFQOSRemap_000H);      
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_001_ADDR + uRegOffset, uVBIFQOSRemap_001L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_001_ADDR + uRegOffset, uVBIFQOSRemap_001H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_010_ADDR + uRegOffset, uVBIFQOSRemap_010L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_010_ADDR + uRegOffset, uVBIFQOSRemap_010H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_011_ADDR + uRegOffset, uVBIFQOSRemap_011L);
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_011_ADDR + uRegOffset, uVBIFQOSRemap_011H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_100_ADDR + uRegOffset, uVBIFQOSRemap_100L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_100_ADDR + uRegOffset, uVBIFQOSRemap_100H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_101_ADDR + uRegOffset, uVBIFQOSRemap_101L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_101_ADDR + uRegOffset, uVBIFQOSRemap_101H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_110_ADDR + uRegOffset, uVBIFQOSRemap_110L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_110_ADDR + uRegOffset, uVBIFQOSRemap_110H);    
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_LVL_REMAP_111_ADDR + uRegOffset, uVBIFQOSRemap_111L);    
    out_dword(HWIO_VBIF_VBIF_XINH_QOS_LVL_REMAP_111_ADDR + uRegOffset, uVBIFQOSRemap_111H);    
 }
 else if (HAL_MDP_VBIF_1 == eVbifId)
 {
   // Rotator (NRT) clients
   uint32 uVBIFQOSRemap_000L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_000_ADDR + uRegOffset);
   uint32 uVBIFQOSRemap_001L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_001_ADDR + uRegOffset);
   uint32 uVBIFQOSRemap_010L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_010_ADDR + uRegOffset);
   uint32 uVBIFQOSRemap_011L = in_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_011_ADDR + uRegOffset);

   // TODO: Add support for 3rd bit
   
   // Apply settings based on VBIF client ID..
   // Clients 0-7 are in the low tables, Clients 8-13 are in the high tables
   switch (eClientId)
   {
     case HAL_MDP_VBIF_CLIENT_ROT_RD:     
       uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                QOS_REMAP_000_C0, 3);
       uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                QOS_REMAP_001_C0, 3);
       uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                QOS_REMAP_010_C0, 4);
       uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                QOS_REMAP_011_C0, 4);
     break;
     case HAL_MDP_VBIF_CLIENT_ROT_WR:
       uVBIFQOSRemap_000L = HWIO_OUT_FLD(uVBIFQOSRemap_000L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_000,
                                QOS_REMAP_000_C1, 3);
       uVBIFQOSRemap_001L = HWIO_OUT_FLD(uVBIFQOSRemap_001L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_001,
                                QOS_REMAP_001_C1, 3);
       uVBIFQOSRemap_010L = HWIO_OUT_FLD(uVBIFQOSRemap_010L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_010,
                                QOS_REMAP_010_C1, 4);
       uVBIFQOSRemap_011L = HWIO_OUT_FLD(uVBIFQOSRemap_011L,
                                VBIF_VBIF_XINL_QOS_RP_REMAP_011,
                                QOS_REMAP_011_C1, 4);
       break;
     default:
       break; 
    }

    //write into the registers
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_000_ADDR + uRegOffset, uVBIFQOSRemap_000L);
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_001_ADDR + uRegOffset, uVBIFQOSRemap_001L);
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_010_ADDR + uRegOffset, uVBIFQOSRemap_010L);
    out_dword(HWIO_VBIF_VBIF_XINL_QOS_RP_REMAP_011_ADDR + uRegOffset, uVBIFQOSRemap_011L);
 }
  
 return eStatus; 
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_AXI_Halt()
*/
/*!
* \brief
*     Halts all AXI ports in a Vbif block
*
* \param [in] eVbifId    - VBIF block ID
* \param [in] uIdleMask  - AXI Port masks
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
static HAL_MDSS_ErrorType HAL_MDP_Vbif_AXI_Halt(HAL_MDP_VbifId eVbifId, uint32 uIdleMask)
{
  uintPtr            uRegOffset      = 0;
  uint32             uCtrlRegValue   = 0;
  uint32             uCnt            = 0x00;
  HAL_MDSS_ErrorType eStatus         = HAL_MDSS_MDP_STATUS_FAILED;
  uint32             uAckMask        = HWIO_VBIF_VBIF_AXI_HALT_CTRL1_HALT_ACK_BMSK;
  bool32             bAXIIdle        = FALSE;

  uRegOffset = HAL_MDP_Get_Vbif_BaseOffset(eVbifId);

  // Issue a halt request
  uCtrlRegValue = in_dword(HWIO_VBIF_VBIF_AXI_HALT_CTRL0_ADDR + uRegOffset);
  uCtrlRegValue = HWIO_OUT_FLD(uCtrlRegValue, VBIF_VBIF_AXI_HALT_CTRL0, HALT_REQ, 1);

  out_dword(HWIO_VBIF_VBIF_AXI_HALT_CTRL0_ADDR + uRegOffset, uCtrlRegValue);

  // Poll for AXI HALT acknowledgement
  for(uCnt = 0; uCnt < HAL_ROT_MAX_RETRIES_FOR_VBIF_PATH_RESET_COMPLETE; uCnt++)
  {
    uint32 uStatusRegValue = in_dword(HWIO_VBIF_VBIF_AXI_HALT_CTRL1_ADDR + uRegOffset);

    if ((uAckMask == (uStatusRegValue & uAckMask)) &&
        (uIdleMask == (uStatusRegValue & uIdleMask)))
    {
      // Halt succeeded
      bAXIIdle = TRUE;
      eStatus  = HAL_MDSS_STATUS_SUCCESS;
      break;
    }
  }

  // Clear the halt request bits
  uCtrlRegValue = HWIO_OUT_FLD(uCtrlRegValue, VBIF_VBIF_AXI_HALT_CTRL0, HALT_REQ, 0);
  out_dword(HWIO_VBIF_VBIF_AXI_HALT_CTRL0_ADDR + uRegOffset, uCtrlRegValue);

  return eStatus;
}

/* -------------------------------------------------------------------------------------
 * Public functions
 * ------------------------------------------------------------------------------------ */

/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_Init()
*/
/*!
* \brief
*     Initializes VBIF settings.
*
* \param [in] eVbifId    - VBIF block ID
* \param [in] uFlags     - reserved flags
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
HAL_MDSS_ErrorType HAL_MDP_Vbif_Init(HAL_MDP_VbifId eVbifId, uint32 uFlags)
{
   /* configure VBIF clock gating */
   HAL_MDP_Vbif_Config_ClockGating(eVbifId, ((HAL_MDP_VBIF_ENABLE_CLOCKGATING & uFlags) ? TRUE : FALSE), 0);
   
   /* configure VBIF burst limits */
   HAL_MDP_Vbif_BurstLimitsConfig(eVbifId, 
                                  pgsMdpHwInfo->uVBIFMaxDdrRdBurstSize,
                                  pgsMdpHwInfo->uVBIFMaxRdOT,
                                  pgsMdpHwInfo->uVBIFMaxDdrWrBurstSize,
                                  pgsMdpHwInfo->uVBIFMaxWrOT,
                                  0);

   /* enable SW controlling AOOOWR/RD signals on AXI protocol */
   HAL_MDP_Vbif_AoooCtrlConfig(eVbifId, TRUE, 0);

   HAL_MDP_VBif_QOSSetup(eVbifId, 0);

   /* enable Round-Robin Arbiter with QoS signal */
   HAL_MDP_Vbif_RoundRobinQoSArbiConfig(eVbifId, TRUE, 0);

   // Recommended VBIF settings for Gandalf MDSS
   if(NULL != pgsMdpHwInfo->sIpFxnTbl.Vbif_HwDefaultConfig)
   {
       pgsMdpHwInfo->sIpFxnTbl.Vbif_HwDefaultConfig(eVbifId);
   }

   HAL_MDP_Vbif_AMEMTYPE_CONF(eVbifId);

   return HAL_MDSS_STATUS_SUCCESS;
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_Vbif_Deinit()
*/
/*!
* \brief
*     Deinitializes MDP VBIF
*
* \param [in] eVbifId    - VBIF block ID
* \param [in] uFlags     - reserved flags
*
* \retval HAL_MDSS_ErrorType
*
****************************************************************************/
HAL_MDSS_ErrorType HAL_MDP_Vbif_Deinit(HAL_MDP_VbifId eVbifId, uint32 uFlags)
{
  uint32             uIdleMask = 0;
  HAL_MDSS_ErrorType eStatus   = HAL_MDSS_STATUS_FAILED_NOT_SUPPORTED;

  // Number of AXI ports are different for different eVbifIds. So create the appropriate mask.
  switch (eVbifId)
  {
  case HAL_MDP_VBIF_0:
     // VBIF_0 is the realtime VBIF client used by MDP and has 2 AXI ports (A0 & A1)
    uIdleMask = (HWIO_VBIF_VBIF_AXI_HALT_CTRL1_HALT_IDLE_A0_BMSK | HWIO_VBIF_VBIF_AXI_HALT_CTRL1_HALT_IDLE_A1_BMSK);
    break;
  case HAL_MDP_VBIF_1:
     // VBIF_1 is the non-realtime VBIF client used by Rotator and has 1 AXI port (A0)
    uIdleMask = (HWIO_VBIF_VBIF_AXI_HALT_CTRL1_HALT_IDLE_A0_BMSK);
    break;
  default:
    // Invalid VBIF ID
    eStatus = HAL_MDSS_STATUS_FAILED_NOT_SUPPORTED;
    break;
  }

  if (0 != uIdleMask)
  {
    eStatus = HAL_MDP_Vbif_AXI_Halt(eVbifId, uIdleMask);
  }
  
  return eStatus;
}


#ifdef __cplusplus
}
#endif
