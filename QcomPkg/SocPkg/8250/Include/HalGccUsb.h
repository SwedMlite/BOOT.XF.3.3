#include "msmhwiobase.h"
#include "HALhwio.h"

/*----------------------------------------------------------------------------
 * MODULE: GCC_CLK_CTL_REG
 *--------------------------------------------------------------------------*/
#define GCC_CLK_CTL_REG_REG_BASE                                                                   (CLK_CTL_BASE      + 0x00000000)
#define GCC_CLK_CTL_REG_REG_BASE_SIZE                                                              0x1f0000
#define GCC_CLK_CTL_REG_REG_BASE_USED                                                              0x9c100
#define GCC_CLK_CTL_REG_REG_BASE_PHYS                                                              (CLK_CTL_BASE_PHYS + 0x00000000)
#define GCC_CLK_CTL_REG_REG_BASE_OFFS                                                              0x00000000

#define HWIO_GCC_USB30_PRIM_BCR_ADDR                                                               (GCC_CLK_CTL_REG_REG_BASE      + 0x0000f000)
#define HWIO_GCC_USB30_PRIM_BCR_PHYS                                                               (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0000f000)
#define HWIO_GCC_USB30_PRIM_BCR_OFFS                                                               (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0000f000)
#define HWIO_GCC_USB30_PRIM_BCR_RMSK                                                                      0x1
#define HWIO_GCC_USB30_PRIM_BCR_POR                                                                0x00000000
#define HWIO_GCC_USB30_PRIM_BCR_POR_RMSK                                                           0xffffffff
#define HWIO_GCC_USB30_PRIM_BCR_ATTR                                                                      0x3
#define HWIO_GCC_USB30_PRIM_BCR_IN          \
        in_dword(HWIO_GCC_USB30_PRIM_BCR_ADDR)
#define HWIO_GCC_USB30_PRIM_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_PRIM_BCR_ADDR, m)
#define HWIO_GCC_USB30_PRIM_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_PRIM_BCR_ADDR,v)
#define HWIO_GCC_USB30_PRIM_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_PRIM_BCR_ADDR,m,v,HWIO_GCC_USB30_PRIM_BCR_IN)
#define HWIO_GCC_USB30_PRIM_BCR_BLK_ARES_BMSK                                                             0x1
#define HWIO_GCC_USB30_PRIM_BCR_BLK_ARES_SHFT                                                             0x0
#define HWIO_GCC_USB30_PRIM_BCR_BLK_ARES_DISABLE_FVAL                                                     0x0
#define HWIO_GCC_USB30_PRIM_BCR_BLK_ARES_ENABLE_FVAL                                                      0x1

#define HWIO_GCC_USB30_PRIM_GDSCR_ADDR                                                             (GCC_CLK_CTL_REG_REG_BASE      + 0x0000f004)
#define HWIO_GCC_USB30_PRIM_GDSCR_PHYS                                                             (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0000f004)
#define HWIO_GCC_USB30_PRIM_GDSCR_OFFS                                                             (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0000f004)
#define HWIO_GCC_USB30_PRIM_GDSCR_RMSK                                                             0xf8ffffff
#define HWIO_GCC_USB30_PRIM_GDSCR_POR                                                              0x0022f001
#define HWIO_GCC_USB30_PRIM_GDSCR_POR_RMSK                                                         0xffffffff
#define HWIO_GCC_USB30_PRIM_GDSCR_ATTR                                                                    0x3
#define HWIO_GCC_USB30_PRIM_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_PRIM_GDSCR_ADDR)
#define HWIO_GCC_USB30_PRIM_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_PRIM_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_PRIM_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_PRIM_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_PRIM_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_PRIM_GDSCR_ADDR,m,v,HWIO_GCC_USB30_PRIM_GDSCR_IN)
#define HWIO_GCC_USB30_PRIM_GDSCR_PWR_ON_BMSK                                                      0x80000000
#define HWIO_GCC_USB30_PRIM_GDSCR_PWR_ON_SHFT                                                            0x1f
#define HWIO_GCC_USB30_PRIM_GDSCR_GDSC_STATE_BMSK                                                  0x78000000
#define HWIO_GCC_USB30_PRIM_GDSCR_GDSC_STATE_SHFT                                                        0x1b
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_WAIT_BMSK                                                  0xf00000
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_WAIT_SHFT                                                      0x14
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_WAIT_BMSK                                                    0xf0000
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_WAIT_SHFT                                                       0x10
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DIS_WAIT_BMSK                                                    0xf000
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DIS_WAIT_SHFT                                                       0xc
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_FF_ENABLE_BMSK                                                 0x800
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_FF_ENABLE_SHFT                                                   0xb
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                           0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                            0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_RESTORE_BMSK                                                          0x400
#define HWIO_GCC_USB30_PRIM_GDSCR_RESTORE_SHFT                                                            0xa
#define HWIO_GCC_USB30_PRIM_GDSCR_RESTORE_DISABLE_FVAL                                                    0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_RESTORE_ENABLE_FVAL                                                     0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_SAVE_BMSK                                                             0x200
#define HWIO_GCC_USB30_PRIM_GDSCR_SAVE_SHFT                                                               0x9
#define HWIO_GCC_USB30_PRIM_GDSCR_SAVE_DISABLE_FVAL                                                       0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_SAVE_ENABLE_FVAL                                                        0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_BMSK                                                           0x100
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_SHFT                                                             0x8
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_DISABLE_FVAL                                                     0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_RETAIN_ENABLE_FVAL                                                      0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_BMSK                                                           0x80
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_SHFT                                                            0x7
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_DISABLE_FVAL                                                    0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_REST_ENABLE_FVAL                                                     0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_BMSK                                                            0x40
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_SHFT                                                             0x6
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_DISABLE_FVAL                                                     0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_EN_FEW_ENABLE_FVAL                                                      0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_CLAMP_IO_BMSK                                                          0x20
#define HWIO_GCC_USB30_PRIM_GDSCR_CLAMP_IO_SHFT                                                           0x5
#define HWIO_GCC_USB30_PRIM_GDSCR_CLAMP_IO_DISABLE_FVAL                                                   0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_CLAMP_IO_ENABLE_FVAL                                                    0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DISABLE_BMSK                                                       0x10
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DISABLE_SHFT                                                        0x4
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                        0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                                            0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_PD_ARES_BMSK                                                            0x8
#define HWIO_GCC_USB30_PRIM_GDSCR_PD_ARES_SHFT                                                            0x3
#define HWIO_GCC_USB30_PRIM_GDSCR_PD_ARES_NO_RESET_FVAL                                                   0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_PD_ARES_RESET_FVAL                                                      0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_OVERRIDE_BMSK                                                        0x4
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_OVERRIDE_SHFT                                                        0x2
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                                0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                                 0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_HW_CONTROL_BMSK                                                         0x2
#define HWIO_GCC_USB30_PRIM_GDSCR_HW_CONTROL_SHFT                                                         0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_HW_CONTROL_DISABLE_FVAL                                                 0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_HW_CONTROL_ENABLE_FVAL                                                  0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_COLLAPSE_BMSK                                                        0x1
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_COLLAPSE_SHFT                                                        0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                                0x0
#define HWIO_GCC_USB30_PRIM_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                                 0x1

#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_ADDR                                                         (GCC_CLK_CTL_REG_REG_BASE      + 0x0000f008)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_PHYS                                                         (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0000f008)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_OFFS                                                         (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0000f008)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_RMSK                                                         0xffffffff
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_POR                                                          0x00088000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_POR_RMSK                                                     0xffffffff
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_ATTR                                                                0x3
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_PRIM_CFG_GDSCR_ADDR)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_PRIM_CFG_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_PRIM_CFG_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_PRIM_CFG_GDSCR_ADDR,m,v,HWIO_GCC_USB30_PRIM_CFG_GDSCR_IN)
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                      0xf0000000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                            0x1c
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                      0xc000000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                           0x1a
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                       0x2000000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                            0x19
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                        0x1000000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                             0x18
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                                 0xf00000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                     0x14
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                                    0x80000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                       0x13
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                        0x40000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                           0x12
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                        0x20000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                           0x11
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                                     0x10000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                        0x10
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                                    0x8000
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                       0xf
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                                   0x7800
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                      0xb
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                           0x400
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                             0xa
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                                    0x200
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                      0x9
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                                    0x100
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                      0x8
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                        0x80
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                         0x7
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                               0x60
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                                0x5
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                         0x10
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                          0x4
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                   0x8
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                   0x3
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                                 0x4
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                                 0x2
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                     0x2
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                     0x1
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                                  0x1
#define HWIO_GCC_USB30_PRIM_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                                  0x0

#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ADDR                                                        (GCC_CLK_CTL_REG_REG_BASE      + 0x0000f00c)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_PHYS                                                        (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0000f00c)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_OFFS                                                        (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0000f00c)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_RMSK                                                           0x1ffff
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_POR                                                         0x0000022a
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_POR_RMSK                                                    0xffffffff
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ATTR                                                               0x3
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ADDR)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_PRIM_CFG2_GDSCR_ADDR,m,v,HWIO_GCC_USB30_PRIM_CFG2_GDSCR_IN)
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                         0x10000
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                            0x10
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                             0xf000
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                                0xc
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                                      0xf00
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                        0x8
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                         0xf0
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                          0x4
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                           0xf
#define HWIO_GCC_USB30_PRIM_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                           0x0

#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ADDR                                                      (GCC_CLK_CTL_REG_REG_BASE      + 0x0000f05c)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_PHYS                                                      (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0000f05c)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_OFFS                                                      (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0000f05c)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_RMSK                                                      0x80000005
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_POR                                                       0x80000000
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_POR_RMSK                                                  0xffffffff
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ATTR                                                             0x3
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_IN          \
        in_dword(HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ADDR)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ADDR, m)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ADDR,v)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_ADDR,m,v,HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_IN)
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_OFF_BMSK                                              0x80000000
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_OFF_SHFT                                                    0x1f
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ARES_BMSK                                                    0x4
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ARES_SHFT                                                    0x2
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ARES_RESET_FVAL                                              0x1
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ENABLE_BMSK                                                  0x1
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ENABLE_SHFT                                                  0x0
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0
#define HWIO_GCC_USB3_PRIM_PHY_PIPE_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1

#define HWIO_GCC_USB30_SEC_BCR_ADDR                                                                (GCC_CLK_CTL_REG_REG_BASE      + 0x00010000)
#define HWIO_GCC_USB30_SEC_BCR_PHYS                                                                (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00010000)
#define HWIO_GCC_USB30_SEC_BCR_OFFS                                                                (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00010000)
#define HWIO_GCC_USB30_SEC_BCR_RMSK                                                                       0x1
#define HWIO_GCC_USB30_SEC_BCR_POR                                                                 0x00000000
#define HWIO_GCC_USB30_SEC_BCR_POR_RMSK                                                            0xffffffff
#define HWIO_GCC_USB30_SEC_BCR_ATTR                                                                       0x3
#define HWIO_GCC_USB30_SEC_BCR_IN          \
        in_dword(HWIO_GCC_USB30_SEC_BCR_ADDR)
#define HWIO_GCC_USB30_SEC_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_SEC_BCR_ADDR, m)
#define HWIO_GCC_USB30_SEC_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_SEC_BCR_ADDR,v)
#define HWIO_GCC_USB30_SEC_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_SEC_BCR_ADDR,m,v,HWIO_GCC_USB30_SEC_BCR_IN)
#define HWIO_GCC_USB30_SEC_BCR_BLK_ARES_BMSK                                                              0x1
#define HWIO_GCC_USB30_SEC_BCR_BLK_ARES_SHFT                                                              0x0
#define HWIO_GCC_USB30_SEC_BCR_BLK_ARES_DISABLE_FVAL                                                      0x0
#define HWIO_GCC_USB30_SEC_BCR_BLK_ARES_ENABLE_FVAL                                                       0x1

#define HWIO_GCC_USB30_SEC_GDSCR_ADDR                                                              (GCC_CLK_CTL_REG_REG_BASE      + 0x00010004)
#define HWIO_GCC_USB30_SEC_GDSCR_PHYS                                                              (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00010004)
#define HWIO_GCC_USB30_SEC_GDSCR_OFFS                                                              (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00010004)
#define HWIO_GCC_USB30_SEC_GDSCR_RMSK                                                              0xf8ffffff
#define HWIO_GCC_USB30_SEC_GDSCR_POR                                                               0x0022f001
#define HWIO_GCC_USB30_SEC_GDSCR_POR_RMSK                                                          0xffffffff
#define HWIO_GCC_USB30_SEC_GDSCR_ATTR                                                                     0x3
#define HWIO_GCC_USB30_SEC_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_SEC_GDSCR_ADDR)
#define HWIO_GCC_USB30_SEC_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_SEC_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_SEC_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_SEC_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_SEC_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_SEC_GDSCR_ADDR,m,v,HWIO_GCC_USB30_SEC_GDSCR_IN)
#define HWIO_GCC_USB30_SEC_GDSCR_PWR_ON_BMSK                                                       0x80000000
#define HWIO_GCC_USB30_SEC_GDSCR_PWR_ON_SHFT                                                             0x1f
#define HWIO_GCC_USB30_SEC_GDSCR_GDSC_STATE_BMSK                                                   0x78000000
#define HWIO_GCC_USB30_SEC_GDSCR_GDSC_STATE_SHFT                                                         0x1b
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_WAIT_BMSK                                                   0xf00000
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_WAIT_SHFT                                                       0x14
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_WAIT_BMSK                                                     0xf0000
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_WAIT_SHFT                                                        0x10
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DIS_WAIT_BMSK                                                     0xf000
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DIS_WAIT_SHFT                                                        0xc
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_FF_ENABLE_BMSK                                                  0x800
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_FF_ENABLE_SHFT                                                    0xb
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                            0x0
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                             0x1
#define HWIO_GCC_USB30_SEC_GDSCR_RESTORE_BMSK                                                           0x400
#define HWIO_GCC_USB30_SEC_GDSCR_RESTORE_SHFT                                                             0xa
#define HWIO_GCC_USB30_SEC_GDSCR_RESTORE_DISABLE_FVAL                                                     0x0
#define HWIO_GCC_USB30_SEC_GDSCR_RESTORE_ENABLE_FVAL                                                      0x1
#define HWIO_GCC_USB30_SEC_GDSCR_SAVE_BMSK                                                              0x200
#define HWIO_GCC_USB30_SEC_GDSCR_SAVE_SHFT                                                                0x9
#define HWIO_GCC_USB30_SEC_GDSCR_SAVE_DISABLE_FVAL                                                        0x0
#define HWIO_GCC_USB30_SEC_GDSCR_SAVE_ENABLE_FVAL                                                         0x1
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_BMSK                                                            0x100
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_SHFT                                                              0x8
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_DISABLE_FVAL                                                      0x0
#define HWIO_GCC_USB30_SEC_GDSCR_RETAIN_ENABLE_FVAL                                                       0x1
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_BMSK                                                            0x80
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_SHFT                                                             0x7
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_DISABLE_FVAL                                                     0x0
#define HWIO_GCC_USB30_SEC_GDSCR_EN_REST_ENABLE_FVAL                                                      0x1
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_BMSK                                                             0x40
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_SHFT                                                              0x6
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_DISABLE_FVAL                                                      0x0
#define HWIO_GCC_USB30_SEC_GDSCR_EN_FEW_ENABLE_FVAL                                                       0x1
#define HWIO_GCC_USB30_SEC_GDSCR_CLAMP_IO_BMSK                                                           0x20
#define HWIO_GCC_USB30_SEC_GDSCR_CLAMP_IO_SHFT                                                            0x5
#define HWIO_GCC_USB30_SEC_GDSCR_CLAMP_IO_DISABLE_FVAL                                                    0x0
#define HWIO_GCC_USB30_SEC_GDSCR_CLAMP_IO_ENABLE_FVAL                                                     0x1
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DISABLE_BMSK                                                        0x10
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DISABLE_SHFT                                                         0x4
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                         0x0
#define HWIO_GCC_USB30_SEC_GDSCR_CLK_DISABLE_CLK_DISABLE_FVAL                                             0x1
#define HWIO_GCC_USB30_SEC_GDSCR_PD_ARES_BMSK                                                             0x8
#define HWIO_GCC_USB30_SEC_GDSCR_PD_ARES_SHFT                                                             0x3
#define HWIO_GCC_USB30_SEC_GDSCR_PD_ARES_NO_RESET_FVAL                                                    0x0
#define HWIO_GCC_USB30_SEC_GDSCR_PD_ARES_RESET_FVAL                                                       0x1
#define HWIO_GCC_USB30_SEC_GDSCR_SW_OVERRIDE_BMSK                                                         0x4
#define HWIO_GCC_USB30_SEC_GDSCR_SW_OVERRIDE_SHFT                                                         0x2
#define HWIO_GCC_USB30_SEC_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                                 0x0
#define HWIO_GCC_USB30_SEC_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                                  0x1
#define HWIO_GCC_USB30_SEC_GDSCR_HW_CONTROL_BMSK                                                          0x2
#define HWIO_GCC_USB30_SEC_GDSCR_HW_CONTROL_SHFT                                                          0x1
#define HWIO_GCC_USB30_SEC_GDSCR_HW_CONTROL_DISABLE_FVAL                                                  0x0
#define HWIO_GCC_USB30_SEC_GDSCR_HW_CONTROL_ENABLE_FVAL                                                   0x1
#define HWIO_GCC_USB30_SEC_GDSCR_SW_COLLAPSE_BMSK                                                         0x1
#define HWIO_GCC_USB30_SEC_GDSCR_SW_COLLAPSE_SHFT                                                         0x0
#define HWIO_GCC_USB30_SEC_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                                 0x0
#define HWIO_GCC_USB30_SEC_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                                  0x1

#define HWIO_GCC_USB30_SEC_CFG_GDSCR_ADDR                                                          (GCC_CLK_CTL_REG_REG_BASE      + 0x00010008)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_PHYS                                                          (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00010008)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_OFFS                                                          (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00010008)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_RMSK                                                          0xffffffff
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_POR                                                           0x00088000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_POR_RMSK                                                      0xffffffff
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_ATTR                                                                 0x3
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_SEC_CFG_GDSCR_ADDR)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_SEC_CFG_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_SEC_CFG_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_SEC_CFG_GDSCR_ADDR,m,v,HWIO_GCC_USB30_SEC_CFG_GDSCR_IN)
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                       0xf0000000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                             0x1c
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                       0xc000000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                            0x1a
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                                        0x2000000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                             0x19
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                         0x1000000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                              0x18
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                                  0xf00000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                                      0x14
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                                     0x80000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                        0x13
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                         0x40000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                            0x12
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                         0x20000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                            0x11
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                                      0x10000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                         0x10
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                                     0x8000
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                        0xf
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                                    0x7800
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                                       0xb
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                            0x400
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                              0xa
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                                     0x200
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                       0x9
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                                     0x100
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                       0x8
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                         0x80
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                          0x7
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                                0x60
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                                 0x5
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                          0x10
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                           0x4
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                    0x8
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                    0x3
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                                  0x4
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                                  0x2
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                                      0x2
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                                      0x1
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                                   0x1
#define HWIO_GCC_USB30_SEC_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                                   0x0

#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_ADDR                                                         (GCC_CLK_CTL_REG_REG_BASE      + 0x0001000c)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_PHYS                                                         (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0001000c)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_OFFS                                                         (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0001000c)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_RMSK                                                            0x1ffff
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_POR                                                          0x0000022a
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_POR_RMSK                                                     0xffffffff
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_ATTR                                                                0x3
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_IN          \
        in_dword(HWIO_GCC_USB30_SEC_CFG2_GDSCR_ADDR)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB30_SEC_CFG2_GDSCR_ADDR, m)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_OUT(v)      \
        out_dword(HWIO_GCC_USB30_SEC_CFG2_GDSCR_ADDR,v)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB30_SEC_CFG2_GDSCR_ADDR,m,v,HWIO_GCC_USB30_SEC_CFG2_GDSCR_IN)
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                          0x10000
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                             0x10
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                              0xf000
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                                 0xc
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                                       0xf00
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                         0x8
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                          0xf0
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                           0x4
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                            0xf
#define HWIO_GCC_USB30_SEC_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                            0x0

#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ADDR                                                       (GCC_CLK_CTL_REG_REG_BASE      + 0x0001005c)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_PHYS                                                       (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0001005c)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_OFFS                                                       (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0001005c)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_RMSK                                                       0x80000005
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_POR                                                        0x80000000
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_POR_RMSK                                                   0xffffffff
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ATTR                                                              0x3
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_IN          \
        in_dword(HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ADDR)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ADDR, m)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ADDR,v)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_ADDR,m,v,HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_IN)
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_OFF_BMSK                                               0x80000000
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_OFF_SHFT                                                     0x1f
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ARES_BMSK                                                     0x4
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ARES_SHFT                                                     0x2
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ARES_NO_RESET_FVAL                                            0x0
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ARES_RESET_FVAL                                               0x1
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ENABLE_BMSK                                                   0x1
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ENABLE_SHFT                                                   0x0
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ENABLE_DISABLE_FVAL                                           0x0
#define HWIO_GCC_USB3_SEC_PHY_PIPE_CBCR_CLK_ENABLE_ENABLE_FVAL                                            0x1

#define HWIO_GCC_USB3_PHY_PRIM_BCR_ADDR                                                            (GCC_CLK_CTL_REG_REG_BASE      + 0x00050000)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_PHYS                                                            (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00050000)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_OFFS                                                            (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00050000)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_RMSK                                                                   0x1
#define HWIO_GCC_USB3_PHY_PRIM_BCR_POR                                                             0x00000001
#define HWIO_GCC_USB3_PHY_PRIM_BCR_POR_RMSK                                                        0xffffffff
#define HWIO_GCC_USB3_PHY_PRIM_BCR_ATTR                                                                   0x3
#define HWIO_GCC_USB3_PHY_PRIM_BCR_IN          \
        in_dword(HWIO_GCC_USB3_PHY_PRIM_BCR_ADDR)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_PHY_PRIM_BCR_ADDR, m)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_PHY_PRIM_BCR_ADDR,v)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_PHY_PRIM_BCR_ADDR,m,v,HWIO_GCC_USB3_PHY_PRIM_BCR_IN)
#define HWIO_GCC_USB3_PHY_PRIM_BCR_BLK_ARES_BMSK                                                          0x1
#define HWIO_GCC_USB3_PHY_PRIM_BCR_BLK_ARES_SHFT                                                          0x0
#define HWIO_GCC_USB3_PHY_PRIM_BCR_BLK_ARES_DISABLE_FVAL                                                  0x0
#define HWIO_GCC_USB3_PHY_PRIM_BCR_BLK_ARES_ENABLE_FVAL                                                   0x1

#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ADDR                                                         (GCC_CLK_CTL_REG_REG_BASE      + 0x00050004)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_PHYS                                                         (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00050004)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_OFFS                                                         (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00050004)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_RMSK                                                                0x1
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_POR                                                          0x00000000
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_POR_RMSK                                                     0xffffffff
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ATTR                                                                0x3
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_IN          \
        in_dword(HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ADDR)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ADDR, m)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ADDR,v)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3PHY_PHY_PRIM_BCR_ADDR,m,v,HWIO_GCC_USB3PHY_PHY_PRIM_BCR_IN)
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_BLK_ARES_BMSK                                                       0x1
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_BLK_ARES_SHFT                                                       0x0
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_BLK_ARES_DISABLE_FVAL                                               0x0
#define HWIO_GCC_USB3PHY_PHY_PRIM_BCR_BLK_ARES_ENABLE_FVAL                                                0x1

#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ADDR                                                         (GCC_CLK_CTL_REG_REG_BASE      + 0x00050008)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_PHYS                                                         (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00050008)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_OFFS                                                         (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00050008)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_RMSK                                                                0x1
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_POR                                                          0x00000000
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_POR_RMSK                                                     0xffffffff
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ATTR                                                                0x3
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_IN          \
        in_dword(HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ADDR)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ADDR, m)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ADDR,v)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_DP_PHY_PRIM_BCR_ADDR,m,v,HWIO_GCC_USB3_DP_PHY_PRIM_BCR_IN)
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_BLK_ARES_BMSK                                                       0x1
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_BLK_ARES_SHFT                                                       0x0
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_BLK_ARES_DISABLE_FVAL                                               0x0
#define HWIO_GCC_USB3_DP_PHY_PRIM_BCR_BLK_ARES_ENABLE_FVAL                                                0x1

#define HWIO_GCC_USB3_PHY_SEC_BCR_ADDR                                                             (GCC_CLK_CTL_REG_REG_BASE      + 0x0005000c)
#define HWIO_GCC_USB3_PHY_SEC_BCR_PHYS                                                             (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0005000c)
#define HWIO_GCC_USB3_PHY_SEC_BCR_OFFS                                                             (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0005000c)
#define HWIO_GCC_USB3_PHY_SEC_BCR_RMSK                                                                    0x1
#define HWIO_GCC_USB3_PHY_SEC_BCR_POR                                                              0x00000000
#define HWIO_GCC_USB3_PHY_SEC_BCR_POR_RMSK                                                         0xffffffff
#define HWIO_GCC_USB3_PHY_SEC_BCR_ATTR                                                                    0x3
#define HWIO_GCC_USB3_PHY_SEC_BCR_IN          \
        in_dword(HWIO_GCC_USB3_PHY_SEC_BCR_ADDR)
#define HWIO_GCC_USB3_PHY_SEC_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_PHY_SEC_BCR_ADDR, m)
#define HWIO_GCC_USB3_PHY_SEC_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_PHY_SEC_BCR_ADDR,v)
#define HWIO_GCC_USB3_PHY_SEC_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_PHY_SEC_BCR_ADDR,m,v,HWIO_GCC_USB3_PHY_SEC_BCR_IN)
#define HWIO_GCC_USB3_PHY_SEC_BCR_BLK_ARES_BMSK                                                           0x1
#define HWIO_GCC_USB3_PHY_SEC_BCR_BLK_ARES_SHFT                                                           0x0
#define HWIO_GCC_USB3_PHY_SEC_BCR_BLK_ARES_DISABLE_FVAL                                                   0x0
#define HWIO_GCC_USB3_PHY_SEC_BCR_BLK_ARES_ENABLE_FVAL                                                    0x1

#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_ADDR                                                          (GCC_CLK_CTL_REG_REG_BASE      + 0x00050010)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_PHYS                                                          (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00050010)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_OFFS                                                          (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00050010)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_RMSK                                                                 0x1
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_POR                                                           0x00000000
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_POR_RMSK                                                      0xffffffff
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_ATTR                                                                 0x3
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_IN          \
        in_dword(HWIO_GCC_USB3PHY_PHY_SEC_BCR_ADDR)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3PHY_PHY_SEC_BCR_ADDR, m)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3PHY_PHY_SEC_BCR_ADDR,v)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3PHY_PHY_SEC_BCR_ADDR,m,v,HWIO_GCC_USB3PHY_PHY_SEC_BCR_IN)
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_BLK_ARES_BMSK                                                        0x1
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_BLK_ARES_SHFT                                                        0x0
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_BLK_ARES_DISABLE_FVAL                                                0x0
#define HWIO_GCC_USB3PHY_PHY_SEC_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1

#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_ADDR                                                          (GCC_CLK_CTL_REG_REG_BASE      + 0x00050014)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_PHYS                                                          (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00050014)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_OFFS                                                          (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00050014)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_RMSK                                                                 0x1
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_POR                                                           0x00000000
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_POR_RMSK                                                      0xffffffff
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_ATTR                                                                 0x3
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_IN          \
        in_dword(HWIO_GCC_USB3_DP_PHY_SEC_BCR_ADDR)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_DP_PHY_SEC_BCR_ADDR, m)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB3_DP_PHY_SEC_BCR_ADDR,v)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_DP_PHY_SEC_BCR_ADDR,m,v,HWIO_GCC_USB3_DP_PHY_SEC_BCR_IN)
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_BLK_ARES_BMSK                                                        0x1
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_BLK_ARES_SHFT                                                        0x0
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_BLK_ARES_DISABLE_FVAL                                                0x0
#define HWIO_GCC_USB3_DP_PHY_SEC_BCR_BLK_ARES_ENABLE_FVAL                                                 0x1

#define HWIO_GCC_QUSB2PHY_PRIM_BCR_ADDR                                                            (GCC_CLK_CTL_REG_REG_BASE      + 0x00012000)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_PHYS                                                            (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00012000)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_OFFS                                                            (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00012000)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_RMSK                                                                   0x1
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_POR                                                             0x00000000
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_POR_RMSK                                                        0xffffffff
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_ATTR                                                                   0x3
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_IN          \
        in_dword(HWIO_GCC_QUSB2PHY_PRIM_BCR_ADDR)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_QUSB2PHY_PRIM_BCR_ADDR, m)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_OUT(v)      \
        out_dword(HWIO_GCC_QUSB2PHY_PRIM_BCR_ADDR,v)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_QUSB2PHY_PRIM_BCR_ADDR,m,v,HWIO_GCC_QUSB2PHY_PRIM_BCR_IN)
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_BLK_ARES_BMSK                                                          0x1
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_BLK_ARES_SHFT                                                          0x0
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_BLK_ARES_DISABLE_FVAL                                                  0x0
#define HWIO_GCC_QUSB2PHY_PRIM_BCR_BLK_ARES_ENABLE_FVAL                                                   0x1

#define HWIO_GCC_QUSB2PHY_SEC_BCR_ADDR                                                             (GCC_CLK_CTL_REG_REG_BASE      + 0x00012004)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_PHYS                                                             (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x00012004)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_OFFS                                                             (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x00012004)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_RMSK                                                                    0x1
#define HWIO_GCC_QUSB2PHY_SEC_BCR_POR                                                              0x00000000
#define HWIO_GCC_QUSB2PHY_SEC_BCR_POR_RMSK                                                         0xffffffff
#define HWIO_GCC_QUSB2PHY_SEC_BCR_ATTR                                                                    0x3
#define HWIO_GCC_QUSB2PHY_SEC_BCR_IN          \
        in_dword(HWIO_GCC_QUSB2PHY_SEC_BCR_ADDR)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_QUSB2PHY_SEC_BCR_ADDR, m)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_OUT(v)      \
        out_dword(HWIO_GCC_QUSB2PHY_SEC_BCR_ADDR,v)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_QUSB2PHY_SEC_BCR_ADDR,m,v,HWIO_GCC_QUSB2PHY_SEC_BCR_IN)
#define HWIO_GCC_QUSB2PHY_SEC_BCR_BLK_ARES_BMSK                                                           0x1
#define HWIO_GCC_QUSB2PHY_SEC_BCR_BLK_ARES_SHFT                                                           0x0
#define HWIO_GCC_QUSB2PHY_SEC_BCR_BLK_ARES_DISABLE_FVAL                                                   0x0
#define HWIO_GCC_QUSB2PHY_SEC_BCR_BLK_ARES_ENABLE_FVAL                                                    0x1

#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ADDR                                                      (GCC_CLK_CTL_REG_REG_BASE      + 0x0006a000)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_PHYS                                                      (GCC_CLK_CTL_REG_REG_BASE_PHYS + 0x0006a000)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_OFFS                                                      (GCC_CLK_CTL_REG_REG_BASE_OFFS + 0x0006a000)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_RMSK                                                             0x1
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_POR                                                       0x00000000
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_POR_RMSK                                                  0xffffffff
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ATTR                                                             0x3
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_IN          \
        in_dword(HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ADDR)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_INM(m)      \
        in_dword_masked(HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ADDR, m)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_OUT(v)      \
        out_dword(HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ADDR,v)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_ADDR,m,v,HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_IN)
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_BLK_ARES_BMSK                                                    0x1
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_BLK_ARES_SHFT                                                    0x0
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_BLK_ARES_DISABLE_FVAL                                            0x0
#define HWIO_GCC_USB_PHY_CFG_AHB2PHY_BCR_BLK_ARES_ENABLE_FVAL                                             0x1

#define HWIO_GCC_USB3_SEC_CLKREF_EN_ADDR                                                           (GCC_CLK_CTL_REG_REG_BASE      + 0x0008c010)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_OFFS                                                           (0x0008c010)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_RMSK                                                           0x80000001
#define HWIO_GCC_USB3_SEC_CLKREF_EN_IN          \
        in_dword(HWIO_GCC_USB3_SEC_CLKREF_EN_ADDR)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_INM(m)      \
        in_dword_masked(HWIO_GCC_USB3_SEC_CLKREF_EN_ADDR, m)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_OUT(v)      \
        out_dword(HWIO_GCC_USB3_SEC_CLKREF_EN_ADDR,v)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_OUTM(m,v) \
        out_dword_masked_ns(HWIO_GCC_USB3_SEC_CLKREF_EN_ADDR,m,v,HWIO_GCC_USB3_SEC_CLKREF_EN_IN)
#define HWIO_GCC_USB3_SEC_CLKREF_EN_USB3_STATUS_BMSK                                               0x80000000
#define HWIO_GCC_USB3_SEC_CLKREF_EN_USB3_STATUS_SHFT                                                     0x1f
#define HWIO_GCC_USB3_SEC_CLKREF_EN_USB3_ENABLE_BMSK                                                      0x1
#define HWIO_GCC_USB3_SEC_CLKREF_EN_USB3_ENABLE_SHFT                                                      0x0

