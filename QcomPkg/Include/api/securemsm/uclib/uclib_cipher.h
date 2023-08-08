#ifndef _UCLIB_CIPHER
#define _UCLIB_CIPHER

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Cipher API

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_cipher.h#1 $
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
#include <stdlib.h>
#include <stdbool.h>
#include "uclib_engine.h"
#include "uclib_hash.h"
#include "uclib_env.h"

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
/* Opaque cipher context pointer */
typedef struct cipher_ctx_s * UCLIB_CIPHER_HANDLE;

/* Encrypt arg. definitions for uclib_cipher_init */
#define UCLIB_ENCRYPT          true
#define UCLIB_DECRYPT          false

/* Cipher algorithms */
typedef enum {
  UCLIB_DES = 0,
  UCLIB_3DES,
  UCLIB_AES128,
  UCLIB_AES192,
  UCLIB_AES256,

  UCLIB_CIPHER_MAX_ALG_COUNT
}UCLIB_CIPHER_ALG;

/* Cipher Modes */
typedef enum {
  /* Confidentiality */
  UCLIB_ECB = 0,
  UCLIB_CBC,
  UCLIB_CTR,
  UCLIB_CTS,
  UCLIB_IDSA,
  UCLIB_XTS,

  /* Confidentiality  and integrity */
  UCLIB_CCM,
  UCLIB_GCM,

  /* HashCipher Modes */
  UCLIB_HC_CBC,
  UCLIB_HC_CTR,
  UCLIB_HC_CTS,

  /* VA Cipher Modes */
  UCLIB_CBC_VA,
  UCLIB_CTR_VA,

  UCLIB_CIPHER_MAX_MODE_COUNT
}UCLIB_CIPHER_MODE;

/* Plaintext PAD types */
typedef enum {
  UCLIB_CIPHER_NO_PAD = 0,          /** No padding - default                                            */
  UCLIB_CIPHER_ZERO,                /** Padding with Zero                                               */
  UCLIB_CIPHER_ISO10126,            /** Padding with random number                                      */
  UCLIB_CIPHER_PKCS7,               /** Padding with padding length                                     */

  UCLIB_CIPHER_MAX_PAD_COUNT
}UCLIB_CIPHER_PAD;

typedef enum {
  UCLIB_CIPHER_OEM_HW_KEY = 0,      /** OEM HW KEY - default                                            */
  UCLIB_CIPHER_QC_HW_KEY,           /** QCOM HW KEY                                                     */

  UCLIB_CIPHER_MAX_HW_KEYS
}UCLIB_CIPHER_HW_KEY_TYPE;

/* VA Operation Modes */
typedef enum {
  UCLIB_CIPHER_VA_OP_INVALID = 0,   /** Invalid - default                                               */
  UCLIB_CIPHER_VA_OP_ENCRYPT,       /** Encrypt                                                         */
  UCLIB_CIPHER_VA_OP_DECRYPT,       /** Decrypt                                                         */
  UCLIB_CIPHER_VA_OP_COPY,          /** Copy                                                            */

  UCLIB_CIPHER_MAX_VA_OP_COUNT
}UCLIB_CIPHER_VA_OP_MODE;

/* Cipher Context Parameter Types */
typedef enum {
  UCLIB_CIPHER_SET_DIR = 0,         /** Possible Values: UCLIB_ENCRYPT, UCLIB_DECRYPT                                          */
  UCLIB_CIPHER_GET_DIR,             /** Possible Values: UCLIB_ENCRYPT, UCLIB_DECRYPT                                          */

  UCLIB_CIPHER_GET_ALG,             /** Possible Values: values enumerated in UCLIB_CIPHER_ALG                                 */
  UCLIB_CIPHER_GET_MODE,            /** Possible Values: values enumerated in UCLIB_CIPHER_MODE                                */
  UCLIB_CIPHER_GET_ENG,             /** Possible Values: values enumerated in UCLIB_ENGINE_TYPE                                */

  UCLIB_CIPHER_SET_HW_KEY_TYPE,     /** Possible Values: values enumerated in UCLIB_CIPHER_HW_KEY_TYPE                         */

  UCLIB_CIPHER_SET_KEY,             /** Data buffer and size                                                                   */
  UCLIB_CIPHER_GET_KEY,             /** Data buffer and size                                                                   */
  UCLIB_CIPHER_SET_IV,              /** Data buffer and size                                                                   */
  UCLIB_CIPHER_GET_IV,              /** Data buffer and size                                                                   */
  UCLIB_CIPHER_SET_NONCE,           /** Data buffer and size                                                                   */

  UCLIB_CIPHER_SET_XCM_PAYLOAD_LEN, /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_SET_XCM_TAG_LEN,     /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_SET_XCM_HDR_LEN,     /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_SET_XCM_TAG,         /** CCM/GCM Params: Data buffer and size                                                   */
  UCLIB_CIPHER_GET_XCM_PAYLOAD_LEN, /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_GET_XCM_TAG_LEN,     /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_GET_XCM_HDR_LEN,     /** CCM/GCM Params: Possible Values: 0 to MAX_UINT32                                       */
  UCLIB_CIPHER_GET_XCM_TAG,         /** CCM/GCM Params: Data buffer and size                                                   */

  UCLIB_CIPHER_SET_XTS_DU_SIZE,     /** Possible Values: cipher block size to 2^20 bytes                                       */
  UCLIB_CIPHER_GET_XTS_DU_SIZE,     /** Possible Values: cipher block size to 2^20 bytes                                       */
  UCLIB_CIPHER_SET_XTS_KEY,         /** Data buffer and size                                                                   */

  UCLIB_CIPHER_SET_COUNTER_SZ,      /** Possible Values: 32 to 128 bits                                                        */

  UCLIB_CIPHER_SET_PAD_TYPE,        /** Possible Values: all modes in UCLIB_CIPHER_PAD                                         */
  UCLIB_CIPHER_GET_PAD_TYPE,        /** Possible Values: all modes in UCLIB_CIPHER_PAD                                         */

  UCLIB_CIPHER_SET_HASH_ALG,        /** Possible Values: values enumerated in UCLIB_HASH_ALG                                   */
  UCLIB_CIPHER_SET_HASH_ORDER,      /** Possible Values: UCLIB_HASH_BEFORE_ENCR, UCLIB_HASH_AFTER_ENCR                         */

  UCLIB_CIPHER_SET_BAM_PIPE,        /** Set the bam pipe set for CE                                                            */
  UCLIB_CIPHER_GET_BAM_PIPE,        /** Get the bam pipe set for CE                                                            */

  UCLIB_CIPHER_SET_VA_OP_MODE,      /** Set Operation Mode using VA - UCLIB_CIPHER_VA_OP_MODE                                  */

  UCLIB_CIPHER_SET_COPY,            /** Copies the cipher context passed as an argument into the current cipher context handle */

  UCLIB_CIPHER_SET_PIPE_TIMER,      /** Set the timeout for the pipe which will be configured by this context                  */

  UCLIB_CIPHER_CONFIG_BAM_PIPE,     /** Configures the selected BAM pipe with options from the current context                 */

  UCLIB_CIPHER_SET_PATT_OFFSET,     /** Set pattern offset                                                                     */
  UCLIB_CIPHER_SET_PATT_DATA_SIZE,  /** Set pattern processing data size                                                       */
  UCLIB_CIPHER_SET_PATT_SIZE,       /** Set pattern size                                                                       */

  UCLIB_CIPHER_SET_BLOCK_OFFSET,    /** Set the partial block offset                                                           */

  UCLIB_CIPHER_USE_ODD_KEYS,        /** Set a flag to use odd keys. Pipe keys set and used by this context will be odd keys.   */
  UCLIB_CIPHER_USE_EVEN_KEYS,       /** Clear the flag to use odd keys. Pipe keys set and used by this context will be even.   */

  UCLIB_CIPHER_MAX_PARAM_TYPE_COUNT
}UCLIB_CIPHER_PARAM_TYPE;


/**
 * @brief Creates a context for cipher operation and returns a
 *        handle to the caller. It is the caller responsiblity
 *        to call uclib_cipher_free() to properly clean up
 *        cipher context and release the resources.
 *
 * @param env    [in] Pointer to environment structure
 *
 * @return Non zero value if successful.
 */
UCLIB_CIPHER_HANDLE uclib_cipher_new(env_t *env);

/**
 * @brief Clears cipher context and releases internal resources.
 *
 * @param h      [in] handle to the cipher context
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_free(UCLIB_CIPHER_HANDLE h);

/**
 * @brief Resets internal states in order to use the handle for
 *        fresh cipher operation. The interface retains the
 *        cipher algorithm, mode, engine, direction, and key
 *        that user has already initialized for the same handle
 *        using Cipher Init and Ctrl interfaces. IV/Nonce has to
 *        be re-initialized.
 *
 * @param h      [in] handle to the cipher context
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_reset(UCLIB_CIPHER_HANDLE h);

/**
 * @brief Writes/reads cipher context parameters. Parameters can
 *        be passed as value using [val] or as an array of bytes
 *        (8-bit) using [ibuf, isz] arguments. If client does
 *        not know the required buffer size for a type, it can
 *        call the API with ibuf as NULL and provide valid
 *        pointer to osz to retrieve required buffer size for
 *        associated parameter. Refer to UCLIB_CIPHER_PARAM_TYPE
 *        definition for more details of each parameter type. To
 *        read any cipher parameter, [ibuf, isz] are required.
 *
 * @param h      [in] handle to the cipher context
 * @param type   [in] Cipher context parameter type
 * @param val    [in] Cipher context parameter can be passed by
 *               value using this parameter.
 * @param ibuf   [in, out] pointer to buffer in order to
 *               write/read to/from cipher context
 * @param isz    [in] ibuf size in bytes
 * @param osz    [out] pointer to required size on return from
 *               API
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_ctrl(UCLIB_CIPHER_HANDLE h,
                      UCLIB_CIPHER_PARAM_TYPE type,
                      int val,
                      uint8_t *ibuf,
                      size_t isz,
                      size_t *osz);

/**
 * @brief Initializes cipher context based on requested cipher
 *        algorithm, cipher mode and acceleration engine. If
 *        engine parameter is passed as zero, the default engine
 *        will be used. The default engine is defined in UCLIB
 *        configuration file. User can set key and iv parameters
 *        later using uclib_cipher_ctx_ctrl API and passes NULL
 *        as either of key and iv parameters. Key and IV buffers
 *        size are implicitly specified by the cipher mode
 *        passed in the api. Encrypt parameter controls cipher
 *        direction in the context (Encryption vs. Decryption)
 *
 * @param h       [in] handle to the cipher context
 * @param alg     [in] cipher alg enumerated in UCLIB_CIPHER_ALG
 * @param mode    [in] cipher mode enumerated in
 *                UCLIB_CIPHER_MODE
 * @param engine  [in] engine type enumerated in
 *                UCLIB_ENGINE_TYPE
 * @param encrypt [in] direction (true: Encrypt, false:
 *                 Decrypt)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_init(UCLIB_CIPHER_HANDLE h,
                      UCLIB_CIPHER_ALG alg,
                      UCLIB_CIPHER_MODE mode,
                      UCLIB_ENGINE_TYPE engine,
                      bool  encrypt);

/**
 * @brief  Encrypts/Decrypts input buffer [ibuf, isz], saves the
 *         cipher/plain text to output buffer [obuf, osz] and
 *         saves cipher context for further updates. The API
 *         will update output size on successful return in
 *         vld_osz pointer if provided by caller.
 *
 * @param h        [in]  handle to the cipher context
 * @param ibuf     [in]  pointer to input buffer
 * @param isz      [in]  input buffer size
 * @param obuf     [in]  pointer to output buffer
 * @param osz      [in]  output buffer size
 * @param vld_osz  [out] pointer to output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_update(UCLIB_CIPHER_HANDLE h,
                        const uint8_t *ibuf, size_t isz,
                        uint8_t *obuf, size_t osz,
                        size_t *vld_osz);

/**
 * @brief  Encrypt/Decrypt the last segment of input buffer
 *         saved in cipher context and saves the cipher/plain
 *         text to output buffer [obuf, osz]. The API will
 *         update output size on successful return in vld_osz
 *         pointer if provided by caller.
 *
 * @param h        [in] handle to the cipher context
 * @param obuf     [in] pointer to output buffer
 * @param osz      [in] pointer output buffer size
 * @param vld_osz  [out] pointer output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_final(UCLIB_CIPHER_HANDLE h,
                       uint8_t *obuf, size_t osz,
                       size_t *vld_osz);

/**
 * @brief  Updates additional authentication data when
 *         authenticated cipher mode (e.g CCM/GCM) is selected.
 *         It returns failure for other cipher modes.
 *
 * @param h        [in]  handle to the cipher context
 * @param aad      [in]  pointer to AAD buffer
 * @param aad_sz   [in]  AAD buffer size
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_cipher_update_aad(UCLIB_CIPHER_HANDLE h,
                            const uint8_t *aad, size_t aad_sz);

/**
 * @brief  Encrypts/Decrypts input buffer [ibuf, isz], saves the
 *         cipher/plain text to output buffer [obuf, osz],
 *         calculates hash of cipher/plain text and saves
 *         cipher/hash context for further updates. The API will
 *         update output size on successful return in vld_osz
 *         pointer if provided by caller.
 *
 * @param h        [in]  handle to the cipher context
 * @param ibuf     [in]  pointer to input buffer
 * @param isz      [in]  input buffer size
 * @param obuf     [in]  pointer to output buffer
 * @param osz      [in]  output buffer size
 * @param vld_osz  [out] pointer to output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_cipher_update(UCLIB_CIPHER_HANDLE h,
                             const uint8_t *ibuf, size_t isz,
                             uint8_t *obuf, size_t osz,
                             size_t *vld_osz);

/**
 * @brief  Encrypt/Decrypt the last segment of input buffer
 *         saved in cipher context, calculates hash of
 *         cipher/plain text in hash context and saves the
 *         cipher/plain text to output buffer [obuf, osz]. The
 *         API will update output size on successful return in
 *         vld_osz pointer if provided by caller. The hash
 *         result is stored in digest buffer [dgst, dgst_sz]
 *         provided by caller.
 *
 * @param h        [in] handle to the cipher context
 * @param dgst     [in] pointer to digest buffer
 * @param dgst_sz  [in] digest buffer size
 * @param obuf     [in] pointer to output buffer
 * @param osz      [in] output buffer size
 * @param vld_osz  [out] pointer to output buffer size after
 *                 returning from API (optional)
 *
 * @return UCLIB_SUCCESS if successful. UCLIB Error Code
 *         otherwise.
 */
int uclib_hash_cipher_final(UCLIB_CIPHER_HANDLE h,
                            uint8_t *dgst, size_t dgst_sz,
                            uint8_t *obuf, size_t osz,
                            size_t *vld_osz);


/**
 * @brief  Cipher operations for CE BAM virtual address cases
 *         This function is called when SMMU virtual addresses are used
 *
 * @param h            [in]  handle to the cipher context
 * @param in_va        [in]  input virtual address
 * @param in_va_len    [in]  input virtual address length
 * @param out_va       [in]  output virtual address
 * @param out_va_len   [in]  output virtual address length
 * @param copy         [in]  direction (true: copy through CE, false: not copy)
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_cipher_op_bam_va( UCLIB_CIPHER_HANDLE  h,
                            uintptr_t            in_va,
                            size_t               in_va_len,
                            uintptr_t            out_va,
                            size_t               out_va_len,
                            bool                 copy );

#endif /* _UCLIB_CIPHER */
