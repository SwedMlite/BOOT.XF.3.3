/**
==============================================================================

  @file ClockSDI.c
  
  Clock functions for support System Debug Image driver.  Since SDI image is
  required to be every small memory footprint, clock drivers only brings in
  necessary code to support it.

  Copyright (c) 2017,2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================


==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockSDI.c#5 $

  when      who     what, where, why
  --------  ------  ------------------------------------------------------
  05/16/17  vphan   Initial SDM855 revision, branched from SDM845.

==============================================================================
*/


/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "HALclkHWIO.h"
#include "ClockDriver.h"
#include "ClockBSPExtern.h"

/*=========================================================================
                       MACRO DEFINITIONS
==========================================================================*/

/*=========================================================================
      Data 
==========================================================================*/

/*=========================================================================
      Function Prototypes
==========================================================================*/

/*===========================================================================
                      FUNCTION DECLARATIONS
===========================================================================*/ 

/* ========================================================================
**  Function : Clock_ConfigureDDR
** ======================================================================*/
/*
    Description: Configure all clocks needed for DDR configuration.  This
    extension API is used for bootup and emergency download mode.

    @param None
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_ConfigureDDR( void )
{
  Clock_SetDomainFreq(&ClockDomain_GCC_GCCDDRMCCH0ROOT, 200000);
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCSHRM);
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCMEMNOC);

  /* Enable all MemNOC clocks */
  Clock_ToggleClock(HWIO_GCC_MSS_Q6_MEMNOC_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  Clock_ToggleClock(HWIO_GCC_SHRM_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_PIMEM_AHB_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_PIMEM_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_SYS_NOC_GC_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  HWIO_OUTF(GCC_MMNOC_GDSCR, SW_COLLAPSE, 0);
  while( HWIO_INF(GCC_MMNOC_GDSCR, PWR_ON) == 0);

  Clock_ToggleClock(HWIO_GCC_MMNOC_AHB_CFG_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_MMNOC_HF_QX_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_MMNOC_QOSGEN_EXTREF_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_MMNOC_SF_QX_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_MMNOC_TBU_HF0_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_MMNOC_TBU_HF1_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_NOC_MMNOC_DCD_XO_CBCR_ADDR, CLK_TOGGLE_ENABLE);

#if 0
  Clock_ToggleClock( HWIO_ADDR(GCC_DNOC_CFG_CBCR), CLK_TOGGLE_ENABLE );
#endif
  Clock_ToggleClock( HWIO_ADDR(GCC_SNOC_QOSGEN_EXTREF_CBCR), CLK_TOGGLE_ENABLE );

  Clock_ToggleClock(HWIO_GCC_DDRSS_XO_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_SLEEP_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_DDRSS_MMNOC_SF_QX_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  // Clock_ToggleClock(HWIO_GCC_DDRSS_MMNOC_HF_QX_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_TCU_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_SYS_NOC_GC_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_SYS_NOC_SF_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  /* CR 2291005: Hangup in SDI that prevents ramdump */
  // Clock_ToggleClock(HWIO_GCC_DDRSS_TURING_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_MSS_Q6_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_DDRSS_GPU_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);

#if 0
  Clock_ToggleClock(HWIO_GCC_DDR_I_HCLK_CBCR_ADDR, CLK_TOGGLE_ENABLE);
#endif
  Clock_ToggleClock(HWIO_GCC_DDRMC_CH0_CBCR_ADDR, CLK_TOGGLE_ENABLE);


  return TRUE;
}

