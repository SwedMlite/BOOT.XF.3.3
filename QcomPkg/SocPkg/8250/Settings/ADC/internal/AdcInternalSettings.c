/*============================================================================
  FILE:         AdcInternalSettings.c

  OVERVIEW:     Internal settings for ADC.

  DEPENDENCIES: None

                Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Confidential and Proprietary.
============================================================================*/
/*============================================================================
  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.  Please
  use ISO format for dates.

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2017-11-16  jjo  Initial version.

============================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "AdcBsp.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof((a)[0]))

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

/*
 * PM855_PM855L
 */
static const AdcPhysicalDeviceType adcPhysicalDevices_PM855_PM855L[] =
{
   {
      .pszDevName = "/vadc/pm855",
   },

   {
      .pszDevName = "/vadc/pm855l",
   },
};

const AdcBspType AdcBsp_PM855_PM855L[] =
{
   {
      .paAdcPhysicalDevices = adcPhysicalDevices_PM855_PM855L,
      .uNumDevices          = ARRAY_LENGTH(adcPhysicalDevices_PM855_PM855L)
   }
};

/*
 * PM855_PM855B_PM855L
 */
static const AdcPhysicalDeviceType adcPhysicalDevices_PM855_PM855B_PM855L[] =
{
   {
      .pszDevName = "/vadc/pm855",
   },

   {
      .pszDevName = "/vadc/pm855b",
   },

   {
      .pszDevName = "/vadc/pm855l",
   },
};

const AdcBspType AdcBsp_PM855_PM855B_PM855L[] =
{
   {
      .paAdcPhysicalDevices = adcPhysicalDevices_PM855_PM855B_PM855L,
      .uNumDevices          = ARRAY_LENGTH(adcPhysicalDevices_PM855_PM855B_PM855L)
   }
};

