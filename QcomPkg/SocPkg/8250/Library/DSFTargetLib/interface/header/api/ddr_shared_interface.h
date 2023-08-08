#ifndef __SHARED_INTERFACE_H__
#define __SHARED_INTERFACE_H__
/*
===========================================================================

FILE:         ddr_shared_interface.h

DESCRIPTION:  
  This is the file which contains structures required for both core_sw and ddr_fw

Copyright 2019 by Qualcomm Technologies, Inc.  All Rights Reserved.
===========================================================================

                             Edit History


when       who       what, where, why
--------   ---       --------------------------------------------------------
01/25/19   daisond   Initial version

===========================================================================
*/
/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include "HAL_SNS_DDR.h"

#define DSF_INTERFACE_VERSION   16

//=============================================================
// Debug Print Control
//=============================================================
#ifdef FEATURE_DSF_DEBUG_PRINTS
#define CORE_SW_PRINTS      1
#define DDRSS_PRINTS        1
#define DIT_PRINTS          1
#define TRN_PRINTS          1
#define ALL_PHY_PRINTS      1
#else
#define CORE_SW_PRINTS      0
#define DDRSS_PRINTS        0
#define DIT_PRINTS          0
#define TRN_PRINTS          0
#define ALL_PHY_PRINTS      0
#endif // FEATURE_DSF_DEBUG_PRINTS

#define PHY_CBT_PRINTS      (0 | ALL_PHY_PRINTS)
#define PHY_CAL_PRINTS      (0 | ALL_PHY_PRINTS)
#define PHY_DCC_PRINTS      (0 | ALL_PHY_PRINTS)
#define PHY_MISC_PRINTS     (0 | ALL_PHY_PRINTS)
#define PHY_RCW_PRINTS      (0 | ALL_PHY_PRINTS)
#define PHY_RD_PRINTS       (0 | ALL_PHY_PRINTS)
#define PHY_TEST_PRINTS     (0 | ALL_PHY_PRINTS)
#define PHY_WR_PRINTS       (0 | ALL_PHY_PRINTS)
#define PHY_WRLVL_PRINTS    (0 | ALL_PHY_PRINTS)

#define CORE_SW_SEVERITY    DDR_DETAIL
#define DDRSS_SEVERITY      DDR_DETAIL
#define DIT_SEVERITY        DDR_DETAIL
#define TRN_SEVERITY        DDR_DETAIL
#define PHY_CBT_SEVERITY    DDR_DETAIL
#define PHY_CAL_SEVERITY    DDR_DETAIL
#define PHY_DCC_SEVERITY    DDR_DETAIL
#define PHY_MISC_SEVERITY   DDR_DETAIL
#define PHY_RCW_SEVERITY    DDR_DETAIL
#define PHY_RD_SEVERITY     DDR_DETAIL
#define PHY_TEST_SEVERITY   DDR_DETAIL
#define PHY_WR_SEVERITY     DDR_DETAIL
#define PHY_WRLVL_SEVERITY  DDR_DETAIL

// Defines for boot training status (DDR_FW_PTR->misc.ddr.boot_training_status)
#define TRAINING_NOT_STARTED    (0)
#define TRAINING_IN_PROGRESS    (1)
#define TRAINING_COMPLETED      (2)
#define CA_TRAINING_IN_PROGRESS (3)

#define CONVERT_CYC_TO_PS        1000000000

#define DDR_FW_BUFFER_MAX_SIZE (1024*64)
#define SDI_DUMP_BUFFER_MAX_SIZE (1024*1)
#define DCB_MAX_SIZE ((1024*22)+4+1004) // must be multiple of 4, must not be multiple of 512

// Indices for DCB header
enum
{
    DCB_CRC_IDX,
    DCB_SIZE_IDX,
    DSF_VERSION_IDX,
    DDI_INPUT_IDX,
    RUNTIME_IDX,
    MC_PXI_PRE_TRAINING_CFG_IDX,
    MC_PXI_RD_CFG_IDX,
    MC_PXI_WR_CFG_IDX,
    MC_PXI_RCW_CFG_IDX,
    MC_PXI_WRLVL_CFG_IDX,
    MC_PXI_CBT_CFG_IDX,
    SAVE_RESTORE_IDX,
    TRAINING_PARAMS_IDX,
    RECLAIM_IDX,
    // All data stored below this line will be cleared at the end of DDR_FW_Init
    MC_STATES_IDX = RECLAIM_IDX,
    SHUB_STATES_IDX,
    SHRM_STATES_IDX,
    DEFAULT_ALC_POLICY_IDX,
    ALC_TIMINGS_IDX,
    ALC_POLICY_INDEX_IDX,
    PERF_MODE_ALC_POLICY_IDX,
    PMIC_SETTINGS_IDX,
    MIN_DDR_SHUB_RATIO_IDX,
    ECDT_PRE_DEVICE_INIT_IDX,
    ECDT_POST_DEVICE_INIT_IDX,
    DDRSS_CFG_IDX,
    NOC_CFG_IDX,
    SHRM_CFG_IDX,
    MCCC_MSTR_CFG_IDX,
    MCCC_SLV_CFG_IDX,
    DDRPHY_CFG_IDX,
    MC_CFG_IDX,
    LLCC_CFG_IDX,
    AHB2PHY_CFG_IDX,
    SHRM_DUMP_IDX,
    DCB_IDX_MAX,
};

#define DC 0xFFFFFFFF

typedef enum
{
    UNCATEGORIZED,
    INVALID_ECDT_ENTRY,
    LIMIT_EXCEEDED,
    NO_MEMORY_DEVICE_DETECTED,
    ONLY_RANK_1_OF_MEMORY_DEVICE_DETECTED,
    MEMORY_DEVICE_DOES_NOT_MATCH_OTHER_CHANNELS,
    READ_ZERO_EYE_OPENING,
    WRITE_ZERO_EYE_OPENING,
    RCW_TRAINING_FAIL,
    DIT_READ_FAIL,
    DCB_LOAD_FAIL,
    DCB_VERSION_INCORRECT,
    SDI_VERSION_INCORRECT,
    MANAGER_VERSION_INCORRECT,
    DRAM_DCC_FAIL,
}
DDR_ABORT_REASON;

typedef struct
{
    uint32  reason;
    uint32  freq;
    uint32  ch;
    uint32  cs;
    uint32  byte;
    uint32  bit;
    uint32  limit;
    int     value;
}
DDR_ABORT_STRUCT;

typedef struct
{
    uint32                                      dsf_code_version;               // needed at this location for debug
    uint32                                      shrm_code_version;              // needed at this location for debug
    uint32                                      dsf_training_version;           // needed at this location for debug
	uint32                                      shrm_waiti_addr;                // needed for SDI DCC SHRM LL to store WFI Address
    uint32                                      dcb_crc;                        // CRC of DDR config block
    
	uint8                                       num_ddr_levels;                 // number of DDR clock plan indices populated from DCB   
	uint8                                       num_shub_levels;                // number of SHUB clock plan indices populated from DCB    
	uint8                                       num_shrm_levels;                // number of SHRM clock plan indices populated from DCB    
	uint8                                       ddr_max_freq_idx;               // highest enabled DDR clock index

    struct detected_ddr_device_params           device_params;
    ddr_sns_size_info                           ddr_size_info;
    DDR_ABORT_STRUCT                            ddr_abort_info;                 // records information for categorizing aborts
    
    uint16                                      buffer_e_size;                  // Size of data in buffer_e
    uint16                                      buffer_i_size;                  // Size of data in buffer_i

    union // Pointers require union with double to make the size the same for 32 bit and 64 bit processors
    {
        uint8                                   *ptr;                           // pointer to buffer_e
        double                                  rsvd;
    }
    buffer_e;

    union // Pointers require union with double to make the size the same for 32 bit and 64 bit processors
    {
        uint8                                   *ptr;                           // pointer to buffer_i
        double                                  rsvd;
    }
    buffer_i;
    
    union // Pointers require union with double to make the size the same for 32 bit and 64 bit processors
    { 
        struct ddr_params_partition             *ptr;                           // pointer to buffer for data stored in flash
        double                                  rsvd;   
    }
    flash_params;

    union // Pointers require union with double to make the size the same for 32 bit and 64 bit processors
    {
        uint16                                  (*ptr)[DCB_IDX_MAX][2];         // pointer to buffer for DCB
        double                                  rsvd;
    }
    dcb;

    union // Pointers require union with double to make the size the same for 32 bit and 64 bit processors
    {
        DDR_AOP_PARAMS                          *ptr;                           // pointer to buffer for DDR_AOP_PARAMS
        double                                  rsvd;
    }
    ddr_aop_params;

    uint8                                       ddr_init_clk_idx;               // initial DDR clock index
    uint8                                       shub_init_clk_idx;              // initial SHUB clock index
    uint8                                       shrm_init_clk_idx;              // initial SHRM clock index

    uint32                                      enabled_channels;               // mask indicating which channels are enabled
    uint8                                       enabled_chipselects;            // mask indicating which chipsets are enabled
    uint8                                       total_channels;                 // number of supported channels
    uint8                                       num_channel;                    // number of enabled channels    

    uint8                                       jtag_connected;                 // 0: JTAG not connected, 1: JTAG connected
    uint8                                       target_silicon;                 // 0: emulation platform, 1: ASIC (silicon)
    uint32                                      platform_id;                    // SoC platform ID
    uint32                                      chip_version;                   // SoC chip version
    uint32                                      serial_num;                     // SoC serial number
    uint32                                      platform_info;                  // platform information (development, test, etc)
    
    uint8                                       extended_term_log_en;           // 0: disable extended terminal logging, 1: enable
}
DDR_SHARED_STRUCT;

#define MAX_NUM_TRAININGS   20
#define MAX_GROUP_STR_LEN   14
#define MAX_NAME_STR_LEN    25

typedef void (*CORE_SW_TRN_FUNC_PTR)(void);

typedef struct
{
    union
    {
        CORE_SW_TRN_FUNC_PTR    ptr;                        // training function pointer
        double                  rsvd;
    }
    func;
    char                    group[MAX_GROUP_STR_LEN];       // name of training group
    char                    name[MAX_NAME_STR_LEN];         // name of training function
    uint8                   enabled;                        // 0: disabled, 1: enabled
    uint8                   flag[MAX_NUM_CLOCK_PLAN_IDX];   // flag indicating if training function should be called
                                                            // 0: never, 1: always, 2: only if highest enabled clock index, 3: if not highest enabled clock index
}
CORE_SW_TRN_SWITCHBOARD_STRUCT;

#endif
