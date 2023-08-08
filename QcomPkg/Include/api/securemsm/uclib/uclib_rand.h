#ifndef _UCLIB_RAND
#define _UCLIB_RAND

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Libraray - PRNG API

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_rand.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
 5/14/2017  ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stdlib.h>
#include "uclib_env.h"

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
/**
 * @brief Reads PRNG data and saves them into caller provided buffer.
 *
 * @param env      [in] Pointer to environment structure
 * @param buf      [in] Buffer pointer to save in PRNG data
 * @param buf_sz   [in] PRNG buffer data size
 *
 * @return Number of bytes written to the buffer.
 */
size_t uclib_get_prng_data(env_t *env, uint8_t *buf, size_t buf_sz);

#endif /* _UCLIB_RAND */
