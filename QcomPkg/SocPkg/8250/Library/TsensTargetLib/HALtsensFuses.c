/*============================================================================
  FILE:         HALtsensFuses.c

  OVERVIEW:     Implementation of the TSENS HAL for reading fuses

  DEPENDENCIES: None

                Copyright (c) 2019 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary.
============================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "HALhwio.h"
#include "HALhwioTsensFuses.h"
#include "HALtsens.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Static Function Declarations
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Global Data Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Static Variable Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Static Function Declarations and Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Externalized Function Definitions
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Char data
 * -------------------------------------------------------------------------*/

/* ============================================================================
**
**  HAL_tsens_UseRedundant
**
**  Description:
**    Whether or not to use the redundant region
**
**  Parameters:
**    None
**
**  Return: TRUE: use redundant char data
**
**  Dependencies: None
**
** ========================================================================= */
boolean HAL_tsens_UseRedundant(void)
{
   return FALSE;
}

/* ============================================================================
**
**  HAL_tsens_CalSelect
**
**  Description:
**    Determines whether there is 1) no cal data 2) single point cal data or
**    3) two point cal data
**
**  Parameters:
**    bUseRedundant - whether or not to use the redundant location
**
**  Return: HAL_tsens_Calibration (not calibrated, one point, or two point)
**
**  Dependencies: None
**
** ========================================================================= */
HAL_tsens_Calibration HAL_tsens_CalSelect(boolean bUseRedundant)
{
   /* TSENS_CAL_SEL
    * 0: not calibrated
    * 1: slope & offset truncated 3 bits (1 offset bit == 8 codes)
    * 2: offset
    * 3: slope & offset
    * 4: slope & offset (SW compatible with method 3)
    * 5: new method (treated as uncalibrated until defined)
    * 6: slope & offset truncated 1 bit (1 offset bit == 2 codes)
    * 7: new method (treated as uncalibrated until defined)
    */
   if (!bUseRedundant)
   {
      switch (HWIO_INF(QFPROM_CORR_CALIB_ROW5_MSB, TSENS_CAL_SEL))
      {
         case 1:
            return HAL_TSENS_CAL_SLOPE_OFFSET_TRUNCATED_3;
         case 2:
            return HAL_TSENS_CAL_OFFSET;
         case 3:
            return HAL_TSENS_CAL_OFFSET_SLOPE;
         case 4:
            return HAL_TSENS_CAL_OFFSET_SLOPE;
         case 6:
            return HAL_TSENS_CAL_SLOPE_OFFSET_TRUNCATED_1;
         default:
            return HAL_TSENS_CAL_NOT_CALIBRATED;
      }
   }

   return HAL_TSENS_CAL_NOT_CALIBRATED;
}

/* ============================================================================
**
**  HAL_tsens_PartialGoodsEnabled
**
**  Description:
**    Determines whether or not partial goods encoding has been enabled
**
**  Parameters:
**    bUseRedundant - whether or not to use the redundant location
**
**  Return: TRUE / FALSE
**
**  Dependencies: None
**
** ========================================================================= */
boolean HAL_tsens_PartialGoodsEnabled(boolean bUseRedundant)
{
   return FALSE;
}

/* ============================================================================
**
**  HAL_tsens_GetBase1
**
**  Description:
**    Gets the Tsens base for cal point 1
**
**  Parameters:
**    bUseRedundant - whether or not to use the redundant location
**    uController - which controller
**
**  Return: adc code
**
**  Dependencies: None
**
** ========================================================================= */
uint32 HAL_tsens_GetBase1(boolean bUseRedundant, uint32 uController)
{
   if (!bUseRedundant)
   {
      switch (uController)
      {
         case 0:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_LSB, TSENS0_BASE0);
         case 1:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_LSB, TSENS1_BASE0);
         default:
            break;
      }
   }

   return 0;
}

/* ============================================================================
**
**  HAL_tsens_GetBase2
**
**  Description:
**    Gets the Tsens base for cal point 2
**
**  Parameters:
**    bUseRedundant - whether or not to use the redundant location
**    uController - which controller
**
**  Return: adc code
**
**  Dependencies: None
**
** ========================================================================= */
uint32 HAL_tsens_GetBase2(boolean bUseRedundant, uint32 uController)
{
   if (!bUseRedundant)
   {
      switch (uController)
      {
         case 0:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_LSB, TSENS0_BASE1);
         case 1:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_LSB, TSENS1_BASE1_1_0) | (HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS1_BASE1_9_2) << 2);
         default:
            break;
      }
   }

   return 0;
}

/* ============================================================================
**
**  HAL_tsens_GetOffset
**
**  Description:
**    Gets Tsens uSensor offset for cal point 1
**
**  Parameters:
**    bUseRedundant - whether or not to use the redundant location
**    uint32 uFuseIdx
**
**  Return: offset from base
**
**  Dependencies: None
**
** ========================================================================= */
uint32 HAL_tsens_GetOffset(boolean bUseRedundant, uint32 uFuseIdx)
{
   if (!bUseRedundant)
   {
      switch (uFuseIdx)
      {
         case 0:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS0_OFFSET);
         case 1:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS1_OFFSET);
         case 2:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS2_OFFSET);
         case 3:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS3_OFFSET);
         case 4:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW3_MSB, TSENS4_OFFSET_3_0) | (HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS4_OFFSET_4) << 4);
         case 5:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS5_OFFSET);
         case 6:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS6_OFFSET);
         case 7:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS7_OFFSET);
         case 8:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS8_OFFSET);
         case 9:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS9_OFFSET);
         case 10:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS10_OFFSET);
         case 11:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_LSB, TSENS11_OFFSET_0) | (HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS11_OFFSET_4_1) << 1);
         case 12:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS12_OFFSET);
         case 13:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS13_OFFSET);
         case 14:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS14_OFFSET);
         case 15:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS15_OFFSET);
         case 16:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS16_OFFSET);
         case 17:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW4_MSB, TSENS17_OFFSET_2_0) | (HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS17_OFFSET_4_3) << 3);
         case 18:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS18_OFFSET);
         case 19:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS19_OFFSET);
         case 20:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS20_OFFSET);
         case 21:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS21_OFFSET);
         case 22:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS22_OFFSET);
         case 23:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_LSB, TSENS23_OFFSET);
         case 24:
            return HWIO_INF(QFPROM_CORR_CALIB_ROW5_MSB, TSENS24_OFFSET);
         default:
            break;
      }
   }

   return 0;
}

