/** @file Testcases.c
   
  Test application for DisplayDxe graphics output protocol

  Copyright (c) 2019 Qualcomm Technologies, Inc.  
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  
**/
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/QcomLib.h>
#include <Library/QcomBaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/GraphicsOutput.h>
#include <Protocol/EFIDisplayPwrCtrl.h>
#include <Protocol/EFIDisplayPwr.h>
#include <Protocol/EFIClock.h>
#include <Protocol/EFIDisplayUtils.h>
#include <string.h>
#include "Utils.h"
#include "Testcases.h"


/*=========================================================================
  Public Structures and Definitions
 ==========================================================================*/
 
/* String definitions */

#define MAX_STRING                          64
#define TESTCASE_MAX_NAME                   40
#define TESTCASE_MAX_DESCRIPTION            140

#define BITMAP_IMAGE_WIDTH                  640
#define BITMAP_IMAGE_HEIGHT                 480

#define BACKGROUND_R                        0x00
#define BACKGROUND_G                        0x66
#define BACKGROUND_B                        0xCC
#define BACKGROUND_A                        0xFF

#define DEFAULT_WAIT                        (10*16*1000)    // ~10  Frames
#define DEFAULT_LONG_WAIT                   (30*16*1000)    // ~30 Frames

#define PANEL_OVERRIDE_ENABLE_MASK          (0x80000000)
#define PANEL_OVERRIDE_PANELID(_ID_)        (~PANEL_OVERRIDE_ENABLE_MASK & (_ID_))

#define DYNAMIC_REFRESH_MAX_FREQ            16
#define DYNAMIC_REFRESH_PLL_CODE_PER_FREQ   3
#define DYNAMIC_REFRESH_MAX_DSI_NUM         2
#define DYNAMIC_REFRESH_MAX_PLL_CODES_SIZE  (DYNAMIC_REFRESH_MAX_FREQ*DYNAMIC_REFRESH_PLL_CODE_PER_FREQ*DYNAMIC_REFRESH_MAX_DSI_NUM)

#define GOLDEN_SETTING_MAX_LINE_SIZE        64


/* Clock list entry
 */
typedef struct {
  CHAR8       sClockName[MAX_STRING];
} ClockListEntry;

/* Test case description 
 */
typedef struct {
    CHAR8     sTestName[TESTCASE_MAX_NAME];               /* Test name */
    CHAR8     sTestDescription[TESTCASE_MAX_DESCRIPTION]; /* Test description */
} TestCaseInfo;

/* Test case entry 
 */
typedef struct {
  TestCaseInfo  *pTestInfo;                                  /* Test description */
  EFI_STATUS   (*pTestFn)(void);                             /* Test Function Pointer */
} TestCaseEntry;



/*=========================================================================
  Local Variables
 ==========================================================================*/

static void    *pBitmapImage = NULL;


/*=========================================================================
  Local structures
 ==========================================================================*/

/* Total number of clock entries */
#define NUM_CLOCK_ENTRIES         (sizeof(ClockList)/sizeof(ClockListEntry))   

/* List of all mdss clocks 
 */
ClockListEntry ClockList[] = 
{
   {"gcc_disp_ahb_clk"},
   {"disp_cc_mdss_ahb_clk"},
   {"disp_cc_mdss_mdp_clk"},
   {"disp_cc_mdss_vsync_clk"},
   {"disp_cc_mdss_esc0_clk"},
   {"disp_cc_mdss_byte0_clk"},
   {"disp_cc_mdss_byte0_intf_clk"},
   {"disp_cc_mdss_pclk0_clk"},
   {"disp_cc_mdss_esc1_clk"},   
   {"disp_cc_mdss_byte1_clk"},
   {"disp_cc_mdss_byte1_intf_clk"},
   {"disp_cc_mdss_pclk1_clk"},
};


/*=========================================================================
  Local function prototypes
 ==========================================================================*/

static void DisplayDumpClocks();
static void DisplayClockStatus(CHAR8 *pClockName);
static void DisplayBltPrintResults(CHAR8 *testName, UINT64 byteProcessed, UINT32 totalTime, UINT32 blockSize);
static VOID EFIAPI DummyEventHandle( IN EFI_EVENT  Event, IN VOID *Context);
static VOID EFIAPI HallMonitorTestCallBack(IN EFI_EVENT  Event, IN VOID *Context);
static EFI_STATUS VerifyRegisterSettings(CHAR8 *pFile, UINT32 uBufSize);


/*=========================================================================
  Test and helper functions
 ==========================================================================*/


/* Generate a checkerboard bitmap image
*/
static EFI_STATUS DisplayGenerateBitmap(void)
{
  EFI_STATUS    eStatus            = EFI_SUCCESS;

  eStatus = gBS->AllocatePool(EfiBootServicesData, (BITMAP_IMAGE_WIDTH*BITMAP_IMAGE_HEIGHT*4), (VOID**)&pBitmapImage);
  
  if ((eStatus != EFI_SUCCESS) || (pBitmapImage == NULL))
  {
    eStatus = EFI_OUT_OF_RESOURCES;
  }
  else
  {
      UINT32  pattern[2]   = {0xFF993300, 0xFFFFFFF};
      UINT32  *pData       = (UINT32*)pBitmapImage;
      UINT32  uPatternSize = 4;
      UINT32  x, y;

      
      for (y=0; y<BITMAP_IMAGE_HEIGHT ;y++)
      {
        for (x=0; x<BITMAP_IMAGE_WIDTH; x++)
        {
          *pData++ = pattern[((y>>uPatternSize)+(x>>uPatternSize)) & 1];
        }
      }  
  }

  return eStatus;
}


/* DisplayInfoTest()
 */
 static TestCaseInfo DisplayInfoDescription = 
{
    "Display Info",
    "Reports mode information from the graphics output protocol (GOP)."    
};

static EFI_STATUS DisplayInfoTest(void)
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  EFI_GUID                       sGfxOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  EFI_GRAPHICS_OUTPUT_PROTOCOL  *pGfxProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&sGfxOutputGUID, 
                                                     NULL, 
                                                     (VOID **)&pGfxProtocol)))                     
  {
    AsciiPrint ("DisplayInfoTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION   *pModeInfo;
    UINTN                                   nModeInfoSize = sizeof(EFI_GRAPHICS_OUTPUT_MODE_INFORMATION);
    UINT32                                  mode = 0;

    AsciiPrint("Available Display Modes:\n\n");
    do {    
      if (EFI_SUCCESS == (eStatus = pGfxProtocol->QueryMode(pGfxProtocol, mode, &nModeInfoSize, &pModeInfo)))
      {
         AsciiPrint("%d] %dx%d (Format:%d)\n", mode, pModeInfo->HorizontalResolution, pModeInfo->VerticalResolution, (UINT32)pModeInfo->PixelFormat);
         mode++;
      }
    } while (EFI_SUCCESS == eStatus);

    // Succes if we have more than one mode 
    if (mode>0)
    {
      eStatus = EFI_SUCCESS;
    }
    AsciiPrint("\nTotal number of modes enumerated: %d\n\n", mode);

    if (NULL != pGfxProtocol->Mode)
    {
        AsciiPrint("DisplayDxe Mode Information:\n");
        AsciiPrint("  Number of modes exposed: %d\n", pGfxProtocol->Mode->MaxMode);
        AsciiPrint("  Current mode index     : %d\n", pGfxProtocol->Mode->Mode);
        if (NULL != pGfxProtocol->Mode->Info)
        {
          AsciiPrint("  Current mode details   : %dx%d (Format:%d)\n", pGfxProtocol->Mode->Info->HorizontalResolution, pGfxProtocol->Mode->Info->VerticalResolution, (UINT32)pGfxProtocol->Mode->Info->PixelFormat);
        }
        else
        {
          AsciiPrint("  Current mode details   : Unavailable\n");
        }
        AsciiPrint("  Frame buffer address   : 0x%08x\n", (UINT32) pGfxProtocol->Mode->FrameBufferBase);
        AsciiPrint("  Frame buffer size      : %d bytes\n", pGfxProtocol->Mode->FrameBufferSize);
    }
    else
    {
      AsciiPrint("Error: Current mode not set!\n");
    }
  }

  return eStatus;
}


/* DisplayBltPerformanceTest()
 */
static TestCaseInfo DisplayBltPerformanceDescription = 
{
    "Blt Performance",
    "Performance test for Blt operation. 5KB, 100KB and 1MB blocks of data are copied from Buffer to Video, Video to Video and Blt Fill."    
};

static EFI_STATUS DisplayBltPerformanceTest(void)
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  UINT32                         uStartTime;
  UINT32                         uEndTime;
  UINT32                         uTotalFuncTime = 0; 
  UINT64                         perfno;  
  EFI_GUID                       sGfxOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  EFI_GRAPHICS_OUTPUT_PROTOCOL  *pGfxProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sGfxOutputGUID,
      NULL,
      (VOID **)&pGfxProtocol)))
  {
      AsciiPrint("DisplayBltOperationTest: LocateProtocol() failed.\n");
  }
  else
  {
      EFI_GRAPHICS_OUTPUT_MODE_INFORMATION   *pModeInfo;
      UINTN                                   nModeInfoSize;
      EFI_GRAPHICS_OUTPUT_BLT_PIXEL           bgPixel;
      UINT32                                 *BltBuffer = NULL;
      UINTN                                   BufferLen;
      UINT32                                  mode = 0;
      UINT32                                  inplace;

      if (EFI_SUCCESS != (eStatus = pGfxProtocol->SetMode(pGfxProtocol, mode)))
      {
          AsciiPrint("DisplayBltOperationTest: SetMode() failed.\n");
      }
      else if (EFI_SUCCESS != (eStatus = pGfxProtocol->QueryMode(pGfxProtocol, 0, &nModeInfoSize, &pModeInfo)))
      {
          AsciiPrint("DisplayBltOperationTest: QueryMode() failed.\n");
      }
      else
      {
          // Pixel sizes to execute (each operation is 4 bytes/32bpp)
          UINT32 blocksize[]      = { 1, 64, 256, 512, 1024 };
          // Test loop times of items from blocksize[]
          UINT32 iterationArray[] = { 1000 * 1000, 200 * 1000, 50 * 1000, 20 * 1000, 10 * 1000 };
          UINT32 blockLength      = sizeof(EFI_GRAPHICS_OUTPUT_BLT_PIXEL);
          UINT32 verti            = 1;
          UINT32 loopv;
          UINT32 yPos;
          UINT32 iter;

          for (inplace = 0; inplace < 2; inplace++)
          {
              AsciiPrint("\nPerformance numbers %a: \n\n", (0 == inplace) ? "incrementing addresses" : "in-place addresses");

              
              AsciiPrint("\nVideo Buffer fill (EfiBltVideoFill)\n");
              
              for (iter = 0; iter < (sizeof(blocksize) / sizeof(blocksize[0])); iter++)
              {
                  UINT32 hori = blocksize[iter];

                  // Limit the block size to the horizontal resolution
                  if (blocksize[iter] > pModeInfo->HorizontalResolution)
                  {
                      blocksize[iter] = pModeInfo->HorizontalResolution;
                  }

                  /* Fill background as Blue */
                  bgPixel.Blue     = BACKGROUND_B;
                  bgPixel.Green    = BACKGROUND_G;
                  bgPixel.Red      = BACKGROUND_R;
                  bgPixel.Reserved = BACKGROUND_A;


                  // Start Time   
                  yPos = 0;
                  uStartTime = GetTimerCountms();
                  for (loopv = 0; loopv < iterationArray[iter]; loopv++)
                  {
                      if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol,
                                                                      (EFI_GRAPHICS_OUTPUT_BLT_PIXEL*)&bgPixel,
                                                                      EfiBltVideoFill,
                                                                      0, 0,
                                                                      0, yPos,
                                                                      hori,
                                                                      verti,
                                                                      0)))
                      {
                          break;
                      }

                      // For non-inplace cases, keep moving the YPosition
                      if (!inplace)
                      {
                          yPos++;
                          if (yPos >= pModeInfo->VerticalResolution)
                          {
                              yPos = 0;
                          }
                      }
                  }

                  if (eStatus == EFI_SUCCESS)
                  {
                      // End time
                      uEndTime = GetTimerCountms();
                      //Function execution time(ms)
                      uTotalFuncTime = (uEndTime - uStartTime);

                      if (uTotalFuncTime == 0)
                      {
                          AsciiPrint("Total time taken for BltVideoFill: 0ms\n");
                      }
                      else
                      {
                          perfno = (blocksize[iter] * iterationArray[iter] * blockLength * 1000) / uTotalFuncTime;

                          DisplayBltPrintResults("BltVideoFill", perfno, uTotalFuncTime, blocksize[iter]);
                      }
                  }
                  else
                  {
                      AsciiPrint("DisplayBltOperationTest: Blt(EfiBltVideoFill) %d pixels failed. \n", blocksize[iter]);
                      break;
                  }
              }


              // Buffer to Video
              AsciiPrint("\nSystem buffer to video buffer copy (EfiBltBufferToVideo)\n");
              for (iter = 0; iter < (sizeof(blocksize) / sizeof(blocksize[0])); iter++)
              {
                  UINT32 hori = blocksize[iter];
                  
                  BufferLen = hori * verti * sizeof(EFI_GRAPHICS_OUTPUT_BLT_PIXEL);

                  eStatus = gBS->AllocatePool(EfiBootServicesData, (BufferLen), (VOID**)&BltBuffer);
                  if ((eStatus != EFI_SUCCESS) || (BltBuffer == NULL))
                  {
                      eStatus = !EFI_SUCCESS;
                      break;
                  }
                  else
                  {
                      //Zero out the buffer to make it black
                      ZeroMem(BltBuffer, (BufferLen));

                      // Start Time
                      yPos = 0;
                      uStartTime = GetTimerCountms();
                      for (loopv = 0; loopv < iterationArray[iter]; loopv++)
                      {
                          if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol,
                                                                          (EFI_GRAPHICS_OUTPUT_BLT_PIXEL*)BltBuffer,
                                                                          EfiBltBufferToVideo,
                                                                          0, 0,
                                                                          0, yPos,
                                                                          hori,
                                                                          verti,
                                                                          0)))
                          {
                              break;
                          }

                          // For non-inplace cases, keep moving the YPosition
                          if (!inplace)
                          {
                              yPos++;
                              if (yPos >= pModeInfo->VerticalResolution)
                              {
                                  yPos = 0;
                              }
                          }
                      }

                      if (EFI_SUCCESS == eStatus)
                      {
                          // End time
                          uEndTime = GetTimerCountms();
                          //Function execution time(ms)
                          uTotalFuncTime = (uEndTime - uStartTime);
                          if (uTotalFuncTime == 0)
                          {
                              AsciiPrint("Total time taken for BltBufferToVideo: 0ms\n");
                          }
                          else
                          {
                              perfno = (blocksize[iter] * iterationArray[iter] * blockLength * 1000) / (uTotalFuncTime);

                              DisplayBltPrintResults("BltBufferToVideo", perfno, uTotalFuncTime, blocksize[iter]);
                          }
                      }
                      else
                      {
                          AsciiPrint("DisplayBltOperationTest: Blt(EfiBltBufferToVideo) %d pixels failed. \n", blocksize[iter]);
                          break;
                      }

                      gBS->FreePool(BltBuffer);
                  }
              }

              // Video to Video copy 
              AsciiPrint("\nVideo buffer to video buffer copy (EfiBltVideoToVideo)\n");
              for (iter = 0; iter < (sizeof(blocksize) / sizeof(blocksize[0])); iter++)
              {
                  UINT32 hori = blocksize[iter];
                  
                  // Start Time
                  yPos = 0;
                  uStartTime = GetTimerCountms();
                  for (loopv = 0; loopv < iterationArray[iter]; loopv++)
                  {
                      if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol, NULL,
                                                                      EfiBltVideoToVideo,
                                                                      0, 0,
                                                                      0, yPos,
                                                                      hori,
                                                                      verti,
                                                                      0)))
                      {
                          break;
                      }

                      // For non-inplace cases, keep moving the YPosition
                      if (!inplace)
                      {
                          yPos++;
                          if (yPos >= pModeInfo->VerticalResolution)
                          {
                              yPos = 0;
                          }
                      }
                  }

                  if (EFI_SUCCESS == eStatus)
                  {
                      // End time
                      uEndTime = GetTimerCountms();
                      //Function execution time(ms)
                      uTotalFuncTime = (UINT32)(uEndTime - uStartTime);
                      if (uTotalFuncTime == 0)
                      {
                          AsciiPrint("Total time taken for BltVideoToVideo(%d pixels): 0ms\n", blocksize[iter]);
                      }
                      else
                      {
                          perfno = (blocksize[iter] * iterationArray[iter] * blockLength * 1000) / uTotalFuncTime;

                          DisplayBltPrintResults("BltVideoToVideo", perfno, uTotalFuncTime, blocksize[iter]);
                      }
                  }
                  else
                  {
                      AsciiPrint("DisplayBltOperationTest: Blt(EfiBltVideoToVideo) %d pixels failed. \n", blocksize[iter]);
                  }
              }
          }
      }
  }

  return eStatus; 
}


/* DisplayBltOperationTest()
 */
static TestCaseInfo DisplayBltOperationDescription = 
{
    "Blt Operation",
    "Blt functional test that verifies blt modes, Fill, BufferToVideo, VideoToVideo and VideoToBuffer."    
};

static EFI_STATUS DisplayBltOperationTest(void)
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  EFI_GUID                       sGfxOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  EFI_GRAPHICS_OUTPUT_PROTOCOL  *pGfxProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&sGfxOutputGUID, 
                                                     NULL, 
                                                     (VOID **)&pGfxProtocol)))                     
  {
    AsciiPrint ("DisplayBltOperationTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION   *pModeInfo;
    UINTN                                   nModeInfoSize;
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           bgPixel;
    UINTN                                   centerX;
    UINTN                                   centerY;
    UINT32                                  mode = 0;
    
    if (EFI_SUCCESS != (eStatus = pGfxProtocol->SetMode(pGfxProtocol, mode)))
    {
      AsciiPrint ("DisplayBltOperationTest: SetMode() failed.\n");
      return eStatus;
    }
    AsciiPrint ("DisplayBltOperationTest: Set mode - %d\n", mode);
    if (EFI_SUCCESS != (eStatus = pGfxProtocol->QueryMode(pGfxProtocol, 0, &nModeInfoSize, &pModeInfo)))
    {
      AsciiPrint ("DisplayBltOperationTest: QueryMode() failed.\n");
      return eStatus;
    }
    AsciiPrint ("DisplayBltOperationTest: Query mode - %dx%d\n", pModeInfo->HorizontalResolution, pModeInfo->VerticalResolution);
    /* Fill background as Blue */
    bgPixel.Blue     = BACKGROUND_B;
    bgPixel.Green    = BACKGROUND_G;
    bgPixel.Red      = BACKGROUND_R;
    bgPixel.Reserved = BACKGROUND_A;
    
    AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltVideoFill)\n");
    if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol, 
                                                    (EFI_GRAPHICS_OUTPUT_BLT_PIXEL*)&bgPixel,
                                                    EfiBltVideoFill,
                                                    0, 0,
                                                    0, 0, 
                                                    pModeInfo->HorizontalResolution,
                                                    pModeInfo->VerticalResolution,
                                                    0)))
    {
      AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltVideoFill) failed.\n");
      return eStatus;
    }
    gBS->Stall(DEFAULT_LONG_WAIT);
    /* Copy image to center */
    centerX = (pModeInfo->HorizontalResolution>>1) - (BITMAP_IMAGE_WIDTH>>1);
    centerY = (pModeInfo->VerticalResolution>>1) - (BITMAP_IMAGE_HEIGHT>>1);
    AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltBufferToVideo)\n");
    if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol, 
                                                    (EFI_GRAPHICS_OUTPUT_BLT_PIXEL*)pBitmapImage,
                                                    EfiBltBufferToVideo,
                                                    0, 0,
                                                    centerX, centerY,
                                                    BITMAP_IMAGE_WIDTH,
                                                    BITMAP_IMAGE_HEIGHT,
                                                    0)))
    {
      AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltBufferToVideo) failed.\n");
      return eStatus;
    }
    gBS->Stall(DEFAULT_LONG_WAIT);
    /* Copy image to top left */
    AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltVideoToVideo)\n");
    if (EFI_SUCCESS != (eStatus = pGfxProtocol->Blt(pGfxProtocol, 
                                                    NULL,
                                                    EfiBltVideoToVideo,
                                                    centerX, centerY,
                                                    0, 0,                      
                                                    BITMAP_IMAGE_WIDTH,
                                                    BITMAP_IMAGE_HEIGHT,
                                                    0)))
    {
      AsciiPrint ("DisplayBltOperationTest: Blt(EfiBltVideoToVideo) failed.\n");
      return eStatus;
    }
    gBS->Stall(DEFAULT_LONG_WAIT);
  }
  return eStatus; 
}


/* DisplayPanelPowerControlTest()
 */
static TestCaseInfo DisplayPanelPowerControlDescription = 
{
    "Power Control",
    "Power control test for the PwrCtrl Protocol, verifies the ability to turn a display on and off."    
};

static EFI_STATUS DisplayPanelPowerControlTest(void)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_QCOM_DISPLAY_PWR_CTRL_PROTOCOL  *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gQcomDisplayPwrCtrlProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayPanelPowerControlTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    UINT32                         cntr         = 0;
    EFI_DISPLAY_TYPE               eDisplayType = EFI_DISPLAY_TYPE_INTERNAL_ALL;
    EFI_DISPLAY_POWER_CTRL_STATE   ePowerState  = EFI_DISPLAY_POWER_STATE_OFF;    

    for (cntr = 0; cntr < 2; cntr++)
    {
      AsciiPrint ("DisplayPanelPowerControlTest: Display panel power off...\n");
      /* Turn off the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_OFF;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerControlTest: DisplayPanelPowerControl() failed.\n");
        return eStatus;
      } 
      gBS->Stall(DEFAULT_LONG_WAIT);
    
      /* Dump Clock Status */
      DisplayDumpClocks();
    
      AsciiPrint ("DisplayPanelPowerControlTest: Display panel power on...\n");
      /* Turn on the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_ON;    
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerControlTest: DisplayPanelPowerControl() failed.\n");
        return eStatus;
      }
      gBS->Stall(DEFAULT_LONG_WAIT);
    
      /* Dump Clock Status */
      DisplayDumpClocks();
    }
  }
  return eStatus;
}


/* DisplayBacklightBrightnessLevelControlTest()
 */
static TestCaseInfo DisplayBacklightBrightnessLevelControlDescription = 
{
    "Brightness Test",
    "Test that sweeps the entire display brightness range (in percentage)."
};

static EFI_STATUS DisplayBacklightBrightnessLevelControlTest(void)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_QCOM_DISPLAY_PWR_CTRL_PROTOCOL  *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gQcomDisplayPwrCtrlProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayBacklightBrightnessLevelControlTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    UINT32            uBackLightLevel = 0;
    EFI_DISPLAY_TYPE  eDisplayType    = EFI_DISPLAY_TYPE_PRIMARY;
    
    AsciiPrint ("DisplayBacklightBrightnessLevelControlTest: Decrease the display backlight...\n");
    /* Decrease the backlight gradually */ 
    for (uBackLightLevel = 100; uBackLightLevel > 0; uBackLightLevel--)
    {
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayBacklightBrightnessLevelControl(eDisplayType, uBackLightLevel)))
      {
        AsciiPrint ("DisplayBacklightBrightnessLevelControlTest: DisplayBacklightBrightnessLevelControl() failed.\n");
        return eStatus;
      }   
      gBS->Stall(DEFAULT_WAIT); 
    }
    AsciiPrint ("DisplayBacklightBrightnessLevelControlTest: Increase the display backlight...\n");
    /* Increase the backlight gradually */ 
    for (uBackLightLevel = 0; uBackLightLevel <= 100; uBackLightLevel++)
    {
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayBacklightBrightnessLevelControl(eDisplayType, uBackLightLevel)))
      {
        AsciiPrint ("DisplayBacklightBrightnessLevelControlTest: DisplayBacklightBrightnessLevelControl() failed.\n");
        return eStatus;
      }
      gBS->Stall(DEFAULT_WAIT);
    }         
  }
  return eStatus;
}

/* DisplayBacklightBrightnessLevelStatusTest()
 */
static TestCaseInfo DisplayBacklightBrightnessLevelStatusDescription = 
{
    "Brightness Status",
    "Test that ramps brightness and reports the current level."    
};

static EFI_STATUS DisplayBacklightBrightnessLevelStatusTest(void)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_QCOM_DISPLAY_PWR_CTRL_PROTOCOL  *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gQcomDisplayPwrCtrlProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayBacklightBrightnessLevelStatusTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    UINT32            uRetBackLightLevel  = 0;
    UINT32            uBackLightLevel     = 0;
    EFI_DISPLAY_TYPE  eDisplayType        = EFI_DISPLAY_TYPE_PRIMARY;
    
    AsciiPrint ("DisplayBacklightBrightnessLevelStatusTest: Decrease the display backlight...\n");
    /* Decrease the backlight gradually */ 
    for (uBackLightLevel = 0; uBackLightLevel <= 100; uBackLightLevel++)
    {
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayBacklightBrightnessLevelControl(eDisplayType, uBackLightLevel)))
      {
        AsciiPrint ("DisplayBacklightBrightnessLevelStatusTest: DisplayBacklightBrightnessLevelControl() failed.\n");
        return eStatus;
      }
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayBacklightBrightnessLevelStatus(eDisplayType, &uRetBackLightLevel)))
      {
        AsciiPrint ("DisplayBacklightBrightnessLevelStatusTest: DisplayBackLightBrightnessLevelStatus() failed.\n");
        return eStatus;
      }
      AsciiPrint ("DisplayBacklightBrightnessLevelStatusTest: Backlight level - %d\n", uRetBackLightLevel);
      gBS->Stall(DEFAULT_WAIT); 
    }
  }
  return eStatus;
}


/* DisplayPanelPowerStatusTest()
 */
static TestCaseInfo DisplayPanelPowerStatusDescription = 
{
    "Power Status Test",
    "Test that verifies low power mode (LPM) by checking display clock status."
};

static EFI_STATUS DisplayPanelPowerStatusTest(void)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_QCOM_DISPLAY_PWR_CTRL_PROTOCOL  *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gQcomDisplayPwrCtrlProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayPanelPowerStatusTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    UINT32                         cntr            = 0;
    EFI_DISPLAY_POWER_CTRL_STATE   uPanelPwrState  = (EFI_DISPLAY_POWER_CTRL_STATE)0;
    EFI_DISPLAY_TYPE               eDisplayType    = EFI_DISPLAY_TYPE_INTERNAL_ALL;
    EFI_DISPLAY_POWER_CTRL_STATE   ePowerState     = EFI_DISPLAY_POWER_STATE_OFF;    
    
    for (cntr = 0; cntr < 3; cntr++)
    {
      /* Turn off the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_OFF;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStatusTest: DisplayPanelPowerControl() failed.\n");
        return eStatus;
      } 
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerStatus(eDisplayType, &uPanelPwrState)))
      {
        AsciiPrint ("DisplayPanelPowerStatusTest: DisplayPanelPowerStatus() failed.\n");
        return eStatus;
      } 
      AsciiPrint ("DisplayPanelPowerStatusTest: Display panel power state - %d\n", uPanelPwrState ? 1 : 0);
      gBS->Stall(DEFAULT_LONG_WAIT);

      /* Dump Clock Status */
      DisplayDumpClocks();    
    
      /* Turn on the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_ON;    
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStatusTest: DisplayPanelPowerControl() failed.\n");
        return eStatus;
      }
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerStatus(eDisplayType, &uPanelPwrState)))
      {
        AsciiPrint ("DisplayPanelPowerStatusTest: DisplayPanelPowerStatus() failed.\n");
        return eStatus;
      } 
      AsciiPrint ("DisplayPanelPowerStatusTest: Display panel power state - %d\n", uPanelPwrState ? 1 : 0);
      gBS->Stall(DEFAULT_LONG_WAIT);
    
      /* Dump Clock Status */
      DisplayDumpClocks();    
    }
  }
  return eStatus;
}


/* DisplayPanelPowerStateTest()
 */
static TestCaseInfo DisplayPanelPowerStateDescription = 
{
    "Power State Test",
    "Verifies the DisplayPowerState protocol by turning the display on/off and adjusting the brightness."
};

static EFI_STATUS DisplayPanelPowerStateTest(void)
{
  EFI_STATUS                           eStatus = EFI_SUCCESS;
  EFI_DISPLAY_POWER_PROTOCOL          *pDisplayPwrCtrlProtocol;
  
  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&gEfiDisplayPowerStateProtocolGuid, 
                                                     NULL, 
                                                     (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayPanelPowerStateTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
    UINT32                         cntr = 0;
    EFI_DISPLAY_POWER_STATE        ePowerState  = EfiDisplayPowerStateOff;    
    
    for (cntr = 0; cntr < 2; cntr++)
    {
      AsciiPrint ("DisplayPanelPowerStateTest: Display panel power off...\n");
      /* Turn off the display */
      ePowerState  = EfiDisplayPowerStateOff;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->SetDisplayPowerState(NULL, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStateTest: SetDisplayPowerState() failed.\n");
        return eStatus;
      } 
      /* Retrieve the power status */ 
      ePowerState = EfiDisplayPowerStateUnknown;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->GetDisplayPowerState(NULL, &ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStateTest: GetDisplayPowerState() failed.\n");
        return eStatus;
      } 
      AsciiPrint ("DisplayPanelPowerStateTest: Display panel power status : %d\n", ePowerState);
      gBS->Stall(DEFAULT_LONG_WAIT);
      AsciiPrint ("DisplayPanelPowerStateTest: Display panel power on...\n");
      /* Turn on the display and backlight */
      ePowerState  = EfiDisplayPowerStateMaximum;   
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->SetDisplayPowerState(NULL, ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStateTest: SetDisplayPowerState() failed.\n");
        return eStatus;
      }
      /* Retrieve the power status */ 
      ePowerState = EfiDisplayPowerStateUnknown;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->GetDisplayPowerState(NULL, &ePowerState)))
      {
        AsciiPrint ("DisplayPanelPowerStateTest: GetDisplayPowerState() failed.\n");
        return eStatus;
      } 
      AsciiPrint ("DisplayPanelPowerStateTest: Display panel power status : %d\n", ePowerState);
      gBS->Stall(DEFAULT_LONG_WAIT);
    }
  }
  return eStatus;
}


/* DisplayPowerEventTest()
 */
static TestCaseInfo DisplayPowerEventDescription = 
{
    "Power Event Test",
    "Test that verifies the active/idle events used by clients to turn the display on and off."
};

static EFI_STATUS DisplayPowerEventTest(void)
{
  EFI_STATUS    eStatus            = EFI_SUCCESS;
  EFI_GUID      UIActiveEventGuid  = EFI_UI_ACTIVE_EVENT_GUID;
  EFI_GUID      UIIdleEventGuid    = EFI_UI_IDLE_EVENT_GUID;
  EFI_EVENT     UIActiveEvent      = NULL;
  EFI_EVENT     UIIdleEvent        = NULL;


  //Create UI_Acitve/UI_Idle events
  if (EFI_SUCCESS != (eStatus = gBS->CreateEventEx(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, DummyEventHandle, NULL, &UIActiveEventGuid, &UIActiveEvent)))
  {
    AsciiPrint("DisplayPowerEventTest: Failed to create event UI_Active\n");
  }
  else if (EFI_SUCCESS != (eStatus = gBS->CreateEventEx(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, DummyEventHandle, NULL, &UIIdleEventGuid, &UIIdleEvent)))
  {
    AsciiPrint("DisplayPowerEventTest: Failed to create event UI_Idle\n");
  }
  else
  {
    UINT32                         cntr = 0;

    //Loop to turn of and on display multiply times.
    for (cntr = 0; cntr < 2; cntr++)
    {
      /* Turn off the display */
      AsciiPrint("DisplayPowerEventTest: Display panel power off...\n");
      if (EFI_SUCCESS != (eStatus = gBS->SignalEvent(UIIdleEvent)))
      {
        AsciiPrint("DisplayPowerEventTest: failed signal event UI_Idle.\n");
        break;
      }
      gBS->Stall(DEFAULT_LONG_WAIT);

      /* Turn on the display */
      AsciiPrint("DisplayPowerEventTest: Display panel power on...\n");
      if (EFI_SUCCESS != (eStatus = gBS->SignalEvent(UIActiveEvent)))
      {
        AsciiPrint("DisplayPowerEventTest: failed signal event UI_Active.\n");
        break;
      }
      gBS->Stall(DEFAULT_LONG_WAIT);
    }
  }

  //Close Event handles
  if (NULL != UIActiveEvent)
  {
    if (EFI_SUCCESS != (eStatus = gBS->CloseEvent(UIActiveEvent)))
    {
      AsciiPrint("DisplayPowerEventTest: Failed to Close event UI_Active\n");
    }
  }
  if (NULL != UIIdleEvent)
  {
    if (EFI_SUCCESS != (eStatus = gBS->CloseEvent(UIIdleEvent)))
    {
      AsciiPrint("DisplayPowerEventTest: Failed to Close event UI_Idle\n");
    }
  }

  return eStatus;
}


/* DisplaySetModeTest()
 */
static TestCaseInfo DisplaySetModeDescription = 
{
    "Modeset (Virtual modes) Test",
    "Test that verifies different virtual modes exposed by the graphics output protocol (GOP)."
};

static EFI_STATUS DisplaySetModeTest()
{
  EFI_STATUS                     eStatus        = EFI_SUCCESS;
  EFI_GUID                       sGfxOutputGUID = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
  EFI_GRAPHICS_OUTPUT_PROTOCOL  *pGfxProtocol;

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol (&sGfxOutputGUID, 
                                                     NULL, 
                                                     (VOID **)&pGfxProtocol)))                 
  {
    AsciiPrint ("DisplaySetModeTest: LocateProtocol() failed.\n");
    return eStatus;
  }
  else
  {
     uint32 uLastMode = 0;
     uint32 uModeIndex;

     for (uModeIndex = 0; uModeIndex < pGfxProtocol->Mode->MaxMode; uModeIndex++)
     {
       if (EFI_SUCCESS == (eStatus = pGfxProtocol->SetMode(pGfxProtocol, (UINT32) uModeIndex)))
       {
         AsciiPrint("DisplaySetModeTest : Mode#%d succesfully changed (Current Mode %dx%d)\n",
                (UINT32)uModeIndex,
                pGfxProtocol->Mode->Info->HorizontalResolution,
                pGfxProtocol->Mode->Info->VerticalResolution);

         uLastMode = uModeIndex;
       }
       else
       {
         AsciiPrint("DisplaySetModeTest : Mode#%d failed! (status:%d)\n",
                (UINT32)uModeIndex,
                eStatus);
       }
       gBS->Stall(DEFAULT_LONG_WAIT);       
     }

     // Reset back to mode 0 at the end
     if (0 != uLastMode)
     {
        pGfxProtocol->SetMode(pGfxProtocol, 0);
     }
  }

  return eStatus;
}


/* DisplaySetModeExtTest()
 */
static TestCaseInfo DisplaySetModeExtDescription = 
{
    "External Display Test",
    "Test that verifies external display functionality through the Display Utils protocol."
};

static EFI_STATUS DisplaySetModeExtTest(void)
{
  EFI_STATUS                        eStatus            = EFI_SUCCESS;
  EFI_GUID                          sDisplayUtilGUID   = EFI_DISPLAYUTILS_PROTOCOL_GUID;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL  *pDisplayUtilProtocol;
  UINT32                            DisplayId          = 2; /* external display */
  UINT32                            ModeNUm            = 0;
  UINT32                            Flags              = 0;

  AsciiPrint("\nNote: For this test a Type-C to DP cable must be plugged in to a monitor.\n");
  AsciiPrint("      Plug polarity is not supported, so please try both cable directions.\n");
  AsciiPrint("      This test will fail if a monitor cannot be detected.\n\n");

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sDisplayUtilGUID,
                                                     NULL,
                                                     (VOID **)&pDisplayUtilProtocol)))
  {
     AsciiPrint("DisplaySetMode: LocateProtocol() failed.\n");
  }
  else 
  {
      if (EFI_SUCCESS == (eStatus = pDisplayUtilProtocol->DisplayUtilsSetMode(DisplayId, ModeNUm, Flags)))
      {
          AsciiPrint("DisplaySetModeExtTest: Success to set external display mode\n");
      }
      else 
      {
          AsciiPrint("DisplaySetModeExtTest: Failed to set external display mode\n");
      }

  }

  return eStatus;
}


/* DisplayCalibratePLLTest()
 */
static TestCaseInfo DisplayCalibratePLLDescription = 
{
    "Display PLL Calibration Test",
    "Test that verifies dynamic refresh calibration code generation."
};

static EFI_STATUS DisplayCalibratePLLTest(void)
{
  EFI_STATUS                        eStatus               = EFI_SUCCESS;
  EFI_GUID                          sDisplayUtilGUID      = EFI_DISPLAYUTILS_PROTOCOL_GUID;
  UINT32                            FreqList[]            = {0x350000, 0x360000, 0x370000, 0x380000, 0x390000, 0x3A0000, 0x3B0000, 0x3C0000};
  UINT32                            FreqNum               = sizeof(FreqList)/sizeof(FreqList[0]);
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL  *pDisplayUtilProtocol;
  UINT32                            i;
  UINT32                            j;
  UINT32                            k;
  UINT32                            PLLCodesNumEachFreq;
  UINT32                            CalTime;
  UINT32                            PLLCodesSize[DYNAMIC_REFRESH_MAX_DSI_NUM];
  UINT32                            PllCodes[DYNAMIC_REFRESH_MAX_PLL_CODES_SIZE];

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sDisplayUtilGUID,
                                               NULL,
                                               (VOID **)&pDisplayUtilProtocol)))
  {
     AsciiPrint("DisplayCalibratePLL: LocateProtocol() failed.\n");
     eStatus = EFI_NOT_FOUND;
  }
  else if (DYNAMIC_REFRESH_MAX_FREQ < FreqNum)
  {
     AsciiPrint("DisplayCalibratePLL: Too many dynamic refresh frequencies\n");
     eStatus = EFI_INVALID_PARAMETER;
  }
  else if (0 == FreqNum)
  {
     AsciiPrint("DisplayCalibratePLL: dynamic refresh frequencies number is 0\n");
     eStatus = EFI_SUCCESS;
  }
  else 
  {
    /* Prepare the frequencies */
    if (EFI_SUCCESS != (eStatus = pDisplayUtilProtocol->DisplayUtilsSetProperty(EFI_DISPLAY_UTILS_DYNAMIC_REFRESH,
                                                                    FreqList, FreqNum)))
    {
        AsciiPrint("DisplayCalibratePLL: Failed to set dynamic refresh frequencies\n");
    }
    else
    {
      uint32 t0;
      uint32 t1;
      uint32 index = 0;
      
      ZeroMem(PllCodes, sizeof(PllCodes));
      ZeroMem(PLLCodesSize, sizeof(PLLCodesSize));

      t0 = GetTimerCountus();
      /* Do the real calibration here */
      if (EFI_SUCCESS != (eStatus = pDisplayUtilProtocol->DisplayUtilsGetProperty(EFI_DISPLAY_UTILS_DYNAMIC_REFRESH,
                                                                    PllCodes, PLLCodesSize)))
      {
        AsciiPrint("DisplayCalibratePLL: Failed to calibrate PLL\n");
      }
      else
      {
        t1 = GetTimerCountus();
        
        PLLCodesNumEachFreq = PLLCodesSize[0] / sizeof(uint32) / FreqNum;

        for (k = 0; k < sizeof(PLLCodesSize)/sizeof(PLLCodesSize[0]); k++)
        {
          if (0 != PLLCodesSize[k])
          {
            AsciiPrint("DeviceId=0x%x\n", k);
            /* Show the pll codes result */
            for (i = 0; i < FreqNum; i++)
            {
              AsciiPrint("Frequency=0x%x\n", FreqList[i]);
              for (j = 0; j < PLLCodesNumEachFreq; j++)
              {
                AsciiPrint("PllCodes[%d]=0x%x\n", j, PllCodes[index+PLLCodesNumEachFreq*i+j]);
              }
              AsciiPrint("=====================\n");
            }
            index += PLLCodesSize[k];
          }
        }

        
        CalTime = t1 - t0;
        AsciiPrint("Total Calibration Time:%d us, Calibration Time Per Frequency=%d us\n", CalTime, CalTime/FreqNum);
      }
      
    }
  }

  return eStatus;
}


/* DisplayMultiDisplayPowerTest()
 */
static TestCaseInfo DisplayMultiDisplayPowerDescription = 
{
    "Display Multi-Display Power Test",
    "Test multi-display power control."
};

static EFI_STATUS DisplayMultiDisplayPowerTest(void)
{
  EFI_STATUS                           eStatus                                = EFI_SUCCESS;
  EFI_GUID                             DisplayInitEventGuid                   = EFI_DISPLAY_INIT_EVENT_GUID;
  EFI_EVENT                            DisplayInitEvent                       = NULL;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL     *pDisplayUtilsProtocol                  = NULL;
  EFI_QCOM_DISPLAY_PWR_CTRL_PROTOCOL  *pDisplayPwrCtrlProtocol                = NULL;
  EFI_DISABLED_DISPLAYS_TYPE           sDisabledDisplayList;

  ZeroMem(&sDisabledDisplayList, sizeof(sDisabledDisplayList));

  eStatus = gBS->LocateProtocol(&gQcomDisplayUtilsProtocolGuid, NULL, (void**)&pDisplayUtilsProtocol);

  if ((EFI_SUCCESS !=  eStatus) ||
      (NULL        ==  pDisplayUtilsProtocol))
  {
    DEBUG((EFI_D_WARN, "DisplayMultiDisplayPowerTest: Locate display utils protocol failed with status: %r\n", eStatus));
  }
  else if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&gQcomDisplayPwrCtrlProtocolGuid, 
                                                          NULL, 
                                                          (VOID **)&pDisplayPwrCtrlProtocol)))                     
  {
    AsciiPrint ("DisplayMultiDisplayPowerTest: Locate display power control protocol failed.\n");
  }
  else if (EFI_SUCCESS != (eStatus = gBS->CreateEventEx(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, HallMonitorTestCallBack, (VOID *)(&sDisabledDisplayList), &DisplayInitEventGuid, &DisplayInitEvent)))
  {
    AsciiPrint("DisplayMultiDisplayPowerTest: Failed to create event Display_Init\n");
  }
  else
  {
    UINT32                          uCtrlIndex    = 0;
    EFI_DISPLAY_TYPE                eDisplayType  = EFI_DISPLAY_TYPE_INTERNAL_ALL;
    EFI_DISPLAY_POWER_CTRL_STATE    ePowerState   = EFI_DISPLAY_POWER_STATE_OFF;

    /* Loop to test multi-display power control */
    for (uCtrlIndex = 0; uCtrlIndex < 4; uCtrlIndex++)
    {
      AsciiPrint ("DisplayMultiDisplayPowerTest: Display panel power off...\n");

      /* Turn off the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_OFF;
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayMultiDisplayPowerTest: DisplayPanelPowerControl() failed with status(%d).\n", eStatus);
      } 
      gBS->Stall(DEFAULT_LONG_WAIT);

      AsciiPrint ("DisplayMultiDisplayPowerTest: Display panel power on...\n");

      /* Turn on the display */
      ePowerState  = EFI_DISPLAY_POWER_STATE_ON;    
      if (EFI_SUCCESS != (eStatus = pDisplayPwrCtrlProtocol->DisplayPanelPowerControl(eDisplayType, ePowerState)))
      {
        AsciiPrint ("DisplayMultiDisplayPowerTest: DisplayPanelPowerControl() failed with status(%d).\n", eStatus);
      }
      gBS->Stall(DEFAULT_LONG_WAIT);
    }
  }

  /* Close event handles */
  if (NULL != DisplayInitEvent)
  {
    if (EFI_SUCCESS != (eStatus = gBS->CloseEvent(DisplayInitEvent)))
    {
      AsciiPrint("DisplayMultiDisplayPowerTest: Failed to close event Display_Init\n");
    }
  }

  return eStatus;
}


/* DisplayOrientationTest()
 */
static TestCaseInfo DisplayOrientationDescription = 
{
    "Display Orientation Test",
    "Verify that the orientation of the picture on the screen can be chaned."
};

static EFI_STATUS DisplayOrientationTest()
{
  EFI_STATUS                       eStatus            = EFI_SUCCESS;
  EFI_GUID                         sDisplayUtilGUID   = EFI_DISPLAYUTILS_PROTOCOL_GUID;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL *pDisplayUtilProtocol;

  if (EFI_SUCCESS != (eStatus = gBS->LocateProtocol(&sDisplayUtilGUID,
                                                      NULL,
                                                      (VOID **)&pDisplayUtilProtocol)))
   {
      AsciiPrint("DisplayOrientationTest: LocateProtocol() failed.\n");
   }
   else 
   {
       EFI_DISPLAY_UTILS_DISPLAY_ORIENTATION_PARAMS sOrientation;

       sOrientation.bInverted = TRUE;

       if (EFI_SUCCESS == (eStatus = pDisplayUtilProtocol->DisplayUtilsSetProperty(EFI_DISPLAY_UTILS_DISPLAY_ORIENTATION,
                                                                                    &sOrientation,
                                                                                    sizeof(sOrientation))))
       {
          AsciiPrint("DisplayOrientationTest : Successfully inverted display!\n");
       }
       else
       {
          AsciiPrint("DisplayOrientationTest : Failed!\n");
       }

       gBS->Stall(DEFAULT_LONG_WAIT);

       // Restore the display
       sOrientation.bInverted = FALSE;

       if (EFI_SUCCESS == (eStatus = pDisplayUtilProtocol->DisplayUtilsSetProperty(EFI_DISPLAY_UTILS_DISPLAY_ORIENTATION,
                                                                                    &sOrientation,
                                                                                    sizeof(sOrientation))))
       {
          AsciiPrint("DisplayOrientationTest : Successfully restored display!\n");
       }
       else
       {
          AsciiPrint("DisplayOrientationTest : Failed!\n");
       }

   }
   
  return eStatus;
}


/*
 *Verify whether the register value is equal to golden setting.
 */
EFI_STATUS DisplayVerifyRegTest(void)
{
  EFI_STATUS                        eStatus               = EFI_SUCCESS;
  CHAR8                            *pGoldenSettingBuf     = NULL;
  UINT32                            uGoldenSetiingBufSize = 0;

  if (EFI_SUCCESS != (eStatus = DisplayGetConsoleInput(&pGoldenSettingBuf, &uGoldenSetiingBufSize)))
  {
    AsciiPrint("DisplayVerifyRegTest: DisplayGetConsoleInput() failed.\n");
    eStatus = EFI_NOT_FOUND;
  }
  else if ((NULL == pGoldenSettingBuf) ||
           (0 == uGoldenSetiingBufSize) )
  {
    AsciiPrint("DisplayVerifyRegTest: Golden setting invalid.\n");
    eStatus = EFI_NOT_FOUND;
  }
  else if (EFI_SUCCESS != (eStatus = VerifyRegisterSettings(pGoldenSettingBuf, uGoldenSetiingBufSize)))
  {
    AsciiPrint("DisplayVerifyRegTest: VerifyRegisterSettings() failed.\n");
  }

  /* Always try free the allocted buffer in the end */
  if (NULL != pGoldenSettingBuf)
  {
    FreePool(pGoldenSettingBuf);
  }
  
  return eStatus;
}

/*=========================================================================
  Test case list
 ==========================================================================*/

/* List of display test cases 
 */
TestCaseEntry TestCaseList[] = 
{
  {&DisplayInfoDescription,                            &DisplayInfoTest},
  {&DisplayBltPerformanceDescription,                  &DisplayBltPerformanceTest},
  {&DisplayBltOperationDescription,                    &DisplayBltOperationTest},
  {&DisplayPanelPowerControlDescription,               &DisplayPanelPowerControlTest},
  {&DisplayPanelPowerStateDescription,                 &DisplayPanelPowerStateTest},
  {&DisplayPanelPowerStatusDescription,                &DisplayPanelPowerStatusTest},
  {&DisplayMultiDisplayPowerDescription,               &DisplayMultiDisplayPowerTest},
  {&DisplayBacklightBrightnessLevelControlDescription, &DisplayBacklightBrightnessLevelControlTest},  
  {&DisplayBacklightBrightnessLevelStatusDescription,  &DisplayBacklightBrightnessLevelStatusTest},  
  {&DisplayPowerEventDescription,                      &DisplayPowerEventTest},
  {&DisplaySetModeExtDescription,                      &DisplaySetModeExtTest},
  {&DisplayCalibratePLLDescription,                    &DisplayCalibratePLLTest},
  {&DisplaySetModeDescription,                         &DisplaySetModeTest},
  {&DisplayOrientationDescription,                     &DisplayOrientationTest},
};

/* Total number of test cases */
#define NUM_TEST_CASES        (sizeof(TestCaseList)/sizeof(TestCaseEntry))

/* BVT Test Case Help  */
void DisplayBVTHelp()
{
  UINTN uCount;

  AsciiPrint ("  -%-16a : %a\n\n\n", "bvt", "Execute the display BVT test or a specific test number");  
  AsciiPrint ("BVT Test Case List:\n");
    
  for (uCount=0;uCount<NUM_TEST_CASES;uCount++)
  {
    AsciiPrint(" #%d: %a\n", uCount+1, TestCaseList[uCount].pTestInfo->sTestName);
    AsciiPrint("      %a\n\n", TestCaseList[uCount].pTestInfo->sTestDescription);
  }
  AsciiPrint("\n");
}

/* BVT Executor */
UINTN DisplayBVTParser(CHAR8* pCommandLine, CHAR8* pArgs)
{
  UINTN uResult = 1;
  
  if (0 == AsciiStrCmp("bvt", pCommandLine))
  {
    EFI_STATUS eStatus     = EFI_SUCCESS;
    UINT32     uTestStart  = 0;    
    UINT32     uTestEnd    = NUM_TEST_CASES;
    UINT32     uTestCount  = 0;
    UINT32     uTestPassed = 0;
    UINT32     uTestCase   = AsciiStrDecimalToUintn(pArgs);
    UINT32     uCount;    
    
    if (EFI_SUCCESS != DisplayGenerateBitmap())
    {
      AsciiPrint("Unable to generate bitmap, cannot continue!\n\n");
    }
    else
    {
      if ((uTestCase > 0) &&
          (uTestCase <= NUM_TEST_CASES))
      {
        uTestStart = uTestCase-1;
        uTestEnd   = uTestStart+1;
      }
    
      // Loop all tests
      for (uCount=uTestStart;uCount<uTestEnd;uCount++)
      {
        AsciiPrint("======] Test Case Start   : %a\n\n", TestCaseList[uCount].pTestInfo->sTestName);
    
        // Increment the number of tests run
        uTestCount++;
        if (EFI_SUCCESS == (eStatus = TestCaseList[uCount].pTestFn()))
        {
          // Increment the test pass count
          uTestPassed++;
        }
    
        AsciiPrint("\n======] Test Case Complete: %a\n", (EFI_SUCCESS==eStatus)?"Passed":"Failed");
      }
    
      if (uTestCount)
      {
        AsciiPrint("\n\nDisplay BVT Result: %d tests run (%d%% pass rate)\n", uTestCount, (100*uTestPassed)/uTestCount);
      }
    
      // Free the image buffer
      if (NULL != pBitmapImage)
      {
        gBS->FreePool (pBitmapImage);    
      }
    }
  }
  else
  {
    uResult = 0;
  }

  return uResult;
}


/*=========================================================================
  Local helper functions
 ==========================================================================*/

/* DisplayDumpClocks 
 * - Helper to dump all clocks
 * 
 */
static void DisplayDumpClocks()
{
  uint32 i;
  
  AsciiPrint("%-30a %4a %10a\n", "Clock Name", "State", "Frequency");
  for (i=0;i<NUM_CLOCK_ENTRIES;i++)
  {
     DisplayClockStatus(ClockList[i].sClockName);
  }
}

/* DisplayClockStatus 
 * - Display the status of a clock 
 * 
 */
static void DisplayClockStatus(CHAR8 *pClockName)
{
  EFI_CLOCK_PROTOCOL  *mClockProtocol;
  UINTN                uClockId;
  
  // Grab the clock protocol
  if (NULL == pClockName)
  {
    AsciiPrint("ERROR: Cannot query invalid clock\n");
  }
  else if (EFI_SUCCESS != gBS->LocateProtocol(&gEfiClockProtocolGuid,
                                         NULL,
                                         (VOID **) &mClockProtocol))
  {
    AsciiPrint("ERROR: Failed to read clock %a\n", pClockName);
  }
  else if (EFI_SUCCESS != mClockProtocol->GetClockID(mClockProtocol,  pClockName, &uClockId))
  {
    AsciiPrint("ERROR: %a is not a valid clock\n", pClockName);
  }
  else 
  {
    BOOLEAN bClockOn = FALSE; 
    UINT32  uFreq    = 0;
    
      if (EFI_SUCCESS != mClockProtocol->IsClockOn(mClockProtocol, uClockId, &bClockOn))
    {
         AsciiPrint("ERROR: Failed to query clock status of %a\n", pClockName);    
    }
    
    if (EFI_SUCCESS != mClockProtocol->GetClockFreqHz(mClockProtocol, uClockId, &uFreq))
    {
         AsciiPrint("ERROR: Failed to query clock frequency of %a\n", pClockName);    
    }
    
    AsciiPrint("%-30a %3a    %dHz\n", pClockName, (bClockOn)?"ON":"OFF", (bClockOn)?uFreq:0);  
  }
}


/* Dummy Power Event handle function needed to create local events for UI_Active/UI_Idle*/
static VOID EFIAPI DummyEventHandle( IN EFI_EVENT  Event, IN VOID *Context)
{
  /* Dummy Power Event handle function, do nothing here*/
}


/** 
 Helper to print results in simplified units 
 **/
static void DisplayBltPrintResults(CHAR8 *testName, UINT64 byteProcessed, UINT32 totalTime, UINT32 blockSize)
{
    UINT64 throughput; 
    
    if (byteProcessed >= (10*1024))  
    { 
      throughput = byteProcessed / 1024;
      AsciiPrint("  %-20a:%8dKB/s (blocksize: %d, test duration: %dms)\n", testName, throughput, blockSize, totalTime);
    }
    else
    {
      AsciiPrint("  %-20a:%8dBytes/s (blocksize: %d, test duration: %dms)\n", testName, byteProcessed, blockSize, totalTime);
    }
}

/* 
 *Callback function to detect HALL status, to set the disabled display list for primary or secondary display.
 */
static VOID EFIAPI HallMonitorTestCallBack(IN EFI_EVENT  Event, IN VOID *Context)
{
  static  UINT32                    uTestNum                 = 0;
  EFI_DISABLED_DISPLAYS_TYPE       *pDisabledDisplayList     = (EFI_DISABLED_DISPLAYS_TYPE *)Context;
  EFI_QCOM_DISPLAY_UTILS_PROTOCOL  *pDisplayUtilsProtocol    = NULL;

  if (NULL == pDisabledDisplayList)
  {
    DEBUG((EFI_D_WARN, "HallMonitorTest: Supported display list is NULL\n"));
  }
  else if (EFI_SUCCESS !=  gBS->LocateProtocol(&gQcomDisplayUtilsProtocolGuid, NULL, (void**)&pDisplayUtilsProtocol) ||
          (NULL        ==  pDisplayUtilsProtocol))
  {
    DEBUG((EFI_D_WARN, "HallMonitorTest: Locate display utils protocol failed\n"));
  }
  else
  {
    /* Set disabled display list according to the uTestNum to test dual display control */
    switch (uTestNum)
    {
    case 0:
      /* Set both of primary and secondary display to the disabled display list */
      pDisabledDisplayList->aDisabledDisplays[0]  = EFI_DISPLAY_TYPE_PRIMARY;
      pDisabledDisplayList->aDisabledDisplays[1]  = EFI_DISPLAY_TYPE_SECONDARY;
      pDisabledDisplayList->uNumOfDisplays        = 2;
      break;

    case 1:
      /* Set secondary display to the disabled display list */
      pDisabledDisplayList->aDisabledDisplays[0]  = EFI_DISPLAY_TYPE_SECONDARY;
      pDisabledDisplayList->uNumOfDisplays        = 1;
      break;

    case 2:
      /* Set primary display to the disabled display list */
      pDisabledDisplayList->aDisabledDisplays[0]  = EFI_DISPLAY_TYPE_PRIMARY;
      pDisabledDisplayList->uNumOfDisplays        = 1;
      break;
  
    case 3:
    default:
      pDisabledDisplayList->uNumOfDisplays        = 0;
      break;
    }

    if (pDisplayUtilsProtocol->DisplayUtilsSetProperty(EFI_DISPLAY_UTILS_DISABLE_DISPLAY, pDisabledDisplayList, sizeof(EFI_DISABLED_DISPLAYS_TYPE)))
    {
      DEBUG((EFI_D_WARN, "HallMonitorTest: Failed to set the disabled display list.\n"));
    }
  }

  uTestNum++; 
}


/* 
 * Helper to process a line, this function is able to process line format like below:
 * case 1: 0xabcd1234: 12345678
 * case 2: ABCD1234  : 0x12345678
 * Both register address and value are considered as hex string
 */
EFI_STATUS ParseRegisterValuePair(CHAR8 *pLine, UINT32 uLineLength, UINT64 *pAddr, UINT32 *pRegVal)
{
  EFI_STATUS eStatus = EFI_SUCCESS;
  
  if ((NULL == pLine) || 
      (NULL == pAddr) || 
      (NULL == pRegVal))
  {
    eStatus = EFI_INVALID_PARAMETER;
  }
  else if (uLineLength > (GOLDEN_SETTING_MAX_LINE_SIZE - 1))
  {
    eStatus = EFI_INVALID_PARAMETER;
  }
  else
  {
    CHAR8 *pSavedPtr   = NULL;    
    UINT64 uRegAddress = 0;
    UINT64 uRegValue   = 0;
    UINT8  uPair;
    CHAR8  aLine[GOLDEN_SETTING_MAX_LINE_SIZE];
    CHAR8 *pToken      = NULL;
    UINT32 uErrCount   = 0;
    
    CopyMem(aLine, pLine, uLineLength);
    aLine[uLineLength] = '\0';

    pToken = strtok_r(aLine, ":", &pSavedPtr);

    for (uPair = 0; uPair < 2; uPair++)
    {
      if (NULL != pToken)
      {
        switch (uPair)
        {
          case 0:    
            uRegAddress = AsciiStrHexToUint64(pToken);
            break;
          case 1:
            uRegValue = AsciiStrHexToUint64(pToken);
            break;
        }
      }
      else
      {
        uErrCount++;
      }
      
      pToken = strtok_r(NULL, ":", &pSavedPtr);
    }

    if (uErrCount > 0)
    {
      eStatus = EFI_UNSUPPORTED;
    }
    else
    {
      *pAddr   = uRegAddress;
      *pRegVal = uRegValue;
    }
  } 

  return eStatus;
}

/* 
 * Helper to process register setting from buffer
 */
static EFI_STATUS VerifyRegisterSettings(CHAR8 *pBuf, UINT32 uBufSize)
{ 
  EFI_STATUS   eStatus          = EFI_SUCCESS;
  UINT32       uLineLength      = 0;
  INT32        uRemainingBytes  = uBufSize;
  UINT64       uAddr;
  UINT32       uRegVal;
  CHAR8       *pLineBegin       = pBuf;
  UINT32       uFailCount       = 0;
  UINT32       uTotalCount      = 0;
  
  while(uRemainingBytes > 0)
  {
    if (0 == (uLineLength = GetBytesInLine(pLineBegin,  uRemainingBytes)))
    {
      eStatus = EFI_UNSUPPORTED;  
      break;
    }
    else if (EFI_SUCCESS == ParseRegisterValuePair(pLineBegin, uLineLength, &uAddr, &uRegVal))
    {
      uTotalCount++;
      
      if (0 == uAddr)
      {
        uFailCount++;
        AsciiPrint("ERROR: Addr is 0, \t%a\n", pLineBegin);
      }
      else
      {
        UINT32 uReadVal = *(UINT32*)uAddr;

        if (uReadVal != uRegVal)
        {
          uFailCount++;
          AsciiPrint("WARNING: Addr: 0x%x, GoldenSeting: 0x%x, ReadVal: 0x%x\n", uAddr, uRegVal, uReadVal);
        }
      }
    }
    
    uRemainingBytes -= uLineLength;
    pLineBegin      += uLineLength;
  }

  if (uFailCount > 0)
  {
    eStatus = EFI_UNSUPPORTED;
    AsciiPrint("WARNING: %d/%d values did not match\n", uFailCount, uTotalCount);
  }
  else
  {
    AsciiPrint("SUCCESS: %d/%d values matched\n", uTotalCount, uTotalCount);
  }
  
  return eStatus;
}

