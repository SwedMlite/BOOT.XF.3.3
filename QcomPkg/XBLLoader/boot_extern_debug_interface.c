/*===========================================================================

                    BOOT EXTERN DEBUG DRIVER DEFINITIONS

DESCRIPTION
  Contains wrapper definition for external ddr drivers used for Debug/SDI
  image functionality

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
#  Copyright (c) 2015-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
#  Qualcomm Technologies Proprietary and Confidential.
============================================================================*/
/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.
    
    
when       who     what, where, why
--------   ---     ----------------------------------------------------------
06/12/17   rp      Updated boot_ddr_enter_self_refresh return type
04/25/17   kpa     Update boot_ddr_exit_self_refresh return type
03/16/16   kpa     Updates to jump back to Qsee from EL1 to EL3 via smc call
02/12/15   kpa     Initial Creation.
=============================================================================*/

/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "boot_extern_debug_interface.h"
#include "ddr_sdi_wrapper.h"
#include "boot_fastcall_tz.h"
#include "boot_sbl_shared.h"


/* =============================================================================
**  Function : boot_ddr_enter_self_refresh
** =============================================================================
*/
/**
*   @brief
*   Enter DDR Self Refresh.
*
*   @param  None
*
*   @retval  TRUE if success, else FALSE.
*
*   @dependencies
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
boolean boot_ddr_enter_self_refresh(void)
{
  boolean status = FALSE;
  status = ddr_sdi_exit();
  return status;
}

/* =============================================================================
**  Function : boot_ddr_exit_self_refresh
** =============================================================================
*/
/**
*   @brief
*   Enter DDR Self Refresh.
*
*   @param  None
*
*   @retval  TRUE if success, else FALSE.
*
*   @dependencies
*
*   @sideeffects
*   None
*
*   @sa
*   None
*/
boolean boot_ddr_exit_self_refresh(void)
{
  boolean status = FALSE;
  status = ddr_sdi_init();
  return status;
}
