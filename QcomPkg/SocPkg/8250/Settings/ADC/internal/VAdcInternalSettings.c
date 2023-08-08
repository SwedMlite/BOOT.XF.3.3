/*============================================================================
  FILE:         VAdcInternalSettings.c

  OVERVIEW:     Internal settings for VADC.

  DEPENDENCIES: None

                Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
                All Rights Reserved.
                Qualcomm Technologies Proprietary and Confidential.
============================================================================*/
/*============================================================================
  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.  Please
  use ISO format for dates.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/ADC/internal/VAdcInternalSettings.c#2 $

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2017-11-10  jjo  Initial revision.

============================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include "VAdcBsp.h"
#include "AdcInputs.h"

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
extern const VAdcChannelConfigType gVAdcChannelsPM855[];
extern const VAdcChannelConfigType gVAdcChannelsPM855B[];
extern const VAdcChannelConfigType gVAdcChannelsPM855L[];
extern const uint32 guNumVAdcChannelsPM855;
extern const uint32 guNumVAdcChannelsPM855B;
extern const uint32 guNumVAdcChannelsPM855L;

/*----------------------------------------------------------------------------
 * Static Variable Definitions
 * -------------------------------------------------------------------------*/
/*
 * This table is a mapping of ADC channels to GPIO inputs.
 */
static const uint8 aucAmux1GpioChans[] = {0x12, 0x32, 0x52, 0x72};
static const uint8 aucAmux2GpioChans[] = {0x13, 0x33, 0x53, 0x73};
static const uint8 aucAmux3GpioChans[] = {0x14, 0x34, 0x54, 0x74, 0x94};
static const uint8 aucAmux4GpioChans[] = {0x15, 0x35, 0x55, 0x75, 0x95};

/*----------------------------------------------------------------------------
 * PM855 Settings
 * -------------------------------------------------------------------------*/
static const VAdcGpioChannelMappingType vAdcGpioChannelMappingsPM855[] =
{
   {
      .paucChannels = aucAmux1GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux1GpioChans),
      .eGpio        = PM_GPIO_3,
   },

   {
      .paucChannels = aucAmux2GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux2GpioChans),
      .eGpio        = PM_GPIO_4,
   },

   {
      .paucChannels = aucAmux3GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux3GpioChans),
      .eGpio        = PM_GPIO_5,
   },

   {
      .paucChannels = aucAmux4GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux4GpioChans),
      .eGpio        = PM_GPIO_2,    /* Driver remaps to PM_GPIO_6 for < rev 3.0 */
   },
};

const VAdcBspType VAdcBspPM855[] =
{
   {
      .paChannels              = gVAdcChannelsPM855,
      .puNumChannels           = &guNumVAdcChannelsPM855,
      .paAveragedChannels      = NULL,
      .puNumAveragedChannels   = NULL,
      .paGpioChannelMappings   = vAdcGpioChannelMappingsPM855,
      .uNumGpioChannelMappings = ARRAY_LENGTH(vAdcGpioChannelMappingsPM855),
      .bUsesInterrupts         = FALSE,
      .uFullScale_code         = 0x70E4,
      .uFullScale_uV           = 1875000,
      .uReadTimeout_us         = 500000,
      .uLDOSettlingTime_us     = 67,
      .uSlaveId                = 0,
      .uPeripheralId           = 0x31,
      .uMasterID               = 0,
      .eAccessPriority         = SPMI_BUS_ACCESS_PRIORITY_LOW,
      .ucPmicDevice            = 0,
   }
};

/*----------------------------------------------------------------------------
 * PM855B Settings
 * -------------------------------------------------------------------------*/
static const uint8 aucAmuxThm4GpioChans[] = {0x10, 0x30, 0x50, 0x70};

static const VAdcGpioChannelMappingType vAdcGpioChannelMappingsPM855B[] =
{
   {
      .paucChannels = aucAmuxThm4GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmuxThm4GpioChans),
      .eGpio        = PM_GPIO_1,
   },

   {
      .paucChannels = aucAmux1GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux1GpioChans),
      .eGpio        = PM_GPIO_11,
   },

   {
      .paucChannels = aucAmux2GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux2GpioChans),
      .eGpio        = PM_GPIO_12,
   },

   {
      .paucChannels = aucAmux3GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux3GpioChans),
      .eGpio        = PM_GPIO_7,
   },

   {
      .paucChannels = aucAmux4GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux4GpioChans),
      .eGpio        = PM_GPIO_8,
   },
};

const VAdcBspType VAdcBspPM855B[] =
{
   {
      .paChannels              = gVAdcChannelsPM855B,
      .puNumChannels           = &guNumVAdcChannelsPM855B,
      .paAveragedChannels      = NULL,
      .puNumAveragedChannels   = NULL,
      .paGpioChannelMappings   = vAdcGpioChannelMappingsPM855B,
      .uNumGpioChannelMappings = ARRAY_LENGTH(vAdcGpioChannelMappingsPM855B),
      .bUsesInterrupts         = FALSE,
      .uFullScale_code         = 0x70E4,
      .uFullScale_uV           = 1875000,
      .uReadTimeout_us         = 500000,
      .uLDOSettlingTime_us     = 67,
      .uSlaveId                = 2,
      .uPeripheralId           = 0x31,
      .uMasterID               = 0,
      .eAccessPriority         = SPMI_BUS_ACCESS_PRIORITY_LOW,
      .ucPmicDevice            = 1,
   }
};

/*----------------------------------------------------------------------------
 * PM855L Settings
 * -------------------------------------------------------------------------*/
static const VAdcGpioChannelMappingType vAdcGpioChannelMappingsPM855L[] =
{
   {
      .paucChannels = aucAmux1GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux1GpioChans),
      .eGpio        = PM_GPIO_5,
   },

   {
      .paucChannels = aucAmux2GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux2GpioChans),
      .eGpio        = PM_GPIO_6,
   },

   {
      .paucChannels = aucAmux3GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux3GpioChans),
      .eGpio        = PM_GPIO_7,
   },

   {
      .paucChannels = aucAmux4GpioChans,
      .uNumChannels = ARRAY_LENGTH(aucAmux4GpioChans),
      .eGpio        = PM_GPIO_10,
   },
};

const VAdcBspType VAdcBspPM855L[] =
{
   {
      .paChannels              = gVAdcChannelsPM855L,
      .puNumChannels           = &guNumVAdcChannelsPM855L,
      .paAveragedChannels      = NULL,
      .puNumAveragedChannels   = NULL,
      .paGpioChannelMappings   = vAdcGpioChannelMappingsPM855L,
      .uNumGpioChannelMappings = ARRAY_LENGTH(vAdcGpioChannelMappingsPM855L),
      .bUsesInterrupts         = FALSE,
      .uFullScale_code         = 0x70E4,
      .uFullScale_uV           = 1875000,
      .uReadTimeout_us         = 500000,
      .uLDOSettlingTime_us     = 67,
      .uSlaveId                = 4,
      .uPeripheralId           = 0x31,
      .uMasterID               = 0,
      .eAccessPriority         = SPMI_BUS_ACCESS_PRIORITY_LOW,
      .ucPmicDevice            = 2,
   }
};

