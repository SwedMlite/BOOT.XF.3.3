#ifndef _UCLIB_PKEY_H
#define _UCLIB_PKEY_H

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Libraray - PKEY API

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_pkey.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------

 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stddef.h>
#include "uclib_engine.h" /* For UCLIB_ENGINE_TYPE */
#include "uclib_env.h" /* For UCLIB Environment type */

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/

/* Opaque PKEY context pointer handle */
typedef struct pkey_ctx_s * UCLIB_PKEY_HANDLE;

/* PKEY algorithms */
typedef enum {
  UCLIB_PKEY_RSA = 0,
  UCLIB_PKEY_EC,
  UCLIB_PKEY_SM2,

  UCLIB_PKEY_MAX_ALG_COUNT
} UCLIB_PKEY_ALG;

/* PKEY padding types */
typedef enum {
  UCLIB_PKEY_PAD_NONE = 0,      /* padding type NONE */
  UCLIB_PKEY_PAD_PKCSV15,       /* padding type PKCSV1.5 */
  UCLIB_PKEY_PAD_OAEP,          /* padding type OAEP */
  UCLIB_PKEY_PAD_PSS,           /* padding type PSS */

  UCLIB_PKEY_PADDING_MAX
} UCLIB_PKEY_PADDING_TYPE;

/* EC Curve types */
typedef enum {
  UCLIB_EC_CURVE_P160 = 0,
  UCLIB_EC_CURVE_P192,
  UCLIB_EC_CURVE_P224,
  UCLIB_EC_CURVE_P256,
  UCLIB_EC_CURVE_P384,
  UCLIB_EC_CURVE_P521,

  UCLIB_EC_CURVE_MAX
} UCLIB_EC_CURVE_ID;

/* PKEY paramater types */
typedef enum {

  /* Parameter of type UCLIB_PKEY_PADDING_TYPE will be used */
  UCLIB_PKEY_PARAM_SET_PAD_TYPE = 0,

  /* Auto recover the salt length if PSS padding type is used */
  UCLIB_PKEY_PARAM_SET_PSS_AUTORECOVER,

  /* Parameter of type UCLIB_HASH_ALG will be used internally for applicable
   * padding schemes */
  UCLIB_PKEY_PARAM_SET_MD_ALG,

  /* Parameter of type UCLIB_HASH_ALG will be used internally for applicable
   * MGF1 schemes */
  UCLIB_PKEY_PARAM_SET_MGF1_MD_ALG,

  /* Sets the key size (in bits) */
  UCLIB_PKEY_PARAM_SET_KEYGEN_BITS,

  /* Gets the key size (in bytes) */
  UCLIB_PKEY_PARAM_GET_KEYSIZE_BITS,

  /* Accepts a byte-array and length to set the modulus.
   * When working with EC curves, this accepts a hexadecimal string and length
   * to set the modulus for the curve
   */
  UCLIB_PKEY_PARAM_SET_MOD,

  /* Accepts a byte-array and length to set the public key/exponent */
  UCLIB_PKEY_PARAM_SET_PUBKEY,

  /* Accepts a byte-array and length to set the private exponent */
  UCLIB_PKEY_PARAM_SET_PRIVKEY,

  /* Accepts a byte-array and length to set the peer public key */
  UCLIB_PKEY_PARAM_SET_PEERKEY,

  /* Use the CRT algorithm */
  UCLIB_PKEY_PARAM_SET_CRT,

  /* Accepts a parameter of type integer to set the salt length to be used
   * with PSS padding
   */
  UCLIB_PKEY_PARAM_SET_SALT_LEN,

  /* Accepts an unsigned character buffer, along with a length, to set the
   * label to be used with OAEP padding
   */
  UCLIB_PKEY_PARAM_SET_LABEL,

  /* Accepts a byte-array and length to return the modulus */
  UCLIB_PKEY_PARAM_GET_MOD,

  /* Accepts a byte-array and length to return the public exponent/key */
  UCLIB_PKEY_PARAM_GET_PUBKEY,

  /* Accepts a byte-array and length to return the private exponent/key */
  UCLIB_PKEY_PARAM_GET_PRIVKEY,

  /* Accepts a curve ID to initialize the EC parameters */
  UCLIB_PKEY_PARAM_SET_EC_CURVE,

  /* Accepts a hexadecimal string and length to set the a-coefficient of the
   * curve
   */
  UCLIB_PKEY_PARAM_SET_COEFFICIENT_A,

  /* Accepts a hexadecimal string and length to set the b-coefficient of the
   * curve
   */
  UCLIB_PKEY_PARAM_SET_COEFFICIENT_B,

  /* Accepts a hexadecimal string and length to set the X co-ordinate of the
   * generator/base point of the curve
   */
  UCLIB_PKEY_PARAM_SET_BASE_X,

  /* Accepts a hexadecimal string and length to set the Y co-ordinate of the
   * generator/base point of the curve
   */
  UCLIB_PKEY_PARAM_SET_BASE_Y,

  /* Accepts a hexadecimal string and length to set the order of the base point
   * of the curve
   */
  UCLIB_PKEY_PARAM_SET_BASE_N,

  /* Accepts a hexadecimal string and length to set the co-factor of the group
   * generated by the base point
   */
  UCLIB_PKEY_PARAM_SET_COFACTOR,

  /* Set the user 'identifier' - used primarily with SM2 sign, verify and
   * key exchange operations.
   */
  UCLIB_PKEY_PARAM_SET_IDENTIFIER,
  UCLIB_PKEY_PARAM_SET_PEER_IDENTIFIER,

  /* Get the size of the signature in bytes */
  UCLIB_PKEY_PARAM_GET_SIGNATURE_SIZE,

  /* Generate and retrieve the parameter 'R' (R=[r]G) for SM2 shared-key
   * derivation
   */
  UCLIB_PKEY_PARAM_GET_SHARED_KEY_PARAM,

  /* Set the peer's parameter 'R', used in shared-key derivation for SM2 */
  UCLIB_PKEY_PARAM_SET_PEER_SHARED_KEY_PARAM,

  /* Set whether the user is the shared-key derivation initiator */
  UCLIB_PKEY_PARAM_SET_SHARED_KEY_INITIATOR,

  UCLIB_PKEY_PARAM_MAX

} UCLIB_PKEY_PARAM_TYPE;


/**
 * @brief Allocates memory for a context for pkey operations and returns a
 *        handle to the caller.
 *        It is the caller's responsiblity to call uclib_pkey_free() to
 *        properly clean up pkey context and release any associated resources.
 *
 * @param env    [in] Pointer to environment structure
 *
 * @return       Non zero value if successful.
 */
UCLIB_PKEY_HANDLE uclib_pkey_new(env_t *env);

/**
 * @brief Clears the pkey context and releases internal resources.
 *
 * @param h      [in] handle to the pkey context.
 *
 * @return       0 if successful, negative value otherwise.
 */
int uclib_pkey_free(UCLIB_PKEY_HANDLE h);

/**
 * @brief Initializes a previously-allocated handle for pkey operations, based
 *        on the alogrithm and engine chosen.
 *
 * @param h      [in] handle to the pkey context
 * @param algo   [in] pkey algorithm type enumerated in UCLIB_PKEY_ALG
 * @param engine [in] engine type enumerated in UCLIB_ENGINE_TYPE. If the
 *               engine parameter is passed as 0, the default engine will be
 *               used.
 *
 * @return       0 if successful, negative value otherwise.
 */
int uclib_pkey_init(UCLIB_PKEY_HANDLE h,
                    UCLIB_PKEY_ALG algo,
                    UCLIB_ENGINE_TYPE engine);

/**
 * @brief Resets pkey context and clears internal states in order to re-use the
 *        pkey context for another pkey operation. One can use the interface to
 *        re-use the allocated pkey context for different pkey algorithm.
 *
 * @param h      [in] handle to the pkey context
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_reset(UCLIB_PKEY_HANDLE h);

/**
 * @brief Sets or gets control or context parameters, related to the operation
 *        of the chosen algorithm. When the paramter name contains _GET_, this
 *        typically signifies that the caller is requesting for the value of a
 *        parameter to be returned to them. Otherwise the parameter signifies
 *        the setting of a control variable.
 *
 * @param h     [in]      handle to the pkey context
 * @param type  [in]      pkey param type (parameter name indicates get/set)
 * @param val   [in]      Integer input parameter
 * @param buf   [in, out] pointer to a buffer-parameter which
 *                        can be used to pass data to or
 *                        retrieve data from the context
 * @param isz   [in]      Size-parameter, used to indicate the
 *                        length of the buffer parameter
 * @param osz   [out]     Size-parameter, used to indicate the
 *                        length of the buffer being returned
 *
 * @return      0 if successful. negative value otherwise.
 */
int uclib_pkey_ctrl(UCLIB_PKEY_HANDLE h,
                    UCLIB_PKEY_PARAM_TYPE type,
                    int val,
                    uint8_t *buf,
                    size_t isz,
                    size_t *osz);

/**
 * @brief Generates a key.
 *        Parameters can be set up using the uclib_pkey_ctrl() API.
 *
 * @param h      [in]  handle to the pkey context
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_keygen(UCLIB_PKEY_HANDLE h);

/**
 * @brief  Signs the message digest using the private key and returns the
 *         signature.
 *         Parameters can be set up using the uclib_pkey_ctrl() API.
 *
 * @param h           [in]  handle to the pkey context
 * @param md          [in]  pointer to message digest
 * @param md_len      [in]  message digest length
 * @param sig         [out] pointer to signature output buffer
 * @param sig_buf_len [in]  output buffer length
 * @param out_len     [out] length of data filled into output buffer
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_sign(UCLIB_PKEY_HANDLE h,
                    const uint8_t *md,
                    size_t md_len,
                    uint8_t *sig,
                    size_t sig_buf_len,
                    size_t *out_len);

/**
 * @brief  Verify the message digest and signature by using public key.
 *         Parameters can be set up using the uclib_pkey_ctrl() API.
 *
 * @param h        [in]  handle to the pkey context
 * @param md       [in]  pointer to message digest
 * @param md_len   [in]  message digest length
 * @param sig      [in]  pointer to signature
 * @param sig_len  [in]  length of signature.
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_verify(UCLIB_PKEY_HANDLE h,
                      const uint8_t *md,
                      size_t md_len,
                      const uint8_t *sig,
                      size_t sig_len);

/**
 * @brief  Encrypt the input message by using public key.
 *         Parameters can be set up using the uclib_pkey_ctrl() API.
 *         The value in out_len indicates the length of the data filled into
 *         the out buffer.
 *
 * @param h           [in]  handle to the pkey context
 * @param in          [in]  pointer to message
 * @param in_len      [in]  message length
 * @param out         [out] pointer to cipher output buffer
 * @param out_buf_len [in]  output buffer length
 * @param out_len     [out] length of data filled into output buffer
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_encrypt(UCLIB_PKEY_HANDLE h,
                       const uint8_t *in,
                       size_t in_len,
                       uint8_t *out,
                       size_t out_buf_len,
                       size_t *out_len);

/**
 * @brief  Decrypt the input cipher message by using private key.
 *         Parameters can be set up using the uclib_pkey_ctrl() API.
 *         The value in out_len indicates the length of the data filled into
 *         the out buffer.
 *
 * @param h           [in]  handle to the pkey context
 * @param in          [in]  pointer to cipher message
 * @param in_len      [in]  cipher message length
 * @param out         [out] pointer to message output buffer
 * @param out_buf_len [in]  output buffer length
 * @param out_len     [out] length of data filled into output buffer
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_decrypt(UCLIB_PKEY_HANDLE h,
                       const uint8_t *in,
                       size_t in_len,
                       uint8_t *out,
                       size_t out_buf_len,
                       size_t *out_len);

/**
 * @brief  Derive the shared secret/key
 *
 * @param h           [in]  handle to the pkey context
 * @param out         [out] pointer to output buffer
 * @param out_buf_len [in]  output buffer length
 * @param out_len     [out] length of data filled into output buffer
 *
 * @return 0 if successful. negative value otherwise.
 */
int uclib_pkey_derive(UCLIB_PKEY_HANDLE h,
                      uint8_t *out,
                      size_t out_buf_len,
                      size_t *out_len);

#endif /* _UCLIB_PKEY_H */
