#ifndef __CLOCK_H__
#define __CLOCK_H__

/*
==============================================================================

FILE: Clock.h

DESCRIPTION:
  Clock driver public interface.

==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/Include/Library/Clock.h#1 $

==============================================================================
Copyright (c) 2018-2019 QUALCOMM Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR
==============================================================================

*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockDefs.h"
#include "stdbool.h"
#include "stdint.h"


/*=========================================================================
      Top-Level Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_Attach
** =========================================================================*/
/**
  Attaches to the Clock Driver and initializes a client handle.

  It's a requirement for all clients to call this function first. The handle
  returned by this function must be passed as the first argument to all other
  interfaces.

  @param pHandle [in/out] Handle to the client.
  @param szName [in] String name of the client identifier.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Null pointer or invalid client identifier.
  CLOCK_ERROR -- Failed to create a client handle.
  CLOCK_SUCCESS -- A client handle was created.
*/
ClockResult Clock_Attach
(
  ClockHandle *pHandle,
  const char  *szName
);

/* =========================================================================
**  Function : Clock_Detach
** =========================================================================*/
/**
  Detaches from the Clock Driver and destroys the client handle.

  The handle passed to this function will be destroyed and all related context
  data will be cleaned up accordingly.

  @param hClient [in] Handle to the client.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Null pointer or invalid client identifier.
  CLOCK_ERROR -- Failed to detach or destroy the client handle.
  CLOCK_SUCCESS -- The client was detached and handle was destroyed.
*/
ClockResult Clock_Detach
(
  ClockHandle hClient
);


/*=========================================================================
      Clock Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_GetId
** =========================================================================*/
/**
  Get an ID for the specified name.

  This function looks up the specified name and returns an ID that is used as
  input to most of the other clock APIs. The ID type is common across all object
  types, so the name can be the name of a CBC, PLL, GDSC, CDIV, etc... The names
  can be found in the HW frequency plans, e.g., gcc_xo_clk, gcc_gpll0, etc...

  @param hClient [in] Handle to the client.
  @param szName [in] String name to lookup.
  @param pId [out] Pointer to the ID to be filled in.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Pointer to szName or pId is NULL.
  CLOCK_ERROR_NOT_FOUND -- Object was not found on this target.
  CLOCK_SUCCESS -- Object was found and the ID was filled in.
*/
ClockResult Clock_GetId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
);

/* =========================================================================
**  Function : Clock_Enable
** =========================================================================*/
/**
  Clock_EnableEx wrapper using default flags.
 */
#define Clock_Enable(hClient, ClockId) \
  Clock_EnableEx(hClient, ClockId, 0)

/* =========================================================================
**  Function : Clock_EnableEx
** =========================================================================*/
/**
  Enables a clock.

  This function enables a specified clock. The clock is only turned on when the
  reference count goes from 0 to 1.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to enable.
  @param nFlags [in] API-specific flags. See CLOCK_ENABLE_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_INTERNAL -- Unable to enable clock.
  CLOCK_SUCCESS -- Clock was enabled.
*/
ClockResult Clock_EnableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
);

/* =========================================================================
**  Function : Clock_Disable
** =========================================================================*/
/**
  Clock_DisableEx wrapper using default flags.
 */
#define Clock_Disable(hClient, ClockId) \
  Clock_DisableEx(hClient, ClockId, 0)

/* =========================================================================
**  Function : Clock_DisableEx
** =========================================================================*/
/**
  Disables a clock.

  This function removes the client's vote to enable a specified clock. The clock
  will only be disabled when the reference count reaches 0.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to disable.
  @param nFlags [in] API-specific flags. See CLOCK_DISABLE_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_INTERNAL -- Unable to disable clock.
  CLOCK_SUCCESS -- Call was successful (although the clock may still be enabled).
*/
ClockResult Clock_DisableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
);

/* =========================================================================
**  Function : Clock_IsEnabled
** =========================================================================*/
/**
  Checks the enabled state of a clock.

  This function checks whether a specified clock is enabled or disabled. Note
  that this is not necessarily equivalent to the clock being active. A clock may
  be disabled by the local processor, but enabled by another one. Or if the
  hardware is misconfigured the clock may be enabled, but not actively toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsEnabled [in/out] Status of check.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid parameter provided.
  CLOCK_ERROR -- Unable to determine clock status.
  CLOCK_SUCCESS -- Status returned in pbIsEnabled parameter.

  @see_also
  Clock_GetId
  Clock_IsOn
*/
ClockResult Clock_IsEnabled
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsEnabled
);

/* =========================================================================
**  Function : Clock_IsOn
** =========================================================================*/
/**
  Checks whether a clock is on.

  If the clock is on, it means the clock is not just enabled, but is actually
  toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsOn [in/out] Status of check.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid parameter provided.
  CLOCK_ERROR -- Unable to determine clock status.
  CLOCK_SUCCESS -- Status returned in pbIsOn parameter.

  @see_also
  Clock_GetId
  Clock_IsEnabled
*/
ClockResult Clock_IsOn
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsOn
);

/* =========================================================================
**  Function : Clock_SetFrequency
** =========================================================================*/
/**
  Clock_SetFrequencyEx wrapper using default flags.
 */
#define Clock_SetFrequency(hClient, ClockId, nFreq, eMatch, pnResultFreq) \
  Clock_SetFrequencyEx(hClient, ClockId, nFreq, eMatch, pnResultFreq, 0)

/* =========================================================================
**  Function : Clock_SetFrequencyEx
** =========================================================================*/
/**
  Sets the frequency of a clock.

  This function requests a frequency change for a specified clock. The driver
  selects the exact frequency based on the matching argument, which allows
  requesting a minimum or approximate frequency. There is no support for
  concurrent requests; the last request will be serviced and override any other
  minimum frequency requests.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the frequency.
  @param nFreq [in] Clock frequency in Hz, kHz, or MHz, depending on the eMatch parameter.
  @param eMatch [in] Type of match request.
  @param pnResultFreq [out] The programmed clock frequency in the same units as nFreq; can be NULL if the resulting frequency does not need to be checked. Note that the result is truncated to the units requested.
  @param nFlags [in] API-specific flags. See CLOCK_SETFREQUENCY_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid clock ID.
  CLOCK_ERROR_INTERNAL -- Unable to set clock config or invalid domain.
  CLOCK_ERROR_NOT_SUPPORTED -- A matching frequency was not found or domain config is null.
  CLOCK_SUCCESS -- Requested clock frequency was found and programmed.

  @see_also
  Clock_GetId
*/
ClockResult Clock_SetFrequencyEx
(
  ClockHandle          hClient,
  ClockIdType          ClockId,
  uint32_t             nFreq,
  ClockFrequencyType   eMatch,
  uint32_t            *pnResultFreq,
  uint32_t             nFlags
);

/* =========================================================================
**  Function : Clock_GetFrequency
** =========================================================================*/
/**
  Gets the frequency of a clock.

  This function retrieves the current frequency of a clock in Hz. This is
  independent of whether or not the clock is running. Note that only clocks
  controlled on the local processor can have the frequency retrieved.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pnFrequencyHz [out] Pointer to uint32_t to fill in with the frequency. A value of zero indicates that the frequency could not be determined.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier or frequency was invalid
  CLOCK_SUCCESS -- Clock was valid. The frequency may or may not have been retrieved (see function description).

  @see_also
  Clock_GetId
*/
ClockResult Clock_GetFrequency
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t    *pnFrequencyHz
);

/* =========================================================================
**  Function : Clock_MeasureFrequency
** =========================================================================*/
/**
  Clock_MeasureFrequencyEx wrapper using default mux selection.
 */
#define Clock_MeasureFrequency(hClient, ClockId, pnFrequencyHz) \
  Clock_MeasureFrequencyEx(hClient, ClockId, 0, pnFrequencyHz)

/* =========================================================================
**  Function : Clock_MeasureFrequencyEx
** =========================================================================*/
/**
  Measures the frequency of a clock.

  This function measures the current frequency of a clock in Hz using hardware
  counting circuits. This functionality  depends on the presence of this
  hardware support, as well as being available on the current processor. It also
  requires that the clock can be enabled, which must be possible from the
  current environment. The frequency measurement is accurate to within a few
  kHz. The measurement takes a long time (at least a few milliseconds) and is
  intended only for testing purposes, not any real modes of operation.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param nMuxSel [in] Debug mux select value to check.
  @param pnFrequencyHz [out] Pointer to uint32_t to fill in with the frequency. A value of zero indicates that the frequency could not be determined.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid, or frequency pointer was null.
  CLOCK_SUCCESS -- Clock frequency was measured successfully.

  @dependencies

  @side_effects

  @see_also
  Clock_GetId
  Clock_MeasureDebugMuxInput
  Clock_GetFrequency
*/
ClockResult Clock_MeasureFrequencyEx
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t     nMuxSel,
  uint32_t    *pnFrequencyHz
);

/* =========================================================================
**  Function : Clock_Query
** =========================================================================*/
/**
  Query information about about a clock.

  This function queries information about a clock or one of its performance
  levels.

  Note: The CLOCK_QUERY_PERF_LEVEL_* queries use the nPerfLevel argument
        to determine which performance level to query. All other query types
        ignore this argument.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to query the frequency plan.
  @param eQuery[in] Query to perform.
  @param nPerfLevel[in] Performance level index to query.
  @param pResult[out] Query result.

  @return
  CLOCK_ERROR_NOT_SUPPORTED -- Query type or performance level not supported.
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid, or pResult was NULL.
  CLOCK_SUCCESS -- Query result successfully placed in pResult.

  @see_also
  Clock_GetId
*/
ClockResult Clock_Query
(
  ClockHandle            hClient,
  ClockIdType            ClockId,
  ClockQueryType         eQuery,
  uint32_t               nPerfLevel,
  ClockQueryResultType  *pResult
);

/* =========================================================================
**  Function : Clock_ResetBlock
** =========================================================================*/
/**
  Controls the reset assertion for a clock functional group.

  This function allows resetting hardware in the functional group of the
  specified clock, also known as a 'block-level' reset. All clocks within the
  same functional group share the same reset, so the reset only needs to be
  applied to a single clock within that group. The resetting is destructive to
  the hardware and requires reconfiguration after the reset is deasserted.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the Reset state.
  @param eReset [in] Type of reset: assert, deassert, or pulse.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Clock reset was successfully applied.

  @see_also
  Clock_GetId
*/
ClockResult Clock_ResetBlock
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
);

/* =========================================================================
**  Function : Clock_Reset
** =========================================================================*/
/**
  Controls the reset assertion for a clock branch.

  This function allows resetting the hardware on the specified clock branch. The
  resetting is destructive to the hardware and requires reconfiguration after
  the reset is deasserted.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the Reset state.
  @param eReset [in] Type of reset: assert, deassert, or pulse.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Clock reset was successfully applied.

  @see_also
  Clock_GetId
*/
ClockResult Clock_Reset
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
);

/* =========================================================================
**  Function : Clock_SelectExternalSource
** =========================================================================*/
/**
  Clock_SelectExternalSourceEx wrapper using default flags.
 */
#define Clock_SelectExternalSource(hClient, ClockId, nFreqHz, nSource, nDiv2x, nM, nN, n2D) \
  Clock_SelectExternalSourceEx(hClient, ClockId, nFreqHz, nSource, nDiv2x, nM, nN, n2D, 0)

/* =========================================================================
**  Function : Clock_SelectExternalSourceEx
** =========================================================================*/
/**
  Selects an external source for a clock.

  This function selects an external source for a clock and configures the clock
  generator dividers. This is only necessary for clock domains that can be
  derived from a source outside the clock block such that
  Clock_SetFrequency() cannot be used. Note that the caller must specify
  a non-zero value for the source clock's frequency if the caller expects the
  clock driver to provide voltage scaling support.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to configure.
  @param nFreqHz [in] Source frequency in Hz. The value '0' indicates that voltage scaling is not expected for this source.
  @param nSource [in] Source to use. This value should match the MUX input on which the external source is connected. @note1 If the specified clock does not support the requested external source, this request selects the first source (in most cases XO) available to the clock.
  @param nDiv2x [in] Integer divider to use (2x the desired divider).
  @param nM [in] The M value for any M/N counter (0 to bypass). Not all clock domains have M/N counters; these values will be ignored in such cases.
  @param nN [in] The N value for any M/N counter.
  @param n2D [in] Twice the D value for any M/N counter. The raw value is doubled to allow for half-integer duty cycles.
  @param nFlags [in] API-specific flags. See CLOCK_SELECTEXTERNALSOURCE_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid clock identifier or external source.
  CLOCK_ERROR_INTERNAL -- Invalid domain.
  CLOCK_SUCCESS -- Clock was valid, and external source was selected.

  @see_also
  Clock_GetId
  Clock_SetFrequency
*/
ClockResult Clock_SelectExternalSourceEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFreqHz,
  uint32_t    nSource,
  uint32_t    nDiv2x,
  uint32_t    nM,
  uint32_t    nN,
  uint32_t    n2D,
  uint32_t    nFlags
);

/* =========================================================================
**  Function : Clock_Configure
** =========================================================================*/
/**
  Configures a clock.

  This function configures a clock based on predefined configuration modes.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param eConfig [in] Clock configuration.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_OUT_OF_RANGE_PARAMETER -- Configuration is not supported/invalid.
  CLOCK_SUCCESS -- Call was successful.

  @see_also
  Clock_GetId
*/
ClockResult Clock_Configure
(
  ClockHandle     hClient,
  ClockIdType     ClockId,
  ClockConfigType eConfig
);

/* =========================================================================
**  Function : Clock_SetClockDivider
** =========================================================================*/
/**
  Sets the divider for a clock.

  This function programs the divider for a specified clock. This functionality
  only applies to a small subset of clocks that have independent dividers off
  the main domain.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the divider.
  @param nDivider [in] Clock divider in logical units; 0 is invalid.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Requested clock ID was valid. Divider value may or may  not be correct.

  @see_also
  Clock_GetId
*/
ClockResult Clock_SetDivider
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nDivider
);

/* =========================================================================
**  Function : Clock_Invert
** =========================================================================*/
/**
  Sets the Inversion state for a clock.

  This function allows inverting or uninverting a clock. This is rarely used. It
  is generally used just to overcome timing problems in the hardware.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the divider.
  @param bInvert [in] Whether to invert the clock or not.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid Clock ID.
  CLOCK_ERROR_NOT_SUPPORTED -- Function currently not supported.
  CLOCK_SUCCESS -- Clock inversion was successfully applied.

  @see_also
  Clock_GetId
*/
ClockResult Clock_Invert
(
  ClockHandle hClient,
  ClockIdType ClockId,
  bool        bInvert
);


/*=========================================================================
      Misc Functions
==========================================================================*/

/* =========================================================================
**  Function : Clock_ProcessorSleep
** =========================================================================*/
/**
  Puts the processor in the Sleep mode.

  This function configures the processor clocks for Sleep mode and, depending on
  the environment, may execute the appropriate Stand by and Wait For Interrupt
  (SWFI) instruction.

  @param hClient [in] Handle to the client.
  @param eMode [in] Type of sleep to enter.
  @param nFlags [in] Mode-specific flags.

  @return
  CLOCK_ERROR_NOT_SUPPORTED -- Function not supported.
  CLOCK_ERROR_INTERNAL -- Error executing this function.
  CLOCK_SUCCESS -- Processor clocks configured for sleep mode.

  @dependencies

  @see_also
  Clock_ProcessorRestore
*/
ClockResult Clock_ProcessorSleep
(
  ClockHandle        hClient,
  ClockSleepModeType eMode,
  uint32_t           nFlags
);

/* =========================================================================
**  Function : Clock_ProcessorRestore
** =========================================================================*/
/**
  Restores the processor clock state after sleep.

  This function restores the processor clocks after a power collapse.

  @param hClient [in] Handle to the client.
  @param eMode [in] Type of sleep to leave.
  @param nFlags [in] Mode-specific flags.

  @return
  CLOCK_ERROR_NOT_SUPPORTED -- Function not supported.
  CLOCK_ERROR_INTERNAL -- Error executing this function.
  CLOCK_SUCCESS -- Processor clocks restored.

  @dependencies

  @see_also
  Clock_ProcessorSleep
*/
ClockResult Clock_ProcessorRestore
(
  ClockHandle        hClient,
  ClockSleepModeType eMode,
  uint32_t           nFlags
);

#endif /* __CLOCK_H__ */

