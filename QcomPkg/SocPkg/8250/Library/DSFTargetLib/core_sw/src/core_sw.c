/****************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2018, Qualcomm Technologies Incorporated. All rights reserved.
 ****************************************************************************/
/*==============================================================================
                                EDIT HISTORY

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/DSFTargetLib/core_sw/src/core_sw.c#6 $
$DateTime: 2019/12/18 23:06:39 $
$Author: pwbldsvc $
================================================================================
when       who          what, where, why
--------   ---          --------------------------------------------------------
01/12/18   sr           Initial version.
================================================================================*/
#include "core_sw_interface.h"
#include <limits.h>

//=============================================================
// Debug Print Macros
//=============================================================
#if CORE_SW_PRINTS
    #define CORE_SW_printf HAL_EXT_CORE_SW_DDR_printf
#else
    #define CORE_SW_printf(...)
#endif

void CORE_SW_DCB_Init(DDR_SHARED_STRUCT *ddr_shared_ptr)
{
    char dcb_name[22] = {0};
    
    // Generate DCB file name
    HAL_EXT_CORE_SW_snprintf(dcb_name, sizeof(dcb_name), "/%04X_%04X_%01X_dcb.bin",
        ddr_shared_ptr->platform_id,
        (ddr_shared_ptr->chip_version & 0xFF00), // Ignore minor chip version when selecting DCB binary
        ddr_shared_ptr->target_silicon);

    // Read DCB from file to buffer
    if(HAL_EXT_CORE_SW_Get_DCB(ddr_shared_ptr->dcb.ptr, DCB_MAX_SIZE, dcb_name) != TRUE)
    {
        ddr_shared_ptr->ddr_abort_info.reason = DCB_LOAD_FAIL;
        HAL_CORE_SW_DDR_Print_and_Abort(ddr_shared_ptr);
    }
        
    // Print DCB CRC
    CORE_SW_printf(CORE_SW_SEVERITY, "DCB CRC = 0x%X\n", ((uint32*)ddr_shared_ptr->dcb.ptr)[DCB_CRC_IDX]);

    // Store DCB CRC in SHRM DDR struct
    ddr_shared_ptr->dcb_crc = ((uint32*)ddr_shared_ptr->dcb.ptr)[DCB_CRC_IDX];
    
    // Check DCB version against DSF version
    if(((uint32*)ddr_shared_ptr->dcb.ptr)[DSF_VERSION_IDX] != ddr_shared_ptr->dsf_code_version)
    {
        ddr_shared_ptr->ddr_abort_info.reason = DCB_VERSION_INCORRECT;
        HAL_CORE_SW_DDR_Print_and_Abort(ddr_shared_ptr);
    }
}

void CORE_SW_DCB_Set_DDR_AOP_PARAMS(DDR_SHARED_STRUCT *ddr_shared_ptr)
{
    uint16 (*dcb_ptr)[DCB_IDX_MAX][2] = ddr_shared_ptr->dcb.ptr;
    DDR_AOP_PARAMS *ddr_aop_params_ptr = ddr_shared_ptr->ddr_aop_params.ptr;
    shared_table_header_type *shared_table_header_ptr = ddr_aop_params_ptr->ddr_smem_info_header.shared_table_header;

    ddr_aop_params_ptr->ddr_smem_info_header.major_version = AOP_PARAMS_MAJOR_VERSION;
    ddr_aop_params_ptr->ddr_smem_info_header.minor_version = AOP_PARAMS_MINOR_VERSION;

    // Set number of clock plan levels supplied by DCB
    ddr_shared_ptr->num_ddr_levels = (*dcb_ptr)[MC_STATES_IDX][1] / sizeof(FREQ_STATE);
    ddr_shared_ptr->num_shub_levels = (*dcb_ptr)[SHUB_STATES_IDX][1] / sizeof(FREQ_STATE);
    ddr_shared_ptr->num_shrm_levels = (*dcb_ptr)[SHRM_STATES_IDX][1] / sizeof(FREQ_STATE);
    
    // MC_STATES
    shared_table_header_ptr[MC_STATES].size = (*dcb_ptr)[MC_STATES_IDX][1];
    shared_table_header_ptr[MC_STATES].offset = offsetof(DDR_AOP_PARAMS, mc_states);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->mc_states, sizeof(ddr_aop_params_ptr->mc_states), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[MC_STATES_IDX][0]), (*dcb_ptr)[MC_STATES_IDX][1]);

    // SHUB_STATES
    shared_table_header_ptr[SHUB_STATES].size = (*dcb_ptr)[SHUB_STATES_IDX][1];
    shared_table_header_ptr[SHUB_STATES].offset = offsetof(DDR_AOP_PARAMS, shub_states);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->shub_states, sizeof(ddr_aop_params_ptr->shub_states), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[SHUB_STATES_IDX][0]), (*dcb_ptr)[SHUB_STATES_IDX][1]);

    // SHRM_STATES
    // Not shared with AOP
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->shrm_states, sizeof(ddr_aop_params_ptr->shrm_states), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[SHRM_STATES_IDX][0]), (*dcb_ptr)[SHRM_STATES_IDX][1]);

    // DEFAULT_ALC_POLICY
    shared_table_header_ptr[DEFAULT_ALC_POLICY].size = (*dcb_ptr)[DEFAULT_ALC_POLICY_IDX][1];
    shared_table_header_ptr[DEFAULT_ALC_POLICY].offset = offsetof(DDR_AOP_PARAMS, default_alc_policy);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->default_alc_policy, sizeof(ddr_aop_params_ptr->default_alc_policy), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[DEFAULT_ALC_POLICY_IDX][0]), (*dcb_ptr)[DEFAULT_ALC_POLICY_IDX][1]);

    // ALC_TIMINGS
    shared_table_header_ptr[ALC_TIMINGS].size = (*dcb_ptr)[ALC_TIMINGS_IDX][1];
    shared_table_header_ptr[ALC_TIMINGS].offset = offsetof(DDR_AOP_PARAMS, alc_timings);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->alc_timings, sizeof(ddr_aop_params_ptr->alc_timings), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[ALC_TIMINGS_IDX][0]), (*dcb_ptr)[ALC_TIMINGS_IDX][1]);

    // PASR_DDR_INFO_TABLE
    shared_table_header_ptr[PASR_DDR_INFO_TABLE].size = sizeof(ddr_aop_params_ptr->ddr_part_info);
    shared_table_header_ptr[PASR_DDR_INFO_TABLE].offset = offsetof(DDR_AOP_PARAMS, ddr_part_info);

    // ALC_POLICY_INDEX
    shared_table_header_ptr[ALC_POLICY_INDEX].size = (*dcb_ptr)[ALC_POLICY_INDEX_IDX][1];
    shared_table_header_ptr[ALC_POLICY_INDEX].offset = offsetof(DDR_AOP_PARAMS, alc_policy_index);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->alc_policy_index, sizeof(ddr_aop_params_ptr->alc_policy_index), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[ALC_POLICY_INDEX_IDX][0]), (*dcb_ptr)[ALC_POLICY_INDEX_IDX][1]);
        
    // PERF_MODE_ALC_POLICY
    shared_table_header_ptr[PERF_MODE_ALC_POLICY].size = (*dcb_ptr)[PERF_MODE_ALC_POLICY_IDX][1];
    shared_table_header_ptr[PERF_MODE_ALC_POLICY].offset = offsetof(DDR_AOP_PARAMS, perf_mode_alc_policy);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->perf_mode_alc_policy, sizeof(ddr_aop_params_ptr->perf_mode_alc_policy), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[PERF_MODE_ALC_POLICY_IDX][0]), (*dcb_ptr)[PERF_MODE_ALC_POLICY_IDX][1]);

    // DDR_DEVICE_TYPE
    shared_table_header_ptr[DDR_DEVICE_TYPE].size = sizeof(ddr_aop_params_ptr->ddr_type);
    shared_table_header_ptr[DDR_DEVICE_TYPE].offset = offsetof(DDR_AOP_PARAMS, ddr_type);
    ddr_aop_params_ptr->ddr_type = ddr_shared_ptr->device_params.device_type;

    // AOP_PMIC_SETTINGS
    shared_table_header_ptr[AOP_PMIC_SETTINGS].size = (*dcb_ptr)[PMIC_SETTINGS_IDX][1];
    shared_table_header_ptr[AOP_PMIC_SETTINGS].offset = offsetof(DDR_AOP_PARAMS, aop_pmic_settings);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->aop_pmic_settings, sizeof(ddr_aop_params_ptr->aop_pmic_settings), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[PMIC_SETTINGS_IDX][0]), (*dcb_ptr)[PMIC_SETTINGS_IDX][1]);

    // MIN_DDR_SHUB_RATIO
    shared_table_header_ptr[MIN_DDR_SHUB_RATIO].size = (*dcb_ptr)[MIN_DDR_SHUB_RATIO_IDX][1];
    shared_table_header_ptr[MIN_DDR_SHUB_RATIO].offset = offsetof(DDR_AOP_PARAMS, min_ddr_shub_ratio);
    HAL_EXT_CORE_SW_memcpy_s(&ddr_aop_params_ptr->min_ddr_shub_ratio, sizeof(ddr_aop_params_ptr->min_ddr_shub_ratio), 
        (void*)((size_t)(dcb_ptr) + (*dcb_ptr)[MIN_DDR_SHUB_RATIO_IDX][0]), (*dcb_ptr)[MIN_DDR_SHUB_RATIO_IDX][1]);
}

uint8 CORE_SW_Get_Nearest_Enabled_Clock_Index(FREQ_STATE *freq_states, uint8 num_levels, uint32 freq_khz)
{
    uint8 clk_idx;
    uint8 nearest_enabled_clk_idx = 1;
    int curr_freq_delta;
    int prev_freq_delta = INT_MAX;

    // Skip clock index 0
    for(clk_idx = 1; clk_idx < num_levels; clk_idx++)
    {
        // Skip frequency if not enabled
        if(freq_states[clk_idx].freq_enable == FALSE)
        {
            continue;
        }
        
        // Calculate absolute delta between frequencies
        curr_freq_delta = freq_states[clk_idx].freq_khz - freq_khz;
        if(curr_freq_delta < 0)
        {
            curr_freq_delta = -curr_freq_delta;
        }
        
        // Assume frequencies increase for each index
        // Exit if current delta is greater than previous
        if(curr_freq_delta > prev_freq_delta)
        {
            break;
        }
        
        // Update previous delta with current
        prev_freq_delta = curr_freq_delta;
        
        // Assume this is the nearest clock index
        nearest_enabled_clk_idx = clk_idx;
    }
    
    return nearest_enabled_clk_idx;
}

void CORE_SW_Set_Initial_Clock_Indices(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 ddr_khz, uint32 shub_khz, uint32 shrm_khz)
{
    DDR_AOP_PARAMS *ddr_aop_params_ptr = ddr_shared_ptr->ddr_aop_params.ptr;
    
    ddr_shared_ptr->ddr_init_clk_idx = CORE_SW_Get_Nearest_Enabled_Clock_Index(ddr_aop_params_ptr->mc_states, ddr_shared_ptr->num_ddr_levels, ddr_khz);
    ddr_shared_ptr->shub_init_clk_idx = CORE_SW_Get_Nearest_Enabled_Clock_Index(ddr_aop_params_ptr->shub_states, ddr_shared_ptr->num_shub_levels, shub_khz);
    ddr_shared_ptr->shrm_init_clk_idx = CORE_SW_Get_Nearest_Enabled_Clock_Index(ddr_aop_params_ptr->shrm_states, ddr_shared_ptr->num_shrm_levels, shrm_khz);
}

void CORE_SW_Set_Config(uint32 base_addr, uint16 reg_cnt, uint32 (*reg_offset_val_ptr)[2])
{
    uint16 i = 0;
    
    for(i = 0; i < reg_cnt; i++)
    {
        out_dword(base_addr + reg_offset_val_ptr[i][0], reg_offset_val_ptr[i][1]);
    }
}

void CORE_SW_Set_PASR_DDR_INFO_TABLE(DDR_SHARED_STRUCT *ddr_shared_ptr)
{
    DDR_AOP_PARAMS *ddr_aop_params_ptr = ddr_shared_ptr->ddr_aop_params.ptr;
    
    ddr_aop_params_ptr->ddr_part_info.ddr_cs0_addr = ddr_shared_ptr->ddr_size_info.ddr_cs0_addr[0];
    ddr_aop_params_ptr->ddr_part_info.ddr_cs1_addr = ddr_shared_ptr->ddr_size_info.ddr_cs1_addr[0];
    ddr_aop_params_ptr->ddr_part_info.ddr_cs0_remapped_addr = ddr_shared_ptr->ddr_size_info.ddr_cs0_remapped_addr[0];
    ddr_aop_params_ptr->ddr_part_info.ddr_cs1_remapped_addr = ddr_shared_ptr->ddr_size_info.ddr_cs1_remapped_addr[0];
    ddr_aop_params_ptr->ddr_part_info.per_ch_density_rank0 = ddr_shared_ptr->ddr_size_info.ddr_cs0_mb[0] >> 7; //MB to Gb conversion
    ddr_aop_params_ptr->ddr_part_info.per_ch_density_rank1 = ddr_shared_ptr->ddr_size_info.ddr_cs1_mb[0] >> 7; //MB to Gb conversion
    ddr_aop_params_ptr->ddr_part_info.num_channels= ddr_shared_ptr->num_channel;
}

uint32 CORE_SW_Get_Training_Checksum(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 seed)
{
    DDR_AOP_PARAMS *ddr_aop_params_ptr = ddr_shared_ptr->ddr_aop_params.ptr;
    struct ddr_params_partition *training_results_ptr = ddr_shared_ptr->flash_params.ptr;
    uint8 *crc_data_ptr;
    uint32 crc_data_size_bytes;
    uint16 crc_data_max_chunk_bytes = (SHRT_MAX / 8);
    uint32 temp;
    
    struct
    {
        uint32 mc_states[MAX_NUM_CLOCK_PLAN_IDX];
        uint32 max_ddr_freq;
        uint32 dsf_training_version;
        uint32 serial_number;
    }
    checksum_struct;
    
    uint32 clk_idx;
    uint32 checksum = seed;

    // Populate structure which will be used for CRC calculation
    for(clk_idx = 0; clk_idx < MAX_NUM_CLOCK_PLAN_IDX; clk_idx++)
    {
        checksum_struct.mc_states[clk_idx] = ddr_aop_params_ptr->mc_states[clk_idx].freq_khz;
    }
    checksum_struct.max_ddr_freq = ddr_aop_params_ptr->mc_states[ddr_shared_ptr->ddr_max_freq_idx].freq_khz;
    checksum_struct.dsf_training_version = ddr_shared_ptr->dsf_training_version;
    checksum_struct.serial_number = ddr_shared_ptr->serial_num;

    // Calculate CRC from training data
    crc_data_ptr = (uint8 *)(training_results_ptr->training_data);
    crc_data_size_bytes = TRAINING_DATA_SIZE_IN_BYTES;
    
    // Make sure not to exceed checksum size limit
    while(crc_data_size_bytes > 0)
    {
        if(crc_data_size_bytes > crc_data_max_chunk_bytes)
        {
            temp = crc_data_max_chunk_bytes;
        }
        else
        {
            temp = crc_data_size_bytes;
        }
        
        checksum = HAL_EXT_CORE_SW_Get_Checksum(crc_data_ptr, temp * 8, checksum);
        crc_data_size_bytes -= temp;
        crc_data_ptr += temp;
    }
    
    // Calculate CRC from factory training data
    checksum = HAL_EXT_CORE_SW_Get_Checksum((uint8 *)(training_results_ptr->training_data_factory), TRAINING_DATA_SIZE_IN_BYTES_FACTORY * 8, checksum);

    // Calculate CRC from checksum structure
    checksum = HAL_EXT_CORE_SW_Get_Checksum((uint8 *)(&checksum_struct), sizeof(checksum_struct) * 8, checksum);
    
    return checksum;
}

void CORE_SW_TRN_FRWK_Run_Switchboard(DDR_SHARED_STRUCT *ddr_shared_ptr, CORE_SW_TRN_SWITCHBOARD_STRUCT switchboard[MAX_NUM_TRAININGS])
{
    DDR_AOP_PARAMS *ddr_aop_params_ptr = ddr_shared_ptr->ddr_aop_params.ptr;
    
    uint8 group_idx = 0;
    uint8 trn_idx = 0;

    uint8 max_clk_idx = ddr_shared_ptr->ddr_max_freq_idx; 
    uint8 clk_idx = 0;
    uint8 group_printed = 0; 

    uint8 training_call_count[MAX_NUM_TRAININGS] = {0};
    uint32 training_total_time[MAX_NUM_TRAININGS] = {0};
    
    uint32 time_start = 0;
    uint32 time_finish = 0;
    uint32 time_elapsed = 0;
    uint32 time_total = 0;

    // Loop through list of trainings
    while(group_idx < MAX_NUM_TRAININGS)
    {
        // Loop through DDR clock indices from high to low
        for(clk_idx = max_clk_idx; clk_idx > 0; clk_idx--)
        {
            // Loop through trainings in group
            for(trn_idx = group_idx; trn_idx < MAX_NUM_TRAININGS; trn_idx++)
            {
                // Exit loop if group changed
                if(HAL_EXT_CORE_SW_strncmp(switchboard[trn_idx].group, switchboard[group_idx].group, MAX_GROUP_STR_LEN) != 0)
                {
                    break;
                }
                
                // Skip training if frequency is not enabled 
                if(ddr_aop_params_ptr->mc_states[clk_idx].freq_enable == 0)
                    continue;
                
                // Skip training if training is disabled
                if(switchboard[trn_idx].enabled == 0)
                    continue;

                // Skip training if flag is 0
                if(switchboard[trn_idx].flag[clk_idx] == 0)
                    continue;

                // Skip training if flag is 2 and current DDR clock index is not the maximum enabled clock index
                if((switchboard[trn_idx].flag[clk_idx] == 2) && (clk_idx != max_clk_idx))
                    continue;

                // Skip training if flag is 3 and current DDR clock index is the maximum enabled clock index
                if((switchboard[trn_idx].flag[clk_idx] == 3) && (clk_idx == max_clk_idx))
                    continue;
                
                if(group_printed == 0)
                {
                    CORE_SW_printf(CORE_SW_SEVERITY, ">====================================================================<\n");
                    CORE_SW_printf(CORE_SW_SEVERITY, "\tTRAINING GROUP:  %s\n", switchboard[trn_idx].group);
                    CORE_SW_printf(CORE_SW_SEVERITY, ">====================================================================<\n");
                    group_printed = 1;
                }

                CORE_SW_printf(CORE_SW_SEVERITY, ">====================================================================<\n");
                CORE_SW_printf(CORE_SW_SEVERITY, "\tTRAINING NAME:   %s @ %d\n", switchboard[trn_idx].name, ddr_aop_params_ptr->mc_states[clk_idx].freq_khz);
                CORE_SW_printf(CORE_SW_SEVERITY, ">====================================================================<\n");

                // Change DDR frequency
                HAL_EXT_CORE_SW_DDR_Freq_Switch(clk_idx);
                
                // Check function pointer isn't null
                if(switchboard[trn_idx].func.ptr == NULL)
                {
                    CORE_SW_printf(CORE_SW_SEVERITY, "ERROR: Training function pointer is NULL!\n");
                    HAL_CORE_SW_DDR_Print_and_Abort(ddr_shared_ptr);
                }

                // Get start time
                time_start = HAL_EXT_CORE_SW_Get_Time();

                // Call training function
                (switchboard[trn_idx].func.ptr)();

                // Get finish time
                time_finish = HAL_EXT_CORE_SW_Get_Time();
                
                // Calculated elapsed time in function
                time_elapsed = time_finish - time_start;
                
                // Add elapsed time to per function total
                training_total_time[trn_idx] += time_elapsed;
                
                // Add elapsed time to total for all functions
                time_total += time_elapsed;
                
                // Increment call count
                training_call_count[trn_idx]++;

                // Print training group, training name, DDR frequency, and time delta
                HAL_EXT_CORE_SW_DDR_printf(DDR_NORMAL, "TRAINING TIME PER CALL: GROUP=%s,NAME=%s,FREQ(kHz)=%d,TIME(us)=%d\n", switchboard[trn_idx].group, switchboard[trn_idx].name, ddr_aop_params_ptr->mc_states[clk_idx].freq_khz, time_elapsed);
            } // trn_idx
        } // clk_idx

        // Proceed to next group
        group_idx = trn_idx;
        group_printed = 0;
    } // group_idx
    
    // Loop through trainings a second time to print total time spent in each enabled training function
    for(trn_idx = 0; trn_idx < MAX_NUM_TRAININGS; trn_idx++)
    {
        // Skip training if training is disabled
        if(switchboard[trn_idx].enabled == 0)
            continue;
        
        // Print training group, training name, total time, and call count
        HAL_EXT_CORE_SW_DDR_printf(DDR_BOOTLOG, "TRAINING TIME PER FUNCTION: GROUP=%s,NAME=%s,CALL_COUNT=%d,TOTAL_TIME(us)=%d\n", switchboard[trn_idx].group, switchboard[trn_idx].name, training_call_count[trn_idx], training_total_time[trn_idx]);
    }
    
    // Print total training time for all functions
    HAL_EXT_CORE_SW_DDR_printf(DDR_BOOTLOG, "TRAINING TIME TOTAL(us): %d\n", time_total);
}

void CORE_SW_Value_String(char *string, size_t length, uint32 value)
{
    if(value == DC)
    {
        HAL_EXT_CORE_SW_snprintf(string, length, "%s", "DC");
    }
    else
    {
        HAL_EXT_CORE_SW_snprintf(string, length, "%d", value);
    }
}

void CORE_SW_DDR_Abort_Info_Print(DDR_ABORT_STRUCT *ddr_abort_ptr, char *prefix, uint32 severity)
{
    char* reason_str[] =
    {
        "UNCATEGORIZED",
        "INVALID_ECDT_ENTRY",
        "LIMIT_EXCEEDED",
        "NO_MEMORY_DEVICE_DETECTED",
        "ONLY_RANK_1_OF_MEMORY_DEVICE_DETECTED",
        "MEMORY_DEVICE_DOES_NOT_MATCH_OTHER_CHANNELS",
        "READ_ZERO_EYE_OPENING",
        "WRITE_ZERO_EYE_OPENING",
        "RCW_TRAINING_FAIL",
        "DIT_READ_FAIL",
        "DCB_LOAD_FAIL",
        "DCB_VERSION_INCORRECT",
        "SDI_VERSION_INCORRECT",
        "MANAGER_VERSION_INCORRECT",
        "DRAM_DCC_FAIL",
    };
    
    #define STR_SIZE 3
	char freq_str[STR_SIZE];
    char ch_str[STR_SIZE];
    char cs_str[STR_SIZE];
    char byte_str[STR_SIZE];
	char bit_str[STR_SIZE];
    
    // Convert to strings
    CORE_SW_Value_String(freq_str, STR_SIZE, ddr_abort_ptr->freq);
    CORE_SW_Value_String(ch_str, STR_SIZE, ddr_abort_ptr->ch);
    CORE_SW_Value_String(cs_str, STR_SIZE, ddr_abort_ptr->cs);
    CORE_SW_Value_String(byte_str, STR_SIZE, ddr_abort_ptr->byte);
    CORE_SW_Value_String(bit_str, STR_SIZE, ddr_abort_ptr->bit);
    
    // Print abort message to terminal
    HAL_EXT_CORE_SW_DDR_printf(severity, "%s: REASON=%s,FREQ=%s,CHANNEL=%s,CHIPSELECT=%s,BYTE=%s,BIT=%s,LIMIT=0x%X,VALUE=%d\n",
        prefix, reason_str[ddr_abort_ptr->reason],
        freq_str, ch_str, cs_str, byte_str, bit_str,
        ddr_abort_ptr->limit, ddr_abort_ptr->value);
}

void CORE_SW_DDR_Print_and_Abort(DDR_SHARED_STRUCT *ddr_shared_ptr)
{
    // Print abort message to terminal
    CORE_SW_DDR_Abort_Info_Print(&ddr_shared_ptr->ddr_abort_info, "DDR_ABORT", DDR_ERROR);
    
    // Call abort function
    HAL_EXT_CORE_SW_DDR_Abort();
}
