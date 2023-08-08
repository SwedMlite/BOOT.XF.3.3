/**

@file   icb_sdi.c

@brief  ICB support for SDI. Save/restore MEMNOC address translators
        
===========================================================================

                             Edit History


when         who     what, where, why
----------   ---     --------------------------------------------------------
2018/06/20   sds     Created 

===========================================================================
       Copyright (c) 2018 QUALCOMM Technologies Incorporated.
                       All Rights Reserved.
                       QUALCOMM Proprietary
===========================================================================
*/

/* -----------------------------------------------------------------------
** Includes
** ----------------------------------------------------------------------- */
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "../../../../Include/HALhwio.h"
#include "../../Include/msmhwiobase.h"
#include "../../../../Library/ICBLib/icbcfg_hwio.h"
#include "icbcfg_hwio_target.h"
#include "string.h"

/* -----------------------------------------------------------------------
** Definitions
** ----------------------------------------------------------------------- */
#define MAX_CHANNELS 4
#define SEGMENTS 6

/* -----------------------------------------------------------------------
** Types
** ----------------------------------------------------------------------- */
typedef struct
{
  uint32_t base_low;
  uint32_t base_high;
  uint32_t offset_low;
  uint32_t offset_high;
} icb_segment_t;

typedef struct
{
  uint32_t      enable_low;
  uint32_t      error_low;
  icb_segment_t segs[SEGMENTS];
} icb_sdi_trans_t;

/* -----------------------------------------------------------------------
** Data
** ----------------------------------------------------------------------- */
static bool valid = false;
static uint32_t channels = 4;
static icb_sdi_trans_t trans[MAX_CHANNELS];
static uint32_t trans_bases_llcc[MAX_CHANNELS] =
{
  HWIO_ADDR(LLCC0_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  HWIO_ADDR(LLCC1_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  HWIO_ADDR(LLCC2_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
  HWIO_ADDR(LLCC3_LLCC_BEAC0_LLCC_BEAC_ADDR_TRANSLATOR_CFG),
};

/* -----------------------------------------------------------------------
** Functions
** ----------------------------------------------------------------------- */

//*============================================================================*/
/**
@brief 
      Save addr translators
*/ 
/*============================================================================*/
void icb_sdi_save( void )
{
  uint32_t ch, seg;

  /* Save segment decode registers. */
  memset(&trans, 0, sizeof(trans));
  for( ch = 0; ch < channels; ch ++ )
  {
    trans[ch].enable_low = HWIO_INXF(trans_bases_llcc[ch],LLCC_BEAC_ADDR_TRANSLATOR_CFG,ENABLE);
    trans[ch].error_low  = HWIO_INXF(trans_bases_llcc[ch],LLCC_BEAC_ADDR_TRANSLATOR_CFG,ERROR);
    for( seg = 0; seg < SEGMENTS; seg ++ )
    {
      if( seg != 0 )
      {
        trans[ch].segs[seg].base_low  = HWIO_INXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG2,seg);
        trans[ch].segs[seg].base_high = HWIO_INXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG3,seg);
      }
      trans[ch].segs[seg].offset_low  = HWIO_INXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG0,seg);
      trans[ch].segs[seg].offset_high = HWIO_INXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG1,seg);
    }
  }

  valid = true;
}

//*============================================================================*/
/**
@brief 
      Restore addr translators

@dependencies
      icb_sdi_save() must have been called first.
 
@return    
      true if successful
      false if no valid data to restore
*/ 
/*============================================================================*/
bool icb_sdi_restore( void )
{
  uint32_t ch, seg;

  if( false == valid )
  {
    return false;
  }

  /* First, disable all address translators. */
  for( ch = 0; ch < channels; ch ++ )
  {
    HWIO_OUTXF(trans_bases_llcc[ch],LLCC_BEAC_ADDR_TRANSLATOR_CFG,ENABLE,0);
  }

  /* Write translator configuration. */
  for( ch = 0; ch < channels; ch ++ )
  {
    HWIO_OUTXF(trans_bases_llcc[ch],LLCC_BEAC_ADDR_TRANSLATOR_CFG,ERROR,trans[ch].error_low);
    for( seg = 0; seg < SEGMENTS; seg ++ )
    {
      if( seg != 0 )
      {
        HWIO_OUTXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG2,seg,trans[ch].segs[seg].base_low);
        HWIO_OUTXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG3,seg,trans[ch].segs[seg].base_high);
      }
      HWIO_OUTXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG0,seg,trans[ch].segs[seg].offset_low);
      HWIO_OUTXI(trans_bases_llcc[ch],LLCC_BEAC_ADDR_REGIONn_CFG1,seg,trans[ch].segs[seg].offset_high);
    }
  }

  /* Finally, set enable bits according to saved state. */
  for( ch = 0; ch < channels; ch ++ )
  {
    HWIO_OUTXF(trans_bases_llcc[ch],LLCC_BEAC_ADDR_TRANSLATOR_CFG,ENABLE,trans[ch].enable_low);
  }

  return true;
}

