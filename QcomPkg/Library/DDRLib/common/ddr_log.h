#ifndef __DDR_LOG_H__
#define __DDR_LOG_H__

/**
 * @file ddr_log.h
 * @brief
 * Header file for DDR logging.
 */
 /*******************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2012,2014,2017-2018, Qualcomm Technologies Incorporated.
 All rights reserved.
 ******************************************************************************/
/*==============================================================================
                                EDIT HISTORY

================================================================================
when       who     what, where, why
--------   ---     -------------------------------------------------------------
08/18/15   elt     Converted ddr_log to macro that calls boot_profiler feature
04/11/14   sr      supported DDR logging for SNS DDR driver .
09/12/12   sl      Use macro-style DDR logging.
07/19/12   tw      Implemented qdss swevent wrapper around DDR logging.
03/02/12   tw      Initial version.
==============================================================================*/

#include <stdio.h>
#include <stdarg.h>
#ifdef BUILD_BOOT_CHAIN
#include "ddr_profiler.h"
#endif

/*==============================================================================
                                  MACROS
==============================================================================*/
#ifndef BUILD_BOOT_CHAIN
#define PROFILER_TIMING_MSG 0
#endif
#define DDR_LOG_BUF_LEN_MAX 256

/*==============================================================================
                                  TYPES
==============================================================================*/
enum ddr_log_level
{
  DDR_STATUS, /* not provided for DDRSNS , existing for legacy targets support */
  DDR_BOOTLOG = PROFILER_TIMING_MSG,
  DDR_WARNING, /* not provided for DDRSNS , existing for legacy targets support */
  DDR_ERROR = PROFILER_TIMING_MSG, /* provided for flagging Error conditions in DDRSNS */
  DDR_NORMAL, /* provided for printing interesting/debug  information along with BEGIN/END of each DDRSNS function */
  DDR_DETAIL, /* provided for detailed logging information i.e; coarse/fine delay training & other training(CA/WRLRL/RCW) results with DDRSNS */
};

/*==============================================================================
                                  DATA
==============================================================================*/
extern enum ddr_log_level ddr_log_level;

/*==============================================================================
                                  FUNCTIONS
==============================================================================*/
/* ============================================================================
**  Function : ddr_logf
** ============================================================================
*/
/*!
*   @brief
*
*
*   @details
*
*   @param
*   None
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  None
*
*   @sa None
*/
void ddr_logf(uint32 severity, const char* fmt, va_list args);

#ifdef BUILD_BOOT_CHAIN
#define ddr_printf(severity, xxstring, ...)                               \
      do                                                                  \
      {                                                                   \
        boot_profiler_ddr_message((boot_profiler_log_level)severity, xxstring, ##__VA_ARGS__);     \
      } while (0)
#else
static inline void ddr_printf(uint32 severity, const char* fmt, ...)
{
    return;
}
#endif // BUILD_BOOT_CHAIN

#endif /* __DDR_LOG_H__ */
