/*==============================================================================

FILE:      icbcfg_data.c

DESCRIPTION: This file implements the ICB Configuration driver.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/ICB/loader/icbcfg_data.c#17 $
$DateTime: 2019/12/18 12:22:40 $
$Author: pwbldsvc $
$Change: 21887570 $

When        Who    What, where, why
----------  ---    -----------------------------------------------------------
2019/10/01  sds    Switch LLCC mode in post_init
2019/05/02  sds    Use split segment configuration
2019/03/22  sds    v4 QM recommendations
2019/03/04  sds    ADSP SCID overrides
2019/02/08  sds    QM configuration and partial throttle configuration
2019/01/14  sds    CAMNOC TrType workaround for HW CR QCTDD05560660
2018/10/15  sds    SWC update for HW CR QCTDD05350699
2018/06/20  sds    Created

                Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
                             All Rights Reserved.
                          QUALCOMM Proprietary/GTDR
==============================================================================*/
#include "icbcfg_hwio.h"
#include "../../../../../Library/ICBLib/icbcfgi.h"
#include "../../../Library/ICBTargetLib/icbcfg_hwio_target.h"

/*---------------------------------------------------------------------------*/
/*          Macro and constant definitions                                   */
/*---------------------------------------------------------------------------*/
//#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

/*============================================================================
                        DEVICE CONFIG PROPERTY DATA
============================================================================*/

/*---------------------------------------------------------------------------*/
/*          Properties data for device ID  = "icbcfg/boot"                   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* SM8250 v1                                                                 */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Init Config Segments                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* QM Config Segment                                                         */
/*---------------------------------------------------------------------------*/
icbcfg_data_type icbcfg_qm_cfg_data_sm8250_v1[] =
{
  /* Enable QM core cgc */
  ICBCFG_HWIO_DW(QM_CORE_CLK_CGC_CNTRL, 0x1),

  /* Stall timers */
  ICBCFG_HWIO_DW(QM_PRE_STALL_TIMEOUT_CNT_URG_0, 0x60),
  ICBCFG_HWIO_DW(QM_PRE_STALL_TIMEOUT_CNT_URG_1, 0x27),
  ICBCFG_HWIO_DW(QM_PRE_STALL_TIMEOUT_CNT_URG_2, 0x27),
  ICBCFG_HWIO_DW(QM_PRE_STALL_TIMEOUT_CNT_URG_3, 0x27),
  ICBCFG_HWIO_DW(QM_POST_STALL_TIMEOUT_CNT_URG_0, 0x60),
  ICBCFG_HWIO_DW(QM_POST_STALL_TIMEOUT_CNT_URG_1, 0x27),
  ICBCFG_HWIO_DW(QM_POST_STALL_TIMEOUT_CNT_URG_2, 0x27),
  ICBCFG_HWIO_DW(QM_POST_STALL_TIMEOUT_CNT_URG_3, 0x27),
  ICBCFG_HWIO_DW(QM_POST_STALL_WDW_OVERLAP_CNTL, 0x1),
  ICBCFG_HWIO_DW(QM_SMMU_INV_PRE_STALL_TIMEOUT_CNT_URG_0, 0x780),
  ICBCFG_HWIO_DW(QM_SMMU_INV_PRE_STALL_TIMEOUT_CNT_URG_1, 0x300),
  ICBCFG_HWIO_DW(QM_SMMU_INV_PRE_STALL_TIMEOUT_CNT_URG_2, 0x300),
  ICBCFG_HWIO_DW(QM_SMMU_INV_PRE_STALL_TIMEOUT_CNT_URG_3, 0x300),
  ICBCFG_HWIO_DW(QM_SMMU_INV_POST_STALL_TIMEOUT_CNT_URG_0, 0x0),
  ICBCFG_HWIO_DW(QM_SMMU_INV_POST_STALL_TIMEOUT_CNT_URG_1, 0x0),
  ICBCFG_HWIO_DW(QM_SMMU_INV_POST_STALL_TIMEOUT_CNT_URG_2, 0x0),
  ICBCFG_HWIO_DW(QM_SMMU_INV_POST_STALL_TIMEOUT_CNT_URG_3, 0x0),
  ICBCFG_HWIO_DW(QM_SMMU_INV_POST_STALL_WDW_OVERLAP_CNTL, 0x1),

  /* SAFE client overrides */
  ICBCFG_HWIO_DW(QM_DSP_SAFE_MASK_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_SAFE_OVERRIDE_VALUE, 0x8),
  ICBCFG_HWIO_DW(QM_SAFE_OVERRIDE_EN,    0x8),

  /* Titan-RT throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_0_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_0_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIO_DW(QM_CLNT_0_THROTTLE_LEVEL_OUTPUT_EN, 0x0),

  /* Titan-NRT throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_1_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_1_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_1_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_1_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_1_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_1_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* NPU throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_2_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_2_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_2_THROTTLE_LEVEL_QOS_n, 3, 0xEE000003),
  ICBCFG_HWIOI_DW(QM_CLNT_2_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_2_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_2_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_2_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* PCIe throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_3_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_3_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_3_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_3_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_3_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_3_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* SNOC throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_4_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_4_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_4_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_4_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_4_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_4_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* DPU-NRT throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_5_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_5_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_5_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_5_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_5_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_5_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* IRIS-VCODEC throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_6_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_6_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_6_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_6_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_6_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_6_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* IRIS-CVP throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_7_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_7_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_7_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_7_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_7_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_7_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* GPU throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_8_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_8_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_8_THROTTLE_LEVEL_QOS_n, 3, 0xEE000003),
  ICBCFG_HWIOI_DW(QM_CLNT_8_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_8_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_8_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_8_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* CPU throttle client */
  ICBCFG_HWIO_DW(QM_CLNT_9_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_CLNT_9_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIOI_DW(QM_CLNT_9_THROTTLE_LEVEL_QOS_n, 3, 0xEE000003),
  ICBCFG_HWIOI_DW(QM_CLNT_9_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_9_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_9_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_9_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* CDSP throttle client */
  ICBCFG_HWIO_DW(QM_DSP_DANGER_AGGR_CNTRL, 0x3),
  ICBCFG_HWIO_DW(QM_DSP_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIO_DW(QM_DSP_PRIORITY_MODE_SEL, 0x1),
  ICBCFG_HWIO_DW(QM_DSP_SYSTEM_DANGER_AGGR_MODEM_CNTRL, 0x0),
  ICBCFG_HWIO_DW(QM_DSP_SYSTEM_DANGER_OUTPUT_EN, 0x1),
  ICBCFG_HWIOI_DW(QM_CLNT_10_THROTTLE_LEVEL_QOS_n, 3, 0xEE000003),
  ICBCFG_HWIOI_DW(QM_CLNT_10_THROTTLE_LEVEL_QOS_n, 4, 0xEE000004),
  ICBCFG_HWIOI_DW(QM_CLNT_10_THROTTLE_LEVEL_QOS_n, 6, 0xEE000006),
  ICBCFG_HWIOI_DW(QM_CLNT_10_THROTTLE_LEVEL_QOS_n, 7, 0xAA000000),
  ICBCFG_HWIO_DW(QM_CLNT_10_THROTTLE_LEVEL_OUTPUT_EN, 0x3),

  /* Throttle level generation */
  ICBCFG_HWIO_DW(QM_THROTTLE_LEVEL_LEGACY_SELECT, 0x0),
  ICBCFG_HWIOI_DW(QM_THROTTLE_LEVEL_QOS_n, 7, 0x7FC),
  ICBCFG_HWIO_DW(QM_THROTTLE_LEVEL_SU_CFG, 0x7F),
  ICBCFG_HWIOF_READ_DW(CABO0_CABO_GLOBAL_DDR_CLK_PERIOD_CFG,DDR_CLK_PERIOD),
  ICBCFG_HWIOF_WRITE_DW(QM_PERIOD_BUS_CFG,PERIOD_BUS_SW),
  ICBCFG_HWIOF_DW(QM_PERIOD_BUS_CFG, PERIOD_BUS_LOAD_SW, 0x1),
  ICBCFG_HWIOF_DW(QM_PERIOD_BUS_CFG, PERIOD_BUS_SW_OVERRIDE, 0x0),
  ICBCFG_HWIOI_DW(QOS_FREQ_BAND_BNDRY_n, 0, 0x97B),
  ICBCFG_HWIOI_DW(QOS_FREQ_BAND_BNDRY_n, 1, 0x0),
  ICBCFG_HWIOI_DW(QOS_FREQ_BAND_BNDRY_n, 2, 0x0),
  ICBCFG_HWIO_DW(QM_AGGR_SAFE_OVERRIDE_CNTRL, 0x1),
  ICBCFG_HWIO_DW(QM_AGGR_SAFE_TL_V2_OVERRIDE_CNTRL, 0x0),
  ICBCFG_HWIO_DW(QM_DANGER_SAFE_CNTRL,0x1),

  /* AP throttles and shapers */
  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_0_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_0_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_0_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_0_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_0_THRESHOLD_01, 0x0064FFFF),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_0_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_0_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_0_CNTRL, 0x5E01),

  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_1_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_1_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_1_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_1_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_1_THRESHOLD_01, 0x0064FFFF),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_1_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(APP_BWMON_THROTTLE_1_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(APP_BWMON_THROTTLE_1_CNTRL, 0x5E01),

  /* GPU throttles and shapers */
  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_0_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_0_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_0_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_0_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_0_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_0_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_0_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_0_CNTRL, 0x5E01),

  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_1_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_1_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_1_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_1_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_1_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_1_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(GPU_BWMON_THROTTLE_1_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(GPU_BWMON_THROTTLE_1_CNTRL, 0x5E01),

  /* CDSP throttles and shapers */
  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_0_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_0_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_0_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_0_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_0_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_0_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_0_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_0_CNTRL, 0x5E01),

  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_1_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_1_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_1_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_1_THRESHOLD_02, 0xFFFF0064),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_1_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_1_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(CDSP_BWMON_THROTTLE_1_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(CDSP_BWMON_THROTTLE_1_CNTRL, 0x5E01),

  /* PCIe throttle and shaper */
  ICBCFG_HWIOF_DW(PCIE_THROTTLE_THROTTLE_0_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(PCIE_THROTTLE_THROTTLE_0_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(PCIE_THROTTLE_THROTTLE_0_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(PCIE_THROTTLE_THROTTLE_0_THRESHOLD_02, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(PCIE_THROTTLE_THROTTLE_0_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(PCIE_THROTTLE_THROTTLE_0_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(PCIE_THROTTLE_THROTTLE_0_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(PCIE_THROTTLE_THROTTLE_0_CNTRL, 0x5001),

  /* SNOC throttle and shaper */
  ICBCFG_HWIOF_DW(SNOC_THROTTLE_THROTTLE_0_CGC_CNTRL, THROTTLE_CGC_EN, 0x1),
  ICBCFG_HWIOF_DW(SNOC_THROTTLE_THROTTLE_0_GRANT_PERIOD, GRANT_PERIOD, 0x3e8),
  ICBCFG_HWIO_DW(SNOC_THROTTLE_THROTTLE_0_THRESHOLD_03, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(SNOC_THROTTLE_THROTTLE_0_THRESHOLD_02, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(SNOC_THROTTLE_THROTTLE_0_THRESHOLD_01, 0x0000FFFF),
  ICBCFG_HWIO_DW(SNOC_THROTTLE_THROTTLE_0_THRESHOLD_00, 0x0000FFFF),
  ICBCFG_HWIOF_DW(SNOC_THROTTLE_THROTTLE_0_PEAK_ACCUM_CREDIT, PEAK_ACCUM_CREDIT, 0x100),
  ICBCFG_HWIO_DW(SNOC_THROTTLE_THROTTLE_0_CNTRL, 0x5001),

  /* DCD Enables */
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_NORTH_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_PCIE_CENTER_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_PCIE_NORTH_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_PCIE_SOUTH_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_SOUTH_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_SP_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_ANOC_WEST_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_CDSPNOC_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(AGGRE_NOC_AGGRE_NOC_CDSPNOC_Q6_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_CENTER_QHCLK_DCD_MAXDIV_LOW, 0x1),  // SDM855 uses only 1.
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_COMPUTE_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_LPASS_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_MMNOC_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_NORTH_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_SOUTH_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(CONFIG_NOC_DCD_CNOC_WEST_QHCLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(MMSS_NOC_MNOC_HF_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(MMSS_NOC_MNOC_SF_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_CENTER_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_GC_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_LPASS_SF_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_NORTH_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_SF_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(SYSTEM_NOC_DCD_SOUTH_QX_CLK_DCD_MAXDIV_LOW, 0x4),
  ICBCFG_HWIO_DW(DC_NOCDC_NOC_DCD_DCD_MAXDIV_LOW, 0x4),
  // ICBCFG_HWIO_DW(TITAN_A_CAMNOC_CAM_NOC_CAMNOC_DCD_DCD_MAXDIV_LOW, 0x4),

};

icbcfg_prop_seg_type icbcfg_qm_cfg_seg_sm8250_v1 = 
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_qm_cfg_data_sm8250_v1),
  /* Pointer to config data array */ 
  icbcfg_qm_cfg_data_sm8250_v1                                    
};

/*---------------------------------------------------------------------------*/
/* Init Config Segment list                                                  */
/*---------------------------------------------------------------------------*/
icbcfg_prop_seg_type *icbcfg_boot_segs_sm8250_v1[] =
{
  &icbcfg_qm_cfg_seg_sm8250_v1,
};

icbcfg_prop_type icbcfg_boot_prop_sm8250_v1 =
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_boot_segs_sm8250_v1),
  /* Pointer to config data array */
  icbcfg_boot_segs_sm8250_v1
};

/*---------------------------------------------------------------------------*/
/* PostInit Config Segments                                                  */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* DDRSS SWC                                                                 */
/*---------------------------------------------------------------------------*/
icbcfg_data_type icbcfg_gemnoc_data_sm8250_v1[] =
{
  /* DDRSS SWC v7 */
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC0_POS_CTL_CFGDUT_LOW,       0x00000002),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC0_POS_CTL_CHISCE0_LOW,      0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC2_POS_CTL_CFGDUT_LOW,       0x00000002),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC2_POS_CTL_CHISCE0_LOW,      0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC1_POS_CTL_CFGDUT_LOW,       0x00000002),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC1_POS_CTL_CHISCE0_LOW,      0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC3_POS_CTL_CFGDUT_LOW,       0x00000002),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC3_POS_CTL_CHISCE0_LOW,      0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_PCIE_POS_CTL_CFGDUT_LOW,            0x00000001),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_PCIE_POS_CTL_CHISCE0_LOW,           0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_SNOC_POS_CTL_CFGDUT_LOW,            0x00000001),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_SNOC_POS_CTL_CHISCE0_LOW,           0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_GPU_TCU_DYNATTR_MAINCTL_LOW,        0x00100000),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_GPU_TCU_DYNATTR_CACHEINDEXVAL_LOW,  0x0000000B),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_SYS_TCU_DYNATTR_MAINCTL_LOW,        0x00100000),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_SYS_TCU_DYNATTR_CACHEINDEXVAL_LOW,  0x0000000D),
  ICBCFG_HWIOF_DW(GEMNOC_GEM_NOC_QNM_MNOC_SF1_QOSGEN_MAINCTL_LOW, SAFESHAPING, 0x2),
};

icbcfg_prop_seg_type icbcfg_gemnoc_seg_sm8250_v1 = 
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_gemnoc_data_sm8250_v1),
  /* Pointer to config data array */ 
  icbcfg_gemnoc_data_sm8250_v1                                    
};

/*---------------------------------------------------------------------------*/
/* Hardware Workaround Config Segment                                        */
/*---------------------------------------------------------------------------*/
icbcfg_data_type icbcfg_hwwa_data_sm8250_v1[] =
{
  /* HW CR QCTDD05560660: Override CAMNOC Device => Normal
   * Power/clocks already enabled by clock driver */
  ICBCFG_HWIO_DW(MMSS_NOC_QNM_CAMNOC_SF0_DYNATTR_TRTYPELUT_LOW,    0x00043222),
  ICBCFG_HWIOF_DW(MMSS_NOC_QNM_CAMNOC_SF0_DYNATTR_MAINCTL_LOW, TRTYPEOV, 0x1),
  ICBCFG_HWIO_DW(MMSS_NOC_QNM_CAMNOC_SF1_DYNATTR_TRTYPELUT_LOW,    0x00043222),
  ICBCFG_HWIOF_DW(MMSS_NOC_QNM_CAMNOC_SF1_DYNATTR_MAINCTL_LOW, TRTYPEOV, 0x1),
  ICBCFG_HWIO_DW(MMSS_NOC_QNM_CAMNOC_HF0_DYNATTR_TRTYPELUT_LOW,    0x00043222),
  ICBCFG_HWIOF_DW(MMSS_NOC_QNM_CAMNOC_HF0_DYNATTR_MAINCTL_LOW, TRTYPEOV, 0x1),
  ICBCFG_HWIO_DW(MMSS_NOC_QNM_CAMNOC_HF1_DYNATTR_TRTYPELUT_LOW,    0x00043222),
  ICBCFG_HWIOF_DW(MMSS_NOC_QNM_CAMNOC_HF1_DYNATTR_MAINCTL_LOW, TRTYPEOV, 0x1),
  /* Set MMNOC retention */
  ICBCFG_HWIOF_DW(GCC_MMNOC_GDSCR, RETAIN_FF_ENABLE, 0x1),

  /* LLCC force alloc, ADSP/SMMU */
  ICBCFG_HWIO_DW(LLCC_BROADCAST_LLCC_TRP_RD_NOALLOC_ON_MISS_OVERRIDE_CFG0, 0x00402000),
  ICBCFG_HWIO_DW(LLCC_BROADCAST_LLCC_TRP_WR_NOALLOC_ON_MISS_OVERRIDE_CFG0, 0x00400000),

  /* ADSP SCID overrides, clock driver enables power/clock */
  ICBCFG_HWIO_DW(LPASS_AG_NOC_QHM_LPASS_CORE_DYNATTR_CACHEINDEXVAL_LOW, 22),
  ICBCFG_HWIOF_DW(LPASS_AG_NOC_QHM_LPASS_CORE_DYNATTR_MAINCTL_LOW, CACHEINDEXOV, 1),
  ICBCFG_HWIO_DW(LPASS_AG_NOC_QNM_LPASS_HW_AF_DYNATTR_CACHEINDEXVAL_LOW, 22),
  ICBCFG_HWIOF_DW(LPASS_AG_NOC_QNM_LPASS_HW_AF_DYNATTR_MAINCTL_LOW, CACHEINDEXOV, 1),

  /* LLCC TAG sequence */
  ICBCFG_HWIO_DW(LLCC_BROADCAST_LLCC_TRP_NC_AS_C_OVERRIDE_CFG, 0xFFFFFFFF),
  ICBCFG_HWIO_DW(LLCC_BROADCAST_LLCC_TRP_C_AS_NC_OVERRIDE_CFG, 0x00000000),
};

icbcfg_prop_seg_type icbcfg_hwwa_seg_sm8250_v1 = 
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_hwwa_data_sm8250_v1),
  /* Pointer to config data array */ 
  icbcfg_hwwa_data_sm8250_v1                                    
};

/*---------------------------------------------------------------------------*/
/* PostInit Config Segment list                                              */
/*---------------------------------------------------------------------------*/
icbcfg_prop_seg_type *icbcfg_post_boot_segs_sm8250_v1[] =
{
  &icbcfg_gemnoc_seg_sm8250_v1,
  &icbcfg_hwwa_seg_sm8250_v1,
};

icbcfg_prop_type icbcfg_post_prop_sm8250_v1 =
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_post_boot_segs_sm8250_v1),
  /* Pointer to config data array */
  icbcfg_post_boot_segs_sm8250_v1
};

/*---------------------------------------------------------------------------*/
/* Memory map definition                                                     */
/*---------------------------------------------------------------------------*/
icbcfg_mem_region_type map_ddr_regions_sm8250_v1[] =
{
  { 0x080000000ULL, 0x400000000ULL },
  { 0x800000000ULL, 0x1000000000ULL },
};

/* Translation block base addresses. */
uint8 *trans_bases_sm8250_v1[] =
{
  (uint8 *)HWIO_ADDR(LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  (uint8 *)HWIO_ADDR(LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  (uint8 *)HWIO_ADDR(LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  (uint8 *)HWIO_ADDR(LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
};

/*---------------------------------------------------------------------------*/
/* TARGET: SM8250v1                                                          */
/*---------------------------------------------------------------------------*/
icbcfg_device_config_type sm8250_v1 =
{
  /* Chip version information for this device data. */
  .family   = CHIPINFO_FAMILY_SM8250,      /**< Chip family */
  .match    = false,                       /**< Exact match for version? */
  .version  = 0,                           /**< Chip version */

  /* Device information. */
  .map_ddr_region_count = ARRAY_SIZE(map_ddr_regions_sm8250_v1), /**< Number of regions in the DDR map */
  .map_ddr_regions      = map_ddr_regions_sm8250_v1,             /**< Array of mappable DDR regions */
  .num_segments         = 6,                                     /**< Number of mapping segments. */
  .num_channels         = 4,                                     /**< Number of channels. */
  .addr_width           = 36,                                    /**< Address width in bits. */
  .trans_type           = ICBCFG_ADDR_TRANS_LLCC,                /**< Address translator hardware type. */
  .trans_bases          = trans_bases_sm8250_v1,                 /**< Translation block base addresses. */

  /* Prop lists. */
  .prop_data      = &icbcfg_boot_prop_sm8250_v1,           /**< Init time prop list. */
  .post_prop_data = &icbcfg_post_prop_sm8250_v1,           /**< Post-init time prop list. */
};

/*---------------------------------------------------------------------------*/
/* SM8250 v2                                                                 */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* DDRSS SWC                                                                 */
/*---------------------------------------------------------------------------*/
icbcfg_data_type icbcfg_gemnoc_data_sm8250_v2[] =
{
  /* DDRSS SWC v1 */
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC0_POS_CTL_CHISCE0_LOW,     0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC2_POS_CTL_CHISCE0_LOW,     0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC1_POS_CTL_CHISCE0_LOW,     0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_QNS_POS_LLCC3_POS_CTL_CHISCE0_LOW,     0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_PCIE_POS_CTL_CFGDUT_LOW,           0x00000001),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_PCIE_POS_CTL_CHISCE0_LOW,          0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_SNOC_POS_CTL_CFGDUT_LOW,           0x00000001),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_POS_SNOC_POS_CTL_CHISCE0_LOW,          0x00000401),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_GPU_TCU_DYNATTR_MAINCTL_LOW,       0x00100000),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_GPU_TCU_DYNATTR_CACHEINDEXVAL_LOW, 0x0000000B),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_SYS_TCU_DYNATTR_MAINCTL_LOW,       0x00100000),
  ICBCFG_HWIO_DW(GEMNOC_GEM_NOC_ALM_SYS_TCU_DYNATTR_CACHEINDEXVAL_LOW, 0x0000000D),
};

icbcfg_prop_seg_type icbcfg_gemnoc_seg_sm8250_v2 = 
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_gemnoc_data_sm8250_v2),
  /* Pointer to config data array */ 
  icbcfg_gemnoc_data_sm8250_v2                                    
};

/*---------------------------------------------------------------------------*/
/* PostInit Config Segment list                                              */
/*---------------------------------------------------------------------------*/
icbcfg_prop_seg_type *icbcfg_post_boot_segs_sm8250_v2[] =
{
  &icbcfg_gemnoc_seg_sm8250_v2,
  &icbcfg_hwwa_seg_sm8250_v1,
};

icbcfg_prop_type icbcfg_post_prop_sm8250_v2 =
{
  /* Length of the config  data array */
  ARRAY_SIZE(icbcfg_post_boot_segs_sm8250_v2),
  /* Pointer to config data array */
  icbcfg_post_boot_segs_sm8250_v2
};

/*---------------------------------------------------------------------------*/
/* TARGET: SM8250v2                                                          */
/*---------------------------------------------------------------------------*/
icbcfg_device_config_type sm8250_v2 =
{
  /* Chip version information for this device data. */
  .family   = CHIPINFO_FAMILY_SM8250,  /**< Chip family */
  .match    = false,                   /**< Exact match for version? */
  .version  = CHIPINFO_VERSION(2,0),   /**< Chip version */

  /* Device information. */
  .map_ddr_region_count = ARRAY_SIZE(map_ddr_regions_sm8250_v1), /**< Number of regions in the DDR map */
  .map_ddr_regions      = map_ddr_regions_sm8250_v1,             /**< Array of mappable DDR regions */
  .num_segments         = 6,                                     /**< Number of mapping segments. */
  .num_channels         = 4,                                     /**< Number of channels. */
  .addr_width           = 36,                                    /**< Address width in bits. */
  .trans_type           = ICBCFG_ADDR_TRANS_LLCC,                /**< Address translator hardware type. */
  .trans_bases          = trans_bases_sm8250_v1,                 /**< Translation block base addresses. */

  /* Prop lists. */
  .prop_data      = &icbcfg_boot_prop_sm8250_v1, /**< Init time prop list. */
  .post_prop_data = &icbcfg_post_prop_sm8250_v2, /**< Post-init time prop list. */
};

/*---------------------------------------------------------------------------*/
/* TARGET LIST                                                               */
/*---------------------------------------------------------------------------*/
icbcfg_device_config_type *configs_sm8250[] =
{
  [0] = &sm8250_v2,
  [1] = &sm8250_v1,
};

/*---------------------------------------------------------------------------*/
/* EXPORTED TARGET DEFINITION                                                */
/*---------------------------------------------------------------------------*/
icbcfg_info_type icbcfg_info =
{
  .num_configs = ARRAY_SIZE(configs_sm8250),
  .configs     = configs_sm8250,
};
