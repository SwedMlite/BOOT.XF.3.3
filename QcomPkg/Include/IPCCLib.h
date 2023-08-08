#ifndef __IPCCLIB_H__
#define __IPCCLIB_H__
/*
===========================================================================
*/
/**
  @file IPCCLib.h
  @brief Public interface include file for accessing the IPCC Library.

  The IPCCLib.h file is the public API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2018 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Include/IPCCLib.h#1 $
  $DateTime: 2018/11/12 11:05:42 $
  $Author: pwbldsvc $

  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
  11/05/18   cp      Initial revision.

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <stdint.h>

/*=========================================================================
      Type Definitions
==========================================================================*/

/** @addtogroup data_types
@{ */

/**
 * Signal value to listen in on or to trigger. 
 * Values range from 0 to number supported. 
 */
typedef uint32_t      IPCC_Signal;

/**
 * Return value is a number.  They generally take form 
 * of definitions defined as IPCC_E*. Success generally 
 * returns IPCC_EOK for example. 
 */
typedef int32_t      IPCCErr;

/**
 * Protocol enumeration based on IPCC specification.
 */
typedef enum
{
  IPCC_P_MPROC = 0, /**< MPROC Protocol */
  IPCC_P_COMPUTEL0, /**< Compute Level 0 Protocol */
  IPCC_P_COMPUTEL1, /**< Compute Level 1 Protocol */
  IPCC_P_TOTAL      /**< Total number of supported protocols */
}
IPCC_Protocol;

/**
 * Client enumeration based on IPCC specification.
 */
typedef enum
{
  IPCC_C_AOP = 0, /**< Always-On Processor */
  IPCC_C_TZ,      /**< Trustzone (Secure Application Processor) */
  IPCC_C_MPSS,    /**< Modem DSP */
  IPCC_C_LPASS,   /**< Low-Power Audio DSP */
  IPCC_C_SLPI,    /**< Sensors Low Power Island DSP */
  IPCC_C_SDC,     /**< Sensors Co-Processor */
  IPCC_C_CDSP,    /**< Compute DSP */
  IPCC_C_NPU,     /**< Neuro Processing Unit */
  IPCC_C_APPS,    /**< Application Processor (Non-Secure) */
  IPCC_C_GPU,     /**< Graphics Processing Unit */
  IPCC_C_CVP,     /**< Computer Vision Processor */
  IPCC_C_CAM,     /**< Camera Processor */
  IPCC_C_VPU,     /**< Video Processing Unit */
  IPCC_C_PCIE0,   /**< PCIe Client 0 */
  IPCC_C_PCIE1,   /**< PCIe Client 1 */
  IPCC_C_PCIE2,   /**< PCIe Client 2 */
  IPCC_C_SPSS,    /**< Secure Processor */
  IPCC_C_TOTAL    /**< Total number of supported clients */
}
IPCC_Client;

/** @} */ /* end_data_types */

/** @addtogroup constants_macros
@{ */

/**
 * Return value MACROs.
 */
#define IPCC_EOK             0 /**< Success */
#define IPCC_EGENERR        -1 /**< Generic (unspecified) error */
#define IPCC_EMEM           -2 /**< Memory error */
#define IPCC_EARG           -3 /**< Argument error */
#define IPCC_EINUSE         -4 /**< Signal in-use error */
#define IPCC_EUNUSED        -5 /**< Signal not used error */
#define IPCC_ENOTFOUND      -6 /**< Signal not found error */
#define IPCC_ENOTSUPPORTED  -7 /**< Signal not supported error */

/** @} */ /* end_addtogroup constants_macros */



/*=========================================================================
      Interface Declarations
==========================================================================*/
/** @addtogroup ipcc_functions
@{ */


/* =========================================================================
**  Function : IPCCLib_Trigger
** =========================================================================*/
/**
  Triggers interrupts on remote clients.

  This function is used to assert the signals in the range nSignalLow to
  nSignalHigh on target eTargetCID.  

  @param eTargetCID  [in] Client ID of the target.
  @param nSignalLow  [in] Lowest signal number to assert.
  @param nSignalHigh [in] Highest signal number to assert.

  @return
  IPCC_EOK -- Successfully trigger the signals to eTargetCID. \n
  IPCC_EARG -- Unsupported argument passed in by client.

  @dependencies
  None.
*/

IPCCErr
IPCCLib_Trigger
(
  IPCC_Client       eTargetCID,
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);

/** @} */ /* end_addtogroup ipcc_functions */

#endif /*__IPCCLIB_H__*/
