/**
==============================================================================
  @file ClockRamDump.c

  Clock functions for the XBL RAM Dump image, which primarily supports a 
  video splash screen.

==============================================================================
            Copyright (c) 2016-2019 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/


/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include "HALclkHWIO.h"
#include "ClockDriver.h"
#include "ClockBSP.h"
#include <string.h>
#include "busywait.h"
#include "HALclkPLLSettings.h"

/*=========================================================================
                       MACRO DEFINITIONS
==========================================================================*/
#define DIV(div) ((int)2*div)
#define ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))

/*
 * Clock ID macros.
 */
#define CLOCK_MAKE_ID(cat, idx)   (((cat) << 16) | (idx))
#define CLOCK_GET_ID_CATEGORY(id) (((id) & 0xFFFF0000) >> 16)
#define CLOCK_GET_ID_INDEX(id)    ((id) & 0xFFFF)
#define CLOCK_ID_INVALID          0

/*
 * Use a global constant as the handle since we only have one client
 */
#define CLOCK_GLOBAL_HANDLE_ID 0x1CEB00DA

/*=========================================================================
      Function Prototypes
==========================================================================*/
static ClockResult Clock_GetClockId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
);

static ClockResult Clock_GetPowerDomainId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
);

static ClockResult Clock_GetDividerId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
);

/*=========================================================================
      Type Definitions
==========================================================================*/

/*
 * GetId function type.
 */
typedef ClockResult (*ClockGetIdFn) (ClockHandle, const char *, ClockIdType *);

/*
 * ClockIdCategoryType
 *
 * Clock ID categories.
 */
typedef enum
{
  CLOCK_ID_CATEGORY_NONE = 0,
  CLOCK_ID_CATEGORY_CLOCK,
  CLOCK_ID_CATEGORY_POWERDOMAIN,
  CLOCK_ID_CATEGORY_SOURCE,
  CLOCK_ID_CATEGORY_DEBUGMUX,
  CLOCK_ID_CATEGORY_DIVIDER,

  CLOCK_ID_CATEGORY_TOTAL,
} ClockIdCategoryType;

/*=========================================================================
      Data
==========================================================================*/

extern ClockBSPType ClockBSP;

/*
 * Object-specific GetId function pointers.
 */
static ClockGetIdFn ClockGetIdFunctions[] =
{
  Clock_GetClockId,
  Clock_GetPowerDomainId,
  Clock_GetDividerId,
};

/*===========================================================================
                      LOCAL FUNCTION DECLARATIONS
===========================================================================*/

/* =========================================================================
**  Function : Clock_InitSources
** =========================================================================*/
/**
  This function initializes the MMSS clock sources.

  @dependencies
  None.
*/
static int Clock_InitSources( void )
{
  static byte source_init_complete = FALSE;
  int i;

  if (source_init_complete == FALSE)
  {
    Clock_OverrideMMCXArc( TRUE );
    /* Be sure that DISP_CC is available */

    Clock_ToggleClock(HWIO_ADDR(GCC_DISP_AHB_CBCR), CLK_TOGGLE_ENABLE);
    Clock_ToggleClock(HWIO_ADDR(GCC_MMNOC_AT_CBCR), CLK_TOGGLE_ENABLE);

    for (i = 0; i < ClockBSP.nNumSources; i++)
    {
      if (Clock_EnableSource(ClockBSP.aSources[i], CLOCK_MASTER_APCS, NULL) != TRUE) return FALSE;
    }

    source_init_complete = TRUE;
  }
  return TRUE;
}


/* =========================================================================
**  Function : Clock_GetClockId
** =========================================================================*/
/**
  See ClockDriver.h
*/
static ClockResult Clock_GetClockId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  uint32_t i;

  if (!szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  for (i = 0; i < ClockBSP.nNumClocks; i++)
  {
    if (!strcmp(szName, ClockBSP.aClocks[i].szName))
    {
      *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_CLOCK, i);
      return CLOCK_SUCCESS;
    }
  }

  *pId = CLOCK_ID_INVALID;
  return CLOCK_ERROR_NOT_FOUND;
} /* END Clock_GetClockId */


/* =========================================================================
**  Function : Clock_GetPowerDomainId
** =========================================================================*/
/**
  See ClockDriver.h
*/
static ClockResult Clock_GetPowerDomainId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  uint32_t i;

  if (!szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  for (i = 0; i < ClockBSP.nNumPowerDomains; i++)
  {
    if (!strcmp(szName, ClockBSP.aPowerDomains[i].szName))
    {
      *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_POWERDOMAIN, i);
      return CLOCK_SUCCESS;
    }
  }

  *pId = CLOCK_ID_INVALID;
  return CLOCK_ERROR_NOT_FOUND;
} /* END Clock_GetPowerDomainId */


/* =========================================================================
**  Function : Clock_GetDividerId
** =========================================================================*/
/**
  See ClockDriver.h
*/

static ClockResult Clock_GetDividerId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  uint32_t i;

  if (!szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  for (i = 0; i < ClockBSP.nNumDividers; i++)
  {
    if (!strcmp(szName, ClockBSP.aDividers[i].szName))
    {
      *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_DIVIDER, i);
      return CLOCK_SUCCESS;
    }
  }

  *pId = CLOCK_ID_INVALID;
  return CLOCK_ERROR_NOT_FOUND;
} /* END Clock_GetDividerId */

/*=========================================================================
**  Function : Clock_GetClockNode
** =========================================================================*/
/**
  Get pointer to a particular Clock Node based to Clock ID.
*/

static ClockNodeType *Clock_GetClockNode
(
  ClockIdType ClockId
)
{
  ClockIdCategoryType  nCat   = CLOCK_GET_ID_CATEGORY(ClockId);
  uint32_t             nIndex = CLOCK_GET_ID_INDEX(ClockId);

  if (nCat == CLOCK_ID_CATEGORY_CLOCK &&
      nIndex < ClockBSP.nNumClocks)
  {
    return &ClockBSP.aClocks[nIndex];
  }

  return NULL;
} /* END Clock_GetClockNode */


/*=========================================================================
**  Function : Clock_GetPowerDomainNode
** =========================================================================*/
/**
  Get pointer to a particular Power Domain Node based to Clock ID.
*/

static ClockPowerDomainNodeType *Clock_GetPowerDomainNode
(
  ClockIdType ClockId
)
{
  ClockIdCategoryType  nCat   = CLOCK_GET_ID_CATEGORY(ClockId);
  uint32_t             nIndex = CLOCK_GET_ID_INDEX(ClockId);

  if (nCat == CLOCK_ID_CATEGORY_POWERDOMAIN &&
      nIndex < ClockBSP.nNumPowerDomains)
  {
    return &ClockBSP.aPowerDomains[nIndex];
  }

  return NULL;
} /* END Clock_GetPowerDomainNode */


/*=========================================================================
**  Function : Clock_GetDividerNode
** =========================================================================*/
/**
  Get pointer to a particular Power Domain Node based to Clock ID.
*/

static ClockDividerNodeType *Clock_GetDividerNode
(
  ClockIdType ClockId
)
{
  ClockIdCategoryType  nCat   = CLOCK_GET_ID_CATEGORY(ClockId);
  uint32_t             nIndex = CLOCK_GET_ID_INDEX(ClockId);

  if (nCat == CLOCK_ID_CATEGORY_DIVIDER &&
      nIndex < ClockBSP.nNumDividers)
  {
    return &ClockBSP.aDividers[nIndex];
  }

  return NULL;
} /* END Clock_GetDividerNode */

/* =========================================================================
**  Function : Clock_EnableClockEx
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_EnableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  uintnt nCBCRAddr;
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  Clock_InitSources();
  nCBCRAddr = pClock->HALClock.mRegisters.nBranchAddr;

  return Clock_ToggleClock(nCBCRAddr, CLK_TOGGLE_ENABLE) ? 
         CLOCK_SUCCESS : CLOCK_ERROR;
} /* END Clock_EnableClockEx */


/* =========================================================================
**  Function : Clock_EnablePowerDomainEx
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_EnablePowerDomainEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  uintnt nGDSCRAddr;
  uint32_t loops = 200;
  ClockPowerDomainNodeType *pPowerDomain = Clock_GetPowerDomainNode(ClockId);
 
  if (!pPowerDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  nGDSCRAddr = pPowerDomain->HALPowerDomain.nGDSCRAddr;
  outp32(nGDSCRAddr, inp32(nGDSCRAddr) & ~0x1);

  while ((loops > 0) &&  ((inp32(nGDSCRAddr) >> 31) == 0)) {
    loops--;
    busywait(1);
  }

  return (loops != 0) ? CLOCK_SUCCESS : CLOCK_ERROR;
} /* END Clock_EnablePowerDomainEx */


/* =========================================================================
**  Function : Clock_DisableClockEx
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_DisableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  uintnt nCBCRAddr;
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  nCBCRAddr = pClock->HALClock.mRegisters.nBranchAddr;

  return Clock_ToggleClock(nCBCRAddr, CLK_TOGGLE_DISABLE) ? 
         CLOCK_SUCCESS : CLOCK_ERROR;
} /* END Clock_DisableClockEx */


/* =========================================================================
**  Function : Clock_DisablePowerDomainEx
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_DisablePowerDomainEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  uintnt nGDSCRAddr;
  ClockPowerDomainNodeType *pPowerDomain = Clock_GetPowerDomainNode(ClockId);
 
  if (!pPowerDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  nGDSCRAddr = pPowerDomain->HALPowerDomain.nGDSCRAddr;
  outp32(nGDSCRAddr, inp32(nGDSCRAddr) | 0x1);

  return CLOCK_SUCCESS;
} /* END Clock_DisablePowerDomainEx */


/* =========================================================================
**  Function : Clock_IsClockEnabled
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_IsClockEnabled
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  boolean      *pbIsEnabled
)
{
  uintnt nCBCRAddr;
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  nCBCRAddr = pClock->HALClock.mRegisters.nBranchAddr;
  *pbIsEnabled = inp32(nCBCRAddr) & 0x1;

  return CLOCK_SUCCESS;
} /* END Clock_IsClockEnabled */


/* =========================================================================
**  Function : Clock_IsClockOn
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_IsClockOn
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  boolean      *pbIsOn
)
{
  uintnt nCBCRAddr;
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  nCBCRAddr = pClock->HALClock.mRegisters.nBranchAddr;
  *pbIsOn = (inp32(nCBCRAddr)>>31) == 0;

  return CLOCK_SUCCESS;
} /* END Clock_IsClockOn */


/* =========================================================================
**  Function : Clock_SetClockFrequency
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_SetClockFrequencyEx
(
  ClockHandle          hClient,
  ClockIdType          ClockId,
  uint32_t             nFreq,
  ClockFrequencyType   eMatch,
  uint32_t            *pnResultFreq,
  uint32_t             nFlags
)
{
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (eMatch != CLOCK_FREQUENCY_KHZ_AT_LEAST)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  /* One time initialize the MMSS PLLs */
  Clock_InitSources();

  if (Clock_SetDomainFreq(pClock->pDomain, nFreq) != TRUE)
  {
    return CLOCK_ERROR;
  }

  if (pnResultFreq)
  {
    *pnResultFreq = pClock->pDomain->pActiveMuxConfig->nFreqHz;
  }

  return CLOCK_SUCCESS;
} /* END Clock_SetClockFrequency */


/* =========================================================================
**  Function : Clock_SelectExternalClockSourceEx
** =========================================================================*/
/**
  See Clock.h
*/
static ClockResult Clock_SelectExternalClockSourceEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFreqHz,
  uint32_t    nSource,
  uint32_t    nDiv2x,
  uint32_t    nM,
  uint32_t    nN,
  uint32_t    n2D,
  uint32_t    nFlags
)
{
  HAL_clk_ClockMuxConfigType muxConfig = {0};
  ClockNodeType *pClock = Clock_GetClockNode(ClockId);

  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  Clock_InitSources();

  muxConfig.nMuxSel = nSource;
  muxConfig.nDiv2x  = nDiv2x;
  muxConfig.nM      = nM;
  muxConfig.nN      = nN;

  return Clock_ConfigMux(&pClock->pDomain->HALDomain, &muxConfig) ?
         CLOCK_SUCCESS : CLOCK_ERROR;
} /* END Clock_SelectExternalClockSourceEx */


/*===========================================================================
                      PUBLIC FUNCTION DECLARATIONS
===========================================================================*/

/*=========================================================================
**  Function : Clock_Attach
** =========================================================================*/
/**
  See ClockDriver.h
*/
ClockResult Clock_Attach
(
  ClockHandle *phClient,
  const char  *szName
)
{ 
  if (!phClient)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  *phClient = CLOCK_GLOBAL_HANDLE_ID;

  return CLOCK_SUCCESS;
} /* END Clock_Attach */


/*=========================================================================
**  Function : Clock_Detach
** =========================================================================*/
/**
  See Clock.h
*/
ClockResult Clock_Detach
(
  ClockHandle hClient
)
{
  return CLOCK_SUCCESS;
} /* END Clock_Detach */


/* =========================================================================
**  Function : Clock_GetId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{ 
  ClockIdType   nId;
  ClockGetIdFn  fGetId;
  ClockResult   eResult;
  uint32        i;

  if (!hClient || !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  for (i = 0; i < SIZEOF_ARRAY(ClockGetIdFunctions); i++)
  {
    fGetId = ClockGetIdFunctions[i];
    eResult = fGetId(hClient, szName, &nId);
    if (eResult == CLOCK_SUCCESS)
    {
      *pId = nId;
      return CLOCK_SUCCESS;
    }
  }

  *pId = CLOCK_ID_INVALID;
  return CLOCK_ERROR_NOT_FOUND;
} /* END Clock_GetId */


/* =========================================================================
**  Function : Clock_EnableEx
** =========================================================================*/
/**
  See Clock.h
*/
ClockResult Clock_EnableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_EnableClockEx(hClient, ClockId, nFlags);

    case CLOCK_ID_CATEGORY_POWERDOMAIN:
      return Clock_EnablePowerDomainEx(hClient, ClockId, nFlags);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_EnableEx */


/* =========================================================================
**  Function : Clock_DisableEx
** =========================================================================*/
/*
  See Clock.h
*/
ClockResult Clock_DisableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_DisableClockEx(hClient, ClockId, nFlags);

    case CLOCK_ID_CATEGORY_POWERDOMAIN:
      return Clock_DisablePowerDomainEx(hClient, ClockId, nFlags);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_DisableEx */


/* =========================================================================
**  Function : Clock_IsEnabled
** =========================================================================*/
/*
  See Clock.h
*/
ClockResult Clock_IsEnabled
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  boolean      *pbIsEnabled
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_IsClockEnabled(hClient, ClockId, pbIsEnabled);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_IsEnabled */


/* =========================================================================
**  Function : Clock_IsOn
** =========================================================================*/
/*
  See Clock.h
*/
ClockResult Clock_IsOn
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  boolean      *pbIsOn
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_IsClockOn(hClient, ClockId, pbIsOn);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_IsOn */


/* =========================================================================
**  Function : Clock_SetFrequencyEx
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_SetFrequencyEx
(
  ClockHandle          hClient,
  ClockIdType          ClockId,
  uint32_t             nFreq,
  ClockFrequencyType   eMatch,
  uint32_t            *pnResultFreq,
  uint32_t             nFlags
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_SetClockFrequencyEx(
               hClient, ClockId, nFreq, eMatch, pnResultFreq, nFlags);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_SetFrequencyEx */


/* =========================================================================
**  Function : Clock_SelectExternalSourceEx
** =========================================================================*/
/**
  See Clock.h
*/
ClockResult Clock_SelectExternalSourceEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFreqHz,
  uint32_t    nSource,
  uint32_t    nDiv2x,
  uint32_t    nM,
  uint32_t    nN,
  uint32_t    n2D,
  uint32_t    nFlags
)
{
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_SelectExternalClockSourceEx(
               hClient, ClockId, nFreqHz, nSource, nDiv2x, nM, nN, n2D, nFlags);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }
} /* END Clock_SelectExternalSourceEx */

/* =========================================================================
**  Function : Clock_SetDivider
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_SetDivider
(
  ClockHandle          hClient,
  ClockIdType          ClockId,
  uint32_t             nDivider
)
{
  ClockDividerNodeType *pDivider = Clock_GetDividerNode(ClockId);

  if (!pDivider)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  Clock_ConfigDivider(&pDivider->HALDivider, nDivider);

  return CLOCK_SUCCESS;

} /* END Clock_SetDivider */

