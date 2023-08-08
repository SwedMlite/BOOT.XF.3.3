/**
 * @file ddi_testing.c
 * @brief
 * DDI testing entry point
 */
/*=============================================================================

                                DDI Test cases
                                Source File
GENERAL DESCRIPTION
This file defines the entry point for DDI testing

  Copyright (c) 2016-2017 QUALCOMM Technologies Incorporated.
  All rights reserved.
  Qualcomm Confidential and Proprietary.
===============================================================================

===============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

===============================================================================
when       who     what, where, why
--------   ---     ------------------------------------------------------------
07/19/17   na      Initial version
==============================================================================*/

/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include <string.h>

#include "ddi_testing.h"
#include "ddi_flash_params.h"

#include "boot_util.h"
#include "ddr_external.h"
#include "ddr_params.h"
#include "boot_extern_ddi_interface.h"
#include "boot_emergency_dload.h"

/*==============================================================================
                                  DATA
==============================================================================*/

extern ddi_test_case_func test_case_list[];
extern uint8 ddi_number_of_cmds;

// internal output buffer which will be flushed to the flash
uint8 ddi_int_out[DDI_INT_OUT_BUF_SIZE];

// output report counter
uint64 ddi_report_offset = 0;

#if DDI_PRINT_ENABLE
char ddi_log_string[50];
#endif

/*==============================================================================
                                  FUNCTIONS
==============================================================================*/

#if defined FEATURE_BOOT_DDI_ENABLE

/* ============================================================================
**  Function : ddi_ddr_fw_exit
** ============================================================================
*/
/*!
*   @brief
*   Wrapper for ddr_fw_exit
*
*   @param None
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
void ddi_ddr_fw_exit(void)
{
  static boolean b_ddrexited=FALSE;
  if(b_ddrexited==FALSE)
  {
    HAL_DDR_FW_Exit();
    b_ddrexited=TRUE;
  }
}
/* ============================================================================
**  Function : ddi_rhd_command
** ============================================================================
*/
/*!
*   @brief
*   based on input command ID, Add amount of header for skipping
*
*   @param cmd         -   [IN] pointer to DCB data for command header
*   @param input_iter  -   [IN] pointer to current DCB offset
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

void ddi_rhd_command(ddi_command_header* cmd, uint64* input_iter)
{
  if ( cmd->cmd_id >= ddi_number_of_cmds)
  {
	  boot_log_message("DDI invalid cmd\r\n");
  }

  switch(cmd->cmd_id)
  {
  	case 0: //    {DDI_POST_DDR_STEP, ddi_run_command_rd}
  		*input_iter += sizeof(ddi_rd_params);
		break;
  	case 1: //    {DDI_POST_DDR_STEP, ddi_run_command_wr}
		*input_iter += (((ddi_wr_params*)(*input_iter))->pattern_size*sizeof(uint64));
		*input_iter += sizeof(ddi_wr_params);
		break;
  	case 2: //    {DDI_POST_DDR_STEP, ddi_run_command_rdwr}
  		*input_iter	+= (((ddi_rdwr_params*)(*input_iter))->pattern_size*sizeof(uint64));
		*input_iter += sizeof(ddi_rdwr_params);
		break;
  	case 3: //    {DDI_POST_DDR_STEP, ddi_run_command_delay}
  		*input_iter += sizeof(ddi_delay_params);
		break;
  	case 4: //    {DDI_POST_DDR_STEP, ddi_run_command_freq}
  		*input_iter += sizeof(ddi_freq_params);
		break;
  	case 5: //    {DDI_POST_DDR_STEP, ddi_run_command_retention}
  		// not implemented
  		break;
  	case 6: //    {DDI_POST_DDR_STEP, ddi_run_command_plot}
  		*input_iter += sizeof(ddi_plot_params);
		break;
  	case 7: //    {DDI_POST_DDR_STEP, ddi_run_command_phy_update}
  		*input_iter += sizeof(ddi_mod_phy_offset_params);
		break;
	
  	case 8: //    {DDI_PRE_DDR_STEP, ddi_get_device_info}
  	case 9: //    {DDI_PRE_DDR_STEP, ddi_read_ecdt_parameters}
  	case 10://    {DDI_PRE_DDR_STEP, ddi_get_ac_timing}
  	case 11://    {DDI_PRE_DDR_STEP, ddi_get_safe_mode_info}
  	case 12://    {DDI_PRE_DDR_STEP, ddi_run_command_empty}
  	default:
  		break;

	
  }
}

/* ============================================================================
**  Function : ddi_run_command
** ============================================================================
*/
/*!
*   @brief
*   based on input command ID, calls DDI test function
*
*   @param cmd         -   [IN] pointer to DCB data for command header
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

void ddi_run_command(ddi_command_header* cmd, uint64* input_iter, uint64* output_iter)
{
  test_case_func test;
  if ( cmd->cmd_id >= ddi_number_of_cmds)
  {
	  boot_log_message("DDI invalid cmd\r\n");
  }
  test = (test_case_func)test_case_list[cmd->cmd_id].func_ptr;
  test(cmd->cmd_id, (void*)(*input_iter), input_iter, output_iter);
}


/* ============================================================================
**  Function : ddi_run_commands
** ============================================================================
*/
/*!
*   @brief
*   high-level algorithm for running DDI test cases
*
*   @param cmds_hdr    -   [IN] pointer to DCB data for commands header
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
void ddi_run_commands(ddi_commands_header* cmds_hdr, ddi_step_param step)
{
  // trackers for input and output offsets
  ddi_command_header* cmd_hdr;
  uint64 input_iter = (uint64)((void*)cmds_hdr + sizeof(ddi_commands_header));
  uint64 output_iter = ddi_report_offset;
  uint32 num_cmds = cmds_hdr->num_cmds;

  if(step==DDI_PRE_DDR_STEP)
  {
  sbl1_read_from_ddr_partition(DDI_OUTPUT_SECTION_START_IN_DDR, ddi_int_out, sizeof(ddi_int_out));
  if (*((uint32*)ddi_int_out) == DDI_CMDP_COOKIE)
  {
	  boot_log_message("DDI output present, go to EDL");
	  boot_dload_transition_pbl_forced_dload();
  }
  // mark commands as processed in the beginning of testing
  *((uint32*)ddi_int_out) = DDI_CMDP_COOKIE;
  save_ddi_data2ddr_partition(ddi_int_out, sizeof(uint32), output_iter);
  output_iter += sizeof(uint32);
  }

  do {
    input_iter = (uint64)((void*)cmds_hdr + sizeof(ddi_commands_header));
    for (uint32 i = 0; i < num_cmds; i++) {
      cmd_hdr = (ddi_command_header*)input_iter;
      input_iter += sizeof(ddi_command_header);
      if (test_case_list[cmd_hdr->cmd_id].ddi_step == step)
	  {
	  	ddi_run_command(cmd_hdr, &input_iter, &output_iter);
      }
	  else
	  {
	    ddi_rhd_command(cmd_hdr, &input_iter);
	  }
    }
  } while(cmds_hdr->boot_id == DDI_BOOT_ID_REPEAT);

  ddi_report_offset = output_iter;
  if ((cmds_hdr->boot_id == DDI_BOOT_ID_EDL) && (step==DDI_POST_DDR_STEP)){
    boot_dload_transition_pbl_forced_dload();
  }
}

/* ============================================================================
**  Function : ddr_ddi_testing
** ============================================================================
*/
/*!
*   @brief
*   checks version number and decides whether test should be run or not
*
*   @param ddi_data    -   [IN] pointer to DCB data for all DDI input
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
boolean ddr_ddi_testing(void* ddi_data, ddi_step_param step)
{
  if (ddi_data == NULL)
    return FALSE;
  ddi_commands_header* cmds_hdr = (ddi_commands_header*)ddi_data;
  uint32 major = cmds_hdr->ddi_version >> 16;
  uint32 minor = cmds_hdr->ddi_version & 0xFF;
  if (major == DDI_MAJOR_VERSION && minor == DDI_MINOR_VERSION) {
    ddi_run_commands((ddi_commands_header*)ddi_data, step);
    return TRUE;
  }
  return FALSE;
}

#endif //FEATURE_BOOT_DDI_ENABLE
/* ============================================================================
**  Function : ddi_pre_entry
** ============================================================================
*/
/*!
*   @brief
*   entry point for ddi testing
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
void ddi_pre_entry()
{
#if defined FEATURE_BOOT_DDI_ENABLE
  void* ddi_data = ddr_external_read_ddi_binary();
  ddr_ddi_testing(ddi_data, DDI_PRE_DDR_STEP);
#endif
}

/* ============================================================================
**  Function : ddi_entry
** ============================================================================
*/
/*!
*   @brief
*   entry point for ddi testing
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
void ddi_entry()
{
#if defined FEATURE_BOOT_DDI_ENABLE
  void* ddi_data = ddr_external_read_ddi_binary();
  ddr_ddi_testing(ddi_data, DDI_POST_DDR_STEP);
#endif
  ddi_ddr_fw_exit();
}
