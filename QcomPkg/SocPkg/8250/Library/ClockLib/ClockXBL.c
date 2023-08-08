/** @file ClockXBL.c

  This file implements specialized image specific functions such
  as init image, enable DCVS, etc. In case of UEFI, we have few
  place holders for now.

  Copyright (c) 2010-2018, Qualcomm Technologies, Inc.
                   All rights reserved.
                 QUALCOMM Proprietary/GTDR

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 05/30/14   sj      Fixed 64 bit compilation errors
 05/08/14   sr      Ported to 8994.
 08/09/12   sr      Ported to 8974.
 12/23/10   vs      Created.

=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "DDIClock.h"
#include "Drivers/ClockDxe/ClockDriver.h"
#include "ClockApps.h"
#include "../HALclkLib/HALclkHWIO.h"

#include <Protocol/EFIPlatformInfoTypes.h>
#include <api/systemdrivers/icbarb.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/EFIPlatformInfo.h>

#include <Pi/PiStatusCode.h>
#include <Protocol/StatusCode.h>
#include <Protocol/ReportStatusCodeHandler.h>
#include <Library/BaseMemoryLib.h>
#include "Lpm.h"
#include "Drivers/ClockDxe/ClockDriver.h"

/*=========================================================================
      Macros
==========================================================================*/


/*=========================================================================
      Externals
==========================================================================*/

/*=========================================================================
      Prototypes
==========================================================================*/

/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * UEFI Clock Driver local context.
 */
typedef struct
{
  boolean        bLowPowerMode;
  uint32         nSilverPerfLevel;
} ClockLocalCtxtType;

/*=========================================================================
      Data
==========================================================================*/

extern EFI_GUID gEfiRscHandlerProtocolGuid;

EFI_STATUS Clock_RegisterLPMCallBacks (BOOLEAN bIsRegisterLpm);
EFI_STATUS EFIAPI Clock_LowPowerModeHandler (
    IN EFI_STATUS_CODE_TYPE ,
    IN EFI_STATUS_CODE_VALUE,
    IN UINT32,
    IN EFI_GUID *,
    IN EFI_STATUS_CODE_DATA *
    );


ClockLocalCtxtType  ClockLocalCtxt;

#define   CLOCK_CLUSTER_LOW_PERF_LEVEL            0 // 300Mhz


/* This list is every clock that defaults OFF that is owned by APCS */
const char *aClocksRequiredOnList[] =
{
 "gcc_camera_ahb_clk"        	,
 "gcc_gpu_cfg_ahb_clk"       	,
 "gcc_disp_ahb_clk"          	,
 "gcc_video_ahb_clk"            ,
 "gcc_npu_cfg_ahb_clk"          ,
 "gcc_pcie_0_cfg_ahb_clk"       ,
 "gcc_pcie_1_cfg_ahb_clk"       ,
/*
 {"gcc_sdcc2_ahb_clk"            },
 {"gcc_sdcc4_ahb_clk"            },
 {"gcc_boot_rom_ahb_clk"      	 },
 {"gcc_prng_ahb_clk"          	 },
 {"gcc_qupv3_wrap_0_m_ahb_clk"	 },
 {"gcc_qupv3_wrap_0_s_ahb_clk"	 },
 {"gcc_qupv3_wrap_1_m_ahb_clk"	 },
 {"gcc_qupv3_wrap_1_s_ahb_clk"	 },
 {"gcc_qupv3_wrap_2_m_ahb_clk"	 },
 {"gcc_qupv3_wrap_2_s_ahb_clk"	 },
 {"gcc_emac_slv_ahb_clk"      	 },
 {"gcc_qmip_camera_nrt_ahb_clk"  },
 {"gcc_qmip_camera_rt_ahb_clk"   },
 {"gcc_qmip_disp_ahb_clk"        },
 {"gcc_qmip_video_cvp_ahb_clk"   },
 {"gcc_qmip_video_vcodec_ahb_clk"},
 {"gcc_pdm_ahb_clk"              },
 {"gcc_qspi_cnoc_periph_ahb_clk" },
 {"gcc_tsif_ahb_clk"             },
 {"gcc_ufs_card_ahb_clk"         },
 {"gcc_ufs_phy_ahb_clk"          },
*/

  NULL
};




/* =========================================================================
**  Function : Clock_aClocksRequiredOn
** =========================================================================*/
DALResult Clock_aClocksRequiredOn
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult                     eResult = DAL_SUCCESS;
  ClockIdType                   nClockId;
  ClockNodeType                *pClock = NULL;
  uint32                        nIndex = 0;

  for (nIndex = 0; aClocksRequiredOnList[nIndex]!= NULL; nIndex++)
  {
    eResult = Clock_GetClockId(pDrvCtxt,aClocksRequiredOnList[nIndex],(ClockIdType *)&nClockId);
    if ( eResult == DAL_SUCCESS )
      pClock = Clock_GetClockNode(pDrvCtxt, nClockId);

    if ( pClock != NULL )
      eResult = Clock_EnableClock(pDrvCtxt, pClock);
  }
  return  eResult;
}




/* =========================================================================
**  Function : Clock_EnterLowPowerMode
** =========================================================================*/
/*
  See DDIClock.h
*/

DALResult Clock_EnterLowPowerMode
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult           eResult;
  uint32              perfLevel, pnFrequencyHz;

  DALCLOCK_LOCK(pDrvCtxt);

  /*-----------------------------------------------------------------------*/
  /* Do not allow nested entries of the Low Power Mode.                    */
  /*-----------------------------------------------------------------------*/

  if (ClockLocalCtxt.bLowPowerMode == TRUE)
  {
    DALCLOCK_FREE(pDrvCtxt);
    return DAL_ERROR;
  }


  /*-----------------------------------------------------------------------*/
  /* Reduce each core's frequency to the lowest possible.                  */
  /*-----------------------------------------------------------------------*/
  // Set Silver cluster CPU0 perf level
  ClockLocalCtxt.nSilverPerfLevel = 0;
  eResult = Clock_GetCpuPerfLevel( CLOCK_APPS_CPU_C0, &perfLevel);
  if (eResult == DAL_SUCCESS)
  {
    ClockLocalCtxt.nSilverPerfLevel = perfLevel;
    // Set Silver cluster 0  to lowest perf level (300Mhz)
    eResult = Clock_SetCpuPerfLevel(CLOCK_APPS_CPU_C0, CLOCK_CLUSTER_LOW_PERF_LEVEL, &pnFrequencyHz);
  }
  else
  {
    DEBUG ((EFI_D_ERROR, "Clock_SetCpuPerfLevel CLOCK_APPS_CPU_C0 : Fail\n"));
  }

  ClockLocalCtxt.bLowPowerMode = TRUE;

  DALCLOCK_FREE(pDrvCtxt);

  return eResult;

} /* END Clock_EnterLowPowerMode */


/* =========================================================================
**  Function : Clock_ExitLowPowerMode
** =========================================================================*/
/*
  See DDIClock.h
*/

DALResult Clock_ExitLowPowerMode
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult  eResult = DAL_SUCCESS;
  uint32     pnFrequencyHz;

  DALCLOCK_LOCK(pDrvCtxt);

  /*-----------------------------------------------------------------------*/
  /* Make sure the Low Power Mode is active before exiting it.             */
  /*-----------------------------------------------------------------------*/

  if (ClockLocalCtxt.bLowPowerMode == FALSE)
  {
    DALCLOCK_FREE(pDrvCtxt);
    return DAL_ERROR;
  }

  /*-----------------------------------------------------------------------*/
  /* Restore frequencies for CPU clusters to the nominal level.            */
  /*-----------------------------------------------------------------------*/
  /* Silver Cluster */
  eResult = Clock_SetCpuPerfLevel(CLOCK_APPS_CPU_C0, ClockLocalCtxt.nSilverPerfLevel, &pnFrequencyHz); //CLOCK_SILVER_NOMINAL_PERF_LEVEL
  if (eResult != DAL_SUCCESS)
  {
    DEBUG ((EFI_D_ERROR, "Clock_ExitLowPowerMode: Set Silver Perf level Fail\n"));
  }

  ClockLocalCtxt.bLowPowerMode = FALSE;

  DALCLOCK_FREE(pDrvCtxt);

  return eResult;

} /* END Clock_ExitLowPowerMode */

/**
  LPM feature - Clock_LowPowerModeHandler

  @param[IN] CodeType        :EFI_PROGRESS_CODE
  @param[IN] Value           :PcdLpm refer QcomPkg.dec for the value details
  @param[IN] Instance        : 0
  @param[IN] *CallerId       : Caller Id who initiated this CB
  @param[IN] *Data OPTIONAL  : Extended data refer LPM_EVENT_EXT_DATA in lpm.h

  @return
  EFI_SUCCESS                : CB handled
  EFI_UNSUPPORTED            : CB not intended for this module
**/

EFI_STATUS EFIAPI Clock_LowPowerModeHandler
(
    IN EFI_STATUS_CODE_TYPE     CodeType,
    IN EFI_STATUS_CODE_VALUE    Value,
    IN UINT32                   Instance,
    IN EFI_GUID                 *CallerId,
    IN EFI_STATUS_CODE_DATA     *Data OPTIONAL
)
{
  DALResult       eResult = DAL_SUCCESS;
  ClockDrvCtxt   *pDrvCtxt;
  EFI_GUID        QcomProtocolId = gEfiClockProtocolGuid ;
  BOOLEAN         bMatch;
  EFI_STATUS      status = EFI_UNSUPPORTED;
  LPM_EVENT_EXT_DATA *LpmEventData = NULL;


  if (((CodeType & EFI_STATUS_CODE_TYPE_MASK) == EFI_PROGRESS_CODE) &&
      (Value == PcdGet32 (PcdLpm)) &&
      (Data != NULL))
  {
    /* Map LpmEventData */
    LpmEventData = (LPM_EVENT_EXT_DATA*)( Data + 1);

    bMatch = CompareGuid(&(LpmEventData->CalleeGuid), &QcomProtocolId);
    if(TRUE == bMatch)
    {
	  pDrvCtxt = Clock_GetDrvCtxt();
	  if(pDrvCtxt == NULL)
	  {
		    DEBUG(( EFI_D_ERROR, "Clock_LowPowerModeHandler: Clock_GetDrvCtxt=NULL \r\n"));
		    return EFI_ABORTED;
	  }

      //DEBUG(( EFI_D_WARN, "Clock_LowPowerModeHandler::  QcomProtocolId Called ID GUID  Match %d \r\n",CallerId));
      switch (ClockLocalCtxt.bLowPowerMode)
      {
     	case FALSE:
	      if(LPM_ENTRY == LpmEventData->LPMState )
	      {
            eResult = Clock_EnterLowPowerMode(pDrvCtxt);
            status = (eResult==DAL_SUCCESS)? EFI_SUCCESS : EFI_ABORTED;
	      }
	      else
	      {
	        DEBUG(( EFI_D_WARN, "Clock_LowPowerModeHandler: state %d != LPM_ENTRY \r\n", LpmEventData->LPMState));
	        status = EFI_SUCCESS;
	      }
	      break;
	    case TRUE:
	      if(LPM_EXIT == LpmEventData->LPMState )
	      {
            eResult = Clock_ExitLowPowerMode(pDrvCtxt);
            status = (eResult==DAL_SUCCESS)? EFI_SUCCESS : EFI_ABORTED;
	      }
	      else
	      {
	        DEBUG(( EFI_D_WARN, "Clock_LowPowerModeHandler: state %d != LPM_EXIT \r\n", LpmEventData->LPMState));
	        status = EFI_SUCCESS;
	      }
	      break;
	    default:
	        DEBUG(( EFI_D_WARN, "Clock_LowPowerModeHandler: wrong  LPM state %d \r\n", LpmEventData->LPMState));
	        status =  EFI_UNSUPPORTED;

	  }
    }
   }

   return status;
}

/**
  Register/Unregister LPM support to get LPM entry/exit status in CB

  @param[IN] bIsRegisterLpm  : TRUE - Register LPM handler
                               FALSE - UnRegister LPM handler
  @return
  EFI_SUCCESS                : CB registered .
  EFI_DEVICE_ERROR           : device reported an error.
  EFI_UNSUPPORTED            : not supported by this device.
  EFI_INVALID_PARAMETER      : Parameter passed is incorrect.
**/

EFI_STATUS
Clock_RegisterLPMCallBacks (BOOLEAN bIsRegisterLpm)
{
  EFI_STATUS                Status              = EFI_SUCCESS;
  EFI_RSC_HANDLER_PROTOCOL *mRscHandlerProtocol = NULL;

  Status = gBS->LocateProtocol (&gEfiRscHandlerProtocolGuid,
                                NULL,
                               (VOID **) &mRscHandlerProtocol);

  if((EFI_SUCCESS != Status) || (mRscHandlerProtocol == NULL))
  {
    DEBUG ((EFI_D_ERROR, "Clock_RegisterLPMCallBacks Fail %r\n",Status));
    return Status;
  }

  if(bIsRegisterLpm)
  {
    Status |= mRscHandlerProtocol->Register(Clock_LowPowerModeHandler, TPL_CALLBACK);
  }
  else
  {
    Status |= mRscHandlerProtocol->Unregister(Clock_LowPowerModeHandler);
  }
  return Status;
}

