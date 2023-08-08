/*
==============================================================================

FILE:         HALclkAPCS.c

DESCRIPTION:
  This file contains the clock HAL code to control the APCS clocks.


==============================================================================

                             Edit History


==============================================================================
   Copyright (c) 2017-2018 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include <HALhwio.h>
#include "HALclkInternal.h"
#include "HALclkGeneric.h"
#include "HALclkHWIO.h"
#include "HALclkAPCS.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/* ===========================================================================
**  Function : HAL_clk_EPSS_READ_VCINDEX
**
** ======================================================================== */


boolean HAL_clk_EPSS_READ_VCINDEX
(
  HAL_clk_APCSCPUType  eCore,
  uint32              *nVcIndex
)
{ 
    volatile boolean    bValid;
    uint32              nCount = 200;

    do{
      switch(eCore)
      {
        case HAL_CLK_APCS_CPU_CLUSTER0:
          bValid = HWIO_INF(EPSSSLOW_CLKDOM1_DCVS_IN_PROGRESS, STATUS);
          break;

        case HAL_CLK_APCS_CPU_CLUSTER1: 
          bValid = HWIO_INF(EPSSSLOW_CLKDOM2_DCVS_IN_PROGRESS, STATUS);
          break;

        case HAL_CLK_APCS_CPU_CLUSTER2: 
          bValid = HWIO_INF(EPSSSLOW_CLKDOM3_DCVS_IN_PROGRESS, STATUS);
          break;

        case HAL_CLK_APCS_CPU_L3:
          bValid = HWIO_INF(EPSSSLOW_CLKDOM0_DCVS_IN_PROGRESS, STATUS);
          break;

         default:
          return FALSE;
      }
    }while ((--nCount) && bValid);


    switch(eCore)
    {
      case HAL_CLK_APCS_CPU_CLUSTER0: 
		  *nVcIndex = HWIO_INF(EPSSSLOW_CLKDOM1_DOMAIN_STATE, VC_IDX);
        break;

      case HAL_CLK_APCS_CPU_CLUSTER1: 
		  *nVcIndex =HWIO_INF(EPSSSLOW_CLKDOM2_DOMAIN_STATE, VC_IDX);
        break;

      case HAL_CLK_APCS_CPU_CLUSTER2: 
		  *nVcIndex = HWIO_INF(EPSSSLOW_CLKDOM3_DOMAIN_STATE, VC_IDX);
        break;
              
      case HAL_CLK_APCS_CPU_L3: 
		  *nVcIndex = HWIO_INF(EPSSSLOW_CLKDOM0_DOMAIN_STATE, VC_IDX);
        break;

      default:
        return FALSE;
    }
    return TRUE;

} /* END HAL_clk_ReadCurrentCPUFrequency */


/* ===========================================================================
**  Function : HAL_clk_EPSS_LUT_READ_FREQUENCY
**
** ======================================================================== */

boolean HAL_clk_EPSS_LUT_READ_FREQUENCY
(
  HAL_clk_APCSCPUType  eCore,
  uint32               nRow,
  uint32              *nClkSource,
  uint32              *nLVal
)
{
  /* Sanity check */
  if (eCore      >= HAL_CLK_APCS_CPU_TOTAL ||
      nRow       >= EPSS_LUT_MAX_ROWS       ||
      nClkSource == NULL                   ||
      nLVal      == NULL                   )
  {
    return FALSE;
  }

  /* Read program from the hardware. */
  switch(eCore)
  {
    case HAL_CLK_APCS_CPU_CLUSTER0:
		*nClkSource = HWIO_INFI(EPSSSLOW_CLKDOM1_DCVS_LUT_r_FREQUENCY, nRow, CLKSRC);
		*nLVal		= HWIO_INFI(EPSSSLOW_CLKDOM1_DCVS_LUT_r_FREQUENCY, nRow, LVAL);
      break;

    case HAL_CLK_APCS_CPU_CLUSTER1:
		*nClkSource = HWIO_INFI(EPSSSLOW_CLKDOM2_DCVS_LUT_r_FREQUENCY, nRow, CLKSRC);
		*nLVal		= HWIO_INFI(EPSSSLOW_CLKDOM2_DCVS_LUT_r_FREQUENCY, nRow, LVAL);
      break;

    case HAL_CLK_APCS_CPU_CLUSTER2:
		*nClkSource = HWIO_INFI(EPSSSLOW_CLKDOM3_DCVS_LUT_r_FREQUENCY, nRow, CLKSRC);
		*nLVal = HWIO_INFI(EPSSSLOW_CLKDOM3_DCVS_LUT_r_FREQUENCY, nRow, LVAL);
      break;

    case HAL_CLK_APCS_CPU_L3:
		*nClkSource = HWIO_INFI(EPSSSLOW_CLKDOM0_DCVS_LUT_r_FREQUENCY, nRow, CLKSRC);
		*nLVal		= HWIO_INFI(EPSSSLOW_CLKDOM0_DCVS_LUT_r_FREQUENCY, nRow, LVAL);
      break;

    default:
      return FALSE;
  }

  return TRUE;

} /* END HAL_clk_EPSS_LUT_READ_FREQUENCY */

/* ===========================================================================
**  Function : HAL_clk_EPSS_LUT_READ_VOLTAGE
**
** ======================================================================== */

boolean HAL_clk_EPSS_LUT_READ_VOLTAGE
(
HAL_clk_APCSCPUType  eCore,
uint32               nRow,
uint32              *nOpenLoopVoltage
)
{
	/* Sanity check */
	if (eCore >= HAL_CLK_APCS_CPU_TOTAL ||
		nRow >= EPSS_LUT_MAX_ROWS ||
		nOpenLoopVoltage == NULL)
	{
		return FALSE;
	}

	/* Program the hardware. */
	switch (eCore)
	{
	case HAL_CLK_APCS_CPU_CLUSTER0:
		*nOpenLoopVoltage = HWIO_INFI(EPSSSLOW_CLKDOM1_DCVS_LUT_r_VOLTAGE, nRow, OLV);
		break;

	case HAL_CLK_APCS_CPU_CLUSTER1:
		*nOpenLoopVoltage = HWIO_INFI(EPSSSLOW_CLKDOM2_DCVS_LUT_r_VOLTAGE, nRow, OLV);
		break;

	case HAL_CLK_APCS_CPU_CLUSTER2:
		*nOpenLoopVoltage = HWIO_INFI(EPSSSLOW_CLKDOM3_DCVS_LUT_r_VOLTAGE, nRow, OLV);
		break;

	case HAL_CLK_APCS_CPU_L3:
		*nOpenLoopVoltage = HWIO_INFI(EPSSSLOW_CLKDOM0_DCVS_LUT_r_VOLTAGE, nRow, OLV);
		break;

	default:
		return FALSE;
	}

	return TRUE;

} /* END HAL_clk_EPSS_LUT_READ_VOLTAGE */


/* ===========================================================================
**  Function : HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL
**
** ======================================================================== */

boolean HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL
(
  HAL_clk_APCSCPUType eCore,
  uint32              nIndex
)
{
  uintnt  nAddress; 
  uint32  nValue;

  /* Sanity check */
  if (eCore  >= HAL_CLK_APCS_CPU_TOTAL ||
      nIndex >= EPSS_LUT_MAX_ROWS       )
  {
    return FALSE;
  }

  switch(eCore)
  {
    case HAL_CLK_APCS_CPU_CLUSTER0:
      /* Prepare the address and the data. */
		nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, 0);
		nValue	 = HWIO_FVAL(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

	  nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, 1);
	  nValue = HWIO_FVAL(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

	  nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, 2);
	  nValue = HWIO_FVAL(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

	  nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, 3);
	  nValue = HWIO_FVAL(EPSSSLOW_CLKDOM1_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

      break;

    case HAL_CLK_APCS_CPU_CLUSTER1:
      /* Prepare the address and the data. */
		nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, 0);
		nValue = HWIO_FVAL(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

	  nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, 1);
	  nValue = HWIO_FVAL(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

	  nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, 2);
	  nValue = HWIO_FVAL(EPSSSLOW_CLKDOM2_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

      break;

    case HAL_CLK_APCS_CPU_CLUSTER2:
      /* Prepare the address and the data. */
		nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM3_COREd_PERF_STATE_DESIRED, 0);
		nValue = HWIO_FVAL(EPSSSLOW_CLKDOM3_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

      break;

    case HAL_CLK_APCS_CPU_L3:
      /* Prepare the address and the data. */
		nAddress = HWIO_ADDRI(EPSSSLOW_CLKDOM0_COREd_PERF_STATE_DESIRED, 0);
		nValue = HWIO_FVAL(EPSSSLOW_CLKDOM0_COREd_PERF_STATE_DESIRED, SW_INDEX, nIndex);
      /* Program the hardware. */
      outpdw(nAddress, nValue);

      break;

    default:
      return FALSE;
  }

  return TRUE;

} /* END HAL_clk_EPSS_SET_DESIRED_PERF_LEVEL */


/* ===========================================================================
**  HAL_clk_InitMiscGfxRegisters
**
** ======================================================================== */

void HAL_clk_InitMiscGfxRegisters
(
  void
)
{
  HWIO_OUTF(GPUCC_GPU_CC_GFX3D_CRC_SID_FSM_CTRL, SID_FSM_CTRL, 0x00800000);
  HWIO_OUTF(GPUCC_GPU_CC_GFX3D_CRC_MND_CFG,      MND_CFG,      0x00015011);
  HWIO_OUTF(GCC_NPU_CFG_AHB_CBCR,                CLK_ENABLE,   0x1);
  HWIO_OUTF(NPU_CC_CAL_HM0_CRC_SID_FSM_CTRL,     SID_FSM_CTRL, 0x00800000);
  HWIO_OUTF(NPU_CC_CAL_HM0_CRC_MND_CFG ,         MND_CFG,      0x00015011);
  HWIO_OUTF(NPU_CC_CAL_HM1_CRC_SID_FSM_CTRL,     SID_FSM_CTRL, 0x00800000);
  HWIO_OUTF(NPU_CC_CAL_HM1_CRC_MND_CFG ,         MND_CFG,      0x00015011);
} /* HAL_clk_InitMiscGfxRegisters */

