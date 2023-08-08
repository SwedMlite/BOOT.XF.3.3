/*
===========================================================================
*/
/**
  @file ClockAppsDCVS.c

  DCVS and NPA node implementation.
*/
/*
  ====================================================================

  Copyright (c) 2017-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockAppsDCVS.c#3 $
  $DateTime: 2018/11/13 16:12:55 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "Drivers/ClockDxe/ClockDriver.h"
#include "ClockApps.h"
#include "QdssSWEvent.h"
#include "tracer_event_ids.h"

/*=========================================================================
      Constants and Macros
==========================================================================*/

/*=========================================================================
      Type Definitions
==========================================================================*/

/*=========================================================================
      Externals
==========================================================================*/

/*=========================================================================
      Prototypes
==========================================================================*/

/*=========================================================================
      Data
==========================================================================*/

/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_InitDCVS
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult Clock_InitDCVS
(
  ClockDrvCtxt *pDrvCtxt
)
{
  /*-----------------------------------------------------------------------*/
  /* Make sure DCVS is enabled.                                            */
  /*-----------------------------------------------------------------------*/

  pDrvCtxt->bDCVSEnabled = TRUE;

  /*-----------------------------------------------------------------------*/
  /* Good to go.                                                           */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END Clock_InitDCVS */


/* =========================================================================
**  Function : Clock_SetCPUConfig
** =========================================================================*/
/**
  NPA node driver function for the CPU node.

  This function handles minimum frequency requests for the CPU NPA node.

  @param *pDrvCtxt [in] -- Pointer to driver context.
  @param nCPU [in] -- Which CPU domain to change.
  @param nPerfLevel [in] -- New perf level index.

  @return
  DAL_SUCCESS - CPU clock configuration succeeded.
  DAL_ERROR - CPU clock configuration failed.

  @dependencies
  None.
*/

DALResult Clock_SetCPUConfig
(
  ClockDrvCtxt                  *pDrvCtxt,
  ClockAppsCPUType               eCPU,
  uint32                        nPerfLevel
)
{
  DALResult          eResult = DAL_SUCCESS;
  ClockAppsCtxtType *pAppsCtxt;

  DALCLOCK_LOCK(pDrvCtxt);
  pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;

  /*-----------------------------------------------------------------------*/
  /* Sanity checks.                                                        */
  /*-----------------------------------------------------------------------*/

  if (pAppsCtxt == NULL )
  {
    ULOG_RT_PRINTF_0 (pDrvCtxt->hClockLog,
                      "DALSYS_LOGEVENT_FATAL_ERROR: Invalid configuration detected by Clock_SetCPUConfig.");
    DALCLOCK_FREE(pDrvCtxt);
    ERR_FATAL("Clock_SetCPUConfig", 0, 0, 0);
    return DAL_ERROR;
  }

  /*-----------------------------------------------------------------------*/
  /* If the desired frequency has already been set, just return.           */
  /*-----------------------------------------------------------------------*/

  if (pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel].nFreqHz == pAppsCtxt->aCPU[eCPU].pActiveConfig->nFreqHz)
  {
    DALCLOCK_FREE(pDrvCtxt);
    return DAL_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Use EPSS to set the desired perf level.                                */
  /*-----------------------------------------------------------------------*/

  if (!HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL((HAL_clk_APCSCPUType)eCPU, nPerfLevel))
  {
    ULOG_RT_PRINTF_0 (pDrvCtxt->hClockLog,
                      "DALSYS_LOGEVENT_FATAL_ERROR: Invalid EPSS configuration detected by Clock_SetCPUConfig.");
    DALCLOCK_FREE(pDrvCtxt);
    ERR_FATAL("Clock_SetCPUConfig", 0, 0, 0);
    return DAL_ERROR;
  }

  if (CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_FREQ_CHANGE))
  {
    ULOG_RT_PRINTF_2 (
      pDrvCtxt->hClockLog,
      "Freq[/clk/cpu%d] = %lu (Hz)",
      eCPU,
      pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel].nFreqHz);
  }
  DALCLOCK_FREE(pDrvCtxt);

  /*
   * Log CPU frequency change event.
   */
  QDSS_SWEVENT(CLOCK_EVENT_CPU_FREQ, eCPU, pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel].nFreqHz);

  /*-----------------------------------------------------------------------*/
  /* Update state.                                                         */
  /*-----------------------------------------------------------------------*/
  DALCLOCK_LOCK(pDrvCtxt);

  pAppsCtxt->aCPU[eCPU].pActiveConfig = &pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel];
  pAppsCtxt->aCPU[eCPU].ActiveMuxConfig.nFreqHz = pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel].nFreqHz;

  DALCLOCK_FREE(pDrvCtxt);

  return eResult;

} /* END Clock_SetCPUConfig */

