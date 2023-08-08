/******************************************************************//**
 * @file UefiSecAppLoaderLib.h
 *
 * @brief UefiSecAppLoaderLib functions
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
#ifndef __UEFISECAPP_LOADER_LIB_H__
#define __UEFISECAPP_LOADER_LIB_H__

#include <Uefi.h>
/**
 * Load UefiSecApp TA 
 */
EFI_STATUS LoadUefiSecApp (VOID);

#endif //__UEFISECAPP_LOADER_LIB_H__

