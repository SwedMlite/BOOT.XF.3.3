#ifndef _UCLIB_MAC_H
#define _UCLIB_MAC_H

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Libraray - MAC API

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_mac.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
 4/11/2017  ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stddef.h>
#include "uclib_engine.h" /* For UCLIB_ENGINE_TYPE */
#include "uclib_env.h"    /* For UCLIB Environment type */

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/

/* Opaque MAC context pointer handle */
typedef struct mac_ctx_s * UCLIB_MAC_HANDLE;

/* MAC algorithms */
typedef enum {
  UCLIB_MAC_HMAC = 0,
  UCLIB_MAC_CMAC,

  UCLIB_MAC_MAX_ALG_COUNT
} UCLIB_MAC_ALG;

typedef enum {
  UCLIB_MAC_OEM_HW_KEY = 0,      /** OEM HW KEY - default                                            */
  UCLIB_MAC_QC_HW_KEY,           /** QCOM HW KEY                                                     */

  UCLIB_MAC_MAX_HW_KEYS
}UCLIB_MAC_HW_KEY_TYPE;

/* MAC paramater types */
typedef enum {

  UCLIB_MAC_PARAM_SET_HASH_ALG = 0,    /** Possible Values: values enumerated in UCLIB_HASH_ALG                             */

  UCLIB_MAC_PARAM_SET_CIPHER_ALG,      /** Possible Values: values enumerated in UCLIB_CIPHER_ALG                           */

  UCLIB_MAC_PARAM_SET_KEY,             /** Data buffer and size                                                             */

  UCLIB_MAC_PARAM_SET_HW_KEY_TYPE,     /** Possible Values: values enumerated in UCLIB_MAC_HW_KEY_TYPE                      */

  UCLIB_MAC_PARAM_GET_DIGEST_SIZE,     /** Returns required digest size in the context                                      */

  UCLIB_MAC_SET_COPY,                  /** Copies the MAC context passed as an argument into the current MAC context handle */

  UCLIB_MAC_PARAM_MAX

} UCLIB_MAC_PARAM_TYPE;


/**
 * @brief Allocates memory for a context for MAC operations and returns a
 *        handle to the caller.
 *        It is the caller's responsiblity to call uclib_mac_free() to
 *        properly clean up MAC context and release any associated resources.
 *
 * @param env    [in] Pointer to environment structure
 *
 * @return       Non zero value if successful.
 */
UCLIB_MAC_HANDLE uclib_mac_new(env_t *env);

/**
 * @brief Clears the MAC context and releases internal resources.
 *
 * @param h      [in] handle to the MAC context.
 *
 * @return       0 if successful, negative value otherwise.
 */
int uclib_mac_free(UCLIB_MAC_HANDLE h);

/**
 * @brief Resets MAC context and clears internal states in order to re-use the
 *        MAC context for another MAC operation. The interface
 *        retains MAC algorithm, engine and key from previous
 *        initialization.
 *
 * @param h      [in] handle to the MAC context
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_mac_reset(UCLIB_MAC_HANDLE h);

/**
 * @brief Initializes a previously-allocated handle for MAC operations, based
 *        on the alogrithm and engine chosen.
 *
 * @param h      [in] Handle to the MAC context
 * @param algo   [in] MAC algorithm type enumerated in UCLIB_MAC_ALG
 * @param engine [in] Engine type enumerated in UCLIB_ENGINE_TYPE
 *
 * @return       0 if successful, negative value otherwise.
 */
int uclib_mac_init(UCLIB_MAC_HANDLE  h,
                   UCLIB_MAC_ALG     algo,
                   UCLIB_ENGINE_TYPE engine);

/**
 * @brief Sets or gets control or context parameters, related to the operation
 *        of the chosen algorithm. When the paramter name contains _GET_, this
 *        typically signifies that the caller is requesting for the value of a
 *        parameter to be returned to them. Otherwise the parameter signifies
 *        the setting of a control variable.
 *
 * @param h     [in]      handle to the MAC context
 * @param type  [in]      MAC param type (parameter name indicates get/set)
 * @param val   [in]      Integer input parameter
 * @param buf   [in, out] Pointer to a buffer-parameter
 *                        which can be used to pass data to or
 *                        retrieve data from the context
 * @param isz   [in]      Size-parameter, used to indicate the
 *                        length of the buffer parameter
 * @param osz   [out]     Size-parameter, used to indicate the
 *                        length of the buffer being returned
 *
 * @return      0 if successful. negative value otherwise.
 */
int uclib_mac_ctrl(UCLIB_MAC_HANDLE h,
                   UCLIB_MAC_PARAM_TYPE type,
                   int val,
                   uint8_t *buf,
                   size_t isz,
                   size_t *osz);

/**
 * @brief Calculates and updates the MAC result using the given message. This
 *        result is stored in the MAC context.
 *
 * @param h      [in]  handle to the MAC context
 * @param msg    [in]  pointer to the message buffer
 * @param msg_sz [in]  message buffer size
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_mac_update(UCLIB_MAC_HANDLE h, const uint8_t *msg, size_t msg_sz);

/**
 * @brief  Copies the MAC result into the supplied digest buffer. The digest
 *         buffer must be large enough to hold this result.
 *
 * @param h           [in]  handle to the MAC context
 * @param dgst        [in]  pointer to digest buffer
 * @param dgst_sz     [in]  digest buffer size
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_mac_final(UCLIB_MAC_HANDLE h,
                    uint8_t *dgst,
                    size_t dgst_sz);

#endif
