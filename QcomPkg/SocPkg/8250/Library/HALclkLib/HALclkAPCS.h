#ifndef __HALCLKAPCS_H__
#define __HALCLKAPCS_H__

/*
===========================================================================
*/
/**
  @file HALclkAPCS.h

  Header APCS-specific HAL functions.
*/
/*
  ====================================================================

  Copyright (c) 2013-2018 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================


  ====================================================================
*/

/* ============================================================================
**    Include files
** ==========================================================================*/

#include "HALclkInternal.h"


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * EPSS definitions
 */
#define EPSS_LUT_MAX_ROWS  40


/* ============================================================================
**    Typedefs
** ==========================================================================*/

/**
 * Enumeration of CPU/Clusters.
 */
typedef enum
{
  HAL_CLK_APCS_CPU_CLUSTER0,
  HAL_CLK_APCS_CPU_CLUSTER1,
  HAL_CLK_APCS_CPU_CLUSTER2,
  HAL_CLK_APCS_CPU_L3,
  HAL_CLK_APCS_CPU_TOTAL,

  HAL_ENUM_32BITS(CLK_APCS_CPU)
} HAL_clk_APCSCPUType;


/* ============================================================================
**    Functions
** ==========================================================================*/

/* ===========================================================================
**  Function : HAL_clk_EPSS_LUT_READ_FREQUENCY
**
** ======================================================================== */
/**
  Read the programmed data of the specified row of the EPSS Look-Up-Table
  Frequency values.

  @param eCore      [in]  -- CPU cluster to read.
  @param nRow       [in]  -- Row of the EPSS Look-Up-Table to read.
  @param nPllSource [out] -- Clock Source value read.
  @param nLVal      [out] -- PLL L-Value value read.

  @return
  TRUE  -- Configuration read successfully.
  FALSE -- Failed to read configuration for any reason.

  @dependencies
  None.
*/

boolean HAL_clk_EPSS_LUT_READ_FREQUENCY
(
  HAL_clk_APCSCPUType  eCore,
  uint32               nRow,
  uint32              *nClkSource,
  uint32              *nLVal
);



/* ===========================================================================
**  Function : HAL_clk_EPSS_READ_VCINDEX
**
** ======================================================================== */
/**

@param nCPU            [in]   -- CPU cluster to read.
@param nVcIndex        [out]  -- Active VC index.
@dependencies
None.
*/

boolean HAL_clk_EPSS_READ_VCINDEX
(
  HAL_clk_APCSCPUType  eCore,
  uint32               *nVcIndex
);

/* ===========================================================================
**  Function : HAL_clk_EPSS_LUT_READ_VOLTAGE
**
** ======================================================================== */
/**
Read the programed data of the specified row of the EPSS Look-Up-Table
Voltage values.

@param eCore            [in]  -- CPU cluster to read.
@param nRow             [in]  -- Row of the EPSS Look-Up-Table to read.
@param nOpenLoopVoltage [out] -- Open Loop Voltage value read.

@return
TRUE  -- Configuration read successfully.
FALSE -- Failed to read configuration for any reason.

@dependencies
None.
*/

boolean HAL_clk_EPSS_LUT_READ_VOLTAGE
(
HAL_clk_APCSCPUType  eCore,
uint32               nRow,
uint32              *nOpenLoopVoltage
);

/* ===========================================================================
**  Function : HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL
**
** ======================================================================== */
/**
  Governor's request for a specific performance state.

  @param eCore  [in] -- CPU cluster to affect.
  @param nIndex [in] -- Index into the EPSS LUT.

  @return
  TRUE  -- Operation succeeded.
  FALSE -- Operation failed for any reason.

  @dependencies
  EPSS must be programmed and enabled prior to this call.
*/

boolean HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL
(
  HAL_clk_APCSCPUType eCore,
  uint32              nIndex
);


/* ===========================================================================
**  HAL_clk_InitMiscGfxRegisters
**
** ======================================================================== */

void HAL_clk_InitMiscGfxRegisters
(
  void
);


#endif

