/*=============================================================================

  File: MDPPlatformLibPanelCommon.c

  MDP default platform panel functions

  Copyright (c) 2018 - 2019 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/EFIPmicGpio.h>
#include <Protocol/EFIPmicClkBuff.h>
#include <Protocol/EFITlmm.h>
#include <Protocol/EFIPmicLpg.h>
#include <Protocol/EFIPmicGpio.h>
#include <Protocol/EFIPmicVreg.h>
#include <Protocol/EFIPmicWled.h>
#include <Protocol/EFIPmicIbb.h>
#include <Protocol/EFIPmicLab.h>
#include <Protocol/EFIPmicAb.h>
#include <Protocol/EFIPmicLcdb.h>
#include <Protocol/EFIPmicVersion.h>
#include "DDIChipInfo.h"
#include "MDPSystem.h"
#include "MDPPeripherals.h"
#include "MDPPlatformLibPanelCommon.h"
#include "DisplayUtils.h"
#include "pmapp_npa.h"
#include "DDITlmm.h"
#include "HALDSILib.h"
#include "api/pmic/pm/pm_version.h"

/* MDP supported panel functions for each display id */
MDPPlatformPanelFunctionTable gMDPSupportPanelFunctions[MDP_DISPLAY_MAX];

/* Display TE gpio function table */
MDPPlatformTeGpioFunctionType gMDPTeGpioTable[MDP_TE_GPIO_MAX] =
{
  {66,  1},   // MDP_TE_GPIO_66
  {67,  1},   // MDP_TE_GPIO_67
  {68,  1},   // MDP_TE_GPIO_68
  {122, 2},   // MDP_TE_GPIO_122
  {124, 2}    // MDP_TE_GPIO_124
};

/* Default panel gpio table */
MDPPlatformPanelGpioType sDefaultMDPPanelGpio =
{
  75,                       // uDispResetGpio
  MDP_TE_GPIO_66,           // eDispTeGpio
  46,                       // eDispModeGpio
};

/* General helper functions */
static void       Panel_LCDB_WaitForReady(EFI_QCOM_PMIC_LCDB_PROTOCOL   *PmicLCDBProtocol);
static MDP_Status GetPmicIBBLABMode(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);
static MDP_Status Panel_Power_LCD_REG_Enable(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams);


/**********************************************************************************************
*
* FUNCTION: Panel_Default_PowerUp()
*
* DESCRIPTION:
*   Panel power up sequence for default platform, such as CDP/MTP/QRD.
*
***********************************************************************************************/
MDP_Status Panel_Default_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                   Status           = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL           *TLMMProtocol     = NULL;
  EFI_QCOM_PMIC_GPIO_PROTOCOL *PmicGpioProtocol = NULL;

  if (MDP_STATUS_OK != (Status = GetPmicIBBLABMode(eDisplayId, pPowerParams)))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Panel_Default_PowerUp: Getting PMIC mode failed with error(%d), power configuration Failed!\n", Status));
  } else if (MDP_STATUS_OK != (Status =  PlatformClientInit(eDisplayId, pPowerParams)))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Failed to initialize handle for Primary display NPA node.\n"));
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicGpioProtocolGuid, NULL, (VOID **)&PmicGpioProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate PMIC GPIO protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    MDPPlatformPanelFunctionTable *pMDPSupportPanelFunctions = MDP_GET_PANELFUNC(eDisplayId);

    /*
     * Voting for Display NPA node to be ON
     */
    npa_issue_required_request(pPowerParams->sNPAClient[eDisplayId], PMIC_NPA_MODE_ID_GENERIC_ACTIVE);

    MDP_OSAL_DELAYMS(10);   /* delay 10ms to allow power grid to settle */

    /* Set display mode select (dual DSI or single DSI /w DSC) */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->uDispModeGpio, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), TLMM_GPIO_ENABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure GPIO %d for DISP_MODE_SEL failed!\n", pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->uDispModeGpio));
    }

    /* Default to low, dual DSI */
    if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->uDispModeGpio, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_16MA), GPIO_LOW_VALUE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: DISP_MODE_SEL line Low failed!\n"));
    }

    /* Display TE pin */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio(EFI_GPIO_CFG(gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioNum,
                                                             gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioFunc,
                                                             GPIO_INPUT,
                                                             GPIO_NO_PULL,
                                                             GPIO_2MA),
                                                             TLMM_GPIO_ENABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure GPIO %d for TE line failed %d\n", gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioNum));
    }

    /*
     * NOTE:
     * enable LCD_REG_EN for local on board boost regulator
     * it is required for LCD panel with PMIC8150A (AMOLED)
     * it can be removed if PMIC8150L (LCD) presented
     * this is only for testing lcd panel with PMIC8250A (AMOLED)
     */
     if (pPowerParams->ePMICSecondaryPower[eDisplayId] == MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED)
     {
         Panel_Power_LCD_REG_Enable(eDisplayId, pPowerParams);
     }
  }
  return Status;
}

/**********************************************************************************************
*
* FUNCTION: Panel_Power_LCD_REG_Enable()
*
* DESCRIPTION:
*   LCD Panel enable internal boost power
*
***********************************************************************************************/
static MDP_Status Panel_Power_LCD_REG_Enable(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                   Status           = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL           *TLMMProtocol     = NULL;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    /* enable on board boost power */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(Default_DISP_LCD_REG_EN, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), TLMM_GPIO_ENABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure GPIO %d for LCD_REG_EN failed!\n", Default_DISP_LCD_REG_EN));
    }

    if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(Default_DISP_LCD_REG_EN, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_16MA), GPIO_HIGH_VALUE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: LCD_REG_EN line Low failed!\n"));
    }

    /* enable backlight  */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(Default_DISP_LCD_BKLT_EN, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), TLMM_GPIO_ENABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure GPIO %d for LCD_BKLT_EN failed!\n", Default_DISP_LCD_BKLT_EN));
    }

    if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(Default_DISP_LCD_BKLT_EN, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_16MA), GPIO_HIGH_VALUE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: LCD_BKLT_EN line Low failed!\n"));
    }

  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_Default_PowerDown()
*
* DESCRIPTION:
*   Panel power down sequence for default platform, such as CDP/MTP/QRD.
*
***********************************************************************************************/
MDP_Status Panel_Default_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                   Status           = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL           *TLMMProtocol     = NULL;
  EFI_QCOM_PMIC_GPIO_PROTOCOL *PmicGpioProtocol = NULL;

  if (NULL == pPowerParams->sNPAClient[eDisplayId])
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: NULL Handle for Primary display NPA node.\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicGpioProtocolGuid, NULL, (VOID **)&PmicGpioProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate PMIC GPIO protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    MDPPlatformPanelFunctionTable *pMDPSupportPanelFunctions = MDP_GET_PANELFUNC(eDisplayId);

    /* 
     * GPIOs & VRegs
     */
    /* Display RESET_N pin */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(pPowerParams->uResetGpio, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), TLMM_GPIO_DISABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Failed to disable GPIO %d for Reset_N line\n", pPowerParams->uResetGpio));
    }

    /* Display TE pin */
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio(EFI_GPIO_CFG(gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioNum,
                                                             gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioFunc,
                                                             GPIO_INPUT,
                                                             GPIO_PULL_DOWN,
                                                             GPIO_2MA),
                                                             TLMM_GPIO_DISABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Failed to disable GPIO %d for TE pin\n", gMDPTeGpioTable[pMDPSupportPanelFunctions->pMDPPlatformPanelGpio->eDispTeGpio].uGpioNum));
    }


    /*
    * Voltage Regulators
    */
    npa_complete_request(pPowerParams->sNPAClient[eDisplayId]);           // Complete the request to power rails
  }

  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_ResetStateExec()
*
* DESCRIPTION:
*   Toggle reset gpio base on states transition.
*
***********************************************************************************************/
static void Panel_ResetStateExec(EFI_TLMM_PROTOCOL *tlmm, MDPPlatformPanelResetInfo *pResetInfo, uint32 state0, uint32 state1, uint32 state2)
{
    if (EFI_SUCCESS != tlmm->GpioOut((UINT32)EFI_GPIO_CFG(pResetInfo->uResetGpio, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_8MA), state0))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Reset_N line FAILED at state-0!\n"));
    }

    MDP_OSAL_DELAYUS(pResetInfo->uPreResetTimeUs);

    if (EFI_SUCCESS != tlmm->GpioOut((UINT32)EFI_GPIO_CFG(pResetInfo->uResetGpio, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_8MA), state1))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Reset_N line FAILED at state-1!\n"));
    }

    MDP_OSAL_DELAYUS(pResetInfo->uResetAssertTimeUs);

    if (EFI_SUCCESS != tlmm->GpioOut((UINT32)EFI_GPIO_CFG(pResetInfo->uResetGpio, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_16MA), state2))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Reset_N line FAILED at state-2!\n"));
    }
}


/**********************************************************************************************
*
* FUNCTION: Panel_Default_Reset()
*
* DESCRIPTION:
*   Panel reset sequence for default platform, such as CDP/MTP/QRD.
*
***********************************************************************************************/
MDP_Status Panel_Default_Reset(MDPPlatformPanelResetInfo *pResetInfo)
{
  MDP_Status                    Status           = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL            *TLMMProtocol     = NULL;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    /* Enable Display Reset pin*/
    if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(pResetInfo->uResetGpio, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_8MA), TLMM_GPIO_ENABLE))
    {
      DEBUG((EFI_D_WARN, "DisplayDxe: Configure GPIO %d for Reset_N line failed!\n", pResetInfo->uResetGpio));
    }

    switch (pResetInfo->uAssertState)
    {
      case MDP_RESET_STATE_EDGE_LOW2HIGH:
         Panel_ResetStateExec(TLMMProtocol, pResetInfo, GPIO_LOW_VALUE, GPIO_HIGH_VALUE, GPIO_HIGH_VALUE);
       break;
      case MDP_RESET_STATE_EDGE_HIGH2LOW:
         Panel_ResetStateExec(TLMMProtocol, pResetInfo, GPIO_HIGH_VALUE, GPIO_LOW_VALUE, GPIO_LOW_VALUE);
       break;
      case MDP_RESET_STATE_LEVEL_HIGH:
         Panel_ResetStateExec(TLMMProtocol, pResetInfo, GPIO_LOW_VALUE, GPIO_HIGH_VALUE, GPIO_LOW_VALUE);
       break;
      case MDP_RESET_STATE_LEVEL_LOW:
      default:
         Panel_ResetStateExec(TLMMProtocol, pResetInfo, GPIO_HIGH_VALUE, GPIO_LOW_VALUE, GPIO_HIGH_VALUE);
       break;
    }

    MDP_OSAL_DELAYUS(pResetInfo->uPostResetTimeUs);

    /*
     * post reset time: Timing space between end of reset to start sending init dcs cmds
     * NOTE:
     *   use DSIInitMasterTime to extend post reset time control if required
     */
  }

  return Status;
}


/**********************************************************************************************
*
* FUNCTION: GetPmicIBBLABMode()
*
* DESCRIPTION:
*   This function can get the PMIC AMOLED/LCD mode configuration.
*
***********************************************************************************************/
static MDP_Status GetPmicIBBLABMode(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  EFI_QCOM_PMIC_VERSION_PROTOCOL *PmicVersionProtocol = NULL;
  EFI_PM_DEVICE_INFO_TYPE         PmicDeviceInfo;
  MDP_Status                      eStatus             = MDP_STATUS_OK;

  if (NULL == pPowerParams)
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: GetPmicIBBLABMode pPowerParams is NULL!\n"));
    eStatus = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicVersionProtocolGuid, NULL, (VOID **)&PmicVersionProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: GetPmicIBBLABMode Locate PMIC Version Protocol failed!\n"));
    eStatus = MDP_STATUS_NO_RESOURCES;
  }
  else if (pPowerParams->ePMICSecondaryPower[eDisplayId] == MDP_PMIC_MODULE_CONTROLTYPE_NONE)
  {
     if (EFI_SUCCESS != PmicVersionProtocol->GetPmicInfo(PMIC_C, &PmicDeviceInfo))
     {
        DEBUG((EFI_D_ERROR, "DisplayDxe: GetPmicInfo failed!\n"));
        eStatus = MDP_STATUS_NO_RESOURCES;
     }
     else
     {
        if(PmicDeviceInfo.PmicModel == EFI_PMIC_IS_PM8150L)
        {
           pPowerParams->ePMICSecondaryPower[eDisplayId] = MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_LCD; 
        }
        else if (PmicDeviceInfo.PmicModel == EFI_PMIC_IS_PM8150A) 
        {
           pPowerParams->ePMICSecondaryPower[eDisplayId] = MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED; 
        }
        else
        {
           pPowerParams->ePMICSecondaryPower[eDisplayId] = MDP_PMIC_MODULE_CONTROLTYPE_NONE; 
           eStatus = MDP_STATUS_NO_RESOURCES;
        }
     }
   }

  return eStatus;
}


/**********************************************************************************************
*
* FUNCTION: Panel_Default_Brightness_Enable()
*
* DESCRIPTION:
*   Configure wled registers and enable it.
*
***********************************************************************************************/
MDP_Status Panel_Default_Brightness_Enable(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                   Status           = MDP_STATUS_OK;
  EFI_QCOM_PMIC_WLED_PROTOCOL *PmicWledProtocol = NULL;

  if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicWledProtocolGuid, NULL, (VOID **)&PmicWledProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate WLED Protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    /************************************************************************
     *  Enable secondary power source
     ************************************************************************/
    if (MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED == pPowerParams->ePMICSecondaryPower[eDisplayId])
    {
      /* No need to enable brightness manually for OLED panel */
    }
    else /* MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_LCD */
    {
      if (EFI_SUCCESS != PmicWledProtocol->EnableModulator(PMIC_C, EFI_PM_MODULATOR_TYPE_A,TRUE))
      {
        DEBUG((EFI_D_ERROR, "Wled Protocol EnableModulatorA failed\n"));
      }

      if (EFI_SUCCESS != PmicWledProtocol->SetLedDutyCycle(PMIC_C, EFI_PM_MODULATOR_TYPE_A,0x1ff))  /* duty cycle is 12 bits */
      {
        DEBUG((EFI_D_ERROR, "Wled Protocol SetLedDutyCycle failed\n"));
      }

      if (EFI_SUCCESS != PmicWledProtocol->ModulatorSrcSel(PMIC_C, EFI_PM_MODULATOR_TYPE_A, EFI_PM_MODULATOR_SRC_DRV_HIGH))
      {
        DEBUG((EFI_D_ERROR, "Wled Protocol ModulatorSrcSelect failed\n"));
      }

      if (EFI_SUCCESS != PmicWledProtocol->EnableWled(PMIC_C, 0, TRUE))
      {
        DEBUG((EFI_D_ERROR, "Wled Protocol EnableWled failed\n"));
      }

      if (EFI_SUCCESS != PmicWledProtocol->EnableCurrentSink(PMIC_C, EFI_PM_WLED_LED1|EFI_PM_WLED_LED2|EFI_PM_WLED_LED3))
      {
        DEBUG((EFI_D_ERROR, "Wled Protocol EnableCurrentSink failed\n"));
      }

    }
  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_Default_Peripheral_Power()
*
* DESCRIPTION:
*   Secondary power sequence for other PMIC modules such as IBB/LAB.
*
***********************************************************************************************/
MDP_Status Panel_Default_Peripheral_Power(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams, bool32 bPowerUp)
{
  MDP_Status Status = MDP_STATUS_OK;

  if (MDP_STATUS_OK != (Status = GetPmicIBBLABMode(eDisplayId, pPowerParams)))
  {
      DEBUG((EFI_D_ERROR, "DisplayDxe: Panel_Default_Peripheral_Power: Getting PMIC mode failed with error(%d), skipping peripheral power configuration!\n", Status));
  }
  else
  {
    EFI_QCOM_PMIC_WLED_PROTOCOL  *PmicWledProtocol = NULL;
    EFI_QCOM_PMIC_IBB_PROTOCOL   *PmicIBBProtocol  = NULL;
    EFI_QCOM_PMIC_AB_PROTOCOL    *PmicABProtocol   = NULL;
    EFI_QCOM_PMIC_LCDB_PROTOCOL  *PmicLCDBProtocol = NULL;

    if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicWledProtocolGuid, NULL, (VOID **)&PmicWledProtocol))
    {
      DEBUG((EFI_D_ERROR, "DisplayDxe: Locate WLED Protocol failed!\n"));
      Status = MDP_STATUS_NO_RESOURCES;
    }
    else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicIbbProtocolGuid, NULL, (VOID **)&PmicIBBProtocol))
    {
      DEBUG((EFI_D_ERROR, "DisplayDxe: Locate PMIC IBB Protocol failed!\n"));
      Status = MDP_STATUS_NO_RESOURCES;
    }
    else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicAbProtocolGuid, NULL, (VOID **)&PmicABProtocol))
    {
      DEBUG((EFI_D_ERROR, "DisplayDxe: Locate PMIC AB Protocol failed!\n"));
      Status = MDP_STATUS_NO_RESOURCES;
    }
    else if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicLcdbProtocolGuid, NULL, (VOID **)&PmicLCDBProtocol))
    {
      DEBUG((EFI_D_ERROR, "DisplayDxe: Locate PMIC LCDB Protocol failed!\n"));
      Status = MDP_STATUS_NO_RESOURCES;
    }
    else if (TRUE == bPowerUp)
    {
      // ********** Brightness Power-up Sequence **********

      // Configure the power grid based on the module type
      switch (pPowerParams->ePMICSecondaryPower[eDisplayId])
      {
      case MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_LCD:
        {
          // Power up
          /************************************************************************/
          /* Turn On IBB(+5.5v) first, wait for 8ms, turn on LAB(-5.5v)           */
          /************************************************************************/
          // Enable LCD mode
          
          // Turn on LCDB
          
          if (EFI_SUCCESS != PmicLCDBProtocol->SetOutput(PMIC_C,5500,-5500,TRUE))
          {
            DEBUG((EFI_D_ERROR, "DisplayDxe: Error to enable LCDB\n"));
          }

          if (EFI_SUCCESS != PmicLCDBProtocol->ConfigEnableCtrl(PMIC_C, EFI_PM_LCDB_ENABLE_CTL_MODULE_EN, TRUE))
          {
            DEBUG((EFI_D_ERROR, "DisplayDxe: Error to enable LCDB\n"));
          }


          // Wait for IBB/LAB to become ready
          Panel_LCDB_WaitForReady(PmicLCDBProtocol);
        }
        break;
      case MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED:
        {
          /* No need to setup LAB/IBB manually for OLED panel as that is controlled by swire */
        }
        break;
      default:
        break;
      }
    }
    else
    {
      // ********** Brightness Power-down Sequence **********

      // Configure the power grid based on the module type
      switch (pPowerParams->ePMICSecondaryPower[eDisplayId])
      {
      case MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_LCD:
        // Power down
        if (EFI_SUCCESS != PmicLCDBProtocol->ConfigEnableCtrl(PMIC_C, EFI_PM_LCDB_ENABLE_CTL_MODULE_EN, FALSE))
        {
          DEBUG((EFI_D_ERROR, "DisplayDxe: Error to disable LCDB\n"));
        }

        if (EFI_SUCCESS != PmicWledProtocol->EnableCurrentSink(PMIC_C, EFI_PM_WLED_NONE))
        {
            DEBUG((EFI_D_ERROR, "Wled Protocol EnableCurrentSink failed\n"));
        }

        if (EFI_SUCCESS != PmicWledProtocol->EnableWled(PMIC_PMI_DEV_INDEX, 0, FALSE))
        {
          DEBUG((EFI_D_ERROR, "Wled Protocol EnableWled failed\n"));
        }

        break;

      case MDP_PMIC_MODULE_CONTROLTYPE_IBB_LAB_OLED:
      default:
        break;
      }
    }
  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_Default_Brightness_Level()
*
* DESCRIPTION:
*   The function can control the panel brightness level.
*
***********************************************************************************************/
MDP_Status Panel_Default_Brightness_Level(MDP_Display_IDType eDisplayId, BacklightConfigType *pBacklightConfig)
{
  MDP_Status Status = MDP_STATUS_OK;

  if (MDP_PANEL_BACKLIGHTTYPE_PMIC == pBacklightConfig->eBacklightType)
  {
    // Configure the power grid based on the module type
    switch (pBacklightConfig->uBacklightCntrl.eBacklightCtrl)
    {
    case MDP_PMIC_BACKLIGHT_CONTROLTYPE_WLED:
      {
        EFI_QCOM_PMIC_WLED_PROTOCOL  *PmicWledProtocol = NULL;

        if (EFI_SUCCESS != gBS->LocateProtocol(&gQcomPmicWledProtocolGuid, NULL, (VOID **)&PmicWledProtocol))
        {
          DEBUG((EFI_D_ERROR, "DisplayDxe: Locate WLED Protocol failed!\n"));
          Status = MDP_STATUS_NO_RESOURCES;
        }
        else
        {
          uint32 uWLEDValue = (0xFFF * pBacklightConfig->uLevel) / 100; // Calculate duty cycle based on 12 bit mode

          if (EFI_SUCCESS != PmicWledProtocol->SetLedDutyCycle(PMIC_PMI_DEV_INDEX, EFI_PM_MODULATOR_TYPE_A, uWLEDValue))
          {
            DEBUG((EFI_D_ERROR, "Wled Protocol SetLedDutyCycle for ModulatorA failed\n"));
          }

          if (EFI_SUCCESS != PmicWledProtocol->SetLedDutyCycle(PMIC_PMI_DEV_INDEX, EFI_PM_MODULATOR_TYPE_B, uWLEDValue))
          {
            DEBUG((EFI_D_ERROR, "Wled Protocol SetLedDutyCycle for ModulatorB failed\n"));
          }
        }
      }
      break;
    default:
      break;
    }
  }
  else if (MDP_PANEL_BACKLIGHTTYPE_DSI == pBacklightConfig->eBacklightType)
  {
    if (pBacklightConfig->uNumBits > 16)
    {
      DEBUG((EFI_D_ERROR, "Backlight dcs bit width is not available\n"));
      Status = MDP_STATUS_BAD_PARAM;
    }
    else
    {
      PlatformPanelBacklightControl panelBacklightControl = {
        0x00,
        {0x51, 0x00, 0x00}, // Using standard MIPI DCS commands to control brightness
      };

      if (pBacklightConfig->uNumBits > 8)
      {
        // Calculate brightness
        panelBacklightControl.uCmdType   = 0x39; // Use dcs long write type, e.g. 10bits: first byte is bits 0:7, the second byte is bits 8:9.
        panelBacklightControl.command[1] = DISP_DIV_ROUND_UP(((1 << pBacklightConfig->uNumBits) - 1) * pBacklightConfig->uLevel, 100) &  0xFF;
        panelBacklightControl.command[2] = DISP_DIV_ROUND_UP(((1 << pBacklightConfig->uNumBits) - 1) * pBacklightConfig->uLevel, 100) >> 0x08;
      }
      else
      {
        // Default to calculate brightness based on 8 bit mode
        panelBacklightControl.uCmdType   = 0x15; // Use dcs short write type as only needs one byte.
        panelBacklightControl.command[1] = DISP_DIV_ROUND_UP(0xFF * pBacklightConfig->uLevel, 100) & 0xFF;
      }

      Status = DSIDriver_Write(eDisplayId,
                               panelBacklightControl.uCmdType,
                               panelBacklightControl.command,
                               sizeof(panelBacklightControl.command));
      if (MDP_STATUS_OK != Status)
      {
        DEBUG((EFI_D_ERROR, "Backlight brightness DCS command send failed\n"));
      }
	}
  }
  else
  {
    // Nothing to do for other configurations
  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: Panel_LCDB_WaitForReady()
*
* DESCRIPTION:
*   Polling loop to wait for IBB/LAB modules to be ready.
*   VDISN, VDISP will reach the proper voltage upon ready.
*
***********************************************************************************************/
static void Panel_LCDB_WaitForReady(EFI_QCOM_PMIC_LCDB_PROTOCOL   *PmicLCDBProtocol)
{

  BOOLEAN lcdbStatus;
  uint32                 uCount;

  for (uCount = 0; uCount < PMIC_IBBLAB_READYTIME; uCount++)
  {
      if (EFI_SUCCESS == PmicLCDBProtocol->VregOk(PMIC_C, &lcdbStatus))
      {
          if (TRUE == lcdbStatus)
             break;
      }
      else
      {
        DEBUG((EFI_D_ERROR, "DisplayDxe: LCDB VregOK() failed\n"));
        break;
      }
      // Wait 1ms between checks
      MDP_OSAL_DELAYMS(1);
  }

}


/**********************************************************************************************
*
* FUNCTION: DP_USBPlugInvertedOrientation()
*
* DESCRIPTION:
*   Get DP plug polarity (TRUE = inverted, FALSE = normal).
*
***********************************************************************************************/
bool32 DP_USBPlugInvertedOrientation (void)
{ 
  /* USB driver support for detecting orientation is not available. 
   * Use Hardcoded cable polarity 
   */
  bool32  bPolarity = DP_PLUG_INVERTED_POLARITY;

  // For Klocwork - will never be true when this fn. is called
  if (PCD_EXTERNAL_DISPLAY_DP != PcdGet32(PcdExtDisplayType))
  {
     bPolarity = !bPolarity;
  }

  return bPolarity;
}


/**********************************************************************************************
*
* FUNCTION: ExternalPanel_Default_PowerUp()
*
* DESCRIPTION:
*   The default power up function for external display.
*
***********************************************************************************************/
MDP_Status ExternalPanel_Default_PowerUp(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                    Status            = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL            *TLMMProtocol      = NULL;

  if (MDP_STATUS_OK != (Status =  PlatformClientInit(eDisplayId, pPowerParams)))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Failed to initialize handle for External (HDMI) display NPA node.\n"));
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    /*
    * Voting for Display NPA node to be ON
    */
    npa_issue_required_request(pPowerParams->sNPAClient[eDisplayId], PMIC_NPA_MODE_ID_GENERIC_ACTIVE );

    switch (PcdGet32(PcdExtDisplayType))
    {
      case PCD_EXTERNAL_DISPLAY_DP:
        npa_issue_required_request(pPowerParams->sNPAClient[eDisplayId], PMIC_NPA_MODE_ID_GENERIC_ACTIVE );

        /* Configure USB_DP_OE_N (EN_N) GPIO */
        if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(43, 1, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA), DAL_TLMM_GPIO_ENABLE))
        {
          DEBUG((EFI_D_ERROR, "DP: failed to configure USB_DP_OE_N GPIO as output \n"));        
          Status = MDP_STATUS_FAILED;
        }
        if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(43, 1, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA), GPIO_LOW_VALUE))
        {
          DEBUG((EFI_D_ERROR, "DP: failed to drive USB_DP_OE_N GPIO \n"));  
          Status = MDP_STATUS_FAILED;
        }
           
        /* Configure gpio for chip select OE_N of USB-DP Mux logic (SBU_SW_OE) */      
        if (EFI_SUCCESS != TLMMProtocol->ConfigGpio((UINT32)EFI_GPIO_CFG(51, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), DAL_TLMM_GPIO_ENABLE))
        {
          DEBUG((EFI_D_ERROR, "DP: failed to configure USB_EURO_SEL_DC GPIO as output \n"));      
          Status = MDP_STATUS_FAILED;
        }
        if (EFI_SUCCESS != TLMMProtocol->GpioOut((UINT32)EFI_GPIO_CFG(51, 0, GPIO_OUTPUT, GPIO_PULL_UP, GPIO_16MA), GPIO_LOW_VALUE))
        {
          DEBUG((EFI_D_ERROR, "DP: failed to drive USB_EURO_SEL_DC GPIO \n"));
          Status = MDP_STATUS_FAILED;
        }
           
        break;
  
      default:
        break;
    }
  }
  return Status;
}


/**********************************************************************************************
*
* FUNCTION: ExternalPanel_Default_PowerDown()
*
* DESCRIPTION:
*   The default power down function for external display.
*
***********************************************************************************************/
MDP_Status ExternalPanel_Default_PowerDown(MDP_Display_IDType eDisplayId, Panel_PowerCtrlParams *pPowerParams)
{
  MDP_Status                    Status            = MDP_STATUS_OK;
  EFI_TLMM_PROTOCOL             *TLMMProtocol     = NULL;

  if (NULL == pPowerParams->sNPAClient[eDisplayId])
  {
    DEBUG ((EFI_D_ERROR, "DisplayDxe: NULL Handle for HDMI NPA node.\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiTLMMProtocolGuid, NULL, (void **)&TLMMProtocol))
  {
    DEBUG((EFI_D_ERROR, "DisplayDxe: Locate TLMM protocol failed!\n"));
    Status = MDP_STATUS_NO_RESOURCES;
  }
  else
  {
    switch (PcdGet32(PcdExtDisplayType))
    {
      case PCD_EXTERNAL_DISPLAY_DP:
        break;
 
      default:
        break;
    }
  }

  return Status;
}

#ifdef __cplusplus
}
#endif
