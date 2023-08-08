#ifndef __CORESW_INTERFACE_H__
#define __CORESW_INTERFACE_H__
/*
===========================================================================

FILE:         core_sw_interface.h

DESCRIPTION:  
  This file declare APIs that gets called by ddr_fw.
  core_sw expose APIs in this file for providing services to ddr_fw .

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
extern void (*fptr_HAL_CORE_SW_DCB_Init)(DDR_SHARED_STRUCT *ddr_shared_ptr);
extern void (*fptr_HAL_CORE_SW_DCB_Set_DDR_AOP_PARAMS)(DDR_SHARED_STRUCT *ddr_shared_ptr);
extern uint8 (*fptr_HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index)(FREQ_STATE *freq_states, uint8 num_levels, uint32 freq_khz);
extern void (*fptr_HAL_CORE_SW_Set_Initial_Clock_Indices)(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 ddr_khz, uint32 shub_khz, uint32 shrm_khz);
extern void (*fptr_HAL_CORE_SW_Set_Config)(uint32 base_addr, uint16 reg_cnt, uint32  (*reg_offset_val_ptr)[2]);
extern void (*fptr_HAL_CORE_SW_Set_PASR_DDR_INFO_TABLE)(DDR_SHARED_STRUCT *ddr_shared_ptr);
extern uint32 (*fptr_HAL_CORE_SW_Get_Training_Checksum)(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 seed);
extern void (*fptr_HAL_CORE_SW_TRN_FRWK_Run_Switchboard)(DDR_SHARED_STRUCT *ddr_shared_ptr, CORE_SW_TRN_SWITCHBOARD_STRUCT switchboard[MAX_NUM_TRAININGS]);
extern void (*fptr_HAL_CORE_SW_DDR_Abort_Info_Print)(DDR_ABORT_STRUCT *ddr_abort_ptr, char *prefix, uint32 severity);
extern void (*fptr_HAL_CORE_SW_DDR_Print_and_Abort)(DDR_SHARED_STRUCT *ddr_shared_ptr);

// External
extern boolean (*fptr_HAL_EXT_CORE_SW_Get_DCB)(void *buffer_ptr, size_t size, char *name);
extern uint32 (*fptr_HAL_EXT_CORE_SW_Get_Checksum)(uint8 *buf_ptr, uint16 len, uint32 seed);
extern uint32 (*fptr_HAL_EXT_CORE_SW_Get_Time)(void);
extern void (*fptr_HAL_EXT_CORE_SW_DDR_Freq_Switch)(uint8 clk_idx);
extern void (*fptr_HAL_EXT_CORE_SW_DDR_Abort)(void);
extern void (*fptr_HAL_EXT_CORE_SW_Seq_Wait)(uint32 time_value, SEQ_TimeUnit time_unit);
extern void (*fptr_HAL_EXT_CORE_SW_DDR_printf)(uint32 severity, const char *format, va_list args);
extern void (*fptr_HAL_EXT_CORE_SW_memcpy_s)(void *dest, size_t dst_size, const void *src, size_t copy_size);
extern void (*fptr_HAL_EXT_CORE_SW_memset)(void* dst_ptr, int val, size_t len);
extern void (*fptr_HAL_EXT_CORE_SW_snprintf)(char *str, size_t size, const char *format, va_list args);
extern int (*fptr_HAL_EXT_CORE_SW_strncmp)(const char *str1, const char *str2, size_t len);
extern boolean (*fptr_HAL_EXT_CORE_SW_DDI_Save_Data)(uint8 *ddi_data_ptr, uint32 ddi_data_size, uint32 ddi_data_offset);
extern boolean (*fptr_HAL_EXT_CORE_SW_Get_Regulator_Voltage)(const char *regulator, uint32 *voltage);

/* ============================================================================
**  Function : HAL_CORE_SW_DCB_Init
** ============================================================================
*/
/*!
*   @brief
*   This function loads DCB from binary file to buffer at DDR_SHARED_STRUCT.dcb.ptr
*   Also checks version of DCB against DDR_SHARED_STRUCT.dsf_code_version
*   
*   @param DDR_SHARED_STRUCT    -  [IN] pointer to DDR_SHARED_STRUCT
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
void HAL_CORE_SW_DCB_Init(DDR_SHARED_STRUCT *ddr_shared_ptr);

/* ============================================================================
**  Function : HAL_CORE_SW_DCB_Set_DDR_AOP_PARAMS
** ============================================================================
*/
/*!
*   @brief
*   This function populates DDR_AOP_PARAMS from DCB
*   
*   @param ddr_shared_ptr       -  [IN] pointer to DDR_SHARED_STRUCT
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
void HAL_CORE_SW_DCB_Set_DDR_AOP_PARAMS(DDR_SHARED_STRUCT *ddr_shared_ptr);

/* ============================================================================
**  Function : HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index
** ============================================================================
*/
/*!
*   @brief
*   This function gets the enabled clock index with frequency nearest the frequency provided
*   
*   @param freq_states  -  [IN] pointer to array of FREQ_STATE structures
*   @param num_levels   -  [IN] number of indices to check in array
*   @param freq_khz     -  [IN] frequency in Kilohertz
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   Returns enabled clock index with frequency nearest the frequency provided
*   
*   @sa None
*/
uint8 HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index(FREQ_STATE *freq_states, uint8 num_levels, uint32 freq_khz);

/* ============================================================================
**  Function : HAL_CORE_SW_Set_Initial_Clock_Indices
** ============================================================================
*/
/*!
*   @brief
*   This function populates initial clock indices for DDR, SHUB, and SHRM
*   The clock indices are the nearest to the supplied frequencies
*   
*   @param ddr_shared_ptr       -  [IN] pointer to DDR_SHARED_STRUCT
*   @param ddr_khz              -  [IN] DDR clock frequency in kHz
*   @param shub_khz             -  [IN] SHUB clock frequency in kHz
*   @param shrm_khz             -  [IN] SHRM clock frequency in kHz
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
void HAL_CORE_SW_Set_Initial_Clock_Indices(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 ddr_khz, uint32 shub_khz, uint32 shrm_khz);

/* ============================================================================
**  Function : HAL_CORE_SW_Set_Config
** ============================================================================
*/
/*!
*   @brief
*   This function sets registers from an array of offset and value pairs
*   
*   @param base_addr            -  [IN] base address for registers
*   @param reg_cnt              -  [IN] number of registers
*   @param reg_offset_val_ptr   -  [IN] array of register offset and value pairs
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
void HAL_CORE_SW_Set_Config(uint32 base_addr, uint16 reg_cnt, uint32 (*reg_offset_val_ptr)[2]);

/* ============================================================================
**  Function : HAL_CORE_SW_Set_PASR_DDR_INFO_TABLE
** ============================================================================
*/
/*!
*   @brief
*   This function populates PASR_DDR_INFO_TABLE from DDR_SHARED_STRUCT.device_params & .ddr_size_info
*   
*   @param ddr_shared_ptr       -  [IN] pointer to DDR_SHARED_STRUCT
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
void HAL_CORE_SW_Set_PASR_DDR_INFO_TABLE(DDR_SHARED_STRUCT *ddr_shared_ptr);

/* ============================================================================
**  Function : HAL_CORE_SW_Get_Training_Checksum
** ============================================================================
*/
/*!
*   @brief
*   This function determines if training is required by comparing information in
*   DDR_SHARED_STRUCT and FLASH_PARAMS
*   
*   @param ddr_shared_ptr       -  [IN] pointer to DDR_SHARED_STRUCT
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
uint32 HAL_CORE_SW_Get_Training_Checksum(DDR_SHARED_STRUCT *ddr_shared_ptr, uint32 seed);

/* ============================================================================
**  Function : HAL_CORE_SW_TRN_FRWK_Run_Switchboard
** ============================================================================
*/
/*!
*   @brief
*   This function runs trainings in the order dictated by the switchboard
*   
*   @param ddr_shared_ptr   -  [IN] pointer to DDR_SHARED_STRUCT
*   @param switchboard      -  [IN] array of CORE_SW_TRN_SWITCHBOARD_STRUCT
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
void HAL_CORE_SW_TRN_FRWK_Run_Switchboard(DDR_SHARED_STRUCT *ddr_shared_ptr, CORE_SW_TRN_SWITCHBOARD_STRUCT switchboard[MAX_NUM_TRAININGS]);

/* ============================================================================
**  Function : HAL_CORE_SW_DDR_Abort_Info_Print
** ============================================================================
*/
/*!
*   @brief
*   This function prints a message using content of DDR_ABORT_STRUCT
*   
*   @param ddr_abort_ptr    -  [IN] pointer to DDR_ABORT_STRUCT
*   @param prefix           -  [IN] pointer to prefix string for print
*   @param severity         -  [IN] severity for print
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
void HAL_CORE_SW_DDR_Abort_Info_Print(DDR_ABORT_STRUCT *ddr_abort_ptr, char *prefix, uint32 severity);

/* ============================================================================
**  Function : HAL_CORE_SW_DDR_Print_and_Abort
** ============================================================================
*/
/*!
*   @brief
*   This function prints a message using content of DDR_SHARED_STRUCT.ddr_abort_info
*   and then the calls the HAL_EXT_CORE_SW_DDR_Abort
*   
*   @param ddr_shared_ptr   -  [IN] pointer to DDR_SHARED_STRUCT
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
void HAL_CORE_SW_DDR_Print_and_Abort(DDR_SHARED_STRUCT *ddr_shared_ptr);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_Get_DCB
** ============================================================================
*/
/*!
*   @brief
*   This function reads the DCB from a file to a buffer
*   
*   @param buffer_ptr   -  [IN] pointer to buffer where to load DCB
*   @param size         -  [IN] size of buffer
*   @param name         -  [IN] name of DCB file to read
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if file is found and read successfully to the buffer
*   
*   @sa None
*/
boolean HAL_EXT_CORE_SW_Get_DCB(void *buffer_ptr, size_t size, char *name);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_Get_Time
** ============================================================================
*/
/*!
*   @brief
*   This function obtains the system uptime in milliseconds
*   
*   @param
*   None
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval
*   System uptime in milliseconds
*   
*   @sa None
*/
uint32 HAL_EXT_CORE_SW_Get_Time(void);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_Get_Checksum
** ============================================================================
*/
/*!
*   @brief
*   This function gets a checksum from a buffer and a seed
*   
*   @param buf_ptr      -  [IN] pointer to buffer on which to perform checksum
*   @param len          -  [IN] length of buffer in bits
*   @param seed         -  [IN] seed for checksum
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   Calculated checksum
*   
*   @sa None
*/
uint32 HAL_EXT_CORE_SW_Get_Checksum(uint8 *buf_ptr, uint16 len, uint32 seed);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_DDR_Freq_Switch
** ============================================================================
*/
/*!
*   @brief
*   This function switches DDR frequency
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
void HAL_EXT_CORE_SW_DDR_Freq_Switch(uint8 clk_idx);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_DDR_Abort
** ============================================================================
*/
/*!
*   @brief
*   This function indicates an unrecoverable error has occurred
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
void HAL_EXT_CORE_SW_DDR_Abort(void);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_Seq_Wait
** ============================================================================
*/
/*!
*   @brief
*   This function supplies a delay
*   
*   @param time_value   -  [IN] amount of delay
*   @param time_unit    -  [IN] unit of time (SEC/MS/US/NS etc)
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
void HAL_EXT_CORE_SW_Seq_Wait(uint32 time_value, SEQ_TimeUnit time_unit);

/* ============================================================================
**  Function : HAL_EXT_CORE_SW_DDR_printf
** ============================================================================
*/
/*!
*   @brief
*   This function prints based on severity level
*  
*   @param severity     - [IN] level of severity (DDR_NORMAL, DDR_ERROR, etc)
*   @param fmt          - [IN] format string for data
*   @param ...          - [IN] comma separated data
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
void HAL_EXT_CORE_SW_DDR_printf(uint32 severity, const char* fmt, ...);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_memcpy_s
** ==========================================================================
*/
/*!
*   @brief
*   This function copies data from source to destination
*  
*   @param dest         - [IN] pointer to destination buffer
*   @param dst_size     - [IN] destination buffer size
*   @param src          - [IN] pointer to source buffer
*   @param copy_size    - [IN] size of data to copy
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
void HAL_EXT_CORE_SW_memcpy_s(void *dest, size_t dst_size, const void *src, size_t copy_size);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_memset
** ==========================================================================
*/
/*!
*   @brief
*   This function sets memory to a given value
*  
*   @param dst_ptr      - [IN] pointer to destination buffer
*   @param val          - [IN] values to set
*   @param len          - [IN] number of bytes to set
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
void HAL_EXT_CORE_SW_memset(void* dst_ptr, int val, size_t len);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_snprintf
** ==========================================================================
*/
/*!
*   @brief
*   This function prints to a string
*  
*   @param str      - [IN] pointer to destination buffer
*   @param size     - [IN] size of destination buffer
*   @param format   - [IN] format string for data
*   @param ...      - [IN] comma separated data
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
void HAL_EXT_CORE_SW_snprintf(char* str, size_t size, const char* fmt, ...);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_strncmp
** ==========================================================================
*/
/*!
*   @brief
*   This function compares two strings
*  
*   @param str1     - [IN] pointer to first string
*   @param str2     - [IN] pointer to second string
*   @param len      - [IN] length to compare
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval 
*   0 if identical, otherwise non-zero
*   
*   @sa None
*/
int HAL_EXT_CORE_SW_strncmp(const char* str1, const char *str2, size_t len);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_DDI_Save_Data
** ==========================================================================
*/
/*!
*   @brief
*   This function saves data to the DDR partition
*  
*   @param ddi_data_ptr     - [IN] pointer to data
*   @param ddi_data_size    - [IN] size of data
*   @param ddi_data_offset  - [IN] offset in DDR partition
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if data is successfully saved to the DDR partition
*   
*   @sa None
*/
boolean HAL_EXT_CORE_SW_DDI_Save_Data(uint8* ddi_data_ptr, uint32 ddi_data_size, uint32 ddi_data_offset);

/*===========================================================================
**  Function : HAL_EXT_CORE_SW_Get_Regulator_Voltage
** ==========================================================================
*/
/*!
*   @brief
*   This function saves data to the DDR partition
*  
*   @param regulator    - [IN] regulator short name (ex: "S3A")
*   @param voltage      - [OUT] regulator voltage in millivolts (mV)
*   
*   @par Dependencies
*   None
*   
*   @par Side Effects
*   None
*   
*   @retval
*   Returns TRUE if regulator voltage was read successfully
*   
*   @sa None
*/
boolean HAL_EXT_CORE_SW_Get_Regulator_Voltage(const char *regulator, uint32 *voltage);

#endif // __CORESW_INTERFACE_H__
