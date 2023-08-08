/** 
  @file  ddi_test_cases_internal.h
  @brief defines DDI internal test case APIs
*/
/*=============================================================================

                                DDI Internal Test cases APIs
                                Header File
GENERAL DESCRIPTION
This file defines the DDI test case APIs which are for internal Qualcomm use

  Copyright (c) 2016-2017 QUALCOMM Technologies Incorporated.
  All rights reserved.
  Qualcomm Confidential and Proprietary.
===============================================================================

===============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ------------------------------------------------------------
07/19/17   na      Initial version.
==============================================================================*/
#ifndef __DDI_TEST_CASES_INTERNAL_H__
#define __DDI_TEST_CASES_INTERNAL_H__

/*==========================================================================
                               INCLUDES
===========================================================================*/

#include "ddi_flash_params.h"

/*==========================================================================
                               FUNCTION DEFINITIONS
===========================================================================*/

// helper functions

/* ============================================================================
**  Function : ddi_handle_fail_ret
** ============================================================================
*/
/*!
*   @brief
*   This function is called to log a retention failure to the flash
*
*   @details
*   This will log a DRAM retention test case failure to the flash
*
*   @param fail_params -   [IN] pointer to test case failure summary
*   @param addr        -   [IN] failing address
*   @param expected    -   [IN] expected data
*   @param read        -   [IN] read data
*   @param output_iter -   [IN] pointer to current DDR partition offset
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval boolean
*
*   @sa None
*/
boolean ddi_handle_fail_ret(ddi_handle_fail_params* fail_params, uint64* addr, uint64 expected, uint64 read, uint64* output_iter);

// test case entry points
/* ============================================================================
**  Function : ddi_run_command_ret
** ============================================================================
*/
/*!
*   @brief
*   This function is called to run the DRAM retention DDI test case
*
*   @details
*   This will run DRAM retention testing from the DDI test case interface.
*   Two main modes of this test case:
*   1. measure DRAM cell retention
*   2. validate DRAM self-refresh data integrity
*
*   @param cmd_id      -   [IN] ID of the command. Used for logging to flash.
*   @param params      -   [IN] pointer to test case parameters
*   @param input_iter  -   [IN] pointer to current DCB offset
*   @param output_iter -   [IN] pointer to current DDR partition offset
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
void ddi_run_command_ret(uint64 cmd_id, void* params, uint64* input_iter, uint64* output_iter);

/* ============================================================================
**  Function : ddi_run_command_modify_phy
** ============================================================================
*/
/*!
*   @brief
*   This function is called to change the offsets of CDC and Vref for the SW eye sweep
*
*   @details
*   This will call into DSF to offset CDC and Vref
*   After applying the offset bootup is expected to continue and the host tool is expected to monitor the target
*
*   @param cmd_id      -   [IN] ID of the command. Used for logging to flash.
*   @param params      -   [IN] pointer to test case parameters
*   @param input_iter  -   [IN] pointer to current DCB offset
*   @param output_iter -   [IN] pointer to current DDR partition offset
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval None
*
*   @sa None
*/

void ddi_run_command_modify_phy(uint64 cmd_id, void* params, uint64* input_iter, uint64* output_iter);

#endif /* __DDI_TEST_CASES_INTERNAL_H__ */