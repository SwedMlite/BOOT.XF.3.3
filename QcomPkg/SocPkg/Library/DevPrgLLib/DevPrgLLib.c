/** @file DeviceProgrammerLiteLib.c
  
  Stub functions for DeviceProgrammerLiteLib

  Copyright (c) 2014-2016,2019 Qualcomm Technologies, Inc. All rights reserved. 
**/

/*=============================================================================
                              EDIT HISTORY


when       who      what, where, why
--------   ---      -----------------------------------------------------------
12/05/16   sb        Make an SCM call to unlock the TZ region in OCIMEM
10/22/15   plc       Replaced tlb invalidate with el-agnostic mmu_invalidate_tlb
12/02/14   wkimberl  Initial revision.


=============================================================================*/
#include "boot_sbl_if.h"
#include "deviceprogrammer_initialize.h"

/*!
 * Stub for boot_hand_control_to_deviceprogrammer_lite_main
 *
 * @param bl_shared_data
 *    The shared bootloader information.
 *
*****************************************************************************/
void
boot_hand_control_to_deviceprogrammer_lite_main (boot_pbl_shared_data_type *pbl_shared_data)
{
  deviceprogrammer_entry(pbl_shared_data);
}
