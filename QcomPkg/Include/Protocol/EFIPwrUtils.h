/**
  @file  EFIPwrUtils.h
  @brief PWR UTILS Protocol for UEFI.
*/
/*=============================================================================
  Copyright (c) 2019 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

#ifndef __EFIpwr_utils_H__
#define __EFIpwr_utils_H__

/*===========================================================================
  INCLUDE FILES
===========================================================================*/

/*===========================================================================
  MACRO DECLARATIONS
===========================================================================*/

/** @ingroup efi_pwr_utils_constants
  Protocol version.
*/
#define EFI_PWR_UTILS_PROTOCOL_REVISION 0x0000000000010000
/** @} */ /* end_addtogroup efi_pwr_utils_constants */

/*  Protocol GUID definition */
/** @ingroup efi_pwr_utils_protocol */
#define EFI_PWR_UTILS_PROTOCOL_GUID \
  { 0x3C50E0F7, 0x7D40, 0x4A86, { 0x90, 0x67, 0x11, 0xA2, 0x37, 0x2B, 0xFC, 0x3D } }

/** @cond */
/*===========================================================================
  EXTERNAL VARIABLES
===========================================================================*/
/**
  External reference to the EFI PWR UTILS Protocol GUID.
 */
extern EFI_GUID gEfiPwrUtilsProtocolGuid;
/** @endcond */

/*===========================================================================
  TYPE DEFINITIONS
===========================================================================*/
/** @cond */
typedef struct _EFI_PWR_UTILS_PROTOCOL EFI_PWR_UTILS_PROTOCOL;
/** @endcond */

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
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_LVL_RESOURCE_IDX)(EFI_PWR_UTILS_PROTOCOL *This,
                                           const char   *res_name,
                                           int          *res_ind);

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
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_HLVL)(EFI_PWR_UTILS_PROTOCOL *This,
                                            int resource_idx, 
											int vlvl, 
											int *mapped_vlvl,
											int *hlvl);


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
 
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_HLVL_NAMED_RESOURCE)(EFI_PWR_UTILS_PROTOCOL *This,
                                            const char *resource, 
											int vlvl, 
											int *mapped_vlvl,
											int *hlvl);

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
 
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_RESOURCE_LVLS_COUNT)(EFI_PWR_UTILS_PROTOCOL *This,
                                           int          res_idx,
                                           int          *hlvl_count); 
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
 
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_NAMED_RESOURCE_LVLS_COUNT)(EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
                                           int          *hlvl_count);

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
 
   
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_VLVL)(EFI_PWR_UTILS_PROTOCOL *This,
                                           int          res_idx,
										   int          hlvl,
                                           int          *vlvl); 
 
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
 
  
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_VLVL_NAMED_RESOURCE) (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
										   int                 hlvl,
                                           int                 *vlvl);
 
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
 
typedef EFI_STATUS (EFIAPI* EFI_PWR_UTILS_MOL_RESOURCE_IDX) (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *res_name,
                                           int                 *res_idx); 
 
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
 
typedef EFI_STATUS ( EFIAPI * EFI_PWR_UTILS_MOL_HLVL) (EFI_PWR_UTILS_PROTOCOL *This,
                                           int                 res_id,
                                           int                 *mol_hlvl);
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

typedef EFI_STATUS (EFIAPI * EFI_PWR_UTILS_MOL_HLVL_NAMED_RESOURCE) (EFI_PWR_UTILS_PROTOCOL *This,
                                           const char          *resource,
                                           int                 *mol_hlvl);

/*===========================================================================
  PROTOCOL INTERFACE
===========================================================================*/
/** @ingroup efi_pwr_utils_protocol
  @par Summary
  Pwr utils Driver Protocol interface.

  @par Parameters
  @inputprotoparams{pwr_utils_proto_params.tex}
*/
typedef struct _EFI_PWR_UTILS_PROTOCOL {
  UINT64                                        Revision;
  EFI_PWR_UTILS_LVL_RESOURCE_IDX                LvlResourceIdx;
  EFI_PWR_UTILS_HLVL                            Hlvl;
  EFI_PWR_UTILS_HLVL_NAMED_RESOURCE             HlvlNamedResource;
  EFI_PWR_UTILS_RESOURCE_LVLS_COUNT             ResourceLvlsCount;
  EFI_PWR_UTILS_NAMED_RESOURCE_LVLS_COUNT       NamedResourceLvlsCount;
  EFI_PWR_UTILS_VLVL                            Vlvl;
  EFI_PWR_UTILS_VLVL_NAMED_RESOURCE             VlvlNamedResource;
  EFI_PWR_UTILS_MOL_RESOURCE_IDX                MolResourceIdx;
  EFI_PWR_UTILS_MOL_HLVL                        MolHlvl;
  EFI_PWR_UTILS_MOL_HLVL_NAMED_RESOURCE         MolHlvlNamedResource;
  
}EFI_PWR_UTILS_PROTOCOL;

#endif /* EFIpwr_utils_H */
