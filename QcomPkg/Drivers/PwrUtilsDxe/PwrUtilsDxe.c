/*============================================================================
  FILE:         PwrUtilsDxe.c

  OVERVIEW:     Implementation of the PwrUtils EFI protocol interface

  DEPENDENCIES: None

                Copyright (c) 2019 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Proprietary and Confidential.
============================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/EFIPwrUtils.h>
#include <Library/pwr_utils_lvl.h>

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/
 
 
 /*----------------------------------------------------------------------------
 * Static Function Declarations
 * -------------------------------------------------------------------------*/
 
/**
 * <!-- pwr_utils_lvl_resource_idx -->
 *
 * @brief Returns the resource index corresponding to input name that
 *        can be used for subsequently for querying hlvls and vlvls.
 *
 * @note This resource index is for power utils lvl functions only. It 
 *       has no relevance outside of it.
 *
 * @param res_name: Resource name e.g. cx.lvl, mx.lvl, etc
 * 
 * @return Resource index (>=0) if successful else -1.
 */
STATIC EFI_STATUS EFI_pwr_utils_lvl_resource_idx(EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *res_name,
                                           int          *res_ind)
{
  if ((This == NULL) || (res_name == NULL) || (res_ind == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *res_ind = pwr_utils_lvl_resource_idx(res_name);

  return EFI_SUCCESS;
}

/**
 * <!-- pwr_utils_hlvl -->
 *
 * @brief This function returns the HW corner (hlvl) that corresponds to 
 *        input SW corner (vlvl) and resource id.
 *
 * @see pwr_utils_lvl_resource_idx
 *
 * @param resource_idx: Resoruce index for which we are querying hlvl usually
 *                      obtained by pwr_utils_lvl_resource_idx.
 * @param vlvl: SW corner level we want to map to hlvl.
 * @param mapped_vlvl: If not NULL and call is successful, it will contain the 
 *                     vlvl used for returning hlvl.
 *                     = vlvl if exact vlvl is supported by the resource.
 *                     > vlvl if round up happened.
 *                     = RAIL_VOLTAGE_LEVEL_OVERLIMIT when 
 *                       vlvl > max_supported_vlvl (error condition)
 *
 * @return HW corner level (>=0) if successful else -1.
 */
STATIC EFI_STATUS EFI_pwr_utils_hlvl(EFI_PWR_UTILS_PROTOCOL *This,
                                            int resource_idx, 
											int vlvl, 
											int *mapped_vlvl,
											int *hlvl)
{
  if ((This == NULL) || (mapped_vlvl == NULL) || (hlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *hlvl = pwr_utils_hlvl(resource_idx, vlvl, mapped_vlvl);

  return EFI_SUCCESS;
}


/**
 * <!-- pwr_utils_hlvl_named_resource -->
 *
 * @brief This function returns the HW corner (hlvl) that corresponds to
 *        input SW corner (vlvl) and resource.
 *
 * @note Unlike @pwr_utils_hlvl, this function has to perform some extra
 *       internal look up each time to obtain HW corner. So if client
 *       expects to query same resource multiple times, he should consider
 *       using pwr_utils_hlvl instead for improved efficiency.
 *
 * @param resource: Resource name for which we are querying hlvl e.g. 
 *                  cx.lvl, mx.lvl.
 * @param vlvl: SW corner we want to map to hlvl.
 * @param mapped_vlvl: If not NULL and call is successful, it will contain the 
 *                     vlvl used for returning hlvl.
 *                     = vlvl if exact vlvl is supported by the resource.
 *                     > vlvl if round up happened.
 *                     = RAIL_VOLTAGE_LEVEL_OVERLIMIT when 
 *                       vlvl > max_supported_vlvl (error condition)
 *
 * @return HW corner level (>=0) if successful else -1.
 */
 
STATIC EFI_STATUS EFI_pwr_utils_hlvl_named_resource(EFI_PWR_UTILS_PROTOCOL *This,
                                            const char *resource, 
											int vlvl, 
											int *mapped_vlvl,
											int *hlvl)
{
  if ((This == NULL) || (resource == NULL) || (mapped_vlvl == NULL) || (hlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *hlvl = pwr_utils_hlvl_named_resource(resource, vlvl, mapped_vlvl);

  return EFI_SUCCESS;
}

 /**
 * <!-- pwr_utils_resource_lvls_count -->
 *
 * @brief This function returns the number of HLVLs supported by the input
 *        resource.
 *
 * @see pwr_utils_lvl_resource_idx
 *
 * @param resource_idx: Resource index for which we are querying number of
 *                      supported hlvls.
 *
 * @return Number of hlvls (>=0) if successful else -1.
 */
 
 STATIC EFI_STATUS EFI_pwr_utils_resource_lvls_count(EFI_PWR_UTILS_PROTOCOL *This,
                                           int          res_idx,
                                           int          *hlvl_count)
{
  if ((This == NULL) || (hlvl_count == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *hlvl_count = pwr_utils_resource_lvls_count(res_idx);

  return EFI_SUCCESS;
}
 
 /**
 * <!-- pwr_utils_named_resource_lvls_count -->
 *
 * @brief This function return the number of HLVLs supported by the input
 *        resource.
 *
 * @see pwr_utils_lvl_resource_idx
 *
 * @note Unlike @pwr_utils_resource_lvls_count, this function has to perform 
 *       some extra internal look up each time to obtain HLVL count. So if
 *       client expects to query same resource multiple times, he should 
 *       consider using pwr_utils_resource_lvls_count instead for improved 
 *       efficiency.
 *
 * @param resource: Resource name for which we are querying hlvl count e.g. 
 *                  cx.lvl, mx.lvl.
 *
 * @return Number of hlvls (>=0) if successful else -1.
 */
 
STATIC EFI_STATUS EFI_pwr_utils_named_resource_lvls_count(EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
                                           int          *hlvl_count)
{
  if ((This == NULL) || (hlvl_count == NULL) || (resource == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *hlvl_count = pwr_utils_named_resource_lvls_count(resource);

  return EFI_SUCCESS;
}

 /**
 * <!-- pwr_utils_vlvl -->
 *
 * @brief This function returns the SW corner (vlvl) corresponding to 
 *        input HW corner (hlvl) and rail id.
 *
 * @see pwr_utils_lvl_resource_idx
 *
 * @param resource_idx: Resource index for which we are querying vlvl,
 *                      usually obtained by pwr_utils_lvl_resource_idx.
 * @param hlvl: HW corner which we want to map to SW corner (vlvl).
 *
 * @return Valid SW corner if successful else < 0
 */
 
   
STATIC EFI_STATUS EFI_pwr_utils_vlvl(EFI_PWR_UTILS_PROTOCOL *This,
                                           int          res_idx,
										   int          hlvl,
                                           int          *vlvl)
{
  if ((This == NULL) || (vlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *vlvl = pwr_utils_vlvl(res_idx, hlvl);

  return EFI_SUCCESS;
}
 
 
 /**
 * <!-- pwr_utils_vlvl_named_resource -->
 *
 * @brief This function returns the SW corner (vlvl) for the input resource
 *        name and HW corner (hlvl).
 *
 * @note Unlike @pwr_utils_vlvl, this function has to perform some extra
 *       internal look up each time to obtain SW corner. So if client
 *       expects to query for same resource multiple times, he should consider
 *       using pwr_utils_vlvl instead for improved efficiency.
 *
 * @param resource: Resource name for which we are querying vlvl e.g. 
 *                  cx.lvl, mx.lvl.
 * @param hlvl: HW corner which we want to map to SW corner (vlvl).
 *
 * @return Valid SW corner if successful else < 0
 */
 
  
STATIC EFI_STATUS EFI_pwr_utils_vlvl_named_resource (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
										   int                 hlvl,
                                           int                 *vlvl)
{
  if ((This == NULL) || (resource == NULL) || (vlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *vlvl = pwr_utils_vlvl_named_resource(resource, hlvl);

  return EFI_SUCCESS;
}
 
 
/**
 * <!-- pwr_utils_mol_resource_idx -->
 *
 * @brief Returns the resource index corresponding to input name that
 *        can be used for subsequently for querying hlvls and vlvls.
 *
 * @note This resource index is for power utils mol functions only. It 
 *       has no relevance outside of it.
 *
 * @param res_name: Resource name e.g. cx.mol, mx.mol, etc
 * 
 * @return Resource index (>=0) if successful else -1.
 */
 
STATIC EFI_STATUS EFI_pwr_utils_mol_resource_idx (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *res_name,
                                           int                 *res_idx)
{
  if ((This == NULL) || (res_name == NULL) || (res_idx == NULL))
  { 
    return EFI_INVALID_PARAMETER;
  }

  *res_idx = pwr_utils_mol_resource_idx(res_name);

  return EFI_SUCCESS;
}
 
 
 
 /**
 * <!-- pwr_utils_mol_hlvl -->
 *
 * @brief This function returns the Minimum operating level(MOL) HW corner(hlvl)  
 *        corresponding to rail id.
 *
 * @see pwr_utils_lvl_resource_idx
 *
 * @param resource_idx: Resource index for which we are querying vlvl,
 *                      usually obtained by pwr_utils_lvl_resource_idx.
 * 
 *
 * @return  HW corner level (>=0) if successful else -1
 */
 
 STATIC EFI_STATUS EFI_pwr_utils_mol_hlvl (EFI_PWR_UTILS_PROTOCOL *This,
                                           int                 res_id,
                                           int                 *mol_hlvl)
{
  if ((This == NULL) || (mol_hlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *mol_hlvl = pwr_utils_mol_hlvl(res_id);

  return EFI_SUCCESS;
}
 
/**
 * <!-- pwr_utils_mol_hlvl_named_resource -->
 *
 * @brief This function returns the Minimum operating level(MOL) HW corner(hlvl)  
 *        corresponding to rail id.
 *
 * @note Unlike @pwr_utils_mol_hlvl, this function has to perform some extra
 *       internal look up each time to obtain SW corner. So if client
 *       expects to query for same resource multiple times, he should consider
 *       using pwr_utils_mol_hlvl instead for improved efficiency.
 *
 * @param resource: Resource name for which we are querying MOL hlvl e.g. 
 *                  cx.mol, mx.mol.
 *
 * @return HW corner level (>=0) if successful else -1
*/

STATIC EFI_STATUS EFI_pwr_utils_mol_hlvl_named_resource (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
                                           int                 *mol_hlvl)
{
  if ((This == NULL) || (resource == NULL) || (mol_hlvl == NULL))
  {
    return EFI_INVALID_PARAMETER;
  }

  *mol_hlvl = pwr_utils_mol_hlvl_named_resource(resource);

  return EFI_SUCCESS;
}
/*----------------------------------------------------------------------------
 * Global Data Definitions
 * -------------------------------------------------------------------------*/
STATIC EFI_HANDLE  gProtocolHandle = NULL;

/*----------------------------------------------------------------------------
 * Static Variable Definitions
 * -------------------------------------------------------------------------*/
static EFI_PWR_UTILS_PROTOCOL PwrUtilsProtocol =
{
  EFI_PWR_UTILS_PROTOCOL_REVISION,
  EFI_pwr_utils_lvl_resource_idx,
  EFI_pwr_utils_hlvl,
  EFI_pwr_utils_hlvl_named_resource,
  EFI_pwr_utils_resource_lvls_count,
  EFI_pwr_utils_named_resource_lvls_count,
  EFI_pwr_utils_vlvl,
  EFI_pwr_utils_vlvl_named_resource,
  EFI_pwr_utils_mol_resource_idx,
  EFI_pwr_utils_mol_hlvl,
  EFI_pwr_utils_mol_hlvl_named_resource,
};

/*----------------------------------------------------------------------------
 * Static Function Declarations and Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Externalized Function Definitions
 * -------------------------------------------------------------------------*/
EFI_STATUS
EFIAPI
PwrUtilsEntryPoint(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
   EFI_STATUS efiStatus = EFI_SUCCESS;

   pwr_utils_lvl_init();

   efiStatus = gBS->InstallMultipleProtocolInterfaces(
                    &gProtocolHandle,
                    &gEfiPwrUtilsProtocolGuid,(void **)&PwrUtilsProtocol,
                    NULL );

   return efiStatus;
}

