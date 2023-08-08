/**
  @file  EFIVcs.h
  @brief VCS Protocol for UEFI.
*/
/*=============================================================================
  Copyright (c) 2019-2022 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/06/19   ra      Created.

=============================================================================*/
#ifndef __EFIVCS_H__
#define __EFIVCS_H__

/*===========================================================================
  MACRO DECLARATIONS
===========================================================================*/
/**
  Protocol version.
*/
#define EFI_VCS_PROTOCOL_VERSION 0x0000000000010006  

/*===========================================================================
  EXTERNAL VARIABLES
===========================================================================*/
/**
  External reference to the VCS Protocol GUID.
*/
extern EFI_GUID gEfiVcsProtocolGuid;

/*===========================================================================
  TYPE DEFINITIONS
===========================================================================*/
/**
  Protocol declaration.
*/
typedef struct _EFI_VCS_PROTOCOL EFI_VCS_PROTOCOL;


/*===========================================================================
  FUNCTION DEFINITIONS
===========================================================================*/

/** EFI_VCS_GET_BOOT_CORNER 
 This API is gets the boot corner for the voltage rails.

  @par Description
    @param  This      [in]  The EFI_VCS_PROTOCOL instance.
    @param szName     [in]  Pointer to the voltage rail name
	@param pLevel     [out] Pointer to the voltage level 
 
  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

typedef
EFI_STATUS
(EFIAPI *EFI_VCS_GET_BOOT_CORNER)(
  IN  EFI_VCS_PROTOCOL *This,
  IN  CONST CHAR8 *szName,
  OUT UINT32   *pLevel
);

/*===========================================================================
  PROTOCOL INTERFACE
===========================================================================*/
/*  VCS Protocol interface.
*/
struct _EFI_VCS_PROTOCOL {
   UINT64                           Version;
   EFI_VCS_GET_BOOT_CORNER          GetBootCorner;
};


#endif  /* __EFIVCS_H__ */
