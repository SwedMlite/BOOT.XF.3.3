/*
==============================================================================

FILE:         TLMMBSP.c

DESCRIPTION:
  This file contains the TLMM driver hardware BSP data.


==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/NullLibs/TLMMTargetLibNull/TLMMBSP.c#1 $

==============================================================================
            Copyright (c) 2017 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "GPIOTypes.h"

/*=========================================================================
      Externs
==========================================================================*/


/*=========================================================================
      Data Declarations
==========================================================================*/

HALgpioBlockDescType GPIOBlockDescriptors[] =
{
  {
    GPIO_DEVICE_TLMM,
    0,
    0x1000,
    0,
    {
      0,
      0,
      0,
      0,
      0
    },
    0,
    0,
    GPIO_HW_VERSION(0xFF, 0xFF, 0xFF, 0xFF),
  },  
};

uint32 gnNumBlockDescs = 1;

