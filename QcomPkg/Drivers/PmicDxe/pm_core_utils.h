#ifndef __PMCOREUTILS_H__
#define __PMCOREUTILS_H__

/*! @file pm_core_utils.h
 *
 *  This file contains functions and variable declarations for utils 
 *  
 *  Copyright (c) 2015-2018 Qualcomm Technologies, Inc.  All Rights Reserved. 
 *  Qualcomm Technologies Proprietary and Confidential.
 */

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
11/22/15   va      New file.
===========================================================================*/
/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
  
#include <Library/QcomBaseLib.h>
#include <Library/UefiLib.h>
#include <../../Library/PmicLib/utils/inc/pm_utils.h>
#include "pm_err_flags.h"


/*===========================================================================
                     MACRO DEFINATIONS
===========================================================================*/

/*===========================================================================
                     TYPE DECLARATIONS
===========================================================================*/


/*===========================================================================
                       FUNCTION PROTOTYPES
===========================================================================*/

/* Protocol GUID definition */
/** @ingroup efi_pmicGenericprotocol */

typedef 
EFI_STATUS (EFIAPI *EFI_PM_EXIT_CLEANUP) (
   void
);

typedef
struct _EFI_QCOM_PMIC_GENERIC_PROTOCOL {
  UINT64                                  Revision;
  EFI_PM_EXIT_CLEANUP                     PmExitCleanup;
}EFI_QCOM_PMIC_GENERIC_PROTOCOL;

pm_err_flag_type pm_core_utils_dump_peripheral(UINT8 slave_id, UINT32 PherStartAddr, UINT8 NumOfPeripheral);

#endif // __PMICBATTERYPARAMETER_H__

