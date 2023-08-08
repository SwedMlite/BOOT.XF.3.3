/*
===========================================================================
*/
/**
  @file ClockAppsBSP.c

  BSP data for the SM8250 apps clock driver.
*/
/*
  ====================================================================

  Copyright (c) 2014-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockAppsBSP.c#6 $
  $DateTime: 2019/02/15 19:45:31 $
  $Author: pwbldsvc $
  ====================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include "ClockAppsBSP.h"
#include "ClockApps.h"
#include "HALhwio.h"
#include "../HALclkLib/HALclkHWIO.h"

#include "CoreVerify.h"

/*=========================================================================
      Data
==========================================================================*/

/*
 * Performance level configuration data for the Silver Cluster clock.
 * This table is a placeholder and is updated at runtime.
 */
static ClockAppsBSPCPUConfigType ClockAppsBSPConfigSilverCluster;
/*
 * Performance level configuration data for the Gold Cluster clock.
 * This table is a placeholder and is updated at runtime.
 */
static ClockAppsBSPCPUConfigType ClockAppsBSPConfigGoldCluster;

/*
 * Performance level configuration data for the Gold Cluster clock.
 * This table is a placeholder and is updated at runtime.
 */
static ClockAppsBSPCPUConfigType ClockAppsBSPConfigGoldPlusCluster;

/*
 * Performance level configuration data for the L3 clock.
 * This table is a placeholder and is updated at runtime.
 */
static ClockAppsBSPCPUConfigType ClockAppsBSPConfigL3;


/*
 * Apps BSP data.
 */
static ClockAppsBSPType ClockAppsBSPConfig =
{
  /* .aCPUConfig = */
  {
    {
       .szName                 =  "apcs_silver_post_acd_clk",
       .pConfig                =  &ClockAppsBSPConfigSilverCluster,
    },
    {
       .szName                 =  "apcs_gold_post_acd_clk",
       .pConfig                =  &ClockAppsBSPConfigGoldCluster,
    },
    {
       .szName                 =  "apcs_goldplus_post_acd_clk",
       .pConfig                =  &ClockAppsBSPConfigGoldPlusCluster,
    },
    {
       .szName                 =  "apcs_l3_post_acd_clk",
       .pConfig                =  &ClockAppsBSPConfigL3,
    },
  },
   .aClockEPSSLut               =  {},
};

/*=========================================================================
     Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_ReadEPSSLutData
** =========================================================================*/
/*
  Reads the EPSS LUT from the EPSS hardware.
*/

static DALResult Clock_ReadEPSSLutData
(
  ClockDrvCtxt     *pDrvCtxt,
  ClockAppsCPUType  eCPU
)
{
  uint32  nRowNumber;

  for (nRowNumber = 0; nRowNumber < CLOCK_EPSS_LUT_MAX_ROWS; nRowNumber++)
  {
	  if (!HAL_clk_EPSS_LUT_READ_FREQUENCY(
		  (HAL_clk_APCSCPUType)eCPU,
		  nRowNumber,
		  &ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nClockSource,
		  &ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].lval))
	  {
		  return DAL_ERROR;
	  }

	  if (!HAL_clk_EPSS_LUT_READ_VOLTAGE(
		  (HAL_clk_APCSCPUType)eCPU,
		  nRowNumber,
		  &ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nOpenLoopVoltage))
	  {
		  return DAL_ERROR;
	  }
  }
  
  return DAL_SUCCESS;

} /* END Clock_ReadEPSSLutData */


/* =========================================================================
**  Function : Clock_SaveEPSSLutData
** =========================================================================*/
/*
  Saves the EPSS LUT data from the hardware and parces it into the frequency
  and voltage tables.
*/

static DALResult Clock_SaveEPSSLutData
(
  ClockDrvCtxt     *pDrvCtxt,
  ClockAppsCPUType  eCPU
)
{
	uint32                nRowNumber = 0,nMaxPublishedPerfLevel = 0;
	ClockAppsClusterType  eCluster;
	uint32                nPrevLval = 0, nPrevVoltage = 0;

	switch (eCPU)
	{
	case CLOCK_APPS_CPU_C0:
		eCluster = CLOCK_APPS_CPU_CLUSTER_C0;
		break;

	case CLOCK_APPS_CPU_C1:
		eCluster = CLOCK_APPS_CPU_CLUSTER_C1;
		break;

	case CLOCK_APPS_CPU_C2:
		eCluster = CLOCK_APPS_CPU_CLUSTER_C2;
		break;

	case CLOCK_APPS_CPU_L3:
		eCluster = CLOCK_APPS_CPU_CLUSTER_L3;
		break;

	default:
		ULOG_RT_PRINTF_0(pDrvCtxt->hClockLog,
			"DALSYS_LOGEVENT_FATAL_ERROR: Invalid clock domain detected by Clock_SaveEPSSLutData.");
		ERR_FATAL("Clock_SaveEPSSLutData", 0, 0, 0);
		return DAL_ERROR_INTERNAL;
	}

	/* Count the number of valid performance levels programmed into the EPSS LUT. */
	for (nRowNumber = 0; nRowNumber < CLOCK_EPSS_LUT_MAX_ROWS; nRowNumber++)
	{
		/* Identify duplicate rows -- frequency and voltage pairs identical to the previous. */
		if ((ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].lval == nPrevLval &&
			ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nOpenLoopVoltage == nPrevVoltage) ||
			(ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].lval == 0 &&
			ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nOpenLoopVoltage == 0))
		{
			break;
		}
		nPrevLval = ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].lval;
		nPrevVoltage = ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nOpenLoopVoltage;
		nMaxPublishedPerfLevel++;
		if (ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nClockSource == 0)
		{
			ClockAppsBSPConfig.aCPUConfig[eCluster].pConfig->aPerfConfig[nRowNumber].nFreqHz = 300000000;
		}
		else
		{
			ClockAppsBSPConfig.aCPUConfig[eCluster].pConfig->aPerfConfig[nRowNumber].nFreqHz =
				ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].lval * 19200000;
		}
		ClockAppsBSPConfig.aCPUConfig[eCluster].pConfig->aPerfConfig[nRowNumber].nVoltageUV =
			ClockAppsBSPConfig.aClockEPSSLut[eCPU][nRowNumber].nOpenLoopVoltage * 1000;		
	}
	if(nMaxPublishedPerfLevel > 0)
	{
		nMaxPublishedPerfLevel--;
	}
	ClockAppsBSPConfig.aCPUConfig[eCluster].pConfig->nMaxPerfLevel = nMaxPublishedPerfLevel;
	
	return DAL_SUCCESS;

} /* END Clock_SaveEPSSLutData */


/* =========================================================================
**  Function : Clock_InitAppsBSP
** =========================================================================*/
/*
  See ClockAppsBSP.h
*/

DALResult Clock_InitAppsBSP
(
  ClockDrvCtxt *pDrvCtxt
)
{
  ClockAppsCPUType   eCPU;
  
  /*-----------------------------------------------------------------------*/
  /* Read data programmed into the Operation State Manager (EPSS) by Trust  */
  /* Zone clock driver and recreate the corresponding frequency and        */
  /* voltage plan tables.                                                  */
  /*-----------------------------------------------------------------------*/

  /* Read the EPSS hardware to get the values from the EPSS LUT. */
  for (eCPU = CLOCK_APPS_CPU_C0; eCPU < CLOCK_APPS_CPU_TOTAL; eCPU++)
  {
    if (Clock_ReadEPSSLutData(pDrvCtxt, eCPU) != DAL_SUCCESS)
    {
      return DAL_ERROR;
    }
    if (Clock_SaveEPSSLutData(pDrvCtxt, eCPU) != DAL_SUCCESS)
    {
      return DAL_ERROR;
    }
  }

  return DAL_SUCCESS;

} /* END Clock_InitAppsBSP */


/* =========================================================================
**  Function : Clock_GetAppsBSP
** =========================================================================*/
/*
  See ClockAppsBSP.h
*/

ClockAppsBSPType *Clock_GetAppsBSP
(
  void
)
{
  return &ClockAppsBSPConfig;

} /* END Clock_GetAppsBSP */

/* =========================================================================
**  Function : Clock_MapPerfLevelToFrequency
** =========================================================================*/
/**
  See ClockApps.h
*/

uint32 Clock_MapPerfLevelToFrequency
(
  ClockDrvCtxt     *pDrvCtxt,
  ClockAppsCPUType  eCPU,
  uint32            nPerfLevel
)
{
  ClockAppsCtxtType         *pAppsCtxt = (ClockAppsCtxtType *)pDrvCtxt->pImageCtxt;

  /*-----------------------------------------------------------------------*/
  /* Get the frequency associated with the perf level                                             */
  /*-----------------------------------------------------------------------*/
  if(pAppsCtxt)
  {
	  return pAppsCtxt->aCPU[eCPU].pBSPConfig->pConfig->aPerfConfig[nPerfLevel].nFreqHz;
  }
  return 0;

} /* END Clock_MapPerfLevelToFrequency */






