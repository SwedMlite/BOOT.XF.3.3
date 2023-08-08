#ifndef __HALCLKLUCID5lpePLL_H__
#define __HALCLKLUCID5lpePLL_H__
/*
==============================================================================

FILE:         HALclkLucid5lpePLL.h

DESCRIPTION:
  Internal, chipset specific PLL definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/HALclkSharedLib/HALclkLucid5lpePLL.h#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
08/02/19   richaa  Created.

==============================================================================
    Copyright (c) 2010-2019 QUALCOMM Technologies Incorporated.All Rights Reserved.
	QUALCOMM Proprietary and Confidential.
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * Registers for programming operational mode
 */
#define HAL_PLL_OPMODE_STANDBY  0x0
#define HAL_PLL_OPMODE_RUN      0x1
#define HAL_PLL_OPMODE_FREEZE   0x3

/*
 * PLL register offsets.
 */
#define HWIO_PLL_MODE_OFFS                                  0x00000000
#define HWIO_PLL_L_VAL_OFFS                                 0x00000004
#define HWIO_PLL_CAL_L_VAL_OFFS                             0x00000008
#define HWIO_PLL_USER_CTL_OFFS                              0x0000000c
#define HWIO_PLL_USER_CTL_U_OFFS                            0x00000010
#define HWIO_PLL_USER_CTL_U1_OFFS                           0x00000014
#define HWIO_PLL_CONFIG_CTL_OFFS                            0x00000018
#define HWIO_PLL_CONFIG_CTL_U_OFFS                          0x0000001c
#define HWIO_PLL_CONFIG_CTL_U1_OFFS                         0x00000020
#define HWIO_PLL_TEST_CTL_OFFS                              0x00000024
#define HWIO_PLL_TEST_CTL_U_OFFS                            0x00000028
#define HWIO_PLL_TEST_CTL_U1_OFFS                           0x0000002c
#define HWIO_PLL_STATUS_OFFS                                0x00000030
#define HWIO_PLL_FREQ_CTL_OFFS                              0x00000034
#define HWIO_PLL_OPMODE_OFFS                                0x00000038
#define HWIO_PLL_STATE_OFFS                                 0x0000003c
#define HWIO_PLL_FRAC_VAL_OFFS                              0x00000040

/*
 * PLL_MODE register definitions.
 */
#define HWIO_PLL_MODE_PLL_LOCK_DET_BMSK                     0x80000000
#define HWIO_PLL_MODE_PLL_LOCK_DET_SHFT                           0x1f
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_BMSK                      0x4000
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_SHFT                         0xe
#define HWIO_PLL_MODE_PLL_ACK_LATCH_BMSK                        0x2000
#define HWIO_PLL_MODE_PLL_ACK_LATCH_SHFT                           0xd
#define HWIO_PLL_MODE_PLL_LOCK_DET_FINE_BMSK                    0x1000
#define HWIO_PLL_MODE_PLL_LOCK_DET_FINE_SHFT                       0xc
#define HWIO_PLL_MODE_PCAL_DONE_BMSK                             0x800
#define HWIO_PLL_MODE_PCAL_DONE_SHFT                               0xb
#define HWIO_PLL_MODE_OUT_TEST_HW_CTL_BMSK                        0x40
#define HWIO_PLL_MODE_OUT_TEST_HW_CTL_SHFT                         0x6
#define HWIO_PLL_MODE_OUT_ODD_HW_CTL_BMSK                         0x20
#define HWIO_PLL_MODE_OUT_ODD_HW_CTL_SHFT                          0x5
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_BMSK                        0x10
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_SHFT                         0x4
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_BMSK                         0x8
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_SHFT                         0x3
#define HWIO_PLL_MODE_PLL_RESET_N_BMSK                             0x4
#define HWIO_PLL_MODE_PLL_RESET_N_SHFT                             0x2
#define HWIO_PLL_MODE_PLL_OUTCTRL_BMSK                             0x1
#define HWIO_PLL_MODE_PLL_OUTCTRL_SHFT                             0x0

/*
 * PLL_USER_CTL register definitions.
 */
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_BMSK                0x400000
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_SHFT                    0x16
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_BMSK                 0x200000
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_SHFT                     0x15
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_BMSK                    0x70000
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_SHFT                       0x10
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_ODD_BMSK                0xf000
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_ODD_SHFT                   0xc
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK                0xf00
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                  0x8
#define HWIO_PLL_USER_CTL_OUT_CLK_POLARITY_BMSK                    0x80
#define HWIO_PLL_USER_CTL_OUT_CLK_POLARITY_SHFT                     0x7
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_BMSK                         0x10
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_SHFT                          0x4
#define HWIO_PLL_USER_CTL_PLLOUT_ODD_BMSK                           0x4
#define HWIO_PLL_USER_CTL_PLLOUT_ODD_SHFT                           0x2
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_BMSK                          0x2
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_SHFT                          0x1
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_BMSK                          0x1
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_SHFT                          0x0


/*
 * PLL_USER_CTL_U register definitions.
 */
#define HWIO_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_BMSK      0x10000
#define HWIO_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_SHFT         0x10
#define HWIO_PLL_USER_CTL_U_FRAC_FORMAT_SEL_BMSK                0x8000
#define HWIO_PLL_USER_CTL_U_FRAC_FORMAT_SEL_SHFT                   0xf
#define HWIO_PLL_USER_CTL_U_REF_CLK_AT_OUT_BMSK                 0x2000
#define HWIO_PLL_USER_CTL_U_REF_CLK_AT_OUT_SHFT                    0xd
#define HWIO_PLL_USER_CTL_U_SCALE_FREQUENCY_ON_RESTART_BMSK     0x1800
#define HWIO_PLL_USER_CTL_U_SCALE_FREQUENCY_ON_RESTART_SHFT        0xb
#define HWIO_PLL_USER_CTL_U_LATCH_INTERFACE_BYPASS_BMSK          0x400
#define HWIO_PLL_USER_CTL_U_LATCH_INTERFACE_BYPASS_SHFT            0xa
#define HWIO_PLL_USER_CTL_U_STATUS_REGISTER_BMSK                 0x3e0
#define HWIO_PLL_USER_CTL_U_STATUS_REGISTER_SHFT                   0x5
#define HWIO_PLL_USER_CTL_U_WRITE_STATE_EN_BMSK                   0x10
#define HWIO_PLL_USER_CTL_U_WRITE_STATE_EN_SHFT                    0x4
#define HWIO_PLL_USER_CTL_U_CALIB_CTL_BMSK                         0xe
#define HWIO_PLL_USER_CTL_U_CALIB_CTL_SHFT                         0x1
#define HWIO_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_BMSK            0x1
#define HWIO_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_SHFT            0x0


/*
 * PLL_TEST_CTL_U register definitions.
 * All reserved space
 */


/*
 * PLL_FRAC_VAL register definitions.
 *   These fields are defined implicitly here because the bits in this register
 *   are overloaded depending on the value of PLL_USER_CTL[FRAC_FORMAT_SEL].
 *
 *   TODO Technically, these should be PLL_ALPHA_VAL instead.
 *        The same applies to Trion.
 */
#define HWIO_PLL_FRAC_VAL_PLL_FRAC_VAL_BMSK                     0xffff
#define HWIO_PLL_FRAC_VAL_PLL_FRAC_VAL_SHFT                        0x0
#define HWIO_PLL_FRAC_VAL_M_VAL_BMSK                              0xff
#define HWIO_PLL_FRAC_VAL_M_VAL_SHFT                               0x8
#define HWIO_PLL_FRAC_VAL_N_VAL_BMSK                              0xff
#define HWIO_PLL_FRAC_VAL_N_VAL_SHFT                               0x0


/*
 * PLL_STATUS register definitions.
 */
#define HWIO_PLL_STATUS_STATUS_0_CAL_DONE_BMSK               0x4000000
#define HWIO_PLL_STATUS_STATUS_0_CAL_DONE_SHFT                      26


/* ============================================================================
**    External Definitions
** ==========================================================================*/


/* ============================================================================
**    Functions
** ==========================================================================*/

#endif  /* __HALCLKLUCID5lpePLL_H__ */
 

