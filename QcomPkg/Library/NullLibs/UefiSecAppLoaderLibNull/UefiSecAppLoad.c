/******************************************************************//**
 * @file UefiSecAppLoad.c
 *
 * @brief UefiSecAppLoaderLib Null functions
 *
 * Copyright (c) 2018 by Qualcomm Technologies, Inc. 
 * All Rights Reserved.
 *
 *********************************************************************/
/*=======================================================================
                        Edit History

when       who     what, where, why
--------   ----    --------------------------------------------------- 
03/08/18   ai      Initial Null checkin
========================================================================*/

#include <Library/UefiSecAppLoaderLib.h>
#include <Library/DebugLib.h>

/**
 * Load UefiSecApp TA 
 */
EFI_STATUS LoadUefiSecApp (VOID)
{
  DEBUG ((EFI_D_INFO, "NULL Lib called: UefiSecAppLoaderLib\n"));
  return EFI_SUCCESS; 
}

