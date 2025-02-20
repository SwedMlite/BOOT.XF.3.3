/** @file ClockDxe.c

  This file implements clock EFI protocol interface.
  Copyright (c) 2017 - 2019 Qualcomm Technologies, Inc. All rights reserved.

**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 01/08/18   op      Update Clock Register Exit Boot Service Callback
 03/14/17   op      Add Dump Clock's state
 10/18/14   jb      Added DAL initialization
 05/01/14   asmitp  Renamed header file DALSYSProtocol.h to EFIDALSYSProtocol.h
 12/23/10   vs      Created.

=============================================================================*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Protocol/EFIDALSYSProtocol.h>
#include <Protocol/EFIClock.h>
#include "DALDeviceId.h"
#include "DDIClock.h"
#include <api/systemdrivers/icbarb.h>
#include <Library/QcomTargetLib.h>
#include <Library/QcomLib.h>

/*=========================================================================
      Type Definitions
==========================================================================*/


/*=========================================================================
      Function Prototypes
==========================================================================*/

EFI_STATUS EFI_GetClockID(IN EFI_CLOCK_PROTOCOL *This,
                          IN CONST CHAR8 *ClockName, OUT UINTN *ClockId);
EFI_STATUS EFI_EnableClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId);
EFI_STATUS EFI_DisableClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId);
EFI_STATUS EFI_IsClockEnabled(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              OUT BOOLEAN *IsEnabled);
EFI_STATUS EFI_IsClockOn(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                         OUT BOOLEAN *IsOn);
EFI_STATUS EFI_SetClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              IN UINT32 FreqHz,
                              IN EFI_CLOCK_FREQUENCY_TYPE  Match,
                              OUT UINT32 *ResultFreqHz);
EFI_STATUS EFI_GetClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                              OUT UINT32 *FreqHz);
EFI_STATUS EFI_CalcClockFreqHz(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                               OUT UINT32 *FreqHz);
EFI_STATUS EFI_SelectExternalSource(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                                    IN UINT32 FreqHz, IN UINT32 Source,
                                    IN UINT32 Divider, IN UINT32 VAL_M,
                                    IN UINT32 VAL_N, IN UINT32 VAL_2D);
EFI_STATUS EFI_GetClockPowerDomainID(IN EFI_CLOCK_PROTOCOL *This,
                                     IN CONST CHAR8 *ClockPowerDomainName,
                                     OUT UINTN *ClockPowerDomainId);
EFI_STATUS EFI_EnableClockPowerDomain(IN EFI_CLOCK_PROTOCOL *This,
                                      IN UINTN ClockPowerDomainId);
EFI_STATUS EFI_DisableClockPowerDomain(IN EFI_CLOCK_PROTOCOL *This,
                                       IN UINTN ClockPowerDomainId);
EFI_STATUS EFI_EnterLowPowerMode(IN EFI_CLOCK_PROTOCOL *This);
EFI_STATUS EFI_ExitLowPowerMode(IN EFI_CLOCK_PROTOCOL *This);
EFI_STATUS EFI_SetClockDivider(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                               IN UINT32 Divider);
EFI_STATUS EFI_ResetClock(IN EFI_CLOCK_PROTOCOL *This, IN UINTN ClockId,
                          IN EFI_CLOCK_RESET_TYPE eReset);

EFI_STATUS EFI_GetMaxPerfLevel(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU, OUT UINT32 *pnPerfLevel);
EFI_STATUS EFI_GetMinPerfLevel(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU, OUT UINT32 *pnPerfLevel);
EFI_STATUS EFI_GetCpuPerfLevelFrequency(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU,
                                        IN UINT32 nPerfLevel, OUT UINT32 *pnFrequencyHz,
                                        OUT UINT32 *pnRequiredVoltage);
EFI_STATUS EFI_SetCpuPerfLevel(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU,
                               IN UINT32 nPerfLevel, OUT UINT32 *pnFrequencyHz);
EFI_STATUS EFI_GetCpuPerfLevel(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU, OUT UINT32 *pnPerfLevel);
EFI_STATUS EFI_GetCPUFrequencyLevels(IN  EFI_CLOCK_PROTOCOL *This, IN  UINT32 nCPU,
                                        OUT UINT32 *pnFrequencyLevels);
EFI_STATUS EFI_GetCPUFrequencyPlan(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU,
                                      IN EFI_CLOCK_FREQ_PLAN_TYPE  *pCPUFreqPlan, IN UINT32 nSize);
EFI_STATUS EFI_SetCPUFrequency(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU, IN UINT32 nFrequencyHz, OUT UINT32 *pnResultFreqHz);
EFI_STATUS EFI_GetCPUFrequency(IN EFI_CLOCK_PROTOCOL *This, IN UINT32 nCPU, OUT UINT32 *pnFrequencyHz);

EFI_STATUS EFI_LogClocksState(IN EFI_TEST_CLOCK_PROTOCOL *This, IN UINT32 nFlag);

EFI_STATUS EFI_DumpClocksState(IN EFI_TEST_CLOCK_PROTOCOL *This, IN UINT32 nFlag);


/*=========================================================================
      Data Declarations
==========================================================================*/

// Clock Public Protocol
static EFI_CLOCK_PROTOCOL ClockProtocol =
{
   EFI_CLOCK_PROTOCOL_VERSION,
   EFI_GetClockID,
   EFI_EnableClock,
   EFI_DisableClock,
   EFI_IsClockEnabled,
   EFI_IsClockOn,
   EFI_SetClockFreqHz,
   EFI_GetClockFreqHz,
   EFI_CalcClockFreqHz,
   EFI_SelectExternalSource,
   EFI_GetClockPowerDomainID,
   EFI_EnableClockPowerDomain,
   EFI_DisableClockPowerDomain,
   EFI_EnterLowPowerMode,
   EFI_ExitLowPowerMode,
   EFI_SetClockDivider,
   EFI_ResetClock,
   EFI_GetMaxPerfLevel,
   EFI_GetMinPerfLevel,
   EFI_GetCpuPerfLevelFrequency,
   EFI_SetCpuPerfLevel,
   EFI_GetCpuPerfLevel,
 };


// Clock Public Protocol
static EFI_TEST_CLOCK_PROTOCOL TestClockProtocol =
{
   EFI_TEST_CLOCK_PROTOCOL_VERSION,
   EFI_LogClocksState,
   EFI_DumpClocksState
};

static DalDeviceHandle *hClock = NULL;

DALProps gDALModStringDeviceInfoList = {NULL, 0 ,0 , NULL};

/*==============================================================================

                     GLOBAL VARIABLES FOR THIS MODULE

==============================================================================*/
extern DALREG_DriverInfo DALClock_DriverInfo;

static DALREG_DriverInfo * DALDriverInfoArr[1] = { &DALClock_DriverInfo };

static DALSYSConfig DALSYSModConfig =
   {
      {0, NULL},              // string device info
      {1, DALDriverInfoArr}   // numeric driver info
   };

/* Exit Boot Services vars */
extern EFI_GUID gEfiEventExitBootServicesGuid;

EFI_EVENT  ClockExitBSEvent             = (EFI_EVENT)NULL;

VOID      *VarProtocolNotificationToken =  NULL;
EFI_EVENT  VarProtocolNotificationEvent = (EFI_EVENT) NULL;
/*=========================================================================
      Functions
==========================================================================*/


/**
  Looks-up a clock id given a clock name.

  This function takes the name of a clock, and will return a handle that
  can be used for making requests on that clock.  This function will generally
  need to be the first to be invoked prior to using any other clock APIs.
  The string name of the clock can be found in the clock chapter of the
  chip HLD.  For example, "cc_uart2_clk".

  @param  This      [in]        The EFI_CLOCK_PROTOCOL instance.
  @param  ClockName [in]        String name of the clock.
  @param  ClockId   [out]       Pointer to fill in with the clock id.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockID(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  CONST CHAR8        *ClockName,
   OUT UINTN              *ClockId)
{
  return EFI_SUCCESS;
}


/**
  Enables a clock.

  This function will enable the given clock.  It does not reference count
  recursive calls, but does do tracking between multiple clients.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to enable.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_EnableClock(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockId)
{
  return EFI_SUCCESS;
}


/**
  Disables a clock.

  This function will remove the client's vote to enable the given clock.
  There is no support for reference counting recursive calls, however the
  driver will not disable the clock if a different client has made an
  "enable" request.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to disable.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_DisableClock(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockId)
{
  return EFI_SUCCESS;
}


/**
  Check the enabled state of a clock.

  This function checks if the given clock is enabled or disabled.  Note
  that this is not necessarily equivalent to the clock being active.  A
  clock may be disabled by the local processor, but enabled by another one.
  Or if the hardware is misconfigured the clock may be enabled, but not
  actively toggling.

  @param  This      [in]        The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId   [in]        Clock to check.
  @param  IsEnabled [out]       Return 1 if clock is enabled, 0 otherwise.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_IsClockEnabled(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT BOOLEAN            *IsEnabled)
{

  return EFI_SUCCESS;
}


/**
  Check if a clock is on or not.

  This function checks if the given clock is on or not.  "On"
  means the clock is not just enabled, but is actually toggling.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  IsOn     [out]        Return 1 if clock is ON, 0 otherwise.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_IsClockOn(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT BOOLEAN            *IsOn)
{

  return EFI_SUCCESS;
}


/**
  Sets the frequency of a clock.

  This function will request a frequency change for the given clock.  The
  driver will select the exact frequency based on the matching argument,
  which allows requesting a minimum or approximate frequency for
  example. There is no support for concurrent requests - the
  last request will be serviced and override any other minimum
  frequency requests.

  @param  This         [in]     The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId      [in]     Clock to set frequency of.
  @param  Freq         [in]     Clock frequency
  @param  Match        [in]     Type of match request:
                                0 - Frequency is a minimum allowed
                                1 - Frequency is a maximum allowed
                                2 - Closest match
                                3 - Exact match only
  @param  ResultFreq   [out]    The programmed clock frequency,
                                can be NULL if resulting
                                frequency does not need to be
                                checked.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_SetClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL        *This,
   IN  UINTN                     ClockId,
   IN  UINT32                    Freq,
   IN  EFI_CLOCK_FREQUENCY_TYPE  Match,
   OUT UINT32                   *ResultFreq)
{

  return EFI_SUCCESS;
}


/**
  Get the frequency of a clock.

  This function retrieves the current frequency of a clock in Hertz.  This
  is independent of if the clock is running or not.  Note only clocks
  controlled on the local processor can have the frequency retrieved.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [out]        Pointer to uint32 to fill
                                in with the frequency. A value
                                of zero indicates the frequency
                                could not be determined.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT UINT32             *FreqHz)
{

  return EFI_SUCCESS;
}


/**
  Calculate the frequency of a clock.

  This function calculates the current frequency of a clock in Hertz using
  hardware counting circuits.  This functionality depends on this hardware
  support being present, as well as available on the current processor.  It
  also requires that the clock be enabled, which must be possible from
  the current environment.
  The frequency calculation is accurrate to within a few KHz.
  The calculation takes a long time (at least a few milliseconds) and
  is intended only for testing purposes, not any real modes of operation.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [out]        Pointer to uint32 to fill
                                in with the frequency. A value
                                of zero indicates the frequency
                                could not be determined.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_CalcClockFreqHz(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  UINTN              ClockId,
   OUT UINT32             *FreqHz)
{

  return EFI_SUCCESS;
}


/**
  Select an external source for a clock.

  This function will select an external source for a clock, and configure
  the clock generator dividers.  This is only necessary for clock domains
  that can be derived from a source outside of the clock block such that
  EFI_SetClockFreqHz cannot be used.
  Note that the caller must specify a non-zero value for the source clock's
  frequency if the caller expects the clock driver to provide voltage scaling
  support.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId  [in]         Clock to check.
  @param  FreqHz   [in]         Source frequency in Hz. The value '0' indicates that
                                voltage scaling is not expected for this source.
  @param  Source   [in]         Source to use.  Pass the following values:
                                0 - to select the first (or only) external source.
                                1 - to select the second external source.
                                2 - etc.
  @param  Divider  [in]         The integer divider to use.
  @param  VAL_M    [in]         The "M" value for any M/N counter (0 to bypass).
                                Not all clock domains have M/N counters,and these values
                                will be ignored.
  @param  VAL_N    [in]         The "N" value for any M/N counter.
  @param  VAL_2D   [in]         Twice the "D" value for any M/N counter.
                                The raw value is doubled to allow for
                                half-integer duty cycles.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_SelectExternalSource(
    IN EFI_CLOCK_PROTOCOL *This,
    IN UINTN              ClockId,
    IN UINT32             FreqHz,
    IN UINT32             Source,
    IN UINT32             Divider,
    IN UINT32             VAL_M,
    IN UINT32             VAL_N,
    IN UINT32             VAL_2D)
{
  return EFI_SUCCESS;
}


/**
  Looks up a Power Domain ID for a specified power domain name.

  This function takes the name of a power domain and returns a handle that
  can be used for making requests on that power domain. Usually, this function
  must be the first to be invoked prior to using any other power domain functions.
  The string name of the clock can be found in the software frequency
  plan, e.g., VDD_GRP.

  @param[in]  This                   Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]  ClockPowerDomainName   String name of the power domain.
  @param[out] ClockPowerDomainId     Pointer where to fill in the power domain ID.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_GetClockPowerDomainID(
   IN  EFI_CLOCK_PROTOCOL *This,
   IN  CONST CHAR8        *ClockPowerDomainName,
   OUT UINTN              *ClockPowerDomainId)
{
  return EFI_SUCCESS;
}


/**
  Enables a specified power domain.

  @param  This               [in]    The EFI_CLOCK_PROTOCOL instance.
  @param  ClockPowerDomainId [in]    Power Domain to enable.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_EnableClockPowerDomain(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockPowerDomainId)
{
  return EFI_SUCCESS;
}


/**
  Disables a power domain.

  @param  This               [in]    The EFI_CLOCK_PROTOCOL instance.
  @param  ClockPowerDomainId [in]    Power Domain to disable.

  @return EFI_SUCCESS                The function completed successfully.
  @return EFI_PROTOCOL_ERROR         The function had a protocol error.
**/

EFI_STATUS
EFI_DisableClockPowerDomain(
   IN EFI_CLOCK_PROTOCOL *This,
   IN UINTN              ClockPowerDomainId)
{
  return EFI_SUCCESS;
}


/**
  Enter the low power mode.

  This function is used to enter a low power state that facilitates
  rapid battery charging.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_EnterLowPowerMode(
    IN EFI_CLOCK_PROTOCOL *This)
{
  return EFI_SUCCESS;
}


/**
  Exit the low power mode.

  This function restores the state of the SoC to the state it was in before
  it entered a low power state that facilitates rapid battery charging.

  @param  This     [in]         The EFI_CLOCK_PROTOCOL instance.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
*/

EFI_STATUS
EFI_ExitLowPowerMode(
    IN EFI_CLOCK_PROTOCOL *This)
{
  return EFI_SUCCESS;
}


/**
  Sets the divider for a clock.

  This function programs the divider for a specified clock. This
  functionality only applies to a small subset of clocks that have
  independent dividers off the main domain.

  @param  This         [in]     The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId      [in]     Clock to set divider of.
  @param  Divider      [in]     Clock divider.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_SetClockDivider(
   IN  EFI_CLOCK_PROTOCOL        *This,
   IN  UINTN                     ClockId,
   IN  UINT32                    Divider)
{

  return EFI_SUCCESS;
}


/**
  Resets a specified clock's hardware.

  This function allows resetting the hardware in a specified clock domain. The
  resetting is destructive to the hardware and requires reconfiguration
  after the reset is deasserted.

  @param  This    [in]          The EFI_CLOCK_PROTOCOL instance.
  @param  ClockId [in]          Clock to reset.
  @param  eReset  [in]          Type of reset: assert, deassert, or pulse.

  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_ResetClock(
   IN EFI_CLOCK_PROTOCOL   *This,
   IN UINTN                 ClockId,
   IN EFI_CLOCK_RESET_TYPE  eReset)
{
  return EFI_SUCCESS;
}

/**
  Returns the maximum perf level supported for the given CPU Core or Cluster.

  @param[in]   This               Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU               CPU Core or Cluster ID
  @param[out]  pnPerfLevel        Pointer to the UINT32 to be filled
                                  in with the maximum perf level supported
                                  for this Core or Cluster.
  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetMaxPerfLevel(
  IN  EFI_CLOCK_PROTOCOL *This,
  IN  UINT32              nCPU,
  OUT UINT32             *pnPerfLevel)
{
  return EFI_SUCCESS;
}

/**
  Returns the minimum perf level supported for the given CPU Core or Cluster.

  @param[in]   This               Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU               CPU Core or Cluster ID
  @param[out]  pnPerfLevel        Pointer to the UINT32 to be filled
                                  in with the minimum perf level supported
                                  for this Core or Cluster.
  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetMinPerfLevel(
   IN  EFI_CLOCK_PROTOCOL *This,
  IN  UINT32              nCPU,
  OUT UINT32             *pnPerfLevel)
{
  return EFI_SUCCESS;
}

/**
  Returns the frequency and voltage associated with the given perf level for
  the given CPU Core or Cluster.

  @param[in]   This               Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU               CPU Core or Cluster ID
  @param[in]   nPerfLevel         Perf Level under query.
  @param[out]  pnFrequencyHz      Pointer to the associated frequency.
  @param[out]  pnRequiredVoltage  Pointer to the associated voltage.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetCpuPerfLevelFrequency(
  IN  EFI_CLOCK_PROTOCOL *This,
  IN  UINT32              nCPU,
  IN  UINT32              nPerfLevel,
  OUT UINT32             *pnFrequencyHz,
  OUT UINT32             *pnRequiredVoltage)
{
  return EFI_SUCCESS;
}

/**
  Sets the desired perf level for the given CPU Core or Cluster.

  @param[in]   This               Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU               CPU Core or Cluster ID
  @param[in]   nPerfLevel         Desired Perf Level.
  @param[out]  pnFrequencyHz      Pointer to the actual frequency achieved.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_SetCpuPerfLevel(
  IN  EFI_CLOCK_PROTOCOL  *This,
  IN  UINT32              nCPU,
  IN  UINT32              nPerfLevel,
  OUT UINT32             *pnFrequencyHz)
{
  return EFI_SUCCESS;
}

/**
  Gets the current perf level of the given CPU Core or Cluster.

  @param[in]   This               Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU               CPU Core or Cluster ID
  @param[out]  pnPerfLevel        Pointer to the current Perf Level.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetCpuPerfLevel(
  IN  EFI_CLOCK_PROTOCOL  *This,
  IN  UINT32              nCPU,
  OUT UINT32             *pnPerfLevel)
{
  return EFI_SUCCESS;
}

/**
  Gets the number of frequency levels available for the given CPU Core or Cluster.

  @param[in]   This                 Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU                 CPU Core or Cluster ID
  @param[out]  pnFrequencyLevels    Pointer to the number of frequency levels.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetCPUFrequencyLevels(
  IN  EFI_CLOCK_PROTOCOL      *This,
  IN  UINT32              nCPU,
  OUT UINT32             *pnFrequencyLevels)
{
  return EFI_SUCCESS;
}

/** 
  Dumps the frequency plan for the specified CPU in the Table passed as pointer.

  @param[in]   This                 Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU                 CPU Core or Cluster ID
  @param[in]   pCPUFreqPlan         Pointer to the table storing the frequency plan.
  @param[in]   nSize                Size of the Frequency plan table, expected value to be: (No. of Perf Levels * sizeof(ClockFreqPlanType))

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetCPUFrequencyPlan(
  IN  EFI_CLOCK_PROTOCOL        *This,
  IN  UINT32                    nCPU,
  IN  EFI_CLOCK_FREQ_PLAN_TYPE  *pCPUFreqPlan,
  IN  UINT32                    nSize)
{
  return EFI_SUCCESS;
}



/** 
  Changes the processor clock speed and voltage.
  
  @param[in]   This                 Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU                 CPU Core or Cluster ID
  @param[in]   nFrequencyHz         User requested frequency
  @param[out]  pnResultFreqHz       Pointer to the actual frequency achieved.(It is an optional parameter)

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/


EFI_STATUS
EFI_SetCPUFrequency(
  IN  EFI_CLOCK_PROTOCOL  *This,
  IN  UINT32              nCPU,
  IN  UINT32              nFrequencyHz,
  OUT UINT32              *pnResultFreqHz)
{
  return EFI_SUCCESS;
}


/**
  Gets the current clock speed in Hz of the given processor.

  @param[in]   This                 Pointer to the EFI_CLOCK_PROTOCOL instance.
  @param[in]   nCPU                 CPU Core or Cluster ID
  @param[out]  pnFrequencyHz        Pointer to the actual frequency achieved.

  @return
  EFI_SUCCESS        -- Function completed successfully. \n
  EFI_PROTOCOL_ERROR -- Error occurred during the operation.
*/

EFI_STATUS
EFI_GetCPUFrequency(
  IN  EFI_CLOCK_PROTOCOL  *This,
  IN  UINT32              nCPU,
  OUT UINT32              *pnFrequencyHz)
{
  return EFI_SUCCESS;
}


/**
  EFI_LogClocksState

  Read BDSClockLogState in EFI_VARIABLE_NON_VOLATILE. Based on the current BDSClockLogState setting, whether or not
  the clocks states will be dumpped

    @param  This      [in]  The EFI_TEST_CLOCK_PROTOCOL instance.
    @param nLogMask   [in]  used to select clock Characteristic to be dumpped
                            0                               : not dump the Clock frequency
                            CLOCK_LOG_STATE_CLOCK_FREQUENCY : dump the Clock frequency
  @return
  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_LogClocksState(
   IN  EFI_TEST_CLOCK_PROTOCOL *This,
   IN  UINT32                   nLogMask)
{

  return EFI_SUCCESS;
}

/**
  EFI_DumpClocksState

  Read BDSClockLogState in ESB menu. Based on the current BDSClockLogState setting, whether or not
  the clocks states will be dumpped

    @param  This      [in]  The EFI_TEST_CLOCK_PROTOCOL instance.
    @param nLogMask   [in]  used to select clock Characteristic to be dumpped
                            0                               : not dump the Clock frequency
                            CLOCK_LOG_STATE_CLOCK_FREQUENCY : dump the Clock frequency
  @return
  @return EFI_SUCCESS           The function completed successfully.
  @return EFI_PROTOCOL_ERROR    The function had a protocol error.
**/

EFI_STATUS
EFI_DumpClocksState(
   IN  EFI_TEST_CLOCK_PROTOCOL *This,
   IN  UINT32                   nLogMask)
{

  return EFI_SUCCESS;
}
/**
 * <!-- Exit Boot service CB -->
 *
 * @brief Call Clock destructor
 *
 * @return       VOID
 */
VOID
EFIAPI
ClockRegisterExitBSCallback (
  IN EFI_EVENT        Event,
  IN VOID             *Context)
{
  
}

/**
  VarProtocolInstalledNotification()

  @brief
  Notify  when the variable installed
**/
VOID EFIAPI VarProtocolInstalledNotification
(
  IN EFI_EVENT Event,
  IN VOID     *Context
)
{
  
}

/**
  ClockBDSmenuInit

  @brief
  Init Clock BDS menu
**/

VOID EFIAPI ClockBDSmenuInit(void)
{
  
}


/**
  Clock DXE driver entry point.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/

EFI_STATUS
EFIAPI
ClockDxeEntryPoint (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_HANDLE  handle = NULL;
  EFI_STATUS  status;
  DALResult   eResult;

  // Init DALSys
  DALSYS_InitMod(&DALSYSModConfig);

  /*Init IcbArb which needs to happen after NPA/CMDDB/RPMh drivers are initialized */
  icbarb_init();

  //Attach to the clock DAL
  eResult = DAL_DeviceAttach(DALDEVICEID_CLOCK, &hClock);
  if(eResult == DAL_SUCCESS)
  {
   if (!RETAIL)
     {
       ClockBDSmenuInit();

       // Publish the DALSYS Protocol
       status = gBS->InstallMultipleProtocolInterfaces(
                    &handle,
                    &gEfiClockProtocolGuid,
                    (void **)&ClockProtocol,
                    &gEfiTestClockProtocolGuid,
                    (void **)&TestClockProtocol,
                     NULL );
    }
    else
    {
      // Publish the DALSYS Protocol
       status = gBS->InstallMultipleProtocolInterfaces(
                    &handle,
                    &gEfiClockProtocolGuid,
                    (void **)&ClockProtocol,
                     NULL );
    }
  }
  else
  {
    DALSYS_DeInitMod();
    status = EFI_PROTOCOL_ERROR;
  }

  return status;
}

