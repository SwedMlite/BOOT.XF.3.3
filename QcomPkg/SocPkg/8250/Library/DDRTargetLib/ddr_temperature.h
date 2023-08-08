/*============================================================================
  FILE:         ddr_temperature.h

  OVERVIEW:     Implementation of temperature of DDR

  DEPENDENCIES: None

                Copyright (c) 2018 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary.
============================================================================*/
/*============================================================================
  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.  Please
  use ISO format for dates.

  when        who     what, where, why
  ----------  ---     -----------------------------------------------------------
  2018-03-08  daisond Get DDR temperature

============================================================================*/
#ifndef __DDR_TEMPERATURE_H__
#define __DDR_TEMPERATURE_H__
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/

#include "TsensLib.h"


/*----------------------------------------------------------------------------
 * Externalized Function Definitions
 * -------------------------------------------------------------------------*/
/* ============================================================================
**
**  BootTempCheck
**
**  Description:
**    Checks the TSENS boot temperature.
**
**  Parameters:
**    None
**
**  Return:
**    BootTempCheckStatusType
**
**  Dependencies:
**    None
**
** ========================================================================= */
boolean get_ddr_temperature(uint32 *tempDegC);

#endif