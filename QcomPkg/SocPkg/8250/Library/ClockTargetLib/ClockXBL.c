/**
==============================================================================
  @file ClockXBL.c

  Clock functions for the XBL Loader Clock Driver.

  Copyright (c) 2017,2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================
*/


/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "HALclkHWIO.h"
#include "ClockBoot.h"
#include "ClockDriver.h"
#include "ClockBSP.h"
#include "ClockBSPExtern.h"
#include "railway.h"
#include "busywait.h"
#include "ChipInfo.h"
#include "CoreMsgRam.h"

/*=========================================================================
                       MACRO DEFINITIONS
==========================================================================*/
#define CLK_HW_CTL_MASK 0x2
#define CLK_DCD_ENABLE  0x1
#define AOP_BOOT_COOKIE 0xA0C00C1E

/*=========================================================================
      Data
==========================================================================*/

ClockDomainNodeType *Clock_InitDomains[] =
{
  &ClockDomain_GCC_GCCSYSNOC,
  &ClockDomain_GCC_GCCSYSNOCGCAXI,
  &ClockDomain_GCC_GCCSYSNOCSFAXI,
  &ClockDomain_GCC_GCCAGGRENOC,
  &ClockDomain_GCC_GCCAGGRENOCNORTHSF,
  &ClockDomain_GCC_GCCAGGRENOCWESTSF,
  &ClockDomain_GCC_GCCCONFIGNOC,
  &ClockDomain_GCC_GCCCNOCPERIPH,
  &ClockDomain_GCC_GCCGPUMEMNOCGFX,
  &ClockDomain_GCC_GCCMEMNOC,
  &ClockDomain_GCC_GCCMMUTCU,
  &ClockDomain_GCC_GCCDPM,
};

/* Clock performance CP for sharing with AOP */
ClockCfgCPType Clock_PerfData;

/* DCD control variables. */
boolean Boot_Clock_DCD = TRUE;

/* List of registers to initialize for DCD setup. */
uint64 Clock_DCD_Cfg[] =
{
  // DCD enable registers
  HWIO_GCC_SYS_NOC_GC_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_WEST_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_SOUTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_NORTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_MONAQ_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_SF_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_MONAQ_SF_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_MONAQ_AXI_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_CENTER_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_WEST_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_NORTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_SOUTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_MONAQ_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_MMNOC_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CONFIG_NOC_COMPUTE_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_MMU_TCU_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_MMNOC_HF_QX_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_MMNOC_SF_QX_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_SHRM_DCD_CDIV_DCDR_ADDR, // Used as a backup since DCG has issues
  //HWIO_GCC_MEMNOC_DCD_CDIV_DCDR_ADDR , 0x0  },  // Should be DCG, Clocks HPG Ch 4
  //HWIO_GCC_DDRMC_CH0_ROOT_DCD_CDIV_DCDR_ADDR , 0x0 },  // Should be DCG, Clocks HPG Ch 4
  //HWIO_GCC_DDRMC_CH1_ROOT_DCD_CDIV_DCDR_ADDR , 0x0 },  // Should be DCG, Clocks HPG Ch 4
  //HWIO_GCC_TURING_AXI_DCD_CDIV_DCDR_ADDR , 0x0 },  // Should be DCG, Clocks HPG Ch 4
  HWIO_GCC_CPUSS_AXI_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_WEST_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_NORTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_SOUTH_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_MONAQ_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_WEST_SF_DCD_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_NORTH_SF_DCD_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_CDSP_NOC_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_IPA_2X_DCD_CDIV_DCDR_ADDR,
  //HWIO_GCC_GPU_MEMNOC_GFX_DCD_CDIV_DCDR_ADDR , 0x0  // Should be DCG, Clocks HPG Ch 4},
  HWIO_GCC_AGGRE_NOC_COMPUTE_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_SF_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_SOUTH_SF_DCD_DCDR_ADDR,
  HWIO_GCC_SYS_NOC_LPASS_SF_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_AGGRE_NOC_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_CFG_NOC_LPASS_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_NPU_DMA_DCD_CDIV_DCDR_ADDR,
  HWIO_GCC_TURING_Q6_AXI_DCD_CDIV_DCDR_ADDR,
};

/* ODSC control variables. */
boolean Boot_Clock_ODSC = TRUE;

uint64 Clock_ODSC_Cfg[] =
{
  // HWIO_GCC_SYS_NOC_SF_TCU_CBCR_ADDR, // used for registers local for SMMU, Clocks HPG Ch 11.2
  HWIO_GCC_QMIP_VIDEO_CVP_AHB_CBCR_ADDR,
  HWIO_GCC_QMIP_VIDEO_VCODEC_AHB_CBCR_ADDR,
  HWIO_GCC_QMIP_CAMERA_NRT_AHB_CBCR_ADDR,
  HWIO_GCC_QMIP_CAMERA_RT_AHB_CBCR_ADDR,
  HWIO_GCC_QMIP_DISP_AHB_CBCR_ADDR,
  // HWIO_GCC_QDSS_CFG_AHB_CBCR_ADDR, // Side effect to power sequence, Clocks HPG Ch 11.2
  // HWIO_GCC_AHB2PHY_SOUTH_CBCR_ADDR, // Crash in HLOS
  HWIO_GCC_QUPV3_WRAP_0_S_AHB_CBCR_ADDR,
  HWIO_GCC_QUPV3_WRAP_1_S_AHB_CBCR_ADDR,
  HWIO_GCC_PDM_AHB_CBCR_ADDR,
  // HWIO_GCC_BOOT_ROM_AHB_CBCR_ADDR, // block's main clock, connected to BOOT image rom and other logic, Clocks HPG Ch 11.2
  // HWIO_GCC_TLMM_NORTH_AHB_CBCR_ADDR, // clock is used for summary interrupt processing, Clocks HPG Ch 11.2
  // HWIO_GCC_TLMM_SOUTH_AHB_CBCR_ADDR, // clock is used for summary interrupt processing, Clocks HPG Ch 11.2
  // HWIO_GCC_TLMM_WEST_AHB_CBCR_ADDR, // clock is used for summary interrupt processing, Clocks HPG Ch 11.2

  /*
   * Enabling ODSC on gcc_aoss_cnoc_s_ahb_clk seems to cause AOP hangs when
   * existing CX PC. The reason for this is not understood yet, but disabling
   * it fixes the problem in the APT farm.
   */
  // HWIO_GCC_AOSS_CNOC_S_AHB_CBCR_ADDR,

  HWIO_GCC_SEC_CTRL_AHB_CBCR_ADDR,
  HWIO_GCC_SPDM_CFG_AHB_CBCR_ADDR,
  HWIO_GCC_CE1_AHB_CBCR_ADDR,
  // HWIO_GCC_LPASS_AXIS2_CBCR_ADDR, // clock needed when system is down, Clocks HPG Ch 11.2
  HWIO_GCC_TURING_CFG_AHB_CBCR_ADDR,
  HWIO_GCC_RBCPR_CX_AHB_CBCR_ADDR,
  HWIO_GCC_RBCPR_MX_AHB_CBCR_ADDR,
  // HWIO_GCC_PCIE_0_SLV_AXI_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  // HWIO_GCC_PCIE_0_CFG_AHB_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  // HWIO_GCC_PCIE_1_SLV_AXI_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  // HWIO_GCC_PCIE_1_CFG_AHB_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  HWIO_GCC_VS_CTRL_AHB_CBCR_ADDR,
  HWIO_GCC_MSS_CFG_AHB_CBCR_ADDR,
  // HWIO_GCC_GPU_CFG_AHB_CBCR_ADDR, // Clock used for internal AHB traffic as well as different event sampling, Clocks HPG Ch 11.2
  HWIO_GCC_SP_CFG_AHB_CBCR_ADDR,
  HWIO_GCC_AHB2PHY_NORTH_CBCR_ADDR,
  HWIO_GCC_NPU_CFG_AHB_CBCR_ADDR,
  HWIO_GCC_QUPV3_WRAP_2_S_AHB_CBCR_ADDR,
  HWIO_GCC_RBCPR_MMCX_AHB_CBCR_ADDR,
  // HWIO_GCC_PCIE_2_SLV_AXI_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  // HWIO_GCC_PCIE_2_CFG_AHB_CBCR_ADDR, // used for summary interrupt processing and synchronization, Clocks HPG Ch 11.2
  HWIO_GCC_IPCC_AHB_CBCR_ADDR,
  HWIO_GCC_DPM_AHB_CBCR_ADDR,
  /*
   * External disable signals from outside the NOC keeps these slaves off even
   * when there is a bus transaction directed to one of these slaves. ODSC has
   * been disabled as a workaround for this issue.
   */
  // HWIO_GCC_VIDEO_AHB_CBCR_ADDR,
  // HWIO_GCC_CAMERA_AHB_CBCR_ADDR,
  // HWIO_GCC_DISP_AHB_CBCR_ADDR,
  // HWIO_GCC_UFS_CARD_AHB_CBCR_ADDR,
  // HWIO_GCC_UFS_PHY_AHB_CBCR_ADDR,
  // HWIO_GCC_IPA_AHB_CBCR_ADDR,
};

/* Enable Hardware Control of MEMNOC related clocks */
boolean Boot_Clock_MEMNOC_DCG = TRUE;

uint64 Boot_Clock_MEMNOC_CBCRs[] = 
{
  // HWIO_ADDR(GCC_DDRSS_MSS_Q6_AXI_CBCR),
  // HWIO_ADDR(GCC_MSS_Q6_MEMNOC_AXI_CBCR),
  HWIO_ADDR(GCC_DDRSS_GPU_AXI_CBCR),
  // HWIO_ADDR(GCC_GPU_MEMNOC_GFX_CBCR),
  HWIO_ADDR(GCC_MEMNOC_CBCR),
  // HWIO_ADDR(GCC_SHRM_CBCR), // HW CR QCTDD05409689: This clock feeds into another clock in DPCC
  HWIO_ADDR(GCC_DDRMC_CH0_CBCR),
  HWIO_ADDR(GCC_DDRMC_CH1_CBCR),
  HWIO_ADDR(GCC_TURING_AXI_CBCR),
  HWIO_ADDR(GCC_DDRSS_TURING_AXI_CBCR),
  HWIO_ADDR(GCC_MMU_TCU_CBCR),
  HWIO_ADDR(GCC_DDRSS_TCU_CBCR),
  // HWIO_ADDR(GCC_TURING_TBU0_CBCR),
  // HWIO_ADDR(GCC_TURING_TBU1_CBCR),
};


/*=========================================================================
      Function Prototypes
==========================================================================*/

static boolean Clock_InitCrypto(ClockBootPerfLevelType eSysPerfLevel);
static boolean Clock_InitPLLStatic(void);
static void Clock_EnableDynClkDivide (void);
static void Clock_EnableODSC(void);
static void Clock_InitRefgen (void);
static boolean Clock_InitLPASS(void);
static boolean Clock_DeInitLPASS(void);

extern uint32 Clock_GetAPSSCL0SpeedKHz(void);
extern boolean Clock_ConfigAOP( void );

/*===========================================================================
                      FUNCTION DECLARATIONS
===========================================================================*/

static void Clock_EnableBootClocks(void)
{
  ClockBSPType *pBSP = &ClockBSP;
  uintnt nAddr;
  uint32 nMask;
  uint32 i;

  for (i = 0; i < pBSP->nNumPDEnables; i++)
  {
    nAddr = pBSP->aPDEnable[i];
    outpdw(nAddr, inpdw(nAddr) & ~0x1);
  }

  for (i = 0; i < pBSP->nNumBranchEnables; i++)
  {
    nAddr = pBSP->aBranchEnable[i];
    outpdw(nAddr, inpdw(nAddr) | 0x1);
  }

  for (i = 0; i < pBSP->nNumBranchVotes; i++)
  {
    nAddr = pBSP->aBranchVote[i].nAddr;
    nMask = pBSP->aBranchVote[i].nMask;
    outpdw(nAddr, inpdw(nAddr) | nMask);
  }

}

/* ============================================================================
**  Function : Clock_DebugInit
** ============================================================================
*/
/*!

    This function is called very early in boot.  It is used for work-arounds that
    need to be done before JTAG attaches at the XBL "hold focus button" spin loop.

    @return
    TRUE -- Clean up was successful.
    FALSE -- Clean up failed.

   @dependencies
    You cannot use busywait in this function.

*/
boolean Clock_DebugInit(void)
{  
  /* To improve boot time, speed up the CPU and buses */
  if( ! Clock_SetSysPerfLevel(CLOCK_BOOT_PERF_DEFAULT)) return FALSE;
  if( ! Clock_SetCPUPerfLevel(CLOCK_BOOT_PERF_DEFAULT)) return FALSE;

  /* Enable access to clock controllers */
  Clock_ToggleClock(HWIO_GCC_GPU_CFG_AHB_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  Clock_EnableBootClocks();
  Clock_InitRefgen();

  /*
   * IPA needs to retain their RAM across power collapse.
   *
   * TODO: Unclear if we should do this by default for all RPMh-controlled
   *       SREG_PSCBCs.
   */
  HWIO_OUTF(GCC_IPA_CBCR, FORCE_MEM_CORE_ON, 1);
  HWIO_OUTF(GCC_IPA_2X_CBCR, FORCE_MEM_CORE_ON, 1);

  if( ! Clock_InitPLLStatic()) return FALSE;
  if( ! Clock_InitCrypto(CLOCK_BOOT_PERF_DEFAULT) ) return FALSE;
  if( ! Clock_InitLPASS() ) return FALSE;

  /* Enable DDRSS TURING AXI so we have access to the CDSP throttle blocks.
   * This will be put under hw control again in Clock_ExitBoot */
  Clock_ToggleClock(HWIO_GCC_DDRSS_TURING_AXI_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  /* Enable for ICB access to DCNOC MAXDIV */
  Clock_ToggleClock(HWIO_DPCC_REG_DPCC_DDRSS_TOP_XO_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  /* Turn off these clocks as they are not connected to anything */
  Clock_ToggleClock(HWIO_GCC_AGGRE_NOC_MONAQ_AXI_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_CFG_NOC_MONAQ_AHB_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_IPA_SLEEP_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_NOC_MONAQ_DCD_XO_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_SYS_NOC_MONAQ_AXI_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_SYS_NOC_MONAQ_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  Clock_ToggleClock(HWIO_GCC_SYS_NOC_MONAQ_SF_AXI_CBCR_ADDR, CLK_TOGGLE_DISABLE);


  return TRUE;
}


/* ============================================================================
**  Function : Clock_Init
** ============================================================================
*/
/*!

    This function turns on the required clocks and configures
    Fabric and Krait speeds depending on the System Fabric and
    CPU boot performance level.

    @param eSysPerfLevel   -  [in] Fabric and DDR performance level to initialize.
    @param eCPUPerfLevel   -  [in] Scropion CPU performance level to initialize.

    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

   @dependencies
    None.

*/

boolean Clock_Init( ClockBootPerfLevelType eSysPerfLevel,
                    ClockBootPerfLevelType eCPUPerfLevel)
{
  if( ! Clock_SetCPUPerfLevel(eCPUPerfLevel)) return FALSE;
  if( ! Clock_SetSysPerfLevel(eSysPerfLevel)) return FALSE;

  if(HWIO_INF(GCC_UFS_PHY_ICE_CORE_CBCR, CLK_OFF) == 1)
  {
    Clock_UFSInit( CLOCK_BOOT_PERF_DEFAULT );
  }
  return TRUE;
}


/* ========================================================================
**  Function : Clock_PreDDRInitEx
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
boolean Clock_PreDDRInitEx( uint32 ddr_type )
{
  const ClockMuxConfigType *pConfig;

  pConfig = Clock_GetDomainFreqConfig(&ClockDomain_GCC_GCCDDRMCCH0ROOT, 200000);
  if (!pConfig)
  {
    return FALSE;
  }

  if (!Clock_SetDomainFreqConfig(&ClockDomain_GCC_GCCDDRMCCH0ROOT, pConfig)) return FALSE;
  Clock_PerfData.nDDR = pConfig->HALConfig.nDFSIdx;

  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCSHRM);

  /* Set MSG_RAM base address for passing smem address to AOP since there is no smem driver in AOP
   * This address is based on target specific.
   * It needs to sync up with AOP team when porting this code to new target
   */
  /* TODO: Why is this being done here? Not our responsibility. */
  msg_ram_init_base( (uint32*)(AOP_SS_MSG_RAM_START_ADDRESS_BASE + AOP_SS_MSG_RAM_DRV14_BASE) );

  /*
   * HW CR QCTDD05409689. This clock feeds into another clock in DPCC. The RPMh
   * disable signal will force off gcc_shrm_clk before the DPCC clock, which
   * means the DPCC clock status gets stuck high. This blocks CX collapse,
   * since the ddrss_all_clks_off signal never asserts.
   */
  HWIO_OUTF(GCC_SHRM_CBCR, IGNORE_RPMH_CLK_DIS, 1);

  /*
   * DDRSS HPG section 2.1.1 - GCC Programming
   *
   * These are required, otherwise DDR gets stuck entering power collapse.
   * There should be a HW CR for this, but it hasn't been filed yet.
   */
  HWIO_OUTF(GCC_DDRSS_GPU_AXI_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_MMNOC_HF_QX_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_MMNOC_SF_QX_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_PCIE_SF_TBU_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_SYS_NOC_GC_AXI_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_SYS_NOC_SF_AXI_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_SYS_NOC_SLAVE_AXI_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_TCU_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_DDRSS_TURING_AXI_CBCR, IGNORE_RPMH_CLK_DIS, 1);
  HWIO_OUTF(GCC_MEMNOC_CBCR, IGNORE_RPMH_CLK_DIS, 1);

  return TRUE;
}


/* ========================================================================
**  Function : Clock_PreDDRInit
** ======================================================================*/
/*
    Description: Clock_PreDDRInitEx() was added in 8974 to provide a separate API
    for emergency download (EDL) without including Mxdroop work around. Adding wrapper
    function to avoid compilation erros in 8x26 and 8x10.

    @param None
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_PreDDRInit( uint32 ddr_type )
{
  Clock_RailwayType *pClockRailway;

  /* Setup railways */
  pClockRailway = Clock_RailwayConfig();
  pClockRailway->nCxRailId = RAIL_NOT_SUPPORTED_BY_RAILWAY;
  pClockRailway->nEBIRailId = RAIL_NOT_SUPPORTED_BY_RAILWAY;

  /* Only vote for railways for normal boot (Not deviceprogrammer) */
  if ( PcdGet32 (PcdBuildType) == 0 )
  {
    /* Initialize CX & VDDA_EBI Rails */
    pClockRailway->nCxRailId = rail_id(pClockRailway->CxRail);
    pClockRailway->nEBIRailId = rail_id(pClockRailway->EBIRail);

    if( (RAIL_NOT_SUPPORTED_BY_RAILWAY == pClockRailway->nCxRailId) ||
        (RAIL_NOT_SUPPORTED_BY_RAILWAY == pClockRailway->nEBIRailId) )
    {
      return FALSE;
    }

    pClockRailway->CxVoter = railway_create_voter(pClockRailway->nCxRailId,RAILWAY_CLOCK_DRIVER_VOTER_ID);
    pClockRailway->EBIVoter = railway_create_voter(pClockRailway->nEBIRailId,RAILWAY_CLOCK_DRIVER_VOTER_ID);

    railway_corner_vote(pClockRailway->CxVoter, RAILWAY_NOMINAL);
    railway_corner_vote(pClockRailway->EBIVoter, RAILWAY_SVS);
    railway_transition_rails( );
  }

  return Clock_PreDDRInitEx( ddr_type );
}


/* ========================================================================
**  Function : Clock_I2CInit
** ======================================================================*/
/*
    Description: Configure all clocks needed for EEPROM to be used Pre DDR.

    @param None
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_I2CInit( void )
{
  /* No need to enable I2C for access EEPROM */
  return TRUE;
}


/* ============================================================================
**  Function : Clock_InitForDownloadMode
** ============================================================================
*/
/*!
    Configure clocks for download.  Enable every RAM we want to dump.

    @param None.
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
void Clock_InitForDownloadMode(void)
{
  uint32 mask;

  /* Enable the necessary voteable APCS clocks */
  mask =
    HWIO_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE, IMEM_AXI_CLK_ENA) | 
    HWIO_FMSK(GCC_APCS_CLOCK_BRANCH_ENA_VOTE, BOOT_ROM_AHB_CLK_ENA);
  HWIO_OUTM(GCC_APCS_CLOCK_BRANCH_ENA_VOTE, mask, mask);
}


/* ============================================================================
**  Function : Clock_ExitBoot
** ============================================================================
*/
/*!

    This function turns off clocks that were used during boot, but are not
    needed after boot.  This should be called at the end of boot.

    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

   @dependencies
    None.

*/
boolean Clock_ExitBoot(void)
{
  /* Enable HW clock dividers based on activity. */
  if (Boot_Clock_DCD == TRUE)
  {
    Clock_EnableDynClkDivide();
  }

  if (Boot_Clock_MEMNOC_DCG == TRUE)
  {
    int i;
    for (i = 0; i < CLK_NUM_ELEM(Boot_Clock_MEMNOC_CBCRs); i++ )
    {
      /* With the software enables removed, only the hardware controlled enables
       * will remain to allow the clocks to turn off */
      outpdw(Boot_Clock_MEMNOC_CBCRs[i],
             inpdw(Boot_Clock_MEMNOC_CBCRs[i]) & ~0x1UL); // clear bit 0 (CLK_ENABLE)
    }
  }

  // Enable ODSC
  if (Boot_Clock_ODSC == TRUE)
  {
    Clock_EnableODSC();
  }
  if (!Clock_DeInitLPASS()) return FALSE;

  return TRUE;
}


/* ============================================================================
**  Function : Clock_SetSysPerfLevel
** ============================================================================
*/
/**
  Configure NOCs and RPM to a perf level.

  @param eSysPerfLevel [in]  -  NOCs and RPM performance level to configure.

  @return
  TRUE -- NOCs were configured to perf level successful.
  FALSE -- Configuration failed.

  @dependencies
  None.

  @sa
  Clock_Init.
*/

boolean Clock_SetSysPerfLevel
(
  ClockBootPerfLevelType eSysPerfLevel
)
{
  static ClockBootPerfLevelType eCurrLevel = CLOCK_BOOT_PERF_NONE;
  uint32 i;

  /* Don't switch performance level if it has been set previously */
  if ( eCurrLevel == eSysPerfLevel )
  {
    return TRUE;
  }
  eCurrLevel = eSysPerfLevel;

  for (i = 0; i < SIZEOF_ARRAY(Clock_InitDomains); i++)
  {
    Clock_SetDomainBootFMax(Clock_InitDomains[i]);
  }

  Clock_PerfData.nSHUB = ClockDomain_GCC_GCCMEMNOC.pActiveMuxConfig->HALConfig.nDFSIdx;

  return TRUE;
}


/* ============================================================================
**  Function : Clock_InitCrypto
** ============================================================================
*/
/*!

Configure Crypto clocks.

    @param None.
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/

boolean Clock_InitCrypto
(
  ClockBootPerfLevelType eSysPerfLevel
)
{
  uint32 mask;
  static ClockBootPerfLevelType eCurrLevel = CLOCK_BOOT_PERF_NONE;

  /* Don't switch performance level if it has been set previously */
  if ( eCurrLevel == eSysPerfLevel )
  {
    return TRUE;
  }
  eCurrLevel = eSysPerfLevel;

  if(eSysPerfLevel >= CLOCK_BOOT_PERF_NUM) return FALSE;

  /* Configure crypto engine */
  Clock_SetDomainBootFMax(&ClockDomain_GCC_GCCCE1);

  mask =
    HWIO_FMSK(GCC_RPM_CLOCK_BRANCH_ENA_VOTE, CE1_CLK_ENA) |
    HWIO_FMSK(GCC_RPM_CLOCK_BRANCH_ENA_VOTE, CE1_AXI_CLK_ENA) |
    HWIO_FMSK(GCC_RPM_CLOCK_BRANCH_ENA_VOTE, CE1_AHB_CLK_ENA );
  HWIO_OUTM(GCC_RPM_CLOCK_BRANCH_ENA_VOTE, mask, mask);

  return TRUE;

} /* END Clock_InitCrypto */


/* ============================================================================
**  Function : Clock_InitLPASS
** ============================================================================
*/
/*!

Configure LPASS core clocks to turn on LPASS.

    @param None.
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/

boolean Clock_InitLPASS(void)
{
  /*
   * LPASS Core needs to be powered up so that ICB can progream
   * LPASS with it's SCID.
   */
  Clock_ToggleClock(HWIO_GCC_CFG_NOC_LPASS_CBCR_ADDR, CLK_TOGGLE_ENABLE);
  Clock_ToggleClock(HWIO_GCC_LPASS_CFG_NOC_SWAY_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  /*
   * Following instructions from LPASS HPG V9.0
   * See section 3.4.1.2:
   * Initial POR Power UP sequence of LPASS_CORE_HM performed by APPS
   */
  HWIO_OUTF(LPASS_LPASS_TOP_CC_LPI_SWAY_AHB_LS_CBCR, HW_CTL, 1);
  HWIO_OUTF(LPASS_LPASS_CORE_HM_GDSCR, SW_COLLAPSE, 0);
  while(!HWIO_INF(LPASS_LPASS_CORE_HM_GDSCR, PWR_ON));
  while(!HWIO_INF(LPASS_LPASS_CORE_GDS_HM_READY, LPASS_CORE_HM));
  HWIO_OUTF(LPASS_LPASS_CORE_HM_GDSCR, RETAIN_FF_ENABLE, 1);

  Clock_ToggleClock(HWIO_LPASS_AUDIO_CORE_SYSNOC_MPORT_CORE_CBCR_ADDR, CLK_TOGGLE_ENABLE);

  /*
   * LPASS HPG section 3.3.25 - LPASS CPR Clocks
   *
   * Prevent HW from forcing off the CPR clock during initial configuration
   * when HW isn't capable of driving these signals appropriately yet.
   */
  HWIO_OUTF(LPASS_CPR_CLK_DIS_OVERRIDE, CLK_DIS_OVERRIDE, 0);

  return TRUE;

} /* END Clock_InitLPASS */


/* ============================================================================
**  Function : Clock_DeInitLPASS
** ============================================================================
*/
/*!

Turn off LPASS.

    @param None.
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/

boolean Clock_DeInitLPASS(void)
{
  /*
   * LPASS HPG section 3.3.25 - LPASS CPR Clocks
   *
   * Allow HW to force off the CPR clock again, since initial configuration
   * is now complete.
   */
  HWIO_OUTF(LPASS_CPR_CLK_DIS_OVERRIDE, CLK_DIS_OVERRIDE, 1);

  /*
   * Disable clocks that were enabled in Clock_InitLPASS and not needed anymore.
   */
  Clock_ToggleClock(HWIO_LPASS_AUDIO_CORE_SYSNOC_MPORT_CORE_CBCR_ADDR, CLK_TOGGLE_DISABLE);
  HWIO_OUTF(LPASS_LPASS_CORE_HM_GDSCR, SW_COLLAPSE, 1);
  HWIO_OUTF(LPASS_LPASS_TOP_CC_LPI_SWAY_AHB_LS_CBCR, HW_CTL, 0);
  Clock_ToggleClock(HWIO_GCC_LPASS_CFG_NOC_SWAY_CBCR_ADDR, CLK_TOGGLE_DISABLE);

  return TRUE;

} /* END Clock_DeInitLPASS */


/* ============================================================================
**  Function : Clock_GetClockFrequency
** ============================================================================
*/
/*!
    Get the requested clock frequency in hertz.

    @param
      eBootLogClock [in]  - targeted clock
      pnFrequencyHz [out] - frequency of clock in hertz

    @return
      True iff the requested clock frequency is placed in pnFrequencyHz.

    @dependencies
    None.

    @sa None
*/

boolean Clock_GetClockFrequency(ClockBootLogQueryType eBootLogClock,
                                uint32 *pnFrequencyHz)
{
  boolean ret = TRUE;

  switch(eBootLogClock)
  {
  case CLK_BOOT_LOG_APPS_CLUSTER_0:
    *pnFrequencyHz = (Clock_GetAPSSCL0SpeedKHz() * 1000);
    break;

  case CLK_BOOT_LOG_DDR:
    *pnFrequencyHz = (Clock_DDRSpeed() * 1000);
    break;

  case CLK_BOOT_LOG_SHUB:
    *pnFrequencyHz = Clock_GetDomainFrequency(&ClockDomain_GCC_GCCMEMNOC);
    break;

  case CLK_BOOT_LOG_SHRM:
    *pnFrequencyHz = Clock_GetDomainFrequency(&ClockDomain_GCC_GCCSHRM);
    break;

  default:
    ret = FALSE;
    break;
  }

  return ret;
}


/* ============================================================================
**  Function : Clock_InitRPM()
** ============================================================================
*/
/**
  Perform any initialization needed just before RPM starts.  SMEM is available
  at this time.

  @param
  @return
  TRUE -- Initialization succeeded.
  FALSE -- Initialization failed.

  @dependencies
  None.

  @sa
  Clock_Init.
  boot_smem_init
*/

boolean Clock_InitRPM( void )
{
  boolean aop_ret = Clock_ConfigAOP();

  return aop_ret;
}

/* ============================================================================
**  Function : Clock_InitPLLStatic()
** ============================================================================
*/
/**
  Perform initial static configurations and workarounds
  defined in frequency plan documentation,

  @param
  @return
  TRUE -- Initialization succeeded.
  FALSE -- Initialization failed.

  @dependencies
  None.

*/
boolean Clock_InitPLLStatic( void )
{
  const uint32 mask = HWIO_FMSK(GCC_GPLL0_MODE, OUT_ODD_HW_CTL)  |
                      HWIO_FMSK(GCC_GPLL0_MODE, OUT_EVEN_HW_CTL) |
                      HWIO_FMSK(GCC_GPLL0_MODE, OUT_MAIN_HW_CTL);

  /* Put GPLL0 outputs in HW control */
  HWIO_OUTM( GCC_GPLL0_MODE, mask, mask);

  // Setup GPLL9 spread spectrum setting. 
  HWIO_OUT(GCC_GPLL9_SSC_NUM_STEPS, 0xF);
  HWIO_OUT(GCC_GPLL9_SSC_UPDATE_RATE, 0xF);
  HWIO_OUT(GCC_GPLL9_SSC_DELTA_ALPHA, 8);

  return TRUE;

}


/* ============================================================================
**  Function : Clock_EnableDynClkDivide
** ============================================================================
*/
/**
  Enable dynamic clock dividers.
*/

static void Clock_EnableDynClkDivide (void)
{
  int i;

  /* Initialize the registers for DCD */
  for (i = 0; i < CLK_NUM_ELEM(Clock_DCD_Cfg); i++ )
  {
    outpdw(Clock_DCD_Cfg[i], CLK_DCD_ENABLE);
  }
}


/* ============================================================================
**  Function : Clock_EnableODSC
** ============================================================================
*/
/**
  Enable on-demand slave clocking
*/

static void Clock_EnableODSC(void)
{
  for (int i = 0; i < CLK_NUM_ELEM(Clock_ODSC_Cfg); i++)
  {
    outpdw(Clock_ODSC_Cfg[i], inpdw(Clock_ODSC_Cfg[i]) | CLK_HW_CTL_MASK);
  }
}


/* ============================================================================
**  Function : Clock_InitRefgen
** ============================================================================
*/
/**
  Initialize PHY_REFGEN.
*/

static void Clock_InitRefgen (void)
{
  /*
   * Wait for REFGEN calibration to complete. Calibration starts automatically
   * as soon as its clocks are enabled, which often are enabled in HW by
   * default. It takes around 60us to finished calibration.
   */
  if (!RUMI_CHECK())
  {
    while(!HWIO_INF(PERIPH_SS_PHY_REFGEN_NORTH_RESTRIM_CODE_STATUS, REFGEN_READY));
    while(!HWIO_INF(PHY_REFGEN_SOUTH_RESTRIM_CODE_STATUS, REFGEN_READY));
  }

  /*
   * Once calibration is done, ignore the bg_en_in signal so REFGEN can turn off.
   */
  HWIO_OUT(PERIPH_SS_PHY_REFGEN_NORTH_CMN_REFGEN_CTRL1, 0x8);
  HWIO_OUT(PHY_REFGEN_SOUTH_CMN_REFGEN_CTRL1, 0x8);

  /*
   * QCTDD05586797
   *
   * CSI is connected to REFGEN_SOUTH, but its HW enable requests are sent to
   * REFGEN_NORTH. Ignore the enable signal from CSI (pwrdwn_b_cx[8]) so NORTH
   * isn't kept on unnecessarily. SW will vote for SOUTH as needed in HLOS.
   */
  HWIO_OUT(PERIPH_SS_PHY_REFGEN_NORTH_PWRDWN_CTRL2, 0x1);
}

