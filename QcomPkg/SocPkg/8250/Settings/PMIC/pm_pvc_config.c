/*! \file
*  \n
*  \brief  pm_pvc_config.c
*  \n
*  \n This file contains pmic configuration data specific for SPMI Controller's
      Peripheral for SDM845 device..
*  \n
*  \n &copy; Copyright 2015-2019 Qualcomm Technologies Incorporated, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/PMIC/pm_pvc_config.c#9 $

when       who    what, where, why
--------   ---    ----------------------------------------------------------
03/22/18   aab    Updated MGPI2 Negative edge data to: 0xC0
12/19/17   aab    Updated MGPI configuration for SDM855 Target 
02/01/17   aab    Supported SDM845 target.  Added SPMI,PVC, MGPI and VIOCTL configurations
08/25/15   vtw    Created.
========================================================================== */

/*-------------------------------------------------------------------------
* Include Files
* ----------------------------------------------------------------------*/

#include "SpmiCfg.h"

/*-------------------------------------------------------------------------
* Preprocessor Definitions and Constants
* ----------------------------------------------------------------------*/

/* Converts a PVC port index to an overall PMIC Arbiter port index */
#define PVC_PORT_TO_PMIC_ARB_PORT(p) (p+1)

/*   Port assignment in Kona   */
#define APPS0_PORT      0   /* APPS Port 0  */
#define APPS1_PORT      1   /* APPS Port 1  */
#define MGPI_PVC_PORT   4   /* UICC MGPI port 6  */

/*-------------------------------------------------------------------------
* Static Variable Definitions
* ----------------------------------------------------------------------*/

/*
 * pm_pvc_apps0_addr
 *
 * PVC port addr for APPS0 Gold cluster.
 */
SpmiCfg_Ppid pm_pvc_apps0_addr[] =
{
  {0x1, 0x2F40}, /* PM855, S10_CTRL_VSET_LB */
  {0x1, 0x2F41}, /* PM855, S10_CTRL_VSET_UB */
  {0x1, 0x2F45}, /* PM855, S10_CTRL_MODE_CTL */
  {0x1, 0x2F46}  /* PM855, S10_CTRL_EN_CTL */
};

const SpmiCfg_PvcPortCfg pm_pvc_apps0_cfg = {APPS0_PORT, SPMI_ACCESS_PRIORITY_LOW, pm_pvc_apps0_addr, sizeof(pm_pvc_apps0_addr)/sizeof(SpmiCfg_Ppid)};

/*
 * pm_pvc_apps1_addr
 *
 * PVC port addr for APPS1 Silver cluster block.
 */
SpmiCfg_Ppid pm_pvc_apps1_addr[] =
{
  {0x1, 0x2C40}, /* PM855, S9_CTRL_VSET_LB */
  {0x1, 0x2C41}, /* PM855, S9_CTRL_VSET_UB */
  {0x1, 0x2C45}, /* PM855, S9_CTRL_MODE_CTL */
  {0x1, 0x2C46}  /* PM855, S9_CTRL_EN_CTL */
};

const SpmiCfg_PvcPortCfg pm_pvc_apps1_cfg = {APPS1_PORT, SPMI_ACCESS_PRIORITY_LOW, pm_pvc_apps1_addr, sizeof(pm_pvc_apps1_addr)/sizeof(SpmiCfg_Ppid)};

/*
 * pm_pvc_mgpi_addr
 *
 * PVC port addr for UICC MGPI block.
 */
SpmiCfg_Ppid pm_pvc_mgpi_addr[] =
{
  {0, 0},        /* MGPI0 , UICC1, unused for Kona */
  {0x0, 0x0967}, /* MGPI1 , NFC, LNBBCLK3_PC */
  {0x0, 0x0969}, /* MGPI2 , WiGig, RFCLK_1 PC */
  {0x0, 0x096A}, /* MGPI3 , WLAN/BT(WLAN_SW_EN_CTRL), RFCLK3D enable */
  {0x5, 0x4846}, /* MGPI4 , SD card removal detection. Default disabled unless for QRD*/
  {0, 0},         /* MGPI5 , UICC0, unused for Kona */
  {0x0, 0x0},    /* MGPI6 , AOP PDC TRIGGER */
  {0x0, 0x0}     /* MGPI7 , EUD */  
};

const SpmiCfg_PvcPortCfg pm_pvc_uicc_mgpi_cfg = {MGPI_PVC_PORT, SPMI_ACCESS_PRIORITY_LOW, pm_pvc_mgpi_addr, sizeof(pm_pvc_mgpi_addr)/sizeof(SpmiCfg_Ppid)};

/*
 * pm_arb_pvc_cfg
 *
 * PMIC Arbiter PVC ports config.
 */
const SpmiCfg_PvcPortCfg* pm_arb_pvc_port_cfg[] = {&pm_pvc_apps0_cfg, &pm_pvc_apps1_cfg, &pm_pvc_uicc_mgpi_cfg};

uint32 pm_arb_pvc_port_cfg_size[] = {sizeof(pm_arb_pvc_port_cfg) / sizeof(SpmiCfg_PvcPortCfg*)};



/*
 * pm_mgpi_port_cfg
 *
 * PMIC MGPI ports config.
 */
 //UICC
const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_0_cfg = 
{
  0,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  FALSE,             /* Positive edge enable */
  0,                 /* Positive edge PVC port address index */
  0,                 /* Positive edge data */
  FALSE,              /* Negative edge enable */
  0,                 /* Negative edge PVC port address index */
  0,                 /* Negative edge data */
  FALSE,             /* MUX Sel Valid Flag*/
  0,                 /* MUX Sel Value */
};

//NFC
const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_1_cfg = 
{
  1,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  TRUE,              /* Positive edge enable */
  1,                 /* Positive edge PVC port address index */
  0x01,              /* Positive edge data */
  TRUE,              /* Negative edge enable */
  1,                 /* Negative edge PVC port address index */
  0x0,               /* Negative edge data */
  TRUE,              /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};


//Wigig
const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_2_cfg = 
{
  2,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  TRUE,              /* Positive edge enable */
  2,                 /* Positive edge PVC port address index */
  1,                 /* Positive edge data */
  TRUE,              /* Negative edge enable */
  2,                 /* Negative edge PVC port address index */
  0,                 /* Negative edge data */
  TRUE,              /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};

//Wlan/Bt sw en ctrl
const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_3_cfg = 
{
  3,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  TRUE,              /* Positive edge enable */
  3,                 /* Positive edge PVC port address index */
  0x1,               /* Positive edge data */
  TRUE,              /* Negative edge enable */
  3,                 /* Negative edge PVC port address index */
  0x0,               /* Negative edge data */
  TRUE,              /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};


//SD Card Removal
const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_4_cfg = 
{
  4,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  FALSE,              /* Positive edge enable */
  4,                 /* Positive edge PVC port address index */
  0,                 /* Positive edge data */
  TRUE,              /* Negative edge enable */
  4,                 /* Negative edge PVC port address index */
  0,                 /* Negative edge data */
  TRUE,              /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};


const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_5_cfg = 
{
  5,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  FALSE,              /* Positive edge enable */
  5,                 /* Positive edge PVC port address index */
  1,                 /* Positive edge data */
  FALSE,             /* Negative edge enable */
  5,                 /* Negative edge PVC port address index */
  0,                 /* Negative edge data */
  FALSE,             /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};

const SpmiBusCfg_MgpiPortCfg pm_mgpi_port_6_cfg = 
{
  6,                 /* MGPI Port id */
  MGPI_PVC_PORT,     /* PVC Port id */
  FALSE,             /* Positive edge enable */
  6,                 /* Positive edge PVC port address index */
  1,                 /* Positive edge data */
  FALSE,             /* Negative edge enable */
  6,                 /* Negative edge PVC port address index */
  0,                 /* Negative edge data */
  FALSE,             /* MUX Sel Valid Flag*/
  0                  /* MUX Sel Value */
};

const SpmiBusCfg_MgpiPortCfg* pm_mgpi_port_cfg[] = {&pm_mgpi_port_0_cfg, &pm_mgpi_port_1_cfg, &pm_mgpi_port_2_cfg, &pm_mgpi_port_3_cfg, &pm_mgpi_port_4_cfg, &pm_mgpi_port_5_cfg, &pm_mgpi_port_6_cfg};

uint32 pm_mgpi_port_cfg_size[] = {sizeof(pm_mgpi_port_cfg) / sizeof(SpmiBusCfg_MgpiPortCfg*)};
