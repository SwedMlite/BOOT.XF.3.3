#ifndef __DDR_AOP_PARAMS_H__
#define __DDR_AOP_PARAMS_H__

/*=============================================================================

                                DDR AOP PARAMETERS
                                Header File
GENERAL DESCRIPTION
This file defines the AOP parameters provided from DCB

Copyright 2018 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/

/*==========================================================================
                               INCLUDE FILES
===========================================================================*/

/*==============================================================================
                                  TYPES & DEFINES
==============================================================================*/

#define MAX_NUM_CLOCK_PLAN_IDX 16
#define MAX_NUM_SHUB_CLOCK_PLAN_IDX 8
#define MAX_NUM_SHRM_CLOCK_PLAN_IDX 5
#define MAX_NUM_AOP_PMIC_SETTINGS 16


/*
 *  Clock plan inputs to AOP from DDR
 */
typedef enum
{
    GCC,
    DDRCC,
    NA = 0xFF,
	CLK_MODE_32_BIT = 0x7FFFFFFF,
} CLK_MODE;

typedef enum
{
    VDD_OFF     = 0x0,
    VDD_RET     = 0x10,
    MIN_SVS     = 0x30,
    LOW_SVS     = 0x40,
    SVS         = 0x80,
    SVS_L1      = 0xC0,
    NOMINAL     = 0x100,
    NOMINAL_L1  = 0x140,
    NOMINAL_L2  = 0x150,
    TURBO       = 0x180,
    TURBO_L1    = 0x1A0,
    MAX         = TURBO_L1,
    //VDD_INVALID = -1, // redefinition of enumerator
    VDD_NUM_LEVELS = 11,
	VOLTAGE_RAIL_32_BIT = 0x7FFFFFFF,
} VOLTAGE_RAIL;

typedef enum
{
    PMIC_CFG_0,
    PMIC_CFG_1,
    PMIC_CFG_2,
    PMIC_CFG_3,
    PMIC_CFG_4,
    PMIC_CFG_5,
    PMIC_CFG_6,
    PMIC_CFG_7,
    PMIC_CFG_8,
    PMIC_CFG_9,
    PMIC_CFG_10,
	PMIC_MODE_32_BIT = 0x7FFFFFFF,
} PMIC_MODE;

typedef struct
{
#if defined(COMPILING_LPASS_PROC)\
    || defined(COMPILING_MSS_PROC)\
    || defined(COMPILING_SC300_PROC)\
    || defined(COMPILING_SSC_PROC)\
    || defined(COMPILING_SSC_SDC_PROC)\
    || defined(COMPILING_TURING_PROC)
    uint8 clk_idx;
    uint32 freq_khz;
    uint32 clk_period;
    uint8 freq_enable;
    uint32 mode;
    uint32 vddcx;
    uint32 vddmx;
    uint32 vdda;
    uint32 pmic_mode_cfg;
    uint8 max_up_idx;
    uint8 min_down_idx;
    uint8 double_freq_switch;
#else
    uint8 clk_idx;
    uint32 freq_khz;
    uint32 clk_period;
    boolean freq_enable;
    CLK_MODE mode;
    VOLTAGE_RAIL vddcx;
    VOLTAGE_RAIL vddmx;
    VOLTAGE_RAIL vdda;
    PMIC_MODE pmic_mode_cfg;
    uint8 max_up_idx;
    uint8 min_down_idx;
    boolean double_freq_switch;
#endif
} FREQ_STATE;


/*
 *  ALC (Active Latency Code) inputs to AOP from DDR
 *
 *  The MC (memory controller) and DDR_CC (DDR clock controller) have timers
 *  controlling when to enter incrementally lower power states when idle.
 *
 *  IDLE power state entry timeline     : ==>------|---|---|---|---------------
 *                                                             /\
 *  EXIT from highest power state       : ==>-<================================
 *  EXIT from intermediate power state  : ==>-------<+++=======================
 *  EXIT from lowest power state        : ==>---------------------<++++++++====
 *                                                                        /\
 *  Above ">" indicates a memory channel becoming idle, "-" indicates the memory
 *  channel continuing to be idle, and "|" indicates enty into a lower power state.
 *
 *  Above "<" indicates a need to become active, "+" indicates waiting to become
 *  active, and "=" indicates the memory channel being active.
 *
 *  The idle hysteresis is the latency from becoming idle to entering the lowest
 *  allowed power state (from ">" to "/\" in timeline above).
 *
 *  The exit latency is the latency from needing to become active from the lowest
 *  allowed power state to being active (from "<" to "/\" in timeline above).
 *
 *  Intermediate power states will have entry and exit latencies not communicated
 *  to AOP.
 */
#define MAX_NUM_ALC_POLICY 16

typedef struct
{
    uint32 idle_hysteresis_in_ns;   // latency to lowest allowed power state from
                                    // idle (zero indicates invalid ALC policy)
    uint32 exit_latency_in_ns;      // latency from lowest allowed power state to
                                    // active (zero indicates invalid ALC policy)
} ALC_POLICY_TIMINGS;

typedef struct
{
    uint8 clk_idx;
    uint32 freq_khz;
    uint32 vddq; /*Voltage in micro volts*/
}vddq_state;

typedef struct
{
    uint8 num_levels;
    vddq_state *vddq_state;
}ddr_vddq_plan;

typedef struct
{
  uint64 ddr_cs0_addr;
  uint64 ddr_cs1_addr;
  uint64 ddr_cs0_remapped_addr;
  uint64 ddr_cs1_remapped_addr;
  uint32 num_channels;
  uint8  per_ch_density_rank0;
  uint8  per_ch_density_rank1;	
  uint8  reserved1;
  uint8  reserved2;
}pasr_shared_ddr_info;

typedef struct
{
    char name[8];       // Name of PMIC setting
                        // "pam" = PAM table index
                        // "<regulator short name>.e" = regulator enable
                        // "<regulator short name>.m" = regulator mode
                        // "<regulator short name>.v" = regulator voltage
    
    uint16 values[8];   // Values for each PMIC_MODE_CFG index from MC_STATES table
}
AOP_PMIC_SETTINGS_STRUCT;

typedef struct
{
  uint16 size;
  uint16 offset;
}shared_table_header_type;

typedef enum
{
  MC_STATES = 0,
  SHUB_STATES,
  DEFAULT_ALC_POLICY,
  ALC_TIMINGS,
  PASR_DDR_INFO_TABLE,
  ALC_POLICY_INDEX,
  DDR_DEVICE_TYPE,
  AOP_PMIC_SETTINGS,
  MIN_DDR_SHUB_RATIO,
  PERF_MODE_ALC_POLICY,
  MAX_NUM_TABLES,
}smem_tables;

typedef struct
{
  uint16 major_version;
  uint16 minor_version;
  shared_table_header_type shared_table_header[MAX_NUM_TABLES];
}ddr_smem_info;

/*
 * AOP parameters provided from DCB
 */
typedef struct
{
    ddr_smem_info ddr_smem_info_header;
    FREQ_STATE mc_states[MAX_NUM_CLOCK_PLAN_IDX];
    FREQ_STATE shub_states[MAX_NUM_SHUB_CLOCK_PLAN_IDX];
    FREQ_STATE shrm_states[MAX_NUM_SHRM_CLOCK_PLAN_IDX];
    uint8 default_alc_policy;
    ALC_POLICY_TIMINGS alc_timings[MAX_NUM_ALC_POLICY];
    pasr_shared_ddr_info ddr_part_info;
    uint8 alc_policy_index[MAX_NUM_CLOCK_PLAN_IDX];
    uint8 perf_mode_alc_policy[MAX_NUM_CLOCK_PLAN_IDX];
    uint32 ddr_type;
    AOP_PMIC_SETTINGS_STRUCT aop_pmic_settings[MAX_NUM_AOP_PMIC_SETTINGS];
    uint8 min_ddr_shub_ratio[MAX_NUM_CLOCK_PLAN_IDX];
} DDR_AOP_PARAMS;

/*==============================================================================
                                  MACROS
==============================================================================*/
#define AOP_PARAMS_MAJOR_VERSION 0x1
#define AOP_PARAMS_MINOR_VERSION 0x5

/* With the new SMEM architecture, SMEM IDs need to be defined in individual driver files */
#define DDR_AOP_SMEM_ID 0x25C   //604

#endif /* __DDR_AOP_PARAMS_H__ */
