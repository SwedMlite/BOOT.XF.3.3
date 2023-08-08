#ifndef __UT_PM_RTC_H__
#define __UT_PM_RTC_H__
/*! \file ut_pm_rtc.h
 *  \n
 *  \brief This file contains functions and variable declarations to support 
 *   the testing RTC driver module.
 *
 *  \n &copy; Copyright (c) 2019 by Qualcomm Technologies Inc.  All Rights Reserved.
 */

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ----------------------------------------------------------
06/18/19   cg      Created RTC API.
===========================================================================*/
/*===========================================================================

                        HEADER FILES

===========================================================================*/
#include "pm_err_flags.h"
#include "com_dtypes.h"

/*===========================================================================

                        TYPE DEFINITIONS 

===========================================================================*/

/*Test API to call the RTC APIs for basic sanity testing*/
pm_err_flag_type rtc_test(void);

#endif // __UT_PM_RTC_H__
