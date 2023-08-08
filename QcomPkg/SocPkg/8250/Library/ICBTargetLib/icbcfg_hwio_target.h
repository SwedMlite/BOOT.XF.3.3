#ifndef __ICBCFG_HWIO_TARGET_H__
#define __ICBCFG_HWIO_TARGET_H__
/*
===========================================================================
*/
/**
  @file icbcfg_hwio_target.h
  @brief Auto-generated HWIO interface include file.

  This file contains HWIO register definitions for the following modules:
    LLCC0_LLCC_BEAC0
    LLCC1_LLCC_BEAC0
    LLCC2_LLCC_BEAC0
    LLCC3_LLCC_BEAC0

  'Include' filters applied: ADDR_TRANSLATOR_CFG[LLCC2_LLCC_BEAC0] ADDR_TRANSLATOR_CFG[LLCC1_LLCC_BEAC0] ADDR_TRANSLATOR_CFG[LLCC3_LLCC_BEAC0] ADDR_TRANSLATOR_CFG[LLCC0_LLCC_BEAC0] 

  Generation parameters: 
  { u'filename': u'icbcfg_hwio_target.h',
    u'header': u'#include "../../../Include/msmhwiobase.h"',
    u'module-filter-exclude': { },
    u'module-filter-include': { u'LLCC0_LLCC_BEAC0': [u'ADDR_TRANSLATOR_CFG'],
                                u'LLCC1_LLCC_BEAC0': [u'ADDR_TRANSLATOR_CFG'],
                                u'LLCC2_LLCC_BEAC0': [u'ADDR_TRANSLATOR_CFG'],
                                u'LLCC3_LLCC_BEAC0': [u'ADDR_TRANSLATOR_CFG']},
    u'modules': [ u'LLCC0_LLCC_BEAC0',
                  u'LLCC1_LLCC_BEAC0',
                  u'LLCC2_LLCC_BEAC0',
                  u'LLCC3_LLCC_BEAC0']}
*/
/*
  ===========================================================================

  Copyright (c) 2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies, Inc.

  ===========================================================================

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ICBTargetLib/icbcfg_hwio_target.h#3 $
  $DateTime: 2018/08/09 14:39:37 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "../../Include/msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: LLCC0_LLCC_BEAC0
 *--------------------------------------------------------------------------*/

#define LLCC0_LLCC_BEAC0_REG_BASE                                                                       (DDR_SS_BASE      + 0x00248000)
#define LLCC0_LLCC_BEAC0_REG_BASE_SIZE                                                                  0x8000
#define LLCC0_LLCC_BEAC0_REG_BASE_USED                                                                  0x6018

#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR                                        (LLCC0_LLCC_BEAC0_REG_BASE      + 0x00000080)
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK                                             0x3f1
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN          \
        in_dword_masked(HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK)
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_INM(m)      \
        in_dword_masked(HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, m)
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUT(v)      \
        out_dword(HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,v)
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,m,v,HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN)
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_BMSK                                       0x3f0
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_SHFT                                         0x4
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_BMSK                                        0x1
#define HWIO_LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_SHFT                                        0x0

/*----------------------------------------------------------------------------
 * MODULE: LLCC1_LLCC_BEAC0
 *--------------------------------------------------------------------------*/

#define LLCC1_LLCC_BEAC0_REG_BASE                                                                       (DDR_SS_BASE      + 0x002c8000)
#define LLCC1_LLCC_BEAC0_REG_BASE_SIZE                                                                  0x8000
#define LLCC1_LLCC_BEAC0_REG_BASE_USED                                                                  0x6018

#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR                                        (LLCC1_LLCC_BEAC0_REG_BASE      + 0x00000080)
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK                                             0x3f1
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN          \
        in_dword_masked(HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK)
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_INM(m)      \
        in_dword_masked(HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, m)
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUT(v)      \
        out_dword(HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,v)
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,m,v,HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN)
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_BMSK                                       0x3f0
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_SHFT                                         0x4
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_BMSK                                        0x1
#define HWIO_LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_SHFT                                        0x0

/*----------------------------------------------------------------------------
 * MODULE: LLCC2_LLCC_BEAC0
 *--------------------------------------------------------------------------*/

#define LLCC2_LLCC_BEAC0_REG_BASE                                                                       (DDR_SS_BASE      + 0x00348000)
#define LLCC2_LLCC_BEAC0_REG_BASE_SIZE                                                                  0x8000
#define LLCC2_LLCC_BEAC0_REG_BASE_USED                                                                  0x6018

#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR                                        (LLCC2_LLCC_BEAC0_REG_BASE      + 0x00000080)
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK                                             0x3f1
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN          \
        in_dword_masked(HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK)
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_INM(m)      \
        in_dword_masked(HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, m)
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUT(v)      \
        out_dword(HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,v)
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,m,v,HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN)
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_BMSK                                       0x3f0
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_SHFT                                         0x4
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_BMSK                                        0x1
#define HWIO_LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_SHFT                                        0x0

/*----------------------------------------------------------------------------
 * MODULE: LLCC3_LLCC_BEAC0
 *--------------------------------------------------------------------------*/

#define LLCC3_LLCC_BEAC0_REG_BASE                                                                       (DDR_SS_BASE      + 0x003c8000)
#define LLCC3_LLCC_BEAC0_REG_BASE_SIZE                                                                  0x8000
#define LLCC3_LLCC_BEAC0_REG_BASE_USED                                                                  0x6018

#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR                                        (LLCC3_LLCC_BEAC0_REG_BASE      + 0x00000080)
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK                                             0x3f1
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN          \
        in_dword_masked(HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_RMSK)
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_INM(m)      \
        in_dword_masked(HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR, m)
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUT(v)      \
        out_dword(HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,v)
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ADDR,m,v,HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_IN)
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_BMSK                                       0x3f0
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ERROR_SHFT                                         0x4
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_BMSK                                        0x1
#define HWIO_LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG_ENABLE_SHFT                                        0x0


#endif /* __ICBCFG_HWIO_TARGET_H__ */
