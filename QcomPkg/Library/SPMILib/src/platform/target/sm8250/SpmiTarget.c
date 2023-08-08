/**
 * @file:  SpmiTarget.c
 * 
 * Copyright (c) 2013-2019 by Qualcomm Technologies Incorporated. All Rights Reserved.
 * 
 * $DateTime: 2019/08/24 00:40:51 $
 * $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/SPMILib/src/platform/target/sm8250/SpmiTarget.c#2 $
 * $Change: 20310296 $ 
 * $Author: pwbldsvc $
 *                              Edit History
 * Date     Description
 * -------  ------------------------------------------------------------------- 
 * * 06/24/19  Initial Version
 */
#include "SpmiHal.h"
#include "ChipInfo.h"
#include "SpmiTarget.h"



//******************************************************************************
// Macros / Definitions / Constants
//******************************************************************************

#define WDT_CFG_VAL  0x01
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR      0x0F1B8000
#define HWIO_TLMM_PMIC_HDRV_PULL_CTL_DATA      0x00FF0800

/**
 * Static Function Declarations and Definitions
 */


//******************************************************************************
// Global Data
//******************************************************************************




//******************************************************************************
// Implemented API Functions
//******************************************************************************



void SpmiTarget_PreInit(SpmiDevInfo *pDev)
{
    uint8 * base_addr = pDev->baseAddrs;

    if (ChipInfo_GetChipVersion() >= CHIPINFO_VERSION(2, 0))
    {
        SPMI_HWIO_OUT_MASK( HWIO_SPMI_CFG_REG_ADDR( base_addr ), HWIO_SPMI_CFG_REG_WDT_CFG_BMSK, WDT_CFG_VAL << HWIO_SPMI_CFG_REG_WDT_CFG_SHFT);
        /* Set TLMM HDRV PULL CTL Setting */
        SPMI_HWIO_OUT(HWIO_TLMM_PMIC_HDRV_PULL_CTL_ADDR, HWIO_TLMM_PMIC_HDRV_PULL_CTL_DATA);
    }
      
    
    return;
}

