/*******************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2019, Qualcomm Technologies Incorporated.
 All rights reserved.
 ******************************************************************************/
/*==============================================================================
$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/DSFTargetLib/interface/header/api/core_sw_func.h#4 $
$DateTime: 2019/11/11 19:41:28 $
$Author: pwbldsvc $
==============================================================================*/

#ifndef __CORE_SW_FUNC_H__
#define __CORE_SW_FUNC_H__

#include "ddr_shared_interface.h"

void CORE_SW_DCB_Init(DDR_SHARED_STRUCT *ddr_shared_ptr);
void CORE_SW_DCB_Set_DDR_AOP_PARAMS(DDR_SHARED_STRUCT *ddr_shared_ptr);
uint8 CORE_SW_Get_Nearest_Enabled_Clock_Index(FREQ_STATE *freq_states, uint8 num_levels, uint32 freq_khz);
void CORE_SW_Set_Initial_Clock_Indices(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 ddr_khz, uint32 shub_khz, uint32 shrm_khz);
void CORE_SW_Set_Config(uint32 base_addr, uint16 reg_cnt, uint32  (*reg_offset_val_ptr)[2]);
void CORE_SW_Set_PASR_DDR_INFO_TABLE(DDR_SHARED_STRUCT *ddr_shared_ptr);
uint32 CORE_SW_Get_Training_Checksum(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 seed);
void CORE_SW_TRN_FRWK_Run_Switchboard(DDR_SHARED_STRUCT *ddr_shared_ptr, CORE_SW_TRN_SWITCHBOARD_STRUCT switchboard[MAX_NUM_TRAININGS]);
void CORE_SW_DDR_Abort_Info_Print(DDR_ABORT_STRUCT *ddr_abort_ptr, char *prefix, uint32 severity);
void CORE_SW_DDR_Print_and_Abort(DDR_SHARED_STRUCT *ddr_shared_ptr);

// External
boolean EXT_CORE_SW_Get_DCB(void *buffer_ptr, size_t size, char *name);
uint32 EXT_CORE_SW_Get_Checksum(uint8 *buf_ptr, uint16 len, uint32 seed);
uint32 EXT_CORE_SW_Get_Time(void);
void EXT_CORE_SW_DDR_Freq_Switch(uint8 clk_idx);
void EXT_CORE_SW_DDR_Abort(void);
void EXT_CORE_SW_Seq_Wait(uint32 time_value, SEQ_TimeUnit time_unit);
void EXT_CORE_SW_DDR_printf(uint32 severity, const char *format, va_list args);
void EXT_CORE_SW_memcpy_s(void *dest, size_t dst_size, const void *src, size_t copy_size);
void EXT_CORE_SW_memset(void* dst_ptr, int val, size_t len);
void EXT_CORE_SW_snprintf(char *str, size_t size, const char *format, va_list args);
int  EXT_CORE_SW_strncmp(const char *str1, const char *str2, size_t len);
boolean EXT_CORE_SW_DDI_Save_Data(uint8* ddi_data_ptr, uint32 ddi_data_size, uint32 ddi_data_offset);
boolean EXT_CORE_SW_Get_Regulator_Voltage(const char *regulator, uint32 *voltage);

#endif /* __CORE_SW_FUNC_H__ */ 
