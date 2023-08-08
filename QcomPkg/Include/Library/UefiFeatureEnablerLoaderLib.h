/******************************************************************//**
 * @file UefiFeatureEnablerLoaderLib.h
 *
 * @brief UefiSecAppLoaderLib functions
 *
 * Copyright (c) 2019 by Qualcomm Technologies, Inc. 
 * All Rights Reserved.
 *
 *********************************************************************/
/*=======================================================================
                        Edit History

when       who     what, where, why
--------   ----    --------------------------------------------------- 
03/07/19   zwy     Initial
========================================================================*/
#ifndef __UEFIFEATUREENABLER_LOADER_LIB_H__
#define __UEFIFEATUREENABLER_LOADER_LIB_H__

#include <Uefi.h>



/**********************************************************************************************************************
 *   Structures
 **/

/* This structure record FeatureEnabler context, and will be passed down to sub-modules to use */
typedef struct
{
  UINT32                 uFeatenableAppId;
  BOOLEAN                bTaLoaded;
} FeatureEnablerContextType;


/**********************************************************************************************************************
 *   Function Prototypes.
 **/

/**
FeatureEnablerLoadTA

Load  TA which named through FEATENABLER_TA_NAME or GUID

@param  pFeatureEnablerContext     Pointer to context which passed from upped level

@retval EFI_SUCCESS      Protocol registered
@retval EFI_NOT_FOUND    Fail to load the QseeComProtocol

**/
EFI_STATUS FeatureEnablerLoadTA (FeatureEnablerContextType *pFeatureEnablerContext);

#endif //__UEFIFEATUREENABLER_LOADER_LIB_H__

