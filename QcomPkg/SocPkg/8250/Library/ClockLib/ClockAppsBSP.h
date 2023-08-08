#ifndef __CLOCKAPPSBSP_H__
#define __CLOCKAPPSBSP_H__
/*
===========================================================================
*/
/**
  @file ClockAppsBSP.h

  Header description for the SDM845 apps clock driver BSP format.
*/
/*
  ====================================================================

  Copyright (c) 2010-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockAppsBSP.h#4 $
  $DateTime: 2019/05/06 20:41:41 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "Drivers/ClockDxe/ClockBSP.h"
#include "Drivers/ClockDxe/ClockDriver.h"
#include "../HALclkLib/HALclkAPCS.h"


/*=========================================================================
      Macros
==========================================================================*/

#define CLOCK_EPSS_LUT_MAX_ROWS  EPSS_LUT_MAX_ROWS
#define CLOCK_APPS_PERF_LEVEL_TOTAL 40
#define MIN_PERF_LEVEL              0
#define MAX_PERF_LEVEL              39

/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * Enumeration of CPU elements.
 */
typedef enum
{
  CLOCK_APPS_CPU_C0     = HAL_CLK_APCS_CPU_CLUSTER0,
  CLOCK_APPS_CPU_C1     = HAL_CLK_APCS_CPU_CLUSTER1,
  CLOCK_APPS_CPU_C2     = HAL_CLK_APCS_CPU_CLUSTER2,
  CLOCK_APPS_CPU_L3     = HAL_CLK_APCS_CPU_L3,
  CLOCK_APPS_CPU_TOTAL,
  CLOCK_APPS_CPU_CLUSTER_0_TOTAL = CLOCK_APPS_CPU_C1,
  CLOCK_APPS_CPU_CLUSTER_1_TOTAL = CLOCK_APPS_CPU_C2,
  CLOCK_APPS_CPU_CLUSTER_2_TOTAL = CLOCK_APPS_CPU_L3,
  CLOCK_APPS_CPU_L2  = CLOCK_APPS_CPU_L3,

  CLOCK_ENUM_32BITS(APPS_CPU)
} ClockAppsCPUType;

/**
 * Enumeration of CPU Cluster elements.
 */
typedef enum
{
  CLOCK_APPS_CPU_CLUSTER_C0,
  CLOCK_APPS_CPU_CLUSTER_C1,
  CLOCK_APPS_CPU_CLUSTER_C2,
  CLOCK_APPS_CPU_CLUSTER_L3,
  CLOCK_APPS_CPU_CLUSTER_TOTAL,

  CLOCK_ENUM_32BITS(APPS_CPU_CLUSTER)
} ClockAppsClusterType;

/*
 * ClockAppsPerfLevelConfigType
 *
 * Configuration parameters for a performance level.
 *
 *  nFreqHz             - Frequency in Hz for this configuration.
 *  nVRegAPCCornerIndex - Index to APC rail voltage corner for CPR control.
 */
typedef struct
{
  uint32             nFreqHz;
  uint32             nVoltageUV;        /* voltage (uV)*/
} ClockAppsPerfLevelConfigType;

/*
 * Actual format for the data stored in the BSP.
 */
typedef struct
{
  uint32             nMinPerfLevel;
  uint32             nMaxPerfLevel;
  ClockAppsPerfLevelConfigType  aPerfConfig[CLOCK_APPS_PERF_LEVEL_TOTAL];
} ClockAppsBSPCPUConfigType;

/*
 * CPU BSP type.
 */
typedef struct
{
  const char                    *szName;
  ClockAppsBSPCPUConfigType     *pConfig;
} ClockAppsBSPCPUType;

/*
 * EPSS type.
 */
typedef struct
{
  uint32        nOpenLoopVoltage;
  uint32        lval;
  uint32        nClockSource;
} ClockEPSSLutType;

/*
 * Apps BSP type.
 */
typedef struct
{
  ClockAppsBSPCPUType aCPUConfig[CLOCK_APPS_CPU_CLUSTER_TOTAL];
  ClockEPSSLutType     aClockEPSSLut[CLOCK_APPS_CPU_TOTAL][CLOCK_EPSS_LUT_MAX_ROWS];
} ClockAppsBSPType;

/* =========================================================================
**  Function : Clock_InitAppsBSP
** =========================================================================*/
/**
  Initializes the Apps BSP data.

  Initializes the Apps BSP data by doing any necessary runtime detection based
  on information such as: chip ID, chip version, PVS bins, and speed bins.

  @param *pDrvCtxt [in] -- Handle to the DAL driver context.

  @return
  DAL_SUCCESS -- BSP initialized successfully.
  DAL_ERROR -- BSP initialization failed.

  @dependencies
  None.
*/

DALResult Clock_InitAppsBSP
(
  ClockDrvCtxt *pDrvCtxt
);


/* =========================================================================
**  Function : Clock_GetAppsBSP
** =========================================================================*/
/**
  Returns a pointer to the Apps BSP data.

    @return
    Pointer to the BSP data.

    @dependencies
    None.
*/

ClockAppsBSPType *Clock_GetAppsBSP
(
  void
);

#endif  /* __CLOCKAPPSBSP_H__ */

