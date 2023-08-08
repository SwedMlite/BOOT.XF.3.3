/*
===========================================================================

FILE:         ddr_params.c

DESCRIPTION:
  Information of DDR devices supported by target.

===========================================================================

                             Edit History


when       who     what, where, why
--------   ---     --------------------------------------------------------
09/10/19   kns     Add ddr_search_nominal_freq
12/18/12   dj      Add ddr info protocal
03/12/14   sr      Initial revision.

===========================================================================
                   Copyright 2018-2019 Qualcomm Technologies Incorporated
                              All Rights Reserved
                     Qualcomm Confidential and Proprietary
===========================================================================
*/

/*==============================================================================
                                    INCLUDES
==============================================================================*/
#include "ddr_params.h"
#include "crc.h"
#include "ddr_log.h"
#include "dev_flash_params.h"
#define USE_LOADER_UTILS
#include "LoaderUtils.h"
#include "Target_cust.h"
#include "ddr_hwio.h"
#include "ddr_target.h"
#include "ddr_sdi_log.h"
#include "boot_util.h"
#include "ClockBoot.h"

/*==============================================================================
                                      DATA
==============================================================================*/

DDR_SHARED_STRUCT *ddr_shared_data = NULL;
DDR_SDI_LOGS *ddr_sdi_logs_ptr = (DDR_SDI_LOGS *)SDI_COOKIES_STRUCT_BASE;
static DDR_DRIVER_STRUCT ddr_swdriver_struct;
DDR_DRIVER_STRUCT *ddr_driver_struct = &ddr_swdriver_struct;


/*==============================================================================
                                   FUNCTIONS
==============================================================================*/

void HAL_Set_Function_Pointers()
{   
    fptr_HAL_CORE_SW_DCB_Init = CORE_SW_DCB_Init;
    fptr_HAL_CORE_SW_DCB_Set_DDR_AOP_PARAMS =  CORE_SW_DCB_Set_DDR_AOP_PARAMS;
    fptr_HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index = CORE_SW_Get_Nearest_Enabled_Clock_Index;
    fptr_HAL_CORE_SW_Set_Initial_Clock_Indices = CORE_SW_Set_Initial_Clock_Indices;
    fptr_HAL_CORE_SW_Set_Config = CORE_SW_Set_Config;
    fptr_HAL_CORE_SW_Set_PASR_DDR_INFO_TABLE = CORE_SW_Set_PASR_DDR_INFO_TABLE;
    fptr_HAL_CORE_SW_Get_Training_Checksum = CORE_SW_Get_Training_Checksum;
    fptr_HAL_CORE_SW_TRN_FRWK_Run_Switchboard = CORE_SW_TRN_FRWK_Run_Switchboard;


    fptr_HAL_EXT_CORE_SW_Get_DCB = ddr_external_get_dcb;
	fptr_HAL_EXT_CORE_SW_Get_Time = ddr_external_get_time;
	fptr_HAL_EXT_CORE_SW_Get_Checksum = ddr_external_get_checksum;
    fptr_HAL_EXT_CORE_SW_DDR_Freq_Switch = ddr_external_set_clk_speed;
    fptr_HAL_EXT_CORE_SW_DDR_Abort = ddr_abort;
    fptr_HAL_EXT_CORE_SW_memcpy_s = ddr_external_memscpy;
    fptr_HAL_EXT_CORE_SW_memset = ddr_external_memset;
    fptr_HAL_EXT_CORE_SW_Seq_Wait = seq_wait;
    fptr_HAL_EXT_CORE_SW_DDR_printf = ddr_logf;
    fptr_HAL_EXT_CORE_SW_snprintf = ddr_external_snprintf;
    fptr_HAL_EXT_CORE_SW_strncmp = ddr_external_strncmp;
    fptr_HAL_EXT_CORE_SW_Get_Regulator_Voltage = ddr_external_get_regulator_voltage;
    fptr_HAL_EXT_CORE_SW_DDI_Save_Data = save_ddi_data2ddr_partition;//EXT_CORE_SW_DDI_Save_Data;

    fptr_HAL_CORE_SW_DDR_Abort_Info_Print = CORE_SW_DDR_Abort_Info_Print;
    fptr_HAL_CORE_SW_DDR_Print_and_Abort = CORE_SW_DDR_Print_and_Abort; 
    
    fptr_HAL_DDR_FW_Enter = DDR_FW_Enter;
    fptr_HAL_DDR_FW_Get_DDR_SHARED_STRUCT_Pointer = DDR_FW_Get_DDR_SHARED_STRUCT_Pointer;
    fptr_HAL_DDR_FW_Init = DDR_FW_Init;
    fptr_HAL_DDR_FW_Train = DDR_FW_Train;
    fptr_HAL_DDR_FW_Restore = DDR_FW_Restore;
    fptr_HAL_DDR_FW_Exit = DDR_FW_Exit;

    fptr_HAL_DDR_FW_DDR_Freq_Switch_Prework = DDR_FW_DDR_Freq_Switch_Prework;
    fptr_HAL_DDR_FW_DDR_Freq_Switch_Work = DDR_FW_DDR_Freq_Switch_Work;
    fptr_HAL_DDR_FW_DDR_Freq_Switch_Postwork = DDR_FW_DDR_Freq_Switch_Postwork;
		
    fptr_HAL_DDR_FW_MC_Auto_Refresh_Ctrl = DDR_FW_MC_Auto_Refresh_Ctrl;
    fptr_HAL_DDR_FW_MC_Enter_Self_Refresh = DDR_FW_MC_Enter_Self_Refresh;
    fptr_HAL_DDR_FW_MC_Exit_Self_Refresh = DDR_FW_MC_Exit_Self_Refresh;

    fptr_HAL_DDR_FW_SDI_Get_Version = DDR_FW_SDI_Get_Version;
    fptr_HAL_DDR_FW_SDI_Recover = DDR_FW_SDI_Recover;
    fptr_HAL_DDR_FW_SDI_Dump = DDR_FW_SDI_Dump;

    fptr_HAL_DDR_FW_eCDT_Get_Interface_Parameter_Values = DDR_FW_eCDT_Get_Interface_Parameter_Values;
    fptr_HAL_DDR_FW_eCDT_Get_AC_Timing_Values = DDR_FW_eCDT_Get_AC_Timing_Values;
    fptr_HAL_DDR_FW_eCDT_Get_Safe_Mode_Values = DDR_FW_eCDT_Get_Safe_Mode_Values;

    fptr_HAL_DDR_FW_XY_Plot_CA = DDR_FW_XY_Plot_CA;
    fptr_HAL_DDR_FW_XY_Plot_RD = DDR_FW_XY_Plot_RD;
    fptr_HAL_DDR_FW_XY_Plot_WR = DDR_FW_XY_Plot_WR;

    fptr_HAL_DDR_FW_Axis_Offset_Init = DDR_FW_Axis_Offset_Init;
    fptr_HAL_DDR_FW_X_Axis_Offset_CA = DDR_FW_X_Axis_Offset_CA;
    fptr_HAL_DDR_FW_Y_Axis_Offset_CA = DDR_FW_Y_Axis_Offset_CA;
    fptr_HAL_DDR_FW_X_Axis_Offset_RD = DDR_FW_X_Axis_Offset_RD;
    fptr_HAL_DDR_FW_Y_Axis_Offset_RD = DDR_FW_Y_Axis_Offset_RD;
    fptr_HAL_DDR_FW_X_Axis_Offset_WR = DDR_FW_X_Axis_Offset_WR;
    fptr_HAL_DDR_FW_Y_Axis_Offset_WR = DDR_FW_Y_Axis_Offset_WR;

}

/* ============================================================================
**  Function : ddr_get_shub_shrm_freq
** ============================================================================
*/
/**
*   @brief
*   This function call clock api to get shub and shrm frequency.
*
*   @param[in]  void
*
*   @return
*
*   @dependencies
*   Must be called prior to ddr_initialize_device
*
*   @sa
*   None
*
*   @sa
*   None
*/

void ddr_get_shub_shrm_freq(void)
{
    /* Fill the SDI Cookie struct with addresses */
	uint32 shub_init_freq;
	uint32 shrm_init_freq;
	
 	if(Clock_GetClockFrequency(CLK_BOOT_LOG_SHUB, &shub_init_freq) == TRUE)
	{
		ddr_shared_data->shub_init_clk_idx =  HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index(ddr_shared_data->ddr_aop_params.ptr->shub_states, ddr_shared_data->num_shub_levels, shub_init_freq/1000);
	}
	
	if(Clock_GetClockFrequency(CLK_BOOT_LOG_SHRM, &shrm_init_freq) == TRUE)
	{
		ddr_shared_data->shrm_init_clk_idx = HAL_CORE_SW_Get_Nearest_Enabled_Clock_Index(ddr_shared_data->ddr_aop_params.ptr->shrm_states, ddr_shared_data->num_shrm_levels, shrm_init_freq/1000);
	}
}


/* ============================================================================
**  Function : ddr_set_params
** ============================================================================
*/
/**
*   @brief
*   This function sets the DDR driver's device table to an external device table.
*   It will also update the interleaving mode information according to the parameter
*   header that's passed in.
*   User should append ddr_device_params_header_v1 header in front of their own DDR device 
*   table and pass  a pointer points to the beginning of this header via the this API to 
*   force DDR driver to utilize the user defined parameters.
*   The user defined ddr device table must contain a minimal number of entries to 
*   match the system's ddr devices.
*   For example if a system has two ddr devices attached then the external table must 
*   define at least two entries to match those two devices.
*   However, more entries can be added to the end of table to support other ddr devices
*   with different parameters.
*
*   @param[in]  ddr_params_ptr   Pointer to the external ddr parameters. It should
*                                point to the user defined ddr device table with ddr
*                                parameters header appended in front. This pointer must
*                                points to a 4 bytes aligned address.
*                         
*
*   @return
*   TRUE if DDR device table is updated, FALSE if an error happens and this operation
*   is aborted
*
*   @dependencies
*   Must be called prior to ddr_initialize_device. 
*   This API will take no effect after ddr_initialize_device
*
*   @sa
*   None
*
*   @sa
*   None
*/
boolean ddr_set_params(boolean dload_mode, boolean clock_configured)
{
  HAL_Set_Function_Pointers();
  ddr_set_sdi_struct();
  if ((!dload_mode)||(HWIO_INF(AOSS_CC_RESET_FSM_CTRL, FIRST_PASS_COMPLETE) && HWIO_AOSS_CC_ALT_RESET_ENABLE_INM(HWIO_AOSS_CC_ALT_RESET_ENABLE_ALLOW_BIMC_ALT_ARES_BMSK)) ||
            HWIO_INF(AOSS_CC_RESET_FSM_STATUS, FIRST_PASS_EXPIRE))
  {
      if(clock_configured == FALSE)
      {
          HAL_DDR_FW_Enter((void*)SCL_SBL1_DDR_DSF_CFG_BUF_BASE, SIZE_64KB);
      }
  }
  ddr_shared_data = HAL_DDR_FW_Get_DDR_SHARED_STRUCT_Pointer();

  return TRUE;
}

/* ============================================================================
**  Function : ddr_set_sdi_struct
** ============================================================================
*/
/**
*   @brief
*   This function sets the addresses for the SDI logging space.
*
*   @param[in]  void
*
*   @return
*
*   @dependencies
*   Must be called prior to ddr_set_params
*
*   @sa
*   None
*
*   @sa
*   None
*/

void ddr_set_sdi_struct(void)
{
    /* Fill the SDI Cookie struct with addresses */
  ddr_sdi_logs_ptr->pass1_enter_cookie = (SDIInfo *)PASS1_ENTER_COOKIE;
  ddr_sdi_logs_ptr->pass2_cookie = (SDIInfo *)PASS2_COOKIE;
  ddr_sdi_logs_ptr->pass1_exit_cookie = (SDIInfo *)PASS1_EXIT_COOKIE;
  ddr_sdi_logs_ptr->sdi_csr_log = (void *)SDI_REG_LOG_START_ADDR;
}


/* ============================================================================
**  Function : ddr_get_detected_params
** ============================================================================
*/
/**
*   @brief
*   Get DDR device parameters.
*
*   @param[in]  interface_name  Interface to get DDR device parameters for
*
*   @return
*   DDR device parameters
*
*   @dependencies
*   None
*
*   @sa
*   None
*
*   @sa
*   None
*/
struct detected_ddr_device_params *ddr_get_detected_params(DDR_CHANNEL interface_name)
{
  struct detected_ddr_device_params *ddr_detected_params = NULL;
  uint8 i = 0;

  // i = ((interface_name == DDR_CH0) ? 0 : (interface_name == DDR_CH1) ? 1 : (interface_name == DDR_CH2) ? 2 : (interface_name == DDR_CH3) ? 3 : 0);                                       

  while (interface_name != 1)
  {
    interface_name >>= 1;
    i++;
  } 

  ddr_detected_params = &(ddr_shared_data->device_params);

  return ddr_detected_params;
} /* ddr_get_detected_params */

/* ============================================================================
**  Function : ddr_param_interleaved
** ============================================================================
*/
/**
*   @brief
*   Return the interleave setting based on ddr parameters
*
*   @return
*   return a bitmask of interleave status
*
*   @dependencies
*   Must be called after ddr_set_params. Calling it before ddr_set_params will
*   return the default setting which is TRUE.
*
*   @sa
*   None
*
*   @sa
*   None
*/
uint32 ddr_param_interleaved(void)
{
  return DDR_CS0_CS1_INTERLEAVE;
}

/* =============================================================================
**  Function : ddr_params_get_training_data
** =============================================================================
*/
/**
*   @brief
*   Get DDR parameter partition: partition base is returned, and partition size
*   is updated through pointer.
*
*   @param[out]  size  DDR parameter partition size
*
*   @return
*   DDR parameter partition base
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void *ddr_params_get_training_data(uint32 *size)
{
  *size = sizeof(struct ddr_params_partition);

  return (void *)(ddr_shared_data->flash_params.ptr);

} /* ddr_params_get_partition */

/* =============================================================================
**  Function : ddr_params_get_data_buffer
** =============================================================================
*/
/**
*   @brief
*   Get DDR parameter partition: buffer base is returned, and buffer size
*   is updated through pointer.
*
*   @param[out]  size  buffer size
*
*   @return
*   buffer base
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
void *ddr_params_get_data_buffer(uint32 *size, uint8 index)
{
   void* buffer_ptr = NULL;
   if(index == 1)
   {
     *size = ddr_shared_data->buffer_e_size;
     buffer_ptr = (void *)(ddr_shared_data->buffer_e.ptr);
   }
   if(index == 2)
   {
     *size = ddr_shared_data->buffer_i_size;
     buffer_ptr = (void *)(ddr_shared_data->buffer_i.ptr);
   }
   return buffer_ptr;
} /* ddr_params_get_partition */

/* =============================================================================
**  Function : ddr_params_set_training_data
** =============================================================================
*/
/**
*   @brief
*   Set DDR parameter partition.
*
*   @param[in]  base  DDR parameter partition base
*   @param[in]  size  DDR parameter partition size
*
*   @retval  TRUE   Partition set successfully
*   @retval  FALSE  Partition set unsuccessfully
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
boolean ddr_params_set_training_data(void *base, uint32 size)
{
  boolean success = FALSE;

  if ( base != NULL && size == sizeof(struct ddr_params_partition) )
  {
    ddr_shared_data->flash_params.ptr = (struct ddr_params_partition *)base;   
    success = TRUE;
  }
  return success;
}

/* =============================================================================
**  Function : ddr_get_shared_info_details
** =============================================================================
*/
/**
*   @brief
*   Gets the shared info details from detected ddr device params
*
*   @param
*   ddr_details_entry_ptr
*
*   @return
*   status
*
*   @dependencies
*   None
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/


boolean ddr_get_shared_info_details(ddr_details_entry_ptr_type ddr_details_entry_ptr)
{
	  boolean status = TRUE;
	  /* Allocate memory in shared memory region for ddr info table */
	  struct detected_ddr_device_params * detected_param_ptr = NULL;
	  uint8 channel_no=0, channel=1, rank=0;
	  uint8 num_of_ranks;
	  uint8 clk_idx=0;

      ddr_details_entry_ptr->num_channels = ddr_shared_data->num_channel;
	  if(ddr_shared_data->ddr_size_info.ddr_cs1_mb[ddr_details_entry_ptr->num_channels-1]!=0){
		  num_of_ranks = 2;
	  }	  
	  else{
		  num_of_ranks = 1;
	  }

	  detected_param_ptr = ddr_get_detected_params(channel);
          /* fill in the manufacture_id & device_type on to ddr_details_entry_ptr */
	  ddr_details_entry_ptr->manufacturer_id = detected_param_ptr->manufacturer_id;
	  ddr_details_entry_ptr->device_type = detected_param_ptr->device_type; 
	
	  for(channel_no = 0, channel = 1; channel_no < ddr_shared_data->num_channel; channel_no++, channel = channel << 1)
	  {
	    /*Get the detected DDR device params for all channels*/
		detected_param_ptr = ddr_get_detected_params(channel);
		for(rank=0; rank < num_of_ranks; rank++)
		{
			/* Revision ID1 */
			ddr_details_entry_ptr->ddr_params[channel_no].revision_id1[rank] = detected_param_ptr->revision_id_1[rank];
			/* Revision ID2 */
			ddr_details_entry_ptr->ddr_params[channel_no].revision_id2[rank] = detected_param_ptr->revision_id_2[rank];
			/* Width */
			ddr_details_entry_ptr->ddr_params[channel_no].width[rank] = detected_param_ptr->device_io_width[rank];
			/* Density*/
			ddr_details_entry_ptr->ddr_params[channel_no].density[rank] = detected_param_ptr->device_density[rank];	   
		}
	  }

	  
	  /* fill the DDR freq plan for UEFI DDRINFO protocol in UEFI SMEM */
	  /* for SM8250 use 14 instead of MAX_NUM_CLOCK_PLAN_IDX */
	  for(clk_idx = 0;clk_idx < 14;clk_idx++)
	  {
		  ddr_details_entry_ptr->ddr_freq_tbl.ddr_freq[clk_idx].freq_khz = ddr_driver_struct->aop_params->mc_states[clk_idx].freq_khz;
		  ddr_details_entry_ptr->ddr_freq_tbl.ddr_freq[clk_idx].enable   = ddr_driver_struct->aop_params->mc_states[clk_idx].freq_enable;
	  }
	  /* fill the current ddr freq addr to UEFI SMEM */
	  ddr_details_entry_ptr->ddr_freq_tbl.num_ddr_freqs = ddr_shared_data->num_ddr_levels;
	  ddr_details_entry_ptr->ddr_freq_tbl.clk_period_address = (UINT32*)get_clk_period_regaddr();
	  
	  return status;
}

/* ============================================================================
**  Function : ddr_search_nominal_freq
** ============================================================================
*/
/*!
*   @brief
*   Return the max DDR nominal frequency in MC Clock plan table
*
*   @details
*   Return the max DDR nominal frequency in MC Clock plan table, if no nominal 
*   frequency be found, then set the bootup frequency which is below TURBO. 
*
*   @param
*   None
*
*   @par Dependencies
*   this function should be called after training init /training restore
*
*   @par Side Effects
*   None
*
*   @retval  max DDR nominal frequency in KHz
*
*   @sa None
*/

uint32 ddr_search_nominal_freq(void)
{
	uint32 NewLvlIdx = 0, TURBOIdx = 0;
	uint32 FreqKHz = 200000, MaxDDRLevels = 0;
	FREQ_STATE *MCCfg = NULL;

	/* Get MC configure data */
	if (MCCfg == NULL)
	{
		ddr_clock_plan DDRQuery = ddr_clock_query(MC_CLOCK_PLAN);

		/* Spin in while-loop for error if number of DDR levels is not matching */
		MaxDDRLevels = DDRQuery.num_levels;
		MCCfg = DDRQuery.state;
	}

	/* Search the max DDR nominal frequency in MC Clock plan table */
	for (NewLvlIdx = MaxDDRLevels - 1; NewLvlIdx > 0; NewLvlIdx--)
	{
		if (MCCfg[NewLvlIdx].vddcx == TURBO)
		{
			TURBOIdx = NewLvlIdx;
		}
		if (MCCfg[NewLvlIdx].vddcx == NOMINAL)
		{
			if (MCCfg[NewLvlIdx].freq_enable == TRUE)
			{
				FreqKHz = MCCfg[NewLvlIdx].freq_khz;
				break;
			}
		}
	}

	/* If no nominal frequency, set the bootup frequency which is below TURBO */
	if (NewLvlIdx == 0)
	{
		for (NewLvlIdx = TURBOIdx - 1; NewLvlIdx > 0; NewLvlIdx--)
		{
			if (MCCfg[NewLvlIdx].freq_enable == TRUE)
			{
				FreqKHz = MCCfg[NewLvlIdx].freq_khz;
				break;
			}
		}
	}
	return FreqKHz;
} /* ddr_search_nominal_freq */