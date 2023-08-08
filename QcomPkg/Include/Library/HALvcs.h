#ifndef __HALVCS_H__
#define __HALVCS_H__
/*
==============================================================================

FILE:         HALcpu.h

DESCRIPTION:
  Common includes for the LDO HAL module.

==============================================================================

                             Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/Include/Library/HALvcs.h#1 $

==============================================================================
            Copyright (c) 2017 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


#include <HALcomdef.h>

/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/
/*
 * HAL_vcs_Context
 *
 *
 *  BusyWait     - Pointer to busy wait function.
 *                 Assumption: Will be implemented or passed down by the
 *                 top level driver. If this function pointer is NULL then
 *                 HAL modules that require a wait/pause may fail - this
 *                 will be functional failure and not compile time failure.
 *
 *  nChipVersion - Version of the chip. Compare against 
 *                 CHIP_VERSION(major, minor).
 *  nChipId      - ID of the chip.
 *  nChipFamily  - Family of the chip.
 */
typedef struct
{
  void (*BusyWait) (uint32 uSeconds);
  uint32 nChipVersion;
  uint32 nChipId;
  uint32 nChipFamily;
} HAL_vcs_ContextType;


/*============================================================================

               FUNCTION DECLARATIONS FOR MODULE

============================================================================*/

/*=========================================================================
**  Function : HAL_vcs_Init
** =========================================================================*/
/**
  Initialize the LDO HAL. 

  @param pHALCtxt [in] HAL LDO context.

  @return 
  Nothing.

  @dependencies
  None.
*/

void HAL_vcs_Init
(
  HAL_vcs_ContextType *pHALCtxt
);

/*=========================================================================
**  Function : HAL_vcs_GetChipVersion
** =========================================================================*/
/**
  Return the chip version.

  @return 
  Chip version.

  @dependencies
  None.
*/

uint32 HAL_vcs_GetChipVersion
(
  void
);


/*=========================================================================
**  Function : HAL_vcs_GetChipId
** =========================================================================*/
/**
  Return the chip ID.

  @return 
  Chip ID.

  @dependencies
  None.
*/

uint32 HAL_vcs_GetChipId
(
  void
);


/*=========================================================================
**  Function : HAL_vcs_GetChipFamily
** =========================================================================*/
/**
  Return the chip family.

  @return 
  Chip family.

  @dependencies
  None.
*/

uint32 HAL_vcs_GetChipFamily
(
  void
);


void HAL_vcs_BusyWait
(
  uint32 nTimeUS
);


#endif  /* __HALVCS_H__ */ 

