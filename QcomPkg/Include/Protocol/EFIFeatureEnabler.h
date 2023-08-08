/** 
  @file  EFIFeatureEnabler.h
  @brief UEFI featuer enabler apps boot loader definitions.
*/
/*=============================================================================
    Copyright (c) 2019 Qualcomm Technologies, Inc.  All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifndef __EFIFEATUREENABLER_H__
#define __EFIFEATUREENABLER_H__

/*===========================================================================
  INCLUDE FILES
===========================================================================*/

/*===========================================================================
  MACRO DECLARATIONS
===========================================================================*/
/** @addtogroup efi_feature_enabler_constants  
@{ */
/**
  Protocol version.
*/
#define FEATURE_ENABLER_REVISION 0x0000000000010001

/**
  Max number of feature enabler modules supported for each chip family
*/
#define FEATURE_ENABLER_MODULE_MAX_NUM       16

/**
  Max length in bytes for the feature enabler module name
*/
#define FEATURE_ENABLER_MODULE_NAME_MAX_LEN       32

/** @} */ /* end_addtogroup efi_feature_enabler_constants */

/*  Protocol GUID definition */
/** @ingroup efi_feature_enabler_protocol */

// {975f5af4-0f78-4eb1-9554-9a676b0b0896}
#define EFI_FEATURE_ENABLER_PROTOCOL_GUID \
    {0x975f5af4, 0x0f78, 0x4eb1, {0x95, 0x54, 0x9a, 0x67, 0x6b, 0x0b, 0x08, 0x96}}


/** @cond */
/*===========================================================================
  EXTERNAL VARIABLES
===========================================================================*/
/**
  External reference to the feature enabler Protocol GUID.
*/
extern EFI_GUID gQcomFeatureEnablerProtocolGuid;

/**
  Protocol declaration.
*/
typedef struct _EFI_QCOM_FEATURE_ENABLER_PROTOCOL  EFI_QCOM_FEATURE_ENABLER_PROTOCOL;


/*===========================================================================
  TYPE DEFINITIONS
===========================================================================*/

/* Feature enabler Status Type */
typedef enum 
{
  FEATURE_ENABLER_STATUS_UNINITIALIZED  = 0x0,  /* feature enabler not initialized */
  FEATURE_ENABLER_STATUS_SUCCESS,               /* feature enabler Status Success */
  FEATURE_ENABLER_STATUS_FAIL                   /* feature enabler Status Fail */
} EFI_FEATURE_ENABLER_STATUS_TYPE;

/* record module name and execution status */
typedef struct
{
  EFI_FEATURE_ENABLER_STATUS_TYPE eStatus;
  CHAR8                           sModuleName[FEATURE_ENABLER_MODULE_NAME_MAX_LEN];
} EFI_FEATURE_ENABLER_MODULE_INFO;

/* This structure record the moudles that support feature enabler */
typedef struct
{
  UINT32                          uNumModules;                           /* Number of valid moudles in sInfo */   
  EFI_FEATURE_ENABLER_MODULE_INFO sInfo[FEATURE_ENABLER_MODULE_MAX_NUM]; /* Valid module table */   
} EFI_FEATURE_ENABLER_STATUS_INFO;


/* This structure record feature enabler status */
typedef struct
{
  EFI_FEATURE_ENABLER_STATUS_TYPE  eTALoadStatus;       /* TA load status */             
  EFI_FEATURE_ENABLER_STATUS_INFO  sTAExeStatus;        /* TA command execution status */
  EFI_FEATURE_ENABLER_STATUS_TYPE  eTAUnloadStatus;     /* TA unload status */
} EFI_FEATURE_ENABLER_STATUS;




/*===========================================================================
  FUNCTION DEFINITIONS
===========================================================================*/


/* EFI_FEATURE_ENABLER_QUERY_STATUS */ 
/** @ingroup efi_feature_enabler_protocol
  @par Summary
  query the TA status
  
  @return
  EFI_SUCCESS              : get TA status successfully

*/
typedef
EFI_STATUS (EFIAPI *EFI_FEATURE_ENABLER_QUERY_STATUS)(
  EFI_FEATURE_ENABLER_STATUS *pStatus
);


/*===========================================================================
  PROTOCOL INTERFACE
===========================================================================*/

/** @ingroup efi_feature_enabler_protocol
  @par Summary
  Qualcomm Feature Enabler Protocol interface.

  @par Parameters
  @inputprotoparams{} 
*/
struct _EFI_QCOM_FEATURE_ENABLER_PROTOCOL
{
  EFI_FEATURE_ENABLER_QUERY_STATUS             FeatureEnablerQueryStatus;
};


#endif  /* __EFIFEATURE_ENABLER_H__ */
