/*===========================================================================
                             pdc_seq_target.c

DESCRIPTION:
  This file implements functions that are specific to environment where
  PDC sequencer driver is running (processor/os/exception level).

  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.

  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies, Inc.
===========================================================================*/

//===========================================================================
//                   Includes and Variable Definitions
//===========================================================================

//---------------------------------------------------------------------------
//  Include Files
//---------------------------------------------------------------------------

#include "pdc_seq.h"
#include "pdc_seq_internal.h"
#include "msmhwiobase.h"

//---------------------------------------------------------------------------
//  Defines
//---------------------------------------------------------------------------

/* Stringify parameter */
#define __STR(x) #x
#define STR(x) __STR(x)

//---------------------------------------------------------------------------
//  Static Variables
//---------------------------------------------------------------------------

/* AOSS base address - obtained by different mechanism depending on the
 * environment. This is used in conjuction with PDC offset. */
static uint8* g_pdc_aoss_base = (uint8*)AOSS_BASE;

/* Subsystem base address - obtained by different mechanism depending on
 * the environment. This will be used in conjuction with RSC offset. */
static uint8* g_pdc_ss_base = NULL;


//===========================================================================
//                       Function Defintions
//===========================================================================

//---------------------------------------------------------------------------
//  Public Function Definitions
//---------------------------------------------------------------------------

/**
 * <!-- pdc_seq_handle_env_init -->
 *
 * @brief Environment specific initialization for a PDC handle like
 *        mapping physical address to perform HW IO.
 *
 * This is an internal function expected to be called during PDC
 * handle initialization.
 *
 * @note No input validation as it is an internal function.
 *
 * @param handle: PDC handle to be initialized.
 *
 * @return PDC Sequencer error code (@see pdc_seq_result_t)
 */
pdc_seq_result_t pdc_seq_handle_env_init (pdc_seq_handle handle)
{
  if (handle == NULL)
  {
    return PDC_SEQ_INVALID_PARAM;
  }

  /* AOP has one to one physical to virtual mapping */
  handle->addr = handle->offset + g_pdc_aoss_base;

  if (handle->rsc_offset != 0)
  {
    /* PDC has attached RSC - get its address too */
    handle->rsc_addr = handle->rsc_offset + g_pdc_ss_base;
  }

  return PDC_SEQ_SUCCESS;
}
