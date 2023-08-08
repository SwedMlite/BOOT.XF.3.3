/**
 * @file XBLSdi.c
 * @brief
 * XBLSdi main control file.
 */
/*=============================================================================
 Copyright 2011-2019 by Qualcomm Technologies, Inc.  All Rights Reserved.
 =============================================================================*/
/*==============================================================================
                                EDIT HISTORY
================================================================================
when       who       what, where, why
--------   ---       -------------------------------------------------------------
01/25/19   ds   Initial version.
================================================================================
                   Copyright 2019 Qualcomm Technologies Incorporated
                              All Rights Reserved
                     Qualcomm Confidential and Proprietary
==============================================================================*/
/*==============================================================================
                                  INCLUDES
==============================================================================*/
#include "boot_extern_debug_interface.h"

boolean (*enter_ddr_refresh)(void) = boot_ddr_enter_self_refresh;
boolean (*exit_ddr_refresh)(void) = boot_ddr_exit_self_refresh;
/*==============================================================================
                                  DEFINITIONS
==============================================================================*/
void XBLSdiMain(uint64 * volatile enter_refresh, uint64 * volatile exit_refresh)
{
  *enter_refresh = (uint64)boot_ddr_enter_self_refresh;
  *exit_refresh = (uint64)boot_ddr_exit_self_refresh;
  
  // if((uint64)(*enter_refresh)==0 || (uint64)(*exit_refresh)==0)
  // {
    // while(1);
  // }
}