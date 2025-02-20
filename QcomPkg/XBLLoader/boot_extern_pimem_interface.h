#ifndef BOOT_EXTERN_PIMEM_INTERFACE_H
#define BOOT_EXTERN_PIMEM_INTERFACE_H
/*===========================================================================

                    BOOT EXTERN PIMEM DRIVER DEFINITIONS

DESCRIPTION
  Contains wrapper definition for external pimem drivers

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  
Copyright 2015,2017,2019 by Qualcomm Technologies Incorporated.  All Rights Reserved.
============================================================================*/
/*===========================================================================

                      EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.
 
    
when       who     what, where, why
--------   ---     ----------------------------------------------------------
04/17/17   yps     Remove PIMEM init
05/18/15   kedara  Added pimem_get_status
02/11/15   kedara  Initial Creation.
===========================================================================*/

/*==========================================================================

                               INCLUDE FILES

===========================================================================*/
#include <comdef.h>

typedef enum {
    PIMEM_OK = 0,
    PIMEM_DISABLE,
    PIMEM_ERROR,
    PIMEM_UNKNOWN_ERROR=0x7F
} PIMEM_STATUS;

/*===========================================================================
                      FUNCTION DECLARATIONS
===========================================================================*/ 

/* ============================================================================
**  Function : boot_pimem_get_status
** ============================================================================
*/
/*!
*   @brief
*   Return current pimem status
*
*   @details
*
*   @param size_in_mb   -   [OUT] pointer to fill with actual pimem vault size
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  PIMEM_STATUS - return the current status of pimem
*
*   @sa None
*/

PIMEM_STATUS boot_pimem_get_status(uint32 * size_in_mb);


/* ============================================================================
**  Function : boot_pimem_init
** ============================================================================
*/
/*!
*   @brief
*   PIMEM init call
*
*   @details
*
*   @param void
*
*   @par Dependencies
*
*   @par Side Effects
*   None
*
*   @retval  void
*
*   @sa None
*/

void boot_pimem_init(void);

#endif /* BOOT_EXTERN_PIMEM_INTERFACE_H */
