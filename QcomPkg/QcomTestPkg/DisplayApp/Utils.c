/** @file Utils.c
   
  Test utilities for DisplayDxe graphics output protocol

  Copyright (c) 2019-20 Qualcomm Technologies, Inc.  
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
**/
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/QcomLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/GraphicsOutput.h>
#include <Protocol/EFIDisplayPwrCtrl.h>
#include <Protocol/EFIDisplayPwr.h>
#include <Protocol/EFIDisplayUtils.h>
#include "Testcases.h"


/*=========================================================================
  Local structures and Definitions
 ==========================================================================*/

#define PANEL_OVERRIDE_ENABLE_MASK                  (0x80000000)
#define PANEL_OVERRIDE_PANELID(_ID_)                (~PANEL_OVERRIDE_ENABLE_MASK & (_ID_))

#define MAX_STRING                                  128
#define MAX_UTIL_NAME                               32
#define MAX_UTIL_DESCRIPTION                        64

#define MAX_CONSOLE_INPUT_SIZE                      (1024*1024)

/* Clock list entry
 */
typedef struct {
  CHAR8       sClockName[MAX_STRING];
} ClockListEntry;

/* Enumeration of display variables
 */
typedef enum {
  DISPLAY_VAR_DISABLEDISPLAY = 0,
  DISPLAY_VAR_DISPLAYID,
  DISPLAY_VAR_ENABLEIMAGEFV,
  DISPLAY_VAR_MAX,
} EnvVariables;

/* Environment variable list
 */
typedef struct {
  CHAR16      sVarName[MAX_STRING];
  UINTN       nVarSize;
} EnvVarEntry;

/* Test case entry 
 */
typedef struct {
  CHAR8        sUtilCmd[MAX_UTIL_NAME];                                        /* Utility command */
  CHAR8        sUtilDescription[MAX_UTIL_DESCRIPTION];                         /* Utility description */
  EFI_STATUS   (*pUtilFn)(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs);  /* Test Function Pointer */
} UtilCmdEntry;



/*=========================================================================
  Local variables
 ==========================================================================*/

/* List of display environment variables
 */
EnvVarEntry EnvVarList[] =
{
  {L"DISABLEDISPLAY",        sizeof(UINT8)},      // DISPLAY_VAR_DISABLEDISPLAY
  {L"DISPLAYID",             sizeof(UINT32)},     // DISPLAY_VAR_DISPLAYID
  {L"EnableDisplayImageFv",  sizeof(UINT32)},     // DISPLAY_VAR_ENABLEIMAGEFV
};


/*=========================================================================
  Public Structures and Definitions
 ==========================================================================*/


/* DisplaySetEnvVar()
    Set a generic display variable
 */
static EFI_STATUS DisplaySetEnvVar(CHAR16 *pVarname, UINT32 uValue)
{
  EFI_STATUS                          eStatus                = EFI_SUCCESS;
  CHAR8                               VarValue[MAX_STRING]   = "";
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL    *pDisplayUtilsProtocol  = NULL;

  AsciiSPrint (VarValue, sizeof(VarValue), "%x", uValue);

  eStatus = gBS->LocateProtocol(&gQcomDisplayUtilsProtocolGuid, NULL, (void**)&pDisplayUtilsProtocol);
  if ((EFI_SUCCESS !=  eStatus) ||
      (NULL        ==  pDisplayUtilsProtocol))
  {
    DEBUG((EFI_D_WARN, "Locate display utils protocol failed with status: %r\n", eStatus));
  }
  else
  {
    // Set variable value
    eStatus = pDisplayUtilsProtocol->DisplayUtilsSetVariable(pVarname, (UINT8 *)VarValue, AsciiStrLen (VarValue), 0);
  }

  return eStatus;
}


/* DisplayGetEnvVar()
    Get a generic display variable
 */
static EFI_STATUS DisplayGetEnvVar(CHAR16 *pVarname, UINT32 *pValue)
{
  EFI_STATUS                          eStatus                = EFI_SUCCESS;
  CHAR8                               VarValue[MAX_STRING]   = "";
  UINTN                               uStorageSize           = MAX_STRING;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL    *pDisplayUtilsProtocol  = NULL;

  eStatus = gBS->LocateProtocol(&gQcomDisplayUtilsProtocolGuid, NULL, (void**)&pDisplayUtilsProtocol);
  if ((EFI_SUCCESS !=  eStatus) ||
      (NULL        ==  pDisplayUtilsProtocol))
  {
    DEBUG((EFI_D_WARN, "Locate display utils protocol failed with status: %r\n", eStatus));
  }
  else
  {
    // Get variable value
    eStatus = pDisplayUtilsProtocol->DisplayUtilsGetVariable(pVarname, (UINT8 *)VarValue, &uStorageSize, 0);
  }
  
  if ((EFI_SUCCESS  == eStatus) &&
      (uStorageSize  > 0))
  {
    *pValue = AsciiStrHexToUintn(VarValue);
  }
  else
  {
    *pValue = 0;
  }

  return eStatus;
}


/* External Display mode set 
 */
static EFI_STATUS DisplayUtilSetModeExt(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  EFI_STATUS                        eStatus            = EFI_SUCCESS;
  EFI_GUID                          sDisplayUtilGUID   = EFI_DISPLAYUTILS_PROTOCOL_GUID;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL  *pDisplayUtilProtocol;
  UINT32                            uDisplayId		   = 2; /* set MDP_EXTERNAL_DISPLAY by default */
  UINTN                             uMode              = AsciiStrDecimalToUintn(pArgs);
  UINTN                             uFlags             = 0;

  // Map the display based on the command
  if (0 == AsciiStriCmp("setmodeext1", pCommandLine))  
  {
    uDisplayId = 2; /* MDP_DISPLAY_EXTERNAL -- mini DP (EDID mode) */
  }
  else if (0 == AsciiStriCmp("setmodeext1a", pCommandLine))
  {
    uDisplayId = 2; /* MDP_DISPLAY_EXTERNAL -- mini DP (bypass EDID) */
    uFlags     = 1;
  }
  else if (0 == AsciiStriCmp("setmodeext2", pCommandLine))
  {
    uDisplayId = 3; /* MDP_DISPLAY_EXTERNAL3 -- DP over Type-C (Port#0) */
  }
  else if (0 == AsciiStriCmp("setmodeext3", pCommandLine))
  {
    uDisplayId = 4; /* MDP_DISPLAY_EXTERNAL4 -- DP over Type-C (Port1) */
  }

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sDisplayUtilGUID,
                                                     NULL,
                                                     (VOID **)&pDisplayUtilProtocol)))
  {
     AsciiPrint("DisplaySetModeExt: LocateProtocol() failed.\n");
  }
  else 
  {
    if (EFI_SUCCESS != (eStatus = pDisplayUtilProtocol->DisplayUtilsSetMode(uDisplayId, uMode, uFlags)))
    {
      AsciiPrint("DisplaySetModeExt: Failed to set external display ModeNum=%d\n", uMode);
    }
  }

  return eStatus;
}


/* Panel power state changes */
EFI_STATUS DisplayUtilPowerState(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_DISPLAY_POWER_PROTOCOL          *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gEfiDisplayPowerStateProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("PowerState: LocateProtocol() failed.\n");
    return eStatus;
  }
  else 
  {
     EFI_DISPLAY_POWER_STATE ePowerState  = (AsciiStrDecimalToUintn(pArgs)==0)?EfiDisplayPowerStateOff:EfiDisplayPowerStateMaximum;

     if (EFI_SUCCESS == (eStatus = pDisplayPwrCtrlProtocol->SetDisplayPowerState(NULL, ePowerState)))
     {
        AsciiPrint("PowerState: Successfully set power state to %d.\n", ePowerState);
     }
     else
     {
        AsciiPrint("PowerState: Failed (%d).\n", eStatus);
     }

  }

  return eStatus;
}


/**
Display Set Mode
**/
static EFI_STATUS DisplayUtilSetMode(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  EFI_GUID                       sGfxOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  EFI_GRAPHICS_OUTPUT_PROTOCOL  *pGfxProtocol;

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&sGfxOutputGUID, 
                                                     NULL, 
                                                     (VOID **)&pGfxProtocol)))                 
  {
    AsciiPrint ("SetMode: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
     UINTN uModeIndex = AsciiStrDecimalToUintn(pArgs);
     
     if (EFI_SUCCESS == (eStatus = pGfxProtocol->SetMode(pGfxProtocol, uModeIndex)))
     {
       AsciiPrint("SetMode : Mode#%d succesfully changed (Current Mode %dx%d)\n",
              (UINT32)uModeIndex,
              pGfxProtocol->Mode->Info->HorizontalResolution,
              pGfxProtocol->Mode->Info->VerticalResolution);
     }
     else
     {
        AsciiPrint("SetMode : Mode#%d failed! (status:%d)\n",
              (UINT32)uModeIndex,
              eStatus);
     }
  }    

  return eStatus;
}



/* Extract out XML tag for panel names from panel configuration
*/
static void GetPanelName(CHAR8 *pConfig, uint32 uConfigLength, CHAR8 *pPanelName, uint32 uPanelNameLength)
{
   CHAR8  *pTagStart;
   CHAR8  *pTagEnd;   

   ZeroMem(pPanelName, uPanelNameLength);
   
   if ((NULL != (pTagStart = AsciiStrStr(pConfig, "<PanelDescription>"))) &&
       (NULL != (pTagEnd   = AsciiStrStr(pConfig, "</PanelDescription>"))))
   {
     CHAR8   *pNameStart = pTagStart+AsciiStrLen("<PanelDescription>");
     uint32  uLength     = (pTagEnd-pNameStart);
     uint32  uCopyAmount = (uLength<uPanelNameLength)?uLength:uPanelNameLength;
     
     AsciiStrnCpy(pPanelName, pNameStart, uCopyAmount);        
   }
   else if ((NULL != (pTagStart = AsciiStrStr(pConfig, "<PanelName>"))) &&
            (NULL != (pTagEnd   = AsciiStrStr(pConfig, "</PanelName>"))))
   {
     CHAR8   *pNameStart = pTagStart+AsciiStrLen("<PanelName>");
     uint32  uLength     = (pTagEnd-pNameStart);
     uint32  uCopyAmount = (uLength<uPanelNameLength)?uLength:uPanelNameLength;
     
     AsciiStrnCpy(pPanelName, pNameStart, uCopyAmount);        
   }
   else    
   {
     AsciiStrnCpy(pPanelName, "Panel (Unknown configuration)", AsciiStrLen("Panel (Unknown configuration)"));
   }
}


/* DisplayListPanels Help
*/
static UINT32 DisplayListPanels(uint32 uCurrentIndex, UINTN bShow)
{
  EFI_STATUS                        eStatus            = EFI_SUCCESS;
  UINT32                            uNumPanels         = 0;  
  EFI_GUID                          sDisplayUtilGUID   = EFI_DISPLAYUTILS_PROTOCOL_GUID;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL  *pDisplayUtilProtocol;

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sDisplayUtilGUID,
                                                     NULL,
                                                     (VOID **)&pDisplayUtilProtocol)))
  {
     AsciiPrint("DisplayListPanels: LocateProtocol() failed.\n");
  }
  else 
  {
    EFI_DISPLAY_UTILS_PANEL_CONFIG_PARAMS sPanelConfig;
    UINT32                                uIndex      = 0;
    UINT32                                uParamSize  = sizeof(sPanelConfig);

    if (bShow)
    {
      AsciiPrint ("Available Panel List:\n");
      AsciiPrint ("%2a 0] Default Panel (Auto detect)\n", (uCurrentIndex==0)?"*":"");
    } 

    do
    {
      ZeroMem(&sPanelConfig, sizeof(sPanelConfig));
      sPanelConfig.uPanelIndex = uIndex;
      if (EFI_SUCCESS == (eStatus = pDisplayUtilProtocol->DisplayUtilsGetProperty(EFI_DISPLAY_UTILS_PANEL_CONFIG, (VOID*)&sPanelConfig, &uParamSize)))
      {
         if (bShow)
         {
           char sName[128];

           GetPanelName((CHAR8*)sPanelConfig.pPanelConfig, sPanelConfig.uPanelConfigLength, (CHAR8*)&sName, sizeof(sName));
         
            AsciiPrint ("%2a %d] %a\n", (uCurrentIndex==(uIndex+1))?"*":"", uIndex+1, sName);
         }

         uIndex++;
         uNumPanels++;
      }
    }  while (eStatus == EFI_SUCCESS);  
  }


  if (bShow)
  {
    AsciiPrint ("\n\n"); 
    AsciiPrint ("* - Current override selection"); 
    AsciiPrint ("\n\n");  
  }

  return uNumPanels;
}


/* DisplayUtilDisable Helper
*/
static EFI_STATUS DisplayUtilDisable(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  UINTN uValue = AsciiStrDecimalToUintn(pArgs);  

  // Configure or display the environment variable
  if (EFI_SUCCESS != DisplaySetEnvVar((CHAR16*)&EnvVarList[DISPLAY_VAR_DISABLEDISPLAY].sVarName, uValue))
  {
     AsciiPrint("Error: Failed to set environment variable for disabledisplay.\n");
  }

  return EFI_SUCCESS;
}


/* DisplayUtilPanelID Helper
*/
static EFI_STATUS DisplayUtilPanelID(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  UINTN  bNext       = (0==AsciiStriCmp("next", pArgs))?1:0;
  UINTN  uValue      = AsciiStrHexToUintn(pArgs);
  UINT32 nNumPanels  = 0;
  UINTN  uPanelIndex = 0;
  UINT32 uPanelId    = 0;
  
  // Read the current Panel ID
  if (EFI_SUCCESS == DisplayGetEnvVar((CHAR16*)&EnvVarList[DISPLAY_VAR_DISPLAYID].sVarName, &uPanelId))
  {
    // Ensure the enable bit is set
    if (uPanelId & PANEL_OVERRIDE_ENABLE_MASK)
    {
        // Offset the ID by 1 so we report 0 as the default (no override) correctly
        uPanelIndex = PANEL_OVERRIDE_PANELID(uPanelId) + 1;
    }
  }
  
  // Update the variable if there is a request to change it.
  if (uNumArgs)
  {
     // Query the list of valid panels
     nNumPanels = DisplayListPanels(uPanelIndex, 0);
  
     // Relative adjustment, go to the next panel
     if (uValue<=nNumPanels)
     {
  
       // Request is to just increment the selection (i.e next)
       if (bNext)
       {
         // Clear the flag, and go to th next ID.
         uPanelId =  PANEL_OVERRIDE_PANELID(uPanelId); 
         uPanelId++;
  
         // Wrap around
         if (uPanelId >= nNumPanels)
         {
           uPanelId = 0x0;
         }
  
         // Reapply the mask
         uPanelId = (PANEL_OVERRIDE_ENABLE_MASK | uPanelId); 
       }
       else 
       {
         // Absolute adjustment, go a specific index
         uPanelId = (0==uValue)?0:(PANEL_OVERRIDE_ENABLE_MASK | (uValue-1));
       }
       
       // Configure or display the environment variable, 0 has a special meaning which is auto detect (no variable set)
       if (EFI_SUCCESS == DisplaySetEnvVar((CHAR16*)&EnvVarList[DISPLAY_VAR_DISPLAYID].sVarName, uPanelId))
       {
          // Update with the new panel id and show the updated table, no override means auto-detect
          if (uPanelId & PANEL_OVERRIDE_ENABLE_MASK)
          {
            uPanelIndex = PANEL_OVERRIDE_PANELID(uPanelId) + 1;
          }
          else
          {
            uPanelIndex = 0;
          }
          
          DisplayListPanels(uPanelIndex, 1);
       }
       else
       {
         AsciiPrint("Error: Failed to set environment variable for panelid.\n");
       }
    }   
    else
    {
         AsciiPrint("Error: Invalid panel selection (%d).\n", uValue);        
    }
  }
  else
  {
      // Show the list of panels, including the selected one.
      nNumPanels = DisplayListPanels(uPanelIndex, 1);
  }

  return EFI_SUCCESS;
}


/* DisplayUtilEnableImageFv Helper
*/
static EFI_STATUS DisplayUtilEnableImageFv(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  UINTN uValue = AsciiStrDecimalToUintn(pArgs);

  // Configure or display the environment variable
  if (EFI_SUCCESS != DisplaySetEnvVar((CHAR16*)&EnvVarList[DISPLAY_VAR_ENABLEIMAGEFV].sVarName, uValue))
  {
    AsciiPrint("DisplayUtilEnableImageFv: Failed to set environment variable for display enable imagefv.\n");
  }
  else
  {
    AsciiPrint("DisplayUtilEnableImageFv: Set imagefv loading status as %a.\n", (0 == uValue) ? "disabled" : "enabled");
  }

  return EFI_SUCCESS;
}



/* DisplayUtilVerifyReg two commandsformat supported:
 * Format 1: start DisplayApp -RegTest:addr:val (addr and val are hex string)
 * Format 2: start DisplayApp -RegTest, user can then input multiple lines of addr:val (addr and val are hex string), 
 *           until two carriage return.
 */
static EFI_STATUS DisplayUtilVerifyReg(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  EFI_STATUS eStatus = EFI_SUCCESS;

  if ((NULL == pCommandLine) ||
      (NULL == pArgs))
  {
    eStatus = EFI_INVALID_PARAMETER;
    AsciiPrint("WARNING: DisplayUtilVerifyReg invalid parameter\n");
  }
  else if (0 == uNumArgs)
  {
    eStatus = DisplayVerifyRegTest();
  }
  else
  {
    UINT32 uArgsLen    = AsciiStrLen(pArgs);
    UINT64 uRegAddress = 0;
    UINT32 uRegValue   = 0;

    if (EFI_SUCCESS != (eStatus = ParseRegisterValuePair(pArgs, uArgsLen, &uRegAddress, &uRegValue)))
    {
      AsciiPrint("ERROR: ParseRegisterValuePair failed\n");
    }
    else if (0 == uRegAddress)
    {
      AsciiPrint("ERROR: ParseRegisterValuePair Addr is 0, \t%a\n", pArgs);
      eStatus = EFI_UNSUPPORTED;
    }
    else
    {
      UINT32 uReadVal = *(UINT32*)uRegAddress;

      if (uReadVal != uRegValue)
      {
        AsciiPrint("WARNING: Addr: 0x%x, GoldenSeting: 0x%x, ReadVal: 0x%x\n", uRegAddress, uRegValue, uReadVal);
        eStatus = EFI_UNSUPPORTED;
      }
      else
      {
        AsciiPrint("SUCCESS: Register matches\n");
      }
    }
  }

  return eStatus;
}



/*=========================================================================
  Util function list and helpers
 ==========================================================================*/


/* List of all display utility commands 
 */
UtilCmdEntry sUtilList[] = //zwy need modify this
{
    {"disabledisplay",
     "Set or clear the disable display variable.",
     &DisplayUtilDisable},

    {"setpower",
     "Turn the display on/off. 0=off, 1=on.",
     &DisplayUtilPowerState},

    {"setmode",
     "Set the mode on the internal/embedded display.",
     &DisplayUtilSetMode},

    {"setmodeext1",
     "Set the external display mini DP mode.",
     &DisplayUtilSetModeExt},     

    {"setmodeext1a",
     "Set the external display mini DP mode (ignoring sink EDID).",
     &DisplayUtilSetModeExt},    

    {"setmodeext2",
     "Set the external-3 display DP over USB#0 port.",
     &DisplayUtilSetModeExt}, 

    {"setmodeext3",
     "Set the external-4 display DP over USB#1 port.",
     &DisplayUtilSetModeExt}, 

    {"panelid",
     "Set panel ID. No params lists all panels, 'next' to toggle.",
     &DisplayUtilPanelID}, 

    {"enableimagefv",
     "Enable imagefv to load logo from imagefv.",
     &DisplayUtilEnableImageFv}, 

     {"RegTest",
      "Verify display registers",
      &DisplayUtilVerifyReg},

};

/* Total number of test cases */
#define NUM_UTIL_FUNCTIONS                           (sizeof(sUtilList)/sizeof(UtilCmdEntry))



/* DisplayUtilsParser
*/
UINTN DisplayUtilsParser(CHAR8* pCommandLine, CHAR8* pArgs, UINTN uNumArgs)
{
  UINTN uResult = 0;
  UINTN uCount;

  for (uCount = 0; uCount < NUM_UTIL_FUNCTIONS; uCount++ )
  {
    if (0 == AsciiStrCmp(pCommandLine, sUtilList[uCount].sUtilCmd))
    {
        /* Execute the utility function */
        sUtilList[uCount].pUtilFn(pCommandLine, pArgs, uNumArgs);

        uResult = 1;
    }
  }

  return uResult;
}


/* DisplayUtilsHelp
*/
void DisplayUtilsHelp()
{
  UINTN uCount;
  
  for (uCount = 0; uCount <NUM_UTIL_FUNCTIONS; uCount++ )
  {
    AsciiPrint("  -%-16a : %a\n", sUtilList[uCount].sUtilCmd, sUtilList[uCount].sUtilDescription);
  }

}


/* Accpets user input, terminated by two carriage returns
*/
EFI_STATUS DisplayGetConsoleInput(CHAR8 **pBuf, UINT32 *pBufSize)
{
  EFI_STATUS          eStatus               = EFI_SUCCESS;
  CHAR8              *pGoldenSettingBuf     = NULL;
  UINT32              index                 = 0;
  EFI_INPUT_KEY       sKey;
  UINTN               WaitIndex;

  SetMem(&sKey, 0, sizeof(EFI_INPUT_KEY));
  
  if (NULL == gST->ConIn)
  {
    eStatus = EFI_OUT_OF_RESOURCES;
  }
  else if (NULL == (pGoldenSettingBuf = (CHAR8*)AllocatePool(MAX_CONSOLE_INPUT_SIZE)))
  {
    eStatus = EFI_OUT_OF_RESOURCES;
  }
  else
  {    
    /* Get buffer from user console input, terminated by two carriage returns */
    while (index < (MAX_CONSOLE_INPUT_SIZE-1))
    {
      if (EFI_SUCCESS != (eStatus = gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &WaitIndex)))
      {
        continue;
      }
      
      gST->ConIn->ReadKeyStroke(gST->ConIn, &sKey);
      
      if (0 != sKey.UnicodeChar)
      {  
        pGoldenSettingBuf[index++] = (sKey.UnicodeChar & 0xff);

        /* Terminated if last two characters are carriage return */
        if ((index > 2) && 
            (('\r' == pGoldenSettingBuf[index-1]) ||
            ('\n' == pGoldenSettingBuf[index-1])) &&
            (('\r' == pGoldenSettingBuf[index-2]) ||
            ('\n' == pGoldenSettingBuf[index-2])))
        {
          break;
        }
      }
    }
    
    pGoldenSettingBuf[index] = '\0';
    *pBuf                    = pGoldenSettingBuf;
    *pBufSize                = index + 1;    
 }

 return eStatus;
}


/** 
 Helper to check whether a current character is a line end character
 **/
BOOLEAN IsWhiteSpace(CHAR8 c)
{
  BOOLEAN bRet = FALSE;
  
  if((c == '\r')||
     (c == '\n') ||
     (c == '\t') ||
     (c == ' ') ||
     (c == '\0')
     )
  {
    bRet =  TRUE;
  }

  return bRet;
}


/* 
 * Function returns the number of bytes till the next line
 * Return 0 if buffer is NULL or invalid
 */
UINT32 GetBytesInLine(CHAR8 *pBuffer, UINT32 uBufferLength)
{
  UINT32 uBytesInLine = 0;
  UINT32 uIndex       = 0;
  CHAR8 *pBuf         = pBuffer;
  
  if ((NULL == pBuf) || 
      (0 == uBufferLength))
  {
    
  }
  else
  {
    BOOLEAN bFoundCarriageRet = FALSE;
    
    while(uIndex < uBufferLength)
    {
      CHAR8 uChar = pBuf[uIndex];
      
      if (('\r' == uChar) ||
          ('\n' == uChar) ||
          ('\0' == uChar))
      {
        uIndex++;
        bFoundCarriageRet = TRUE;
        break;
      }
      else
      {
        uIndex++;
      }
    }

    uBytesInLine = uIndex;

    /* Overwrite return value if no carriage return found */
    if (FALSE == bFoundCarriageRet)
    {
      uBytesInLine = uBufferLength;
    }
  }

  return uBytesInLine;
}

