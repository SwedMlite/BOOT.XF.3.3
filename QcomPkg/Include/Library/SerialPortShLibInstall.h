/** @file SerialPortShLibInstall.h
   
  Interface to install Shared serial lib.

  Copyright (c) 2012 Qualcomm Technologies, Inc.  All Rights Reserved. 
   
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 12/18/18   md      Added API to reinit serial buffer with configurable size.
                    Added API to prevent reinit of serial buffer. 
 11/01/16   bh      Add API to initialize log buffer parameters
 12/12/12   yg      Initial Version

=============================================================================*/
#ifndef __SIO_SH_LIB_INSTALL__H__
#define __SIO_SH_LIB_INSTALL__H__

#include <Uefi.h>

/* This function installs the Serial Port Shared Library into system.
 * Only SEC should be calling this function only once during system Init. */
EFI_STATUS SerialPortShLibInit (VOID);

EFI_STATUS
SerialBufferInit( IN  UINT8*   SerialBuffer  OPTIONAL, 
                  IN  UINT32   BufferSize    OPTIONAL);

EFI_STATUS
SerialBufferReInit( IN  UINT8*   SerialBuffer  OPTIONAL,
                    IN  UINT32   BufferSize    OPTIONAL);

VOID SerialBufferReInitLock (VOID); 

#endif /* __SIO_SH_LIB_INSTALL__H__ */

