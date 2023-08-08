/*============================================================================
  FILE:         ddr_temperature.c

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
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/

#include "ddr_temperature.h"


/*----------------------------------------------------------------------------
 * Externalized Function Definitions
 * -------------------------------------------------------------------------*/
/* ============================================================================
**
**  get_ddr_temperature
**
**  Description:
**    Get the DDR temperature.
**
**  Parameters:
**    None
**
**  Return:
**    TRUE  - Temperature retrieved successfully
**    FALSE - Temperature API failed to retrieve temperature
**
**  Dependencies:
**    None
**
** ========================================================================= */
boolean get_ddr_temperature(uint32 *tempDegC)
{
   uint32 uLoopCount = 0;
   uint32 ddr_sensor_no = 19;
   TsensResultType tsensResult;
   int32 nDeciDegC;

   for ( ; uLoopCount<10; uLoopCount++)
   {
      tsensResult = Tsens_GetTemp(ddr_sensor_no, &nDeciDegC);      
   }
   if (tsensResult == TSENS_SUCCESS)
   {
         *tempDegC = nDeciDegC;
		 return TRUE;
   }
   else
   {
	   return FALSE;
   }
  
}

