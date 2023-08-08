/*==========================================================================================================
 
  File: dp_link.c
 
  Source file for DP main link related functionality 
   
  Copyright (c) 2016-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================================================*/

/*---------------------------------------------------------------------------------------------------------------------
 * Include Files
 *-------------------------------------------------------------------------------------------------------------------*/
#include "dp_i.h"
#include "hal_dp_phy.h"


#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------------------------------------------
 * Defines
 *-------------------------------------------------------------------------------------------------------------------*/
#define EXTRA_PIXCLK_CYCLE_DELAY 5
#define MAX_LINK_TRAINING_LOOP   5
#define RATIO_SCALE              1.001


#ifndef MAX
#define MAX(a,b)                (a > b ? a : b)
#endif

#ifndef ABS
#define ABS(a)                  (a > 0 ? a : -a)
#endif

#define MAX_16BITS_VALUE        ((1 << 16) - 1)     /* 16 bits value */

/* DP Nvid value factor */
typedef enum
{
  DP_NVID_FACTOR_1_62G = 1,
  DP_NVID_FACTOR_2_70G = 1,
  DP_NVID_FACTOR_5_40G = 2,
  DP_NVID_FACTOR_8_10G = 3,
  DP_NVID_FACTOR_MAX,
  DP_NVID_FACTOR_32BIT = 0x7FFFFFFF
}DP_NvidFactorType;

/* Clock MND divider info */
typedef struct
{
  uint64    uSrcRate;           /* Input clock frequency    */
  uint64    uTargetRate;        /* Divided clock frequency  */
  uint32    uMVal;              /* Divider M value          */
  uint32    uNVal;              /* Divider N value          */
  uint32    u2DVal;             /* Divider 2 * D value      */
  uint32    uNotNMinusM;        /* Divider NOT(N - M) value */
  uint32    uNot2D;             /* Divider NOT(N) value     */
} DP_MNDType;

/* DP Link rate settings */
typedef struct {
  uint32 uLinkRateMBps;
  uint32 uInputClkMhz;
  uint32 uNvidFactor;
} DP_LinkRateSettings;

/*---------------------------------------------------------------------------------------------------------------------
 * Global Data Definitions
 *-------------------------------------------------------------------------------------------------------------------*/
DP_PixelFormat_Info       gsDPPixelFormatInfo[DP_PIXEL_FORMAT_MAX] = 
{
  /*uBitsPerPixel   uBitsPerComponent*/
  {  0,             0  },       /*DP_PIXEL_FORMAT_NONE          */
  { 18,             6  },       /*DP_PIXEL_FORMAT_RGB_666_18BPP */
  { 24,             8  },       /*DP_PIXEL_FORMAT_RGB_888_24BPP */
  { 30,            10  },       /*DP_PIXEL_FORMAT_RGB_101010_30BPP */
};

/*---------------------------------------------------------------------------------------------------------------------
 * Function pre-declarations
 *-------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************

FUNCTION: DP_MNReduceBits()
          -- prevent both M and N not greater than  16 BIts value

Parameters:

Return: 

**********************************************************************************************************************/
void DP_MNReduceBits(uint32 *puMVal, uint32 *puNVal, float fLRatio)
{
  uint32 uLMVal = *puMVal;
  uint32 uLNVal = *puNVal;
  uint32 uLMTmp0;
  uint32 uLMTmp1;
  uint32 uLNTmp0;
  uint32 uLNTmp1;
  uint32 uLNMminusM0;
  uint32 uLNMminusM1;
  float fLErrD;
  float fLErrU;

  /* Round Down */
  uLMTmp0 = (uint32)(uLMVal / 2);                                   /* right shit one bit   */
  fLErrD  = ((float)uLMTmp0) / ((float)uLMVal / 2.0F);              /* Error by truncating  */
  uLNTmp0 = (uint32)(((float)uLNVal) / 2.0 * fLErrD + 0.5);


  /* Round Up */
  uLMTmp1 = (uint32)((float)(uLMVal) / 2.0) + 1;                    /* right shit one bit             */
  fLErrU  = ((float)uLMTmp1) / ((float)uLMVal / 2.0F);               /* Error by truncation and round  */
  uLNTmp1 = (uint32)(((float)uLNVal) / 2.0 * fLErrU + 0.5);

  if ((uLMTmp0 <= MAX_16BITS_VALUE) &&
      (uLMTmp1 >  MAX_16BITS_VALUE))  /* less than 16 bits */
  {
    *puMVal = uLMTmp0;
    *puNVal = uLNTmp0;
  }
  else
  {
    // Do the checking for n-m
    uLNMminusM0 = uLNTmp0 - uLMTmp0;
    uLNMminusM1 = uLNTmp1 - uLMTmp1;
    if ((uLNMminusM0 <= MAX_16BITS_VALUE) && 
        (uLNMminusM1 >  MAX_16BITS_VALUE))
    {
      *puMVal = uLMTmp0;
      *puNVal = uLNTmp0;
    }
    else if (ABS((float)fLRatio - ((float)uLMTmp0 / (float)uLNTmp0)) < ABS((float)fLRatio - ((float)uLMTmp1 / (float)uLNTmp1)))
    {
      *puMVal = uLMTmp0;
      *puNVal = uLNTmp0;
    }
    else
    {
      *puMVal = uLMTmp1;
      *puNVal = uLNTmp1;
    }
  }

  return;
}
/**********************************************************************************************************************

FUNCTION: DP_MNValueSearch()
          -- M, N finder

Parameters:

Return: 

**********************************************************************************************************************/
void DP_MNValueSearch(uint32 *puMVal, uint32 *puNVal)
{
  uint32 uLMVal = *puMVal;
  uint32 uLNVal = *puNVal;
  uint32 uLNTmp;
  float  fLRatio = (float)*puMVal / (float)*puNVal;

  while (uLMVal > MAX_16BITS_VALUE)    /* more than 16 bits */
  {
    DP_MNReduceBits(&uLMVal, &uLNVal, fLRatio);
  }

  // Check N for overflow.
  // N is programmed as ~(N-M)
  uLNTmp = (uLNVal - uLMVal);
  while (uLNTmp > MAX_16BITS_VALUE)
  {
    DP_MNReduceBits(&uLMVal, &uLNVal, fLRatio);
    uLNTmp = (uLNVal - uLMVal);
  }

  *puMVal = uLMVal;
  *puNVal = uLNVal;
}
/**********************************************************************************************************************

FUNCTION: mm_value_gcd()
       -- GCD calculation

Parameters:

Return: 
   uint64

**********************************************************************************************************************/
uint64 DP_MNValueGcd(uint64 uNumerator, uint64 uDenominator)
{
  uint64 num1, num2, tmp;

  num1 = uNumerator;
  num2 = uDenominator;
  tmp  = 0;

  while (num2 != 0)
  {
    tmp  = num2;
    num2 = num1 % num2;
    num1 = tmp;
  }

  return num1;
}

/**********************************************************************************************************************

FUNCTION: DP_MNValueFinder()

Parameters:

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_MNValueFinder(uint64 uSrcRate, uint64 uTargetRate, uint32 *uNumerator, uint32 *uDenominator)
{
  DP_Status eStatus     = DP_STATUS_SUCCESS;
  uint32    num         = 1;
  uint32    den         = 1;
  uint64    gcd;
  uint64    uSrcFreq;
  uint64    uTargetFreq;
  double    error       = 0;

  if ((float)uTargetRate > (2.0 / 3.0*(float)uSrcRate))
  {
    DP_LOG_MESSAGE_ERROR("DP_MNValueFinder: Target Clock frequency (%llu) must be less than 2/3 Source clock frequency (%llu) in Dual-edge mode\n", (uint32)uTargetRate, (uint32)uSrcRate);
    eStatus = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
  }
  else
  {
    uSrcFreq    = (uint64)(uSrcRate    * 1000000);
    uTargetFreq = (uint64)(uTargetRate * 1000000);

    gcd         = DP_MNValueGcd(uTargetFreq, uSrcFreq);
    num         = (uint32)(uTargetFreq / gcd);
    den         = (uint32)(uSrcFreq / gcd);

    DP_MNValueSearch(&num, &den);
    error       = (double)uTargetFreq - ((double)uSrcFreq * (double)num / (double)den);
    if (error != 0)
    {
       DP_LOG_MESSAGE_ERROR("DP_MNValueFinder: can NOT find best M=%d N=%d Error=%d\n" , num, den, error);
    }

    *uNumerator   = num;
    *uDenominator = den;
  }

  return eStatus;
}


/**********************************************************************************************************************

FUNCTION: DP_MNDFinder()
       -- only support 16 bits of M, N and D 

Parameters:
   sMNDCfg           -[in ] 

Return: 
   DP_Status

**********************************************************************************************************************/
DP_Status DP_MNDFinder(DP_MNDType *sMNDCfg)
{
  DP_Status eStatus = DP_STATUS_SUCCESS;
  uint32    uNVal;
  uint32    uMVal;

  if (DP_STATUS_SUCCESS != (eStatus = DP_MNValueFinder(sMNDCfg->uSrcRate, sMNDCfg->uTargetRate, &uMVal, &uNVal)))
  {
    DP_LOG_MESSAGE_ERROR("DP_MNDFinder: Can NOT find correct M,N and D\n");
  }
  else
  {
    sMNDCfg->uMVal       = uMVal;
    sMNDCfg->uNVal       = uNVal;
    sMNDCfg->u2DVal      = uNVal;
    sMNDCfg->uNotNMinusM = (~(uNVal - uMVal)) & 0xffff;
    sMNDCfg->uNot2D      = (~uNVal) & 0xffff;
  }

  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: Div_RoundUp()
   
   This function will do divide first and round up

Parameters:
   num           -[in ] 
   div           -[in ] 

Return: 
   int

**********************************************************************************************************************/
static int Div_RoundUp(double num, int div)
{
  double k2;

  k2 = num / div;
  if (num - (int)k2*div)
  {
    k2 = (int)k2 + 1;
  }
  return (int)k2 * div;
}
   
/**********************************************************************************************************************

FUNCTION: Ceil()
   
   This function will get the ceiling of double value.

Parameters:
   Number                           -[in ] 

Return: 
   int

**********************************************************************************************************************/
int Ceil(double Number)
{
  if(Number >= 0)
  {
    if(Number == (int)Number )
      return (int)Number;
    else
      return (int)Number + 1;
  }
  else
  {
    return (int)Number;
  }
}

/*********************************************************************************************
*
** FUNCTION: DP_CalculateTU()
*/
/*!
* \DESCRIPTION
*     This function will calculate the TU based the the lane #, link clock, pixel clock, color format.
*
* \param [in]   psDisplayInfo         - panel info
* \param [out]  psTUConfig            - The TU parameters
*
* \retval DP_Status
*
**********************************************************************************************/
DP_Status  DP_CalculateTU(DP_TUSizePararmType             *psDisplayInfo,
                          HAL_DP_TUConfigType             *psTUConfig)
{
  DP_Status eStatus              = DP_STATUS_SUCCESS;
  bool32    bEvenDistribution;
  double    fError;
  double    fNewError;
  double    fOldError;
  double    fRatio;
  double    fOriginalRatio;
  double    fAverageValid;
  double    fResultingValid;
  double    fEffectiveValid;
  double    fRemainderTUs;
  double    fRemainderTUsUpper;
  double    fRemainderTUsLower;

  int32     iTUDesired                  = 0;
  int32     iTotalValid                 = 0;
  int32     iNewValidBoundaryLink       = 0;
  int32     iNumberOfTUsPerLane         = 0;
  int32     iNumberOfTUs                = 0;
  int32     iPairedTUs                  = 0;
  int32     iExtraRequiredBytesNew      = 0;
  int32     iExtraPixClkCycles          = 0;
  int32     iExtraPixClkCyclesInLinkClk = 0;
  int32     iFillerSize                 = 0;
  int32     iTUIndex                    = 0;
  int32     iUpperBoundaryIndex         = 0;
  int32     iLowerBoundaryIndex         = 0;
  int32     extra_buffer_margin         = 0;

  if ((0 == psDisplayInfo->uPixelClockInKhz) ||
      (0 == psDisplayInfo->uLinkClockInKhz)  ||
      (0 == psDisplayInfo->uNumberOfLanes))
  {
    eStatus = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
  }
  else
  {
    extra_buffer_margin              = Ceil((double)psDisplayInfo->uLinkClockInKhz * EXTRA_PIXCLK_CYCLE_DELAY / psDisplayInfo->uPixelClockInKhz);
    fRatio                           = ((double)psDisplayInfo->uPixelClockInKhz * psDisplayInfo->uBPP) / 
                                       ((double)psDisplayInfo->uLinkClockInKhz  * psDisplayInfo->uNumberOfLanes * 8);
    fOriginalRatio                   = fRatio;

    if( (psDisplayInfo->uVisWidth % psDisplayInfo->uNumberOfLanes != 0) && 
        (fRatio < 1))
    {
      fRatio = fRatio * RATIO_SCALE;
      fRatio = fRatio < 1 ? fRatio : 1;
    }

    fError                           = 1000;

    for(iTUIndex = 32; iTUIndex <= 64; iTUIndex++)
    {
       fNewError = Ceil(fRatio * iTUIndex) -  (fRatio * iTUIndex);
       if(fNewError < fError)
       {
          fError     = fNewError;
          iTUDesired = iTUIndex;
       }
    }

    if (fError == 0)
    {
        iNewValidBoundaryLink           = Ceil(fRatio * iTUDesired);
        iNumberOfTUs                    = (int)((psDisplayInfo->uVisWidth * psDisplayInfo->uBPP / 8) / iNewValidBoundaryLink);
        iExtraRequiredBytesNew          = Ceil((iNumberOfTUs + 1) * (iNewValidBoundaryLink - fOriginalRatio * iTUDesired));
        iExtraPixClkCycles              = Ceil((double)iExtraRequiredBytesNew * 8/ psDisplayInfo->uBPP); 
        iExtraPixClkCyclesInLinkClk     = Ceil((double)iExtraPixClkCycles * psDisplayInfo->uLinkClockInKhz / psDisplayInfo->uPixelClockInKhz);
        iFillerSize                     = Ceil(iTUDesired - iNewValidBoundaryLink);

        psTUConfig->uDelayStartLink     = (MAX(iExtraRequiredBytesNew, iExtraPixClkCyclesInLinkClk) + iFillerSize + extra_buffer_margin);
        psTUConfig->uValidBoundaryLink  = iNewValidBoundaryLink;
        psTUConfig->bBoundaryModEnable  = FALSE;
        psTUConfig->uUpperBoundaryCount = 0;
        psTUConfig->uLowerBoundaryCount = 0;
        psTUConfig->uValidLowerBoundary = 0;
        psTUConfig->uTuSize             = iTUDesired;
    }
    else 
    {
       fError                           = 1000;

       for(iTUIndex = 32; iTUIndex <= 64; iTUIndex++)
       {
          for( iUpperBoundaryIndex = 1; iUpperBoundaryIndex<= 15; iUpperBoundaryIndex++)
          {
             for(iLowerBoundaryIndex = 1; iLowerBoundaryIndex<= 15; iLowerBoundaryIndex++)
             {
               iNewValidBoundaryLink    = Ceil(fRatio * iTUIndex);
               fAverageValid            = (double)( iUpperBoundaryIndex *  iNewValidBoundaryLink + 
                                                   iLowerBoundaryIndex * (iNewValidBoundaryLink - 1)) /
                                                  (iUpperBoundaryIndex + iLowerBoundaryIndex);
               iNumberOfTUs             = (int)((psDisplayInfo->uVisWidth * psDisplayInfo->uBPP / 8) / fAverageValid);
               iNumberOfTUsPerLane      = (int)((double)iNumberOfTUs/ psDisplayInfo->uNumberOfLanes);
               iPairedTUs               = (int)((double)iNumberOfTUsPerLane / (iUpperBoundaryIndex + iLowerBoundaryIndex));
               fRemainderTUs            = iNumberOfTUsPerLane - iPairedTUs * (iUpperBoundaryIndex + iLowerBoundaryIndex);

               //finding how many upper fRemainderTUs boundary TUs left
               if ((fRemainderTUs - iUpperBoundaryIndex) > 0) 
               {
                  fRemainderTUsUpper = iUpperBoundaryIndex;
                  fRemainderTUsLower = fRemainderTUs - iUpperBoundaryIndex;
               }
               else
               {
                  fRemainderTUsUpper = fRemainderTUs;
                  fRemainderTUsLower = 0;
               }
               iTotalValid = (int32)(iPairedTUs   * 
                        (iUpperBoundaryIndex * iNewValidBoundaryLink + 
                        iLowerBoundaryIndex  * (iNewValidBoundaryLink - 1)) +
                        (fRemainderTUsUpper  * iNewValidBoundaryLink) + 
                        (fRemainderTUsLower  * (iNewValidBoundaryLink - 1)));

               if(iNumberOfTUsPerLane == 0)
               {
                  fEffectiveValid = 0;
               }
               else
               {
                  fEffectiveValid = iTotalValid*1.0 / iNumberOfTUsPerLane;
               }

               fNewError = fEffectiveValid - fRatio * iTUIndex;         /*this is error with considering line width   */
               fOldError = fAverageValid   - fRatio * iTUIndex;         /*this is error without considering line width*/
               if((iNumberOfTUs % psDisplayInfo->uNumberOfLanes) == 0)
               {
                  bEvenDistribution = TRUE;
               }
               else
               {
                  bEvenDistribution = FALSE;
               }

               /*
                * To reduce complexity of calculation, checking "hporch < delay_start"
                * is not enforce here since horizontal porch is very large and delay_start
                * usually is small. On the other words, the possibility of fail at checking
                * "hporch < delay_start" is very rare and it can be ignored.
                */
               if ( (bEvenDistribution == TRUE      ) &&
                    (fOldError > 0                  ) && 
                    (fNewError > 0                  ) && 
                    (fNewError < fError             ) && 
                    ((iNewValidBoundaryLink - 1) > 0) )
               {
                   fError                          = fNewError;
                   psTUConfig->bBoundaryModEnable  = TRUE;
                   psTUConfig->uUpperBoundaryCount = iUpperBoundaryIndex;
                   psTUConfig->uLowerBoundaryCount = iLowerBoundaryIndex;
                   iTUDesired                      = iTUIndex; 
                   psTUConfig->uValidBoundaryLink  = iNewValidBoundaryLink;
                   psTUConfig->uValidLowerBoundary = iNewValidBoundaryLink -1;
               }
             }
          }

          if (psTUConfig->bBoundaryModEnable == TRUE)
          {    
             fResultingValid = ((double)(psTUConfig->uUpperBoundaryCount * psTUConfig->uValidBoundaryLink + 
                                         psTUConfig->uLowerBoundaryCount * (psTUConfig->uValidBoundaryLink - 1))) / 
                                        (psTUConfig->uUpperBoundaryCount + psTUConfig->uLowerBoundaryCount);
             iNumberOfTUs                 = (int)((psDisplayInfo->uVisWidth * psDisplayInfo->uBPP / 8) / fResultingValid);
             iExtraRequiredBytesNew       = Ceil((iNumberOfTUs + 1) * (fResultingValid - fOriginalRatio * iTUDesired)) + 
                                            Ceil( psTUConfig->uUpperBoundaryCount                        * 
                                                ( psTUConfig->uValidBoundaryLink - fOriginalRatio * iTUDesired) *
                                                  psDisplayInfo->uNumberOfLanes);
             iExtraPixClkCycles          = Ceil((double)iExtraRequiredBytesNew * 8/ psDisplayInfo->uBPP); 
             iExtraPixClkCyclesInLinkClk = Ceil((double)iExtraPixClkCycles * psDisplayInfo->uLinkClockInKhz /
                                           psDisplayInfo->uPixelClockInKhz);
             iFillerSize                 = Ceil(iTUDesired - psTUConfig->uValidBoundaryLink);
             psTUConfig->uDelayStartLink = (MAX(iExtraRequiredBytesNew, iExtraPixClkCyclesInLinkClk) + 
                                      iFillerSize + 1 + extra_buffer_margin); //recalculating delay start
             psTUConfig->uTuSize         = iTUDesired;
          }
          else
          {
              eStatus = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
          }
       }
    }
  }
  return eStatus;
}

/*********************************************************************************************
*
** FUNCTION: DP_CalculateLink()
*/
/*!
* \DESCRIPTION
*     This function will Calculate the Link settings, such as clock freq, number of lane needed.
*
* \param [in]   pDeviceCtx            - Pointer to device context
* \param [in]   psDPCDSinkCap         - Pointer to sink DPCD capabilities
* \param [in]   psPanelInfo           - Pointer to panel info corresponding to current mode
* \param [out]  pPixClkInfo           - Pointer to pixel clock info (dividers, etc.)
*
* \retval DP_Status
*
**********************************************************************************************/
DP_Status  DP_CalculateLink(DP_DeviceCtxType         *pDeviceCtx,
                            DP_DPCDSinkCapType       *psDPCDSinkCap,
                            DP_PanelInfoType         *psPanelInfo,
                            DP_PixelClk_Info         *pPixClkInfo)
{
  DP_Status             eStatus              = DP_STATUS_SUCCESS;
  uint32                uLinkRate            = 0;
  uint32                uDesiredLaneNumber   = 0;
  uint32                uBitRate;
  uint32                uLaneNumber;
  uint32                uLaneRate;
  DP_MNDType            sMNDCfg;
  DP_LinkRateSettings   sLinkSettings[] = {
                                          {162000,  810, 1},  // EDP_PHY_RATE_1P62G
                                          {216000, 1080, 1},  // EDP_PHY_RATE_2P16G
                                          {243000, 1215, 1},  // EDP_PHY_RATE_2P43G
                                          {270000, 1350, 1},  // EDP_PHY_RATE_2P7G
                                          {324000,  810, 2},  // EDP_PHY_RATE_3P24G
                                          {432000, 1080, 2},  // EDP_PHY_RATE_4P32G
                                          {540000, 1350, 2},  // EDP_PHY_RATE_5P4G
                                          {594000,  990, 3},  // EDP_PHY_RATE_5P94G
                                          {810000, 1350, 3},  // EDP_PHY_RATE_8P1G
                                          {0,         0, 0},  //  End
                                          };
  bool32               bLaneFound       = FALSE;
  DP_LinkRateSettings  *pLinkSetting;

  /* Clear the link rate and lane number setting if they are not set by DP_Host_SetProperty for mode changing */
  if (0 == (pDeviceCtx->uDirtyBits & DP_DIRTYFIELD_LINK_RATE))
  {
    pDeviceCtx->uLinkRateInKhz = 0;
  }
  
  if (0 == (pDeviceCtx->uDirtyBits & DP_DIRTYFIELD_LANE_NUMBER))
  {
    pDeviceCtx->uNumLanes      = 0;
  }

  if (pDeviceCtx->uLinkRateInKhz == 0)  /* link rate not set */
  {
       uLinkRate = pDeviceCtx->sSinkDPCDCap.uMaxLinkRateInKhz;  /* use highest supported link rate */
  }
  else
  {
       uLinkRate = pDeviceCtx->uLinkRateInKhz;  /* use pre set link rate */
  }

  pLinkSetting = &sLinkSettings[0];  /* 1.62 G */
  while (pLinkSetting->uInputClkMhz != 0)
  {
      if (pLinkSetting->uLinkRateMBps == uLinkRate)
         break;

      pLinkSetting++;   /* search from lower rate to higher rate */
  }

  if (pLinkSetting->uInputClkMhz == 0)
  {
     pLinkSetting = &sLinkSettings[0];  /* not found, default at 1.62G */
  }

  if (psPanelInfo->uPclkFreq == 0)
  {
     DP_LOG_MESSAGE_ERROR("DisplayDxe: DP_CalculateLink: ID=%d no pixel clock rate assigned\n", pDeviceCtx->eDeviceID);
     eStatus = DP_STATUS_FAILED_NOT_SUPPORTED;
  }
  else
  {

    // Calculate the bit rate
    uBitRate = (psPanelInfo->uPclkFreq / 1000) * DPHOST_GETPIXELFMT(psPanelInfo->eColorFormat).uBitsPerPixel;

    /* prefer using highest rate with less lane */

    uLinkRate = pLinkSetting->uLinkRateMBps;

    if (pDeviceCtx->uNumLanes ==  0)
    {
       // Calculate the desired number of lanes
       for (uLaneNumber = 1; uLaneNumber <= psDPCDSinkCap->uMaxLaneCount; uLaneNumber++)
       {
           if (uLaneNumber == 3)
           {
             /* Lane Number cannot be 3 */
             continue;
           }
           uLaneRate = (uint32)(uLinkRate * uLaneNumber * 8);
           if (uLaneRate > uBitRate)
           {
             bLaneFound = TRUE;
             uDesiredLaneNumber      = uLaneNumber;
             break;
           }
         }
     }
     else
     {
             uDesiredLaneNumber      = pDeviceCtx->uNumLanes;
             bLaneFound = TRUE;
     }

    if (bLaneFound)
    {
      pDeviceCtx->uNumLanes                  =  uDesiredLaneNumber;
      pDeviceCtx->uLinkRateInKhz             =  uLinkRate;
      pDeviceCtx->uPixelClkInKhz             =  psPanelInfo->uPclkFreq / 1000;

      DP_LOG_MESSAGE_INFO("DP_CalculateLink: calculated lane=%d rate=%d pclk=%d\n", pDeviceCtx->uNumLanes, pDeviceCtx->uLinkRateInKhz, pDeviceCtx->uPixelClkInKhz);

      sMNDCfg.uSrcRate    = pLinkSetting->uInputClkMhz * 1000000;
      sMNDCfg.uTargetRate = psPanelInfo->uPclkFreq / 2; /* Use 2 pixels per clock mode for all DP interfaces */

      /* Use pixel clock from EDID, standard pixel clock should give 0-error MND value*/
      if (DP_STATUS_SUCCESS != (eStatus = DP_MNDFinder(&sMNDCfg)))
      {
         DP_LOG_MESSAGE_WARN("DP_CalculateLink: cannot find a jitter free MND, src rate=%d target rate=%d\n", sMNDCfg.uSrcRate, sMNDCfg.uTargetRate);
         eStatus = DP_STATUS_FAILED_NOT_SUPPORTED;
      }
      else
      {
         /* pixel clock m,n,d value */
         pPixClkInfo->uPixelClkMNDInputMhz      =  pLinkSetting->uInputClkMhz;
         pPixClkInfo->uPixelClk_M               =  sMNDCfg.uMVal;
         pPixClkInfo->uPixelClk_N               =  sMNDCfg.uNVal;
         pPixClkInfo->uPixelClk_2D              =  sMNDCfg.u2DVal;
         pPixClkInfo->uPixelDivider             =  1;

         if (pDeviceCtx->bSynchronousClk)
         {
           if (DP_DPCD_DOWNSTREAMPORTTYPE_VGA_DVI_I == pDeviceCtx->sSinkDPCDCap.eDwnStreamPortType)
           {
          // Most DP to VGA dongle on market will only accept Nvid = 0x8000, thus SW workaround is to fix NVid to 0x8000, and based on it calculate the value of MVid.
          // For the rest of DP to VGA dongle, the setting is still working, as long as Mvid / Nvid = PixelClk / LinkFreq
             if (0 == pDeviceCtx->uLinkRateInKhz)
             {
               DP_LOG_MESSAGE_WARN("Cannot calculate MVid value, Link Rate is set to 0!");
               eStatus = DP_STATUS_FAILED_NOT_SUPPORTED;
             }
             else
             {
               pPixClkInfo->uSWNVid = 0x8000;
               pPixClkInfo->uSWMVid = (uint32)(((uint64)pPixClkInfo->uSWNVid * pDeviceCtx->uPixelClkInKhz) / pDeviceCtx->uLinkRateInKhz);
             }
           }
           else
           {
             /*
              * Mvid/Nvid = PixelClk/LinkFreq .
              * In sync mode, we have pixel_clk = (link * 5 * M)/ (uPreDiv * N)
              *
              * Both uSWMVid and uSWNVID are conveyed over mainlink to panel (sinker)
              * They have to be used at 1 pixel per clock value so that uSWMVid must
              * timed by 2 since it was calculated at 2 pixel per clock earlier
              */
             pPixClkInfo->uSWMVid                 =  sMNDCfg.uMVal * 5 * 2;
             pPixClkInfo->uSWNVid                 =  sMNDCfg.uNVal * pLinkSetting->uNvidFactor;
          }
        }
      }
    }
    else
    {
       DP_LOG_MESSAGE_WARN("Cannot find a Lane Number for LinkRtae=%d!\n", uLinkRate);
       eStatus = DP_STATUS_FAILED_NOT_SUPPORTED;
    }
  }
  return eStatus;
}

/**********************************************************************************************************

FUNCTION: DP_CheckTrainingResult()
   
   This function will get the max (among all lanes) drive setting requested by the sink 

Parameters:
   pDeviceCtx                         -[in ] Pointer to device context
   psDPCDSinkStatus                   -[in ] Pointer to DPCP sink status
   eTrainingType                      -[in ] type of link training done

Return: 
   bool32                             - TRUE = training successful 

************************************************************************************************************/
bool32  DP_CheckTrainingResult(DP_DeviceCtxType            *pDeviceCtx,
                               DP_DPCDSinkStatusType       *psDPCDSinkStatus,
                               DP_LinkTrainingStatusType    eTrainingType)
{  
  bool32            bDone       = TRUE;
  uint32            i           = 0;

  if (DP_LINK_TRAINING_STATUS_CLK_RECOVERY_DONE & eTrainingType)
  {
    for (i = 0; i< pDeviceCtx->uNumLanes; ++i)
    {
      if (0 == (psDPCDSinkStatus->eLaneStatus[i] & DP_DPCD_LANE_STATUS_CR_DONE))
      {
        bDone = FALSE;
        goto exit;
      }
    }
  }

  if (DP_LINK_TRAINING_STATUS_CHANNEL_EQ_DONE & eTrainingType)
  {
    for (i = 0; i< pDeviceCtx->uNumLanes; ++i)
    {
      if (0 == (psDPCDSinkStatus->eLaneStatus[i] & DP_DPCD_LANE_STATUS_CHANNEL_EQ_DONE))
      {
        bDone = FALSE;
        goto exit;
      }
    }
  }

  if (DP_LINK_TRAINING_STATUS_SYMBOL_LOCKED & eTrainingType)
  {
    for (i = 0; i< pDeviceCtx->uNumLanes; ++i)
    {
      if (0 == (psDPCDSinkStatus->eLaneStatus[i] & DP_DPCD_LANE_STATUS_SYMBOL_LOCKED))
      {
        bDone = FALSE;
        goto exit;
      }
    }
  }

  if (DP_LINK_TRAINING_STATUS_INTERLANE_ALIGN_DONE & eTrainingType)
  {  
    if (0 == (psDPCDSinkStatus->eLinkStatusBitArray & DP_DPCD_BIT_STATUS_INTERLANE_ALIGN_DONE))
    {
      bDone = FALSE;
      goto exit;
    }
  }

exit:

  return bDone;
}

/**********************************************************************************************************

FUNCTION: DP_GetMaxSinkPeSwRequest()
   
   This function will get the max (among all lanes) drive setting requested by the sink 

Parameters:
   pDeviceCtx                         -[in ] Pointer to device context
   psDPCDSinkStatus                   -[in ] Pointer to DPCP sink status
   uVoltSwingLvl                      -[out ] max Voltage swing level requested
   uPreemphLvl                        -[out ] max Pre-emphasis level requested

Return: 
   DP_Status 

************************************************************************************************************/
static void DP_GetMaxSinkPeSwRequest(DP_DeviceCtxType                *pDeviceCtx,
                                     DP_DPCDSinkStatusType           *psDPCDSinkStatus, 
                                     uint32                          *uVoltSwingLvl,
                                     uint32                          *uPreemphLvl)
{
  uint32             i           = 0;
  uint32             uSwLvl      = 0;
  uint32             uPeLvl      = 0;

  /*  We do not support per-lane drive settings.
   *  If sink makes such a request, pick the highest pre-emphasis and swing of all lanes
   */

  uSwLvl  = DPCD_SPEC_MIN_VOLTAGE_SWING_LEVEL;
  for (i = 0; i < pDeviceCtx->uNumLanes; i++)
  {
    if (uSwLvl < psDPCDSinkStatus->uVoltageSwingLevel[i])
    {
      uSwLvl = psDPCDSinkStatus->uVoltageSwingLevel[i];
    }
  }

  uPeLvl  = DPCD_SPEC_MIN_PRE_EMPHASIS_LEVEL;
  for (i = 0; i< pDeviceCtx->uNumLanes; i++)
  {
    if (uPeLvl < psDPCDSinkStatus->uPreEmphasisLevel[i])
    {
      uPeLvl = psDPCDSinkStatus->uPreEmphasisLevel[i];
    }
  }

  *uVoltSwingLvl = uSwLvl;
  *uPreemphLvl   = uPeLvl;
}

/**********************************************************************************************************

FUNCTION: DP_LinkSetupPreemphSwing()
   
   This function will set up the nearest possible premphasis / voltage swing to teh requested level 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   uVoltSwingLvl                    -[in ] Voltage swing level to set
   uPreemphasisLvl                  -[in ] Pre-emphasis level to set

Return: 
   DP_Status 

************************************************************************************************************/
static DP_Status DP_LinkSetupPreemphSwing(DP_DeviceCtxType  *pDeviceCtx,
                                          uint32             uVoltSwingLvl,
                                          uint32             uPreemphasisLvl)
{
  DP_Status         eStatus                 = DP_STATUS_SUCCESS;
  
  HAL_DP_PeSwConfigType  sPeSwConfig;

  /* Check if request is outside the limits of DP spec*/
  if (uVoltSwingLvl > DPCD_SPEC_MAX_VOLTAGE_SWING_LEVEL)
  {
    uVoltSwingLvl = DPCD_SPEC_MAX_VOLTAGE_SWING_LEVEL;
  }
  if (uPreemphasisLvl > DPCD_SPEC_MAX_PRE_EMPHASIS_LEVEL)
  {
    uPreemphasisLvl = DPCD_SPEC_MAX_PRE_EMPHASIS_LEVEL;
  }

  sPeSwConfig.uLaneSwingLevel       = uVoltSwingLvl;
  sPeSwConfig.uPreemphasisLevel     = uPreemphasisLvl;
  sPeSwConfig.bPreemphNotSupported  = FALSE;
  sPeSwConfig.bSwingNotsupported    = FALSE;

  /* Set the requested or closest possible settings */
  
  while (HAL_MDSS_STATUS_SUCCESS != HAL_DP_SetupPHYPeSwLevel(pDeviceCtx->eDeviceID, &sPeSwConfig))
  {    
    if ((DPCD_SPEC_MIN_PRE_EMPHASIS_LEVEL  == sPeSwConfig.uPreemphasisLevel) &&
        (DPCD_SPEC_MIN_VOLTAGE_SWING_LEVEL == sPeSwConfig.uLaneSwingLevel))
    {
      // We should never hit this in practice
      DP_LOG_MESSAGE_ERROR("Failed to set lane drv settings\n");
      eStatus = DP_STATUS_FAIL;
      break;
    }
    
    if (sPeSwConfig.bPreemphNotSupported)
    {
     /* pre-emphasis level exceeds our capability - choose the next highest level we support */
      --(sPeSwConfig.uPreemphasisLevel);
    }
    else if (sPeSwConfig.bSwingNotsupported)
    {      
      /* voltage swing level exceeds our capability for this pre-emphasis 
       *     - choose the highest swing we can support at this pre-emphasis level 
       */
      --(sPeSwConfig.uLaneSwingLevel);
    }
    else
    {
      // We should never hit this in practice
      DP_LOG_MESSAGE_ERROR("Hardware failed to set lane drv settings\n");
      eStatus = DP_STATUS_FAILED_RESOURCE_FAILED;
      break;
    }
  }

  if (DP_STATUS_SUCCESS == eStatus)
  {
    pDeviceCtx->uVoltageSwingLevel = sPeSwConfig.uLaneSwingLevel;
    pDeviceCtx->uPreEmphasisLevel  = sPeSwConfig.uPreemphasisLevel;
  }
  
  return eStatus;
}

/**********************************************************************************************************************

FUNCTION: DP_LinkTraining_ClockRecovery()
   
   This function will do link training with pattern TPS1 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   uFlags                           -[in ] Reserved

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_LinkTraining_ClockRecovery(DP_DeviceCtxType  *pDeviceCtx,
                                         DP_FlagsType       uFlags)
{
  DP_Status                       eStatus            = DP_STATUS_SUCCESS;
  uint32                          uRetries           = MAX_LINK_TRAINING_LOOP;
  uint32                          uVoltSwingLvl      = 0;
  uint32                          uPreemphLvl        = 0;
  uint32                          uPrevVoltSwingLvl  = DPCD_SPEC_MIN_VOLTAGE_SWING_LEVEL;
  uint32                          uPrevPreemphLvl    = DPCD_SPEC_MIN_PRE_EMPHASIS_LEVEL;
  DP_DPCDSinkStatusType           sSinkDPCDStatus; 
 
  if(DP_STATUS_SUCCESS == eStatus)
  {
    // Start sending Training Pattern 1
    HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN1);

    // Inform sink about the Training Pattern we are using
    eStatus  = DP_WriteSinkDPCDTrainingPattern(pDeviceCtx, DP_DPCD_TRAININGPATTERNSET_PATTERN1);

    // Start with minimum pre-emphasis & voltage swing  
    DP_LinkSetupPreemphSwing(pDeviceCtx, uPrevVoltSwingLvl, uPreemphLvl);
    eStatus = DP_WriteSinkDPCDLevels(pDeviceCtx, pDeviceCtx->uVoltageSwingLevel, pDeviceCtx->uPreEmphasisLevel);

  }

  if(DP_STATUS_SUCCESS == eStatus)
  {
    for(;;)
    {
      // Wait for a period defined by the DPCD 
      DP_OSAL_SleepUs(100);  /* always 100 us */

      eStatus = DP_ReadSinkDPCDStatus(pDeviceCtx, &sSinkDPCDStatus);
      if (DP_STATUS_SUCCESS != eStatus)
      {
        DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ClockRecovery: Failed to read sink status from DPCD\n");
        break;
      }
            
      if (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_CLK_RECOVERY_DONE))
      {       
        // Link Training successful        
        break;
      }

      // Get Sink requested pre-emphasis and voltage swing
      DP_GetMaxSinkPeSwRequest(pDeviceCtx, &sSinkDPCDStatus, &uVoltSwingLvl, &uPreemphLvl);

      if (uPrevVoltSwingLvl == pDeviceCtx->uMaxVoltSwingLvl)
      {
        DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ClockRecovery: DP_LinkSetupPreemphSwing failed, eStatus =%d\n", eStatus);
        eStatus = DP_STATUS_FAILED_LINK_TRAINING;
        break;
      }

      if ((uPrevVoltSwingLvl == uVoltSwingLvl) &&
          (uPrevPreemphLvl   == uPreemphLvl))
      {
        if (--uRetries == 0)
        {
          eStatus = DP_STATUS_FAILED_LINK_TRAINING;
          DP_LOG_MESSAGE_ERROR("Link Training (clock recovery) failed (5 attempts)\n");
          break;
        }
      }
      else
      {
        // Reset loop count
        uRetries = MAX_LINK_TRAINING_LOOP;
        uPrevVoltSwingLvl = uVoltSwingLvl;
        uPrevPreemphLvl   = uPreemphLvl;
      }

      // Apply newly requested settings
      if (DP_STATUS_SUCCESS != (eStatus = DP_LinkSetupPreemphSwing(pDeviceCtx, uVoltSwingLvl, uPreemphLvl)))
      {
        DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ClockRecovery: DP_LinkSetupPreemphSwing failed, eStatus =%d\n", eStatus);
        break;
      }
      else if(DP_STATUS_SUCCESS != (eStatus = DP_WriteSinkDPCDLevels(pDeviceCtx, pDeviceCtx->uVoltageSwingLevel, pDeviceCtx->uPreEmphasisLevel)))
      {
        DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ClockRecovery: DP_WriteSinkDPCDLevels failed, eStatus =%d\n", eStatus);
        break;
      }
    }
  }
  
  if(DP_STATUS_SUCCESS != eStatus)
  {
    DP_LOG_MESSAGE_ERROR("Link training 1 failed with eStatus=0x%x\n",eStatus);
  }
  else
  {
    DP_LOG_MESSAGE_INFO("DP_LinkTraining_ClockRecovery: Succeed\n");
  }

  return eStatus;
}


/**********************************************************************************************************************

FUNCTION: DP_LinkTraing_Pattern23()
   
   This function will do link training with pattern TPS2 or TPS3 

Parameters:
   pDeviceCtx                       -[in ] Pointer to device context
   uFlags                           -[in ] Reserved

Return: 
   DP_Status 

**********************************************************************************************************************/
DP_Status  DP_LinkTraining_ChannelEqualization(DP_DeviceCtxType    *pDeviceCtx,
                                               DP_FlagsType         uFlags)
{
  DP_Status   eStatus            = DP_STATUS_SUCCESS;  

  if (NULL == pDeviceCtx)
  {
    DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: input is NULL pointer\n");
  }
  else
  {
    DP_DPCDTrainingPatternSetType eTrainingPattern;

    if (pDeviceCtx->sSinkDPCDCap.eDPCDCap & DP_DPCD_CAP_SUPPORT_TRAININGPATTERN4)
    {
      // Start sending Training Pattern 4
      HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN4);
      eTrainingPattern = DP_DPCD_TRAININGPATTERNSET_PATTERN4;
    }
    else if (pDeviceCtx->sSinkDPCDCap.eDPCDCap & DP_DPCD_CAP_SUPPORT_TRAININGPATTERN3)
    {
      // Start sending Training Pattern 3
      HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN3);
      eTrainingPattern = DP_DPCD_TRAININGPATTERNSET_PATTERN3;
    }
    else
    {
      // Start sending Training Pattern 2
      HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN2);
      eTrainingPattern = DP_DPCD_TRAININGPATTERNSET_PATTERN2;
    }

    // Inform sink about the Training Pattern we are using
    if (DP_STATUS_SUCCESS != (eStatus = DP_WriteSinkDPCDTrainingPattern(pDeviceCtx, eTrainingPattern)))
    {
      DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: DP_WriteSinkDPCDTrainingPattern failed, eStatus = %d\n", eStatus);
    }
    else if (DP_STATUS_SUCCESS != (eStatus = DP_LinkSetupPreemphSwing(pDeviceCtx, pDeviceCtx->uVoltageSwingLevel, pDeviceCtx->uPreEmphasisLevel)))
    {
      DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: DP_LinkSetupPreemphSwing failed, eStatus = %d\n", eStatus);
    }
    else if (DP_STATUS_SUCCESS != (eStatus = DP_WriteSinkDPCDLevels(pDeviceCtx, pDeviceCtx->uVoltageSwingLevel, pDeviceCtx->uPreEmphasisLevel)))
    {
      DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: DP_WriteSinkDPCDLevels failed, eStatus = %d\n", eStatus);
    }
    else
    {
      DP_DPCDSinkStatusType   sSinkDPCDStatus;
      uint32                  uVoltSwingLvl = 0;
      uint32                  uPreemphLvl   = 0;
      uint32                  uRetries      = 0;

      for (uRetries = 0; uRetries < MAX_LINK_TRAINING_LOOP; uRetries++)
      {
        /* Wait for a period defined by the DPCD 0x0E. */
        DP_OSAL_SleepUs(pDeviceCtx->sSinkDPCDCap.uTrainingIntervalInUs);


        /* Read the DPCP Link Status */
        eStatus  = DP_ReadSinkDPCDStatus(pDeviceCtx, &sSinkDPCDStatus);
        if(DP_STATUS_SUCCESS != eStatus)
        {    
          DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: Failed to read sink status from DPCD\n");
          break;
        }
      
        if(FALSE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_CLK_RECOVERY_DONE))
        {
          DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: Clock Recovery Failed\n");
          eStatus = DP_STATUS_FAILED_RESOURCE_FAILED;
          break;
        }

        if((TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_CHANNEL_EQ_DONE)) &&
           (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_SYMBOL_LOCKED))   &&
           (TRUE == DP_CheckTrainingResult(pDeviceCtx, &sSinkDPCDStatus, DP_LINK_TRAINING_STATUS_INTERLANE_ALIGN_DONE)))
        {
          /* Link Training 2/3 done successfully */
          DP_LOG_MESSAGE_WARN("Link training on DeviceId=%d: Channel EQ , Symbol Lock and Inter-lane align Done\n", pDeviceCtx->eDeviceID);
          pDeviceCtx->bLinkLost = FALSE;
          break;
        }

        // Get Sink requested pre-emphasis and voltage swing
        DP_GetMaxSinkPeSwRequest(pDeviceCtx, &sSinkDPCDStatus, &uVoltSwingLvl, &uPreemphLvl);

        // Apply newly requested settings
        if (DP_STATUS_SUCCESS != (eStatus = DP_LinkSetupPreemphSwing(pDeviceCtx, uVoltSwingLvl, uPreemphLvl)))
        {
          DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: DP_LinkSetupPreemphSwing failed, eStatus =%d\n", eStatus);
          break;
        }
        else if (DP_STATUS_SUCCESS != (eStatus = DP_WriteSinkDPCDLevels(pDeviceCtx, pDeviceCtx->uVoltageSwingLevel, pDeviceCtx->uPreEmphasisLevel)))
        {
          DP_LOG_MESSAGE_ERROR("DP_LinkTraining_ChannelEqualization: DP_WriteSinkDPCDLevels failed, eStatus =%d\n", eStatus);
          break;
        }
      }

      if (uRetries >= MAX_LINK_TRAINING_LOOP)
      {
        DP_LOG_MESSAGE_ERROR("Link Training (channel Eq) failed (%d attempts)\n", MAX_LINK_TRAINING_LOOP);
        eStatus = DP_STATUS_FAILED_RESOURCE_FAILED;
      }
    }
  }
  
  return eStatus;
}

/*********************************************************************************************
*
** FUNCTION: DP_LinkTraining()
*/
/*!
* \DESCRIPTION
*     This function will read from AUX/I2c channel
*
* \param [in]   pDeviceCtx              - Pointer to device context
* \param [in]   eLinkTrainingType       - The type of Link training
* \param [in]   uFlags                  - Reserved
*
* \retval DP_Status
*
**********************************************************************************************/
DP_Status DP_LinkTraining(DP_DeviceCtxType         *pDeviceCtx,
                          DP_LinkTrainingType       eLinkTrainingType,
                          DP_FlagsType              uFlags)
{
  DP_Status             eStatus     = DP_STATUS_SUCCESS;

  if (DP_LINK_TRAINING_TYPE_FULL_TRAINING == eLinkTrainingType)
  {
    
    // TPS1
    if (eStatus == DP_STATUS_SUCCESS)
    {
      eStatus = DP_LinkTraining_ClockRecovery(pDeviceCtx, uFlags);
    }
    
    // TPS2 or TPS3
    if (eStatus == DP_STATUS_SUCCESS)
    {
      eStatus = DP_LinkTraining_ChannelEqualization(pDeviceCtx, uFlags);      
    }

    // Stop training
    HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_NONE);
    DP_WriteSinkDPCDTrainingPattern(pDeviceCtx, DP_DPCD_TRAININGPATTERNSET_NONE);

  }
  else if (DP_LINK_TRAINING_TYPE_FAST_TRAINING == eLinkTrainingType)
  {
    /* In the fast training approach, we send each training pattern for a certain amount of time.
     * We do not do any AUX transactions in this training mode
     */
     
    // TPS 1
    HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN1);
    DP_OSAL_SleepMs(1);

    // TPS2
    HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_SEND_PATTERN2);
    DP_OSAL_SleepMs(1);

    // Stop training
    HAL_DP_SetLinkState(pDeviceCtx->eControllerID, HAL_DP_LINKCOMMAND_TYPE_NONE);
  }
  else if (DP_LINK_TRAINING_TYPE_NO_TRAINING == eLinkTrainingType)
  {
    // Nothing to do
    DP_LOG_MESSAGE_WARN("DP_LinkTraining: NO training\n");
  }
  else
  {
    DP_LOG_MESSAGE_ERROR("DP_LinkTraining: invalid training type = %d\n", (uint32)eLinkTrainingType);
    eStatus = DP_STATUS_FAILED_INVALID_INPUT_PARAMETER;
  }

  return eStatus;
}

/*********************************************************************************************
*
** FUNCTION: DP_CalculateMisc0()
*/
/*!
* \DESCRIPTION
*     This function will calculate the MISCO value according to DP Spec
*
* \param [in]   eColorFormat             - Sink color format
*
* \retval  uint8 Misc0 value
*
**********************************************************************************************/
uint8  DP_CalculateMisc0(DP_PixelFormatType eColorFormat )
{
  uint8 uMisc0;

  if (DP_PIXEL_FORMAT_RGB_666_18BPP == eColorFormat )
  {
    uMisc0 = 0;
  }
  else if (DP_PIXEL_FORMAT_RGB_101010_30BPP == eColorFormat )
  {
    uMisc0 = DP_SPEC_MSA_MISCO_COLOR_10BPC_BMSK;
  }
  else
  {
    uMisc0 = DP_SPEC_MSA_MISCO_COLOR_8BPC_BMSK;
  }
  return uMisc0;
}

#ifdef __cplusplus
}
#endif

