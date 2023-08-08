/**
  @file bamtgtcfgdata_apss.h
  @brief
  This file contains configuration data for the BAM driver for the 
  8998 APSS system.

*/
/*
===============================================================================

                             Edit History


when       who     what, where, why
--------   ---     ------------------------------------------------------------
19/6/19    ay      Updated a flag in tgtcfg options for APPS CE BAM
03/3116    ss      updated for 8998
27/8/14    rl      initial

===============================================================================
                   Copyright (c) 2013-2016, 2019 QUALCOMM Technologies Inc.
                          All Rights Reserved.
                        Qualcomm Confidential and Proprietary.
===============================================================================
*/

/** Configs supported for
    CE0
 */
#include "Include/Library/bamtgtcfg.h"
//#include "bamtgtcfg.h"

#define BAM_CNFG_BITS_VAL 0xFFFFF004

const bam_target_config_type  bam_tgt_config[] = {
    { 
                        // CE0_BAM 
     /* .bam_pa     */   0x1DC4000,
     /* .options    */   BAM_TGT_CMD_UL_CHCK,
     /* .cfg_bits   */   BAM_CNFG_BITS_VAL,     
     /* .ee         */   0,
     /* .sec_config */   NULL,
     /* .size       */   BAM_MAX_MMAP
    },
    { //dummy config
     /* .bam_pa     */   BAM_TGT_CFG_LAST,
     /* .options    */   0,
     /* .cfg_bits   */   0,
     /* .ee         */   0,
     /* .sec_config */   NULL,
     /* .size       */   0
    },
};




