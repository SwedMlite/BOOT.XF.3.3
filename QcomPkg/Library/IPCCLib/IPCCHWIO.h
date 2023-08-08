#ifndef __IPCCHWIO_H__
#define __IPCCHWIO_H__
/*
===========================================================================
*/
/**
  @file IPCCHWIO.h
  @brief Auto-generated HWIO interface include file.

  Reference chip release:
    SM8250 (Kona) [kona_v1.0_p1q0r8.8]
 
  This file contains HWIO register definitions for the following modules:
    IPC_CORE
    IPC_CONFIG


  Generation parameters: 
  { u'explicit-addressing': True,
    u'filename': u'IPCCHWIO.h',
    u'header': u'#include "HALhwio.h"',
    u'module-filter-exclude': { },
    u'module-filter-include': { },
    u'modules': [u'IPC_CORE', u'IPC_CONFIG'],
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

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/IPCCLib/IPCCHWIO.h#1 $
  $DateTime: 2018/11/12 11:05:42 $
  $Author: pwbldsvc $

  ===========================================================================
*/

#include "HALhwio.h"

/*----------------------------------------------------------------------------
 * MODULE: IPC_CORE
 *--------------------------------------------------------------------------*/

#define HWIO_IPC_VERSION_ADDR(base,p,c)                                      ((base) + 0x00000000 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_VERSION_OFFS(base,p,c)                                      (0x00000000 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_VERSION_RMSK                                                  0xffffff
#define HWIO_IPC_VERSION_MAXp                                                         2
#define HWIO_IPC_VERSION_MAXc                                                        16
#define HWIO_IPC_VERSION_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_VERSION_ADDR(base,p,c), HWIO_IPC_VERSION_RMSK)
#define HWIO_IPC_VERSION_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_VERSION_ADDR(base,p,c), mask)
#define HWIO_IPC_VERSION_MAJOR_VER_BMSK                                        0xff0000
#define HWIO_IPC_VERSION_MAJOR_VER_SHFT                                            0x10
#define HWIO_IPC_VERSION_MINOR_VER_BMSK                                          0xff00
#define HWIO_IPC_VERSION_MINOR_VER_SHFT                                             0x8
#define HWIO_IPC_VERSION_STEP_VER_BMSK                                             0xff
#define HWIO_IPC_VERSION_STEP_VER_SHFT                                              0x0

#define HWIO_IPC_ID_ADDR(base,p,c)                                           ((base) + 0x00000004 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_ID_OFFS(base,p,c)                                           (0x00000004 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_ID_RMSK                                                     0xffffffff
#define HWIO_IPC_ID_MAXp                                                              2
#define HWIO_IPC_ID_MAXc                                                             16
#define HWIO_IPC_ID_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_ID_ADDR(base,p,c), HWIO_IPC_ID_RMSK)
#define HWIO_IPC_ID_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_ID_ADDR(base,p,c), mask)
#define HWIO_IPC_ID_CLIENT_ID_BMSK                                           0xffff0000
#define HWIO_IPC_ID_CLIENT_ID_SHFT                                                 0x10
#define HWIO_IPC_ID_PROTOCOL_ID_BMSK                                             0xffff
#define HWIO_IPC_ID_PROTOCOL_ID_SHFT                                                0x0

#define HWIO_IPC_CONFIG_ADDR(base,p,c)                                       ((base) + 0x00000008 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CONFIG_OFFS(base,p,c)                                       (0x00000008 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CONFIG_RMSK                                                 0x80000001
#define HWIO_IPC_CONFIG_MAXp                                                          2
#define HWIO_IPC_CONFIG_MAXc                                                         16
#define HWIO_IPC_CONFIG_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_CONFIG_ADDR(base,p,c), HWIO_IPC_CONFIG_RMSK)
#define HWIO_IPC_CONFIG_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_CONFIG_ADDR(base,p,c), mask)
#define HWIO_IPC_CONFIG_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_CONFIG_ADDR(base,p,c),val)
#define HWIO_IPC_CONFIG_OUTMI2(base,p,c,mask,val) \
        out_dword_masked_ns(HWIO_IPC_CONFIG_ADDR(base,p,c),mask,val,HWIO_IPC_CONFIG_INI2(base,p,c))
#define HWIO_IPC_CONFIG_CLIENT_DISABLE_BMSK                                  0x80000000
#define HWIO_IPC_CONFIG_CLIENT_DISABLE_SHFT                                        0x1f
#define HWIO_IPC_CONFIG_CLEAR_ON_RECV_RD_BMSK                                       0x1
#define HWIO_IPC_CONFIG_CLEAR_ON_RECV_RD_SHFT                                       0x0

#define HWIO_IPC_SEND_ADDR(base,p,c)                                         ((base) + 0x0000000c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_SEND_OFFS(p,c)                                              (0x0000000c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_SEND_RMSK                                                   0xffffffff
#define HWIO_IPC_SEND_MAXp                                                            2
#define HWIO_IPC_SEND_MAXc                                                           16
#define HWIO_IPC_SEND_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_SEND_ADDR(base,p,c),val)
#define HWIO_IPC_SEND_BROADCAST_BMSK                                         0x80000000
#define HWIO_IPC_SEND_BROADCAST_SHFT                                               0x1f
#define HWIO_IPC_SEND_CLIENT_ID_BMSK                                         0x7fff0000
#define HWIO_IPC_SEND_CLIENT_ID_SHFT                                               0x10
#define HWIO_IPC_SEND_SIGNAL_ID_BMSK                                             0xffff
#define HWIO_IPC_SEND_SIGNAL_ID_SHFT                                                0x0

#define HWIO_IPC_RECV_ID_ADDR(base,p,c)                                      ((base) + 0x00000010 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_ID_OFFS(base,p,c)                                      (0x00000010 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_ID_RMSK                                                0xffffffff
#define HWIO_IPC_RECV_ID_MAXp                                                         2
#define HWIO_IPC_RECV_ID_MAXc                                                        16
#define HWIO_IPC_RECV_ID_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_RECV_ID_ADDR(base,p,c), HWIO_IPC_RECV_ID_RMSK)
#define HWIO_IPC_RECV_ID_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_RECV_ID_ADDR(base,p,c), mask)
#define HWIO_IPC_RECV_ID_CLIENT_ID_BMSK                                      0xffff0000
#define HWIO_IPC_RECV_ID_CLIENT_ID_SHFT                                            0x10
#define HWIO_IPC_RECV_ID_SIGNAL_ID_BMSK                                          0xffff
#define HWIO_IPC_RECV_ID_SIGNAL_ID_SHFT                                             0x0

#define HWIO_IPC_RECV_SIGNAL_ENABLE_ADDR(base,p,c)                           ((base) + 0x00000014 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_ENABLE_OFFS(base,p,c)                           (0x00000014 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_ENABLE_RMSK                                     0xffffffff
#define HWIO_IPC_RECV_SIGNAL_ENABLE_MAXp                                              2
#define HWIO_IPC_RECV_SIGNAL_ENABLE_MAXc                                             16
#define HWIO_IPC_RECV_SIGNAL_ENABLE_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_RECV_SIGNAL_ENABLE_ADDR(base,p,c),val)
#define HWIO_IPC_RECV_SIGNAL_ENABLE_CLIENT_ID_BMSK                           0xffff0000
#define HWIO_IPC_RECV_SIGNAL_ENABLE_CLIENT_ID_SHFT                                 0x10
#define HWIO_IPC_RECV_SIGNAL_ENABLE_SIGNAL_ID_BMSK                               0xffff
#define HWIO_IPC_RECV_SIGNAL_ENABLE_SIGNAL_ID_SHFT                                  0x0

#define HWIO_IPC_RECV_SIGNAL_DISABLE_ADDR(base,p,c)                          ((base) + 0x00000018 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_DISABLE_OFFS(base,p,c)                          (0x00000018 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_DISABLE_RMSK                                    0xffffffff
#define HWIO_IPC_RECV_SIGNAL_DISABLE_MAXp                                             2
#define HWIO_IPC_RECV_SIGNAL_DISABLE_MAXc                                            16
#define HWIO_IPC_RECV_SIGNAL_DISABLE_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_RECV_SIGNAL_DISABLE_ADDR(base,p,c),val)
#define HWIO_IPC_RECV_SIGNAL_DISABLE_CLIENT_ID_BMSK                          0xffff0000
#define HWIO_IPC_RECV_SIGNAL_DISABLE_CLIENT_ID_SHFT                                0x10
#define HWIO_IPC_RECV_SIGNAL_DISABLE_SIGNAL_ID_BMSK                              0xffff
#define HWIO_IPC_RECV_SIGNAL_DISABLE_SIGNAL_ID_SHFT                                 0x0

#define HWIO_IPC_RECV_SIGNAL_CLEAR_ADDR(base,p,c)                            ((base) + 0x0000001c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_CLEAR_OFFS(base,p,c)                            (0x0000001c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_SIGNAL_CLEAR_RMSK                                      0xffffffff
#define HWIO_IPC_RECV_SIGNAL_CLEAR_MAXp                                               2
#define HWIO_IPC_RECV_SIGNAL_CLEAR_MAXc                                              16
#define HWIO_IPC_RECV_SIGNAL_CLEAR_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_RECV_SIGNAL_CLEAR_ADDR(base,p,c),val)
#define HWIO_IPC_RECV_SIGNAL_CLEAR_CLIENT_ID_BMSK                            0xffff0000
#define HWIO_IPC_RECV_SIGNAL_CLEAR_CLIENT_ID_SHFT                                  0x10
#define HWIO_IPC_RECV_SIGNAL_CLEAR_SIGNAL_ID_BMSK                                0xffff
#define HWIO_IPC_RECV_SIGNAL_CLEAR_SIGNAL_ID_SHFT                                   0x0

#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_ADDR(base,p,c)                       ((base) + 0x00000020 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_OFFS(base,p,c)                       (0x00000020 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_RMSK                                 0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_MAXp                                          2
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_MAXc                                         16
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_ADDR(base,p,c), HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_RMSK)
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_ADDR(base,p,c), mask)
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_SIGNAL_STATUS_BMSK                   0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_0_SIGNAL_STATUS_SHFT                          0x0

#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_ADDR(base,p,c)                       ((base) + 0x00000024 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_OFFS(base,p,c)                       (0x00000024 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_RMSK                                 0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_MAXp                                          2
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_MAXc                                         16
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_ADDR(base,p,c), HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_RMSK)
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_ADDR(base,p,c), mask)
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_SIGNAL_STATUS_BMSK                   0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_STATUS_1_SIGNAL_STATUS_SHFT                          0x0

#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_ADDR(base,p,c)                        ((base) + 0x00000028 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_OFFS(base,p,c)                        (0x00000028 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_RMSK                                  0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_MAXp                                           2
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_MAXc                                          16
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_ADDR(base,p,c),val)
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_SIGNAL_CLEAR_BMSK                     0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_0_SIGNAL_CLEAR_SHFT                            0x0

#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_ADDR(base,p,c)                        ((base) + 0x0000002c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_OFFS(base,p,c)                        (0x0000002c + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_RMSK                                  0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_MAXp                                           2
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_MAXc                                          16
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_ADDR(base,p,c),val)
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_SIGNAL_CLEAR_BMSK                     0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_CLEAR_1_SIGNAL_CLEAR_SHFT                            0x0

#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_ADDR(base,p,c)                         ((base) + 0x00000030 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_OFFS(base,p,c)                         (0x00000030 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_RMSK                                   0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_MAXp                                            2
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_MAXc                                           16
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_MASK_0_ADDR(base,p,c), HWIO_IPC_GLOBAL_SIGNAL_MASK_0_RMSK)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_MASK_0_ADDR(base,p,c), mask)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_GLOBAL_SIGNAL_MASK_0_ADDR(base,p,c),val)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_OUTMI2(base,p,c,mask,val) \
        out_dword_masked_ns(HWIO_IPC_GLOBAL_SIGNAL_MASK_0_ADDR(base,p,c),mask,val,HWIO_IPC_GLOBAL_SIGNAL_MASK_0_INI2(base,p,c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_SIGNAL_MASK_BMSK                       0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_0_SIGNAL_MASK_SHFT                              0x0

#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_ADDR(base,p,c)                         ((base) + 0x00000034 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_OFFS(base,p,c)                         (0x00000034 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_RMSK                                   0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_MAXp                                            2
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_MAXc                                           16
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_INI2(base,p,c)        \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_MASK_1_ADDR(base,p,c), HWIO_IPC_GLOBAL_SIGNAL_MASK_1_RMSK)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_INMI2(base,p,c,mask)    \
        in_dword_masked(HWIO_IPC_GLOBAL_SIGNAL_MASK_1_ADDR(base,p,c), mask)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_GLOBAL_SIGNAL_MASK_1_ADDR(base,p,c),val)
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_OUTMI2(base,p,c,mask,val) \
        out_dword_masked_ns(HWIO_IPC_GLOBAL_SIGNAL_MASK_1_ADDR(base,p,c),mask,val,HWIO_IPC_GLOBAL_SIGNAL_MASK_1_INI2(base,p,c))
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_SIGNAL_MASK_BMSK                       0xffffffff
#define HWIO_IPC_GLOBAL_SIGNAL_MASK_1_SIGNAL_MASK_SHFT                              0x0

#define HWIO_IPC_CLIENT_CLEAR_ADDR(base,p,c)                                 ((base) + 0x00000038 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_CLEAR_OFFS(base,p,c)                                 (0x00000038 + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_CLEAR_RMSK                                                  0x1
#define HWIO_IPC_CLIENT_CLEAR_MAXp                                                    2
#define HWIO_IPC_CLIENT_CLEAR_MAXc                                                   16
#define HWIO_IPC_CLIENT_CLEAR_OUTI2(base,p,c,val)    \
        out_dword(HWIO_IPC_CLIENT_CLEAR_ADDR(base,p,c),val)
#define HWIO_IPC_CLIENT_CLEAR_CLIENT_CLEAR_BMSK                                     0x1
#define HWIO_IPC_CLIENT_CLEAR_CLIENT_CLEAR_SHFT                                     0x0

#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_ADDR(base,p,c,n)                     ((base) + 0x00000100 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_OFFS(base,p,c,n)                     (0x00000100 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_RMSK                                        0x3
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_MAXp                                          2
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_MAXc                                         16
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_MAXn                                         16
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_INI3(base,p,c,n)        \
        in_dword_masked(HWIO_IPC_RECV_CLIENT_PRIORITY_n_ADDR(base,p,c,n), HWIO_IPC_RECV_CLIENT_PRIORITY_n_RMSK)
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_INMI3(base,p,c,n,mask)    \
        in_dword_masked(HWIO_IPC_RECV_CLIENT_PRIORITY_n_ADDR(base,p,c,n), mask)
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_OUTI3(base,p,c,n,val)    \
        out_dword(HWIO_IPC_RECV_CLIENT_PRIORITY_n_ADDR(base,p,c,n),val)
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_OUTMI3(base,p,c,n,mask,val) \
        out_dword_masked_ns(HWIO_IPC_RECV_CLIENT_PRIORITY_n_ADDR(base,p,c,n),mask,val,HWIO_IPC_RECV_CLIENT_PRIORITY_n_INI3(base,p,c,n))
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_PRIORITY_LEVEL_BMSK                         0x3
#define HWIO_IPC_RECV_CLIENT_PRIORITY_n_PRIORITY_LEVEL_SHFT                         0x0

#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_ADDR(base,p,c,n)                     ((base) + 0x00000200 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_OFFS(base,p,c,n)                     (0x00000200 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_RMSK                                 0xffffffff
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_MAXp                                          2
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_MAXc                                         16
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_MAXn                                         16
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_OUTI3(base,p,c,n,val)    \
        out_dword(HWIO_IPC_RECV_CLIENT_ENABLE_0_n_ADDR(base,p,c,n),val)
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_ENABLE_VECTOR_BMSK                   0xffffffff
#define HWIO_IPC_RECV_CLIENT_ENABLE_0_n_ENABLE_VECTOR_SHFT                          0x0

#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_ADDR(base,p,c,n)                     ((base) + 0x00000300 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_OFFS(base,p,c,n)                     (0x00000300 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_RMSK                                 0xffffffff
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_MAXp                                          2
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_MAXc                                         16
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_MAXn                                         16
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_OUTI3(base,p,c,n,val)    \
        out_dword(HWIO_IPC_RECV_CLIENT_ENABLE_1_n_ADDR(base,p,c,n),val)
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_ENABLE_VECTOR_BMSK                   0xffffffff
#define HWIO_IPC_RECV_CLIENT_ENABLE_1_n_ENABLE_VECTOR_SHFT                          0x0

#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_ADDR(base,p,c,n)                    ((base) + 0x00000400 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_OFFS(base,p,c,n)                    (0x00000400 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_RMSK                                0xffffffff
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_MAXp                                         2
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_MAXc                                        16
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_MAXn                                        16
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_OUTI3(base,p,c,n,val)    \
        out_dword(HWIO_IPC_RECV_CLIENT_DISABLE_0_n_ADDR(base,p,c,n),val)
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_DISABLE_VECTOR_BMSK                 0xffffffff
#define HWIO_IPC_RECV_CLIENT_DISABLE_0_n_DISABLE_VECTOR_SHFT                        0x0

#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_ADDR(base,p,c,n)                    ((base) + 0x00000500 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_OFFS(base,p,c,n)                    (0x00000500 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_RMSK                                0xffffffff
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_MAXp                                         2
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_MAXc                                        16
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_MAXn                                        16
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_OUTI3(base,p,c,n,val)    \
        out_dword(HWIO_IPC_RECV_CLIENT_DISABLE_1_n_ADDR(base,p,c,n),val)
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_DISABLE_VECTOR_BMSK                 0xffffffff
#define HWIO_IPC_RECV_CLIENT_DISABLE_1_n_DISABLE_VECTOR_SHFT                        0x0

#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_ADDR(base,p,c,n)                   ((base) + 0x00000600 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_OFFS(base,p,c,n)                   (0x00000600 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_RMSK                               0xffffffff
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_MAXp                                        2
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_MAXc                                       16
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_MAXn                                       16
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_INI3(base,p,c,n)        \
        in_dword_masked(HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_ADDR(base,p,c,n), HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_RMSK)
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_INMI3(base,p,c,n,mask)    \
        in_dword_masked(HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_ADDR(base,p,c,n), mask)
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_CLIENT_SIGNAL_STATUS_BMSK          0xffffffff
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_0_n_CLIENT_SIGNAL_STATUS_SHFT                 0x0

#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_ADDR(base,p,c,n)                   ((base) + 0x00000700 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_OFFS(base,p,c,n)                   (0x00000700 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_RMSK                               0xffffffff
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_MAXp                                        2
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_MAXc                                       16
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_MAXn                                       16
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_INI3(base,p,c,n)        \
        in_dword_masked(HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_ADDR(base,p,c,n), HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_RMSK)
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_INMI3(base,p,c,n,mask)    \
        in_dword_masked(HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_ADDR(base,p,c,n), mask)
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_CLIENT_SIGNAL_STATUS_BMSK          0xffffffff
#define HWIO_IPC_CLIENT_SIGNAL_STATUS_1_n_CLIENT_SIGNAL_STATUS_SHFT                 0x0

#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_ADDR(base,p,c,n)                   ((base) + 0x00000800 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_OFFS(base,p,c,n)                   (0x00000800 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_RMSK                               0xffffffff
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_MAXp                                        2
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_MAXc                                       16
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_MAXn                                       16
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_INI3(base,p,c,n)        \
        in_dword_masked(HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_ADDR(base,p,c,n), HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_RMSK)
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_INMI3(base,p,c,n,mask)    \
        in_dword_masked(HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_ADDR(base,p,c,n), mask)
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_CLIENT_ENABLE_STATUS_BMSK          0xffffffff
#define HWIO_IPC_CLIENT_ENABLE_STATUS_0_n_CLIENT_ENABLE_STATUS_SHFT                 0x0

#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_ADDR(base,p,c,n)                   ((base) + 0x00000900 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_OFFS(base,p,c,n)                   (0x00000900 + 0x4 * (n) + 0x40000 * (p) + 0x1000 * (c))
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_RMSK                               0xffffffff
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_MAXp                                        2
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_MAXc                                       16
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_MAXn                                       16
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_INI3(base,p,c,n)        \
        in_dword_masked(HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_ADDR(base,p,c,n), HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_RMSK)
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_INMI3(base,p,c,n,mask)    \
        in_dword_masked(HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_ADDR(base,p,c,n), mask)
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_CLIENT_ENABLE_STATUS_BMSK          0xffffffff
#define HWIO_IPC_CLIENT_ENABLE_STATUS_1_n_CLIENT_ENABLE_STATUS_SHFT                 0x0

/*----------------------------------------------------------------------------
 * MODULE: IPC_CONFIG
 *--------------------------------------------------------------------------*/

#define HWIO_IPC_TOP_MODE_ADDR(x)            ((x) + 0x000fc000)
#define HWIO_IPC_TOP_MODE_OFFS               (0x00000000)
#define HWIO_IPC_TOP_MODE_RMSK                      0x1
#define HWIO_IPC_TOP_MODE_IN(x)      \
        in_dword_masked(HWIO_IPC_TOP_MODE_ADDR(x), HWIO_IPC_TOP_MODE_RMSK)
#define HWIO_IPC_TOP_MODE_INM(x, m)      \
        in_dword_masked(HWIO_IPC_TOP_MODE_ADDR(x), m)
#define HWIO_IPC_TOP_MODE_OUT(x, v)      \
        out_dword(HWIO_IPC_TOP_MODE_ADDR(x),v)
#define HWIO_IPC_TOP_MODE_OUTM(x,m,v) \
        out_dword_masked_ns(HWIO_IPC_TOP_MODE_ADDR(x),m,v,HWIO_IPC_TOP_MODE_IN(x))
#define HWIO_IPC_TOP_MODE_MODE_BMSK                 0x1
#define HWIO_IPC_TOP_MODE_MODE_SHFT                 0x0
#define HWIO_IPC_TOP_MODE_MODE_LEGACY_MODE_FVAL        0x0
#define HWIO_IPC_TOP_MODE_MODE_IPC_ROUTER_MODE_FVAL        0x1


#endif /* __IPCCHWIO_H__ */
