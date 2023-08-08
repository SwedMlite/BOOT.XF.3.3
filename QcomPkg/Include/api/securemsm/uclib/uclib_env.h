#ifndef _UCLIB_ENV
#define _UCLIB_ENV

/* ====================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All Rights Reserved.
 * Confidential and Proprietary – Qualcomm Technologies, Inc.
 * ====================================================================
 */

/*===========================================================================

Unified Crypto Library - Environment APIs

GENERAL DESCRIPTION


EXTERNALIZED FUNCTIONS


INITIALIZATION AND SEQUENCING REQUIREMENTS

===========================================================================*/

/*===========================================================================
                      EDIT HISTORY FOR FILE

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/api/securemsm/uclib/uclib_env.h#1 $
 $DateTime: 2019/04/24 14:51:54 $
 $Author: pwbldsvc $

 when       who     what, where, why
 --------   ---     ----------------------------------------------------------
11/06/17    shl     Added selftest fields
02/07/17    ah      Initial version
 ===========================================================================*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#define UCLIB_ENV_VERSION_MAJOR   1
#define UCLIB_ENV_VERSION_MINOR   0
#define UCLIB_ENV_MAGIC_NUMBER    0xD0E1A2D3

/*===========================================================================
                 DEFINITIONS AND TYPE DECLARATIONS
 ===========================================================================*/
/** Environment Function Pointers */

/** CE HW Base Address */
typedef struct env_ce_hw_s
{
  uint32_t ce_base;
  uint32_t ce_bam_base;
  uint32_t ce_irq_num;

  uint32_t prng_base;
}env_ce_hw_t;

/** CE HW BW Configuration API */
// Level of clock frequence
typedef enum
{
  INACTIVE          = 0x0,
  LOW               = 0x1,
  MEDIUM            = 0x2,
  HIGH              = 0x3,
  CLKLEV_COUNT_MAX  = 0x4,
  CLKLEV_MAX_ENTRY  = 0x7FFFFFFF
}env_clklev;

// Voteable clock resource, will
// ensure to vote for all dependencies
typedef enum
{
  CE1                 = 0x1,
  CE2                 = 0x2,
  CE3                 = 0x3,
  PRNG                = 0x4,
  CLK_RESOURCE_COUNT  = 0x5,
  CLK_RESOURCE_MAX    = 0x7FFFFFFF
}env_resource;

typedef enum
{
  GET               = 0x1,
  SET               = 0x2,
  CLR               = 0x3,
  INCR              = 0x4,
  DECR              = 0x5,
  OP_MAX            = 0x7FFFFFFF
}env_var_op;

typedef enum
{
  ENV_BAM_INIT        = 0x0,
  ENV_PRNG_INIT       = 0x1,
  ENV_INIT_VAR_COUNT  = 0x2,
  ENV_INIT_VAR_INVALID= 0x7FFFFFFF
}env_init_var;

typedef bool (*init_done_cb)(env_var_op operation, env_init_var var);

/** Sets Clock frequency for CE HW */
typedef int (*env_set_bandwidth)(void *clk_name, size_t clk_name_len, env_resource ce, env_clklev lvl, uint32_t flags);
typedef size_t (*env_clk_ref)(env_var_op operation, env_resource ce);

typedef struct env_clk_s
{
  char              name[32];         /** Clock Name string   */
  size_t            name_sz;          /** Clock Name size     */
  env_resource      ce_clk;           /** Clock Resource Name */
  env_clklev        lvl;              /** Bandwidth level     */
  env_clk_ref       ref;              /** Reference count     */
  env_set_bandwidth set_bw_fp;        /** Mandatory Env. callback if HW crypto is supported */
}env_clk_t;

/** Heap API's */
typedef void * (*env_malloc)(uint32_t);
typedef void (*env_free)(void *);
typedef void * (*env_realloc)(void *, uint32_t);
typedef struct env_mem_magic_num_s
{
  uint32_t *magic_num;
  uint16_t *magic_num_index_array;
  uint16_t  magic_num_index;
}env_mem_magic_num_t;

typedef struct env_static_mem_s
{
  uint32_t            magic_num[5];
  uint16_t            magic_num_index_array[6];
  uint8_t             mem_desc[128];
  env_mem_magic_num_t mem_magic_num;
  bool                mem_init_done;

  uint8_t             *mem_pool_ptr;
  size_t              mem_pool_size;
}env_static_mem_t;

typedef struct env_mm_s
{
  env_malloc       malloc_fp;          /** Mandatory Env. callback if heap management is supported in the image */
  env_free         free_fp;            /** Mandatory Env. callback if heap management is supported in the image */
  env_realloc      realloc_fp;         /** Mandatory Env. callback if heap management is supported in the image */

  env_static_mem_t *mem_mgr_ptr;       /** Mandatory pointer to Env. structure if heap management is not supported in the image */
}env_mm_t;

/** memory API's */
typedef void * (*env_memcpy)(void *dst, const void *src, size_t sz);
typedef void * (*env_memset)(void *str, int c, size_t n);
typedef int (*env_memcmp)(const void *str1, const void *str2, size_t n);
typedef int (*env_timesafe_memcmp)(const void *str1, const void *str2, size_t n);
typedef void * (*env_memmove)(void *dst, const void *src, size_t cpy_sz);

/** VA to PA conversion API */
typedef int (*env_vtop)(uintptr_t va, uintptr_t *pa);

/** DCache clean and invalidate API */
typedef void (*env_dcache_civ)(void *addr, size_t len);
/** DCache line size API */
typedef size_t (*env_dcache_sz)(void);

/** Memory barrier API */
typedef void (*env_mem_bar)(void);
/** Instruction barrier API */
typedef void (*env_ins_bar)(void);

typedef struct env_mu_s
{
  env_memcpy          memcpy_fp;           /** Mandatory Env. callback */
  env_memset          memset_fp;           /** Mandatory Env. callback */
  env_memcmp          memcmp_fp;           /** Mandatory Env. callback */
  env_timesafe_memcmp timesafe_memcmp_fp;  /** Mandatory Env. callback */
  env_memmove         memmove_fp;          /** Mandatory Env. callback */

  env_vtop            vtop_fp;             /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_dcache_civ      dcache_civ_fp;       /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_dcache_sz       dcache_sz_fp;        /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_mem_bar         mem_barrier_fp;      /** Mandatory Env. callback if HW crypto BAM mode is supported  */
  env_ins_bar         inst_barrier_fp;     /** Mandatory Env. callback if HW crypto BAM mode is supported  */

}env_mu_t;

/** Mutex API's */
typedef int (*env_mutex_init)(void *lock);
typedef int (*env_mutex_lock)(void *lock);
typedef int (*env_mutex_release)(void *lock);
typedef struct env_mtx_s
{
  env_mutex_init    mutex_init_fp;     /** Optional Env. callback */
  env_mutex_lock    mutex_lock_fp;     /** Optional Env. callback */
  env_mutex_release mutex_release_fp;  /** Optional Env. callback */

  void*             lock;              /** Optional CE lock       */
}env_mtx_t;

/** PRNG Access API's */
typedef int (*env_prng_enable_access)(void);
typedef int (*env_prng_disable_access)(void);
/** PRNG Get Data API */
typedef size_t (*prng_cb) (uint8_t *buf, size_t buf_sz);
typedef struct env_prng_s
{
  env_prng_enable_access  prng_en_fp;  /** Optional Env. callback */
  env_prng_disable_access prng_dis_fp; /** Optional Env. callback */
  prng_cb                 prng_cb_fp;  /** Mandatory Env. callback if UCLIB is integrated in user space image */
  bool                    prng_ac_en;  /** Mandatory flag */
  init_done_cb            init_done;
  env_clk_t               prng_clk;
}env_prng_t;

/** Log API's */
typedef void (*env_log)(const char* fmt, va_list ap);

/** BAM Driver Static Allocations */
typedef struct env_bam_ctx_s
{
  init_done_cb init_done;
  uint8_t      *tx_desc;                    /** Mandatory if BAM Engine is used. Uncached Memory with 8-byte alignment               */
  uint8_t      *rx_desc;                    /** Mandatory if BAM Engine is used. Uncached Memory with 8-byte alignment               */
  uint8_t      *rslt;                       /** Mandatory if BAM Engine is used. Size: 256 bytes with cache line size alignment      */
  uint8_t      *container;                  /** Mandatory if BAM Engine is used. Size: 256 bytes with cache line size alignment      */

  uint8_t      *bam_ctx;                    /** Mandatory if BAM Engine is used. Size: 1200 bytes                                    */
  size_t       bam_ctx_size;                /** Mandatory if BAM Engine is used. Size of BAM context = 1200                          */
  size_t       desc_sz;                     /** Mandatory if BAM Engine is used. Size in bytes. Must be multiple of 8 bytes          */
  bool         uses_550_features;           /** Indicates whether CE 5.5.0 features (pipe keys, pattern processing) are required.    */
}env_bam_ctx_t;

typedef enum
{
  CRYPTO_OPERATION_AES = 0,
  CRYPTO_OPERATION_ECC = 1,
  CRYPTO_OPERATION_ECDH = 2,
  CRYPTO_OPERATION_MAC = 3,
  CRYPTO_OPERATION_KDF = 4,
  CRYPTO_OPERATION_RSA = 5,
  CRYPTO_OPERATION_SHA = 6,
  CRYPTO_OPERATION_TDES = 7,
  CRYPTO_OPERATION_SM2 = 8,
  CRYPTO_OPERATION_INVALID
} crypto_operation_enum;

typedef bool (*env_is_crypto_operation_allowed)(crypto_operation_enum operation);
typedef bool (*env_is_fips_enabled)(void);

/** Crypto Yield API */
typedef void (*env_crypto_yield)(bool);

struct env_s
{
  uint32_t ver;
  uint32_t magic;

  /** CE HW Base Address */
  env_ce_hw_t ce;

  /** Clock API's */
  env_clk_t clk;

  /** Heap API's */
  env_mm_t mm;

  /** memory API's */
  env_mu_t mem;

  /** Mutex API's */
  env_mtx_t mtx;

  /** PRNG Access API's */
  env_prng_t prng;

  /** Log API's */
  env_log log_fp;

  /** BAM Driver Static Allocations */
  env_bam_ctx_t bam;

  /** selftest API's */
  env_is_crypto_operation_allowed is_crypto_operation_allowed_fp;
  env_is_fips_enabled is_fips_enabled_fp;

  /** Crypto Yield API */
  env_crypto_yield crypto_yield_fp;

};

typedef struct env_s env_t;

/**
 * @brief Returns pointer to environment structure that has been
 *        initialized by the image.
 *
 * @return pointer to environment structure.
 */
env_t * ucenv_get_env(void);

#endif /* _UCLIB_ENV */
