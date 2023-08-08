#ifndef _UCLIB_HASH
#define _UCLIB_HASH

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Libraray - Hash API

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_hash.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
 2/7/2017   ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stdlib.h>
#include "uclib_engine.h"
#include "uclib_env.h"

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
/* Opaque hash context pointer */
typedef struct hash_ctx_s * UCLIB_MD_HANDLE;

#define UCLIB_BUF_CACHED        0
#define UCLIB_BUF_UNCACHED      1

#define UCLIB_BAM_BLOCKING      0
#define UCLIB_BAM_NON_BLOCKING  1

/* Possible types for UCLIB_HASH_ORDER parameter in cipher context */
#define UCLIB_HASH_BEFORE_ENCR  0
#define UCLIB_HASH_AFTER_ENCR   1

/* Hash algorithms */
typedef enum {
  UCLIB_SHA1 = 0,

  UCLIB_SHA2_224,
  UCLIB_SHA2_256,
  UCLIB_SHA2_384,
  UCLIB_SHA2_512,

  UCLIB_SHA3_224,
  UCLIB_SHA3_256,
  UCLIB_SHA3_384,
  UCLIB_SHA3_512,

  UCLIB_MD5,
  UCLIB_SM3,

  UCLIB_HASH_MAX_ALG_COUNT
}UCLIB_HASH_ALG;

typedef enum {
  UCLIB_HMAC_OEM_HW_KEY = 0,      /** OEM HW KEY - default                                            */
  UCLIB_HMAC_QC_HW_KEY,           /** QCOM HW KEY                                                     */

  UCLIB_HMAC_MAX_HW_KEYS
}UCLIB_HMAC_HW_KEY_TYPE;

/* Hash Context Parameter Types */
typedef enum {
  UCLIB_HASH_SET_MSG_MEM_TYPE = 0,    /** Possible Values: UCLIB_BUF_CACHED, UCLIB_BUF_UNCACHED                              */

  UCLIB_HASH_SET_BAM_DSC_MEM_TYPE,    /** Possible Values: UCLIB_BUF_CACHED, UCLIB_BUF_UNCACHED                              */
  UCLIB_HASH_SET_BAM_MODE,            /** Possible Values: UCLIB_BAM_BLOCKING, UCLIB_BAM_NON_BLOCKING                        */

  UCLIB_HASH_GET_DIGEST_SIZE,         /** Returns required digest size in the context                                        */

  UCLIB_HASH_SET_HMAC_HW_KEY_TYPE,    /** Possible Values: values enumerated in UCLIB_AUTH_HW_KEY_TYPE                       */

  UCLIB_HASH_SET_HMAC_KEY,            /** Set HMAC mode, the buffer (and size) point to the HMAC key                         */

  UCLIB_HASH_GET_BLOCK_SIZE,          /** Get the internal block size of the hash algorithm in use                           */

  UCLIB_HASH_SET_HASH_ORDER,          /** Possible Values: UCLIB_HASH_BEFORE_ENCR, UCLIB_HASH_AFTER_ENCR                     */
  UCLIB_HASH_GET_HASH_ORDER,          /** Possible Values: UCLIB_HASH_BEFORE_ENCR, UCLIB_HASH_AFTER_ENCR                     */
  UCLIB_HASH_GET_HASH_ALG,            /** Possible Values: UCLIB_HASH_ALG enumerations                                       */

  UCLIB_HASH_SET_COPY,                /** Copies the hash context passed as an argument into the current hash context handle */

  UCLIB_HASH_MAX_PARAM_TYPE_COUNT
}UCLIB_HASH_PARAM_TYPE;

/**
 * @brief Creates a context for hash operation and returns a
 *        handle to the caller. It is the caller responsiblity
 *        to call uclib_hash_free() to properly clean up hash
 *        context and release the resources.
 *
 * @param env    [in] Pointer to environment structure
 *
 * @return Non zero value if successful.
 */
UCLIB_MD_HANDLE uclib_hash_new(env_t *env);

/**
 * @brief Zeros hash context and releases internal resources.
 *
 * @param h      [in] handle to the hash context
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_free(UCLIB_MD_HANDLE h);

/**
 * @brief Resets internal states in order to use the handle for
 *        fresh hash operation. The interface retains the hash
 *        algorithm and engine that user has already initialized
 *        for the same handle using Hash Init interface.
 *
 * @param h      [in] handle to the hash context
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_reset(UCLIB_MD_HANDLE h);

/**
 * @brief Writes/reads hash context parameters. Parameters can
 *        be passed as value using [val] or as an array of bytes
 *        (8-bit) using [ibuf, isz] arguments. If client does
 *        not know the required buffer size for a type, it can
 *        call the API with ibuf as NULL and provide valid
 *        pointer to osz to retrieve required buffer size for
 *        associated parameter. Refer to UCLIB_HASH_PARAM_TYPE
 *        definition for more details of each parameter type. To
 *        read any hash parameter, [ibuf, isz] are required.
 *
 * @param h      [in] handle to the hash context
 * @param type   [in] Hash context parameter type
 * @param val    [in] Hash context parameter can be passed by
 *               value using this parameter.
 * @param ibuf   [in, out] pointer to buffer in order to
 *               write/read to/from hash context
 * @param isz    [in] ibuf size in bytes
 * @param osz    [out] pointer to required size on return from
 *               API
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_ctrl(UCLIB_MD_HANDLE h,
                    UCLIB_HASH_PARAM_TYPE type,
                    int val,
                    uint8_t *ibuf,
                    size_t isz,
                    size_t *osz);

/**
 * @brief Initializes hash context based on requested hash
 *        algorithm and acceleration engine. If engine parameter
 *        is passed as zero, the default engine will be used.
 *        The default engine is defined in UCLIB configuration
 *        file.
 *
 * @param h      [in] handle to the hash context
 * @param alg    [in] hash type enumerated in UCLIB_HASH_ALG
 * @param engine [in] engine type enumerated in
 *               UCLIB_ENGINE_TYPE
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_init(UCLIB_MD_HANDLE h, UCLIB_HASH_ALG alg, UCLIB_ENGINE_TYPE engine);

/**
 * @brief  Calculates hash of a message. The hash result is
 *         stored in hash context. API returns error when one
 *         passes null pointer message or (msg + msg_sz) range
 *         causes address overflow. Hash of zero-length message
 *         is supported.
 *
 * @param h        [in] handle to the hash context
 * @param msg      [in] pointer to message buffer
 * @param msg_sz   [in] message buffer size
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_update(UCLIB_MD_HANDLE h, const uint8_t *msg, size_t msg_sz);

/**
 * @brief Copies hash result to digest buffer. Digest buffer
 *        size should be large enough for copying hash result.
 *        User can retrieve required digest buffer size using
 *        uclib_hash_ctrl api. API returns error when caller
 *        passes null pointer digest or digest size as zero.
 *        Digest buffer address range represented by [dgst,
 *        dgst_sz] should not cause address overflow or API
 *        returns with error otherwise.
 *
 * @param h         [in]    handle to the hash context
 * @param dgst      [in]    pointer to digest buffer
 * @param dgst_sz   [in]    digest buffer size
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_final(UCLIB_MD_HANDLE h, uint8_t *dgst, size_t dgst_sz);

#endif /* _UCLIB_HASH */
