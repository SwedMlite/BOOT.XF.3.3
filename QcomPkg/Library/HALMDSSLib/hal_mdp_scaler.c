/*
===========================================================================

FILE:         hal_mdp_source.h

===========================================================================
  Copyright (c) 2010-2018 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
===========================================================================
*/

/* -----------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------- */

#include "hal_mdp_i.h"
#include "hal_mdp.h"


#ifdef __cplusplus
extern "C" {
#endif

static uint32 aSep1DLUTs[10][33] = { // [10][33] - 32 bit uint
    /* upscale    */{ 0,4261413376,4227859456,4211017472,4194175743,4177268223,4143649023,4143518718,4109834238,4076149758,4075954173,4058981373,4058785788,4041813243,4024840443,4024579578,4007541498,4007280633,4007019768,3989981688,4006432503,3989394423,3989068278,4005519093,3988481268,3988089588,4004540403,4004214003,4003887858,4003561713,4019946993,4019620848,4036006128 },
    /* ds < 1.25  */{ 0,16516096,16254976,15993856,15732736,15471616,15210496,14949376,14688256,14427136,14166016,13904896,13643776,13382656,13121536,12860416,12599296,12338176,12077056,11815936,11554816,11293696,11032576,10771456,10510336,10249216,9988096,9726976,9465856,9204736,8943616,8682496,8421376 },
    /* ds < 1.50  */{ 449648896,432676096,415768576,398861056,398665216,381757696,364784896,347877376,330969856,330774016,313866496,296893696,279986176,263078656,262882816,245975296,229002496,212094976,195187456,194991616,178084096,161111296,144203776,127296256,110323456,93415936,93220096,76312576,59405056,42432256,25524736,25328896,8421376 },
    /* ds < 1.75  */{ 732637696,715730176,682110976,665268736,648361216,614742016,597899776,580992256,547373056,530530816,513623296,480004096,463161856,446254336,412635136,395792896,378885376,345266176,328423936,311516416,277897216,261054976,227370496,210528256,176909056,160001536,143159296,109540096,92632576,75790336,42171136,25263616,8421376 },
    /* ds < 2.00  */{ 932329216,898775296,881933056,848379136,814759936,797917696,764363776,730744576,697190656,680348416,646794496,613175296,596333056,562779136,529159936,495606016,478763776,445209856,411590656,394748416,344417536,327575296,294021376,260402176,226848256,210006016,176386816,142832896,125990656,92436736,58817536,25263616,8421376 },
    /* ds < 2.50  */{ 1082146816,1048592896,1015038976,981485056,947931136,914377216,880823296,847269376,813715456,780161536,746607616,713053696,679499776,645945856,612391936,578838016,545284096,511730176,478176256,444622336,411068416,377514496,343960576,310406656,276852736,243298816,209744896,176190976,142637056,109083136,75529216,41975296,8421376 },
    /* ds < 3.00  */{ 1298550016,1281772801,1264995841,1231441666,1197887491,1164333316,1147556101,1114002181,1097224966,1063670791,1030116616,1013339401,979785481,963008266,929454091,895899916,879122701,845634061,812079886,778525711,761748496,728194576,711417361,677863186,644309011,627531796,593977876,577200661,543646486,510092311,476538136,459761176,426207001 },
    /* ds < 3.50  */{ 1448432896,1431655681,1398101251,1381324036,1364546821,1330992391,1314215176,1297437961,1263883531,1247106316,1230329101,1196774671,1179997456,1163220241,1129665811,1112888596,1096111381,1062556951,1045779736,1029002521,995448091,978670876,961893661,928339231,911562016,894784801,861230371,844453156,827675941,794121511,777344296,760567081,727012651 },
    /* ds < 4.00  */{ 1246316836,1229539621,1229539621,1212762406,1195985191,1195985191,1179207976,1179207976,1162430761,1162430761,1145653546,1128876331,1128876331,1112099116,1112099116,1095321901,1095321901,1078544686,1061767471,1061767471,1044990256,1044990256,1028213041,1028213041,1011435826,994658611,994658611,977881396,977881396,961104181,961104181,944326966,927549751 },
    /* ds = 4.00  */{ 1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576,1077952576 }
};


/****************************************************************************
*
** FUNCTION: HAL_MDP_Get_DestScaler_BaseOffset()
*/
/*!
* \brief
*     Returns the offset of Destination scaler register block from first layer's SSPP address
*
* \param [in]   eDestPipe         - Destination pipe id
*
* \retval uint32
*
****************************************************************************/
static uintPtr HAL_MDP_Get_DestScaler_BaseOffset(HAL_MDP_DestinationPipeId   eDestPipe)
{
   uintPtr      uRegOffset        = 0;

   uRegOffset = uMDPDestScalerRegBaseOffset[eDestPipe];

   return uRegOffset;
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_QSEED_LUTConfig()
*/
/*!
* \brief
*     Configures the QSEED LUT
*
* \param [in] uRegOffset            - Scalar register offset
* \param [in] psScalarConfig        - QSEED LUT configuration
*
* \retval NONE
*
****************************************************************************/
static void HAL_MDP_QSEED_LUTConfig(uintPtr                   uScalarRegOffset,
                                    HAL_MDP_ScalarConfigType *psScalarConfig)
{
  uint32 COEF_SEP_INFO[2][2] = 
  {
    { 33,  0x000  },
    { 33,  0x200  },
  };

  bool32  enableWr[2] =
  {
    psScalarConfig->bYSepWriteEnable,
    psScalarConfig->bUVSepWriteEnable
  };

  uint32*  wrLut[2] = 
  {
    NULL, NULL
  };

  uint32  lutValue[2] = 
  {
    psScalarConfig->eYSepLutIndex,
    psScalarConfig->eUVSepLutIndex
  };

  uint32     uFilterId           = 0;
  uintPtr    uQseed3CoefBase     = 0;
  uint32     uRegIndex           = 0;
  uint32     uLutIndex           = 0;
  uint32     uCoefTabSize        = 0;
  uintPtr    uRegAddr            = 0;
  uint32     uLutCtrl            = 0;
  
  if ( psScalarConfig->bYSepWriteEnable ||
       psScalarConfig->bUVSepWriteEnable )
  {
    if((psScalarConfig->bYSepWriteEnable) &&
       (psScalarConfig->eYSepLutIndex >= HAL_MDP_QSEED_LUT_INDEX_0) &&
       (psScalarConfig->eYSepLutIndex <  HAL_MDP_QSEED_LUT_INDEX_MAX))
    {
      wrLut[0] = (uint32 *)&aSep1DLUTs[psScalarConfig->eYSepLutIndex - HAL_MDP_QSEED_LUT_INDEX_0];
    }

    if((psScalarConfig->bUVSepWriteEnable) && 
       (psScalarConfig->eUVSepLutIndex >= HAL_MDP_QSEED_LUT_INDEX_0) &&
       (psScalarConfig->eUVSepLutIndex < HAL_MDP_QSEED_LUT_INDEX_MAX))
    {
      wrLut[1] = (uint32 *)&aSep1DLUTs[psScalarConfig->eUVSepLutIndex - HAL_MDP_QSEED_LUT_INDEX_0];
    }

    for (uFilterId = 0; uFilterId < (sizeof(enableWr)/sizeof(enableWr[0])); uFilterId++)
    { 
      if ((enableWr[uFilterId] == 0) || (lutValue[uFilterId] < HAL_MDP_QSEED_LUT_INDEX_0))
      {
          continue;
      }
      uLutIndex = 0;

      uQseed3CoefBase  = HWIO_MDP_VP_0_VIG_0_QSEED3_COEF_LUT_COEF_Y_SEP_IDXi_DATA_ADDR(0) + uScalarRegOffset + COEF_SEP_INFO[uFilterId][1];
      uCoefTabSize     = COEF_SEP_INFO[uFilterId][0];
      uRegAddr         = uQseed3CoefBase;

      for (uRegIndex = 0; uRegIndex < uCoefTabSize; uRegIndex++, uRegAddr += 4, uLutIndex++)
      {
        out_dword(uRegAddr , wrLut[uFilterId][uLutIndex]);
      }
    } 
  } 

  // Enable SWAP
  if(psScalarConfig->bLutSwapEnable)
  {
    uLutCtrl   = in_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_COEF_LUT_CTRL_ADDR + uScalarRegOffset);
    uLutCtrl   = HWIO_OUT_FLD(uLutCtrl, MDP_VP_0_VIG_0_QSEED3_COEF_LUT_CTRL, SWAP, 1);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_COEF_LUT_CTRL_ADDR + uScalarRegOffset, uLutCtrl); 
  }
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_QSEED_DE_Config()
*/
/*!
* \brief
*     Program  qseed DE registers
*
* \param [in]   uRegOffset              - Register offset
* \param [in]   psScalarConfig          - Scalar configuration
*
* \retval void
*
****************************************************************************/
void HAL_MDP_QSEED_DE_Config(uintPtr                          uRegOffset,
                             HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uint32        uDeSharpen          = 0;
  uint32        uDeSharpenCtl       = 0;
  uint32        uDeShapeCtl         = 0;
  uint32        uDeThreshold        = 0;
  uint32        uDeAdjustData0      = 0;
  uint32        uDeAdjustData1      = 0;
  uint32        uDeAdjustData2      = 0;

  if (TRUE == psScalarConfig->sDetailEnhancer.bDetailEnhancerEnable)
  {
    uDeSharpen   = HWIO_OUT_FLD(uDeSharpen,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN,
                     DE_SHARPEN_LEVEL1,
                     psScalarConfig->sDetailEnhancer.iDeSharpenLevel1);
    uDeSharpen   = HWIO_OUT_FLD(uDeSharpen,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN,
                     DE_SHARPEN_LEVEL2,
                     psScalarConfig->sDetailEnhancer.iDeSharpenLevel2);

    uDeSharpenCtl = HWIO_OUT_FLD(uDeSharpenCtl,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN_CTL,
                     DE_LIMIT,
                     psScalarConfig->sDetailEnhancer.uDeLimit);
    uDeSharpenCtl = HWIO_OUT_FLD(uDeSharpenCtl,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN_CTL,
                     DE_PREC,
                     psScalarConfig->sDetailEnhancer.uDePrecisionShift);
    uDeSharpenCtl = HWIO_OUT_FLD(uDeSharpenCtl,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN_CTL,
                     DE_CLIP,
                     psScalarConfig->sDetailEnhancer.uDeClipShift);

    uDeShapeCtl   = HWIO_OUT_FLD(uDeShapeCtl,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHAPE_CTL,
                     THR_QUIET,
                     psScalarConfig->sDetailEnhancer.uDeThresholdQuiet);
    uDeShapeCtl   = HWIO_OUT_FLD(uDeShapeCtl,
                     MDP_VP_0_VIG_0_QSEED3_DE_SHAPE_CTL,
                     THR_DIEOUT,
                     psScalarConfig->sDetailEnhancer.uDeThresholdDieout);

    uDeThreshold   = HWIO_OUT_FLD(uDeThreshold,
                     MDP_VP_0_VIG_0_QSEED3_DE_THRESHOLD,
                     THR_LOW,
                     psScalarConfig->sDetailEnhancer.uDeThresholdLow);
    uDeThreshold   = HWIO_OUT_FLD(uDeThreshold,
                     MDP_VP_0_VIG_0_QSEED3_DE_THRESHOLD,
                     THR_HIGH,
                     psScalarConfig->sDetailEnhancer.uDeThresholdHigh);

    uDeAdjustData0   = HWIO_OUT_FLD(uDeAdjustData0,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_0,
                     ADJUST_A0,
                     psScalarConfig->sDetailEnhancer.iDeAdjustA[0]);
    uDeAdjustData0   = HWIO_OUT_FLD(uDeAdjustData0,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_0,
                     ADJUST_A1,
                     psScalarConfig->sDetailEnhancer.iDeAdjustA[1]);
    uDeAdjustData0   = HWIO_OUT_FLD(uDeAdjustData0,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_0,
                     ADJUST_A2,
                     psScalarConfig->sDetailEnhancer.iDeAdjustA[2]);

    uDeAdjustData1   = HWIO_OUT_FLD(uDeAdjustData1,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_1,
                     ADJUST_B0,
                     psScalarConfig->sDetailEnhancer.iDeAdjustB[0]);
    uDeAdjustData1   = HWIO_OUT_FLD(uDeAdjustData1,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_1,
                     ADJUST_B1,
                     psScalarConfig->sDetailEnhancer.iDeAdjustB[1]);
    uDeAdjustData1   = HWIO_OUT_FLD(uDeAdjustData1,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_1,
                     ADJUST_B2,
                     psScalarConfig->sDetailEnhancer.iDeAdjustB[2]);

    uDeAdjustData2   = HWIO_OUT_FLD(uDeAdjustData2,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_2,
                     ADJUST_C0,
                     psScalarConfig->sDetailEnhancer.iDeAdjustC[0]);
    uDeAdjustData2   = HWIO_OUT_FLD(uDeAdjustData2,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_2,
                     ADJUST_C1,
                     psScalarConfig->sDetailEnhancer.iDeAdjustC[1]);
    uDeAdjustData2   = HWIO_OUT_FLD(uDeAdjustData2,
                     MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_2,
                     ADJUST_C2,
                     psScalarConfig->sDetailEnhancer.iDeAdjustC[2]);

    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN_ADDR       + uRegOffset, uDeSharpen);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_SHARPEN_CTL_ADDR   + uRegOffset, uDeSharpenCtl);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_SHAPE_CTL_ADDR     + uRegOffset, uDeShapeCtl);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_THRESHOLD_ADDR     + uRegOffset, uDeThreshold);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_0_ADDR + uRegOffset, uDeAdjustData0);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_1_ADDR + uRegOffset, uDeAdjustData1);
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DE_ADJUST_DATA_2_ADDR + uRegOffset, uDeAdjustData2);
  }
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_QSEED_Config()
*/
/*!
* \brief
*     Program  qseed registers
*
* \param [in]   uRegOffset              - Register offset
* \param [in]   psScalarConfig          - Scalar configuration
*
* \retval void
*
****************************************************************************/
static void HAL_MDP_QSEED_Config(uintPtr                          uRegOffset,
                                 HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uint32        uOpMode             = 0;
  uint32        uPreload            = 0;
  uint32        uSrcSizeY           = 0;
  uint32        uSrcSizeUV          = 0;
  uint32        uDstSize            = 0;
    
    /* Always enable scaler even in the unity scaling case*/
    uOpMode = HWIO_OUT_FLD(uOpMode,
                           MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                           EN,
                           psScalarConfig->bScalarEnable);
    if (TRUE == psScalarConfig->bScalarEnable)
    {
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             DIR_EN,
                             psScalarConfig->bDirectionDetectionEnable);
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             DE_EN,
                             psScalarConfig->sDetailEnhancer.bDetailEnhancerEnable);
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             ALPHA_EN,
                             psScalarConfig->bAlpha);
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             COLOR_SPACE,
                             psScalarConfig->bYuvColorSpace);
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             BIT_WIDTH,
                             psScalarConfig->bBitWidth);

      /* Scaling filter of component y/rgb */
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             Y_CFG,
                             psScalarConfig->uC0Filter);
      /* Scaling filter of component uv */
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             UV_CFG,
                             psScalarConfig->uC12Filter);
      
      /* Scaling filter of alpha component */
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_VP_0_VIG_0_QSEED3_OP_MODE,
                             A_CFG,
                             psScalarConfig->uC3Filter);

      uPreload = HWIO_OUT_FLD(uPreload,
                              MDP_VP_0_VIG_0_QSEED3_PRELOAD,
                              Y_PRELOAD_H,
                              psScalarConfig->iC03HorizontalPreload);
      uPreload = HWIO_OUT_FLD(uPreload,
                              MDP_VP_0_VIG_0_QSEED3_PRELOAD,
                              Y_PRELOAD_V,
                              psScalarConfig->iC03VerticalPreload);
      uPreload = HWIO_OUT_FLD(uPreload,
                              MDP_VP_0_VIG_0_QSEED3_PRELOAD,
                              UV_PRELOAD_H,
                              psScalarConfig->iC12HorizontalPreload);
      uPreload = HWIO_OUT_FLD(uPreload,
                              MDP_VP_0_VIG_0_QSEED3_PRELOAD,
                              UV_PRELOAD_V,
                              psScalarConfig->iC12VerticalPreload);

      uSrcSizeY = HWIO_OUT_FLD(uSrcSizeY,
                               MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_Y_RGB_A,
                               Y_RGB_A_SRC_W,
                               psScalarConfig->uC03SrcWidth);
      uSrcSizeY = HWIO_OUT_FLD(uSrcSizeY,
                               MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_Y_RGB_A,
                               Y_RGB_A_SRC_H,
                               psScalarConfig->uC03SrcHeight);
      uSrcSizeUV = HWIO_OUT_FLD(uSrcSizeUV,
                               MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_UV,
                               UV_SRC_W,
                               psScalarConfig->uC12SrcWidth);
      uSrcSizeUV = HWIO_OUT_FLD(uSrcSizeUV,
                                MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_UV,
                                UV_SRC_H,
                                psScalarConfig->uC12SrcHeight);

      uDstSize = HWIO_OUT_FLD(uDstSize,
                              MDP_VP_0_VIG_0_QSEED3_DST_SIZE,
                              DST_W,
                              psScalarConfig->uDstWidth);
      uDstSize = HWIO_OUT_FLD(uDstSize,
                              MDP_VP_0_VIG_0_QSEED3_DST_SIZE,
                              DST_H,
                              psScalarConfig->uDstHeight);
      
      HAL_MDP_QSEED_LUTConfig(uRegOffset, psScalarConfig);

      if(TRUE == psScalarConfig->sDetailEnhancer.bDetailEnhancerEnable)
      {
        HAL_MDP_QSEED_DE_Config(uRegOffset,psScalarConfig);
      }

      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_INIT_Y_H_ADDR   + uRegOffset, psScalarConfig->uC03HorizontalInitPhase);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_INIT_Y_V_ADDR   + uRegOffset, psScalarConfig->uC03VerticalInitPhase);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_INIT_UV_H_ADDR  + uRegOffset, psScalarConfig->uC12HorizontalInitPhase);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_INIT_UV_V_ADDR  + uRegOffset, psScalarConfig->uC12VerticalInitPhase);
      
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_STEP_Y_H_ADDR   + uRegOffset,psScalarConfig->uC03HorizontalPhaseStep);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_STEP_Y_V_ADDR   + uRegOffset,psScalarConfig->uC03VerticalPhaseStep);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_STEP_UV_H_ADDR  + uRegOffset,psScalarConfig->uC12HorizontalPhaseStep);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PHASE_STEP_UV_V_ADDR  + uRegOffset,psScalarConfig->uC12VerticalPhaseStep);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_PRELOAD_ADDR          + uRegOffset,uPreload);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_Y_RGB_A_ADDR + uRegOffset,uSrcSizeY);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_SRC_SIZE_UV_ADDR      + uRegOffset,uSrcSizeUV);
      out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_DST_SIZE_ADDR         + uRegOffset,uDstSize);
    }
    out_dword(HWIO_MDP_VP_0_VIG_0_QSEED3_OP_MODE_ADDR          + uRegOffset, uOpMode);

}



/****************************************************************************
*
** FUNCTION: HAL_MDP_SSPP_ScalerLUTConfig()
*/
/*!
* \brief
*     Configures the SSPP scaler LUT
*
* \param [in] eSourcePipe           - Source Pipe ID
* \param [in] psScalarConfig        - QSEED LUT configuration
*
* \retval NONE
*
****************************************************************************/
void HAL_MDP_SSPP_ScalerLUTConfig(HAL_MDP_SourcePipeId      eSourcePipe, 
                                  HAL_MDP_ScalarConfigType *psScalarConfig)
{
  uintPtr uLayerRegOffset = HAL_MDP_Get_Layer_BaseOffset(eSourcePipe);

  HAL_MDP_QSEED_LUTConfig(uLayerRegOffset,psScalarConfig);
}


/****************************************************************************
*
** FUNCTION: HAL_MDP_SSPP_ScalerDEConfig()
*/
/*!
* \brief
*     Program  scaler DE registers
*
* \param [in]   eSourcePipe             - Source pipe id
* \param [in]   eLayerType              - Layer Type, Only RGB, VG and DMA are supported
* \param [in]   psScalarConfig          - Scalar configuration
*
* \retval void
*
****************************************************************************/
void HAL_MDP_SSPP_ScalerDEConfig(HAL_MDP_SourcePipeId             eSourcePipe,
                                 HAL_MDP_LayerType                eLayerType,
                                 HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uintPtr       uLayerRegOffset     = 0;

  if(HAL_MDP_LAYER_TYPE_VIG == eLayerType)
  {
    uLayerRegOffset   = HAL_MDP_Get_Layer_BaseOffset(eSourcePipe);
    HAL_MDP_QSEED_DE_Config(uLayerRegOffset,psScalarConfig);
  }
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_SSPP_ScalerConfig()
*/
/*!
* \brief
*     Program  scaler registers
*
* \param [in]   eSourcePipe             - Source pipe id
* \param [in]   eLayerType              - Layer Type, Only RGB, VG and DMA are supported
* \param [in]   psScalarConfig          - Scalar configuration
*
* \retval void
*
****************************************************************************/
void HAL_MDP_SSPP_ScalerConfig(HAL_MDP_SourcePipeId             eSourcePipe,
                               HAL_MDP_LayerType                eLayerType,
                               HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uintPtr       uLayerRegOffset     = 0;

  if(HAL_MDP_LAYER_TYPE_VIG == eLayerType)
  {
    uLayerRegOffset   = HAL_MDP_Get_Layer_BaseOffset(eSourcePipe);
    HAL_MDP_QSEED_Config(uLayerRegOffset,psScalarConfig);
  }
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_SSPP_ScalerLUTConfig()
*/
/*!
* \brief
*     Configures the DSPP scaler LUT
*
* \param [in] eDestPipe             - Destination Pipe ID
* \param [in] psScalarConfig        - QSEED LUT configuration
*
* \retval NONE
*
****************************************************************************/
void HAL_MDP_DSPP_ScalerLUTConfig(HAL_MDP_DestinationPipeId   eDestPipe, 
                                  HAL_MDP_ScalarConfigType   *psScalarConfig)
{
  uintPtr uRegOffset = HAL_MDP_Get_DestScaler_BaseOffset(eDestPipe);

  HAL_MDP_QSEED_LUTConfig(uRegOffset,psScalarConfig);
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_DSPP_ScalerDEConfig()
*/
/*!
* \brief
*     Program  destination scaler DE registers
*     populated from HAL_MDP_UTILITY_CalcDisplayConfig()
*
* \param [in]   eDestPipe               - Destination pipe id
* \param [in]   psScalarConfig          - Values populated from 
*                                         HAL_MDP_UTILITY_CalcDisplayConfig()
*
* \retval void
*
****************************************************************************/
void HAL_MDP_DSPP_ScalerDEConfig(HAL_MDP_DestinationPipeId        eDestPipe,
                                 HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uintPtr uDestScalarRegOffset = HAL_MDP_Get_DestScaler_BaseOffset(eDestPipe);

  HAL_MDP_QSEED_DE_Config(uDestScalarRegOffset,psScalarConfig);
}

/****************************************************************************
*
** FUNCTION: HAL_MDP_DSPP_ScalerConfig()
*/
/*!
* \brief
*     Program  scaler registers
*
* \param [in]   eDestPipe               - Destination pipe id
* \param [in]   psScalarConfig          - Scalar configuration
*
* \retval void
*
****************************************************************************/
void HAL_MDP_DSPP_ScalerConfig(HAL_MDP_DestinationPipeId        eDestPipe,
                               HAL_MDP_ScalarConfigType        *psScalarConfig)
{
  uintPtr uRegOffset      = HAL_MDP_Get_DestScaler_BaseOffset(eDestPipe);
  static uint32  uOpMode  = 0;

  if( (HAL_MDP_DESTINATION_PIPE_0 == eDestPipe) || (HAL_MDP_DESTINATION_PIPE_1 == eDestPipe))
  {
    HAL_MDP_QSEED_Config(uRegOffset,psScalarConfig);

    //uOpMode  = in_dword(HWIO_MDP_DEST_SCALER_0_OP_MODE_ADDR);
    if(HAL_MDP_DESTINATION_PIPE_0 == eDestPipe)
    {
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_DEST_SCALER_0_OP_MODE,
                             SCALER_0_EN,
                             psScalarConfig->bScalarEnable);
    }
    else
    {
      uOpMode = HWIO_OUT_FLD(uOpMode,
                             MDP_DEST_SCALER_0_OP_MODE,
                             SCALER_1_EN,
                             psScalarConfig->bScalarEnable);
    }
    uOpMode = HWIO_OUT_FLD(uOpMode,
                           MDP_DEST_SCALER_0_OP_MODE,
                           SCALER_01_DUAL_MODE,
                           psScalarConfig->bDualScalarMode);
    out_dword(HWIO_MDP_DEST_SCALER_0_OP_MODE_ADDR, uOpMode);
  }

}




#ifdef __cplusplus
}
#endif
