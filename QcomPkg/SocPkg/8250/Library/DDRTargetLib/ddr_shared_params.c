/**
 * @file ddr_shared_params.c
 * @brief
 * DDR related shared data between BOOT and AOP
 */
/*==============================================================================
                                EDIT HISTORY

================================================================================
when       who     what, where, why
--------   ---     -------------------------------------------------------------
06/04/18   daisond PASR table share with AOP
05/24/17   rp      Initial version
================================================================================
                   Copyright 2014-2018 Qualcomm Technologies Incorporated
                              All Rights Reserved
                     Qualcomm Confidential and Proprietary
==============================================================================*/
/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include "ddr_drivers.h"
#include "ddr_params.h"
#include "HAL_SNS_DDR.h"
#include "CoreVerify.h"
#include "ddr_shared_params.h"
#include "boot_util.h"
#include "smem.h"
#include "CoreMsgRam.h"


/*==============================================================================
                                  MACROS
==============================================================================*/


/*==============================================================================
                                  DATA
==============================================================================*/


/*==============================================================================
                                  FUNCTIONS
==============================================================================*/

/* ============================================================================
**  Function : ddr_clock_query
** ============================================================================
*/
/*!
*   @brief
*   This function is called by clock driver to query ddr clock info
*
*   @details
*   Clock driver queries DDR driver to get all the MC and SHUB clock plan related info
*
*   @param
*   ddr_clock_query_type
*
*   @par Dependencies
*   Needs to be called after HAL_DDR_Init once DCB is parsed
*
*   @par Side Effects
*   None
*
*   @retval  struct ddr_clock_plan
*
*   @sa None
*/
ddr_clock_plan ddr_clock_query(ddr_clock_query_type query)
{
	ddr_clock_plan mc_shub_plan;
	switch (query)
	{
		case MC_CLOCK_PLAN:
			mc_shub_plan.num_levels = ddr_shared_data->num_ddr_levels;
			mc_shub_plan.state = &ddr_driver_struct->aop_params->mc_states[0];
			break;
		
		case SHUB_CLOCK_PLAN:
			mc_shub_plan.num_levels = ddr_shared_data->num_shub_levels;
			mc_shub_plan.state =  &ddr_driver_struct->aop_params->shub_states[0];
			break;
			
		default:
			mc_shub_plan.num_levels = 0;
			mc_shub_plan.state = NULL;
	}
	return mc_shub_plan;
} /* ddr_clock_query */

/* ============================================================================
**  Function : ddr_clock_query_vddq_plan
** ============================================================================
*/
/*!
*   @brief
*   This function is called by clock driver to get vddq clock plan information
*
*   @details
*   Clock driver queries DDR driver to get vddq clock plan information
*
*   @param
*   ddr_clock_query_type
*
*   @par Side Effects
*   None
*
*   @retval  struct vddq_clock_plan
*
*   @sa None
*/
ddr_vddq_plan ddr_clock_query_vddq_plan(ddr_clock_query_type query)
{
	ddr_vddq_plan vddq_clock_plan;
	switch (query)
	{
		case VDDQ_CLOCK_PLAN:
			vddq_clock_plan.num_levels = ddr_shared_data->num_ddr_levels;
			vddq_clock_plan.vddq_state = &ddr_driver_struct->vddq_plan[0];
			break;
			
		default:
			vddq_clock_plan.num_levels = 0;
			vddq_clock_plan.vddq_state = NULL;
	}
	return vddq_clock_plan;
} /* ddr_clock_query_vddq_plan */

/* ============================================================================
**  Function : ddr_share_data_to_aop
** ============================================================================
*/
/*!
*   @brief
*   This function is called to copy all the ddr related info required by AOP
*
*   @details
*   All the DDR related information required by AOP during runtime is copied 
*   into SMEM in this function
*
*   @param
*   None
*
*   @par Dependencies
*   SMEM should have been initialized before calling this function
*
*   @par Side Effects
*   None
*
*   @retval  None
*
*   @sa None
*/
void ddr_share_data_to_aop(void)
{
  void *smem_ptr = smem_alloc(DDR_AOP_SMEM_ID, sizeof(DDR_AOP_PARAMS));
  CORE_VERIFY(smem_ptr != NULL); 
  
  /* Store smem address in AOP msg_ram */
  msg_ram_set_smem_address((uint32)DDR_AOP_SMEM_ID, (uint32)smem_ptr);
  
  HAL_CORE_SW_Set_PASR_DDR_INFO_TABLE(ddr_shared_data);
  
  qmemscpy(smem_ptr, sizeof(DDR_AOP_PARAMS), ddr_shared_data->ddr_aop_params.ptr, sizeof(DDR_AOP_PARAMS));
  
} /* ddr_share_data_to_aop */