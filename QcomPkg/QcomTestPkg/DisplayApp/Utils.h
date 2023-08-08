/** @file Utils.h
   
  Test utilities for DisplayDxe graphics output protocol

  Copyright (c) 2019 Qualcomm Technologies, Inc.  
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
**/
#include <Uefi.h>

/*=========================================================================
  Public helper APIs
 ==========================================================================*/


/* DisplayUtilsParser
*/
UINTN DisplayUtilsParser(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs);
    


/* DisplayUtilsHelp
*/
void DisplayUtilsHelp();


/* Accpets user input, terminated by two carriage returns
*/
EFI_STATUS DisplayGetConsoleInput(CHAR8 **pBuf, UINT32 *pBufSize);


/* Helper to check whether a current character is a line end character
*/
BOOLEAN IsWhiteSpace(CHAR8 c);


/* Function returns the number of bytes till the next line
 * Return 0 if buffer is NULL or invalid
 */
UINT32 GetBytesInLine(CHAR8 *pBuffer, UINT32 uBufferLength);



