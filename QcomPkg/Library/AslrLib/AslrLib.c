/**
  @file AslrLib.c
 
  @brief ASLR functionality
 
  Copyright (c) 2016,2019 by Qualcomm Technologies, Inc.
  All Rights Reserved.
**/
 
/*=======================================================================
                        Edit History

 when       who     what, where, why
 --------   ----    --------------------------------------------------- 
 02/04/19   md      Fix for if RNG val is 0,  
                    Simplified th logic to return RNG value and
                    Added function to check if using constant RNG value.
 12/08/16   bh      Initial version

========================================================================*/

#include <Library/AslrLib.h>
#include <Library/TzRngLib.h>

BOOLEAN IsStaticRNGUsed()
{
   return ((GetRNGVal() == 0)? TRUE:FALSE);
}

#define STATIC_VAL 0xA5A5
UINTN GetRNumOfBits(UINTN NumOfBits)
{
  STATIC UINTN RNGVal = 0;
#ifdef ENABLE_ASLR 
  UINTN Adjusted;
  UINTN Mask;

  if (RNGVal == 0)
    RNGVal = GetRNGVal();

  Mask = ((0x1 << NumOfBits) - 1);

  if (RNGVal == 0) 
     RNGVal = STATIC_VAL & Mask;
     
  Adjusted = (RNGVal & Mask);
  RNGVal = RNGVal >> NumOfBits;

  return Adjusted;
#else
  return RNGVal;
#endif
}

/* Returns new stack end pointer when ASLR is enabled */
UINTN RandomizeStack(UINTN StackSize)
{
  return (StackSize - (GetRNumOfBits(ASLR_STACK_RNG_BITS) * ASLR_STACK_ALIGN));
}


