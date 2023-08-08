/*
==============================================================================

FILE:         ClockBSP.c

DESCRIPTION:
  This file contains the clock driver BSP data.

  Auto-generated from the following IPCat controller releases:

    SM8250v1 (kona_1.0):
      PLL_HSR   : 13.0
      DISP_CC   : z_disp_cc_3.0_p3q3r4.8 [kona_disp_cc.r4]
      GCC       : z_kona_clk_ctl_p3q3r13_s3 [kona_gcc.r25]

    SM8250v2 (kona_2.0):
      PLL_HSR   : 5.0
      DISP_CC   : z_disp_cc_3.0_p3q3r4.8 [kona_disp_cc.r4]
      GCC       : z_kona_clk_ctl_p3q3r13_s7 [kona_gcc.r25]


  Generated using the following clockdrivergen settings:

CLOCKDRIVERGEN_CONFIG = \
{'filter_warning': 'sw',
 'generators': [{'options': {'chipinfo_enum': {'kona': 'sm8250'},
                             'env': 'ramdump',
                             'explicit_ownership': True,
                             'include_control': False,
                             'include_debug_mux': False,
                             'include_divider': ['.*disp_cc*'],
                             'include_file': {'HALclkTest.c': False},
                             'include_unique_id': False,
                             'include_voltage_control': False,
                             'include_xo_voting': False},
                 'output_dir': 'ClockRamDumpLib',
                 'type': 'dalclock'}],
 'target': ['kona']}

==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockRamDumpLib/ClockBSP.c#9 $

==============================================================================
            Copyright (c) 2020 QUALCOMM Technologies Incorporated.
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

static const ClockSourceRegSettingsType ClockSourceRegSettings_DISPCC_DISPCCPLL0[] =
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


/*=========================================================================
      Source BSP
==========================================================================*/

/*
 * ClockSourceBSP_DISPCC_DISPCCPLL0
 *
 * Used by:
 *   ClockSource_DISPCC_DISPCCPLL0
 */
static const ClockSourceFreqConfigType ClockSourceBSP_DISPCC_DISPCCPLL0[] =
{
  { 1380000000,  { 0, 0, 1, 71,  0x0000E000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};
static const ClockSourceFreqConfigType ClockSourceBSPCal_DISPCC_DISPCCPLL0[] =
{
  { 1305600000,  { 0, 0, 1, 68,  0x00000000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS_L1,    },
};

/*
 * ClockSourceBSP_DISPCC_DISPCCPLL1
 *
 * Used by:
 *   ClockSource_DISPCC_DISPCCPLL1
 */
static const ClockSourceFreqConfigType ClockSourceBSP_DISPCC_DISPCCPLL1[] =
{
  {  600000000,  { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
};

/*
 * ClockSourceBSP_GCC_GPLL0
 *
 * Used by:
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL0[] =
{
  {  600000000,  { 0, 0, 1, 31,  0x00004000, HAL_CLK_PLL_FRAC_MODE_ALPHA, {.Lucid.nEven = 2}           }, RAIL_VOLTAGE_LEVEL_MIN_SVS,   },
};

/*
 * ClockSourceBSP_GCC_GPLL1
 *
 * Used by:
 */
static const ClockSourceFreqConfigType ClockSourceBSP_GCC_GPLL1[] =
{
  { 1066000000,  { 0, 0, 1, 55,  0x00008555, HAL_CLK_PLL_FRAC_MODE_ALPHA, {{0}}                      }, RAIL_VOLTAGE_LEVEL_SVS,       },
};


/*=========================================================================
      Sources
==========================================================================*/

static ClockSourceNodeType ClockSource_DISPCC_DISPCCPLL0 =
{
  .szName       = "disp_cc_pll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC_DISPCCPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC_DISPCCPLL0),
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(DISP_CC_PLL0_MODE),
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_DISPCC_DISPCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_DISPCC_DISPCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_DISPCC_DISPCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_DISPCC_DISPCCPLL0),
};

static ClockSourceNodeType ClockSource_DISPCC_DISPCCPLL1 =
{
  .szName       = "disp_cc_pll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL,
  .aBSP         = ClockSourceBSP_DISPCC_DISPCCPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_DISPCC_DISPCCPLL1),
  .nConfigMask  = 0x0,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(DISP_CC_PLL1_MODE),
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_DISPCC_DISPCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_DISPCC_DISPCCPLL0),
  .pRegSettings               = ClockSourceRegSettings_DISPCC_DISPCCPLL0,
  .nRegSettingsLen            = SIZEOF_ARRAY(ClockSourceRegSettings_DISPCC_DISPCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GPLL0 =
{
  .szName       = "gpll0",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL |
                  CLOCK_FLAG_READ_ONLY,
  .aBSP         = ClockSourceBSP_GCC_GPLL0,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL0),
  .nConfigMask  = CLOCK_CONFIG_PLL_EVEN_OUTPUT_ENABLE |
                  CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL0_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x1},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_DISPCC_DISPCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_DISPCC_DISPCCPLL0),
};

static ClockSourceNodeType ClockSource_GCC_GPLL1 =
{
  .szName       = "gpll1",
  .nFlags       = CLOCK_FLAG_INTERNAL_CONTROL |
                  CLOCK_FLAG_READ_ONLY,
  .aBSP         = ClockSourceBSP_GCC_GPLL1,
  .nBSPLen      = SIZEOF_ARRAY(ClockSourceBSP_GCC_GPLL1),
  .nConfigMask  = CLOCK_CONFIG_PLL_FSM_MODE_ENABLE,
  .eDisableMode = HAL_CLK_SOURCE_DISABLE_MODE_STANDBY,
  .HALSource = {
    .nAddr          = HWIO_ADDR(GCC_GPLL1_MODE),
    .VoterRegister  = {HWIO_ADDR(GCC_PROC_CLK_PLL_ENA_VOTE), 0x2},
  },
  .pCalibrationFreqConfig     = ClockSourceBSPCal_DISPCC_DISPCCPLL0,
  .nCalibrationFreqConfigLen  = SIZEOF_ARRAY(ClockSourceBSPCal_DISPCC_DISPCCPLL0),
};


static ClockSourceNodeType *aSources[] =
{
  &ClockSource_DISPCC_DISPCCPLL0,
  &ClockSource_DISPCC_DISPCCPLL1,
  &ClockSource_GCC_GPLL0,
  &ClockSource_GCC_GPLL1,
};


/*=========================================================================
      Dividers
==========================================================================*/

static ClockDividerNodeType aDividers[] =
{
  {
    .szName    = "disp_cc_debug_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_DEBUG_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_byte0_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_BYTE0_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_byte1_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_BYTE1_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_dp_link1_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_DP_LINK1_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_dp_link_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_DP_LINK_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_edp_link_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_EDP_LINK_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_debug_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_DEBUG_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_dp_crypto_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_CRYPTO_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_dp_pixel1_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_PIXEL1_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_dp_pixel_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_PIXEL_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_mdp_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_MDP_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_pclk0_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_PCLK0_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_pclk1_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_PCLK1_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_rot_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_MDSS_SPDM_ROT_DIV_CDIVR),
    },
  },
  {
    .szName    = "disp_cc_pll_test_div_clk_src",
    .nFlags    = 0x0,
    .HALDivider = {
      .nAddr       = HWIO_ADDR(DISP_CC_PLL_TEST_DIV_CDIVR),
    },
  },
};

/*=========================================================================
      Domain BSP
==========================================================================*/

/*
 * ClockDomainBSP_DISPCC_DISPCCMDSSAHB
 *
 * Used by:
 *   ClockDomain_DISPCC_DISPCCMDSSAHB
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC_DISPCCMDSSAHB[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   37500000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     32,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {   75000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     16,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
};

/*
 * ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0
 *
 * Used by:
 *   ClockDomain_DISPCC_DISPCCMDSSBYTE0
 *   ClockDomain_DISPCC_DISPCCMDSSBYTE1
 *   ClockDomain_DISPCC_DISPCCMDSSDPAUX1
 *   ClockDomain_DISPCC_DISPCCMDSSDPAUX
 *   ClockDomain_DISPCC_DISPCCMDSSDPLINK1
 *   ClockDomain_DISPCC_DISPCCMDSSDPLINK
 *   ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1
 *   ClockDomain_DISPCC_DISPCCMDSSDPPIXEL2
 *   ClockDomain_DISPCC_DISPCCMDSSDPPIXEL
 *   ClockDomain_DISPCC_DISPCCMDSSEDPAUX
 *   ClockDomain_DISPCC_DISPCCMDSSEDPGTC
 *   ClockDomain_DISPCC_DISPCCMDSSEDPLINK
 *   ClockDomain_DISPCC_DISPCCMDSSEDPPIXEL
 *   ClockDomain_DISPCC_DISPCCMDSSESC0
 *   ClockDomain_DISPCC_DISPCCMDSSESC1
 *   ClockDomain_DISPCC_DISPCCMDSSPCLK0
 *   ClockDomain_DISPCC_DISPCCMDSSPCLK1
 *   ClockDomain_DISPCC_DISPCCMDSSVSYNC
 *   ClockDomain_DISPCC_DISPCCXO
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
};

/*
 * ClockDomainBSP_DISPCC_DISPCCMDSSMDP
 *
 * Used by:
 *   ClockDomain_DISPCC_DISPCCMDSSMDP
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC_DISPCCMDSSMDP[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   85714286, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     14,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  100000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     12,    0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  150000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  200000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  300000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  345000000, &ClockSource_DISPCC_DISPCCPLL0,           { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
  {  460000000, &ClockSource_DISPCC_DISPCCPLL0,           { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_DISPCC_DISPCCMDSSROT
 *
 * Used by:
 *   ClockDomain_DISPCC_DISPCCMDSSROT
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC_DISPCCMDSSROT[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {  200000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  300000000, &ClockSource_DISPCC_DISPCCPLL1,           { 4,     4,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[4] = DISP_CC_PLL1_OUT_MAIN */
  {  345000000, &ClockSource_DISPCC_DISPCCPLL0,           { 1,     8,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
  {  460000000, &ClockSource_DISPCC_DISPCCPLL0,           { 1,     6,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = DISP_CC_PLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_DISPCC_DISPCCSLEEP
 *
 * Used by:
 *   ClockDomain_DISPCC_DISPCCSLEEP
 */
static ClockMuxConfigType ClockDomainBSP_DISPCC_DISPCCSLEEP[] =
{
  {      32000, NULL,                                     { 0,     2,     0,     0,     0xFF }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = CHIP_SLEEP_CLK */
};

/*
 * ClockDomainBSP_GCC_GCCCONFIGNOC
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCCONFIGNOC
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCCONFIGNOC[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   37500000, &ClockSource_GCC_GPLL0,                   { 1,     32,    0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
  {   75000000, &ClockSource_GCC_GPLL0,                   { 1,     16,    0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[1] = GPLL0_OUT_MAIN */
};

/*
 * ClockDomainBSP_GCC_GCCMMNOCHFQX
 *
 * Note: These frequencies are used by domains possibly under DFS control. The
 *       DFS-enable state will be detected during init. If under DFS control,
 *       the domain will dynamically allocate its own BSP array and populate
 *       it with configurations detected from the DFS registers.
 *
 * Used by:
 *   ClockDomain_GCC_GCCMMNOCHFQX
 */
static ClockMuxConfigType ClockDomainBSP_GCC_GCCMMNOCHFQX[] =
{
  {   19200000, NULL,                                     { 0,     2,     0,     0,     0x00 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[0] = BI_TCXO */
  {   75000000, &ClockSource_GCC_GPLL0,                   { 6,     8,     0,     0,     0x02 }, RAIL_VOLTAGE_LEVEL_MIN_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP15_CLKGEN_ACGC_CLK */
  {  150000000, &ClockSource_GCC_GPLL0,                   { 6,     4,     0,     0,     0x03 }, RAIL_VOLTAGE_LEVEL_LOW_SVS,    },                                                            /* Mux[6] = GCC_GPLL0_OUT_EVEN_PWRGRP15_CLKGEN_ACGC_CLK */
  {  240000000, &ClockSource_GCC_GPLL0,                   { 1,     5,     0,     0,     0x04 }, RAIL_VOLTAGE_LEVEL_SVS,        },                                                            /* Mux[1] = GCC_GPLL0_OUT_MAIN_PWRGRP2_CLKGEN_ACGC_CLK */
  {  266500000, &ClockSource_GCC_GPLL1,                   { 4,     8,     0,     0,     0x05 }, RAIL_VOLTAGE_LEVEL_SVS_L1,     },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
  {  355333333, &ClockSource_GCC_GPLL1,                   { 4,     6,     0,     0,     0x06 }, RAIL_VOLTAGE_LEVEL_NOM,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
  {  426400000, &ClockSource_GCC_GPLL1,                   { 4,     5,     0,     0,     0x07 }, RAIL_VOLTAGE_LEVEL_TUR,        },                                                            /* Mux[4] = GPLL1_OUT_MAIN */
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

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSAHB =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSAHB,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSAHB),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_AHB_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSBYTE0 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_BYTE0_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSBYTE1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_BYTE1_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPAUX1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_AUX1_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPAUX =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_AUX_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPCRYPTO =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_CRYPTO_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPLINK1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_LINK1_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPLINK =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_LINK_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL1_CMD_RCGR),
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPPIXEL2 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL2_CMD_RCGR),
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSDPPIXEL =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL_CMD_RCGR),
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSEDPAUX =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_EDP_AUX_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSEDPGTC =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_EDP_GTC_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSEDPLINK =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_EDP_LINK_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSEDPPIXEL =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_EDP_PIXEL_CMD_RCGR),
    .nMNDWidth  = 16,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSESC0 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_ESC0_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSESC1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_ESC1_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSMDP =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSMDP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSMDP),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_MDP_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSPCLK0 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_PCLK0_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSPCLK1 =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_PCLK1_CMD_RCGR),
    .nMNDWidth  = 8,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSROT =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSROT,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSROT),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_ROT_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCMDSSVSYNC =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_MDSS_VSYNC_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCPLLTESTMUX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = 0,
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCSLEEP =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCSLEEP,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCSLEEP),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_SLEEP_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_DISPCC_DISPCCXO =
{
  .aBSP      = ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_DISPCC_DISPCCMDSSBYTE0),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(DISP_CC_XO_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOC =
{
  .aBSP      = ClockDomainBSP_GCC_GCCCONFIGNOC,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCCONFIGNOC),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_CONFIG_NOC_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMMNOCHFQX =
{
  .aBSP      = ClockDomainBSP_GCC_GCCMMNOCHFQX,
  .nBSPLen   = SIZEOF_ARRAY(ClockDomainBSP_GCC_GCCMMNOCHFQX),
  .nFlags    = 0x0,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMNOC_HF_QX_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCMMNOCSFQX =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_MMNOC_SF_QX_CMD_RCGR),
  },
};

static ClockDomainNodeType ClockDomain_GCC_GCCXO =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = HWIO_ADDR(GCC_XO_CMD_RCGR),
  },
};


static ClockDomainNodeType *aDomains[] =
{
  &ClockDomain_DISPCC_DISPCCMDSSAHB,
  &ClockDomain_DISPCC_DISPCCMDSSBYTE0,
  &ClockDomain_DISPCC_DISPCCMDSSBYTE1,
  &ClockDomain_DISPCC_DISPCCMDSSDPAUX,
  &ClockDomain_DISPCC_DISPCCMDSSDPAUX1,
  &ClockDomain_DISPCC_DISPCCMDSSDPCRYPTO,
  &ClockDomain_DISPCC_DISPCCMDSSDPLINK,
  &ClockDomain_DISPCC_DISPCCMDSSDPLINK1,
  &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL,
  &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1,
  &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL2,
  &ClockDomain_DISPCC_DISPCCMDSSEDPAUX,
  &ClockDomain_DISPCC_DISPCCMDSSEDPGTC,
  &ClockDomain_DISPCC_DISPCCMDSSEDPLINK,
  &ClockDomain_DISPCC_DISPCCMDSSEDPPIXEL,
  &ClockDomain_DISPCC_DISPCCMDSSESC0,
  &ClockDomain_DISPCC_DISPCCMDSSESC1,
  &ClockDomain_DISPCC_DISPCCMDSSMDP,
  &ClockDomain_DISPCC_DISPCCMDSSPCLK0,
  &ClockDomain_DISPCC_DISPCCMDSSPCLK1,
  &ClockDomain_DISPCC_DISPCCMDSSROT,
  &ClockDomain_DISPCC_DISPCCMDSSVSYNC,
  &ClockDomain_DISPCC_DISPCCPLLTESTMUX,
  &ClockDomain_DISPCC_DISPCCSLEEP,
  &ClockDomain_DISPCC_DISPCCXO,
  &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
  &ClockDomain_GCC_GCCCONFIGNOC,
  &ClockDomain_GCC_GCCMMNOCHFQX,
  &ClockDomain_GCC_GCCMMNOCSFQX,
  &ClockDomain_GCC_GCCXO,
};


/*=========================================================================
      Clocks
==========================================================================*/

static ClockNodeType aClocks[] =
{
  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSAHB                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSAHB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_AHB_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_non_gdsc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSAHB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_NON_GDSC_AHB_CBCR), HWIO_ADDR(DISP_CC_MDSS_RSCC_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_rscc_ahb_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSAHB,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_RSCC_AHB_CBCR), HWIO_ADDR(DISP_CC_MDSS_RSCC_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSBYTE0                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_byte0_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSBYTE0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_BYTE0_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_byte0_intf_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSBYTE0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_BYTE0_INTF_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSBYTE1                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_byte1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSBYTE1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_BYTE1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_byte1_intf_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSBYTE1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_BYTE1_INTF_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPAUX1                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_aux1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPAUX1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_AUX1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPAUX                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_aux_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPAUX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_AUX_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPCRYPTO                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_spdm_dp_crypto_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPCRYPTO,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_CRYPTO_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPLINK1                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_link1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPLINK1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_LINK1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_dp_link1_intf_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPLINK1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_LINK1_INTF_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPLINK                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_link_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPLINK,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_LINK_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_dp_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPLINK,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_LINK_INTF_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_dp_pixel1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_PIXEL1_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPPIXEL2                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_pixel2_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL2,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL2_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSDPPIXEL                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_dp_pixel_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_DP_PIXEL_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_dp_pixel_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSDPPIXEL,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_DP_PIXEL_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSEDPAUX                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_edp_aux_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSEDPAUX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_EDP_AUX_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSEDPGTC                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_edp_gtc_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSEDPGTC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_EDP_GTC_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSEDPLINK                                  */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_edp_link_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSEDPLINK,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_EDP_LINK_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_edp_link_intf_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSEDPLINK,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_EDP_LINK_INTF_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSEDPPIXEL                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_edp_pixel_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSEDPPIXEL,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_EDP_PIXEL_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSESC0                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_esc0_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSESC0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_ESC0_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSESC1                                     */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_esc1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSESC1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_ESC1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSMDP                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSMDP,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_MDP_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_mdp_lut_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSMDP,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_MDP_LUT_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_mdp_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSMDP,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_MDP_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSPCLK0                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSPCLK0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_PCLK0_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_pclk0_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSPCLK0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_PCLK0_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSPCLK1                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSPCLK1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_PCLK1_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_pclk1_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSPCLK1,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_PCLK1_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSROT                                      */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_rot_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSROT,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_ROT_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_rot_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSROT,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_ROT_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCMDSSVSYNC                                    */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_mdss_rscc_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSVSYNC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_RSCC_VSYNC_CBCR), HWIO_ADDR(DISP_CC_MDSS_RSCC_BCR), {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_vsync_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCMDSSVSYNC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_VSYNC_CBCR), HWIO_ADDR(DISP_CC_MDSS_CORE_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCPLLTESTMUX                                   */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_pll_test_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCPLLTESTMUX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_PLL_TEST_CBCR), 0, {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCSLEEP                                        */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_sleep_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCSLEEP,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_SLEEP_CBCR), 0, {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_DISPCC_DISPCCXO                                           */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_xo_clk",
    .pDomain   = &ClockDomain_DISPCC_DISPCCXO,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_XO_CBCR), 0, {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE                                */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "disp_cc_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_DEBUG_CBCR), 0, {0, 0} },
    },
  },
  {
    .szName    = "disp_cc_mdss_spdm_debug_clk",
    .pDomain   = &ClockDomain_GCC_CLOCKDRIVERGENNOSOURCE,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(DISP_CC_MDSS_SPDM_DEBUG_CBCR), HWIO_ADDR(DISP_CC_MDSS_SPDM_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCCONFIGNOC                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_CAMERA_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_disp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_DISP_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_qmip_camera_nrt_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_QMIP_CAMERA_NRT_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_qmip_camera_rt_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_QMIP_CAMERA_RT_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_qmip_disp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_QMIP_DISP_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_qmip_video_cvp_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_QMIP_VIDEO_CVP_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_qmip_video_vcodec_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_QMIP_VIDEO_VCODEC_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_video_ahb_clk",
    .pDomain   = &ClockDomain_GCC_GCCCONFIGNOC,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_VIDEO_AHB_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMMNOCHFQX                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_hf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_CAMERA_HF_AXI_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_disp_hf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCHFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_DISP_HF_AXI_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCMMNOCSFQX                                          */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_sf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_CAMERA_SF_AXI_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_disp_sf_axi_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_DISP_SF_AXI_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_video_axi0_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_VIDEO_AXI0_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_video_axi1_clk",
    .pDomain   = &ClockDomain_GCC_GCCMMNOCSFQX,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_VIDEO_AXI1_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },

  /*-----------------------------------------------------------------------*/
  /* ClockDomain_GCC_GCCXO                                                 */
  /*-----------------------------------------------------------------------*/
  {
    .szName    = "gcc_camera_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_CAMERA_XO_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_disp_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_DISP_XO_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
  {
    .szName    = "gcc_video_xo_clk",
    .pDomain   = &ClockDomain_GCC_GCCXO,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { HWIO_ADDR(GCC_VIDEO_XO_CBCR), HWIO_ADDR(GCC_MMSS_BCR), {0, 0} },
    },
  },
};


/*=========================================================================
      Power Domains
==========================================================================*/

static ClockPowerDomainNodeType aPowerDomains[] =
{
  {
    .szName         = "mdss_core_gdsc",
    .nFlags         = 0x0,
    .HALPowerDomain = {
      .nGDSCRAddr   = HWIO_ADDR(DISP_CC_MDSS_CORE_GDSCR),
    },
  },
};


/*=========================================================================
      Main BSP
==========================================================================*/

ClockBSPType ClockBSP =
{
  .aClocks           = aClocks,
  .nNumClocks        = SIZEOF_ARRAY(aClocks),
  .aDomains          = aDomains,
  .nNumDomains       = SIZEOF_ARRAY(aDomains),
  .aSources          = aSources,
  .nNumSources       = SIZEOF_ARRAY(aSources),
  .aDividers         = aDividers,
  .nNumDividers      = SIZEOF_ARRAY(aDividers),
  .aPowerDomains     = aPowerDomains,
  .nNumPowerDomains  = SIZEOF_ARRAY(aPowerDomains),
  .nFlags            = 0x0,
  .SafeMuxConfig     = { 0, 2, 0, 0 },
};

