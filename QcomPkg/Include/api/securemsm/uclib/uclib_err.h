#ifndef _UCLIB_ERR
#define _UCLIB_ERR

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Errors

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

Copyright (c) 2017 by Qualcomm Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_err.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
01/12/2018  shl     Added SMMU virtual address case error code
 2/7/2017   ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/

/* Error Modules */
#define UCM_CMN                0 /** Common */
#define UCM_ENV                1 /** Environment */
#define UCM_CEHW               2 /** Crypto Engine HWIO HAL Driver */
#define UCM_CEBAM              3 /** Crypto Engine BAM HAL Driver */
#define UCM_HASH               4 /** Hash */
#define UCM_CIPHER             5 /** Cipher */
#define UCM_AES                6 /** AES */
#define UCM_DES                7 /** DES */
#define UCM_PRNG               8 /** PRNG */
#define UCM_PKEY               9 /** Public-Key */
#define UCM_BIGINT            10 /** Crypto Big-Integer */
#define UCM_MAC               11 /** MAC */
#define UCM_KDF               12 /** KDF */

/**
 Macro to create error code.
 31*******************20**********************************0
 +--------------------+-----------------------------------+
 |    12 bits for     |          20 bits
 |    Module Name     |        error code
 +--------------------+-----------------------------------+
*/
#define UCLIB_GET_EC(mod, ec)    ((((mod) & 0xFFF) << 20) + ((ec) & 0xFFFFF))
#define UCLIB_ERR(mod, ec)       ((int)UCLIB_GET_EC(mod, ec))

enum uclib_err_enum
{
  /** Common UCLIB Error Codes */
  UCLIB_SUCCESS                  = UCLIB_ERR(UCM_CMN, 0),         /** Operation successful                 */
  UCLIB_ERR_FAILURE              = UCLIB_ERR(UCM_CMN, 1),         /** Operation failed due to unknown err  */
  UCLIB_ERR_INVALID_ARG          = UCLIB_ERR(UCM_CMN, 2),         /** Arg is not recognized                */
  UCLIB_ERR_OUT_OF_RANGE         = UCLIB_ERR(UCM_CMN, 3),         /** Arg value is out of range            */
  UCLIB_ERR_VERSION_MISMATCH     = UCLIB_ERR(UCM_CMN, 4),         /** Unexpected software or protocol ver. */
  UCLIB_ERR_NOT_SUPPORTED        = UCLIB_ERR(UCM_CMN, 5),         /** Operation not yet implemented        */
  UCLIB_ERR_INVALID_CONTEXT      = UCLIB_ERR(UCM_CMN, 6),         /** Invalid context                      */
  UCLIB_ERR_OUT_OF_MEMORY        = UCLIB_ERR(UCM_CMN, 7),         /** Out of memory                        */
  UCLIB_ERR_INV_DGST_SIZE        = UCLIB_ERR(UCM_CMN, 9),         /** Invalid digest size                  */
  UCLIB_ERR_INV_DGST_CONTEXT     = UCLIB_ERR(UCM_CMN, 10),        /** Invalid digest context               */
  UCLIB_ERR_ADD_OVERFLOW         = UCLIB_ERR(UCM_CMN, 11),        /** Addition Overflow                    */
  UCLIB_ERR_HEAP_LITE_FAILED     = UCLIB_ERR(UCM_CMN, 12),        /** Heap API failed                      */
  UCLIB_ERR_SELF_TEST_FAILED     = UCLIB_ERR(UCM_CMN, 13),        /** Self test failed                     */

  /** Environment Error Codes */
  UCLIB_ERR_SET_CLK_BW           = UCLIB_ERR(UCM_ENV, 1),         /** Set Clock BW failed                  */
  UCLIB_ERR_VTOP_FAILED          = UCLIB_ERR(UCM_ENV, 2),         /** VA to PA failed                      */
  UCLIB_ERR_MUTEX_INIT           = UCLIB_ERR(UCM_ENV, 3),         /** Mutex Init API failed                */
  UCLIB_ERR_MUTEX_LOCK           = UCLIB_ERR(UCM_ENV, 4),         /** Mutex Lock API failed                */
  UCLIB_ERR_MUTEX_RELEASE        = UCLIB_ERR(UCM_ENV, 5),         /** Mutex Release API failed             */
  UCLIB_ERR_HEAP_NOT_SUPPORTED   = UCLIB_ERR(UCM_ENV, 6),         /** Heap API not supported               */
  UCLIB_ERR_HEAP_INIT_FAILED     = UCLIB_ERR(UCM_ENV, 7),         /** Heap init. failed                    */
  UCLIB_ERR_INV_BAM_CTX_SIZE     = UCLIB_ERR(UCM_ENV, 8),         /** Invalid BAM Driver CTX size          */
  UCLIB_ERR_INV_BAM_CTX          = UCLIB_ERR(UCM_ENV, 9),         /** Invalid BAM Driver CTX               */
  UCLIB_ERR_PRNG_CLK_FAILED      = UCLIB_ERR(UCM_ENV, 10),        /** PRNG Clock Vote API failed           */

  /** CE HWIO HAL Driver Error Codes */
  UCLIB_ERR_INV_AUTH_XFER_SZ     = UCLIB_ERR(UCM_CEHW, 1),       /** Invalid Auth Transfer size            */
  UCLIB_ERR_INV_CIPHER_XFER_SZ   = UCLIB_ERR(UCM_CEHW, 2),       /** Invalid Cipher Transfer size          */
  UCLIB_ERR_CE_HAL_CTX_INVALID   = UCLIB_ERR(UCM_CEHW, 3),       /** Invalid CE HAL Context                */
  UCLIB_ERR_HAL_MAC_FAILED       = UCLIB_ERR(UCM_CEHW, 4),       /**                                       */
  UCLIB_ERR_HAL_ACCESS_VIOL      = UCLIB_ERR(UCM_CEHW, 5),       /**                                       */
  UCLIB_ERR_HAL_PIPE_ACTIVE_ERR  = UCLIB_ERR(UCM_CEHW, 6),       /**                                       */
  UCLIB_ERR_HAL_CFG_CHNG_ERR     = UCLIB_ERR(UCM_CEHW, 7),       /**                                       */
  UCLIB_ERR_HAL_DOUT_ERR         = UCLIB_ERR(UCM_CEHW, 8),       /**                                       */
  UCLIB_ERR_HAL_DIN_ERR          = UCLIB_ERR(UCM_CEHW, 9),       /**                                       */
  UCLIB_ERR_HAL_AXI_ERR          = UCLIB_ERR(UCM_CEHW, 10),      /**                                       */
  UCLIB_ERR_HAL_CE_BUSY_ERR      = UCLIB_ERR(UCM_CEHW, 11),      /**                                       */
  UCLIB_ERR_HAL_SET_IV_FAILED    = UCLIB_ERR(UCM_CEHW, 12),      /**                                       */

  /** CE BAM HAL Driver Error Codes */
  UCLIB_ERR_BAM_INIT_FAILED      = UCLIB_ERR(UCM_CEBAM, 1),      /** BAM driver init. failed               */
  UCLIB_ERR_BAM_INIT_TXPIPE      = UCLIB_ERR(UCM_CEBAM, 2),      /** BAM Tx pipe init. failed              */
  UCLIB_ERR_BAM_INIT_RXPIPE      = UCLIB_ERR(UCM_CEBAM, 3),      /** BAM Rx pipe init. failed              */
  UCLIB_ERR_BAM_TX_IRQ_MODE      = UCLIB_ERR(UCM_CEBAM, 4),      /** BAM Tx IRQ Mode set failed            */
  UCLIB_ERR_BAM_RX_IRQ_MODE      = UCLIB_ERR(UCM_CEBAM, 5),      /** BAM Rx IRQ Mode set failed            */
  UCLIB_ERR_BAM_XFR_CMD_DSC      = UCLIB_ERR(UCM_CEBAM, 6),      /** BAM Command Descriptor Xfer failed    */
  UCLIB_ERR_BAM_XFR_DAT_DSC      = UCLIB_ERR(UCM_CEBAM, 7),      /** BAM Data Descriptor Xfer failed       */
  UCLIB_ERR_BAM_XFR_RSLT_DSC     = UCLIB_ERR(UCM_CEBAM, 8),      /** BAM Result Dump Xfer failed           */
  UCLIB_ERR_BAM_BUF_PA_XLATE     = UCLIB_ERR(UCM_CEBAM, 9),      /** Data buffer VTOP failed               */
  UCLIB_ERR_BAM_PIPE_UNLCK       = UCLIB_ERR(UCM_CEBAM, 10),     /** BAM pipe unlock request failed        */
  UCLIB_ERR_BAM_TX_PIPE_POLL     = UCLIB_ERR(UCM_CEBAM, 11),     /** Tx pipe poll API failed               */
  UCLIB_ERR_BAM_RX_PIPE_POLL     = UCLIB_ERR(UCM_CEBAM, 12),     /** Rx pipe poll API failed               */
  UCLIB_ERR_BAM_PIPE_BUSY        = UCLIB_ERR(UCM_CEBAM, 13),     /** Tx/Rx pipe is still busy              */
  UCLIB_ERR_BAM_NO_ENG_EN        = UCLIB_ERR(UCM_CEBAM, 14),     /**               */

  /** CE Cipher Error Codes */
  UCLIB_ERR_CIPHER_INV_KEY_PTR      = UCLIB_ERR(UCM_CIPHER, 1),     /**                */
  UCLIB_ERR_CIPHER_INV_KEY_SZ       = UCLIB_ERR(UCM_CIPHER, 2),     /**                */
  UCLIB_ERR_CIPHER_INV_IV_PTR       = UCLIB_ERR(UCM_CIPHER, 3),     /**                */
  UCLIB_ERR_CIPHER_INV_IV_SZ        = UCLIB_ERR(UCM_CIPHER, 4),     /**                */
  UCLIB_ERR_CIPHER_NO_PADDING       = UCLIB_ERR(UCM_CIPHER, 5),     /**                */
  UCLIB_ERR_CIPHER_SMALL_OUT_BUF    = UCLIB_ERR(UCM_CIPHER, 6),     /**                */
  UCLIB_ERR_CIPHER_INV_IBUF_SZ      = UCLIB_ERR(UCM_CIPHER, 7),     /**                */
  UCLIB_ERR_CIPHER_INV_KEY          = UCLIB_ERR(UCM_CIPHER, 8),     /**                */
  UCLIB_ERR_CIPHER_INV_IV           = UCLIB_ERR(UCM_CIPHER, 9),     /**                */
  UCLIB_ERR_CIPHER_INV_NONCE_PTR    = UCLIB_ERR(UCM_CIPHER, 10),    /**                */
  UCLIB_ERR_CIPHER_INV_NONCE_SZ     = UCLIB_ERR(UCM_CIPHER, 11),    /**                */
  UCLIB_ERR_CIPHER_INV_NONCE_VAL    = UCLIB_ERR(UCM_CIPHER, 12),    /**                */
  UCLIB_ERR_CIPHER_INV_TAG_SZ       = UCLIB_ERR(UCM_CIPHER, 13),    /**                */
  UCLIB_ERR_CIPHER_ODD_TAG_SZ       = UCLIB_ERR(UCM_CIPHER, 14),    /**                */
  UCLIB_ERR_CIPHER_INV_AAD_UPDATE   = UCLIB_ERR(UCM_CIPHER, 15),    /**                */
  UCLIB_ERR_CIPHER_INV_DATA_UPDATE  = UCLIB_ERR(UCM_CIPHER, 16),    /**                */
  UCLIB_ERR_CIPHER_INV_FINAL_CALL   = UCLIB_ERR(UCM_CIPHER, 17),    /**                */
  UCLIB_ERR_CIPHER_INV_AUTH_FLD_LEN = UCLIB_ERR(UCM_CIPHER, 18),    /**                */
  UCLIB_ERR_CIPHER_INV_AUTH_SIZE    = UCLIB_ERR(UCM_CIPHER, 19),    /**                */
  UCLIB_ERR_CIPHER_INV_MSG_SIZE     = UCLIB_ERR(UCM_CIPHER, 20),    /**                */
  UCLIB_ERR_CIPHER_INV_MAC          = UCLIB_ERR(UCM_CIPHER, 21),    /**                */
  UCLIB_ERR_CIPHER_INV_TAG_PTR      = UCLIB_ERR(UCM_CIPHER, 22),    /**                */
  UCLIB_ERR_CIPHER_PADDING_FAILED   = UCLIB_ERR(UCM_CIPHER, 23),    /**                */
  UCLIB_ERR_CIPHER_INV_PLD_SIZE     = UCLIB_ERR(UCM_CIPHER, 24),    /**                */
  UCLIB_ERR_CIPHER_INV_HDR_SIZE     = UCLIB_ERR(UCM_CIPHER, 25),    /**                */
  UCLIB_ERR_CIPHER_INV_VA_PARAM     = UCLIB_ERR(UCM_CIPHER, 26),    /**                */
  UCLIB_ERR_CIPHER_INV_DIR          = UCLIB_ERR(UCM_CIPHER, 27),    /**                */
  UCLIB_ERR_CIPHER_INV_BAM_PIPE     = UCLIB_ERR(UCM_CIPHER, 28),    /**                */
  UCLIB_ERR_CIPHER_INV_FINAL_DATA   = UCLIB_ERR(UCM_CIPHER, 29),    /**                */
  UCLIB_ERR_CIPHER_INV_XTS_KEY_PTR  = UCLIB_ERR(UCM_CIPHER, 30),    /**                */
  UCLIB_ERR_CIPHER_INV_XTS_KEY_SZ   = UCLIB_ERR(UCM_CIPHER, 31),    /**                */
  UCLIB_ERR_CIPHER_INV_XTS_KEY      = UCLIB_ERR(UCM_CIPHER, 32),    /**                */
  UCLIB_ERR_CIPHER_INV_XTS_DU_SIZE  = UCLIB_ERR(UCM_CIPHER, 33),    /**                */
  UCLIB_ERR_CIPHER_INV_CTR_SIZE     = UCLIB_ERR(UCM_CIPHER, 34),    /**                */
  UCLIB_ERR_CIPHER_INV_HASH_ALG     = UCLIB_ERR(UCM_CIPHER, 35),    /**                */
  UCLIB_ERR_CIPHER_INV_HASH_ORDER   = UCLIB_ERR(UCM_CIPHER, 36),    /**                */
  UCLIB_ERR_CIPHER_INV_CTR_BUF_SZ   = UCLIB_ERR(UCM_CIPHER, 37),    /**                */

  /** CE Cipher - AES Error Codes */
  UCLIB_ERR_AES_SET_ENC_KEY      = UCLIB_ERR(UCM_AES, 1),        /**                */
  UCLIB_ERR_AES_SET_DEC_KEY      = UCLIB_ERR(UCM_AES, 2),        /**                */
  UCLIB_ERR_AES_ENC              = UCLIB_ERR(UCM_AES, 3),        /**                */
  UCLIB_ERR_AES_DEC              = UCLIB_ERR(UCM_AES, 4),        /**                */

  /** CE Cipher - DES Error Codes */
  UCLIB_ERR_DES_SET_ENC_KEY      = UCLIB_ERR(UCM_DES, 1),        /**                */
  UCLIB_ERR_DES_SET_DEC_KEY      = UCLIB_ERR(UCM_DES, 2),        /**                */
  UCLIB_ERR_DES_ENC              = UCLIB_ERR(UCM_DES, 3),        /**                */
  UCLIB_ERR_DES_DEC              = UCLIB_ERR(UCM_DES, 4),        /**                */

  /** PRNG - Error Codes */
  UCLIB_ERR_PRNG_ACCESS_ENABLE   = UCLIB_ERR(UCM_PRNG, 1),       /**                */
  UCLIB_ERR_PRNG_ACCESS_DISABLE  = UCLIB_ERR(UCM_PRNG, 2),       /**                */

  /** CE Public-Key Error Codes */
  UCLIB_ERR_PKEY_KEY_SIZE_TOO_SMALL       = UCLIB_ERR(UCM_PKEY, 1),   /** Key size too small to be secure                           */
  UCLIB_ERR_PKEY_KEY_SIZE_TOO_LARGE       = UCLIB_ERR(UCM_PKEY, 2),   /** Key size exceeds BigInteger size                          */
  UCLIB_ERR_PKEY_MSG_SIZE_TOO_LARGE       = UCLIB_ERR(UCM_PKEY, 3),   /** Message size too large for padding scheme                 */
  UCLIB_ERR_DIGEST_ALG_UNSUPPORTED        = UCLIB_ERR(UCM_PKEY, 4),   /** The digest algorithm is not supported                     */
  UCLIB_ERR_MSG_SIZE_DIGEST_MISMATCH      = UCLIB_ERR(UCM_PKEY, 5),   /** Message size does not match digest size                   */
  UCLIB_ERR_PKEY_INVALID_SIGNATURE        = UCLIB_ERR(UCM_PKEY, 6),   /** Invalid signature                                         */
  UCLIB_ERR_PKEY_DECRYPT_KEY_SIZE_INVALID = UCLIB_ERR(UCM_PKEY, 7),   /** Invalid key size for decryption                           */
  UCLIB_ERR_PKEY_PADDED_PACKET_INVALID    = UCLIB_ERR(UCM_PKEY, 8),   /** Invalid padding detected                                  */
  UCLIB_ERR_PKEY_DECRYPT_BUF_TOO_SMALL    = UCLIB_ERR(UCM_PKEY, 9),   /** Buffer provided for decrypted message is not large enough */
  UCLIB_ERR_PKEY_PADDING_PRNG_FAILED      = UCLIB_ERR(UCM_PKEY, 10),  /** Failed to generate required number of bytes for padding   */
  UCLIB_ERR_PKEY_POINT_AT_INFINITY        = UCLIB_ERR(UCM_PKEY, 11),  /** Point at infinity                                         */
  UCLIB_ERR_PKEY_CONV_TO_BIGVAL_FAILED    = UCLIB_ERR(UCM_PKEY, 12),  /** Conversion from byte buffer to big-integer failed         */
  UCLIB_ERR_PKEY_CONV_FROM_BIGVAL_FAILED  = UCLIB_ERR(UCM_PKEY, 13),  /** Conversion from big-integer to byte-buffer failed         */

  /** CE BigInteger Error Codes */
  UCLIB_ERR_GENPRIME_BITS_INVALID  = UCLIB_ERR(UCM_BIGINT, 1),  /* Invalid number of bits provided for prime-generation           */
  UCLIB_ERR_GENPRIME_PRNG_FAILED   = UCLIB_ERR(UCM_BIGINT, 2),  /* PRNG failed                                                    */
  UCLIB_ERR_BIGINT_OVERFLOW        = UCLIB_ERR(UCM_BIGINT, 3),  /* Operation would exceed maximum number of bits in BigInteger    */
  UCLIB_ERR_BIGINT_NO_INVERSE      = UCLIB_ERR(UCM_BIGINT, 4),  /* No inverse present                                             */
  UCLIB_ERR_BIGINT_INVALID_LENGTH  = UCLIB_ERR(UCM_BIGINT, 5),  /* Length field of BigInteger exceeds length of BigInteger array  */
  UCLIB_ERR_BIGINT_IS_COMPOSITE    = UCLIB_ERR(UCM_BIGINT, 6),  /* BigInteger is trivially composite                              */

  /** MAC Error Codes */
  UCLIB_ERR_MAC_ALG_NOT_SET         = UCLIB_ERR(UCM_MAC, 1),  /* Underlying Hash/Cipher algorithm was not set */
  UCLIB_ERR_MAC_KEY_NOT_SET         = UCLIB_ERR(UCM_MAC, 2),  /* MAC key was not set */

  /** KDF Error Codes */
  UCLIB_ERR_KDF_MAC_ALG_NOT_SET          = UCLIB_ERR(UCM_KDF, 1),  /* pseudorandom number function not set */
  UCLIB_ERR_KDF_MAC_ALG_NOT_MATCH        = UCLIB_ERR(UCM_KDF, 2),  /* pseudorandom number function not match */
  UCLIB_ERR_KDF_R_LEN_NOT_SET            = UCLIB_ERR(UCM_KDF, 3),  /* r length not set */
  UCLIB_ERR_KDF_CTR_LOC_NOT_SET          = UCLIB_ERR(UCM_KDF, 4),  /* counter location not set */
  UCLIB_ERR_KDF_CIPHER_ALG_NOT_SET       = UCLIB_ERR(UCM_KDF, 5),  /* cipher algorithm not set */
  UCLIB_ERR_KDF_CIPHER_KEY_LEN_NOT_MATCH = UCLIB_ERR(UCM_KDF, 6),  /* cipher key length not match */
  UCLIB_ERR_KDF_HASH_ALG_NOT_SET         = UCLIB_ERR(UCM_KDF, 7),  /* hash algorithm not match */
  UCLIB_ERR_KDF_PASSWORD_NOT_SET         = UCLIB_ERR(UCM_KDF, 8),  /* pbkdf password not set */
  UCLIB_ERR_KDF_SALT_NOT_SET             = UCLIB_ERR(UCM_KDF, 9),  /* pbkdf salt not set */
  UCLIB_ERR_KDF_ITERATION_NOT_SET        = UCLIB_ERR(UCM_KDF, 10), /* pbkdf iteration not set */
  UCLIB_ERR_KDF_KO_LEN_NOT_SET           = UCLIB_ERR(UCM_KDF, 11), /* pbkdf output key length not set */
  UCLIB_ERR_KDF_KO_LEN_TOO_LONG          = UCLIB_ERR(UCM_KDF, 12), /* pbkdf output key length too long */
  UCLIB_ERR_KDF_KEY_NOT_SET              = UCLIB_ERR(UCM_KDF, 13), /* kbkdf key not set */
  UCLIB_ERR_KDF_IV_NOT_SET               = UCLIB_ERR(UCM_KDF, 14), /* kbkdf iv not set */
};
#endif /* _UCLIB_ERR */
