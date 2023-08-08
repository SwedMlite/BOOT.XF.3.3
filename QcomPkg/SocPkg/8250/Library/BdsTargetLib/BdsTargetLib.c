#include "Uefi.h"
#include <Library/BdsTargetLib.h>
#include <HALhwio.h>
#include "HALbootHWIO.h"

/**
  This function verifies if Device is external or Internal

  @retval TRUE      If Device is external
  @retval FALSE     If Device is internal

**/
/* Check if Device is external or Internal */
BOOLEAN IsDeviceExternal()
{
   /* LCM_0 register bit 5 indicates if the device is external */
   return(HWIO_LCM_0_INM(HWIO_LCM_0_QC_EXTERNAL_BMSK)>>HWIO_LCM_0_QC_EXTERNAL_SHFT);
}
