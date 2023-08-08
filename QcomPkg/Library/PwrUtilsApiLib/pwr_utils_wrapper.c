/** @file pwr_utils_wrapper.c

  Map Pwr Utils API in common code to PWR UTILS DXE interface

  Copyright (c) 2019, Qualcomm Technologies Inc. All rights
  reserved.

**/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/EFIPwrUtils.h>

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
int pwr_utils_lvl_resource_idx (const char *res_name)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->LvlResourceIdx(pwr_utils_protocol,
                                   res_name,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_hlvl (int resource_idx, int vlvl, int *mapped_vlvl)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int hlvl = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->Hlvl(pwr_utils_protocol,
                                   resource_idx,
								   vlvl,
								   mapped_vlvl,
                                   &hlvl);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return hlvl;
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
int pwr_utils_hlvl_named_resource 
(
  const char *resource, 
  int vlvl, 
  int *mapped_vlvl
)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->HlvlNamedResource(pwr_utils_protocol,
                                   resource,
								   vlvl,
								   mapped_vlvl,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
  
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
int pwr_utils_resource_lvls_count (int resource_idx)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->ResourceLvlsCount(pwr_utils_protocol,
                                   resource_idx,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_named_resource_lvls_count (const char *resource)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->NamedResourceLvlsCount(pwr_utils_protocol,
                                   resource,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_vlvl (int resource_idx, int hlvl)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->Vlvl(pwr_utils_protocol,
                                   resource_idx,
								   hlvl,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_vlvl_named_resource (const char *resource, int hlvl)
{
	
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->VlvlNamedResource( pwr_utils_protocol,
                                   resource,
								   hlvl,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_mol_resource_idx (const char *res_name)
{
	
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->MolResourceIdx( pwr_utils_protocol,
                                   res_name,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
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
int pwr_utils_mol_hlvl (int resource)
{
	
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int mol_hlvl = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->MolHlvl( pwr_utils_protocol,
                                   resource,
                                   &mol_hlvl);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return mol_hlvl;
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
int pwr_utils_mol_hlvl_named_resource (const char *resource)
{
  EFI_PWR_UTILS_PROTOCOL * pwr_utils_protocol;
  int res_idx = 0;
  EFI_STATUS status;

  status = gBS->LocateProtocol(&gEfiPwrUtilsProtocolGuid, NULL, (void**)&pwr_utils_protocol);
  if(status == EFI_SUCCESS)
  {
      pwr_utils_protocol->MolHlvlNamedResource( pwr_utils_protocol,
                                   resource,
                                   &res_idx);
  }
  else
  {
      DEBUG ((EFI_D_ERROR, "Locate pwr_utils_protocol failed:%r\n", status));
  }
  return res_idx;
}

