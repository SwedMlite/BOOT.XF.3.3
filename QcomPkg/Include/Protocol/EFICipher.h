/** 
  @file  EFICipher.h
  @brief Cipher EFI Protocol for CipherDxe use.
*/
/*=============================================================================
  Copyright (c) 2018 - 2019 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 02/22/19   jp     added GCM support
 03/28/18   jp     initial version

=============================================================================*/

#ifndef __EFI_CIPHER_PROTOCOL_H__
#define __EFI_CIPHER_PROTOCOL_H__

#define EFI_CIPHER_PROTOCOL_REVISION   0x0000000000010000

#define EFI_CIPHER_PROTOCOL_GUID \
  { \
    0xa4ed10e0, 0x3010, 0x4998, {0xbc, 0xf6, 0x0c, 0xc6, 0xd2, 0x10, 0xb4, 0xd9 } \
  }

#define EFI_CIPHER_SERVICE_BINDING_PROTOCOL_GUID \
  { \
    0x62ee97f1, 0xb4b6, 0x42f2, {0xb4, 0xed, 0x31, 0xfa, 0x02, 0x8a, 0x82, 0xcc } \
  }

#define EFI_CIPHER_ALGORITHM_AES128_GUID \
  { \
    0x68c540e3, 0xe5d0, 0x4cfb, {0x9b, 0x92, 0xf2, 0x7e, 0xc4, 0x48, 0x5b, 0xef } \
  }

#define EFI_CIPHER_ALGORITHM_AES256_GUID \
  { \
    0x9ec6431c, 0x7a2b, 0x4d75, {0xb5, 0x8e, 0x20, 0x7b, 0x0c, 0x8b, 0x14, 0x0a } \
  }

#define EFI_CIPHER_MODE_ECB_GUID \
  { \
    0xdaa0df64, 0x87ff, 0x4349, {0x82, 0x17, 0xb9, 0x36, 0x4d, 0x39, 0x2e, 0x8a } \
  }

#define EFI_CIPHER_MODE_CBC_GUID \
  { \
    0xd4efcf6f, 0x7ecc, 0x4a3f, {0x89, 0x9c, 0x28, 0xc9, 0xbd, 0x15, 0xb3, 0x68 } \
  }

#define EFI_CIPHER_MODE_CTR_GUID \
  { \
    0xf21ec7da, 0x5406, 0x46b5, {0x90, 0x81, 0x2e, 0xaa, 0x18, 0xa8, 0xb2, 0xec } \
  }

#define EFI_CIPHER_MODE_CTS_GUID \
  { \
    0x2ed2abbf, 0x7c80, 0x4de6, {0x92, 0x7a, 0x51, 0x32, 0x7c, 0x02, 0xfb, 0x63 } \
  }

#define EFI_CIPHER_MODE_GCM_GUID \
  { \
    0x7d517cd5, 0x3398, 0x4a93, {0x80, 0xd4, 0x76, 0x3e, 0x30, 0x64, 0xbb, 0xdc } \
  }

#define EFI_CIPHER_ENGINE_ARMV8_GUID \
  { \
    0x56dfb26c, 0xf557, 0x47aa, {0x9d, 0x2d, 0xda, 0x4c, 0x00, 0xcf, 0xf5, 0x75 } \
  }

#define EFI_CIPHER_ENGINE_CEHW_GUID \
  { \
    0x51aa59de, 0x9dd9, 0x4fc4, {0x92, 0x4c, 0xbe, 0x6b, 0x48, 0x7a, 0x6e, 0x6b } \
  }
#define EFI_CIPHER_DIR_ENCRYPT_GUID \
  { \
    0x75bf1ab5, 0xfa11, 0x4170, {0x9c, 0x54, 0x9f, 0x75, 0x7b, 0x5b, 0x48, 0x26 } \
  }
#define EFI_CIPHER_DIR_DECRYPT_GUID \
  { \
    0x4b3a8f0e, 0x84a1, 0x4c57, {0x91, 0xf1, 0xc8, 0xa2, 0x15, 0x56, 0x4f, 0x48 } \
  }

#define EFI_CIPHER_SET_PARAM_DIR_GUID \
  { \
    0x3275fc27, 0x4890, 0x4042, {0x92, 0xa7, 0x6e, 0x1d, 0x5b, 0xe5, 0x1b, 0xd2 } \
  }

#define EFI_CIPHER_SET_PARAM_KEY_GUID \
  { \
    0xbf5950be, 0xb478, 0x4282, {0x9d, 0x9c, 0xcb, 0x89, 0xc0, 0x45, 0x6e, 0x77 } \
  }

#define EFI_CIPHER_SET_PARAM_IV_GUID \
  { \
    0x45f6d870, 0xf7b2, 0x4b0a, {0xb9, 0x20, 0x8f, 0x7e, 0x9a, 0xcc, 0xe4, 0x96 } \
  }

#define EFI_CIPHER_SET_PARAM_MODE_GUID \
  { \
    0x668451a8, 0x23b4, 0x4a47, {0x9b, 0x9e, 0x48, 0xde, 0x84, 0x78, 0x57, 0xc9 } \
  }

/* GCM */
#define EFI_CIPHER_SET_PARAM_NONCE_GUID \
  { \
    0xb1eddbd5, 0x1b1c, 0x42c4, {0xb0, 0x14, 0x00, 0xbc, 0x82, 0xdd, 0x11, 0x38 } \
  }

#define EFI_CIPHER_SET_XCMTAG_GUID \
  { \
    0x565f121c, 0x8964, 0x4ebe, {0xa2, 0xe9, 0x5e, 0x3e, 0x12, 0xc5, 0x91, 0x7f } \
  }

#define EFI_CIPHER_GET_XCMTAG_GUID \
  { \
    0x4af2e7d3, 0x37c6, 0x48c6, {0x91, 0x0b, 0xbe, 0xd0, 0x0a, 0x72, 0x94, 0x4b } \
  }

typedef struct _EFI_CIPHER_PROTOCOL EFI_CIPHER_PROTOCOL;

/**
  This function must be called to initialize a cipher calculation to be subsequently performed using the
  _EFI_CIPHER_PROTOCOL functions efiCipherCtl(), efiCipherData() and efiCipherDeInit().

  @param[in]  This                Points to this instance of EFI_CIPHER_PROTOCOL.
  @param[in]  CipherAlgorithm     Points to the EFI_GUID which identifies the cipher algorithm to use.
                                  The Guids can be used here:
                                    gEfiCipherAlgorithmAES128Guid;
                                    gEfiCipherAlgorithmAES256Guid;
  @param[in]  CipherMode          Points to the EFI_GUID which identifies the cipher mode to use.
                                  The Guids can be used here:
                                    gEfiCipherModeECBGuid;
                                    gEfiCipherModeCBCGuid;
                                    gEfiCipherModeCTRGuid;
                                    gEfiCipherModeCTSGuid;
                                    gEfiCipherModeGCMGuid;
  @param[in]  CipherEngine        Points to the EFI_GUID which identifies the cipher engine.
                                  The Guids can be used here:
                                    gEfiCipherEngineArmv8Guid;
                                    gEfiCipherEngineCeHwGuid;
  @param[in]  CipherDir           Points to the EFI_GUID which identifies the cipher direction of encrypt or decrypt.
                                  The Guids can be used here:
                                    gEfiCipherDirEncryptGuid;
                                    gEfiCipherDirDecryptGuid;

  @retval EFI_SUCCESS             Initialized successfully.
  @retval EFI_INVALID_PARAMETER   Either of these parameters is Null.
  @retval EFI_UNSUPPORTED         The specified algorithm/mode/engine is not supported by this driver.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_CIPHER_CIPHER_INIT)(
  IN CONST EFI_CIPHER_PROTOCOL      *This,
  IN CONST EFI_GUID                 *CipherAlgorithm,
  IN CONST EFI_GUID                 *CipherMode,
  IN CONST EFI_GUID                 *CipherEngine,
  IN CONST EFI_GUID                 *CipherDir
  );

/**
  This function must be called before a cipher calculation to set necessary parameters. It writes/reads 
  cipher context parameters. Parameters can be passed as an array of bytes (8-bit) using 
  [CipherParam_ibuf, Cipher_isz] arguments. If client does not know the required buffer size for a type, 
  it can call the API with CipherParam_ibuf as NULL and provide valid pointer to Cipher_osz to retrieve 
  required buffer size for associated parameter. To read any cipher parameter, [CipherParam_ibuf, Cipher_isz]
  are required.

  @param[in]  This                Points to this instance of EFI_CIPHER_PROTOCOL.
  @param[in]  CipherSetParamType  Points to the EFI_GUID which identifies the cipher parameter type to be set.
                                  The Guids can be used here:
                                    gEfiCipherSetParamDirGuid;
                                    gEfiCipherSetParamModeGuid;
                                    gEfiCipherSetParamKeyGuid;
                                    gEfiCipherSetParamIVGuid;
                                    gEfiCipherSetParamNonceGuid;
                                    gEfiCipherSetXcmTagGuid;
                                    gEfiCipherGetXcmTagGuid;

  @param[in]  CipherParamSubType  Points to the EFI_GUID which indicates the parameter Dir or Mode to be set.
                                  In cas of CipherSetParamType == gEfiCipherSetParamDirGuid, the Guids can be used here:
                                    gEfiCipherDirEncryptGuid;
                                    gEfiCipherDirDecryptGuid;
                                  In cas of CipherSetParamType == gEfiCipherSetParamModeGuid, the Guids can be used here:
                                    gEfiCipherModeECBGuid;
                                    gEfiCipherModeCBCGuid;
                                    gEfiCipherModeCTRGuid;
                                    gEfiCipherModeCTSGuid;
                                    gEfiCipherModeGCMGuid;
  @param[in]  CipherParam_ibuf   Points to the start of the input buffer for user to set/get parameters.
  @param[in]  Cipher_isz          The size of the input buffer, in byte.
  @param[out] Cipher_osz         Points to the returned size that retrieved the required buffer size for associated parameter, 
                                 in case that client does not know the required buffer size for a type.
  
  @retval EFI_SUCCESS             Set/Get Cipher Parameter successfully.
  @retval EFI_INVALID_PARAMETER   Invalid Parameters.
  @retval EFI_UNSUPPORTED         The specified CipherSetParamType/CipherParamSubType are not supported by this driver.
  @retval EFI_NOT_READY           No valid instance data associated with this protocol(This).
  @retval EFI_DEVICE_ERROR        Other failures. 
**/
typedef
EFI_STATUS
(EFIAPI *EFI_CIPHER_CIPHER_CTL)(
  IN CONST EFI_CIPHER_PROTOCOL      *This,
  IN CONST EFI_GUID                 *CipherSetParamType,
  IN CONST EFI_GUID                 *CipherParamSubType,
  IN UINT8                          *CipherParam_ibuf,
  IN UINTN                          Cipher_isz,
  OUT UINTN                         *Cipher_osz
  );

/**
  Updates additional authentication data when authenticated cipher mode (e.g CCM/GCM) is selected.
  It returns failure for other cipher modes.

  @param[in]  This            Points to this instance of EFI_CIPHER_PROTOCOL.
  @param[in]  Cipher_aad      Points to the AAD buffer.
  @param[in]  Cipher_aad_sz   AAD buffer size, in bytes.
  
  @retval EFI_SUCCESS           Updates additional authentication data successfully.
  @retval EFI_INVALID_PARAMETER Invalid Parameters.
  @retval EFI_NOT_READY         No valid instance data associated with this protocol(This).
  @retval EFI_DEVICE_ERROR      Other failures. 
**/
typedef
EFI_STATUS
(EFIAPI *EFI_CIPHER_CIPHER_UPDATE_AAD)(
  IN CONST EFI_CIPHER_PROTOCOL    *This,
  IN CONST UINT8                  *Cipher_aad,
  IN UINTN                        Cipher_aad_sz
  );

/**
  Creates a cipher text for the specified message text.

  @param[in]  This            Points to this instance of EFI_CIPHER_PROTOCOL.
  @param[in]  Cipher_ibuf     Points to the buffer of the plain message.
  @param[in]  Cipher_isz      The size of plain message, in bytes.
  @param[in]  Cipher_obuf     Points to the buffer of the output cipher message.
  @param[in]  Cipher_osz      The size of the output buffer, in bytes.
  @param[out] Cipher_vld_osz  Points to the returned size for the cipher.
  
  @retval EFI_SUCCESS           Cipher returned successfully.
  @retval EFI_INVALID_PARAMETER Invalid Parameters.
  @retval EFI_NOT_READY         No valid instance data associated with this protocol(This).
  @retval EFI_DEVICE_ERROR      Other failures. 
**/
typedef
EFI_STATUS
(EFIAPI *EFI_CIPHER_CIPHER_DATA)(
  IN CONST EFI_CIPHER_PROTOCOL    *This,
  IN CONST UINT8                  *Cipher_ibuf,
  IN UINTN                        Cipher_isz,
  IN UINT8                        *Cipher_obuf,
  IN UINTN                        Cipher_osz,
  OUT UINTN                       *Cipher_vld_osz
  );

/**
  This function is called after a cipher calculation to free the resource.

  @param[in]  This                Points to this instance of EFI_CIPHER_PROTOCOL.
  
  @retval EFI_SUCCESS             Deinit successfully.
  @retval EFI_INVALID_PARAMETER   This is NULL.
  @retval EFI_NOT_READY           No valid instance data associated with this protocol(This).
  @retval EFI_DEVICE_ERROR        Other failures. 
**/

typedef
EFI_STATUS
(EFIAPI *EFI_CIPHER_CIPHER_DEINIT)(
  IN CONST EFI_CIPHER_PROTOCOL      *This
  );  


///
/// This protocol allows encrypt/decrypt a message.
///
struct _EFI_CIPHER_PROTOCOL {
  EFI_CIPHER_CIPHER_INIT            efiCipherInit;
  EFI_CIPHER_CIPHER_CTL             efiCipherCtl;
  EFI_CIPHER_CIPHER_DATA            efiCipherData;
  EFI_CIPHER_CIPHER_DEINIT          efiCipherDeInit;
  EFI_CIPHER_CIPHER_UPDATE_AAD      efiCipherUpdateAAD;
  UINT64                            Revision;
};

extern EFI_GUID gEfiCipherProtocolGuid;
extern EFI_GUID gEfiCipherServiceBindingProtocolGuid;

extern EFI_GUID gEfiCipherAlgorithmAES128Guid;
extern EFI_GUID gEfiCipherAlgorithmAES256Guid;
extern EFI_GUID gEfiCipherModeECBGuid;
extern EFI_GUID gEfiCipherModeCBCGuid;
extern EFI_GUID gEfiCipherModeCTRGuid;
extern EFI_GUID gEfiCipherModeCTSGuid;
extern EFI_GUID gEfiCipherModeGCMGuid;
extern EFI_GUID gEfiCipherEngineArmv8Guid;
extern EFI_GUID gEfiCipherEngineCeHwGuid;
extern EFI_GUID gEfiCipherDirEncryptGuid;
extern EFI_GUID gEfiCipherDirDecryptGuid;
extern EFI_GUID gEfiCipherSetParamDirGuid;
extern EFI_GUID gEfiCipherSetParamKeyGuid;
extern EFI_GUID gEfiCipherSetParamIVGuid;
extern EFI_GUID gEfiCipherSetParamModeGuid;

/* GCM */
extern EFI_GUID gEfiCipherSetParamNonceGuid;
extern EFI_GUID gEfiCipherSetXcmTagGuid;
extern EFI_GUID gEfiCipherGetXcmTagGuid;

#endif
