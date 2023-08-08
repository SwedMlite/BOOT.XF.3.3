/*==============================================================================

FILE:      Busywait.c

DESCRIPTION: This file implements the busywait routine using Qtimer registers. 

===========================================================================
             Copyright (c) 2014 QUALCOMM Technologies, Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
===========================================================================

                              EDIT HISTORY

 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 11/14/14  pbitra   Created.
=============================================================================*/
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>


/*===========================================================================

                           DATA DEFINITIONS

============================================================================*/



/*==========================================================================

  FUNCTION      busywait
==========================================================================*/
void busywait
(
  UINT32 pause_time_us
)
{
  gBS->Stall(pause_time_us);
} /* END busywait */
