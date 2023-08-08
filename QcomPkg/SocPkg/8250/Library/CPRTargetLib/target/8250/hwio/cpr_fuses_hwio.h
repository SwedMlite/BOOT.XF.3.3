#ifndef __CPR_FUSES_HWIO_H__
#define __CPR_FUSES_HWIO_H__
/*
===========================================================================
*/
/**
  @file cpr_fuses_hwio.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) v2 [kona_v2.1_p3q2r13.1_M03]
 
  This file contains HWIO register definitions for the following modules:
    SECURITY_CONTROL_CORE


  Generation parameters: 
  { 'filename': 'cpr_fuses_hwio.h',
    'header': '#include "msmhwiobase.h"',
    'module-filter-exclude': {},
    'module-filter-include': {},
    'modules': ['SECURITY_CONTROL_CORE'],
    'output-fvals': True,
    'output-offsets': True,
    'output-phys': True}
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/CPRTargetLib/target/8250/hwio/cpr_fuses_hwio.h#4 $
  $DateTime: 2019/09/12 12:21:02 $
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
#define SECURITY_CONTROL_CORE_REG_BASE_PHYS                                                     (SECURITY_CONTROL_BASE_PHYS + 0x00000000)
#define SECURITY_CONTROL_CORE_REG_BASE_OFFS                                                     0x00000000

#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n)                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000000 + 0x4 * (n))
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_PHYS(n)                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000000 + 0x4 * (n))
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_OFFS(n)                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000000 + 0x4 * (n))
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_MAXn                                                            71
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n), HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_RMSK)
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_ADDR(n), mask)
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_BMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_SHFT                                            0x0

#define HWIO_QFPROM_RAW_LCM_ROW_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000120)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000120)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000120)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_LCM_ROW_LSB_ADDR)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_LCM_ROW_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_LCM_ROW_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_LCM_ROW_LSB_ADDR,m,v,HWIO_QFPROM_RAW_LCM_ROW_LSB_IN)
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_LCM_BMSK                                            0x80000000
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_LCM_SHFT                                                  0x1f
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_LCM_STATE_TRANSITION_BMSK                           0x40000000
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_LCM_STATE_TRANSITION_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_SECURE_PHK_BMSK                                     0x20000000
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_DISABLE_SECURE_PHK_SHFT                                           0x1d
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_RSVD_BMSK                                                   0x1fffffe0
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_RSVD_SHFT                                                          0x5
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_EXTERNAL_BMSK                                                  0x10
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_EXTERNAL_SHFT                                                   0x4
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_INTERNAL_BMSK                                                   0x8
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_INTERNAL_SHFT                                                   0x3
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_FEAT_CONFIG_BMSK                                                0x4
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_QC_FEAT_CONFIG_SHFT                                                0x2
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_HW_TEST_BMSK                                                       0x2
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_HW_TEST_SHFT                                                       0x1
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_SOC_PERSO_BMSK                                                     0x1
#define HWIO_QFPROM_RAW_LCM_ROW_LSB_SOC_PERSO_SHFT                                                     0x0

#define HWIO_QFPROM_RAW_LCM_ROW_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000124)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000124)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000124)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_LCM_ROW_MSB_ADDR)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_LCM_ROW_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_LCM_ROW_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_LCM_ROW_MSB_ADDR,m,v,HWIO_QFPROM_RAW_LCM_ROW_MSB_IN)
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_RSVD_BMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_LCM_ROW_MSB_RSVD_SHFT                                                          0x0

#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000128 + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000128 + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000128 + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_MAXn                                                    1
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_RSVD_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_LSB_RSVD_SHFT                                             0x0

#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000012c + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000012c + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000012c + 0x8 * (n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_MAXn                                                    1
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_RSVD_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_BOOT_PATCH_HASH_ROWn_MSB_RSVD_SHFT                                             0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000138 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_PHYS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000138 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OFFS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000138 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                             3
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000013c + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_PHYS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000013c + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OFFS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000013c + 0x8 * (n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                             3
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_BMSK                          0x7f000000
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_SHFT                                0x18
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                            0xffffff
#define HWIO_QFPROM_RAW_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000158)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000158)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000158)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_RMSK                                            0x7fffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_BMSK                    0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_SHFT                          0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_BMSK                              0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_SHFT                                    0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                       0x1fe00000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                             0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                        0x180000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                            0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_DEFAULT_FVAL                     0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_1024_FVAL                   0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2048_FVAL                   0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2560_FVAL                   0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_BMSK                      0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_SHFT                         0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_BMSK                      0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_SHFT                         0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_BMSK                               0x10000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_SHFT                                  0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_BMSK                               0x8000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_SHFT                                  0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_BMSK                               0x4000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_SHFT                                  0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_BMSK                                     0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_SHFT                                        0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                   0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                      0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                          0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                            0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                  0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                    0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                   0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                     0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_BMSK                                   0x100
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_SHFT                                     0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                       0x80
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                        0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                             0x40
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                              0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_BMSK                          0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_SHFT                           0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_BMSK                                    0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_SHFT                                     0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT0_FVAL                           0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT1_FVAL                           0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_BMSK                                      0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_SHFT                                      0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                            0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                            0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_ENABLE_PATCHING_FVAL            0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_DISABLE_PATCHING_FVAL           0x1

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000015c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000015c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000015c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_RMSK                                            0xe7fffff7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                          0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_SW_KEY_FVAL          0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_HW_KEY_FVAL          0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                          0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_SW_KEY_FVAL          0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_HW_KEY_FVAL          0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                      0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_BMSK                                 0x4000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_SHFT                                      0x1a
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_BMSK              0x2000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                   0x19
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_BMSK                  0x1000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_SHFT                       0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_BMSK                  0x800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_SHFT                      0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                            0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_BMSK                       0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_SHFT                           0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_BMSK                                    0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_SHFT                                        0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_BMSK                                0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_SHFT                                   0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                             0x7c000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                 0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                          0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                             0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_BMSK                             0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_SHFT                                0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANA_FEAT_SET_FVAL                  0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANAQ_FEAT_SET_FVAL                 0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                      0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                        0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_BMSK                             0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_SHFT                               0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                    0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                      0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                     0x1e0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                       0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                           0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                            0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_BMSK                                    0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_SHFT                                    0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_BMSK                                    0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_SHFT                                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_BMSK                                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_SHFT                                    0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_DISABLE_FVAL                            0x1

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000160)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000160)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000160)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_BMSK                 0xffffc000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_SHFT                        0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_BMSK                       0x3c00
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_SHFT                          0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                     0x3ff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                       0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_DISABLE_FVAL               0x1

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000164)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000164)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000164)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_BMSK                        0xc0000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_SHFT                              0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_BMSK              0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_SHFT                    0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_BMSK                  0x10000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_SHFT                        0x1c
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_MOBILE_FVAL                  0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_AUTOMOTIVE_FVAL              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_BMSK                        0x8000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_SHFT                             0x1b
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_MOBILE_FVAL                       0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_AUTOMOTIVE_FVAL                   0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_BMSK                                0x4000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_SHFT                                     0x1a
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_BMSK                      0x2000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_SHFT                           0x19
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_BMSK                                 0x1000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_SHFT                                      0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_BMSK                   0xffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_SHFT                        0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_DISABLE_FVAL                0x1

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000168)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000168)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000168)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_RMSK                                            0xfbffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_BMSK             0x80000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_SHFT                   0x1f
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_BMSK                     0x40000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_SHFT                           0x1e
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_BMSK                              0x20000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_SHFT                                    0x1d
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_BMSK                                 0x10000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_SHFT                                       0x1c
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_BMSK                                  0x8000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_SHFT                                       0x1b
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_BMSK               0x2000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_SHFT                    0x19
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_BMSK               0x1000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_SHFT                    0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_BMSK                0x800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_SHFT                    0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_BMSK                0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_SHFT                    0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_BMSK                0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_SHFT                    0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_BMSK                 0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_SHFT                     0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                         0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                            0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                         0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                            0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_BMSK                    0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_SHFT                       0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_BMSK                    0x10000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_SHFT                       0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_BMSK                     0x8000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_SHFT                        0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_BMSK                     0x4000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_SHFT                        0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_BMSK                    0x2000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_SHFT                       0xd
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_BMSK                    0x1000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_SHFT                       0xc
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                  0x800
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                    0xb
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_BMSK                   0x400
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_SHFT                     0xa
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_BMSK                        0x200
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_SHFT                          0x9
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_BMSK                        0x100
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_SHFT                          0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_BMSK                         0x80
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_SHFT                          0x7
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_BMSK                         0x40
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_SHFT                          0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_BMSK                        0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_SHFT                         0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_BMSK                        0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_SHFT                         0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_BMSK                      0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_SHFT                      0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_BMSK                       0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_SHFT                       0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                   0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                   0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                       0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                       0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_DISABLE_FVAL                               0x1

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000016c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000016c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000016c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_BMSK                       0xff000000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_SHFT                             0x18
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_BMSK                         0x800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_SHFT                             0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_BMSK                          0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_SHFT                              0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_BMSK                     0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_SHFT                         0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                           0x1f8000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                0xf
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                         0x4000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                            0xe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                        0x3fc0
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                           0x6
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_BMSK                   0x20
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_SHFT                    0x5
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_BMSK                   0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_SHFT                    0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_BMSK                    0x8
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_SHFT                    0x3
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_BMSK                    0x4
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_SHFT                    0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_BMSK                    0x2
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_SHFT                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_BMSK                    0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_SHFT                    0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000170)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000170)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000170)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_RMSK                                            0x7fffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_BMSK                  0x7f800000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_SHFT                        0x17
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_BMSK                       0x400000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_SHFT                           0x16
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_BMSK                       0x200000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_SHFT                           0x15
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_BMSK                       0x100000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_SHFT                           0x14
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_BMSK                        0x80000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_SHFT                           0x13
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_BMSK                        0x40000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_SHFT                           0x12
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_BMSK                        0x20000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_SHFT                           0x11
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_BMSK                        0x10000
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_SHFT                           0x10
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_BMSK                          0xffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_SHFT                             0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000174)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000174)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000174)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_RSVD_BMSK                                       0xfffffffe
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_RSVD_SHFT                                              0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_BMSK                             0x1
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_SHFT                             0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000178)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000178)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000178)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_RSVD_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_LSB_RSVD_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000017c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000017c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000017c)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_RSVD_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW4_MSB_RSVD_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000180)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000180)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000180)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_RSVD_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_LSB_RSVD_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000184)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000184)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000184)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_ADDR)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_RSVD_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_CM_FEAT_CONFIG_ROW5_MSB_RSVD_SHFT                                              0x0

#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000188)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000188)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000188)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_RSVD0_BMSK                                             0xfffffff0
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_RSVD0_SHFT                                                    0x4
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ROOT_CERT_ACTIVATION_LIST_BMSK                                0xf
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_LSB_ROOT_CERT_ACTIVATION_LIST_SHFT                                0x0

#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000018c)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000018c)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000018c)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_RSVD1_BMSK                                             0xfffffffe
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_RSVD1_SHFT                                                    0x1
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_CURRENT_UIE_KEY_SEL_BMSK                                      0x1
#define HWIO_QFPROM_RAW_MRC_2_0_ROW0_MSB_CURRENT_UIE_KEY_SEL_SHFT                                      0x0

#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000190)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000190)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000190)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_RSVD0_BMSK                                             0xfffffff0
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_RSVD0_SHFT                                                    0x4
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ROOT_CERT_REVOCATION_LIST_BMSK                                0xf
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_LSB_ROOT_CERT_REVOCATION_LIST_SHFT                                0x0

#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000194)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000194)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000194)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_RSVD0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_MRC_2_0_ROW1_MSB_RSVD0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000198)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000198)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000198)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_RSVD0_BMSK                                                 0xe0000000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_RSVD0_SHFT                                                       0x1d
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_MACCHIATO_EN_BMSK                                          0x10000000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_MACCHIATO_EN_SHFT                                                0x1c
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_FEATURE_ID_BMSK                                             0xff00000
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_FEATURE_ID_SHFT                                                  0x14
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_JTAG_ID_BMSK                                                  0xfffff
#define HWIO_QFPROM_RAW_PTE_ROW0_LSB_JTAG_ID_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000019c)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000019c)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000019c)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW0_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a0)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001a0)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001a0)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a4)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001a4)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001a4)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW1_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001a8)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001a8)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001a8)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001ac)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001ac)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001ac)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW2_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b0)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001b0)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001b0)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b4)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001b4)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001b4)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW3_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001b8)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001b8)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001b8)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW4_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001bc)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001bc)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001bc)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW4_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c0)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001c0)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001c0)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW5_LSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW5_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW5_LSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW5_LSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_PTE_DATA0_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW5_LSB_PTE_DATA0_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c4)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001c4)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001c4)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_PTE_ROW5_MSB_ADDR)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_PTE_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_PTE_ROW5_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PTE_ROW5_MSB_ADDR,m,v,HWIO_QFPROM_RAW_PTE_ROW5_MSB_IN)
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_PTE_DATA1_BMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_PTE_ROW5_MSB_PTE_DATA1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001c8)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001c8)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001c8)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_RD_PERM_LSB_ADDR,m,v,HWIO_QFPROM_RAW_RD_PERM_LSB_IN)
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG31_BMSK                                        0x80000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG31_SHFT                                              0x1f
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG31_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG31_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_BMSK                                        0x40000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_SHFT                                              0x1e
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG30_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_BMSK                                        0x20000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_SHFT                                              0x1d
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG29_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_BMSK                                        0x10000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_SHFT                                              0x1c
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SPARE_REG28_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_USER_DATA_KEY_BMSK                                           0x8000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_USER_DATA_KEY_SHFT                                                0x1b
#define HWIO_QFPROM_RAW_RD_PERM_LSB_USER_DATA_KEY_ALLOW_READ_FVAL                                      0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_USER_DATA_KEY_DISABLE_READ_FVAL                                    0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                         0x4000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                              0x1a
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_IMAGE_ENCR_KEY1_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_BMSK                                          0x2000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_SHFT                                               0x19
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_ROM_PATCH_DISABLE_READ_FVAL                                   0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                  0x1000000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                       0x18
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_ALLOW_READ_FVAL                             0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_DISABLE_READ_FVAL                           0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_BMSK                                             0x800000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_SHFT                                                 0x17
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_ALLOW_READ_FVAL                                       0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_SEC_BOOT_DISABLE_READ_FVAL                                     0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                       0x400000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                           0x16
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_ALLOW_READ_FVAL                                 0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_DISABLE_READ_FVAL                               0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG21_BMSK                                           0x200000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG21_SHFT                                               0x15
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG21_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG21_DISABLE_READ_FVAL                                   0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG20_BMSK                                           0x100000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG20_SHFT                                               0x14
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG20_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_QC_SPARE_REG20_DISABLE_READ_FVAL                                   0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_BMSK                                                0x80000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_SHFT                                                   0x13
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_ALLOW_READ_FVAL                                         0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MEM_CONFIG_DISABLE_READ_FVAL                                       0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_BMSK                                                     0x40000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_SHFT                                                        0x12
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_ALLOW_READ_FVAL                                              0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CALIB_DISABLE_READ_FVAL                                            0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_BMSK                                                  0x20000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_SHFT                                                     0x11
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_ALLOW_READ_FVAL                                           0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PK_HASH0_DISABLE_READ_FVAL                                         0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_5_BMSK                                           0x10000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_5_SHFT                                              0x10
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_5_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_5_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                            0x8000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                               0xf
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_4_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                            0x4000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                               0xe
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_3_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                            0x2000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                               0xd
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_2_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                            0x1000
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                               0xc
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_ANTI_ROLLBACK_1_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_BMSK                                                 0x800
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_SHFT                                                   0xb
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_ALLOW_READ_FVAL                                        0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEAT_CONFIG_DISABLE_READ_FVAL                                      0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_BMSK                                                  0x400
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_SHFT                                                    0xa
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_ALLOW_READ_FVAL                                         0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_OEM_CONFIG_DISABLE_READ_FVAL                                       0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_BMSK                                                      0x200
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_SHFT                                                        0x9
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_ALLOW_READ_FVAL                                             0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_FEC_EN_DISABLE_READ_FVAL                                           0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_BMSK                                                     0x100
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_SHFT                                                       0x8
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_ALLOW_READ_FVAL                                            0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_WR_PERM_DISABLE_READ_FVAL                                          0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_BMSK                                                      0x80
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_SHFT                                                       0x7
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_ALLOW_READ_FVAL                                            0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_RD_PERM_DISABLE_READ_FVAL                                          0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_BMSK                                                          0x40
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_SHFT                                                           0x6
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_ALLOW_READ_FVAL                                                0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PTE_DISABLE_READ_FVAL                                              0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MRC_2_0_BMSK                                                      0x20
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MRC_2_0_SHFT                                                       0x5
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MRC_2_0_ALLOW_READ_FVAL                                            0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_MRC_2_0_DISABLE_READ_FVAL                                          0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_BMSK                                               0x10
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                0x4
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CM_FEAT_CONFIG_DISABLE_READ_FVAL                                   0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                        0x8
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                        0x3
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_ALLOW_READ_FVAL                             0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_DISABLE_READ_FVAL                           0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_PATCH_HASH_BMSK                                               0x4
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_PATCH_HASH_SHFT                                               0x2
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_PATCH_HASH_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_BOOT_PATCH_HASH_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_LCM_BMSK                                                           0x2
#define HWIO_QFPROM_RAW_RD_PERM_LSB_LCM_SHFT                                                           0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_LCM_ALLOW_READ_FVAL                                                0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_LCM_DISABLE_READ_FVAL                                              0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                0x1
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_RAW_RD_PERM_LSB_CRI_CM_PRIVATE_DISABLE_READ_FVAL                                   0x1

#define HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001cc)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001cc)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001cc)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_RD_PERM_MSB_ADDR,m,v,HWIO_QFPROM_RAW_RD_PERM_MSB_IN)
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RSVD0_BMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_RD_PERM_MSB_RSVD0_SHFT                                                         0x0

#define HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001d0)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001d0)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001d0)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_WR_PERM_LSB_ADDR,m,v,HWIO_QFPROM_RAW_WR_PERM_LSB_IN)
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG31_BMSK                                        0x80000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG31_SHFT                                              0x1f
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG31_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG31_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_BMSK                                        0x40000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_SHFT                                              0x1e
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG30_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_BMSK                                        0x20000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_SHFT                                              0x1d
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG29_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_BMSK                                        0x10000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_SHFT                                              0x1c
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SPARE_REG28_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_USER_DATA_KEY_BMSK                                           0x8000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_USER_DATA_KEY_SHFT                                                0x1b
#define HWIO_QFPROM_RAW_WR_PERM_LSB_USER_DATA_KEY_ALLOW_WRITE_FVAL                                     0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_USER_DATA_KEY_DISABLE_WRITE_FVAL                                   0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                         0x4000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                              0x1a
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_IMAGE_ENCR_KEY1_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_BMSK                                          0x2000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_SHFT                                               0x19
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_ROM_PATCH_DISABLE_WRITE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                  0x1000000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                       0x18
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_ALLOW_WRITE_FVAL                            0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_DISABLE_WRITE_FVAL                          0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_BMSK                                             0x800000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_SHFT                                                 0x17
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_ALLOW_WRITE_FVAL                                      0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_SEC_BOOT_DISABLE_WRITE_FVAL                                    0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                       0x400000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                           0x16
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_ALLOW_WRITE_FVAL                                0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_DISABLE_WRITE_FVAL                              0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG21_BMSK                                           0x200000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG21_SHFT                                               0x15
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG21_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG21_DISABLE_WRITE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG20_BMSK                                           0x100000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG20_SHFT                                               0x14
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG20_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_QC_SPARE_REG20_DISABLE_WRITE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_BMSK                                                0x80000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_SHFT                                                   0x13
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_ALLOW_WRITE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MEM_CONFIG_DISABLE_WRITE_FVAL                                      0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_BMSK                                                     0x40000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_SHFT                                                        0x12
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_ALLOW_WRITE_FVAL                                             0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CALIB_DISABLE_WRITE_FVAL                                           0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_BMSK                                                  0x20000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_SHFT                                                     0x11
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_ALLOW_WRITE_FVAL                                          0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PK_HASH0_DISABLE_WRITE_FVAL                                        0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_5_BMSK                                           0x10000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_5_SHFT                                              0x10
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_5_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_5_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                            0x8000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                               0xf
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_4_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                            0x4000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                               0xe
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_3_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                            0x2000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                               0xd
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_2_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                            0x1000
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                               0xc
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_ANTI_ROLLBACK_1_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_BMSK                                                 0x800
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_SHFT                                                   0xb
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_ALLOW_WRITE_FVAL                                       0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEAT_CONFIG_DISABLE_WRITE_FVAL                                     0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_BMSK                                                  0x400
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_SHFT                                                    0xa
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_ALLOW_WRITE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_OEM_CONFIG_DISABLE_WRITE_FVAL                                      0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_BMSK                                                      0x200
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_SHFT                                                        0x9
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_ALLOW_WRITE_FVAL                                            0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_FEC_EN_DISABLE_WRITE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_BMSK                                                     0x100
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_SHFT                                                       0x8
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_ALLOW_WRITE_FVAL                                           0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_WR_PERM_DISABLE_WRITE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_BMSK                                                      0x80
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_SHFT                                                       0x7
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_ALLOW_WRITE_FVAL                                           0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_RD_PERM_DISABLE_WRITE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_BMSK                                                          0x40
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_SHFT                                                           0x6
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_ALLOW_WRITE_FVAL                                               0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PTE_DISABLE_WRITE_FVAL                                             0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MRC_2_0_BMSK                                                      0x20
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MRC_2_0_SHFT                                                       0x5
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MRC_2_0_ALLOW_WRITE_FVAL                                           0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_MRC_2_0_DISABLE_WRITE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_BMSK                                               0x10
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_SHFT                                                0x4
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CM_FEAT_CONFIG_DISABLE_WRITE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                        0x8
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                        0x3
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_ALLOW_WRITE_FVAL                            0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_DISABLE_WRITE_FVAL                          0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_PATCH_HASH_BMSK                                               0x4
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_PATCH_HASH_SHFT                                               0x2
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_PATCH_HASH_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_BOOT_PATCH_HASH_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_LCM_BMSK                                                           0x2
#define HWIO_QFPROM_RAW_WR_PERM_LSB_LCM_SHFT                                                           0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_LCM_ALLOW_WRITE_FVAL                                               0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_LCM_DISABLE_WRITE_FVAL                                             0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_BMSK                                                0x1
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_SHFT                                                0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_WR_PERM_LSB_CRI_CM_PRIVATE_DISABLE_WRITE_FVAL                                  0x1

#define HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001d4)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001d4)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001d4)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_WR_PERM_MSB_ADDR,m,v,HWIO_QFPROM_RAW_WR_PERM_MSB_IN)
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RSVD0_BMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_WR_PERM_MSB_RSVD0_SHFT                                                         0x0

#define HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001d8)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_PHYS                                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001d8)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_OFFS                                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001d8)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEC_EN_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEC_EN_LSB_IN)
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION31_FEC_EN_BMSK                                         0x80000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION31_FEC_EN_SHFT                                               0x1f
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION31_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION31_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_BMSK                                         0x40000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_SHFT                                               0x1e
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_BMSK                                         0x20000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_SHFT                                               0x1d
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_BMSK                                         0x10000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_SHFT                                               0x1c
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION28_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_BMSK                                          0x8000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_SHFT                                               0x1b
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION27_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_BMSK                                          0x4000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_SHFT                                               0x1a
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION26_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_BMSK                                          0x2000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_SHFT                                               0x19
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION25_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_BMSK                                          0x1000000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_SHFT                                               0x18
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION24_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_BMSK                                           0x800000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_SHFT                                               0x17
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION23_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_BMSK                                           0x400000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_SHFT                                               0x16
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION22_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_BMSK                                           0x200000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_SHFT                                               0x15
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION21_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_BMSK                                           0x100000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_SHFT                                               0x14
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION20_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_BMSK                                            0x80000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_SHFT                                               0x13
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION19_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_BMSK                                            0x40000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_SHFT                                               0x12
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION18_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_BMSK                                            0x20000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_SHFT                                               0x11
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION17_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_BMSK                                            0x10000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_SHFT                                               0x10
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION16_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_BMSK                                             0x8000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_SHFT                                                0xf
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION15_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_BMSK                                             0x4000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_SHFT                                                0xe
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION14_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_BMSK                                             0x2000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_SHFT                                                0xd
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION13_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_BMSK                                             0x1000
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_SHFT                                                0xc
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION12_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_BMSK                                              0x800
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_SHFT                                                0xb
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION11_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_BMSK                                              0x400
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_SHFT                                                0xa
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION10_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_BMSK                                               0x200
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_SHFT                                                 0x9
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION9_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_BMSK                                               0x100
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_SHFT                                                 0x8
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION8_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_BMSK                                                0x80
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_SHFT                                                 0x7
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION7_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_BMSK                                                0x40
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_SHFT                                                 0x6
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION6_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_BMSK                                                0x20
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_SHFT                                                 0x5
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION5_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_BMSK                                                0x10
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_SHFT                                                 0x4
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION4_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_BMSK                                                 0x8
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_SHFT                                                 0x3
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION3_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_BMSK                                                 0x4
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_SHFT                                                 0x2
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION2_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_BMSK                                                 0x2
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_SHFT                                                 0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION1_FEC_EN_ENABLE_FVAL                                          0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_BMSK                                                 0x1
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_SHFT                                                 0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_DISABLE_FVAL                                         0x0
#define HWIO_QFPROM_RAW_FEC_EN_LSB_REGION0_FEC_EN_ENABLE_FVAL                                          0x1

#define HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001dc)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_PHYS                                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001dc)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_OFFS                                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001dc)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RMSK                                                         0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEC_EN_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEC_EN_MSB_IN)
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RSVD0_BMSK                                                   0xffffffff
#define HWIO_QFPROM_RAW_FEC_EN_MSB_RSVD0_SHFT                                                          0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001e0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001e0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001e0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                    0x80000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                          0x1f
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_BMSK                     0x40000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_SHFT                           0x1e
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_BMSK                              0x20000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_SHFT                                    0x1d
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_BMSK                           0x10000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_SHFT                                 0x1c
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SP_DISABLE_BMSK                                      0x8000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SP_DISABLE_SHFT                                           0x1b
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SP_DISABLE_ENABLE_FVAL                                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SP_DISABLE_DISABLE_FVAL                                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_BMSK                                     0x4000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_SHFT                                          0x1a
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_DISABLE_IN_ROM_BMSK                            0x2000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DEBUG_DISABLE_IN_ROM_SHFT                                 0x19
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_BMSK                 0x1000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_SHFT                      0x18
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_DISABLE_FVAL               0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_ENABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                0x800000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                    0x17
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_DISABLE_FVAL             0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_ENABLE_FVAL              0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_BMSK                                   0x400000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_SHFT                                       0x16
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_BMSK                            0x200000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_SHFT                                0x15
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_USE_OEM_ID_FVAL                      0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_USE_SERIAL_NUM_FVAL                  0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_BMSK                             0x100000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_SHFT                                 0x14
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_BMSK                           0x80000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_SHFT                              0x13
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ROOT_CERT_TOTAL_NUM_BMSK                               0x60000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ROOT_CERT_TOTAL_NUM_SHFT                                  0x11
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_BMSK                            0x10000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_SHFT                               0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_BMSK                                    0x8000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_SHFT                                       0xf
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_BMSK                                            0x4000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_SHFT                                               0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_USE_GPIO_FVAL                                      0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_WDOG_EN_IGNORE_GPIO_ENABLE_WDOG_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_BMSK               0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_SHFT                  0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_DISABLE_EDL_RESET_FVAL        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_ENABLE_EDL_RESET_FVAL        0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_BMSK                               0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_SHFT                                  0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SPI_CLK_BOOT_FREQ_BMSK                                   0x800
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SPI_CLK_BOOT_FREQ_SHFT                                     0xb
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_BMSK                           0x400
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_SHFT                             0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_SD_USB_FVAL                      0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_QSPI_SD_USB_FVAL                 0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_BMSK                                           0x3e0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SHFT                                             0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_DEFAULT_FVAL                                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SD_UFS_EDL_FVAL                                  0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SD_EDL_FVAL                                      0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_USB_EDL_FVAL                                     0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_QSPI_EDL_FVAL                                    0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SPI_EDL_FVAL                                     0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FAST_BOOT_UGSG4_SD_USB_EDL_FVAL                            0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_BMSK                                  0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_SHFT                                   0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_ENUM_19_2_MHZ_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_ENUM_25_MHZ_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_BMSK                                0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_SHFT                                0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL        0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_BMSK                                   0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_SHFT                                   0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL        0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_BMSK                                          0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_SHFT                                          0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_TIMEOUT_DISABLED_FVAL                         0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_TIMEOUT_ENABLED_90S_FVAL                      0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_BMSK                                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_SHFT                                       0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_DOWNLOADER_ENABLED_FVAL                    0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_DOWNLOADER_DISABLED_FVAL                   0x1

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001e4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001e4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001e4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD1_BMSK                                          0xffffc000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_RSVD1_SHFT                                                 0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_BMSK                         0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_SHFT                            0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_BMSK                         0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_SHFT                            0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_BMSK                          0x800
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_SHFT                            0xb
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_BMSK                          0x400
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_SHFT                            0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_BMSK                          0x200
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_SHFT                            0x9
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_BMSK                           0x100
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_SHFT                             0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_BMSK                                   0x80
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_SHFT                                    0x7
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_BMSK                                   0x40
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_SHFT                                    0x6
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_BMSK                              0x20
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_SHFT                               0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_BMSK                              0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_SHFT                               0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_BMSK                               0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_SHFT                               0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_BMSK                               0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_SHFT                               0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_BMSK                              0x2
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_SHFT                              0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_BMSK                              0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_SHFT                              0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                      0x1

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001e8)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001e8)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001e8)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_DISABLE_RSA_BMSK                                    0x80000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_DISABLE_RSA_SHFT                                          0x1f
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_EKU_ENFORCEMENT_EN_BMSK                             0x40000000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_EKU_ENFORCEMENT_EN_SHFT                                   0x1e
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD2_BMSK                                          0x3fff0000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD2_SHFT                                                0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_BMSK                                 0x8000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_SHFT                                    0xf
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_NOT_SECURE_FVAL                         0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_SECURE_FVAL                             0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_BMSK                                 0x4000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_SHFT                                    0xe
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_NOT_SECURE_FVAL                         0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_SECURE_FVAL                             0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_BMSK                                 0x2000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_SHFT                                    0xd
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_NOT_SECURE_FVAL                         0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_SECURE_FVAL                             0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_BMSK                                 0x1000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_SHFT                                    0xc
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_NOT_SECURE_FVAL                         0x0
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_SECURE_FVAL                             0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD3_BMSK                                               0x800
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD3_SHFT                                                 0xb
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPU_IAR_ENABLED_BMSK                                     0x400
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SPU_IAR_ENABLED_SHFT                                       0xa
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD1_BMSK                                               0x300
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD1_SHFT                                                 0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_OVERRIDE_BMSK                           0x80
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_OVERRIDE_SHFT                            0x7
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_FIPS_OVERRIDE_BMSK                                     0x40
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_FIPS_OVERRIDE_SHFT                                      0x6
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_MODEM_CRYPTO_FIPS_ENABLE_BMSK                             0x20
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_MODEM_CRYPTO_FIPS_ENABLE_SHFT                              0x5
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_ENABLE_BMSK                             0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_ENABLE_SHFT                              0x4
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_FIPS_ENABLE_BMSK                                        0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_FIPS_ENABLE_SHFT                                        0x3
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_NVM_AR_CONFIG_BMSK                                      0x6
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_SP_NVM_AR_CONFIG_SHFT                                      0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD0_BMSK                                                 0x1
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_LSB_RSVD0_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001ec)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001ec)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001ec)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_BMSK                                 0xffff0000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_SHFT                                       0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_BMSK                                          0xffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_SHFT                                             0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001f0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001f0)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_VID_BMSK                                     0xffff0000
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_VID_SHFT                                           0x10
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_PID_BMSK                                         0xffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_LSB_PERIPH_PID_SHFT                                            0x0

#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001f4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001f4)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RSVD0_BMSK                                          0xffffff00
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_RSVD0_SHFT                                                 0x8
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_BMSK                             0xff
#define HWIO_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_SHFT                              0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001f8)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001f8)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001f8)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_RMSK                                               0x7fffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_BMSK                       0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_SHFT                             0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_BMSK                                 0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_SHFT                                       0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                          0x1fe00000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                                0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                           0x180000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                               0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_DEFAULT_FVAL                        0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_1024_FVAL                      0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2048_FVAL                      0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2560_FVAL                      0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_BMSK                         0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_SHFT                            0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_BMSK                         0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_SHFT                            0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_BMSK                                  0x10000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_SHFT                                     0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_BMSK                                  0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_SHFT                                     0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_BMSK                                  0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_SHFT                                     0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_BMSK                                        0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_SHFT                                           0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                      0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                         0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                             0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                               0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                     0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                       0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                      0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                        0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_BMSK                                      0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_SHFT                                        0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                          0x80
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                           0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                                0x40
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                                 0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_ENABLE_FVAL                          0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_DISABLE_FVAL                         0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_BMSK                             0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_SHFT                              0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_BMSK                                       0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_SHFT                                        0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT0_FVAL                              0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT1_FVAL                              0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_BMSK                                         0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_SHFT                                         0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                               0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                               0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_ENABLE_PATCHING_FVAL               0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_DISABLE_PATCHING_FVAL              0x1

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000001fc)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000001fc)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000001fc)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_RMSK                                               0xe7fffff7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                             0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                   0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_SW_KEY_FVAL             0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_HW_KEY_FVAL             0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                             0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                   0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_SW_KEY_FVAL             0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_HW_KEY_FVAL             0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                   0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                         0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_BMSK                                    0x4000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_SHFT                                         0x1a
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_BMSK                 0x2000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                      0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_BMSK                     0x1000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_SHFT                          0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_BMSK                     0x800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_SHFT                         0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                               0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                   0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_BMSK                          0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_SHFT                              0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_BMSK                                       0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_SHFT                                           0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_BMSK                                   0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_SHFT                                      0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                                0x7c000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                    0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                             0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                                0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_ENABLE_FVAL                         0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_DISABLE_FVAL                        0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_BMSK                                0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_SHFT                                   0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANA_FEAT_SET_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANAQ_FEAT_SET_FVAL                    0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                         0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                           0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_BMSK                                0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_SHFT                                  0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                       0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                         0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                        0x1e0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                          0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                              0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                               0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_BMSK                                       0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_SHFT                                       0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_BMSK                                       0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_SHFT                                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_BMSK                                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_SHFT                                       0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_DISABLE_FVAL                               0x1

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000200)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000200)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000200)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_BMSK                    0xffffc000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_SHFT                           0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_BMSK                          0x3c00
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_SHFT                             0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                        0x3ff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                          0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_DISABLE_FVAL                  0x1

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000204)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000204)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000204)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_BMSK                           0xc0000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_BMSK                 0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_SHFT                       0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_BMSK                     0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_SHFT                           0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_MOBILE_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_AUTOMOTIVE_FVAL                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_BMSK                           0x8000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_SHFT                                0x1b
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_MOBILE_FVAL                          0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_AUTOMOTIVE_FVAL                      0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_BMSK                                   0x4000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_SHFT                                        0x1a
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_BMSK                         0x2000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_SHFT                              0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_BMSK                                    0x1000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_SHFT                                         0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_BMSK                      0xffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_SHFT                           0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_DISABLE_FVAL                   0x1

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000208)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000208)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000208)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_RMSK                                               0xfbffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_BMSK                0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_SHFT                      0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_BMSK                        0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_SHFT                              0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_BMSK                                 0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_SHFT                                       0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_BMSK                                    0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_SHFT                                          0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_BMSK                                     0x8000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_SHFT                                          0x1b
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_BMSK                  0x2000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_SHFT                       0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_BMSK                  0x1000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_SHFT                       0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_BMSK                   0x800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_SHFT                       0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_BMSK                   0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_SHFT                       0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_BMSK                   0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_SHFT                       0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_BMSK                    0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_SHFT                        0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                            0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                               0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_ENABLE_FVAL                         0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_DISABLE_FVAL                        0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                            0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                               0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_ENABLE_FVAL                         0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_DISABLE_FVAL                        0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_BMSK                       0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_SHFT                          0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_BMSK                       0x10000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_SHFT                          0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_BMSK                        0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_SHFT                           0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_BMSK                        0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_SHFT                           0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_BMSK                       0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_SHFT                          0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_BMSK                       0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_SHFT                          0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                     0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                       0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_BMSK                      0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_SHFT                        0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_BMSK                           0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_SHFT                             0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_BMSK                           0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_SHFT                             0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_BMSK                            0x80
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_SHFT                             0x7
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_BMSK                            0x40
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_SHFT                             0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_BMSK                           0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_SHFT                            0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_BMSK                           0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_SHFT                            0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_BMSK                         0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_SHFT                         0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_BMSK                          0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_SHFT                          0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                      0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                      0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                          0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                          0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_DISABLE_FVAL                                  0x1

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000020c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000020c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000020c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_BMSK                          0xff000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_SHFT                                0x18
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_BMSK                            0x800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_SHFT                                0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_BMSK                             0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_SHFT                                 0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_BMSK                        0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_SHFT                            0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                              0x1f8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                   0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                            0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                               0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                           0x3fc0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                              0x6
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_BMSK                      0x20
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_SHFT                       0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_BMSK                      0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_SHFT                       0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_BMSK                       0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_SHFT                       0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_BMSK                       0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_SHFT                       0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_BMSK                       0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_SHFT                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_BMSK                       0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_SHFT                       0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000210)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000210)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000210)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_RMSK                                               0x7fffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_BMSK                     0x7f800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_SHFT                           0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_BMSK                          0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_SHFT                              0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_BMSK                          0x200000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_SHFT                              0x15
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_BMSK                          0x100000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_SHFT                              0x14
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_BMSK                           0x80000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_SHFT                              0x13
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_BMSK                           0x40000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_SHFT                              0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_BMSK                           0x20000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_SHFT                              0x11
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_BMSK                           0x10000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_SHFT                              0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_BMSK                             0xffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_SHFT                                0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000214)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000214)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000214)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_RSVD_BMSK                                          0xfffffffe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_RSVD_SHFT                                                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_BMSK                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_SHFT                                0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000218)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000218)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000218)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD_BMSK                                          0xfffffffe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_RSVD_SHFT                                                 0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_LEGACY_MBNV6_OVERRIDE_BMSK                                0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_LSB_LEGACY_MBNV6_OVERRIDE_SHFT                                0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000021c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000021c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000021c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RSVD_BMSK                                          0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW4_MSB_RSVD_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000220)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000220)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000220)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_RSVD_BMSK                                          0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_LSB_RSVD_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000224)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000224)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000224)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_RSVD_BMSK                                          0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW5_MSB_RSVD_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000228)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000228)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000228)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK              0xfffc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                    0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_TAP_INSTR_DISABLE_BMSK                                0x3ffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_LSB_TAP_INSTR_DISABLE_SHFT                                    0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000022c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000022c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000022c)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_SEC_TAP_ACCESS_DISABLE_BMSK                        0xfffc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_SEC_TAP_ACCESS_DISABLE_SHFT                              0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK                0x3ffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW6_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                    0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000230)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000230)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000230)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_PATCH_VERSION_BMSK                       0xfe000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_PATCH_VERSION_SHFT                             0x19
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_PATCH_VERSION_BMSK                         0x1fc0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_PATCH_VERSION_SHFT                              0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_BMSK                              0x30000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_SHFT                                 0x10
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_ENUM_600_MHZ_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_XO_FVAL                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_ENUM_1200_MHZ_FVAL                    0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_NA_FVAL                               0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_BOOT_BMSK                                    0x8000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_BOOT_SHFT                                       0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_RSVD1_56_14_BMSK                                       0x4000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_RSVD1_56_14_SHFT                                          0xe
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_BOOT_FROM_ROM_BMSK                                0x2000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_APPS_BOOT_FROM_ROM_SHFT                                   0xd
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ENABLE_DEVICE_IN_TEST_MODE_BMSK                        0x1000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ENABLE_DEVICE_IN_TEST_MODE_SHFT                           0xc
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_QTI_ROOT_SIG_FORMAT_SEL_BMSK                            0x800
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_QTI_ROOT_SIG_FORMAT_SEL_SHFT                              0xb
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_BMSK                                     0x400
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_SHFT                                       0xa
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_BMSK                 0x200
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_SHFT                   0x9
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ARM_CE_DISABLE_USAGE_BMSK                               0x100
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_ARM_CE_DISABLE_USAGE_SHFT                                 0x8
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_BOOT_ROM_CFG_BMSK                                        0xff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_LSB_BOOT_ROM_CFG_SHFT                                         0x0

#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000234)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000234)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000234)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_ADDR)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_ADDR,m,v,HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_IN)
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_BMSK                     0x80000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_SHFT                           0x1f
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                    0x40000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                          0x1e
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_XBL_SEC_AUTH_DISABLE_BMSK                          0x20000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_XBL_SEC_AUTH_DISABLE_SHFT                                0x1d
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_MSM_PKG_TYPE_BMSK                                  0x10000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_MSM_PKG_TYPE_SHFT                                        0x1c
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_SPSS_CONFIG_MODE_BMSK                               0xc000000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_SPSS_CONFIG_MODE_SHFT                                    0x1a
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PERIPH_DRV_STRENGTH_SETTING_BMSK                    0x3800000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PERIPH_DRV_STRENGTH_SETTING_SHFT                         0x17
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_RSVD3_56_54_BMSK                                     0x400000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_RSVD3_56_54_SHFT                                         0x16
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_BMSK                                      0x3c0000
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SHFT                                          0x12
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_TSMC_FVAL                                      0x0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_GLOBAL_FOUNDRIES_FVAL                          0x1
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SAMSUNG_FVAL                                   0x2
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_IBM_FVAL                                       0x3
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_UMC_FVAL                                       0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SMIC_FVAL                                      0x5
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PLL_CFG_BMSK                                          0x3fff0
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_PLL_CFG_SHFT                                              0x4
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_PBL_PLL_CTRL_BMSK                                    0xf
#define HWIO_QFPROM_RAW_FEAT_CONFIG_ROW7_MSB_APPS_PBL_PLL_CTRL_SHFT                                    0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000238)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000238)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000238)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_XBL0_BMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_XBL0_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000023c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000023c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000023c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_XBL1_BMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_XBL1_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000240)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000240)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000240)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_BMSK                             0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_SHFT                                    0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000244)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000244)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000244)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_XBL_SEC_BMSK                                        0xfe000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_XBL_SEC_SHFT                                              0x19
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_AOP_BMSK                                             0x1fe0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_AOP_SHFT                                                  0x11
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_TZ_BMSK                                                0x1ffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_TZ_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000248)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000248)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000248)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_XBL_CONFIG_1_0_BMSK                                 0xc0000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_XBL_CONFIG_1_0_SHFT                                       0x1e
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_BMSK                                0x3e000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_SHFT                                      0x19
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_BMSK                            0x1000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_SHFT                                 0x18
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_RPMB_KEY_NOT_PROVISIONED_FVAL         0x0
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_RPMB_KEY_PROVISIONED_FVAL             0x1
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_BMSK                              0xffff00
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_SHFT                                   0x8
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAFESWITCH_BMSK                                           0xff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAFESWITCH_SHFT                                            0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000024c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000024c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000024c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_XBL_CONFIG_5_2_BMSK                                 0xf0000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_XBL_CONFIG_5_2_SHFT                                       0x1c
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_BMSK                                      0xffe0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_SHFT                                           0x11
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_BMSK                                      0x1f000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_SHFT                                          0xc
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_HYPERVISOR_BMSK                                          0xfff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_HYPERVISOR_SHFT                                            0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000250)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000250)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000250)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MSS_BMSK                                            0xffff0000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MSS_SHFT                                                  0x10
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MISC_BMSK                                               0xffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_MISC_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000254)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000254)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000254)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_SIMLOCK_BMSK                                        0x80000000
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_SIMLOCK_SHFT                                              0x1f
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RSVD0_BMSK                                          0x7ffffff0
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_RSVD0_SHFT                                                 0x4
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ROOT_CERT_PK_HASH_INDEX_BMSK                               0xf
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ROOT_CERT_PK_HASH_INDEX_SHFT                               0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000258)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000258)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000258)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_MISC_BMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_MISC_SHFT                                                  0x0

#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000025c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000025c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000025c)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR,m,v,HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_IN)
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_RSVD0_BMSK                                          0xffffffff
#define HWIO_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_RSVD0_SHFT                                                 0x0

#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000260 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_PHYS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000260 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_OFFS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000260 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_MAXn                                                           5
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_HASH_DATA0_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_LSB_HASH_DATA0_SHFT                                              0x0

#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000264 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_PHYS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000264 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_OFFS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000264 + 0x8 * (n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_MAXn                                                           5
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_HASH_DATA1_BMSK                                       0xffffffff
#define HWIO_QFPROM_RAW_PK_HASH0_ROWn_MSB_HASH_DATA1_SHFT                                              0x0

#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000290)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000290)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000290)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW0_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD2_BMSK                                               0xfe000000
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD2_SHFT                                                     0x19
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_USB2PHY_RCAL_CODE_BMSK                                    0x1e00000
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_USB2PHY_RCAL_CODE_SHFT                                         0x15
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD1_BMSK                                                 0x1ff000
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD1_SHFT                                                      0xc
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_VREF_TRIM_BMSK                               0xf80
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_VREF_TRIM_SHFT                                 0x7
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_ENABLE_NOM_BMSK                               0x40
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_TURING_Q6SS1_LDO_ENABLE_NOM_SHFT                                0x6
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD_BMSK                                                      0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW0_LSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000294)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000294)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000294)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW0_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW0_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW0_MSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000298)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000298)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000298)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW1_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW1_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_LSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000029c)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000029c)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000029c)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW1_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW1_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RSVD1_BMSK                                               0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RSVD1_SHFT                                                     0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_NORTH_BGV_TRIM_BMSK                               0x7f800000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_NORTH_BGV_TRIM_SHFT                                     0x17
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_SOUTH_BGV_TRIM_BMSK                                 0x7f8000
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_REFGEN_SOUTH_BGV_TRIM_SHFT                                      0xf
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_BANDGAP_TRIM_BMSK                                            0x7f00
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_BANDGAP_TRIM_SHFT                                               0x8
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RSVD_BMSK                                                      0xff
#define HWIO_QFPROM_RAW_CALIB_ROW1_MSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002a0)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002a0)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002a0)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_AOSS_K_13_0_BMSK                                         0xfffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_AOSS_K_13_0_SHFT                                               0x12
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_AOSS_N1_BMSK                                                0x3ffff
#define HWIO_QFPROM_RAW_CALIB_ROW2_LSB_AOSS_N1_SHFT                                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002a4)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002a4)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002a4)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_RSVD_BMSK                                                0xff000000
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_RSVD_SHFT                                                      0x18
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_DCOPCODE_BMSK                                         0x800000
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_DCOPCODE_SHFT                                             0x17
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_TDOPCODE_BMSK                                         0x700000
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_TDOPCODE_SHFT                                             0x14
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_P1_BMSK                                                0xffffc
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_P1_SHFT                                                    0x2
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_K_15_14_BMSK                                               0x3
#define HWIO_QFPROM_RAW_CALIB_ROW2_MSB_AOSS_K_15_14_SHFT                                               0x0

#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002a8)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002a8)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002a8)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW3_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW3_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS1_BASE1_1_0_BMSK                                    0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS1_BASE1_1_0_SHFT                                          0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS0_BASE1_BMSK                                        0x3ff00000
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS0_BASE1_SHFT                                              0x14
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS1_BASE0_BMSK                                           0xffc00
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS1_BASE0_SHFT                                               0xa
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS0_BASE0_BMSK                                             0x3ff
#define HWIO_QFPROM_RAW_CALIB_ROW3_LSB_TSENS0_BASE0_SHFT                                               0x0

#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002ac)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002ac)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002ac)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW3_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW3_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS4_OFFSET_3_0_BMSK                                   0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS4_OFFSET_3_0_SHFT                                         0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS3_OFFSET_BMSK                                        0xf800000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS3_OFFSET_SHFT                                             0x17
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS2_OFFSET_BMSK                                         0x7c0000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS2_OFFSET_SHFT                                             0x12
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS1_OFFSET_BMSK                                          0x3e000
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS1_OFFSET_SHFT                                              0xd
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS0_OFFSET_BMSK                                           0x1f00
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS0_OFFSET_SHFT                                              0x8
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS1_BASE1_9_2_BMSK                                          0xff
#define HWIO_QFPROM_RAW_CALIB_ROW3_MSB_TSENS1_BASE1_9_2_SHFT                                           0x0

#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002b0)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002b0)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002b0)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS11_OFFSET_0_BMSK                                    0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS11_OFFSET_0_SHFT                                          0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS10_OFFSET_BMSK                                      0x7c000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS10_OFFSET_SHFT                                            0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS9_OFFSET_BMSK                                        0x3e00000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS9_OFFSET_SHFT                                             0x15
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS8_OFFSET_BMSK                                         0x1f0000
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS8_OFFSET_SHFT                                             0x10
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS7_OFFSET_BMSK                                           0xf800
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS7_OFFSET_SHFT                                              0xb
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS6_OFFSET_BMSK                                            0x7c0
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS6_OFFSET_SHFT                                              0x6
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS5_OFFSET_BMSK                                             0x3e
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS5_OFFSET_SHFT                                              0x1
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS4_OFFSET_4_BMSK                                            0x1
#define HWIO_QFPROM_RAW_CALIB_ROW4_LSB_TSENS4_OFFSET_4_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002b4)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002b4)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002b4)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS17_OFFSET_2_0_BMSK                                  0xe0000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS17_OFFSET_2_0_SHFT                                        0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS16_OFFSET_BMSK                                      0x1f000000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS16_OFFSET_SHFT                                            0x18
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS15_OFFSET_BMSK                                        0xf80000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS15_OFFSET_SHFT                                            0x13
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS14_OFFSET_BMSK                                         0x7c000
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS14_OFFSET_SHFT                                             0xe
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS13_OFFSET_BMSK                                          0x3e00
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS13_OFFSET_SHFT                                             0x9
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS12_OFFSET_BMSK                                           0x1f0
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS12_OFFSET_SHFT                                             0x4
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS11_OFFSET_4_1_BMSK                                         0xf
#define HWIO_QFPROM_RAW_CALIB_ROW4_MSB_TSENS11_OFFSET_4_1_SHFT                                         0x0

#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002b8)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002b8)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002b8)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW5_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW5_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS23_OFFSET_BMSK                                      0xf8000000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS23_OFFSET_SHFT                                            0x1b
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS22_OFFSET_BMSK                                       0x7c00000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS22_OFFSET_SHFT                                            0x16
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS21_OFFSET_BMSK                                        0x3e0000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS21_OFFSET_SHFT                                            0x11
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS20_OFFSET_BMSK                                         0x1f000
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS20_OFFSET_SHFT                                             0xc
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS19_OFFSET_BMSK                                           0xf80
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS19_OFFSET_SHFT                                             0x7
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS18_OFFSET_BMSK                                            0x7c
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS18_OFFSET_SHFT                                             0x2
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS17_OFFSET_4_3_BMSK                                         0x3
#define HWIO_QFPROM_RAW_CALIB_ROW5_LSB_TSENS17_OFFSET_4_3_SHFT                                         0x0

#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002bc)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002bc)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002bc)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW5_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW5_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_RSVD_BMSK                                                0xffffff00
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_RSVD_SHFT                                                       0x8
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_TSENS_CAL_SEL_BMSK                                             0xe0
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_TSENS_CAL_SEL_SHFT                                              0x5
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_TSENS24_OFFSET_BMSK                                            0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW5_MSB_TSENS24_OFFSET_SHFT                                             0x0

#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002c0)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002c0)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002c0)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW6_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW6_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S5_BMSK                                     0xe0000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S5_SHFT                                           0x1d
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S4_BMSK                                     0x1c000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S4_SHFT                                           0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S3_BMSK                                      0x3800000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S3_SHFT                                           0x17
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S2_BMSK                                       0x700000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S2_SHFT                                           0x14
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S1_BMSK                                        0xe0000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S1_SHFT                                           0x11
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S0_BMSK                                        0x1c000
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_S0_SHFT                                            0xe
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE2_BMSK                                            0x3f00
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE2_SHFT                                               0x8
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_BMSK                                              0xff
#define HWIO_QFPROM_RAW_CALIB_ROW6_LSB_VSENSE_FUSE1_SHFT                                               0x0

#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002c4)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002c4)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002c4)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW6_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW6_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S6_BMSK                                     0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S6_SHFT                                           0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S5_BMSK                                     0x30000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S5_SHFT                                           0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S4_BMSK                                      0xc000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S4_SHFT                                           0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S3_BMSK                                      0x3000000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S3_SHFT                                           0x18
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S2_BMSK                                       0xc00000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S2_SHFT                                           0x16
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S1_BMSK                                       0x300000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S1_SHFT                                           0x14
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S0_BMSK                                        0xc0000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE2_S0_SHFT                                           0x12
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_RSVD_BMSK                                                   0x3f000
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_RSVD_SHFT                                                       0xc
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S9_BMSK                                          0xe00
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S9_SHFT                                            0x9
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S8_BMSK                                          0x1c0
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S8_SHFT                                            0x6
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S7_BMSK                                           0x38
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S7_SHFT                                            0x3
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S6_BMSK                                            0x7
#define HWIO_QFPROM_RAW_CALIB_ROW6_MSB_VSENSE_FUSE1_S6_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002c8)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002c8)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002c8)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW7_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW7_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_RSVD_BMSK                                                0xffffffc0
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_RSVD_SHFT                                                       0x6
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S9_BMSK                                           0x30
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S9_SHFT                                            0x4
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S8_BMSK                                            0xc
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S8_SHFT                                            0x2
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S7_BMSK                                            0x3
#define HWIO_QFPROM_RAW_CALIB_ROW7_LSB_VSENSE_FUSE2_S7_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002cc)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002cc)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002cc)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW7_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW7_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW7_MSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002d0)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002d0)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002d0)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW8_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW8_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_LSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002d4)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002d4)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002d4)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW8_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW8_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW8_MSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002d8)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002d8)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002d8)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW9_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW9_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW9_LSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002dc)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_PHYS                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002dc)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_OFFS                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002dc)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_RMSK                                                     0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW9_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW9_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_RSVD_BMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW9_MSB_RSVD_SHFT                                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002e0)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002e0)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002e0)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW10_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW10_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW10_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002e4)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002e4)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002e4)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW10_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW10_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW10_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002e8)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002e8)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002e8)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW11_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW11_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002ec)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002ec)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002ec)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW11_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW11_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW11_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002f0)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002f0)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002f0)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW12_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW12_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002f4)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002f4)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002f4)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW12_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW12_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW12_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002f8)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002f8)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002f8)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW13_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW13_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_MM_MODE_DISABLE_0_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_MM_MODE_DISABLE_0_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_SSC_CX_MODE_DISABLE_BMSK                            0x70000000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_SSC_CX_MODE_DISABLE_SHFT                                  0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_DDR_MODE_DISABLE_BMSK                                0xe000000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_DDR_MODE_DISABLE_SHFT                                     0x19
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_GFX_MODE_DISABLE_BMSK                                0x1c00000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_GFX_MODE_DISABLE_SHFT                                     0x16
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_CX_MODE_DISABLE_BMSK                                  0x380000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_CX_MODE_DISABLE_SHFT                                      0x13
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_LOCAL_RC_BMSK                                          0x70000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_LOCAL_RC_SHFT                                             0x10
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_GLOBAL_RC_BMSK                                          0xe000
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_CPR_GLOBAL_RC_SHFT                                             0xd
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_AON_AGING_BMSK                                              0x1fe0
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_AON_AGING_SHFT                                                 0x5
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_AON_TARG_VOLT_BMSK                                            0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW13_LSB_AON_TARG_VOLT_SHFT                                             0x0

#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000002fc)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000002fc)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000002fc)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW13_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW13_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_RSVD_BMSK                                               0xfffffffc
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_RSVD_SHFT                                                      0x2
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR_MM_MODE_DISABLE_2_1_BMSK                                   0x3
#define HWIO_QFPROM_RAW_CALIB_ROW13_MSB_CPR_MM_MODE_DISABLE_2_1_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000300)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000300)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000300)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW14_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW14_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_NOM_BMSK                          0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_NOM_SHFT                                0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_TUR_BMSK                           0xf000000
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_TUR_SHFT                                0x18
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_SUT_BMSK                            0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_OFFSET_SUT_SHFT                                0x14
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS3_BMSK                                   0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS3_SHFT                                       0xf
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS_BMSK                                     0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SVS_SHFT                                        0xa
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_NOM_BMSK                                      0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_NOM_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SUT_BMSK                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW14_LSB_CPR0_TARG_VOLT_SUT_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000304)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000304)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000304)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW14_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW14_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_RSVD_BMSK                                               0xfff00000
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_RSVD_SHFT                                                     0x14
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_AGING_BMSK                                            0xff000
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_AGING_SHFT                                                0xc
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS3_BMSK                              0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS3_SHFT                                0x8
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_BMSK                               0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS2_SHFT                                0x4
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS_BMSK                                 0xf
#define HWIO_QFPROM_RAW_CALIB_ROW14_MSB_CPR0_TARG_VOLT_OFFSET_SVS_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000308)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000308)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000308)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW15_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW15_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_NOM_BMSK                          0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_NOM_SHFT                                0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_TUR_BMSK                           0xf000000
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_TUR_SHFT                                0x18
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_SUT_BMSK                            0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_OFFSET_SUT_SHFT                                0x14
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS3_BMSK                                   0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS3_SHFT                                       0xf
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS_BMSK                                     0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SVS_SHFT                                        0xa
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_NOM_BMSK                                      0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_NOM_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SUT_BMSK                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW15_LSB_CPR1_TARG_VOLT_SUT_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000030c)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000030c)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000030c)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW15_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW15_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_RSVD_BMSK                                               0xfff00000
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_RSVD_SHFT                                                     0x14
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_AGING_BMSK                                            0xff000
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_AGING_SHFT                                                0xc
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS3_BMSK                              0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS3_SHFT                                0x8
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS2_BMSK                               0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS2_SHFT                                0x4
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS_BMSK                                 0xf
#define HWIO_QFPROM_RAW_CALIB_ROW15_MSB_CPR1_TARG_VOLT_OFFSET_SVS_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000310)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000310)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000310)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW16_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW16_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_NOM_1_0_BMSK                             0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_NOM_1_0_SHFT                                   0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_TUR_BMSK                                 0x3e000000
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_TUR_SHFT                                       0x19
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_SUT_BMSK                                  0x1f00000
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR3_TARG_VOLT_SUT_SHFT                                       0x14
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS3_BMSK                                   0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS3_SHFT                                       0xf
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS_BMSK                                     0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_SVS_SHFT                                        0xa
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_NOM_BMSK                                      0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_NOM_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_TUR_BMSK                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW16_LSB_CPR2_TARG_VOLT_TUR_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000314)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000314)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000314)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW16_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW16_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_RSVD_BMSK                                               0xff000000
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_RSVD_SHFT                                                     0x18
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SVSP_BMSK                           0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SVSP_SHFT                               0x14
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_NOM_BMSK                             0xf0000
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_NOM_SHFT                                0x10
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_TUR_BMSK                              0xf000
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_TUR_SHFT                                 0xc
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SUT_BMSK                               0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_OFFSET_SUT_SHFT                                 0x8
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_SVSP_BMSK                                      0xf8
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_SVSP_SHFT                                       0x3
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_NOM_4_2_BMSK                                    0x7
#define HWIO_QFPROM_RAW_CALIB_ROW16_MSB_CPR3_TARG_VOLT_NOM_4_2_SHFT                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000318)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000318)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000318)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW17_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW17_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW17_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW17_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW17_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_OFFSET_TUR_1_0_BMSK                      0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_OFFSET_TUR_1_0_SHFT                            0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS3_BMSK                                0x3e000000
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS3_SHFT                                      0x19
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS_BMSK                                  0x1f00000
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_SVS_SHFT                                       0x14
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_NOM_BMSK                                    0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_NOM_SHFT                                        0xf
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_TUR_BMSK                                     0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR5_TARG_VOLT_TUR_SHFT                                        0xa
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR4_TARG_VOLT_NOM_BMSK                                      0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR4_TARG_VOLT_NOM_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR4_TARG_VOLT_TUR_BMSK                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW17_LSB_CPR4_TARG_VOLT_TUR_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000031c)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000031c)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000031c)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW17_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW17_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW17_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW17_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW17_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_RSVD_BMSK                                               0xfc000000
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_RSVD_SHFT                                                     0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_AGING_BMSK                                          0x3fc0000
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_AGING_SHFT                                               0x12
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS3_BMSK                            0x3c000
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS3_SHFT                                0xe
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS2_BMSK                             0x3c00
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS2_SHFT                                0xa
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS_BMSK                               0x3c0
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_SVS_SHFT                                 0x6
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_NOM_BMSK                                0x3c
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_NOM_SHFT                                 0x2
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_TUR_3_2_BMSK                             0x3
#define HWIO_QFPROM_RAW_CALIB_ROW17_MSB_CPR5_TARG_VOLT_OFFSET_TUR_3_2_SHFT                             0x0

#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000320)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000320)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000320)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW18_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW18_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW18_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW18_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW18_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_SVSP_BMSK                         0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_SVSP_SHFT                               0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_NOM_BMSK                           0xf000000
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_NOM_SHFT                                0x18
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_TUR_BMSK                            0xf00000
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_OFFSET_TUR_SHFT                                0x14
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS2_BMSK                                   0xf8000
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS2_SHFT                                       0xf
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS_BMSK                                     0x7c00
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_SVS_SHFT                                        0xa
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_NOM_BMSK                                      0x3e0
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_NOM_SHFT                                        0x5
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_TUR_BMSK                                       0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW18_LSB_CPR6_TARG_VOLT_TUR_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000324)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000324)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000324)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW18_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW18_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW18_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW18_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW18_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_RSVD_BMSK                                               0xffff0000
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_RSVD_SHFT                                                     0x10
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_AGING_BMSK                                             0xff00
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_AGING_SHFT                                                0x8
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS2_BMSK                               0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS2_SHFT                                0x4
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS_BMSK                                 0xf
#define HWIO_QFPROM_RAW_CALIB_ROW18_MSB_CPR6_TARG_VOLT_OFFSET_SVS_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000328)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000328)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000328)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW19_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW19_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW19_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW19_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW19_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_SVS_3_0_BMSK                             0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_SVS_3_0_SHFT                                   0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_NOM_BMSK                                  0xfc00000
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_NOM_SHFT                                       0x16
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_TUR_BMSK                                   0x3f0000
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TARG_VOLT_TUR_SHFT                                       0x10
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_SVS2_ROSEL_BMSK                                        0xf000
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_SVS2_ROSEL_SHFT                                           0xc
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_SVS_ROSEL_BMSK                                          0xf00
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_SVS_ROSEL_SHFT                                            0x8
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_NOMINAL_ROSEL_BMSK                                       0xf0
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_NOMINAL_ROSEL_SHFT                                        0x4
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TURBO_ROSEL_BMSK                                          0xf
#define HWIO_QFPROM_RAW_CALIB_ROW19_LSB_CPR7_TURBO_ROSEL_SHFT                                          0x0

#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000032c)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000032c)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000032c)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW19_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW19_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW19_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW19_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW19_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_NOMINAL_QUOT_VMIN_BMSK                             0xfff00000
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_NOMINAL_QUOT_VMIN_SHFT                                   0x14
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TURBO_QUOT_VMIN_BMSK                                  0xfff00
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TURBO_QUOT_VMIN_SHFT                                      0x8
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS2_BMSK                                      0xfc
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS2_SHFT                                       0x2
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS_5_4_BMSK                                    0x3
#define HWIO_QFPROM_RAW_CALIB_ROW19_MSB_CPR7_TARG_VOLT_SVS_5_4_SHFT                                    0x0

#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000330)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000330)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000330)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW20_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW20_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW20_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW20_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW20_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_QUOT_OFFSET_TUR_BMSK                               0xff000000
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_QUOT_OFFSET_TUR_SHFT                                     0x18
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_SVS2_QUOT_VMIN_BMSK                                  0xfff000
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_SVS2_QUOT_VMIN_SHFT                                       0xc
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_SVS_QUOT_VMIN_BMSK                                      0xfff
#define HWIO_QFPROM_RAW_CALIB_ROW20_LSB_CPR7_SVS_QUOT_VMIN_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000334)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000334)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000334)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW20_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW20_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW20_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW20_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW20_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_RSVD_BMSK                                               0xffc00000
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_RSVD_SHFT                                                     0x16
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_AGING_BMSK                                           0x3fc000
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_AGING_SHFT                                                0xe
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_SVS_BMSK                                   0x3f80
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_SVS_SHFT                                      0x7
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_NOM_BMSK                                     0x7f
#define HWIO_QFPROM_RAW_CALIB_ROW20_MSB_CPR7_QUOT_OFFSET_NOM_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000338)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000338)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000338)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW21_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW21_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW21_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW21_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW21_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TURBO_QUOT_VMIN_7_0_BMSK                           0xff000000
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TURBO_QUOT_VMIN_7_0_SHFT                                 0x18
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS2_BMSK                                  0xfc0000
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS2_SHFT                                      0x12
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS_BMSK                                    0x3f000
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_SVS_SHFT                                        0xc
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_NOM_BMSK                                      0xfc0
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_NOM_SHFT                                        0x6
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_TUR_BMSK                                       0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW21_LSB_CPR8_TARG_VOLT_TUR_SHFT                                        0x0

#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000033c)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000033c)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000033c)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW21_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW21_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW21_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW21_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW21_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_SVS2_QUOT_VMIN_3_0_BMSK                            0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_SVS2_QUOT_VMIN_3_0_SHFT                                  0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_SVS_QUOT_VMIN_BMSK                                  0xfff0000
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_SVS_QUOT_VMIN_SHFT                                       0x10
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_NOMINAL_QUOT_VMIN_BMSK                                 0xfff0
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_NOMINAL_QUOT_VMIN_SHFT                                    0x4
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_TURBO_QUOT_VMIN_11_8_BMSK                                 0xf
#define HWIO_QFPROM_RAW_CALIB_ROW21_MSB_CPR8_TURBO_QUOT_VMIN_11_8_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000340)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000340)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000340)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW22_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW22_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW22_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW22_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW22_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR9_TURBO_ROSEL_1_0_BMSK                               0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR9_TURBO_ROSEL_1_0_SHFT                                     0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_SVS_BMSK                               0x3f800000
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_SVS_SHFT                                     0x17
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_NOM_BMSK                                 0x7f0000
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_NOM_SHFT                                     0x10
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_TUR_BMSK                                   0xff00
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_QUOT_OFFSET_TUR_SHFT                                      0x8
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_SVS2_QUOT_VMIN_11_4_BMSK                                 0xff
#define HWIO_QFPROM_RAW_CALIB_ROW22_LSB_CPR8_SVS2_QUOT_VMIN_11_4_SHFT                                  0x0

#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000344)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000344)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000344)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW22_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW22_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW22_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW22_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW22_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_SVS_BMSK                                 0xfc000000
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_SVS_SHFT                                       0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_NOM_BMSK                                  0x3f00000
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_NOM_SHFT                                       0x14
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_TUR_BMSK                                    0xfc000
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TARG_VOLT_TUR_SHFT                                        0xe
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_SVS2_ROSEL_BMSK                                        0x3c00
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_SVS2_ROSEL_SHFT                                           0xa
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_SVS_ROSEL_BMSK                                          0x3c0
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_SVS_ROSEL_SHFT                                            0x6
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_NOMINAL_ROSEL_BMSK                                       0x3c
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_NOMINAL_ROSEL_SHFT                                        0x2
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TURBO_ROSEL_3_2_BMSK                                      0x3
#define HWIO_QFPROM_RAW_CALIB_ROW22_MSB_CPR9_TURBO_ROSEL_3_2_SHFT                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000348)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000348)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000348)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW23_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW23_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW23_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW23_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW23_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_SVS_QUOT_VMIN_1_0_BMSK                             0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_SVS_QUOT_VMIN_1_0_SHFT                                   0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_NOMINAL_QUOT_VMIN_BMSK                             0x3ffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_NOMINAL_QUOT_VMIN_SHFT                                   0x12
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_TURBO_QUOT_VMIN_BMSK                                  0x3ffc0
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_TURBO_QUOT_VMIN_SHFT                                      0x6
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_TARG_VOLT_SVS2_BMSK                                      0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW23_LSB_CPR9_TARG_VOLT_SVS2_SHFT                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000034c)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000034c)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000034c)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW23_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW23_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW23_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW23_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW23_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_NOM_1_0_BMSK                           0xc0000000
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_NOM_1_0_SHFT                                 0x1e
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_TUR_BMSK                               0x3fc00000
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_QUOT_OFFSET_TUR_SHFT                                     0x16
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_SVS2_QUOT_VMIN_BMSK                                  0x3ffc00
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_SVS2_QUOT_VMIN_SHFT                                       0xa
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_SVS_QUOT_VMIN_11_2_BMSK                                 0x3ff
#define HWIO_QFPROM_RAW_CALIB_ROW23_MSB_CPR9_SVS_QUOT_VMIN_11_2_SHFT                                   0x0

#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000350)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000350)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000350)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW24_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW24_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW24_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW24_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW24_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR10_TARG_VOLT_NOM_BMSK                                0xfc000000
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR10_TARG_VOLT_NOM_SHFT                                      0x1a
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR10_TARG_VOLT_TUR_BMSK                                 0x3f00000
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR10_TARG_VOLT_TUR_SHFT                                      0x14
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_AGING_BMSK                                            0xff000
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_AGING_SHFT                                                0xc
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_SVS_BMSK                                    0xfe0
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_SVS_SHFT                                      0x5
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_NOM_6_2_BMSK                                 0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW24_LSB_CPR9_QUOT_OFFSET_NOM_6_2_SHFT                                  0x0

#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000354)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000354)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000354)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW24_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW24_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW24_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW24_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW24_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_NOMINAL_QUOT_VMIN_7_0_BMSK                        0xff000000
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_NOMINAL_QUOT_VMIN_7_0_SHFT                              0x18
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TURBO_QUOT_VMIN_BMSK                                0xfff000
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TURBO_QUOT_VMIN_SHFT                                     0xc
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS2_BMSK                                    0xfc0
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS2_SHFT                                      0x6
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS_BMSK                                      0x3f
#define HWIO_QFPROM_RAW_CALIB_ROW24_MSB_CPR10_TARG_VOLT_SVS_SHFT                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000358)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000358)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000358)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW25_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW25_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW25_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW25_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW25_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_QUOT_OFFSET_TUR_3_0_BMSK                          0xf0000000
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_QUOT_OFFSET_TUR_3_0_SHFT                                0x1c
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_SVS2_QUOT_VMIN_BMSK                                0xfff0000
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_SVS2_QUOT_VMIN_SHFT                                     0x10
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_SVS_QUOT_VMIN_BMSK                                    0xfff0
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_SVS_QUOT_VMIN_SHFT                                       0x4
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_NOMINAL_QUOT_VMIN_11_8_BMSK                              0xf
#define HWIO_QFPROM_RAW_CALIB_ROW25_LSB_CPR10_NOMINAL_QUOT_VMIN_11_8_SHFT                              0x0

#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000035c)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000035c)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000035c)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW25_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW25_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW25_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW25_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW25_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_RSVD_BMSK                                               0xfffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_RSVD_SHFT                                                     0x12
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_SVS_BMSK                                 0x3f800
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_SVS_SHFT                                     0xb
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_NOM_BMSK                                   0x7f0
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_NOM_SHFT                                     0x4
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_TUR_7_4_BMSK                                 0xf
#define HWIO_QFPROM_RAW_CALIB_ROW25_MSB_CPR10_QUOT_OFFSET_TUR_7_4_SHFT                                 0x0

#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000360)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000360)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000360)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW26_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW26_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW26_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW26_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW26_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_CPR_RSVD_31_5_BMSK                                      0xffffffe0
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_CPR_RSVD_31_5_SHFT                                             0x5
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_CPR1_TARG_VOLT_SVSP_BMSK                                      0x1f
#define HWIO_QFPROM_RAW_CALIB_ROW26_LSB_CPR1_TARG_VOLT_SVSP_SHFT                                       0x0

#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000364)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000364)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000364)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW26_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW26_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW26_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW26_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW26_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_RSVD_BMSK                                               0xfffc0000
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_RSVD_SHFT                                                     0x12
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_CPR_RSVD_49_32_BMSK                                        0x3ffff
#define HWIO_QFPROM_RAW_CALIB_ROW26_MSB_CPR_RSVD_49_32_SHFT                                            0x0

#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000368)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000368)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000368)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW27_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW27_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW27_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW27_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW27_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW27_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000036c)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000036c)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000036c)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW27_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW27_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW27_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW27_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW27_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW27_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000370)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000370)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000370)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW28_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW28_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW28_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW28_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW28_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW28_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000374)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000374)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000374)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW28_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW28_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW28_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW28_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW28_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW28_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000378)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000378)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000378)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW29_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW29_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW29_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW29_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW29_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW29_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000037c)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000037c)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000037c)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW29_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW29_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW29_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW29_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW29_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW29_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000380)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000380)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000380)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW30_LSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW30_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW30_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW30_LSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW30_LSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW30_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000384)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000384)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000384)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_CALIB_ROW30_MSB_ADDR)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_CALIB_ROW30_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_CALIB_ROW30_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_CALIB_ROW30_MSB_ADDR,m,v,HWIO_QFPROM_RAW_CALIB_ROW30_MSB_IN)
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_RAW_CALIB_ROW30_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000388 + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_PHYS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000388 + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_OFFS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000388 + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_MAXn                                                        70
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_REDUN_DATA_BMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_LSB_REDUN_DATA_SHFT                                            0x0

#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000038c + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_PHYS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000038c + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_OFFS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000038c + 0x8 * (n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_MAXn                                                        70
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_REDUN_DATA_BMSK                                     0xffffffff
#define HWIO_QFPROM_RAW_MEM_CONFIG_ROWn_MSB_REDUN_DATA_SHFT                                            0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005c0)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_PHYS                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005c0)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_OFFS                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005c0)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_ADDR)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_ADDR,m,v,HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_IN)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_QC_SPARE_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_LSB_QC_SPARE_SHFT                                               0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005c4)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_PHYS                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005c4)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_OFFS                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005c4)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_ADDR)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_ADDR,m,v,HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_IN)
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_RSVD0_BMSK                                           0x80000000
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_RSVD0_SHFT                                                 0x1f
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_FEC_VALUE_BMSK                                       0x7f000000
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_FEC_VALUE_SHFT                                             0x18
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_QC_SPARE_BMSK                                          0xffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG20_MSB_QC_SPARE_SHFT                                               0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005c8)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_PHYS                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005c8)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_OFFS                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005c8)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_ADDR)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_ADDR,m,v,HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_IN)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_QC_SPARE_BMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_LSB_QC_SPARE_SHFT                                               0x0

#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_ADDR                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005cc)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_PHYS                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005cc)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_OFFS                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005cc)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_ADDR)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_ADDR,m,v,HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_IN)
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_RSVD0_BMSK                                           0x80000000
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_RSVD0_SHFT                                                 0x1f
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_FEC_VALUE_BMSK                                       0x7f000000
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_FEC_VALUE_SHFT                                             0x18
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_QC_SPARE_BMSK                                          0xffffff
#define HWIO_QFPROM_RAW_QC_SPARE_REG21_MSB_QC_SPARE_SHFT                                               0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n)                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005d0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_PHYS(n)                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005d0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OFFS(n)                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005d0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_MAXn                                                 1
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_BMSK                              0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_SHFT                                     0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n)                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005d4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_PHYS(n)                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005d4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OFFS(n)                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005d4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_MAXn                                                 1
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RSVD1_BMSK                                  0x80000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RSVD1_SHFT                                        0x1f
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_FEC_VALUE_BMSK                              0x7f000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_FEC_VALUE_SHFT                                    0x18
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_BMSK                                0xffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_SHFT                                     0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005e0)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_PHYS                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005e0)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OFFS                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005e0)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_BMSK                                  0xffff0000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_SHFT                                        0x10
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_BMSK                                  0xffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_SHFT                                     0x0

#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005e4)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_PHYS                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005e4)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OFFS                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005e4)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK                                        0xffffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD1_BMSK                                  0x80000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD1_SHFT                                        0x1f
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_FEC_VALUE_BMSK                              0x7f000000
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_FEC_VALUE_SHFT                                    0x18
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_BMSK                                    0xffffff
#define HWIO_QFPROM_RAW_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_SHFT                                         0x0

#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n)                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005e8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_PHYS(n)                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005e8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_OFFS(n)                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005e8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_MAXn                                                       1
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_BMSK                                    0xff000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_SHFT                                          0x18
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_BMSK                                      0xff0000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_SHFT                                          0x10
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_BMSK                                        0xff00
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_SHFT                                           0x8
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_BMSK                                          0xff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_SHFT                                           0x0

#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n)                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005ec + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_PHYS(n)                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005ec + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_OFFS(n)                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005ec + 0x8 * (n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_MAXn                                                       1
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RSVD1_BMSK                                        0x80000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_RSVD1_SHFT                                              0x1f
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_FEC_VALUE_BMSK                                    0x7f000000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_FEC_VALUE_SHFT                                          0x18
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_BMSK                                      0xff0000
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_SHFT                                          0x10
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_BMSK                                        0xff00
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_SHFT                                           0x8
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_BMSK                                          0xff
#define HWIO_QFPROM_RAW_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_SHFT                                           0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_PHYS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OFFS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                             3
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x000005fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_PHYS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000005fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OFFS(n)                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000005fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                             3
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RSVD1_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_BMSK                          0x7f000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_FEC_VALUE_SHFT                                0x18
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                            0xffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                 0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000618)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_PHYS                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000618)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OFFS                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000618)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                          0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                 0x0

#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000061c)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_PHYS                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000061c)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OFFS                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000061c)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                    0xffffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_BMSK                              0x80000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD1_SHFT                                    0x1f
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_BMSK                          0x7f000000
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_FEC_VALUE_SHFT                                0x18
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                                0xffffff
#define HWIO_QFPROM_RAW_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                     0x0

#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000620 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_PHYS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000620 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_OFFS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000620 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_MAXn                                                         55
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_PATCH_DATA_BMSK                                      0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_LSB_PATCH_DATA_SHFT                                             0x0

#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000624 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PHYS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000624 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_OFFS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000624 + 0x8 * (n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_MAXn                                                         55
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD1_BMSK                                           0x80000000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD1_SHFT                                                 0x1f
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_FEC_VALUE_BMSK                                       0x7f000000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_FEC_VALUE_SHFT                                             0x18
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD0_BMSK                                             0xfe0000
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_RSVD0_SHFT                                                 0x11
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_ADDR_BMSK                                         0x1fffe
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_ADDR_SHFT                                             0x1
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_EN_BMSK                                               0x1
#define HWIO_QFPROM_RAW_ROM_PATCH_ROWn_MSB_PATCH_EN_SHFT                                               0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007e0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007e0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007e0 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_MAXn                                                    1
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_BMSK                                 0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_SHFT                                        0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007e4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007e4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007e4 + 0x8 * (n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_MAXn                                                    1
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RSVD1_BMSK                                     0x80000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_RSVD1_SHFT                                           0x1f
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_FEC_VALUE_BMSK                                 0x7f000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_FEC_VALUE_SHFT                                       0x18
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_BMSK                                   0xffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_SHFT                                        0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007f0)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007f0)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007f0)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR,m,v,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_IN)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_BMSK                                     0xffff0000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_SHFT                                           0x10
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_BMSK                                     0xffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_SHFT                                        0x0

#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007f4)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007f4)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007f4)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR,m,v,HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_IN)
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD1_BMSK                                     0x80000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD1_SHFT                                           0x1f
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_FEC_VALUE_BMSK                                 0x7f000000
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_FEC_VALUE_SHFT                                       0x18
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_BMSK                                       0xffffff
#define HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_SHFT                                            0x0

#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_PHYS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_OFFS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007f8 + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_MAXn                                                      3
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_INI(n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_USER_DATA_KEY_BMSK                               0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_LSB_USER_DATA_KEY_SHFT                                      0x0

#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000007fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_PHYS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000007fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_OFFS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000007fc + 0x8 * (n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_MAXn                                                      3
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_INI(n))
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_RSVD1_BMSK                                       0x80000000
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_RSVD1_SHFT                                             0x1f
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_FEC_VALUE_BMSK                                   0x7f000000
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_FEC_VALUE_SHFT                                         0x18
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_USER_DATA_KEY_BMSK                                 0xffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROWn_MSB_USER_DATA_KEY_SHFT                                      0x0

#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000818)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_PHYS                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000818)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_OFFS                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000818)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_ADDR)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_ADDR,v)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_ADDR,m,v,HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_IN)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_USER_DATA_KEY_BMSK                               0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_LSB_USER_DATA_KEY_SHFT                                      0x0

#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_ADDR                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000081c)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_PHYS                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000081c)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_OFFS                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000081c)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_ADDR)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_OUT(v)      \
        out_dword(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_ADDR,v)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_ADDR,m,v,HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_IN)
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_RSVD1_BMSK                                       0x80000000
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_RSVD1_SHFT                                             0x1f
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_FEC_VALUE_BMSK                                   0x7f000000
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_FEC_VALUE_SHFT                                         0x18
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_RSVD0_BMSK                                         0xffffff
#define HWIO_QFPROM_RAW_USER_DATA_KEY_ROW4_MSB_RSVD0_SHFT                                              0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000660 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000660 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000660 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_MAXn                                                    31
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000664 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000664 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000664 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_MAXn                                                    31
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00000668 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00000668 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00000668 + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_MAXn                                                    31
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000066c + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000066c + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000066c + 0x10 * (n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_MAXn                                                    31
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_RMSK)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), mask)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OUTI(n,val)    \
        out_dword(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n),val)
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OUTMI(n,mask,val) \
        out_dword_masked_ns(HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_ADDR(n),mask,val,HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_INI(n))
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_BMSK                                  0xffffffff
#define HWIO_QFPROM_RAW_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_SHFT                                         0x0

#define HWIO_QFPROM_BLOW_TIMER_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000203c)
#define HWIO_QFPROM_BLOW_TIMER_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000203c)
#define HWIO_QFPROM_BLOW_TIMER_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000203c)
#define HWIO_QFPROM_BLOW_TIMER_RMSK                                                                  0xfff
#define HWIO_QFPROM_BLOW_TIMER_IN          \
        in_dword(HWIO_QFPROM_BLOW_TIMER_ADDR)
#define HWIO_QFPROM_BLOW_TIMER_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BLOW_TIMER_ADDR, m)
#define HWIO_QFPROM_BLOW_TIMER_OUT(v)      \
        out_dword(HWIO_QFPROM_BLOW_TIMER_ADDR,v)
#define HWIO_QFPROM_BLOW_TIMER_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_BLOW_TIMER_ADDR,m,v,HWIO_QFPROM_BLOW_TIMER_IN)
#define HWIO_QFPROM_BLOW_TIMER_BLOW_TIMER_BMSK                                                       0xfff
#define HWIO_QFPROM_BLOW_TIMER_BLOW_TIMER_SHFT                                                         0x0

#define HWIO_QFPROM_TEST_CTRL_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002040)
#define HWIO_QFPROM_TEST_CTRL_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002040)
#define HWIO_QFPROM_TEST_CTRL_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002040)
#define HWIO_QFPROM_TEST_CTRL_RMSK                                                                     0xf
#define HWIO_QFPROM_TEST_CTRL_IN          \
        in_dword(HWIO_QFPROM_TEST_CTRL_ADDR)
#define HWIO_QFPROM_TEST_CTRL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_TEST_CTRL_ADDR, m)
#define HWIO_QFPROM_TEST_CTRL_OUT(v)      \
        out_dword(HWIO_QFPROM_TEST_CTRL_ADDR,v)
#define HWIO_QFPROM_TEST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_TEST_CTRL_ADDR,m,v,HWIO_QFPROM_TEST_CTRL_IN)
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_ROM_BMSK                                                         0x8
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_ROM_SHFT                                                         0x3
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_WL_BMSK                                                          0x4
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_WL_SHFT                                                          0x2
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_BL_BMSK                                                          0x2
#define HWIO_QFPROM_TEST_CTRL_SEL_TST_BL_SHFT                                                          0x1
#define HWIO_QFPROM_TEST_CTRL_EN_FUSE_RES_MEAS_BMSK                                                    0x1
#define HWIO_QFPROM_TEST_CTRL_EN_FUSE_RES_MEAS_SHFT                                                    0x0

#define HWIO_QFPROM_ACCEL_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002044)
#define HWIO_QFPROM_ACCEL_PHYS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002044)
#define HWIO_QFPROM_ACCEL_OFFS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002044)
#define HWIO_QFPROM_ACCEL_RMSK                                                                       0xfff
#define HWIO_QFPROM_ACCEL_IN          \
        in_dword(HWIO_QFPROM_ACCEL_ADDR)
#define HWIO_QFPROM_ACCEL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_ACCEL_ADDR, m)
#define HWIO_QFPROM_ACCEL_OUT(v)      \
        out_dword(HWIO_QFPROM_ACCEL_ADDR,v)
#define HWIO_QFPROM_ACCEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_ACCEL_ADDR,m,v,HWIO_QFPROM_ACCEL_IN)
#define HWIO_QFPROM_ACCEL_QFPROM_GATELAST_BMSK                                                       0x800
#define HWIO_QFPROM_ACCEL_QFPROM_GATELAST_SHFT                                                         0xb
#define HWIO_QFPROM_ACCEL_QFPROM_TRIPPT_SEL_BMSK                                                     0x700
#define HWIO_QFPROM_ACCEL_QFPROM_TRIPPT_SEL_SHFT                                                       0x8
#define HWIO_QFPROM_ACCEL_QFPROM_ACCEL_BMSK                                                           0xff
#define HWIO_QFPROM_ACCEL_QFPROM_ACCEL_SHFT                                                            0x0

#define HWIO_QFPROM_BLOW_STATUS_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002048)
#define HWIO_QFPROM_BLOW_STATUS_PHYS                                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002048)
#define HWIO_QFPROM_BLOW_STATUS_OFFS                                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002048)
#define HWIO_QFPROM_BLOW_STATUS_RMSK                                                                   0x3
#define HWIO_QFPROM_BLOW_STATUS_IN          \
        in_dword(HWIO_QFPROM_BLOW_STATUS_ADDR)
#define HWIO_QFPROM_BLOW_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BLOW_STATUS_ADDR, m)
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_BMSK                                                     0x2
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_SHFT                                                     0x1
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_NO_ERROR_FVAL                                            0x0
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_WR_ERR_ERROR_FVAL                                               0x1
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_BUSY_BMSK                                                       0x1
#define HWIO_QFPROM_BLOW_STATUS_QFPROM_BUSY_SHFT                                                       0x0

#define HWIO_QFPROM_ROM_ERROR_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000204c)
#define HWIO_QFPROM_ROM_ERROR_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000204c)
#define HWIO_QFPROM_ROM_ERROR_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000204c)
#define HWIO_QFPROM_ROM_ERROR_RMSK                                                                     0x1
#define HWIO_QFPROM_ROM_ERROR_IN          \
        in_dword(HWIO_QFPROM_ROM_ERROR_ADDR)
#define HWIO_QFPROM_ROM_ERROR_INM(m)      \
        in_dword_masked(HWIO_QFPROM_ROM_ERROR_ADDR, m)
#define HWIO_QFPROM_ROM_ERROR_ERROR_BMSK                                                               0x1
#define HWIO_QFPROM_ROM_ERROR_ERROR_SHFT                                                               0x0
#define HWIO_QFPROM_ROM_ERROR_ERROR_NO_ERROR_FVAL                                                      0x0
#define HWIO_QFPROM_ROM_ERROR_ERROR_ERROR_FVAL                                                         0x1

#define HWIO_QFPROM0_MATCH_STATUS_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002050)
#define HWIO_QFPROM0_MATCH_STATUS_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002050)
#define HWIO_QFPROM0_MATCH_STATUS_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002050)
#define HWIO_QFPROM0_MATCH_STATUS_RMSK                                                          0xffffffff
#define HWIO_QFPROM0_MATCH_STATUS_IN          \
        in_dword(HWIO_QFPROM0_MATCH_STATUS_ADDR)
#define HWIO_QFPROM0_MATCH_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM0_MATCH_STATUS_ADDR, m)
#define HWIO_QFPROM0_MATCH_STATUS_FLAG_BMSK                                                     0xffffffff
#define HWIO_QFPROM0_MATCH_STATUS_FLAG_SHFT                                                            0x0

#define HWIO_QFPROM1_MATCH_STATUS_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002054)
#define HWIO_QFPROM1_MATCH_STATUS_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002054)
#define HWIO_QFPROM1_MATCH_STATUS_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002054)
#define HWIO_QFPROM1_MATCH_STATUS_RMSK                                                          0xffffffff
#define HWIO_QFPROM1_MATCH_STATUS_IN          \
        in_dword(HWIO_QFPROM1_MATCH_STATUS_ADDR)
#define HWIO_QFPROM1_MATCH_STATUS_INM(m)      \
        in_dword_masked(HWIO_QFPROM1_MATCH_STATUS_ADDR, m)
#define HWIO_QFPROM1_MATCH_STATUS_FLAG_BMSK                                                     0xffffffff
#define HWIO_QFPROM1_MATCH_STATUS_FLAG_SHFT                                                            0x0

#define HWIO_FEC_ESR_ADDR                                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002058)
#define HWIO_FEC_ESR_PHYS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002058)
#define HWIO_FEC_ESR_OFFS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002058)
#define HWIO_FEC_ESR_RMSK                                                                           0x2fdf
#define HWIO_FEC_ESR_IN          \
        in_dword(HWIO_FEC_ESR_ADDR)
#define HWIO_FEC_ESR_INM(m)      \
        in_dword_masked(HWIO_FEC_ESR_ADDR, m)
#define HWIO_FEC_ESR_OUT(v)      \
        out_dword(HWIO_FEC_ESR_ADDR,v)
#define HWIO_FEC_ESR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_FEC_ESR_ADDR,m,v,HWIO_FEC_ESR_IN)
#define HWIO_FEC_ESR_CORR_SW_ACC_BMSK                                                               0x2000
#define HWIO_FEC_ESR_CORR_SW_ACC_SHFT                                                                  0xd
#define HWIO_FEC_ESR_CORR_SECURE_CHANNEL_BMSK                                                        0x800
#define HWIO_FEC_ESR_CORR_SECURE_CHANNEL_SHFT                                                          0xb
#define HWIO_FEC_ESR_CORR_BOOT_ROM_BMSK                                                              0x400
#define HWIO_FEC_ESR_CORR_BOOT_ROM_SHFT                                                                0xa
#define HWIO_FEC_ESR_CORR_FUSE_SENSE_BMSK                                                            0x200
#define HWIO_FEC_ESR_CORR_FUSE_SENSE_SHFT                                                              0x9
#define HWIO_FEC_ESR_CORR_MULT_BMSK                                                                  0x100
#define HWIO_FEC_ESR_CORR_MULT_SHFT                                                                    0x8
#define HWIO_FEC_ESR_CORR_SEEN_BMSK                                                                   0x80
#define HWIO_FEC_ESR_CORR_SEEN_SHFT                                                                    0x7
#define HWIO_FEC_ESR_CORR_SEEN_NO_CORRECTION_FVAL                                                      0x0
#define HWIO_FEC_ESR_CORR_SEEN_CORRECTION_FVAL                                                         0x1
#define HWIO_FEC_ESR_ERR_SW_ACC_BMSK                                                                  0x40
#define HWIO_FEC_ESR_ERR_SW_ACC_SHFT                                                                   0x6
#define HWIO_FEC_ESR_ERR_SECURE_CHANNEL_BMSK                                                          0x10
#define HWIO_FEC_ESR_ERR_SECURE_CHANNEL_SHFT                                                           0x4
#define HWIO_FEC_ESR_ERR_BOOT_ROM_BMSK                                                                 0x8
#define HWIO_FEC_ESR_ERR_BOOT_ROM_SHFT                                                                 0x3
#define HWIO_FEC_ESR_ERR_FUSE_SENSE_BMSK                                                               0x4
#define HWIO_FEC_ESR_ERR_FUSE_SENSE_SHFT                                                               0x2
#define HWIO_FEC_ESR_ERR_MULT_BMSK                                                                     0x2
#define HWIO_FEC_ESR_ERR_MULT_SHFT                                                                     0x1
#define HWIO_FEC_ESR_ERR_SEEN_BMSK                                                                     0x1
#define HWIO_FEC_ESR_ERR_SEEN_SHFT                                                                     0x0
#define HWIO_FEC_ESR_ERR_SEEN_NO_ERROR_FVAL                                                            0x0
#define HWIO_FEC_ESR_ERR_SEEN_ERROR_FVAL                                                               0x1

#define HWIO_FEC_EAR_ADDR                                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000205c)
#define HWIO_FEC_EAR_PHYS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000205c)
#define HWIO_FEC_EAR_OFFS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000205c)
#define HWIO_FEC_EAR_RMSK                                                                       0xffffffff
#define HWIO_FEC_EAR_IN          \
        in_dword(HWIO_FEC_EAR_ADDR)
#define HWIO_FEC_EAR_INM(m)      \
        in_dword_masked(HWIO_FEC_EAR_ADDR, m)
#define HWIO_FEC_EAR_CORR_ADDR_BMSK                                                             0xffff0000
#define HWIO_FEC_EAR_CORR_ADDR_SHFT                                                                   0x10
#define HWIO_FEC_EAR_ERR_ADDR_BMSK                                                                  0xffff
#define HWIO_FEC_EAR_ERR_ADDR_SHFT                                                                     0x0

#define HWIO_QFPROM_BIST_CTRL_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002060)
#define HWIO_QFPROM_BIST_CTRL_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002060)
#define HWIO_QFPROM_BIST_CTRL_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002060)
#define HWIO_QFPROM_BIST_CTRL_RMSK                                                                    0xff
#define HWIO_QFPROM_BIST_CTRL_IN          \
        in_dword(HWIO_QFPROM_BIST_CTRL_ADDR)
#define HWIO_QFPROM_BIST_CTRL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_CTRL_ADDR, m)
#define HWIO_QFPROM_BIST_CTRL_OUT(v)      \
        out_dword(HWIO_QFPROM_BIST_CTRL_ADDR,v)
#define HWIO_QFPROM_BIST_CTRL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_BIST_CTRL_ADDR,m,v,HWIO_QFPROM_BIST_CTRL_IN)
#define HWIO_QFPROM_BIST_CTRL_AUTH_REGION_BMSK                                                        0xfc
#define HWIO_QFPROM_BIST_CTRL_AUTH_REGION_SHFT                                                         0x2
#define HWIO_QFPROM_BIST_CTRL_SHA_ENABLE_BMSK                                                          0x2
#define HWIO_QFPROM_BIST_CTRL_SHA_ENABLE_SHFT                                                          0x1
#define HWIO_QFPROM_BIST_CTRL_START_BMSK                                                               0x1
#define HWIO_QFPROM_BIST_CTRL_START_SHFT                                                               0x0

#define HWIO_QFPROM_BIST_ERROR0_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002064)
#define HWIO_QFPROM_BIST_ERROR0_PHYS                                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002064)
#define HWIO_QFPROM_BIST_ERROR0_OFFS                                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002064)
#define HWIO_QFPROM_BIST_ERROR0_RMSK                                                            0xffffffff
#define HWIO_QFPROM_BIST_ERROR0_IN          \
        in_dword(HWIO_QFPROM_BIST_ERROR0_ADDR)
#define HWIO_QFPROM_BIST_ERROR0_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR0_ADDR, m)
#define HWIO_QFPROM_BIST_ERROR0_ERROR_BMSK                                                      0xffffffff
#define HWIO_QFPROM_BIST_ERROR0_ERROR_SHFT                                                             0x0
#define HWIO_QFPROM_BIST_ERROR0_ERROR_NO_ERROR_FVAL                                                    0x0
#define HWIO_QFPROM_BIST_ERROR0_ERROR_ERROR_FVAL                                                       0x1

#define HWIO_QFPROM_BIST_ERROR1_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002068)
#define HWIO_QFPROM_BIST_ERROR1_PHYS                                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002068)
#define HWIO_QFPROM_BIST_ERROR1_OFFS                                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002068)
#define HWIO_QFPROM_BIST_ERROR1_RMSK                                                            0xffffffff
#define HWIO_QFPROM_BIST_ERROR1_IN          \
        in_dword(HWIO_QFPROM_BIST_ERROR1_ADDR)
#define HWIO_QFPROM_BIST_ERROR1_INM(m)      \
        in_dword_masked(HWIO_QFPROM_BIST_ERROR1_ADDR, m)
#define HWIO_QFPROM_BIST_ERROR1_ERROR_BMSK                                                      0xffffffff
#define HWIO_QFPROM_BIST_ERROR1_ERROR_SHFT                                                             0x0
#define HWIO_QFPROM_BIST_ERROR1_ERROR_NO_ERROR_FVAL                                                    0x0
#define HWIO_QFPROM_BIST_ERROR1_ERROR_ERROR_FVAL                                                       0x1

#define HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000206c + 0x4 * (n))
#define HWIO_QFPROM_HASH_SIGNATUREn_PHYS(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000206c + 0x4 * (n))
#define HWIO_QFPROM_HASH_SIGNATUREn_OFFS(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000206c + 0x4 * (n))
#define HWIO_QFPROM_HASH_SIGNATUREn_RMSK                                                        0xffffffff
#define HWIO_QFPROM_HASH_SIGNATUREn_MAXn                                                                 7
#define HWIO_QFPROM_HASH_SIGNATUREn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n), HWIO_QFPROM_HASH_SIGNATUREn_RMSK)
#define HWIO_QFPROM_HASH_SIGNATUREn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_HASH_SIGNATUREn_ADDR(n), mask)
#define HWIO_QFPROM_HASH_SIGNATUREn_HASH_VALUE_BMSK                                             0xffffffff
#define HWIO_QFPROM_HASH_SIGNATUREn_HASH_VALUE_SHFT                                                    0x0

#define HWIO_HW_KEY_STATUS_ADDR                                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000208c)
#define HWIO_HW_KEY_STATUS_PHYS                                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000208c)
#define HWIO_HW_KEY_STATUS_OFFS                                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000208c)
#define HWIO_HW_KEY_STATUS_RMSK                                                                      0x7ff
#define HWIO_HW_KEY_STATUS_IN          \
        in_dword(HWIO_HW_KEY_STATUS_ADDR)
#define HWIO_HW_KEY_STATUS_INM(m)      \
        in_dword_masked(HWIO_HW_KEY_STATUS_ADDR, m)
#define HWIO_HW_KEY_STATUS_MSA_SECURE_BMSK                                                           0x400
#define HWIO_HW_KEY_STATUS_MSA_SECURE_SHFT                                                             0xa
#define HWIO_HW_KEY_STATUS_MSA_SECURE_MSA_NOT_SECURE_FVAL                                              0x0
#define HWIO_HW_KEY_STATUS_MSA_SECURE_MSA_SECURE_FVAL                                                  0x1
#define HWIO_HW_KEY_STATUS_APPS_SECURE_BMSK                                                          0x200
#define HWIO_HW_KEY_STATUS_APPS_SECURE_SHFT                                                            0x9
#define HWIO_HW_KEY_STATUS_APPS_SECURE_APPS_NOT_SECURE_FVAL                                            0x0
#define HWIO_HW_KEY_STATUS_APPS_SECURE_APPS_SECURE_FVAL                                                0x1
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_BMSK                                            0x100
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_SHFT                                              0x8
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_KDF_AND_HW_KEY_SHIFT_IN_PROGRESS_FVAL             0x0
#define HWIO_HW_KEY_STATUS_KDF_AND_HW_KEY_SHIFT_DONE_KDF_AND_HW_KEY_SHIFT_HAS_COMPLETED_FVAL           0x1
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_BMSK                                                     0x80
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_SHFT                                                      0x7
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_HW_KEY_SHIFT_IN_PROGRESS_FVAL                             0x0
#define HWIO_HW_KEY_STATUS_HW_KEY_SHIFT_DONE_HW_KEY_SHIFT_HAS_COMPLETED_FVAL                           0x1
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_BMSK                                                       0x40
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_SHFT                                                        0x6
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_FUSE_SENSE_IN_PROGRESS_FVAL                                 0x0
#define HWIO_HW_KEY_STATUS_FUSE_SENSE_DONE_FUSE_SENSE_HAS_COMPLETED_FVAL                               0x1
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_BMSK                                                      0x20
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_SHFT                                                       0x5
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_CRI_CM_BOOT_IN_PROGRESS_FVAL                               0x0
#define HWIO_HW_KEY_STATUS_CRI_CM_BOOT_DONE_CRI_CM_BOOT_HAS_COMPLETED_FVAL                             0x1
#define HWIO_HW_KEY_STATUS_KDF_DONE_BMSK                                                              0x10
#define HWIO_HW_KEY_STATUS_KDF_DONE_SHFT                                                               0x4
#define HWIO_HW_KEY_STATUS_KDF_DONE_KDF_OPERATION_IN_PROGRESS_FVAL                                     0x0
#define HWIO_HW_KEY_STATUS_KDF_DONE_KDF_OPERATION_HAS_COMPLETED_FVAL                                   0x1
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_BMSK                                                       0x8
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_SHFT                                                       0x3
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_NOT_BLOCKED_FVAL                                           0x0
#define HWIO_HW_KEY_STATUS_MSA_KEYS_BLOCKED_BLOCKED_FVAL                                               0x1
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_BMSK                                                      0x4
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_SHFT                                                      0x2
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_NOT_BLOCKED_FVAL                                          0x0
#define HWIO_HW_KEY_STATUS_APPS_KEYS_BLOCKED_BLOCKED_FVAL                                              0x1
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_BMSK                                           0x2
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_SHFT                                           0x1
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_NOT_BLOWN_FVAL                                 0x0
#define HWIO_HW_KEY_STATUS_SEC_KEY_DERIVATION_KEY_BLOWN_BLOWN_FVAL                                     0x1
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_BMSK                                           0x1
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_SHFT                                           0x0
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_NOT_BLOWN_FVAL                                 0x0
#define HWIO_HW_KEY_STATUS_PRI_KEY_DERIVATION_KEY_BLOWN_BLOWN_FVAL                                     0x1

#define HWIO_RESET_JDR_STATUS_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002090)
#define HWIO_RESET_JDR_STATUS_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002090)
#define HWIO_RESET_JDR_STATUS_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002090)
#define HWIO_RESET_JDR_STATUS_RMSK                                                                     0x3
#define HWIO_RESET_JDR_STATUS_IN          \
        in_dword(HWIO_RESET_JDR_STATUS_ADDR)
#define HWIO_RESET_JDR_STATUS_INM(m)      \
        in_dword_masked(HWIO_RESET_JDR_STATUS_ADDR, m)
#define HWIO_RESET_JDR_STATUS_FORCE_RESET_BMSK                                                         0x2
#define HWIO_RESET_JDR_STATUS_FORCE_RESET_SHFT                                                         0x1
#define HWIO_RESET_JDR_STATUS_DISABLE_SYSTEM_RESET_BMSK                                                0x1
#define HWIO_RESET_JDR_STATUS_DISABLE_SYSTEM_RESET_SHFT                                                0x0

#define HWIO_ATPG_JDR_STATUS_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002094)
#define HWIO_ATPG_JDR_STATUS_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002094)
#define HWIO_ATPG_JDR_STATUS_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002094)
#define HWIO_ATPG_JDR_STATUS_RMSK                                                                      0x1
#define HWIO_ATPG_JDR_STATUS_IN          \
        in_dword(HWIO_ATPG_JDR_STATUS_ADDR)
#define HWIO_ATPG_JDR_STATUS_INM(m)      \
        in_dword_masked(HWIO_ATPG_JDR_STATUS_ADDR, m)
#define HWIO_ATPG_JDR_STATUS_FUSE_SENSE_ATPG_CTL_BMSK                                                  0x1
#define HWIO_ATPG_JDR_STATUS_FUSE_SENSE_ATPG_CTL_SHFT                                                  0x0

#define HWIO_FEAT_PROV_OUTn_ADDR(n)                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002098 + 0x4 * (n))
#define HWIO_FEAT_PROV_OUTn_PHYS(n)                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002098 + 0x4 * (n))
#define HWIO_FEAT_PROV_OUTn_OFFS(n)                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002098 + 0x4 * (n))
#define HWIO_FEAT_PROV_OUTn_RMSK                                                                0xffffffff
#define HWIO_FEAT_PROV_OUTn_MAXn                                                                         3
#define HWIO_FEAT_PROV_OUTn_INI(n)        \
        in_dword_masked(HWIO_FEAT_PROV_OUTn_ADDR(n), HWIO_FEAT_PROV_OUTn_RMSK)
#define HWIO_FEAT_PROV_OUTn_INMI(n,mask)    \
        in_dword_masked(HWIO_FEAT_PROV_OUTn_ADDR(n), mask)
#define HWIO_FEAT_PROV_OUTn_FEAT_PROV_OUT_VALUE_BMSK                                            0xffffffff
#define HWIO_FEAT_PROV_OUTn_FEAT_PROV_OUT_VALUE_SHFT                                                   0x0

#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n)                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000020a8 + 0x4 * (n))
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_PHYS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000020a8 + 0x4 * (n))
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_OFFS(n)                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000020a8 + 0x4 * (n))
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_RMSK                                                  0xffffffff
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_MAXn                                                           3
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_INI(n)        \
        in_dword_masked(HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n), HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_RMSK)
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_INMI(n,mask)    \
        in_dword_masked(HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_ADDR(n), mask)
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_SEC_CTRL_MISC_CONFIG_STATUS_VALUE_BMSK                0xffffffff
#define HWIO_SEC_CTRL_MISC_CONFIG_STATUSn_SEC_CTRL_MISC_CONFIG_STATUS_VALUE_SHFT                       0x0

#define HWIO_DEBUG_FUSE_STATUS_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x000020f0)
#define HWIO_DEBUG_FUSE_STATUS_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000020f0)
#define HWIO_DEBUG_FUSE_STATUS_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000020f0)
#define HWIO_DEBUG_FUSE_STATUS_RMSK                                                             0xffffffff
#define HWIO_DEBUG_FUSE_STATUS_IN          \
        in_dword(HWIO_DEBUG_FUSE_STATUS_ADDR)
#define HWIO_DEBUG_FUSE_STATUS_INM(m)      \
        in_dword_masked(HWIO_DEBUG_FUSE_STATUS_ADDR, m)
#define HWIO_DEBUG_FUSE_STATUS_RSVD0_BMSK                                                       0xff000000
#define HWIO_DEBUG_FUSE_STATUS_RSVD0_SHFT                                                             0x18
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC5_DEBUG_BMSK                                            0x800000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC5_DEBUG_SHFT                                                0x17
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC4_DEBUG_BMSK                                            0x400000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC4_DEBUG_SHFT                                                0x16
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC3_DEBUG_BMSK                                            0x200000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC3_DEBUG_SHFT                                                0x15
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC2_DEBUG_BMSK                                            0x100000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC2_DEBUG_SHFT                                                0x14
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC1_DEBUG_BMSK                                             0x80000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC1_DEBUG_SHFT                                                0x13
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC_DEBUG_BMSK                                              0x40000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MISC_DEBUG_SHFT                                                 0x12
#define HWIO_DEBUG_FUSE_STATUS_APPS_NIDEN_BMSK                                                     0x20000
#define HWIO_DEBUG_FUSE_STATUS_APPS_NIDEN_SHFT                                                        0x11
#define HWIO_DEBUG_FUSE_STATUS_APPS_DBGEN_BMSK                                                     0x10000
#define HWIO_DEBUG_FUSE_STATUS_APPS_DBGEN_SHFT                                                        0x10
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_QSEE_SPNIDEN_BMSK                                            0x8000
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_QSEE_SPNIDEN_SHFT                                               0xf
#define HWIO_DEBUG_FUSE_STATUS_SHARED_QSEE_SPNIDEN_BMSK                                             0x4000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_QSEE_SPNIDEN_SHFT                                                0xe
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_MSS_NIDEN_BMSK                                               0x2000
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_MSS_NIDEN_SHFT                                                  0xd
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MSS_NIDEN_BMSK                                                0x1000
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MSS_NIDEN_SHFT                                                   0xc
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_CP_NIDEN_BMSK                                                 0x800
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_CP_NIDEN_SHFT                                                   0xb
#define HWIO_DEBUG_FUSE_STATUS_SHARED_CP_NIDEN_BMSK                                                  0x400
#define HWIO_DEBUG_FUSE_STATUS_SHARED_CP_NIDEN_SHFT                                                    0xa
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_NS_NIDEN_BMSK                                                 0x200
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_NS_NIDEN_SHFT                                                   0x9
#define HWIO_DEBUG_FUSE_STATUS_SHARED_NS_NIDEN_BMSK                                                  0x100
#define HWIO_DEBUG_FUSE_STATUS_SHARED_NS_NIDEN_SHFT                                                    0x8
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_QSEE_SPIDEN_BMSK                                               0x80
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_QSEE_SPIDEN_SHFT                                                0x7
#define HWIO_DEBUG_FUSE_STATUS_SHARED_QSEE_SPIDEN_BMSK                                                0x40
#define HWIO_DEBUG_FUSE_STATUS_SHARED_QSEE_SPIDEN_SHFT                                                 0x6
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_MSS_DBGEN_BMSK                                                 0x20
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_MSS_DBGEN_SHFT                                                  0x5
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MSS_DBGEN_BMSK                                                  0x10
#define HWIO_DEBUG_FUSE_STATUS_SHARED_MSS_DBGEN_SHFT                                                   0x4
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_CP_DBGEN_BMSK                                                   0x8
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_CP_DBGEN_SHFT                                                   0x3
#define HWIO_DEBUG_FUSE_STATUS_SHARED_CP_DBGEN_BMSK                                                    0x4
#define HWIO_DEBUG_FUSE_STATUS_SHARED_CP_DBGEN_SHFT                                                    0x2
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_NS_DBGEN_BMSK                                                   0x2
#define HWIO_DEBUG_FUSE_STATUS_PRIVATE_NS_DBGEN_SHFT                                                   0x1
#define HWIO_DEBUG_FUSE_STATUS_SHARED_NS_DBGEN_BMSK                                                    0x1
#define HWIO_DEBUG_FUSE_STATUS_SHARED_NS_DBGEN_SHFT                                                    0x0

#define HWIO_HW_ATTESTATION_CTRL0_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002100)
#define HWIO_HW_ATTESTATION_CTRL0_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002100)
#define HWIO_HW_ATTESTATION_CTRL0_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002100)
#define HWIO_HW_ATTESTATION_CTRL0_RMSK                                                          0x1fffffff
#define HWIO_HW_ATTESTATION_CTRL0_IN          \
        in_dword(HWIO_HW_ATTESTATION_CTRL0_ADDR)
#define HWIO_HW_ATTESTATION_CTRL0_INM(m)      \
        in_dword_masked(HWIO_HW_ATTESTATION_CTRL0_ADDR, m)
#define HWIO_HW_ATTESTATION_CTRL0_OUT(v)      \
        out_dword(HWIO_HW_ATTESTATION_CTRL0_ADDR,v)
#define HWIO_HW_ATTESTATION_CTRL0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_HW_ATTESTATION_CTRL0_ADDR,m,v,HWIO_HW_ATTESTATION_CTRL0_IN)
#define HWIO_HW_ATTESTATION_CTRL0_REGION_BMSK                                                   0x1f800000
#define HWIO_HW_ATTESTATION_CTRL0_REGION_SHFT                                                         0x17
#define HWIO_HW_ATTESTATION_CTRL0_CONTEXT_STRING_BMSK                                             0x7fff80
#define HWIO_HW_ATTESTATION_CTRL0_CONTEXT_STRING_SHFT                                                  0x7
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_BMSK                                                     0x78
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_SHFT                                                      0x3
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_PKDK_FVAL                                                 0x0
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_SKDK_FVAL                                                 0x1
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_RTL_TEST_KEY_FVAL                                         0x2
#define HWIO_HW_ATTESTATION_CTRL0_KEY_SELECT_RTL_COMMERCIAL_KEY_FVAL                                   0x3
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_BMSK                                                       0x7
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_SHFT                                                       0x0
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_DEFAULT_FVAL                                               0x0
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_KEY_GEN_FVAL                                               0x1
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_START_FVAL                                                 0x2
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_UPDATE_FVAL                                                0x3
#define HWIO_HW_ATTESTATION_CTRL0_OPERATION_FINAL_FVAL                                                 0x4

#define HWIO_HW_ATTESTATION_CTRL1_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002104)
#define HWIO_HW_ATTESTATION_CTRL1_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002104)
#define HWIO_HW_ATTESTATION_CTRL1_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002104)
#define HWIO_HW_ATTESTATION_CTRL1_RMSK                                                          0xffffffff
#define HWIO_HW_ATTESTATION_CTRL1_IN          \
        in_dword(HWIO_HW_ATTESTATION_CTRL1_ADDR)
#define HWIO_HW_ATTESTATION_CTRL1_INM(m)      \
        in_dword_masked(HWIO_HW_ATTESTATION_CTRL1_ADDR, m)
#define HWIO_HW_ATTESTATION_CTRL1_OUT(v)      \
        out_dword(HWIO_HW_ATTESTATION_CTRL1_ADDR,v)
#define HWIO_HW_ATTESTATION_CTRL1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_HW_ATTESTATION_CTRL1_ADDR,m,v,HWIO_HW_ATTESTATION_CTRL1_IN)
#define HWIO_HW_ATTESTATION_CTRL1_NONCE_BMSK                                                    0xffffffff
#define HWIO_HW_ATTESTATION_CTRL1_NONCE_SHFT                                                           0x0

#define HWIO_HW_ATTESTATION_CMD_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002108)
#define HWIO_HW_ATTESTATION_CMD_PHYS                                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002108)
#define HWIO_HW_ATTESTATION_CMD_OFFS                                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002108)
#define HWIO_HW_ATTESTATION_CMD_RMSK                                                                   0x1
#define HWIO_HW_ATTESTATION_CMD_OUT(v)      \
        out_dword(HWIO_HW_ATTESTATION_CMD_ADDR,v)
#define HWIO_HW_ATTESTATION_CMD_OPERATION_COMMAND_BMSK                                                 0x1
#define HWIO_HW_ATTESTATION_CMD_OPERATION_COMMAND_SHFT                                                 0x0

#define HWIO_HW_ATTESTATION_STATUS_ADDR                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000210c)
#define HWIO_HW_ATTESTATION_STATUS_PHYS                                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000210c)
#define HWIO_HW_ATTESTATION_STATUS_OFFS                                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000210c)
#define HWIO_HW_ATTESTATION_STATUS_RMSK                                                         0xffffffff
#define HWIO_HW_ATTESTATION_STATUS_IN          \
        in_dword(HWIO_HW_ATTESTATION_STATUS_ADDR)
#define HWIO_HW_ATTESTATION_STATUS_INM(m)      \
        in_dword_masked(HWIO_HW_ATTESTATION_STATUS_ADDR, m)
#define HWIO_HW_ATTESTATION_STATUS_STATUS_BMSK                                                  0xffffffff
#define HWIO_HW_ATTESTATION_STATUS_STATUS_SHFT                                                         0x0
#define HWIO_HW_ATTESTATION_STATUS_STATUS_HW_ATTEST_DERIVED_KEY_READY_FVAL                             0x0
#define HWIO_HW_ATTESTATION_STATUS_STATUS_HW_ATTEST_MAC_VALUE_READY_FVAL                               0x1

#define HWIO_HW_ATTESTATION_ERROR_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002110)
#define HWIO_HW_ATTESTATION_ERROR_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002110)
#define HWIO_HW_ATTESTATION_ERROR_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002110)
#define HWIO_HW_ATTESTATION_ERROR_RMSK                                                          0xffffffff
#define HWIO_HW_ATTESTATION_ERROR_IN          \
        in_dword(HWIO_HW_ATTESTATION_ERROR_ADDR)
#define HWIO_HW_ATTESTATION_ERROR_INM(m)      \
        in_dword_masked(HWIO_HW_ATTESTATION_ERROR_ADDR, m)
#define HWIO_HW_ATTESTATION_ERROR_ERROR_BMSK                                                    0xffffffff
#define HWIO_HW_ATTESTATION_ERROR_ERROR_SHFT                                                           0x0
#define HWIO_HW_ATTESTATION_ERROR_ERROR_REGION_OUTSIDE_VALID_RANGE_FVAL                                0x0

#define HWIO_HW_ATTESTATION_RESULTn_ADDR(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00002120 + 0x4 * (n))
#define HWIO_HW_ATTESTATION_RESULTn_PHYS(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00002120 + 0x4 * (n))
#define HWIO_HW_ATTESTATION_RESULTn_OFFS(n)                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00002120 + 0x4 * (n))
#define HWIO_HW_ATTESTATION_RESULTn_RMSK                                                        0xffffffff
#define HWIO_HW_ATTESTATION_RESULTn_MAXn                                                                 7
#define HWIO_HW_ATTESTATION_RESULTn_INI(n)        \
        in_dword_masked(HWIO_HW_ATTESTATION_RESULTn_ADDR(n), HWIO_HW_ATTESTATION_RESULTn_RMSK)
#define HWIO_HW_ATTESTATION_RESULTn_INMI(n,mask)    \
        in_dword_masked(HWIO_HW_ATTESTATION_RESULTn_ADDR(n), mask)
#define HWIO_HW_ATTESTATION_RESULTn_RESULT_BMSK                                                 0xffffffff
#define HWIO_HW_ATTESTATION_RESULTn_RESULT_SHFT                                                        0x0

#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n)                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004000 + 0x4 * (n))
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_PHYS(n)                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004000 + 0x4 * (n))
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_OFFS(n)                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004000 + 0x4 * (n))
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_MAXn                                                           71
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n), HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_RMSK)
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_ADDR(n), mask)
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_BMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_CRI_CM_PRIVATEn_CRI_CM_PRIVATE_SHFT                                           0x0

#define HWIO_QFPROM_CORR_LCM_ROW_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004120)
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004120)
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004120)
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_LCM_ROW_LSB_ADDR)
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_LCM_ROW_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_LCM_BMSK                                           0x80000000
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_LCM_SHFT                                                 0x1f
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_LCM_STATE_TRANSITION_BMSK                          0x40000000
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_LCM_STATE_TRANSITION_SHFT                                0x1e
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_SECURE_PHK_BMSK                                    0x20000000
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_DISABLE_SECURE_PHK_SHFT                                          0x1d
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_RSVD_BMSK                                                  0x1fffffe0
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_RSVD_SHFT                                                         0x5
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_EXTERNAL_BMSK                                                 0x10
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_EXTERNAL_SHFT                                                  0x4
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_INTERNAL_BMSK                                                  0x8
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_INTERNAL_SHFT                                                  0x3
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_FEAT_CONFIG_BMSK                                               0x4
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_QC_FEAT_CONFIG_SHFT                                               0x2
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_HW_TEST_BMSK                                                      0x2
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_HW_TEST_SHFT                                                      0x1
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_SOC_PERSO_BMSK                                                    0x1
#define HWIO_QFPROM_CORR_LCM_ROW_LSB_SOC_PERSO_SHFT                                                    0x0

#define HWIO_QFPROM_CORR_LCM_ROW_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004124)
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004124)
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004124)
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_LCM_ROW_MSB_ADDR)
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_LCM_ROW_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_RSVD_BMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_LCM_ROW_MSB_RSVD_SHFT                                                         0x0

#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n)                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004128 + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_PHYS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004128 + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_OFFS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004128 + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_RMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_MAXn                                                   1
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_RSVD_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_LSB_RSVD_SHFT                                            0x0

#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n)                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000412c + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_PHYS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000412c + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_OFFS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000412c + 0x8 * (n))
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_RMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_MAXn                                                   1
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_RSVD_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_BOOT_PATCH_HASH_ROWn_MSB_RSVD_SHFT                                            0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004138 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_PHYS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004138 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_OFFS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004138 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                   0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                            3
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                         0xffffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                0x0

#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000413c + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_PHYS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000413c + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_OFFS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000413c + 0x8 * (n))
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                     0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                            3
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                           0xffffff
#define HWIO_QFPROM_CORR_PRI_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004158)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004158)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004158)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_RMSK                                           0x7fffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_BMSK                   0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_SHFT                         0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_BMSK                             0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_SHFT                                   0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                      0x1fe00000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                            0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                       0x180000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                           0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_DEFAULT_FVAL                    0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_1024_FVAL                  0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2048_FVAL                  0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2560_FVAL                  0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_BMSK                     0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_SHFT                        0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_BMSK                     0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_SHFT                        0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_BMSK                              0x10000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_SHFT                                 0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_BMSK                              0x8000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_SHFT                                 0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_ENABLE_FVAL                          0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_DISABLE_FVAL                         0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_BMSK                              0x4000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_SHFT                                 0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_ENABLE_FVAL                          0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_DISABLE_FVAL                         0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_BMSK                                    0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_SHFT                                       0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                  0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                     0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                         0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                           0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                 0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                   0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_ENABLE_FVAL            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_DISABLE_FVAL           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                  0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                    0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_BMSK                                  0x100
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_SHFT                                    0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                      0x80
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                       0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                            0x40
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                             0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_BMSK                         0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_SHFT                          0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_BMSK                                   0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_SHFT                                    0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT0_FVAL                          0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT1_FVAL                          0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_BMSK                                     0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_SHFT                                     0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                           0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                           0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_ENABLE_PATCHING_FVAL           0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_DISABLE_PATCHING_FVAL          0x1

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000415c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000415c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000415c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_RMSK                                           0xe7fffff7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                         0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                               0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_SW_KEY_FVAL         0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_HW_KEY_FVAL         0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                         0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                               0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_SW_KEY_FVAL         0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_HW_KEY_FVAL         0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                               0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                     0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_BMSK                                0x4000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_SHFT                                     0x1a
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_BMSK             0x2000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                  0x19
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_ENABLE_FVAL            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_DISABLE_FVAL           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_BMSK                 0x1000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_SHFT                      0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_BMSK                 0x800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_SHFT                     0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                           0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                               0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_BMSK                      0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_SHFT                          0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_BMSK                                   0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_SHFT                                       0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_BMSK                               0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_SHFT                                  0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                            0x7c000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                         0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                            0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_BMSK                            0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_SHFT                               0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANA_FEAT_SET_FVAL                 0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANAQ_FEAT_SET_FVAL                0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                     0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                       0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_BMSK                            0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_SHFT                              0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                   0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                     0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                    0x1e0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                      0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                          0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                           0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_BMSK                                   0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_SHFT                                   0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_BMSK                                   0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_SHFT                                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_BMSK                                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_SHFT                                   0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_DISABLE_FVAL                           0x1

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004160)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004160)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004160)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_BMSK                0xffffc000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_SHFT                       0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_BMSK                      0x3c00
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_SHFT                         0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                    0x3ff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                      0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_DISABLE_FVAL              0x1

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004164)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004164)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004164)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_BMSK                       0xc0000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_SHFT                             0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_BMSK             0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_SHFT                   0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_BMSK                 0x10000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_SHFT                       0x1c
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_MOBILE_FVAL                 0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_AUTOMOTIVE_FVAL             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_BMSK                       0x8000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_SHFT                            0x1b
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_MOBILE_FVAL                      0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_AUTOMOTIVE_FVAL                  0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_BMSK                               0x4000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_SHFT                                    0x1a
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_BMSK                     0x2000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_SHFT                          0x19
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_BMSK                                0x1000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_SHFT                                     0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_BMSK                  0xffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_SHFT                       0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_DISABLE_FVAL               0x1

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004168)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004168)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004168)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_RMSK                                           0xfbffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_BMSK            0x80000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_SHFT                  0x1f
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_BMSK                    0x40000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_SHFT                          0x1e
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_BMSK                             0x20000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_SHFT                                   0x1d
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_BMSK                                0x10000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_SHFT                                      0x1c
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_BMSK                                 0x8000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_SHFT                                      0x1b
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_BMSK              0x2000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_SHFT                   0x19
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_BMSK              0x1000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_SHFT                   0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_BMSK               0x800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_SHFT                   0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_BMSK               0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_SHFT                   0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_BMSK               0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_SHFT                   0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_BMSK                0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_SHFT                    0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                        0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                           0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                        0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                           0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_BMSK                   0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_SHFT                      0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_BMSK                   0x10000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_SHFT                      0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_BMSK                    0x8000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_SHFT                       0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_BMSK                    0x4000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_SHFT                       0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_BMSK                   0x2000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_SHFT                      0xd
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_BMSK                   0x1000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_SHFT                      0xc
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                 0x800
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                   0xb
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL            0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL           0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_BMSK                  0x400
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_SHFT                    0xa
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL             0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_BMSK                       0x200
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_SHFT                         0x9
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_BMSK                       0x100
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_SHFT                         0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_BMSK                        0x80
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_SHFT                         0x7
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_BMSK                        0x40
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_SHFT                         0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_BMSK                       0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_SHFT                        0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_BMSK                       0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_SHFT                        0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_BMSK                     0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_SHFT                     0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL              0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_BMSK                      0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_SHFT                      0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                  0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                  0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_ENABLE_FVAL                           0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_DISABLE_FVAL                          0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                      0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                      0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_DISABLE_FVAL                              0x1

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000416c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000416c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000416c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_BMSK                      0xff000000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_SHFT                            0x18
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_BMSK                        0x800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_SHFT                            0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_BMSK                         0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_SHFT                             0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_BMSK                    0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_SHFT                        0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                          0x1f8000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                               0xf
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                        0x4000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                           0xe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                       0x3fc0
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                          0x6
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_BMSK                  0x20
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_SHFT                   0x5
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_BMSK                  0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_SHFT                   0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_BMSK                   0x8
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_SHFT                   0x3
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_BMSK                   0x4
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_SHFT                   0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_BMSK                   0x2
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_SHFT                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_BMSK                   0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_SHFT                   0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004170)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004170)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004170)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_RMSK                                           0x7fffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_BMSK                 0x7f800000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_SHFT                       0x17
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_BMSK                      0x400000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_SHFT                          0x16
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_BMSK                      0x200000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_SHFT                          0x15
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_BMSK                      0x100000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_SHFT                          0x14
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_BMSK                       0x80000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_SHFT                          0x13
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_BMSK                       0x40000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_SHFT                          0x12
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_BMSK                       0x20000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_SHFT                          0x11
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_BMSK                       0x10000
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_SHFT                          0x10
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_BMSK                         0xffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_SHFT                            0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004174)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004174)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004174)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_RSVD_BMSK                                      0xfffffffe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_RSVD_SHFT                                             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_BMSK                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_SHFT                            0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004178)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004178)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004178)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_RSVD_BMSK                                      0xfffffffe
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_RSVD_SHFT                                             0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_LEGACY_MBNV6_OVERRIDE_BMSK                            0x1
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_LSB_LEGACY_MBNV6_OVERRIDE_SHFT                            0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000417c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000417c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000417c)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_RSVD_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW4_MSB_RSVD_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004180)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004180)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004180)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_RSVD_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_LSB_RSVD_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_ADDR                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004184)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_PHYS                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004184)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_OFFS                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004184)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_ADDR)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_RSVD_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_CM_FEAT_CONFIG_ROW5_MSB_RSVD_SHFT                                             0x0

#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004188)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_PHYS                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004188)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_OFFS                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004188)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_RSVD0_BMSK                                            0xfffffff0
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_RSVD0_SHFT                                                   0x4
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_ROOT_CERT_ACTIVATION_LIST_BMSK                               0xf
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_LSB_ROOT_CERT_ACTIVATION_LIST_SHFT                               0x0

#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000418c)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_PHYS                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000418c)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_OFFS                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000418c)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_RSVD1_BMSK                                            0xfffffffe
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_RSVD1_SHFT                                                   0x1
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_CURRENT_UIE_KEY_SEL_BMSK                                     0x1
#define HWIO_QFPROM_CORR_MRC_2_0_ROW0_MSB_CURRENT_UIE_KEY_SEL_SHFT                                     0x0

#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004190)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_PHYS                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004190)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_OFFS                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004190)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_RSVD0_BMSK                                            0xfffffff0
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_RSVD0_SHFT                                                   0x4
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_ROOT_CERT_REVOCATION_LIST_BMSK                               0xf
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_LSB_ROOT_CERT_REVOCATION_LIST_SHFT                               0x0

#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_ADDR                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004194)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_PHYS                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004194)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_OFFS                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004194)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_RMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_RSVD0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_MRC_2_0_ROW1_MSB_RSVD0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004198)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004198)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004198)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_RSVD0_BMSK                                                0xe0000000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_RSVD0_SHFT                                                      0x1d
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_MACCHIATO_EN_BMSK                                         0x10000000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_MACCHIATO_EN_SHFT                                               0x1c
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_FEATURE_ID_BMSK                                            0xff00000
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_FEATURE_ID_SHFT                                                 0x14
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_JTAG_ID_BMSK                                                 0xfffff
#define HWIO_QFPROM_CORR_PTE_ROW0_LSB_JTAG_ID_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000419c)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000419c)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000419c)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW0_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a0)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041a0)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041a0)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_PTE_DATA0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_LSB_PTE_DATA0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a4)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041a4)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041a4)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW1_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041a8)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041a8)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041a8)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_PTE_DATA0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_LSB_PTE_DATA0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041ac)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041ac)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041ac)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW2_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b0)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041b0)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041b0)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_PTE_DATA0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_LSB_PTE_DATA0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b4)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041b4)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041b4)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW3_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041b8)
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041b8)
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041b8)
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_PTE_DATA0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW4_LSB_PTE_DATA0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041bc)
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041bc)
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041bc)
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW4_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c0)
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041c0)
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041c0)
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW5_LSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_PTE_DATA0_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW5_LSB_PTE_DATA0_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_ADDR                                                      (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c4)
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_PHYS                                                      (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041c4)
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_OFFS                                                      (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041c4)
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_RMSK                                                      0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_PTE_ROW5_MSB_ADDR)
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_PTE_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_PTE_DATA1_BMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_PTE_ROW5_MSB_PTE_DATA1_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041c8)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041c8)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041c8)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG31_BMSK                                       0x80000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG31_SHFT                                             0x1f
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG31_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG31_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_BMSK                                       0x40000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_SHFT                                             0x1e
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG30_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_BMSK                                       0x20000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_SHFT                                             0x1d
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG29_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_BMSK                                       0x10000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_SHFT                                             0x1c
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SPARE_REG28_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_USER_DATA_KEY_BMSK                                          0x8000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_USER_DATA_KEY_SHFT                                               0x1b
#define HWIO_QFPROM_CORR_RD_PERM_LSB_USER_DATA_KEY_ALLOW_READ_FVAL                                     0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_USER_DATA_KEY_DISABLE_READ_FVAL                                   0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                        0x4000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                             0x1a
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_IMAGE_ENCR_KEY1_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_BMSK                                         0x2000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_SHFT                                              0x19
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_ROM_PATCH_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                 0x1000000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                      0x18
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_ALLOW_READ_FVAL                            0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_SEC_KEY_DERIVATION_KEY_DISABLE_READ_FVAL                          0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_BMSK                                            0x800000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_SHFT                                                0x17
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_ALLOW_READ_FVAL                                      0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_SEC_BOOT_DISABLE_READ_FVAL                                    0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                      0x400000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                          0x16
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_ALLOW_READ_FVAL                                0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_IMAGE_ENCR_KEY_DISABLE_READ_FVAL                              0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG21_BMSK                                          0x200000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG21_SHFT                                              0x15
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG21_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG21_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG20_BMSK                                          0x100000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG20_SHFT                                              0x14
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG20_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_QC_SPARE_REG20_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_BMSK                                               0x80000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_SHFT                                                  0x13
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_ALLOW_READ_FVAL                                        0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MEM_CONFIG_DISABLE_READ_FVAL                                      0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_BMSK                                                    0x40000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_SHFT                                                       0x12
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_ALLOW_READ_FVAL                                             0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CALIB_DISABLE_READ_FVAL                                           0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_BMSK                                                 0x20000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_SHFT                                                    0x11
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_ALLOW_READ_FVAL                                          0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PK_HASH0_DISABLE_READ_FVAL                                        0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_5_BMSK                                          0x10000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_5_SHFT                                             0x10
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_5_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_5_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                           0x8000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                              0xf
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_4_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                           0x4000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                              0xe
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_3_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                           0x2000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                              0xd
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_2_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                           0x1000
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                              0xc
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_ANTI_ROLLBACK_1_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_BMSK                                                0x800
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_SHFT                                                  0xb
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_ALLOW_READ_FVAL                                       0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEAT_CONFIG_DISABLE_READ_FVAL                                     0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_BMSK                                                 0x400
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_SHFT                                                   0xa
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_ALLOW_READ_FVAL                                        0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_OEM_CONFIG_DISABLE_READ_FVAL                                      0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_BMSK                                                     0x200
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_SHFT                                                       0x9
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_ALLOW_READ_FVAL                                            0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_FEC_EN_DISABLE_READ_FVAL                                          0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_BMSK                                                    0x100
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_SHFT                                                      0x8
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_ALLOW_READ_FVAL                                           0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_WR_PERM_DISABLE_READ_FVAL                                         0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_BMSK                                                     0x80
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_SHFT                                                      0x7
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_ALLOW_READ_FVAL                                           0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_RD_PERM_DISABLE_READ_FVAL                                         0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_BMSK                                                         0x40
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_SHFT                                                          0x6
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_ALLOW_READ_FVAL                                               0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PTE_DISABLE_READ_FVAL                                             0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MRC_2_0_BMSK                                                     0x20
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MRC_2_0_SHFT                                                      0x5
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MRC_2_0_ALLOW_READ_FVAL                                           0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_MRC_2_0_DISABLE_READ_FVAL                                         0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_BMSK                                              0x10
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_SHFT                                               0x4
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CM_FEAT_CONFIG_DISABLE_READ_FVAL                                  0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                       0x8
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                       0x3
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_ALLOW_READ_FVAL                            0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_PRI_KEY_DERIVATION_KEY_DISABLE_READ_FVAL                          0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_PATCH_HASH_BMSK                                              0x4
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_PATCH_HASH_SHFT                                              0x2
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_PATCH_HASH_ALLOW_READ_FVAL                                   0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_BOOT_PATCH_HASH_DISABLE_READ_FVAL                                 0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_LCM_BMSK                                                          0x2
#define HWIO_QFPROM_CORR_RD_PERM_LSB_LCM_SHFT                                                          0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_LCM_ALLOW_READ_FVAL                                               0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_LCM_DISABLE_READ_FVAL                                             0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_BMSK                                               0x1
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_SHFT                                               0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_ALLOW_READ_FVAL                                    0x0
#define HWIO_QFPROM_CORR_RD_PERM_LSB_CRI_CM_PRIVATE_DISABLE_READ_FVAL                                  0x1

#define HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041cc)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041cc)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041cc)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_RD_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RSVD0_BMSK                                                 0xffffffff
#define HWIO_QFPROM_CORR_RD_PERM_MSB_RSVD0_SHFT                                                        0x0

#define HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041d0)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041d0)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041d0)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG31_BMSK                                       0x80000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG31_SHFT                                             0x1f
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG31_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG31_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_BMSK                                       0x40000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_SHFT                                             0x1e
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG30_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_BMSK                                       0x20000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_SHFT                                             0x1d
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG29_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_BMSK                                       0x10000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_SHFT                                             0x1c
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SPARE_REG28_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_USER_DATA_KEY_BMSK                                          0x8000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_USER_DATA_KEY_SHFT                                               0x1b
#define HWIO_QFPROM_CORR_WR_PERM_LSB_USER_DATA_KEY_ALLOW_WRITE_FVAL                                    0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_USER_DATA_KEY_DISABLE_WRITE_FVAL                                  0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_BMSK                                        0x4000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_SHFT                                             0x1a
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_IMAGE_ENCR_KEY1_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_BMSK                                         0x2000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_SHFT                                              0x19
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_ROM_PATCH_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_BMSK                                 0x1000000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_SHFT                                      0x18
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_ALLOW_WRITE_FVAL                           0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_SEC_KEY_DERIVATION_KEY_DISABLE_WRITE_FVAL                         0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_BMSK                                            0x800000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_SHFT                                                0x17
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_ALLOW_WRITE_FVAL                                     0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_SEC_BOOT_DISABLE_WRITE_FVAL                                   0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_BMSK                                      0x400000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_SHFT                                          0x16
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_ALLOW_WRITE_FVAL                               0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_IMAGE_ENCR_KEY_DISABLE_WRITE_FVAL                             0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG21_BMSK                                          0x200000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG21_SHFT                                              0x15
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG21_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG21_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG20_BMSK                                          0x100000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG20_SHFT                                              0x14
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG20_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_QC_SPARE_REG20_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_BMSK                                               0x80000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_SHFT                                                  0x13
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_ALLOW_WRITE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MEM_CONFIG_DISABLE_WRITE_FVAL                                     0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_BMSK                                                    0x40000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_SHFT                                                       0x12
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_ALLOW_WRITE_FVAL                                            0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CALIB_DISABLE_WRITE_FVAL                                          0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_BMSK                                                 0x20000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_SHFT                                                    0x11
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_ALLOW_WRITE_FVAL                                         0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PK_HASH0_DISABLE_WRITE_FVAL                                       0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_5_BMSK                                          0x10000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_5_SHFT                                             0x10
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_5_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_5_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_BMSK                                           0x8000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_SHFT                                              0xf
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_4_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_BMSK                                           0x4000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_SHFT                                              0xe
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_3_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_BMSK                                           0x2000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_SHFT                                              0xd
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_2_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_BMSK                                           0x1000
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_SHFT                                              0xc
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_ANTI_ROLLBACK_1_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_BMSK                                                 0x800
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_SHFT                                                   0xb
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_ALLOW_WRITE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_OEM_CONFIG_DISABLE_WRITE_FVAL                                     0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_BMSK                                                0x400
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_SHFT                                                  0xa
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_ALLOW_WRITE_FVAL                                      0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEAT_CONFIG_DISABLE_WRITE_FVAL                                    0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_BMSK                                                     0x200
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_SHFT                                                       0x9
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_ALLOW_WRITE_FVAL                                           0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_FEC_EN_DISABLE_WRITE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_BMSK                                                    0x100
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_SHFT                                                      0x8
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_ALLOW_WRITE_FVAL                                          0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_WR_PERM_DISABLE_WRITE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_BMSK                                                     0x80
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_SHFT                                                      0x7
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_ALLOW_WRITE_FVAL                                          0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_RD_PERM_DISABLE_WRITE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_BMSK                                                         0x40
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_SHFT                                                          0x6
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_ALLOW_WRITE_FVAL                                              0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PTE_DISABLE_WRITE_FVAL                                            0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MRC_2_0_BMSK                                                     0x20
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MRC_2_0_SHFT                                                      0x5
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MRC_2_0_ALLOW_WRITE_FVAL                                          0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_MRC_2_0_DISABLE_WRITE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_BMSK                                              0x10
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_SHFT                                               0x4
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CM_FEAT_CONFIG_DISABLE_WRITE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_BMSK                                       0x8
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_SHFT                                       0x3
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_ALLOW_WRITE_FVAL                           0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_PRI_KEY_DERIVATION_KEY_DISABLE_WRITE_FVAL                         0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_PATCH_HASH_BMSK                                              0x4
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_PATCH_HASH_SHFT                                              0x2
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_PATCH_HASH_ALLOW_WRITE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_BOOT_PATCH_HASH_DISABLE_WRITE_FVAL                                0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_LCM_BMSK                                                          0x2
#define HWIO_QFPROM_CORR_WR_PERM_LSB_LCM_SHFT                                                          0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_LCM_ALLOW_WRITE_FVAL                                              0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_LCM_DISABLE_WRITE_FVAL                                            0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_BMSK                                               0x1
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_SHFT                                               0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_ALLOW_WRITE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_WR_PERM_LSB_CRI_CM_PRIVATE_DISABLE_WRITE_FVAL                                 0x1

#define HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041d4)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_PHYS                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041d4)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_OFFS                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041d4)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RMSK                                                       0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_WR_PERM_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RSVD0_BMSK                                                 0xffffffff
#define HWIO_QFPROM_CORR_WR_PERM_MSB_RSVD0_SHFT                                                        0x0

#define HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041d8)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041d8)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041d8)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION31_FEC_EN_BMSK                                        0x80000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION31_FEC_EN_SHFT                                              0x1f
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION31_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION31_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_BMSK                                        0x40000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_SHFT                                              0x1e
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION30_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_BMSK                                        0x20000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_SHFT                                              0x1d
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION29_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_BMSK                                        0x10000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_SHFT                                              0x1c
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION28_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_BMSK                                         0x8000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_SHFT                                              0x1b
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION27_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_BMSK                                         0x4000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_SHFT                                              0x1a
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION26_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_BMSK                                         0x2000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_SHFT                                              0x19
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION25_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_BMSK                                         0x1000000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_SHFT                                              0x18
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION24_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_BMSK                                          0x800000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_SHFT                                              0x17
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION23_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_BMSK                                          0x400000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_SHFT                                              0x16
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION22_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_BMSK                                          0x200000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_SHFT                                              0x15
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION21_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_BMSK                                          0x100000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_SHFT                                              0x14
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION20_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_BMSK                                           0x80000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_SHFT                                              0x13
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION19_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_BMSK                                           0x40000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_SHFT                                              0x12
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION18_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_BMSK                                           0x20000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_SHFT                                              0x11
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION17_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_BMSK                                           0x10000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_SHFT                                              0x10
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION16_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_BMSK                                            0x8000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_SHFT                                               0xf
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION15_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_BMSK                                            0x4000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_SHFT                                               0xe
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION14_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_BMSK                                            0x2000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_SHFT                                               0xd
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION13_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_BMSK                                            0x1000
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_SHFT                                               0xc
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION12_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_BMSK                                             0x800
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_SHFT                                               0xb
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION11_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_BMSK                                             0x400
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_SHFT                                               0xa
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_DISABLE_FVAL                                       0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION10_FEC_EN_ENABLE_FVAL                                        0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_BMSK                                              0x200
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_SHFT                                                0x9
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION9_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_BMSK                                              0x100
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_SHFT                                                0x8
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION8_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_BMSK                                               0x80
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_SHFT                                                0x7
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION7_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_BMSK                                               0x40
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_SHFT                                                0x6
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION6_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_BMSK                                               0x20
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_SHFT                                                0x5
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION5_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_BMSK                                               0x10
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_SHFT                                                0x4
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION4_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_BMSK                                                0x8
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_SHFT                                                0x3
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION3_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_BMSK                                                0x4
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_SHFT                                                0x2
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION2_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_BMSK                                                0x2
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_SHFT                                                0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION1_FEC_EN_ENABLE_FVAL                                         0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_BMSK                                                0x1
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_SHFT                                                0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_DISABLE_FVAL                                        0x0
#define HWIO_QFPROM_CORR_FEC_EN_LSB_REGION0_FEC_EN_ENABLE_FVAL                                         0x1

#define HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041dc)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_PHYS                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041dc)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_OFFS                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041dc)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RMSK                                                        0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RSVD0_BMSK                                                  0xffffffff
#define HWIO_QFPROM_CORR_FEC_EN_MSB_RSVD0_SHFT                                                         0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041e0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041e0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041e0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_OUT(v)      \
        out_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR,v)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR,m,v,HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IN)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                   0x80000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                         0x1f
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_BMSK                    0x40000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_SHFT                          0x1e
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_BMSK                             0x20000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_SHFT                                   0x1d
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ALL_DEBUG_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_BMSK                          0x10000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_SHFT                                0x1c
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_ENABLE_FVAL                          0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_POLICY_DISABLE_DISABLE_FVAL                         0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SP_DISABLE_BMSK                                     0x8000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SP_DISABLE_SHFT                                          0x1b
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SP_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SP_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_BMSK                                    0x4000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_SHFT                                         0x1a
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_UDK_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_DISABLE_IN_ROM_BMSK                           0x2000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DEBUG_DISABLE_IN_ROM_SHFT                                0x19
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_BMSK                0x1000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_SHFT                     0x18
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_DISABLE_FVAL              0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_MSS_HASH_INTEGRITY_CHECK_ENABLE_ENABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK               0x800000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                   0x17
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_DISABLE_FVAL            0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_APPS_HASH_INTEGRITY_CHECK_DISABLE_ENABLE_FVAL             0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_BMSK                                  0x400000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_SHFT                                      0x16
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_USB_SS_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_BMSK                           0x200000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_SHFT                               0x15
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_USE_OEM_ID_FVAL                     0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_ROT_USE_SERIAL_NUM_USE_SERIAL_NUM_FVAL                 0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_BMSK                            0x100000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_SHFT                                0x14
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_ENABLE_FVAL                          0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_DISABLE_ROT_TRANSFER_DISABLE_FVAL                         0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_BMSK                          0x80000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_IMAGE_ENCRYPTION_ENABLE_SHFT                             0x13
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ROOT_CERT_TOTAL_NUM_BMSK                              0x60000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ROOT_CERT_TOTAL_NUM_SHFT                                 0x11
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_BMSK                           0x10000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_USB_TYPE_C_DISABLE_SHFT                              0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_BMSK                                   0x8000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_LOG_DISABLE_SHFT                                      0xf
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_BMSK                                           0x4000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_SHFT                                              0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_USE_GPIO_FVAL                                     0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_WDOG_EN_IGNORE_GPIO_ENABLE_WDOG_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_BMSK              0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_SHFT                 0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_DISABLE_EDL_RESET_FVAL        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_ENABLE_EDL_RESET_FVAL        0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_BMSK                              0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SW_FUSE_PROG_DISABLE_SHFT                                 0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SPI_CLK_BOOT_FREQ_BMSK                                  0x800
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SPI_CLK_BOOT_FREQ_SHFT                                    0xb
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_BMSK                          0x400
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_SHFT                            0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_SD_USB_FVAL                     0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_PBL_QSPI_BOOT_EDL_ENABLED_QSPI_SD_USB_FVAL                0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_BMSK                                          0x3e0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SHFT                                            0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_DEFAULT_FVAL                                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SD_UFS_EDL_FVAL                                 0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SD_EDL_FVAL                                     0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_USB_EDL_FVAL                                    0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_QSPI_EDL_FVAL                                   0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_SPI_EDL_FVAL                                    0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FAST_BOOT_UGSG4_SD_USB_EDL_FVAL                           0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_BMSK                                 0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_SHFT                                  0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_ENUM_19_2_MHZ_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_SDCC_MCLK_BOOT_FREQ_ENUM_25_MHZ_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_BMSK                               0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_SHFT                               0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_USB_BOOT_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL        0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_BMSK                                  0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_SHFT                                  0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_FORCE_DLOAD_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL        0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_BMSK                                         0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_SHFT                                         0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_TIMEOUT_DISABLED_FVAL                        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ENUM_TIMEOUT_TIMEOUT_ENABLED_90S_FVAL                     0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_BMSK                                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_SHFT                                      0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_DOWNLOADER_ENABLED_FVAL                   0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_E_DLOAD_DISABLE_DOWNLOADER_DISABLED_FVAL                  0x1

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041e4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041e4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041e4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD1_BMSK                                         0xffffc000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_RSVD1_SHFT                                                0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_BMSK                        0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_SHFT                           0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_BMSK                        0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_SHFT                           0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_BMSK                         0x800
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_SHFT                           0xb
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_BMSK                         0x400
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_SHFT                           0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_BMSK                         0x200
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_SHFT                           0x9
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_BMSK                          0x100
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_SHFT                            0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_BMSK                                  0x80
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_SHFT                                   0x7
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_NIDEN_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_BMSK                                  0x40
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_SHFT                                   0x6
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_ENABLE_FVAL                            0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_APPS_DBGEN_DISABLE_DISABLE_FVAL                           0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_BMSK                             0x20
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_SHFT                              0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_BMSK                             0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_SHFT                              0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_BMSK                              0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_SHFT                              0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_BMSK                              0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_SHFT                              0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_BMSK                             0x2
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_SHFT                             0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_BMSK                             0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_SHFT                             0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW0_MSB_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                     0x1

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041e8)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041e8)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041e8)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_DISABLE_RSA_BMSK                                   0x80000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_DISABLE_RSA_SHFT                                         0x1f
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_EKU_ENFORCEMENT_EN_BMSK                            0x40000000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_EKU_ENFORCEMENT_EN_SHFT                                  0x1e
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD2_BMSK                                         0x3fff0000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD2_SHFT                                               0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_BMSK                                0x8000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_SHFT                                   0xf
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_NOT_SECURE_FVAL                        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG31_SECURE_SECURE_FVAL                            0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_BMSK                                0x4000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_SHFT                                   0xe
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_NOT_SECURE_FVAL                        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG30_SECURE_SECURE_FVAL                            0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_BMSK                                0x2000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_SHFT                                   0xd
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_NOT_SECURE_FVAL                        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG29_SECURE_SECURE_FVAL                            0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_BMSK                                0x1000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_SHFT                                   0xc
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_NOT_SECURE_FVAL                        0x0
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPARE_REG28_SECURE_SECURE_FVAL                            0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD3_BMSK                                              0x800
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD3_SHFT                                                0xb
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPU_IAR_ENABLED_BMSK                                    0x400
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SPU_IAR_ENABLED_SHFT                                      0xa
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD1_BMSK                                              0x300
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD1_SHFT                                                0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_OVERRIDE_BMSK                          0x80
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_OVERRIDE_SHFT                           0x7
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_FIPS_OVERRIDE_BMSK                                    0x40
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_FIPS_OVERRIDE_SHFT                                     0x6
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_MODEM_CRYPTO_FIPS_ENABLE_BMSK                            0x20
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_MODEM_CRYPTO_FIPS_ENABLE_SHFT                             0x5
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_ENABLE_BMSK                            0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_TZ_SW_CRYPTO_FIPS_ENABLE_SHFT                             0x4
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_FIPS_ENABLE_BMSK                                       0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_FIPS_ENABLE_SHFT                                       0x3
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_NVM_AR_CONFIG_BMSK                                     0x6
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_SP_NVM_AR_CONFIG_SHFT                                     0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD0_BMSK                                                0x1
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_LSB_RSVD0_SHFT                                                0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041ec)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041ec)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041ec)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_BMSK                                0xffff0000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_PRODUCT_ID_SHFT                                      0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_BMSK                                         0xffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW1_MSB_OEM_HW_ID_SHFT                                            0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041f0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041f0)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_VID_BMSK                                    0xffff0000
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_VID_SHFT                                          0x10
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_PID_BMSK                                        0xffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_LSB_PERIPH_PID_SHFT                                           0x0

#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041f4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041f4)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RSVD0_BMSK                                         0xffffff00
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_RSVD0_SHFT                                                0x8
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_BMSK                            0xff
#define HWIO_QFPROM_CORR_OEM_CONFIG_ROW2_MSB_ANTI_ROLLBACK_FEATURE_EN_SHFT                             0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041f8)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041f8)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041f8)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_RMSK                                              0x7fffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_BMSK                      0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_SHFT                            0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_ENABLE_FVAL                      0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_TURING_Q6SS_HVX_DISABLE_DISABLE_FVAL                     0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_BMSK                                0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_SHFT                                      0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_QC_SP_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_BMSK                         0x1fe00000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_GFX3D_FREQ_LIMIT_VAL_SHFT                               0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_BMSK                          0x180000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_SHFT                              0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_DEFAULT_FVAL                       0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_1024_FVAL                     0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2048_FVAL                     0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDSS_RESOLUTION_LIMIT_ENUM_2560_FVAL                     0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_BMSK                        0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_SHFT                           0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_ENCODE_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_BMSK                        0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_SHFT                           0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_HEVC_DECODE_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_BMSK                                 0x10000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_SHFT                                    0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_4K_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_BMSK                                 0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_SHFT                                    0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_CVP_DISABLE_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_BMSK                                 0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_SHFT                                    0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_ENABLE_FVAL                             0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_IRIS_DISABLE_VPX_DISABLE_FVAL                            0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_BMSK                                       0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_SHFT                                          0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DP_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_BMSK                                     0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_SHFT                                        0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_BMSK                            0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_SHFT                              0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_MDP_APICAL_LTC_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                    0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                      0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_BMSK                                     0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_SHFT                                       0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_1_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_BMSK                                     0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_SHFT                                       0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_DSI_0_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_BMSK                                         0x80
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_SHFT                                          0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_FD_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_BMSK                               0x40
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_SHFT                                0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_ENABLE_FVAL                         0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_CSID_DPCM_14_DISABLE_DISABLE_FVAL                        0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_BMSK                            0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EFUSE_CAM_SBI_ENABLE_IF_SHFT                             0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_BMSK                                      0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_SHFT                                       0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT0_FVAL                             0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_PORT1_SEL_USB_PORT1_FVAL                             0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_BMSK                                        0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_EUD_IGNR_CSR_SHFT                                        0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_BMSK                              0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_SHFT                              0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_ENABLE_PATCHING_FVAL              0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_LSB_BOOT_ROM_PATCH_DISABLE_DISABLE_PATCHING_FVAL             0x1

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000041fc)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000041fc)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000041fc)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_RMSK                                              0xe7fffff7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_BMSK                            0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_SHFT                                  0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_SW_KEY_FVAL            0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_HW_KEY_FVAL            0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_BMSK                            0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_SHFT                                  0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_SW_KEY_FVAL            0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_HW_KEY_FVAL            0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_BMSK                                  0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_SHFT                                        0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_ICE_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_BMSK                                   0x4000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_SHFT                                        0x1a
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_BMSK                0x2000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                     0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_ISLAND_MODE_Q6_CLK_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_BMSK                    0x1000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_SHFT                         0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SSC_SW_ISLAND_MODE_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_BMSK                    0x800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_TCSR_SW_OVERRIDE_SOC_HW_VER_SHFT                        0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_BMSK                              0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_APS_RESET_DISABLE_SHFT                                  0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_BMSK                         0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_SHFT                             0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_IRIS_MULTIPIPE_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_BMSK                                      0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_DOLBY_BIT_SHFT                                          0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_BMSK                                  0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_SHFT                                     0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_QC_UDK_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_BMSK                               0x7c000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_STACKED_MEMORY_ID_SHFT                                   0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_BMSK                            0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_SHFT                               0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PRNG_TESTMODE_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_BMSK                               0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_SHFT                                  0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANA_FEAT_SET_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MDSS_Q_CONFIG_FUSE_HANAQ_FEAT_SET_FVAL                   0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_BMSK                                        0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_MOCHA_PART_SHFT                                          0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_BMSK                               0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_EFUSE_Q6SS_HVX_HALF_SHFT                                 0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_BMSK                                      0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_SHFT                                        0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_SMMU_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_BMSK                                       0x1e0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_VENDOR_LOCK_SHFT                                         0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_BMSK                             0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_SHFT                              0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_CM_FEAT_CONFIG_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_BMSK                                      0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_SHFT                                      0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_2_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_BMSK                                      0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_SHFT                                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_1_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_BMSK                                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_SHFT                                      0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW0_MSB_PCIE_0_DISABLE_DISABLE_FVAL                              0x1

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004200)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004200)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004200)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_BMSK                   0xffffc000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_SHFT                          0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_HARD_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_BMSK                         0x3c00
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_SHFT                            0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_IU_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_BMSK                       0x3ff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_SHFT                         0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_LSB_MODEM_FEATURE_DISABLE_SPARE_DISABLE_FVAL                 0x1

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004204)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004204)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004204)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_BMSK                          0xc0000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_APSS_PDXWRPNTRDELAY_SHFT                                0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_BMSK                0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_SHFT                      0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_SEC_CTRL_GCC_NPU_FUSE_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_BMSK                    0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_SHFT                          0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_MOBILE_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_FUNCTIONAL_AUTOMOTIVE_FVAL                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_BMSK                          0x8000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_SHFT                               0x1b
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_MOBILE_FVAL                         0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_AUTOMOTIVE_BIT_POWER_AUTOMOTIVE_FVAL                     0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_BMSK                                  0x4000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_SHFT                                       0x1a
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_EMAC_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_BMSK                        0x2000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_SHFT                             0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_ENABLE_FVAL                       0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_TCM_BOOT_DISABLE_DISABLE_FVAL                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_BMSK                                   0x1000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_SHFT                                        0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_NAV_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_BMSK                     0xffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_SHFT                          0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW1_MSB_MODEM_FEATURE_DISABLE_SOFT_DISABLE_FVAL                  0x1

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004208)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004208)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004208)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_RMSK                                              0xfbffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_BMSK               0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_P2S_ACCU_RED_DEC_END_VAL_FUSE0_SHFT                     0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_BMSK                       0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_FUSE_CORTEX_M3_DISABLE_SHFT                             0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_BMSK                                0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_Q_CONFIG_FUSE_SHFT                                      0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_BMSK                                   0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_I_MC5_FUSE_SHFT                                         0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_BMSK                                    0x8000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_I_MC4_FUSE_SHFT                                         0x1b
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_BMSK                 0x2000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_SHFT                      0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_BMSK                 0x1000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_SHFT                      0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_BMSK                  0x800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_SHFT                      0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_BMSK                  0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_SHFT                      0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_BMSK                  0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_SHFT                      0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_BMSK                   0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_SHFT                       0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_BMSK                           0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_SHFT                              0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_NIDEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_BMSK                           0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_SHFT                              0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_ENABLE_FVAL                        0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_APPS_DBGEN_DISABLE_DISABLE_FVAL                       0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_BMSK                      0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_SHFT                         0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_BMSK                      0x10000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_SHFT                         0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_BMSK                       0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_SHFT                          0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_BMSK                       0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_SHFT                          0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                   0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                  0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_BMSK                      0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_SHFT                         0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_BMSK                      0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_SHFT                         0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                    0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                      0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_BMSK                     0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_SHFT                       0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_QC_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_BMSK                          0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_SHFT                            0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_NIDEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_BMSK                          0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_SHFT                            0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_NS_DBGEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_BMSK                           0x80
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_SHFT                            0x7
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_NIDEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_BMSK                           0x40
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_SHFT                            0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_ENABLE_FVAL                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_CP_DBGEN_DISABLE_DISABLE_FVAL                    0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_BMSK                          0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_SHFT                           0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_NIDEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_BMSK                          0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_SHFT                           0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_MSS_DBGEN_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_BMSK                        0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_SHFT                        0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                 0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_BMSK                         0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_SHFT                         0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_PRIVATE_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                 0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_BMSK                                     0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_SHFT                                     0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_ENABLE_FVAL                              0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_SM_BIST_DISABLE_DISABLE_FVAL                             0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_BMSK                                         0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_SHFT                                         0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_LSB_TIC_DISABLE_DISABLE_FVAL                                 0x1

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000420c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000420c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000420c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_BMSK                         0xff000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_CFG_APC1PLL_LVAL_SHFT                               0x18
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_BMSK                           0x800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APSS_KRYO_PP_DISABLE_SHFT                               0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_BMSK                            0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_CFG_L3_SIZE_RED_SHFT                                0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_BMSK                       0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_AUTO_CCI_RCG_CFG_DISABLE_SHFT                           0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_BMSK                             0x1f8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_APPS_BOOT_FSM_FUSE_SHFT                                  0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_BMSK                           0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCSCFGAPMBOOTONMX_SHFT                              0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_BMSK                          0x3fc0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_SYS_APCCCFGCPUPRESENT_N_SHFT                             0x6
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_BMSK                     0x20
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE6_SHFT                      0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_BMSK                     0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE5_SHFT                      0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_BMSK                      0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE4_SHFT                      0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_BMSK                      0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE3_SHFT                      0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_BMSK                      0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE2_SHFT                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_BMSK                      0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW2_MSB_P2S_ACCU_RED_DEC_END_VAL_FUSE1_SHFT                      0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004210)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004210)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004210)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_RMSK                                              0x7fffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_BMSK                    0x7f800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_SYS_CFG_GOLDPLUS_PLL_LVAL_SHFT                          0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_BMSK                         0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_6_SHFT                             0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_BMSK                         0x200000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_5_SHFT                             0x15
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_BMSK                         0x100000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_4_SHFT                             0x14
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_BMSK                          0x80000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_3_SHFT                             0x13
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_BMSK                          0x40000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_2_SHFT                             0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_BMSK                          0x20000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_1_SHFT                             0x11
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_BMSK                          0x10000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_ACCU_RED_DEC_END_VAL_0_SHFT                             0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_BMSK                            0xffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_LSB_TURING_Q6SS_PLL_L_MAX_SHFT                               0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004214)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004214)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004214)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_RSVD_BMSK                                         0xfffffffe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_RSVD_SHFT                                                0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_BMSK                               0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW3_MSB_DISABLE_SEC_BOOT_GPIO_SHFT                               0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004218)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004218)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004218)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_LSB_RSVD_SHFT                                                0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000421c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000421c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000421c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RSVD_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW4_MSB_RSVD_SHFT                                                0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004220)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004220)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004220)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_RSVD_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_LSB_RSVD_SHFT                                                0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004224)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004224)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004224)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_RSVD_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW5_MSB_RSVD_SHFT                                                0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004228)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004228)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004228)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK             0xfffc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                   0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_TAP_INSTR_DISABLE_BMSK                               0x3ffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_LSB_TAP_INSTR_DISABLE_SHFT                                   0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000422c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000422c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000422c)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_SEC_TAP_ACCESS_DISABLE_BMSK                       0xfffc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_SEC_TAP_ACCESS_DISABLE_SHFT                             0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK               0x3ffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW6_MSB_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                   0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004230)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004230)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004230)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_PATCH_VERSION_BMSK                      0xfe000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_PATCH_VERSION_SHFT                            0x19
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_PATCH_VERSION_BMSK                        0x1fc0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_PATCH_VERSION_SHFT                             0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_BMSK                             0x30000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_SHFT                                0x10
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_ENUM_600_MHZ_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_XO_FVAL                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_ENUM_1200_MHZ_FVAL                   0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_PBL_BOOT_SPEED_NA_FVAL                              0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_BOOT_BMSK                                   0x8000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_MODEM_PBL_BOOT_SHFT                                      0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_RSVD1_56_14_BMSK                                      0x4000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_RSVD1_56_14_SHFT                                         0xe
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_BOOT_FROM_ROM_BMSK                               0x2000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_APPS_BOOT_FROM_ROM_SHFT                                  0xd
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ENABLE_DEVICE_IN_TEST_MODE_BMSK                       0x1000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ENABLE_DEVICE_IN_TEST_MODE_SHFT                          0xc
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_QTI_ROOT_SIG_FORMAT_SEL_BMSK                           0x800
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_QTI_ROOT_SIG_FORMAT_SEL_SHFT                             0xb
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_BMSK                                    0x400
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_SHFT                                      0xa
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_ENABLE_FVAL                               0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_CE_BAM_DISABLE_DISABLE_FVAL                              0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_BMSK                0x200
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_SHFT                  0x9
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ARM_CE_DISABLE_USAGE_BMSK                              0x100
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_ARM_CE_DISABLE_USAGE_SHFT                                0x8
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_BOOT_ROM_CFG_BMSK                                       0xff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_LSB_BOOT_ROM_CFG_SHFT                                        0x0

#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004234)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004234)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004234)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_RMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_ADDR)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_BMSK                    0x80000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_SHFT                          0x1f
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_ENABLE_FVAL                    0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_BOOT_TRIGGER_DISABLE_DISABLE_FVAL                   0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                   0x40000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                         0x1e
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_XBL_SEC_AUTH_DISABLE_BMSK                         0x20000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_XBL_SEC_AUTH_DISABLE_SHFT                               0x1d
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_MSM_PKG_TYPE_BMSK                                 0x10000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_MSM_PKG_TYPE_SHFT                                       0x1c
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_SPSS_CONFIG_MODE_BMSK                              0xc000000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_SPSS_CONFIG_MODE_SHFT                                   0x1a
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PERIPH_DRV_STRENGTH_SETTING_BMSK                   0x3800000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PERIPH_DRV_STRENGTH_SETTING_SHFT                        0x17
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_RSVD3_56_54_BMSK                                    0x400000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_RSVD3_56_54_SHFT                                        0x16
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_BMSK                                     0x3c0000
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SHFT                                         0x12
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_TSMC_FVAL                                     0x0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_GLOBAL_FOUNDRIES_FVAL                         0x1
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SAMSUNG_FVAL                                  0x2
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_IBM_FVAL                                      0x3
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_UMC_FVAL                                      0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_FOUNDRY_ID_SMIC_FVAL                                     0x5
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PLL_CFG_BMSK                                         0x3fff0
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_PLL_CFG_SHFT                                             0x4
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_PBL_PLL_CTRL_BMSK                                   0xf
#define HWIO_QFPROM_CORR_FEAT_CONFIG_ROW7_MSB_APPS_PBL_PLL_CTRL_SHFT                                   0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004238)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004238)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004238)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_XBL0_BMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_XBL0_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000423c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000423c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000423c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_XBL1_BMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_1_MSB_XBL1_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004240)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004240)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004240)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_BMSK                            0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_PIL_SUBSYSTEM_31_0_SHFT                                   0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004244)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004244)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004244)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_XBL_SEC_BMSK                                       0xfe000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_XBL_SEC_SHFT                                             0x19
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_AOP_BMSK                                            0x1fe0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_AOP_SHFT                                                 0x11
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_TZ_BMSK                                               0x1ffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_2_MSB_TZ_SHFT                                                   0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004248)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004248)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004248)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_XBL_CONFIG_1_0_BMSK                                0xc0000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_XBL_CONFIG_1_0_SHFT                                      0x1e
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_BMSK                               0x3e000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_TQS_HASH_ACTIVE_SHFT                                     0x19
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_BMSK                           0x1000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_SHFT                                0x18
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_RPMB_KEY_NOT_PROVISIONED_FVAL        0x0
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_RPMB_KEY_PROVISIONED_RPMB_KEY_PROVISIONED_FVAL            0x1
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_BMSK                             0xffff00
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_PIL_SUBSYSTEM_47_32_SHFT                                  0x8
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_SAFESWITCH_BMSK                                          0xff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_SAFESWITCH_SHFT                                           0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000424c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000424c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000424c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_XBL_CONFIG_5_2_BMSK                                0xf0000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_XBL_CONFIG_5_2_SHFT                                      0x1c
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_BMSK                                     0xffe0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEVICE_CFG_SHFT                                          0x11
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_BMSK                                     0x1f000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_DEBUG_POLICY_SHFT                                         0xc
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_HYPERVISOR_BMSK                                         0xfff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_3_MSB_HYPERVISOR_SHFT                                           0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004250)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004250)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004250)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MSS_BMSK                                           0xffff0000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MSS_SHFT                                                 0x10
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MISC_BMSK                                              0xffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_MISC_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004254)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004254)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004254)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_SIMLOCK_BMSK                                       0x80000000
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_SIMLOCK_SHFT                                             0x1f
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RSVD0_BMSK                                         0x7ffffff0
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_RSVD0_SHFT                                                0x4
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ROOT_CERT_PK_HASH_INDEX_BMSK                              0xf
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_4_MSB_ROOT_CERT_PK_HASH_INDEX_SHFT                              0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004258)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004258)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004258)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_MISC_BMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_MISC_SHFT                                                 0x0

#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_ADDR                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000425c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_PHYS                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000425c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_OFFS                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000425c)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_ADDR)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_RSVD0_BMSK                                         0xffffffff
#define HWIO_QFPROM_CORR_ANTI_ROLLBACK_5_MSB_RSVD0_SHFT                                                0x0

#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004260 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_PHYS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004260 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_OFFS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004260 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_MAXn                                                          5
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_HASH_DATA0_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_LSB_HASH_DATA0_SHFT                                             0x0

#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n)                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004264 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_PHYS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004264 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_OFFS(n)                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004264 + 0x8 * (n))
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_RMSK                                                 0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_MAXn                                                          5
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_HASH_DATA1_BMSK                                      0xffffffff
#define HWIO_QFPROM_CORR_PK_HASH0_ROWn_MSB_HASH_DATA1_SHFT                                             0x0

#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004290)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004290)
#define HWIO_QFPROM_CORR_CALIB_ROW0_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004290)
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
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004294)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004294)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW0_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW0_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004298)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004298)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004298)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW1_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW1_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000429c)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000429c)
#define HWIO_QFPROM_CORR_CALIB_ROW1_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000429c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042a0)
#define HWIO_QFPROM_CORR_CALIB_ROW2_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042a0)
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
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042a4)
#define HWIO_QFPROM_CORR_CALIB_ROW2_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042a4)
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
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042a8)
#define HWIO_QFPROM_CORR_CALIB_ROW3_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042a8)
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
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042ac)
#define HWIO_QFPROM_CORR_CALIB_ROW3_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042ac)
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
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042b0)
#define HWIO_QFPROM_CORR_CALIB_ROW4_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042b0)
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
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042b4)
#define HWIO_QFPROM_CORR_CALIB_ROW4_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042b4)
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
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042b8)
#define HWIO_QFPROM_CORR_CALIB_ROW5_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042b8)
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
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042bc)
#define HWIO_QFPROM_CORR_CALIB_ROW5_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042bc)
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
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042c0)
#define HWIO_QFPROM_CORR_CALIB_ROW6_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042c0)
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
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042c4)
#define HWIO_QFPROM_CORR_CALIB_ROW6_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042c4)
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
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042c8)
#define HWIO_QFPROM_CORR_CALIB_ROW7_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042c8)
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
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042cc)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042cc)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW7_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW7_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d0)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042d0)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042d0)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d4)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042d4)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042d4)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW8_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW8_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042d8)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042d8)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042d8)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_LSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042dc)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042dc)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042dc)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RMSK                                                    0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW9_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RSVD_BMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW9_MSB_RSVD_SHFT                                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e0)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042e0)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042e0)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e4)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042e4)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042e4)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW10_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW10_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042e8)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042e8)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042e8)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042ec)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042ec)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042ec)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW11_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW11_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f0)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042f0)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042f0)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f4)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042f4)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042f4)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW12_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW12_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000042f8)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042f8)
#define HWIO_QFPROM_CORR_CALIB_ROW13_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042f8)
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
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000042fc)
#define HWIO_QFPROM_CORR_CALIB_ROW13_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000042fc)
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
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004300)
#define HWIO_QFPROM_CORR_CALIB_ROW14_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004300)
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
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004304)
#define HWIO_QFPROM_CORR_CALIB_ROW14_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004304)
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
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004308)
#define HWIO_QFPROM_CORR_CALIB_ROW15_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004308)
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
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000430c)
#define HWIO_QFPROM_CORR_CALIB_ROW15_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000430c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004310)
#define HWIO_QFPROM_CORR_CALIB_ROW16_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004310)
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
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004314)
#define HWIO_QFPROM_CORR_CALIB_ROW16_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004314)
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
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004318)
#define HWIO_QFPROM_CORR_CALIB_ROW17_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004318)
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
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000431c)
#define HWIO_QFPROM_CORR_CALIB_ROW17_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000431c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004320)
#define HWIO_QFPROM_CORR_CALIB_ROW18_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004320)
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
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004324)
#define HWIO_QFPROM_CORR_CALIB_ROW18_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004324)
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
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004328)
#define HWIO_QFPROM_CORR_CALIB_ROW19_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004328)
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
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000432c)
#define HWIO_QFPROM_CORR_CALIB_ROW19_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000432c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004330)
#define HWIO_QFPROM_CORR_CALIB_ROW20_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004330)
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
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004334)
#define HWIO_QFPROM_CORR_CALIB_ROW20_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004334)
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
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004338)
#define HWIO_QFPROM_CORR_CALIB_ROW21_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004338)
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
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000433c)
#define HWIO_QFPROM_CORR_CALIB_ROW21_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000433c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004340)
#define HWIO_QFPROM_CORR_CALIB_ROW22_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004340)
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
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004344)
#define HWIO_QFPROM_CORR_CALIB_ROW22_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004344)
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
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004348)
#define HWIO_QFPROM_CORR_CALIB_ROW23_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004348)
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
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000434c)
#define HWIO_QFPROM_CORR_CALIB_ROW23_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000434c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004350)
#define HWIO_QFPROM_CORR_CALIB_ROW24_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004350)
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
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004354)
#define HWIO_QFPROM_CORR_CALIB_ROW24_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004354)
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
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004358)
#define HWIO_QFPROM_CORR_CALIB_ROW25_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004358)
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
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000435c)
#define HWIO_QFPROM_CORR_CALIB_ROW25_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000435c)
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
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004360)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004360)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW26_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW26_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR_RSVD_31_5_BMSK                                     0xffffffe0
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR_RSVD_31_5_SHFT                                            0x5
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR1_TARG_VOLT_SVSP_BMSK                                     0x1f
#define HWIO_QFPROM_CORR_CALIB_ROW26_LSB_CPR1_TARG_VOLT_SVSP_SHFT                                      0x0

#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004364)
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004364)
#define HWIO_QFPROM_CORR_CALIB_ROW26_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004364)
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
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004368)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004368)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW27_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW27_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000436c)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000436c)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000436c)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW27_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW27_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004370)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004370)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004370)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW28_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004374)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004374)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004374)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW28_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW28_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004378)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004378)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004378)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW29_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000437c)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000437c)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000437c)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW29_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW29_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004380)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004380)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004380)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW30_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_LSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004384)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_PHYS                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004384)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_OFFS                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004384)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RMSK                                                   0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_CALIB_ROW30_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RSVD_BMSK                                              0xffffffff
#define HWIO_QFPROM_CORR_CALIB_ROW30_MSB_RSVD_SHFT                                                     0x0

#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n)                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004388 + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_PHYS(n)                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004388 + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_OFFS(n)                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004388 + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_MAXn                                                       70
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_REDUN_DATA_BMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_LSB_REDUN_DATA_SHFT                                           0x0

#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n)                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000438c + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_PHYS(n)                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000438c + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_OFFS(n)                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000438c + 0x8 * (n))
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_RMSK                                               0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_MAXn                                                       70
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_REDUN_DATA_BMSK                                    0xffffffff
#define HWIO_QFPROM_CORR_MEM_CONFIG_ROWn_MSB_REDUN_DATA_SHFT                                           0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045c0)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045c0)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045c0)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_ADDR)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_QC_SPARE_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_LSB_QC_SPARE_SHFT                                              0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045c4)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045c4)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045c4)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_RMSK                                                  0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_ADDR)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_QC_SPARE_BMSK                                         0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG20_MSB_QC_SPARE_SHFT                                              0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045c8)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045c8)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045c8)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_ADDR)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_QC_SPARE_BMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_LSB_QC_SPARE_SHFT                                              0x0

#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_ADDR                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045cc)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_PHYS                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045cc)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_OFFS                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045cc)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_RMSK                                                  0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_ADDR)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_QC_SPARE_BMSK                                         0xffffff
#define HWIO_QFPROM_CORR_QC_SPARE_REG21_MSB_QC_SPARE_SHFT                                              0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n)                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045d0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_PHYS(n)                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045d0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_OFFS(n)                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045d0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_MAXn                                                1
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_BMSK                             0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_LSB_KEY_DATA0_SHFT                                    0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n)                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045d4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_PHYS(n)                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045d4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_OFFS(n)                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045d4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK                                         0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_MAXn                                                1
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_BMSK                               0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROWn_MSB_KEY_DATA1_SHFT                                    0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045e0)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_PHYS                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045e0)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_OFFS                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045e0)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RMSK                                       0xffffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_BMSK                                 0xffff0000
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_RSVD0_SHFT                                       0x10
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_BMSK                                 0xffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_LSB_KEY_DATA0_SHFT                                    0x0

#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045e4)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_PHYS                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045e4)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_OFFS                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045e4)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RMSK                                         0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_BMSK                                   0xffffff
#define HWIO_QFPROM_CORR_OEM_IMAGE_ENCR_KEY_ROW2_MSB_RSVD0_SHFT                                        0x0

#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045e8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_PHYS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045e8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_OFFS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045e8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_RMSK                                             0xffffffff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_MAXn                                                      1
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_BMSK                                   0xff000000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT4_SHFT                                         0x18
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_BMSK                                     0xff0000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT3_SHFT                                         0x10
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_BMSK                                       0xff00
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT2_SHFT                                          0x8
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_BMSK                                         0xff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_LSB_SEC_BOOT1_SHFT                                          0x0

#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n)                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045ec + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_PHYS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045ec + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_OFFS(n)                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045ec + 0x8 * (n))
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_RMSK                                               0xffffff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_MAXn                                                      1
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_BMSK                                     0xff0000
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT7_SHFT                                         0x10
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_BMSK                                       0xff00
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT6_SHFT                                          0x8
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_BMSK                                         0xff
#define HWIO_QFPROM_CORR_OEM_SEC_BOOT_ROWn_MSB_SEC_BOOT5_SHFT                                          0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n)                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_PHYS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_OFFS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK                                   0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_MAXn                                            3
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_BMSK                         0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_LSB_KEY_DATA0_SHFT                                0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n)                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000045fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_PHYS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000045fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_OFFS(n)                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000045fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK                                     0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_MAXn                                            3
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_BMSK                           0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROWn_MSB_KEY_DATA1_SHFT                                0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004618)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_PHYS                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004618)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_OFFS                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004618)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_RMSK                                   0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_BMSK                         0xffffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_LSB_KEY_DATA0_SHFT                                0x0

#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000461c)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_PHYS                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000461c)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_OFFS                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000461c)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RMSK                                     0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_BMSK                               0xffffff
#define HWIO_QFPROM_CORR_SEC_KEY_DERIVATION_KEY_ROW4_MSB_RSVD0_SHFT                                    0x0

#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004620 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_PHYS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004620 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_OFFS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004620 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_RMSK                                                0xffffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_MAXn                                                        55
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_PATCH_DATA_BMSK                                     0xffffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_LSB_PATCH_DATA_SHFT                                            0x0

#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n)                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004624 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PHYS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004624 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_OFFS(n)                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004624 + 0x8 * (n))
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RMSK                                                  0xffffff
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_MAXn                                                        55
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RSVD0_BMSK                                            0xfe0000
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_RSVD0_SHFT                                                0x11
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_ADDR_BMSK                                        0x1fffe
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_ADDR_SHFT                                            0x1
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_EN_BMSK                                              0x1
#define HWIO_QFPROM_CORR_ROM_PATCH_ROWn_MSB_PATCH_EN_SHFT                                              0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n)                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047e0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_PHYS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047e0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_OFFS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047e0 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_MAXn                                                   1
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_BMSK                                0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_LSB_KEY_DATA0_SHFT                                       0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n)                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047e4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_PHYS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047e4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_OFFS(n)                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047e4 + 0x8 * (n))
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK                                            0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_MAXn                                                   1
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_BMSK                                  0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROWn_MSB_KEY_DATA1_SHFT                                       0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047f0)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_PHYS                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047f0)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_OFFS                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047f0)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RMSK                                          0xffffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_BMSK                                    0xffff0000
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_RSVD0_SHFT                                          0x10
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_BMSK                                    0xffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_LSB_KEY_DATA0_SHFT                                       0x0

#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047f4)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_PHYS                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047f4)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_OFFS                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047f4)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RMSK                                            0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_BMSK                                      0xffffff
#define HWIO_QFPROM_CORR_IMAGE_ENCR_KEY1_ROW2_MSB_RSVD0_SHFT                                           0x0

#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047f8 + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_MAXn                                                     3
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_ADDR(n), HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_RMSK)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_USER_DATA_KEY_BMSK                              0xffffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_LSB_USER_DATA_KEY_SHFT                                     0x0

#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_ADDR(n)                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x000047fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_PHYS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000047fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_OFFS(n)                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000047fc + 0x8 * (n))
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_RMSK                                              0xffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_MAXn                                                     3
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_ADDR(n), HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_RMSK)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_USER_DATA_KEY_BMSK                                0xffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROWn_MSB_USER_DATA_KEY_SHFT                                     0x0

#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004818)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004818)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004818)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_RMSK                                            0xffffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_IN          \
        in_dword(HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_ADDR)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_ADDR, m)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_USER_DATA_KEY_BMSK                              0xffffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_LSB_USER_DATA_KEY_SHFT                                     0x0

#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_ADDR                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000481c)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_PHYS                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000481c)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_OFFS                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000481c)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_RMSK                                              0xffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_IN          \
        in_dword(HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_ADDR)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_ADDR, m)
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_RSVD0_BMSK                                        0xffffff
#define HWIO_QFPROM_CORR_USER_DATA_KEY_ROW4_MSB_RSVD0_SHFT                                             0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004660 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004660 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004660 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_MAXn                                                   31
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_LSB_OEM_SPARE_SHFT                                        0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004664 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004664 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004664 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_MAXn                                                   31
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW0_MSB_OEM_SPARE_SHFT                                        0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00004668 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00004668 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00004668 + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_MAXn                                                   31
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_LSB_OEM_SPARE_SHFT                                        0x0

#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n)                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000466c + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_PHYS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000466c + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_OFFS(n)                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000466c + 0x10 * (n))
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_RMSK                                           0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_MAXn                                                   31
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_INI(n)        \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_RMSK)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_INMI(n,mask)    \
        in_dword_masked(HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_ADDR(n), mask)
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_BMSK                                 0xffffffff
#define HWIO_QFPROM_CORR_OEM_SPARE_REGn_ROW1_MSB_OEM_SPARE_SHFT                                        0x0

#define HWIO_SEC_CTRL_HW_VERSION_ADDR                                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006000)
#define HWIO_SEC_CTRL_HW_VERSION_PHYS                                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006000)
#define HWIO_SEC_CTRL_HW_VERSION_OFFS                                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006000)
#define HWIO_SEC_CTRL_HW_VERSION_RMSK                                                           0xffffffff
#define HWIO_SEC_CTRL_HW_VERSION_IN          \
        in_dword(HWIO_SEC_CTRL_HW_VERSION_ADDR)
#define HWIO_SEC_CTRL_HW_VERSION_INM(m)      \
        in_dword_masked(HWIO_SEC_CTRL_HW_VERSION_ADDR, m)
#define HWIO_SEC_CTRL_HW_VERSION_MAJOR_BMSK                                                     0xf0000000
#define HWIO_SEC_CTRL_HW_VERSION_MAJOR_SHFT                                                           0x1c
#define HWIO_SEC_CTRL_HW_VERSION_MINOR_BMSK                                                      0xfff0000
#define HWIO_SEC_CTRL_HW_VERSION_MINOR_SHFT                                                           0x10
#define HWIO_SEC_CTRL_HW_VERSION_STEP_BMSK                                                          0xffff
#define HWIO_SEC_CTRL_HW_VERSION_STEP_SHFT                                                             0x0

#define HWIO_FEATURE_CONFIG0_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006004)
#define HWIO_FEATURE_CONFIG0_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006004)
#define HWIO_FEATURE_CONFIG0_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006004)
#define HWIO_FEATURE_CONFIG0_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG0_IN          \
        in_dword(HWIO_FEATURE_CONFIG0_ADDR)
#define HWIO_FEATURE_CONFIG0_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG0_ADDR, m)
#define HWIO_FEATURE_CONFIG0_RSVD1_BMSK                                                         0x80000000
#define HWIO_FEATURE_CONFIG0_RSVD1_SHFT                                                               0x1f
#define HWIO_FEATURE_CONFIG0_TURING_Q6SS_HVX_DISABLE_BMSK                                       0x40000000
#define HWIO_FEATURE_CONFIG0_TURING_Q6SS_HVX_DISABLE_SHFT                                             0x1e
#define HWIO_FEATURE_CONFIG0_TURING_Q6SS_HVX_DISABLE_ENABLE_FVAL                                       0x0
#define HWIO_FEATURE_CONFIG0_TURING_Q6SS_HVX_DISABLE_DISABLE_FVAL                                      0x1
#define HWIO_FEATURE_CONFIG0_QC_SP_DISABLE_BMSK                                                 0x20000000
#define HWIO_FEATURE_CONFIG0_QC_SP_DISABLE_SHFT                                                       0x1d
#define HWIO_FEATURE_CONFIG0_QC_SP_DISABLE_ENABLE_FVAL                                                 0x0
#define HWIO_FEATURE_CONFIG0_QC_SP_DISABLE_DISABLE_FVAL                                                0x1
#define HWIO_FEATURE_CONFIG0_GFX3D_FREQ_LIMIT_VAL_BMSK                                          0x1fe00000
#define HWIO_FEATURE_CONFIG0_GFX3D_FREQ_LIMIT_VAL_SHFT                                                0x15
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_BMSK                                           0x180000
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_SHFT                                               0x13
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_DEFAULT_FVAL                                        0x0
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_ENUM_1024_FVAL                                      0x1
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_ENUM_2048_FVAL                                      0x2
#define HWIO_FEATURE_CONFIG0_MDSS_RESOLUTION_LIMIT_ENUM_2560_FVAL                                      0x3
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_ENCODE_DISABLE_BMSK                                         0x40000
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_ENCODE_DISABLE_SHFT                                            0x12
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_ENCODE_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_ENCODE_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_DECODE_DISABLE_BMSK                                         0x20000
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_DECODE_DISABLE_SHFT                                            0x11
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_DECODE_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG0_IRIS_HEVC_DECODE_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG0_IRIS_4K_DISABLE_BMSK                                                  0x10000
#define HWIO_FEATURE_CONFIG0_IRIS_4K_DISABLE_SHFT                                                     0x10
#define HWIO_FEATURE_CONFIG0_IRIS_4K_DISABLE_ENABLE_FVAL                                               0x0
#define HWIO_FEATURE_CONFIG0_IRIS_4K_DISABLE_DISABLE_FVAL                                              0x1
#define HWIO_FEATURE_CONFIG0_IRIS_CVP_DISABLE_BMSK                                                  0x8000
#define HWIO_FEATURE_CONFIG0_IRIS_CVP_DISABLE_SHFT                                                     0xf
#define HWIO_FEATURE_CONFIG0_IRIS_CVP_DISABLE_ENABLE_FVAL                                              0x0
#define HWIO_FEATURE_CONFIG0_IRIS_CVP_DISABLE_DISABLE_FVAL                                             0x1
#define HWIO_FEATURE_CONFIG0_IRIS_DISABLE_VPX_BMSK                                                  0x4000
#define HWIO_FEATURE_CONFIG0_IRIS_DISABLE_VPX_SHFT                                                     0xe
#define HWIO_FEATURE_CONFIG0_IRIS_DISABLE_VPX_ENABLE_FVAL                                              0x0
#define HWIO_FEATURE_CONFIG0_IRIS_DISABLE_VPX_DISABLE_FVAL                                             0x1
#define HWIO_FEATURE_CONFIG0_DP_DISABLE_BMSK                                                        0x2000
#define HWIO_FEATURE_CONFIG0_DP_DISABLE_SHFT                                                           0xd
#define HWIO_FEATURE_CONFIG0_DP_DISABLE_ENABLE_FVAL                                                    0x0
#define HWIO_FEATURE_CONFIG0_DP_DISABLE_DISABLE_FVAL                                                   0x1
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_BMSK                                                      0x1000
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_SHFT                                                         0xc
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_ENABLE_FVAL                                                  0x0
#define HWIO_FEATURE_CONFIG0_HDCP_DISABLE_DISABLE_FVAL                                                 0x1
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_BMSK                                             0x800
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_SHFT                                               0xb
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_FEATURE_CONFIG0_MDP_APICAL_LTC_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_BMSK                                     0x400
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_SHFT                                       0xa
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_FEATURE_CONFIG0_HDCP_GLOBAL_KEY_SPLIT2_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_BMSK                                                      0x200
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_SHFT                                                        0x9
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_ENABLE_FVAL                                                 0x0
#define HWIO_FEATURE_CONFIG0_DSI_1_DISABLE_DISABLE_FVAL                                                0x1
#define HWIO_FEATURE_CONFIG0_DSI_0_DISABLE_BMSK                                                      0x100
#define HWIO_FEATURE_CONFIG0_DSI_0_DISABLE_SHFT                                                        0x8
#define HWIO_FEATURE_CONFIG0_DSI_0_DISABLE_ENABLE_FVAL                                                 0x0
#define HWIO_FEATURE_CONFIG0_DSI_0_DISABLE_DISABLE_FVAL                                                0x1
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_BMSK                                                          0x80
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_SHFT                                                           0x7
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_ENABLE_FVAL                                                    0x0
#define HWIO_FEATURE_CONFIG0_FD_DISABLE_DISABLE_FVAL                                                   0x1
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_BMSK                                                0x40
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_SHFT                                                 0x6
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_ENABLE_FVAL                                          0x0
#define HWIO_FEATURE_CONFIG0_CSID_DPCM_14_DISABLE_DISABLE_FVAL                                         0x1
#define HWIO_FEATURE_CONFIG0_EFUSE_CAM_SBI_ENABLE_IF_BMSK                                             0x20
#define HWIO_FEATURE_CONFIG0_EFUSE_CAM_SBI_ENABLE_IF_SHFT                                              0x5
#define HWIO_FEATURE_CONFIG0_EUD_PORT1_SEL_BMSK                                                       0x10
#define HWIO_FEATURE_CONFIG0_EUD_PORT1_SEL_SHFT                                                        0x4
#define HWIO_FEATURE_CONFIG0_EUD_PORT1_SEL_USB_PORT0_FVAL                                              0x0
#define HWIO_FEATURE_CONFIG0_EUD_PORT1_SEL_USB_PORT1_FVAL                                              0x1
#define HWIO_FEATURE_CONFIG0_EUD_IGNR_CSR_BMSK                                                         0x8
#define HWIO_FEATURE_CONFIG0_EUD_IGNR_CSR_SHFT                                                         0x3
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_BMSK                                               0x7
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_SHFT                                               0x0
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_ENABLE_PATCHING_FVAL                               0x0
#define HWIO_FEATURE_CONFIG0_BOOT_ROM_PATCH_DISABLE_DISABLE_PATCHING_FVAL                              0x1

#define HWIO_FEATURE_CONFIG1_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006008)
#define HWIO_FEATURE_CONFIG1_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006008)
#define HWIO_FEATURE_CONFIG1_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006008)
#define HWIO_FEATURE_CONFIG1_RMSK                                                               0xe7fffff7
#define HWIO_FEATURE_CONFIG1_IN          \
        in_dword(HWIO_FEATURE_CONFIG1_ADDR)
#define HWIO_FEATURE_CONFIG1_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG1_ADDR, m)
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_BMSK                                             0x80000000
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_SHFT                                                   0x1f
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_SW_KEY_FVAL                             0x0
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY1_ICE_ENGINE_USES_HW_KEY_FVAL                             0x1
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_BMSK                                             0x40000000
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_SHFT                                                   0x1e
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_SW_KEY_FVAL                             0x0
#define HWIO_FEATURE_CONFIG1_ICE_FORCE_HW_KEY0_ICE_ENGINE_USES_HW_KEY_FVAL                             0x1
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_BMSK                                                   0x20000000
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_SHFT                                                         0x1d
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_ENABLE_FVAL                                                   0x0
#define HWIO_FEATURE_CONFIG1_ICE_DISABLE_DISABLE_FVAL                                                  0x1
#define HWIO_FEATURE_CONFIG1_SSC_DISABLE_BMSK                                                    0x4000000
#define HWIO_FEATURE_CONFIG1_SSC_DISABLE_SHFT                                                         0x1a
#define HWIO_FEATURE_CONFIG1_SSC_DISABLE_ENABLE_FVAL                                                   0x0
#define HWIO_FEATURE_CONFIG1_SSC_DISABLE_DISABLE_FVAL                                                  0x1
#define HWIO_FEATURE_CONFIG1_SSC_ISLAND_MODE_Q6_CLK_DISABLE_BMSK                                 0x2000000
#define HWIO_FEATURE_CONFIG1_SSC_ISLAND_MODE_Q6_CLK_DISABLE_SHFT                                      0x19
#define HWIO_FEATURE_CONFIG1_SSC_ISLAND_MODE_Q6_CLK_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_FEATURE_CONFIG1_SSC_ISLAND_MODE_Q6_CLK_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_FEATURE_CONFIG1_SSC_SW_ISLAND_MODE_DISABLE_BMSK                                     0x1000000
#define HWIO_FEATURE_CONFIG1_SSC_SW_ISLAND_MODE_DISABLE_SHFT                                          0x18
#define HWIO_FEATURE_CONFIG1_SSC_SW_ISLAND_MODE_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG1_SSC_SW_ISLAND_MODE_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG1_TCSR_SW_OVERRIDE_SOC_HW_VER_BMSK                                     0x800000
#define HWIO_FEATURE_CONFIG1_TCSR_SW_OVERRIDE_SOC_HW_VER_SHFT                                         0x17
#define HWIO_FEATURE_CONFIG1_APS_RESET_DISABLE_BMSK                                               0x400000
#define HWIO_FEATURE_CONFIG1_APS_RESET_DISABLE_SHFT                                                   0x16
#define HWIO_FEATURE_CONFIG1_IRIS_MULTIPIPE_DISABLE_BMSK                                          0x200000
#define HWIO_FEATURE_CONFIG1_IRIS_MULTIPIPE_DISABLE_SHFT                                              0x15
#define HWIO_FEATURE_CONFIG1_IRIS_MULTIPIPE_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_FEATURE_CONFIG1_IRIS_MULTIPIPE_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_FEATURE_CONFIG1_DOLBY_BIT_BMSK                                                       0x100000
#define HWIO_FEATURE_CONFIG1_DOLBY_BIT_SHFT                                                           0x14
#define HWIO_FEATURE_CONFIG1_QC_UDK_DISABLE_BMSK                                                   0x80000
#define HWIO_FEATURE_CONFIG1_QC_UDK_DISABLE_SHFT                                                      0x13
#define HWIO_FEATURE_CONFIG1_QC_UDK_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_FEATURE_CONFIG1_QC_UDK_DISABLE_DISABLE_FVAL                                               0x1
#define HWIO_FEATURE_CONFIG1_STACKED_MEMORY_ID_BMSK                                                0x7c000
#define HWIO_FEATURE_CONFIG1_STACKED_MEMORY_ID_SHFT                                                    0xe
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_BMSK                                             0x2000
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_SHFT                                                0xd
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_ENABLE_FVAL                                         0x0
#define HWIO_FEATURE_CONFIG1_PRNG_TESTMODE_DISABLE_DISABLE_FVAL                                        0x1
#define HWIO_FEATURE_CONFIG1_MDSS_Q_CONFIG_FUSE_BMSK                                                0x1000
#define HWIO_FEATURE_CONFIG1_MDSS_Q_CONFIG_FUSE_SHFT                                                   0xc
#define HWIO_FEATURE_CONFIG1_MDSS_Q_CONFIG_FUSE_HANA_FEAT_SET_FVAL                                     0x0
#define HWIO_FEATURE_CONFIG1_MDSS_Q_CONFIG_FUSE_HANAQ_FEAT_SET_FVAL                                    0x1
#define HWIO_FEATURE_CONFIG1_MOCHA_PART_BMSK                                                         0x800
#define HWIO_FEATURE_CONFIG1_MOCHA_PART_SHFT                                                           0xb
#define HWIO_FEATURE_CONFIG1_EFUSE_Q6SS_HVX_HALF_BMSK                                                0x400
#define HWIO_FEATURE_CONFIG1_EFUSE_Q6SS_HVX_HALF_SHFT                                                  0xa
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_BMSK                                                       0x200
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_SHFT                                                         0x9
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_ENABLE_FVAL                                                  0x0
#define HWIO_FEATURE_CONFIG1_SMMU_DISABLE_DISABLE_FVAL                                                 0x1
#define HWIO_FEATURE_CONFIG1_VENDOR_LOCK_BMSK                                                        0x1e0
#define HWIO_FEATURE_CONFIG1_VENDOR_LOCK_SHFT                                                          0x5
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_BMSK                                              0x10
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_SHFT                                               0x4
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_FEATURE_CONFIG1_CM_FEAT_CONFIG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_FEATURE_CONFIG1_PCIE_2_DISABLE_BMSK                                                       0x4
#define HWIO_FEATURE_CONFIG1_PCIE_2_DISABLE_SHFT                                                       0x2
#define HWIO_FEATURE_CONFIG1_PCIE_2_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_FEATURE_CONFIG1_PCIE_2_DISABLE_DISABLE_FVAL                                               0x1
#define HWIO_FEATURE_CONFIG1_PCIE_1_DISABLE_BMSK                                                       0x2
#define HWIO_FEATURE_CONFIG1_PCIE_1_DISABLE_SHFT                                                       0x1
#define HWIO_FEATURE_CONFIG1_PCIE_1_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_FEATURE_CONFIG1_PCIE_1_DISABLE_DISABLE_FVAL                                               0x1
#define HWIO_FEATURE_CONFIG1_PCIE_0_DISABLE_BMSK                                                       0x1
#define HWIO_FEATURE_CONFIG1_PCIE_0_DISABLE_SHFT                                                       0x0
#define HWIO_FEATURE_CONFIG1_PCIE_0_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_FEATURE_CONFIG1_PCIE_0_DISABLE_DISABLE_FVAL                                               0x1

#define HWIO_FEATURE_CONFIG2_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000600c)
#define HWIO_FEATURE_CONFIG2_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000600c)
#define HWIO_FEATURE_CONFIG2_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000600c)
#define HWIO_FEATURE_CONFIG2_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG2_IN          \
        in_dword(HWIO_FEATURE_CONFIG2_ADDR)
#define HWIO_FEATURE_CONFIG2_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG2_ADDR, m)
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_HARD_BMSK                                    0xffffc000
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_HARD_SHFT                                           0xe
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_HARD_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_HARD_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_IU_BMSK                                          0x3c00
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_IU_SHFT                                             0xa
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_IU_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_IU_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_BMSK                                        0x3ff
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_SHFT                                          0x0
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_ENABLE_FVAL                                   0x0
#define HWIO_FEATURE_CONFIG2_MODEM_FEATURE_DISABLE_SPARE_DISABLE_FVAL                                  0x1

#define HWIO_FEATURE_CONFIG3_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006010)
#define HWIO_FEATURE_CONFIG3_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006010)
#define HWIO_FEATURE_CONFIG3_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006010)
#define HWIO_FEATURE_CONFIG3_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG3_IN          \
        in_dword(HWIO_FEATURE_CONFIG3_ADDR)
#define HWIO_FEATURE_CONFIG3_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG3_ADDR, m)
#define HWIO_FEATURE_CONFIG3_APSS_PDXWRPNTRDELAY_BMSK                                           0xc0000000
#define HWIO_FEATURE_CONFIG3_APSS_PDXWRPNTRDELAY_SHFT                                                 0x1e
#define HWIO_FEATURE_CONFIG3_SEC_CTRL_GCC_NPU_FUSE_DISABLE_BMSK                                 0x20000000
#define HWIO_FEATURE_CONFIG3_SEC_CTRL_GCC_NPU_FUSE_DISABLE_SHFT                                       0x1d
#define HWIO_FEATURE_CONFIG3_SEC_CTRL_GCC_NPU_FUSE_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG3_SEC_CTRL_GCC_NPU_FUSE_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_FUNCTIONAL_BMSK                                     0x10000000
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_FUNCTIONAL_SHFT                                           0x1c
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_FUNCTIONAL_MOBILE_FVAL                                     0x0
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_FUNCTIONAL_AUTOMOTIVE_FVAL                                 0x1
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_POWER_BMSK                                           0x8000000
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_POWER_SHFT                                                0x1b
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_POWER_MOBILE_FVAL                                          0x0
#define HWIO_FEATURE_CONFIG3_AUTOMOTIVE_BIT_POWER_AUTOMOTIVE_FVAL                                      0x1
#define HWIO_FEATURE_CONFIG3_EMAC_DISABLE_BMSK                                                   0x4000000
#define HWIO_FEATURE_CONFIG3_EMAC_DISABLE_SHFT                                                        0x1a
#define HWIO_FEATURE_CONFIG3_EMAC_DISABLE_ENABLE_FVAL                                                  0x0
#define HWIO_FEATURE_CONFIG3_EMAC_DISABLE_DISABLE_FVAL                                                 0x1
#define HWIO_FEATURE_CONFIG3_MODEM_TCM_BOOT_DISABLE_BMSK                                         0x2000000
#define HWIO_FEATURE_CONFIG3_MODEM_TCM_BOOT_DISABLE_SHFT                                              0x19
#define HWIO_FEATURE_CONFIG3_MODEM_TCM_BOOT_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_FEATURE_CONFIG3_MODEM_TCM_BOOT_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_FEATURE_CONFIG3_NAV_DISABLE_BMSK                                                    0x1000000
#define HWIO_FEATURE_CONFIG3_NAV_DISABLE_SHFT                                                         0x18
#define HWIO_FEATURE_CONFIG3_NAV_DISABLE_ENABLE_FVAL                                                   0x0
#define HWIO_FEATURE_CONFIG3_NAV_DISABLE_DISABLE_FVAL                                                  0x1
#define HWIO_FEATURE_CONFIG3_MODEM_FEATURE_DISABLE_SOFT_BMSK                                      0xffffff
#define HWIO_FEATURE_CONFIG3_MODEM_FEATURE_DISABLE_SOFT_SHFT                                           0x0
#define HWIO_FEATURE_CONFIG3_MODEM_FEATURE_DISABLE_SOFT_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG3_MODEM_FEATURE_DISABLE_SOFT_DISABLE_FVAL                                   0x1

#define HWIO_FEATURE_CONFIG4_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006014)
#define HWIO_FEATURE_CONFIG4_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006014)
#define HWIO_FEATURE_CONFIG4_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006014)
#define HWIO_FEATURE_CONFIG4_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG4_IN          \
        in_dword(HWIO_FEATURE_CONFIG4_ADDR)
#define HWIO_FEATURE_CONFIG4_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG4_ADDR, m)
#define HWIO_FEATURE_CONFIG4_P2S_ACCU_RED_DEC_END_VAL_FUSE0_BMSK                                0x80000000
#define HWIO_FEATURE_CONFIG4_P2S_ACCU_RED_DEC_END_VAL_FUSE0_SHFT                                      0x1f
#define HWIO_FEATURE_CONFIG4_FUSE_CORTEX_M3_DISABLE_BMSK                                        0x40000000
#define HWIO_FEATURE_CONFIG4_FUSE_CORTEX_M3_DISABLE_SHFT                                              0x1e
#define HWIO_FEATURE_CONFIG4_Q_CONFIG_FUSE_BMSK                                                 0x20000000
#define HWIO_FEATURE_CONFIG4_Q_CONFIG_FUSE_SHFT                                                       0x1d
#define HWIO_FEATURE_CONFIG4_I_MC5_FUSE_BMSK                                                    0x10000000
#define HWIO_FEATURE_CONFIG4_I_MC5_FUSE_SHFT                                                          0x1c
#define HWIO_FEATURE_CONFIG4_I_MC4_FUSE_BMSK                                                     0x8000000
#define HWIO_FEATURE_CONFIG4_I_MC4_FUSE_SHFT                                                          0x1b
#define HWIO_FEATURE_CONFIG4_RSVD_BMSK                                                           0x4000000
#define HWIO_FEATURE_CONFIG4_RSVD_SHFT                                                                0x1a
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC5_DEBUG_DISABLE_BMSK                                  0x2000000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC5_DEBUG_DISABLE_SHFT                                       0x19
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC4_DEBUG_DISABLE_BMSK                                  0x1000000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC4_DEBUG_DISABLE_SHFT                                       0x18
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC3_DEBUG_DISABLE_BMSK                                   0x800000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC3_DEBUG_DISABLE_SHFT                                       0x17
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC2_DEBUG_DISABLE_BMSK                                   0x400000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC2_DEBUG_DISABLE_SHFT                                       0x16
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC1_DEBUG_DISABLE_BMSK                                   0x200000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC1_DEBUG_DISABLE_SHFT                                       0x15
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC_DEBUG_DISABLE_BMSK                                    0x100000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC_DEBUG_DISABLE_SHFT                                        0x14
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_BMSK                                            0x80000
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_SHFT                                               0x13
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_ENABLE_FVAL                                         0x0
#define HWIO_FEATURE_CONFIG4_QC_APPS_NIDEN_DISABLE_DISABLE_FVAL                                        0x1
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_BMSK                                            0x40000
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_SHFT                                               0x12
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_ENABLE_FVAL                                         0x0
#define HWIO_FEATURE_CONFIG4_QC_APPS_DBGEN_DISABLE_DISABLE_FVAL                                        0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_NIDEN_DISABLE_BMSK                                       0x20000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_NIDEN_DISABLE_SHFT                                          0x11
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_DBGEN_DISABLE_BMSK                                       0x10000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_DBGEN_DISABLE_SHFT                                          0x10
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_NIDEN_DISABLE_BMSK                                        0x8000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_NIDEN_DISABLE_SHFT                                           0xf
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_DBGEN_DISABLE_BMSK                                        0x4000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_DBGEN_DISABLE_SHFT                                           0xe
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_NIDEN_DISABLE_BMSK                                       0x2000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_NIDEN_DISABLE_SHFT                                          0xd
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_DBGEN_DISABLE_BMSK                                       0x1000
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_DBGEN_DISABLE_SHFT                                          0xc
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                                     0x800
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                                       0xb
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                                0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                               0x1
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPIDEN_DISABLE_BMSK                                      0x400
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPIDEN_DISABLE_SHFT                                        0xa
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                                 0x0
#define HWIO_FEATURE_CONFIG4_QC_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                                0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_NIDEN_DISABLE_BMSK                                           0x200
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_NIDEN_DISABLE_SHFT                                             0x9
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_NIDEN_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_NIDEN_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_DBGEN_DISABLE_BMSK                                           0x100
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_DBGEN_DISABLE_SHFT                                             0x8
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_DBGEN_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_NS_DBGEN_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_NIDEN_DISABLE_BMSK                                            0x80
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_NIDEN_DISABLE_SHFT                                             0x7
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_NIDEN_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_NIDEN_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_DBGEN_DISABLE_BMSK                                            0x40
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_DBGEN_DISABLE_SHFT                                             0x6
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_DBGEN_DISABLE_ENABLE_FVAL                                      0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_CP_DBGEN_DISABLE_DISABLE_FVAL                                     0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_NIDEN_DISABLE_BMSK                                           0x20
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_NIDEN_DISABLE_SHFT                                            0x5
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_NIDEN_DISABLE_ENABLE_FVAL                                     0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_NIDEN_DISABLE_DISABLE_FVAL                                    0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_DBGEN_DISABLE_BMSK                                           0x10
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_DBGEN_DISABLE_SHFT                                            0x4
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_DBGEN_DISABLE_ENABLE_FVAL                                     0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_MSS_DBGEN_DISABLE_DISABLE_FVAL                                    0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPNIDEN_DISABLE_BMSK                                         0x8
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPNIDEN_DISABLE_SHFT                                         0x3
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                                  0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                                 0x1
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPIDEN_DISABLE_BMSK                                          0x4
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPIDEN_DISABLE_SHFT                                          0x2
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                                   0x0
#define HWIO_FEATURE_CONFIG4_PRIVATE_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                                  0x1
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_BMSK                                                      0x2
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_SHFT                                                      0x1
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_ENABLE_FVAL                                               0x0
#define HWIO_FEATURE_CONFIG4_SM_BIST_DISABLE_DISABLE_FVAL                                              0x1
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_BMSK                                                          0x1
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_SHFT                                                          0x0
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_ENABLE_FVAL                                                   0x0
#define HWIO_FEATURE_CONFIG4_TIC_DISABLE_DISABLE_FVAL                                                  0x1

#define HWIO_FEATURE_CONFIG5_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006018)
#define HWIO_FEATURE_CONFIG5_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006018)
#define HWIO_FEATURE_CONFIG5_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006018)
#define HWIO_FEATURE_CONFIG5_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG5_IN          \
        in_dword(HWIO_FEATURE_CONFIG5_ADDR)
#define HWIO_FEATURE_CONFIG5_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG5_ADDR, m)
#define HWIO_FEATURE_CONFIG5_SYS_CFG_APC1PLL_LVAL_BMSK                                          0xff000000
#define HWIO_FEATURE_CONFIG5_SYS_CFG_APC1PLL_LVAL_SHFT                                                0x18
#define HWIO_FEATURE_CONFIG5_APSS_KRYO_PP_DISABLE_BMSK                                            0x800000
#define HWIO_FEATURE_CONFIG5_APSS_KRYO_PP_DISABLE_SHFT                                                0x17
#define HWIO_FEATURE_CONFIG5_SYS_CFG_L3_SIZE_RED_BMSK                                             0x400000
#define HWIO_FEATURE_CONFIG5_SYS_CFG_L3_SIZE_RED_SHFT                                                 0x16
#define HWIO_FEATURE_CONFIG5_AUTO_CCI_RCG_CFG_DISABLE_BMSK                                        0x200000
#define HWIO_FEATURE_CONFIG5_AUTO_CCI_RCG_CFG_DISABLE_SHFT                                            0x15
#define HWIO_FEATURE_CONFIG5_APPS_BOOT_FSM_FUSE_BMSK                                              0x1f8000
#define HWIO_FEATURE_CONFIG5_APPS_BOOT_FSM_FUSE_SHFT                                                   0xf
#define HWIO_FEATURE_CONFIG5_SYS_APCSCFGAPMBOOTONMX_BMSK                                            0x4000
#define HWIO_FEATURE_CONFIG5_SYS_APCSCFGAPMBOOTONMX_SHFT                                               0xe
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGCPUPRESENT_N_BMSK                                           0x3fc0
#define HWIO_FEATURE_CONFIG5_SYS_APCCCFGCPUPRESENT_N_SHFT                                              0x6
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE6_BMSK                                      0x20
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE6_SHFT                                       0x5
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE5_BMSK                                      0x10
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE5_SHFT                                       0x4
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE4_BMSK                                       0x8
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE4_SHFT                                       0x3
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE3_BMSK                                       0x4
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE3_SHFT                                       0x2
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE2_BMSK                                       0x2
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE2_SHFT                                       0x1
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE1_BMSK                                       0x1
#define HWIO_FEATURE_CONFIG5_P2S_ACCU_RED_DEC_END_VAL_FUSE1_SHFT                                       0x0

#define HWIO_FEATURE_CONFIG6_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000601c)
#define HWIO_FEATURE_CONFIG6_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000601c)
#define HWIO_FEATURE_CONFIG6_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000601c)
#define HWIO_FEATURE_CONFIG6_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG6_IN          \
        in_dword(HWIO_FEATURE_CONFIG6_ADDR)
#define HWIO_FEATURE_CONFIG6_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG6_ADDR, m)
#define HWIO_FEATURE_CONFIG6_RSVD1_BMSK                                                         0x80000000
#define HWIO_FEATURE_CONFIG6_RSVD1_SHFT                                                               0x1f
#define HWIO_FEATURE_CONFIG6_SYS_CFG_GOLDPLUS_PLL_LVAL_BMSK                                     0x7f800000
#define HWIO_FEATURE_CONFIG6_SYS_CFG_GOLDPLUS_PLL_LVAL_SHFT                                           0x17
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_6_BMSK                                          0x400000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_6_SHFT                                              0x16
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_5_BMSK                                          0x200000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_5_SHFT                                              0x15
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_4_BMSK                                          0x100000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_4_SHFT                                              0x14
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_3_BMSK                                           0x80000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_3_SHFT                                              0x13
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_2_BMSK                                           0x40000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_2_SHFT                                              0x12
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_1_BMSK                                           0x20000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_1_SHFT                                              0x11
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_0_BMSK                                           0x10000
#define HWIO_FEATURE_CONFIG6_ACCU_RED_DEC_END_VAL_0_SHFT                                              0x10
#define HWIO_FEATURE_CONFIG6_TURING_Q6SS_PLL_L_MAX_BMSK                                             0xffff
#define HWIO_FEATURE_CONFIG6_TURING_Q6SS_PLL_L_MAX_SHFT                                                0x0

#define HWIO_FEATURE_CONFIG7_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006020)
#define HWIO_FEATURE_CONFIG7_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006020)
#define HWIO_FEATURE_CONFIG7_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006020)
#define HWIO_FEATURE_CONFIG7_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG7_IN          \
        in_dword(HWIO_FEATURE_CONFIG7_ADDR)
#define HWIO_FEATURE_CONFIG7_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG7_ADDR, m)
#define HWIO_FEATURE_CONFIG7_RSVD_BMSK                                                          0xfffffffe
#define HWIO_FEATURE_CONFIG7_RSVD_SHFT                                                                 0x1
#define HWIO_FEATURE_CONFIG7_DISABLE_SEC_BOOT_GPIO_BMSK                                                0x1
#define HWIO_FEATURE_CONFIG7_DISABLE_SEC_BOOT_GPIO_SHFT                                                0x0

#define HWIO_FEATURE_CONFIG8_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006024)
#define HWIO_FEATURE_CONFIG8_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006024)
#define HWIO_FEATURE_CONFIG8_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006024)
#define HWIO_FEATURE_CONFIG8_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG8_IN          \
        in_dword(HWIO_FEATURE_CONFIG8_ADDR)
#define HWIO_FEATURE_CONFIG8_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG8_ADDR, m)
#define HWIO_FEATURE_CONFIG8_RSVD_BMSK                                                          0xfffffffe
#define HWIO_FEATURE_CONFIG8_RSVD_SHFT                                                                 0x1
#define HWIO_FEATURE_CONFIG8_LEGACY_MBNV6_OVERRIDE_BMSK                                                0x1
#define HWIO_FEATURE_CONFIG8_LEGACY_MBNV6_OVERRIDE_SHFT                                                0x0

#define HWIO_FEATURE_CONFIG9_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006028)
#define HWIO_FEATURE_CONFIG9_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006028)
#define HWIO_FEATURE_CONFIG9_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006028)
#define HWIO_FEATURE_CONFIG9_RMSK                                                               0xffffffff
#define HWIO_FEATURE_CONFIG9_IN          \
        in_dword(HWIO_FEATURE_CONFIG9_ADDR)
#define HWIO_FEATURE_CONFIG9_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG9_ADDR, m)
#define HWIO_FEATURE_CONFIG9_RSVD_BMSK                                                          0xffffffff
#define HWIO_FEATURE_CONFIG9_RSVD_SHFT                                                                 0x0

#define HWIO_FEATURE_CONFIG10_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000602c)
#define HWIO_FEATURE_CONFIG10_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000602c)
#define HWIO_FEATURE_CONFIG10_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000602c)
#define HWIO_FEATURE_CONFIG10_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG10_IN          \
        in_dword(HWIO_FEATURE_CONFIG10_ADDR)
#define HWIO_FEATURE_CONFIG10_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG10_ADDR, m)
#define HWIO_FEATURE_CONFIG10_RSVD1_BMSK                                                        0xffffffff
#define HWIO_FEATURE_CONFIG10_RSVD1_SHFT                                                               0x0

#define HWIO_FEATURE_CONFIG11_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006030)
#define HWIO_FEATURE_CONFIG11_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006030)
#define HWIO_FEATURE_CONFIG11_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006030)
#define HWIO_FEATURE_CONFIG11_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG11_IN          \
        in_dword(HWIO_FEATURE_CONFIG11_ADDR)
#define HWIO_FEATURE_CONFIG11_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG11_ADDR, m)
#define HWIO_FEATURE_CONFIG11_RSVD1_BMSK                                                        0xffffffff
#define HWIO_FEATURE_CONFIG11_RSVD1_SHFT                                                               0x0

#define HWIO_FEATURE_CONFIG12_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006034)
#define HWIO_FEATURE_CONFIG12_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006034)
#define HWIO_FEATURE_CONFIG12_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006034)
#define HWIO_FEATURE_CONFIG12_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG12_IN          \
        in_dword(HWIO_FEATURE_CONFIG12_ADDR)
#define HWIO_FEATURE_CONFIG12_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG12_ADDR, m)
#define HWIO_FEATURE_CONFIG12_TAP_GEN_SPARE_INSTR_DISABLE_13_0_BMSK                             0xfffc0000
#define HWIO_FEATURE_CONFIG12_TAP_GEN_SPARE_INSTR_DISABLE_13_0_SHFT                                   0x12
#define HWIO_FEATURE_CONFIG12_TAP_INSTR_DISABLE_BMSK                                               0x3ffff
#define HWIO_FEATURE_CONFIG12_TAP_INSTR_DISABLE_SHFT                                                   0x0

#define HWIO_FEATURE_CONFIG13_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006038)
#define HWIO_FEATURE_CONFIG13_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006038)
#define HWIO_FEATURE_CONFIG13_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006038)
#define HWIO_FEATURE_CONFIG13_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG13_IN          \
        in_dword(HWIO_FEATURE_CONFIG13_ADDR)
#define HWIO_FEATURE_CONFIG13_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG13_ADDR, m)
#define HWIO_FEATURE_CONFIG13_SEC_TAP_ACCESS_DISABLE_BMSK                                       0xfffc0000
#define HWIO_FEATURE_CONFIG13_SEC_TAP_ACCESS_DISABLE_SHFT                                             0x12
#define HWIO_FEATURE_CONFIG13_TAP_GEN_SPARE_INSTR_DISABLE_31_14_BMSK                               0x3ffff
#define HWIO_FEATURE_CONFIG13_TAP_GEN_SPARE_INSTR_DISABLE_31_14_SHFT                                   0x0

#define HWIO_FEATURE_CONFIG14_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000603c)
#define HWIO_FEATURE_CONFIG14_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000603c)
#define HWIO_FEATURE_CONFIG14_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000603c)
#define HWIO_FEATURE_CONFIG14_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG14_IN          \
        in_dword(HWIO_FEATURE_CONFIG14_ADDR)
#define HWIO_FEATURE_CONFIG14_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG14_ADDR, m)
#define HWIO_FEATURE_CONFIG14_MODEM_PBL_PATCH_VERSION_BMSK                                      0xfe000000
#define HWIO_FEATURE_CONFIG14_MODEM_PBL_PATCH_VERSION_SHFT                                            0x19
#define HWIO_FEATURE_CONFIG14_APPS_PBL_PATCH_VERSION_BMSK                                        0x1fc0000
#define HWIO_FEATURE_CONFIG14_APPS_PBL_PATCH_VERSION_SHFT                                             0x12
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_BMSK                                             0x30000
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_SHFT                                                0x10
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_ENUM_600_MHZ_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_XO_FVAL                                              0x1
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_ENUM_1200_MHZ_FVAL                                   0x2
#define HWIO_FEATURE_CONFIG14_APPS_PBL_BOOT_SPEED_NA_FVAL                                              0x3
#define HWIO_FEATURE_CONFIG14_MODEM_PBL_BOOT_BMSK                                                   0x8000
#define HWIO_FEATURE_CONFIG14_MODEM_PBL_BOOT_SHFT                                                      0xf
#define HWIO_FEATURE_CONFIG14_RSVD1_56_14_BMSK                                                      0x4000
#define HWIO_FEATURE_CONFIG14_RSVD1_56_14_SHFT                                                         0xe
#define HWIO_FEATURE_CONFIG14_APPS_BOOT_FROM_ROM_BMSK                                               0x2000
#define HWIO_FEATURE_CONFIG14_APPS_BOOT_FROM_ROM_SHFT                                                  0xd
#define HWIO_FEATURE_CONFIG14_ENABLE_DEVICE_IN_TEST_MODE_BMSK                                       0x1000
#define HWIO_FEATURE_CONFIG14_ENABLE_DEVICE_IN_TEST_MODE_SHFT                                          0xc
#define HWIO_FEATURE_CONFIG14_QTI_ROOT_SIG_FORMAT_SEL_BMSK                                           0x800
#define HWIO_FEATURE_CONFIG14_QTI_ROOT_SIG_FORMAT_SEL_SHFT                                             0xb
#define HWIO_FEATURE_CONFIG14_CE_BAM_DISABLE_BMSK                                                    0x400
#define HWIO_FEATURE_CONFIG14_CE_BAM_DISABLE_SHFT                                                      0xa
#define HWIO_FEATURE_CONFIG14_CE_BAM_DISABLE_ENABLE_FVAL                                               0x0
#define HWIO_FEATURE_CONFIG14_CE_BAM_DISABLE_DISABLE_FVAL                                              0x1
#define HWIO_FEATURE_CONFIG14_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_BMSK                                0x200
#define HWIO_FEATURE_CONFIG14_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_SHFT                                  0x9
#define HWIO_FEATURE_CONFIG14_ARM_CE_DISABLE_USAGE_BMSK                                              0x100
#define HWIO_FEATURE_CONFIG14_ARM_CE_DISABLE_USAGE_SHFT                                                0x8
#define HWIO_FEATURE_CONFIG14_BOOT_ROM_CFG_BMSK                                                       0xff
#define HWIO_FEATURE_CONFIG14_BOOT_ROM_CFG_SHFT                                                        0x0

#define HWIO_FEATURE_CONFIG15_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006040)
#define HWIO_FEATURE_CONFIG15_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006040)
#define HWIO_FEATURE_CONFIG15_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006040)
#define HWIO_FEATURE_CONFIG15_RMSK                                                              0xffffffff
#define HWIO_FEATURE_CONFIG15_IN          \
        in_dword(HWIO_FEATURE_CONFIG15_ADDR)
#define HWIO_FEATURE_CONFIG15_INM(m)      \
        in_dword_masked(HWIO_FEATURE_CONFIG15_ADDR, m)
#define HWIO_FEATURE_CONFIG15_APPS_BOOT_TRIGGER_DISABLE_BMSK                                    0x80000000
#define HWIO_FEATURE_CONFIG15_APPS_BOOT_TRIGGER_DISABLE_SHFT                                          0x1f
#define HWIO_FEATURE_CONFIG15_APPS_BOOT_TRIGGER_DISABLE_ENABLE_FVAL                                    0x0
#define HWIO_FEATURE_CONFIG15_APPS_BOOT_TRIGGER_DISABLE_DISABLE_FVAL                                   0x1
#define HWIO_FEATURE_CONFIG15_PBL_QSEE_BOOT_FLOW_DISABLE_BMSK                                   0x40000000
#define HWIO_FEATURE_CONFIG15_PBL_QSEE_BOOT_FLOW_DISABLE_SHFT                                         0x1e
#define HWIO_FEATURE_CONFIG15_XBL_SEC_AUTH_DISABLE_BMSK                                         0x20000000
#define HWIO_FEATURE_CONFIG15_XBL_SEC_AUTH_DISABLE_SHFT                                               0x1d
#define HWIO_FEATURE_CONFIG15_MSM_PKG_TYPE_BMSK                                                 0x10000000
#define HWIO_FEATURE_CONFIG15_MSM_PKG_TYPE_SHFT                                                       0x1c
#define HWIO_FEATURE_CONFIG15_SPSS_CONFIG_MODE_BMSK                                              0xc000000
#define HWIO_FEATURE_CONFIG15_SPSS_CONFIG_MODE_SHFT                                                   0x1a
#define HWIO_FEATURE_CONFIG15_PERIPH_DRV_STRENGTH_SETTING_BMSK                                   0x3800000
#define HWIO_FEATURE_CONFIG15_PERIPH_DRV_STRENGTH_SETTING_SHFT                                        0x17
#define HWIO_FEATURE_CONFIG15_RSVD3_56_54_BMSK                                                    0x400000
#define HWIO_FEATURE_CONFIG15_RSVD3_56_54_SHFT                                                        0x16
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_BMSK                                                     0x3c0000
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_SHFT                                                         0x12
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_TSMC_FVAL                                                     0x0
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_GLOBAL_FOUNDRIES_FVAL                                         0x1
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_SAMSUNG_FVAL                                                  0x2
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_IBM_FVAL                                                      0x3
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_UMC_FVAL                                                      0x4
#define HWIO_FEATURE_CONFIG15_FOUNDRY_ID_SMIC_FVAL                                                     0x5
#define HWIO_FEATURE_CONFIG15_PLL_CFG_BMSK                                                         0x3fff0
#define HWIO_FEATURE_CONFIG15_PLL_CFG_SHFT                                                             0x4
#define HWIO_FEATURE_CONFIG15_APPS_PBL_PLL_CTRL_BMSK                                                   0xf
#define HWIO_FEATURE_CONFIG15_APPS_PBL_PLL_CTRL_SHFT                                                   0x0

#define HWIO_OEM_CONFIG0_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006044)
#define HWIO_OEM_CONFIG0_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006044)
#define HWIO_OEM_CONFIG0_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006044)
#define HWIO_OEM_CONFIG0_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG0_IN          \
        in_dword(HWIO_OEM_CONFIG0_ADDR)
#define HWIO_OEM_CONFIG0_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG0_ADDR, m)
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                                       0x80000000
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                                             0x1f
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPNIDEN_DISABLE_ENABLE_FVAL                                       0x0
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPNIDEN_DISABLE_DISABLE_FVAL                                      0x1
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPIDEN_DISABLE_BMSK                                        0x40000000
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPIDEN_DISABLE_SHFT                                              0x1e
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPIDEN_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG0_SHARED_QSEE_SPIDEN_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_BMSK                                                 0x20000000
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_SHFT                                                       0x1d
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_ENABLE_FVAL                                                 0x0
#define HWIO_OEM_CONFIG0_ALL_DEBUG_DISABLE_DISABLE_FVAL                                                0x1
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_BMSK                                              0x10000000
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_SHFT                                                    0x1c
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_ENABLE_FVAL                                              0x0
#define HWIO_OEM_CONFIG0_DEBUG_POLICY_DISABLE_DISABLE_FVAL                                             0x1
#define HWIO_OEM_CONFIG0_SP_DISABLE_BMSK                                                         0x8000000
#define HWIO_OEM_CONFIG0_SP_DISABLE_SHFT                                                              0x1b
#define HWIO_OEM_CONFIG0_SP_DISABLE_ENABLE_FVAL                                                        0x0
#define HWIO_OEM_CONFIG0_SP_DISABLE_DISABLE_FVAL                                                       0x1
#define HWIO_OEM_CONFIG0_UDK_DISABLE_BMSK                                                        0x4000000
#define HWIO_OEM_CONFIG0_UDK_DISABLE_SHFT                                                             0x1a
#define HWIO_OEM_CONFIG0_UDK_DISABLE_ENABLE_FVAL                                                       0x0
#define HWIO_OEM_CONFIG0_UDK_DISABLE_DISABLE_FVAL                                                      0x1
#define HWIO_OEM_CONFIG0_DEBUG_DISABLE_IN_ROM_BMSK                                               0x2000000
#define HWIO_OEM_CONFIG0_DEBUG_DISABLE_IN_ROM_SHFT                                                    0x19
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_ENABLE_BMSK                                    0x1000000
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_ENABLE_SHFT                                         0x18
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_ENABLE_DISABLE_FVAL                                  0x0
#define HWIO_OEM_CONFIG0_MSS_HASH_INTEGRITY_CHECK_ENABLE_ENABLE_FVAL                                   0x1
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_BMSK                                   0x800000
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_SHFT                                       0x17
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_DISABLE_FVAL                                0x0
#define HWIO_OEM_CONFIG0_APPS_HASH_INTEGRITY_CHECK_DISABLE_ENABLE_FVAL                                 0x1
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_BMSK                                                      0x400000
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_SHFT                                                          0x16
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_ENABLE_FVAL                                                    0x0
#define HWIO_OEM_CONFIG0_USB_SS_DISABLE_DISABLE_FVAL                                                   0x1
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_BMSK                                               0x200000
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_SHFT                                                   0x15
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_USE_OEM_ID_FVAL                                         0x0
#define HWIO_OEM_CONFIG0_SW_ROT_USE_SERIAL_NUM_USE_SERIAL_NUM_FVAL                                     0x1
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_BMSK                                                0x100000
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_SHFT                                                    0x14
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_ENABLE_FVAL                                              0x0
#define HWIO_OEM_CONFIG0_DISABLE_ROT_TRANSFER_DISABLE_FVAL                                             0x1
#define HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_BMSK                                              0x80000
#define HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_SHFT                                                 0x13
#define HWIO_OEM_CONFIG0_ROOT_CERT_TOTAL_NUM_BMSK                                                  0x60000
#define HWIO_OEM_CONFIG0_ROOT_CERT_TOTAL_NUM_SHFT                                                     0x11
#define HWIO_OEM_CONFIG0_PBL_USB_TYPE_C_DISABLE_BMSK                                               0x10000
#define HWIO_OEM_CONFIG0_PBL_USB_TYPE_C_DISABLE_SHFT                                                  0x10
#define HWIO_OEM_CONFIG0_PBL_LOG_DISABLE_BMSK                                                       0x8000
#define HWIO_OEM_CONFIG0_PBL_LOG_DISABLE_SHFT                                                          0xf
#define HWIO_OEM_CONFIG0_WDOG_EN_BMSK                                                               0x4000
#define HWIO_OEM_CONFIG0_WDOG_EN_SHFT                                                                  0xe
#define HWIO_OEM_CONFIG0_WDOG_EN_USE_GPIO_FVAL                                                         0x0
#define HWIO_OEM_CONFIG0_WDOG_EN_IGNORE_GPIO_ENABLE_WDOG_FVAL                                          0x1
#define HWIO_OEM_CONFIG0_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_BMSK                                  0x2000
#define HWIO_OEM_CONFIG0_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_SHFT                                     0xd
#define HWIO_OEM_CONFIG0_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_DISABLE_EDL_RESET_FVAL                   0x0
#define HWIO_OEM_CONFIG0_PBL_FDL_TIMEOUT_RESET_FEATURE_ENABLE_ENABLE_EDL_RESET_FVAL                    0x1
#define HWIO_OEM_CONFIG0_SW_FUSE_PROG_DISABLE_BMSK                                                  0x1000
#define HWIO_OEM_CONFIG0_SW_FUSE_PROG_DISABLE_SHFT                                                     0xc
#define HWIO_OEM_CONFIG0_SPI_CLK_BOOT_FREQ_BMSK                                                      0x800
#define HWIO_OEM_CONFIG0_SPI_CLK_BOOT_FREQ_SHFT                                                        0xb
#define HWIO_OEM_CONFIG0_PBL_QSPI_BOOT_EDL_ENABLED_BMSK                                              0x400
#define HWIO_OEM_CONFIG0_PBL_QSPI_BOOT_EDL_ENABLED_SHFT                                                0xa
#define HWIO_OEM_CONFIG0_PBL_QSPI_BOOT_EDL_ENABLED_SD_USB_FVAL                                         0x0
#define HWIO_OEM_CONFIG0_PBL_QSPI_BOOT_EDL_ENABLED_QSPI_SD_USB_FVAL                                    0x1
#define HWIO_OEM_CONFIG0_FAST_BOOT_BMSK                                                              0x3e0
#define HWIO_OEM_CONFIG0_FAST_BOOT_SHFT                                                                0x5
#define HWIO_OEM_CONFIG0_FAST_BOOT_DEFAULT_FVAL                                                        0x0
#define HWIO_OEM_CONFIG0_FAST_BOOT_SD_UFS_EDL_FVAL                                                     0x1
#define HWIO_OEM_CONFIG0_FAST_BOOT_SD_EDL_FVAL                                                         0x2
#define HWIO_OEM_CONFIG0_FAST_BOOT_USB_EDL_FVAL                                                        0x3
#define HWIO_OEM_CONFIG0_FAST_BOOT_QSPI_EDL_FVAL                                                       0x4
#define HWIO_OEM_CONFIG0_FAST_BOOT_SPI_EDL_FVAL                                                        0x5
#define HWIO_OEM_CONFIG0_FAST_BOOT_UGSG4_SD_USB_EDL_FVAL                                               0x8
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_BMSK                                                     0x10
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_SHFT                                                      0x4
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_ENUM_19_2_MHZ_FVAL                                        0x0
#define HWIO_OEM_CONFIG0_SDCC_MCLK_BOOT_FREQ_ENUM_25_MHZ_FVAL                                          0x1
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_BMSK                                                   0x8
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_SHFT                                                   0x3
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_OEM_CONFIG0_FORCE_USB_BOOT_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL                        0x1
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_BMSK                                                      0x4
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_SHFT                                                      0x2
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_USE_FORCE_USB_BOOT_GPIO_TO_FORCE_BOOT_FROM_USB_FVAL        0x0
#define HWIO_OEM_CONFIG0_FORCE_DLOAD_DISABLE_NOT_USE_FORCE_USB_BOOT_PIN_FVAL                           0x1
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_BMSK                                                             0x2
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_SHFT                                                             0x1
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_TIMEOUT_DISABLED_FVAL                                            0x0
#define HWIO_OEM_CONFIG0_ENUM_TIMEOUT_TIMEOUT_ENABLED_90S_FVAL                                         0x1
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_BMSK                                                          0x1
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_SHFT                                                          0x0
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_DOWNLOADER_ENABLED_FVAL                                       0x0
#define HWIO_OEM_CONFIG0_E_DLOAD_DISABLE_DOWNLOADER_DISABLED_FVAL                                      0x1

#define HWIO_OEM_CONFIG1_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006048)
#define HWIO_OEM_CONFIG1_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006048)
#define HWIO_OEM_CONFIG1_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006048)
#define HWIO_OEM_CONFIG1_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG1_IN          \
        in_dword(HWIO_OEM_CONFIG1_ADDR)
#define HWIO_OEM_CONFIG1_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG1_ADDR, m)
#define HWIO_OEM_CONFIG1_RSVD1_BMSK                                                             0xffffc000
#define HWIO_OEM_CONFIG1_RSVD1_SHFT                                                                    0xe
#define HWIO_OEM_CONFIG1_SHARED_MISC5_DEBUG_DISABLE_BMSK                                            0x2000
#define HWIO_OEM_CONFIG1_SHARED_MISC5_DEBUG_DISABLE_SHFT                                               0xd
#define HWIO_OEM_CONFIG1_SHARED_MISC5_DEBUG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC5_DEBUG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG1_SHARED_MISC4_DEBUG_DISABLE_BMSK                                            0x1000
#define HWIO_OEM_CONFIG1_SHARED_MISC4_DEBUG_DISABLE_SHFT                                               0xc
#define HWIO_OEM_CONFIG1_SHARED_MISC4_DEBUG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC4_DEBUG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG1_SHARED_MISC3_DEBUG_DISABLE_BMSK                                             0x800
#define HWIO_OEM_CONFIG1_SHARED_MISC3_DEBUG_DISABLE_SHFT                                               0xb
#define HWIO_OEM_CONFIG1_SHARED_MISC3_DEBUG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC3_DEBUG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG1_SHARED_MISC2_DEBUG_DISABLE_BMSK                                             0x400
#define HWIO_OEM_CONFIG1_SHARED_MISC2_DEBUG_DISABLE_SHFT                                               0xa
#define HWIO_OEM_CONFIG1_SHARED_MISC2_DEBUG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC2_DEBUG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG1_SHARED_MISC1_DEBUG_DISABLE_BMSK                                             0x200
#define HWIO_OEM_CONFIG1_SHARED_MISC1_DEBUG_DISABLE_SHFT                                               0x9
#define HWIO_OEM_CONFIG1_SHARED_MISC1_DEBUG_DISABLE_ENABLE_FVAL                                        0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC1_DEBUG_DISABLE_DISABLE_FVAL                                       0x1
#define HWIO_OEM_CONFIG1_SHARED_MISC_DEBUG_DISABLE_BMSK                                              0x100
#define HWIO_OEM_CONFIG1_SHARED_MISC_DEBUG_DISABLE_SHFT                                                0x8
#define HWIO_OEM_CONFIG1_SHARED_MISC_DEBUG_DISABLE_ENABLE_FVAL                                         0x0
#define HWIO_OEM_CONFIG1_SHARED_MISC_DEBUG_DISABLE_DISABLE_FVAL                                        0x1
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_BMSK                                                      0x80
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_SHFT                                                       0x7
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_OEM_CONFIG1_APPS_NIDEN_DISABLE_DISABLE_FVAL                                               0x1
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_BMSK                                                      0x40
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_SHFT                                                       0x6
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_ENABLE_FVAL                                                0x0
#define HWIO_OEM_CONFIG1_APPS_DBGEN_DISABLE_DISABLE_FVAL                                               0x1
#define HWIO_OEM_CONFIG1_SHARED_NS_NIDEN_DISABLE_BMSK                                                 0x20
#define HWIO_OEM_CONFIG1_SHARED_NS_NIDEN_DISABLE_SHFT                                                  0x5
#define HWIO_OEM_CONFIG1_SHARED_NS_NIDEN_DISABLE_ENABLE_FVAL                                           0x0
#define HWIO_OEM_CONFIG1_SHARED_NS_NIDEN_DISABLE_DISABLE_FVAL                                          0x1
#define HWIO_OEM_CONFIG1_SHARED_NS_DBGEN_DISABLE_BMSK                                                 0x10
#define HWIO_OEM_CONFIG1_SHARED_NS_DBGEN_DISABLE_SHFT                                                  0x4
#define HWIO_OEM_CONFIG1_SHARED_NS_DBGEN_DISABLE_ENABLE_FVAL                                           0x0
#define HWIO_OEM_CONFIG1_SHARED_NS_DBGEN_DISABLE_DISABLE_FVAL                                          0x1
#define HWIO_OEM_CONFIG1_SHARED_CP_NIDEN_DISABLE_BMSK                                                  0x8
#define HWIO_OEM_CONFIG1_SHARED_CP_NIDEN_DISABLE_SHFT                                                  0x3
#define HWIO_OEM_CONFIG1_SHARED_CP_NIDEN_DISABLE_ENABLE_FVAL                                           0x0
#define HWIO_OEM_CONFIG1_SHARED_CP_NIDEN_DISABLE_DISABLE_FVAL                                          0x1
#define HWIO_OEM_CONFIG1_SHARED_CP_DBGEN_DISABLE_BMSK                                                  0x4
#define HWIO_OEM_CONFIG1_SHARED_CP_DBGEN_DISABLE_SHFT                                                  0x2
#define HWIO_OEM_CONFIG1_SHARED_CP_DBGEN_DISABLE_ENABLE_FVAL                                           0x0
#define HWIO_OEM_CONFIG1_SHARED_CP_DBGEN_DISABLE_DISABLE_FVAL                                          0x1
#define HWIO_OEM_CONFIG1_SHARED_MSS_NIDEN_DISABLE_BMSK                                                 0x2
#define HWIO_OEM_CONFIG1_SHARED_MSS_NIDEN_DISABLE_SHFT                                                 0x1
#define HWIO_OEM_CONFIG1_SHARED_MSS_NIDEN_DISABLE_ENABLE_FVAL                                          0x0
#define HWIO_OEM_CONFIG1_SHARED_MSS_NIDEN_DISABLE_DISABLE_FVAL                                         0x1
#define HWIO_OEM_CONFIG1_SHARED_MSS_DBGEN_DISABLE_BMSK                                                 0x1
#define HWIO_OEM_CONFIG1_SHARED_MSS_DBGEN_DISABLE_SHFT                                                 0x0
#define HWIO_OEM_CONFIG1_SHARED_MSS_DBGEN_DISABLE_ENABLE_FVAL                                          0x0
#define HWIO_OEM_CONFIG1_SHARED_MSS_DBGEN_DISABLE_DISABLE_FVAL                                         0x1

#define HWIO_OEM_CONFIG2_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000604c)
#define HWIO_OEM_CONFIG2_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000604c)
#define HWIO_OEM_CONFIG2_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000604c)
#define HWIO_OEM_CONFIG2_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG2_IN          \
        in_dword(HWIO_OEM_CONFIG2_ADDR)
#define HWIO_OEM_CONFIG2_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG2_ADDR, m)
#define HWIO_OEM_CONFIG2_DISABLE_RSA_BMSK                                                       0x80000000
#define HWIO_OEM_CONFIG2_DISABLE_RSA_SHFT                                                             0x1f
#define HWIO_OEM_CONFIG2_EKU_ENFORCEMENT_EN_BMSK                                                0x40000000
#define HWIO_OEM_CONFIG2_EKU_ENFORCEMENT_EN_SHFT                                                      0x1e
#define HWIO_OEM_CONFIG2_RSVD2_BMSK                                                             0x3fff0000
#define HWIO_OEM_CONFIG2_RSVD2_SHFT                                                                   0x10
#define HWIO_OEM_CONFIG2_SPARE_REG31_SECURE_BMSK                                                    0x8000
#define HWIO_OEM_CONFIG2_SPARE_REG31_SECURE_SHFT                                                       0xf
#define HWIO_OEM_CONFIG2_SPARE_REG31_SECURE_NOT_SECURE_FVAL                                            0x0
#define HWIO_OEM_CONFIG2_SPARE_REG31_SECURE_SECURE_FVAL                                                0x1
#define HWIO_OEM_CONFIG2_SPARE_REG30_SECURE_BMSK                                                    0x4000
#define HWIO_OEM_CONFIG2_SPARE_REG30_SECURE_SHFT                                                       0xe
#define HWIO_OEM_CONFIG2_SPARE_REG30_SECURE_NOT_SECURE_FVAL                                            0x0
#define HWIO_OEM_CONFIG2_SPARE_REG30_SECURE_SECURE_FVAL                                                0x1
#define HWIO_OEM_CONFIG2_SPARE_REG29_SECURE_BMSK                                                    0x2000
#define HWIO_OEM_CONFIG2_SPARE_REG29_SECURE_SHFT                                                       0xd
#define HWIO_OEM_CONFIG2_SPARE_REG29_SECURE_NOT_SECURE_FVAL                                            0x0
#define HWIO_OEM_CONFIG2_SPARE_REG29_SECURE_SECURE_FVAL                                                0x1
#define HWIO_OEM_CONFIG2_SPARE_REG28_SECURE_BMSK                                                    0x1000
#define HWIO_OEM_CONFIG2_SPARE_REG28_SECURE_SHFT                                                       0xc
#define HWIO_OEM_CONFIG2_SPARE_REG28_SECURE_NOT_SECURE_FVAL                                            0x0
#define HWIO_OEM_CONFIG2_SPARE_REG28_SECURE_SECURE_FVAL                                                0x1
#define HWIO_OEM_CONFIG2_RSVD3_BMSK                                                                  0x800
#define HWIO_OEM_CONFIG2_RSVD3_SHFT                                                                    0xb
#define HWIO_OEM_CONFIG2_SPU_IAR_ENABLED_BMSK                                                        0x400
#define HWIO_OEM_CONFIG2_SPU_IAR_ENABLED_SHFT                                                          0xa
#define HWIO_OEM_CONFIG2_RSVD1_BMSK                                                                  0x300
#define HWIO_OEM_CONFIG2_RSVD1_SHFT                                                                    0x8
#define HWIO_OEM_CONFIG2_TZ_SW_CRYPTO_FIPS_OVERRIDE_BMSK                                              0x80
#define HWIO_OEM_CONFIG2_TZ_SW_CRYPTO_FIPS_OVERRIDE_SHFT                                               0x7
#define HWIO_OEM_CONFIG2_SP_FIPS_OVERRIDE_BMSK                                                        0x40
#define HWIO_OEM_CONFIG2_SP_FIPS_OVERRIDE_SHFT                                                         0x6
#define HWIO_OEM_CONFIG2_MODEM_CRYPTO_FIPS_ENABLE_BMSK                                                0x20
#define HWIO_OEM_CONFIG2_MODEM_CRYPTO_FIPS_ENABLE_SHFT                                                 0x5
#define HWIO_OEM_CONFIG2_TZ_SW_CRYPTO_FIPS_ENABLE_BMSK                                                0x10
#define HWIO_OEM_CONFIG2_TZ_SW_CRYPTO_FIPS_ENABLE_SHFT                                                 0x4
#define HWIO_OEM_CONFIG2_SP_FIPS_ENABLE_BMSK                                                           0x8
#define HWIO_OEM_CONFIG2_SP_FIPS_ENABLE_SHFT                                                           0x3
#define HWIO_OEM_CONFIG2_SP_NVM_AR_CONFIG_BMSK                                                         0x6
#define HWIO_OEM_CONFIG2_SP_NVM_AR_CONFIG_SHFT                                                         0x1
#define HWIO_OEM_CONFIG2_RSVD0_BMSK                                                                    0x1
#define HWIO_OEM_CONFIG2_RSVD0_SHFT                                                                    0x0

#define HWIO_OEM_CONFIG3_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006050)
#define HWIO_OEM_CONFIG3_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006050)
#define HWIO_OEM_CONFIG3_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006050)
#define HWIO_OEM_CONFIG3_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG3_IN          \
        in_dword(HWIO_OEM_CONFIG3_ADDR)
#define HWIO_OEM_CONFIG3_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG3_ADDR, m)
#define HWIO_OEM_CONFIG3_OEM_PRODUCT_ID_BMSK                                                    0xffff0000
#define HWIO_OEM_CONFIG3_OEM_PRODUCT_ID_SHFT                                                          0x10
#define HWIO_OEM_CONFIG3_OEM_HW_ID_BMSK                                                             0xffff
#define HWIO_OEM_CONFIG3_OEM_HW_ID_SHFT                                                                0x0

#define HWIO_OEM_CONFIG4_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006054)
#define HWIO_OEM_CONFIG4_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006054)
#define HWIO_OEM_CONFIG4_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006054)
#define HWIO_OEM_CONFIG4_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG4_IN          \
        in_dword(HWIO_OEM_CONFIG4_ADDR)
#define HWIO_OEM_CONFIG4_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG4_ADDR, m)
#define HWIO_OEM_CONFIG4_PERIPH_VID_BMSK                                                        0xffff0000
#define HWIO_OEM_CONFIG4_PERIPH_VID_SHFT                                                              0x10
#define HWIO_OEM_CONFIG4_PERIPH_PID_BMSK                                                            0xffff
#define HWIO_OEM_CONFIG4_PERIPH_PID_SHFT                                                               0x0

#define HWIO_OEM_CONFIG5_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006058)
#define HWIO_OEM_CONFIG5_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006058)
#define HWIO_OEM_CONFIG5_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006058)
#define HWIO_OEM_CONFIG5_RMSK                                                                   0xffffffff
#define HWIO_OEM_CONFIG5_IN          \
        in_dword(HWIO_OEM_CONFIG5_ADDR)
#define HWIO_OEM_CONFIG5_INM(m)      \
        in_dword_masked(HWIO_OEM_CONFIG5_ADDR, m)
#define HWIO_OEM_CONFIG5_RSVD0_BMSK                                                             0xffffff00
#define HWIO_OEM_CONFIG5_RSVD0_SHFT                                                                    0x8
#define HWIO_OEM_CONFIG5_ANTI_ROLLBACK_FEATURE_EN_BMSK                                                0xff
#define HWIO_OEM_CONFIG5_ANTI_ROLLBACK_FEATURE_EN_SHFT                                                 0x0

#define HWIO_BOOT_CONFIG_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006070)
#define HWIO_BOOT_CONFIG_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006070)
#define HWIO_BOOT_CONFIG_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006070)
#define HWIO_BOOT_CONFIG_RMSK                                                                        0x1ff
#define HWIO_BOOT_CONFIG_IN          \
        in_dword(HWIO_BOOT_CONFIG_ADDR)
#define HWIO_BOOT_CONFIG_INM(m)      \
        in_dword_masked(HWIO_BOOT_CONFIG_ADDR, m)
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_BMSK                                                    0x180
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_SHFT                                                      0x7
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_ENUM_600_MHZ_FVAL                                         0x0
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_ENUM_300_MHZ_FVAL                                         0x1
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_CXO_FVAL                                                  0x2
#define HWIO_BOOT_CONFIG_APPS_PBL_BOOT_SPEED_NA_FVAL                                                   0x3
#define HWIO_BOOT_CONFIG_APPS_BOOT_FROM_ROM_BMSK                                                      0x40
#define HWIO_BOOT_CONFIG_APPS_BOOT_FROM_ROM_SHFT                                                       0x6
#define HWIO_BOOT_CONFIG_FAST_BOOT_BMSK                                                               0x3e
#define HWIO_BOOT_CONFIG_FAST_BOOT_SHFT                                                                0x1
#define HWIO_BOOT_CONFIG_FAST_BOOT_DEFAULT_FVAL                                                        0x0
#define HWIO_BOOT_CONFIG_FAST_BOOT_PCIE_FVAL                                                           0x1
#define HWIO_BOOT_CONFIG_FAST_BOOT_USB_FVAL                                                            0x2
#define HWIO_BOOT_CONFIG_FAST_BOOT_EMMC_USB_FVAL                                                       0x3
#define HWIO_BOOT_CONFIG_WDOG_EN_BMSK                                                                  0x1
#define HWIO_BOOT_CONFIG_WDOG_EN_SHFT                                                                  0x0
#define HWIO_BOOT_CONFIG_WDOG_EN_GPIO_CONTROLLED_FVAL                                                  0x0
#define HWIO_BOOT_CONFIG_WDOG_EN_ENABLE_WDOG_FVAL                                                      0x1

#define HWIO_SECURE_BOOTn_ADDR(n)                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006078 + 0x4 * (n))
#define HWIO_SECURE_BOOTn_PHYS(n)                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006078 + 0x4 * (n))
#define HWIO_SECURE_BOOTn_OFFS(n)                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006078 + 0x4 * (n))
#define HWIO_SECURE_BOOTn_RMSK                                                                       0x1ff
#define HWIO_SECURE_BOOTn_MAXn                                                                          14
#define HWIO_SECURE_BOOTn_INI(n)        \
        in_dword_masked(HWIO_SECURE_BOOTn_ADDR(n), HWIO_SECURE_BOOTn_RMSK)
#define HWIO_SECURE_BOOTn_INMI(n,mask)    \
        in_dword_masked(HWIO_SECURE_BOOTn_ADDR(n), mask)
#define HWIO_SECURE_BOOTn_FUSE_SRC_BMSK                                                              0x100
#define HWIO_SECURE_BOOTn_FUSE_SRC_SHFT                                                                0x8
#define HWIO_SECURE_BOOTn_FUSE_SRC_QUALCOMM_FVAL                                                       0x0
#define HWIO_SECURE_BOOTn_FUSE_SRC_OEM_FVAL                                                            0x1
#define HWIO_SECURE_BOOTn_RSVD_7_BMSK                                                                 0x80
#define HWIO_SECURE_BOOTn_RSVD_7_SHFT                                                                  0x7
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_BMSK                                                         0x40
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_SHFT                                                          0x6
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_USE_OEM_ID_FVAL                                               0x0
#define HWIO_SECURE_BOOTn_USE_SERIAL_NUM_USE_SERIAL_NUM_FVAL                                           0x1
#define HWIO_SECURE_BOOTn_AUTH_EN_BMSK                                                                0x20
#define HWIO_SECURE_BOOTn_AUTH_EN_SHFT                                                                 0x5
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_BMSK                                                        0x10
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_SHFT                                                         0x4
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_SHA_256_HASH_OF_ROOT_CERTIFICATE_IS_IN_ROM_FVAL              0x0
#define HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_SHA_256_HASH_OF_ROOT_CERTIFICATE_IS_IN_PK_HASH_FVAL          0x1
#define HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_BMSK                                                       0xf
#define HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_SHFT                                                       0x0

#define HWIO_QSEE_INV_OVERRIDE_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c0)
#define HWIO_QSEE_INV_OVERRIDE_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060c0)
#define HWIO_QSEE_INV_OVERRIDE_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060c0)
#define HWIO_QSEE_INV_OVERRIDE_RMSK                                                             0xffffffff
#define HWIO_QSEE_INV_OVERRIDE_IN          \
        in_dword(HWIO_QSEE_INV_OVERRIDE_ADDR)
#define HWIO_QSEE_INV_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_QSEE_INV_OVERRIDE_ADDR, m)
#define HWIO_QSEE_INV_OVERRIDE_OUT(v)      \
        out_dword(HWIO_QSEE_INV_OVERRIDE_ADDR,v)
#define HWIO_QSEE_INV_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QSEE_INV_OVERRIDE_ADDR,m,v,HWIO_QSEE_INV_OVERRIDE_IN)
#define HWIO_QSEE_INV_OVERRIDE_RSVD_31_1_BMSK                                                   0xfffffffe
#define HWIO_QSEE_INV_OVERRIDE_RSVD_31_1_SHFT                                                          0x1
#define HWIO_QSEE_INV_OVERRIDE_SHARED_QSEE_SPIDEN_DISABLE_BMSK                                         0x1
#define HWIO_QSEE_INV_OVERRIDE_SHARED_QSEE_SPIDEN_DISABLE_SHFT                                         0x0
#define HWIO_QSEE_INV_OVERRIDE_SHARED_QSEE_SPIDEN_DISABLE_FUSE_VALUE_FVAL                              0x0
#define HWIO_QSEE_INV_OVERRIDE_SHARED_QSEE_SPIDEN_DISABLE_QC_FUSE_VALUE_FVAL                           0x1

#define HWIO_QSEE_NI_OVERRIDE_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c4)
#define HWIO_QSEE_NI_OVERRIDE_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060c4)
#define HWIO_QSEE_NI_OVERRIDE_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060c4)
#define HWIO_QSEE_NI_OVERRIDE_RMSK                                                              0xffffffff
#define HWIO_QSEE_NI_OVERRIDE_IN          \
        in_dword(HWIO_QSEE_NI_OVERRIDE_ADDR)
#define HWIO_QSEE_NI_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_QSEE_NI_OVERRIDE_ADDR, m)
#define HWIO_QSEE_NI_OVERRIDE_OUT(v)      \
        out_dword(HWIO_QSEE_NI_OVERRIDE_ADDR,v)
#define HWIO_QSEE_NI_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QSEE_NI_OVERRIDE_ADDR,m,v,HWIO_QSEE_NI_OVERRIDE_IN)
#define HWIO_QSEE_NI_OVERRIDE_RSVD_31_1_BMSK                                                    0xfffffffe
#define HWIO_QSEE_NI_OVERRIDE_RSVD_31_1_SHFT                                                           0x1
#define HWIO_QSEE_NI_OVERRIDE_SHARED_QSEE_SPNIDEN_DISABLE_BMSK                                         0x1
#define HWIO_QSEE_NI_OVERRIDE_SHARED_QSEE_SPNIDEN_DISABLE_SHFT                                         0x0
#define HWIO_QSEE_NI_OVERRIDE_SHARED_QSEE_SPNIDEN_DISABLE_FUSE_VALUE_FVAL                              0x0
#define HWIO_QSEE_NI_OVERRIDE_SHARED_QSEE_SPNIDEN_DISABLE_QC_FUSE_VALUE_FVAL                           0x1

#define HWIO_MSS_INV_OVERRIDE_ADDR                                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060c8)
#define HWIO_MSS_INV_OVERRIDE_PHYS                                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060c8)
#define HWIO_MSS_INV_OVERRIDE_OFFS                                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060c8)
#define HWIO_MSS_INV_OVERRIDE_RMSK                                                              0xffffffff
#define HWIO_MSS_INV_OVERRIDE_IN          \
        in_dword(HWIO_MSS_INV_OVERRIDE_ADDR)
#define HWIO_MSS_INV_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_MSS_INV_OVERRIDE_ADDR, m)
#define HWIO_MSS_INV_OVERRIDE_OUT(v)      \
        out_dword(HWIO_MSS_INV_OVERRIDE_ADDR,v)
#define HWIO_MSS_INV_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_MSS_INV_OVERRIDE_ADDR,m,v,HWIO_MSS_INV_OVERRIDE_IN)
#define HWIO_MSS_INV_OVERRIDE_RSVD_31_1_BMSK                                                    0xfffffffe
#define HWIO_MSS_INV_OVERRIDE_RSVD_31_1_SHFT                                                           0x1
#define HWIO_MSS_INV_OVERRIDE_SHARED_MSS_DBGEN_DISABLE_BMSK                                            0x1
#define HWIO_MSS_INV_OVERRIDE_SHARED_MSS_DBGEN_DISABLE_SHFT                                            0x0
#define HWIO_MSS_INV_OVERRIDE_SHARED_MSS_DBGEN_DISABLE_FUSE_VALUE_FVAL                                 0x0
#define HWIO_MSS_INV_OVERRIDE_SHARED_MSS_DBGEN_DISABLE_QC_FUSE_VALUE_FVAL                              0x1

#define HWIO_MSS_NI_OVERRIDE_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060cc)
#define HWIO_MSS_NI_OVERRIDE_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060cc)
#define HWIO_MSS_NI_OVERRIDE_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060cc)
#define HWIO_MSS_NI_OVERRIDE_RMSK                                                               0xffffffff
#define HWIO_MSS_NI_OVERRIDE_IN          \
        in_dword(HWIO_MSS_NI_OVERRIDE_ADDR)
#define HWIO_MSS_NI_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_MSS_NI_OVERRIDE_ADDR, m)
#define HWIO_MSS_NI_OVERRIDE_OUT(v)      \
        out_dword(HWIO_MSS_NI_OVERRIDE_ADDR,v)
#define HWIO_MSS_NI_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_MSS_NI_OVERRIDE_ADDR,m,v,HWIO_MSS_NI_OVERRIDE_IN)
#define HWIO_MSS_NI_OVERRIDE_RSVD_31_1_BMSK                                                     0xfffffffe
#define HWIO_MSS_NI_OVERRIDE_RSVD_31_1_SHFT                                                            0x1
#define HWIO_MSS_NI_OVERRIDE_SHARED_MSS_NIDEN_DISABLE_BMSK                                             0x1
#define HWIO_MSS_NI_OVERRIDE_SHARED_MSS_NIDEN_DISABLE_SHFT                                             0x0
#define HWIO_MSS_NI_OVERRIDE_SHARED_MSS_NIDEN_DISABLE_FUSE_VALUE_FVAL                                  0x0
#define HWIO_MSS_NI_OVERRIDE_SHARED_MSS_NIDEN_DISABLE_QC_FUSE_VALUE_FVAL                               0x1

#define HWIO_CP_INV_OVERRIDE_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d0)
#define HWIO_CP_INV_OVERRIDE_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060d0)
#define HWIO_CP_INV_OVERRIDE_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060d0)
#define HWIO_CP_INV_OVERRIDE_RMSK                                                               0xffffffff
#define HWIO_CP_INV_OVERRIDE_IN          \
        in_dword(HWIO_CP_INV_OVERRIDE_ADDR)
#define HWIO_CP_INV_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_CP_INV_OVERRIDE_ADDR, m)
#define HWIO_CP_INV_OVERRIDE_OUT(v)      \
        out_dword(HWIO_CP_INV_OVERRIDE_ADDR,v)
#define HWIO_CP_INV_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CP_INV_OVERRIDE_ADDR,m,v,HWIO_CP_INV_OVERRIDE_IN)
#define HWIO_CP_INV_OVERRIDE_RSVD_31_1_BMSK                                                     0xfffffffe
#define HWIO_CP_INV_OVERRIDE_RSVD_31_1_SHFT                                                            0x1
#define HWIO_CP_INV_OVERRIDE_SHARED_CP_DBGEN_DISABLE_BMSK                                              0x1
#define HWIO_CP_INV_OVERRIDE_SHARED_CP_DBGEN_DISABLE_SHFT                                              0x0
#define HWIO_CP_INV_OVERRIDE_SHARED_CP_DBGEN_DISABLE_FUSE_VALUE_FVAL                                   0x0
#define HWIO_CP_INV_OVERRIDE_SHARED_CP_DBGEN_DISABLE_QC_FUSE_VALUE_FVAL                                0x1

#define HWIO_CP_NI_OVERRIDE_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d4)
#define HWIO_CP_NI_OVERRIDE_PHYS                                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060d4)
#define HWIO_CP_NI_OVERRIDE_OFFS                                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060d4)
#define HWIO_CP_NI_OVERRIDE_RMSK                                                                0xffffffff
#define HWIO_CP_NI_OVERRIDE_IN          \
        in_dword(HWIO_CP_NI_OVERRIDE_ADDR)
#define HWIO_CP_NI_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_CP_NI_OVERRIDE_ADDR, m)
#define HWIO_CP_NI_OVERRIDE_OUT(v)      \
        out_dword(HWIO_CP_NI_OVERRIDE_ADDR,v)
#define HWIO_CP_NI_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CP_NI_OVERRIDE_ADDR,m,v,HWIO_CP_NI_OVERRIDE_IN)
#define HWIO_CP_NI_OVERRIDE_RSVD_31_1_BMSK                                                      0xfffffffe
#define HWIO_CP_NI_OVERRIDE_RSVD_31_1_SHFT                                                             0x1
#define HWIO_CP_NI_OVERRIDE_SHARED_CP_NIDEN_DISABLE_BMSK                                               0x1
#define HWIO_CP_NI_OVERRIDE_SHARED_CP_NIDEN_DISABLE_SHFT                                               0x0
#define HWIO_CP_NI_OVERRIDE_SHARED_CP_NIDEN_DISABLE_FUSE_VALUE_FVAL                                    0x0
#define HWIO_CP_NI_OVERRIDE_SHARED_CP_NIDEN_DISABLE_QC_FUSE_VALUE_FVAL                                 0x1

#define HWIO_NS_INV_OVERRIDE_ADDR                                                               (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060d8)
#define HWIO_NS_INV_OVERRIDE_PHYS                                                               (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060d8)
#define HWIO_NS_INV_OVERRIDE_OFFS                                                               (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060d8)
#define HWIO_NS_INV_OVERRIDE_RMSK                                                               0xffffffff
#define HWIO_NS_INV_OVERRIDE_IN          \
        in_dword(HWIO_NS_INV_OVERRIDE_ADDR)
#define HWIO_NS_INV_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_NS_INV_OVERRIDE_ADDR, m)
#define HWIO_NS_INV_OVERRIDE_OUT(v)      \
        out_dword(HWIO_NS_INV_OVERRIDE_ADDR,v)
#define HWIO_NS_INV_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_NS_INV_OVERRIDE_ADDR,m,v,HWIO_NS_INV_OVERRIDE_IN)
#define HWIO_NS_INV_OVERRIDE_RSVD_31_5_BMSK                                                     0xffffffe0
#define HWIO_NS_INV_OVERRIDE_RSVD_31_5_SHFT                                                            0x5
#define HWIO_NS_INV_OVERRIDE_APPS_DBGEN_DISABLE_BMSK                                                  0x10
#define HWIO_NS_INV_OVERRIDE_APPS_DBGEN_DISABLE_SHFT                                                   0x4
#define HWIO_NS_INV_OVERRIDE_APPS_DBGEN_DISABLE_FUSE_VALUE_FVAL                                        0x0
#define HWIO_NS_INV_OVERRIDE_APPS_DBGEN_DISABLE_QC_FUSE_VALUE_FVAL                                     0x1
#define HWIO_NS_INV_OVERRIDE_RSVD_3_1_BMSK                                                             0xe
#define HWIO_NS_INV_OVERRIDE_RSVD_3_1_SHFT                                                             0x1
#define HWIO_NS_INV_OVERRIDE_SHARED_NS_DBGEN_DISABLE_BMSK                                              0x1
#define HWIO_NS_INV_OVERRIDE_SHARED_NS_DBGEN_DISABLE_SHFT                                              0x0
#define HWIO_NS_INV_OVERRIDE_SHARED_NS_DBGEN_DISABLE_FUSE_VALUE_FVAL                                   0x0
#define HWIO_NS_INV_OVERRIDE_SHARED_NS_DBGEN_DISABLE_QC_FUSE_VALUE_FVAL                                0x1

#define HWIO_NS_NI_OVERRIDE_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060dc)
#define HWIO_NS_NI_OVERRIDE_PHYS                                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060dc)
#define HWIO_NS_NI_OVERRIDE_OFFS                                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060dc)
#define HWIO_NS_NI_OVERRIDE_RMSK                                                                0xffffffff
#define HWIO_NS_NI_OVERRIDE_IN          \
        in_dword(HWIO_NS_NI_OVERRIDE_ADDR)
#define HWIO_NS_NI_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_NS_NI_OVERRIDE_ADDR, m)
#define HWIO_NS_NI_OVERRIDE_OUT(v)      \
        out_dword(HWIO_NS_NI_OVERRIDE_ADDR,v)
#define HWIO_NS_NI_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_NS_NI_OVERRIDE_ADDR,m,v,HWIO_NS_NI_OVERRIDE_IN)
#define HWIO_NS_NI_OVERRIDE_RSVD_31_5_BMSK                                                      0xffffffe0
#define HWIO_NS_NI_OVERRIDE_RSVD_31_5_SHFT                                                             0x5
#define HWIO_NS_NI_OVERRIDE_APPS_NIDEN_DISABLE_BMSK                                                   0x10
#define HWIO_NS_NI_OVERRIDE_APPS_NIDEN_DISABLE_SHFT                                                    0x4
#define HWIO_NS_NI_OVERRIDE_APPS_NIDEN_DISABLE_FUSE_VALUE_FVAL                                         0x0
#define HWIO_NS_NI_OVERRIDE_APPS_NIDEN_DISABLE_QC_FUSE_VALUE_FVAL                                      0x1
#define HWIO_NS_NI_OVERRIDE_RSVD_3_1_BMSK                                                              0xe
#define HWIO_NS_NI_OVERRIDE_RSVD_3_1_SHFT                                                              0x1
#define HWIO_NS_NI_OVERRIDE_SHARED_NS_NIDEN_DISABLE_BMSK                                               0x1
#define HWIO_NS_NI_OVERRIDE_SHARED_NS_NIDEN_DISABLE_SHFT                                               0x0
#define HWIO_NS_NI_OVERRIDE_SHARED_NS_NIDEN_DISABLE_FUSE_VALUE_FVAL                                    0x0
#define HWIO_NS_NI_OVERRIDE_SHARED_NS_NIDEN_DISABLE_QC_FUSE_VALUE_FVAL                                 0x1

#define HWIO_MISC_DEBUG_OVERRIDE_ADDR                                                           (SECURITY_CONTROL_CORE_REG_BASE      + 0x000060e0)
#define HWIO_MISC_DEBUG_OVERRIDE_PHYS                                                           (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000060e0)
#define HWIO_MISC_DEBUG_OVERRIDE_OFFS                                                           (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000060e0)
#define HWIO_MISC_DEBUG_OVERRIDE_RMSK                                                           0xffffffff
#define HWIO_MISC_DEBUG_OVERRIDE_IN          \
        in_dword(HWIO_MISC_DEBUG_OVERRIDE_ADDR)
#define HWIO_MISC_DEBUG_OVERRIDE_INM(m)      \
        in_dword_masked(HWIO_MISC_DEBUG_OVERRIDE_ADDR, m)
#define HWIO_MISC_DEBUG_OVERRIDE_OUT(v)      \
        out_dword(HWIO_MISC_DEBUG_OVERRIDE_ADDR,v)
#define HWIO_MISC_DEBUG_OVERRIDE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_MISC_DEBUG_OVERRIDE_ADDR,m,v,HWIO_MISC_DEBUG_OVERRIDE_IN)
#define HWIO_MISC_DEBUG_OVERRIDE_RSVD_31_6_BMSK                                                 0xffffffc0
#define HWIO_MISC_DEBUG_OVERRIDE_RSVD_31_6_SHFT                                                        0x6
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC5_DEBUG_DISABLE_BMSK                                      0x20
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC5_DEBUG_DISABLE_SHFT                                       0x5
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC5_DEBUG_DISABLE_FUSE_VALUE_FVAL                            0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC5_DEBUG_DISABLE_ZERO_FVAL                                  0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC4_DEBUG_DISABLE_BMSK                                      0x10
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC4_DEBUG_DISABLE_SHFT                                       0x4
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC4_DEBUG_DISABLE_FUSE_VALUE_FVAL                            0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC4_DEBUG_DISABLE_ZERO_FVAL                                  0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC3_DEBUG_DISABLE_BMSK                                       0x8
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC3_DEBUG_DISABLE_SHFT                                       0x3
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC3_DEBUG_DISABLE_FUSE_VALUE_FVAL                            0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC3_DEBUG_DISABLE_ZERO_FVAL                                  0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC2_DEBUG_DISABLE_BMSK                                       0x4
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC2_DEBUG_DISABLE_SHFT                                       0x2
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC2_DEBUG_DISABLE_FUSE_VALUE_FVAL                            0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC2_DEBUG_DISABLE_ZERO_FVAL                                  0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC1_DEBUG_DISABLE_BMSK                                       0x2
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC1_DEBUG_DISABLE_SHFT                                       0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC1_DEBUG_DISABLE_FUSE_VALUE_FVAL                            0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC1_DEBUG_DISABLE_ZERO_FVAL                                  0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC_DEBUG_DISABLE_BMSK                                        0x1
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC_DEBUG_DISABLE_SHFT                                        0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC_DEBUG_DISABLE_FUSE_VALUE_FVAL                             0x0
#define HWIO_MISC_DEBUG_OVERRIDE_SHARED_MISC_DEBUG_DISABLE_QC_FUSE_VALUE_FVAL                          0x1

#define HWIO_CAPT_SEC_GPIO_ADDR                                                                 (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006100)
#define HWIO_CAPT_SEC_GPIO_PHYS                                                                 (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006100)
#define HWIO_CAPT_SEC_GPIO_OFFS                                                                 (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006100)
#define HWIO_CAPT_SEC_GPIO_RMSK                                                                     0x1fff
#define HWIO_CAPT_SEC_GPIO_IN          \
        in_dword(HWIO_CAPT_SEC_GPIO_ADDR)
#define HWIO_CAPT_SEC_GPIO_INM(m)      \
        in_dword_masked(HWIO_CAPT_SEC_GPIO_ADDR, m)
#define HWIO_CAPT_SEC_GPIO_OUT(v)      \
        out_dword(HWIO_CAPT_SEC_GPIO_ADDR,v)
#define HWIO_CAPT_SEC_GPIO_OUTM(m,v) \
        out_dword_masked_ns(HWIO_CAPT_SEC_GPIO_ADDR,m,v,HWIO_CAPT_SEC_GPIO_IN)
#define HWIO_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_BMSK                                                 0x1000
#define HWIO_CAPT_SEC_GPIO_FORCE_USB_BOOT_GPIO_SHFT                                                    0xc
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_BMSK                                          0x800
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_AUTH_EN_SHFT                                            0xb
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_BMSK                                  0x400
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_AP_PK_HASH_IN_FUSE_SHFT                                    0xa
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_BMSK                                  0x200
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_ALL_USE_SERIAL_NUM_SHFT                                    0x9
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_BMSK                                   0x100
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_PK_HASH_INDEX_SRC_SHFT                                     0x8
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_BMSK                                  0xc0
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_PBL_BOOT_SPEED_SHFT                                   0x6
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_BOOT_FROM_ROM_BMSK                                   0x20
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_APPS_BOOT_FROM_ROM_SHFT                                    0x5
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_BMSK                                            0x1e
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_FAST_BOOT_SHFT                                             0x1
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_BMSK                                          0x1
#define HWIO_CAPT_SEC_GPIO_BOOT_CONFIG_GPIO_WDOG_DISABLE_SHFT                                          0x0

#define HWIO_APP_PROC_CFG_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006110)
#define HWIO_APP_PROC_CFG_PHYS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006110)
#define HWIO_APP_PROC_CFG_OFFS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006110)
#define HWIO_APP_PROC_CFG_RMSK                                                                     0xfffff
#define HWIO_APP_PROC_CFG_IN          \
        in_dword(HWIO_APP_PROC_CFG_ADDR)
#define HWIO_APP_PROC_CFG_INM(m)      \
        in_dword_masked(HWIO_APP_PROC_CFG_ADDR, m)
#define HWIO_APP_PROC_CFG_OUT(v)      \
        out_dword(HWIO_APP_PROC_CFG_ADDR,v)
#define HWIO_APP_PROC_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_APP_PROC_CFG_ADDR,m,v,HWIO_APP_PROC_CFG_IN)
#define HWIO_APP_PROC_CFG_SPARE0_BMSK                                                              0xc0000
#define HWIO_APP_PROC_CFG_SPARE0_SHFT                                                                 0x12
#define HWIO_APP_PROC_CFG_SPARE1_BMSK                                                              0x30000
#define HWIO_APP_PROC_CFG_SPARE1_SHFT                                                                 0x10
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC2_BMSK                                                       0xf000
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC2_SHFT                                                          0xc
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC1_BMSK                                                        0xf00
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC1_SHFT                                                          0x8
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC0_BMSK                                                         0xc0
#define HWIO_APP_PROC_CFG_APPS_CFG_MISC0_SHFT                                                          0x6
#define HWIO_APP_PROC_CFG_APPS_CP15_DISABLE_BMSK                                                      0x20
#define HWIO_APP_PROC_CFG_APPS_CP15_DISABLE_SHFT                                                       0x5
#define HWIO_APP_PROC_CFG_APPS_CFG_NMFI_BMSK                                                          0x10
#define HWIO_APP_PROC_CFG_APPS_CFG_NMFI_SHFT                                                           0x4
#define HWIO_APP_PROC_CFG_APPS_CFG_NMFI_NORMAL_FVAL                                                    0x0
#define HWIO_APP_PROC_CFG_APPS_CFG_NMFI_DISABLE_FVAL                                                   0x1
#define HWIO_APP_PROC_CFG_SHARED_QSEE_SPNIDEN_BMSK                                                     0x8
#define HWIO_APP_PROC_CFG_SHARED_QSEE_SPNIDEN_SHFT                                                     0x3
#define HWIO_APP_PROC_CFG_SHARED_CP_NIDEN_BMSK                                                         0x4
#define HWIO_APP_PROC_CFG_SHARED_CP_NIDEN_SHFT                                                         0x2
#define HWIO_APP_PROC_CFG_SHARED_NS_NIDEN_BMSK                                                         0x2
#define HWIO_APP_PROC_CFG_SHARED_NS_NIDEN_SHFT                                                         0x1
#define HWIO_APP_PROC_CFG_APPS_NIDEN_BMSK                                                              0x1
#define HWIO_APP_PROC_CFG_APPS_NIDEN_SHFT                                                              0x0

#define HWIO_MSS_PROC_CFG_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006114)
#define HWIO_MSS_PROC_CFG_PHYS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006114)
#define HWIO_MSS_PROC_CFG_OFFS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006114)
#define HWIO_MSS_PROC_CFG_RMSK                                                                         0x1
#define HWIO_MSS_PROC_CFG_IN          \
        in_dword(HWIO_MSS_PROC_CFG_ADDR)
#define HWIO_MSS_PROC_CFG_INM(m)      \
        in_dword_masked(HWIO_MSS_PROC_CFG_ADDR, m)
#define HWIO_MSS_PROC_CFG_OUT(v)      \
        out_dword(HWIO_MSS_PROC_CFG_ADDR,v)
#define HWIO_MSS_PROC_CFG_OUTM(m,v) \
        out_dword_masked_ns(HWIO_MSS_PROC_CFG_ADDR,m,v,HWIO_MSS_PROC_CFG_IN)
#define HWIO_MSS_PROC_CFG_SHARED_MSS_NIDEN_BMSK                                                        0x1
#define HWIO_MSS_PROC_CFG_SHARED_MSS_NIDEN_SHFT                                                        0x0

#define HWIO_QFPROM_CLK_CTL_ADDR                                                                (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006118)
#define HWIO_QFPROM_CLK_CTL_PHYS                                                                (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006118)
#define HWIO_QFPROM_CLK_CTL_OFFS                                                                (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006118)
#define HWIO_QFPROM_CLK_CTL_RMSK                                                                       0x1
#define HWIO_QFPROM_CLK_CTL_IN          \
        in_dword(HWIO_QFPROM_CLK_CTL_ADDR)
#define HWIO_QFPROM_CLK_CTL_INM(m)      \
        in_dword_masked(HWIO_QFPROM_CLK_CTL_ADDR, m)
#define HWIO_QFPROM_CLK_CTL_OUT(v)      \
        out_dword(HWIO_QFPROM_CLK_CTL_ADDR,v)
#define HWIO_QFPROM_CLK_CTL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_CLK_CTL_ADDR,m,v,HWIO_QFPROM_CLK_CTL_IN)
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_BMSK                                                              0x1
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_SHFT                                                              0x0
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_CLK_ENABLED_FVAL                                                  0x0
#define HWIO_QFPROM_CLK_CTL_CLK_HALT_CLK_DISABLED_FVAL                                                 0x1

#define HWIO_JTAG_ID_ADDR                                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006130)
#define HWIO_JTAG_ID_PHYS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006130)
#define HWIO_JTAG_ID_OFFS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006130)
#define HWIO_JTAG_ID_RMSK                                                                       0xffffffff
#define HWIO_JTAG_ID_IN          \
        in_dword(HWIO_JTAG_ID_ADDR)
#define HWIO_JTAG_ID_INM(m)      \
        in_dword_masked(HWIO_JTAG_ID_ADDR, m)
#define HWIO_JTAG_ID_JTAG_ID_BMSK                                                               0xffffffff
#define HWIO_JTAG_ID_JTAG_ID_SHFT                                                                      0x0

#define HWIO_SERIAL_NUM_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006134)
#define HWIO_SERIAL_NUM_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006134)
#define HWIO_SERIAL_NUM_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006134)
#define HWIO_SERIAL_NUM_RMSK                                                                    0xffffffff
#define HWIO_SERIAL_NUM_IN          \
        in_dword(HWIO_SERIAL_NUM_ADDR)
#define HWIO_SERIAL_NUM_INM(m)      \
        in_dword_masked(HWIO_SERIAL_NUM_ADDR, m)
#define HWIO_SERIAL_NUM_SERIAL_NUM_BMSK                                                         0xffffffff
#define HWIO_SERIAL_NUM_SERIAL_NUM_SHFT                                                                0x0

#define HWIO_OEM_ID_ADDR                                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006138)
#define HWIO_OEM_ID_PHYS                                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006138)
#define HWIO_OEM_ID_OFFS                                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006138)
#define HWIO_OEM_ID_RMSK                                                                        0xffffffff
#define HWIO_OEM_ID_IN          \
        in_dword(HWIO_OEM_ID_ADDR)
#define HWIO_OEM_ID_INM(m)      \
        in_dword_masked(HWIO_OEM_ID_ADDR, m)
#define HWIO_OEM_ID_OEM_ID_BMSK                                                                 0xffff0000
#define HWIO_OEM_ID_OEM_ID_SHFT                                                                       0x10
#define HWIO_OEM_ID_OEM_PRODUCT_ID_BMSK                                                             0xffff
#define HWIO_OEM_ID_OEM_PRODUCT_ID_SHFT                                                                0x0

#define HWIO_TEST_BUS_SEL_ADDR                                                                  (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000613c)
#define HWIO_TEST_BUS_SEL_PHYS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000613c)
#define HWIO_TEST_BUS_SEL_OFFS                                                                  (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000613c)
#define HWIO_TEST_BUS_SEL_RMSK                                                                         0x7
#define HWIO_TEST_BUS_SEL_IN          \
        in_dword(HWIO_TEST_BUS_SEL_ADDR)
#define HWIO_TEST_BUS_SEL_INM(m)      \
        in_dword_masked(HWIO_TEST_BUS_SEL_ADDR, m)
#define HWIO_TEST_BUS_SEL_OUT(v)      \
        out_dword(HWIO_TEST_BUS_SEL_ADDR,v)
#define HWIO_TEST_BUS_SEL_OUTM(m,v) \
        out_dword_masked_ns(HWIO_TEST_BUS_SEL_ADDR,m,v,HWIO_TEST_BUS_SEL_IN)
#define HWIO_TEST_BUS_SEL_TEST_EN_BMSK                                                                 0x4
#define HWIO_TEST_BUS_SEL_TEST_EN_SHFT                                                                 0x2
#define HWIO_TEST_BUS_SEL_TEST_EN_DEBUG_DISABLED_FVAL                                                  0x0
#define HWIO_TEST_BUS_SEL_TEST_EN_DEBUG_ENABLED_FVAL                                                   0x1
#define HWIO_TEST_BUS_SEL_TEST_SELECT_BMSK                                                             0x3
#define HWIO_TEST_BUS_SEL_TEST_SELECT_SHFT                                                             0x0
#define HWIO_TEST_BUS_SEL_TEST_SELECT_FUSE_SENSE_FVAL                                                  0x0
#define HWIO_TEST_BUS_SEL_TEST_SELECT_QFPROM_ARBITER_FVAL                                              0x1
#define HWIO_TEST_BUS_SEL_TEST_SELECT_SW_FVAL                                                          0x2
#define HWIO_TEST_BUS_SEL_TEST_SELECT_ACC_FVAL                                                         0x3

#define HWIO_SPDM_DYN_SECURE_MODE_ADDR                                                          (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006140)
#define HWIO_SPDM_DYN_SECURE_MODE_PHYS                                                          (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006140)
#define HWIO_SPDM_DYN_SECURE_MODE_OFFS                                                          (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006140)
#define HWIO_SPDM_DYN_SECURE_MODE_RMSK                                                                 0x1
#define HWIO_SPDM_DYN_SECURE_MODE_IN          \
        in_dword(HWIO_SPDM_DYN_SECURE_MODE_ADDR)
#define HWIO_SPDM_DYN_SECURE_MODE_INM(m)      \
        in_dword_masked(HWIO_SPDM_DYN_SECURE_MODE_ADDR, m)
#define HWIO_SPDM_DYN_SECURE_MODE_OUT(v)      \
        out_dword(HWIO_SPDM_DYN_SECURE_MODE_ADDR,v)
#define HWIO_SPDM_DYN_SECURE_MODE_OUTM(m,v) \
        out_dword_masked_ns(HWIO_SPDM_DYN_SECURE_MODE_ADDR,m,v,HWIO_SPDM_DYN_SECURE_MODE_IN)
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_BMSK                                                     0x1
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_SHFT                                                     0x0
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_DISABLE_FVAL                                             0x0
#define HWIO_SPDM_DYN_SECURE_MODE_SECURE_MODE_ENABLE_FVAL                                              0x1

#define HWIO_CHIP_ID_ADDR                                                                       (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006144)
#define HWIO_CHIP_ID_PHYS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006144)
#define HWIO_CHIP_ID_OFFS                                                                       (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006144)
#define HWIO_CHIP_ID_RMSK                                                                           0xffff
#define HWIO_CHIP_ID_IN          \
        in_dword(HWIO_CHIP_ID_ADDR)
#define HWIO_CHIP_ID_INM(m)      \
        in_dword_masked(HWIO_CHIP_ID_ADDR, m)
#define HWIO_CHIP_ID_CHIP_ID_BMSK                                                                   0xffff
#define HWIO_CHIP_ID_CHIP_ID_SHFT                                                                      0x0

#define HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n)                                                        (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006150 + 0x4 * (n))
#define HWIO_OEM_IMAGE_ENCR_KEYn_PHYS(n)                                                        (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006150 + 0x4 * (n))
#define HWIO_OEM_IMAGE_ENCR_KEYn_OFFS(n)                                                        (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006150 + 0x4 * (n))
#define HWIO_OEM_IMAGE_ENCR_KEYn_RMSK                                                           0xffffffff
#define HWIO_OEM_IMAGE_ENCR_KEYn_MAXn                                                                    3
#define HWIO_OEM_IMAGE_ENCR_KEYn_INI(n)        \
        in_dword_masked(HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n), HWIO_OEM_IMAGE_ENCR_KEYn_RMSK)
#define HWIO_OEM_IMAGE_ENCR_KEYn_INMI(n,mask)    \
        in_dword_masked(HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(n), mask)
#define HWIO_OEM_IMAGE_ENCR_KEYn_KEY_DATA0_BMSK                                                 0xffffffff
#define HWIO_OEM_IMAGE_ENCR_KEYn_KEY_DATA0_SHFT                                                        0x0

#define HWIO_IMAGE_ENCR_KEY1_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006160)
#define HWIO_IMAGE_ENCR_KEY1_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006160)
#define HWIO_IMAGE_ENCR_KEY1_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006160)
#define HWIO_IMAGE_ENCR_KEY1_0_RMSK                                                             0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_0_IN          \
        in_dword(HWIO_IMAGE_ENCR_KEY1_0_ADDR)
#define HWIO_IMAGE_ENCR_KEY1_0_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_0_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_BMSK                                                   0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_SHFT                                                          0x0

#define HWIO_IMAGE_ENCR_KEY1_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006164)
#define HWIO_IMAGE_ENCR_KEY1_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006164)
#define HWIO_IMAGE_ENCR_KEY1_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006164)
#define HWIO_IMAGE_ENCR_KEY1_1_RMSK                                                             0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_1_IN          \
        in_dword(HWIO_IMAGE_ENCR_KEY1_1_ADDR)
#define HWIO_IMAGE_ENCR_KEY1_1_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_1_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_BMSK                                                   0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_SHFT                                                          0x0

#define HWIO_IMAGE_ENCR_KEY1_2_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006168)
#define HWIO_IMAGE_ENCR_KEY1_2_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006168)
#define HWIO_IMAGE_ENCR_KEY1_2_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006168)
#define HWIO_IMAGE_ENCR_KEY1_2_RMSK                                                             0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_2_IN          \
        in_dword(HWIO_IMAGE_ENCR_KEY1_2_ADDR)
#define HWIO_IMAGE_ENCR_KEY1_2_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_2_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_BMSK                                                   0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_SHFT                                                          0x0

#define HWIO_IMAGE_ENCR_KEY1_3_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000616c)
#define HWIO_IMAGE_ENCR_KEY1_3_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000616c)
#define HWIO_IMAGE_ENCR_KEY1_3_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000616c)
#define HWIO_IMAGE_ENCR_KEY1_3_RMSK                                                             0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_3_IN          \
        in_dword(HWIO_IMAGE_ENCR_KEY1_3_ADDR)
#define HWIO_IMAGE_ENCR_KEY1_3_INM(m)      \
        in_dword_masked(HWIO_IMAGE_ENCR_KEY1_3_ADDR, m)
#define HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_BMSK                                                   0xffffffff
#define HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_SHFT                                                          0x0

#define HWIO_PK_HASH0_0_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006190)
#define HWIO_PK_HASH0_0_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006190)
#define HWIO_PK_HASH0_0_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006190)
#define HWIO_PK_HASH0_0_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_0_IN          \
        in_dword(HWIO_PK_HASH0_0_ADDR)
#define HWIO_PK_HASH0_0_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_0_ADDR, m)
#define HWIO_PK_HASH0_0_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_0_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_1_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006194)
#define HWIO_PK_HASH0_1_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006194)
#define HWIO_PK_HASH0_1_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006194)
#define HWIO_PK_HASH0_1_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_1_IN          \
        in_dword(HWIO_PK_HASH0_1_ADDR)
#define HWIO_PK_HASH0_1_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_1_ADDR, m)
#define HWIO_PK_HASH0_1_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_1_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_2_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006198)
#define HWIO_PK_HASH0_2_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006198)
#define HWIO_PK_HASH0_2_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006198)
#define HWIO_PK_HASH0_2_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_2_IN          \
        in_dword(HWIO_PK_HASH0_2_ADDR)
#define HWIO_PK_HASH0_2_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_2_ADDR, m)
#define HWIO_PK_HASH0_2_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_2_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_3_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000619c)
#define HWIO_PK_HASH0_3_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000619c)
#define HWIO_PK_HASH0_3_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000619c)
#define HWIO_PK_HASH0_3_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_3_IN          \
        in_dword(HWIO_PK_HASH0_3_ADDR)
#define HWIO_PK_HASH0_3_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_3_ADDR, m)
#define HWIO_PK_HASH0_3_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_3_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_4_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a0)
#define HWIO_PK_HASH0_4_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061a0)
#define HWIO_PK_HASH0_4_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061a0)
#define HWIO_PK_HASH0_4_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_4_IN          \
        in_dword(HWIO_PK_HASH0_4_ADDR)
#define HWIO_PK_HASH0_4_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_4_ADDR, m)
#define HWIO_PK_HASH0_4_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_4_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_5_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a4)
#define HWIO_PK_HASH0_5_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061a4)
#define HWIO_PK_HASH0_5_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061a4)
#define HWIO_PK_HASH0_5_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_5_IN          \
        in_dword(HWIO_PK_HASH0_5_ADDR)
#define HWIO_PK_HASH0_5_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_5_ADDR, m)
#define HWIO_PK_HASH0_5_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_5_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_6_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061a8)
#define HWIO_PK_HASH0_6_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061a8)
#define HWIO_PK_HASH0_6_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061a8)
#define HWIO_PK_HASH0_6_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_6_IN          \
        in_dword(HWIO_PK_HASH0_6_ADDR)
#define HWIO_PK_HASH0_6_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_6_ADDR, m)
#define HWIO_PK_HASH0_6_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_6_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_7_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061ac)
#define HWIO_PK_HASH0_7_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061ac)
#define HWIO_PK_HASH0_7_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061ac)
#define HWIO_PK_HASH0_7_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_7_IN          \
        in_dword(HWIO_PK_HASH0_7_ADDR)
#define HWIO_PK_HASH0_7_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_7_ADDR, m)
#define HWIO_PK_HASH0_7_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_7_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_8_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b0)
#define HWIO_PK_HASH0_8_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061b0)
#define HWIO_PK_HASH0_8_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061b0)
#define HWIO_PK_HASH0_8_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_8_IN          \
        in_dword(HWIO_PK_HASH0_8_ADDR)
#define HWIO_PK_HASH0_8_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_8_ADDR, m)
#define HWIO_PK_HASH0_8_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_8_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_9_ADDR                                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b4)
#define HWIO_PK_HASH0_9_PHYS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061b4)
#define HWIO_PK_HASH0_9_OFFS                                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061b4)
#define HWIO_PK_HASH0_9_RMSK                                                                    0xffffffff
#define HWIO_PK_HASH0_9_IN          \
        in_dword(HWIO_PK_HASH0_9_ADDR)
#define HWIO_PK_HASH0_9_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_9_ADDR, m)
#define HWIO_PK_HASH0_9_HASH_DATA0_BMSK                                                         0xffffffff
#define HWIO_PK_HASH0_9_HASH_DATA0_SHFT                                                                0x0

#define HWIO_PK_HASH0_10_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061b8)
#define HWIO_PK_HASH0_10_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061b8)
#define HWIO_PK_HASH0_10_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061b8)
#define HWIO_PK_HASH0_10_RMSK                                                                   0xffffffff
#define HWIO_PK_HASH0_10_IN          \
        in_dword(HWIO_PK_HASH0_10_ADDR)
#define HWIO_PK_HASH0_10_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_10_ADDR, m)
#define HWIO_PK_HASH0_10_HASH_DATA0_BMSK                                                        0xffffffff
#define HWIO_PK_HASH0_10_HASH_DATA0_SHFT                                                               0x0

#define HWIO_PK_HASH0_11_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061bc)
#define HWIO_PK_HASH0_11_PHYS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061bc)
#define HWIO_PK_HASH0_11_OFFS                                                                   (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061bc)
#define HWIO_PK_HASH0_11_RMSK                                                                   0xffffffff
#define HWIO_PK_HASH0_11_IN          \
        in_dword(HWIO_PK_HASH0_11_ADDR)
#define HWIO_PK_HASH0_11_INM(m)      \
        in_dword_masked(HWIO_PK_HASH0_11_ADDR, m)
#define HWIO_PK_HASH0_11_HASH_DATA0_BMSK                                                        0xffffffff
#define HWIO_PK_HASH0_11_HASH_DATA0_SHFT                                                               0x0

#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061f0)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061f0)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061f0)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_RMSK                                              0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_IN          \
        in_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_INM(m)      \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR, m)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_OUT(v)      \
        out_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR,v)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_ADDR,m,v,HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_IN)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION31_STICKY_BIT_BMSK                          0x80000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION31_STICKY_BIT_SHFT                                0x1f
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION31_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION31_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_BMSK                          0x40000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_SHFT                                0x1e
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION30_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_BMSK                          0x20000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_SHFT                                0x1d
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION29_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_BMSK                          0x10000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_SHFT                                0x1c
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION28_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_BMSK                           0x8000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_SHFT                                0x1b
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION27_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_BMSK                           0x4000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_SHFT                                0x1a
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION26_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_BMSK                           0x2000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_SHFT                                0x19
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION25_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_BMSK                           0x1000000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_SHFT                                0x18
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION24_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_BMSK                            0x800000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_SHFT                                0x17
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION23_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_BMSK                            0x400000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_SHFT                                0x16
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION22_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_BMSK                            0x200000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_SHFT                                0x15
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION21_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_BMSK                            0x100000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_SHFT                                0x14
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION20_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_BMSK                             0x80000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_SHFT                                0x13
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION19_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_BMSK                             0x40000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_SHFT                                0x12
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION18_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_BMSK                             0x20000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_SHFT                                0x11
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION17_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_BMSK                             0x10000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_SHFT                                0x10
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION16_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_BMSK                              0x8000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_SHFT                                 0xf
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION15_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_BMSK                              0x4000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_SHFT                                 0xe
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION14_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_BMSK                              0x2000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_SHFT                                 0xd
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION13_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_BMSK                              0x1000
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_SHFT                                 0xc
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION12_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_BMSK                               0x800
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_SHFT                                 0xb
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION11_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_BMSK                               0x400
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_SHFT                                 0xa
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_ALLOW_WRITE_FVAL                     0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION10_STICKY_BIT_DISABLE_WRITE_FVAL                   0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_BMSK                                0x200
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_SHFT                                  0x9
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION9_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_BMSK                                0x100
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_SHFT                                  0x8
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION8_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_BMSK                                 0x80
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_SHFT                                  0x7
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION7_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_BMSK                                 0x40
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_SHFT                                  0x6
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION6_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_BMSK                                 0x20
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_SHFT                                  0x5
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION5_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_BMSK                                 0x10
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_SHFT                                  0x4
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION4_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_BMSK                                  0x8
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_SHFT                                  0x3
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION3_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_BMSK                                  0x4
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_SHFT                                  0x2
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION2_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_BMSK                                  0x2
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_SHFT                                  0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_BMSK                                  0x1
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_SHFT                                  0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_ALLOW_WRITE_FVAL                      0x0
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION0_STICKY_BIT_DISABLE_WRITE_FVAL                    0x1

#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR                                              (SECURITY_CONTROL_CORE_REG_BASE      + 0x000061f4)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_PHYS                                              (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x000061f4)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_OFFS                                              (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x000061f4)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RMSK                                              0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_IN          \
        in_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_INM(m)      \
        in_dword_masked(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR, m)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_OUT(v)      \
        out_dword(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR,v)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_OUTM(m,v) \
        out_dword_masked_ns(HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_ADDR,m,v,HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_IN)
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RSVD0_BMSK                                        0xffffffff
#define HWIO_QFPROM_WRITE_DISABLE_STICKY_BIT1_RSVD0_SHFT                                               0x0

#define HWIO_ANTI_ROLLBACK_1_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006200)
#define HWIO_ANTI_ROLLBACK_1_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006200)
#define HWIO_ANTI_ROLLBACK_1_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006200)
#define HWIO_ANTI_ROLLBACK_1_0_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_1_0_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_1_0_ADDR)
#define HWIO_ANTI_ROLLBACK_1_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_1_0_XBL0_BMSK                                                        0xffffffff
#define HWIO_ANTI_ROLLBACK_1_0_XBL0_SHFT                                                               0x0

#define HWIO_ANTI_ROLLBACK_1_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006204)
#define HWIO_ANTI_ROLLBACK_1_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006204)
#define HWIO_ANTI_ROLLBACK_1_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006204)
#define HWIO_ANTI_ROLLBACK_1_1_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_1_1_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_1_1_ADDR)
#define HWIO_ANTI_ROLLBACK_1_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_1_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_1_1_XBL1_BMSK                                                        0xffffffff
#define HWIO_ANTI_ROLLBACK_1_1_XBL1_SHFT                                                               0x0

#define HWIO_ANTI_ROLLBACK_2_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006208)
#define HWIO_ANTI_ROLLBACK_2_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006208)
#define HWIO_ANTI_ROLLBACK_2_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006208)
#define HWIO_ANTI_ROLLBACK_2_0_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_2_0_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_2_0_ADDR)
#define HWIO_ANTI_ROLLBACK_2_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_2_0_PIL_SUBSYSTEM_31_0_BMSK                                          0xffffffff
#define HWIO_ANTI_ROLLBACK_2_0_PIL_SUBSYSTEM_31_0_SHFT                                                 0x0

#define HWIO_ANTI_ROLLBACK_2_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000620c)
#define HWIO_ANTI_ROLLBACK_2_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000620c)
#define HWIO_ANTI_ROLLBACK_2_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000620c)
#define HWIO_ANTI_ROLLBACK_2_1_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_2_1_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_2_1_ADDR)
#define HWIO_ANTI_ROLLBACK_2_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_2_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_2_1_XBL_SEC_BMSK                                                     0xfe000000
#define HWIO_ANTI_ROLLBACK_2_1_XBL_SEC_SHFT                                                           0x19
#define HWIO_ANTI_ROLLBACK_2_1_AOP_BMSK                                                          0x1fe0000
#define HWIO_ANTI_ROLLBACK_2_1_AOP_SHFT                                                               0x11
#define HWIO_ANTI_ROLLBACK_2_1_TZ_BMSK                                                             0x1ffff
#define HWIO_ANTI_ROLLBACK_2_1_TZ_SHFT                                                                 0x0

#define HWIO_ANTI_ROLLBACK_3_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006210)
#define HWIO_ANTI_ROLLBACK_3_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006210)
#define HWIO_ANTI_ROLLBACK_3_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006210)
#define HWIO_ANTI_ROLLBACK_3_0_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_3_0_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_3_0_ADDR)
#define HWIO_ANTI_ROLLBACK_3_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_3_0_RSVD1_BMSK                                                       0xc0000000
#define HWIO_ANTI_ROLLBACK_3_0_RSVD1_SHFT                                                             0x1e
#define HWIO_ANTI_ROLLBACK_3_0_TQS_HASH_ACTIVE_BMSK                                             0x3e000000
#define HWIO_ANTI_ROLLBACK_3_0_TQS_HASH_ACTIVE_SHFT                                                   0x19
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_BMSK                                         0x1000000
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_SHFT                                              0x18
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_RPMB_KEY_NOT_PROVISIONED_FVAL                      0x0
#define HWIO_ANTI_ROLLBACK_3_0_RPMB_KEY_PROVISIONED_RPMB_KEY_PROVISIONED_FVAL                          0x1
#define HWIO_ANTI_ROLLBACK_3_0_PIL_SUBSYSTEM_47_32_BMSK                                           0xffff00
#define HWIO_ANTI_ROLLBACK_3_0_PIL_SUBSYSTEM_47_32_SHFT                                                0x8
#define HWIO_ANTI_ROLLBACK_3_0_SAFESWITCH_BMSK                                                        0xff
#define HWIO_ANTI_ROLLBACK_3_0_SAFESWITCH_SHFT                                                         0x0

#define HWIO_ANTI_ROLLBACK_3_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006214)
#define HWIO_ANTI_ROLLBACK_3_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006214)
#define HWIO_ANTI_ROLLBACK_3_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006214)
#define HWIO_ANTI_ROLLBACK_3_1_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_3_1_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_3_1_ADDR)
#define HWIO_ANTI_ROLLBACK_3_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_3_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_3_1_RSVD1_BMSK                                                       0xf0000000
#define HWIO_ANTI_ROLLBACK_3_1_RSVD1_SHFT                                                             0x1c
#define HWIO_ANTI_ROLLBACK_3_1_DEVICE_CFG_BMSK                                                   0xffe0000
#define HWIO_ANTI_ROLLBACK_3_1_DEVICE_CFG_SHFT                                                        0x11
#define HWIO_ANTI_ROLLBACK_3_1_DEBUG_POLICY_BMSK                                                   0x1f000
#define HWIO_ANTI_ROLLBACK_3_1_DEBUG_POLICY_SHFT                                                       0xc
#define HWIO_ANTI_ROLLBACK_3_1_HYPERVISOR_BMSK                                                       0xfff
#define HWIO_ANTI_ROLLBACK_3_1_HYPERVISOR_SHFT                                                         0x0

#define HWIO_ANTI_ROLLBACK_4_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006218)
#define HWIO_ANTI_ROLLBACK_4_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006218)
#define HWIO_ANTI_ROLLBACK_4_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006218)
#define HWIO_ANTI_ROLLBACK_4_0_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_4_0_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_4_0_ADDR)
#define HWIO_ANTI_ROLLBACK_4_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_4_0_MSS_BMSK                                                         0xffff0000
#define HWIO_ANTI_ROLLBACK_4_0_MSS_SHFT                                                               0x10
#define HWIO_ANTI_ROLLBACK_4_0_MISC_BMSK                                                            0xffff
#define HWIO_ANTI_ROLLBACK_4_0_MISC_SHFT                                                               0x0

#define HWIO_ANTI_ROLLBACK_4_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000621c)
#define HWIO_ANTI_ROLLBACK_4_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000621c)
#define HWIO_ANTI_ROLLBACK_4_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000621c)
#define HWIO_ANTI_ROLLBACK_4_1_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_4_1_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_4_1_ADDR)
#define HWIO_ANTI_ROLLBACK_4_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_4_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_4_1_SIMLOCK_BMSK                                                     0x80000000
#define HWIO_ANTI_ROLLBACK_4_1_SIMLOCK_SHFT                                                           0x1f
#define HWIO_ANTI_ROLLBACK_4_1_RSVD0_BMSK                                                       0x7ffffff0
#define HWIO_ANTI_ROLLBACK_4_1_RSVD0_SHFT                                                              0x4
#define HWIO_ANTI_ROLLBACK_4_1_ROOT_CERT_PK_HASH_INDEX_BMSK                                            0xf
#define HWIO_ANTI_ROLLBACK_4_1_ROOT_CERT_PK_HASH_INDEX_SHFT                                            0x0

#define HWIO_ANTI_ROLLBACK_5_0_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006220)
#define HWIO_ANTI_ROLLBACK_5_0_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006220)
#define HWIO_ANTI_ROLLBACK_5_0_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006220)
#define HWIO_ANTI_ROLLBACK_5_0_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_5_0_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_5_0_ADDR)
#define HWIO_ANTI_ROLLBACK_5_0_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_5_0_ADDR, m)
#define HWIO_ANTI_ROLLBACK_5_0_MISC_BMSK                                                        0xffffffff
#define HWIO_ANTI_ROLLBACK_5_0_MISC_SHFT                                                               0x0

#define HWIO_ANTI_ROLLBACK_5_1_ADDR                                                             (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006224)
#define HWIO_ANTI_ROLLBACK_5_1_PHYS                                                             (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006224)
#define HWIO_ANTI_ROLLBACK_5_1_OFFS                                                             (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006224)
#define HWIO_ANTI_ROLLBACK_5_1_RMSK                                                             0xffffffff
#define HWIO_ANTI_ROLLBACK_5_1_IN          \
        in_dword(HWIO_ANTI_ROLLBACK_5_1_ADDR)
#define HWIO_ANTI_ROLLBACK_5_1_INM(m)      \
        in_dword_masked(HWIO_ANTI_ROLLBACK_5_1_ADDR, m)
#define HWIO_ANTI_ROLLBACK_5_1_MISC_BMSK                                                        0xffffffff
#define HWIO_ANTI_ROLLBACK_5_1_MISC_SHFT                                                               0x0

#define HWIO_MRC_2_0_0_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006250)
#define HWIO_MRC_2_0_0_PHYS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006250)
#define HWIO_MRC_2_0_0_OFFS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006250)
#define HWIO_MRC_2_0_0_RMSK                                                                     0xffffffff
#define HWIO_MRC_2_0_0_IN          \
        in_dword(HWIO_MRC_2_0_0_ADDR)
#define HWIO_MRC_2_0_0_INM(m)      \
        in_dword_masked(HWIO_MRC_2_0_0_ADDR, m)
#define HWIO_MRC_2_0_0_RSVD0_BMSK                                                               0xfffffff0
#define HWIO_MRC_2_0_0_RSVD0_SHFT                                                                      0x4
#define HWIO_MRC_2_0_0_ROOT_CERT_ACTIVATION_LIST_BMSK                                                  0xf
#define HWIO_MRC_2_0_0_ROOT_CERT_ACTIVATION_LIST_SHFT                                                  0x0

#define HWIO_MRC_2_0_1_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006254)
#define HWIO_MRC_2_0_1_PHYS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006254)
#define HWIO_MRC_2_0_1_OFFS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006254)
#define HWIO_MRC_2_0_1_RMSK                                                                     0xffffffff
#define HWIO_MRC_2_0_1_IN          \
        in_dword(HWIO_MRC_2_0_1_ADDR)
#define HWIO_MRC_2_0_1_INM(m)      \
        in_dword_masked(HWIO_MRC_2_0_1_ADDR, m)
#define HWIO_MRC_2_0_1_RSVD1_BMSK                                                               0xfffffffe
#define HWIO_MRC_2_0_1_RSVD1_SHFT                                                                      0x1
#define HWIO_MRC_2_0_1_CURRENT_UIE_KEY_SEL_BMSK                                                        0x1
#define HWIO_MRC_2_0_1_CURRENT_UIE_KEY_SEL_SHFT                                                        0x0

#define HWIO_MRC_2_0_2_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006258)
#define HWIO_MRC_2_0_2_PHYS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006258)
#define HWIO_MRC_2_0_2_OFFS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006258)
#define HWIO_MRC_2_0_2_RMSK                                                                     0xffffffff
#define HWIO_MRC_2_0_2_IN          \
        in_dword(HWIO_MRC_2_0_2_ADDR)
#define HWIO_MRC_2_0_2_INM(m)      \
        in_dword_masked(HWIO_MRC_2_0_2_ADDR, m)
#define HWIO_MRC_2_0_2_RSVD0_BMSK                                                               0xfffffff0
#define HWIO_MRC_2_0_2_RSVD0_SHFT                                                                      0x4
#define HWIO_MRC_2_0_2_ROOT_CERT_REVOCATION_LIST_BMSK                                                  0xf
#define HWIO_MRC_2_0_2_ROOT_CERT_REVOCATION_LIST_SHFT                                                  0x0

#define HWIO_MRC_2_0_3_ADDR                                                                     (SECURITY_CONTROL_CORE_REG_BASE      + 0x0000625c)
#define HWIO_MRC_2_0_3_PHYS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x0000625c)
#define HWIO_MRC_2_0_3_OFFS                                                                     (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x0000625c)
#define HWIO_MRC_2_0_3_RMSK                                                                     0xffffffff
#define HWIO_MRC_2_0_3_IN          \
        in_dword(HWIO_MRC_2_0_3_ADDR)
#define HWIO_MRC_2_0_3_INM(m)      \
        in_dword_masked(HWIO_MRC_2_0_3_ADDR, m)
#define HWIO_MRC_2_0_3_RSVD0_BMSK                                                               0xffffffff
#define HWIO_MRC_2_0_3_RSVD0_SHFT                                                                      0x0

#define HWIO_CRYPTO_LIB_VERSION_ADDR                                                            (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006300)
#define HWIO_CRYPTO_LIB_VERSION_PHYS                                                            (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006300)
#define HWIO_CRYPTO_LIB_VERSION_OFFS                                                            (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006300)
#define HWIO_CRYPTO_LIB_VERSION_RMSK                                                            0xffffffff
#define HWIO_CRYPTO_LIB_VERSION_IN          \
        in_dword(HWIO_CRYPTO_LIB_VERSION_ADDR)
#define HWIO_CRYPTO_LIB_VERSION_INM(m)      \
        in_dword_masked(HWIO_CRYPTO_LIB_VERSION_ADDR, m)
#define HWIO_CRYPTO_LIB_VERSION_VERSION_BMSK                                                    0xffffffff
#define HWIO_CRYPTO_LIB_VERSION_VERSION_SHFT                                                           0x0

#define HWIO_LCM_0_ADDR                                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006304)
#define HWIO_LCM_0_PHYS                                                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006304)
#define HWIO_LCM_0_OFFS                                                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006304)
#define HWIO_LCM_0_RMSK                                                                         0xffffffff
#define HWIO_LCM_0_IN          \
        in_dword(HWIO_LCM_0_ADDR)
#define HWIO_LCM_0_INM(m)      \
        in_dword_masked(HWIO_LCM_0_ADDR, m)
#define HWIO_LCM_0_DISABLE_LCM_BMSK                                                             0x80000000
#define HWIO_LCM_0_DISABLE_LCM_SHFT                                                                   0x1f
#define HWIO_LCM_0_DISABLE_LCM_STATE_TRANSITION_BMSK                                            0x40000000
#define HWIO_LCM_0_DISABLE_LCM_STATE_TRANSITION_SHFT                                                  0x1e
#define HWIO_LCM_0_DISABLE_SECURE_PHK_BMSK                                                      0x20000000
#define HWIO_LCM_0_DISABLE_SECURE_PHK_SHFT                                                            0x1d
#define HWIO_LCM_0_RSVD_BMSK                                                                    0x1fffff00
#define HWIO_LCM_0_RSVD_SHFT                                                                           0x8
#define HWIO_LCM_0_DEBUG_STATE_BMSK                                                                   0x80
#define HWIO_LCM_0_DEBUG_STATE_SHFT                                                                    0x7
#define HWIO_LCM_0_ILLEGAL_STATE_BMSK                                                                 0x40
#define HWIO_LCM_0_ILLEGAL_STATE_SHFT                                                                  0x6
#define HWIO_LCM_0_QC_EXTERNAL_BMSK                                                                   0x20
#define HWIO_LCM_0_QC_EXTERNAL_SHFT                                                                    0x5
#define HWIO_LCM_0_QC_INTERNAL_BMSK                                                                   0x10
#define HWIO_LCM_0_QC_INTERNAL_SHFT                                                                    0x4
#define HWIO_LCM_0_QC_FEAT_CONFIG_BMSK                                                                 0x8
#define HWIO_LCM_0_QC_FEAT_CONFIG_SHFT                                                                 0x3
#define HWIO_LCM_0_HW_TEST_BMSK                                                                        0x4
#define HWIO_LCM_0_HW_TEST_SHFT                                                                        0x2
#define HWIO_LCM_0_SOC_PERSO_BMSK                                                                      0x2
#define HWIO_LCM_0_SOC_PERSO_SHFT                                                                      0x1
#define HWIO_LCM_0_BLANK_BMSK                                                                          0x1
#define HWIO_LCM_0_BLANK_SHFT                                                                          0x0

#define HWIO_LCM_1_ADDR                                                                         (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006308)
#define HWIO_LCM_1_PHYS                                                                         (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006308)
#define HWIO_LCM_1_OFFS                                                                         (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006308)
#define HWIO_LCM_1_RMSK                                                                         0xffffffff
#define HWIO_LCM_1_IN          \
        in_dword(HWIO_LCM_1_ADDR)
#define HWIO_LCM_1_INM(m)      \
        in_dword_masked(HWIO_LCM_1_ADDR, m)
#define HWIO_LCM_1_LCM_DATA1_BMSK                                                               0xffffffff
#define HWIO_LCM_1_LCM_DATA1_SHFT                                                                      0x0

#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDR                                                    (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006400)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_PHYS                                                    (SECURITY_CONTROL_CORE_REG_BASE_PHYS + 0x00006400)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_OFFS                                                    (SECURITY_CONTROL_CORE_REG_BASE_OFFS + 0x00006400)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_RMSK                                                    0xffffffff
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_IN          \
        in_dword(HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDR)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_INM(m)      \
        in_dword_masked(HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDR, m)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_OUT(v)      \
        out_dword(HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDR,v)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDR,m,v,HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_IN)
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDRESS_BMSK                                            0xffffffff
#define HWIO_VIRTUAL_SEC_CTRL_BASE_ADDR_ADDRESS_SHFT                                                   0x0


#endif /* __CPR_FUSES_HWIO_H__ */
