#ifndef CLOCKDRIVER_H
#define CLOCKDRIVER_H

/**
==============================================================================

  @file ClockDriver.h

  Clock driver functions for PLL and clock management

  Copyright (c) 2016-2018 QUALCOMM Technologies, Inc.  All Rights Reserved.  
  QUALCOMM Proprietary and Confidential.

==============================================================================
*/

#include <HALcomdef.h>
#include "ClockBoot.h"
#include "ClockBSP.h"

/*=========================================================================
      Definitions
==========================================================================*/
#define CLK_ELEM_SIZE(array)      sizeof((array)[0])
#define CLK_NUM_ELEM(array)       (sizeof(array) / CLK_ELEM_SIZE(array))

#define CLK_BITS_ARE_CLR(nVal, nMask)    (((nVal) & (nMask)) == 0)
#define CLK_BITS_ARE_SET(nVal, nMask)    (((nVal) & (nMask)) == (nMask))

#define CLK_ENABLE_MSK 0x00000001
#define CLK_OFF_MSK    0x80000000
#define CLK_GDSCR_SW_COLLAPSE_MSK 0x00000001
#define CLK_GDSCR_PWR_ON_MSK      0x80000000
#define CLK_GDSCR_TIMEOUT_US      150

/*
 * RCGR update timeout. In practice this should be very short (less than 1us),
 * but it depends on the clock frequency being fed into the RCG. Choosing
 * a very conservative value.
 */
#define CLOCK_UPDATE_TIMEOUT_US 1000

#define DIV2X(d) ((int)(2*(d)))

/*=========================================================================
      Type Definitions
==========================================================================*/

/* These values are used to select sources in Kryo-B */
typedef enum {
  APCS_SOURCE_CXO        = 0x0, // refRoot_Clk
  APCS_SOURCE_GPLL0_MAIN = 0x1, 
  APCS_SOURCE_AG_EARLY   = 0x2, // Apps PLL early output
  APCS_SOURCE_AG_MAIN    = 0x3, // Apps PLL main output
} ClockAPCSSourceType;

typedef enum {
  ACPS_SOURCE_CXO_STATUS_MASK        = (1<<31),
  APCS_SOURCE_GPLL0_MAIN_STATUS_MASK = (1<<30),
  APCS_SOURCE_AG_EARLY_STATUS_MASK   = (1<<29),
  APCS_SOURCE_AG_MAIN_STATUS_MASK    = (1<<28)
} Clock_APCSSourceStatusMaskType;

typedef struct {
  uint8  nCPUSource;
  uint8  nLVal;
  uint8  nDiv2x;
  uint8  nReserved;
  uint32 nFreqKHz;
} ClockAPCSCfgType;


/**
 * Clock config setting CP data for sharing with AOP
 */
typedef struct
{
  uint8 nSHUB;        // System HUB
  uint8 nSNOC;        // System NOC
  uint8 nCNOC;        // Config NOC
  uint8 nCDSP;        // CDSP NOC
  uint8 nCE;          // Crypto Engine
  uint8 nIPA;         // IPA
  uint8 nDDR;         // DDR
  uint8 nReserved;   // Reserved
} ClockCfgCPType;

/*
 * Clock_CBCRtoggleType
 *
 * A type to choose the the operation on clocks(enable/disable).
 */
typedef enum{
  CLK_TOGGLE_DISABLE    = 0,
  CLK_TOGGLE_ENABLE     = 1,
  NUM_CLK_TOGGLE_TYPES
} Clock_CBCRtoggleType;

/* Data structure for Railway data */
typedef struct
{
  char*             CxRail;
  int               nCxRailId;
  railway_voter_t   CxVoter;
  char*             EBIRail;
  int               nEBIRailId;
  railway_voter_t   EBIVoter;
}Clock_RailwayType;

/* Macros to check to see if this is a presilicon simulation platform, that has issues */
#define SOC_RUMI 1
#define SOC_PLATFORM_TYPE_MASK 0x3 
#define RUMI_CHECK() ((HWIO_IN(TCSR_SOC_EMULATION_TYPE) & SOC_PLATFORM_TYPE_MASK) == SOC_RUMI)

/* ============================================================================
**  Function : Clock_EnableSource
** ============================================================================
*/
/*!
    Configure and enable a PLL.  If it is voteable, it will be set for FSM mode
    and voted for using the vote register.

    @param pSource -  [IN] PLL configuration structure
    @param eVoteMaster - [IN] Master who is voting for this PLL
    @param pConfig -  [IN] PLL frequency configuration
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_EnableSource (ClockSourceNodeType *pSource, ClockMasterType eVoteMaster, const ClockSourceFreqConfigType *pConfig );

/* ============================================================================
**  Function : Clock_DisableSource
** ============================================================================
*/
/*!
    Disable a PLL.

    @param pSource -  [IN] PLL configuration structure
    @param eVoteMaster - [IN] Master who is voting for this PLL
    @return
    TRUE -- The PLL was succesfully disabled.
    FALSE -- Disable failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_DisableSource( ClockSourceNodeType *pSource, ClockMasterType eVoteMaster );

/* =========================================================================
**  Function : Clock_ConfigurePLL
** =========================================================================*/
/**
  Configures a PLL but do not enable it.  If the PLL is already enabled or
  set to FSM mode, this will fail.

  @param pSource -  [IN] PLL configuration structure
  @param pConfig -  [IN] PLL frequency configuration
  @return
  TRUE -- Configuration was successful
  FALSE -- The PLL was already enabled or in FSM mode.

*/
boolean Clock_ConfigurePLL(ClockSourceNodeType *pSource, const ClockSourceFreqConfigType *pConfig);


/* =========================================================================
**  Function : Clock_ConfigMux
** =========================================================================*/
/*!
    Configure a clock mux.

    @param pConfig -  [IN] Clock mux config structure
    @return
    TRUE -- Initialization was successful.
    FALSE -- Initialization failed.

    @dependencies
    None.

    @sa None
*/
boolean Clock_ConfigMux (HAL_clk_ClockDomainDescType *pDomain, const HAL_clk_ClockMuxConfigType *pConfig);

/* =========================================================================
**  Function : Clock_ToggleClock
** =========================================================================*/
/*!
    Enable/Disable a Clock.

    @param CBCR_addr - Address of the CBCR register
           enable :-  enable/disable the CBCR
    TRUE -- CBCR programming successful.
    FALSE -- CBCR programming failed.

    @dependencies
    None.

    @sa None
*/

boolean Clock_ToggleClock(uintnt CBCR_addr, Clock_CBCRtoggleType clk_enable);


/* ===========================================================================
**  Clock_PowerDomainEnable
** ======================================================================== */
boolean Clock_PowerDomainEnable ( uintnt nGDSCRAddr );

/* ===========================================================================
**  Clock_PowerDomainDisable
** ======================================================================== */
boolean Clock_PowerDomainDisable ( uintnt nGDSCRAddr );


/* ============================================================================
**  Function : Clock_ToggleEnableList
** ============================================================================
*/
void Clock_ToggleEnableList( uint64* pList );

/* ============================================================================
**  Function : Clock_OverrideMMCXArc
** ============================================================================
  This function overrides the MMCX ARC state to allow Display clocks to be turned on.
  Requirements : MMCX needs to be enabled by direct PMIC writes in boot for this override to be used.
*/
boolean Clock_OverrideMMCXArc( boolean ena );

/* ============================================================================
**  Function : Clock_ChipVersion
** ============================================================================
  A simple function to read and cache the chip version
*/
int32 Clock_ChipVersion();

/* =========================================================================
**  Function : Clock_RailwayConfig
** =========================================================================*/
/**
  Get railway configuration.
*/
Clock_RailwayType *Clock_RailwayConfig (void);

/* =========================================================================
**  Function : Clock_IsBSPSupported
** =========================================================================*/
/**
  Check if BSP entry is supported.
*/
boolean Clock_IsBSPSupported (const ClockHWVersionType *pHWVersion);

/* =========================================================================
**  Function : Clock_GetSourceFreqConfig
** =========================================================================*/
/**
  Get source frequency configuration entry matching nMinFreqKHz.
*/
const ClockSourceFreqConfigType *Clock_GetSourceFreqConfig (ClockSourceNodeType *pSource, uint32 nMinFreqKHz);

/* =========================================================================
**  Function : Clock_GetSourceCalConfig
** =========================================================================*/
/**
  Get source calibration configuration.
*/
const ClockSourceFreqConfigType *Clock_GetSourceCalConfig (ClockSourceNodeType *pSource);

/* =========================================================================
**  Function : Clock_GetSourceRegSettings
** =========================================================================*/
/**
  Get source HSR register settings.
*/
const HAL_clk_SourceRegSettingsType *Clock_GetSourceRegSettings (ClockSourceNodeType *pSource);

/* =========================================================================
**  Function : Clock_GetDomainFreqConfig
** =========================================================================*/
/**
  Get domain frequency configuration matching nMinFreqKHz.
*/
const ClockMuxConfigType *Clock_GetDomainFreqConfig (ClockDomainNodeType *pDomain, uint32 nMinFreqKHz);

/* =========================================================================
**  Function : Clock_GetDomainFreqConfig
** =========================================================================*/
/**
  Get configured domain frequency.
*/
uint32 Clock_GetDomainFrequency (ClockDomainNodeType *pDomain);

/* =========================================================================
**  Function : Clock_GetDomainFMaxConfig
** =========================================================================*/
/**
  Get domain configuration for the max frequency in eCorner.
*/
ClockMuxConfigType *Clock_GetDomainFMaxConfig(ClockDomainNodeType *pDomain, rail_voltage_level eCorner);

/* =========================================================================
**  Function : Clock_SetDomainFreqConfig
** =========================================================================*/
/**
  Set domain frequency configuration.
*/
boolean Clock_SetDomainFreqConfig(ClockDomainNodeType *pDomain, const ClockMuxConfigType *pConfig);

/* =========================================================================
**  Function : Clock_SetDomainFreq
** =========================================================================*/
/**
  Set domain frequency to nMinFreqKHz.
*/
boolean Clock_SetDomainFreq(ClockDomainNodeType *pDomain, uint32 nMinFreqHz);

/* =========================================================================
**  Function : Clock_SetDomainFMax
** =========================================================================*/
/**
  Set domain frequency to the max supported in eCorner.
*/
boolean Clock_SetDomainFMax (ClockDomainNodeType *pDomain, rail_voltage_level eCorner);

/* =========================================================================
**  Function : Clock_SetDomainBootFMax
** =========================================================================*/
/**
  Set domain frequency to the max supported by the default boot corner.
*/
void Clock_SetDomainBootFMax (ClockDomainNodeType *pDomain);

/* =========================================================================
**  Function : Clock_ConfigDivider
** =========================================================================*/
/**
  Set Divider for a given clock.
*/
void Clock_ConfigDivider(HAL_clk_DividerDescType    *pHALDivider, uint32 nDiv);

#endif /* CLOCKDRIVER_H */
