/*
==============================================================================

FILE:         TLMMBSP.c

DESCRIPTION:
  This file contains the TLMM driver hardware BSP data.


==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/TLMMTargetLib/TLMMBSP.c#4 $

==============================================================================
            Copyright (c) 2017 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "msmhwiobase.h"
#include "GPIOTypes.h"
#include "HALtlmm.h"

/*=========================================================================
      Externs
==========================================================================*/

extern HAL_tlmm_GpioCoreControlType HAL_gpio_CoreControl;
extern HAL_tlmm_GpioExtControlType HAL_gpio_ExtControl;

/*=========================================================================
      Data Declarations
==========================================================================*/

HALgpioBlockDescType GPIOBlockDescriptors[] =
{
  {
    GPIO_DEVICE_TLMM,
    0,
    0x1000,
    3,
    {
      0xF100000,
      0xF500000	,
      0xF900000,
      0,
      0
    },
    0,
    179,
    GPIO_HW_VERSION(1, 0, 0xFF, 0xFF),
    &HAL_gpio_CoreControl,
    &HAL_gpio_ExtControl
  },  
};

uint32 gnNumBlockDescs = 1;

uint32 nHWRevisionAddr = (CORE_TOP_CSR_BASE + 0xC8000);
