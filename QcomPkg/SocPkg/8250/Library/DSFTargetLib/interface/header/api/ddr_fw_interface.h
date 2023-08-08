#ifndef __DDRFW_INTERFACE_H__
#define __DDRFW_INTERFACE_H__
/*
===========================================================================

FILE:         ddr_fw_interface.h

DESCRIPTION:  
   This file declare APIs that gets called by core_sw.
   ddr_fw expose APIs in this file to core_sw .

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
#include "ddr_shared_interface.h"

/*==============================================================================
                                  FUNCTION POINTER DECLARATIONS
==============================================================================*/
extern void (*fptr_HAL_DDR_FW_Enter)(void *buffer_ptr, size_t size);
extern void (*fptr_HAL_DDR_FW_Exit)(void);
extern DDR_SHARED_STRUCT* (*fptr_HAL_DDR_FW_Get_DDR_SHARED_STRUCT_Pointer)(void); 
extern void (*fptr_HAL_DDR_FW_Init)(void);
extern void (*fptr_HAL_DDR_FW_Train)(void);
extern void (*fptr_HAL_DDR_FW_Restore)(void);

// Frequency Switch
extern void (*fptr_HAL_DDR_FW_DDR_Freq_Switch_Prework)(uint8 new_clk_idx);
extern void (*fptr_HAL_DDR_FW_DDR_Freq_Switch_Work)(uint8 new_clk_idx);
extern void (*fptr_HAL_DDR_FW_DDR_Freq_Switch_Postwork)(uint8 new_clk_idx);

// SDI
extern uint32 (*fptr_HAL_DDR_FW_SDI_Get_Version)(void);
extern void (*fptr_HAL_DDR_FW_SDI_Recover)(void);
extern void (*fptr_HAL_DDR_FW_SDI_Dump)(void *buffer_ptr, size_t size);

// eCDT (used by DDI for providing QDUTT information)
extern int (*fptr_HAL_DDR_FW_eCDT_Get_Interface_Parameter_Values)(uint8 clk_idx, uint32 *buffer_ptr, size_t size);
extern int (*fptr_HAL_DDR_FW_eCDT_Get_AC_Timing_Values)(uint32 *buffer_ptr, size_t size);
extern int (*fptr_HAL_DDR_FW_eCDT_Get_Safe_Mode_Values)(uint32 *buffer_ptr, size_t size);

// MC (used by DDI for DRAM retention testing)
extern void (*fptr_HAL_DDR_FW_MC_Auto_Refresh_Ctrl)(uint8 enable);
extern void (*fptr_HAL_DDR_FW_MC_Enter_Self_Refresh)(void);
extern void (*fptr_HAL_DDR_FW_MC_Exit_Self_Refresh)(void);

// X,Y Offset (used by DDI for margin testing)
extern void (*fptr_HAL_DDR_FW_Axis_Offset_Init)(uint8 clk_idx);
extern boolean (*fptr_HAL_DDR_FW_X_Axis_Offset_CA)(int offset);
extern boolean (*fptr_HAL_DDR_FW_Y_Axis_Offset_CA)(int offset);
extern boolean (*fptr_HAL_DDR_FW_X_Axis_Offset_RD)(int offset);
extern boolean (*fptr_HAL_DDR_FW_Y_Axis_Offset_RD)(int offset);
extern boolean (*fptr_HAL_DDR_FW_X_Axis_Offset_WR)(int offset);
extern boolean (*fptr_HAL_DDR_FW_Y_Axis_Offset_WR)(int offset);

// X,Y Plot (used by DDI for providing QDUTT information)
extern boolean (*fptr_HAL_DDR_FW_XY_Plot_CA)(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);
extern boolean (*fptr_HAL_DDR_FW_XY_Plot_RD)(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);
extern boolean (*fptr_HAL_DDR_FW_XY_Plot_WR)(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);

/* ============================================================================
**  Function : HAL_DDR_FW_Enter
** ============================================================================
*/
/*!
*   @brief
*   This function provides a buffer for DCB, FLASH_PARAMS, and LOCAL_VARS
*   Safe to call HAL_DDR_FW and HAL_CORE_SW functions after this call
*   
*   @param buffer_ptr   -  [IN] pointer to buffer
*   @param size         -  [IN] size of buffer
*   
*   @par Dependencies
*   None 
*   
*   @par Side Effects
*   None
*
*   @retval
*   None
*   
*   @sa None
*/
void HAL_DDR_FW_Enter(void *buffer_ptr, size_t size);


/* ============================================================================
**  Function : HAL_DDR_FW_Exit
** ============================================================================
*/
/*!
*   @brief
*   This function performs final configuration such as enabling power saving features
*   
*   @param
*   None
*   
*   @par Dependencies
*   None 
*   
*   @par Side Effects
*   None
*
*   @retval
*   None
*   
*   @sa None
*/
void HAL_DDR_FW_Exit(void);

/* ============================================================================
**  Function : HAL_DDR_FW_Get_DDR_SHARED_STRUCT_Pointer
** ============================================================================
*/
/*!
*   @brief
*   This function returns a pointer to DDR_SHARED_STRUCT
*   
*   @param
*   None
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   pointer to DDR_SHARED_STRUCT
*   
*   @sa None
*/
DDR_SHARED_STRUCT* HAL_DDR_FW_Get_DDR_SHARED_STRUCT_Pointer(void); 

/* ============================================================================
**  Function : HAL_DDR_FW_Init
** ============================================================================
*/
/*!
*   @brief
*   This function initializes DDR
*   
*   @param
*   None
*   
*   @par Dependencies
*   Requires information is populated in DDR_SHARED_STRUCT
*   
*   @par Side Effects
*   None
*   
*   @retval
*   None
*   
*   @sa None
*/
void HAL_DDR_FW_Init(void);

/* ============================================================================
**  Function : HAL_DDR_FW_Train
** ============================================================================
*/
/*!
*   @brief
*   This function performs DDR training
*   
*   @param
*   None
*   
*   @par Dependencies
*   Requires DDR has been initialized
*   
*   @par Side Effects
*   None
*   
*   @retval
*   None
*   
*   @sa None
*/
void HAL_DDR_FW_Train(void);

/* ============================================================================
**  Function : HAL_DDR_FW_Restore
** ============================================================================
*/
/*!
*   @brief
*   This function restores training results
*   
*   @param
*   None
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   None
*   
*   @sa None
*/
void HAL_DDR_FW_Restore(void);

/* ============================================================================
**  Function : HAL_DDR_FW_DDR_Freq_Switch_Prework
** ============================================================================
*/
/*!
*   @brief
*   This function is called right before clock switching occurs
*
*   @param new_clk_idx  -  [IN] DDR clock index being switched to
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_DDR_Freq_Switch_Prework(uint8 new_clk_idx);

/* ============================================================================
**  Function : HAL_DDR_FW_DDR_Freq_Switch_Work
** ============================================================================
*/
/*!
*   @brief
*   This function is called right after prework function
*
*   @param new_clk_idx  -  [IN] DDR clock index being switched to
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_DDR_Freq_Switch_Work(uint8 new_clk_idx);

/* ============================================================================
**  Function : HAL_DDR_FW_DDR_Freq_Switch_Postwork
** ============================================================================
*/
/*!
*   @brief
*   This function is called right after changing clock frequency
*
*   @param new_clk_idx  -  [IN] DDR clock index being switched to
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_DDR_Freq_Switch_Postwork(uint8 new_clk_idx);

/* ============================================================================
**  Function : HAL_DDR_FW_DDR_Freq_Switch_Postwork
** ============================================================================
*/
/*!
*   @brief
*   This function is called right after changing clock frequency
*
*   @param new_clk_idx  -  [IN] DDR clock index being switched to
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_DDR_Freq_Switch_Postwork(uint8 new_clk_idx);

/* ============================================================================
**  Function : HAL_DDR_FW_SDI_Get_Version
** ============================================================================
*/
/*!
*   @brief
*   This function returns the SDI version in DDR_FW
*   
*   @param
*   None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
uint32 HAL_DDR_FW_SDI_Get_Version(void);

/* ============================================================================
**  Function : HAL_DDR_FW_SDI_Recover
** ============================================================================
*/
/*!
*   @brief
*   This function recovers DDR for SDI
*   
*   @param
*   None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_SDI_Recover(void);

/* ============================================================================
**  Function : HAL_DDR_FW_SDI_Dump
** ============================================================================
*/
/*!
*   @brief
*   This function performs a register dump in a buffer provided
*   
*   @param buffer_ptr   -  [IN] pointer to buffer
*   @param size         -  [IN] size of buffer
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_SDI_Dump(void *buffer_ptr, size_t size);

/* ============================================================================
**  Function : HAL_DDR_FW_eCDT_Get_Interface_Parameter_Values
** ============================================================================
*/
/*!
*   @brief
*   This function gets the current eCDT SoC/DRAM interface parameters for a specificed DDR clock index
*   
*   @param clk_idx      -  [IN] DDR clock index
*   @param buffer_ptr   -  [IN] pointer to buffer for storing index and value
*   @param size         -  [IN] size of buffer
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns number of bytes used in buffer
*
*   @sa None
*/
int HAL_DDR_FW_eCDT_Get_Interface_Parameter_Values(uint8 clk_idx, uint32 *buffer_ptr, size_t size);

/* ============================================================================
**  Function : HAL_DDR_FW_eCDT_Get_AC_Timing_Values
** ============================================================================
*/
/*!
*   @brief
*   This function gets the current eCDT AC timing values
*   
*   @param buffer_ptr   -  [IN] pointer to buffer for storing index and value
*   @param size         -  [IN] size of buffer
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns number of bytes used in buffer
*
*   @sa None
*/
int HAL_DDR_FW_eCDT_Get_AC_Timing_Values(uint32 *buffer_ptr, size_t size);

/* ============================================================================
**  Function : HAL_DDR_FW_eCDT_Get_Safe_Mode_Values
** ============================================================================
*/
/*!
*   @brief
*   This function gets the current eCDT safe mode values
*   
*   @param buffer_ptr   -  [IN] pointer to buffer for storing index and value
*   @param size         -  [IN] size of buffer
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns number of bytes used in buffer
*
*   @sa None
*/
int HAL_DDR_FW_eCDT_Get_Safe_Mode_Values(uint32 *buffer_ptr, size_t size);

/* ============================================================================
**  Function : HAL_DDR_FW_MC_Auto_Refresh_Ctrl
** ============================================================================
*/
/*!
*   @brief
*   This function controls periodic auto refresh
*   
*   @param enable   -  [IN] 0: disable periodic auto refresh, 1: enable
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_MC_Auto_Refresh_Ctrl(uint8 enable);

/* ============================================================================
**  Function : HAL_DDR_FW_MC_Enter_Self_Refresh
** ============================================================================
*/
/*!
*   @brief
*   This function puts the memory device in self refresh
*   
*   @param
*   None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_MC_Enter_Self_Refresh(void);

/* ============================================================================
**  Function : HAL_DDR_FW_MC_Exit_Self_Refresh
** ============================================================================
*/
/*!
*   @brief
*   This function takes the memory device out of self refresh
*   
*   @param
*   None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_MC_Exit_Self_Refresh(void);

/* ============================================================================
**  Function : HAL_DDR_FW_XY_Plot_CA
** ============================================================================
*/
/*!
*   @brief
*   This function creates a plot by offseting from trainined position
*   
*   @param clk_idx              -  [IN] DDR clock index
*   @param ddi_data_offset_ptr  -  [IN] pointer to offset in DDR partition
*   @param x_step               -  [IN] number of steps to offset for each data point on x-axis
*   @param y_step               -  [IN] number of steps to offset for each data point on y-axis
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns FALSE if plot encounters an error saving data to DDR partition
*
*   @sa None
*/
boolean HAL_DDR_FW_XY_Plot_CA(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);

/* ============================================================================
**  Function : HAL_DDR_FW_XY_Plot_RD
** ============================================================================
*/
/*!
*   @brief
*   This function creates a plot by offseting from trainined position
*   
*   @param clk_idx              -  [IN] DDR clock index
*   @param ddi_data_offset_ptr  -  [IN] pointer to offset in DDR partition
*   @param x_step               -  [IN] number of steps to offset for each data point on x-axis
*   @param y_step               -  [IN] number of steps to offset for each data point on y-axis
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns FALSE if plot encounters an error saving data to DDR partition
*
*   @sa None
*/
boolean HAL_DDR_FW_XY_Plot_RD(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);

/* ============================================================================
**  Function : HAL_DDR_FW_XY_Plot_WR
** ============================================================================
*/
/*!
*   @brief
*   This function creates a plot by offseting from trainined position
*   
*   @param clk_idx              -  [IN] DDR clock index
*   @param ddi_data_offset_ptr  -  [IN] pointer to offset in DDR partition
*   @param x_step               -  [IN] number of steps to offset for each data point on x-axis
*   @param y_step               -  [IN] number of steps to offset for each data point on y-axis
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns FALSE if plot encounters an error saving data to DDR partition
*
*   @sa None
*/
boolean HAL_DDR_FW_XY_Plot_WR(uint8 clk_idx, uint32* ddi_data_offset_ptr, uint8 x_step, uint8 y_step);

/* ============================================================================
**  Function : HAL_DDR_FW_Axis_Offset_Init
** ============================================================================
*/
/*!
*   @brief
*   This function initializes data structures needed by [X,Y]_Axis_Offset functions
*   
*   @param clk_idx  -  [IN] DDR clock index
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
void HAL_DDR_FW_Axis_Offset_Init(uint8 clk_idx);

/* ============================================================================
**  Function : HAL_DDR_FW_X_Axis_Offset_CA
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if offset saturates
*
*   @sa None
*/
boolean HAL_DDR_FW_X_Axis_Offset_CA(int offset);

/* ============================================================================
**  Function : HAL_DDR_FW_Y_Axis_Offset_CA
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   None
*
*   @sa None
*/
boolean HAL_DDR_FW_Y_Axis_Offset_CA(int offset);

/* ============================================================================
**  Function : HAL_DDR_FW_X_Axis_Offset_RD
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if offset saturates
*
*   @sa None
*/
boolean HAL_DDR_FW_X_Axis_Offset_RD(int offset);

/* ============================================================================
**  Function : HAL_DDR_FW_Y_Axis_Offset_RD
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if offset saturates
*
*   @sa None
*/
boolean HAL_DDR_FW_Y_Axis_Offset_RD(int offset);

/* ============================================================================
**  Function : HAL_DDR_FW_X_Axis_Offset_WR
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if offset saturates
*
*   @sa None
*/
boolean HAL_DDR_FW_X_Axis_Offset_WR(int offset);

/* ============================================================================
**  Function : HAL_DDR_FW_Y_Axis_Offset_WR
** ============================================================================
*/
/*!
*   @brief
*   This function offsets from trainined position
*   
*   @param offset   -  [IN] number of steps to offset from trained position
*
*   @par Dependencies
*   Must call HAL_DDR_FW_Axis_Offset_Init first
*
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if offset saturates
*
*   @sa None
*/
boolean HAL_DDR_FW_Y_Axis_Offset_WR(int offset);

#endif // __DDRFW_INTERFACE_H__
