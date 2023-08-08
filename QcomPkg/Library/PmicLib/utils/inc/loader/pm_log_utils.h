#ifndef __PM_LOG_UTILS_H__
#define __PM_LOG_UTILS_H__

/*! \file
 *  
 *  \brief  pm_log_utils.h ----This file contain PMIC wrapper function of DALSYS_Malloc()
 *  \details his file contain PMIC wrapper function of DALSYS_Malloc()
 *  
 *    &copy; Copyright 2012-2019 Qualcomm Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

                EDIT HISTORY FOR MODULE

  This document is created by a code generator, therefore this section will
  not contain comments describing changes made to the module over time.


$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/PmicLib/utils/inc/loader/pm_log_utils.h#4 $
$Author: pwbldsvc $
$DateTime: 2019/10/02 11:27:52 $
when       who     what, where, why
--------   ---     ----------------------------------------------------------
09/13/16   aab     Updated logging message size since this Macro is used to handle all SBL logging 
08/05/16   aab     Created 
===========================================================================*/

/*===========================================================================

                     INCLUDE FILES 

===========================================================================*/
#include <stdio.h>
#include "pm_utils.h"
#include "boot_logger.h"

// defined in pm_utils_loader.c
extern char status_message[];

#define pm_log_message(...)      \
  do {\
    snprintf((status_message+PM_STATUS_MSG_HEAD_LEN), PM_STATUS_MSG_LEN,__VA_ARGS__); \
    LogMsg(status_message); \
  }while(0)

/*===========================================================================

                        FUNCTION PROTOTYPES

===========================================================================*/



#endif // __PM_LOG_UTILS_H__
