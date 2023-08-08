#ifndef __HWIO_H__
#define __HWIO_H__
/*
===========================================================================
*/
/**
  @file hwio.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) v2 [kona_v2.0_p3q1r6.8_F00_partitioned_rtl]
 
  This file contains HWIO register definitions for the following modules:
    IPA_0_GSI_TOP_GSI

  'Exclude' filters applied: DUMMY RESERVED 

  Generation parameters: 
  { u'exclude-reserved': True,
    u'filename': 'hwio.h',
    u'module-filter-exclude': { },
    u'module-filter-include': { },
    u'modules': [u'IPA_0_GSI_TOP_GSI']}
*/
/*
  ===========================================================================

  Copyright (c) 2019 Qualcomm Technologies, Inc.
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/IpaTargetLib/inc/ipa_hwio.h#1 $
  $DateTime: 2019/02/27 18:17:29 $
  $Author: pwbldsvc $

  ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: IPA_0_GSI_TOP_GSI
 *--------------------------------------------------------------------------*/

#define IPA_0_GSI_TOP_GSI_REG_BASE                                                               (IPA_0_IPA_WRAPPER_BASE      + 0x00004000)
#define IPA_0_GSI_TOP_GSI_REG_BASE_SIZE                                                          0x23000
#define IPA_0_GSI_TOP_GSI_REG_BASE_USED                                                          0x22ffc

#define HWIO_IPA_0_GSI_TOP_GSI_CFG_ADDR                                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000000)
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_RMSK                                                               0xf3f
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_CFG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_CFG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_CFG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_CFG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_CFG_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_SLEEP_CLK_DIV_BMSK                                                 0xf00
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_SLEEP_CLK_DIV_SHFT                                                   0x8
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_BP_MTRIX_DISABLE_BMSK                                               0x20
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_BP_MTRIX_DISABLE_SHFT                                                0x5
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_GSI_PWR_CLPS_BMSK                                                   0x10
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_GSI_PWR_CLPS_SHFT                                                    0x4
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_UC_IS_MCS_BMSK                                                       0x8
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_UC_IS_MCS_SHFT                                                       0x3
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_DOUBLE_MCS_CLK_FREQ_BMSK                                             0x4
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_DOUBLE_MCS_CLK_FREQ_SHFT                                             0x2
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_MCS_ENABLE_BMSK                                                      0x2
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_MCS_ENABLE_SHFT                                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_GSI_ENABLE_BMSK                                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_CFG_GSI_ENABLE_SHFT                                                      0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000008)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_VER_BMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_MCS_CODE_VER_VER_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_ADDR                                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000010)
#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_RMSK                                                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_ZEROS_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ZEROS_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_ZEROS_BMSK                                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ZEROS_ZEROS_SHFT                                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000018)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_BASE_ADDR_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_LSB_BASE_ADDR_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000001c)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_BASE_ADDR_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_BASE_ADDR_MSB_BASE_ADDR_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000020)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_RMSK                                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_CHID_BIT_MAP_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_PERIPH_PENDING_CHID_BIT_MAP_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_ADDR                                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000030)
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_RMSK                                                       0xffffff
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_OOWR_BMSK                                           0xff0000
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_OOWR_SHFT                                               0x10
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_OORD_BMSK                                             0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_OORD_SHFT                                                0x8
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_REQ_PRIO_BMSK                                           0xff
#define HWIO_IPA_0_GSI_TOP_GSI_MOQA_CFG_CLIENT_REQ_PRIO_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_ADDR                                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000038)
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_RMSK                                                          0xff03
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_MAX_BURST_SIZE_BMSK                                           0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_MAX_BURST_SIZE_SHFT                                              0x8
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_CHANNEL_EMPTY_INT_ENABLE_BMSK                                    0x2
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_CHANNEL_EMPTY_INT_ENABLE_SHFT                                    0x1
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_MOVE_TO_ESC_CLR_MODE_TRSH_BMSK                                   0x1
#define HWIO_IPA_0_GSI_TOP_GSI_REE_CFG_MOVE_TO_ESC_CLR_MODE_TRSH_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_ADDR                                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000060)
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_RMSK                                                         0x1fff
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_13_HW_CGC_EN_BMSK                                     0x1000
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_13_HW_CGC_EN_SHFT                                        0xc
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_12_HW_CGC_EN_BMSK                                      0x800
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_12_HW_CGC_EN_SHFT                                        0xb
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_11_HW_CGC_EN_BMSK                                      0x400
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_11_HW_CGC_EN_SHFT                                        0xa
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_10_HW_CGC_EN_BMSK                                      0x200
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_10_HW_CGC_EN_SHFT                                        0x9
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_9_HW_CGC_EN_BMSK                                       0x100
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_9_HW_CGC_EN_SHFT                                         0x8
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_8_HW_CGC_EN_BMSK                                        0x80
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_8_HW_CGC_EN_SHFT                                         0x7
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_7_HW_CGC_EN_BMSK                                        0x40
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_7_HW_CGC_EN_SHFT                                         0x6
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_6_HW_CGC_EN_BMSK                                        0x20
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_6_HW_CGC_EN_SHFT                                         0x5
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_5_HW_CGC_EN_BMSK                                        0x10
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_5_HW_CGC_EN_SHFT                                         0x4
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_4_HW_CGC_EN_BMSK                                         0x8
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_4_HW_CGC_EN_SHFT                                         0x3
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_3_HW_CGC_EN_BMSK                                         0x4
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_3_HW_CGC_EN_SHFT                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_2_HW_CGC_EN_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_2_HW_CGC_EN_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_1_HW_CGC_EN_BMSK                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_CGC_CTRL_REGION_1_HW_CGC_EN_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ADDR                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000080)
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_RMSK                                                      0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_AREQPRIORITY_BMSK                                         0x30
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_AREQPRIORITY_SHFT                                          0x4
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ATRANSIENT_BMSK                                            0x8
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ATRANSIENT_SHFT                                            0x3
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ANOALLOCATE_BMSK                                           0x4
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ANOALLOCATE_SHFT                                           0x2
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_AINNERSHARED_BMSK                                          0x2
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_AINNERSHARED_SHFT                                          0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ASHARED_BMSK                                               0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MSI_CACHEATTR_ASHARED_SHFT                                               0x0

#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000084)
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_RMSK                                                    0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_AREQPRIORITY_BMSK                                       0x30
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_AREQPRIORITY_SHFT                                        0x4
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ATRANSIENT_BMSK                                          0x8
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ATRANSIENT_SHFT                                          0x3
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ANOALLOCATE_BMSK                                         0x4
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ANOALLOCATE_SHFT                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_AINNERSHARED_BMSK                                        0x2
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_AINNERSHARED_SHFT                                        0x1
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ASHARED_BMSK                                             0x1
#define HWIO_IPA_0_GSI_TOP_GSI_EVENT_CACHEATTR_ASHARED_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000088)
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_RMSK                                                     0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_AREQPRIORITY_BMSK                                        0x30
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_AREQPRIORITY_SHFT                                         0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ATRANSIENT_BMSK                                           0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ATRANSIENT_SHFT                                           0x3
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ANOALLOCATE_BMSK                                          0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ANOALLOCATE_SHFT                                          0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_AINNERSHARED_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_AINNERSHARED_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ASHARED_BMSK                                              0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DATA_CACHEATTR_ASHARED_SHFT                                              0x0

#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ADDR                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000090)
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_RMSK                                                      0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_AREQPRIORITY_BMSK                                         0x30
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_AREQPRIORITY_SHFT                                          0x4
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ATRANSIENT_BMSK                                            0x8
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ATRANSIENT_SHFT                                            0x3
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ANOALLOCATE_BMSK                                           0x4
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ANOALLOCATE_SHFT                                           0x2
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_AINNERSHARED_BMSK                                          0x2
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_AINNERSHARED_SHFT                                          0x1
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ASHARED_BMSK                                               0x1
#define HWIO_IPA_0_GSI_TOP_GSI_TRE_CACHEATTR_ASHARED_SHFT                                               0x0

#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000a0)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_RMSK                                      0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_TLV_INT_BMSK                              0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_TLV_INT_SHFT                                    0x18
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_CSR_INT_BMSK                                0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_CSR_INT_SHFT                                    0x12
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_INT_END_INT_BMSK                              0x1000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_INT_END_INT_SHFT                                 0xc
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_EV_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_EV_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_REE_INT_BMSK                                     0x7
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_LSB_REE_INT_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000a4)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_RMSK                                       0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_SDMA_INT_BMSK                              0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_SDMA_INT_SHFT                                   0x18
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                        0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                            0x12
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_RD_WR_INT_BMSK                                0x3000
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_RD_WR_INT_SHFT                                   0xc
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_DB_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_DB_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_TIMER_INT_BMSK                                   0x1
#define HWIO_IPA_0_GSI_TOP_IC_DISABLE_CHNL_BCK_PRS_MSB_TIMER_INT_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000a8)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_RMSK                                          0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_TLV_INT_BMSK                                  0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_TLV_INT_SHFT                                        0x18
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_CSR_INT_BMSK                                    0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_CSR_INT_SHFT                                        0x12
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_INT_END_INT_BMSK                                  0x1000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_INT_END_INT_SHFT                                     0xc
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_EV_ENG_INT_BMSK                                     0x40
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_EV_ENG_INT_SHFT                                      0x6
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_REE_INT_BMSK                                         0x7
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_LSB_REE_INT_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000ac)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_RMSK                                           0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_SDMA_INT_BMSK                                  0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_SDMA_INT_SHFT                                       0x18
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                            0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                                0x12
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_RD_WR_INT_BMSK                                    0x3000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_RD_WR_INT_SHFT                                       0xc
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_DB_ENG_INT_BMSK                                     0x40
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_DB_ENG_INT_SHFT                                      0x6
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_TIMER_INT_BMSK                                       0x1
#define HWIO_IPA_0_GSI_TOP_IC_GEN_EVNT_BCK_PRS_MSB_TIMER_INT_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_ADDR                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000b0)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_RMSK                                           0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_TLV_INT_BMSK                                   0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_TLV_INT_SHFT                                         0x18
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_CSR_INT_BMSK                                     0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_CSR_INT_SHFT                                         0x12
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_INT_END_INT_BMSK                                   0x1000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_INT_END_INT_SHFT                                      0xc
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_EV_ENG_INT_BMSK                                      0x40
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_EV_ENG_INT_SHFT                                       0x6
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_REE_INT_BMSK                                          0x7
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_LSB_REE_INT_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_ADDR                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000b4)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_RMSK                                            0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_SDMA_INT_BMSK                                   0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_SDMA_INT_SHFT                                        0x18
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                             0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                                 0x12
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_RD_WR_INT_BMSK                                     0x3000
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_RD_WR_INT_SHFT                                        0xc
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_DB_ENG_INT_BMSK                                      0x40
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_DB_ENG_INT_SHFT                                       0x6
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_TIMER_INT_BMSK                                        0x1
#define HWIO_IPA_0_GSI_TOP_IC_GEN_INT_BCK_PRS_MSB_TIMER_INT_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000b8)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_RMSK                                      0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_TLV_INT_BMSK                              0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_TLV_INT_SHFT                                    0x18
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_CSR_INT_BMSK                                0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_CSR_INT_SHFT                                    0x12
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_INT_END_INT_BMSK                              0x1000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_INT_END_INT_SHFT                                 0xc
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_EV_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_EV_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_REE_INT_BMSK                                     0x7
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_LSB_REE_INT_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000bc)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_RMSK                                       0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_SDMA_INT_BMSK                              0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_SDMA_INT_SHFT                                   0x18
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                        0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                            0x12
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_RD_WR_INT_BMSK                                0x3000
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_RD_WR_INT_SHFT                                   0xc
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_DB_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_DB_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_TIMER_INT_BMSK                                   0x1
#define HWIO_IPA_0_GSI_TOP_IC_STOP_INT_MOD_BCK_PRS_MSB_TIMER_INT_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000c0)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_RMSK                                      0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_TLV_INT_BMSK                              0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_TLV_INT_SHFT                                    0x18
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_CSR_INT_BMSK                                0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_CSR_INT_SHFT                                    0x12
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_INT_END_INT_BMSK                              0x1000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_INT_END_INT_SHFT                                 0xc
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_EV_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_EV_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_REE_INT_BMSK                                     0x7
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_LSB_REE_INT_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000c4)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_RMSK                                       0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_SDMA_INT_BMSK                              0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_SDMA_INT_SHFT                                   0x18
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                        0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                            0x12
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_RD_WR_INT_BMSK                                0x3000
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_RD_WR_INT_SHFT                                   0xc
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_DB_ENG_INT_BMSK                                 0x40
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_DB_ENG_INT_SHFT                                  0x6
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_TIMER_INT_BMSK                                   0x1
#define HWIO_IPA_0_GSI_TOP_IC_PROCESS_DESC_BCK_PRS_MSB_TIMER_INT_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000c8)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_RMSK                                          0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_TLV_INT_BMSK                                  0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_TLV_INT_SHFT                                        0x18
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_CSR_INT_BMSK                                    0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_CSR_INT_SHFT                                        0x12
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_INT_END_INT_BMSK                                  0x1000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_INT_END_INT_SHFT                                     0xc
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_EV_ENG_INT_BMSK                                     0x40
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_EV_ENG_INT_SHFT                                      0x6
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_REE_INT_BMSK                                         0x7
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_LSB_REE_INT_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000cc)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_RMSK                                           0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_SDMA_INT_BMSK                                  0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_SDMA_INT_SHFT                                       0x18
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                            0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                                0x12
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_RD_WR_INT_BMSK                                    0x3000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_RD_WR_INT_SHFT                                       0xc
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_DB_ENG_INT_BMSK                                     0x40
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_DB_ENG_INT_SHFT                                      0x6
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_TIMER_INT_BMSK                                       0x1
#define HWIO_IPA_0_GSI_TOP_IC_TLV_STOP_BCK_PRS_MSB_TIMER_INT_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000d0)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_RMSK                                         0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_TLV_INT_BMSK                                 0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_TLV_INT_SHFT                                       0x18
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_CSR_INT_BMSK                                   0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_CSR_INT_SHFT                                       0x12
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_INT_END_INT_BMSK                                 0x1000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_INT_END_INT_SHFT                                    0xc
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_EV_ENG_INT_BMSK                                    0x40
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_EV_ENG_INT_SHFT                                     0x6
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_REE_INT_BMSK                                        0x7
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_LSB_REE_INT_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000d4)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_RMSK                                          0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_SDMA_INT_BMSK                                 0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_SDMA_INT_SHFT                                      0x18
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                           0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                               0x12
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_RD_WR_INT_BMSK                                   0x3000
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_RD_WR_INT_SHFT                                      0xc
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_DB_ENG_INT_BMSK                                    0x40
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_DB_ENG_INT_SHFT                                     0x6
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_TIMER_INT_BMSK                                      0x1
#define HWIO_IPA_0_GSI_TOP_IC_TLV_RESET_BCK_PRS_MSB_TIMER_INT_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_ADDR                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000d8)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_RMSK                                       0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_TLV_INT_BMSK                               0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_TLV_INT_SHFT                                     0x18
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_CSR_INT_BMSK                                 0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_CSR_INT_SHFT                                     0x12
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_INT_END_INT_BMSK                               0x1000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_INT_END_INT_SHFT                                  0xc
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_EV_ENG_INT_BMSK                                  0x40
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_EV_ENG_INT_SHFT                                   0x6
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_REE_INT_BMSK                                      0x7
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_LSB_REE_INT_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_ADDR                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000dc)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_RMSK                                        0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_SDMA_INT_BMSK                               0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_SDMA_INT_SHFT                                    0x18
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                         0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                             0x12
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_RD_WR_INT_BMSK                                 0x3000
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_RD_WR_INT_SHFT                                    0xc
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_DB_ENG_INT_BMSK                                  0x40
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_DB_ENG_INT_SHFT                                   0x6
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_TIMER_INT_BMSK                                    0x1
#define HWIO_IPA_0_GSI_TOP_IC_RGSTR_TIMER_BCK_PRS_MSB_TIMER_INT_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000e0)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_RMSK                                              0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_TLV_INT_BMSK                                      0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_TLV_INT_SHFT                                            0x18
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_CSR_INT_BMSK                                        0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_CSR_INT_SHFT                                            0x12
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_INT_END_INT_BMSK                                      0x1000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_INT_END_INT_SHFT                                         0xc
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_EV_ENG_INT_BMSK                                         0x40
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_EV_ENG_INT_SHFT                                          0x6
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_REE_INT_BMSK                                             0x7
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_LSB_REE_INT_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000e4)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_RMSK                                               0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_SDMA_INT_BMSK                                      0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_SDMA_INT_SHFT                                           0x18
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                                0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                                    0x12
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_RD_WR_INT_BMSK                                        0x3000
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_RD_WR_INT_SHFT                                           0xc
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_DB_ENG_INT_BMSK                                         0x40
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_DB_ENG_INT_SHFT                                          0x6
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_TIMER_INT_BMSK                                           0x1
#define HWIO_IPA_0_GSI_TOP_IC_READ_BCK_PRS_MSB_TIMER_INT_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_ADDR                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000e8)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_RMSK                                             0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_TLV_INT_BMSK                                     0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_TLV_INT_SHFT                                           0x18
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_CSR_INT_BMSK                                       0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_CSR_INT_SHFT                                           0x12
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_INT_END_INT_BMSK                                     0x1000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_INT_END_INT_SHFT                                        0xc
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_EV_ENG_INT_BMSK                                        0x40
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_EV_ENG_INT_SHFT                                         0x6
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_REE_INT_BMSK                                            0x7
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_LSB_REE_INT_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_ADDR                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000ec)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_RMSK                                              0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_SDMA_INT_BMSK                                     0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_SDMA_INT_SHFT                                          0x18
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                               0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                                   0x12
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_RD_WR_INT_BMSK                                       0x3000
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_RD_WR_INT_SHFT                                          0xc
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_DB_ENG_INT_BMSK                                        0x40
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_DB_ENG_INT_SHFT                                         0x6
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_TIMER_INT_BMSK                                          0x1
#define HWIO_IPA_0_GSI_TOP_IC_WRITE_BCK_PRS_MSB_TIMER_INT_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_ADDR                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000f0)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_RMSK                                   0x3ffc1047
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_TLV_INT_BMSK                           0x3f000000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_TLV_INT_SHFT                                 0x18
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_CSR_INT_BMSK                             0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_CSR_INT_SHFT                                 0x12
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_INT_END_INT_BMSK                           0x1000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_INT_END_INT_SHFT                              0xc
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_EV_ENG_INT_BMSK                              0x40
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_EV_ENG_INT_SHFT                               0x6
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_REE_INT_BMSK                                  0x7
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_LSB_REE_INT_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_ADDR                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000000f4)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_RMSK                                    0xffc3041
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_IN)
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_SDMA_INT_BMSK                           0xf000000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_SDMA_INT_SHFT                                0x18
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_UCONTROLLER_INT_BMSK                     0xfc0000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_UCONTROLLER_INT_SHFT                         0x12
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_RD_WR_INT_BMSK                             0x3000
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_RD_WR_INT_SHFT                                0xc
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_DB_ENG_INT_BMSK                              0x40
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_DB_ENG_INT_SHFT                               0x6
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_TIMER_INT_BMSK                                0x1
#define HWIO_IPA_0_GSI_TOP_IC_UCONTROLLER_GPR_BCK_PRS_MSB_TIMER_INT_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_ADDR                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000100)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_RMSK                                                     0xfff
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_CH_EMPTY_INT_WEIGHT_BMSK                                 0xf00
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_CH_EMPTY_INT_WEIGHT_SHFT                                   0x8
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_NEW_RE_INT_WEIGHT_BMSK                                    0xf0
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_NEW_RE_INT_WEIGHT_SHFT                                     0x4
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_STOP_CH_COMP_INT_WEIGHT_BMSK                               0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_REE_STOP_CH_COMP_INT_WEIGHT_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000104)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_RMSK                                                   0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_EVNT_ENG_INT_WEIGHT_BMSK                               0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_EVT_ENG_EVNT_ENG_INT_WEIGHT_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000108)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_RMSK                                                   0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_INT_ENG_INT_WEIGHT_BMSK                                0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_INT_ENG_INT_ENG_INT_WEIGHT_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_ADDR                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000010c)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_RMSK                                                      0xff
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_EE_GENERIC_INT_WEIGHT_BMSK                                0xf0
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_EE_GENERIC_INT_WEIGHT_SHFT                                 0x4
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_CH_CMD_INT_WEIGHT_BMSK                                     0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_CSR_CH_CMD_INT_WEIGHT_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000110)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_RMSK                                                0xffff
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_CH_NOT_FULL_INT_WEIGHT_BMSK                         0xf000
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_CH_NOT_FULL_INT_WEIGHT_SHFT                            0xc
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_2_INT_WEIGHT_BMSK                                0xf00
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_2_INT_WEIGHT_SHFT                                  0x8
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_1_INT_WEIGHT_BMSK                                 0xf0
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_1_INT_WEIGHT_SHFT                                  0x4
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_0_INT_WEIGHT_BMSK                                  0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TLV_ENG_TLV_0_INT_WEIGHT_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000114)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_RMSK                                                 0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_TIMER_INT_WEIGHT_BMSK                                0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_TIMER_ENG_TIMER_INT_WEIGHT_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_ADDR                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000118)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_RMSK                                                    0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_NEW_DB_INT_WEIGHT_BMSK                                  0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_DB_ENG_NEW_DB_INT_WEIGHT_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000011c)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_RMSK                                                0xff
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_WRITE_INT_WEIGHT_BMSK                               0xf0
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_WRITE_INT_WEIGHT_SHFT                                0x4
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_READ_INT_WEIGHT_BMSK                                 0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_RD_WR_ENG_READ_INT_WEIGHT_SHFT                                 0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR                                    (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000120)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_RMSK                                           0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_UCONTROLLER_GP_INT_WEIGHT_BMSK                 0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_UCONTROLLER_ENG_UCONTROLLER_GP_INT_WEIGHT_SHFT                 0x0

#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000124)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_RMSK                                                   0xffff
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_ADDR)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_ADDR,m,v,HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_IN)
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_3_WEIGHT_BMSK                                 0xf000
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_3_WEIGHT_SHFT                                    0xc
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_2_WEIGHT_BMSK                                  0xf00
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_2_WEIGHT_SHFT                                    0x8
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_1_WEIGHT_BMSK                                   0xf0
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_1_WEIGHT_SHFT                                    0x4
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_0_WEIGHT_BMSK                                    0xf
#define HWIO_IPA_0_GSI_TOP_IC_INT_WEIGHT_SDMA_SDMA_INT_0_WEIGHT_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_ADDR                                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000003c)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_RMSK                                                       0xffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_BURST_READ_BMSK                                        0xff0000
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_BURST_READ_SHFT                                            0x10
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_BURST_WRITE_BMSK                                         0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_BURST_WRITE_SHFT                                            0x8
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_OS_READ_BMSK                                               0xf0
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_OS_READ_SHFT                                                0x4
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_OS_WRITE_BMSK                                               0xf
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CFG_MAX_OS_WRITE_SHFT                                               0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000094)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_RMSK                                                     0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_AREQPRIORITY_BMSK                                        0x30
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_AREQPRIORITY_SHFT                                         0x4
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ATRANSIENT_BMSK                                           0x8
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ATRANSIENT_SHFT                                           0x3
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ANOALLOCATE_BMSK                                          0x4
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ANOALLOCATE_SHFT                                          0x2
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_AINNERSHARED_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_AINNERSHARED_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ASHARED_BMSK                                              0x1
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_CACHEATTR_ASHARED_SHFT                                              0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000140 + 0x8 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_MAXn                                                   3
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_SDMA_SG_IOVEC_LSB_BMSK                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_LSB_n_SDMA_SG_IOVEC_LSB_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000144 + 0x8 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_MAXn                                                   3
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_SDMA_SG_IOVEC_MSB_BMSK                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SDMA_SG_IOVEC_MSB_n_SDMA_SG_IOVEC_MSB_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_ADDR(n)                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000300 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_RMSK                                               0x1f1f03
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_MAX_EV_ALLOC_BMSK                                  0x1f0000
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_MAX_EV_ALLOC_SHFT                                      0x10
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_MAX_CH_ALLOC_BMSK                                    0x1f00
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_MAX_CH_ALLOC_SHFT                                       0x8
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_EE_PRIO_BMSK                                            0x3
#define HWIO_IPA_0_GSI_TOP_GSI_MANAGER_EE_QOS_n_EE_PRIO_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000200)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_RMSK                                     0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_SHRAM_PTR_BMSK                           0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_SHRAM_PTR_SHFT                              0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000204)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_RMSK                                     0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_SHRAM_PTR_BMSK                           0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_SHRAM_PTR_SHFT                              0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000208)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_RMSK                                   0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_SHRAM_PTR_BMSK                         0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_SHRAM_PTR_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000020c)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_RMSK                                   0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_SHRAM_PTR_BMSK                         0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_SHRAM_PTR_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000240)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_RMSK                                    0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_SHRAM_PTR_BMSK                          0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_SHRAM_PTR_SHFT                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000244)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_RMSK                                   0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_SHRAM_PTR_BMSK                         0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_SHRAM_PTR_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000248)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_RMSK                                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_SHRAM_PTR_BMSK                        0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_SHRAM_PTR_SHFT                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000024c)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_RMSK                                 0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_SHRAM_PTR_BMSK                       0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_SHRAM_PTR_SHFT                          0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000250)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_RMSK                                 0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_SHRAM_PTR_BMSK                       0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_SHRAM_PTR_SHFT                          0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000254)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_RMSK                            0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_BMSK                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_SHFT                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000258)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_RMSK                            0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_BMSK                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_SHFT                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000025c)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_RMSK                               0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_SHRAM_PTR_BMSK                     0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_SHRAM_PTR_SHFT                        0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000260)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_RMSK                                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_SHRAM_PTR_BMSK                        0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_SHRAM_PTR_SHFT                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000264)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_RMSK                                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_SHRAM_PTR_BMSK                        0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_SHRAM_PTR_SHFT                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000400)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_RMSK                                                   0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_IRAM_PTR_BMSK                                          0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_CMD_IRAM_PTR_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000404)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_RMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_IRAM_PTR_BMSK                                  0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EE_GENERIC_CMD_IRAM_PTR_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000408)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_RMSK                                          0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IRAM_PTR_BMSK                                 0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IRAM_PTR_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000418)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_RMSK                                                    0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_IRAM_PTR_BMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DB_IRAM_PTR_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000041c)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_RMSK                                                    0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_IRAM_PTR_BMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EV_DB_IRAM_PTR_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000420)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_RMSK                                                   0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_IRAM_PTR_BMSK                                          0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_NEW_RE_IRAM_PTR_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_ADDR                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000424)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_RMSK                                              0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_IRAM_PTR_BMSK                                     0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_DIS_COMP_IRAM_PTR_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000428)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_RMSK                                                 0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_IRAM_PTR_BMSK                                        0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_CH_EMPTY_IRAM_PTR_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000042c)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_RMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_IRAM_PTR_BMSK                                  0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_EVENT_GEN_COMP_IRAM_PTR_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000430)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_RMSK                                       0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IRAM_PTR_BMSK                              0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IRAM_PTR_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000434)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_RMSK                                       0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IRAM_PTR_BMSK                              0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IRAM_PTR_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000438)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_RMSK                                       0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IRAM_PTR_BMSK                              0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IRAM_PTR_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000043c)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_RMSK                                            0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_IRAM_PTR_BMSK                                   0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_TIMER_EXPIRED_IRAM_PTR_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000440)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_RMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_IRAM_PTR_BMSK                                  0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_WRITE_ENG_COMP_IRAM_PTR_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_ADDR                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000444)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_RMSK                                            0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_IRAM_PTR_BMSK                                   0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_READ_ENG_COMP_IRAM_PTR_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_ADDR                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000448)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_RMSK                                                0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_IRAM_PTR_BMSK                                       0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_UC_GP_INT_IRAM_PTR_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000044c)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_RMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_IRAM_PTR_BMSK                                  0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_INT_MOD_STOPED_IRAM_PTR_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000450 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_RMSK                                               0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_MAXn                                                   3
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_IRAM_PTR_BMSK                                      0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_IRAM_PTR_SDMA_INT_n_IRAM_PTR_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_ADDR(n)                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001b000 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_RMSK                                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_MAXn                                                         8191
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_3_BMSK                                       0xff000000
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_3_SHFT                                             0x18
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_2_BMSK                                         0xff0000
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_2_SHFT                                             0x10
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_1_BMSK                                           0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_1_SHFT                                              0x8
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_0_BMSK                                             0xff
#define HWIO_IPA_0_GSI_TOP_GSI_INST_RAM_n_INST_BYTE_0_SHFT                                              0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_ADDR(n)                                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00002000 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_RMSK                                                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_MAXn                                                            1343
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_SHRAM_BMSK                                                0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_SHRAM_n_SHRAM_SHFT                                                       0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(n,k)                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00003800 + 0x80 * (n) + 0x4 * (k))
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_RMSK                                             0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_MAXn                                                2
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_MAXk                                               22
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(n,k), HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_VALID_BMSK                                       0x20
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_VALID_SHFT                                        0x5
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_PHY_CH_BMSK                                      0x1f
#define HWIO_IPA_0_GSI_TOP_GSI_MAP_EE_n_CH_k_VP_TABLE_PHY_CH_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_ADDR                                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001000)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_RMSK                                                    0xf00ff
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_GSI_HW_EVENTS_SEL_BMSK                                  0xf0000
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_GSI_HW_EVENTS_SEL_SHFT                                     0x10
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_BMSK                                       0xff
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_ADDR                                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001008)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_RMSK                                                 0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_GSI_TESTBUS_REG_BMSK                                 0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_TEST_BUS_REG_GSI_TESTBUS_REG_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001010)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_RMSK                                                   0x1fff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_SDMA_BUSY_BMSK                                         0x1000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_SDMA_BUSY_SHFT                                            0xc
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_IC_BUSY_BMSK                                            0x800
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_IC_BUSY_SHFT                                              0xb
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_UC_BUSY_BMSK                                            0x400
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_UC_BUSY_SHFT                                              0xa
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_DBG_CNT_BUSY_BMSK                                       0x200
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_DBG_CNT_BUSY_SHFT                                         0x9
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_DB_ENG_BUSY_BMSK                                        0x100
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_DB_ENG_BUSY_SHFT                                          0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_REE_PWR_CLPS_BUSY_BMSK                                   0x80
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_REE_PWR_CLPS_BUSY_SHFT                                    0x7
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_INT_ENG_BUSY_BMSK                                        0x40
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_INT_ENG_BUSY_SHFT                                         0x6
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_EV_ENG_BUSY_BMSK                                         0x20
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_EV_ENG_BUSY_SHFT                                          0x5
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_RD_WR_BUSY_BMSK                                          0x10
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_RD_WR_BUSY_SHFT                                           0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_TIMER_BUSY_BMSK                                           0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_TIMER_BUSY_SHFT                                           0x3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_MCS_BUSY_BMSK                                             0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_MCS_BUSY_SHFT                                             0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_REE_BUSY_BMSK                                             0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_REE_BUSY_SHFT                                             0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_CSR_BUSY_BMSK                                             0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_BUSY_REG_CSR_BUSY_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001014)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_CHID_BIT_MAP_BMSK                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EVENT_PENDING_CHID_BIT_MAP_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001018)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_CHID_BIT_MAP_BMSK                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_TIMER_PENDING_CHID_BIT_MAP_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_ADDR                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000101c)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_CHID_BIT_MAP_BMSK                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_RD_WR_PENDING_CHID_BIT_MAP_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ADDR(n)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001200 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_RMSK                                             0x1fffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_MAXn                                                    7
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_CHAIN_BMSK                                       0x100000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_CHAIN_SHFT                                           0x14
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_VIRTUAL_CHNL_BMSK                                 0xff000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_VIRTUAL_CHNL_SHFT                                     0xc
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_EE_BMSK                                             0xf00
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_EE_SHFT                                               0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_EVNT_TYPE_BMSK                                       0xf8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_EVNT_TYPE_SHFT                                        0x3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_CLR_AT_READ_BMSK                                      0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_CLR_AT_READ_SHFT                                      0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_STOP_AT_WRAP_ARND_BMSK                                0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_STOP_AT_WRAP_ARND_SHFT                                0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ENABLE_BMSK                                           0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTER_CFGn_ENABLE_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_ADDR(n)                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001240 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_RMSK                                                   0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_MAXn                                                        7
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_COUNTER_VALUE_BMSK                                     0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_COUNTERn_COUNTER_VALUE_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_ADDR                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001040)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_RMSK                                                  0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_IRAM_PTR_BMSK                                         0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FROM_SW_IRAM_PTR_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001044)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_RMSK                                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_MCS_STALL_BMSK                                            0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_STALL_MCS_STALL_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_ADDR                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001048)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_RMSK                                                0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_IRAM_PTR_BMSK                                       0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_PC_FOR_DEBUG_IRAM_PTR_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001050)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_RMSK                                              0xffff01
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_MID_BMSK                                      0xff0000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_MID_SHFT                                          0x10
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_TID_BMSK                                        0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_TID_SHFT                                           0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_WRITE_BMSK                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_SEL_SEL_WRITE_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001058)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_RMSK                                                   0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_LOG_CLR_BMSK                                           0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_CLR_LOG_CLR_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR                                    (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001060)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_RMSK                                     0x1ffff01
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_SAVED_BMSK                           0x1000000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_SAVED_SHFT                                0x18
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_MID_BMSK                              0xff0000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_MID_SHFT                                  0x10
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_TID_BMSK                                0xff00
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_TID_SHFT                                   0x8
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_WRITE_BMSK                                 0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_WRITE_SHFT                                 0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001064)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_ADDR_31_0_BMSK                                    0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_0_ADDR_31_0_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001068)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_RMSK                                              0xfff7ffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AREQPRIORITY_BMSK                                 0xf0000000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AREQPRIORITY_SHFT                                       0x1c
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ASIZE_BMSK                                         0xf000000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ASIZE_SHFT                                              0x18
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ALEN_BMSK                                           0xf00000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ALEN_SHFT                                               0x14
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AOOOWR_BMSK                                          0x40000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AOOOWR_SHFT                                             0x12
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AOOORD_BMSK                                          0x20000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AOOORD_SHFT                                             0x11
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ATRANSIENT_BMSK                                      0x10000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ATRANSIENT_SHFT                                         0x10
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ACACHEABLE_BMSK                                       0x8000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ACACHEABLE_SHFT                                          0xf
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ASHARED_BMSK                                          0x4000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ASHARED_SHFT                                             0xe
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ANOALLOCATE_BMSK                                      0x2000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ANOALLOCATE_SHFT                                         0xd
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AINNERSHARED_BMSK                                     0x1000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_AINNERSHARED_SHFT                                        0xc
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ADDR_43_32_BMSK                                        0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_1_ADDR_43_32_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000106c)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_RMSK                                                  0xffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_AMEMTYPE_BMSK                                         0xf000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_AMEMTYPE_SHFT                                            0xc
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_AMMUSID_BMSK                                           0xfff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_2_AMMUSID_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(n)                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001070 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_RMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MAXn                                           3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MID_BMSK                              0xf8000000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MID_SHFT                                    0x1b
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_TID_BMSK                               0x7c00000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_TID_SHFT                                    0x16
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_WRITE_BMSK                              0x200000
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_WRITE_SHFT                                  0x15
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR_20_0_BMSK                          0x1fffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR_20_0_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001080 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_MAXn                                                  31
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_DATA_IN_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_WRITE_DATA_IN_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_ADDR(n)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001100 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_RMSK                                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_MAXn                                                   31
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_RF_REG_BMSK                                    0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SW_RF_n_READ_RF_REG_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(n,k)                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001400 + 0x80 * (n) + 0x4 * (k))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_RMSK                                           0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_MAXn                                              3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_MAXk                                             22
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(n,k), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_VALID_BMSK                                     0x20
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_VALID_SHFT                                      0x5
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_PHY_CH_BMSK                                    0x1f
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_CH_k_VP_TABLE_PHY_CH_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(n,k)                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001600 + 0x80 * (n) + 0x4 * (k))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_RMSK                                           0x3f
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_MAXn                                              3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_MAXk                                             19
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(n,k), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_VALID_BMSK                                     0x20
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_VALID_SHFT                                      0x5
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_PHY_EV_CH_BMSK                                 0x1f
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_EE_n_EV_k_VP_TABLE_PHY_EV_CH_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_ADDR(n)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00001800 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_RMSK                                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_MAXn                                                 5
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_USER_DATA_LSB_BMSK                          0xfffff800
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_USER_DATA_LSB_SHFT                                 0xb
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_TID_CNT_BMSK                                     0x780
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_TID_CNT_SHFT                                       0x7
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_INT_ID_BMSK                                       0x78
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_INT_ID_SHFT                                        0x3
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_VLD_BMSK                                           0x4
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_VLD_SHFT                                           0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_BLOCKING_BMSK                                      0x2
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_BLOCKING_SHFT                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_WR_BMSK                                            0x1
#define HWIO_IPA_0_GSI_TOP_GSI_DEBUG_SDMA_TRANS_DB_n_WR_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_ADDR                                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000500)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_RMSK                                                          0xf
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_IC_2_UC_MCS_INT_VLD_BMSK                                      0x8
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_IC_2_UC_MCS_INT_VLD_SHFT                                      0x3
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_ACC_2_UC_MCS_GO_ACK_BMSK                                      0x4
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_ACC_2_UC_MCS_GO_ACK_SHFT                                      0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_UC_ACC_CMPLT_BMSK                                             0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_UC_ACC_CMPLT_SHFT                                             0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_UC_ACC_GO_BMSK                                                0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_UC_ACC_GO_SHFT                                                0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000504)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_RMSK                                                      0xf
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_IC_2_UC_MCS_INT_VLD_BMSK                                  0x8
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_IC_2_UC_MCS_INT_VLD_SHFT                                  0x3
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ACC_2_UC_MCS_GO_ACK_BMSK                                  0x4
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_ACC_2_UC_MCS_GO_ACK_SHFT                                  0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_UC_ACC_CMPLT_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_UC_ACC_CMPLT_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_UC_ACC_GO_BMSK                                            0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_MSK_UC_ACC_GO_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000508)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_RMSK                                                      0xf
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_IC_2_UC_MCS_INT_VLD_BMSK                                  0x8
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_IC_2_UC_MCS_INT_VLD_SHFT                                  0x3
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_ACC_2_UC_MCS_GO_ACK_BMSK                                  0x4
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_ACC_2_UC_MCS_GO_ACK_SHFT                                  0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_UC_ACC_CMPLT_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_UC_ACC_CMPLT_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_UC_ACC_GO_BMSK                                            0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_SRC_IRQ_CLR_UC_ACC_GO_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_ADDR(n)                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000050c + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_RMSK                                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_MAXn                                                            5
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_GSI_ACC_ARGS_BMSK                                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ARGS_n_GSI_ACC_ARGS_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_ADDR                                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000524)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_RMSK                                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_GSI_ACC_ROUTINE_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_ROUTINE_GSI_ACC_ROUTINE_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_ADDR                                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000528)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_RMSK                                                             0x7f
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_TIMER_GO_BMSK                                                    0x40
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_TIMER_GO_SHFT                                                     0x6
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_RW_ENG_GO_BMSK                                                   0x20
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_RW_ENG_GO_SHFT                                                    0x5
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_INT_ENG_GO_BMSK                                                  0x10
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_INT_ENG_GO_SHFT                                                   0x4
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_TLV_OUT_GO_BMSK                                                   0x8
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_TLV_OUT_GO_SHFT                                                   0x3
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_CSR_GO_BMSK                                                       0x4
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_CSR_GO_SHFT                                                       0x2
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_RE_ENG_GO_BMSK                                                    0x2
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_RE_ENG_GO_SHFT                                                    0x1
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_EV_ENG_GO_BMSK                                                    0x1
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_GO_EV_ENG_GO_SHFT                                                    0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000052c)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_GSI_ACC_2_UC_MCS_STTS_BMSK                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_STTS_GSI_ACC_2_UC_MCS_STTS_SHFT                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_ADDR                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000530)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_RMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_GSI_ACC_2_UC_MCS_RET_VAL_BMSK            0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_LSB_GSI_ACC_2_UC_MCS_RET_VAL_SHFT                   0x0

#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_ADDR                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000534)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_RMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_GSI_ACC_2_UC_MCS_RET_VAL_BMSK            0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_ACC_2_UC_MCS_RET_VAL_MSB_GSI_ACC_2_UC_MCS_RET_VAL_SHFT                   0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000538)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_GSI_IC_2_UC_MCS_VLD_BMSK                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_VLD_GSI_IC_2_UC_MCS_VLD_SHFT                                 0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_ADDR                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000053c)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_RMSK                                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_GSI_IC_2_UC_MCS_PC_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_PC_GSI_IC_2_UC_MCS_PC_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_ADDR(n)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000540 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_RMSK                                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_MAXn                                                    5
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_GSI_IC_2_UC_MCS_ARGS_BMSK                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_IC_2_UC_MCS_ARGS_n_GSI_IC_2_UC_MCS_ARGS_SHFT                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_ADDR                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000558)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_RMSK                                                       0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_GSI_UC_TLV_IN_VLD_BMSK                                     0x1
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_VLD_GSI_UC_TLV_IN_VLD_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_ADDR                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000055c)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_GSI_UC_TLV_IN_ROUTINE_BMSK                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ROUTINE_GSI_UC_TLV_IN_ROUTINE_SHFT                             0x0

#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_ADDR(n)                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00000560 + 0x4 * (n))
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_MAXn                                                      5
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_ADDR(n), HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_RMSK)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_INI(n))
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_GSI_UC_TLV_IN_ARGS_BMSK                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_GSI_UC_TLV_IN_ARGS_n_GSI_UC_TLV_IN_ARGS_SHFT                                 0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_RMSK                                            0xfff7ffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ELEMENT_SIZE_BMSK                               0xff000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ELEMENT_SIZE_SHFT                                     0x18
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_BMSK                                      0xf00000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_SHFT                                          0x14
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ERINDEX_BMSK                                       0x7c000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_ERINDEX_SHFT                                           0xe
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_MSB_BMSK                            0x2000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_MSB_SHFT                               0xd
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHID_BMSK                                           0x1f00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHID_SHFT                                              0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_EE_BMSK                                               0xf0
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_EE_SHFT                                                0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_BMSK                                        0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_SHFT                                        0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_BMSK                                   0x7
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_RMSK                                                0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_R_LENGTH_BMSK                                       0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_1_R_LENGTH_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f00c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_READ_PTR_LSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_4_READ_PTR_LSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_READ_PTR_MSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_5_READ_PTR_MSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_WRITE_PTR_LSB_BMSK                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_6_WRITE_PTR_LSB_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f01c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_MAXk                                                    22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_WRITE_PTR_MSB_BMSK                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_CNTXT_7_WRITE_PTR_MSB_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(n,k)                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f054 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_RMSK                                      0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_MAXn                                           2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_MAXk                                          22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_READ_PTR_BMSK                             0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_READ_PTR_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(n,k)                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f058 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RMSK                                     0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_MAXn                                          2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_MAXk                                         22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RE_INTR_DB_BMSK                          0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RE_INTR_DB_SHFT                             0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_ADDR(n,k)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f05c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_RMSK                                                  0xff3f0f
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_MAXn                                                         2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_MAXk                                                        22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_EMPTY_LVL_THRSHOLD_BMSK                               0xff0000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_EMPTY_LVL_THRSHOLD_SHFT                                   0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_BMSK                                      0x3c00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_SHFT                                         0xa
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_USE_DB_ENG_BMSK                                          0x200
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_USE_DB_ENG_SHFT                                            0x9
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_BMSK                                        0x100
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_SHFT                                          0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_WRR_WEIGHT_BMSK                                            0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_QOS_WRR_WEIGHT_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f060 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_MAXk                                                  22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_SCRATCH_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_0_SCRATCH_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f064 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_MAXk                                                  22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_SCRATCH_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_1_SCRATCH_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f068 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_MAXk                                                  22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_SCRATCH_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_2_SCRATCH_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f06c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_MAXk                                                  22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_SCRATCH_BMSK                                  0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_SCRATCH_3_SCRATCH_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(n,k)                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000f070 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_RMSK                                       0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_MAXn                                            2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_MAXk                                           22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_LAST_DB_2_MCS_BMSK                         0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_LAST_DB_2_MCS_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_RMSK                                             0xfff1ffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ELEMENT_SIZE_BMSK                                0xff000000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_ELEMENT_SIZE_SHFT                                      0x18
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_CHSTATE_BMSK                                       0xf00000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_CHSTATE_SHFT                                           0x14
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_INTYPE_BMSK                                         0x10000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_INTYPE_SHFT                                            0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_EVCHID_BMSK                                          0xff00
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_EVCHID_SHFT                                             0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_EE_BMSK                                                0xf0
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_EE_SHFT                                                 0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_CHTYPE_BMSK                                             0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_0_CHTYPE_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_RMSK                                                 0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_R_LENGTH_BMSK                                        0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_1_R_LENGTH_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001000c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_READ_PTR_LSB_BMSK                                0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_4_READ_PTR_LSB_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_READ_PTR_MSB_BMSK                                0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_5_READ_PTR_MSB_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_WRITE_PTR_LSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_6_WRITE_PTR_LSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001001c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_WRITE_PTR_MSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_7_WRITE_PTR_MSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010020 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MOD_CNT_BMSK                                 0xff000000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MOD_CNT_SHFT                                       0x18
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MODC_BMSK                                      0xff0000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MODC_SHFT                                          0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MODT_BMSK                                        0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_8_INT_MODT_SHFT                                           0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_ADDR(n,k)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010024 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_MAXk                                                     19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_INTVEC_BMSK                                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_9_INTVEC_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010028 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_MAXk                                                    19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_MSI_ADDR_LSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_10_MSI_ADDR_LSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001002c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_MAXk                                                    19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_MSI_ADDR_MSB_BMSK                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_11_MSI_ADDR_MSB_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010030 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_MAXk                                                    19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_RP_UPDATE_ADDR_LSB_BMSK                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_12_RP_UPDATE_ADDR_LSB_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_ADDR(n,k)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010034 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_MAXk                                                    19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_RP_UPDATE_ADDR_MSB_BMSK                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_CNTXT_13_RP_UPDATE_ADDR_MSB_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_ADDR(n,k)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00010048 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_RMSK                                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_MAXn                                                    2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_MAXk                                                   19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_SCRATCH_BMSK                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_0_SCRATCH_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_ADDR(n,k)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001004c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_RMSK                                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_MAXn                                                    2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_MAXk                                                   19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_INI2(n,k)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_ADDR(n,k), HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_INMI2(n,k,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_ADDR(n,k), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_OUTMI2(n,k,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_ADDR(n,k),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_INI2(n,k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_SCRATCH_BMSK                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_SCRATCH_1_SCRATCH_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_ADDR(n,k)                                    (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00011000 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_MAXk                                                 22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_WRITE_PTR_LSB_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_0_WRITE_PTR_LSB_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_ADDR(n,k)                                    (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00011004 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_MAXk                                                 22
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_WRITE_PTR_MSB_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_k_DOORBELL_1_WRITE_PTR_MSB_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00011100 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_MAXk                                                  19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_WRITE_PTR_LSB_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_0_WRITE_PTR_LSB_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_ADDR(n,k)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00011104 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_MAXk                                                  19
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_OUTI2(n,k,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_ADDR(n,k),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_WRITE_PTR_MSB_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_k_DOORBELL_1_WRITE_PTR_MSB_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_ADDR(n)                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012000 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_RMSK                                                         0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_MAXn                                                           2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_ENABLED_BMSK                                                 0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_STATUS_ENABLED_SHFT                                                 0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_ADDR(n)                                               (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012008 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_RMSK                                                  0xff0000ff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_MAXn                                                           2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_OPCODE_BMSK                                           0xff000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_OPCODE_SHFT                                                 0x18
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_CHID_BMSK                                                   0xff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_CH_CMD_CHID_SHFT                                                    0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_ADDR(n)                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012010 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_RMSK                                                   0xff0000ff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_MAXn                                                            2
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_OPCODE_BMSK                                            0xff000000
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_OPCODE_SHFT                                                  0x18
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_CHID_BMSK                                                    0xff
#define HWIO_IPA_0_GSI_TOP_EE_n_EV_CH_CMD_CHID_SHFT                                                     0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012018 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_OPCODE_BMSK                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_EE_GENERIC_CMD_OPCODE_SHFT                                          0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012038 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_USE_AXI_M_BMSK                                    0x80000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_USE_AXI_M_SHFT                                          0x1f
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_PERIPH_SEC_GRP_BMSK                               0x7c000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_PERIPH_SEC_GRP_SHFT                                     0x1a
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_PERIPH_CONF_ADDR_BUS_W_BMSK                        0x3e00000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_PERIPH_CONF_ADDR_BUS_W_SHFT                             0x15
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_NUM_EES_BMSK                                        0x1f0000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_NUM_EES_SHFT                                            0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_GSI_CH_NUM_BMSK                                       0xff00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_GSI_CH_NUM_SHFT                                          0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_GSI_EV_CH_NUM_BMSK                                      0xff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_0_GSI_EV_CH_NUM_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001203c + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_2_EN_BMSK               0x80000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_2_EN_SHFT                     0x1f
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_1_EN_BMSK               0x40000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_1_EN_SHFT                     0x1e
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_SIMPLE_RD_WR_BMSK                             0x20000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_SIMPLE_RD_WR_SHFT                                   0x1d
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_ESCAPE_BUF_ONLY_BMSK                          0x10000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_ESCAPE_BUF_ONLY_SHFT                                0x1c
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_UC_IF_BMSK                                 0x8000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_UC_IF_SHFT                                      0x1b
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_DB_ENG_BMSK                                0x4000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_DB_ENG_SHFT                                     0x1a
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_BP_MTRIX_BMSK                              0x2000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_BP_MTRIX_SHFT                                   0x19
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NUM_TIMERS_BMSK                                0x1f00000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NUM_TIMERS_SHFT                                     0x14
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_XPU_BMSK                                     0x80000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_USE_XPU_SHFT                                        0x13
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_QRIB_EN_BMSK                                     0x40000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_QRIB_EN_SHFT                                        0x12
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_VMIDACR_EN_BMSK                                  0x20000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_VMIDACR_EN_SHFT                                     0x11
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_SEC_EN_BMSK                                      0x10000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_SEC_EN_SHFT                                         0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NONSEC_EN_BMSK                                    0xf000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NONSEC_EN_SHFT                                       0xc
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NUM_QAD_BMSK                                       0xf00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_NUM_QAD_SHFT                                         0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_M_DATA_BUS_W_BMSK                                   0xff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_1_GSI_M_DATA_BUS_W_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012040 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_INTER_EE_BMSK                             0x80000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_INTER_EE_SHFT                                   0x1f
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_RD_WR_ENG_BMSK                            0x40000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_RD_WR_ENG_SHFT                                  0x1e
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_IOVEC_BMSK                             0x38000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_IOVEC_SHFT                                   0x1b
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_MAX_BURST_BMSK                            0x7f80000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_MAX_BURST_SHFT                                 0x13
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_INT_BMSK                                  0x70000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_INT_SHFT                                     0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_SDMA_BMSK                                     0x8000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_USE_SDMA_SHFT                                        0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_CH_FULL_LOGIC_BMSK                                0x4000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_CH_FULL_LOGIC_SHFT                                   0xe
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_CH_PEND_TRANSLATE_BMSK                            0x2000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_CH_PEND_TRANSLATE_SHFT                               0xd
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_NUM_EV_PER_EE_BMSK                                0x1f00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_NUM_EV_PER_EE_SHFT                                   0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_NUM_CH_PER_EE_BMSK                                  0xf8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_NUM_CH_PER_EE_SHFT                                   0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_BMSK                                       0x7
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012044 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_RMSK                                              0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_MAJOR_BMSK                                        0xf0000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_MAJOR_SHFT                                              0x1c
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_MINOR_BMSK                                         0xfff0000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_MINOR_SHFT                                              0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_STEP_BMSK                                             0xffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_SW_VERSION_STEP_SHFT                                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_ADDR(n)                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012048 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_RMSK                                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_VER_BMSK                                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_MCS_CODE_VER_VER_SHFT                                               0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001204c + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_RMSK                                               0xfffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_SLEEP_CLK_DIV_BMSK                         0x8000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_SLEEP_CLK_DIV_SHFT                              0x1b
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_VIR_CH_IF_BMSK                             0x4000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_VIR_CH_IF_SHFT                                  0x1a
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_IROM_BMSK                                  0x2000000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_USE_IROM_SHFT                                       0x19
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_REE_MAX_BURST_LEN_BMSK                         0x1f00000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_REE_MAX_BURST_LEN_SHFT                              0x14
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_M_ADDR_BUS_W_BMSK                                0xff000
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_M_ADDR_BUS_W_SHFT                                    0xc
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_NUM_PREFETCH_BUFS_BMSK                             0xf00
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_NUM_PREFETCH_BUFS_SHFT                               0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_WR_BMSK                                 0xf0
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_WR_SHFT                                  0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_RD_BMSK                                  0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_RD_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_ADDR(n)                                           (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012080 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_RMSK                                                    0x7f
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MAXn                                                       2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_GENERAL_BMSK                                            0x40
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_GENERAL_SHFT                                             0x6
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INTER_EE_EV_CTRL_BMSK                                   0x20
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INTER_EE_EV_CTRL_SHFT                                    0x5
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INTER_EE_CH_CTRL_BMSK                                   0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_INTER_EE_CH_CTRL_SHFT                                    0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_IEOB_BMSK                                                0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_IEOB_SHFT                                                0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_GLOB_EE_BMSK                                             0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_GLOB_EE_SHFT                                             0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_EV_CTRL_BMSK                                             0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_EV_CTRL_SHFT                                             0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_CH_CTRL_BMSK                                             0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_CH_CTRL_SHFT                                             0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012088 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_RMSK                                                0x7f
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_GENERAL_BMSK                                        0x40
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_GENERAL_SHFT                                         0x6
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_EV_CTRL_BMSK                               0x20
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_EV_CTRL_SHFT                                0x5
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_CH_CTRL_BMSK                               0x10
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_CH_CTRL_SHFT                                0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_IEOB_BMSK                                            0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_IEOB_SHFT                                            0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_GLOB_EE_BMSK                                         0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_GLOB_EE_SHFT                                         0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_EV_CTRL_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_EV_CTRL_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_CH_CTRL_BMSK                                         0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_TYPE_IRQ_MSK_CH_CTRL_SHFT                                         0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(n)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012090 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_RMSK                                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MAXn                                                 2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_BMSK                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(n)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012094 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(n)                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012098 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_RMSK                                      0x7fffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_MAXn                                             2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_BMSK                   0x7fffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_SHFT                        0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(n)                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001209c + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_RMSK                                        0xfffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_MAXn                                              2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_BMSK                      0xfffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_SHFT                          0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_ADDR(n)                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000120a0 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_RMSK                                    0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_MAXn                                             2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_BMSK                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_ADDR(n)                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000120a4 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_RMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_MAXn                                              2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_BMSK                       0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_SHFT                              0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000120b0 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_EV_CH_BIT_MAP_BMSK                            0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_EV_CH_BIT_MAP_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(n)                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000120b8 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_RMSK                                         0xfffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_MAXn                                               2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_EV_CH_BIT_MAP_MSK_BMSK                       0xfffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_EV_CH_BIT_MAP_MSK_SHFT                           0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_ADDR(n)                                   (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x000120c0 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_RMSK                                      0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_MAXn                                               2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_EV_CH_BIT_MAP_BMSK                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_EV_CH_BIT_MAP_SHFT                               0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(n)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012100 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_RMSK                                                0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT3_BMSK                                        0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT3_SHFT                                        0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT2_BMSK                                        0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT2_SHFT                                        0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT1_BMSK                                        0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT1_SHFT                                        0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_ERROR_INT_BMSK                                      0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_STTS_ERROR_INT_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(n)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012108 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_RMSK                                                  0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_MAXn                                                    2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT3_BMSK                                          0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT3_SHFT                                          0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT2_BMSK                                          0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT2_SHFT                                          0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT1_BMSK                                          0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT1_SHFT                                          0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ERROR_INT_BMSK                                        0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_EN_ERROR_INT_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012110 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_RMSK                                                 0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT3_BMSK                                         0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT3_SHFT                                         0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT2_BMSK                                         0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT2_SHFT                                         0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT1_BMSK                                         0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT1_SHFT                                         0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_ERROR_INT_BMSK                                       0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GLOB_IRQ_CLR_ERROR_INT_SHFT                                       0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012118 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_RMSK                                                 0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_MCS_STACK_OVRFLOW_BMSK                           0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_MCS_STACK_OVRFLOW_SHFT                           0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_CMD_FIFO_OVRFLOW_BMSK                            0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_CMD_FIFO_OVRFLOW_SHFT                            0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BUS_ERROR_BMSK                                   0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BUS_ERROR_SHFT                                   0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BREAK_POINT_BMSK                                 0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BREAK_POINT_SHFT                                 0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_ADDR(n)                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012120 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_RMSK                                                   0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_MCS_STACK_OVRFLOW_BMSK                             0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_MCS_STACK_OVRFLOW_SHFT                             0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_CMD_FIFO_OVRFLOW_BMSK                              0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_CMD_FIFO_OVRFLOW_SHFT                              0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_BUS_ERROR_BMSK                                     0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_BUS_ERROR_SHFT                                     0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_BREAK_POINT_BMSK                                   0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_EN_GSI_BREAK_POINT_SHFT                                   0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_ADDR(n)                                        (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012128 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_RMSK                                                  0xf
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_MAXn                                                    2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_MCS_STACK_OVRFLOW_BMSK                            0x8
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_MCS_STACK_OVRFLOW_SHFT                            0x3
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_CMD_FIFO_OVRFLOW_BMSK                             0x4
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_CMD_FIFO_OVRFLOW_SHFT                             0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BUS_ERROR_BMSK                                    0x2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BUS_ERROR_SHFT                                    0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BREAK_POINT_BMSK                                  0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BREAK_POINT_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_ADDR(n)                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012180 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_RMSK                                                       0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_MAXn                                                         2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_INTYPE_BMSK                                                0x1
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INTSET_INTYPE_SHFT                                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012188 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_MSI_ADDR_LSB_BMSK                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_LSB_MSI_ADDR_LSB_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_ADDR(n)                                       (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0001218c + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_RMSK                                          0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_MAXn                                                   2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_MSI_ADDR_MSB_BMSK                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_MSI_BASE_MSB_MSI_ADDR_MSB_SHFT                                    0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_ADDR(n)                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012190 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_RMSK                                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_MAXn                                                        2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_INT_VEC_BMSK                                       0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_INT_VEC_INT_VEC_SHFT                                              0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ADDR(n)                                                (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012200 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_RMSK                                                   0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_MAXn                                                            2
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ERROR_LOG_BMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_ERROR_LOG_SHFT                                                0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_ADDR(n)                                            (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012210 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_RMSK                                               0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_MAXn                                                        2
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_ERROR_LOG_CLR_BMSK                                 0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_ERROR_LOG_CLR_ERROR_LOG_CLR_SHFT                                        0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_ADDR(n)                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012400 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_SCRATCH_BMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_0_SCRATCH_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_ADDR(n)                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x00012404 + 0x4000 * (n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_RMSK                                             0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_ADDR(n), HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_RMSK)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_INI(n))
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_SCRATCH_BMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_EE_n_CNTXT_SCRATCH_1_SCRATCH_SHFT                                            0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_ADDR                                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000b000)
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_RMSK                                                             0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_MCS_ENABLE_BMSK                                                  0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MCS_CFG_MCS_ENABLE_SHFT                                                  0x0

#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000b008)
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_RMSK                                                     0x3
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                               0x2
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                               0x1
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_TZ_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_ADDR                                             (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000b010)
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_RMSK                                                    0x3
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                              0x2
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                              0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                     0x1
#define HWIO_IPA_0_GSI_TOP_GSI_MSA_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                     0x0

#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_ADDR                                              (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000b018)
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_RMSK                                                     0x3
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_IN          \
        in_dword(HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_ADDR)
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_INM(m)      \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_ADDR, m)
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_OUT(v)      \
        out_dword(HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_ADDR,v)
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_OUTM(m,v) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_ADDR,m,v,HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_IN)
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                               0x2
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                               0x1
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                      0x1
#define HWIO_IPA_0_GSI_TOP_GSI_SP_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_ADDR(n)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c000 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_RMSK                                                0xf
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_ADDR(n), HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_RMSK)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_INI(n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_EE_NUMBER_BMSK                                      0xf
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_ORIGINATOR_EE_EE_NUMBER_SHFT                                      0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_ADDR(n)                                         (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c008 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_RMSK                                            0xff0000ff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_MAXn                                                     2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_OPCODE_BMSK                                     0xff000000
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_OPCODE_SHFT                                           0x18
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_CHID_BMSK                                             0xff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_GSI_CH_CMD_CHID_SHFT                                              0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_ADDR(n)                                          (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c010 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_RMSK                                             0xff0000ff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_MAXn                                                      2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_OPCODE_BMSK                                      0xff000000
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_OPCODE_SHFT                                            0x18
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_CHID_BMSK                                              0xff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_EV_CH_CMD_CHID_SHFT                                               0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_ADDR(n)                                     (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c018 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_RMSK                                        0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MAXn                                                 2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_BMSK                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_SHFT                                0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_ADDR(n)                                      (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c01c + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_RMSK                                         0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MAXn                                                  2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_ADDR(n), HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_RMSK)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_BMSK                           0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_SHFT                                  0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_ADDR(n)                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c020 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_RMSK                                      0x7fffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_MAXn                                             2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_BMSK                   0x7fffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_SHFT                        0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_ADDR(n)                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c024 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_RMSK                                        0xfffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_MAXn                                              2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_INI(n)        \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_ADDR(n), HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_RMSK)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_INMI(n,mask)    \
        in_dword_masked(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_ADDR(n), mask)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_ADDR(n),mask,val,HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_INI(n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_BMSK                      0xfffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_SHFT                          0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_ADDR(n)                                 (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c028 + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_RMSK                                    0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_MAXn                                             2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_BMSK                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_SHFT                            0x0

#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_ADDR(n)                                  (IPA_0_GSI_TOP_GSI_REG_BASE      + 0x0000c02c + 0x1000 * (n))
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_RMSK                                     0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_MAXn                                              2
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_OUTI(n,val)    \
        out_dword(HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_ADDR(n),val)
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_BMSK                       0xffffffff
#define HWIO_IPA_0_GSI_TOP_INTER_EE_n_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_SHFT                              0x0


#endif /* __HWIO_H__ */
