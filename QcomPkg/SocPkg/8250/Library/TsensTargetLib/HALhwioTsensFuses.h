#ifndef __HALHWIOTSENSFUSES_H__
#define __HALHWIOTSENSFUSES_H__
/*
===========================================================================
*/
/**
  @file HALhwioTsensFuses.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) [kona_v1.0_p3q2r17.8_MTO]
 
  This file contains HWIO register definitions for the following modules:
    SECURITY_CONTROL_CORE

  'Include' filters applied: QFPROM_CORR_CALIB.*[SECURITY_CONTROL_CORE] 

  Generation parameters: 
  { u'filename': u'HALhwioTsensFuses.h',
    u'header': u'#include "msmhwiobase.h"',
    u'module-filter-exclude': { },
    u'module-filter-include': { u'SECURITY_CONTROL_CORE': [ u'QFPROM_CORR_CALIB.*']},
    u'modules': [u'SECURITY_CONTROL_CORE']}
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/TsensTargetLib/HALhwioTsensFuses.h#5 $
  $DateTime: 2019/02/08 13:26:04 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SECURITY_CONTROL_CORE
 *--------------------------------------------------------------------------*/

#define SECURITY_CONTROL_CORE_REG_BASE                                                          (SECURITY_CONTROL_BASE      + 0x00000000)
#define SECURITY_CONTROL_CORE_REG_BASE_SIZE                                                     0x7000
#define SECURITY_CONTROL_CORE_REG_BASE_USED                                                     0x6400

#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004290)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD2_BMSK                                              0xfe000000
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD2_SHFT                                                    0x19
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_USB2PHY_RCAL_CODE_BMSK                                   0x1e00000
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_USB2PHY_RCAL_CODE_SHFT                                        0x15
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD1_BMSK                                                0x1ff000
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD1_SHFT                                                     0xc
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_VREF_TRIM_BMSK                              0xf80
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_VREF_TRIM_SHFT                                0x7
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_ENABLE_NOM_BMSK                              0x40
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_ENABLE_NOM_SHFT                               0x6
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD_BMSK                                                     0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004294)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004298)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000429c)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RSVD1_BMSK                                              0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RSVD1_SHFT                                                    0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_NORTH_BGV_TRIM_BMSK                              0x7f800000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_NORTH_BGV_TRIM_SHFT                                    0x17
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_SOUTH_BGV_TRIM_BMSK                                0x7f8000
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_REFGEN_SOUTH_BGV_TRIM_SHFT                                     0xf
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_BANDGAP_TRIM_BMSK                                           0x7f00
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_BANDGAP_TRIM_SHFT                                              0x8
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RSVD_BMSK                                                     0xff
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042a0)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_AOSS_K_13_0_BMSK                                        0xfffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_AOSS_K_13_0_SHFT                                              0x12
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_AOSS_N1_BMSK                                               0x3ffff
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_AOSS_N1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042a4)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_RSVD_BMSK                                               0xff000000
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_RSVD_SHFT                                                     0x18
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_DCOPCODE_BMSK                                        0x800000
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_DCOPCODE_SHFT                                            0x17
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_TDOPCODE_BMSK                                        0x700000
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_TDOPCODE_SHFT                                            0x14
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_P1_BMSK                                               0xffffc
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_P1_SHFT                                                   0x2
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_K_15_14_BMSK                                              0x3
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_AOSS_K_15_14_SHFT                                              0x0

#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042a8)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS1_BASE1_1_0_BMSK                                   0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS1_BASE1_1_0_SHFT                                         0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS0_BASE1_BMSK                                       0x3ff00000
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS0_BASE1_SHFT                                             0x14
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS1_BASE0_BMSK                                          0xffc00
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS1_BASE0_SHFT                                              0xa
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS0_BASE0_BMSK                                            0x3ff
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_TSENS0_BASE0_SHFT                                              0x0

#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042ac)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS4_OFFSET_3_0_BMSK                                  0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS4_OFFSET_3_0_SHFT                                        0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS3_OFFSET_BMSK                                       0xf800000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS3_OFFSET_SHFT                                            0x17
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS2_OFFSET_BMSK                                        0x7c0000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS2_OFFSET_SHFT                                            0x12
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS1_OFFSET_BMSK                                         0x3e000
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS1_OFFSET_SHFT                                             0xd
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS0_OFFSET_BMSK                                          0x1f00
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS0_OFFSET_SHFT                                             0x8
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS1_BASE1_9_2_BMSK                                         0xff
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_TSENS1_BASE1_9_2_SHFT                                          0x0

#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042b0)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS11_OFFSET_0_BMSK                                   0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS11_OFFSET_0_SHFT                                         0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS10_OFFSET_BMSK                                     0x7c000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS10_OFFSET_SHFT                                           0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS9_OFFSET_BMSK                                       0x3e00000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS9_OFFSET_SHFT                                            0x15
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS8_OFFSET_BMSK                                        0x1f0000
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS8_OFFSET_SHFT                                            0x10
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS7_OFFSET_BMSK                                          0xf800
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS7_OFFSET_SHFT                                             0xb
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS6_OFFSET_BMSK                                           0x7c0
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS6_OFFSET_SHFT                                             0x6
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS5_OFFSET_BMSK                                            0x3e
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS5_OFFSET_SHFT                                             0x1
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS4_OFFSET_4_BMSK                                           0x1
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_TSENS4_OFFSET_4_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042b4)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS17_OFFSET_2_0_BMSK                                 0xe0000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS17_OFFSET_2_0_SHFT                                       0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS16_OFFSET_BMSK                                     0x1f000000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS16_OFFSET_SHFT                                           0x18
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS15_OFFSET_BMSK                                       0xf80000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS15_OFFSET_SHFT                                           0x13
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS14_OFFSET_BMSK                                        0x7c000
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS14_OFFSET_SHFT                                            0xe
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS13_OFFSET_BMSK                                         0x3e00
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS13_OFFSET_SHFT                                            0x9
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS12_OFFSET_BMSK                                          0x1f0
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS12_OFFSET_SHFT                                            0x4
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS11_OFFSET_4_1_BMSK                                        0xf
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_TSENS11_OFFSET_4_1_SHFT                                        0x0

#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042b8)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS23_OFFSET_BMSK                                     0xf8000000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS23_OFFSET_SHFT                                           0x1b
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS22_OFFSET_BMSK                                      0x7c00000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS22_OFFSET_SHFT                                           0x16
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS21_OFFSET_BMSK                                       0x3e0000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS21_OFFSET_SHFT                                           0x11
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS20_OFFSET_BMSK                                        0x1f000
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS20_OFFSET_SHFT                                            0xc
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS19_OFFSET_BMSK                                          0xf80
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS19_OFFSET_SHFT                                            0x7
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS18_OFFSET_BMSK                                           0x7c
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS18_OFFSET_SHFT                                            0x2
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS17_OFFSET_4_3_BMSK                                        0x3
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_TSENS17_OFFSET_4_3_SHFT                                        0x0

#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042bc)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_RSVD_BMSK                                               0xffffff00
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_RSVD_SHFT                                                      0x8
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_TSENS_CAL_SEL_BMSK                                            0xe0
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_TSENS_CAL_SEL_SHFT                                             0x5
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_TSENS24_OFFSET_BMSK                                           0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_TSENS24_OFFSET_SHFT                                            0x0

#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042c0)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S5_BMSK                                    0xe0000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S5_SHFT                                          0x1d
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S4_BMSK                                    0x1c000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S4_SHFT                                          0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S3_BMSK                                     0x3800000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S3_SHFT                                          0x17
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S2_BMSK                                      0x700000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S2_SHFT                                          0x14
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S1_BMSK                                       0xe0000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S1_SHFT                                          0x11
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S0_BMSK                                       0x1c000
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_S0_SHFT                                           0xe
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE2_BMSK                                           0x3f00
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE2_SHFT                                              0x8
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_BMSK                                             0xff
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_VSENSE_FUSE1_SHFT                                              0x0

#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042c4)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S6_BMSK                                    0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S6_SHFT                                          0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S5_BMSK                                    0x30000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S5_SHFT                                          0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S4_BMSK                                     0xc000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S4_SHFT                                          0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S3_BMSK                                     0x3000000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S3_SHFT                                          0x18
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S2_BMSK                                      0xc00000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S2_SHFT                                          0x16
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S1_BMSK                                      0x300000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S1_SHFT                                          0x14
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S0_BMSK                                       0xc0000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE2_S0_SHFT                                          0x12
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_RSVD_BMSK                                                  0x3f000
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_RSVD_SHFT                                                      0xc
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S9_BMSK                                         0xe00
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S9_SHFT                                           0x9
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S8_BMSK                                         0x1c0
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S8_SHFT                                           0x6
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S7_BMSK                                          0x38
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S7_SHFT                                           0x3
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S6_BMSK                                           0x7
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_VSENSE_FUSE1_S6_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042c8)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_RSVD_BMSK                                               0xffffffc0
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_RSVD_SHFT                                                      0x6
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S9_BMSK                                          0x30
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S9_SHFT                                           0x4
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S8_BMSK                                           0xc
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S8_SHFT                                           0x2
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S7_BMSK                                           0x3
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_VSENSE_FUSE2_S7_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042cc)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d0)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d4)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d8)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042dc)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e0)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e4)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e8)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042ec)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f0)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f4)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f8)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_MM_MODE_DISABLE_0_BMSK                             0x80000000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_MM_MODE_DISABLE_0_SHFT                                   0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_SSC_CX_MODE_DISABLE_BMSK                           0x70000000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_SSC_CX_MODE_DISABLE_SHFT                                 0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_DDR_MODE_DISABLE_BMSK                               0xe000000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_DDR_MODE_DISABLE_SHFT                                    0x19
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_GFX_MODE_DISABLE_BMSK                               0x1c00000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_GFX_MODE_DISABLE_SHFT                                    0x16
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_CX_MODE_DISABLE_BMSK                                 0x380000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_CX_MODE_DISABLE_SHFT                                     0x13
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_LOCAL_RC_BMSK                                         0x70000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_LOCAL_RC_SHFT                                            0x10
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_GLOBAL_RC_BMSK                                         0xe000
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_CPR_GLOBAL_RC_SHFT                                            0xd
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_AON_AGING_BMSK                                             0x1fe0
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_AON_AGING_SHFT                                                0x5
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_AON_TARG_VOLT_BMSK                                           0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_AON_TARG_VOLT_SHFT                                            0x0

#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042fc)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW13_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_RSVD_BMSK                                              0xfffffffc
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_RSVD_SHFT                                                     0x2
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR_MM_MODE_DISABLE_2_1_BMSK                                  0x3
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_CPR_MM_MODE_DISABLE_2_1_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004300)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_NOM_BMSK                         0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_NOM_SHFT                               0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_TUR_BMSK                          0xf000000
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_TUR_SHFT                               0x18
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_SUT_BMSK                           0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_SUT_SHFT                               0x14
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS3_BMSK                                  0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS3_SHFT                                      0xf
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS_BMSK                                    0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS_SHFT                                       0xa
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_NOM_BMSK                                     0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_NOM_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SUT_BMSK                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SUT_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004304)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW14_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_RSVD_BMSK                                              0xfff00000
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_RSVD_SHFT                                                    0x14
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_AGING_BMSK                                           0xff000
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_AGING_SHFT                                               0xc
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS3_BMSK                             0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS3_SHFT                               0x8
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_BMSK                              0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_SHFT                               0x4
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS_BMSK                                0xf
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004308)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_NOM_BMSK                         0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_NOM_SHFT                               0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_TUR_BMSK                          0xf000000
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_TUR_SHFT                               0x18
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_SUT_BMSK                           0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_SUT_SHFT                               0x14
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS3_BMSK                                  0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS3_SHFT                                      0xf
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS_BMSK                                    0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS_SHFT                                       0xa
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_NOM_BMSK                                     0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_NOM_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SUT_BMSK                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SUT_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000430c)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW15_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_RSVD_BMSK                                              0xfff00000
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_RSVD_SHFT                                                    0x14
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_AGING_BMSK                                           0xff000
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_AGING_SHFT                                               0xc
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS3_BMSK                             0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS3_SHFT                               0x8
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS2_BMSK                              0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS2_SHFT                               0x4
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS_BMSK                                0xf
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004310)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_NOM_1_0_BMSK                            0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_NOM_1_0_SHFT                                  0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_TUR_BMSK                                0x3e000000
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_TUR_SHFT                                      0x19
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_SUT_BMSK                                 0x1f00000
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR3_TARG_VOLT_SUT_SHFT                                      0x14
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS3_BMSK                                  0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS3_SHFT                                      0xf
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS_BMSK                                    0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS_SHFT                                       0xa
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_NOM_BMSK                                     0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_NOM_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_TUR_BMSK                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_CPR2_TARG_VOLT_TUR_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004314)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW16_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_RSVD_BMSK                                              0xff000000
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_RSVD_SHFT                                                    0x18
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SVSP_BMSK                          0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SVSP_SHFT                              0x14
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_NOM_BMSK                            0xf0000
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_NOM_SHFT                               0x10
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_TUR_BMSK                             0xf000
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_TUR_SHFT                                0xc
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SUT_BMSK                              0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SUT_SHFT                                0x8
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_SVSP_BMSK                                     0xf8
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_SVSP_SHFT                                      0x3
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_NOM_4_2_BMSK                                   0x7
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_CPR3_TARG_VOLT_NOM_4_2_SHFT                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004318)
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW17_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW17_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_OFFSET_TUR_1_0_BMSK                     0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_OFFSET_TUR_1_0_SHFT                           0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS3_BMSK                               0x3e000000
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS3_SHFT                                     0x19
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS_BMSK                                 0x1f00000
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS_SHFT                                      0x14
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_NOM_BMSK                                   0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_NOM_SHFT                                       0xf
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_TUR_BMSK                                    0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR5_TARG_VOLT_TUR_SHFT                                       0xa
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR4_TARG_VOLT_NOM_BMSK                                     0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR4_TARG_VOLT_NOM_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR4_TARG_VOLT_TUR_BMSK                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_CPR4_TARG_VOLT_TUR_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000431c)
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW17_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW17_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_RSVD_BMSK                                              0xfc000000
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_RSVD_SHFT                                                    0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_AGING_BMSK                                         0x3fc0000
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_AGING_SHFT                                              0x12
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS3_BMSK                           0x3c000
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS3_SHFT                               0xe
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS2_BMSK                            0x3c00
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS2_SHFT                               0xa
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS_BMSK                              0x3c0
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS_SHFT                                0x6
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_NOM_BMSK                               0x3c
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_NOM_SHFT                                0x2
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_TUR_3_2_BMSK                            0x3
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_TUR_3_2_SHFT                            0x0

#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004320)
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW18_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW18_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_SVSP_BMSK                        0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_SVSP_SHFT                              0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_NOM_BMSK                          0xf000000
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_NOM_SHFT                               0x18
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_TUR_BMSK                           0xf00000
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_TUR_SHFT                               0x14
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS2_BMSK                                  0xf8000
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS2_SHFT                                      0xf
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS_BMSK                                    0x7c00
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS_SHFT                                       0xa
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_NOM_BMSK                                     0x3e0
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_NOM_SHFT                                       0x5
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_TUR_BMSK                                      0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_CPR6_TARG_VOLT_TUR_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004324)
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW18_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW18_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_RSVD_BMSK                                              0xffff0000
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_RSVD_SHFT                                                    0x10
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_AGING_BMSK                                            0xff00
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_AGING_SHFT                                               0x8
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS2_BMSK                              0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS2_SHFT                               0x4
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS_BMSK                                0xf
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004328)
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW19_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW19_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_SVS_3_0_BMSK                            0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_SVS_3_0_SHFT                                  0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_NOM_BMSK                                 0xfc00000
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_NOM_SHFT                                      0x16
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_TUR_BMSK                                  0x3f0000
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TARG_VOLT_TUR_SHFT                                      0x10
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_SVS2_ROSEL_BMSK                                       0xf000
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_SVS2_ROSEL_SHFT                                          0xc
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_SVS_ROSEL_BMSK                                         0xf00
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_SVS_ROSEL_SHFT                                           0x8
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_NOMINAL_ROSEL_BMSK                                      0xf0
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_NOMINAL_ROSEL_SHFT                                       0x4
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TURBO_ROSEL_BMSK                                         0xf
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_CPR7_TURBO_ROSEL_SHFT                                         0x0

#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000432c)
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW19_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW19_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_NOMINAL_QUOT_VMIN_BMSK                            0xfff00000
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_NOMINAL_QUOT_VMIN_SHFT                                  0x14
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TURBO_QUOT_VMIN_BMSK                                 0xfff00
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TURBO_QUOT_VMIN_SHFT                                     0x8
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS2_BMSK                                     0xfc
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS2_SHFT                                      0x2
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS_5_4_BMSK                                   0x3
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS_5_4_SHFT                                   0x0

#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004330)
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW20_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW20_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_QUOT_OFFSET_TUR_BMSK                              0xff000000
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_QUOT_OFFSET_TUR_SHFT                                    0x18
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_SVS2_QUOT_VMIN_BMSK                                 0xfff000
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_SVS2_QUOT_VMIN_SHFT                                      0xc
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_SVS_QUOT_VMIN_BMSK                                     0xfff
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_CPR7_SVS_QUOT_VMIN_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004334)
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW20_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW20_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_RSVD_BMSK                                              0xffc00000
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_RSVD_SHFT                                                    0x16
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_AGING_BMSK                                          0x3fc000
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_AGING_SHFT                                               0xe
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_SVS_BMSK                                  0x3f80
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_SVS_SHFT                                     0x7
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_NOM_BMSK                                    0x7f
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_NOM_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004338)
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW21_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW21_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TURBO_QUOT_VMIN_7_0_BMSK                          0xff000000
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TURBO_QUOT_VMIN_7_0_SHFT                                0x18
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS2_BMSK                                 0xfc0000
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS2_SHFT                                     0x12
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS_BMSK                                   0x3f000
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS_SHFT                                       0xc
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_NOM_BMSK                                     0xfc0
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_NOM_SHFT                                       0x6
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_TUR_BMSK                                      0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_CPR8_TARG_VOLT_TUR_SHFT                                       0x0

#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000433c)
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW21_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW21_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_SVS2_QUOT_VMIN_3_0_BMSK                           0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_SVS2_QUOT_VMIN_3_0_SHFT                                 0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_SVS_QUOT_VMIN_BMSK                                 0xfff0000
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_SVS_QUOT_VMIN_SHFT                                      0x10
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_NOMINAL_QUOT_VMIN_BMSK                                0xfff0
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_NOMINAL_QUOT_VMIN_SHFT                                   0x4
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_TURBO_QUOT_VMIN_11_8_BMSK                                0xf
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_CPR8_TURBO_QUOT_VMIN_11_8_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004340)
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW22_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW22_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR9_TURBO_ROSEL_1_0_BMSK                              0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR9_TURBO_ROSEL_1_0_SHFT                                    0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_SVS_BMSK                              0x3f800000
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_SVS_SHFT                                    0x17
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_NOM_BMSK                                0x7f0000
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_NOM_SHFT                                    0x10
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_TUR_BMSK                                  0xff00
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_TUR_SHFT                                     0x8
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_SVS2_QUOT_VMIN_11_4_BMSK                                0xff
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_CPR8_SVS2_QUOT_VMIN_11_4_SHFT                                 0x0

#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004344)
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW22_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW22_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_SVS_BMSK                                0xfc000000
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_SVS_SHFT                                      0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_NOM_BMSK                                 0x3f00000
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_NOM_SHFT                                      0x14
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_TUR_BMSK                                   0xfc000
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TARG_VOLT_TUR_SHFT                                       0xe
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_SVS2_ROSEL_BMSK                                       0x3c00
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_SVS2_ROSEL_SHFT                                          0xa
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_SVS_ROSEL_BMSK                                         0x3c0
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_SVS_ROSEL_SHFT                                           0x6
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_NOMINAL_ROSEL_BMSK                                      0x3c
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_NOMINAL_ROSEL_SHFT                                       0x2
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TURBO_ROSEL_3_2_BMSK                                     0x3
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_CPR9_TURBO_ROSEL_3_2_SHFT                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004348)
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW23_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW23_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_SVS_QUOT_VMIN_1_0_BMSK                            0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_SVS_QUOT_VMIN_1_0_SHFT                                  0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_NOMINAL_QUOT_VMIN_BMSK                            0x3ffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_NOMINAL_QUOT_VMIN_SHFT                                  0x12
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_TURBO_QUOT_VMIN_BMSK                                 0x3ffc0
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_TURBO_QUOT_VMIN_SHFT                                     0x6
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_TARG_VOLT_SVS2_BMSK                                     0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_CPR9_TARG_VOLT_SVS2_SHFT                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000434c)
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW23_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW23_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_NOM_1_0_BMSK                          0xc0000000
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_NOM_1_0_SHFT                                0x1e
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_TUR_BMSK                              0x3fc00000
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_TUR_SHFT                                    0x16
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_SVS2_QUOT_VMIN_BMSK                                 0x3ffc00
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_SVS2_QUOT_VMIN_SHFT                                      0xa
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_SVS_QUOT_VMIN_11_2_BMSK                                0x3ff
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_CPR9_SVS_QUOT_VMIN_11_2_SHFT                                  0x0

#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004350)
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW24_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW24_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR10_TARG_VOLT_NOM_BMSK                               0xfc000000
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR10_TARG_VOLT_NOM_SHFT                                     0x1a
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR10_TARG_VOLT_TUR_BMSK                                0x3f00000
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR10_TARG_VOLT_TUR_SHFT                                     0x14
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_AGING_BMSK                                           0xff000
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_AGING_SHFT                                               0xc
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_SVS_BMSK                                   0xfe0
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_SVS_SHFT                                     0x5
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_NOM_6_2_BMSK                                0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_NOM_6_2_SHFT                                 0x0

#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004354)
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW24_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW24_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_NOMINAL_QUOT_VMIN_7_0_BMSK                       0xff000000
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_NOMINAL_QUOT_VMIN_7_0_SHFT                             0x18
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TURBO_QUOT_VMIN_BMSK                               0xfff000
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TURBO_QUOT_VMIN_SHFT                                    0xc
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS2_BMSK                                   0xfc0
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS2_SHFT                                     0x6
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS_BMSK                                     0x3f
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS_SHFT                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004358)
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW25_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW25_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_QUOT_OFFSET_TUR_3_0_BMSK                         0xf0000000
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_QUOT_OFFSET_TUR_3_0_SHFT                               0x1c
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_SVS2_QUOT_VMIN_BMSK                               0xfff0000
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_SVS2_QUOT_VMIN_SHFT                                    0x10
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_SVS_QUOT_VMIN_BMSK                                   0xfff0
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_SVS_QUOT_VMIN_SHFT                                      0x4
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_NOMINAL_QUOT_VMIN_11_8_BMSK                             0xf
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_CPR10_NOMINAL_QUOT_VMIN_11_8_SHFT                             0x0

#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000435c)
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW25_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW25_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_RSVD_BMSK                                              0xfffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_RSVD_SHFT                                                    0x12
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_SVS_BMSK                                0x3f800
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_SVS_SHFT                                    0xb
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_NOM_BMSK                                  0x7f0
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_NOM_SHFT                                    0x4
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_TUR_7_4_BMSK                                0xf
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_TUR_7_4_SHFT                                0x0

#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004360)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW26_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW26_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR_RSVD_31_0_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR_RSVD_31_0_SHFT                                            0x0

#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004364)
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW26_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW26_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_RSVD_BMSK                                              0xfffc0000
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_RSVD_SHFT                                                    0x12
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_CPR_RSVD_49_32_BMSK                                       0x3ffff
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_CPR_RSVD_49_32_SHFT                                           0x0

#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004368)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW27_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW27_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000436c)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004370)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004374)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004378)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000437c)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004380)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004384)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RSVD_SHFT                                                     0x0


#endif /* __HALHWIOTSENSFUSES_H__ */
