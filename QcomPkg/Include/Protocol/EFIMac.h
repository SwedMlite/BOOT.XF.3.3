/** 
  @file  EFIMac.h
  @brief Mac EFI Protocol for mMacDxe use.
*/
/*=============================================================================
  Copyright (c) 2019 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 02/22/19   jp     initial version

=============================================================================*/

#ifndef __EFI_MAC_PROTOCOL_H__
#define __EFI_MAC_PROTOCOL_H__

#define EFI_MAC_PROTOCOL_REVISION   0x0000000000010000

#define EFI_MAC_PROTOCOL_GUID \
  { \
    0x919a4ecf, 0xe0ae, 0x44dd, {0xa3, 0x9a, 0xbc, 0x3d, 0xd5, 0x24, 0xa6, 0x0d } \
  }

#define EFI_MAC_SERVICE_BINDING_PROTOCOL_GUID \
  { \
    0x126e463b, 0x5ad4, 0x4e07, {0xa3, 0x0c, 0xc3, 0x1c, 0xab, 0xb7, 0xac, 0x8d } \
  }

#define EFI_MAC_ALGORITHM_HMAC_GUID \
  { \
    0x3b67e9f0, 0x4220, 0x4a1b, {0x9f, 0xc0, 0x40, 0x7d, 0x3b, 0x81, 0xd9, 0xca } \
  }

#define EFI_MAC_ALGORITHM_CMAC_GUID \
  { \
    0x406a077a, 0xa9ad, 0x492e, {0x9d, 0x83, 0x9b, 0x40, 0xfe, 0x9e, 0x77, 0x4e } \
  }

#define EFI_MAC_ENGINE_ARMV8_GUID \
  { \
    0x64e8487d, 0xfa74, 0x49e2, {0x87, 0x02, 0xab, 0x2c, 0x85, 0xbf, 0x17, 0x19 } \
  }

#define EFI__MAC_ENGINE_CEHW_GUID \
  { \
    0x7ffeeb55, 0x1b79, 0x4ed2, {0xa9, 0x8d, 0x76, 0x1f, 0x46, 0x84, 0xc2, 0xe1 } \
  }

#define EFI_MAC_SET_PARAM_HASH_ALGO_GUID \
  { \
    0x573142a1, 0x4eb3, 0x45a9, {0x81, 0xa2, 0xd3, 0x76, 0x5e, 0xfe, 0xb8, 0xff } \
  }

#define EFI_MAC_SET_PARAM_KEY_GUID \
  { \
    0x84723e17, 0xbf34, 0x404b, {0x99, 0x5f, 0x68, 0xe0, 0xfe, 0x22, 0x0e, 0xbd } \
  }

#define EFI_MAC_GET_DIGEST_SIZE_GUID \
  { \
    0xd0c40b06, 0x325e, 0x4344, {0x91, 0xcb, 0xe1, 0xcc, 0x97, 0x82, 0xb8, 0x9d } \
  }


typedef struct _EFI_MAC_PROTOCOL EFI_MAC_PROTOCOL;

/**
  This function must be called to initialize a Mac calculation to be subsequently performed using the
  _EFI_MAC_PROTOCOL functions efiMacCtl(), efiMacUpdate(), efiMacFinal() and efiMacDeInit().

  @param[in]  This             Points to this instance of EFI_MAC_PROTOCOL.
  @param[in]  MacAlgorithm     Points to the EFI_GUID which identifies the Mac algorithm to use.
                                  The Guids can be used here:
                                    gEfiMacAlgorithmHMACGuid;
                                    gEfiMacAlgorithmCMACGuid;
  @param[in]  MacEngine        Points to the EFI_GUID which identifies the Mac engine.
                                  The Guids can be used here:
                                    gEfiMacEngineArmv8Guid;
                                    gEfiMacEngineCeHwioGuid;
                                    gEfiMacEngineSwGuid;
                                    gEfiMacEngineCeBamGuid;

  @retval EFI_SUCCESS             Initialized successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   Either of these parameters is Null.
  @retval EFI_UNSUPPORTED         The specified algorithm/engine is not supported by this driver.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_INIT)(
  IN CONST EFI_MAC_PROTOCOL         *This,
  IN CONST EFI_GUID                 *MacAlgorithm,
  IN CONST EFI_GUID                 *MacEngine
  );

/**
  This function resets MAC context and clears internal states in order to re-use the MAC context
  for another MAC operation. The interface retains MAC algorithm, engine and key from previous initialization.

  @param[in]  This                Points to this instance of EFI_MAC_PROTOCOL.

  @retval EFI_SUCCESS             Initialized successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   Invalid Parameters.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_RESET)(
  IN CONST EFI_MAC_PROTOCOL         *This
  );
 
/**
  This function must be called before a Mac calculation to set necessary parameters.
  It writes/reads hmac context parameters. Parameters can be passed as an array of bytes (8-bit) using 
  [MacParam_buf, Mac_isz] arguments. If client does not know the required buffer size for a type, 
  it can call the API with MacParam_buf as NULL and provide valid pointer to Mac_osz to retrieve 
  required buffer size for associated parameter. To read any hmac parameter, [MacParam_buf, Mac_isz]
  are required.

  @param[in]  This               Points to this instance of EFI_MAC_PROTOCOL.
  @param[in]  MacSetParamType    Points to the EFI_GUID which identifies the Mac parameter type to be set.
                                  The Guids can be used here:
                                    gEfiMacSetParamHashAlgoGuid;
                                    gEfiMacSetParamCipherAlgoGuid;
                                    gEfiMacSetParamKeyGuid;

  @param[in]  MacParamSubType     Points to the EFI_GUID which indicate the parameter value for dir or mode to be set.
                                  In cas of MacSetParamType == gEfiMacSetParamHashAlgoGuid, the Guids can be used here:
                                    gEfiMacHashAlgoSha1Guid;
                                    gEfiMacHashAlgoSha256Guid;

  @param[in, out]  MacParam_buf   Points to the start of the parameter buffer for user to set/get parameters.
  @param[in]  Mac_isz             The size of the input buffer, in byte.
  @param[out] Mac_osz             Points to the returned size, in byte.
  
  @retval EFI_SUCCESS             Set Mac Parameter successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   Invalid Parameters.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_CTL)(
  IN CONST EFI_MAC_PROTOCOL         *This,
  IN CONST EFI_GUID                 *MacSetParamType,
  IN CONST EFI_GUID                 *MacParamSubType,
  IN OUT UINT8                      *MacParam_buf,
  IN UINTN                          Mac_isz,
  OUT UINTN                         *Mac_osz
  );

/**
  Calculates and updates the MAC result using the given message. 
  This result is stored in the MAC context.

  @param[in]  This         Points to this instance of EFI_MAC_PROTOCOL.
  @param[in]  Mac_ibuf     Points to the message buffer.
  @param[in]  Mac_isz      The size of the message buffer, in bytes.
  
  @retval EFI_SUCCESS             Mac returned successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   Mac_ibuf is NULL.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_UPDATE)(
  IN CONST EFI_MAC_PROTOCOL       *This,
  IN CONST UINT8                  *Mac_ibuf,
  IN UINTN                        Mac_isz
  );

/**
  Copies the MAC result into the supplied digest buffer.
  The digest buffer must be large enough to hold this result.

  @param[in]  This            Points to this instance of EFI_MAC_PROTOCOL.
  @param[in]  Mac_dgst        Points to the output digest buffer.
  @param[in]  Mac_dgst_sz     The size of the digest buffer, in bytes.
  
  @retval EFI_SUCCESS             Mac returned successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   Mac_dgst is NULL or Mac_dgst_sz is 0.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_FINAL)(
  IN CONST EFI_MAC_PROTOCOL       *This,
  OUT UINT8                       *Mac_dgst,
  IN UINTN                        Mac_dgst_sz
  );


/**
  This function is called after a Mac calculation to clear the MAC context and releases internal resources.

  @param[in]  This                Points to this instance of EFI_MAC_PROTOCOL.
  
  @retval EFI_SUCCESS             Deinit successfully.
  @retval EFI_DEVICE_ERROR        Failed.
  @retval EFI_INVALID_PARAMETER   This is NULL.
**/

typedef
EFI_STATUS
(EFIAPI *EFI_MAC_MAC_DEINIT)(
  IN CONST EFI_MAC_PROTOCOL      *This
  );

struct _EFI_MAC_PROTOCOL {
  UINT64                      Revision;
  EFI_MAC_MAC_INIT            efiMacInit;
  EFI_MAC_MAC_RESET           efiMacReset;
  EFI_MAC_MAC_CTL             efiMacCtl;
  EFI_MAC_MAC_UPDATE          efiMacUpdate;
  EFI_MAC_MAC_FINAL           efiMacFinal;
  EFI_MAC_MAC_DEINIT          efiMacDeInit;
};

extern EFI_GUID gEfiMacProtocolGuid;
extern EFI_GUID gEfiMacServiceBindingProtocolGuid;

extern EFI_GUID gEfiMacAlgorithmHMACGuid;
extern EFI_GUID gEfiMacAlgorithmCMACGuid;
extern EFI_GUID gEfiMacEngineArmv8Guid;
extern EFI_GUID gEfiMacEngineCeHwGuid;

extern EFI_GUID gEfiMacSetParamHashAlgoGuid;
extern EFI_GUID gEfiMacSetParamKeyGuid;
extern EFI_GUID gEfiMacGetDigestSizeGuid;

/* extern from Hash.h */
extern EFI_GUID gEfiHashAlgorithmSha1Guid;
extern EFI_GUID gEfiHashAlgorithmSha224Guid;
extern EFI_GUID gEfiHashAlgorithmSha256Guid;
extern EFI_GUID gEfiHashAlgorithmSha384Guid;
extern EFI_GUID gEfiHashAlgorithmSha512Guid;

#endif
