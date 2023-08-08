/*
==============================================================================

FILE:         HALvcs.c

DESCRIPTION:
  Common code for the VCS HAL module.

==============================================================================

                             Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/VcsSharedLib/HALvcs.c#1 $

==============================================================================
            Copyright (c) 2017- 2019 QUALCOMM Technologies Incorporated.  All Rights Reserved.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include <HALvcs.h>
#include "voltage_level.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Typedefs
** ==========================================================================*/

/*
 * HAL_vcs_Type
 *
 * Consolidated set of internal static data for the ldo HAL.
 *
 * mHALCtxt - HAL LDO driver context data
 */
typedef struct
{
  HAL_vcs_ContextType mHALCtxt;
} HAL_vcs_Type;


/* ============================================================================
**    Data
** ==========================================================================*/


/*
 * HAL_vcs
 *
 * Consolidated static data for the LDO HAL.
 *
 * We fill in some non-zero data to ensure that this ends up in the RW
 * segment instead of ZI since the LDO HAL is used in the bootloader
 * before the ZI is cleared.
 */
static HAL_vcs_Type HAL_vcs;


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/


/* ===========================================================================
**  HAL_vcs_Init
**
** ======================================================================== */

void HAL_vcs_Init
(
  HAL_vcs_ContextType *pHALCtxt
)
{
  /*
   * Sanity check
   */
  if (pHALCtxt != NULL)
  {
     /*
      * Save the busy wait function pointer
      */
     HAL_vcs.mHALCtxt.BusyWait = pHALCtxt->BusyWait;

     /*
      * Save the chip info
      */
     HAL_vcs.mHALCtxt.nChipVersion = pHALCtxt->nChipVersion;
     HAL_vcs.mHALCtxt.nChipId = pHALCtxt->nChipId;
     HAL_vcs.mHALCtxt.nChipFamily = pHALCtxt->nChipFamily;
  }

} /* END HAL_vcs_Init */

/* ===========================================================================
**  HAL_vcs_GetChipVersion
**
** ======================================================================== */

uint32 HAL_vcs_GetChipVersion
(
  void
)
{
  return HAL_vcs.mHALCtxt.nChipVersion;

} /* END HAL_vcs_GetChipVersion */


/* ===========================================================================
**  HAL_vcs_GetChipId
**
** ======================================================================== */

uint32 HAL_vcs_GetChipId
(
  void
)
{
  return HAL_vcs.mHALCtxt.nChipId;

} /* END HAL_vcs_GetChipId */


/* ===========================================================================
**  HAL_vcs_GetChipFamily
**
** ======================================================================== */

uint32 HAL_vcs_GetChipFamily
(
  void
)
{
  return HAL_vcs.mHALCtxt.nChipFamily;

} /* END HAL_vcs_GetChipFamily */


/* ===========================================================================
**  HAL_vcs_BusyWait
**
** ======================================================================== */

void HAL_vcs_BusyWait
(
  uint32 nTimeUS
)
{
  if (HAL_vcs.mHALCtxt.BusyWait != NULL)
  {
     HAL_vcs.mHALCtxt.BusyWait(nTimeUS);
  }
  else
  {
    /* We can have our own nop loop here but it won't be precise since
     * we don't know how many time to iterate to meet the required uSec
     * pause - need to know cpu frequency.
     */
  }
}

