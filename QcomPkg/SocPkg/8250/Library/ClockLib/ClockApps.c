/*
===========================================================================
*/
/**
  @file ClockApps.c

  Main entry point for the SDM845 main application processor clock driver.
*/
/*
  ====================================================================

  Copyright (c) 2012-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockApps.c#7 $
  $DateTime: 2019/07/22 14:57:35 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "Drivers/ClockDxe/ClockDriver.h"
#include "ClockApps.h"
#include "HALhwio.h"
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/EFIPlatformInfoTypes.h>
#include <Protocol/EFIPlatformInfo.h>

#include <Pi/PiStatusCode.h>
#include <Protocol/StatusCode.h>
#include <Protocol/ReportStatusCodeHandler.h>
#include <Library/BaseMemoryLib.h>
#include "Lpm.h"
#include "Drivers/ClockDxe/ClockDriver.h"


/*=========================================================================
      Type Definitions
==========================================================================*/

/*=========================================================================
      Externs
==========================================================================*/

extern HAL_clk_ClockControlType           HAL_clk_GenericClockControl;
extern HAL_clk_ClockDomainControlType     HAL_clk_GenericDomainControl;


/*=========================================================================
      Function Prototypes
==========================================================================*/
extern void Clock_MdssMdpRequest
(
  ClockDrvCtxt *pDrvCtxt,
  BOOLEAN       bEnable
);

extern EFI_STATUS Clock_RegisterLPMCallBacks (BOOLEAN bIsRegisterLpm);

/*=========================================================================
      Data
==========================================================================*/

/*
 * Clock Apps context.
 */
ClockAppsCtxtType Clock_AppsCtxt;

/*=========================================================================
      Data Declarations
==========================================================================*/

uint32 StubbedAPI_Flag = 0;

/*=========================================================================
      CPU Clock Domains
==========================================================================*/
/* Silver */
static ClockDomainNodeType ClockDomain_CPU_C0 =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .pRail     = NULL,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CPU_C1 =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .pRail     = NULL,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CPU_C2 =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .pRail     = NULL,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType ClockDomain_CPU_L3 =
{
  .aBSP      = NULL,
  .nBSPLen   = 0,
  .pRail     = NULL,
  .pSource   = NULL,
  .nFlags    = CLOCK_FLAG_READ_ONLY,
  .HALDomain = {
    .nCGRAddr   = 0,
    .pmControl  = &HAL_clk_GenericDomainControl,
  },
};

static ClockDomainNodeType *aCpuDomains[] =
{
  &ClockDomain_CPU_C0,
  &ClockDomain_CPU_C1,
  &ClockDomain_CPU_C2,
  &ClockDomain_CPU_L3,
};

/*=========================================================================
      CPU Clocks
==========================================================================*/

static ClockNodeType aCpuClocks[] =
{
  {
    .szName    = "apcs_silver_clk",
    .pDomain   = &ClockDomain_CPU_C0,
    .pDebugMux = NULL,
    .nUniqueId = 0x0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "apcs_gold_clk",
    .pDomain   = &ClockDomain_CPU_C1,
    .pDebugMux = NULL,
    .nUniqueId = 0x0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "apcs_goldplus_clk",
    .pDomain   = &ClockDomain_CPU_C2,
    .pDebugMux = NULL,
    .nUniqueId = 0x0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
  {
    .szName    = "apcs_l3_clk",
    .pDomain   = &ClockDomain_CPU_L3,
    .pDebugMux = NULL,
    .nUniqueId = 0x0,
    .nFlags    = 0x0,
    .HALClock  = {
      .mRegisters   = { 0, 0, {0, 0} },
      .pmControl    = &HAL_clk_GenericClockControl,
      .nDebugMuxSel = HAL_CLK_NO_DEBUG_MUX_SEL,
    },
  },
};

/*=========================================================================
      Externals
==========================================================================*/

/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_InitTarget
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult Clock_InitTarget
(
  ClockDrvCtxt *pDrvCtxt
)
{
  DALResult          eResult = DAL_SUCCESS;
  ClockAppsBSPType  *pAppsBSPConfig;
  uint32             i;
  uint32             nFreqHz;
  ClockIdType        nClockId;
  ClockNodeType     *pClock;
  EFI_STATUS         Status;

  if(StubbedAPI_Flag)
  {
    return DAL_SUCCESS;
  }
  
  /*
   * Hookup the apps context to the driver context.
   */
  pDrvCtxt->pImageCtxt = &Clock_AppsCtxt;

  /*-----------------------------------------------------------------------*/
  /* Initialize the Apps BSP data.                                         */
  /*-----------------------------------------------------------------------*/

  pAppsBSPConfig = Clock_GetAppsBSP();

  for (i = 0; i < CLOCK_APPS_CPU_TOTAL; i++)
  {
    /*
     * Hookup the BSP data.
     */
    switch (i)
    {
      case CLOCK_APPS_CPU_C0:
        Clock_AppsCtxt.aCPU[i].pBSPConfig = &pAppsBSPConfig->aCPUConfig[CLOCK_APPS_CPU_CLUSTER_C0];
        break;

      case CLOCK_APPS_CPU_C1:
        Clock_AppsCtxt.aCPU[i].pBSPConfig = &pAppsBSPConfig->aCPUConfig[CLOCK_APPS_CPU_CLUSTER_C1];
        break;

      case CLOCK_APPS_CPU_C2:
        Clock_AppsCtxt.aCPU[i].pBSPConfig = &pAppsBSPConfig->aCPUConfig[CLOCK_APPS_CPU_CLUSTER_C2];
        break;

      case CLOCK_APPS_CPU_L3:
       Clock_AppsCtxt.aCPU[i].pBSPConfig = &pAppsBSPConfig->aCPUConfig[CLOCK_APPS_CPU_CLUSTER_L3];
        break;

      default:
        return DAL_ERROR_INTERNAL;
    }
  }

  eResult = Clock_InitAppsBSP(pDrvCtxt);
  if (eResult != DAL_SUCCESS)
  {
    return DAL_ERROR_INTERNAL;
  }

  /*-----------------------------------------------------------------------*/
  /* Name and configure the CPU clocks.                                    */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < CLOCK_APPS_CPU_TOTAL; i++)
  {
    /*
     * Get the clock ID.
     */
    eResult = Clock_GetClockId(pDrvCtxt, Clock_AppsCtxt.aCPU[i].pBSPConfig->szName, &nClockId);
    if (eResult != DAL_SUCCESS)
    {
      return DAL_ERROR_INTERNAL;
    }
    pClock = Clock_GetClockNode(pDrvCtxt, nClockId);

    if (pClock == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }
    
    /* Populate the aCpuClocks array data with the corresponding BSP values. */
    Clock_AppsCtxt.aCPU[i].pClock = &aCpuClocks[i];
    aCpuClocks[i].pDebugMux = pClock->pDebugMux;
    aCpuClocks[i].HALClock.nDebugMuxSel = pClock->HALClock.nDebugMuxSel;

    /* Default all CPU active configuration to the first BSP entry. */
    Clock_AppsCtxt.aCPU[i].pActiveConfig = &Clock_AppsCtxt.aCPU[i].pBSPConfig->pConfig->aPerfConfig[0];

    /*
     * Store the original min and max perf levels from BSP data. The BSP values can be updated
     * by subsequent calls to PepClockSetMinPerfLevel and PepClockSetMaxPerfLevel APIs.
     */
    Clock_AppsCtxt.aCPU[i].nMinPerfLevel = Clock_AppsCtxt.aCPU[i].pBSPConfig->pConfig->nMinPerfLevel;
    Clock_AppsCtxt.aCPU[i].nMaxPerfLevel = Clock_AppsCtxt.aCPU[i].pBSPConfig->pConfig->nMaxPerfLevel;

    /* Initialize the CPU ActiveMuxConfig structure. */
    memset(&Clock_AppsCtxt.aCPU[i].ActiveMuxConfig, 0, sizeof(ClockMuxConfigType));
    Clock_AppsCtxt.aCPU[i].pClock->pDomain->pActiveMuxConfig = &Clock_AppsCtxt.aCPU[i].ActiveMuxConfig;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the DCVS module.                                           */
  /*-----------------------------------------------------------------------*/

  Clock_InitDCVS(pDrvCtxt);

  /*-----------------------------------------------------------------------*/
  /* Detecting Current PerfLevel frequency.                          */
  /*-----------------------------------------------------------------------*/

  if ( Clock_DetectCPUFrequency(CLOCK_APPS_CPU_C0,&nFreqHz) != DAL_SUCCESS)
    {
      return DAL_ERROR_INTERNAL;
    }
      DEBUG((EFI_D_WARN, " >>> Cluster 0: %8d MHz\n", nFreqHz/1000000));

   if ( Clock_DetectCPUFrequency(CLOCK_APPS_CPU_L3,&nFreqHz) != DAL_SUCCESS)
    {
      return DAL_ERROR_INTERNAL;
    }
      DEBUG((EFI_D_WARN, " >>> Cluster 2: %8d MHz\n", nFreqHz/1000000));

  /*-----------------------------------------------------------------------*/
  /* Register LPM callbacks.                                               */
  /*-----------------------------------------------------------------------*/
  Status = Clock_RegisterLPMCallBacks(TRUE);

  /*-----------------------------------------------------------------------*/
  /* Update miscellaneous GPU registers.                                   */
  /*-----------------------------------------------------------------------*/

  HAL_clk_InitMiscGfxRegisters();

  /*-----------------------------------------------------------------------*/
  /* Run the BIST if enabled.                                              */
  /*-----------------------------------------------------------------------*/

  if (pDrvCtxt->nBISTLogSize == 0)
  {
    pDrvCtxt->nBISTLogSize = CLOCK_BIST_DEFAULT_LOG_SIZE;
  }

  if (pDrvCtxt->bBISTEnabled)
  {
    Clock_BIST (pDrvCtxt);
  }

  /*-----------------------------------------------------------------------*/
  /* Good to go.                                                           */
  /*-----------------------------------------------------------------------*/

  return DAL_SUCCESS;

} /* END Clock_InitTarget */


/* =========================================================================
**  Function : Clock_DeInitTarget
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult Clock_DeInitTarget
(
  ClockDrvCtxt *pDrvCtxt
)
{
  /*-----------------------------------------------------------------------*/
  /* Clear out driver context data.                                        */
  /*-----------------------------------------------------------------------*/

  memset((void *)pDrvCtxt->pImageCtxt, 0x0, sizeof(ClockAppsCtxtType));

  return DAL_SUCCESS;

} /* END Clock_DeInitTarget */

/* =========================================================================
**  Function : Clock_GetCpuDomains
** =========================================================================*/

ClockDomainNodeType **Clock_GetCpuDomains(void)
{
  return &aCpuDomains[0];
}






