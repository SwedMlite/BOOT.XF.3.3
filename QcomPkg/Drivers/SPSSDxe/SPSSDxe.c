/** @file SPSSDxe.c

  Implements the Qualcomm's driver that loads SPSS

  Copyright (c) 2019,  Qualcomm Technologies Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when         who     what, where, why
 --------     ---     -----------------------------------------------------------
 06/21/19     as      Add IAR support
 06/18/19     av      Read SECURITY CONTROL CORE register for image type
 06/05/19     av      Initial revision - introduce driver that loads SPSS

=============================================================================*/
#include <Uefi.h>

/**
  EFI interfaces
 */
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/QcomLib.h>
#include <Library/QcomUtilsLib.h>
#include <Library/QcomTargetLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/npa.h>

#include <Protocol/EFIVariableServices.h>
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIChipInfoTypes.h>
#include <Library/MemoryAllocationLib.h>

#include <Library/BaseMemoryLib.h>
#include <PrintShLib.h>
#include <HALhwio.h>
#include "HALbootHWIO.h"

/**
  EFI interfaces
 */

#include <Protocol/LoadedImage.h>
#include <Protocol/EFIPIL.h>

/**
File Logging Dependencies
*/
#include "ULogFront.h"
#include "ULogUEFI.h"

extern EFI_STATUS spss_iar_main(PIL_SUBSYS_CFG_TYPE* spss_cfg);

/*===========================================================================*/
/*                  DEFINES                                                  */
/*===========================================================================*/
#define SPSS_MAX_CHIP_VER       3
#define SWAP_BYTES(x,y)  do {           \
                           UINT8 t;     \
                           t = (x);     \
                           (x) = (y);   \
                           (y) = t;     \
                         }while(0)
#define SPSS_CONFIG_DEV_MASK    0x00000003
#define SPSS_CONFIG_TEST_MASK_1 0x00000001
#define SPSS_CONFIG_TEST_MASK_2 0x00000002

/*===========================================================================*/
/*                  FUNCTIONS PROTOTYPES                                     */
/*===========================================================================*/
STATIC EFI_STATUS SPSSDxe_PreLoadChecks( VOID );
STATIC EFI_STATUS SPSSDxe_BuildLoadCfg( PIL_SUBSYS_CFG_TYPE* spss_cfg );
STATIC EFI_STATUS SPSSDxe_LoadSPSS( PIL_SUBSYS_CFG_TYPE* spss_cfg );
STATIC VOID SPSSDxe_VotePMICResources ( VOID );


/*===========================================================================*/
/*                  FUNCTIONS DEFINITIONS                                    */
/*===========================================================================*/
/**
  SPSSDxe_Entry ()

  @brief
  Initialize SPSS App
 */
EFI_STATUS SPSSDxe_Entry
(
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
)
{
  EFI_STATUS                     Status   = EFI_LOAD_ERROR;
  PIL_SUBSYS_CFG_TYPE            spss_cfg = {};

  /* Ensure loading of SPSS in UEFI is supported */
  Status = SPSSDxe_PreLoadChecks();
  if (Status != EFI_SUCCESS)
  {
    return Status;
  }

  /* Build the load configuration for SPSS based on the chip version
     and device type (test or production) */
  Status = SPSSDxe_BuildLoadCfg(&spss_cfg);
  if (EFI_SUCCESS == Status)
  {
    /* Now trigger PilDXE protocol to load SP subsystem */
    Status = SPSSDxe_LoadSPSS(&spss_cfg);
  }

  return Status;
}

/**
  SPSSDxe_PreLoadChecks ()

  @brief
  Perform pre loading checks in order to decide whether to
  move forward with SPSS loading
 */
STATIC EFI_STATUS SPSSDxe_PreLoadChecks( VOID )
{
  EFI_STATUS             Status               = EFI_LOAD_ERROR;
  EFI_CHIPINFO_PROTOCOL *pEfiChipInfoProtocol = NULL;
  EFIChipInfoIdType      chipID               = EFICHIPINFO_NUM_IDS;

  /* Make sure we load SPSS in UEFI only for Kona */
  Status = gBS->LocateProtocol(&gEfiChipInfoProtocolGuid,NULL, (VOID**) &pEfiChipInfoProtocol);
  if (EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a gEfiChipInfoProtocolGuid protocol failed = %r \r\n", __FUNCTION__, Status ));
    return Status;
  }

  Status = pEfiChipInfoProtocol->GetChipId(pEfiChipInfoProtocol,&chipID);
  if ((chipID >= EFICHIPINFO_NUM_IDS) || (EFI_SUCCESS != Status))
  {
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a GetChipId failed = %r \r\n", __FUNCTION__, Status));
    return EFI_INVALID_PARAMETER;
  }

  if (chipID != EFICHIPINFO_ID_SM8250)
  {
    /* This is not a SM8250... */
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a SPSS loading in UEFI not supported for this chipID = %d \r\n", __FUNCTION__, chipID));
    return EFI_INVALID_PARAMETER;
  }

  return EFI_SUCCESS;
}

/* Convert Byte Stream data to GUID format.
 * For example:
 * if Cfg has data in below format:
 *    DEA0BA2C CBDD 4805 B4F9 F428251C3E98
 *
 * Need to be converted into GUID format (Considering integer and endianness)
 *    DEA0BA2C CBDD 4805 B4F9 F428251C3E98 is equal to stream as follows
 *    2C BA A0 DE DD CB 05 48 B4 F9 F4 28 25 1C 3E 98
 * */
STATIC VOID AdjustGUID (UINT8* Buffer)
{
  /* DWord */
  SWAP_BYTES(Buffer[0], Buffer[3]);
  SWAP_BYTES(Buffer[1], Buffer[2]);

  /* Word */
  SWAP_BYTES(Buffer[4], Buffer[5]);

  /* Word */
  SWAP_BYTES(Buffer[6], Buffer[7]);
}

/**
  SPSSDxe_BuildLoadCfg ()

  @brief
  Build the load configuration for SPSS based on the chip
  version and device type (test or production)
 */
STATIC EFI_STATUS SPSSDxe_BuildLoadCfg( PIL_SUBSYS_CFG_TYPE* spss_cfg )
{
  EFI_STATUS             Status               = EFI_LOAD_ERROR;
  CHAR8                 *PartGuidStr          = "EBD0A0A2 B9E5 4433 87C0 68B6B72699C7";
  CHAR8                 *ImagePathPrefix      = "\\image\\spss";
  CHAR8                 *ImagePath            = NULL;
  UINT32                 ImagePathLength      = AsciiStrLen(ImagePathPrefix) + 2;
  EFI_CHIPINFO_PROTOCOL *pEfiChipInfoProtocol = NULL;
  EFIChipInfoVersionType ChipVer              = (EFIChipInfoVersionType) 0;
  UINT32                 ChipVerMajor         = 0;
  UINT32                 SPSS_Config          = 0; /* So that incase the fuse
                                                      reading fails, we load
                                                      prod images by default */

  /* In order to figure out the SPSS image to be loaded, we need to know:
     1. The Chip Version
     2. Test vs Production device.
     So, lets get that information */
  Status = gBS->LocateProtocol(&gEfiChipInfoProtocolGuid,NULL, (VOID**) &pEfiChipInfoProtocol);
  if (EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a gEfiChipInfoProtocolGuid protocol failed = %r \r\n", __FUNCTION__, Status ));
    return Status;
  }

  Status = pEfiChipInfoProtocol->GetChipVersion(pEfiChipInfoProtocol, &ChipVer);
  if (EFI_SUCCESS != Status)
  {
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a GetChipVersion failed = %r \r\n", __FUNCTION__, Status));
    return Status;
  }

  /* First 2 bytes of ChipVer contain the major Version number... thats all
     we need */
  ChipVerMajor = (0x0000FFFF & (ChipVer >> 16));

  if (ChipVerMajor == 0 || ChipVerMajor > SPSS_MAX_CHIP_VER)
  {
    DEBUG((EFI_D_ERROR,"SPSSDxe:: %a GetChipVersion returned invalid chip ver = %d \r\n", __FUNCTION__, ChipVerMajor));
    return EFI_DEVICE_ERROR;
  }

  /* Read SECURITY CONTROL CORE register to find out SPSS CONFIG MODE,
     (in bits 26 and 27) which is then used to determine whether to
     load test, dev or prod SPSS images to the device:
     SPSS_CONFIG_MODE bits 00: prod
     SPSS_CONFIG_MODE bits 01 or 10: test
     SPSS_CONFIG_MODE bits 11: dev */
  SPSS_Config = HWIO_INF(QFPROM_CORR_FEAT_CONFIG_ROW7_MSB, SPSS_CONFIG_MODE);

  /* We retrieved all the info needed. Now lets create a string representing
     the correct SPSS image path */
  ImagePath = AllocateZeroPool(ImagePathLength);
  if (ImagePath == NULL)
  {
    DEBUG((EFI_D_ERROR, "SPSSDxe:: %a MALLOC error. \r\n", __FUNCTION__));
    return EFI_DEVICE_ERROR;
  }

  ImagePathLength = AsciiStrLen(ImagePathPrefix);
  AsciiStrCpy(ImagePath, ImagePathPrefix);
  if (AsciiStrLen(ImagePath) < ImagePathLength)
  {
    DEBUG((EFI_D_ERROR, "SPSSDxe:: %a Couldn't copy ImagePathPrefix string. \r\n", __FUNCTION__));
    FreePool(ImagePath);
    return EFI_DEVICE_ERROR;
  }

  ImagePathLength += 1;
  switch (ChipVerMajor)
  {
    case 2:
      AsciiStrCat(ImagePath, "2");
      break;
    case 3:
      AsciiStrCat(ImagePath, "3");
      break;
    case 1:
    default:
      AsciiStrCat(ImagePath, "1");
      break;
  }
  if (AsciiStrLen(ImagePath) < ImagePathLength)
  {
    DEBUG((EFI_D_ERROR, "SPSSDxe:: %a Couldn't copy ImagePath version. \r\n", __FUNCTION__));
    FreePool(ImagePath);
    return EFI_DEVICE_ERROR;
  }

  ImagePathLength += 1;
  if ((SPSS_Config & SPSS_CONFIG_DEV_MASK) == SPSS_CONFIG_DEV_MASK)
  {
    AsciiStrCat(ImagePath, "d");
  }
  else if ((SPSS_Config & SPSS_CONFIG_TEST_MASK_1) || (SPSS_Config & SPSS_CONFIG_TEST_MASK_2))
  {
    AsciiStrCat(ImagePath, "t");
  }
  else
  {
    AsciiStrCat(ImagePath, "p");
  }

  if (AsciiStrLen(ImagePath) < ImagePathLength)
  {
    DEBUG((EFI_D_ERROR, "SPSSDxe:: %a Couldn't copy ImagePath string. \r\n", __FUNCTION__));
    FreePool(ImagePath);
    return EFI_DEVICE_ERROR;
  }

  /* Now we have everything needed to create the config. Lets create
     the config */
  spss_cfg->Version = 1;
  spss_cfg->Type = ELF_SPLIT;
  HexStrToBin ((UINT8*)PartGuidStr, AsciiStrLen(PartGuidStr),
               (UINT32*)&(spss_cfg->PartiGuid), sizeof(EFI_GUID));
  AdjustGUID((UINT8*)&(spss_cfg->PartiGuid));
  AsciiStrToUnicodeStr(ImagePath, spss_cfg->ImagePath);
  AsciiStrToUnicodeStr("SPSS", spss_cfg->FwName);
  spss_cfg->SubsysID = 14,
  spss_cfg->ResvRegionStart = 0x8BE00000;
  spss_cfg->ResvRegionSize = 0x100000;
  spss_cfg->ImageLoadInfo = TRUE;
  spss_cfg->OverrideElfAddr = TRUE;

  FreePool(ImagePath);
  return Status;
}

/**
  SPSSDxe_VotePMICResources ()

  @brief
  Vote ON the PMIC resources before loading the SPSS image:
  1. Turn ON ARI LDO
  2. Configure ARI power alarm GPIO
 */
STATIC VOID SPSSDxe_VotePMICResources ( VOID )
{
  npa_client_handle vreg_sp = NULL; /* for PX13 */
  npa_client_handle gpio_a8 = NULL; /* for GPIO8A */

  vreg_sp =  npa_create_sync_client("/pm/vreg.sp/en", "vreg_sp", NPA_CLIENT_REQUIRED);
  gpio_a8 =  npa_create_sync_client("/pm/gpioa8/en", "gpio_a8", NPA_CLIENT_REQUIRED);
  if (vreg_sp != NULL)
  {
    npa_issue_required_request(vreg_sp, 1); /* enable vote */
  }

  if (gpio_a8 != NULL)
  {
    npa_issue_required_request(gpio_a8, 1); /* enable vote */
  }
}

/**
  SPSSDxe_LoadSPSS ()

  @brief
  Trigger loading of SPSS image using PILProtocol
 */
STATIC EFI_STATUS SPSSDxe_LoadSPSS( PIL_SUBSYS_CFG_TYPE* spss_cfg )
{
  EFI_PIL_PROTOCOL  *PILProtocol = NULL;
  EFI_STATUS         Status      = EFI_LOAD_ERROR;

  if (spss_cfg == NULL)
  {
    DEBUG((EFI_D_ERROR, "SPSSDxe:: %a invalid argument. \r\n", __FUNCTION__));
    return EFI_INVALID_PARAMETER;
  }

  Status = gBS->LocateProtocol (&gEfiPilProtocolGuid,NULL, (VOID **) &PILProtocol);
  if ((EFI_SUCCESS != Status) && (NULL == PILProtocol))
  {
    DEBUG(( EFI_D_ERROR, "SPSSDxe:: %a LocateProtocol = %r \r\n", __FUNCTION__, Status));
    return Status;
  }

  /* setup for IAR */
  Status = spss_iar_main(spss_cfg);

  /* Now load the SPSS with the cfg created above */
  Status = PILProtocol->ProcessPilImageExt(spss_cfg);

  if (EFI_SUCCESS == Status)
  {
    /* Vote ON the PMIC resources before loading SPSS */
    SPSSDxe_VotePMICResources();
  }
  else
  {
    DEBUG(( EFI_D_ERROR, "SPSSDxe:: %a ProcessPilImageExt = %r \r\n", __FUNCTION__, Status));
  }

  return Status;
}

