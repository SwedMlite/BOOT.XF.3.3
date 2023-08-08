/*******************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2019, Qualcomm Technologies Incorporated.
 All rights reserved.
 ******************************************************************************/
/*==============================================================================
$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/DSFTargetLib/interface/header/api/ddr_fw_func.h#2 $
$DateTime: 2019/07/08 14:50:42 $
$Author: pwbldsvc $
==============================================================================*/

#ifndef __DDR_FW_FUNC_H__
#define __DDR_FW_FUNC_H__

#include "ddr_shared_interface.h"

void DDR_FW_Enter(void *buffer_ptr, size_t size);
DDR_SHARED_STRUCT* DDR_FW_Get_DDR_SHARED_STRUCT_Pointer(void); 
void DDR_FW_Init(void);
void DDR_FW_Train(void);
void DDR_FW_Restore(void);
void DDR_FW_Exit(void);

// Frequency Switch
void DDR_FW_DDR_Freq_Switch_Prework(uint8 new_clk_idx);
void DDR_FW_DDR_Freq_Switch_Work(uint8 new_clk_idx);
void DDR_FW_DDR_Freq_Switch_Postwork(uint8 new_clk_idx);

// SDI
uint32 DDR_FW_SDI_Get_Version(void);
void DDR_FW_SDI_Recover(void);
void DDR_FW_SDI_Dump(void *buffer_ptr, size_t size);

// eCDT (used by DDI for providing QDUTT information)
int DDR_FW_eCDT_Get_Interface_Parameter_Values(uint8 clk_idx, uint32 *buffer_ptr, size_t size);
int DDR_FW_eCDT_Get_AC_Timing_Values(uint32 *buffer_ptr, size_t size);
int DDR_FW_eCDT_Get_Safe_Mode_Values(uint32 *buffer_ptr, size_t size);

// MC (used by DDI for DRAM retention testing)
void DDR_FW_MC_Auto_Refresh_Ctrl(uint8 enable);
void DDR_FW_MC_Enter_Self_Refresh(void);
void DDR_FW_MC_Exit_Self_Refresh(void);

// X,Y Offset (used by DDI for margin testing)
void DDR_FW_Axis_Offset_Init(uint8 clk_idx);
boolean DDR_FW_X_Axis_Offset_CA(int offset);
boolean DDR_FW_Y_Axis_Offset_CA(int offset);
boolean DDR_FW_X_Axis_Offset_RD(int offset);
boolean DDR_FW_Y_Axis_Offset_RD(int offset);
boolean DDR_FW_X_Axis_Offset_WR(int offset);
boolean DDR_FW_Y_Axis_Offset_WR(int offset);

// X,Y Plot (used by DDI for providing QDUTT information)
boolean DDR_FW_XY_Plot_CA(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);
boolean DDR_FW_XY_Plot_RD(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);
boolean DDR_FW_XY_Plot_WR(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);

#endif /* __DDR_FW_FUNC_H__ */
 
