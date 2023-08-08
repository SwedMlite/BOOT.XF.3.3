#ifndef BOOT_SHARED_FUNCTIONS_PRODUCER_H
#define BOOT_SHARED_FUNCTIONS_PRODUCER_H

/*===========================================================================

                                Boot Shared Functions Producer
                                Header File

GENERAL DESCRIPTION
  This header file contains declarations and definitions for Boot's shared 
  functions (Producer). 

Copyright  2014, 2019 by QUALCOMM Technologies Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

when       who          what, where, why
--------   --------     ------------------------------------------------------
01/22/19   yps          Added api to qurey shared function table address
07/14/14   ck           Initial creation
============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "boot_shared_functions.h"


/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/
void boot_shared_functions_register(void);
boot_shared_functions_type * boot_get_shared_function_table(void);

#endif /* BOOT_SHARED_FUNCTIONS_PRODUCER_H */


