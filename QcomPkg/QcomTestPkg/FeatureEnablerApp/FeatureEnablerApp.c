/** @file FeatureEnablerApp.c
   
  Test application for FeatureEnablerDxe protocol

  Copyright (c) 2019 Qualcomm Technologies, Inc.  
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
**/


/*=========================================================================
      Include Files
==========================================================================*/

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/QcomLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/EFIFeatureEnabler.h>

/*=========================================================================
   Defines
==========================================================================*/
#define MAX_STRING                          64


/*=========================================================================
      Type Definitions
==========================================================================*/


/* Test case entry 
 */
typedef struct {
  CHAR8        sTestName[MAX_STRING];
  EFI_STATUS (*pTestFn)(void);
} TestCaseEntry;


/*=========================================================================
     Local Function Declarations
==========================================================================*/

/* FeatureEnabler Querys status test */
static EFI_STATUS FeatureEnablerQueryStatusTest(void);

/* Output feature enabler app help menu */
static void FeatureEnablerAppHelp(void);
/* FeatureEnabler BVT */
static EFI_STATUS FeatureEnablerBVT(UINT32 uTestNumber);
/* Commandline parser helper */
static UINTN FeatureEnablerParseCommand(CHAR8 *pCommandLine, CHAR8 *pParam, CHAR8 *pValue);


/*=========================================================================
      Globals
==========================================================================*/

/* Total number of test cases */
#define NUM_TEST_CASES        (sizeof(TestCaseList)/sizeof(TestCaseEntry))

/* List of feature enabler test cases 
 */
TestCaseEntry TestCaseList[] = 
{
  {"FeatureEnabler Query Status Test",                  &FeatureEnablerQueryStatusTest},
};


/*=========================================================================
     Global Functions
==========================================================================*/

/**
  The user entry point for the feature enabler application. The user code starts with this function
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.  
  @param[in] SystemTable    A pointer to the EFI System Table.
  
  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
FeatureEnablerAppMain (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS   eStatus  = EFI_INVALID_PARAMETER;
  UINTN        Argc     = 0;
  UINTN        HasValue = 0;
  CHAR8      **Argv;
  CHAR8        Param[MAX_STRING], Value[MAX_STRING];

  AsciiPrint("FeatureEnablerApp (Compiled on: %a)\n\n", __DATE__);
  
  // Get the command line arguments
  if ((EFI_SUCCESS == GetCmdLineArgs (ImageHandle, &Argc, &Argv)) &&
      (Argc > 0))
  {
    // Parse the arguments
    HasValue = FeatureEnablerParseCommand((CHAR8*)Argv[0], (CHAR8*)&Param, (CHAR8*)&Value);

    // If we have at least one parameter
    if (HasValue)
    {
      // Command line passed -<Param>:<Value>, we really just want to know if <Value> was passed for the function below so subtract the number of
      // parased commands in the command line.
      HasValue--;
      eStatus = EFI_SUCCESS;
    }
  }

  // Print help on failure
  if (EFI_SUCCESS != eStatus)
  {
    FeatureEnablerAppHelp();
    return 0;
  }

  // Execute the BVT
  if (0 == AsciiStrCmp("bvt", Param))
  {
    UINT32 uTestCase = AsciiStrDecimalToUintn(Value);
    // Execute the BVT
    FeatureEnablerBVT(uTestCase);
  }
  else
  {
    AsciiPrint("Error: %a is an invalid parameter\n", Param);
  }

  return eStatus;
}

/*=========================================================================
     Local Functions
==========================================================================*/


/* Backlight brightness level control test */
static EFI_STATUS FeatureEnablerBVT(UINT32 uTestNumber)
{
  EFI_STATUS eStatus     = EFI_SUCCESS;
  UINT32     uTestStart  = 0;    
  UINT32     uTestEnd    = NUM_TEST_CASES;
  UINT32     uTestCount  = 0;
  UINT32     uTestPassed = 0;
  UINT32     uCount;  
  
  if ((uTestNumber > 0) &&
      (uTestNumber <= NUM_TEST_CASES))
  {
    uTestStart = uTestNumber-1;
    uTestEnd   = uTestStart+1;
  }

  // Loop all tests
  for (uCount=uTestStart;uCount<uTestEnd;uCount++)
  {
    AsciiPrint("======] Test Case Start   : %a\n\n", TestCaseList[uCount].sTestName);

    // Increment the number of tests run
    uTestCount++;
    if (EFI_SUCCESS == (eStatus = TestCaseList[uCount].pTestFn()))
    {
      // Increment the test pass count
      uTestPassed++;
    }

    AsciiPrint("\n======] Test Case Complete: %a\n\n", (EFI_SUCCESS==eStatus)?"Passed":"Failed");
  }

  if (uTestCount)
  {
    AsciiPrint("\n\nFeatureEnabler BVT Result: %d tests run (%d%% pass rate)\n", uTestCount, (100*uTestPassed)/uTestCount);
  }

  return eStatus;
}


/* 
 * Get status from FeatureEnablerDxe
 */
static EFI_STATUS FeatureEnablerQueryStatusTest(void)
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  EFI_GUID                       sFeatureEnablerGUID      = EFI_FEATURE_ENABLER_PROTOCOL_GUID;
  EFI_QCOM_FEATURE_ENABLER_PROTOCOL        *pFeatureEnablerProtocol;
  EFI_FEATURE_ENABLER_STATUS                sFeatureEnablerStatus;
  
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&sFeatureEnablerGUID, 
                                                     NULL, 
                                                     (VOID **)&pFeatureEnablerProtocol)))                     
  {
    AsciiPrint ("FeatureEnablerQueryStatusTest: LocateProtocol() failed.\n");
  }
  else if (NULL != pFeatureEnablerProtocol->FeatureEnablerQueryStatus)
  {
    gBS->SetMem(&sFeatureEnablerStatus, sizeof(sFeatureEnablerStatus), FEATURE_ENABLER_STATUS_FAIL);
    
    if (EFI_SUCCESS != (eStatus = pFeatureEnablerProtocol->FeatureEnablerQueryStatus(&sFeatureEnablerStatus)))
    {
       AsciiPrint("Error: FeatureEnablerQueryStatusTest failed\n");
    }
    else
    {
      UINT32               i;
      UINT32               uSuccessCount = 0;
      UINT32               uFailCount    = 0;
      UINT32               uUninitCount  = 0;

      /* Print TA load status */
      AsciiPrint("TALoadStatus: %a\n\n", (FEATURE_ENABLER_STATUS_SUCCESS==sFeatureEnablerStatus.eTALoadStatus)?"Success":"Fail");

      /* Print TA command execution status for each module */
      for (i = 0; i < sFeatureEnablerStatus.sTAExeStatus.uNumModules; i++)
      {
        AsciiPrint("Module: %a\n", sFeatureEnablerStatus.sTAExeStatus.sInfo[i].sModuleName);
        
        switch (sFeatureEnablerStatus.sTAExeStatus.sInfo[i].eStatus)
        {
          case FEATURE_ENABLER_STATUS_UNINITIALIZED:
            AsciiPrint("  Status: %a\n", "Uninit");
            uUninitCount++;
            break;
          case FEATURE_ENABLER_STATUS_SUCCESS:
            uSuccessCount++;
            AsciiPrint("  Status: %a\n", "Success");
            break;
          case FEATURE_ENABLER_STATUS_FAIL:
            AsciiPrint("  Status: %a\n", "Fail");
            uFailCount++;
            break;
          default:
            AsciiPrint("  Unkonwn Status: %d\n", sFeatureEnablerStatus.sTAExeStatus.sInfo[i].eStatus);
            break;
        }
      }
      
      /* Print Summary of the pass rate */
      AsciiPrint("\nResult: %d/%d Modules Passed\n", uSuccessCount, sFeatureEnablerStatus.sTAExeStatus.uNumModules);

      /* Print TA unload status */
      AsciiPrint("\nTAUnloadStatus: %a\n", (FEATURE_ENABLER_STATUS_FAIL==sFeatureEnablerStatus.eTAUnloadStatus)?"Fail":"Success");

      if ((FEATURE_ENABLER_STATUS_SUCCESS == sFeatureEnablerStatus.eTALoadStatus) &&
          (0 == uFailCount) &&
          (FEATURE_ENABLER_STATUS_SUCCESS == sFeatureEnablerStatus.eTAUnloadStatus))
      {
        eStatus = EFI_SUCCESS;
      }
      else
      {
        eStatus = EFI_ABORTED;
      }
    }
  }
  
  return eStatus;
}



/* FeatureEnablerApp Help
*/
static void FeatureEnablerAppHelp(void)
{
  UINT32 uCount;
  
  AsciiPrint ("Usage:\n");
  AsciiPrint (" FeatureEnablerApp -[option]:[value]\n\n");
  AsciiPrint (" options:\n");  
  AsciiPrint ("   -bvt            : Execute the feature enabler BVT test or a specific test number\n");  
  AsciiPrint ("\nTest Case List:\n");

  for (uCount=0;uCount<NUM_TEST_CASES;uCount++)
  {
    AsciiPrint ("  %d : %a\n", uCount+1, TestCaseList[uCount].sTestName);
  }
  
  AsciiPrint ("\n\n");  
}


/* FeatureEnablerApp Command line parser
 * 
                                0123456789012345
                                 1234567 1234567
 * Parse a string in the format -<Param>:<Value>
*/
static UINTN FeatureEnablerParseCommand(CHAR8 *pCommandLine, CHAR8 *pParam, CHAR8 *pValue)
{
  UINTN params = 0;
  UINTN strlength = AsciiStrLen(pCommandLine);

  // Initialize output to null
  pParam[0] = '\0';
  pValue[0] = '\0';

  // If we detect the swich and at least 1 valid character
  if ((pCommandLine[0] == '-') &&
      (pCommandLine[0] != ':') &&
      (pCommandLine[0] != ' ') &&
      (strlength > 2))
  {
    UINTN uCount;

    // At least one param detected
    params++;

    // Find the length of the parameter
    for (uCount = 1; uCount<strlength; uCount++)
    {
      if ((pCommandLine[uCount] == ':') ||
        (pCommandLine[uCount] == ' '))
      {
        break;
      }
    }

    // Copy the paramter
    AsciiStrnCpy(pParam, &pCommandLine[1], uCount - 1);
    pParam[uCount-1] = '\0';

    // Copy the optional value
    if ((pCommandLine[uCount] == ':') &&
      ((uCount + 1)<strlength))
    {
      params++;

      AsciiStrnCpy(pValue, &pCommandLine[uCount + 1], strlength - uCount - 1);
      pValue[strlength-uCount-1] = '\0';
    }
  }

  return params;
}

