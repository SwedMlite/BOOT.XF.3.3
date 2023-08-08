/*
==============================================================================

FILE:         ClockBSP.c

DESCRIPTION:
  This file contains the clock driver BSP data.

  Auto-generated from the following IPCat controller releases:

    SM8250v1 (kona_1.0):
      PLL_HSR   : 13.0
      AOSS_CC   : z_aoss_cc_3.0_p3q3r6.28 [kona_aoss_cc.r5]
      GCC       : z_kona_clk_ctl_p3q3r13_s3 [kona_gcc.r25]
      GPU_CC    : z_gpu_cc_3.0_p3q3r3.2_fp2 [kona_gpu_cc.r6]

    SM8250v2 (kona_2.0):
      PLL_HSR   : 5.0
      AOSS_CC   : z_aoss_cc_3.0_p3q3r6.39 [kona_aoss_cc.r5]
      GCC       : z_kona_clk_ctl_p3q3r13_s7 [kona_gcc.r25]
      GPU_CC    : z_gpu_cc_3.0_v2_p3q3r3.2_fp3 [kona_v2_gpu_cc.r2]


  Generated using the following clockdrivergen settings:

CLOCKDRIVERGEN_CONFIG = \
{'filter_warning': 'sw',
 'generators': [{'options': {'chipinfo_enum': {'kona': 'sm8250'},
                             'clock_flags': {'gpll0': ['DO_NOT_DISABLE']},
                             'env': ['boot', 'rpmh'],
                             'explicit_ownership': True,
                             'ignore_env_for_pll_settings': True,
                             'include_all_freqs': ['.*sdc.*',
                                                   '.*qspi.*',
                                                   '.*ddrmc.*'],
                             'include_boot_enable_list': True,
                             'include_clocks': False,
                             'include_control': False,
                             'include_debug_mux': False,
                             'include_default_freqs': False,
                             'include_domain_array': False,
                             'include_file': {'ClockBSPExtern.h': True,
                                              'HALclkPLLSettings.h': True,
                                              'HALclkTest.c': False},
                             'include_fmax': False,
                             'include_master_enums': True,
                             'include_only_fmax': {'.*': ['nominal']},
                             'include_only_freqs': {'.*qup.*wrap._s.*': [7372800,
                                                                         14745600,
                                                                         19200000]},
                             'include_pllout_hw_ctl': True,
                             'include_power_domains': False,
                             'include_source_map': False,
                             'include_source_name': False,
                             'include_unique_id': False,
                             'include_voltage_control': False,
                             'include_xo_voting': False,
                             'no_static_scope': ['.*']},
                 'output_dir': '.',
                 'type': 'dalclock'}],
 'target': ['kona']}

==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockBSP.c#13 $

==============================================================================
            Copyright (c) 2019 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockBSP.h"
#include "HALclkHWIO.h"
#include "HALhwio.h"


/*=========================================================================
      Externs
==========================================================================*/


/*=========================================================================
      Data Declarations
==========================================================================*/


/*=========================================================================
      Source Register Settings
==========================================================================*/

static const ClockSourceRegSettingsType ClockSourceRegSettings_AOSSCC_AOSSCCPLL0[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x20485699,
      .nConfigCtl1  = 0x00002261,
      .nConfigCtl2  = 0x329A699C,
      .nTestCtl     = 0x00000000,
      .nTestCtl1    = 0x00000000,
      .nTestCtl2    = 0x00000000,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00000805,
      .nUserCtl2    = 0x00000000,
    },
  },
};

static const ClockSourceRegSettingsType ClockSourceRegSettings_AOSSCC_AOSSCCPLL1[] =
{
  {
    .HALSettings = {
      .nConfigCtl   = 0x60008F64,
      .nConfigCtl1  = 0x0001C808,
      .nConfigCtl2  = 0x00000000,
      .nConfigCtl3  = 0x04000780,
      .nTestCtl     = 0x0088C496,
      .nTestCtl1    = 0x60000000,
      .nTestCtl2    = 0x44210030,
      .nTestCtl3    = 0x00000398,
      .nUserCtl     = 0x00000000,
      .nUserCtl1    = 0x00250002,
    },
  },
};


/*=========================================================================
      Source BSP
==========================================================================*/

/*
 * ClockSourceBSP_AOSSCC_AOSSCCPLL0
 *
 * Used by:
 *   ClockSource_AOSSCC_AOSSCCPLL0
 *   ClockSource_GCC_GPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_AOSSCC_AOSSCCPLL0[] =
{
  {  600000000,  { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucid.nEven = 2}           }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
};
static const ClockSourceFreqConfigType ClockSourceBSPCal_AOSSCC_AOSSCCPLL0[] =
{
  { 1305600000,  { 0, 0, 1, 68,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};

/*
 * ClockSourceBSP_AOSSCC_AOSSCCPLL1
 *
 * Used by:
 *   ClockSource_AOSSCC_AOSSCCPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_AOSSCC_AOSSCCPLL1[] =
{
  {   38400000,  { 0, 0, 1, 2,   0x00000000, HAL_CLK_PLL_FRAC_MODE_UNKNOWN, {.Tweety.nEven = 2}          }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
};

/*
 * ClockSourceBSP_GCC_GPLL1
 *
 * Used by:
 *   ClockSource_GCC_GPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL1[] =
{
  { 1066000000,  { 0, 0, 1, 55,  0x00008555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL10
 *
 * Used by:
 *   ClockSource_GCC_GPLL10
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL10[] =
{
  { 1000000000,  { 0, 0, 1, 52,  0x00001555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       {{0x01, 0x00}, {0x02, 0x00}, CHIPINFO_FAMILY_SM8250}},
  { 1020000000,  { 0, 0, 1, 53,  0x00002000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       {{0x02, 0x00}, {0xFF, 0xFF}, CHIPINFO_FAMILY_SM8250}},
};

/*
 * ClockSourceBSP_GCC_GPLL2
 *
 * Used by:
 *   ClockSource_GCC_GPLL2
 *   ClockSource_GCC_GPLL3
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL2[] =
{
  {  400000000,  { 0, 0, 1, 20,  0x0000D555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
  {  451200000,  { 0, 0, 1, 23,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
  {  547200000,  { 0, 0, 1, 28,  0x00008000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
};

/*
 * ClockSourceBSP_GCC_GPLL4
 *
 * Used by:
 *   ClockSource_GCC_GPLL4
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL4[] =
{
  {  806000000,  { 0, 0, 1, 41,  0x0000FAAA, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL5
 *
 * Used by:
 *   ClockSource_GCC_GPLL5
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL5[] =
{
  {  933000000,  { 0, 0, 1, 48,  0x00009800, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL6
 *
 * Used by:
 *   ClockSource_GCC_GPLL6
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL6[] =
{
  {  880000000,  { 0, 0, 1, 45,  0x0000D555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL7
 *
 * Used by:
 *   ClockSource_GCC_GPLL7
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL7[] =
{
  { 1036000000,  { 0, 0, 1, 53,  0x0000F555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL8
 *
 * Used by:
 *   ClockSource_GCC_GPLL8
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL8[] =
{
  {  700000000,  { 0, 0, 1, 36,  0x00007555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};

/*
 * ClockSourceBSP_GCC_GPLL9
 *
 * Used by:
 *   ClockSource_GCC_GPLL9
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL9[] =
{
  {  808000000,  { 0, 0, 1, 42,  0x00001555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};


/*=========================================================================
      Sources
==========================================================================*/

ClockSourceNodeType ClockSource_AOSSCC_AOSSCCPLL0 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_AOSSCC_AOSSCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_AOSSCC_AOSSCCPLL0),
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE |
                  CLOCK_CONFIG_PLL_ODD_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(AOSS_CC_PLL0_MODE),
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_AOSSCC_AOSSCCPLL1 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_AOSSCC_AOSSCCPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_AOSSCC_AOSSCCPLL1),
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(AOSS_CC_PLL1_MODE),
  },
  .pCalibrationFreqConfig     = ClockSourceBSP_AOSSCC_AOSSCCPLL1,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSP_AOSSCC_AOSSCCPLL1),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL1,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL1),
};

ClockSourceNodeType ClockSource_GCC_GPLL0 =
{
  .nFlags       = CLOCK_FLAG_DO_NOT_DISABLE |
                  CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_AOSSCC_AOSSCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_AOSSCC_AOSSCCPLL0),
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE |
                  CLOCK_CONFIG_PLL_EVEN_OUTPUT_HW_CTL |
                  CLOCK_CONFIG_PLL_FSM_MODE_ENABLE |
                  CLOCK_CONFIG_PLL_MAIN_OUTPUT_HW_CTL,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL0_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x1},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL1 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL1),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL1_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x2},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL10 =
{
  .nFlags       = 0x0,
  .aBSP         = ClockSourceBSP_GCC_GPLL10,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL10),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL10_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x400},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL2 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL2,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL2),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL2_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x4},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL3 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL2,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL2),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL3_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x8},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL4 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL4,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL4),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL4_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x10},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL5 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL5,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL5),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL5_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x20},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL6 =
{
  .nFlags       = 0x0,
  .aBSP         = ClockSourceBSP_GCC_GPLL6,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL6),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL6_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x40},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL7 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL7,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL7),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL7_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x80},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL8 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL8,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL8),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL8_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x100},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};

ClockSourceNodeType ClockSource_GCC_GPLL9 =
{
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_GCC_GPLL9,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL9),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL9_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x200},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_AOSSCC_AOSSCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_AOSSCC_AOSSCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_AOSSCC_AOSSCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_AOSSCC_AOSSCCPLL0),
};


static ClockSourceNodeType *aSources[] =
{
  &ClockSource_AOSSCC_AOSSCCPLL0,
  &ClockSource_AOSSCC_AOSSCCPLL1,
  &ClockSource_GCC_GPLL0,
  &ClockSource_GCC_GPLL1,
  &ClockSource_GCC_GPLL10,
  &ClockSource_GCC_GPLL2,
  &ClockSource_GCC_GPLL3,
  &ClockSource_GCC_GPLL4,
  &ClockSource_GCC_GPLL5,
  &ClockSource_GCC_GPLL6,
  &ClockSource_GCC_GPLL7,
  &ClockSource_GCC_GPLL8,
  &ClockSource_GCC_GPLL9,
};


/*=========================================================================
      Domain BSP
==========================================================================*/

/*
 * ClockDomainBSP_AOSSCC_AOSSCCAOP
 *
 * Used by:
 *   ClockDomain_AOSSCC_AOSSCCAOP
 */
static ClockMuxConfigType ClockDomainBSP_AOSSCC_AOSSCCAOP[] =
{
  {  400000000, &ClockSource_AOSSCC_AOSSCCPLL0,           { 1,     3,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = AOSS_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_AOSSCC_AOSSCCEUDAT
 *
 * Used by:
 *   ClockDomain_AOSSCC_AOSSCCEUDAT
 */
static ClockMuxConfigType ClockDomainBSP_AOSSCC_AOSSCCEUDAT[] =
{
  {   60000000, &ClockSource_AOSSCC_AOSSCCPLL0,           { 1,     10,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = AOSS_CC_PLL0_OUT_EVEN */
};

/*
 * ClockDomainBSP_AOSSCC_AOSSCCIBI
 *
 * Used by:
 *   ClockDomain_AOSSCC_AOSSCCIBI
 */
static ClockMuxConfigType ClockDomainBSP_AOSSCC_AOSSCCIBI[] =
{
  {   38400000, &ClockSource_AOSSCC_AOSSCCPLL1,           { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[3] = AOSS_CC_PLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_AOSSCC_AOSSCCRO
 *
 * Used by:
 *   ClockDomain_AOSSCC_AOSSCCRO
 *   ClockDomain_AOSSCC_AOSSCCSPMIAODSER
 *   ClockDomain_AOSSCC_AOSSCCSWAOTS
 */
static ClockMuxConfigType ClockDomainBSP_AOSSCC_AOSSCCRO[] =
{
  {   19200000, &ClockSource_AOSSCC_AOSSCCPLL1,           { 3,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_RET,        },                                                            /* Mux[3] = AOSS_CC_PLL1_OUT_EVEN */
};

/*
 * ClockDomainBSP_AOSSCC_AOSSCCSWAO
 *
 * Used by:
 *   ClockDomain_AOSSCC_AOSSCCSWAO
 */
static ClockMuxConfigType ClockDomainBSP_AOSSCC_AOSSCCSWAO[] =
{
  {  300000000, &ClockSource_AOSSCC_AOSSCCPLL0,           { 1,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = AOSS_CC_PLL0_OUT_EVEN */
};

/*
 * ClockDomainBSP_GCC_GCCACC
 *
 * Used by:
 *   ClockDomain_GCC_GCCACC
 *   ClockDomain_GCC_GCCUSB30PRIMMASTER
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCACC[] =
{
  {  200000000, &ClockSource_GCC_GPLL0,                   { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP13_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOCCDSPNOC
 *   ClockDomain_GCC_GCCTURINGQ6AXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC[] =
{
  {  710666667, &ClockSource_GCC_GPLL1,                   { 4,     3,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOC
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOC
 *   ClockDomain_GCC_GCCQUPV3WRAP0CORE2X
 *   ClockDomain_GCC_GCCQUPV3WRAP1CORE2X
 *   ClockDomain_GCC_GCCQUPV3WRAP2CORE2X
 *   ClockDomain_GCC_GCCSYSNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOC[] =
{
  {  200000000, &ClockSource_GCC_GPLL0,                   { 1,     6,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOCNORTHSF
 *   ClockDomain_GCC_GCCAGGRENOCSOUTHSF
 *   ClockDomain_GCC_GCCAGGRENOCWESTSF
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF[] =
{
  {  400000000, &ClockSource_GCC_GPLL0,                   { 1,     3,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCAGGRENOCSF
 *
 * Used by:
 *   ClockDomain_GCC_GCCAGGRENOCSF
 *   ClockDomain_GCC_GCCMMUTCU
 *   ClockDomain_GCC_GCCSYSNOCSFAXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCAGGRENOCSF[] =
{
  {  403000000, &ClockSource_GCC_GPLL4,                   { 5,     4,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[5] = GPLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCCE1
 *
 * Used by:
 *   ClockDomain_GCC_GCCCE1
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCE1[] =
{
  {  171428571, &ClockSource_GCC_GPLL0,                   { 1,     7,     0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP13_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCCFGNOCLPASS
 *
 * Used by:
 *   ClockDomain_GCC_GCCCFGNOCLPASS
 *   ClockDomain_GCC_GCCCNOCPERIPH
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCFGNOCLPASS[] =
{
  {  100000000, &ClockSource_GCC_GPLL0,                   { 1,     12,    0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCCONFIGNOC
 *
 * Used by:
 *   ClockDomain_GCC_GCCCONFIGNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCONFIGNOC[] =
{
  {   75000000, &ClockSource_GCC_GPLL0,                   { 1,     16,    0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCCPUSSGPLL0
 *
 * Used by:
 *   ClockDomain_GCC_GCCCPUSSGPLL0
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCPUSSGPLL0[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 6,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP22_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCDDRMCCH0ROOT
 *
 * Used by:
 *   ClockDomain_GCC_GCCDDRMCCH0ROOT
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCDDRMCCH0ROOT[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {  100000000, &ClockSource_GCC_GPLL0,                   { 6,     6,     0,     0,     0x01 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP17_CLKGEN_ACGC_CLK */
  {  200000000, &ClockSource_GCC_GPLL2,                   { 2,     4,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    {{0}}, &ClockSourceBSP_GCC_GPLL2[ 0] /* 400.0  */ },          /* Mux[2] = GPLL2_OUT_MAIN */
  {  300000000, &ClockSource_GCC_GPLL0,                   { 6,     2,     0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP17_CLKGEN_ACGC_CLK */
  {  451200000, &ClockSource_GCC_GPLL2,                   { 2,     2,     0,     0,     0x04 }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    {{0}}, &ClockSourceBSP_GCC_GPLL2[ 1] /* 451.0  */ },          /* Mux[2] = GPLL2_OUT_MAIN */
  {  547200000, &ClockSource_GCC_GPLL2,                   { 2,     2,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_SVS,        {{0}}, &ClockSourceBSP_GCC_GPLL2[ 2] /* 547.0  */ },          /* Mux[2] = GPLL2_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCDDRMCCH1ROOT
 *
 * Used by:
 *   ClockDomain_GCC_GCCDDRMCCH1ROOT
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCDDRMCCH1ROOT[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {  100000000, &ClockSource_GCC_GPLL0,                   { 6,     6,     0,     0,     0x01 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP17_CLKGEN_ACGC_CLK */
  {  200000000, &ClockSource_GCC_GPLL3,                   { 3,     4,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    {{0}}, &ClockSourceBSP_GCC_GPLL2[ 0] /* 400.0  */ },          /* Mux[3] = GPLL3_OUT_MAIN */
  {  300000000, &ClockSource_GCC_GPLL0,                   { 6,     2,     0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP17_CLKGEN_ACGC_CLK */
  {  451200000, &ClockSource_GCC_GPLL3,                   { 3,     2,     0,     0,     0x04 }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    {{0}}, &ClockSourceBSP_GCC_GPLL2[ 1] /* 451.0  */ },          /* Mux[3] = GPLL3_OUT_MAIN */
  {  547200000, &ClockSource_GCC_GPLL3,                   { 3,     2,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_SVS,        {{0}}, &ClockSourceBSP_GCC_GPLL2[ 2] /* 547.0  */ },          /* Mux[3] = GPLL3_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCDPM
 *
 * Used by:
 *   ClockDomain_GCC_GCCDPM
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCDPM[] =
{
  {  200000000, &ClockSource_GCC_GPLL0,                   { 6,     3,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP16_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCGPUMEMNOCGFX
 *
 * Used by:
 *   ClockDomain_GCC_GCCGPUMEMNOCGFX
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCGPUMEMNOCGFX[] =
{
  {  533000000, &ClockSource_GCC_GPLL1,                   { 4,     4,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCIPA2X
 *
 * Used by:
 *   ClockDomain_GCC_GCCIPA2X
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCIPA2X[] =
{
  {  466500000, &ClockSource_GCC_GPLL5,                   { 3,     4,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[3] = GPLL5_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMEMNOC
 *
 * Used by:
 *   ClockDomain_GCC_GCCMEMNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMEMNOC[] =
{
  {  806000000, &ClockSource_GCC_GPLL4,                   { 5,     2,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[5] = GPLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMMNOCHFQX
 *
 * Used by:
 *   ClockDomain_GCC_GCCMMNOCHFQX
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMMNOCHFQX[] =
{
  {  355333333, &ClockSource_GCC_GPLL1,                   { 4,     6,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMMNOCSFQX
 *
 * Used by:
 *   ClockDomain_GCC_GCCMMNOCSFQX
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMMNOCSFQX[] =
{
  {  518000000, &ClockSource_GCC_GPLL7,                   { 2,     4,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[2] = GPLL7_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMMSSQMCORE
 *
 * Used by:
 *   ClockDomain_GCC_GCCMMSSQMCORE
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMMSSQMCORE[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP2_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCNPUDMA
 *
 * Used by:
 *   ClockDomain_GCC_GCCNPUDMA
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCNPUDMA[] =
{
  {  700000000, &ClockSource_GCC_GPLL8,                   { 2,     2,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[2] = GPLL8_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSATBA
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSATBA
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSATBA[] =
{
  {  240000000, &ClockSource_GCC_GPLL0,                   { 1,     5,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSATBB
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSATBB
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSATBB[] =
{
  {  240000000, &ClockSource_GCC_GPLL0,                   { 1,     5,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSATBC
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSATBC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSATBC[] =
{
  {  120000000, &ClockSource_GCC_GPLL0,                   { 1,     10,    0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSSTM
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSSTM
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSSTM[] =
{
  {  200000000, &ClockSource_GCC_GPLL0,                   { 1,     6,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSTRACECLKIN
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSTRACECLKIN
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSTRACECLKIN[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQDSSTRIG
 *
 * Used by:
 *   ClockDomain_GCC_GCCQDSSTRIG
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQDSSTRIG[] =
{
  {  150000000, &ClockSource_GCC_GPLL0,                   { 1,     8,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQSPICORE
 *
 * Used by:
 *   ClockDomain_GCC_GCCQSPICORE
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQSPICORE[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   75000000, &ClockSource_GCC_GPLL0,                   { 6,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP18_CLKGEN_ACGC_CLK */
  {  150000000, &ClockSource_GCC_GPLL0,                   { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCQUPV3WRAP0S0
 *
 * Used by:
 *   ClockDomain_GCC_GCCQUPV3WRAP0S0
 *   ClockDomain_GCC_GCCQUPV3WRAP0S1
 *   ClockDomain_GCC_GCCQUPV3WRAP0S2
 *   ClockDomain_GCC_GCCQUPV3WRAP0S3
 *   ClockDomain_GCC_GCCQUPV3WRAP0S4
 *   ClockDomain_GCC_GCCQUPV3WRAP0S5
 *   ClockDomain_GCC_GCCQUPV3WRAP0S6
 *   ClockDomain_GCC_GCCQUPV3WRAP0S7
 *   ClockDomain_GCC_GCCQUPV3WRAP1S0
 *   ClockDomain_GCC_GCCQUPV3WRAP1S1
 *   ClockDomain_GCC_GCCQUPV3WRAP1S2
 *   ClockDomain_GCC_GCCQUPV3WRAP1S3
 *   ClockDomain_GCC_GCCQUPV3WRAP1S4
 *   ClockDomain_GCC_GCCQUPV3WRAP1S5
 *   ClockDomain_GCC_GCCQUPV3WRAP2S0
 *   ClockDomain_GCC_GCCQUPV3WRAP2S1
 *   ClockDomain_GCC_GCCQUPV3WRAP2S2
 *   ClockDomain_GCC_GCCQUPV3WRAP2S3
 *   ClockDomain_GCC_GCCQUPV3WRAP2S4
 *   ClockDomain_GCC_GCCQUPV3WRAP2S5
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCQUPV3WRAP0S0[] =
{
  {    7372800, &ClockSource_GCC_GPLL0,                   { 6,     2,     384,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP19_CLKGEN_ACGC_CLK */
  {   14745600, &ClockSource_GCC_GPLL0,                   { 6,     2,     768,   15625, 0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP19_CLKGEN_ACGC_CLK */
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
};

/*
 * ClockDomainBSP_GCC_GCCSDCC2APPS
 *
 * Used by:
 *   ClockDomain_GCC_GCCSDCC2APPS
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSDCC2APPS[] =
{
  {     400000, NULL,                                     { 0,     24,    1,     4,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   25000000, &ClockSource_GCC_GPLL0,                   { 6,     24,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP18_CLKGEN_ACGC_CLK */
  {   50000000, &ClockSource_GCC_GPLL0,                   { 6,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP18_CLKGEN_ACGC_CLK */
  {  100000000, &ClockSource_GCC_GPLL0,                   { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
  {  202000000, &ClockSource_GCC_GPLL9,                   { 2,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[2] = GPLL9_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCSDCC4APPS
 *
 * Used by:
 *   ClockDomain_GCC_GCCSDCC4APPS
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSDCC4APPS[] =
{
  {     400000, NULL,                                     { 0,     24,    1,     4,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   25000000, &ClockSource_GCC_GPLL0,                   { 6,     24,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP18_CLKGEN_ACGC_CLK */
  {   50000000, &ClockSource_GCC_GPLL0,                   { 6,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP18_CLKGEN_ACGC_CLK */
  {  100000000, &ClockSource_GCC_GPLL0,                   { 1,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCSHRM
 *
 * Used by:
 *   ClockDomain_GCC_GCCSHRM
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSHRM[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
  {  403000000, &ClockSource_GCC_GPLL4,                   { 5,     4,     0,     0,     0x04 }, RAIL_VOLTAGE_LEVEL_NOM,        {{0x02, 0x00}, {0xFF, 0xFF}, CHIPINFO_FAMILY_SM8250}, },      /* Mux[5] = GPLL4_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCSYSNOCGCAXI
 *
 * Used by:
 *   ClockDomain_GCC_GCCSYSNOCGCAXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCSYSNOCGCAXI[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCTURINGAXI
 *
 * Used by:
 *   ClockDomain_GCC_GCCTURINGAXI
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCTURINGAXI[] =
{
  {  533000000, &ClockSource_GCC_GPLL1,                   { 4,     4,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCUFSPHYAXI
 *
 * Used by:
 *   ClockDomain_GCC_GCCUFSPHYAXI
 *   ClockDomain_GCC_GCCUFSPHYICECORE
 *   ClockDomain_GCC_GCCUFSPHYUNIPROCORE
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCUFSPHYAXI[] =
{
  {  300000000, &ClockSource_GCC_GPLL0,                   { 1,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP5_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCVSENSOR
 *
 * Used by:
 *   ClockDomain_GCC_GCCVSENSOR
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCVSENSOR[] =
{
  {  600000000, &ClockSource_GCC_GPLL0,                   { 1,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP1_CLKGEN_ACGC_CLK */
};

/*
 * ClockDomainBSP_GPUCC_GPUCCRBCPR
 *
 * Used by:
 *   ClockDomain_GPUCC_GPUCCRBCPR
 */
static ClockMuxConfigType ClockDomainBSP_GPUCC_GPUCCRBCPR[] =
{
  {   50000000, &ClockSource_GCC_GPLL0,                   { 6,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[6] = GPLL0_OUT_MAIN_DIV */
};


/*=========================================================================
      Domain Source Maps
==========================================================================*/


/*=========================================================================
      Domain FMAX
==========================================================================*/


/*=========================================================================
      Domains
==========================================================================*/

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCAOP =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCAOP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCAOP),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_AOP_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCEUDAT =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCEUDAT,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCEUDAT),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_EUD_AT_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCIBI =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCIBI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCIBI),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_IBI_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCRO =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCRO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCRO),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_RO_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSPMIAODSER =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCRO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCRO),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_SPMI_AOD_SER_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSWAO =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCSWAO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCSWAO),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_SWAO_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSWAOTS =
{
  .aBSP      = ClockDomainBSP_AOSSCC_AOSSCCRO,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_AOSSCC_AOSSCCRO),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(AOSS_CC_SWAO_TS_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCACC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCACC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCACC),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_ACC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCCDSPNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_CDSP_NOC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCNORTHSF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_NORTH_SF_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCSF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_SF_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCSOUTHSF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_SOUTH_SF_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCWESTSF =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCNORTHSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_AGGRE_NOC_WEST_SF_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCCE1 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCE1,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCE1),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CE1_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCCFGNOCLPASS =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCFGNOCLPASS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCFGNOCLPASS),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CFG_NOC_LPASS_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCCNOCPERIPH =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCFGNOCLPASS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCFGNOCLPASS),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CNOC_PERIPH_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CONFIG_NOC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCCPUSSGPLL0 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCPUSSGPLL0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCPUSSGPLL0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CPUSS_GPLL0_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCDDRMCCH0ROOT =
{
  .aBSP      = ClockDomainBSP_GCC_GCCDDRMCCH0ROOT,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCDDRMCCH0ROOT),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_DDRMC_CH0_ROOT_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCDDRMCCH1ROOT =
{
  .aBSP      = ClockDomainBSP_GCC_GCCDDRMCCH1ROOT,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCDDRMCCH1ROOT),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_DDRMC_CH1_ROOT_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCDPM =
{
  .aBSP      = ClockDomainBSP_GCC_GCCDPM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCDPM),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_DPM_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCGPUMEMNOCGFX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCGPUMEMNOCGFX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCGPUMEMNOCGFX),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_GPU_MEMNOC_GFX_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCIPA2X =
{
  .aBSP      = ClockDomainBSP_GCC_GCCIPA2X,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCIPA2X),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_IPA_2X_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCMEMNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMEMNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMEMNOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MEMNOC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCMMNOCHFQX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMMNOCHFQX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMMNOCHFQX),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMNOC_HF_QX_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCMMNOCSFQX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMMNOCSFQX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMMNOCSFQX),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMNOC_SF_QX_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCMMSSQMCORE =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMMSSQMCORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMMSSQMCORE),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMSS_QM_CORE_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCMMUTCU =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMU_TCU_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCNPUDMA =
{
  .aBSP      = ClockDomainBSP_GCC_GCCNPUDMA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCNPUDMA),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_NPU_DMA_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBA =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSATBA,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSATBA),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_ATB_A_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBB =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSATBB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSATBB),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_ATB_B_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSATBC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSATBC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_ATB_C_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSSTM =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSSTM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSSTM),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_STM_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSTRACECLKIN =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSTRACECLKIN,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSTRACECLKIN),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_TRACECLKIN_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQDSSTRIG =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQDSSTRIG,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQDSSTRIG),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QDSS_TRIG_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQSPICORE =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQSPICORE,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQSPICORE),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QSPI_CORE_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0CORE2X =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_CORE_2X_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S0 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S0_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S1 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S1_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S2 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S2_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S3 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S3_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S4 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S4_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S5 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S5_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S6 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S6_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S7 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP0_S7_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1CORE2X =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_CORE_2X_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S0 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S0_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S1 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S1_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S2 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S2_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S3 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S3_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S4 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S4_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S5 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP1_S5_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2CORE2X =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_CORE_2X_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S0 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S0_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S1 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S1_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S2 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S2_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S3 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S3_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S4 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S4_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S5 =
{
  .aBSP      = ClockDomainBSP_GCC_GCCQUPV3WRAP0S0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCQUPV3WRAP0S0),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_QUPV3_WRAP2_S5_CMD_RCGR),
    .nMNDWidth  = 16,
    .nDFSStates = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSDCC2APPS =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSDCC2APPS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSDCC2APPS),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SDCC2_APPS_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSDCC4APPS =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSDCC4APPS,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSDCC4APPS),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SDCC4_APPS_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSHRM =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSHRM,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSHRM),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SHRM_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSYSNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SYS_NOC_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCGCAXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCSYSNOCGCAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCSYSNOCGCAXI),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SYS_NOC_GC_AXI_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCSFAXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCSF,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCSF),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_SYS_NOC_SF_AXI_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCTURINGAXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCTURINGAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCTURINGAXI),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_TURING_AXI_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCTURINGQ6AXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCAGGRENOCCDSPNOC),
  .eMaster   = CLOCK_MASTER_RPMH,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_TURING_Q6_AXI_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYAXI =
{
  .aBSP      = ClockDomainBSP_GCC_GCCUFSPHYAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCUFSPHYAXI),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_UFS_PHY_AXI_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYICECORE =
{
  .aBSP      = ClockDomainBSP_GCC_GCCUFSPHYAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCUFSPHYAXI),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_UFS_PHY_ICE_CORE_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYUNIPROCORE =
{
  .aBSP      = ClockDomainBSP_GCC_GCCUFSPHYAXI,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCUFSPHYAXI),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_UFS_PHY_UNIPRO_CORE_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCUSB30PRIMMASTER =
{
  .aBSP      = ClockDomainBSP_GCC_GCCACC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCACC),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_USB30_PRIM_MASTER_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

ClockDomainNodeType ClockDomain_GCC_GCCVSENSOR =
{
  .aBSP      = ClockDomainBSP_GCC_GCCVSENSOR,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCVSENSOR),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_VSENSOR_CMD_RCGR),
  },
};

ClockDomainNodeType ClockDomain_GPUCC_GPUCCRBCPR =
{
  .aBSP      = ClockDomainBSP_GPUCC_GPUCCRBCPR,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GPUCC_GPUCCRBCPR),
  .eMaster   = CLOCK_MASTER_DEFAULT,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GPUCC_GPU_CC_RBCPR_CMD_RCGR),
  },
};


/*=========================================================================
      Enable Lists
==========================================================================*/

static uintptr_t aPDEnable[] =
{
  HWIO_ADDR(GCC_IPA_GDSCR),
  HWIO_ADDR(GCC_MMNOC_GDSCR),
};

static uintptr_t aBranchEnable[] =
{
  // HWIO_ADDR(GCC_AGGRE_CNOC_PERIPH_NORTH_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_CNOC_PERIPH_SOUTH_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_AGGRE_NOC_AUDIO_TBU_CBCR),
  HWIO_ADDR(GCC_AGGRE_NOC_CDSP_NOC_AXI_CBCR),
  HWIO_ADDR(GCC_AGGRE_NOC_CDSP_NOC_Q6_AXI_CBCR),
  // HWIO_ADDR(GCC_AGGRE_NOC_CENTER_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_COMPUTE_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_COMPUTE_AXI_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_AGGRE_NOC_IPA_CBCR),
  HWIO_ADDR(GCC_AGGRE_NOC_MONAQ_AXI_CBCR),
  // HWIO_ADDR(GCC_AGGRE_NOC_NORTH_AXI_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_AGGRE_NOC_QOSGEN_EXTREF_CBCR),
  // HWIO_ADDR(GCC_AGGRE_NOC_SF_CENTER_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_SF_NORTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_SF_SOUTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_SF_WEST_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_SOUTH_AHB_CFG_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_SOUTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_TBU1_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_TBU2_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AGGRE_NOC_WEST_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AHB2PHY_NORTH_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AHB2PHY_SOUTH_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AOSS_CNOC_M_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_AOSS_CNOC_S_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_CFG_NOC_AH2PHY_XO_CBCR),
  // HWIO_ADDR(GCC_CFG_NOC_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CFG_NOC_COMPUTE_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_CFG_NOC_MMNOC_AHB_CBCR),
  HWIO_ADDR(GCC_CFG_NOC_MONAQ_AHB_CBCR),
  // HWIO_ADDR(GCC_CFG_NOC_NORTH_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CFG_NOC_SOUTH_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CFG_NOC_WEST_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CM_PHY_REFGEN1_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CM_PHY_REFGEN2_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CNOC_PERIPH_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CNOC_PERIPH_NORTH_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_CNOC_PERIPH_SOUTH_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_DCC_AHB_CBCR),
  HWIO_ADDR(GCC_DDRMC_CH0_CBCR),
  HWIO_ADDR(GCC_DDRMC_CH1_CBCR),
  // HWIO_ADDR(GCC_DDRSS_CFG_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_DDRSS_MMNOC_HF_QX_CBCR),
  HWIO_ADDR(GCC_DDRSS_MMNOC_SF_QX_CBCR),
  HWIO_ADDR(GCC_DDRSS_PCIE_SF_TBU_CBCR),
  HWIO_ADDR(GCC_DDRSS_SLEEP_CBCR),
  HWIO_ADDR(GCC_DDRSS_SYS_NOC_GC_AXI_CBCR),
  // HWIO_ADDR(GCC_DDRSS_SYS_NOC_SF_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_DDRSS_SYS_NOC_SLAVE_AXI_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_DDRSS_TCU_CBCR),
  HWIO_ADDR(GCC_DDRSS_XO_CBCR),
  HWIO_ADDR(GCC_DPM_AHB_CBCR),
  HWIO_ADDR(GCC_DPM_CBCR),
  // HWIO_ADDR(GCC_IMEM_CFG_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_IPA_2X_CBCR),
  HWIO_ADDR(GCC_IPA_AHB_CBCR),
  HWIO_ADDR(GCC_IPA_CBCR),
  HWIO_ADDR(GCC_IPA_SLEEP_CBCR),
  HWIO_ADDR(GCC_IPA_XO_CBCR),
  HWIO_ADDR(GCC_IPCC_AHB_CBCR),
  HWIO_ADDR(GCC_IPCC_CORE_CBCR),
  // HWIO_ADDR(GCC_MEMNOC_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_MMNOC_AHB_CFG_CBCR),
  HWIO_ADDR(GCC_MMNOC_AT_CBCR),
  HWIO_ADDR(GCC_MMNOC_HF_QX_CBCR),
  HWIO_ADDR(GCC_MMNOC_QOSGEN_EXTREF_CBCR),
  HWIO_ADDR(GCC_MMNOC_SF_QX_CBCR),
  HWIO_ADDR(GCC_MMNOC_TBU_HF0_CBCR),
  HWIO_ADDR(GCC_MMNOC_TBU_HF1_CBCR),
  HWIO_ADDR(GCC_MMNOC_TBU_SF0_CBCR),
  HWIO_ADDR(GCC_MMNOC_TBU_SF1_CBCR),
  HWIO_ADDR(GCC_MMSS_QM_AHB_CBCR),
  HWIO_ADDR(GCC_MMSS_QM_CORE_CBCR),
  // HWIO_ADDR(GCC_MMU_TCU_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_NOC_CENTER_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_COMPUTE_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_LPASS_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_MMNOC_CNOC_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_MMNOC_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_MONAQ_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_NORTH_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_SOUTH_DCD_XO_CBCR),
  HWIO_ADDR(GCC_NOC_WEST_DCD_XO_CBCR),
  HWIO_ADDR(GCC_PIMEM_AHB_CBCR),
  HWIO_ADDR(GCC_PIMEM_AXI_CBCR),
  HWIO_ADDR(GCC_QREFS_VBG_CAL_CBCR),
  HWIO_ADDR(GCC_RBCPR_CX_AHB_CBCR),
  HWIO_ADDR(GCC_RBCPR_CX_CBCR),
  HWIO_ADDR(GCC_RBCPR_MMCX_AHB_CBCR),
  HWIO_ADDR(GCC_RBCPR_MMCX_CBCR),
  HWIO_ADDR(GCC_RBCPR_MX_AHB_CBCR),
  HWIO_ADDR(GCC_RBCPR_MX_CBCR),
  // HWIO_ADDR(GCC_SEC_CTRL_ACC_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SEC_CTRL_AHB_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SEC_CTRL_BOOT_ROM_PATCH_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SEC_CTRL_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SEC_CTRL_SENSE_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_SHRM_CBCR),
  HWIO_ADDR(GCC_SLEEP_CBCR),
  HWIO_ADDR(GCC_SNOC_QOSGEN_EXTREF_CBCR),
  // HWIO_ADDR(GCC_SYS_NOC_AHB_CFG_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_GC_AXI_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_SYS_NOC_MONAQ_AXI_CBCR),
  HWIO_ADDR(GCC_SYS_NOC_MONAQ_CBCR),
  HWIO_ADDR(GCC_SYS_NOC_MONAQ_SF_AXI_CBCR),
  // HWIO_ADDR(GCC_SYS_NOC_NORTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_SF_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_SF_NORTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_SF_TCU_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_SF_WEST_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_SOUTH_AXI_CBCR), /* Defaults on. */
  // HWIO_ADDR(GCC_SYS_NOC_WEST_AXI_CBCR), /* Defaults on. */
  HWIO_ADDR(GCC_TURING_TBU0_CBCR),
  HWIO_ADDR(GCC_TURING_TBU1_CBCR),
  // HWIO_ADDR(GCC_XO_CBCR), /* Defaults on. */
  // HWIO_ADDR(GPUCC_GPU_CC_RBCPR_AHB_CBCR), /* Defaults on. */
  HWIO_ADDR(GPUCC_GPU_CC_RBCPR_CBCR),
};

static HAL_clk_RegisterMaskType aBranchVote[] =
{
  /*
   * gcc_ce1_ahb_clk
   * gcc_ce1_axi_clk
   * gcc_ce1_clk
   * gcc_imem_axi_clk
   * gcc_prng_ahb_clk
   * gcc_tcsr_ahb_clk
   * gcc_tlmm_clk
   * gcc_tlmm_north_ahb_clk
   * gcc_tlmm_south_ahb_clk
   * gcc_tlmm_west_ahb_clk
   */
   { HWIO_ADDR(GCC_BOOT_CLK_BRANCH_ENA_VOTE), 0x100697A },

  /*
   * gcc_qupv3_wrap0_core_2x_clk
   * gcc_qupv3_wrap0_core_clk
   * gcc_qupv3_wrap1_core_2x_clk
   * gcc_qupv3_wrap1_core_clk
   * gcc_qupv3_wrap_0_m_ahb_clk
   * gcc_qupv3_wrap_0_s_ahb_clk
   * gcc_qupv3_wrap_1_m_ahb_clk
   * gcc_qupv3_wrap_1_s_ahb_clk
   */
   { HWIO_ADDR(GCC_BOOT_CLK_BRANCH_ENA_VOTE_1), 0x3C03C0 },

  /*
   * gcc_qupv3_wrap2_core_2x_clk
   * gcc_qupv3_wrap2_core_clk
   * gcc_qupv3_wrap_2_m_ahb_clk
   * gcc_qupv3_wrap_2_s_ahb_clk
   */
   { HWIO_ADDR(GCC_BOOT_CLK_BRANCH_ENA_VOTE_2), 0xF },
};

/*=========================================================================
      Main BSP
==========================================================================*/

ClockBSPType ClockBSP =
{
  .aSources          = aSources,
  .nNumSources       = SIZEOF_ARRAY(aSources),
  .nFlags            = 0x0,
  .SafeMuxConfig     = { 0, 2, 0, 0 },
  .aPDEnable         = aPDEnable,
  .nNumPDEnables     = SIZEOF_ARRAY(aPDEnable),
  .aBranchEnable     = aBranchEnable,
  .nNumBranchEnables = SIZEOF_ARRAY(aBranchEnable),
  .aBranchVote       = aBranchVote,
  .nNumBranchVotes   = SIZEOF_ARRAY(aBranchVote),
};

