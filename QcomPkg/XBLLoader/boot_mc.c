/*=============================================================================

                              Boot Main Control

GENERAL DESCRIPTION
  This file contains the main control functions for SBL execution.

Copyright 2010-2011, 2015 by Qualcomm Technologies Inc.  All Rights Reserved.
=============================================================================*/

/*=============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ------------------------------------------------------------
10/05/15   ck      Corrected copyright
03/21/11   dxiang  In boot_do_procedures(), do not force an error fatal if the 
                   procedures parameter is NULL
07/22/10   aus     Initial creation
=============================================================================*/


/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "LoaderUtils.h"
#include "boot_error_handler.h"
#include "boot_mc.h"
#include "boot_sbl_shared.h"
#include "boot_util.h"
#include "err_reset_detect.h"
#include "boot_logger.h"
#include BOOT_PBL_H

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/

/*=============================================================================
   
                              FUNCTION DEFINITIONS

=============================================================================*/

/*===========================================================================

**  Function :  boot_do_procedures

** ==========================================================================
*/
/*!
* 
* @brief
*    Processes an array of boot procedures.
* 
* @param[in] bl_shared_data Pointer to the shared data passed between functions
* @param[in] procs          Pointer to the function pointer table 
*
* @par Dependencies
*   None
* 
* @retval
*   None
* 
* @par Side Effects
*   None
* 
*/
#define BOOT_FUNCTION_LEN 48
void boot_do_procedures
(
  bl_shared_data_type *bl_shared_data,
  boot_function_table_type *procs
)
{
  boot_function_table_type *cur_proc;
  uint32 func_start_time=0;
  char func_name[BOOT_FUNCTION_LEN];

  BL_VERIFY( bl_shared_data != NULL, BL_ERR_NULL_PTR_PASSED|BL_ERROR_GROUP_BOOT );

  if (procs != NULL)
  {
    for ( cur_proc = procs; (boot_procedure_func_type)cur_proc->func != NULL; cur_proc++ )
    {
      func_start_time = boot_log_get_time();
      ((boot_procedure_func_type)cur_proc->func)( bl_shared_data );
      qsnprintf(func_name, BOOT_FUNCTION_LEN ,"%s", cur_proc->func_name);
      boot_log_delta_time(func_start_time,func_name);
    }
  }
} /* boot_do_procedures() */

