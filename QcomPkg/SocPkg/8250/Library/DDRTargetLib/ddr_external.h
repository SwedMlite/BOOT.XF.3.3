#ifndef __DDR_EXTERNAL_H__
#define __DDR_EXTERNAL_H__

/*=============================================================================
                                DDR EXTERNAL
                                Header File
GENERAL DESCRIPTION
 This file defines the external environment APIs that DDR HAL layers may need to invoke
=============================================================================*/
/*******************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2013-2018, Qualcomm Technologies Incorporated.
 All rights reserved.
 ******************************************************************************/
/*==============================================================================
$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/DDRTargetLib/ddr_external.h#3 $
$DateTime: 2019/08/12 14:21:43 $
$Author: pwbldsvc $
================================================================================*/
#include "HALcomdef.h"
#include "HAL_SNS_DDR.h"
//#include "seq_hwio.h"

/*==============================================================================
                                  TYPES
==============================================================================*/

// enum{
    // DDR_SOC_SDM845_V1 = 0x0   //To-do: Fill in the correct SOC value here
// };

typedef enum 
{	
  DDR_TRAINING_READ,	
  DDR_TRAINING_WRITE, 
  DDR_TRAINING_CACK
}ddr_training_type;

typedef struct 
{
  uint8 currentChannel;
  uint8 currentChipSelect;
  uint8 currentFreqIndex;
  uint8 best_cdc_value;
  uint8 best_vref_value;
  uint32 FreqInKhz;
  ddr_training_type trainingType;	
}ddr_training_args;

/*==============================================================================
                                  MACROS
==============================================================================*/
/* Macro for round-up division */
#define div_ceil(n, d)  (((n) + (d) - 1) / (d))

/*==============================================================================
                                  FUNCTION PROTOTYPES
==============================================================================*/

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void ddr_external_set_clk_speed(uint8 clk_in_khz);
#else
  static inline void ddr_external_set_clk_speed(uint8 clk_in_khz)
  {
    return;
  }
#endif


/* ============================================================================
**  Function : seq_wait
** ============================================================================
*/
/*!
*   @brief
*   This function is called by external library to introduce wait/delay
*   
*   @details
*   This api will call the relevant busywait function to introduce needed delay.
*   
*   @param 
*   @param time_value       -  [IN] delay time .
*   @param time_unit        -  [IN] time in units (SEC/MS/US/NS etc)
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  None
*   
*   @sa None
*/
#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void seq_wait(uint32 time_value, SEQ_TimeUnit time_unit);
#else
  static inline void seq_wait(uint32 time_value, SEQ_TimeUnit time_unit)
  {
    return;
  } 
#endif

/* ============================================================================
**  Function : ddr_external_page_to_storage
** ============================================================================
*/
/*!
*   @brief
*   This function is called by external library to save ddr training logs to 
* 	external non-volatile storage
*   
*   @details
*   This function is called by external library to save ddr training logs to 
* 	external non-volatile storage. This api has to take care of offsets for 
* 	saving to external storage so we do not run out of space.
*   api will perform a memset 0 on input buffer of input size before returning
*   
*   @param 
*   @param buffer             -  [IN] uint32 * buffer where traiing logs are located
*   @param size               -  [IN] uint32 * size of data in buffer
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  void
*
*   
*   @sa None
*/

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
void ddr_external_page_to_storage( void * buffer, uint32 size );
#else
  static inline void ddr_external_page_to_storage( void * buffer, uint32 size )
  {
    return;
  } 
#endif

/* ============================================================================
**  Function : ddr_external_get_training_log_size
** ============================================================================
*/
/*!
*   @brief
*   This function is used to return the current stored training log size
*   
*   @details
*   This function is used to return the current stored training log size
*   
*   @param 
*   None
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  uint32
*   size of current trainig log saved to emmc
*   
*   @sa None
*/
#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
uint32 ddr_external_get_training_log_size(void);
#else
  static inline uint32 ddr_external_get_training_log_size(void)
  {
    return 0;
  } 
#endif

/* ============================================================================
**  Function : ddr_external_set_ddrss_cfg_clk
** ============================================================================
*/
/*!
*   @brief
*   This function is called by external library to set( ON/OFF ) the GCC_DDR_DIM_CFG
*   
*   @details
*   This function is called by external library to set( ON/OFF ) the GCC_DDR_DIM_CFG
*   
*   @param 
*   @param boolean            -  [IN] boolean flag to enable/disable GCC_DDR_DIM_CFG clock
*                                                   
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  boolean
*   reutrn operation success\failure
*   
*   @sa None
*/

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  boolean ddr_external_set_ddrss_cfg_clk(boolean on_off);
#else
  static inline boolean ddr_external_set_ddrss_cfg_clk(boolean on_off)
  {
    return TRUE;
  } 
#endif

/* ============================================================================
**  Function : ddr_abort(void)
** ============================================================================
*/
/*!
*   @brief
*   This function is called by external library to abort if a small eye is found.
*   
*   @details
*   This function is called by external library to abort if a small eye is found.
*   
*   @param 
*   @param boolean            -  [IN] boolean flag to enable/disable GCC_DDR_DIM_CFG clock
*                                                   
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  boolean
*   reutrn operation success\failure
*   
*   @sa None
*/

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  void ddr_abort(void);
#else
  static inline void ddr_abort(void)
  {
    return;
  } 
#endif

/* ============================================================================
**  Function : ddr_send_data_to_ddi
** ============================================================================
*/
/*!
*   @brief
*   This function is called during training to pass training results to ddi
*   
*   @details
*   This function is called during training to pass training results to ddi
*   
*   @param 
*   @param flag             -  [IN] boolean flag to enable/disable IO clamps
*   
*   @par Dependencies
*   
*   @par Side Effects
*   None
*   
*   @retval  None
*   
*   @sa None
*/
#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void ddr_send_data_to_ddi(void * buffer, uint32 size, ddr_training_args* tArgs);
#else 
  static inline void ddr_send_data_to_ddi(void * buffer, uint32 size, ddr_training_args* tArgs)
  { 
    return; 
  } 
#endif

/* ============================================================================
**  Function : ddr_external_get_time
** ============================================================================
*/
/*!
* 
* @brief
*  Returns a timestamp which is the current absolute time since bootup
*  subtracts the reference time.
*   
* @retval
*    Current time in microseconds. 
*    LOG_TIMESTAMP_OVERFLOW if timestamp overflows
* 
* @par Side Effects
*   None
* 
*/

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  uint32 ddr_external_get_time(); 
#else 
  static inline uint32 ddr_external_get_time() 
  { 
    return 0; 
  } 
#endif

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  boolean ddr_external_get_dcb (void *buffer, size_t size, char *dcb_name);
#else 
  static inline boolean ddr_external_get_dcb (void *buffer, size_t size, char *dcb_name)
  { 
    return TRUE; 
  } 
#endif

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  uint32 ddr_external_get_checksum(uint8  *buf_ptr, uint16  len, uint32  seed);
#else 
  static inline uint32 ddr_external_get_checksum(uint8  *buf_ptr, uint16  len, uint32  seed)
  { 
    return 0; 
  } 
#endif

#ifdef FEATURE_BOOT_EXTERN_DDR_COMPLETED 
  void pxi_gpio_trigger(uint8 ch); 
#else 
  static inline void pxi_gpio_trigger(uint8 ch)
  { 
    return; 
  } 
#endif

#ifndef DSF_COMPILING_SHRM
#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED && defined FEATURE_BOOT_DDI_ENABLE
  void* ddr_external_read_ddi_binary(); 
#else 
  static void* ddr_external_read_ddi_binary()
  { 
    return NULL; 
  } 
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED && defined FEATURE_BOOT_DDI_ENABLE
  boolean save_ddi_data2ddr_partition
  (
    uint8* ddi_data_ptr,
    uint32 ddi_data_size,
    uint32 ddi_data_offfset
  );
#else 
  static boolean save_ddi_data2ddr_partition
  (
    uint8* ddi_data_ptr,
    uint32 ddi_data_size,
    uint32 ddi_data_offfset
  )
  {
    return TRUE;
  }
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void ddr_external_snprintf(char* str, size_t size, const char* format, va_list vargs);
#else
  static inline void ddr_external_snprintf(char* str, size_t size, const char* format, va_list vargs)
  {
    return;
  }
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void ddr_external_memscpy(void *dest, size_t dst_size, const void *src, size_t copy_size);
#else
  static inline void ddr_external_memscpy(void *dest, size_t dst_size, const void *src, size_t copy_size)
  {
    return;
  }
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED
  void ddr_external_memset(void* dst_ptr, int val, size_t len);
#else
  static inline void ddr_external_memset(void* dst_ptr, int val, size_t len)
  {
    return;
  }
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED
  int ddr_external_strncmp(const char* str1, const char *str2, size_t len);
#else
  static inline int ddr_external_strncmp(const char* str1, const char *str2, size_t len)
  {
    return 0;
  }
#endif

#if defined FEATURE_BOOT_EXTERN_DDR_COMPLETED
  boolean ddr_external_get_regulator_voltage(const char *regulator, uint32 *voltage);
#else
  static inline boolean ddr_external_get_regulator_voltage(const char *regulator, uint32 *voltage)
  {
    return TRUE;
  }
#endif

#endif
#endif /* __DDR_EXTERNAL_H__ */

