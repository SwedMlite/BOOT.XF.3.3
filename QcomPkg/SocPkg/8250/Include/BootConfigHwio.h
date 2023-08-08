#ifndef __BOOTCONFIGHWIO_H__
#define __BOOTCONFIGHWIO_H__
/*
===========================================================================
*/
/**
  @file BootConfigHwio.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) [kona_v1.0_p3q1r17.5_MECO]
 
  This file contains HWIO register definitions for the following modules:
    SECURITY_CONTROL_CORE

  'Include' filters applied: BOOT_CONFIG[SECURITY_CONTROL_CORE] 

  Generation parameters: 
  { u'filename': u'BootConfigHwio.h',
    u'header': u'#include "msmhwiobase.h"',
    u'module-filter-exclude': { },
    u'module-filter-include': { u'SECURITY_CONTROL_CORE': [u'BOOT_CONFIG']},
    u'modules': [u'SECURITY_CONTROL_CORE'],
    u'output-fvals': True}
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Include/BootConfigHwio.h#4 $
  $DateTime: 2018/12/12 13:23:46 $
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

#define HWIO_BOOT_CONFIG_ADDR                                                                   (SECURITY_CONTROL_CORE_REG_BASE      + 0x00006070)
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


#endif /* __BOOTCONFIGHWIO_H__ */