/*
===========================================================================
*/
/**
  @file ClockUEFI.c

  This file contains the clock device driver UEFI specific code.
*/
/*
  ====================================================================

  Copyright (c) 2017 - 2019 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockUEFI.c#10 $
  $DateTime: 2019/12/02 10:16:58 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <string.h>
#include "Drivers/ClockDxe/ClockDriver.h"
#include "ClockApps.h"
#include "../HALclkLib/HALclkHWIO.h"

/*=========================================================================
      Function Prototypes
==========================================================================*/

extern DALResult Clock_SetCPUConfig
(
  ClockDrvCtxt                  *pDrvCtxt,
  ClockAppsCPUType               eCPU,
  uint32                         nperfLevel
);


/*=========================================================================
      Data Declarations
==========================================================================*/

#define MIN_PERF_LEVEL 0
#define MIN_PERF_LEVEL_FREQUENCY 300000000


/*=========================================================================
  Extern
==========================================================================*/

extern uint32 StubbedAPI_Flag;

/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_GetMaxPerfLevel
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetMaxPerfLevel (
  uint32 nCPU,
  uint32 *pnPerfLevel
)
{
  ClockDrvCtxt              *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType *pBSPConfig;
  
  if(StubbedAPI_Flag)
  {
    *pnPerfLevel = MIN_PERF_LEVEL;
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    if (pnPerfLevel)
    {
      *pnPerfLevel = pBSPConfig->nMaxPerfLevel;
    }
  
    return DAL_SUCCESS;
  }
}

/* =========================================================================
**  Function : Clock_GetMinPerfLevel
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult Clock_GetMinPerfLevel
(
  uint32 nCPU,
  uint32 *pnPerfLevel
)
{
  ClockDrvCtxt              *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType *pBSPConfig;
  if(StubbedAPI_Flag)
  {
    *pnPerfLevel = MIN_PERF_LEVEL;
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    if (pnPerfLevel)
    {
      *pnPerfLevel = pBSPConfig->nMinPerfLevel;
    }
   
    return DAL_SUCCESS;
  }
}

/* =========================================================================
**  Function : Clock_GetCpuPerfLevelFrequency
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetCpuPerfLevelFrequency (
  uint32 nCPU,
  uint32 nPerfLevel,
  uint32 *pnFrequencyHz,
  uint32 *pnRequiredVoltage
)
{
  ClockDrvCtxt              *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType *pBSPConfig;

  if(StubbedAPI_Flag)
  {
    *pnFrequencyHz = MIN_PERF_LEVEL_FREQUENCY;
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    if (nPerfLevel < pBSPConfig->nMinPerfLevel || nPerfLevel > pBSPConfig->nMaxPerfLevel)
    {
      return DAL_ERROR_OUT_OF_RANGE_PARAMETER;
    }

    if (pnFrequencyHz)
    {
      *pnFrequencyHz = Clock_MapPerfLevelToFrequency(pDrvCtxt, (ClockAppsCPUType)nCPU, nPerfLevel);
    }

    if (pnRequiredVoltage)
    {
      *pnRequiredVoltage = Clock_MapPerfLevelToVoltage(pDrvCtxt, (ClockAppsCPUType)nCPU, nPerfLevel);
    }

    return DAL_SUCCESS;
  }
}

/* ===========================================================================
**  Function :  Clock_DetectCPUFrequency
**    
** ======================================================================== */

DALResult  Clock_DetectCPUFrequency
(
  uint32 nCPU,
  uint32 *nFreqHz
)
{
  uint32                       nVcIndex;
  ClockAppsCPUType             eCPU = (ClockAppsCPUType)nCPU;
  ClockDrvCtxt                 *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType            *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt; 
  ClockAppsBSPCPUConfigType    *pBSPConfig;
 
  if(StubbedAPI_Flag)
  {
    *nFreqHz = MIN_PERF_LEVEL_FREQUENCY;
    return DAL_SUCCESS;
  }
  else
  { 
    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;
    if(HAL_clk_EPSS_READ_VCINDEX((HAL_clk_APCSCPUType)nCPU, &nVcIndex))
        {
      pAppsCtxt->aCPU[eCPU].pActiveConfig = &pBSPConfig->aPerfConfig[nVcIndex];
      *nFreqHz = pBSPConfig->aPerfConfig[nVcIndex].nFreqHz;
          return DAL_SUCCESS;
        }     
    return DAL_ERROR;
  }
}

/* =========================================================================
**  Function : Clock_GetCPUFrequencyLevels
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetCPUFrequencyLevels (
  uint32 nCPU,
  uint32 *pnFrequencyLevels 
)
{
  DALResult                    eResult=DAL_SUCCESS;
  ClockDrvCtxt                 *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType            *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType    *pBSPConfig;
  
  if(StubbedAPI_Flag)
  {
    *pnFrequencyLevels = MIN_PERF_LEVEL;
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }
    
    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;
    
    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }
    
    *pnFrequencyLevels = pBSPConfig->nMaxPerfLevel +1;
    
    return eResult;
  }
}
 
/* =========================================================================
**  Function : Clock_GetCPUFrequencyPlan
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetCPUFrequencyPlan (
  uint32 nCPU,
  ClockFreqPlanType *pCPUFreqPlan,
  uint32 nSize
)
{
  DALResult                 eResult=DAL_SUCCESS;
  ClockDrvCtxt              *pDrvCtxt = Clock_GetDrvCtxt();
  uint32                    nRowNumber = 0;
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType *pBSPConfig;
  
  if(StubbedAPI_Flag)
  {
    return DAL_SUCCESS;
  }
  else
  { 
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;
    
    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }
    
    //If the size of the table to be dumped is less than that of frequency plan
    if(nSize < (pBSPConfig->nMaxPerfLevel+1)*sizeof(ClockFreqPlanType))
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }
    
    for (nRowNumber = 0; nRowNumber <=pBSPConfig->nMaxPerfLevel; nRowNumber++)
    {
      (pCPUFreqPlan + nRowNumber)->nFreqHz = pBSPConfig->aPerfConfig[nRowNumber].nFreqHz;
      (pCPUFreqPlan + nRowNumber)->eVRegLevel = pBSPConfig->aPerfConfig[nRowNumber].nVoltageUV;    
    }  
    return eResult;
  } 
} 
 

/* =========================================================================
**  Function : Clock_SetCPUFrequency
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_SetCPUFrequency (
  uint32 nCPU,
  uint32 nFrequencyHz,
  uint32 *pnResultFreqHz
)
{
  DALResult                  eResult=DAL_SUCCESS;
  ClockDrvCtxt               *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType          *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  uint32                     nRowNumber;
  ClockAppsBSPCPUConfigType  *pBSPConfig;
  
  if(StubbedAPI_Flag)
  {
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }
    
    for (nRowNumber = 0; nRowNumber <= pBSPConfig->nMaxPerfLevel; nRowNumber++)
    {
      if(nFrequencyHz <= pBSPConfig->aPerfConfig[nRowNumber].nFreqHz)
      {
          break;
      }
    }

    if(nRowNumber > pBSPConfig->nMaxPerfLevel)
    {
      nRowNumber = pBSPConfig->nMaxPerfLevel;
    }
    
    /* Check the state of DCVS and return immediately if DCVS is disabled. */
    if (pDrvCtxt->bDCVSEnabled == TRUE || CLOCK_GLOBAL_FLAG_IS_SET(CPU_TEST_IN_PROGRESS))
    {
      eResult = Clock_SetCPUConfig(
                pDrvCtxt,
                (ClockAppsCPUType)nCPU,
                nRowNumber);
                
      if (eResult == DAL_SUCCESS && pnResultFreqHz != NULL)
      {
         *pnResultFreqHz = pAppsCtxt->aCPU[nCPU].pActiveConfig->nFreqHz;
      }   
    }
  
    return eResult;
  }
}
/* =========================================================================
**  Function : Clock_GetCPUFrequency
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetCPUFrequency (
  uint32 nCPU,
  uint32 *pnFrequencyHz
)
{
  ClockDrvCtxt                 *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType            *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsPerfLevelConfigType *pPerfConfig;
  
  if(StubbedAPI_Flag)
  {
    *pnFrequencyHz = MIN_PERF_LEVEL_FREQUENCY;
    return DAL_SUCCESS;
  }
  else
  {
    if (pnFrequencyHz == NULL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    *pnFrequencyHz = 0;

    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pPerfConfig = pAppsCtxt->aCPU[nCPU].pActiveConfig;

    if (pPerfConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    *pnFrequencyHz = pPerfConfig->nFreqHz;

    return DAL_SUCCESS;

  }
}

/* =========================================================================
**  Function : Clock_SetCpuPerfLevel
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_SetCpuPerfLevel (
  uint32 nCPU,
  uint32 nPerfLevel,
  uint32 *pnFrequencyHz
)
{
  DALResult                  eResult=DAL_SUCCESS;
  ClockDrvCtxt              *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType *pBSPConfig;
  
  if(StubbedAPI_Flag)
  {
    return DAL_SUCCESS;
  }
  else
  {
    if (pnFrequencyHz == NULL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    *pnFrequencyHz = 0;

    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    /* Clamp the given perf level within the valid range. */
      if (nPerfLevel < pBSPConfig->nMinPerfLevel)
      {
        nPerfLevel = pBSPConfig->nMinPerfLevel;
      }
      if (nPerfLevel > pBSPConfig->nMaxPerfLevel)
      {
        nPerfLevel = pBSPConfig->nMaxPerfLevel;
      }

    /* Check the state of DCVS and return immediately if DCVS is disabled. */
    if (pDrvCtxt->bDCVSEnabled == TRUE || CLOCK_GLOBAL_FLAG_IS_SET(CPU_TEST_IN_PROGRESS))
    {
      eResult = Clock_SetCPUConfig(
                pDrvCtxt,
                (ClockAppsCPUType)nCPU,
                nPerfLevel);

      if (eResult == DAL_SUCCESS)
      {
        *pnFrequencyHz = pBSPConfig->aPerfConfig[nPerfLevel].nFreqHz;
      } 
    }
  
    return eResult;
  }
}

/* =========================================================================
**  Function : Clock_GetCpuPerfLevel
** =========================================================================*/
/*
  See ClockDriver.h
*/

DALResult
Clock_GetCpuPerfLevel (
  uint32 nCPU,
  uint32 *pnPerfLevel
)
{
  ClockDrvCtxt                 *pDrvCtxt = Clock_GetDrvCtxt();
  ClockAppsCtxtType            *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;
  ClockAppsBSPCPUConfigType    *pBSPConfig;
  ClockAppsPerfLevelConfigType *pPerfConfig;
  uint32                        nPerfLevel;
   
  if(StubbedAPI_Flag)
  {
    *pnPerfLevel = MIN_PERF_LEVEL;
    return DAL_SUCCESS;
  }
  else
  {
    if ((ClockAppsCPUType)nCPU >= CLOCK_APPS_CPU_TOTAL)
    {
      return DAL_ERROR_INVALID_PARAMETER;
    }

    pBSPConfig = pAppsCtxt->aCPU[nCPU].pBSPConfig->pConfig;

    if (pBSPConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    pPerfConfig = pAppsCtxt->aCPU[nCPU].pActiveConfig;

    if (pPerfConfig == NULL)
    {
      return DAL_ERROR_INTERNAL;
    }

    for (nPerfLevel = pBSPConfig->nMinPerfLevel;
      nPerfLevel < pBSPConfig->nMaxPerfLevel + 1;
      ++nPerfLevel)
    {
      if (&pBSPConfig->aPerfConfig[nPerfLevel] == pPerfConfig)
      {
        *pnPerfLevel = nPerfLevel;
        return DAL_SUCCESS;
      }
    }

    return DAL_ERROR_OUT_OF_RANGE_PARAMETER;

  }
}


