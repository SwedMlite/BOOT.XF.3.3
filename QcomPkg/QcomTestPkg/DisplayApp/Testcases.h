/** @file Testcases.h
   
  Test application for DisplayDxe graphics output protocol

  Copyright (c) 2019 Qualcomm Technologies, Inc.  
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
**/
#include <Uefi.h>

/*=========================================================================
  Public Structures and Definitions
 ==========================================================================*/



/*=========================================================================
  Public API's
 ==========================================================================*/
/* Display BVT Command Line Parser */
UINTN DisplayBVTParser(CHAR8* pCommandLine, CHAR8* pArgs);

/* Display BVT Help */
void DisplayBVTHelp();

/* 
 * Helper to process a line, this function is able to process line format like below:
 * case 1: 0xabcd1234: 12345678
 * case 2: ABCD1234  : 0x12345678
 * Both register address and value are considered as hex string
 */
EFI_STATUS ParseRegisterValuePair(CHAR8 *pLine, UINT32 uLineLength, UINT64 *pAddr, UINT32 *pRegVal);

/*
 *Verify that the register value is equal to golden setting.
 */
EFI_STATUS DisplayVerifyRegTest(void);


