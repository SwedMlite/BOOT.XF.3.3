#ifndef __GSIHWIO_H__
#define __GSIHWIO_H__
/*
===========================================================================
*/
/**
  @file gsihwio.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) [kona_v1.0_p3q1r17.2_M00]
 
  This file contains HWIO register definitions for the following modules:
    QUPV3_0_GSI


  Generation parameters: 
  { u'explicit-addressing': True,
    u'filename': u'gsihwio.h',
    u'ignore-prefixes': True,
    u'module-filter-exclude': { },
    u'module-filter-include': { },
    u'modules': [u'QUPV3_0_GSI'],
    u'output-fvals': True,
    u'output-offsets': True}
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Include/gsihwio.h#2 $
  $DateTime: 2018/12/12 11:40:28 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include <msmhwiobase.h>
#include <Include/HALhwio.h>

#define MAX_NUM_QUP_BLOCKS           4
#define NUM_ACTIVE_QUP_BLOCKS        3
#define MAX_GPII_PER_QUP             15
#define NUM_GPII                     (NUM_ACTIVE_QUP_BLOCKS*MAX_GPII_PER_QUP)

/* GSI HW Instance */
typedef enum
{
   QUPV3_0   = 0,
   QUPV3_1   = 1,
   QUPV3_2   = 2,
   QUPV3_SSC = 3,

   QUP_MAX_BLOCK_IDX = QUPV3_SSC,
}QUPV3_BLOCK_TYPE;

#define QUPV3_0_COMMON_REG_BASE                  (QUPV3_0_QUPV3_ID_1_BASE + 0x000c0000)
#define QUPV3_1_COMMON_REG_BASE                  (QUPV3_1_QUPV3_ID_0_BASE + 0x000c0000)
#define QUPV3_2_COMMON_REG_BASE                  (QUPV3_2_QUPV3_ID_0_BASE + 0x000c0000)
#define QUPV3_COMMON_REG_BASE                    (SSC_BASE                + 0x006c0000)
#define GSI_0_REG_BASE                           (QUPV3_0_QUPV3_ID_1_BASE + 0x00004000)
#define GSI_1_REG_BASE                           (QUPV3_1_QUPV3_ID_0_BASE + 0x00004000)
#define GSI_2_REG_BASE                           (QUPV3_2_QUPV3_ID_0_BASE + 0x00004000)
//#define GSI_REG_BASE                             (SSC_BASE                + 0x00604000)

/* Size of GSI regions in QUPV3 */
#define GSI_0_REG_BASE_SIZE               (0x5F000)
#define GSI_1_REG_BASE_SIZE               (0x46000)
#define GSI_2_REG_BASE_SIZE               (0x46000)
#define GSI_SSC_REG_BASE_SIZE             (0x64000)

/*----------------------------------------------------------------------------
 * MODULE: GSI
 *--------------------------------------------------------------------------*/

#define GSI_REG_BASE                                                                       (QUPV3_0_QUPV3_ID_1_BASE      + 0x00004000)
#define GSI_REG_BASE_SIZE                                                                  0x5f000
#define GSI_REG_BASE_USED                                                                  0x5affc
#define GSI_REG_BASE_OFFS                                                                  0x00004000

#define HWIO_GSI_CFG_ADDR(x)                                                               ((x) + 0x00000000)
#define HWIO_GSI_CFG_OFFS                                                                  (0x00000000)
#define HWIO_GSI_CFG_RMSK                                                                       0xf3f
#define HWIO_GSI_CFG_IN(x)      \
        in_dword(HWIO_GSI_CFG_ADDR(x))
#define HWIO_GSI_CFG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_CFG_ADDR(x), m)
#define HWIO_GSI_CFG_OUT(x, v)      \
        out_dword(HWIO_GSI_CFG_ADDR(x),v)
#define HWIO_GSI_CFG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_CFG_ADDR(x),m,v,HWIO_GSI_CFG_IN(x))
#define HWIO_GSI_CFG_SLEEP_CLK_DIV_BMSK                                                         0xf00
#define HWIO_GSI_CFG_SLEEP_CLK_DIV_SHFT                                                           0x8
#define HWIO_GSI_CFG_BP_MTRIX_DISABLE_BMSK                                                       0x20
#define HWIO_GSI_CFG_BP_MTRIX_DISABLE_SHFT                                                        0x5
#define HWIO_GSI_CFG_GSI_PWR_CLPS_BMSK                                                           0x10
#define HWIO_GSI_CFG_GSI_PWR_CLPS_SHFT                                                            0x4
#define HWIO_GSI_CFG_UC_IS_MCS_BMSK                                                               0x8
#define HWIO_GSI_CFG_UC_IS_MCS_SHFT                                                               0x3
#define HWIO_GSI_CFG_DOUBLE_MCS_CLK_FREQ_BMSK                                                     0x4
#define HWIO_GSI_CFG_DOUBLE_MCS_CLK_FREQ_SHFT                                                     0x2
#define HWIO_GSI_CFG_MCS_ENABLE_BMSK                                                              0x2
#define HWIO_GSI_CFG_MCS_ENABLE_SHFT                                                              0x1
#define HWIO_GSI_CFG_GSI_ENABLE_BMSK                                                              0x1
#define HWIO_GSI_CFG_GSI_ENABLE_SHFT                                                              0x0

#define HWIO_GSI_MANAGER_MCS_CODE_VER_ADDR(x)                                              ((x) + 0x00000008)
#define HWIO_GSI_MANAGER_MCS_CODE_VER_OFFS                                                 (0x00000008)
#define HWIO_GSI_MANAGER_MCS_CODE_VER_RMSK                                                 0xffffffff
#define HWIO_GSI_MANAGER_MCS_CODE_VER_IN(x)      \
        in_dword(HWIO_GSI_MANAGER_MCS_CODE_VER_ADDR(x))
#define HWIO_GSI_MANAGER_MCS_CODE_VER_INM(x, m)      \
        in_dword_masked(HWIO_GSI_MANAGER_MCS_CODE_VER_ADDR(x), m)
#define HWIO_GSI_MANAGER_MCS_CODE_VER_OUT(x, v)      \
        out_dword(HWIO_GSI_MANAGER_MCS_CODE_VER_ADDR(x),v)
#define HWIO_GSI_MANAGER_MCS_CODE_VER_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_MANAGER_MCS_CODE_VER_ADDR(x),m,v,HWIO_GSI_MANAGER_MCS_CODE_VER_IN(x))
#define HWIO_GSI_MANAGER_MCS_CODE_VER_VER_BMSK                                             0xffffffff
#define HWIO_GSI_MANAGER_MCS_CODE_VER_VER_SHFT                                                    0x0

#define HWIO_GSI_ZEROS_ADDR(x)                                                             ((x) + 0x00000010)
#define HWIO_GSI_ZEROS_OFFS                                                                (0x00000010)
#define HWIO_GSI_ZEROS_RMSK                                                                0xffffffff
#define HWIO_GSI_ZEROS_IN(x)      \
        in_dword(HWIO_GSI_ZEROS_ADDR(x))
#define HWIO_GSI_ZEROS_INM(x, m)      \
        in_dword_masked(HWIO_GSI_ZEROS_ADDR(x), m)
#define HWIO_GSI_ZEROS_ZEROS_BMSK                                                          0xffffffff
#define HWIO_GSI_ZEROS_ZEROS_SHFT                                                                 0x0

#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_ADDR(x)                                              ((x) + 0x00000018)
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_OFFS                                                 (0x00000018)
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_RMSK                                                 0xffffffff
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_IN(x)      \
        in_dword(HWIO_GSI_PERIPH_BASE_ADDR_LSB_ADDR(x))
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_INM(x, m)      \
        in_dword_masked(HWIO_GSI_PERIPH_BASE_ADDR_LSB_ADDR(x), m)
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_OUT(x, v)      \
        out_dword(HWIO_GSI_PERIPH_BASE_ADDR_LSB_ADDR(x),v)
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_PERIPH_BASE_ADDR_LSB_ADDR(x),m,v,HWIO_GSI_PERIPH_BASE_ADDR_LSB_IN(x))
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_BASE_ADDR_BMSK                                       0xffffffff
#define HWIO_GSI_PERIPH_BASE_ADDR_LSB_BASE_ADDR_SHFT                                              0x0

#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_ADDR(x)                                              ((x) + 0x0000001c)
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_OFFS                                                 (0x0000001c)
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_RMSK                                                 0xffffffff
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_IN(x)      \
        in_dword(HWIO_GSI_PERIPH_BASE_ADDR_MSB_ADDR(x))
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_INM(x, m)      \
        in_dword_masked(HWIO_GSI_PERIPH_BASE_ADDR_MSB_ADDR(x), m)
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_OUT(x, v)      \
        out_dword(HWIO_GSI_PERIPH_BASE_ADDR_MSB_ADDR(x),v)
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_PERIPH_BASE_ADDR_MSB_ADDR(x),m,v,HWIO_GSI_PERIPH_BASE_ADDR_MSB_IN(x))
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_BASE_ADDR_BMSK                                       0xffffffff
#define HWIO_GSI_PERIPH_BASE_ADDR_MSB_BASE_ADDR_SHFT                                              0x0

#define HWIO_GSI_PERIPH_PENDING_ADDR(x)                                                    ((x) + 0x00000020)
#define HWIO_GSI_PERIPH_PENDING_OFFS                                                       (0x00000020)
#define HWIO_GSI_PERIPH_PENDING_RMSK                                                       0xffffffff
#define HWIO_GSI_PERIPH_PENDING_IN(x)      \
        in_dword(HWIO_GSI_PERIPH_PENDING_ADDR(x))
#define HWIO_GSI_PERIPH_PENDING_INM(x, m)      \
        in_dword_masked(HWIO_GSI_PERIPH_PENDING_ADDR(x), m)
#define HWIO_GSI_PERIPH_PENDING_CHID_BIT_MAP_BMSK                                          0xffffffff
#define HWIO_GSI_PERIPH_PENDING_CHID_BIT_MAP_SHFT                                                 0x0

#define HWIO_GSI_MOQA_CFG_ADDR(x)                                                          ((x) + 0x00000030)
#define HWIO_GSI_MOQA_CFG_OFFS                                                             (0x00000030)
#define HWIO_GSI_MOQA_CFG_RMSK                                                               0xffffff
#define HWIO_GSI_MOQA_CFG_IN(x)      \
        in_dword(HWIO_GSI_MOQA_CFG_ADDR(x))
#define HWIO_GSI_MOQA_CFG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_MOQA_CFG_ADDR(x), m)
#define HWIO_GSI_MOQA_CFG_OUT(x, v)      \
        out_dword(HWIO_GSI_MOQA_CFG_ADDR(x),v)
#define HWIO_GSI_MOQA_CFG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_MOQA_CFG_ADDR(x),m,v,HWIO_GSI_MOQA_CFG_IN(x))
#define HWIO_GSI_MOQA_CFG_CLIENT_OOWR_BMSK                                                   0xff0000
#define HWIO_GSI_MOQA_CFG_CLIENT_OOWR_SHFT                                                       0x10
#define HWIO_GSI_MOQA_CFG_CLIENT_OORD_BMSK                                                     0xff00
#define HWIO_GSI_MOQA_CFG_CLIENT_OORD_SHFT                                                        0x8
#define HWIO_GSI_MOQA_CFG_CLIENT_REQ_PRIO_BMSK                                                   0xff
#define HWIO_GSI_MOQA_CFG_CLIENT_REQ_PRIO_SHFT                                                    0x0

#define HWIO_GSI_REE_CFG_ADDR(x)                                                           ((x) + 0x00000038)
#define HWIO_GSI_REE_CFG_OFFS                                                              (0x00000038)
#define HWIO_GSI_REE_CFG_RMSK                                                                  0xff03
#define HWIO_GSI_REE_CFG_IN(x)      \
        in_dword(HWIO_GSI_REE_CFG_ADDR(x))
#define HWIO_GSI_REE_CFG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_REE_CFG_ADDR(x), m)
#define HWIO_GSI_REE_CFG_OUT(x, v)      \
        out_dword(HWIO_GSI_REE_CFG_ADDR(x),v)
#define HWIO_GSI_REE_CFG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_REE_CFG_ADDR(x),m,v,HWIO_GSI_REE_CFG_IN(x))
#define HWIO_GSI_REE_CFG_MAX_BURST_SIZE_BMSK                                                   0xff00
#define HWIO_GSI_REE_CFG_MAX_BURST_SIZE_SHFT                                                      0x8
#define HWIO_GSI_REE_CFG_CHANNEL_EMPTY_INT_ENABLE_BMSK                                            0x2
#define HWIO_GSI_REE_CFG_CHANNEL_EMPTY_INT_ENABLE_SHFT                                            0x1
#define HWIO_GSI_REE_CFG_MOVE_TO_ESC_CLR_MODE_TRSH_BMSK                                           0x1
#define HWIO_GSI_REE_CFG_MOVE_TO_ESC_CLR_MODE_TRSH_SHFT                                           0x0

#define HWIO_GSI_CGC_CTRL_ADDR(x)                                                          ((x) + 0x00000060)
#define HWIO_GSI_CGC_CTRL_OFFS                                                             (0x00000060)
#define HWIO_GSI_CGC_CTRL_RMSK                                                                 0x1fff
#define HWIO_GSI_CGC_CTRL_IN(x)      \
        in_dword(HWIO_GSI_CGC_CTRL_ADDR(x))
#define HWIO_GSI_CGC_CTRL_INM(x, m)      \
        in_dword_masked(HWIO_GSI_CGC_CTRL_ADDR(x), m)
#define HWIO_GSI_CGC_CTRL_OUT(x, v)      \
        out_dword(HWIO_GSI_CGC_CTRL_ADDR(x),v)
#define HWIO_GSI_CGC_CTRL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_CGC_CTRL_ADDR(x),m,v,HWIO_GSI_CGC_CTRL_IN(x))
#define HWIO_GSI_CGC_CTRL_REGION_13_HW_CGC_EN_BMSK                                             0x1000
#define HWIO_GSI_CGC_CTRL_REGION_13_HW_CGC_EN_SHFT                                                0xc
#define HWIO_GSI_CGC_CTRL_REGION_12_HW_CGC_EN_BMSK                                              0x800
#define HWIO_GSI_CGC_CTRL_REGION_12_HW_CGC_EN_SHFT                                                0xb
#define HWIO_GSI_CGC_CTRL_REGION_11_HW_CGC_EN_BMSK                                              0x400
#define HWIO_GSI_CGC_CTRL_REGION_11_HW_CGC_EN_SHFT                                                0xa
#define HWIO_GSI_CGC_CTRL_REGION_10_HW_CGC_EN_BMSK                                              0x200
#define HWIO_GSI_CGC_CTRL_REGION_10_HW_CGC_EN_SHFT                                                0x9
#define HWIO_GSI_CGC_CTRL_REGION_9_HW_CGC_EN_BMSK                                               0x100
#define HWIO_GSI_CGC_CTRL_REGION_9_HW_CGC_EN_SHFT                                                 0x8
#define HWIO_GSI_CGC_CTRL_REGION_8_HW_CGC_EN_BMSK                                                0x80
#define HWIO_GSI_CGC_CTRL_REGION_8_HW_CGC_EN_SHFT                                                 0x7
#define HWIO_GSI_CGC_CTRL_REGION_7_HW_CGC_EN_BMSK                                                0x40
#define HWIO_GSI_CGC_CTRL_REGION_7_HW_CGC_EN_SHFT                                                 0x6
#define HWIO_GSI_CGC_CTRL_REGION_6_HW_CGC_EN_BMSK                                                0x20
#define HWIO_GSI_CGC_CTRL_REGION_6_HW_CGC_EN_SHFT                                                 0x5
#define HWIO_GSI_CGC_CTRL_REGION_5_HW_CGC_EN_BMSK                                                0x10
#define HWIO_GSI_CGC_CTRL_REGION_5_HW_CGC_EN_SHFT                                                 0x4
#define HWIO_GSI_CGC_CTRL_REGION_4_HW_CGC_EN_BMSK                                                 0x8
#define HWIO_GSI_CGC_CTRL_REGION_4_HW_CGC_EN_SHFT                                                 0x3
#define HWIO_GSI_CGC_CTRL_REGION_3_HW_CGC_EN_BMSK                                                 0x4
#define HWIO_GSI_CGC_CTRL_REGION_3_HW_CGC_EN_SHFT                                                 0x2
#define HWIO_GSI_CGC_CTRL_REGION_2_HW_CGC_EN_BMSK                                                 0x2
#define HWIO_GSI_CGC_CTRL_REGION_2_HW_CGC_EN_SHFT                                                 0x1
#define HWIO_GSI_CGC_CTRL_REGION_1_HW_CGC_EN_BMSK                                                 0x1
#define HWIO_GSI_CGC_CTRL_REGION_1_HW_CGC_EN_SHFT                                                 0x0

#define HWIO_GSI_MSI_CACHEATTR_ADDR(x)                                                     ((x) + 0x00000080)
#define HWIO_GSI_MSI_CACHEATTR_OFFS                                                        (0x00000080)
#define HWIO_GSI_MSI_CACHEATTR_RMSK                                                              0x3f
#define HWIO_GSI_MSI_CACHEATTR_IN(x)      \
        in_dword(HWIO_GSI_MSI_CACHEATTR_ADDR(x))
#define HWIO_GSI_MSI_CACHEATTR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_MSI_CACHEATTR_ADDR(x), m)
#define HWIO_GSI_MSI_CACHEATTR_OUT(x, v)      \
        out_dword(HWIO_GSI_MSI_CACHEATTR_ADDR(x),v)
#define HWIO_GSI_MSI_CACHEATTR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_MSI_CACHEATTR_ADDR(x),m,v,HWIO_GSI_MSI_CACHEATTR_IN(x))
#define HWIO_GSI_MSI_CACHEATTR_AREQPRIORITY_BMSK                                                 0x30
#define HWIO_GSI_MSI_CACHEATTR_AREQPRIORITY_SHFT                                                  0x4
#define HWIO_GSI_MSI_CACHEATTR_ATRANSIENT_BMSK                                                    0x8
#define HWIO_GSI_MSI_CACHEATTR_ATRANSIENT_SHFT                                                    0x3
#define HWIO_GSI_MSI_CACHEATTR_ANOALLOCATE_BMSK                                                   0x4
#define HWIO_GSI_MSI_CACHEATTR_ANOALLOCATE_SHFT                                                   0x2
#define HWIO_GSI_MSI_CACHEATTR_AINNERSHARED_BMSK                                                  0x2
#define HWIO_GSI_MSI_CACHEATTR_AINNERSHARED_SHFT                                                  0x1
#define HWIO_GSI_MSI_CACHEATTR_ASHARED_BMSK                                                       0x1
#define HWIO_GSI_MSI_CACHEATTR_ASHARED_SHFT                                                       0x0

#define HWIO_GSI_EVENT_CACHEATTR_ADDR(x)                                                   ((x) + 0x00000084)
#define HWIO_GSI_EVENT_CACHEATTR_OFFS                                                      (0x00000084)
#define HWIO_GSI_EVENT_CACHEATTR_RMSK                                                            0x3f
#define HWIO_GSI_EVENT_CACHEATTR_IN(x)      \
        in_dword(HWIO_GSI_EVENT_CACHEATTR_ADDR(x))
#define HWIO_GSI_EVENT_CACHEATTR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_EVENT_CACHEATTR_ADDR(x), m)
#define HWIO_GSI_EVENT_CACHEATTR_OUT(x, v)      \
        out_dword(HWIO_GSI_EVENT_CACHEATTR_ADDR(x),v)
#define HWIO_GSI_EVENT_CACHEATTR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_EVENT_CACHEATTR_ADDR(x),m,v,HWIO_GSI_EVENT_CACHEATTR_IN(x))
#define HWIO_GSI_EVENT_CACHEATTR_AREQPRIORITY_BMSK                                               0x30
#define HWIO_GSI_EVENT_CACHEATTR_AREQPRIORITY_SHFT                                                0x4
#define HWIO_GSI_EVENT_CACHEATTR_ATRANSIENT_BMSK                                                  0x8
#define HWIO_GSI_EVENT_CACHEATTR_ATRANSIENT_SHFT                                                  0x3
#define HWIO_GSI_EVENT_CACHEATTR_ANOALLOCATE_BMSK                                                 0x4
#define HWIO_GSI_EVENT_CACHEATTR_ANOALLOCATE_SHFT                                                 0x2
#define HWIO_GSI_EVENT_CACHEATTR_AINNERSHARED_BMSK                                                0x2
#define HWIO_GSI_EVENT_CACHEATTR_AINNERSHARED_SHFT                                                0x1
#define HWIO_GSI_EVENT_CACHEATTR_ASHARED_BMSK                                                     0x1
#define HWIO_GSI_EVENT_CACHEATTR_ASHARED_SHFT                                                     0x0

#define HWIO_GSI_DATA_CACHEATTR_ADDR(x)                                                    ((x) + 0x00000088)
#define HWIO_GSI_DATA_CACHEATTR_OFFS                                                       (0x00000088)
#define HWIO_GSI_DATA_CACHEATTR_RMSK                                                             0x3f
#define HWIO_GSI_DATA_CACHEATTR_IN(x)      \
        in_dword(HWIO_GSI_DATA_CACHEATTR_ADDR(x))
#define HWIO_GSI_DATA_CACHEATTR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DATA_CACHEATTR_ADDR(x), m)
#define HWIO_GSI_DATA_CACHEATTR_OUT(x, v)      \
        out_dword(HWIO_GSI_DATA_CACHEATTR_ADDR(x),v)
#define HWIO_GSI_DATA_CACHEATTR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_DATA_CACHEATTR_ADDR(x),m,v,HWIO_GSI_DATA_CACHEATTR_IN(x))
#define HWIO_GSI_DATA_CACHEATTR_AREQPRIORITY_BMSK                                                0x30
#define HWIO_GSI_DATA_CACHEATTR_AREQPRIORITY_SHFT                                                 0x4
#define HWIO_GSI_DATA_CACHEATTR_ATRANSIENT_BMSK                                                   0x8
#define HWIO_GSI_DATA_CACHEATTR_ATRANSIENT_SHFT                                                   0x3
#define HWIO_GSI_DATA_CACHEATTR_ANOALLOCATE_BMSK                                                  0x4
#define HWIO_GSI_DATA_CACHEATTR_ANOALLOCATE_SHFT                                                  0x2
#define HWIO_GSI_DATA_CACHEATTR_AINNERSHARED_BMSK                                                 0x2
#define HWIO_GSI_DATA_CACHEATTR_AINNERSHARED_SHFT                                                 0x1
#define HWIO_GSI_DATA_CACHEATTR_ASHARED_BMSK                                                      0x1
#define HWIO_GSI_DATA_CACHEATTR_ASHARED_SHFT                                                      0x0

#define HWIO_GSI_TRE_CACHEATTR_ADDR(x)                                                     ((x) + 0x00000090)
#define HWIO_GSI_TRE_CACHEATTR_OFFS                                                        (0x00000090)
#define HWIO_GSI_TRE_CACHEATTR_RMSK                                                              0x3f
#define HWIO_GSI_TRE_CACHEATTR_IN(x)      \
        in_dword(HWIO_GSI_TRE_CACHEATTR_ADDR(x))
#define HWIO_GSI_TRE_CACHEATTR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_TRE_CACHEATTR_ADDR(x), m)
#define HWIO_GSI_TRE_CACHEATTR_OUT(x, v)      \
        out_dword(HWIO_GSI_TRE_CACHEATTR_ADDR(x),v)
#define HWIO_GSI_TRE_CACHEATTR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_TRE_CACHEATTR_ADDR(x),m,v,HWIO_GSI_TRE_CACHEATTR_IN(x))
#define HWIO_GSI_TRE_CACHEATTR_AREQPRIORITY_BMSK                                                 0x30
#define HWIO_GSI_TRE_CACHEATTR_AREQPRIORITY_SHFT                                                  0x4
#define HWIO_GSI_TRE_CACHEATTR_ATRANSIENT_BMSK                                                    0x8
#define HWIO_GSI_TRE_CACHEATTR_ATRANSIENT_SHFT                                                    0x3
#define HWIO_GSI_TRE_CACHEATTR_ANOALLOCATE_BMSK                                                   0x4
#define HWIO_GSI_TRE_CACHEATTR_ANOALLOCATE_SHFT                                                   0x2
#define HWIO_GSI_TRE_CACHEATTR_AINNERSHARED_BMSK                                                  0x2
#define HWIO_GSI_TRE_CACHEATTR_AINNERSHARED_SHFT                                                  0x1
#define HWIO_GSI_TRE_CACHEATTR_ASHARED_BMSK                                                       0x1
#define HWIO_GSI_TRE_CACHEATTR_ASHARED_SHFT                                                       0x0

#define HWIO_IC_INT_WEIGHT_REE_ADDR(x)                                                     ((x) + 0x00000100)
#define HWIO_IC_INT_WEIGHT_REE_OFFS                                                        (0x00000100)
#define HWIO_IC_INT_WEIGHT_REE_RMSK                                                             0xfff
#define HWIO_IC_INT_WEIGHT_REE_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_REE_ADDR(x))
#define HWIO_IC_INT_WEIGHT_REE_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_REE_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_REE_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_REE_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_REE_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_REE_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_REE_IN(x))
#define HWIO_IC_INT_WEIGHT_REE_CH_EMPTY_INT_WEIGHT_BMSK                                         0xf00
#define HWIO_IC_INT_WEIGHT_REE_CH_EMPTY_INT_WEIGHT_SHFT                                           0x8
#define HWIO_IC_INT_WEIGHT_REE_NEW_RE_INT_WEIGHT_BMSK                                            0xf0
#define HWIO_IC_INT_WEIGHT_REE_NEW_RE_INT_WEIGHT_SHFT                                             0x4
#define HWIO_IC_INT_WEIGHT_REE_STOP_CH_COMP_INT_WEIGHT_BMSK                                       0xf
#define HWIO_IC_INT_WEIGHT_REE_STOP_CH_COMP_INT_WEIGHT_SHFT                                       0x0

#define HWIO_IC_INT_WEIGHT_EVT_ENG_ADDR(x)                                                 ((x) + 0x00000104)
#define HWIO_IC_INT_WEIGHT_EVT_ENG_OFFS                                                    (0x00000104)
#define HWIO_IC_INT_WEIGHT_EVT_ENG_RMSK                                                           0xf
#define HWIO_IC_INT_WEIGHT_EVT_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_EVT_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_EVT_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_EVT_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_EVT_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_EVT_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_EVT_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_EVT_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_EVT_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_EVT_ENG_EVNT_ENG_INT_WEIGHT_BMSK                                       0xf
#define HWIO_IC_INT_WEIGHT_EVT_ENG_EVNT_ENG_INT_WEIGHT_SHFT                                       0x0

#define HWIO_IC_INT_WEIGHT_INT_ENG_ADDR(x)                                                 ((x) + 0x00000108)
#define HWIO_IC_INT_WEIGHT_INT_ENG_OFFS                                                    (0x00000108)
#define HWIO_IC_INT_WEIGHT_INT_ENG_RMSK                                                           0xf
#define HWIO_IC_INT_WEIGHT_INT_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_INT_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_INT_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_INT_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_INT_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_INT_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_INT_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_INT_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_INT_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_INT_ENG_INT_ENG_INT_WEIGHT_BMSK                                        0xf
#define HWIO_IC_INT_WEIGHT_INT_ENG_INT_ENG_INT_WEIGHT_SHFT                                        0x0

#define HWIO_IC_INT_WEIGHT_CSR_ADDR(x)                                                     ((x) + 0x0000010c)
#define HWIO_IC_INT_WEIGHT_CSR_OFFS                                                        (0x0000010c)
#define HWIO_IC_INT_WEIGHT_CSR_RMSK                                                              0xff
#define HWIO_IC_INT_WEIGHT_CSR_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_CSR_ADDR(x))
#define HWIO_IC_INT_WEIGHT_CSR_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_CSR_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_CSR_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_CSR_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_CSR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_CSR_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_CSR_IN(x))
#define HWIO_IC_INT_WEIGHT_CSR_EE_GENERIC_INT_WEIGHT_BMSK                                        0xf0
#define HWIO_IC_INT_WEIGHT_CSR_EE_GENERIC_INT_WEIGHT_SHFT                                         0x4
#define HWIO_IC_INT_WEIGHT_CSR_CH_CMD_INT_WEIGHT_BMSK                                             0xf
#define HWIO_IC_INT_WEIGHT_CSR_CH_CMD_INT_WEIGHT_SHFT                                             0x0

#define HWIO_IC_INT_WEIGHT_TLV_ENG_ADDR(x)                                                 ((x) + 0x00000110)
#define HWIO_IC_INT_WEIGHT_TLV_ENG_OFFS                                                    (0x00000110)
#define HWIO_IC_INT_WEIGHT_TLV_ENG_RMSK                                                        0xffff
#define HWIO_IC_INT_WEIGHT_TLV_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_TLV_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_TLV_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_TLV_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_TLV_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_TLV_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_TLV_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_TLV_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_TLV_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_TLV_ENG_CH_NOT_FULL_INT_WEIGHT_BMSK                                 0xf000
#define HWIO_IC_INT_WEIGHT_TLV_ENG_CH_NOT_FULL_INT_WEIGHT_SHFT                                    0xc
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_2_INT_WEIGHT_BMSK                                        0xf00
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_2_INT_WEIGHT_SHFT                                          0x8
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_1_INT_WEIGHT_BMSK                                         0xf0
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_1_INT_WEIGHT_SHFT                                          0x4
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_0_INT_WEIGHT_BMSK                                          0xf
#define HWIO_IC_INT_WEIGHT_TLV_ENG_TLV_0_INT_WEIGHT_SHFT                                          0x0

#define HWIO_IC_INT_WEIGHT_TIMER_ENG_ADDR(x)                                               ((x) + 0x00000114)
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_OFFS                                                  (0x00000114)
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_RMSK                                                         0xf
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_TIMER_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_TIMER_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_TIMER_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_TIMER_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_TIMER_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_TIMER_INT_WEIGHT_BMSK                                        0xf
#define HWIO_IC_INT_WEIGHT_TIMER_ENG_TIMER_INT_WEIGHT_SHFT                                        0x0

#define HWIO_IC_INT_WEIGHT_DB_ENG_ADDR(x)                                                  ((x) + 0x00000118)
#define HWIO_IC_INT_WEIGHT_DB_ENG_OFFS                                                     (0x00000118)
#define HWIO_IC_INT_WEIGHT_DB_ENG_RMSK                                                            0xf
#define HWIO_IC_INT_WEIGHT_DB_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_DB_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_DB_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_DB_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_DB_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_DB_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_DB_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_DB_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_DB_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_DB_ENG_NEW_DB_INT_WEIGHT_BMSK                                          0xf
#define HWIO_IC_INT_WEIGHT_DB_ENG_NEW_DB_INT_WEIGHT_SHFT                                          0x0

#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_ADDR(x)                                               ((x) + 0x0000011c)
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_OFFS                                                  (0x0000011c)
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_RMSK                                                        0xff
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_RD_WR_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_RD_WR_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_RD_WR_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_RD_WR_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_RD_WR_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_WRITE_INT_WEIGHT_BMSK                                       0xf0
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_WRITE_INT_WEIGHT_SHFT                                        0x4
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_READ_INT_WEIGHT_BMSK                                         0xf
#define HWIO_IC_INT_WEIGHT_RD_WR_ENG_READ_INT_WEIGHT_SHFT                                         0x0

#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR(x)                                         ((x) + 0x00000120)
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_OFFS                                            (0x00000120)
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_RMSK                                                   0xf
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_IN(x)      \
        in_dword(HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR(x))
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_INM(x, m)      \
        in_dword_masked(HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR(x), m)
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_OUT(x, v)      \
        out_dword(HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR(x),v)
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_ADDR(x),m,v,HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_IN(x))
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_UCONTROLLER_GP_INT_WEIGHT_BMSK                         0xf
#define HWIO_IC_INT_WEIGHT_UCONTROLLER_ENG_UCONTROLLER_GP_INT_WEIGHT_SHFT                         0x0

#define HWIO_GSI_MANAGER_EE_QOS_n_ADDR(base,n)                                             ((base) + 0x00000300 + 0x4 * (n))
#define HWIO_GSI_MANAGER_EE_QOS_n_OFFS(base,n)                                             (0x00000300 + 0x4 * (n))
#define HWIO_GSI_MANAGER_EE_QOS_n_RMSK                                                       0x1f1f03
#define HWIO_GSI_MANAGER_EE_QOS_n_MAXn                                                             14
#define HWIO_GSI_MANAGER_EE_QOS_n_INI(base,n)        \
        in_dword_masked(HWIO_GSI_MANAGER_EE_QOS_n_ADDR(base,n), HWIO_GSI_MANAGER_EE_QOS_n_RMSK)
#define HWIO_GSI_MANAGER_EE_QOS_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_MANAGER_EE_QOS_n_ADDR(base,n), mask)
#define HWIO_GSI_MANAGER_EE_QOS_n_OUTI(base,n,val)    \
        out_dword(HWIO_GSI_MANAGER_EE_QOS_n_ADDR(base,n),val)
#define HWIO_GSI_MANAGER_EE_QOS_n_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_GSI_MANAGER_EE_QOS_n_ADDR(base,n),mask,val,HWIO_GSI_MANAGER_EE_QOS_n_INI(base,n))
#define HWIO_GSI_MANAGER_EE_QOS_n_MAX_EV_ALLOC_BMSK                                          0x1f0000
#define HWIO_GSI_MANAGER_EE_QOS_n_MAX_EV_ALLOC_SHFT                                              0x10
#define HWIO_GSI_MANAGER_EE_QOS_n_MAX_CH_ALLOC_BMSK                                            0x1f00
#define HWIO_GSI_MANAGER_EE_QOS_n_MAX_CH_ALLOC_SHFT                                               0x8
#define HWIO_GSI_MANAGER_EE_QOS_n_EE_PRIO_BMSK                                                    0x3
#define HWIO_GSI_MANAGER_EE_QOS_n_EE_PRIO_SHFT                                                    0x0

#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR(x)                                      ((x) + 0x00000200)
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_OFFS                                         (0x00000200)
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_RMSK                                             0xffff
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_SHRAM_PTR_BMSK                                   0xffff
#define HWIO_GSI_SHRAM_PTR_CH_CNTXT_BASE_ADDR_SHRAM_PTR_SHFT                                      0x0

#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR(x)                                      ((x) + 0x00000204)
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_OFFS                                         (0x00000204)
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_RMSK                                             0xffff
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_SHRAM_PTR_BMSK                                   0xffff
#define HWIO_GSI_SHRAM_PTR_EV_CNTXT_BASE_ADDR_SHRAM_PTR_SHFT                                      0x0

#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR(x)                                    ((x) + 0x00000208)
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_OFFS                                       (0x00000208)
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_RMSK                                           0xffff
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_SHRAM_PTR_BMSK                                 0xffff
#define HWIO_GSI_SHRAM_PTR_RE_STORAGE_BASE_ADDR_SHRAM_PTR_SHFT                                    0x0

#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR(x)                                    ((x) + 0x0000020c)
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_OFFS                                       (0x0000020c)
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_RMSK                                           0xffff
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_SHRAM_PTR_BMSK                                 0xffff
#define HWIO_GSI_SHRAM_PTR_RE_ESC_BUF_BASE_ADDR_SHRAM_PTR_SHFT                                    0x0

#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR(x)                                     ((x) + 0x00000240)
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_OFFS                                        (0x00000240)
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_RMSK                                            0xffff
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_SHRAM_PTR_BMSK                                  0xffff
#define HWIO_GSI_SHRAM_PTR_EE_SCRACH_BASE_ADDR_SHRAM_PTR_SHFT                                     0x0

#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR(x)                                    ((x) + 0x00000244)
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_OFFS                                       (0x00000244)
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_RMSK                                           0xffff
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_SHRAM_PTR_BMSK                                 0xffff
#define HWIO_GSI_SHRAM_PTR_FUNC_STACK_BASE_ADDR_SHRAM_PTR_SHFT                                    0x0

#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR(x)                                   ((x) + 0x00000248)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_OFFS                                      (0x00000248)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_RMSK                                          0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_SHRAM_PTR_BMSK                                0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH_BASE_ADDR_SHRAM_PTR_SHFT                                   0x0

#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR(x)                                  ((x) + 0x0000024c)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_OFFS                                     (0x0000024c)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_RMSK                                         0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_SHRAM_PTR_BMSK                               0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH1_BASE_ADDR_SHRAM_PTR_SHFT                                  0x0

#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR(x)                                  ((x) + 0x00000250)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_OFFS                                     (0x00000250)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_RMSK                                         0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_SHRAM_PTR_BMSK                               0xffff
#define HWIO_GSI_SHRAM_PTR_MCS_SCRATCH2_BASE_ADDR_SHRAM_PTR_SHFT                                  0x0

#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR(x)                             ((x) + 0x00000254)
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_OFFS                                (0x00000254)
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_RMSK                                    0xffff
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_BMSK                          0xffff
#define HWIO_GSI_SHRAM_PTR_CH_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_SHFT                             0x0

#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR(x)                             ((x) + 0x00000258)
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_OFFS                                (0x00000258)
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_RMSK                                    0xffff
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_BMSK                          0xffff
#define HWIO_GSI_SHRAM_PTR_EV_VP_TRANS_TABLE_BASE_ADDR_SHRAM_PTR_SHFT                             0x0

#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR(x)                                ((x) + 0x0000025c)
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_OFFS                                   (0x0000025c)
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_RMSK                                       0xffff
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_SHRAM_PTR_BMSK                             0xffff
#define HWIO_GSI_SHRAM_PTR_USER_INFO_DATA_BASE_ADDR_SHRAM_PTR_SHFT                                0x0

#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR(x)                                   ((x) + 0x00000260)
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_OFFS                                      (0x00000260)
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_RMSK                                          0xffff
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_SHRAM_PTR_BMSK                                0xffff
#define HWIO_GSI_SHRAM_PTR_EE_CMD_FIFO_BASE_ADDR_SHRAM_PTR_SHFT                                   0x0

#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR(x)                                   ((x) + 0x00000264)
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_OFFS                                      (0x00000264)
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_RMSK                                          0xffff
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_IN(x)      \
        in_dword(HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR(x))
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR(x), m)
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_OUT(x, v)      \
        out_dword(HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR(x),v)
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_ADDR(x),m,v,HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_IN(x))
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_SHRAM_PTR_BMSK                                0xffff
#define HWIO_GSI_SHRAM_PTR_CH_CMD_FIFO_BASE_ADDR_SHRAM_PTR_SHFT                                   0x0

#define HWIO_GSI_IRAM_PTR_CH_CMD_ADDR(x)                                                   ((x) + 0x00000400)
#define HWIO_GSI_IRAM_PTR_CH_CMD_OFFS                                                      (0x00000400)
#define HWIO_GSI_IRAM_PTR_CH_CMD_RMSK                                                           0xfff
#define HWIO_GSI_IRAM_PTR_CH_CMD_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_CH_CMD_ADDR(x))
#define HWIO_GSI_IRAM_PTR_CH_CMD_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_CH_CMD_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_CH_CMD_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_CH_CMD_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_CH_CMD_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_CH_CMD_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_CH_CMD_IN(x))
#define HWIO_GSI_IRAM_PTR_CH_CMD_IRAM_PTR_BMSK                                                  0xfff
#define HWIO_GSI_IRAM_PTR_CH_CMD_IRAM_PTR_SHFT                                                    0x0

#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR(x)                                           ((x) + 0x00000404)
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_OFFS                                              (0x00000404)
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_RMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR(x))
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_IN(x))
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_IRAM_PTR_BMSK                                          0xfff
#define HWIO_GSI_IRAM_PTR_EE_GENERIC_CMD_IRAM_PTR_SHFT                                            0x0

#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR(x)                                          ((x) + 0x00000408)
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_OFFS                                             (0x00000408)
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_RMSK                                                  0xfff
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR(x))
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IN(x))
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IRAM_PTR_BMSK                                         0xfff
#define HWIO_GSI_IRAM_PTR_TLV_CH_NOT_FULL_IRAM_PTR_SHFT                                           0x0

#define HWIO_GSI_IRAM_PTR_CH_DB_ADDR(x)                                                    ((x) + 0x00000418)
#define HWIO_GSI_IRAM_PTR_CH_DB_OFFS                                                       (0x00000418)
#define HWIO_GSI_IRAM_PTR_CH_DB_RMSK                                                            0xfff
#define HWIO_GSI_IRAM_PTR_CH_DB_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_CH_DB_ADDR(x))
#define HWIO_GSI_IRAM_PTR_CH_DB_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_CH_DB_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_CH_DB_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_CH_DB_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_CH_DB_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_CH_DB_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_CH_DB_IN(x))
#define HWIO_GSI_IRAM_PTR_CH_DB_IRAM_PTR_BMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_CH_DB_IRAM_PTR_SHFT                                                     0x0

#define HWIO_GSI_IRAM_PTR_EV_DB_ADDR(x)                                                    ((x) + 0x0000041c)
#define HWIO_GSI_IRAM_PTR_EV_DB_OFFS                                                       (0x0000041c)
#define HWIO_GSI_IRAM_PTR_EV_DB_RMSK                                                            0xfff
#define HWIO_GSI_IRAM_PTR_EV_DB_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_EV_DB_ADDR(x))
#define HWIO_GSI_IRAM_PTR_EV_DB_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_EV_DB_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_EV_DB_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_EV_DB_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_EV_DB_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_EV_DB_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_EV_DB_IN(x))
#define HWIO_GSI_IRAM_PTR_EV_DB_IRAM_PTR_BMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_EV_DB_IRAM_PTR_SHFT                                                     0x0

#define HWIO_GSI_IRAM_PTR_NEW_RE_ADDR(x)                                                   ((x) + 0x00000420)
#define HWIO_GSI_IRAM_PTR_NEW_RE_OFFS                                                      (0x00000420)
#define HWIO_GSI_IRAM_PTR_NEW_RE_RMSK                                                           0xfff
#define HWIO_GSI_IRAM_PTR_NEW_RE_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_NEW_RE_ADDR(x))
#define HWIO_GSI_IRAM_PTR_NEW_RE_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_NEW_RE_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_NEW_RE_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_NEW_RE_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_NEW_RE_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_NEW_RE_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_NEW_RE_IN(x))
#define HWIO_GSI_IRAM_PTR_NEW_RE_IRAM_PTR_BMSK                                                  0xfff
#define HWIO_GSI_IRAM_PTR_NEW_RE_IRAM_PTR_SHFT                                                    0x0

#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_ADDR(x)                                              ((x) + 0x00000424)
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_OFFS                                                 (0x00000424)
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_RMSK                                                      0xfff
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_CH_DIS_COMP_ADDR(x))
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_CH_DIS_COMP_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_CH_DIS_COMP_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_CH_DIS_COMP_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_CH_DIS_COMP_IN(x))
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_IRAM_PTR_BMSK                                             0xfff
#define HWIO_GSI_IRAM_PTR_CH_DIS_COMP_IRAM_PTR_SHFT                                               0x0

#define HWIO_GSI_IRAM_PTR_CH_EMPTY_ADDR(x)                                                 ((x) + 0x00000428)
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_OFFS                                                    (0x00000428)
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_RMSK                                                         0xfff
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_CH_EMPTY_ADDR(x))
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_CH_EMPTY_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_CH_EMPTY_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_CH_EMPTY_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_CH_EMPTY_IN(x))
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_IRAM_PTR_BMSK                                                0xfff
#define HWIO_GSI_IRAM_PTR_CH_EMPTY_IRAM_PTR_SHFT                                                  0x0

#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR(x)                                           ((x) + 0x0000042c)
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_OFFS                                              (0x0000042c)
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_RMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR(x))
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_IN(x))
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_IRAM_PTR_BMSK                                          0xfff
#define HWIO_GSI_IRAM_PTR_EVENT_GEN_COMP_IRAM_PTR_SHFT                                            0x0

#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR(x)                                       ((x) + 0x00000430)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_OFFS                                          (0x00000430)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_RMSK                                               0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IN(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IRAM_PTR_BMSK                                      0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_0_IRAM_PTR_SHFT                                        0x0

#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR(x)                                       ((x) + 0x00000434)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_OFFS                                          (0x00000434)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_RMSK                                               0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IN(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IRAM_PTR_BMSK                                      0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_2_IRAM_PTR_SHFT                                        0x0

#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR(x)                                       ((x) + 0x00000438)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_OFFS                                          (0x00000438)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_RMSK                                               0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IN(x))
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IRAM_PTR_BMSK                                      0xfff
#define HWIO_GSI_IRAM_PTR_PERIPH_IF_TLV_IN_1_IRAM_PTR_SHFT                                        0x0

#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR(x)                                            ((x) + 0x0000043c)
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_OFFS                                               (0x0000043c)
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_RMSK                                                    0xfff
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR(x))
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_IN(x))
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_IRAM_PTR_BMSK                                           0xfff
#define HWIO_GSI_IRAM_PTR_TIMER_EXPIRED_IRAM_PTR_SHFT                                             0x0

#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR(x)                                           ((x) + 0x00000440)
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_OFFS                                              (0x00000440)
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_RMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR(x))
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_IN(x))
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_IRAM_PTR_BMSK                                          0xfff
#define HWIO_GSI_IRAM_PTR_WRITE_ENG_COMP_IRAM_PTR_SHFT                                            0x0

#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_ADDR(x)                                            ((x) + 0x00000444)
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_OFFS                                               (0x00000444)
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_RMSK                                                    0xfff
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_READ_ENG_COMP_ADDR(x))
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_READ_ENG_COMP_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_READ_ENG_COMP_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_READ_ENG_COMP_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_READ_ENG_COMP_IN(x))
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_IRAM_PTR_BMSK                                           0xfff
#define HWIO_GSI_IRAM_PTR_READ_ENG_COMP_IRAM_PTR_SHFT                                             0x0

#define HWIO_GSI_IRAM_PTR_UC_GP_INT_ADDR(x)                                                ((x) + 0x00000448)
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_OFFS                                                   (0x00000448)
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_RMSK                                                        0xfff
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_UC_GP_INT_ADDR(x))
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_UC_GP_INT_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_UC_GP_INT_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_UC_GP_INT_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_UC_GP_INT_IN(x))
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_IRAM_PTR_BMSK                                               0xfff
#define HWIO_GSI_IRAM_PTR_UC_GP_INT_IRAM_PTR_SHFT                                                 0x0

#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR(x)                                           ((x) + 0x0000044c)
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_OFFS                                              (0x0000044c)
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_RMSK                                                   0xfff
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_IN(x)      \
        in_dword(HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR(x))
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_INM(x, m)      \
        in_dword_masked(HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR(x), m)
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_OUT(x, v)      \
        out_dword(HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR(x),v)
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_ADDR(x),m,v,HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_IN(x))
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_IRAM_PTR_BMSK                                          0xfff
#define HWIO_GSI_IRAM_PTR_INT_MOD_STOPED_IRAM_PTR_SHFT                                            0x0

#define HWIO_GSI_INST_RAM_n_ADDR(base,n)                                                   ((base) + 0x00057000 + 0x4 * (n))
#define HWIO_GSI_INST_RAM_n_OFFS(base,n)                                                   (0x00057000 + 0x4 * (n))
#define HWIO_GSI_INST_RAM_n_RMSK                                                           0xffffffff
#define HWIO_GSI_INST_RAM_n_MAXn                                                                 4095
#define HWIO_GSI_INST_RAM_n_INI(base,n)        \
        in_dword_masked(HWIO_GSI_INST_RAM_n_ADDR(base,n), HWIO_GSI_INST_RAM_n_RMSK)
#define HWIO_GSI_INST_RAM_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_INST_RAM_n_ADDR(base,n), mask)
#define HWIO_GSI_INST_RAM_n_OUTI(base,n,val)    \
        out_dword(HWIO_GSI_INST_RAM_n_ADDR(base,n),val)
#define HWIO_GSI_INST_RAM_n_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_GSI_INST_RAM_n_ADDR(base,n),mask,val,HWIO_GSI_INST_RAM_n_INI(base,n))
#define HWIO_GSI_INST_RAM_n_INST_BYTE_3_BMSK                                               0xff000000
#define HWIO_GSI_INST_RAM_n_INST_BYTE_3_SHFT                                                     0x18
#define HWIO_GSI_INST_RAM_n_INST_BYTE_2_BMSK                                                 0xff0000
#define HWIO_GSI_INST_RAM_n_INST_BYTE_2_SHFT                                                     0x10
#define HWIO_GSI_INST_RAM_n_INST_BYTE_1_BMSK                                                   0xff00
#define HWIO_GSI_INST_RAM_n_INST_BYTE_1_SHFT                                                      0x8
#define HWIO_GSI_INST_RAM_n_INST_BYTE_0_BMSK                                                     0xff
#define HWIO_GSI_INST_RAM_n_INST_BYTE_0_SHFT                                                      0x0

#define HWIO_GSI_SHRAM_n_ADDR(base,n)                                                      ((base) + 0x00002000 + 0x4 * (n))
#define HWIO_GSI_SHRAM_n_OFFS(base,n)                                                      (0x00002000 + 0x4 * (n))
#define HWIO_GSI_SHRAM_n_RMSK                                                              0xffffffff
#define HWIO_GSI_SHRAM_n_MAXn                                                                    1023
#define HWIO_GSI_SHRAM_n_INI(base,n)        \
        in_dword_masked(HWIO_GSI_SHRAM_n_ADDR(base,n), HWIO_GSI_SHRAM_n_RMSK)
#define HWIO_GSI_SHRAM_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_SHRAM_n_ADDR(base,n), mask)
#define HWIO_GSI_SHRAM_n_OUTI(base,n,val)    \
        out_dword(HWIO_GSI_SHRAM_n_ADDR(base,n),val)
#define HWIO_GSI_SHRAM_n_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_GSI_SHRAM_n_ADDR(base,n),mask,val,HWIO_GSI_SHRAM_n_INI(base,n))
#define HWIO_GSI_SHRAM_n_SHRAM_BMSK                                                        0xffffffff
#define HWIO_GSI_SHRAM_n_SHRAM_SHFT                                                               0x0

#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(base,n,k)                                     ((base) + 0x00003800 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_OFFS(base,n,k)                                     (0x00003800 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_RMSK                                                     0x3f
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_MAXn                                                       14
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_MAXk                                                        1
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_INI2(base,n,k)        \
        in_dword_masked(HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(base,n,k), HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_RMSK)
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(base,n,k), mask)
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_OUTI2(base,n,k,val)    \
        out_dword(HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(base,n,k),val)
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_ADDR(base,n,k),mask,val,HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_INI2(base,n,k))
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_VALID_BMSK                                               0x20
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_VALID_SHFT                                                0x5
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_PHY_CH_BMSK                                              0x1f
#define HWIO_GSI_MAP_EE_n_CH_k_VP_TABLE_PHY_CH_SHFT                                               0x0

#define HWIO_GSI_TEST_BUS_SEL_ADDR(x)                                                      ((x) + 0x00001000)
#define HWIO_GSI_TEST_BUS_SEL_OFFS                                                         (0x00001000)
#define HWIO_GSI_TEST_BUS_SEL_RMSK                                                            0xf00ff
#define HWIO_GSI_TEST_BUS_SEL_IN(x)      \
        in_dword(HWIO_GSI_TEST_BUS_SEL_ADDR(x))
#define HWIO_GSI_TEST_BUS_SEL_INM(x, m)      \
        in_dword_masked(HWIO_GSI_TEST_BUS_SEL_ADDR(x), m)
#define HWIO_GSI_TEST_BUS_SEL_OUT(x, v)      \
        out_dword(HWIO_GSI_TEST_BUS_SEL_ADDR(x),v)
#define HWIO_GSI_TEST_BUS_SEL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_TEST_BUS_SEL_ADDR(x),m,v,HWIO_GSI_TEST_BUS_SEL_IN(x))
#define HWIO_GSI_TEST_BUS_SEL_GSI_HW_EVENTS_SEL_BMSK                                          0xf0000
#define HWIO_GSI_TEST_BUS_SEL_GSI_HW_EVENTS_SEL_SHFT                                             0x10
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_BMSK                                               0xff
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_SHFT                                                0x0
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_ZEROS_FVAL                                          0x0
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_0_FVAL                                          0x1
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_1_FVAL                                          0x2
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_2_FVAL                                          0x3
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_3_FVAL                                          0x4
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_4_FVAL                                          0x5
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_DB_ENG_FVAL                                         0x9
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_0_FVAL                                          0xb
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_1_FVAL                                          0xc
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_2_FVAL                                          0xd
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_3_FVAL                                          0xe
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_4_FVAL                                          0xf
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_5_FVAL                                         0x10
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_6_FVAL                                         0x11
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_7_FVAL                                         0x12
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_0_FVAL                                         0x13
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_1_FVAL                                         0x14
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_2_FVAL                                         0x15
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_3_FVAL                                         0x16
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_4_FVAL                                         0x17
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_EVE_5_FVAL                                         0x18
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IE_0_FVAL                                          0x1b
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IE_1_FVAL                                          0x1c
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IE_2_FVAL                                          0x1d
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_0_FVAL                                          0x1f
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_1_FVAL                                          0x20
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_2_FVAL                                          0x21
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_3_FVAL                                          0x22
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_4_FVAL                                          0x23
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MOQA_0_FVAL                                        0x27
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MOQA_1_FVAL                                        0x28
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MOQA_2_FVAL                                        0x29
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MOQA_3_FVAL                                        0x2a
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_TMR_0_FVAL                                         0x2b
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_TMR_1_FVAL                                         0x2c
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_TMR_2_FVAL                                         0x2d
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_TMR_3_FVAL                                         0x2e
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_RD_WR_0_FVAL                                       0x33
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_RD_WR_1_FVAL                                       0x34
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_RD_WR_2_FVAL                                       0x35
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_RD_WR_3_FVAL                                       0x36
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_CSR_FVAL                                           0x3a
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_SDMA_0_FVAL                                        0x3c
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_SMDA_1_FVAL                                        0x3d
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_CSR_1_FVAL                                         0x3e
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_CSR_2_FVAL                                         0x3f
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_MCS_5_FVAL                                         0x40
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_IC_5_FVAL                                          0x41
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_CSR_3_FVAL                                         0x42
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_TLV_0_FVAL                                         0x43
#define HWIO_GSI_TEST_BUS_SEL_GSI_TESTBUS_SEL_REE_8_FVAL                                         0x44

#define HWIO_GSI_TEST_BUS_REG_ADDR(x)                                                      ((x) + 0x00001008)
#define HWIO_GSI_TEST_BUS_REG_OFFS                                                         (0x00001008)
#define HWIO_GSI_TEST_BUS_REG_RMSK                                                         0xffffffff
#define HWIO_GSI_TEST_BUS_REG_IN(x)      \
        in_dword(HWIO_GSI_TEST_BUS_REG_ADDR(x))
#define HWIO_GSI_TEST_BUS_REG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_TEST_BUS_REG_ADDR(x), m)
#define HWIO_GSI_TEST_BUS_REG_GSI_TESTBUS_REG_BMSK                                         0xffffffff
#define HWIO_GSI_TEST_BUS_REG_GSI_TESTBUS_REG_SHFT                                                0x0

#define HWIO_GSI_DEBUG_BUSY_REG_ADDR(x)                                                    ((x) + 0x00001010)
#define HWIO_GSI_DEBUG_BUSY_REG_OFFS                                                       (0x00001010)
#define HWIO_GSI_DEBUG_BUSY_REG_RMSK                                                           0x1fff
#define HWIO_GSI_DEBUG_BUSY_REG_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_BUSY_REG_ADDR(x))
#define HWIO_GSI_DEBUG_BUSY_REG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_BUSY_REG_ADDR(x), m)
#define HWIO_GSI_DEBUG_BUSY_REG_SDMA_BUSY_BMSK                                                 0x1000
#define HWIO_GSI_DEBUG_BUSY_REG_SDMA_BUSY_SHFT                                                    0xc
#define HWIO_GSI_DEBUG_BUSY_REG_IC_BUSY_BMSK                                                    0x800
#define HWIO_GSI_DEBUG_BUSY_REG_IC_BUSY_SHFT                                                      0xb
#define HWIO_GSI_DEBUG_BUSY_REG_UC_BUSY_BMSK                                                    0x400
#define HWIO_GSI_DEBUG_BUSY_REG_UC_BUSY_SHFT                                                      0xa
#define HWIO_GSI_DEBUG_BUSY_REG_DBG_CNT_BUSY_BMSK                                               0x200
#define HWIO_GSI_DEBUG_BUSY_REG_DBG_CNT_BUSY_SHFT                                                 0x9
#define HWIO_GSI_DEBUG_BUSY_REG_DB_ENG_BUSY_BMSK                                                0x100
#define HWIO_GSI_DEBUG_BUSY_REG_DB_ENG_BUSY_SHFT                                                  0x8
#define HWIO_GSI_DEBUG_BUSY_REG_REE_PWR_CLPS_BUSY_BMSK                                           0x80
#define HWIO_GSI_DEBUG_BUSY_REG_REE_PWR_CLPS_BUSY_SHFT                                            0x7
#define HWIO_GSI_DEBUG_BUSY_REG_INT_ENG_BUSY_BMSK                                                0x40
#define HWIO_GSI_DEBUG_BUSY_REG_INT_ENG_BUSY_SHFT                                                 0x6
#define HWIO_GSI_DEBUG_BUSY_REG_EV_ENG_BUSY_BMSK                                                 0x20
#define HWIO_GSI_DEBUG_BUSY_REG_EV_ENG_BUSY_SHFT                                                  0x5
#define HWIO_GSI_DEBUG_BUSY_REG_RD_WR_BUSY_BMSK                                                  0x10
#define HWIO_GSI_DEBUG_BUSY_REG_RD_WR_BUSY_SHFT                                                   0x4
#define HWIO_GSI_DEBUG_BUSY_REG_TIMER_BUSY_BMSK                                                   0x8
#define HWIO_GSI_DEBUG_BUSY_REG_TIMER_BUSY_SHFT                                                   0x3
#define HWIO_GSI_DEBUG_BUSY_REG_MCS_BUSY_BMSK                                                     0x4
#define HWIO_GSI_DEBUG_BUSY_REG_MCS_BUSY_SHFT                                                     0x2
#define HWIO_GSI_DEBUG_BUSY_REG_REE_BUSY_BMSK                                                     0x2
#define HWIO_GSI_DEBUG_BUSY_REG_REE_BUSY_SHFT                                                     0x1
#define HWIO_GSI_DEBUG_BUSY_REG_CSR_BUSY_BMSK                                                     0x1
#define HWIO_GSI_DEBUG_BUSY_REG_CSR_BUSY_SHFT                                                     0x0

#define HWIO_GSI_DEBUG_EVENT_PENDING_ADDR(x)                                               ((x) + 0x00001014)
#define HWIO_GSI_DEBUG_EVENT_PENDING_OFFS                                                  (0x00001014)
#define HWIO_GSI_DEBUG_EVENT_PENDING_RMSK                                                  0xffffffff
#define HWIO_GSI_DEBUG_EVENT_PENDING_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_EVENT_PENDING_ADDR(x))
#define HWIO_GSI_DEBUG_EVENT_PENDING_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_EVENT_PENDING_ADDR(x), m)
#define HWIO_GSI_DEBUG_EVENT_PENDING_CHID_BIT_MAP_BMSK                                     0xffffffff
#define HWIO_GSI_DEBUG_EVENT_PENDING_CHID_BIT_MAP_SHFT                                            0x0

#define HWIO_GSI_DEBUG_TIMER_PENDING_ADDR(x)                                               ((x) + 0x00001018)
#define HWIO_GSI_DEBUG_TIMER_PENDING_OFFS                                                  (0x00001018)
#define HWIO_GSI_DEBUG_TIMER_PENDING_RMSK                                                  0xffffffff
#define HWIO_GSI_DEBUG_TIMER_PENDING_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_TIMER_PENDING_ADDR(x))
#define HWIO_GSI_DEBUG_TIMER_PENDING_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_TIMER_PENDING_ADDR(x), m)
#define HWIO_GSI_DEBUG_TIMER_PENDING_CHID_BIT_MAP_BMSK                                     0xffffffff
#define HWIO_GSI_DEBUG_TIMER_PENDING_CHID_BIT_MAP_SHFT                                            0x0

#define HWIO_GSI_DEBUG_RD_WR_PENDING_ADDR(x)                                               ((x) + 0x0000101c)
#define HWIO_GSI_DEBUG_RD_WR_PENDING_OFFS                                                  (0x0000101c)
#define HWIO_GSI_DEBUG_RD_WR_PENDING_RMSK                                                  0xffffffff
#define HWIO_GSI_DEBUG_RD_WR_PENDING_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_RD_WR_PENDING_ADDR(x))
#define HWIO_GSI_DEBUG_RD_WR_PENDING_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_RD_WR_PENDING_ADDR(x), m)
#define HWIO_GSI_DEBUG_RD_WR_PENDING_CHID_BIT_MAP_BMSK                                     0xffffffff
#define HWIO_GSI_DEBUG_RD_WR_PENDING_CHID_BIT_MAP_SHFT                                            0x0

#define HWIO_GSI_DEBUG_COUNTER_CFGn_ADDR(base,n)                                           ((base) + 0x00001200 + 0x4 * (n))
#define HWIO_GSI_DEBUG_COUNTER_CFGn_OFFS(base,n)                                           (0x00001200 + 0x4 * (n))
#define HWIO_GSI_DEBUG_COUNTER_CFGn_RMSK                                                     0x1fffff
#define HWIO_GSI_DEBUG_COUNTER_CFGn_MAXn                                                            7
#define HWIO_GSI_DEBUG_COUNTER_CFGn_INI(base,n)        \
        in_dword_masked(HWIO_GSI_DEBUG_COUNTER_CFGn_ADDR(base,n), HWIO_GSI_DEBUG_COUNTER_CFGn_RMSK)
#define HWIO_GSI_DEBUG_COUNTER_CFGn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_COUNTER_CFGn_ADDR(base,n), mask)
#define HWIO_GSI_DEBUG_COUNTER_CFGn_OUTI(base,n,val)    \
        out_dword(HWIO_GSI_DEBUG_COUNTER_CFGn_ADDR(base,n),val)
#define HWIO_GSI_DEBUG_COUNTER_CFGn_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_GSI_DEBUG_COUNTER_CFGn_ADDR(base,n),mask,val,HWIO_GSI_DEBUG_COUNTER_CFGn_INI(base,n))
#define HWIO_GSI_DEBUG_COUNTER_CFGn_CHAIN_BMSK                                               0x100000
#define HWIO_GSI_DEBUG_COUNTER_CFGn_CHAIN_SHFT                                                   0x14
#define HWIO_GSI_DEBUG_COUNTER_CFGn_VIRTUAL_CHNL_BMSK                                         0xff000
#define HWIO_GSI_DEBUG_COUNTER_CFGn_VIRTUAL_CHNL_SHFT                                             0xc
#define HWIO_GSI_DEBUG_COUNTER_CFGn_EE_BMSK                                                     0xf00
#define HWIO_GSI_DEBUG_COUNTER_CFGn_EE_SHFT                                                       0x8
#define HWIO_GSI_DEBUG_COUNTER_CFGn_EVNT_TYPE_BMSK                                               0xf8
#define HWIO_GSI_DEBUG_COUNTER_CFGn_EVNT_TYPE_SHFT                                                0x3
#define HWIO_GSI_DEBUG_COUNTER_CFGn_CLR_AT_READ_BMSK                                              0x4
#define HWIO_GSI_DEBUG_COUNTER_CFGn_CLR_AT_READ_SHFT                                              0x2
#define HWIO_GSI_DEBUG_COUNTER_CFGn_STOP_AT_WRAP_ARND_BMSK                                        0x2
#define HWIO_GSI_DEBUG_COUNTER_CFGn_STOP_AT_WRAP_ARND_SHFT                                        0x1
#define HWIO_GSI_DEBUG_COUNTER_CFGn_ENABLE_BMSK                                                   0x1
#define HWIO_GSI_DEBUG_COUNTER_CFGn_ENABLE_SHFT                                                   0x0

#define HWIO_GSI_DEBUG_COUNTERn_ADDR(base,n)                                               ((base) + 0x00001240 + 0x4 * (n))
#define HWIO_GSI_DEBUG_COUNTERn_OFFS(base,n)                                               (0x00001240 + 0x4 * (n))
#define HWIO_GSI_DEBUG_COUNTERn_RMSK                                                           0xffff
#define HWIO_GSI_DEBUG_COUNTERn_MAXn                                                                7
#define HWIO_GSI_DEBUG_COUNTERn_INI(base,n)        \
        in_dword_masked(HWIO_GSI_DEBUG_COUNTERn_ADDR(base,n), HWIO_GSI_DEBUG_COUNTERn_RMSK)
#define HWIO_GSI_DEBUG_COUNTERn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_COUNTERn_ADDR(base,n), mask)
#define HWIO_GSI_DEBUG_COUNTERn_COUNTER_VALUE_BMSK                                             0xffff
#define HWIO_GSI_DEBUG_COUNTERn_COUNTER_VALUE_SHFT                                                0x0

#define HWIO_GSI_DEBUG_PC_FROM_SW_ADDR(x)                                                  ((x) + 0x00001040)
#define HWIO_GSI_DEBUG_PC_FROM_SW_OFFS                                                     (0x00001040)
#define HWIO_GSI_DEBUG_PC_FROM_SW_RMSK                                                          0xfff
#define HWIO_GSI_DEBUG_PC_FROM_SW_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_PC_FROM_SW_ADDR(x))
#define HWIO_GSI_DEBUG_PC_FROM_SW_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_PC_FROM_SW_ADDR(x), m)
#define HWIO_GSI_DEBUG_PC_FROM_SW_OUT(x, v)      \
        out_dword(HWIO_GSI_DEBUG_PC_FROM_SW_ADDR(x),v)
#define HWIO_GSI_DEBUG_PC_FROM_SW_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_DEBUG_PC_FROM_SW_ADDR(x),m,v,HWIO_GSI_DEBUG_PC_FROM_SW_IN(x))
#define HWIO_GSI_DEBUG_PC_FROM_SW_IRAM_PTR_BMSK                                                 0xfff
#define HWIO_GSI_DEBUG_PC_FROM_SW_IRAM_PTR_SHFT                                                   0x0

#define HWIO_GSI_DEBUG_SW_STALL_ADDR(x)                                                    ((x) + 0x00001044)
#define HWIO_GSI_DEBUG_SW_STALL_OFFS                                                       (0x00001044)
#define HWIO_GSI_DEBUG_SW_STALL_RMSK                                                              0x1
#define HWIO_GSI_DEBUG_SW_STALL_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_SW_STALL_ADDR(x))
#define HWIO_GSI_DEBUG_SW_STALL_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_SW_STALL_ADDR(x), m)
#define HWIO_GSI_DEBUG_SW_STALL_OUT(x, v)      \
        out_dword(HWIO_GSI_DEBUG_SW_STALL_ADDR(x),v)
#define HWIO_GSI_DEBUG_SW_STALL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_DEBUG_SW_STALL_ADDR(x),m,v,HWIO_GSI_DEBUG_SW_STALL_IN(x))
#define HWIO_GSI_DEBUG_SW_STALL_MCS_STALL_BMSK                                                    0x1
#define HWIO_GSI_DEBUG_SW_STALL_MCS_STALL_SHFT                                                    0x0

#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_ADDR(x)                                                ((x) + 0x00001048)
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_OFFS                                                   (0x00001048)
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_RMSK                                                        0xfff
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_PC_FOR_DEBUG_ADDR(x))
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_PC_FOR_DEBUG_ADDR(x), m)
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_IRAM_PTR_BMSK                                               0xfff
#define HWIO_GSI_DEBUG_PC_FOR_DEBUG_IRAM_PTR_SHFT                                                 0x0

#define HWIO_GSI_DEBUG_QSB_LOG_SEL_ADDR(x)                                                 ((x) + 0x00001050)
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_OFFS                                                    (0x00001050)
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_RMSK                                                      0xffff01
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_QSB_LOG_SEL_ADDR(x))
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_SEL_ADDR(x), m)
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_OUT(x, v)      \
        out_dword(HWIO_GSI_DEBUG_QSB_LOG_SEL_ADDR(x),v)
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_DEBUG_QSB_LOG_SEL_ADDR(x),m,v,HWIO_GSI_DEBUG_QSB_LOG_SEL_IN(x))
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_MID_BMSK                                              0xff0000
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_MID_SHFT                                                  0x10
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_TID_BMSK                                                0xff00
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_TID_SHFT                                                   0x8
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_WRITE_BMSK                                                 0x1
#define HWIO_GSI_DEBUG_QSB_LOG_SEL_SEL_WRITE_SHFT                                                 0x0

#define HWIO_GSI_DEBUG_QSB_LOG_CLR_ADDR(x)                                                 ((x) + 0x00001058)
#define HWIO_GSI_DEBUG_QSB_LOG_CLR_OFFS                                                    (0x00001058)
#define HWIO_GSI_DEBUG_QSB_LOG_CLR_RMSK                                                           0x1
#define HWIO_GSI_DEBUG_QSB_LOG_CLR_OUT(x, v)      \
        out_dword(HWIO_GSI_DEBUG_QSB_LOG_CLR_ADDR(x),v)
#define HWIO_GSI_DEBUG_QSB_LOG_CLR_LOG_CLR_BMSK                                                   0x1
#define HWIO_GSI_DEBUG_QSB_LOG_CLR_LOG_CLR_SHFT                                                   0x0

#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR(x)                                         ((x) + 0x00001060)
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_OFFS                                            (0x00001060)
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_RMSK                                             0x1ffff01
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR(x))
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ADDR(x), m)
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_SAVED_BMSK                                   0x1000000
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_SAVED_SHFT                                        0x18
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_MID_BMSK                                      0xff0000
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_MID_SHFT                                          0x10
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_TID_BMSK                                        0xff00
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_TID_SHFT                                           0x8
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_WRITE_BMSK                                         0x1
#define HWIO_GSI_DEBUG_QSB_LOG_ERR_TRNS_ID_ERR_WRITE_SHFT                                         0x0

#define HWIO_GSI_DEBUG_QSB_LOG_0_ADDR(x)                                                   ((x) + 0x00001064)
#define HWIO_GSI_DEBUG_QSB_LOG_0_OFFS                                                      (0x00001064)
#define HWIO_GSI_DEBUG_QSB_LOG_0_RMSK                                                      0xffffffff
#define HWIO_GSI_DEBUG_QSB_LOG_0_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_QSB_LOG_0_ADDR(x))
#define HWIO_GSI_DEBUG_QSB_LOG_0_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_0_ADDR(x), m)
#define HWIO_GSI_DEBUG_QSB_LOG_0_ADDR_31_0_BMSK                                            0xffffffff
#define HWIO_GSI_DEBUG_QSB_LOG_0_ADDR_31_0_SHFT                                                   0x0

#define HWIO_GSI_DEBUG_QSB_LOG_1_ADDR(x)                                                   ((x) + 0x00001068)
#define HWIO_GSI_DEBUG_QSB_LOG_1_OFFS                                                      (0x00001068)
#define HWIO_GSI_DEBUG_QSB_LOG_1_RMSK                                                      0xfff7ffff
#define HWIO_GSI_DEBUG_QSB_LOG_1_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_QSB_LOG_1_ADDR(x))
#define HWIO_GSI_DEBUG_QSB_LOG_1_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_1_ADDR(x), m)
#define HWIO_GSI_DEBUG_QSB_LOG_1_AREQPRIORITY_BMSK                                         0xf0000000
#define HWIO_GSI_DEBUG_QSB_LOG_1_AREQPRIORITY_SHFT                                               0x1c
#define HWIO_GSI_DEBUG_QSB_LOG_1_ASIZE_BMSK                                                 0xf000000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ASIZE_SHFT                                                      0x18
#define HWIO_GSI_DEBUG_QSB_LOG_1_ALEN_BMSK                                                   0xf00000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ALEN_SHFT                                                       0x14
#define HWIO_GSI_DEBUG_QSB_LOG_1_AOOOWR_BMSK                                                  0x40000
#define HWIO_GSI_DEBUG_QSB_LOG_1_AOOOWR_SHFT                                                     0x12
#define HWIO_GSI_DEBUG_QSB_LOG_1_AOOORD_BMSK                                                  0x20000
#define HWIO_GSI_DEBUG_QSB_LOG_1_AOOORD_SHFT                                                     0x11
#define HWIO_GSI_DEBUG_QSB_LOG_1_ATRANSIENT_BMSK                                              0x10000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ATRANSIENT_SHFT                                                 0x10
#define HWIO_GSI_DEBUG_QSB_LOG_1_ACACHEABLE_BMSK                                               0x8000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ACACHEABLE_SHFT                                                  0xf
#define HWIO_GSI_DEBUG_QSB_LOG_1_ASHARED_BMSK                                                  0x4000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ASHARED_SHFT                                                     0xe
#define HWIO_GSI_DEBUG_QSB_LOG_1_ANOALLOCATE_BMSK                                              0x2000
#define HWIO_GSI_DEBUG_QSB_LOG_1_ANOALLOCATE_SHFT                                                 0xd
#define HWIO_GSI_DEBUG_QSB_LOG_1_AINNERSHARED_BMSK                                             0x1000
#define HWIO_GSI_DEBUG_QSB_LOG_1_AINNERSHARED_SHFT                                                0xc
#define HWIO_GSI_DEBUG_QSB_LOG_1_ADDR_43_32_BMSK                                                0xfff
#define HWIO_GSI_DEBUG_QSB_LOG_1_ADDR_43_32_SHFT                                                  0x0

#define HWIO_GSI_DEBUG_QSB_LOG_2_ADDR(x)                                                   ((x) + 0x0000106c)
#define HWIO_GSI_DEBUG_QSB_LOG_2_OFFS                                                      (0x0000106c)
#define HWIO_GSI_DEBUG_QSB_LOG_2_RMSK                                                          0xffff
#define HWIO_GSI_DEBUG_QSB_LOG_2_IN(x)      \
        in_dword(HWIO_GSI_DEBUG_QSB_LOG_2_ADDR(x))
#define HWIO_GSI_DEBUG_QSB_LOG_2_INM(x, m)      \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_2_ADDR(x), m)
#define HWIO_GSI_DEBUG_QSB_LOG_2_AMEMTYPE_BMSK                                                 0xf000
#define HWIO_GSI_DEBUG_QSB_LOG_2_AMEMTYPE_SHFT                                                    0xc
#define HWIO_GSI_DEBUG_QSB_LOG_2_AMMUSID_BMSK                                                   0xfff
#define HWIO_GSI_DEBUG_QSB_LOG_2_AMMUSID_SHFT                                                     0x0

#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(base,n)                                  ((base) + 0x00001070 + 0x4 * (n))
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_OFFS(base,n)                                  (0x00001070 + 0x4 * (n))
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_RMSK                                          0xffffffff
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MAXn                                                   3
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_INI(base,n)        \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(base,n), HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_RMSK)
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR(base,n), mask)
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MID_BMSK                                      0xf8000000
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_MID_SHFT                                            0x1b
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_TID_BMSK                                       0x7c00000
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_TID_SHFT                                            0x16
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_WRITE_BMSK                                      0x200000
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_WRITE_SHFT                                          0x15
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR_20_0_BMSK                                  0x1fffff
#define HWIO_GSI_DEBUG_QSB_LOG_LAST_MISC_IDn_ADDR_20_0_SHFT                                       0x0

#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_ADDR(base,n)                                          ((base) + 0x00001080 + 0x4 * (n))
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_OFFS(base,n)                                          (0x00001080 + 0x4 * (n))
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_RMSK                                                  0xffffffff
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_MAXn                                                          31
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_OUTI(base,n,val)    \
        out_dword(HWIO_GSI_DEBUG_SW_RF_n_WRITE_ADDR(base,n),val)
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_DATA_IN_BMSK                                          0xffffffff
#define HWIO_GSI_DEBUG_SW_RF_n_WRITE_DATA_IN_SHFT                                                 0x0

#define HWIO_GSI_DEBUG_SW_RF_n_READ_ADDR(base,n)                                           ((base) + 0x00001100 + 0x4 * (n))
#define HWIO_GSI_DEBUG_SW_RF_n_READ_OFFS(base,n)                                           (0x00001100 + 0x4 * (n))
#define HWIO_GSI_DEBUG_SW_RF_n_READ_RMSK                                                   0xffffffff
#define HWIO_GSI_DEBUG_SW_RF_n_READ_MAXn                                                           31
#define HWIO_GSI_DEBUG_SW_RF_n_READ_INI(base,n)        \
        in_dword_masked(HWIO_GSI_DEBUG_SW_RF_n_READ_ADDR(base,n), HWIO_GSI_DEBUG_SW_RF_n_READ_RMSK)
#define HWIO_GSI_DEBUG_SW_RF_n_READ_INMI(base,n,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_SW_RF_n_READ_ADDR(base,n), mask)
#define HWIO_GSI_DEBUG_SW_RF_n_READ_RF_REG_BMSK                                            0xffffffff
#define HWIO_GSI_DEBUG_SW_RF_n_READ_RF_REG_SHFT                                                   0x0

#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(base,n,k)                                   ((base) + 0x00001400 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_OFFS(base,n,k)                                   (0x00001400 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_RMSK                                                   0x3f
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_MAXn                                                      3
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_MAXk                                                      1
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_INI2(base,n,k)        \
        in_dword_masked(HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(base,n,k), HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_RMSK)
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_ADDR(base,n,k), mask)
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_VALID_BMSK                                             0x20
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_VALID_SHFT                                              0x5
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_PHY_CH_BMSK                                            0x1f
#define HWIO_GSI_DEBUG_EE_n_CH_k_VP_TABLE_PHY_CH_SHFT                                             0x0

#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(base,n,k)                                   ((base) + 0x00001600 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_OFFS(base,n,k)                                   (0x00001600 + 0x80 * (n) + 0x4 * (k))
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_RMSK                                                   0x3f
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_MAXn                                                      3
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_MAXk                                                      0
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_INI2(base,n,k)        \
        in_dword_masked(HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(base,n,k), HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_RMSK)
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_ADDR(base,n,k), mask)
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_VALID_BMSK                                             0x20
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_VALID_SHFT                                              0x5
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_PHY_EV_CH_BMSK                                         0x1f
#define HWIO_GSI_DEBUG_EE_n_EV_k_VP_TABLE_PHY_EV_CH_SHFT                                          0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_0_ADDR(base,n,k)                                          ((base) + 0x0001b000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_OFFS(base,n,k)                                          (0x0001b000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_RMSK                                                    0xfff7ffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_0_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_0_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_0_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_CNTXT_0_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_CNTXT_0_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_CNTXT_0_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_ELEMENT_SIZE_BMSK                                       0xff000000
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_ELEMENT_SIZE_SHFT                                             0x18
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_BMSK                                              0xf00000
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_SHFT                                                  0x14
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_NOT_ALLOCATED_FVAL                                     0x0
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_ALLOCATED_FVAL                                         0x1
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_STARTED_FVAL                                           0x2
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_STOPED_FVAL                                            0x3
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_STOP_IN_PROC_FVAL                                      0x4
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHSTATE_ERROR_FVAL                                             0xf
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_ERINDEX_BMSK                                               0x7c000
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_ERINDEX_SHFT                                                   0xe
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_MSB_BMSK                                    0x2000
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_MSB_SHFT                                       0xd
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHID_BMSK                                                   0x1f00
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHID_SHFT                                                      0x8
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_EE_BMSK                                                       0xf0
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_EE_SHFT                                                        0x4
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_BMSK                                                0x8
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_SHFT                                                0x3
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_INBOUND_FVAL                                        0x0
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_DIR_OUTBOUND_FVAL                                       0x1
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_BMSK                                           0x7
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_SHFT                                           0x0
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_MHI_FVAL                                       0x0
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_XHCI_FVAL                                      0x1
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_GPI_FVAL                                       0x2
#define HWIO_EE_n_GSI_CH_k_CNTXT_0_CHTYPE_PROTOCOL_XDCI_FVAL                                      0x3

#define HWIO_EE_n_GSI_CH_k_CNTXT_1_ADDR(base,n,k)                                          ((base) + 0x0001b004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_OFFS(base,n,k)                                          (0x0001b004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_RMSK                                                        0xffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_1_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_1_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_1_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_CNTXT_1_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_CNTXT_1_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_CNTXT_1_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_R_LENGTH_BMSK                                               0xffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_1_R_LENGTH_SHFT                                                  0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_2_ADDR(base,n,k)                                          ((base) + 0x0001b008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_OFFS(base,n,k)                                          (0x0001b008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_2_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_2_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_2_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_CNTXT_2_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_CNTXT_2_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_CNTXT_2_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_BMSK                                   0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_SHFT                                          0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_3_ADDR(base,n,k)                                          ((base) + 0x0001b00c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_OFFS(base,n,k)                                          (0x0001b00c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_3_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_3_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_3_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_CNTXT_3_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_CNTXT_3_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_CNTXT_3_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_BMSK                                   0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_SHFT                                          0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_4_ADDR(base,n,k)                                          ((base) + 0x0001b010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_OFFS(base,n,k)                                          (0x0001b010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_4_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_4_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_4_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_CNTXT_4_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_CNTXT_4_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_CNTXT_4_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_READ_PTR_LSB_BMSK                                       0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_4_READ_PTR_LSB_SHFT                                              0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_5_ADDR(base,n,k)                                          ((base) + 0x0001b014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_OFFS(base,n,k)                                          (0x0001b014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_5_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_5_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_5_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_READ_PTR_MSB_BMSK                                       0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_5_READ_PTR_MSB_SHFT                                              0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_6_ADDR(base,n,k)                                          ((base) + 0x0001b018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_OFFS(base,n,k)                                          (0x0001b018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_6_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_6_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_6_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_WRITE_PTR_LSB_BMSK                                      0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_6_WRITE_PTR_LSB_SHFT                                             0x0

#define HWIO_EE_n_GSI_CH_k_CNTXT_7_ADDR(base,n,k)                                          ((base) + 0x0001b01c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_OFFS(base,n,k)                                          (0x0001b01c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_MAXn                                                            14
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_MAXk                                                             1
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_7_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_CNTXT_7_RMSK)
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_CNTXT_7_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_WRITE_PTR_MSB_BMSK                                      0xffffffff
#define HWIO_EE_n_GSI_CH_k_CNTXT_7_WRITE_PTR_MSB_SHFT                                             0x0

#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(base,n,k)                                ((base) + 0x0001b054 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_OFFS(base,n,k)                                (0x0001b054 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_RMSK                                              0xffff
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_MAXn                                                  14
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_MAXk                                                   1
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_RMSK)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_READ_PTR_BMSK                                     0xffff
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_READ_PTR_READ_PTR_SHFT                                        0x0

#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(base,n,k)                               ((base) + 0x0001b058 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_OFFS(base,n,k)                               (0x0001b058 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RMSK                                             0xffff
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_MAXn                                                 14
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_MAXk                                                  1
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RMSK)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RE_INTR_DB_BMSK                                  0xffff
#define HWIO_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR_RE_INTR_DB_SHFT                                     0x0

#define HWIO_EE_n_GSI_CH_k_QOS_ADDR(base,n,k)                                              ((base) + 0x0001b05c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_QOS_OFFS(base,n,k)                                              (0x0001b05c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_QOS_RMSK                                                          0xff3f0f
#define HWIO_EE_n_GSI_CH_k_QOS_MAXn                                                                14
#define HWIO_EE_n_GSI_CH_k_QOS_MAXk                                                                 1
#define HWIO_EE_n_GSI_CH_k_QOS_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_QOS_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_QOS_RMSK)
#define HWIO_EE_n_GSI_CH_k_QOS_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_QOS_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_QOS_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_QOS_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_QOS_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_QOS_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_QOS_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_QOS_EMPTY_LVL_THRSHOLD_BMSK                                       0xff0000
#define HWIO_EE_n_GSI_CH_k_QOS_EMPTY_LVL_THRSHOLD_SHFT                                           0x10
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_BMSK                                              0x3c00
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_SHFT                                                 0xa
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_USE_PREFETCH_BUFS_FVAL                               0x0
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_ESCAPE_BUF_ONLY_FVAL                                 0x1
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_SMART_PRE_FETCH_FVAL                                 0x2
#define HWIO_EE_n_GSI_CH_k_QOS_PREFETCH_MODE_FREE_PRE_FETCH_FVAL                                  0x3
#define HWIO_EE_n_GSI_CH_k_QOS_USE_DB_ENG_BMSK                                                  0x200
#define HWIO_EE_n_GSI_CH_k_QOS_USE_DB_ENG_SHFT                                                    0x9
#define HWIO_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_BMSK                                                0x100
#define HWIO_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_SHFT                                                  0x8
#define HWIO_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_ONE_PREFETCH_SEG_FVAL                                 0x0
#define HWIO_EE_n_GSI_CH_k_QOS_MAX_PREFETCH_TWO_PREFETCH_SEG_FVAL                                 0x1
#define HWIO_EE_n_GSI_CH_k_QOS_WRR_WEIGHT_BMSK                                                    0xf
#define HWIO_EE_n_GSI_CH_k_QOS_WRR_WEIGHT_SHFT                                                    0x0

#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_ADDR(base,n,k)                                        ((base) + 0x0001b060 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_OFFS(base,n,k)                                        (0x0001b060 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_RMSK                                                  0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_MAXn                                                          14
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_MAXk                                                           1
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_0_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_SCRATCH_0_RMSK)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_0_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_SCRATCH_0_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_SCRATCH_0_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_SCRATCH_0_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_SCRATCH_BMSK                                          0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_0_SCRATCH_SHFT                                                 0x0

#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_ADDR(base,n,k)                                        ((base) + 0x0001b064 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_OFFS(base,n,k)                                        (0x0001b064 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_RMSK                                                  0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_MAXn                                                          14
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_MAXk                                                           1
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_1_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_SCRATCH_1_RMSK)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_1_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_SCRATCH_1_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_SCRATCH_1_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_SCRATCH_1_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_SCRATCH_BMSK                                          0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_1_SCRATCH_SHFT                                                 0x0

#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_ADDR(base,n,k)                                        ((base) + 0x0001b068 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_OFFS(base,n,k)                                        (0x0001b068 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_RMSK                                                  0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_MAXn                                                          14
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_MAXk                                                           1
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_2_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_SCRATCH_2_RMSK)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_2_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_SCRATCH_2_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_SCRATCH_2_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_SCRATCH_2_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_SCRATCH_BMSK                                          0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_2_SCRATCH_SHFT                                                 0x0

#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_ADDR(base,n,k)                                        ((base) + 0x0001b06c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_OFFS(base,n,k)                                        (0x0001b06c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_RMSK                                                  0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_MAXn                                                          14
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_MAXk                                                           1
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_3_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_SCRATCH_3_RMSK)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_SCRATCH_3_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_SCRATCH_3_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_SCRATCH_3_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_SCRATCH_3_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_SCRATCH_BMSK                                          0xffffffff
#define HWIO_EE_n_GSI_CH_k_SCRATCH_3_SCRATCH_SHFT                                                 0x0

#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(base,n,k)                                 ((base) + 0x0001b070 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_OFFS(base,n,k)                                 (0x0001b070 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_RMSK                                               0xffff
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_MAXn                                                   14
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_MAXk                                                    1
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(base,n,k), HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_RMSK)
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(base,n,k), mask)
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_ADDR(base,n,k),mask,val,HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_INI2(base,n,k))
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_LAST_DB_2_MCS_BMSK                                 0xffff
#define HWIO_EE_n_GSI_CH_k_DB_ENG_WRITE_PTR_LAST_DB_2_MCS_SHFT                                    0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_0_ADDR(base,n,k)                                           ((base) + 0x0001c000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_0_OFFS(base,n,k)                                           (0x0001c000 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_0_RMSK                                                     0xfff1ffff
#define HWIO_EE_n_EV_CH_k_CNTXT_0_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_0_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_0_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_0_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_0_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_0_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_0_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_0_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_0_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_0_ELEMENT_SIZE_BMSK                                        0xff000000
#define HWIO_EE_n_EV_CH_k_CNTXT_0_ELEMENT_SIZE_SHFT                                              0x18
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHSTATE_BMSK                                               0xf00000
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHSTATE_SHFT                                                   0x14
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHSTATE_NOT_ALLOCATED_FVAL                                      0x0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHSTATE_ALLOCATED_FVAL                                          0x1
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INTYPE_BMSK                                                 0x10000
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INTYPE_SHFT                                                    0x10
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INTYPE_MSI_FVAL                                                 0x0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_INTYPE_IRQ_FVAL                                                 0x1
#define HWIO_EE_n_EV_CH_k_CNTXT_0_EVCHID_BMSK                                                  0xff00
#define HWIO_EE_n_EV_CH_k_CNTXT_0_EVCHID_SHFT                                                     0x8
#define HWIO_EE_n_EV_CH_k_CNTXT_0_EE_BMSK                                                        0xf0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_EE_SHFT                                                         0x4
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_BMSK                                                     0xf
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_SHFT                                                     0x0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_MHI_EV_FVAL                                              0x0
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_XHCI_EV_FVAL                                             0x1
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_GPI_EV_FVAL                                              0x2
#define HWIO_EE_n_EV_CH_k_CNTXT_0_CHTYPE_XDCI_FVAL                                                0x3

#define HWIO_EE_n_EV_CH_k_CNTXT_1_ADDR(base,n,k)                                           ((base) + 0x0001c004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_1_OFFS(base,n,k)                                           (0x0001c004 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_1_RMSK                                                         0xffff
#define HWIO_EE_n_EV_CH_k_CNTXT_1_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_1_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_1_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_1_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_1_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_1_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_1_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_1_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_1_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_1_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_1_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_1_R_LENGTH_BMSK                                                0xffff
#define HWIO_EE_n_EV_CH_k_CNTXT_1_R_LENGTH_SHFT                                                   0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_2_ADDR(base,n,k)                                           ((base) + 0x0001c008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_2_OFFS(base,n,k)                                           (0x0001c008 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_2_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_2_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_2_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_2_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_2_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_2_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_2_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_2_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_2_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_2_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_2_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_2_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_2_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_BMSK                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_2_R_BASE_ADDR_LSBS_SHFT                                           0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_3_ADDR(base,n,k)                                           ((base) + 0x0001c00c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_3_OFFS(base,n,k)                                           (0x0001c00c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_3_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_3_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_3_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_3_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_3_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_3_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_3_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_3_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_3_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_3_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_3_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_3_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_3_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_BMSK                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_3_R_BASE_ADDR_MSBS_SHFT                                           0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_4_ADDR(base,n,k)                                           ((base) + 0x0001c010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_4_OFFS(base,n,k)                                           (0x0001c010 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_4_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_4_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_4_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_4_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_4_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_4_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_4_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_4_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_4_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_4_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_4_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_4_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_4_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_4_READ_PTR_LSB_BMSK                                        0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_4_READ_PTR_LSB_SHFT                                               0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_5_ADDR(base,n,k)                                           ((base) + 0x0001c014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_5_OFFS(base,n,k)                                           (0x0001c014 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_5_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_5_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_5_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_5_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_5_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_5_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_5_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_5_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_5_READ_PTR_MSB_BMSK                                        0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_5_READ_PTR_MSB_SHFT                                               0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_6_ADDR(base,n,k)                                           ((base) + 0x0001c018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_6_OFFS(base,n,k)                                           (0x0001c018 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_6_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_6_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_6_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_6_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_6_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_6_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_6_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_6_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_6_WRITE_PTR_LSB_BMSK                                       0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_6_WRITE_PTR_LSB_SHFT                                              0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_7_ADDR(base,n,k)                                           ((base) + 0x0001c01c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_7_OFFS(base,n,k)                                           (0x0001c01c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_7_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_7_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_7_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_7_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_7_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_7_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_7_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_7_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_7_WRITE_PTR_MSB_BMSK                                       0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_7_WRITE_PTR_MSB_SHFT                                              0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_8_ADDR(base,n,k)                                           ((base) + 0x0001c020 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_8_OFFS(base,n,k)                                           (0x0001c020 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_8_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_8_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_8_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_8_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_8_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_8_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_8_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_8_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_8_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_8_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_8_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MOD_CNT_BMSK                                         0xff000000
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MOD_CNT_SHFT                                               0x18
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MODC_BMSK                                              0xff0000
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MODC_SHFT                                                  0x10
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MODT_BMSK                                                0xffff
#define HWIO_EE_n_EV_CH_k_CNTXT_8_INT_MODT_SHFT                                                   0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_9_ADDR(base,n,k)                                           ((base) + 0x0001c024 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_9_OFFS(base,n,k)                                           (0x0001c024 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_9_RMSK                                                     0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_9_MAXn                                                             14
#define HWIO_EE_n_EV_CH_k_CNTXT_9_MAXk                                                              0
#define HWIO_EE_n_EV_CH_k_CNTXT_9_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_9_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_9_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_9_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_9_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_9_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_9_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_9_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_9_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_9_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_9_INTVEC_BMSK                                              0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_9_INTVEC_SHFT                                                     0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_10_ADDR(base,n,k)                                          ((base) + 0x0001c028 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_10_OFFS(base,n,k)                                          (0x0001c028 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_10_RMSK                                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_10_MAXn                                                            14
#define HWIO_EE_n_EV_CH_k_CNTXT_10_MAXk                                                             0
#define HWIO_EE_n_EV_CH_k_CNTXT_10_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_10_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_10_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_10_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_10_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_10_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_10_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_10_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_10_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_10_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_10_MSI_ADDR_LSB_BMSK                                       0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_10_MSI_ADDR_LSB_SHFT                                              0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_11_ADDR(base,n,k)                                          ((base) + 0x0001c02c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_11_OFFS(base,n,k)                                          (0x0001c02c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_11_RMSK                                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_11_MAXn                                                            14
#define HWIO_EE_n_EV_CH_k_CNTXT_11_MAXk                                                             0
#define HWIO_EE_n_EV_CH_k_CNTXT_11_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_11_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_11_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_11_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_11_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_11_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_11_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_11_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_11_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_11_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_11_MSI_ADDR_MSB_BMSK                                       0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_11_MSI_ADDR_MSB_SHFT                                              0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_12_ADDR(base,n,k)                                          ((base) + 0x0001c030 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_12_OFFS(base,n,k)                                          (0x0001c030 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_12_RMSK                                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_12_MAXn                                                            14
#define HWIO_EE_n_EV_CH_k_CNTXT_12_MAXk                                                             0
#define HWIO_EE_n_EV_CH_k_CNTXT_12_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_12_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_12_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_12_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_12_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_12_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_12_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_12_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_12_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_12_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_12_RP_UPDATE_ADDR_LSB_BMSK                                 0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_12_RP_UPDATE_ADDR_LSB_SHFT                                        0x0

#define HWIO_EE_n_EV_CH_k_CNTXT_13_ADDR(base,n,k)                                          ((base) + 0x0001c034 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_13_OFFS(base,n,k)                                          (0x0001c034 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_CNTXT_13_RMSK                                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_13_MAXn                                                            14
#define HWIO_EE_n_EV_CH_k_CNTXT_13_MAXk                                                             0
#define HWIO_EE_n_EV_CH_k_CNTXT_13_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_13_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_CNTXT_13_RMSK)
#define HWIO_EE_n_EV_CH_k_CNTXT_13_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_CNTXT_13_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_CNTXT_13_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_CNTXT_13_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_CNTXT_13_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_CNTXT_13_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_CNTXT_13_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_CNTXT_13_RP_UPDATE_ADDR_MSB_BMSK                                 0xffffffff
#define HWIO_EE_n_EV_CH_k_CNTXT_13_RP_UPDATE_ADDR_MSB_SHFT                                        0x0

#define HWIO_EE_n_EV_CH_k_SCRATCH_0_ADDR(base,n,k)                                         ((base) + 0x0001c048 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_OFFS(base,n,k)                                         (0x0001c048 + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_RMSK                                                   0xffffffff
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_MAXn                                                           14
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_MAXk                                                            0
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_SCRATCH_0_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_SCRATCH_0_RMSK)
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_SCRATCH_0_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_SCRATCH_0_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_SCRATCH_0_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_SCRATCH_0_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_SCRATCH_BMSK                                           0xffffffff
#define HWIO_EE_n_EV_CH_k_SCRATCH_0_SCRATCH_SHFT                                                  0x0

#define HWIO_EE_n_EV_CH_k_SCRATCH_1_ADDR(base,n,k)                                         ((base) + 0x0001c04c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_OFFS(base,n,k)                                         (0x0001c04c + 0x4000 * (n) + 0x80 * (k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_RMSK                                                   0xffffffff
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_MAXn                                                           14
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_MAXk                                                            0
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_INI2(base,n,k)        \
        in_dword_masked(HWIO_EE_n_EV_CH_k_SCRATCH_1_ADDR(base,n,k), HWIO_EE_n_EV_CH_k_SCRATCH_1_RMSK)
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_INMI2(base,n,k,mask)    \
        in_dword_masked(HWIO_EE_n_EV_CH_k_SCRATCH_1_ADDR(base,n,k), mask)
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_SCRATCH_1_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_OUTMI2(base,n,k,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_EV_CH_k_SCRATCH_1_ADDR(base,n,k),mask,val,HWIO_EE_n_EV_CH_k_SCRATCH_1_INI2(base,n,k))
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_SCRATCH_BMSK                                           0xffffffff
#define HWIO_EE_n_EV_CH_k_SCRATCH_1_SCRATCH_SHFT                                                  0x0

#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_ADDR(base,n,k)                                       ((base) + 0x0001d000 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_OFFS(base,n,k)                                       (0x0001d000 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_RMSK                                                 0xffffffff
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_MAXn                                                         14
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_MAXk                                                          1
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_DOORBELL_0_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_WRITE_PTR_LSB_BMSK                                   0xffffffff
#define HWIO_EE_n_GSI_CH_k_DOORBELL_0_WRITE_PTR_LSB_SHFT                                          0x0

#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_ADDR(base,n,k)                                       ((base) + 0x0001d004 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_OFFS(base,n,k)                                       (0x0001d004 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_RMSK                                                 0xffffffff
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_MAXn                                                         14
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_MAXk                                                          1
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_GSI_CH_k_DOORBELL_1_ADDR(base,n,k),val)
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_WRITE_PTR_MSB_BMSK                                   0xffffffff
#define HWIO_EE_n_GSI_CH_k_DOORBELL_1_WRITE_PTR_MSB_SHFT                                          0x0

#define HWIO_EE_n_EV_CH_k_DOORBELL_0_ADDR(base,n,k)                                        ((base) + 0x0001d100 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_OFFS(base,n,k)                                        (0x0001d100 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_RMSK                                                  0xffffffff
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_MAXn                                                          14
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_MAXk                                                           0
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_DOORBELL_0_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_WRITE_PTR_LSB_BMSK                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_DOORBELL_0_WRITE_PTR_LSB_SHFT                                           0x0

#define HWIO_EE_n_EV_CH_k_DOORBELL_1_ADDR(base,n,k)                                        ((base) + 0x0001d104 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_OFFS(base,n,k)                                        (0x0001d104 + 0x4000 * (n) + 0x8 * (k))
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_RMSK                                                  0xffffffff
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_MAXn                                                          14
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_MAXk                                                           0
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_OUTI2(base,n,k,val)    \
        out_dword(HWIO_EE_n_EV_CH_k_DOORBELL_1_ADDR(base,n,k),val)
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_WRITE_PTR_MSB_BMSK                                    0xffffffff
#define HWIO_EE_n_EV_CH_k_DOORBELL_1_WRITE_PTR_MSB_SHFT                                           0x0

#define HWIO_EE_n_GSI_STATUS_ADDR(base,n)                                                  ((base) + 0x0001e000 + 0x4000 * (n))
#define HWIO_EE_n_GSI_STATUS_OFFS(base,n)                                                  (0x0001e000 + 0x4000 * (n))
#define HWIO_EE_n_GSI_STATUS_RMSK                                                                 0x1
#define HWIO_EE_n_GSI_STATUS_MAXn                                                                  14
#define HWIO_EE_n_GSI_STATUS_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_STATUS_ADDR(base,n), HWIO_EE_n_GSI_STATUS_RMSK)
#define HWIO_EE_n_GSI_STATUS_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_STATUS_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_STATUS_ENABLED_BMSK                                                         0x1
#define HWIO_EE_n_GSI_STATUS_ENABLED_SHFT                                                         0x0

#define HWIO_EE_n_GSI_CH_CMD_ADDR(base,n)                                                  ((base) + 0x0001e008 + 0x4000 * (n))
#define HWIO_EE_n_GSI_CH_CMD_OFFS(base,n)                                                  (0x0001e008 + 0x4000 * (n))
#define HWIO_EE_n_GSI_CH_CMD_RMSK                                                          0xff0000ff
#define HWIO_EE_n_GSI_CH_CMD_MAXn                                                                  14
#define HWIO_EE_n_GSI_CH_CMD_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_GSI_CH_CMD_ADDR(base,n),val)
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_BMSK                                                   0xff000000
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_SHFT                                                         0x18
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_ALLOCATE_FVAL                                                 0x0
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_START_FVAL                                                    0x1
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_STOP_FVAL                                                     0x2
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_RESET_FVAL                                                    0x9
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_DE_ALLOC_FVAL                                                 0xa
#define HWIO_EE_n_GSI_CH_CMD_OPCODE_DB_STOP_FVAL                                                  0xb
#define HWIO_EE_n_GSI_CH_CMD_CHID_BMSK                                                           0xff
#define HWIO_EE_n_GSI_CH_CMD_CHID_SHFT                                                            0x0

#define HWIO_EE_n_EV_CH_CMD_ADDR(base,n)                                                   ((base) + 0x0001e010 + 0x4000 * (n))
#define HWIO_EE_n_EV_CH_CMD_OFFS(base,n)                                                   (0x0001e010 + 0x4000 * (n))
#define HWIO_EE_n_EV_CH_CMD_RMSK                                                           0xff0000ff
#define HWIO_EE_n_EV_CH_CMD_MAXn                                                                   14
#define HWIO_EE_n_EV_CH_CMD_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_EV_CH_CMD_ADDR(base,n),val)
#define HWIO_EE_n_EV_CH_CMD_OPCODE_BMSK                                                    0xff000000
#define HWIO_EE_n_EV_CH_CMD_OPCODE_SHFT                                                          0x18
#define HWIO_EE_n_EV_CH_CMD_OPCODE_ALLOCATE_FVAL                                                  0x0
#define HWIO_EE_n_EV_CH_CMD_OPCODE_RESET_FVAL                                                     0x9
#define HWIO_EE_n_EV_CH_CMD_OPCODE_DE_ALLOC_FVAL                                                  0xa
#define HWIO_EE_n_EV_CH_CMD_CHID_BMSK                                                            0xff
#define HWIO_EE_n_EV_CH_CMD_CHID_SHFT                                                             0x0

#define HWIO_EE_n_GSI_EE_GENERIC_CMD_ADDR(base,n)                                          ((base) + 0x0001e018 + 0x4000 * (n))
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_OFFS(base,n)                                          (0x0001e018 + 0x4000 * (n))
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_RMSK                                                  0xffffffff
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_MAXn                                                          14
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_GSI_EE_GENERIC_CMD_ADDR(base,n),val)
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_OPCODE_BMSK                                           0xffffffff
#define HWIO_EE_n_GSI_EE_GENERIC_CMD_OPCODE_SHFT                                                  0x0

#define HWIO_EE_n_GSI_HW_PARAM_0_ADDR(base,n)                                              ((base) + 0x0001e038 + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_0_OFFS(base,n)                                              (0x0001e038 + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_0_RMSK                                                      0xffffffff
#define HWIO_EE_n_GSI_HW_PARAM_0_MAXn                                                              14
#define HWIO_EE_n_GSI_HW_PARAM_0_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_0_ADDR(base,n), HWIO_EE_n_GSI_HW_PARAM_0_RMSK)
#define HWIO_EE_n_GSI_HW_PARAM_0_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_0_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_HW_PARAM_0_USE_AXI_M_BMSK                                            0x80000000
#define HWIO_EE_n_GSI_HW_PARAM_0_USE_AXI_M_SHFT                                                  0x1f
#define HWIO_EE_n_GSI_HW_PARAM_0_PERIPH_SEC_GRP_BMSK                                       0x7c000000
#define HWIO_EE_n_GSI_HW_PARAM_0_PERIPH_SEC_GRP_SHFT                                             0x1a
#define HWIO_EE_n_GSI_HW_PARAM_0_PERIPH_CONF_ADDR_BUS_W_BMSK                                0x3e00000
#define HWIO_EE_n_GSI_HW_PARAM_0_PERIPH_CONF_ADDR_BUS_W_SHFT                                     0x15
#define HWIO_EE_n_GSI_HW_PARAM_0_NUM_EES_BMSK                                                0x1f0000
#define HWIO_EE_n_GSI_HW_PARAM_0_NUM_EES_SHFT                                                    0x10
#define HWIO_EE_n_GSI_HW_PARAM_0_GSI_CH_NUM_BMSK                                               0xff00
#define HWIO_EE_n_GSI_HW_PARAM_0_GSI_CH_NUM_SHFT                                                  0x8
#define HWIO_EE_n_GSI_HW_PARAM_0_GSI_EV_CH_NUM_BMSK                                              0xff
#define HWIO_EE_n_GSI_HW_PARAM_0_GSI_EV_CH_NUM_SHFT                                               0x0

#define HWIO_EE_n_GSI_HW_PARAM_1_ADDR(base,n)                                              ((base) + 0x0001e03c + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_1_OFFS(base,n)                                              (0x0001e03c + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_1_RMSK                                                      0xffffffff
#define HWIO_EE_n_GSI_HW_PARAM_1_MAXn                                                              14
#define HWIO_EE_n_GSI_HW_PARAM_1_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_1_ADDR(base,n), HWIO_EE_n_GSI_HW_PARAM_1_RMSK)
#define HWIO_EE_n_GSI_HW_PARAM_1_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_1_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_2_EN_BMSK                       0x80000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_2_EN_SHFT                             0x1f
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_1_EN_BMSK                       0x40000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_BLK_INT_ACCESS_REGION_1_EN_SHFT                             0x1e
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_SIMPLE_RD_WR_BMSK                                     0x20000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_SIMPLE_RD_WR_SHFT                                           0x1d
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_ESCAPE_BUF_ONLY_BMSK                                  0x10000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_ESCAPE_BUF_ONLY_SHFT                                        0x1c
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_UC_IF_BMSK                                         0x8000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_UC_IF_SHFT                                              0x1b
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_DB_ENG_BMSK                                        0x4000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_DB_ENG_SHFT                                             0x1a
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_BP_MTRIX_BMSK                                      0x2000000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_BP_MTRIX_SHFT                                           0x19
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NUM_TIMERS_BMSK                                        0x1f00000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NUM_TIMERS_SHFT                                             0x14
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_XPU_BMSK                                             0x80000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_USE_XPU_SHFT                                                0x13
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_QRIB_EN_BMSK                                             0x40000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_QRIB_EN_SHFT                                                0x12
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_VMIDACR_EN_BMSK                                          0x20000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_VMIDACR_EN_SHFT                                             0x11
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_SEC_EN_BMSK                                              0x10000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_SEC_EN_SHFT                                                 0x10
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NONSEC_EN_BMSK                                            0xf000
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NONSEC_EN_SHFT                                               0xc
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NUM_QAD_BMSK                                               0xf00
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_NUM_QAD_SHFT                                                 0x8
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_M_DATA_BUS_W_BMSK                                           0xff
#define HWIO_EE_n_GSI_HW_PARAM_1_GSI_M_DATA_BUS_W_SHFT                                            0x0

#define HWIO_EE_n_GSI_HW_PARAM_2_ADDR(base,n)                                              ((base) + 0x0001e040 + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_2_OFFS(base,n)                                              (0x0001e040 + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_2_RMSK                                                      0xffffffff
#define HWIO_EE_n_GSI_HW_PARAM_2_MAXn                                                              14
#define HWIO_EE_n_GSI_HW_PARAM_2_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_2_ADDR(base,n), HWIO_EE_n_GSI_HW_PARAM_2_RMSK)
#define HWIO_EE_n_GSI_HW_PARAM_2_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_2_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_INTER_EE_BMSK                                     0x80000000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_INTER_EE_SHFT                                           0x1f
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_RD_WR_ENG_BMSK                                    0x40000000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_RD_WR_ENG_SHFT                                          0x1e
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_IOVEC_BMSK                                     0x38000000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_IOVEC_SHFT                                           0x1b
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_MAX_BURST_BMSK                                    0x7f80000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_MAX_BURST_SHFT                                         0x13
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_INT_BMSK                                          0x70000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_SDMA_N_INT_SHFT                                             0x10
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_SDMA_BMSK                                             0x8000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_USE_SDMA_SHFT                                                0xf
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_CH_FULL_LOGIC_BMSK                                        0x4000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_CH_FULL_LOGIC_SHFT                                           0xe
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_CH_PEND_TRANSLATE_BMSK                                    0x2000
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_CH_PEND_TRANSLATE_SHFT                                       0xd
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_NUM_EV_PER_EE_BMSK                                        0x1f00
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_NUM_EV_PER_EE_SHFT                                           0x8
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_NUM_CH_PER_EE_BMSK                                          0xf8
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_NUM_CH_PER_EE_SHFT                                           0x3
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_BMSK                                               0x7
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_SHFT                                               0x0
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_ONE_KB_FVAL                                        0x0
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_TWO_KB_FVAL                                        0x1
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_TWO_N_HALF_KB_FVAL                                 0x2
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_THREE_KB_FVAL                                      0x3
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_THREE_N_HALF_KB_FVAL                               0x4
#define HWIO_EE_n_GSI_HW_PARAM_2_GSI_IRAM_SIZE_FOUR_KB_FVAL                                       0x5

#define HWIO_EE_n_GSI_SW_VERSION_ADDR(base,n)                                              ((base) + 0x0001e044 + 0x4000 * (n))
#define HWIO_EE_n_GSI_SW_VERSION_OFFS(base,n)                                              (0x0001e044 + 0x4000 * (n))
#define HWIO_EE_n_GSI_SW_VERSION_RMSK                                                      0xffffffff
#define HWIO_EE_n_GSI_SW_VERSION_MAXn                                                              14
#define HWIO_EE_n_GSI_SW_VERSION_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_SW_VERSION_ADDR(base,n), HWIO_EE_n_GSI_SW_VERSION_RMSK)
#define HWIO_EE_n_GSI_SW_VERSION_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_SW_VERSION_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_SW_VERSION_MAJOR_BMSK                                                0xf0000000
#define HWIO_EE_n_GSI_SW_VERSION_MAJOR_SHFT                                                      0x1c
#define HWIO_EE_n_GSI_SW_VERSION_MINOR_BMSK                                                 0xfff0000
#define HWIO_EE_n_GSI_SW_VERSION_MINOR_SHFT                                                      0x10
#define HWIO_EE_n_GSI_SW_VERSION_STEP_BMSK                                                     0xffff
#define HWIO_EE_n_GSI_SW_VERSION_STEP_SHFT                                                        0x0

#define HWIO_EE_n_GSI_MCS_CODE_VER_ADDR(base,n)                                            ((base) + 0x0001e048 + 0x4000 * (n))
#define HWIO_EE_n_GSI_MCS_CODE_VER_OFFS(base,n)                                            (0x0001e048 + 0x4000 * (n))
#define HWIO_EE_n_GSI_MCS_CODE_VER_RMSK                                                    0xffffffff
#define HWIO_EE_n_GSI_MCS_CODE_VER_MAXn                                                            14
#define HWIO_EE_n_GSI_MCS_CODE_VER_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_MCS_CODE_VER_ADDR(base,n), HWIO_EE_n_GSI_MCS_CODE_VER_RMSK)
#define HWIO_EE_n_GSI_MCS_CODE_VER_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_MCS_CODE_VER_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_MCS_CODE_VER_VER_BMSK                                                0xffffffff
#define HWIO_EE_n_GSI_MCS_CODE_VER_VER_SHFT                                                       0x0

#define HWIO_EE_n_GSI_HW_PARAM_3_ADDR(base,n)                                              ((base) + 0x0001e04c + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_3_OFFS(base,n)                                              (0x0001e04c + 0x4000 * (n))
#define HWIO_EE_n_GSI_HW_PARAM_3_RMSK                                                       0xfffffff
#define HWIO_EE_n_GSI_HW_PARAM_3_MAXn                                                              14
#define HWIO_EE_n_GSI_HW_PARAM_3_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_3_ADDR(base,n), HWIO_EE_n_GSI_HW_PARAM_3_RMSK)
#define HWIO_EE_n_GSI_HW_PARAM_3_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_GSI_HW_PARAM_3_ADDR(base,n), mask)
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_SLEEP_CLK_DIV_BMSK                                 0x8000000
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_SLEEP_CLK_DIV_SHFT                                      0x1b
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_VIR_CH_IF_BMSK                                     0x4000000
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_VIR_CH_IF_SHFT                                          0x1a
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_IROM_BMSK                                          0x2000000
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_USE_IROM_SHFT                                               0x19
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_REE_MAX_BURST_LEN_BMSK                                 0x1f00000
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_REE_MAX_BURST_LEN_SHFT                                      0x14
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_M_ADDR_BUS_W_BMSK                                        0xff000
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_M_ADDR_BUS_W_SHFT                                            0xc
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_NUM_PREFETCH_BUFS_BMSK                                     0xf00
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_NUM_PREFETCH_BUFS_SHFT                                       0x8
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_WR_BMSK                                         0xf0
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_WR_SHFT                                          0x4
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_RD_BMSK                                          0xf
#define HWIO_EE_n_GSI_HW_PARAM_3_GSI_SDMA_MAX_OS_RD_SHFT                                          0x0

#define HWIO_EE_n_CNTXT_TYPE_IRQ_ADDR(base,n)                                              ((base) + 0x0001e080 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_TYPE_IRQ_OFFS(base,n)                                              (0x0001e080 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_TYPE_IRQ_RMSK                                                            0x7f
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MAXn                                                              14
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_TYPE_IRQ_ADDR(base,n), HWIO_EE_n_CNTXT_TYPE_IRQ_RMSK)
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_TYPE_IRQ_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_TYPE_IRQ_GENERAL_BMSK                                                    0x40
#define HWIO_EE_n_CNTXT_TYPE_IRQ_GENERAL_SHFT                                                     0x6
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INTER_EE_EV_CTRL_BMSK                                           0x20
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INTER_EE_EV_CTRL_SHFT                                            0x5
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INTER_EE_CH_CTRL_BMSK                                           0x10
#define HWIO_EE_n_CNTXT_TYPE_IRQ_INTER_EE_CH_CTRL_SHFT                                            0x4
#define HWIO_EE_n_CNTXT_TYPE_IRQ_IEOB_BMSK                                                        0x8
#define HWIO_EE_n_CNTXT_TYPE_IRQ_IEOB_SHFT                                                        0x3
#define HWIO_EE_n_CNTXT_TYPE_IRQ_GLOB_EE_BMSK                                                     0x4
#define HWIO_EE_n_CNTXT_TYPE_IRQ_GLOB_EE_SHFT                                                     0x2
#define HWIO_EE_n_CNTXT_TYPE_IRQ_EV_CTRL_BMSK                                                     0x2
#define HWIO_EE_n_CNTXT_TYPE_IRQ_EV_CTRL_SHFT                                                     0x1
#define HWIO_EE_n_CNTXT_TYPE_IRQ_CH_CTRL_BMSK                                                     0x1
#define HWIO_EE_n_CNTXT_TYPE_IRQ_CH_CTRL_SHFT                                                     0x0

#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(base,n)                                          ((base) + 0x0001e088 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_OFFS(base,n)                                          (0x0001e088 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_RMSK                                                        0x7f
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_MAXn                                                          14
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(base,n), HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_RMSK)
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INI(base,n))
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_GENERAL_BMSK                                                0x40
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_GENERAL_SHFT                                                 0x6
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_EV_CTRL_BMSK                                       0x20
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_EV_CTRL_SHFT                                        0x5
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_CH_CTRL_BMSK                                       0x10
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_INTER_EE_CH_CTRL_SHFT                                        0x4
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_IEOB_BMSK                                                    0x8
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_IEOB_SHFT                                                    0x3
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_GLOB_EE_BMSK                                                 0x4
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_GLOB_EE_SHFT                                                 0x2
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_EV_CTRL_BMSK                                                 0x2
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_EV_CTRL_SHFT                                                 0x1
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_CH_CTRL_BMSK                                                 0x1
#define HWIO_EE_n_CNTXT_TYPE_IRQ_MSK_CH_CTRL_SHFT                                                 0x0

#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(base,n)                                        ((base) + 0x0001e090 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_OFFS(base,n)                                        (0x0001e090 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_RMSK                                                0xffffffff
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MAXn                                                        14
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_RMSK)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_BMSK                                 0xffffffff
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_GSI_CH_BIT_MAP_SHFT                                        0x0

#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(base,n)                                         ((base) + 0x0001e094 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_OFFS(base,n)                                         (0x0001e094 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_RMSK                                                 0xffffffff
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MAXn                                                         14
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_RMSK)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_BMSK                                   0xffffffff
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_EV_CH_BIT_MAP_SHFT                                          0x0

#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(base,n)                                    ((base) + 0x0001e098 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_OFFS(base,n)                                    (0x0001e098 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_RMSK                                                   0x3
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_MAXn                                                    14
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_RMSK)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_INI(base,n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_BMSK                                0x3
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_GSI_CH_BIT_MAP_MSK_SHFT                                0x0

#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(base,n)                                     ((base) + 0x0001e09c + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_OFFS(base,n)                                     (0x0001e09c + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_RMSK                                                    0x1
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_MAXn                                                     14
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_RMSK)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_INI(base,n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_BMSK                                  0x1
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_EV_CH_BIT_MAP_MSK_SHFT                                  0x0

#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_ADDR(base,n)                                    ((base) + 0x0001e0a0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_OFFS(base,n)                                    (0x0001e0a0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_RMSK                                            0xffffffff
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_MAXn                                                    14
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_BMSK                             0xffffffff
#define HWIO_EE_n_CNTXT_SRC_GSI_CH_IRQ_CLR_GSI_CH_BIT_MAP_SHFT                                    0x0

#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_ADDR(base,n)                                     ((base) + 0x0001e0a4 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_OFFS(base,n)                                     (0x0001e0a4 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_RMSK                                             0xffffffff
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_MAXn                                                     14
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_BMSK                               0xffffffff
#define HWIO_EE_n_CNTXT_SRC_EV_CH_IRQ_CLR_EV_CH_BIT_MAP_SHFT                                      0x0

#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(base,n)                                          ((base) + 0x0001e0b0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_OFFS(base,n)                                          (0x0001e0b0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_RMSK                                                  0xffffffff
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MAXn                                                          14
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_RMSK)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_EV_CH_BIT_MAP_BMSK                                    0xffffffff
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_EV_CH_BIT_MAP_SHFT                                           0x0

#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(base,n)                                      ((base) + 0x0001e0b8 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_OFFS(base,n)                                      (0x0001e0b8 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_RMSK                                                     0x1
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_MAXn                                                      14
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(base,n), HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_RMSK)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_INI(base,n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_EV_CH_BIT_MAP_MSK_BMSK                                   0x1
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_MSK_EV_CH_BIT_MAP_MSK_SHFT                                   0x0

#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_ADDR(base,n)                                      ((base) + 0x0001e0c0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_OFFS(base,n)                                      (0x0001e0c0 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_RMSK                                              0xffffffff
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_MAXn                                                      14
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_EV_CH_BIT_MAP_BMSK                                0xffffffff
#define HWIO_EE_n_CNTXT_SRC_IEOB_IRQ_CLR_EV_CH_BIT_MAP_SHFT                                       0x0

#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(base,n)                                         ((base) + 0x0001e100 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS(base,n)                                         (0x0001e100 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_RMSK                                                        0xf
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_MAXn                                                         14
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(base,n), HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_RMSK)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT3_BMSK                                                0x8
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT3_SHFT                                                0x3
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT2_BMSK                                                0x4
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT2_SHFT                                                0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT1_BMSK                                                0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_GP_INT1_SHFT                                                0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_ERROR_INT_BMSK                                              0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_STTS_ERROR_INT_SHFT                                              0x0

#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(base,n)                                           ((base) + 0x0001e108 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_OFFS(base,n)                                           (0x0001e108 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_RMSK                                                          0xf
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_MAXn                                                           14
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(base,n), HWIO_EE_n_CNTXT_GLOB_IRQ_EN_RMSK)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_GLOB_IRQ_EN_INI(base,n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT3_BMSK                                                  0x8
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT3_SHFT                                                  0x3
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT2_BMSK                                                  0x4
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT2_SHFT                                                  0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT1_BMSK                                                  0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_GP_INT1_SHFT                                                  0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ERROR_INT_BMSK                                                0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_EN_ERROR_INT_SHFT                                                0x0

#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_ADDR(base,n)                                          ((base) + 0x0001e110 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_OFFS(base,n)                                          (0x0001e110 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_RMSK                                                         0xf
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_MAXn                                                          14
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT3_BMSK                                                 0x8
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT3_SHFT                                                 0x3
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT2_BMSK                                                 0x4
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT2_SHFT                                                 0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT1_BMSK                                                 0x2
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_GP_INT1_SHFT                                                 0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_ERROR_INT_BMSK                                               0x1
#define HWIO_EE_n_CNTXT_GLOB_IRQ_CLR_ERROR_INT_SHFT                                               0x0

#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(base,n)                                          ((base) + 0x0001e118 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_OFFS(base,n)                                          (0x0001e118 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_RMSK                                                         0xf
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_MAXn                                                          14
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(base,n), HWIO_EE_n_CNTXT_GSI_IRQ_STTS_RMSK)
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_GSI_IRQ_STTS_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_MCS_STACK_OVRFLOW_BMSK                                   0x8
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_MCS_STACK_OVRFLOW_SHFT                                   0x3
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_CMD_FIFO_OVRFLOW_BMSK                                    0x4
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_CMD_FIFO_OVRFLOW_SHFT                                    0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BUS_ERROR_BMSK                                           0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BUS_ERROR_SHFT                                           0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BREAK_POINT_BMSK                                         0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_STTS_GSI_BREAK_POINT_SHFT                                         0x0

#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_ADDR(base,n)                                            ((base) + 0x0001e120 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_OFFS(base,n)                                            (0x0001e120 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_RMSK                                                           0xf
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_MAXn                                                            14
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_GSI_IRQ_EN_ADDR(base,n), HWIO_EE_n_CNTXT_GSI_IRQ_EN_RMSK)
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_GSI_IRQ_EN_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_GSI_IRQ_EN_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_GSI_IRQ_EN_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_GSI_IRQ_EN_INI(base,n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_MCS_STACK_OVRFLOW_BMSK                                     0x8
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_MCS_STACK_OVRFLOW_SHFT                                     0x3
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_CMD_FIFO_OVRFLOW_BMSK                                      0x4
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_CMD_FIFO_OVRFLOW_SHFT                                      0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_BUS_ERROR_BMSK                                             0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_BUS_ERROR_SHFT                                             0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_BREAK_POINT_BMSK                                           0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_EN_GSI_BREAK_POINT_SHFT                                           0x0

#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_ADDR(base,n)                                           ((base) + 0x0001e128 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_OFFS(base,n)                                           (0x0001e128 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_RMSK                                                          0xf
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_MAXn                                                           14
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_GSI_IRQ_CLR_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_MCS_STACK_OVRFLOW_BMSK                                    0x8
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_MCS_STACK_OVRFLOW_SHFT                                    0x3
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_CMD_FIFO_OVRFLOW_BMSK                                     0x4
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_CMD_FIFO_OVRFLOW_SHFT                                     0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BUS_ERROR_BMSK                                            0x2
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BUS_ERROR_SHFT                                            0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BREAK_POINT_BMSK                                          0x1
#define HWIO_EE_n_CNTXT_GSI_IRQ_CLR_GSI_BREAK_POINT_SHFT                                          0x0

#define HWIO_EE_n_CNTXT_INTSET_ADDR(base,n)                                                ((base) + 0x0001e180 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_INTSET_OFFS(base,n)                                                (0x0001e180 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_INTSET_RMSK                                                               0x1
#define HWIO_EE_n_CNTXT_INTSET_MAXn                                                                14
#define HWIO_EE_n_CNTXT_INTSET_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_INTSET_ADDR(base,n), HWIO_EE_n_CNTXT_INTSET_RMSK)
#define HWIO_EE_n_CNTXT_INTSET_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_INTSET_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_INTSET_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_INTSET_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_INTSET_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_INTSET_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_INTSET_INI(base,n))
#define HWIO_EE_n_CNTXT_INTSET_INTYPE_BMSK                                                        0x1
#define HWIO_EE_n_CNTXT_INTSET_INTYPE_SHFT                                                        0x0
#define HWIO_EE_n_CNTXT_INTSET_INTYPE_MSI_FVAL                                                    0x0
#define HWIO_EE_n_CNTXT_INTSET_INTYPE_IRQ_FVAL                                                    0x1

#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_ADDR(base,n)                                          ((base) + 0x0001e188 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_OFFS(base,n)                                          (0x0001e188 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_RMSK                                                  0xffffffff
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_MAXn                                                          14
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_MSI_BASE_LSB_ADDR(base,n), HWIO_EE_n_CNTXT_MSI_BASE_LSB_RMSK)
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_MSI_BASE_LSB_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_MSI_BASE_LSB_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_MSI_BASE_LSB_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_MSI_BASE_LSB_INI(base,n))
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_MSI_ADDR_LSB_BMSK                                     0xffffffff
#define HWIO_EE_n_CNTXT_MSI_BASE_LSB_MSI_ADDR_LSB_SHFT                                            0x0

#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_ADDR(base,n)                                          ((base) + 0x0001e18c + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_OFFS(base,n)                                          (0x0001e18c + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_RMSK                                                  0xffffffff
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_MAXn                                                          14
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_MSI_BASE_MSB_ADDR(base,n), HWIO_EE_n_CNTXT_MSI_BASE_MSB_RMSK)
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_MSI_BASE_MSB_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_MSI_BASE_MSB_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_MSI_BASE_MSB_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_MSI_BASE_MSB_INI(base,n))
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_MSI_ADDR_MSB_BMSK                                     0xffffffff
#define HWIO_EE_n_CNTXT_MSI_BASE_MSB_MSI_ADDR_MSB_SHFT                                            0x0

#define HWIO_EE_n_CNTXT_INT_VEC_ADDR(base,n)                                               ((base) + 0x0001e190 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_INT_VEC_OFFS(base,n)                                               (0x0001e190 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_INT_VEC_RMSK                                                       0xffffffff
#define HWIO_EE_n_CNTXT_INT_VEC_MAXn                                                               14
#define HWIO_EE_n_CNTXT_INT_VEC_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_INT_VEC_ADDR(base,n), HWIO_EE_n_CNTXT_INT_VEC_RMSK)
#define HWIO_EE_n_CNTXT_INT_VEC_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_INT_VEC_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_INT_VEC_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_INT_VEC_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_INT_VEC_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_INT_VEC_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_INT_VEC_INI(base,n))
#define HWIO_EE_n_CNTXT_INT_VEC_INT_VEC_BMSK                                               0xffffffff
#define HWIO_EE_n_CNTXT_INT_VEC_INT_VEC_SHFT                                                      0x0

#define HWIO_EE_n_ERROR_LOG_ADDR(base,n)                                                   ((base) + 0x0001e200 + 0x4000 * (n))
#define HWIO_EE_n_ERROR_LOG_OFFS(base,n)                                                   (0x0001e200 + 0x4000 * (n))
#define HWIO_EE_n_ERROR_LOG_RMSK                                                           0xffffffff
#define HWIO_EE_n_ERROR_LOG_MAXn                                                                   14
#define HWIO_EE_n_ERROR_LOG_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_ERROR_LOG_ADDR(base,n), HWIO_EE_n_ERROR_LOG_RMSK)
#define HWIO_EE_n_ERROR_LOG_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_ERROR_LOG_ADDR(base,n), mask)
#define HWIO_EE_n_ERROR_LOG_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_ERROR_LOG_ADDR(base,n),val)
#define HWIO_EE_n_ERROR_LOG_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_ERROR_LOG_ADDR(base,n),mask,val,HWIO_EE_n_ERROR_LOG_INI(base,n))
#define HWIO_EE_n_ERROR_LOG_ERROR_LOG_BMSK                                                 0xffffffff
#define HWIO_EE_n_ERROR_LOG_ERROR_LOG_SHFT                                                        0x0

#define HWIO_EE_n_ERROR_LOG_CLR_ADDR(base,n)                                               ((base) + 0x0001e210 + 0x4000 * (n))
#define HWIO_EE_n_ERROR_LOG_CLR_OFFS(base,n)                                               (0x0001e210 + 0x4000 * (n))
#define HWIO_EE_n_ERROR_LOG_CLR_RMSK                                                       0xffffffff
#define HWIO_EE_n_ERROR_LOG_CLR_MAXn                                                               14
#define HWIO_EE_n_ERROR_LOG_CLR_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_ERROR_LOG_CLR_ADDR(base,n),val)
#define HWIO_EE_n_ERROR_LOG_CLR_ERROR_LOG_CLR_BMSK                                         0xffffffff
#define HWIO_EE_n_ERROR_LOG_CLR_ERROR_LOG_CLR_SHFT                                                0x0

#define HWIO_EE_n_CNTXT_SCRATCH_0_ADDR(base,n)                                             ((base) + 0x0001e400 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SCRATCH_0_OFFS(base,n)                                             (0x0001e400 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SCRATCH_0_RMSK                                                     0xffffffff
#define HWIO_EE_n_CNTXT_SCRATCH_0_MAXn                                                             14
#define HWIO_EE_n_CNTXT_SCRATCH_0_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SCRATCH_0_ADDR(base,n), HWIO_EE_n_CNTXT_SCRATCH_0_RMSK)
#define HWIO_EE_n_CNTXT_SCRATCH_0_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SCRATCH_0_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SCRATCH_0_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SCRATCH_0_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SCRATCH_0_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_SCRATCH_0_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_SCRATCH_0_INI(base,n))
#define HWIO_EE_n_CNTXT_SCRATCH_0_SCRATCH_BMSK                                             0xffffffff
#define HWIO_EE_n_CNTXT_SCRATCH_0_SCRATCH_SHFT                                                    0x0

#define HWIO_EE_n_CNTXT_SCRATCH_1_ADDR(base,n)                                             ((base) + 0x0001e404 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SCRATCH_1_OFFS(base,n)                                             (0x0001e404 + 0x4000 * (n))
#define HWIO_EE_n_CNTXT_SCRATCH_1_RMSK                                                     0xffffffff
#define HWIO_EE_n_CNTXT_SCRATCH_1_MAXn                                                             14
#define HWIO_EE_n_CNTXT_SCRATCH_1_INI(base,n)        \
        in_dword_masked(HWIO_EE_n_CNTXT_SCRATCH_1_ADDR(base,n), HWIO_EE_n_CNTXT_SCRATCH_1_RMSK)
#define HWIO_EE_n_CNTXT_SCRATCH_1_INMI(base,n,mask)    \
        in_dword_masked(HWIO_EE_n_CNTXT_SCRATCH_1_ADDR(base,n), mask)
#define HWIO_EE_n_CNTXT_SCRATCH_1_OUTI(base,n,val)    \
        out_dword(HWIO_EE_n_CNTXT_SCRATCH_1_ADDR(base,n),val)
#define HWIO_EE_n_CNTXT_SCRATCH_1_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_EE_n_CNTXT_SCRATCH_1_ADDR(base,n),mask,val,HWIO_EE_n_CNTXT_SCRATCH_1_INI(base,n))
#define HWIO_EE_n_CNTXT_SCRATCH_1_SCRATCH_BMSK                                             0xffffffff
#define HWIO_EE_n_CNTXT_SCRATCH_1_SCRATCH_SHFT                                                    0x0

#define HWIO_GSI_MCS_CFG_ADDR(x)                                                           ((x) + 0x0000b000)
#define HWIO_GSI_MCS_CFG_OFFS                                                              (0x0000b000)
#define HWIO_GSI_MCS_CFG_RMSK                                                                     0x1
#define HWIO_GSI_MCS_CFG_IN(x)      \
        in_dword(HWIO_GSI_MCS_CFG_ADDR(x))
#define HWIO_GSI_MCS_CFG_INM(x, m)      \
        in_dword_masked(HWIO_GSI_MCS_CFG_ADDR(x), m)
#define HWIO_GSI_MCS_CFG_OUT(x, v)      \
        out_dword(HWIO_GSI_MCS_CFG_ADDR(x),v)
#define HWIO_GSI_MCS_CFG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_MCS_CFG_ADDR(x),m,v,HWIO_GSI_MCS_CFG_IN(x))
#define HWIO_GSI_MCS_CFG_MCS_ENABLE_BMSK                                                          0x1
#define HWIO_GSI_MCS_CFG_MCS_ENABLE_SHFT                                                          0x0

#define HWIO_GSI_TZ_FW_AUTH_LOCK_ADDR(x)                                                   ((x) + 0x0000b008)
#define HWIO_GSI_TZ_FW_AUTH_LOCK_OFFS                                                      (0x0000b008)
#define HWIO_GSI_TZ_FW_AUTH_LOCK_RMSK                                                             0x3
#define HWIO_GSI_TZ_FW_AUTH_LOCK_IN(x)      \
        in_dword(HWIO_GSI_TZ_FW_AUTH_LOCK_ADDR(x))
#define HWIO_GSI_TZ_FW_AUTH_LOCK_INM(x, m)      \
        in_dword_masked(HWIO_GSI_TZ_FW_AUTH_LOCK_ADDR(x), m)
#define HWIO_GSI_TZ_FW_AUTH_LOCK_OUT(x, v)      \
        out_dword(HWIO_GSI_TZ_FW_AUTH_LOCK_ADDR(x),v)
#define HWIO_GSI_TZ_FW_AUTH_LOCK_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_TZ_FW_AUTH_LOCK_ADDR(x),m,v,HWIO_GSI_TZ_FW_AUTH_LOCK_IN(x))
#define HWIO_GSI_TZ_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                                       0x2
#define HWIO_GSI_TZ_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                                       0x1
#define HWIO_GSI_TZ_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                              0x1
#define HWIO_GSI_TZ_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                              0x0

#define HWIO_GSI_MSA_FW_AUTH_LOCK_ADDR(x)                                                  ((x) + 0x0000b010)
#define HWIO_GSI_MSA_FW_AUTH_LOCK_OFFS                                                     (0x0000b010)
#define HWIO_GSI_MSA_FW_AUTH_LOCK_RMSK                                                            0x3
#define HWIO_GSI_MSA_FW_AUTH_LOCK_IN(x)      \
        in_dword(HWIO_GSI_MSA_FW_AUTH_LOCK_ADDR(x))
#define HWIO_GSI_MSA_FW_AUTH_LOCK_INM(x, m)      \
        in_dword_masked(HWIO_GSI_MSA_FW_AUTH_LOCK_ADDR(x), m)
#define HWIO_GSI_MSA_FW_AUTH_LOCK_OUT(x, v)      \
        out_dword(HWIO_GSI_MSA_FW_AUTH_LOCK_ADDR(x),v)
#define HWIO_GSI_MSA_FW_AUTH_LOCK_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_MSA_FW_AUTH_LOCK_ADDR(x),m,v,HWIO_GSI_MSA_FW_AUTH_LOCK_IN(x))
#define HWIO_GSI_MSA_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                                      0x2
#define HWIO_GSI_MSA_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                                      0x1
#define HWIO_GSI_MSA_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                             0x1
#define HWIO_GSI_MSA_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                             0x0

#define HWIO_GSI_SP_FW_AUTH_LOCK_ADDR(x)                                                   ((x) + 0x0000b018)
#define HWIO_GSI_SP_FW_AUTH_LOCK_OFFS                                                      (0x0000b018)
#define HWIO_GSI_SP_FW_AUTH_LOCK_RMSK                                                             0x3
#define HWIO_GSI_SP_FW_AUTH_LOCK_IN(x)      \
        in_dword(HWIO_GSI_SP_FW_AUTH_LOCK_ADDR(x))
#define HWIO_GSI_SP_FW_AUTH_LOCK_INM(x, m)      \
        in_dword_masked(HWIO_GSI_SP_FW_AUTH_LOCK_ADDR(x), m)
#define HWIO_GSI_SP_FW_AUTH_LOCK_OUT(x, v)      \
        out_dword(HWIO_GSI_SP_FW_AUTH_LOCK_ADDR(x),v)
#define HWIO_GSI_SP_FW_AUTH_LOCK_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_GSI_SP_FW_AUTH_LOCK_ADDR(x),m,v,HWIO_GSI_SP_FW_AUTH_LOCK_IN(x))
#define HWIO_GSI_SP_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_BMSK                                       0x2
#define HWIO_GSI_SP_FW_AUTH_LOCK_DIS_DEBUG_SHRAM_WRITE_SHFT                                       0x1
#define HWIO_GSI_SP_FW_AUTH_LOCK_DIS_IRAM_WRITE_BMSK                                              0x1
#define HWIO_GSI_SP_FW_AUTH_LOCK_DIS_IRAM_WRITE_SHFT                                              0x0


#endif /* __GSIHWIO_H__ */
