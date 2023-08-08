#ifndef __MDSSPlatform_6xx_H__
#define __MDSSPlatform_6xx_H__
/*=============================================================================
 
  File: MDSSPlatform_6xx.h
 
  Internal header file for MDSS 6xx library
  
 
  Copyright (c) 2018-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include "MDPLib_i.h"

/*===========================================================================
                                Defines 
===========================================================================*/

#define RES_MAX_FAMILY_MAJOR                      7
#define RES_MAX_FAMILY_MINOR                      2

#define XO_DEFAULT_FREQ_IN_HZ                     19200000

/* Minimal MDP core clock, this is SVS (voltage level) */
#define MDP_MIN_CORE_CLOCK                        300000000

/* MDP core bandwidth IB value, it is 800MB/s */
#define MDP_CORE_BANDWIDTH_VOTE_IB                800000000

 /*=========================================================================
     MDSS 6.x.x Tables
 ==========================================================================*/


 MDPExternalClockEntry            sDSI0ExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_esc0_clk",           0, 1, 0, 0, 0, 0},     // Index 0 : primary source :XO , Secondary source : dsi pll
    {"disp_cc_mdss_pclk0_clk",          1, 0, 0, 0, 0, 0},     // Index 1 : Source DSI0_PLL
    {"disp_cc_mdss_byte0_clk",          1, 0, 0, 0, 0, 0},     // Index 2 : Source DSI0_PLL
    {"disp_cc_mdss_byte0_intf_clk",     1, 0, 2, 0, 0, 0},     // Index 3 : Source DSI0_PLL
    {"disp_cc_mdss_byte0_div_clk_src",  0, 0, 0, 0, 0, 0, 2},  // Index 4 : CDIV, divided by 2 is default for dphy
    {"\0",                              0, 0, 0, 0, 0, 0},  
  };

  MDPExternalClockEntry            sDSI1ExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_esc1_clk",           0, 1, 0, 0, 0, 0},     // Index 0 : primary source :XO , Secondary source : dsi pll
    {"disp_cc_mdss_pclk1_clk",          2, 0, 0, 0, 0, 0},     // Index 1 : Source DSI1_PLL
    {"disp_cc_mdss_byte1_clk",          2, 0, 0, 0, 0, 0},     // Index 2 : Source DSI1_PLL
    {"disp_cc_mdss_byte1_intf_clk",     2, 0, 2, 0, 0, 0},     // Index 3 : Source DSI1_PLL
    {"disp_cc_mdss_byte1_div_clk_src",  0, 0, 0, 0, 0, 0, 2},  // Index 4 : CDIV for byte_intf_clk
    {"\0",                              0, 0, 0, 0, 0, 0},  
  };

  /*For Dual DSI Split display, DSI0/DSI1 share same PLL-- DSI0_PLL */
 MDPExternalClockEntry            sDSI1SharedSourceExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_esc1_clk",           0, 1, 0, 0, 0, 0},     // Index 0 : primary source :XO , Secondary source : dsi pll
    {"disp_cc_mdss_pclk1_clk",          1, 0, 0, 0, 0, 0},     // Index 1 : Source DSI0_PLL
    {"disp_cc_mdss_byte1_clk",          1, 0, 0, 0, 0, 0},     // Index 2 : Source DSI0_PLL
    {"disp_cc_mdss_byte1_intf_clk",     1, 0, 2, 0, 0, 0},     // Index 3 : Source DSI0_PLL
    {"disp_cc_mdss_byte1_div_clk_src",  0, 0, 0, 0, 0, 0, 2},  // Index 4 : CDIV for byte_intf_clk
    {"\0",                              0, 0, 0, 0, 0, 0},  
  }; 
 
  /* MDSS Clock list
   * Note: Clocks are ordered in order to ensure Ahb access is available prior to accessing the core.
   */
  MDPClockEntry MDSSClocks_6xx[] =
  {
      {"gcc_disp_hf_axi_clk",               240000000, NULL, 0x0, 0x0},
      {"disp_cc_mdss_ahb_clk",                      0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_mdp_clk",              345000000, NULL, 0x0, 0x0},
      {"disp_cc_mdss_rot_clk",                      0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_vsync_clk",                    0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_rscc_ahb_clk",                 0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_rscc_vsync_clk",               0, NULL, 0x0, 0x0},
      {"\0",                                        0, NULL, 0x0, 0x0}
  };


  /* Core clock that need be updated dynamically */
  MDPDynamicClockEntry sMDPCoreClock_6xx=
  { 
      "disp_cc_mdss_mdp_clk",                       0, MDP_MIN_CORE_CLOCK
  };
  
  /* Record all the clocks that can be updated dynamically */
  const MDP_DynamicClockList sMDSSDynamicClock_6xx =
  {
    &sMDPCoreClock_6xx,                                  // MDP core clock
  };
  
  /* DSI0 Clock list
   */
  MDPClockEntry DSI0Clocks_6xx[] =
  {
      {"disp_cc_mdss_esc0_clk",         0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte0_clk",        0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte0_intf_clk",   0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_pclk0_clk",        0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte0_div_clk_src",0, NULL, MDP_CLOCKFLAG_CDIV, 0x0},
      {"\0",                            0, NULL, 0x0,                0x0}
  };
  
  /* DSI1 Clock list
   */
  MDPClockEntry DSI1Clocks_6xx[] =
  {
      {"disp_cc_mdss_esc1_clk",         0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte1_clk",        0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte1_intf_clk",   0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_pclk1_clk",        0, NULL, 0x0,                0x0},
      {"disp_cc_mdss_byte1_div_clk_src",0, NULL, MDP_CLOCKFLAG_CDIV, 0x0},
      {"\0",                            0, NULL, 0x0,                0x0}
  };
  
  /* DP 0 Clock list
   */
  MDPClockEntry DP0Clocks_6xx[] =
  {
      {"disp_cc_mdss_dp_pixel_clk",     0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_link_clk",      0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_crypto_clk",    0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_aux_clk",       0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_link_intf_clk", 0, NULL, 0x0, 0x0},
      {"\0",                            0, NULL, 0x0, 0x0}
  };

  /* DP 1 Clock list
   */
  MDPClockEntry DP1Clocks_6xx[] =
  {
      {"disp_cc_mdss_dp_pixel1_clk",     0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_link1_clk",      0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_crypto1_clk",    0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_aux1_clk",       0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_dp_link1_intf_clk", 0, NULL, 0x0, 0x0},
      {"\0",                             0, NULL, 0x0, 0x0}
  };
  
  /* eDP Clock list
   */
  MDPClockEntry EDPClocks_6xx[] =
  {
      {"disp_cc_mdss_edp_aux_clk",       0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_edp_pixel_clk",     0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_edp_link_clk",      0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_edp_link_intf_clk", 0, NULL, 0x0, 0x0},
      {"disp_cc_mdss_edp_gtc_clk",       0, NULL, 0x0, 0x0},
      {"\0",                             0, NULL, 0x0, 0x0}
  };

  /*
   * DP0 controller is hard mapped to Standalone DP Phy
   * PLL sources are dptx2_phy_pll_link_clk (index:5) &
   * dptx2_phy_pll_vco_div_clk (index:6)
   * #TODO#IMPLEMENT run-time mapping
   */
  MDPExternalClockEntry            sDP0ExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_dp_pixel_clk",     6, 0, 0, 0, 0, 0},    // Index 0: Pixel clock
    {"disp_cc_mdss_dp_link_clk",      5, 0, 0, 0, 0, 0},    // Index 1: Link clock
    {"disp_cc_mdss_dp_crypto_clk",    5, 0, 0, 0, 0, 0},    // Index 2: Crypto clock
    {"disp_cc_mdss_dp_aux_clk",       0, 0, 0, 0, 0, 0},    // Index 3: Aux clock
    {"disp_cc_mdss_dp_link_intf_clk", 5, 0, 0, 0, 0, 0},    // Index 4: Link intf clock
    {"\0",                            0, 0, 0, 0, 0, 0}
  };

  /*
   * DP1 controller is hard mapped to Type-C USB 0 PHY
   * PLL sources are dp_phy_pll_link_clk (index:1) &
   * dp_phy_pll_vco_div_clk (index:2)
   * #TODO#IMPLEMENT run-time mapping
   */
  MDPExternalClockEntry            sDP1ExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_dp_pixel1_clk",     2, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_dp_link1_clk",      1, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_dp_crypto1_clk",    1, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_dp_aux1_clk",       0, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_dp_link1_intf_clk", 1, 0, 0, 0, 0, 0},
    {"\0",                             0, 0, 0, 0, 0, 0}
  };

  MDPExternalClockEntry            sEDPExtClocks_6xx[] = 
  {
    {"disp_cc_mdss_edp_pixel_clk",     2, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_edp_link_clk",      1, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_edp_gtc_clk",       0, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_edp_aux_clk",       0, 0, 0, 0, 0, 0},
    {"disp_cc_mdss_edp_link_intf_clk", 1, 0, 0, 0, 0, 0},
    {"\0",                             0, 0, 0, 0, 0, 0}
  };

  /* Disp CC XO clock
  */
  MDPClockEntry DispCcXoClk_6xx[] =
  {
      {"gcc_disp_ahb_clk",      0, NULL, MDP_CLOCKFLAG_SHARED, 0x0},
      {"disp_cc_xo_clk",        0, NULL, MDP_CLOCKFLAG_SHARED, 0x0},
      {"\0",                    0, NULL, 0x0                 , 0x0}
  };
  
  /* MDSS power domain list
   */
  const MDPPowerDomainEntry MDSS6xxPowerDomain[] = 
  {
      {"mdss_core_gdsc",        0x0},
      {"\0",                    0x0}
  };
  
  /* MDSS resource list for MDSS 6.0.0
  */
  const MDP_ResourceList sMDP60xResources =
  {
      (MDPPowerDomainEntry*)  &MDSS6xxPowerDomain,                   /* Power domain    */
      (MDPClockEntry*)        &DispCcXoClk_6xx,                      /* DISP_CC clocks  */
      (MDPClockEntry*)        &MDSSClocks_6xx,                       /* MDP clocks      */
      (MDPClockEntry*)        &DSI0Clocks_6xx,                       /* DSI0 clocks     */
      (MDPClockEntry*)        &DSI1Clocks_6xx,                       /* DSI1 clocks     */
      (MDPClockEntry*)        &DP0Clocks_6xx,                        /* DP0 clocks      */
       NULL,                                                         /* DP1 clocks      */
       NULL,                                                         /* EDP clocks      */
      (MDP_DynamicClockList*) &sMDSSDynamicClock_6xx                 /* Clocks that can be changed dynamically */
  };
  
  /* MDP External resource list for MDSS 60x
  */
  const MDP_ExtClockResourceList sMDP60xExtClockResources =
  {
      (MDPExternalClockEntry*)    &sDSI0ExtClocks_6xx,               /* DSI0 Ext clocks      */
      (MDPExternalClockEntry*)    &sDSI1ExtClocks_6xx,               /* DSI1 Ext clocks      */
      (MDPExternalClockEntry*)    &sDSI1SharedSourceExtClocks_6xx,   /* DSI shared clocks for dual DSI */
      (MDPExternalClockEntry*)    &sDSI0ExtClocks_6xx,               /* DSI0 Ext clocks      */
  };

 /* Display resource list - MDSS 6.0.0
 */
 const DisplayResourceList sDisplayMDP60xResources =
 {
    (MDP_ResourceList*)            &sMDP60xResources,                /* MDP Resources               */
    (MDP_ExtClockResourceList*)    &sMDP60xExtClockResources,        /* MDP Ext Resources           */
 };


 /*=========================================================================
       Top level Tables
 ==========================================================================*/

/* Reesource list for MDSS 6xx
*/
const MDP_HwMinorFamilyResourceList asHarwareFamilyMinor6xx[RES_MAX_FAMILY_MINOR] = {
    {MDSS_DEVICE_VERSION_06_00, (DisplayResourceList*)&sDisplayMDP60xResources},     /* MDSS Family 6.0.x, Kona */
};



/* MDP resource list  based on MDP major version.
*/
const MDP_HwMajorFamilyResourceList asHarwareFamilyMajor[RES_MAX_FAMILY_MAJOR] = {
    {NULL},                                                           /* MDSS Family 0xx   */
    {NULL},                                                           /* MDSS Fmaily 1xx (Badger Family)       */
    {NULL},                                                           /* MDSS Family 2xx   */ 
    {NULL},                                                           /* MDSS Family 3xx   */ 
    {NULL},                                                           /* MDSS Fmaily 4xx (Napali Family)  */
    {NULL},                                                           /* MDSS Fmaily 5xx (Hana/Poipu Family)  */
    {(MDP_HwMinorFamilyResourceList*)&asHarwareFamilyMinor6xx},       /* MDSS Fmaily 6xx (Kona Family)  */
}; 


#endif // __MDSSPlatform_6xx_H__

