/*=============================================================================
 
  File: DisplaySystem.c
 
  Source file for Display System

   
  Copyright (c) 2019 Qualcomm Technologies, Inc.  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#include <Protocol/EFIChipInfoTypes.h>
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIClock.h>
#include "MDPSystem.h"
#include "api/systemdrivers/busywait.h"
#include "HALhwio.h"
#include "DisplaySystem.h"

/*
 * NOTE: gcc_disp_ahb_clk need be enabled before any other clocks be enabled
 */
char *mdss_rscc_clk[] =
{
   "gcc_disp_ahb_clk",        
   "disp_cc_mdss_rscc_ahb_clk",
   "disp_cc_mdss_rscc_vsync_clk",
   NULL
};


/**
MDSS_RSCC_ClkEnable()

Enable MDSS RSCC clocks 

@retval None

**/
static void MDSS_RSCC_ClkEnable(void)
{
   EFI_CLOCK_PROTOCOL  *mClockProtocol;
   UINTN                uClockId;
   UINTN                uCount = 0;

  if (EFI_SUCCESS == gBS->LocateProtocol(&gEfiClockProtocolGuid,
                                         NULL,
                                         (VOID **)&mClockProtocol))
  {
      while (mdss_rscc_clk[uCount] != NULL)
      {
         if (EFI_SUCCESS == mClockProtocol->GetClockID(mClockProtocol,  mdss_rscc_clk[uCount], &uClockId))
         {
             if (EFI_SUCCESS != mClockProtocol->EnableClock(mClockProtocol, uClockId))
             {
                 DEBUG ((EFI_D_WARN, "MDSS_RSCC_ClkEnable: Clock=%a cannot be enabled!\n", mdss_rscc_clk[uCount]));
             }
         }
         else
         {
             DEBUG ((EFI_D_ERROR, "MDSS_RSCC_ClkEnable: Clock=%a  not found!\n", mdss_rscc_clk[uCount]));
         }
         uCount++;
      }
  }

}


/**
DisplaySubsystemInitialization

Do initialization for display subsystem.

@retval None

**/
void DisplaySubsystemInitialization(void)
{
  EFI_CHIPINFO_PROTOCOL                *hChipInfoProtocol;
  EFIChipInfoFamilyType                 sEFIChipSetFamily;

  MDP_OSAL_MEMZERO(&sEFIChipSetFamily, sizeof(sEFIChipSetFamily));
  
  if (EFI_SUCCESS == gBS->LocateProtocol(&gEfiChipInfoProtocolGuid,
                                         NULL,
                                         (VOID **)&hChipInfoProtocol))
  {
    hChipInfoProtocol->GetChipFamily(hChipInfoProtocol, &sEFIChipSetFamily);
  }

  switch (sEFIChipSetFamily)
  {
    case EFICHIPINFO_FAMILY_SM8250:
      MDSS_RSCC_ClkEnable();
      break;
    default:
      break;
  }
}
