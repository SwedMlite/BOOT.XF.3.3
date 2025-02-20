/**
  @file EFIRng.h
  @brief Declaration of RNG(Random Number Generator) DXE Driver Interface 

 EFI_RNG_SERVICE_BINDING_PROTOCOL is defined in UEFI Specs 2.4

 Copyright (c) 2011-2013 Qualcomm Technologies, Incorporated.  All rights reserved.

 Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>
 This program and the accompanying materials are licensed and made available under
 the terms and conditions of the BSD License that accompanies this distribution.
 The full text of the license may be found at
 http://opensource.org/licenses/bsd-license.php.

 THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

*/

/*=============================================================================
                              EDIT HISTORY


 when        who     what, where, why
 --------    ---    -----------------------------------------------------------
 09/20/13    shl     Modified the file header to reflect the status.
 09/21/12    llg     (Tech Pubs) Edited/added Doxygen comments and markup.
 04/25/12    ag      Updated to use MSFT entropy gathering protocol draft 0.6
 07/18/11    shl     Initial version.

=============================================================================*/
#ifndef __EFI_RNG_PROTOCOL_H__
#define __EFI_RNG_PROTOCOL_H__

/** @cond */
typedef struct _EFI_QCOM_RNG_PROTOCOL EFI_QCOM_RNG_PROTOCOL;
/** @endcond */

/** @ingroup efi_rng_constants 
  RNG raw algorithm.  
*/
#define EFI_RNG_ALGORITHM_RAW \
{0xe43176d7, 0xb6e8, 0x4827, 0xb7, 0x84, 0x7f, 0xfd, 0xc4, 0xb6, 0x85, 0x61}

/** @ingroup efi_rng_data_types 
  RNG algorithm.  
*/
typedef EFI_GUID EFI_RNG_ALGORITHM;

/* External reference to the EfiRNGAlgRawGuid GUID */
/** @cond */
extern EFI_GUID gEfiRNGAlgRawGuid;
/** @endcond */


/*===========================================================================
  FUNCTION DEFINITIONS
===========================================================================*/
/* EFI_RNG_GET_INFO */ 
/** @ingroup efi_rng_get_info
  @par Summary
  Returns information about the random number generation implementation.
  
  @param[in]     This                  Pointer to the EFI_QCOM_RNG_PROTOCOL 
                                       instance.
  @param[in,out] RNGAlgorithmListSize  Algorithm list size. 
                                - On input, the size (in bytes) of
                                  RNGAlgorithmList.
                                - On output, one of the following: \n
                                  -- If the buffer was large enough, the size 
                                     (in bytes) of the data returned in 
                                     RNGAlgorithmList. \n
                                  -- If the buffer was not large enough, the 
                                     size (in bytes) of RNGAlgorithmList 
                                     needed to obtain the array. In this 
                                     case, the function returns 
                                     EFI_BUFFER_TOO_SMALL. @tablebulletend
  @param[out] RNGAlgorithmList  Buffer filled with one EFI_RNG_ALGORITHM 
                                element for each supported RNG algorithm. The 
                                list must not change across multiple calls to 
                                the same driver. The first algorithm in the 
                                list is the default algorithm for the driver.

  @return
  EFI_SUCCESS           -- Function completed successfully. \n
  EFI_BUFFER_TOO_SMALL  -- Buffer is not large enough to obtain the array. \n
  EFI_INVALID_PARAMETER -- RNGAlgorithmList parameter is NULL.
*/
typedef EFI_STATUS (EFIAPI *EFI_RNG_GET_INFO)( IN EFI_QCOM_RNG_PROTOCOL *This,
                    IN OUT UINTN *RNGAlgorithmListSize,
                    OUT EFI_RNG_ALGORITHM *RNGAlgorithmList );


/* EFI_RNG_GET_RNG */ 
/** @ingroup efi_rng_get_rng
  @par Summary
  Fills the RNGValue buffer with random bytes from the specified RNG algorithm.
   
  @param[in]  This            Pointer to the EFI_QCOM_RNG_PROTOCOL instance.
  @param[in]  RNGAlgorithm    Pointer to the EFI_RNG_ALGORITHM that identifies 
                              the RNG algorithm to use. This parameter may be 
                              NULL, in which case the function uses its default 
                              RNG algorithm.
  @param[in]  RNGValueLength  Length (in bytes) of the buffer pointed to by 
                              RNGValue.
  @param[out] RNGValue        Pointer to a buffer that holds the resulting RNG 
                              value.

  @return
  EFI_SUCCESS           -- Function completed successfully. \n
  EFI_INVALID_PARAMETER -- RNG value is NULL. \n
  EFI_UNSUPPORTED       -- RNG algorithm is NULL or is not recognized. \n
  EFI_DEVICE_ERROR      -- Physical device reported an error.
*/

typedef EFI_STATUS (EFIAPI *EFI_RNG_GET_RNG)( IN EFI_QCOM_RNG_PROTOCOL *This,
                     IN EFI_RNG_ALGORITHM *RNGAlgorithm,
                     IN UINTN RNGValueLength,
                     OUT UINT8 *RNGValue );

/*===========================================================================
  PROTOCOL INTERFACE
===========================================================================*/
/** @ingroup efi_rng_protocol
  @par Summary
  Qualcomm Random Number Generator (RNG) Protocol interface. 

  @par Parameters
  @inputprotoparams{rng_proto_params.tex} 
*/
struct _EFI_QCOM_RNG_PROTOCOL
{
  EFI_RNG_GET_INFO GetInfo;
  EFI_RNG_GET_RNG GetRNG;
}; 

/** @ingroup efi_rng_constants
  Protocol version. 
*/
#define RNG_REVISION 0x00010000

/* External reference to the QcomRngProtocolGuid Protocol GUID */
/** @ingroup efi_rng_protocol */
extern EFI_GUID gQcomRngProtocolGuid;

#endif
