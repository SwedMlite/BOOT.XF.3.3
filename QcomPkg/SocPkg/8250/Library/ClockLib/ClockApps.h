#ifndef CLOCKAPPS_H
#define CLOCKAPPS_H
/*
===========================================================================
*/
/**
  @file ClockApps.h

  Internal header file for the clock device driver on the apps image.
*/
/*
  ====================================================================

  Copyright (c) 2010-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockApps.h#4 $
  $DateTime: 2019/05/06 20:41:41 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockAppsBSP.h"
#include "../HALclkLib/HALclkAPCS.h"

/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * CPU context.
 */
typedef struct
{
  ClockNodeType                 *pClock;
  ClockAppsBSPCPUType           *pBSPConfig;
  ClockAppsPerfLevelConfigType  *pActiveConfig;
  ClockAppsPerfLevelConfigType  *pPreviousConfig;
  uint32                         nMinPerfLevel;
  uint32                         nMaxPerfLevel;
  ClockMuxConfigType             ActiveMuxConfig;
} ClockAppsCPUCtxt;

/*
 * Initial rail voltage BSP data.
 */
typedef struct
{
  char               *sName;
  rail_voltage_level  eBootCorner;
} ClockRailConfigType;

/**
 * Apps clock driver context.
 */
typedef struct
{
  ClockAppsCPUCtxt    aCPU[CLOCK_APPS_CPU_TOTAL];
} ClockAppsCtxtType;

/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : Clock_GetDrvCtxt
** =========================================================================*/
/*
  Returns a pointer to the Clock Driver Context data.

  @return
  Pointer to the Clock Driver Context data.

  @dependencies
  None.
*/

ClockDrvCtxt *Clock_GetDrvCtxt
(
  void
);

/* =========================================================================
**  Function : Clock_MapPerfLevelToFrequency
** =========================================================================*/
/**
  Maps a given CPU Perf Level to a frequency in Hz.

  This function takes in a given CPU Perf Level and returns the corresponding
  frequency in Hz.

  @param pDrvCtxt   [in] -- Pointer to the driver context.
  @param eCPU       [in] -- CPU/Cluster identifier.
  @param nPerfLevel [in] -- Desired Perf Level.

  @return
  Frequency in Hz.

  @dependencies
  None.
*/

uint32 Clock_MapPerfLevelToFrequency
(
  ClockDrvCtxt     *pDrvCtxt,
  ClockAppsCPUType  eCPU,
  uint32            nPerfLevel
);

/* =========================================================================
**  Function : Clock_DetectCPUFrequency
** =========================================================================*/
/**	
    @param nCPU            [in]   -- CPU cluster to read.
    @param nFreqHz         [out]  -- Frequency of the cluster to be read.
    
    @return
    DAL_SUCCESS -- PerfLevel dectected and active mux config set successfully.
  	DAL_ERROR   -- PerfLevel dectection failed.
    
    @dependencies
    None.
    
*/

DALResult Clock_DetectCPUFrequency
(
	 uint32 nCPU,
	 uint32 *nFreqHz
);

/* =========================================================================
**  Function : Clock_MapPerfLevelToVoltage
** =========================================================================*/
/**
  Maps perf level index to a raw voltage.

  This function takes in perf level index and returns a raw voltage.

  @param pDrvCtxt          [in] -- Pointer to the driver context.
  @param eCPU              [in] -- CPU/Cluster identifier.
  @param nPerfLevel        [in] -- Perf Level index

  @return
  Raw voltage in uV.

  @dependencies
  None.
*/

uint32 Clock_MapPerfLevelToVoltage
(
  ClockDrvCtxt     *pDrvCtxt,
  ClockAppsCPUType  eCPU,
  uint32            nPerfLevel
);

#endif /* !CLOCKAPPS_H */

