/**
  @file TargetResetLib.c
 
  @brief Target Specific Reset Functions
 
  Copyright (c) 2013,2018 by Qualcomm Technologies, Inc. All Rights Reserved.
**/

/*=======================================================================
                        Edit History

when       who     what, where, why
--------   ----    --------------------------------------------------- 
06/17/13   vishalo Initial version
========================================================================*/

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/IoLib.h>

/**
  Target panic
**/
VOID
TargetPanic (VOID)
{
  /* Loop here indefinitely */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfor-loop-analysis"
  for (UINTN Index = 0; Index == 0;);
#pragma clang diagnostic pop
}

