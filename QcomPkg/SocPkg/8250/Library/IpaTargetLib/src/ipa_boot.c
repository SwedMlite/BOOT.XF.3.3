/*==============================================================================

IPA_BOOT.C

DESCRIPTION
This file contains the IPA HW boot related implementation

Copyright (c) 2019 Qualcomm Technologies Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary
==============================================================================*/

/*==============================================================================

INCLUDE FILES FOR MODULE  

==============================================================================*/


#include "msmhwiobase.h"
#include "ipa_msmhwio.h"
#include "ipa_hwio.h"
#include "com_dtypes.h"

#include "ipa_boot.h"


/*==============================================================================
FUNCTION ipa_boot_init()

DESCRIPTION
This function does the minimal configuration to power on IPA for RAM dump 
collection.

PARAMETERS
none

RETURN VALUE
none

DEPENDENCIES  
This is called only after IPA is clocked. Caller should ensure that this
precondition is met.

SIDE EFFECTS
None

==============================================================================*/
void ipa_boot_init(void)
{
  // Enable isochronous clock double frequency to MCS.
  uint32 double_mcs_clk_val = HWIO_IPA_0_GSI_TOP_GSI_CFG_IN;
  double_mcs_clk_val |= HWIO_IPA_0_GSI_TOP_GSI_CFG_DOUBLE_MCS_CLK_FREQ_BMSK;
  HWIO_IPA_0_GSI_TOP_GSI_CFG_OUT(double_mcs_clk_val);
}
