/** @file EudLib.c

  Module to implement helper functions for EUD Enable/Disable/Read
*
*/
/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 08/14/19   aj      Check-in
 07/18/19   dt      Created.
=============================================================================*/

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiCfgLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UncachedMemoryAllocationLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/QcomLib.h>
#include <Library/HobLib.h>
#include <Library/UefiLib.h>
#include <Library/EudLib.h>
#include <Protocol/EFIScm.h>
#include  <Library/DBIDump.h>
#include <Include/scm_sip_interface.h>
#include <Library/CookieLib.h>
#include <Library/BootConfig.h>

#define ENABLE 0x1
#define DISABLE 0x0


EFI_STATUS
Eud_Enable(VOID)
{ 
  QCOM_SCM_PROTOCOL                 *pQcomScmProtocol                  = NULL;
  EFI_STATUS                        Status                             = EFI_SUCCESS;
  UINTN                            Parameters[SCM_MAX_NUM_PARAMETERS] = {0, ENABLE};
  UINTN                            Results[SCM_MAX_NUM_RESULTS]       = {0};
  UINT32                            VarData;

  VarData = 0;
  Status = GetConfigValue("EUDEnableAddr", &VarData);
  if(EFI_ERROR(Status)) 
  {
    DEBUG((EFI_D_INFO, " Locate EUDEnableAddr failed for EUD Enable, Status =  (0x%x)\r\n", Status));
    return Status;
  }
  
  Parameters[0] = VarData;

  // Locate QCOM_SCM_PROTOCOL. 
  Status = gBS->LocateProtocol ( &gQcomScmProtocolGuid, 
                                 NULL, 
                                 (VOID **)&pQcomScmProtocol
                               );
  if(EFI_ERROR(Status)) 
  {
    DEBUG((EFI_D_INFO, " Locate SCM Protocol failed for EUD Enable, Status =  (0x%x)\r\n", Status));
    return Status;
  }

  // make a SCM Sys call 
  Status = pQcomScmProtocol->ScmSipSysCall (pQcomScmProtocol,
                                            TZ_IO_ACCESS_WRITE_ID,
                                            TZ_IO_ACCESS_WRITE_ID_PARAM_ID,
                                            Parameters,
                                            Results
                                            );
  if (EFI_ERROR (Status)) 
  {
    DEBUG((EFI_D_ERROR, "ScmSipSysCall() failed for EUD Enable, Status = (0x%x)\r\n", Status));
    return Status;
  }
  if (Results[0] != 1)
  {    
    Status = EFI_DEVICE_ERROR;
    DEBUG((EFI_D_ERROR, "IO_ACCESS_WRITE failed, Status = (0x%x)\r\n", Results[0]));
    return Status;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Eud_Disable(VOID)
{ 
  QCOM_SCM_PROTOCOL                 *pQcomScmProtocol                  = NULL;
  EFI_STATUS                        Status                             = EFI_SUCCESS;
  UINTN                            Parameters[SCM_MAX_NUM_PARAMETERS] = {0, DISABLE};
  UINTN                            Results[SCM_MAX_NUM_RESULTS]       = {0};
  UINT32                            VarData;

  VarData = 0;
  Status = GetConfigValue("EUDEnableAddr", &VarData);
  if(EFI_ERROR(Status)) 
  {
    DEBUG((EFI_D_INFO, " Locate EUDEnableAddr failed for EUD Disable, Status =  (0x%x)\r\n", Status));
    return Status;
  }
  
  Parameters[0] = VarData;

  // Locate QCOM_SCM_PROTOCOL. 
  Status = gBS->LocateProtocol ( &gQcomScmProtocolGuid, 
                                 NULL, 
                                 (VOID **)&pQcomScmProtocol
                               );
  if(EFI_ERROR(Status)) 
  {
    DEBUG((EFI_D_INFO, " Locate SCM Protocol failed for EUD Disable, Status =  (0x%x)\r\n", Status));
    return Status;
  }

  // make a SCM Sys call 
  Status = pQcomScmProtocol->ScmSipSysCall (pQcomScmProtocol,
                                            TZ_IO_ACCESS_WRITE_ID,
                                            TZ_IO_ACCESS_WRITE_ID_PARAM_ID,
                                            Parameters,
                                            Results
                                            );
  if (EFI_ERROR (Status)) 
  {
    DEBUG((EFI_D_ERROR, "ScmSipSysCall() failed for EUD Disable, Status = (0x%x)\r\n", Status));
    return Status;
  }
  if (Results[0] != 1)
  {    
    Status = EFI_DEVICE_ERROR;
    DEBUG((EFI_D_ERROR, "IO_ACCESS_WRITE failed, Status = (0x%x)\r\n", Results[0]));
    return Status;
  }

  return EFI_SUCCESS;
}

EFI_STATUS Eud_Read(UINTN *enabled)
{ 
  UINTN  *reg = 0;
  UINT32 EUDRegAddr;
  EFI_STATUS Status = EFI_SUCCESS; 


  EUDRegAddr = 0;
  Status = GetConfigValue("EUDEnableAddr", &EUDRegAddr);
  if(EFI_ERROR(Status)) 
  {
    DEBUG((EFI_D_INFO, " Locate EUDEnableAddr failed for EUD Enable, Status =  (0x%x)\r\n", Status));
    return Status;
  }
  
  reg = (UINTN *)(UINTN)(EUDRegAddr);

  *enabled = (*reg) & 0x1;

  return EFI_SUCCESS;
}
