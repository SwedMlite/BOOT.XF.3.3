/** @file StorageProfileStub.c

  Stub Implementation of Storage Profile Library

  Copyright (c) 2016, 2019 Qualcomm Technologies Inc. 
  All rights reserved. 
  Qualcomm Confidential and Proprietary.

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 04/30/19   sa      Changed the header file.
 08/30/16   bb      Initial version

=============================================================================*/

#include "StorageCommon.h"

/*
 * Get the start time
 */
void StorageProfileStart (void)
{
}

/*
 * End the profile event
 */
void StorageProfileEnd (UINT32 opMask, char *op, UINT64 address, UINT32 size)
{
  (void) opMask;
  (void) op;
  (void) address;
  (void) size;
}
