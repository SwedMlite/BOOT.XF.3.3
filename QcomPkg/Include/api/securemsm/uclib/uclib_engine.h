#ifndef _UCLIB_ENGINE
#define _UCLIB_ENGINE

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Engines

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_engine.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
 12/21/2017 shl     Added CE BAM VA engine
 2/7/2017   ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
typedef enum {
  UCLIB_ENGINE_INV = 0,
  UCLIB_CE_SW,     /** SW Crypto Engine */
  UCLIB_CE_ARMV8,  /** Crypto Engine using ARMv8 CE extention */
  UCLIB_CE_HWIO,   /** HW Crypto Engine using HWIO Access */
  UCLIB_CE_BAM,    /** HW Crypto Engine using BAM Access */

  UCLIB_ENGINE_MAX_COUNT
}UCLIB_ENGINE_TYPE;

#endif /* _UCLIB_ENGINE */
