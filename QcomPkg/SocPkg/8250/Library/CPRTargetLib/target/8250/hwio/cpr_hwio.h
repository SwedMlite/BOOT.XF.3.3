#ifndef __CPR_HWIO_H__
#define __CPR_HWIO_H__
/*
===========================================================================
*/
/**
  @file cpr_hwio.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) [kona_v1.0_p3q2r17.8_MTO]
 
  This file contains HWIO register definitions for the following modules:
    CX_CPR3


  Generation parameters: 
  { u'explicit-addressing': True,
    u'filename': u'cpr_hwio.h',
    u'header': u'#include "msmhwiobase.h"\n#include "msmhwio.h"',
    u'ignore-prefixes': True,
    u'module-filter-exclude': { },
    u'module-filter-include': { },
    u'modules': [u'CX_CPR3'],
    u'output-fvals': True,
    u'output-offsets': True}
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/CPRTargetLib/target/8250/hwio/cpr_hwio.h#3 $
  $DateTime: 2019/01/25 09:55:02 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "msmhwiobase.h"
#include "msmhwio.h"

/*----------------------------------------------------------------------------
 * MODULE: CX_CPR3
 *--------------------------------------------------------------------------*/

#define CX_CPR3_REG_BASE                                                             (CX_CPR3_BASE      + 0x00000000)
#define CX_CPR3_REG_BASE_SIZE                                                        0x4000
#define CX_CPR3_REG_BASE_USED                                                        0x3288
#define CX_CPR3_REG_BASE_OFFS                                                        0x00000000

#define HWIO_CPR_VERSION_ADDR(x)                                                     ((x) + 0x00000000)
#define HWIO_CPR_VERSION_OFFS                                                        (0x00000000)
#define HWIO_CPR_VERSION_RMSK                                                        0xffffffff
#define HWIO_CPR_VERSION_IN(x)      \
        in_dword(HWIO_CPR_VERSION_ADDR(x))
#define HWIO_CPR_VERSION_INM(x, m)      \
        in_dword_masked(HWIO_CPR_VERSION_ADDR(x), m)
#define HWIO_CPR_VERSION_MAJOR_BMSK                                                  0xf0000000
#define HWIO_CPR_VERSION_MAJOR_SHFT                                                        0x1c
#define HWIO_CPR_VERSION_MINOR_BMSK                                                   0xfff0000
#define HWIO_CPR_VERSION_MINOR_SHFT                                                        0x10
#define HWIO_CPR_VERSION_STEP_BMSK                                                       0xffff
#define HWIO_CPR_VERSION_STEP_SHFT                                                          0x0

#define HWIO_CPR_FSM_CTL_ADDR(x)                                                     ((x) + 0x00000004)
#define HWIO_CPR_FSM_CTL_OFFS                                                        (0x00000004)
#define HWIO_CPR_FSM_CTL_RMSK                                                        0xffffffff
#define HWIO_CPR_FSM_CTL_IN(x)      \
        in_dword(HWIO_CPR_FSM_CTL_ADDR(x))
#define HWIO_CPR_FSM_CTL_INM(x, m)      \
        in_dword_masked(HWIO_CPR_FSM_CTL_ADDR(x), m)
#define HWIO_CPR_FSM_CTL_OUT(x, v)      \
        out_dword(HWIO_CPR_FSM_CTL_ADDR(x),v)
#define HWIO_CPR_FSM_CTL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_FSM_CTL_ADDR(x),m,v,HWIO_CPR_FSM_CTL_IN(x))
#define HWIO_CPR_FSM_CTL_COUNT_REPEAT_BMSK                                           0xfffffe00
#define HWIO_CPR_FSM_CTL_COUNT_REPEAT_SHFT                                                  0x9
#define HWIO_CPR_FSM_CTL_SET_HTOL_MODE_BMSK                                               0x100
#define HWIO_CPR_FSM_CTL_SET_HTOL_MODE_SHFT                                                 0x8
#define HWIO_CPR_FSM_CTL_COUNT_MODE_BMSK                                                   0xc0
#define HWIO_CPR_FSM_CTL_COUNT_MODE_SHFT                                                    0x6
#define HWIO_CPR_FSM_CTL_IDLE_CLOCKS_BMSK                                                  0x3e
#define HWIO_CPR_FSM_CTL_IDLE_CLOCKS_SHFT                                                   0x1
#define HWIO_CPR_FSM_CTL_LOOP_EN_BMSK                                                       0x1
#define HWIO_CPR_FSM_CTL_LOOP_EN_SHFT                                                       0x0

#define HWIO_CPR_FSM_STA_ADDR(x)                                                     ((x) + 0x00000008)
#define HWIO_CPR_FSM_STA_OFFS                                                        (0x00000008)
#define HWIO_CPR_FSM_STA_RMSK                                                               0x3
#define HWIO_CPR_FSM_STA_IN(x)      \
        in_dword(HWIO_CPR_FSM_STA_ADDR(x))
#define HWIO_CPR_FSM_STA_INM(x, m)      \
        in_dword_masked(HWIO_CPR_FSM_STA_ADDR(x), m)
#define HWIO_CPR_FSM_STA_PAGE_IS_AGE_BMSK                                                   0x2
#define HWIO_CPR_FSM_STA_PAGE_IS_AGE_SHFT                                                   0x1
#define HWIO_CPR_FSM_STA_BUSY_BMSK                                                          0x1
#define HWIO_CPR_FSM_STA_BUSY_SHFT                                                          0x0

#define HWIO_CPR_TIMER_AUTO_CONT_ADDR(x)                                             ((x) + 0x0000000c)
#define HWIO_CPR_TIMER_AUTO_CONT_OFFS                                                (0x0000000c)
#define HWIO_CPR_TIMER_AUTO_CONT_RMSK                                                0xffffffff
#define HWIO_CPR_TIMER_AUTO_CONT_IN(x)      \
        in_dword(HWIO_CPR_TIMER_AUTO_CONT_ADDR(x))
#define HWIO_CPR_TIMER_AUTO_CONT_INM(x, m)      \
        in_dword_masked(HWIO_CPR_TIMER_AUTO_CONT_ADDR(x), m)
#define HWIO_CPR_TIMER_AUTO_CONT_OUT(x, v)      \
        out_dword(HWIO_CPR_TIMER_AUTO_CONT_ADDR(x),v)
#define HWIO_CPR_TIMER_AUTO_CONT_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_TIMER_AUTO_CONT_ADDR(x),m,v,HWIO_CPR_TIMER_AUTO_CONT_IN(x))
#define HWIO_CPR_TIMER_AUTO_CONT_AUTO_CONT_INTERVAL_BMSK                             0xffffffff
#define HWIO_CPR_TIMER_AUTO_CONT_AUTO_CONT_INTERVAL_SHFT                                    0x0

#define HWIO_CPR_TIMER_CLAMP_ADDR(x)                                                 ((x) + 0x00000010)
#define HWIO_CPR_TIMER_CLAMP_OFFS                                                    (0x00000010)
#define HWIO_CPR_TIMER_CLAMP_RMSK                                                    0xf80000ff
#define HWIO_CPR_TIMER_CLAMP_IN(x)      \
        in_dword(HWIO_CPR_TIMER_CLAMP_ADDR(x))
#define HWIO_CPR_TIMER_CLAMP_INM(x, m)      \
        in_dword_masked(HWIO_CPR_TIMER_CLAMP_ADDR(x), m)
#define HWIO_CPR_TIMER_CLAMP_OUT(x, v)      \
        out_dword(HWIO_CPR_TIMER_CLAMP_ADDR(x),v)
#define HWIO_CPR_TIMER_CLAMP_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_TIMER_CLAMP_ADDR(x),m,v,HWIO_CPR_TIMER_CLAMP_IN(x))
#define HWIO_CPR_TIMER_CLAMP_CPR_DISABLE_VALID_BMSK                                  0x80000000
#define HWIO_CPR_TIMER_CLAMP_CPR_DISABLE_VALID_SHFT                                        0x1f
#define HWIO_CPR_TIMER_CLAMP_GDHS_RESTART_ENABLE_BMSK                                0x40000000
#define HWIO_CPR_TIMER_CLAMP_GDHS_RESTART_ENABLE_SHFT                                      0x1e
#define HWIO_CPR_TIMER_CLAMP_BHS_ON_RESTART_ENABLE_BMSK                              0x20000000
#define HWIO_CPR_TIMER_CLAMP_BHS_ON_RESTART_ENABLE_SHFT                                    0x1d
#define HWIO_CPR_TIMER_CLAMP_CLEAR_IRQ_WITH_CONT_EN_BMSK                             0x10000000
#define HWIO_CPR_TIMER_CLAMP_CLEAR_IRQ_WITH_CONT_EN_SHFT                                   0x1c
#define HWIO_CPR_TIMER_CLAMP_THREAD_AGGREGATION_EN_BMSK                               0x8000000
#define HWIO_CPR_TIMER_CLAMP_THREAD_AGGREGATION_EN_SHFT                                    0x1b
#define HWIO_CPR_TIMER_CLAMP_CLAMP_TIMER_INTERVAL_BMSK                                     0xff
#define HWIO_CPR_TIMER_CLAMP_CLAMP_TIMER_INTERVAL_SHFT                                      0x0

#define HWIO_CPR_STEP_QUOT_INIT_ADDR(x)                                              ((x) + 0x00000014)
#define HWIO_CPR_STEP_QUOT_INIT_OFFS                                                 (0x00000014)
#define HWIO_CPR_STEP_QUOT_INIT_RMSK                                                      0xfff
#define HWIO_CPR_STEP_QUOT_INIT_IN(x)      \
        in_dword(HWIO_CPR_STEP_QUOT_INIT_ADDR(x))
#define HWIO_CPR_STEP_QUOT_INIT_INM(x, m)      \
        in_dword_masked(HWIO_CPR_STEP_QUOT_INIT_ADDR(x), m)
#define HWIO_CPR_STEP_QUOT_INIT_OUT(x, v)      \
        out_dword(HWIO_CPR_STEP_QUOT_INIT_ADDR(x),v)
#define HWIO_CPR_STEP_QUOT_INIT_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_STEP_QUOT_INIT_ADDR(x),m,v,HWIO_CPR_STEP_QUOT_INIT_IN(x))
#define HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MAX_BMSK                                   0xfc0
#define HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MAX_SHFT                                     0x6
#define HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MIN_BMSK                                    0x3f
#define HWIO_CPR_STEP_QUOT_INIT_STEP_QUOT_INIT_MIN_SHFT                                     0x0

#define HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(x)                                           ((x) + 0x00000020)
#define HWIO_CPR_BIST_CHAIN_CHECK0_OFFS                                              (0x00000020)
#define HWIO_CPR_BIST_CHAIN_CHECK0_RMSK                                              0x80000fff
#define HWIO_CPR_BIST_CHAIN_CHECK0_IN(x)      \
        in_dword(HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(x))
#define HWIO_CPR_BIST_CHAIN_CHECK0_INM(x, m)      \
        in_dword_masked(HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(x), m)
#define HWIO_CPR_BIST_CHAIN_CHECK0_OUT(x, v)      \
        out_dword(HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(x),v)
#define HWIO_CPR_BIST_CHAIN_CHECK0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_BIST_CHAIN_CHECK0_ADDR(x),m,v,HWIO_CPR_BIST_CHAIN_CHECK0_IN(x))
#define HWIO_CPR_BIST_CHAIN_CHECK0_EN_CHAIN_CHECK_BMSK                               0x80000000
#define HWIO_CPR_BIST_CHAIN_CHECK0_EN_CHAIN_CHECK_SHFT                                     0x1f
#define HWIO_CPR_BIST_CHAIN_CHECK0_SCLK_CNT_EXPECTED_BMSK                                 0xfff
#define HWIO_CPR_BIST_CHAIN_CHECK0_SCLK_CNT_EXPECTED_SHFT                                   0x0

#define HWIO_CPR_BIST_CHAIN_CHECK1_ADDR(x)                                           ((x) + 0x00000024)
#define HWIO_CPR_BIST_CHAIN_CHECK1_OFFS                                              (0x00000024)
#define HWIO_CPR_BIST_CHAIN_CHECK1_RMSK                                              0xe0ffffff
#define HWIO_CPR_BIST_CHAIN_CHECK1_IN(x)      \
        in_dword(HWIO_CPR_BIST_CHAIN_CHECK1_ADDR(x))
#define HWIO_CPR_BIST_CHAIN_CHECK1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_BIST_CHAIN_CHECK1_ADDR(x), m)
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT_DONE_BMSK                                0x80000000
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT_DONE_SHFT                                      0x1f
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT_FAIL_BMSK                                0x60000000
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT_FAIL_SHFT                                      0x1d
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT1_BMSK                                      0xfff000
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT1_SHFT                                           0xc
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT0_BMSK                                         0xfff
#define HWIO_CPR_BIST_CHAIN_CHECK1_SCLK_CNT0_SHFT                                           0x0

#define HWIO_CPR_BIST_QUOT_CHECK0_ADDR(x)                                            ((x) + 0x00000028)
#define HWIO_CPR_BIST_QUOT_CHECK0_OFFS                                               (0x00000028)
#define HWIO_CPR_BIST_QUOT_CHECK0_RMSK                                               0x80ffffff
#define HWIO_CPR_BIST_QUOT_CHECK0_IN(x)      \
        in_dword(HWIO_CPR_BIST_QUOT_CHECK0_ADDR(x))
#define HWIO_CPR_BIST_QUOT_CHECK0_INM(x, m)      \
        in_dword_masked(HWIO_CPR_BIST_QUOT_CHECK0_ADDR(x), m)
#define HWIO_CPR_BIST_QUOT_CHECK0_OUT(x, v)      \
        out_dword(HWIO_CPR_BIST_QUOT_CHECK0_ADDR(x),v)
#define HWIO_CPR_BIST_QUOT_CHECK0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_BIST_QUOT_CHECK0_ADDR(x),m,v,HWIO_CPR_BIST_QUOT_CHECK0_IN(x))
#define HWIO_CPR_BIST_QUOT_CHECK0_FAIL_BMSK                                          0x80000000
#define HWIO_CPR_BIST_QUOT_CHECK0_FAIL_SHFT                                                0x1f
#define HWIO_CPR_BIST_QUOT_CHECK0_QUOT_ABSMAX_BMSK                                     0xfff000
#define HWIO_CPR_BIST_QUOT_CHECK0_QUOT_ABSMAX_SHFT                                          0xc
#define HWIO_CPR_BIST_QUOT_CHECK0_QUOT_ABSMIN_BMSK                                        0xfff
#define HWIO_CPR_BIST_QUOT_CHECK0_QUOT_ABSMIN_SHFT                                          0x0

#define HWIO_CPR_BIST_QUOT_CHECK1_ADDR(x)                                            ((x) + 0x0000002c)
#define HWIO_CPR_BIST_QUOT_CHECK1_OFFS                                               (0x0000002c)
#define HWIO_CPR_BIST_QUOT_CHECK1_RMSK                                               0xffffffff
#define HWIO_CPR_BIST_QUOT_CHECK1_IN(x)      \
        in_dword(HWIO_CPR_BIST_QUOT_CHECK1_ADDR(x))
#define HWIO_CPR_BIST_QUOT_CHECK1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_BIST_QUOT_CHECK1_ADDR(x), m)
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_SEL_MAX_BMSK                                  0xf0000000
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_SEL_MAX_SHFT                                        0x1c
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_SEL_MIN_BMSK                                   0xf000000
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_SEL_MIN_SHFT                                        0x18
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_QUOT_MAX_BMSK                                   0xfff000
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_QUOT_MAX_SHFT                                        0xc
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_QUOT_MIN_BMSK                                      0xfff
#define HWIO_CPR_BIST_QUOT_CHECK1_FAIL_QUOT_MIN_SHFT                                        0x0

#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_ADDR(base,n)                                    ((base) + 0x00000030 + 0x4 * (n))
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_OFFS(base,n)                                    (0x00000030 + 0x4 * (n))
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_RMSK                                            0xffffffff
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_MAXn                                                     1
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_INI(base,n)        \
        in_dword_masked(HWIO_CPR_BIST_FAIL_MAP_MIN_n_ADDR(base,n), HWIO_CPR_BIST_FAIL_MAP_MIN_n_RMSK)
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_BIST_FAIL_MAP_MIN_n_ADDR(base,n), mask)
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_BIST_FAIL_MAP_MIN_BMSK                          0xffffffff
#define HWIO_CPR_BIST_FAIL_MAP_MIN_n_BIST_FAIL_MAP_MIN_SHFT                                 0x0

#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_ADDR(base,n)                                    ((base) + 0x00000050 + 0x4 * (n))
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_OFFS(base,n)                                    (0x00000050 + 0x4 * (n))
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_RMSK                                            0xffffffff
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_MAXn                                                     1
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_INI(base,n)        \
        in_dword_masked(HWIO_CPR_BIST_FAIL_MAP_MAX_n_ADDR(base,n), HWIO_CPR_BIST_FAIL_MAP_MAX_n_RMSK)
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_BIST_FAIL_MAP_MAX_n_ADDR(base,n), mask)
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_BIST_FAIL_MAP_MAX_BMSK                          0xffffffff
#define HWIO_CPR_BIST_FAIL_MAP_MAX_n_BIST_FAIL_MAP_MAX_SHFT                                 0x0

#define HWIO_CPR_DEBUG_ADDR(x)                                                       ((x) + 0x00000070)
#define HWIO_CPR_DEBUG_OFFS                                                          (0x00000070)
#define HWIO_CPR_DEBUG_RMSK                                                              0x3fff
#define HWIO_CPR_DEBUG_IN(x)      \
        in_dword(HWIO_CPR_DEBUG_ADDR(x))
#define HWIO_CPR_DEBUG_INM(x, m)      \
        in_dword_masked(HWIO_CPR_DEBUG_ADDR(x), m)
#define HWIO_CPR_DEBUG_OUT(x, v)      \
        out_dword(HWIO_CPR_DEBUG_ADDR(x),v)
#define HWIO_CPR_DEBUG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_DEBUG_ADDR(x),m,v,HWIO_CPR_DEBUG_IN(x))
#define HWIO_CPR_DEBUG_DEBUG_RO_SEL_BMSK                                                 0x3f00
#define HWIO_CPR_DEBUG_DEBUG_RO_SEL_SHFT                                                    0x8
#define HWIO_CPR_DEBUG_CPR_LOG_THREAD_SEL_BMSK                                             0xe0
#define HWIO_CPR_DEBUG_CPR_LOG_THREAD_SEL_SHFT                                              0x5
#define HWIO_CPR_DEBUG_DEBUG_BUS_SEL_BMSK                                                  0x1f
#define HWIO_CPR_DEBUG_DEBUG_BUS_SEL_SHFT                                                   0x0

#define HWIO_CPR_DEBUG_LOG_n_ADDR(base,n)                                            ((base) + 0x00000080 + 0x4 * (n))
#define HWIO_CPR_DEBUG_LOG_n_OFFS(base,n)                                            (0x00000080 + 0x4 * (n))
#define HWIO_CPR_DEBUG_LOG_n_RMSK                                                    0x3fff000e
#define HWIO_CPR_DEBUG_LOG_n_MAXn                                                             7
#define HWIO_CPR_DEBUG_LOG_n_INI(base,n)        \
        in_dword_masked(HWIO_CPR_DEBUG_LOG_n_ADDR(base,n), HWIO_CPR_DEBUG_LOG_n_RMSK)
#define HWIO_CPR_DEBUG_LOG_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_DEBUG_LOG_n_ADDR(base,n), mask)
#define HWIO_CPR_DEBUG_LOG_n_MID_COUNT_BMSK                                          0x3fff0000
#define HWIO_CPR_DEBUG_LOG_n_MID_COUNT_SHFT                                                0x10
#define HWIO_CPR_DEBUG_LOG_n_UP_FLAG_BMSK                                                   0x8
#define HWIO_CPR_DEBUG_LOG_n_UP_FLAG_SHFT                                                   0x3
#define HWIO_CPR_DEBUG_LOG_n_MID_FLAG_BMSK                                                  0x4
#define HWIO_CPR_DEBUG_LOG_n_MID_FLAG_SHFT                                                  0x2
#define HWIO_CPR_DEBUG_LOG_n_DOWN_FLAG_BMSK                                                 0x2
#define HWIO_CPR_DEBUG_LOG_n_DOWN_FLAG_SHFT                                                 0x1

#define HWIO_CPR_GCNT0_ADDR(x)                                                       ((x) + 0x000000a0)
#define HWIO_CPR_GCNT0_OFFS                                                          (0x000000a0)
#define HWIO_CPR_GCNT0_RMSK                                                              0xffff
#define HWIO_CPR_GCNT0_IN(x)      \
        in_dword(HWIO_CPR_GCNT0_ADDR(x))
#define HWIO_CPR_GCNT0_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT0_ADDR(x), m)
#define HWIO_CPR_GCNT0_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT0_ADDR(x),v)
#define HWIO_CPR_GCNT0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT0_ADDR(x),m,v,HWIO_CPR_GCNT0_IN(x))
#define HWIO_CPR_GCNT0_STEP_QUOT_INIT_PER_RO_KV0_BMSK                                    0xfc00
#define HWIO_CPR_GCNT0_STEP_QUOT_INIT_PER_RO_KV0_SHFT                                       0xa
#define HWIO_CPR_GCNT0_GCNT0_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT0_GCNT0_SHFT                                                           0x0

#define HWIO_CPR_GCNT1_ADDR(x)                                                       ((x) + 0x000000a4)
#define HWIO_CPR_GCNT1_OFFS                                                          (0x000000a4)
#define HWIO_CPR_GCNT1_RMSK                                                              0xffff
#define HWIO_CPR_GCNT1_IN(x)      \
        in_dword(HWIO_CPR_GCNT1_ADDR(x))
#define HWIO_CPR_GCNT1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT1_ADDR(x), m)
#define HWIO_CPR_GCNT1_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT1_ADDR(x),v)
#define HWIO_CPR_GCNT1_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT1_ADDR(x),m,v,HWIO_CPR_GCNT1_IN(x))
#define HWIO_CPR_GCNT1_STEP_QUOT_INIT_PER_RO_KV1_BMSK                                    0xfc00
#define HWIO_CPR_GCNT1_STEP_QUOT_INIT_PER_RO_KV1_SHFT                                       0xa
#define HWIO_CPR_GCNT1_GCNT1_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT1_GCNT1_SHFT                                                           0x0

#define HWIO_CPR_GCNT2_ADDR(x)                                                       ((x) + 0x000000a8)
#define HWIO_CPR_GCNT2_OFFS                                                          (0x000000a8)
#define HWIO_CPR_GCNT2_RMSK                                                              0xffff
#define HWIO_CPR_GCNT2_IN(x)      \
        in_dword(HWIO_CPR_GCNT2_ADDR(x))
#define HWIO_CPR_GCNT2_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT2_ADDR(x), m)
#define HWIO_CPR_GCNT2_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT2_ADDR(x),v)
#define HWIO_CPR_GCNT2_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT2_ADDR(x),m,v,HWIO_CPR_GCNT2_IN(x))
#define HWIO_CPR_GCNT2_STEP_QUOT_INIT_PER_RO_KV2_BMSK                                    0xfc00
#define HWIO_CPR_GCNT2_STEP_QUOT_INIT_PER_RO_KV2_SHFT                                       0xa
#define HWIO_CPR_GCNT2_GCNT2_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT2_GCNT2_SHFT                                                           0x0

#define HWIO_CPR_GCNT3_ADDR(x)                                                       ((x) + 0x000000ac)
#define HWIO_CPR_GCNT3_OFFS                                                          (0x000000ac)
#define HWIO_CPR_GCNT3_RMSK                                                              0xffff
#define HWIO_CPR_GCNT3_IN(x)      \
        in_dword(HWIO_CPR_GCNT3_ADDR(x))
#define HWIO_CPR_GCNT3_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT3_ADDR(x), m)
#define HWIO_CPR_GCNT3_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT3_ADDR(x),v)
#define HWIO_CPR_GCNT3_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT3_ADDR(x),m,v,HWIO_CPR_GCNT3_IN(x))
#define HWIO_CPR_GCNT3_STEP_QUOT_INIT_PER_RO_KV3_BMSK                                    0xfc00
#define HWIO_CPR_GCNT3_STEP_QUOT_INIT_PER_RO_KV3_SHFT                                       0xa
#define HWIO_CPR_GCNT3_GCNT3_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT3_GCNT3_SHFT                                                           0x0

#define HWIO_CPR_GCNT4_ADDR(x)                                                       ((x) + 0x000000b0)
#define HWIO_CPR_GCNT4_OFFS                                                          (0x000000b0)
#define HWIO_CPR_GCNT4_RMSK                                                              0xffff
#define HWIO_CPR_GCNT4_IN(x)      \
        in_dword(HWIO_CPR_GCNT4_ADDR(x))
#define HWIO_CPR_GCNT4_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT4_ADDR(x), m)
#define HWIO_CPR_GCNT4_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT4_ADDR(x),v)
#define HWIO_CPR_GCNT4_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT4_ADDR(x),m,v,HWIO_CPR_GCNT4_IN(x))
#define HWIO_CPR_GCNT4_STEP_QUOT_INIT_PER_RO_KV4_BMSK                                    0xfc00
#define HWIO_CPR_GCNT4_STEP_QUOT_INIT_PER_RO_KV4_SHFT                                       0xa
#define HWIO_CPR_GCNT4_GCNT4_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT4_GCNT4_SHFT                                                           0x0

#define HWIO_CPR_GCNT5_ADDR(x)                                                       ((x) + 0x000000b4)
#define HWIO_CPR_GCNT5_OFFS                                                          (0x000000b4)
#define HWIO_CPR_GCNT5_RMSK                                                              0xffff
#define HWIO_CPR_GCNT5_IN(x)      \
        in_dword(HWIO_CPR_GCNT5_ADDR(x))
#define HWIO_CPR_GCNT5_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT5_ADDR(x), m)
#define HWIO_CPR_GCNT5_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT5_ADDR(x),v)
#define HWIO_CPR_GCNT5_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT5_ADDR(x),m,v,HWIO_CPR_GCNT5_IN(x))
#define HWIO_CPR_GCNT5_STEP_QUOT_INIT_PER_RO_KV5_BMSK                                    0xfc00
#define HWIO_CPR_GCNT5_STEP_QUOT_INIT_PER_RO_KV5_SHFT                                       0xa
#define HWIO_CPR_GCNT5_GCNT5_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT5_GCNT5_SHFT                                                           0x0

#define HWIO_CPR_GCNT6_ADDR(x)                                                       ((x) + 0x000000b8)
#define HWIO_CPR_GCNT6_OFFS                                                          (0x000000b8)
#define HWIO_CPR_GCNT6_RMSK                                                              0xffff
#define HWIO_CPR_GCNT6_IN(x)      \
        in_dword(HWIO_CPR_GCNT6_ADDR(x))
#define HWIO_CPR_GCNT6_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT6_ADDR(x), m)
#define HWIO_CPR_GCNT6_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT6_ADDR(x),v)
#define HWIO_CPR_GCNT6_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT6_ADDR(x),m,v,HWIO_CPR_GCNT6_IN(x))
#define HWIO_CPR_GCNT6_STEP_QUOT_INIT_PER_RO_KV6_BMSK                                    0xfc00
#define HWIO_CPR_GCNT6_STEP_QUOT_INIT_PER_RO_KV6_SHFT                                       0xa
#define HWIO_CPR_GCNT6_GCNT6_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT6_GCNT6_SHFT                                                           0x0

#define HWIO_CPR_GCNT7_ADDR(x)                                                       ((x) + 0x000000bc)
#define HWIO_CPR_GCNT7_OFFS                                                          (0x000000bc)
#define HWIO_CPR_GCNT7_RMSK                                                              0xffff
#define HWIO_CPR_GCNT7_IN(x)      \
        in_dword(HWIO_CPR_GCNT7_ADDR(x))
#define HWIO_CPR_GCNT7_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT7_ADDR(x), m)
#define HWIO_CPR_GCNT7_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT7_ADDR(x),v)
#define HWIO_CPR_GCNT7_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT7_ADDR(x),m,v,HWIO_CPR_GCNT7_IN(x))
#define HWIO_CPR_GCNT7_STEP_QUOT_INIT_PER_RO_KV7_BMSK                                    0xfc00
#define HWIO_CPR_GCNT7_STEP_QUOT_INIT_PER_RO_KV7_SHFT                                       0xa
#define HWIO_CPR_GCNT7_GCNT7_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT7_GCNT7_SHFT                                                           0x0

#define HWIO_CPR_GCNT8_ADDR(x)                                                       ((x) + 0x000000c0)
#define HWIO_CPR_GCNT8_OFFS                                                          (0x000000c0)
#define HWIO_CPR_GCNT8_RMSK                                                              0xffff
#define HWIO_CPR_GCNT8_IN(x)      \
        in_dword(HWIO_CPR_GCNT8_ADDR(x))
#define HWIO_CPR_GCNT8_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT8_ADDR(x), m)
#define HWIO_CPR_GCNT8_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT8_ADDR(x),v)
#define HWIO_CPR_GCNT8_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT8_ADDR(x),m,v,HWIO_CPR_GCNT8_IN(x))
#define HWIO_CPR_GCNT8_STEP_QUOT_INIT_PER_RO_KV8_BMSK                                    0xfc00
#define HWIO_CPR_GCNT8_STEP_QUOT_INIT_PER_RO_KV8_SHFT                                       0xa
#define HWIO_CPR_GCNT8_GCNT8_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT8_GCNT8_SHFT                                                           0x0

#define HWIO_CPR_GCNT9_ADDR(x)                                                       ((x) + 0x000000c4)
#define HWIO_CPR_GCNT9_OFFS                                                          (0x000000c4)
#define HWIO_CPR_GCNT9_RMSK                                                              0xffff
#define HWIO_CPR_GCNT9_IN(x)      \
        in_dword(HWIO_CPR_GCNT9_ADDR(x))
#define HWIO_CPR_GCNT9_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT9_ADDR(x), m)
#define HWIO_CPR_GCNT9_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT9_ADDR(x),v)
#define HWIO_CPR_GCNT9_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT9_ADDR(x),m,v,HWIO_CPR_GCNT9_IN(x))
#define HWIO_CPR_GCNT9_STEP_QUOT_INIT_PER_RO_KV9_BMSK                                    0xfc00
#define HWIO_CPR_GCNT9_STEP_QUOT_INIT_PER_RO_KV9_SHFT                                       0xa
#define HWIO_CPR_GCNT9_GCNT9_BMSK                                                         0x3ff
#define HWIO_CPR_GCNT9_GCNT9_SHFT                                                           0x0

#define HWIO_CPR_GCNT10_ADDR(x)                                                      ((x) + 0x000000c8)
#define HWIO_CPR_GCNT10_OFFS                                                         (0x000000c8)
#define HWIO_CPR_GCNT10_RMSK                                                             0xffff
#define HWIO_CPR_GCNT10_IN(x)      \
        in_dword(HWIO_CPR_GCNT10_ADDR(x))
#define HWIO_CPR_GCNT10_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT10_ADDR(x), m)
#define HWIO_CPR_GCNT10_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT10_ADDR(x),v)
#define HWIO_CPR_GCNT10_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT10_ADDR(x),m,v,HWIO_CPR_GCNT10_IN(x))
#define HWIO_CPR_GCNT10_STEP_QUOT_INIT_PER_RO_KV10_BMSK                                  0xfc00
#define HWIO_CPR_GCNT10_STEP_QUOT_INIT_PER_RO_KV10_SHFT                                     0xa
#define HWIO_CPR_GCNT10_GCNT10_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT10_GCNT10_SHFT                                                         0x0

#define HWIO_CPR_GCNT11_ADDR(x)                                                      ((x) + 0x000000cc)
#define HWIO_CPR_GCNT11_OFFS                                                         (0x000000cc)
#define HWIO_CPR_GCNT11_RMSK                                                             0xffff
#define HWIO_CPR_GCNT11_IN(x)      \
        in_dword(HWIO_CPR_GCNT11_ADDR(x))
#define HWIO_CPR_GCNT11_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT11_ADDR(x), m)
#define HWIO_CPR_GCNT11_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT11_ADDR(x),v)
#define HWIO_CPR_GCNT11_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT11_ADDR(x),m,v,HWIO_CPR_GCNT11_IN(x))
#define HWIO_CPR_GCNT11_STEP_QUOT_INIT_PER_RO_KV11_BMSK                                  0xfc00
#define HWIO_CPR_GCNT11_STEP_QUOT_INIT_PER_RO_KV11_SHFT                                     0xa
#define HWIO_CPR_GCNT11_GCNT11_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT11_GCNT11_SHFT                                                         0x0

#define HWIO_CPR_GCNT12_ADDR(x)                                                      ((x) + 0x000000d0)
#define HWIO_CPR_GCNT12_OFFS                                                         (0x000000d0)
#define HWIO_CPR_GCNT12_RMSK                                                             0xffff
#define HWIO_CPR_GCNT12_IN(x)      \
        in_dword(HWIO_CPR_GCNT12_ADDR(x))
#define HWIO_CPR_GCNT12_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT12_ADDR(x), m)
#define HWIO_CPR_GCNT12_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT12_ADDR(x),v)
#define HWIO_CPR_GCNT12_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT12_ADDR(x),m,v,HWIO_CPR_GCNT12_IN(x))
#define HWIO_CPR_GCNT12_STEP_QUOT_INIT_PER_RO_KV12_BMSK                                  0xfc00
#define HWIO_CPR_GCNT12_STEP_QUOT_INIT_PER_RO_KV12_SHFT                                     0xa
#define HWIO_CPR_GCNT12_GCNT12_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT12_GCNT12_SHFT                                                         0x0

#define HWIO_CPR_GCNT13_ADDR(x)                                                      ((x) + 0x000000d4)
#define HWIO_CPR_GCNT13_OFFS                                                         (0x000000d4)
#define HWIO_CPR_GCNT13_RMSK                                                             0xffff
#define HWIO_CPR_GCNT13_IN(x)      \
        in_dword(HWIO_CPR_GCNT13_ADDR(x))
#define HWIO_CPR_GCNT13_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT13_ADDR(x), m)
#define HWIO_CPR_GCNT13_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT13_ADDR(x),v)
#define HWIO_CPR_GCNT13_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT13_ADDR(x),m,v,HWIO_CPR_GCNT13_IN(x))
#define HWIO_CPR_GCNT13_STEP_QUOT_INIT_PER_RO_KV13_BMSK                                  0xfc00
#define HWIO_CPR_GCNT13_STEP_QUOT_INIT_PER_RO_KV13_SHFT                                     0xa
#define HWIO_CPR_GCNT13_GCNT13_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT13_GCNT13_SHFT                                                         0x0

#define HWIO_CPR_GCNT14_ADDR(x)                                                      ((x) + 0x000000d8)
#define HWIO_CPR_GCNT14_OFFS                                                         (0x000000d8)
#define HWIO_CPR_GCNT14_RMSK                                                             0xffff
#define HWIO_CPR_GCNT14_IN(x)      \
        in_dword(HWIO_CPR_GCNT14_ADDR(x))
#define HWIO_CPR_GCNT14_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT14_ADDR(x), m)
#define HWIO_CPR_GCNT14_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT14_ADDR(x),v)
#define HWIO_CPR_GCNT14_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT14_ADDR(x),m,v,HWIO_CPR_GCNT14_IN(x))
#define HWIO_CPR_GCNT14_STEP_QUOT_INIT_PER_RO_KV14_BMSK                                  0xfc00
#define HWIO_CPR_GCNT14_STEP_QUOT_INIT_PER_RO_KV14_SHFT                                     0xa
#define HWIO_CPR_GCNT14_GCNT14_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT14_GCNT14_SHFT                                                         0x0

#define HWIO_CPR_GCNT15_ADDR(x)                                                      ((x) + 0x000000dc)
#define HWIO_CPR_GCNT15_OFFS                                                         (0x000000dc)
#define HWIO_CPR_GCNT15_RMSK                                                             0xffff
#define HWIO_CPR_GCNT15_IN(x)      \
        in_dword(HWIO_CPR_GCNT15_ADDR(x))
#define HWIO_CPR_GCNT15_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT15_ADDR(x), m)
#define HWIO_CPR_GCNT15_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT15_ADDR(x),v)
#define HWIO_CPR_GCNT15_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT15_ADDR(x),m,v,HWIO_CPR_GCNT15_IN(x))
#define HWIO_CPR_GCNT15_STEP_QUOT_INIT_PER_RO_KV15_BMSK                                  0xfc00
#define HWIO_CPR_GCNT15_STEP_QUOT_INIT_PER_RO_KV15_SHFT                                     0xa
#define HWIO_CPR_GCNT15_GCNT15_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT15_GCNT15_SHFT                                                         0x0

#define HWIO_CPR_GCNT16_ADDR(x)                                                      ((x) + 0x00000600)
#define HWIO_CPR_GCNT16_OFFS                                                         (0x00000600)
#define HWIO_CPR_GCNT16_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT16_IN(x)      \
        in_dword(HWIO_CPR_GCNT16_ADDR(x))
#define HWIO_CPR_GCNT16_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT16_ADDR(x), m)
#define HWIO_CPR_GCNT16_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT16_ADDR(x),v)
#define HWIO_CPR_GCNT16_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT16_ADDR(x),m,v,HWIO_CPR_GCNT16_IN(x))
#define HWIO_CPR_GCNT16_GCNT16_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT16_GCNT16_SHFT                                                         0x0

#define HWIO_CPR_GCNT17_ADDR(x)                                                      ((x) + 0x00000604)
#define HWIO_CPR_GCNT17_OFFS                                                         (0x00000604)
#define HWIO_CPR_GCNT17_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT17_IN(x)      \
        in_dword(HWIO_CPR_GCNT17_ADDR(x))
#define HWIO_CPR_GCNT17_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT17_ADDR(x), m)
#define HWIO_CPR_GCNT17_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT17_ADDR(x),v)
#define HWIO_CPR_GCNT17_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT17_ADDR(x),m,v,HWIO_CPR_GCNT17_IN(x))
#define HWIO_CPR_GCNT17_GCNT17_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT17_GCNT17_SHFT                                                         0x0

#define HWIO_CPR_GCNT18_ADDR(x)                                                      ((x) + 0x00000608)
#define HWIO_CPR_GCNT18_OFFS                                                         (0x00000608)
#define HWIO_CPR_GCNT18_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT18_IN(x)      \
        in_dword(HWIO_CPR_GCNT18_ADDR(x))
#define HWIO_CPR_GCNT18_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT18_ADDR(x), m)
#define HWIO_CPR_GCNT18_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT18_ADDR(x),v)
#define HWIO_CPR_GCNT18_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT18_ADDR(x),m,v,HWIO_CPR_GCNT18_IN(x))
#define HWIO_CPR_GCNT18_GCNT18_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT18_GCNT18_SHFT                                                         0x0

#define HWIO_CPR_GCNT19_ADDR(x)                                                      ((x) + 0x0000060c)
#define HWIO_CPR_GCNT19_OFFS                                                         (0x0000060c)
#define HWIO_CPR_GCNT19_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT19_IN(x)      \
        in_dword(HWIO_CPR_GCNT19_ADDR(x))
#define HWIO_CPR_GCNT19_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT19_ADDR(x), m)
#define HWIO_CPR_GCNT19_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT19_ADDR(x),v)
#define HWIO_CPR_GCNT19_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT19_ADDR(x),m,v,HWIO_CPR_GCNT19_IN(x))
#define HWIO_CPR_GCNT19_GCNT19_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT19_GCNT19_SHFT                                                         0x0

#define HWIO_CPR_GCNT20_ADDR(x)                                                      ((x) + 0x00000610)
#define HWIO_CPR_GCNT20_OFFS                                                         (0x00000610)
#define HWIO_CPR_GCNT20_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT20_IN(x)      \
        in_dword(HWIO_CPR_GCNT20_ADDR(x))
#define HWIO_CPR_GCNT20_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT20_ADDR(x), m)
#define HWIO_CPR_GCNT20_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT20_ADDR(x),v)
#define HWIO_CPR_GCNT20_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT20_ADDR(x),m,v,HWIO_CPR_GCNT20_IN(x))
#define HWIO_CPR_GCNT20_GCNT20_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT20_GCNT20_SHFT                                                         0x0

#define HWIO_CPR_GCNT21_ADDR(x)                                                      ((x) + 0x00000614)
#define HWIO_CPR_GCNT21_OFFS                                                         (0x00000614)
#define HWIO_CPR_GCNT21_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT21_IN(x)      \
        in_dword(HWIO_CPR_GCNT21_ADDR(x))
#define HWIO_CPR_GCNT21_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT21_ADDR(x), m)
#define HWIO_CPR_GCNT21_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT21_ADDR(x),v)
#define HWIO_CPR_GCNT21_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT21_ADDR(x),m,v,HWIO_CPR_GCNT21_IN(x))
#define HWIO_CPR_GCNT21_GCNT21_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT21_GCNT21_SHFT                                                         0x0

#define HWIO_CPR_GCNT22_ADDR(x)                                                      ((x) + 0x00000618)
#define HWIO_CPR_GCNT22_OFFS                                                         (0x00000618)
#define HWIO_CPR_GCNT22_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT22_IN(x)      \
        in_dword(HWIO_CPR_GCNT22_ADDR(x))
#define HWIO_CPR_GCNT22_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT22_ADDR(x), m)
#define HWIO_CPR_GCNT22_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT22_ADDR(x),v)
#define HWIO_CPR_GCNT22_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT22_ADDR(x),m,v,HWIO_CPR_GCNT22_IN(x))
#define HWIO_CPR_GCNT22_GCNT22_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT22_GCNT22_SHFT                                                         0x0

#define HWIO_CPR_GCNT23_ADDR(x)                                                      ((x) + 0x0000061c)
#define HWIO_CPR_GCNT23_OFFS                                                         (0x0000061c)
#define HWIO_CPR_GCNT23_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT23_IN(x)      \
        in_dword(HWIO_CPR_GCNT23_ADDR(x))
#define HWIO_CPR_GCNT23_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT23_ADDR(x), m)
#define HWIO_CPR_GCNT23_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT23_ADDR(x),v)
#define HWIO_CPR_GCNT23_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT23_ADDR(x),m,v,HWIO_CPR_GCNT23_IN(x))
#define HWIO_CPR_GCNT23_GCNT23_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT23_GCNT23_SHFT                                                         0x0

#define HWIO_CPR_GCNT24_ADDR(x)                                                      ((x) + 0x00000620)
#define HWIO_CPR_GCNT24_OFFS                                                         (0x00000620)
#define HWIO_CPR_GCNT24_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT24_IN(x)      \
        in_dword(HWIO_CPR_GCNT24_ADDR(x))
#define HWIO_CPR_GCNT24_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT24_ADDR(x), m)
#define HWIO_CPR_GCNT24_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT24_ADDR(x),v)
#define HWIO_CPR_GCNT24_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT24_ADDR(x),m,v,HWIO_CPR_GCNT24_IN(x))
#define HWIO_CPR_GCNT24_GCNT24_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT24_GCNT24_SHFT                                                         0x0

#define HWIO_CPR_GCNT25_ADDR(x)                                                      ((x) + 0x00000624)
#define HWIO_CPR_GCNT25_OFFS                                                         (0x00000624)
#define HWIO_CPR_GCNT25_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT25_IN(x)      \
        in_dword(HWIO_CPR_GCNT25_ADDR(x))
#define HWIO_CPR_GCNT25_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT25_ADDR(x), m)
#define HWIO_CPR_GCNT25_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT25_ADDR(x),v)
#define HWIO_CPR_GCNT25_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT25_ADDR(x),m,v,HWIO_CPR_GCNT25_IN(x))
#define HWIO_CPR_GCNT25_GCNT25_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT25_GCNT25_SHFT                                                         0x0

#define HWIO_CPR_GCNT26_ADDR(x)                                                      ((x) + 0x00000628)
#define HWIO_CPR_GCNT26_OFFS                                                         (0x00000628)
#define HWIO_CPR_GCNT26_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT26_IN(x)      \
        in_dword(HWIO_CPR_GCNT26_ADDR(x))
#define HWIO_CPR_GCNT26_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT26_ADDR(x), m)
#define HWIO_CPR_GCNT26_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT26_ADDR(x),v)
#define HWIO_CPR_GCNT26_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT26_ADDR(x),m,v,HWIO_CPR_GCNT26_IN(x))
#define HWIO_CPR_GCNT26_GCNT26_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT26_GCNT26_SHFT                                                         0x0

#define HWIO_CPR_GCNT27_ADDR(x)                                                      ((x) + 0x0000062c)
#define HWIO_CPR_GCNT27_OFFS                                                         (0x0000062c)
#define HWIO_CPR_GCNT27_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT27_IN(x)      \
        in_dword(HWIO_CPR_GCNT27_ADDR(x))
#define HWIO_CPR_GCNT27_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT27_ADDR(x), m)
#define HWIO_CPR_GCNT27_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT27_ADDR(x),v)
#define HWIO_CPR_GCNT27_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT27_ADDR(x),m,v,HWIO_CPR_GCNT27_IN(x))
#define HWIO_CPR_GCNT27_GCNT27_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT27_GCNT27_SHFT                                                         0x0

#define HWIO_CPR_GCNT28_ADDR(x)                                                      ((x) + 0x00000630)
#define HWIO_CPR_GCNT28_OFFS                                                         (0x00000630)
#define HWIO_CPR_GCNT28_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT28_IN(x)      \
        in_dword(HWIO_CPR_GCNT28_ADDR(x))
#define HWIO_CPR_GCNT28_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT28_ADDR(x), m)
#define HWIO_CPR_GCNT28_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT28_ADDR(x),v)
#define HWIO_CPR_GCNT28_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT28_ADDR(x),m,v,HWIO_CPR_GCNT28_IN(x))
#define HWIO_CPR_GCNT28_GCNT28_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT28_GCNT28_SHFT                                                         0x0

#define HWIO_CPR_GCNT29_ADDR(x)                                                      ((x) + 0x00000634)
#define HWIO_CPR_GCNT29_OFFS                                                         (0x00000634)
#define HWIO_CPR_GCNT29_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT29_IN(x)      \
        in_dword(HWIO_CPR_GCNT29_ADDR(x))
#define HWIO_CPR_GCNT29_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT29_ADDR(x), m)
#define HWIO_CPR_GCNT29_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT29_ADDR(x),v)
#define HWIO_CPR_GCNT29_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT29_ADDR(x),m,v,HWIO_CPR_GCNT29_IN(x))
#define HWIO_CPR_GCNT29_GCNT29_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT29_GCNT29_SHFT                                                         0x0

#define HWIO_CPR_GCNT30_ADDR(x)                                                      ((x) + 0x00000638)
#define HWIO_CPR_GCNT30_OFFS                                                         (0x00000638)
#define HWIO_CPR_GCNT30_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT30_IN(x)      \
        in_dword(HWIO_CPR_GCNT30_ADDR(x))
#define HWIO_CPR_GCNT30_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT30_ADDR(x), m)
#define HWIO_CPR_GCNT30_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT30_ADDR(x),v)
#define HWIO_CPR_GCNT30_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT30_ADDR(x),m,v,HWIO_CPR_GCNT30_IN(x))
#define HWIO_CPR_GCNT30_GCNT30_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT30_GCNT30_SHFT                                                         0x0

#define HWIO_CPR_GCNT31_ADDR(x)                                                      ((x) + 0x0000063c)
#define HWIO_CPR_GCNT31_OFFS                                                         (0x0000063c)
#define HWIO_CPR_GCNT31_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT31_IN(x)      \
        in_dword(HWIO_CPR_GCNT31_ADDR(x))
#define HWIO_CPR_GCNT31_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT31_ADDR(x), m)
#define HWIO_CPR_GCNT31_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT31_ADDR(x),v)
#define HWIO_CPR_GCNT31_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT31_ADDR(x),m,v,HWIO_CPR_GCNT31_IN(x))
#define HWIO_CPR_GCNT31_GCNT31_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT31_GCNT31_SHFT                                                         0x0

#define HWIO_CPR_GCNT32_ADDR(x)                                                      ((x) + 0x00000640)
#define HWIO_CPR_GCNT32_OFFS                                                         (0x00000640)
#define HWIO_CPR_GCNT32_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT32_IN(x)      \
        in_dword(HWIO_CPR_GCNT32_ADDR(x))
#define HWIO_CPR_GCNT32_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT32_ADDR(x), m)
#define HWIO_CPR_GCNT32_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT32_ADDR(x),v)
#define HWIO_CPR_GCNT32_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT32_ADDR(x),m,v,HWIO_CPR_GCNT32_IN(x))
#define HWIO_CPR_GCNT32_GCNT32_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT32_GCNT32_SHFT                                                         0x0

#define HWIO_CPR_GCNT33_ADDR(x)                                                      ((x) + 0x00000644)
#define HWIO_CPR_GCNT33_OFFS                                                         (0x00000644)
#define HWIO_CPR_GCNT33_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT33_IN(x)      \
        in_dword(HWIO_CPR_GCNT33_ADDR(x))
#define HWIO_CPR_GCNT33_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT33_ADDR(x), m)
#define HWIO_CPR_GCNT33_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT33_ADDR(x),v)
#define HWIO_CPR_GCNT33_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT33_ADDR(x),m,v,HWIO_CPR_GCNT33_IN(x))
#define HWIO_CPR_GCNT33_GCNT33_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT33_GCNT33_SHFT                                                         0x0

#define HWIO_CPR_GCNT34_ADDR(x)                                                      ((x) + 0x00000648)
#define HWIO_CPR_GCNT34_OFFS                                                         (0x00000648)
#define HWIO_CPR_GCNT34_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT34_IN(x)      \
        in_dword(HWIO_CPR_GCNT34_ADDR(x))
#define HWIO_CPR_GCNT34_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT34_ADDR(x), m)
#define HWIO_CPR_GCNT34_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT34_ADDR(x),v)
#define HWIO_CPR_GCNT34_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT34_ADDR(x),m,v,HWIO_CPR_GCNT34_IN(x))
#define HWIO_CPR_GCNT34_GCNT34_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT34_GCNT34_SHFT                                                         0x0

#define HWIO_CPR_GCNT35_ADDR(x)                                                      ((x) + 0x0000064c)
#define HWIO_CPR_GCNT35_OFFS                                                         (0x0000064c)
#define HWIO_CPR_GCNT35_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT35_IN(x)      \
        in_dword(HWIO_CPR_GCNT35_ADDR(x))
#define HWIO_CPR_GCNT35_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT35_ADDR(x), m)
#define HWIO_CPR_GCNT35_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT35_ADDR(x),v)
#define HWIO_CPR_GCNT35_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT35_ADDR(x),m,v,HWIO_CPR_GCNT35_IN(x))
#define HWIO_CPR_GCNT35_GCNT35_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT35_GCNT35_SHFT                                                         0x0

#define HWIO_CPR_GCNT36_ADDR(x)                                                      ((x) + 0x00000650)
#define HWIO_CPR_GCNT36_OFFS                                                         (0x00000650)
#define HWIO_CPR_GCNT36_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT36_IN(x)      \
        in_dword(HWIO_CPR_GCNT36_ADDR(x))
#define HWIO_CPR_GCNT36_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT36_ADDR(x), m)
#define HWIO_CPR_GCNT36_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT36_ADDR(x),v)
#define HWIO_CPR_GCNT36_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT36_ADDR(x),m,v,HWIO_CPR_GCNT36_IN(x))
#define HWIO_CPR_GCNT36_GCNT36_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT36_GCNT36_SHFT                                                         0x0

#define HWIO_CPR_GCNT37_ADDR(x)                                                      ((x) + 0x00000654)
#define HWIO_CPR_GCNT37_OFFS                                                         (0x00000654)
#define HWIO_CPR_GCNT37_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT37_IN(x)      \
        in_dword(HWIO_CPR_GCNT37_ADDR(x))
#define HWIO_CPR_GCNT37_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT37_ADDR(x), m)
#define HWIO_CPR_GCNT37_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT37_ADDR(x),v)
#define HWIO_CPR_GCNT37_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT37_ADDR(x),m,v,HWIO_CPR_GCNT37_IN(x))
#define HWIO_CPR_GCNT37_GCNT37_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT37_GCNT37_SHFT                                                         0x0

#define HWIO_CPR_GCNT38_ADDR(x)                                                      ((x) + 0x00000658)
#define HWIO_CPR_GCNT38_OFFS                                                         (0x00000658)
#define HWIO_CPR_GCNT38_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT38_IN(x)      \
        in_dword(HWIO_CPR_GCNT38_ADDR(x))
#define HWIO_CPR_GCNT38_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT38_ADDR(x), m)
#define HWIO_CPR_GCNT38_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT38_ADDR(x),v)
#define HWIO_CPR_GCNT38_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT38_ADDR(x),m,v,HWIO_CPR_GCNT38_IN(x))
#define HWIO_CPR_GCNT38_GCNT38_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT38_GCNT38_SHFT                                                         0x0

#define HWIO_CPR_GCNT39_ADDR(x)                                                      ((x) + 0x0000065c)
#define HWIO_CPR_GCNT39_OFFS                                                         (0x0000065c)
#define HWIO_CPR_GCNT39_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT39_IN(x)      \
        in_dword(HWIO_CPR_GCNT39_ADDR(x))
#define HWIO_CPR_GCNT39_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT39_ADDR(x), m)
#define HWIO_CPR_GCNT39_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT39_ADDR(x),v)
#define HWIO_CPR_GCNT39_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT39_ADDR(x),m,v,HWIO_CPR_GCNT39_IN(x))
#define HWIO_CPR_GCNT39_GCNT39_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT39_GCNT39_SHFT                                                         0x0

#define HWIO_CPR_GCNT40_ADDR(x)                                                      ((x) + 0x00000660)
#define HWIO_CPR_GCNT40_OFFS                                                         (0x00000660)
#define HWIO_CPR_GCNT40_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT40_IN(x)      \
        in_dword(HWIO_CPR_GCNT40_ADDR(x))
#define HWIO_CPR_GCNT40_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT40_ADDR(x), m)
#define HWIO_CPR_GCNT40_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT40_ADDR(x),v)
#define HWIO_CPR_GCNT40_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT40_ADDR(x),m,v,HWIO_CPR_GCNT40_IN(x))
#define HWIO_CPR_GCNT40_GCNT40_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT40_GCNT40_SHFT                                                         0x0

#define HWIO_CPR_GCNT41_ADDR(x)                                                      ((x) + 0x00000664)
#define HWIO_CPR_GCNT41_OFFS                                                         (0x00000664)
#define HWIO_CPR_GCNT41_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT41_IN(x)      \
        in_dword(HWIO_CPR_GCNT41_ADDR(x))
#define HWIO_CPR_GCNT41_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT41_ADDR(x), m)
#define HWIO_CPR_GCNT41_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT41_ADDR(x),v)
#define HWIO_CPR_GCNT41_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT41_ADDR(x),m,v,HWIO_CPR_GCNT41_IN(x))
#define HWIO_CPR_GCNT41_GCNT41_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT41_GCNT41_SHFT                                                         0x0

#define HWIO_CPR_GCNT42_ADDR(x)                                                      ((x) + 0x00000668)
#define HWIO_CPR_GCNT42_OFFS                                                         (0x00000668)
#define HWIO_CPR_GCNT42_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT42_IN(x)      \
        in_dword(HWIO_CPR_GCNT42_ADDR(x))
#define HWIO_CPR_GCNT42_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT42_ADDR(x), m)
#define HWIO_CPR_GCNT42_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT42_ADDR(x),v)
#define HWIO_CPR_GCNT42_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT42_ADDR(x),m,v,HWIO_CPR_GCNT42_IN(x))
#define HWIO_CPR_GCNT42_GCNT42_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT42_GCNT42_SHFT                                                         0x0

#define HWIO_CPR_GCNT43_ADDR(x)                                                      ((x) + 0x0000066c)
#define HWIO_CPR_GCNT43_OFFS                                                         (0x0000066c)
#define HWIO_CPR_GCNT43_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT43_IN(x)      \
        in_dword(HWIO_CPR_GCNT43_ADDR(x))
#define HWIO_CPR_GCNT43_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT43_ADDR(x), m)
#define HWIO_CPR_GCNT43_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT43_ADDR(x),v)
#define HWIO_CPR_GCNT43_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT43_ADDR(x),m,v,HWIO_CPR_GCNT43_IN(x))
#define HWIO_CPR_GCNT43_GCNT43_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT43_GCNT43_SHFT                                                         0x0

#define HWIO_CPR_GCNT44_ADDR(x)                                                      ((x) + 0x00000670)
#define HWIO_CPR_GCNT44_OFFS                                                         (0x00000670)
#define HWIO_CPR_GCNT44_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT44_IN(x)      \
        in_dword(HWIO_CPR_GCNT44_ADDR(x))
#define HWIO_CPR_GCNT44_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT44_ADDR(x), m)
#define HWIO_CPR_GCNT44_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT44_ADDR(x),v)
#define HWIO_CPR_GCNT44_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT44_ADDR(x),m,v,HWIO_CPR_GCNT44_IN(x))
#define HWIO_CPR_GCNT44_GCNT44_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT44_GCNT44_SHFT                                                         0x0

#define HWIO_CPR_GCNT45_ADDR(x)                                                      ((x) + 0x00000674)
#define HWIO_CPR_GCNT45_OFFS                                                         (0x00000674)
#define HWIO_CPR_GCNT45_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT45_IN(x)      \
        in_dword(HWIO_CPR_GCNT45_ADDR(x))
#define HWIO_CPR_GCNT45_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT45_ADDR(x), m)
#define HWIO_CPR_GCNT45_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT45_ADDR(x),v)
#define HWIO_CPR_GCNT45_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT45_ADDR(x),m,v,HWIO_CPR_GCNT45_IN(x))
#define HWIO_CPR_GCNT45_GCNT45_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT45_GCNT45_SHFT                                                         0x0

#define HWIO_CPR_GCNT46_ADDR(x)                                                      ((x) + 0x00000678)
#define HWIO_CPR_GCNT46_OFFS                                                         (0x00000678)
#define HWIO_CPR_GCNT46_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT46_IN(x)      \
        in_dword(HWIO_CPR_GCNT46_ADDR(x))
#define HWIO_CPR_GCNT46_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT46_ADDR(x), m)
#define HWIO_CPR_GCNT46_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT46_ADDR(x),v)
#define HWIO_CPR_GCNT46_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT46_ADDR(x),m,v,HWIO_CPR_GCNT46_IN(x))
#define HWIO_CPR_GCNT46_GCNT46_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT46_GCNT46_SHFT                                                         0x0

#define HWIO_CPR_GCNT47_ADDR(x)                                                      ((x) + 0x0000067c)
#define HWIO_CPR_GCNT47_OFFS                                                         (0x0000067c)
#define HWIO_CPR_GCNT47_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT47_IN(x)      \
        in_dword(HWIO_CPR_GCNT47_ADDR(x))
#define HWIO_CPR_GCNT47_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT47_ADDR(x), m)
#define HWIO_CPR_GCNT47_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT47_ADDR(x),v)
#define HWIO_CPR_GCNT47_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT47_ADDR(x),m,v,HWIO_CPR_GCNT47_IN(x))
#define HWIO_CPR_GCNT47_GCNT47_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT47_GCNT47_SHFT                                                         0x0

#define HWIO_CPR_GCNT48_ADDR(x)                                                      ((x) + 0x00000680)
#define HWIO_CPR_GCNT48_OFFS                                                         (0x00000680)
#define HWIO_CPR_GCNT48_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT48_IN(x)      \
        in_dword(HWIO_CPR_GCNT48_ADDR(x))
#define HWIO_CPR_GCNT48_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT48_ADDR(x), m)
#define HWIO_CPR_GCNT48_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT48_ADDR(x),v)
#define HWIO_CPR_GCNT48_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT48_ADDR(x),m,v,HWIO_CPR_GCNT48_IN(x))
#define HWIO_CPR_GCNT48_GCNT48_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT48_GCNT48_SHFT                                                         0x0

#define HWIO_CPR_GCNT49_ADDR(x)                                                      ((x) + 0x00000684)
#define HWIO_CPR_GCNT49_OFFS                                                         (0x00000684)
#define HWIO_CPR_GCNT49_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT49_IN(x)      \
        in_dword(HWIO_CPR_GCNT49_ADDR(x))
#define HWIO_CPR_GCNT49_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT49_ADDR(x), m)
#define HWIO_CPR_GCNT49_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT49_ADDR(x),v)
#define HWIO_CPR_GCNT49_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT49_ADDR(x),m,v,HWIO_CPR_GCNT49_IN(x))
#define HWIO_CPR_GCNT49_GCNT49_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT49_GCNT49_SHFT                                                         0x0

#define HWIO_CPR_GCNT50_ADDR(x)                                                      ((x) + 0x00000688)
#define HWIO_CPR_GCNT50_OFFS                                                         (0x00000688)
#define HWIO_CPR_GCNT50_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT50_IN(x)      \
        in_dword(HWIO_CPR_GCNT50_ADDR(x))
#define HWIO_CPR_GCNT50_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT50_ADDR(x), m)
#define HWIO_CPR_GCNT50_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT50_ADDR(x),v)
#define HWIO_CPR_GCNT50_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT50_ADDR(x),m,v,HWIO_CPR_GCNT50_IN(x))
#define HWIO_CPR_GCNT50_GCNT50_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT50_GCNT50_SHFT                                                         0x0

#define HWIO_CPR_GCNT51_ADDR(x)                                                      ((x) + 0x0000068c)
#define HWIO_CPR_GCNT51_OFFS                                                         (0x0000068c)
#define HWIO_CPR_GCNT51_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT51_IN(x)      \
        in_dword(HWIO_CPR_GCNT51_ADDR(x))
#define HWIO_CPR_GCNT51_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT51_ADDR(x), m)
#define HWIO_CPR_GCNT51_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT51_ADDR(x),v)
#define HWIO_CPR_GCNT51_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT51_ADDR(x),m,v,HWIO_CPR_GCNT51_IN(x))
#define HWIO_CPR_GCNT51_GCNT51_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT51_GCNT51_SHFT                                                         0x0

#define HWIO_CPR_GCNT52_ADDR(x)                                                      ((x) + 0x00000690)
#define HWIO_CPR_GCNT52_OFFS                                                         (0x00000690)
#define HWIO_CPR_GCNT52_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT52_IN(x)      \
        in_dword(HWIO_CPR_GCNT52_ADDR(x))
#define HWIO_CPR_GCNT52_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT52_ADDR(x), m)
#define HWIO_CPR_GCNT52_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT52_ADDR(x),v)
#define HWIO_CPR_GCNT52_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT52_ADDR(x),m,v,HWIO_CPR_GCNT52_IN(x))
#define HWIO_CPR_GCNT52_GCNT52_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT52_GCNT52_SHFT                                                         0x0

#define HWIO_CPR_GCNT53_ADDR(x)                                                      ((x) + 0x00000694)
#define HWIO_CPR_GCNT53_OFFS                                                         (0x00000694)
#define HWIO_CPR_GCNT53_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT53_IN(x)      \
        in_dword(HWIO_CPR_GCNT53_ADDR(x))
#define HWIO_CPR_GCNT53_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT53_ADDR(x), m)
#define HWIO_CPR_GCNT53_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT53_ADDR(x),v)
#define HWIO_CPR_GCNT53_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT53_ADDR(x),m,v,HWIO_CPR_GCNT53_IN(x))
#define HWIO_CPR_GCNT53_GCNT53_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT53_GCNT53_SHFT                                                         0x0

#define HWIO_CPR_GCNT54_ADDR(x)                                                      ((x) + 0x00000698)
#define HWIO_CPR_GCNT54_OFFS                                                         (0x00000698)
#define HWIO_CPR_GCNT54_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT54_IN(x)      \
        in_dword(HWIO_CPR_GCNT54_ADDR(x))
#define HWIO_CPR_GCNT54_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT54_ADDR(x), m)
#define HWIO_CPR_GCNT54_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT54_ADDR(x),v)
#define HWIO_CPR_GCNT54_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT54_ADDR(x),m,v,HWIO_CPR_GCNT54_IN(x))
#define HWIO_CPR_GCNT54_GCNT54_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT54_GCNT54_SHFT                                                         0x0

#define HWIO_CPR_GCNT55_ADDR(x)                                                      ((x) + 0x0000069c)
#define HWIO_CPR_GCNT55_OFFS                                                         (0x0000069c)
#define HWIO_CPR_GCNT55_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT55_IN(x)      \
        in_dword(HWIO_CPR_GCNT55_ADDR(x))
#define HWIO_CPR_GCNT55_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT55_ADDR(x), m)
#define HWIO_CPR_GCNT55_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT55_ADDR(x),v)
#define HWIO_CPR_GCNT55_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT55_ADDR(x),m,v,HWIO_CPR_GCNT55_IN(x))
#define HWIO_CPR_GCNT55_GCNT55_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT55_GCNT55_SHFT                                                         0x0

#define HWIO_CPR_GCNT56_ADDR(x)                                                      ((x) + 0x000006a0)
#define HWIO_CPR_GCNT56_OFFS                                                         (0x000006a0)
#define HWIO_CPR_GCNT56_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT56_IN(x)      \
        in_dword(HWIO_CPR_GCNT56_ADDR(x))
#define HWIO_CPR_GCNT56_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT56_ADDR(x), m)
#define HWIO_CPR_GCNT56_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT56_ADDR(x),v)
#define HWIO_CPR_GCNT56_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT56_ADDR(x),m,v,HWIO_CPR_GCNT56_IN(x))
#define HWIO_CPR_GCNT56_GCNT56_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT56_GCNT56_SHFT                                                         0x0

#define HWIO_CPR_GCNT57_ADDR(x)                                                      ((x) + 0x000006a4)
#define HWIO_CPR_GCNT57_OFFS                                                         (0x000006a4)
#define HWIO_CPR_GCNT57_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT57_IN(x)      \
        in_dword(HWIO_CPR_GCNT57_ADDR(x))
#define HWIO_CPR_GCNT57_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT57_ADDR(x), m)
#define HWIO_CPR_GCNT57_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT57_ADDR(x),v)
#define HWIO_CPR_GCNT57_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT57_ADDR(x),m,v,HWIO_CPR_GCNT57_IN(x))
#define HWIO_CPR_GCNT57_GCNT57_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT57_GCNT57_SHFT                                                         0x0

#define HWIO_CPR_GCNT58_ADDR(x)                                                      ((x) + 0x000006a8)
#define HWIO_CPR_GCNT58_OFFS                                                         (0x000006a8)
#define HWIO_CPR_GCNT58_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT58_IN(x)      \
        in_dword(HWIO_CPR_GCNT58_ADDR(x))
#define HWIO_CPR_GCNT58_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT58_ADDR(x), m)
#define HWIO_CPR_GCNT58_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT58_ADDR(x),v)
#define HWIO_CPR_GCNT58_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT58_ADDR(x),m,v,HWIO_CPR_GCNT58_IN(x))
#define HWIO_CPR_GCNT58_GCNT58_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT58_GCNT58_SHFT                                                         0x0

#define HWIO_CPR_GCNT59_ADDR(x)                                                      ((x) + 0x000006ac)
#define HWIO_CPR_GCNT59_OFFS                                                         (0x000006ac)
#define HWIO_CPR_GCNT59_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT59_IN(x)      \
        in_dword(HWIO_CPR_GCNT59_ADDR(x))
#define HWIO_CPR_GCNT59_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT59_ADDR(x), m)
#define HWIO_CPR_GCNT59_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT59_ADDR(x),v)
#define HWIO_CPR_GCNT59_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT59_ADDR(x),m,v,HWIO_CPR_GCNT59_IN(x))
#define HWIO_CPR_GCNT59_GCNT59_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT59_GCNT59_SHFT                                                         0x0

#define HWIO_CPR_GCNT60_ADDR(x)                                                      ((x) + 0x000006b0)
#define HWIO_CPR_GCNT60_OFFS                                                         (0x000006b0)
#define HWIO_CPR_GCNT60_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT60_IN(x)      \
        in_dword(HWIO_CPR_GCNT60_ADDR(x))
#define HWIO_CPR_GCNT60_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT60_ADDR(x), m)
#define HWIO_CPR_GCNT60_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT60_ADDR(x),v)
#define HWIO_CPR_GCNT60_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT60_ADDR(x),m,v,HWIO_CPR_GCNT60_IN(x))
#define HWIO_CPR_GCNT60_GCNT60_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT60_GCNT60_SHFT                                                         0x0

#define HWIO_CPR_GCNT61_ADDR(x)                                                      ((x) + 0x000006b4)
#define HWIO_CPR_GCNT61_OFFS                                                         (0x000006b4)
#define HWIO_CPR_GCNT61_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT61_IN(x)      \
        in_dword(HWIO_CPR_GCNT61_ADDR(x))
#define HWIO_CPR_GCNT61_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT61_ADDR(x), m)
#define HWIO_CPR_GCNT61_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT61_ADDR(x),v)
#define HWIO_CPR_GCNT61_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT61_ADDR(x),m,v,HWIO_CPR_GCNT61_IN(x))
#define HWIO_CPR_GCNT61_GCNT61_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT61_GCNT61_SHFT                                                         0x0

#define HWIO_CPR_GCNT62_ADDR(x)                                                      ((x) + 0x000006b8)
#define HWIO_CPR_GCNT62_OFFS                                                         (0x000006b8)
#define HWIO_CPR_GCNT62_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT62_IN(x)      \
        in_dword(HWIO_CPR_GCNT62_ADDR(x))
#define HWIO_CPR_GCNT62_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT62_ADDR(x), m)
#define HWIO_CPR_GCNT62_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT62_ADDR(x),v)
#define HWIO_CPR_GCNT62_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT62_ADDR(x),m,v,HWIO_CPR_GCNT62_IN(x))
#define HWIO_CPR_GCNT62_GCNT62_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT62_GCNT62_SHFT                                                         0x0

#define HWIO_CPR_GCNT63_ADDR(x)                                                      ((x) + 0x000006bc)
#define HWIO_CPR_GCNT63_OFFS                                                         (0x000006bc)
#define HWIO_CPR_GCNT63_RMSK                                                              0x3ff
#define HWIO_CPR_GCNT63_IN(x)      \
        in_dword(HWIO_CPR_GCNT63_ADDR(x))
#define HWIO_CPR_GCNT63_INM(x, m)      \
        in_dword_masked(HWIO_CPR_GCNT63_ADDR(x), m)
#define HWIO_CPR_GCNT63_OUT(x, v)      \
        out_dword(HWIO_CPR_GCNT63_ADDR(x),v)
#define HWIO_CPR_GCNT63_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_GCNT63_ADDR(x),m,v,HWIO_CPR_GCNT63_IN(x))
#define HWIO_CPR_GCNT63_GCNT63_BMSK                                                       0x3ff
#define HWIO_CPR_GCNT63_GCNT63_SHFT                                                         0x0

#define HWIO_CPR_64RO_CTRL_ADDR(x)                                                   ((x) + 0x000006c0)
#define HWIO_CPR_64RO_CTRL_OFFS                                                      (0x000006c0)
#define HWIO_CPR_64RO_CTRL_RMSK                                                             0x1
#define HWIO_CPR_64RO_CTRL_IN(x)      \
        in_dword(HWIO_CPR_64RO_CTRL_ADDR(x))
#define HWIO_CPR_64RO_CTRL_INM(x, m)      \
        in_dword_masked(HWIO_CPR_64RO_CTRL_ADDR(x), m)
#define HWIO_CPR_64RO_CTRL_OUT(x, v)      \
        out_dword(HWIO_CPR_64RO_CTRL_ADDR(x),v)
#define HWIO_CPR_64RO_CTRL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_64RO_CTRL_ADDR(x),m,v,HWIO_CPR_64RO_CTRL_IN(x))
#define HWIO_CPR_64RO_CTRL_CPR_64RO_EN_BMSK                                                 0x1
#define HWIO_CPR_64RO_CTRL_CPR_64RO_EN_SHFT                                                 0x0

#define HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR(base,n)                                   ((base) + 0x000000e0 + 0x4 * (n))
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_OFFS(base,n)                                   (0x000000e0 + 0x4 * (n))
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_RMSK                                           0xffffffff
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_MAXn                                                    1
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_INI(base,n)        \
        in_dword_masked(HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR(base,n), HWIO_CPR_SENSOR_BYPASS_WRITEn_RMSK)
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR(base,n), mask)
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_OUTI(base,n,val)    \
        out_dword(HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR(base,n),val)
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_CPR_SENSOR_BYPASS_WRITEn_ADDR(base,n),mask,val,HWIO_CPR_SENSOR_BYPASS_WRITEn_INI(base,n))
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_SENSOR_BYPASS_BMSK                             0xffffffff
#define HWIO_CPR_SENSOR_BYPASS_WRITEn_SENSOR_BYPASS_SHFT                                    0x0

#define HWIO_CPR_SENSOR_BYPASS_READn_ADDR(base,n)                                    ((base) + 0x00000100 + 0x4 * (n))
#define HWIO_CPR_SENSOR_BYPASS_READn_OFFS(base,n)                                    (0x00000100 + 0x4 * (n))
#define HWIO_CPR_SENSOR_BYPASS_READn_RMSK                                            0xffffffff
#define HWIO_CPR_SENSOR_BYPASS_READn_MAXn                                                     1
#define HWIO_CPR_SENSOR_BYPASS_READn_INI(base,n)        \
        in_dword_masked(HWIO_CPR_SENSOR_BYPASS_READn_ADDR(base,n), HWIO_CPR_SENSOR_BYPASS_READn_RMSK)
#define HWIO_CPR_SENSOR_BYPASS_READn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_SENSOR_BYPASS_READn_ADDR(base,n), mask)
#define HWIO_CPR_SENSOR_BYPASS_READn_SENSOR_BYPASS_BMSK                              0xffffffff
#define HWIO_CPR_SENSOR_BYPASS_READn_SENSOR_BYPASS_SHFT                                     0x0

#define HWIO_CPR_SENSOR_MASK_WRITEn_ADDR(base,n)                                     ((base) + 0x00000120 + 0x4 * (n))
#define HWIO_CPR_SENSOR_MASK_WRITEn_OFFS(base,n)                                     (0x00000120 + 0x4 * (n))
#define HWIO_CPR_SENSOR_MASK_WRITEn_RMSK                                             0xffffffff
#define HWIO_CPR_SENSOR_MASK_WRITEn_MAXn                                                      1
#define HWIO_CPR_SENSOR_MASK_WRITEn_INI(base,n)        \
        in_dword_masked(HWIO_CPR_SENSOR_MASK_WRITEn_ADDR(base,n), HWIO_CPR_SENSOR_MASK_WRITEn_RMSK)
#define HWIO_CPR_SENSOR_MASK_WRITEn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_SENSOR_MASK_WRITEn_ADDR(base,n), mask)
#define HWIO_CPR_SENSOR_MASK_WRITEn_OUTI(base,n,val)    \
        out_dword(HWIO_CPR_SENSOR_MASK_WRITEn_ADDR(base,n),val)
#define HWIO_CPR_SENSOR_MASK_WRITEn_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_CPR_SENSOR_MASK_WRITEn_ADDR(base,n),mask,val,HWIO_CPR_SENSOR_MASK_WRITEn_INI(base,n))
#define HWIO_CPR_SENSOR_MASK_WRITEn_SENSOR_MASK_BMSK                                 0xffffffff
#define HWIO_CPR_SENSOR_MASK_WRITEn_SENSOR_MASK_SHFT                                        0x0

#define HWIO_CPR_SENSOR_MASK_READn_ADDR(base,n)                                      ((base) + 0x00000140 + 0x4 * (n))
#define HWIO_CPR_SENSOR_MASK_READn_OFFS(base,n)                                      (0x00000140 + 0x4 * (n))
#define HWIO_CPR_SENSOR_MASK_READn_RMSK                                              0xffffffff
#define HWIO_CPR_SENSOR_MASK_READn_MAXn                                                       1
#define HWIO_CPR_SENSOR_MASK_READn_INI(base,n)        \
        in_dword_masked(HWIO_CPR_SENSOR_MASK_READn_ADDR(base,n), HWIO_CPR_SENSOR_MASK_READn_RMSK)
#define HWIO_CPR_SENSOR_MASK_READn_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_SENSOR_MASK_READn_ADDR(base,n), mask)
#define HWIO_CPR_SENSOR_MASK_READn_SENSOR_MASK_BMSK                                  0xffffffff
#define HWIO_CPR_SENSOR_MASK_READn_SENSOR_MASK_SHFT                                         0x0

#define HWIO_CPR_SENSOR_THREAD_n_ADDR(base,n)                                        ((base) + 0x00000200 + 0x4 * (n))
#define HWIO_CPR_SENSOR_THREAD_n_OFFS(base,n)                                        (0x00000200 + 0x4 * (n))
#define HWIO_CPR_SENSOR_THREAD_n_RMSK                                                       0x1
#define HWIO_CPR_SENSOR_THREAD_n_MAXn                                                        46
#define HWIO_CPR_SENSOR_THREAD_n_INI(base,n)        \
        in_dword_masked(HWIO_CPR_SENSOR_THREAD_n_ADDR(base,n), HWIO_CPR_SENSOR_THREAD_n_RMSK)
#define HWIO_CPR_SENSOR_THREAD_n_INMI(base,n,mask)    \
        in_dword_masked(HWIO_CPR_SENSOR_THREAD_n_ADDR(base,n), mask)
#define HWIO_CPR_SENSOR_THREAD_n_OUTI(base,n,val)    \
        out_dword(HWIO_CPR_SENSOR_THREAD_n_ADDR(base,n),val)
#define HWIO_CPR_SENSOR_THREAD_n_OUTMI(base,n,mask,val) \
        out_dword_masked_ns(HWIO_CPR_SENSOR_THREAD_n_ADDR(base,n),mask,val,HWIO_CPR_SENSOR_THREAD_n_INI(base,n))
#define HWIO_CPR_SENSOR_THREAD_n_THREAD_ID_BMSK                                             0x1
#define HWIO_CPR_SENSOR_THREAD_n_THREAD_ID_SHFT                                             0x0

#define HWIO_CPR_MISC_REGISTER_ADDR(x)                                               ((x) + 0x00000700)
#define HWIO_CPR_MISC_REGISTER_OFFS                                                  (0x00000700)
#define HWIO_CPR_MISC_REGISTER_RMSK                                                  0xffffffff
#define HWIO_CPR_MISC_REGISTER_IN(x)      \
        in_dword(HWIO_CPR_MISC_REGISTER_ADDR(x))
#define HWIO_CPR_MISC_REGISTER_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MISC_REGISTER_ADDR(x), m)
#define HWIO_CPR_MISC_REGISTER_OUT(x, v)      \
        out_dword(HWIO_CPR_MISC_REGISTER_ADDR(x),v)
#define HWIO_CPR_MISC_REGISTER_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MISC_REGISTER_ADDR(x),m,v,HWIO_CPR_MISC_REGISTER_IN(x))
#define HWIO_CPR_MISC_REGISTER_TEMP_SENSOR_ID_END_BMSK                               0xf0000000
#define HWIO_CPR_MISC_REGISTER_TEMP_SENSOR_ID_END_SHFT                                     0x1c
#define HWIO_CPR_MISC_REGISTER_TEMP_SENSOR_ID_START_BMSK                              0xf000000
#define HWIO_CPR_MISC_REGISTER_TEMP_SENSOR_ID_START_SHFT                                   0x18
#define HWIO_CPR_MISC_REGISTER_MARGIN_TABLE_ROW_SELECT_BMSK                            0xf00000
#define HWIO_CPR_MISC_REGISTER_MARGIN_TABLE_ROW_SELECT_SHFT                                0x14
#define HWIO_CPR_MISC_REGISTER_UNUSED_BMSK                                              0xff800
#define HWIO_CPR_MISC_REGISTER_UNUSED_SHFT                                                  0xb
#define HWIO_CPR_MISC_REGISTER_CPR_GCNT_PER_MODE_EN_BMSK                                  0x400
#define HWIO_CPR_MISC_REGISTER_CPR_GCNT_PER_MODE_EN_SHFT                                    0xa
#define HWIO_CPR_MISC_REGISTER_CPRF_MID_COMMAND_EN_BMSK                                   0x200
#define HWIO_CPR_MISC_REGISTER_CPRF_MID_COMMAND_EN_SHFT                                     0x9
#define HWIO_CPR_MISC_REGISTER_CPR_TSENSE_CTL_READING_EN_BMSK                             0x100
#define HWIO_CPR_MISC_REGISTER_CPR_TSENSE_CTL_READING_EN_SHFT                               0x8
#define HWIO_CPR_MISC_REGISTER_CPR_AGGRESIVE_CGC_DISABLE_BMSK                              0x80
#define HWIO_CPR_MISC_REGISTER_CPR_AGGRESIVE_CGC_DISABLE_SHFT                               0x7
#define HWIO_CPR_MISC_REGISTER_CPRF_SETTLE_TIMER_DOWN_EN_BMSK                              0x40
#define HWIO_CPR_MISC_REGISTER_CPRF_SETTLE_TIMER_DOWN_EN_SHFT                               0x6
#define HWIO_CPR_MISC_REGISTER_CPRF_INTERFACE_ENABLE_BMSK                                  0x20
#define HWIO_CPR_MISC_REGISTER_CPRF_INTERFACE_ENABLE_SHFT                                   0x5
#define HWIO_CPR_MISC_REGISTER_STEP_QUOT_INIT_PER_RO_BMSK                                  0x10
#define HWIO_CPR_MISC_REGISTER_STEP_QUOT_INIT_PER_RO_SHFT                                   0x4
#define HWIO_CPR_MISC_REGISTER_THREAD_HAS_ALWAYS_VOTE_BMSK                                  0x8
#define HWIO_CPR_MISC_REGISTER_THREAD_HAS_ALWAYS_VOTE_SHFT                                  0x3
#define HWIO_CPR_MISC_REGISTER_RESET_STEP_QUOT_LOOP_EN_BMSK                                 0x4
#define HWIO_CPR_MISC_REGISTER_RESET_STEP_QUOT_LOOP_EN_SHFT                                 0x2
#define HWIO_CPR_MISC_REGISTER_ADD_SUB_MARGIN_BMSK                                          0x2
#define HWIO_CPR_MISC_REGISTER_ADD_SUB_MARGIN_SHFT                                          0x1
#define HWIO_CPR_MISC_REGISTER_TEMP_MARGIN_POLARITY_BMSK                                    0x1
#define HWIO_CPR_MISC_REGISTER_TEMP_MARGIN_POLARITY_SHFT                                    0x0

#define HWIO_CPR_DISABLE_RO_ALL_THREADS_ADDR(x)                                      ((x) + 0x00000704)
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_OFFS                                         (0x00000704)
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_RMSK                                         0xffffffff
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_IN(x)      \
        in_dword(HWIO_CPR_DISABLE_RO_ALL_THREADS_ADDR(x))
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_INM(x, m)      \
        in_dword_masked(HWIO_CPR_DISABLE_RO_ALL_THREADS_ADDR(x), m)
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_OUT(x, v)      \
        out_dword(HWIO_CPR_DISABLE_RO_ALL_THREADS_ADDR(x),v)
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_DISABLE_RO_ALL_THREADS_ADDR(x),m,v,HWIO_CPR_DISABLE_RO_ALL_THREADS_IN(x))
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_UNUSED_BMSK                                  0xffff0000
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_UNUSED_SHFT                                        0x10
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_RO_DISABLE_BMSK                                  0xffff
#define HWIO_CPR_DISABLE_RO_ALL_THREADS_RO_DISABLE_SHFT                                     0x0

#define HWIO_CPR_PER_SENSOR_QUOT_0_ADDR(x)                                           ((x) + 0x00000780)
#define HWIO_CPR_PER_SENSOR_QUOT_0_OFFS                                              (0x00000780)
#define HWIO_CPR_PER_SENSOR_QUOT_0_RMSK                                                 0xfffff
#define HWIO_CPR_PER_SENSOR_QUOT_0_IN(x)      \
        in_dword(HWIO_CPR_PER_SENSOR_QUOT_0_ADDR(x))
#define HWIO_CPR_PER_SENSOR_QUOT_0_INM(x, m)      \
        in_dword_masked(HWIO_CPR_PER_SENSOR_QUOT_0_ADDR(x), m)
#define HWIO_CPR_PER_SENSOR_QUOT_0_OUT(x, v)      \
        out_dword(HWIO_CPR_PER_SENSOR_QUOT_0_ADDR(x),v)
#define HWIO_CPR_PER_SENSOR_QUOT_0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_PER_SENSOR_QUOT_0_ADDR(x),m,v,HWIO_CPR_PER_SENSOR_QUOT_0_IN(x))
#define HWIO_CPR_PER_SENSOR_QUOT_0_PER_SENSOR_QUOT_QUOT_0_BMSK                          0xfff00
#define HWIO_CPR_PER_SENSOR_QUOT_0_PER_SENSOR_QUOT_QUOT_0_SHFT                              0x8
#define HWIO_CPR_PER_SENSOR_QUOT_0_PER_SENSOR_QUOT_ID_0_BMSK                               0xff
#define HWIO_CPR_PER_SENSOR_QUOT_0_PER_SENSOR_QUOT_ID_0_SHFT                                0x0

#define HWIO_CPR_PER_SENSOR_QUOT_1_ADDR(x)                                           ((x) + 0x00000784)
#define HWIO_CPR_PER_SENSOR_QUOT_1_OFFS                                              (0x00000784)
#define HWIO_CPR_PER_SENSOR_QUOT_1_RMSK                                                 0xfffff
#define HWIO_CPR_PER_SENSOR_QUOT_1_IN(x)      \
        in_dword(HWIO_CPR_PER_SENSOR_QUOT_1_ADDR(x))
#define HWIO_CPR_PER_SENSOR_QUOT_1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_PER_SENSOR_QUOT_1_ADDR(x), m)
#define HWIO_CPR_PER_SENSOR_QUOT_1_OUT(x, v)      \
        out_dword(HWIO_CPR_PER_SENSOR_QUOT_1_ADDR(x),v)
#define HWIO_CPR_PER_SENSOR_QUOT_1_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_PER_SENSOR_QUOT_1_ADDR(x),m,v,HWIO_CPR_PER_SENSOR_QUOT_1_IN(x))
#define HWIO_CPR_PER_SENSOR_QUOT_1_PER_SENSOR_QUOT_QUOT_1_BMSK                          0xfff00
#define HWIO_CPR_PER_SENSOR_QUOT_1_PER_SENSOR_QUOT_QUOT_1_SHFT                              0x8
#define HWIO_CPR_PER_SENSOR_QUOT_1_PER_SENSOR_QUOT_ID_1_BMSK                               0xff
#define HWIO_CPR_PER_SENSOR_QUOT_1_PER_SENSOR_QUOT_ID_1_SHFT                                0x0

#define HWIO_CPR_PER_SENSOR_QUOT_2_ADDR(x)                                           ((x) + 0x00000788)
#define HWIO_CPR_PER_SENSOR_QUOT_2_OFFS                                              (0x00000788)
#define HWIO_CPR_PER_SENSOR_QUOT_2_RMSK                                                 0xfffff
#define HWIO_CPR_PER_SENSOR_QUOT_2_IN(x)      \
        in_dword(HWIO_CPR_PER_SENSOR_QUOT_2_ADDR(x))
#define HWIO_CPR_PER_SENSOR_QUOT_2_INM(x, m)      \
        in_dword_masked(HWIO_CPR_PER_SENSOR_QUOT_2_ADDR(x), m)
#define HWIO_CPR_PER_SENSOR_QUOT_2_OUT(x, v)      \
        out_dword(HWIO_CPR_PER_SENSOR_QUOT_2_ADDR(x),v)
#define HWIO_CPR_PER_SENSOR_QUOT_2_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_PER_SENSOR_QUOT_2_ADDR(x),m,v,HWIO_CPR_PER_SENSOR_QUOT_2_IN(x))
#define HWIO_CPR_PER_SENSOR_QUOT_2_PER_SENSOR_QUOT_QUOT_2_BMSK                          0xfff00
#define HWIO_CPR_PER_SENSOR_QUOT_2_PER_SENSOR_QUOT_QUOT_2_SHFT                              0x8
#define HWIO_CPR_PER_SENSOR_QUOT_2_PER_SENSOR_QUOT_ID_2_BMSK                               0xff
#define HWIO_CPR_PER_SENSOR_QUOT_2_PER_SENSOR_QUOT_ID_2_SHFT                                0x0

#define HWIO_CPR_PER_SENSOR_QUOT_3_ADDR(x)                                           ((x) + 0x0000078c)
#define HWIO_CPR_PER_SENSOR_QUOT_3_OFFS                                              (0x0000078c)
#define HWIO_CPR_PER_SENSOR_QUOT_3_RMSK                                                 0xfffff
#define HWIO_CPR_PER_SENSOR_QUOT_3_IN(x)      \
        in_dword(HWIO_CPR_PER_SENSOR_QUOT_3_ADDR(x))
#define HWIO_CPR_PER_SENSOR_QUOT_3_INM(x, m)      \
        in_dword_masked(HWIO_CPR_PER_SENSOR_QUOT_3_ADDR(x), m)
#define HWIO_CPR_PER_SENSOR_QUOT_3_OUT(x, v)      \
        out_dword(HWIO_CPR_PER_SENSOR_QUOT_3_ADDR(x),v)
#define HWIO_CPR_PER_SENSOR_QUOT_3_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_PER_SENSOR_QUOT_3_ADDR(x),m,v,HWIO_CPR_PER_SENSOR_QUOT_3_IN(x))
#define HWIO_CPR_PER_SENSOR_QUOT_3_PER_SENSOR_QUOT_QUOT_3_BMSK                          0xfff00
#define HWIO_CPR_PER_SENSOR_QUOT_3_PER_SENSOR_QUOT_QUOT_3_SHFT                              0x8
#define HWIO_CPR_PER_SENSOR_QUOT_3_PER_SENSOR_QUOT_ID_3_BMSK                               0xff
#define HWIO_CPR_PER_SENSOR_QUOT_3_PER_SENSOR_QUOT_ID_3_SHFT                                0x0

#define HWIO_CPR_PER_SENSOR_QUOT_4_ADDR(x)                                           ((x) + 0x00000790)
#define HWIO_CPR_PER_SENSOR_QUOT_4_OFFS                                              (0x00000790)
#define HWIO_CPR_PER_SENSOR_QUOT_4_RMSK                                                 0xfffff
#define HWIO_CPR_PER_SENSOR_QUOT_4_IN(x)      \
        in_dword(HWIO_CPR_PER_SENSOR_QUOT_4_ADDR(x))
#define HWIO_CPR_PER_SENSOR_QUOT_4_INM(x, m)      \
        in_dword_masked(HWIO_CPR_PER_SENSOR_QUOT_4_ADDR(x), m)
#define HWIO_CPR_PER_SENSOR_QUOT_4_OUT(x, v)      \
        out_dword(HWIO_CPR_PER_SENSOR_QUOT_4_ADDR(x),v)
#define HWIO_CPR_PER_SENSOR_QUOT_4_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_PER_SENSOR_QUOT_4_ADDR(x),m,v,HWIO_CPR_PER_SENSOR_QUOT_4_IN(x))
#define HWIO_CPR_PER_SENSOR_QUOT_4_PER_SENSOR_QUOT_QUOT_4_BMSK                          0xfff00
#define HWIO_CPR_PER_SENSOR_QUOT_4_PER_SENSOR_QUOT_QUOT_4_SHFT                              0x8
#define HWIO_CPR_PER_SENSOR_QUOT_4_PER_SENSOR_QUOT_ID_4_BMSK                               0xff
#define HWIO_CPR_PER_SENSOR_QUOT_4_PER_SENSOR_QUOT_ID_4_SHFT                                0x0

#define HWIO_CPR_DEBUG_BUS_ADDR(x)                                                   ((x) + 0x00000794)
#define HWIO_CPR_DEBUG_BUS_OFFS                                                      (0x00000794)
#define HWIO_CPR_DEBUG_BUS_RMSK                                                      0xffffffff
#define HWIO_CPR_DEBUG_BUS_IN(x)      \
        in_dword(HWIO_CPR_DEBUG_BUS_ADDR(x))
#define HWIO_CPR_DEBUG_BUS_INM(x, m)      \
        in_dword_masked(HWIO_CPR_DEBUG_BUS_ADDR(x), m)
#define HWIO_CPR_DEBUG_BUS_CPR_DEBUG_BUS_BMSK                                        0xffffffff
#define HWIO_CPR_DEBUG_BUS_CPR_DEBUG_BUS_SHFT                                               0x0

#define HWIO_CPR_CORE_ADJ_MODE_REG_ADDR(x)                                           ((x) + 0x00000798)
#define HWIO_CPR_CORE_ADJ_MODE_REG_OFFS                                              (0x00000798)
#define HWIO_CPR_CORE_ADJ_MODE_REG_RMSK                                              0xffffffff
#define HWIO_CPR_CORE_ADJ_MODE_REG_IN(x)      \
        in_dword(HWIO_CPR_CORE_ADJ_MODE_REG_ADDR(x))
#define HWIO_CPR_CORE_ADJ_MODE_REG_INM(x, m)      \
        in_dword_masked(HWIO_CPR_CORE_ADJ_MODE_REG_ADDR(x), m)
#define HWIO_CPR_CORE_ADJ_MODE_REG_OUT(x, v)      \
        out_dword(HWIO_CPR_CORE_ADJ_MODE_REG_ADDR(x),v)
#define HWIO_CPR_CORE_ADJ_MODE_REG_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_CORE_ADJ_MODE_REG_ADDR(x),m,v,HWIO_CPR_CORE_ADJ_MODE_REG_IN(x))
#define HWIO_CPR_CORE_ADJ_MODE_REG_MODE_CHANGE_READY_BMSK                            0x80000000
#define HWIO_CPR_CORE_ADJ_MODE_REG_MODE_CHANGE_READY_SHFT                                  0x1f
#define HWIO_CPR_CORE_ADJ_MODE_REG_CODE_ADJ_NUM_CORES_BMSK                           0x78000000
#define HWIO_CPR_CORE_ADJ_MODE_REG_CODE_ADJ_NUM_CORES_SHFT                                 0x1b
#define HWIO_CPR_CORE_ADJ_MODE_REG_UNUSED_BMSK                                        0x7fffffe
#define HWIO_CPR_CORE_ADJ_MODE_REG_UNUSED_SHFT                                              0x1
#define HWIO_CPR_CORE_ADJ_MODE_REG_MODE_CHANGE_BMSK                                         0x1
#define HWIO_CPR_CORE_ADJ_MODE_REG_MODE_CHANGE_SHFT                                         0x0

#define HWIO_CPR_CPR_SRAM_SENSORS_ADDR(x)                                            ((x) + 0x0000079c)
#define HWIO_CPR_CPR_SRAM_SENSORS_OFFS                                               (0x0000079c)
#define HWIO_CPR_CPR_SRAM_SENSORS_RMSK                                               0xc3ffffff
#define HWIO_CPR_CPR_SRAM_SENSORS_IN(x)      \
        in_dword(HWIO_CPR_CPR_SRAM_SENSORS_ADDR(x))
#define HWIO_CPR_CPR_SRAM_SENSORS_INM(x, m)      \
        in_dword_masked(HWIO_CPR_CPR_SRAM_SENSORS_ADDR(x), m)
#define HWIO_CPR_CPR_SRAM_SENSORS_OUT(x, v)      \
        out_dword(HWIO_CPR_CPR_SRAM_SENSORS_ADDR(x),v)
#define HWIO_CPR_CPR_SRAM_SENSORS_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_CPR_SRAM_SENSORS_ADDR(x),m,v,HWIO_CPR_CPR_SRAM_SENSORS_IN(x))
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM0_RESET_BMSK                                   0x80000000
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM0_RESET_SHFT                                         0x1f
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM1_RESET_BMSK                                   0x40000000
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM1_RESET_SHFT                                         0x1e
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM1_DATA_BMSK                                     0x3ffe000
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM1_DATA_SHFT                                           0xd
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM0_DATA_BMSK                                        0x1fff
#define HWIO_CPR_CPR_SRAM_SENSORS_SRAM0_DATA_SHFT                                           0x0

#define HWIO_CPR_CPRF_DN_TIMER_ADDR(x)                                               ((x) + 0x000007a0)
#define HWIO_CPR_CPRF_DN_TIMER_OFFS                                                  (0x000007a0)
#define HWIO_CPR_CPRF_DN_TIMER_RMSK                                                  0xffffffff
#define HWIO_CPR_CPRF_DN_TIMER_IN(x)      \
        in_dword(HWIO_CPR_CPRF_DN_TIMER_ADDR(x))
#define HWIO_CPR_CPRF_DN_TIMER_INM(x, m)      \
        in_dword_masked(HWIO_CPR_CPRF_DN_TIMER_ADDR(x), m)
#define HWIO_CPR_CPRF_DN_TIMER_OUT(x, v)      \
        out_dword(HWIO_CPR_CPRF_DN_TIMER_ADDR(x),v)
#define HWIO_CPR_CPRF_DN_TIMER_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_CPRF_DN_TIMER_ADDR(x),m,v,HWIO_CPR_CPRF_DN_TIMER_IN(x))
#define HWIO_CPR_CPRF_DN_TIMER_TIMER_INTERVAL_BMSK                                   0xffffffff
#define HWIO_CPR_CPRF_DN_TIMER_TIMER_INTERVAL_SHFT                                          0x0

#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_ADDR(x)                                        ((x) + 0x000007a4)
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_OFFS                                           (0x000007a4)
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_RMSK                                                0x3ff
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_IN(x)      \
        in_dword(HWIO_CPR_SAW_ERROR_STEP_LIMIT_ADDR(x))
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_INM(x, m)      \
        in_dword_masked(HWIO_CPR_SAW_ERROR_STEP_LIMIT_ADDR(x), m)
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_OUT(x, v)      \
        out_dword(HWIO_CPR_SAW_ERROR_STEP_LIMIT_ADDR(x),v)
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_SAW_ERROR_STEP_LIMIT_ADDR(x),m,v,HWIO_CPR_SAW_ERROR_STEP_LIMIT_IN(x))
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_DN_ERROR_STEP_LIMIT_BMSK                            0x3e0
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_DN_ERROR_STEP_LIMIT_SHFT                              0x5
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_UP_ERROR_STEP_LIMIT_BMSK                             0x1f
#define HWIO_CPR_SAW_ERROR_STEP_LIMIT_UP_ERROR_STEP_LIMIT_SHFT                              0x0

#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_ADDR(x)                                     ((x) + 0x000007a8)
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_OFFS                                        (0x000007a8)
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_RMSK                                        0xffffffff
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_IN(x))
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_UNUSED_BMSK                                 0xe0000000
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_UNUSED_SHFT                                       0x1d
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_TIMER_SETTLE_VOLTAGE_COUNT_BMSK             0x1ffc0000
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_TIMER_SETTLE_VOLTAGE_COUNT_SHFT                   0x12
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_TIMER_LOWER_VOLTAGE_COUNT_BMSK                 0x3ffff
#define HWIO_CPR_MARGIN_TEMP_CORE_TIMERS_TIMER_LOWER_VOLTAGE_COUNT_SHFT                     0x0

#define HWIO_CPR_MARGIN_TEMP_0_ADDR(x)                                               ((x) + 0x000007ac)
#define HWIO_CPR_MARGIN_TEMP_0_OFFS                                                  (0x000007ac)
#define HWIO_CPR_MARGIN_TEMP_0_RMSK                                                  0xffffffff
#define HWIO_CPR_MARGIN_TEMP_0_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_0_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_0_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_0_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_0_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_0_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_0_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_0_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_0_IN(x))
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND3_BMSK                                 0xff000000
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND3_SHFT                                       0x18
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND2_BMSK                                   0xff0000
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND2_SHFT                                       0x10
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND1_BMSK                                     0xff00
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND1_SHFT                                        0x8
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND0_BMSK                                       0xff
#define HWIO_CPR_MARGIN_TEMP_0_MARGIN_TEMPBAND0_SHFT                                        0x0

#define HWIO_CPR_MARGIN_TEMP_1_ADDR(x)                                               ((x) + 0x000007b0)
#define HWIO_CPR_MARGIN_TEMP_1_OFFS                                                  (0x000007b0)
#define HWIO_CPR_MARGIN_TEMP_1_RMSK                                                  0xffffffff
#define HWIO_CPR_MARGIN_TEMP_1_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_1_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_1_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_1_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_1_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_1_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_1_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_1_IN(x))
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND3_BMSK                                 0xff000000
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND3_SHFT                                       0x18
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND2_BMSK                                   0xff0000
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND2_SHFT                                       0x10
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND1_BMSK                                     0xff00
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND1_SHFT                                        0x8
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND0_BMSK                                       0xff
#define HWIO_CPR_MARGIN_TEMP_1_MARGIN_TEMPBAND0_SHFT                                        0x0

#define HWIO_CPR_MARGIN_TEMP_2_ADDR(x)                                               ((x) + 0x000007b4)
#define HWIO_CPR_MARGIN_TEMP_2_OFFS                                                  (0x000007b4)
#define HWIO_CPR_MARGIN_TEMP_2_RMSK                                                  0xffffffff
#define HWIO_CPR_MARGIN_TEMP_2_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_2_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_2_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_2_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_2_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_2_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_2_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_2_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_2_IN(x))
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND3_BMSK                                 0xff000000
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND3_SHFT                                       0x18
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND2_BMSK                                   0xff0000
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND2_SHFT                                       0x10
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND1_BMSK                                     0xff00
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND1_SHFT                                        0x8
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND0_BMSK                                       0xff
#define HWIO_CPR_MARGIN_TEMP_2_MARGIN_TEMPBAND0_SHFT                                        0x0

#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_ADDR(x)                                      ((x) + 0x000007b8)
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_OFFS                                         (0x000007b8)
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_RMSK                                         0xffffffff
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_DCVS_POINT_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_DCVS_POINT_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_DCVS_POINT_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_DCVS_POINT_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_DCVS_POINT_IN(x))
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_UNUSED_BMSK                                  0xffff8000
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_UNUSED_SHFT                                         0xf
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT2_BMSK                                 0x7c00
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT2_SHFT                                    0xa
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT1_BMSK                                  0x3e0
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT1_SHFT                                    0x5
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT0_BMSK                                   0x1f
#define HWIO_CPR_MARGIN_TEMP_DCVS_POINT_DCVS_POINT0_SHFT                                    0x0

#define HWIO_CPR_TEMP_SENSOR_DATA_ADDR(x)                                            ((x) + 0x000007ec)
#define HWIO_CPR_TEMP_SENSOR_DATA_OFFS                                               (0x000007ec)
#define HWIO_CPR_TEMP_SENSOR_DATA_RMSK                                               0xffffffff
#define HWIO_CPR_TEMP_SENSOR_DATA_IN(x)      \
        in_dword(HWIO_CPR_TEMP_SENSOR_DATA_ADDR(x))
#define HWIO_CPR_TEMP_SENSOR_DATA_INM(x, m)      \
        in_dword_masked(HWIO_CPR_TEMP_SENSOR_DATA_ADDR(x), m)
#define HWIO_CPR_TEMP_SENSOR_DATA_COLD_SENSOR_BMSK                                   0xf0000000
#define HWIO_CPR_TEMP_SENSOR_DATA_COLD_SENSOR_SHFT                                         0x1c
#define HWIO_CPR_TEMP_SENSOR_DATA_COLD_TEMP_BMSK                                      0xfff0000
#define HWIO_CPR_TEMP_SENSOR_DATA_COLD_TEMP_SHFT                                           0x10
#define HWIO_CPR_TEMP_SENSOR_DATA_HOT_SENSOR_BMSK                                        0xf000
#define HWIO_CPR_TEMP_SENSOR_DATA_HOT_SENSOR_SHFT                                           0xc
#define HWIO_CPR_TEMP_SENSOR_DATA_HOT_TEMP_BMSK                                           0xfff
#define HWIO_CPR_TEMP_SENSOR_DATA_HOT_TEMP_SHFT                                             0x0

#define HWIO_CPR_MARGIN_TEMP_POINT0N1_ADDR(x)                                        ((x) + 0x000007f0)
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_OFFS                                           (0x000007f0)
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_RMSK                                           0xc0ffffff
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_POINT0N1_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_POINT0N1_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_POINT0N1_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_POINT0N1_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_POINT0N1_IN(x))
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_BELOWPOINT0_HOTCOLD_BMSK                       0x80000000
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_BELOWPOINT0_HOTCOLD_SHFT                             0x1f
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_BELOWPOINT1_HOTCOLD_BMSK                       0x40000000
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_BELOWPOINT1_HOTCOLD_SHFT                             0x1e
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_POINT1_BMSK                                      0xfff000
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_POINT1_SHFT                                           0xc
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_POINT0_BMSK                                         0xfff
#define HWIO_CPR_MARGIN_TEMP_POINT0N1_POINT0_SHFT                                           0x0

#define HWIO_CPR_MARGIN_TEMP_POINT2_ADDR(x)                                          ((x) + 0x000007f4)
#define HWIO_CPR_MARGIN_TEMP_POINT2_OFFS                                             (0x000007f4)
#define HWIO_CPR_MARGIN_TEMP_POINT2_RMSK                                             0xc0000fff
#define HWIO_CPR_MARGIN_TEMP_POINT2_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_TEMP_POINT2_ADDR(x))
#define HWIO_CPR_MARGIN_TEMP_POINT2_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_TEMP_POINT2_ADDR(x), m)
#define HWIO_CPR_MARGIN_TEMP_POINT2_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_TEMP_POINT2_ADDR(x),v)
#define HWIO_CPR_MARGIN_TEMP_POINT2_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_TEMP_POINT2_ADDR(x),m,v,HWIO_CPR_MARGIN_TEMP_POINT2_IN(x))
#define HWIO_CPR_MARGIN_TEMP_POINT2_BELOWPOINT2_HOTCOLD_BMSK                         0x80000000
#define HWIO_CPR_MARGIN_TEMP_POINT2_BELOWPOINT2_HOTCOLD_SHFT                               0x1f
#define HWIO_CPR_MARGIN_TEMP_POINT2_ABOVEPOINT2_HOTCOLD_BMSK                         0x40000000
#define HWIO_CPR_MARGIN_TEMP_POINT2_ABOVEPOINT2_HOTCOLD_SHFT                               0x1e
#define HWIO_CPR_MARGIN_TEMP_POINT2_POINT2_BMSK                                           0xfff
#define HWIO_CPR_MARGIN_TEMP_POINT2_POINT2_SHFT                                             0x0

#define HWIO_CPR_MARGIN_ADJ_CTL_ADDR(x)                                              ((x) + 0x000007f8)
#define HWIO_CPR_MARGIN_ADJ_CTL_OFFS                                                 (0x000007f8)
#define HWIO_CPR_MARGIN_ADJ_CTL_RMSK                                                 0xffffffff
#define HWIO_CPR_MARGIN_ADJ_CTL_IN(x)      \
        in_dword(HWIO_CPR_MARGIN_ADJ_CTL_ADDR(x))
#define HWIO_CPR_MARGIN_ADJ_CTL_INM(x, m)      \
        in_dword_masked(HWIO_CPR_MARGIN_ADJ_CTL_ADDR(x), m)
#define HWIO_CPR_MARGIN_ADJ_CTL_OUT(x, v)      \
        out_dword(HWIO_CPR_MARGIN_ADJ_CTL_ADDR(x),v)
#define HWIO_CPR_MARGIN_ADJ_CTL_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_MARGIN_ADJ_CTL_ADDR(x),m,v,HWIO_CPR_MARGIN_ADJ_CTL_IN(x))
#define HWIO_CPR_MARGIN_ADJ_CTL_KV_MARGIN_ADJ_SINGLE_STEP_QUOT_BMSK                  0xfc000000
#define HWIO_CPR_MARGIN_ADJ_CTL_KV_MARGIN_ADJ_SINGLE_STEP_QUOT_SHFT                        0x1a
#define HWIO_CPR_MARGIN_ADJ_CTL_MAX_NUM_CORES_BMSK                                    0x3c00000
#define HWIO_CPR_MARGIN_ADJ_CTL_MAX_NUM_CORES_SHFT                                         0x16
#define HWIO_CPR_MARGIN_ADJ_CTL_INITIAL_TEMP_BAND_BMSK                                 0x380000
#define HWIO_CPR_MARGIN_ADJ_CTL_INITIAL_TEMP_BAND_SHFT                                     0x13
#define HWIO_CPR_MARGIN_ADJ_CTL_LOWER_VOLTAGE_WAIT_SELECT_BMSK                          0x60000
#define HWIO_CPR_MARGIN_ADJ_CTL_LOWER_VOLTAGE_WAIT_SELECT_SHFT                             0x11
#define HWIO_CPR_MARGIN_ADJ_CTL_PMIC_STEP_SIZE_BMSK                                     0x1f000
#define HWIO_CPR_MARGIN_ADJ_CTL_PMIC_STEP_SIZE_SHFT                                         0xc
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_BF_BMSK                                       0x800
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_BF_SHFT                                         0xb
#define HWIO_CPR_MARGIN_ADJ_CTL_SAW_ERROR_REPEAT_EN_BMSK                                  0x400
#define HWIO_CPR_MARGIN_ADJ_CTL_SAW_ERROR_REPEAT_EN_SHFT                                    0xa
#define HWIO_CPR_MARGIN_ADJ_CTL_ADJ_SW_RESET_BMSK                                         0x200
#define HWIO_CPR_MARGIN_ADJ_CTL_ADJ_SW_RESET_SHFT                                           0x9
#define HWIO_CPR_MARGIN_ADJ_CTL_KV_MARGIN_ADJ_EN_BMSK                                     0x100
#define HWIO_CPR_MARGIN_ADJ_CTL_KV_MARGIN_ADJ_EN_SHFT                                       0x8
#define HWIO_CPR_MARGIN_ADJ_CTL_PER_RO_KV_MARGIN_EN_BMSK                                   0x80
#define HWIO_CPR_MARGIN_ADJ_CTL_PER_RO_KV_MARGIN_EN_SHFT                                    0x7
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_TEMP_EN_BMSK                                   0x40
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_TEMP_EN_SHFT                                    0x6
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_EN_BMSK                                        0x20
#define HWIO_CPR_MARGIN_ADJ_CTL_WAIT_MID_DN_EN_SHFT                                         0x5
#define HWIO_CPR_MARGIN_ADJ_CTL_CLOSED_LOOP_EN_BMSK                                        0x10
#define HWIO_CPR_MARGIN_ADJ_CTL_CLOSED_LOOP_EN_SHFT                                         0x4
#define HWIO_CPR_MARGIN_ADJ_CTL_TIMER_SETTLE_VOLTAGE_EN_BMSK                                0x8
#define HWIO_CPR_MARGIN_ADJ_CTL_TIMER_SETTLE_VOLTAGE_EN_SHFT                                0x3
#define HWIO_CPR_MARGIN_ADJ_CTL_TEMP_ADJ_EN_BMSK                                            0x4
#define HWIO_CPR_MARGIN_ADJ_CTL_TEMP_ADJ_EN_SHFT                                            0x2
#define HWIO_CPR_MARGIN_ADJ_CTL_CORE_ADJ_EN_BMSK                                            0x2
#define HWIO_CPR_MARGIN_ADJ_CTL_CORE_ADJ_EN_SHFT                                            0x1
#define HWIO_CPR_MARGIN_ADJ_CTL_BOOST_EN_BMSK                                               0x1
#define HWIO_CPR_MARGIN_ADJ_CTL_BOOST_EN_SHFT                                               0x0

#define HWIO_CPR_HW_STARVATION_THRESHOLD_ADDR(x)                                     ((x) + 0x000007fc)
#define HWIO_CPR_HW_STARVATION_THRESHOLD_OFFS                                        (0x000007fc)
#define HWIO_CPR_HW_STARVATION_THRESHOLD_RMSK                                        0xffffffff
#define HWIO_CPR_HW_STARVATION_THRESHOLD_IN(x)      \
        in_dword(HWIO_CPR_HW_STARVATION_THRESHOLD_ADDR(x))
#define HWIO_CPR_HW_STARVATION_THRESHOLD_INM(x, m)      \
        in_dword_masked(HWIO_CPR_HW_STARVATION_THRESHOLD_ADDR(x), m)
#define HWIO_CPR_HW_STARVATION_THRESHOLD_OUT(x, v)      \
        out_dword(HWIO_CPR_HW_STARVATION_THRESHOLD_ADDR(x),v)
#define HWIO_CPR_HW_STARVATION_THRESHOLD_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_CPR_HW_STARVATION_THRESHOLD_ADDR(x),m,v,HWIO_CPR_HW_STARVATION_THRESHOLD_IN(x))
#define HWIO_CPR_HW_STARVATION_THRESHOLD_THRESHOLD_BMSK                              0xffffffff
#define HWIO_CPR_HW_STARVATION_THRESHOLD_THRESHOLD_SHFT                                     0x0

#define HWIO_CPR_CONT_CMD_t_ADDR(base,t)                                             ((base) + 0x00000800 + 0x440 * (t))
#define HWIO_CPR_CONT_CMD_t_OFFS(base,t)                                             (0x00000800 + 0x440 * (t))
#define HWIO_CPR_CONT_CMD_t_RMSK                                                            0x1
#define HWIO_CPR_CONT_CMD_t_MAXt                                                              0
#define HWIO_CPR_CONT_CMD_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_CONT_CMD_t_ADDR(base,t),val)
#define HWIO_CPR_CONT_CMD_t_VDD_CHANGED_ONE_STEP_BMSK                                       0x1
#define HWIO_CPR_CONT_CMD_t_VDD_CHANGED_ONE_STEP_SHFT                                       0x0

#define HWIO_CPR_THRESHOLD_t_ADDR(base,t)                                            ((base) + 0x00000808 + 0x440 * (t))
#define HWIO_CPR_THRESHOLD_t_OFFS(base,t)                                            (0x00000808 + 0x440 * (t))
#define HWIO_CPR_THRESHOLD_t_RMSK                                                       0x3ffff
#define HWIO_CPR_THRESHOLD_t_MAXt                                                             0
#define HWIO_CPR_THRESHOLD_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_THRESHOLD_t_ADDR(base,t), HWIO_CPR_THRESHOLD_t_RMSK)
#define HWIO_CPR_THRESHOLD_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_THRESHOLD_t_ADDR(base,t), mask)
#define HWIO_CPR_THRESHOLD_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_THRESHOLD_t_ADDR(base,t),val)
#define HWIO_CPR_THRESHOLD_t_OUTMI(base,t,mask,val) \
        out_dword_masked_ns(HWIO_CPR_THRESHOLD_t_ADDR(base,t),mask,val,HWIO_CPR_THRESHOLD_t_INI(base,t))
#define HWIO_CPR_THRESHOLD_t_UP_THRESHOLD_BMSK                                          0x3e000
#define HWIO_CPR_THRESHOLD_t_UP_THRESHOLD_SHFT                                              0xd
#define HWIO_CPR_THRESHOLD_t_DN_THRESHOLD_BMSK                                           0x1f00
#define HWIO_CPR_THRESHOLD_t_DN_THRESHOLD_SHFT                                              0x8
#define HWIO_CPR_THRESHOLD_t_CONSECUTIVE_UP_BMSK                                           0xf0
#define HWIO_CPR_THRESHOLD_t_CONSECUTIVE_UP_SHFT                                            0x4
#define HWIO_CPR_THRESHOLD_t_CONSECUTIVE_DN_BMSK                                            0xf
#define HWIO_CPR_THRESHOLD_t_CONSECUTIVE_DN_SHFT                                            0x0

#define HWIO_CPR_MASK_THREAD_t_ADDR(base,t)                                          ((base) + 0x0000080c + 0x440 * (t))
#define HWIO_CPR_MASK_THREAD_t_OFFS(base,t)                                          (0x0000080c + 0x440 * (t))
#define HWIO_CPR_MASK_THREAD_t_RMSK                                                  0x8000ffff
#define HWIO_CPR_MASK_THREAD_t_MAXt                                                           0
#define HWIO_CPR_MASK_THREAD_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_MASK_THREAD_t_ADDR(base,t), HWIO_CPR_MASK_THREAD_t_RMSK)
#define HWIO_CPR_MASK_THREAD_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_MASK_THREAD_t_ADDR(base,t), mask)
#define HWIO_CPR_MASK_THREAD_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_MASK_THREAD_t_ADDR(base,t),val)
#define HWIO_CPR_MASK_THREAD_t_OUTMI(base,t,mask,val) \
        out_dword_masked_ns(HWIO_CPR_MASK_THREAD_t_ADDR(base,t),mask,val,HWIO_CPR_MASK_THREAD_t_INI(base,t))
#define HWIO_CPR_MASK_THREAD_t_DISABLE_THREAD_BMSK                                   0x80000000
#define HWIO_CPR_MASK_THREAD_t_DISABLE_THREAD_SHFT                                         0x1f
#define HWIO_CPR_MASK_THREAD_t_RO_MASK4THREAD_BMSK                                       0xffff
#define HWIO_CPR_MASK_THREAD_t_RO_MASK4THREAD_SHFT                                          0x0

#define HWIO_CPR_RESULT0_t_ADDR(base,t)                                              ((base) + 0x00000810 + 0x440 * (t))
#define HWIO_CPR_RESULT0_t_OFFS(base,t)                                              (0x00000810 + 0x440 * (t))
#define HWIO_CPR_RESULT0_t_RMSK                                                        0x1fffff
#define HWIO_CPR_RESULT0_t_MAXt                                                               0
#define HWIO_CPR_RESULT0_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_RESULT0_t_ADDR(base,t), HWIO_CPR_RESULT0_t_RMSK)
#define HWIO_CPR_RESULT0_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_RESULT0_t_ADDR(base,t), mask)
#define HWIO_CPR_RESULT0_t_ERROR_LT_0_BMSK                                             0x100000
#define HWIO_CPR_RESULT0_t_ERROR_LT_0_SHFT                                                 0x14
#define HWIO_CPR_RESULT0_t_ERROR_BMSK                                                   0xfff00
#define HWIO_CPR_RESULT0_t_ERROR_SHFT                                                       0x8
#define HWIO_CPR_RESULT0_t_ERROR_STEPS_BMSK                                                0xf8
#define HWIO_CPR_RESULT0_t_ERROR_STEPS_SHFT                                                 0x3
#define HWIO_CPR_RESULT0_t_STEP_UP_BMSK                                                     0x4
#define HWIO_CPR_RESULT0_t_STEP_UP_SHFT                                                     0x2
#define HWIO_CPR_RESULT0_t_STEP_DN_BMSK                                                     0x2
#define HWIO_CPR_RESULT0_t_STEP_DN_SHFT                                                     0x1
#define HWIO_CPR_RESULT0_t_BUSY_BMSK                                                        0x1
#define HWIO_CPR_RESULT0_t_BUSY_SHFT                                                        0x0

#define HWIO_CPR_RESULT1_t_ADDR(base,t)                                              ((base) + 0x00000814 + 0x440 * (t))
#define HWIO_CPR_RESULT1_t_OFFS(base,t)                                              (0x00000814 + 0x440 * (t))
#define HWIO_CPR_RESULT1_t_RMSK                                                      0xffffffff
#define HWIO_CPR_RESULT1_t_MAXt                                                               0
#define HWIO_CPR_RESULT1_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_RESULT1_t_ADDR(base,t), HWIO_CPR_RESULT1_t_RMSK)
#define HWIO_CPR_RESULT1_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_RESULT1_t_ADDR(base,t), mask)
#define HWIO_CPR_RESULT1_t_SEL_MAX_BMSK                                              0xf0000000
#define HWIO_CPR_RESULT1_t_SEL_MAX_SHFT                                                    0x1c
#define HWIO_CPR_RESULT1_t_SEL_MIN_BMSK                                               0xf000000
#define HWIO_CPR_RESULT1_t_SEL_MIN_SHFT                                                    0x18
#define HWIO_CPR_RESULT1_t_QUOT_MAX_BMSK                                               0xfff000
#define HWIO_CPR_RESULT1_t_QUOT_MAX_SHFT                                                    0xc
#define HWIO_CPR_RESULT1_t_QUOT_MIN_BMSK                                                  0xfff
#define HWIO_CPR_RESULT1_t_QUOT_MIN_SHFT                                                    0x0

#define HWIO_CPR_RESULT2_t_ADDR(base,t)                                              ((base) + 0x00000818 + 0x440 * (t))
#define HWIO_CPR_RESULT2_t_OFFS(base,t)                                              (0x00000818 + 0x440 * (t))
#define HWIO_CPR_RESULT2_t_RMSK                                                      0xffff0fff
#define HWIO_CPR_RESULT2_t_MAXt                                                               0
#define HWIO_CPR_RESULT2_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_RESULT2_t_ADDR(base,t), HWIO_CPR_RESULT2_t_RMSK)
#define HWIO_CPR_RESULT2_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_RESULT2_t_ADDR(base,t), mask)
#define HWIO_CPR_RESULT2_t_SENSOR_MAX_BMSK                                           0xff000000
#define HWIO_CPR_RESULT2_t_SENSOR_MAX_SHFT                                                 0x18
#define HWIO_CPR_RESULT2_t_SENSOR_MIN_BMSK                                             0xff0000
#define HWIO_CPR_RESULT2_t_SENSOR_MIN_SHFT                                                 0x10
#define HWIO_CPR_RESULT2_t_STEP_QUOT_MAX_BMSK                                             0xfc0
#define HWIO_CPR_RESULT2_t_STEP_QUOT_MAX_SHFT                                               0x6
#define HWIO_CPR_RESULT2_t_STEP_QUOT_MIN_BMSK                                              0x3f
#define HWIO_CPR_RESULT2_t_STEP_QUOT_MIN_SHFT                                               0x0

#define HWIO_CPR_IRQ_EN_t_ADDR(base,t)                                               ((base) + 0x0000081c + 0x440 * (t))
#define HWIO_CPR_IRQ_EN_t_OFFS(base,t)                                               (0x0000081c + 0x440 * (t))
#define HWIO_CPR_IRQ_EN_t_RMSK                                                       0xc000000f
#define HWIO_CPR_IRQ_EN_t_MAXt                                                                0
#define HWIO_CPR_IRQ_EN_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_IRQ_EN_t_ADDR(base,t), HWIO_CPR_IRQ_EN_t_RMSK)
#define HWIO_CPR_IRQ_EN_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_IRQ_EN_t_ADDR(base,t), mask)
#define HWIO_CPR_IRQ_EN_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_IRQ_EN_t_ADDR(base,t),val)
#define HWIO_CPR_IRQ_EN_t_OUTMI(base,t,mask,val) \
        out_dword_masked_ns(HWIO_CPR_IRQ_EN_t_ADDR(base,t),mask,val,HWIO_CPR_IRQ_EN_t_INI(base,t))
#define HWIO_CPR_IRQ_EN_t_CLAMP_CHANGE_WHILE_BUSY_EN_BMSK                            0x80000000
#define HWIO_CPR_IRQ_EN_t_CLAMP_CHANGE_WHILE_BUSY_EN_SHFT                                  0x1f
#define HWIO_CPR_IRQ_EN_t_STARVATION_ERROR_EN_BMSK                                   0x40000000
#define HWIO_CPR_IRQ_EN_t_STARVATION_ERROR_EN_SHFT                                         0x1e
#define HWIO_CPR_IRQ_EN_t_UP_FLAG_EN_BMSK                                                   0x8
#define HWIO_CPR_IRQ_EN_t_UP_FLAG_EN_SHFT                                                   0x3
#define HWIO_CPR_IRQ_EN_t_MID_FLAG_EN_BMSK                                                  0x4
#define HWIO_CPR_IRQ_EN_t_MID_FLAG_EN_SHFT                                                  0x2
#define HWIO_CPR_IRQ_EN_t_DOWN_FLAG_EN_BMSK                                                 0x2
#define HWIO_CPR_IRQ_EN_t_DOWN_FLAG_EN_SHFT                                                 0x1
#define HWIO_CPR_IRQ_EN_t_CPR_DONE_EN_BMSK                                                  0x1
#define HWIO_CPR_IRQ_EN_t_CPR_DONE_EN_SHFT                                                  0x0

#define HWIO_CPR_IRQ_CLEAR_t_ADDR(base,t)                                            ((base) + 0x00000820 + 0x440 * (t))
#define HWIO_CPR_IRQ_CLEAR_t_OFFS(base,t)                                            (0x00000820 + 0x440 * (t))
#define HWIO_CPR_IRQ_CLEAR_t_RMSK                                                    0xc000000f
#define HWIO_CPR_IRQ_CLEAR_t_MAXt                                                             0
#define HWIO_CPR_IRQ_CLEAR_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_IRQ_CLEAR_t_ADDR(base,t),val)
#define HWIO_CPR_IRQ_CLEAR_t_CLAMP_CHANGE_WHILE_BUSY_CLEAR_BMSK                      0x80000000
#define HWIO_CPR_IRQ_CLEAR_t_CLAMP_CHANGE_WHILE_BUSY_CLEAR_SHFT                            0x1f
#define HWIO_CPR_IRQ_CLEAR_t_STARVATION_ERROR_CLEAR_BMSK                             0x40000000
#define HWIO_CPR_IRQ_CLEAR_t_STARVATION_ERROR_CLEAR_SHFT                                   0x1e
#define HWIO_CPR_IRQ_CLEAR_t_UP_FLAG_CLEAR_BMSK                                             0x8
#define HWIO_CPR_IRQ_CLEAR_t_UP_FLAG_CLEAR_SHFT                                             0x3
#define HWIO_CPR_IRQ_CLEAR_t_MID_FLAG_CLEAR_BMSK                                            0x4
#define HWIO_CPR_IRQ_CLEAR_t_MID_FLAG_CLEAR_SHFT                                            0x2
#define HWIO_CPR_IRQ_CLEAR_t_DOWN_FLAG_CLEAR_BMSK                                           0x2
#define HWIO_CPR_IRQ_CLEAR_t_DOWN_FLAG_CLEAR_SHFT                                           0x1
#define HWIO_CPR_IRQ_CLEAR_t_CPR_DONE_CLEAR_BMSK                                            0x1
#define HWIO_CPR_IRQ_CLEAR_t_CPR_DONE_CLEAR_SHFT                                            0x0

#define HWIO_CPR_IRQ_STATUS_t_ADDR(base,t)                                           ((base) + 0x00000824 + 0x440 * (t))
#define HWIO_CPR_IRQ_STATUS_t_OFFS(base,t)                                           (0x00000824 + 0x440 * (t))
#define HWIO_CPR_IRQ_STATUS_t_RMSK                                                   0xc000000f
#define HWIO_CPR_IRQ_STATUS_t_MAXt                                                            0
#define HWIO_CPR_IRQ_STATUS_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_IRQ_STATUS_t_ADDR(base,t), HWIO_CPR_IRQ_STATUS_t_RMSK)
#define HWIO_CPR_IRQ_STATUS_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_IRQ_STATUS_t_ADDR(base,t), mask)
#define HWIO_CPR_IRQ_STATUS_t_CLAMP_CHANGE_WHILE_BUSY_BMSK                           0x80000000
#define HWIO_CPR_IRQ_STATUS_t_CLAMP_CHANGE_WHILE_BUSY_SHFT                                 0x1f
#define HWIO_CPR_IRQ_STATUS_t_STARVATION_ERROR_BMSK                                  0x40000000
#define HWIO_CPR_IRQ_STATUS_t_STARVATION_ERROR_SHFT                                        0x1e
#define HWIO_CPR_IRQ_STATUS_t_UP_FLAG_BMSK                                                  0x8
#define HWIO_CPR_IRQ_STATUS_t_UP_FLAG_SHFT                                                  0x3
#define HWIO_CPR_IRQ_STATUS_t_MID_FLAG_BMSK                                                 0x4
#define HWIO_CPR_IRQ_STATUS_t_MID_FLAG_SHFT                                                 0x2
#define HWIO_CPR_IRQ_STATUS_t_DOWN_FLAG_BMSK                                                0x2
#define HWIO_CPR_IRQ_STATUS_t_DOWN_FLAG_SHFT                                                0x1
#define HWIO_CPR_IRQ_STATUS_t_CPR_DONE_BMSK                                                 0x1
#define HWIO_CPR_IRQ_STATUS_t_CPR_DONE_SHFT                                                 0x0

#define HWIO_CPR_TARGET_MODE_SELECT_t_ADDR(base,t)                                   ((base) + 0x00000828 + 0x440 * (t))
#define HWIO_CPR_TARGET_MODE_SELECT_t_OFFS(base,t)                                   (0x00000828 + 0x440 * (t))
#define HWIO_CPR_TARGET_MODE_SELECT_t_RMSK                                                  0xf
#define HWIO_CPR_TARGET_MODE_SELECT_t_MAXt                                                    0
#define HWIO_CPR_TARGET_MODE_SELECT_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_TARGET_MODE_SELECT_t_ADDR(base,t), HWIO_CPR_TARGET_MODE_SELECT_t_RMSK)
#define HWIO_CPR_TARGET_MODE_SELECT_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_TARGET_MODE_SELECT_t_ADDR(base,t), mask)
#define HWIO_CPR_TARGET_MODE_SELECT_t_OUTI(base,t,val)    \
        out_dword(HWIO_CPR_TARGET_MODE_SELECT_t_ADDR(base,t),val)
#define HWIO_CPR_TARGET_MODE_SELECT_t_OUTMI(base,t,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET_MODE_SELECT_t_ADDR(base,t),mask,val,HWIO_CPR_TARGET_MODE_SELECT_t_INI(base,t))
#define HWIO_CPR_TARGET_MODE_SELECT_t_TARGET_MODE_SELECT_BMSK                               0xf
#define HWIO_CPR_TARGET_MODE_SELECT_t_TARGET_MODE_SELECT_SHFT                               0x0

#define HWIO_CPR_PTE_RESULT_REGISTER_t_ADDR(base,t)                                  ((base) + 0x0000082c + 0x440 * (t))
#define HWIO_CPR_PTE_RESULT_REGISTER_t_OFFS(base,t)                                  (0x0000082c + 0x440 * (t))
#define HWIO_CPR_PTE_RESULT_REGISTER_t_RMSK                                          0xffffffff
#define HWIO_CPR_PTE_RESULT_REGISTER_t_MAXt                                                   0
#define HWIO_CPR_PTE_RESULT_REGISTER_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_PTE_RESULT_REGISTER_t_ADDR(base,t), HWIO_CPR_PTE_RESULT_REGISTER_t_RMSK)
#define HWIO_CPR_PTE_RESULT_REGISTER_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_PTE_RESULT_REGISTER_t_ADDR(base,t), mask)
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SCLK_CNT_FAIL_BMSK                            0x80000000
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SCLK_CNT_FAIL_SHFT                                  0x1f
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SCLK_CNT0_DIV2_BMSK                           0x7f800000
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SCLK_CNT0_DIV2_SHFT                                 0x17
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SENSOR_MIN_BMSK                                 0x7e0000
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SENSOR_MIN_SHFT                                     0x11
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SEL_MIN_BMSK                                     0x1e000
#define HWIO_CPR_PTE_RESULT_REGISTER_t_SEL_MIN_SHFT                                         0xd
#define HWIO_CPR_PTE_RESULT_REGISTER_t_QUOT_MIN_BMSK                                     0x1ffe
#define HWIO_CPR_PTE_RESULT_REGISTER_t_QUOT_MIN_SHFT                                        0x1
#define HWIO_CPR_PTE_RESULT_REGISTER_t_BUSY_BMSK                                            0x1
#define HWIO_CPR_PTE_RESULT_REGISTER_t_BUSY_SHFT                                            0x0

#define HWIO_CPR_TARGET0_0_m_ADDR(base,m)                                            ((base) + 0x00000840 + 0x40 * (m))
#define HWIO_CPR_TARGET0_0_m_OFFS(base,m)                                            (0x00000840 + 0x40 * (m))
#define HWIO_CPR_TARGET0_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET0_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET0_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET0_0_m_ADDR(base,m), HWIO_CPR_TARGET0_0_m_RMSK)
#define HWIO_CPR_TARGET0_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET0_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET0_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET0_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET0_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET0_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET0_0_m_INI(base,m))
#define HWIO_CPR_TARGET0_0_m_MODE_GCNT0_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET0_0_m_MODE_GCNT0_SHFT                                                0xc
#define HWIO_CPR_TARGET0_0_m_TARGET0_BMSK                                                 0xfff
#define HWIO_CPR_TARGET0_0_m_TARGET0_SHFT                                                   0x0

#define HWIO_CPR_TARGET1_0_m_ADDR(base,m)                                            ((base) + 0x00000844 + 0x40 * (m))
#define HWIO_CPR_TARGET1_0_m_OFFS(base,m)                                            (0x00000844 + 0x40 * (m))
#define HWIO_CPR_TARGET1_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET1_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET1_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET1_0_m_ADDR(base,m), HWIO_CPR_TARGET1_0_m_RMSK)
#define HWIO_CPR_TARGET1_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET1_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET1_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET1_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET1_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET1_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET1_0_m_INI(base,m))
#define HWIO_CPR_TARGET1_0_m_MODE_GCNT1_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET1_0_m_MODE_GCNT1_SHFT                                                0xc
#define HWIO_CPR_TARGET1_0_m_TARGET1_BMSK                                                 0xfff
#define HWIO_CPR_TARGET1_0_m_TARGET1_SHFT                                                   0x0

#define HWIO_CPR_TARGET2_0_m_ADDR(base,m)                                            ((base) + 0x00000848 + 0x40 * (m))
#define HWIO_CPR_TARGET2_0_m_OFFS(base,m)                                            (0x00000848 + 0x40 * (m))
#define HWIO_CPR_TARGET2_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET2_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET2_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET2_0_m_ADDR(base,m), HWIO_CPR_TARGET2_0_m_RMSK)
#define HWIO_CPR_TARGET2_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET2_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET2_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET2_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET2_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET2_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET2_0_m_INI(base,m))
#define HWIO_CPR_TARGET2_0_m_MODE_GCNT2_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET2_0_m_MODE_GCNT2_SHFT                                                0xc
#define HWIO_CPR_TARGET2_0_m_TARGET2_BMSK                                                 0xfff
#define HWIO_CPR_TARGET2_0_m_TARGET2_SHFT                                                   0x0

#define HWIO_CPR_TARGET3_0_m_ADDR(base,m)                                            ((base) + 0x0000084c + 0x40 * (m))
#define HWIO_CPR_TARGET3_0_m_OFFS(base,m)                                            (0x0000084c + 0x40 * (m))
#define HWIO_CPR_TARGET3_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET3_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET3_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET3_0_m_ADDR(base,m), HWIO_CPR_TARGET3_0_m_RMSK)
#define HWIO_CPR_TARGET3_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET3_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET3_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET3_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET3_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET3_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET3_0_m_INI(base,m))
#define HWIO_CPR_TARGET3_0_m_MODE_GCNT3_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET3_0_m_MODE_GCNT3_SHFT                                                0xc
#define HWIO_CPR_TARGET3_0_m_TARGET3_BMSK                                                 0xfff
#define HWIO_CPR_TARGET3_0_m_TARGET3_SHFT                                                   0x0

#define HWIO_CPR_TARGET4_0_m_ADDR(base,m)                                            ((base) + 0x00000850 + 0x40 * (m))
#define HWIO_CPR_TARGET4_0_m_OFFS(base,m)                                            (0x00000850 + 0x40 * (m))
#define HWIO_CPR_TARGET4_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET4_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET4_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET4_0_m_ADDR(base,m), HWIO_CPR_TARGET4_0_m_RMSK)
#define HWIO_CPR_TARGET4_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET4_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET4_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET4_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET4_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET4_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET4_0_m_INI(base,m))
#define HWIO_CPR_TARGET4_0_m_MODE_GCNT4_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET4_0_m_MODE_GCNT4_SHFT                                                0xc
#define HWIO_CPR_TARGET4_0_m_TARGET4_BMSK                                                 0xfff
#define HWIO_CPR_TARGET4_0_m_TARGET4_SHFT                                                   0x0

#define HWIO_CPR_TARGET5_0_m_ADDR(base,m)                                            ((base) + 0x00000854 + 0x40 * (m))
#define HWIO_CPR_TARGET5_0_m_OFFS(base,m)                                            (0x00000854 + 0x40 * (m))
#define HWIO_CPR_TARGET5_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET5_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET5_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET5_0_m_ADDR(base,m), HWIO_CPR_TARGET5_0_m_RMSK)
#define HWIO_CPR_TARGET5_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET5_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET5_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET5_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET5_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET5_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET5_0_m_INI(base,m))
#define HWIO_CPR_TARGET5_0_m_MODE_GCNT5_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET5_0_m_MODE_GCNT5_SHFT                                                0xc
#define HWIO_CPR_TARGET5_0_m_TARGET5_BMSK                                                 0xfff
#define HWIO_CPR_TARGET5_0_m_TARGET5_SHFT                                                   0x0

#define HWIO_CPR_TARGET6_0_m_ADDR(base,m)                                            ((base) + 0x00000858 + 0x40 * (m))
#define HWIO_CPR_TARGET6_0_m_OFFS(base,m)                                            (0x00000858 + 0x40 * (m))
#define HWIO_CPR_TARGET6_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET6_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET6_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET6_0_m_ADDR(base,m), HWIO_CPR_TARGET6_0_m_RMSK)
#define HWIO_CPR_TARGET6_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET6_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET6_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET6_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET6_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET6_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET6_0_m_INI(base,m))
#define HWIO_CPR_TARGET6_0_m_MODE_GCNT6_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET6_0_m_MODE_GCNT6_SHFT                                                0xc
#define HWIO_CPR_TARGET6_0_m_TARGET6_BMSK                                                 0xfff
#define HWIO_CPR_TARGET6_0_m_TARGET6_SHFT                                                   0x0

#define HWIO_CPR_TARGET7_0_m_ADDR(base,m)                                            ((base) + 0x0000085c + 0x40 * (m))
#define HWIO_CPR_TARGET7_0_m_OFFS(base,m)                                            (0x0000085c + 0x40 * (m))
#define HWIO_CPR_TARGET7_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET7_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET7_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET7_0_m_ADDR(base,m), HWIO_CPR_TARGET7_0_m_RMSK)
#define HWIO_CPR_TARGET7_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET7_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET7_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET7_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET7_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET7_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET7_0_m_INI(base,m))
#define HWIO_CPR_TARGET7_0_m_MODE_GCNT7_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET7_0_m_MODE_GCNT7_SHFT                                                0xc
#define HWIO_CPR_TARGET7_0_m_TARGET7_BMSK                                                 0xfff
#define HWIO_CPR_TARGET7_0_m_TARGET7_SHFT                                                   0x0

#define HWIO_CPR_TARGET8_0_m_ADDR(base,m)                                            ((base) + 0x00000860 + 0x40 * (m))
#define HWIO_CPR_TARGET8_0_m_OFFS(base,m)                                            (0x00000860 + 0x40 * (m))
#define HWIO_CPR_TARGET8_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET8_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET8_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET8_0_m_ADDR(base,m), HWIO_CPR_TARGET8_0_m_RMSK)
#define HWIO_CPR_TARGET8_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET8_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET8_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET8_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET8_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET8_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET8_0_m_INI(base,m))
#define HWIO_CPR_TARGET8_0_m_MODE_GCNT8_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET8_0_m_MODE_GCNT8_SHFT                                                0xc
#define HWIO_CPR_TARGET8_0_m_TARGET8_BMSK                                                 0xfff
#define HWIO_CPR_TARGET8_0_m_TARGET8_SHFT                                                   0x0

#define HWIO_CPR_TARGET9_0_m_ADDR(base,m)                                            ((base) + 0x00000864 + 0x40 * (m))
#define HWIO_CPR_TARGET9_0_m_OFFS(base,m)                                            (0x00000864 + 0x40 * (m))
#define HWIO_CPR_TARGET9_0_m_RMSK                                                      0x3fffff
#define HWIO_CPR_TARGET9_0_m_MAXm                                                            15
#define HWIO_CPR_TARGET9_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET9_0_m_ADDR(base,m), HWIO_CPR_TARGET9_0_m_RMSK)
#define HWIO_CPR_TARGET9_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET9_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET9_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET9_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET9_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET9_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET9_0_m_INI(base,m))
#define HWIO_CPR_TARGET9_0_m_MODE_GCNT9_BMSK                                           0x3ff000
#define HWIO_CPR_TARGET9_0_m_MODE_GCNT9_SHFT                                                0xc
#define HWIO_CPR_TARGET9_0_m_TARGET9_BMSK                                                 0xfff
#define HWIO_CPR_TARGET9_0_m_TARGET9_SHFT                                                   0x0

#define HWIO_CPR_TARGET10_0_m_ADDR(base,m)                                           ((base) + 0x00000868 + 0x40 * (m))
#define HWIO_CPR_TARGET10_0_m_OFFS(base,m)                                           (0x00000868 + 0x40 * (m))
#define HWIO_CPR_TARGET10_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET10_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET10_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET10_0_m_ADDR(base,m), HWIO_CPR_TARGET10_0_m_RMSK)
#define HWIO_CPR_TARGET10_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET10_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET10_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET10_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET10_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET10_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET10_0_m_INI(base,m))
#define HWIO_CPR_TARGET10_0_m_MODE_GCNT10_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET10_0_m_MODE_GCNT10_SHFT                                              0xc
#define HWIO_CPR_TARGET10_0_m_TARGET10_BMSK                                               0xfff
#define HWIO_CPR_TARGET10_0_m_TARGET10_SHFT                                                 0x0

#define HWIO_CPR_TARGET11_0_m_ADDR(base,m)                                           ((base) + 0x0000086c + 0x40 * (m))
#define HWIO_CPR_TARGET11_0_m_OFFS(base,m)                                           (0x0000086c + 0x40 * (m))
#define HWIO_CPR_TARGET11_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET11_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET11_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET11_0_m_ADDR(base,m), HWIO_CPR_TARGET11_0_m_RMSK)
#define HWIO_CPR_TARGET11_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET11_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET11_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET11_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET11_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET11_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET11_0_m_INI(base,m))
#define HWIO_CPR_TARGET11_0_m_MODE_GCNT11_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET11_0_m_MODE_GCNT11_SHFT                                              0xc
#define HWIO_CPR_TARGET11_0_m_TARGET11_BMSK                                               0xfff
#define HWIO_CPR_TARGET11_0_m_TARGET11_SHFT                                                 0x0

#define HWIO_CPR_TARGET12_0_m_ADDR(base,m)                                           ((base) + 0x00000870 + 0x40 * (m))
#define HWIO_CPR_TARGET12_0_m_OFFS(base,m)                                           (0x00000870 + 0x40 * (m))
#define HWIO_CPR_TARGET12_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET12_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET12_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET12_0_m_ADDR(base,m), HWIO_CPR_TARGET12_0_m_RMSK)
#define HWIO_CPR_TARGET12_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET12_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET12_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET12_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET12_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET12_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET12_0_m_INI(base,m))
#define HWIO_CPR_TARGET12_0_m_MODE_GCNT12_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET12_0_m_MODE_GCNT12_SHFT                                              0xc
#define HWIO_CPR_TARGET12_0_m_TARGET12_BMSK                                               0xfff
#define HWIO_CPR_TARGET12_0_m_TARGET12_SHFT                                                 0x0

#define HWIO_CPR_TARGET13_0_m_ADDR(base,m)                                           ((base) + 0x00000874 + 0x40 * (m))
#define HWIO_CPR_TARGET13_0_m_OFFS(base,m)                                           (0x00000874 + 0x40 * (m))
#define HWIO_CPR_TARGET13_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET13_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET13_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET13_0_m_ADDR(base,m), HWIO_CPR_TARGET13_0_m_RMSK)
#define HWIO_CPR_TARGET13_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET13_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET13_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET13_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET13_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET13_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET13_0_m_INI(base,m))
#define HWIO_CPR_TARGET13_0_m_MODE_GCNT13_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET13_0_m_MODE_GCNT13_SHFT                                              0xc
#define HWIO_CPR_TARGET13_0_m_TARGET13_BMSK                                               0xfff
#define HWIO_CPR_TARGET13_0_m_TARGET13_SHFT                                                 0x0

#define HWIO_CPR_TARGET14_0_m_ADDR(base,m)                                           ((base) + 0x00000878 + 0x40 * (m))
#define HWIO_CPR_TARGET14_0_m_OFFS(base,m)                                           (0x00000878 + 0x40 * (m))
#define HWIO_CPR_TARGET14_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET14_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET14_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET14_0_m_ADDR(base,m), HWIO_CPR_TARGET14_0_m_RMSK)
#define HWIO_CPR_TARGET14_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET14_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET14_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET14_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET14_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET14_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET14_0_m_INI(base,m))
#define HWIO_CPR_TARGET14_0_m_MODE_GCNT14_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET14_0_m_MODE_GCNT14_SHFT                                              0xc
#define HWIO_CPR_TARGET14_0_m_TARGET14_BMSK                                               0xfff
#define HWIO_CPR_TARGET14_0_m_TARGET14_SHFT                                                 0x0

#define HWIO_CPR_TARGET15_0_m_ADDR(base,m)                                           ((base) + 0x0000087c + 0x40 * (m))
#define HWIO_CPR_TARGET15_0_m_OFFS(base,m)                                           (0x0000087c + 0x40 * (m))
#define HWIO_CPR_TARGET15_0_m_RMSK                                                     0x3fffff
#define HWIO_CPR_TARGET15_0_m_MAXm                                                           15
#define HWIO_CPR_TARGET15_0_m_INI(base,m)        \
        in_dword_masked(HWIO_CPR_TARGET15_0_m_ADDR(base,m), HWIO_CPR_TARGET15_0_m_RMSK)
#define HWIO_CPR_TARGET15_0_m_INMI(base,m,mask)    \
        in_dword_masked(HWIO_CPR_TARGET15_0_m_ADDR(base,m), mask)
#define HWIO_CPR_TARGET15_0_m_OUTI(base,m,val)    \
        out_dword(HWIO_CPR_TARGET15_0_m_ADDR(base,m),val)
#define HWIO_CPR_TARGET15_0_m_OUTMI(base,m,mask,val) \
        out_dword_masked_ns(HWIO_CPR_TARGET15_0_m_ADDR(base,m),mask,val,HWIO_CPR_TARGET15_0_m_INI(base,m))
#define HWIO_CPR_TARGET15_0_m_MODE_GCNT15_BMSK                                         0x3ff000
#define HWIO_CPR_TARGET15_0_m_MODE_GCNT15_SHFT                                              0xc
#define HWIO_CPR_TARGET15_0_m_TARGET15_BMSK                                               0xfff
#define HWIO_CPR_TARGET15_0_m_TARGET15_SHFT                                                 0x0

#define HWIO_CPR_QSENSE_CTRL_q_ADDR(base,q)                                          ((base) + 0x00003100 + 0x4 * (q))
#define HWIO_CPR_QSENSE_CTRL_q_OFFS(base,q)                                          (0x00003100 + 0x4 * (q))
#define HWIO_CPR_QSENSE_CTRL_q_RMSK                                                    0x7fffff
#define HWIO_CPR_QSENSE_CTRL_q_MAXq                                                           1
#define HWIO_CPR_QSENSE_CTRL_q_INI(base,q)        \
        in_dword_masked(HWIO_CPR_QSENSE_CTRL_q_ADDR(base,q), HWIO_CPR_QSENSE_CTRL_q_RMSK)
#define HWIO_CPR_QSENSE_CTRL_q_INMI(base,q,mask)    \
        in_dword_masked(HWIO_CPR_QSENSE_CTRL_q_ADDR(base,q), mask)
#define HWIO_CPR_QSENSE_CTRL_q_OUTI(base,q,val)    \
        out_dword(HWIO_CPR_QSENSE_CTRL_q_ADDR(base,q),val)
#define HWIO_CPR_QSENSE_CTRL_q_OUTMI(base,q,mask,val) \
        out_dword_masked_ns(HWIO_CPR_QSENSE_CTRL_q_ADDR(base,q),mask,val,HWIO_CPR_QSENSE_CTRL_q_INI(base,q))
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_RST_BMSK                                         0x400000
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_RST_SHFT                                             0x16
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_EN_BMSK                                          0x200000
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_EN_SHFT                                              0x15
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_ISO_EN_BMSK                                      0x100000
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_ISO_EN_SHFT                                          0x14
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_PWR_EN_BMSK                                       0x80000
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_PWR_EN_SHFT                                          0x13
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_OVERRIDE_BMSK                                     0x40000
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_OVERRIDE_SHFT                                        0x12
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_GCNT_BMSK                                         0x3f800
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_GCNT_SHFT                                             0xb
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_START_BMSK                                          0x400
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_START_SHFT                                            0xa
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_ADDR_BMSK                                           0x3ff
#define HWIO_CPR_QSENSE_CTRL_q_QSENSE_ADDR_SHFT                                             0x0

#define HWIO_CPR_QSENSE_STATUS_q_ADDR(base,q)                                        ((base) + 0x00003110 + 0x4 * (q))
#define HWIO_CPR_QSENSE_STATUS_q_OFFS(base,q)                                        (0x00003110 + 0x4 * (q))
#define HWIO_CPR_QSENSE_STATUS_q_RMSK                                                    0x1fff
#define HWIO_CPR_QSENSE_STATUS_q_MAXq                                                         1
#define HWIO_CPR_QSENSE_STATUS_q_INI(base,q)        \
        in_dword_masked(HWIO_CPR_QSENSE_STATUS_q_ADDR(base,q), HWIO_CPR_QSENSE_STATUS_q_RMSK)
#define HWIO_CPR_QSENSE_STATUS_q_INMI(base,q,mask)    \
        in_dword_masked(HWIO_CPR_QSENSE_STATUS_q_ADDR(base,q), mask)
#define HWIO_CPR_QSENSE_STATUS_q_QSENSE_RO_CNT_BMSK                                      0x1fff
#define HWIO_CPR_QSENSE_STATUS_q_QSENSE_RO_CNT_SHFT                                         0x0

#define HWIO_CPR_QUOT_MAXMIN_ROr_ADDR(base,r)                                        ((base) + 0x00003200 + 0x8 * (r))
#define HWIO_CPR_QUOT_MAXMIN_ROr_OFFS(base,r)                                        (0x00003200 + 0x8 * (r))
#define HWIO_CPR_QUOT_MAXMIN_ROr_RMSK                                                 0xfff0fff
#define HWIO_CPR_QUOT_MAXMIN_ROr_MAXr                                                        15
#define HWIO_CPR_QUOT_MAXMIN_ROr_INI(base,r)        \
        in_dword_masked(HWIO_CPR_QUOT_MAXMIN_ROr_ADDR(base,r), HWIO_CPR_QUOT_MAXMIN_ROr_RMSK)
#define HWIO_CPR_QUOT_MAXMIN_ROr_INMI(base,r,mask)    \
        in_dword_masked(HWIO_CPR_QUOT_MAXMIN_ROr_ADDR(base,r), mask)
#define HWIO_CPR_QUOT_MAXMIN_ROr_QUOT_MAX_BMSK                                        0xfff0000
#define HWIO_CPR_QUOT_MAXMIN_ROr_QUOT_MAX_SHFT                                             0x10
#define HWIO_CPR_QUOT_MAXMIN_ROr_QUOT_MIN_BMSK                                            0xfff
#define HWIO_CPR_QUOT_MAXMIN_ROr_QUOT_MIN_SHFT                                              0x0

#define HWIO_CPR_QUOT_SUM_ROr_ADDR(base,r)                                           ((base) + 0x00003204 + 0x8 * (r))
#define HWIO_CPR_QUOT_SUM_ROr_OFFS(base,r)                                           (0x00003204 + 0x8 * (r))
#define HWIO_CPR_QUOT_SUM_ROr_RMSK                                                      0x3ffff
#define HWIO_CPR_QUOT_SUM_ROr_MAXr                                                           15
#define HWIO_CPR_QUOT_SUM_ROr_INI(base,r)        \
        in_dword_masked(HWIO_CPR_QUOT_SUM_ROr_ADDR(base,r), HWIO_CPR_QUOT_SUM_ROr_RMSK)
#define HWIO_CPR_QUOT_SUM_ROr_INMI(base,r,mask)    \
        in_dword_masked(HWIO_CPR_QUOT_SUM_ROr_ADDR(base,r), mask)
#define HWIO_CPR_QUOT_SUM_ROr_QUOT_SUM_BMSK                                             0x3ffff
#define HWIO_CPR_QUOT_SUM_ROr_QUOT_SUM_SHFT                                                 0x0

#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_ADDR(x)                                      ((x) + 0x00003280)
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_OFFS                                         (0x00003280)
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_RMSK                                              0x3ff
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_IN(x)      \
        in_dword(HWIO_CPR_TOTAL_UNMASKED_SENSORS_ADDR(x))
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_INM(x, m)      \
        in_dword_masked(HWIO_CPR_TOTAL_UNMASKED_SENSORS_ADDR(x), m)
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_TOTAL_UNMASKED_SENSORS_BMSK                       0x3ff
#define HWIO_CPR_TOTAL_UNMASKED_SENSORS_TOTAL_UNMASKED_SENSORS_SHFT                         0x0

#define HWIO_CPR_BIST_QUOT_CHECK_NEW_ADDR(x)                                         ((x) + 0x00003284)
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_OFFS                                            (0x00003284)
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_RMSK                                                 0xfff
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_IN(x)      \
        in_dword(HWIO_CPR_BIST_QUOT_CHECK_NEW_ADDR(x))
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_INM(x, m)      \
        in_dword_masked(HWIO_CPR_BIST_QUOT_CHECK_NEW_ADDR(x), m)
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_FAIL_SEL_MAX_BMSK                                    0xfc0
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_FAIL_SEL_MAX_SHFT                                      0x6
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_FAIL_SEL_MIN_BMSK                                     0x3f
#define HWIO_CPR_BIST_QUOT_CHECK_NEW_FAIL_SEL_MIN_SHFT                                      0x0

#define HWIO_CPR_RESULT_t_ADDR(base,t)                                               ((base) + 0x00003288 + 0x4 * (t))
#define HWIO_CPR_RESULT_t_OFFS(base,t)                                               (0x00003288 + 0x4 * (t))
#define HWIO_CPR_RESULT_t_RMSK                                                            0xfff
#define HWIO_CPR_RESULT_t_MAXt                                                                0
#define HWIO_CPR_RESULT_t_INI(base,t)        \
        in_dword_masked(HWIO_CPR_RESULT_t_ADDR(base,t), HWIO_CPR_RESULT_t_RMSK)
#define HWIO_CPR_RESULT_t_INMI(base,t,mask)    \
        in_dword_masked(HWIO_CPR_RESULT_t_ADDR(base,t), mask)
#define HWIO_CPR_RESULT_t_SEL_MAX_BMSK                                                    0xfc0
#define HWIO_CPR_RESULT_t_SEL_MAX_SHFT                                                      0x6
#define HWIO_CPR_RESULT_t_SEL_MIN_BMSK                                                     0x3f
#define HWIO_CPR_RESULT_t_SEL_MIN_SHFT                                                      0x0


#endif /* __CPR_HWIO_H__ */
