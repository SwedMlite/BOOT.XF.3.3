/*! \file
*  \n
*  \brief  pm_spmi_config.c
*  \n
*  \n This file contains pmic configuration data specific for SPMI Controller's
      Peripheral for SDM855 device..
*  \n
*  \n &copy; Copyright 2015-2019 QUALCOMM Technologies, Incorporated, All Rights Reserved
*/
/* =======================================================================
Edit History
This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/PMIC/pm_spmi_config.c#9 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
04/02/18   aab     Updated PM855 SDAM7 peripheral access control to APPS
03/22/18   aab     Updated to support PM855A/P
03/05/18   aab     Updated it with PM8009 PMIC
11/14/17   aab     Created to support SDM855
========================================================================== */

/*-------------------------------------------------------------------------
* Include Files
* ----------------------------------------------------------------------*/

#include "pm_device.h"
#include "SpmiCfg.h"
#include "SpmiBusCfg.h" 

/*-------------------------------------------------------------------------
* Preprocessor Definitions and Constants
* ----------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
* Static Variable Definitions
* ----------------------------------------------------------------------*/

/* PMIC MMU/SMMU configuration table. */

SpmiCfg_ChannelCfg pm_spmi_channel_cfg [] =
{
/*SID, Periph ID, IRQ Owner, Periph Owner */ 
  /* PM8250(Wailua) */
  /* PM8150B(Kekaha) */
  /* PM8150A(Makua) */
  /* PMK8002(Timex) */
  /* PMX55(Tibet) */
  /* PM8009(Yoda) */
  {0, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_TZ},   /* BUS  */
  {0, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_TZ},   /* PON  */
  {0, 0x60, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* RTC_RW  */
  {0, 0x70, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* PBS_CORE  */
  {0, 0xB0, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* SDAM1 Shared Info TZ:  TDOS:Table 3-5 RAM size for SDAMM on PM854 */
  {2, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_TZ},   /* BUS PBUS Logger */
  {2, 0x70, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* PBS_CORE  */
  {4, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_TZ},   /* BUS  */
  {4, 0x70, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* PBS_CORE  */
  {8, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_TZ},   /* PON locking it causes issue with poff/wr - seen on hana/poipu */
  {10, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_TZ},   /* BUS  */
  {10, 0x70, SPMI_OWNER_TZ,    SPMI_OWNER_TZ},   /* PBS_CORE  */
  {0, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* BUS  */
  {0, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* PON  */
  {0, 0x24, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* TEMP_ALARM ALARM */
  {0, 0x31, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_CORE1_USR VADC (SINGLE-SHOT) */
  {0, 0x35, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_CORE5_BTM4 VADC BTM (THRESHOLDS) */
  {0, 0x5B, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* DIV_CLK1  */
  {0, 0x5C, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* DIV_CLK2  */
  {0, 0x61, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* RTC_ALARM  */
  {0, 0x62, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* RTC_TIMER  */
  {0, 0xB1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SDAM2 Shared Info HLOS */
  {0, 0xB6, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SDAM7 PBS Pattern Generator1: Spare:  To be used for testing */
  {0, 0xC0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO01 Home Key */
  {0, 0xC2, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO03 NFC 32kHz SLEEP CLK (Backup) */
  {0, 0xC5, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO06 Volume (+) Key */
  {0, 0xC6, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO07 Handshake - Single Line Bus (SLB) */
  {0, 0xC8, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO09 Secondary USB port external boost and OVP IC enable */
  {0, 0xC9, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO10 Secondary USB port VBUS detection (must be MV) */
  {2, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* BUS PBUS Logger */
  {2, 0x10, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_CHGR only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x11, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_DCDC only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x12, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_BATIF only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x13, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_USB only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x14, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_DC only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x15, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_TYPEC only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x16, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_MISC only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x17, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* USB_PD_PHY only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x18, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_FREQ only D1 register will be written. D2 will be open for use by HLOS */
  {2, 0x19, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SCHG_P_OTP_HDR  */
  {2, 0x1A, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* BMD BIM (Battery Interface Module) = BMD (Battery Missing Detection) + BSI */
  {2, 0x1B, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* BSI BSI (MIPI specification for talking to smart battery) */
  {2, 0x1D, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* BCLBIG_COMP  */
  {2, 0x24, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* TEMP_ALARM  */
  {2, 0x31, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_FG1_USR  */
  {2, 0x35, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_FG5_BTM_4  */
  {2, 0x37, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_FG4_CAL  */
  {2, 0x40, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_BATT_SOC  */
  {2, 0x41, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_BATT_INFO  */
  {2, 0x42, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_ADC_RR  */
  {2, 0x43, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_MEM_IF  */
  {2, 0x44, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_1 confirm for DMA if D1 */
  {2, 0x45, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_2  */
  {2, 0x46, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_3  */
  {2, 0x47, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_4  */
  {2, 0x48, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_5  */
  {2, 0x49, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* FG_DMA_6  */
  {2, 0x60, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* DIV_CLK  */
  {2, 0x72, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* PBS_CLIENT1 Charger uses for external Rsense */
  {2, 0xB0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* SDAM1 QNOVO: Table 3-6 RAM size for SDAMM on PM855B */
  {2, 0xC0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO01 I2C IRQ from IDSS */
  {2, 0xC1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO02 WiPower Reset from Kailua */
  {2, 0xC4, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO05 Haptic 5.5V external boost enable */
  {2, 0xC5, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO06 SMB1355 Status */
  {2, 0xC6, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO07 Handshake: Single Line Bus(SLB), (for LP-DDR4X) for initial bring-ups. (test diagrnosis - PMIC message triggers) */
  {2, 0xC7, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO08 Controls external FET for QNOVO */
  {2, 0xC8, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO09 Factory Test Boot 1: If it is not used,  customers can reassign this GPIO for something else. */
  {2, 0xC9, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO10 Factory Test Boot 2: Not used internally. But customers might use it. */
  {2, 0xCB, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO12 PD CLK IN(Backup option); PD: Power Delivery */
  {3, 0xB0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_LUT  */
  {3, 0xB1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_CHAN1  */
  {3, 0xB2, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_CHAN2  */
  {3, 0xC0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* HAPTICS  */
  {3, 0xD0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LED  */
  {4, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* BUS  */
  {4, 0x24, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* TEMP_ALARM  */
  {4, 0x31, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_CORE1_USR VADC (SINGLE-SHOT) */
  {4, 0x35, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* ADC_CORE5_BTM4 VADC BTM (THRESHOLDS) */
  {4, 0x3D, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* BCLBIG_COMP BCL: Battery current limiting */
  {4, 0x5B, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* DIV_CLK1  */
  {4, 0xC0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO01 AOSS Sleep Indication (for internal RCM usage) */
  {4, 0xC2, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO03 camera: calculating Time Of Flight */
  {4, 0xC3, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO04 camera: calculating Time Of Flight */
  {4, 0xC4, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO05 Primary display VSYNC */
  {4, 0xC5, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO06 Backlight PWM Mode (external IC for tablet) */
  {4, 0xC6, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO07 Handshake - Single Line Bus (SLB) (for LP-DDR4X) for initial bring-ups. (test diagrnosis - PMIC message triggers)
5G Option - BOB_HP_EN to Allows SDM to force BOB into automode */
  {4, 0xC7, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO08 Secondary CABC for WLED (for VR use case) */
  {4, 0xC9, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO10 Spare */
  {4, 0xCA, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO11 Spare */
  {5, 0xA1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* BOB_MONITORING Used for thermal use case */
  {5, 0xB0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_LUT  */
  {5, 0xB1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_CHAN1  */
  {5, 0xB2, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_CHAN2  */
  {5, 0xB3, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LPG_CHAN3  */
  {5, 0xBC, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* PWM1  */
  {5, 0xBD, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* PWM2  */
  {5, 0xD0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LED  */
  {5, 0xD3, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* MVFLASH1  */
  {5, 0xD8, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* WLED1_CTRL  */
  {5, 0xD9, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* WLED1_SINK  */
  {5, 0xEC, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* LCDB LCDB_PWRUP_PWRDN_CTL2 | 0x0001EC68 is lock by bit but needs to be written in HLOS */
  {5, 0xDC, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* IBB  */
  {5, 0xDE, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* AB  */
  {5, 0xE0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* OLEDB  */
  {8, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* PON locking it causes issue with poff/wr - seen on hana/poipu */
  {10, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_APPS},   /* BUS  */
  {10, 0x24, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* TEMP_ALARM  */
  {10, 0xC0, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO01 Camera Control */
  {10, 0xC1, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO02 Camera Control */
  {10, 0xC2, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO03 Fault_n */
  {10, 0xC3, SPMI_OWNER_APPS,    SPMI_OWNER_APPS},   /* GPIO04 Camera Control */
  {0, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID  */
  {0, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUS  */
  {0, 0x05, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* INT  */
  {0, 0x06, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI  */
  {0, 0x07, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI_MASTER  */
  {0, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_AOP},   /* PON  */
  {0, 0x09, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC  */
  {0, 0x0B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VREF_MSM  */
  {0, 0x28, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* COIN CHARGER */
  {0, 0x2C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MBG1  */
  {0, 0x32, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE2_MDM VADC (SINGLE-SHOT) */
  {0, 0x36, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE3_PBS  */
  {0, 0x37, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE4_CAL VADC CALIBRATION */
  {0, 0x38, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE5_BTM2 VADC BTM (THRESHOLDS) */
  {0, 0x39, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE6_CMN VADC COMMON SETTINGS */
  {0, 0x3C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VDDGEN  */
  {0, 0x3D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VREG_SPMI  */
  {0, 0x3E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VREG_SP  */
  {0, 0x50, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* XO  */
  {0, 0x51, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LN_BB_CLK1  */
  {0, 0x52, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LN_BB_CLK2  */
  {0, 0x53, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LN_BB_CLK3  */
  {0, 0x54, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK1  */
  {0, 0x55, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK2  */
  {0, 0x56, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK3  */
  {0, 0x59, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CLK_DIST  */
  {0, 0x5A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SLEEP_CLK1  */
  {0, 0x66, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI_MONITOR  */
  {0, 0x67, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RCS_MSGR  */
  {0, 0x71, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT0  */
  {0, 0x72, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT1  */
  {0, 0x73, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS1 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {0, 0x74, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS2 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {0, 0x75, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS3 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {0, 0x76, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PSTM1  */
  {0, 0xB2, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SDAM3 Shared Info AOP */
  {0, 0xB3, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SDAM4 Shared Info MPSS */
  {0, 0xB4, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SDAM5 BTM 4 channel; ATE PBS CAL  :  Spare:  To be used for testing */
  {0, 0xB5, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SDAM6 BTM 2 channel1: Spare:  To be used for testing */
  {0, 0xB7, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SDAM8 AMOLED SWIRE Decode: PM855A; Spare PM855L: Spare:  To be used for testing */
  {0, 0xC1, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO02 PMIC Boot Options or PD CLK OUT (Backup) */
  {0, 0xC3, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO04 PMK8002 (Timex) sleep clock (Backup) or PD CLK OUT (Backup) // AI: confirm from Hana */
  {0, 0xC4, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO05 PMIC Boot Options */
  {0, 0xC7, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO08 Tie to MSM SP block through votlage divider */
  {1, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID1  */
  {1, 0x0F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BCAL_VIRTUAL_SLAVE_BASE  */
  {1, 0x10, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUCK_CMN_MOD  */
  {1, 0x14, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_CTRL  */
  {1, 0x15, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_PS  */
  {1, 0x16, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_FREQ  */
  {1, 0x17, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_CTRL  */
  {1, 0x18, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_PS  */
  {1, 0x19, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_FREQ  */
  {1, 0x1A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_CTRL  */
  {1, 0x1B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_PS  */
  {1, 0x1C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_FREQ  */
  {1, 0x1D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_CTRL  */
  {1, 0x1E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_PS  */
  {1, 0x1F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_FREQ  */
  {1, 0x20, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_CTRL  */
  {1, 0x21, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_PS  */
  {1, 0x22, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_FREQ  */
  {1, 0x23, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_CTRL  */
  {1, 0x24, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_PS  */
  {1, 0x25, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_FREQ  */
  {1, 0x26, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_CTRL  */
  {1, 0x27, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_PS  */
  {1, 0x28, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_FREQ  */
  {1, 0x29, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_CTRL  */
  {1, 0x2A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_PS  */
  {1, 0x2B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_FREQ  */
  {1, 0x2C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S9_CTRL  */
  {1, 0x2D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S9_PS  */
  {1, 0x2E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S9_FREQ  */
  {1, 0x2F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S10_CTRL  */
  {1, 0x30, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S10_PS  */
  {1, 0x31, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S10_FREQ  */
  {1, 0x40, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO01  */
  {1, 0x41, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO02  */
  {1, 0x42, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO03  */
  {1, 0x43, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO04  */
  {1, 0x44, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO05  */
  {1, 0x45, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO06  */
  {1, 0x46, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO07  */
  {1, 0x47, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO08  */
  {1, 0x48, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO09  */
  {1, 0x49, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO10  */
  {1, 0x4A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO11  */
  {1, 0x4B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO12  */
  {1, 0x4C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO13  */
  {1, 0x4D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO14  */
  {1, 0x4E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO15  */
  {1, 0x4F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO16  */
  {1, 0x50, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO17  */
  {1, 0x51, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO18  */
  {2, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID  */
  {2, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUS PBUS Logger */
  {2, 0x05, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* INT  */
  {2, 0x06, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI  */
  {2, 0x08, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PON  */
  {2, 0x09, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC  */
  {2, 0x1E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BCLBIG_PLM  */
  {2, 0x2C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MBG1  */
  {2, 0x30, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_FG7_CMN2  */
  {2, 0x32, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_FG2_MDM  */
  {2, 0x36, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_FG3_PBS  */
  {2, 0x37, SPMI_OWNER_APPS,    SPMI_OWNER_AOP},   /* ADC_FG4_CAL  */
  {2, 0x39, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_FG6_CMN  */
  {2, 0x3C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VDDGEN  */
  {2, 0x59, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CLK_DIST  */
  {2, 0x66, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI_MONITOR  */
  {2, 0x67, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RCS_MSGR New */
  {2, 0x71, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT0  */
  {2, 0x72, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT1 Charger uses for external Rsense */
  {2, 0x73, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS1 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {2, 0x74, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS2 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {2, 0x75, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS3 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {2, 0xC2, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO03 Option pin: SPMI(QCOM) or I2C(3rd party) contol interface selection */
  {2, 0xC3, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO04 Option Pin: betweenUSB connector types(VDD/HighZ=Type C, GND=uUSB) */
  {2, 0xCA, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO11 Spare */
  {4, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID  */
  {4, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUS  */
  {4, 0x05, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* INT  */
  {4, 0x06, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI  */
  {4, 0x08, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PON  */
  {4, 0x09, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC  */
  {4, 0x2C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MBG1  */
  {4, 0x32, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE2_MDM VADC (SINGLE-SHOT) */
  {4, 0x36, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE3_PBS  */
  {4, 0x37, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE4_CAL VADC CALIBRATION */
  {4, 0x39, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE6_CMN VADC COMMON SETTINGS */
  {4, 0x3C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VDDGEN  */
  {4, 0x3E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BCLBIG_PLM  */
  {4, 0x3F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BCL_COMP_MDM  */
  {4, 0x59, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CLK_DIST  */
  {4, 0x5B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* DIV_CLK1  */
  {4, 0x66, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI_MONITOR  */
  {4, 0x67, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RCS_MSGR RCS Messenger (Request Capable Slave)  :   This allows data to be transfered between PMICs using interrupt messages. */
  {4, 0x71, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT0 ??? */
  {4, 0x72, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT1 ?? */
  {4, 0x73, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS1 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {4, 0x74, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS2 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {4, 0x75, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS3 TDOS: Table 3-1 MISC_PBS SW Trigger Assignment */
  {4, 0xC1, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO02 PM3003A control */
  {4, 0xC8, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO09 PMX55 reset; APQ will directly write to PON and so this GPIO will not be written by APPS */
  {4, 0xCB, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* GPIO12 PM3003A Mode select (1.8V= forced PWM; GND= follow register) */
  {5, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID1  */
  {5, 0x10, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUCK_CMN_MOD  */
  {5, 0x14, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_CTRL  */
  {5, 0x15, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_PS  */
  {5, 0x16, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_FREQ  */
  {5, 0x17, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_CTRL  */
  {5, 0x18, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_PS  */
  {5, 0x19, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_FREQ  */
  {5, 0x1A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_CTRL  */
  {5, 0x1B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_PS  */
  {5, 0x1C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_FREQ  */
  {5, 0x1D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_CTRL  */
  {5, 0x1E, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_PS  */
  {5, 0x1F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S3_FREQ  */
  {5, 0x20, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_CTRL  */
  {5, 0x21, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_PS  */
  {5, 0x22, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S4_FREQ  */
  {5, 0x23, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_CTRL  */
  {5, 0x24, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_PS  */
  {5, 0x25, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S5_FREQ  */
  {5, 0x26, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_CTRL  */
  {5, 0x27, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_PS  */
  {5, 0x28, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S6_FREQ  */
  {5, 0x29, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_CTRL  */
  {5, 0x2A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S8_PS  */
  {5, 0x2B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S7_FREQ  */
  {5, 0x40, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO01  */
  {5, 0x41, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO02  */
  {5, 0x42, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO03  */
  {5, 0x43, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO04  */
  {5, 0x44, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO05  */
  {5, 0x45, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO06  */
  {5, 0x46, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO07  */
  {5, 0x47, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO08  */
  {5, 0x48, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO09  */
  {5, 0x49, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO10  */
  {5, 0x4A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO11  */
  {5, 0xA0, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BOB_CONFIG BOB (Buck-Or-Boost): non-inverting buck-boost converter;  For VIN > VSET, VOUT = VSET V (bucking), else VOUT = VSET (boosting) */
  {6, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID  */
  {6, 0x50, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* XO  */
  {6, 0x56, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK3  */
  {6, 0x57, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK4  */
  {6, 0x59, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CLK_DIST  */
  {8, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID  */
  {8, 0x08, SPMI_OWNER_APPS,    SPMI_OWNER_AOP},   /* PON locking it causes issue with poff/wr - seen on hana/poipu */
  {10, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID SID 10/11  for Yoda ;    Subtype is the same as Wilua. Use AON_LPI for detection of Yoda on target */
  {10, 0x04, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUS  */
  {10, 0x05, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* INT  */
  {10, 0x06, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SPMI_RFFE_S_I2C  */
  {10, 0x08, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PON  */
  {10, 0x09, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC  */
  {10, 0x0A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* AON_LPI Unique peripheral */
  {10, 0x2C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MBG1  */
  {10, 0x31, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE1_USR ADC is not used on Yoda */
  {10, 0x32, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE2_MDM  */
  {10, 0x36, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE3_PBS  */
  {10, 0x37, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE4_CAL  */
  {10, 0x39, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* ADC_CORE6_CMN  */
  {10, 0x3C, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VDDGEN  */
  {10, 0x3D, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* VREG_XVDD  */
  {10, 0x3F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BCL_COMP_LITE  */
  {10, 0x50, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* XO_CORE_38M  */
  {10, 0x51, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LN_BB_CLK1  */
  {10, 0x53, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LFRC Not used */
  {10, 0x54, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RF_CLK1  */
  {10, 0x59, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CLK_DIST  */
  {10, 0x5A, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* SLEEP_CLK1  */
  {10, 0x5B, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* DIV_CLK1  */
  {10, 0x5F, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* CALRC3 Not used */
  {10, 0x60, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RTC_RW  */
  {10, 0x61, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RTC_ALARM  */
  {10, 0x62, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* RTC_TIMER  */
  {10, 0x71, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT0  */
  {10, 0x72, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PBS_CLIENT1  */
  {10, 0x73, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS1  */
  {10, 0x74, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* MISC_PBS2  */
  {11, 0x01, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* REVID1  */
  {11, 0x10, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* BUCK_CMN_MOD  */
  {11, 0x14, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_CTRL  */
  {11, 0x15, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_PS  */
  {11, 0x16, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S1_FREQ  */
  {11, 0x17, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_CTRL  */
  {11, 0x18, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_PS  */
  {11, 0x19, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* S2_FREQ  */
  {11, 0x40, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO01  */
  {11, 0x41, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO02  */
  {11, 0x42, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO03  */
  {11, 0x43, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO04  */
  {11, 0x44, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO05  */
  {11, 0x45, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO06  */
  {11, 0x46, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* LDO07  */
  {11, 0xBC, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PWM1 Not used :   Set it to APPS to allow customers to use it */
  {11, 0xBD, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PWM2 Not used :   Set it to APPS to allow customers to use it */
  {11, 0xBE, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PWM3 Not used :   Set it to APPS to allow customers to use it */
  {11, 0xBF, SPMI_OWNER_AOP,    SPMI_OWNER_AOP},   /* PWM4 Not used :   Set it to APPS to allow customers to use it */
};

/* Number of spmi channels config entries. . */
uint32 pm_spmi_channel_cfg_size[] = {sizeof(pm_spmi_channel_cfg) / sizeof(SpmiCfg_ChannelCfg)};

