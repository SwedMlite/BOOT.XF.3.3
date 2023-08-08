/** 
  @file  ddi_testing.h
  @brief defines command DDI test parameters
*/
/*=============================================================================

                                DDI Internal Test cases APIs
                                Header File
GENERAL DESCRIPTION
This file defines common DDI test parameters

  Copyright (c) 2016-2017 QUALCOMM Technologies Incorporated.
  All rights reserved.
  Qualcomm Confidential and Proprietary.
===============================================================================

===============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ------------------------------------------------------------
07/19/17   na      Initial version.
==============================================================================*/
#ifndef __DDI_TESTING_H__
#define __DDI_TESTING_H__

/*==========================================================================
                               INCLUDES
===========================================================================*/

#include "HALcomdef.h"

/*==============================================================================
                                  TYPES & DEFINES
==============================================================================*/

#define DDI_PRINT_ENABLE 1
#define DDI_OUTPUT_SECTION_START_IN_DDR		SIZE_724KB
#define DDI_OUTPUT_SECTION_END_IN_DDR       SIZE_2MB

/*==========================================================================
                               FUNCTION DEFINITIONS
===========================================================================*/

typedef void (*test_case_func)(uint64 cmd_id, void* params, uint64* input_iter, uint64* output_iter);

typedef enum
{
  DDI_PRE_DDR_STEP,
  DDI_POST_DDR_STEP,
}ddi_step_param;
  
typedef struct
{
  ddi_step_param ddi_step;
  test_case_func func_ptr;
}ddi_test_case_func;

#endif /* __DDI_TESTING_H__ */
