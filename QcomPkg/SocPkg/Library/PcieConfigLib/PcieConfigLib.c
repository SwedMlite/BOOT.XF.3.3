/** @file PcieConfigLib.c

  PCIe Init Driver File.

  Copyright (c) 2014-2018, Qualcomm Technologies Inc. All rights reserved.

**/


/*=============================================================================
                              EDIT HISTORY


 when       who      what, where, why
 --------   ---      ----------------------------------------------------------
 07/16/18   ts       Supporting PCIe LPM mode for off mode charging
 05/16/18   ts       Deferred L1ss config to a 100 ms timer callback
 11/15/17   ts       called SMMU Config from PcieConfigLibEnableRootports
 05/22/17   ts       Fixed UpdatePortInfo function for possible memory
                     corruption
 05/05/17   ts       Updated the global port info structure to take in account
                     the removed ports
 07/28/16   ts       Register for a callback to update AML variable on PCIe link
                     state and powered down port PHY in case of link training
                     failure
 07/28/16   ts       Included I/O port access support and removed Address
                     resource configuration for End points
 07/15/16   ts       Formatted strings to %a in debug prints and Implemented
                     PcieConfigLibUpdatePortInfo to update global port info
                     and as well as disable clocks and LDOs(if necessary)
 07/08/16   ts       Renamed file to PcieConfigLib.c & made changes to init
                     root ports one by one
 06/08/16   ts       merged the PERST and link training in one function
 02/08/16   ts       Added pcie xml config support
 01/11/16   ts       Register for PCIe ExitBootServices callback
 06/15/15   ts       Simplified PCIeConfigLibRead_Config function.
                     Calling setup L1ss after iATU setup.
 05/13/15   ts       Unified code for multi platforms
 03/18/15   ts       Fixed Copyrights header
 03/16/15   ts       Added warning messages and split PHY code
                     into common and port
 01/26/15   ts       Updated the code as per 8994 changes
 10/07/14   ah       Changes for 8996
 06/16/14   hk       Add PcieInit protocol
 05/07/14   hk       Turn on PCie during exitbootservices
 04/18/14   hk       First checkin for 8994
=============================================================================*/

#include "PcieLink.h"
#include "DDIChipInfo.h"
#include <Protocol/EFIPlatformInfo.h>
#include <Protocol/EFIChipInfo.h>
#include <Protocol/EFIClock.h>
#include <Protocol/EFIChargerEx.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/IoLib.h>
#include <Library/IoLib.h>
#include <Library/PcieConfigLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>

#include "DALSys.h"
#include "PcieBsp.h"

/*
 * PCIe BSP context stored and passed from Device config
 */
STATIC CONST pcieBsp_t * gPcieBspCtx = NULL;

/*
 * Local port info structure to hold information of all
 * available root ports at any time
 */
STATIC rootPort_t root_port_info = {
  .port_info = NULL,
  .num_rp = 0
};

/***************************************************************************//**
 * @fn PcieConfigLibIsOffModeCharging
 * @brief Return the status of offMode Charging.
 *
 * Function to get off mode charging status to decide whether to initialize
 * PCIe further or to return ERROR from this point
 *
 * @param[in] EFI_CHARGER_EX_PROTOCOL * Charger Extended Protocol instance
 *
 * @retval    BOOLEAN                   return TRUE if we are off mode charging
                                        else FALSE to proceed with PCIe init.
 ******************************************************************************/
STATIC BOOLEAN PcieConfigLibIsOffModeCharging
  (
   EFI_CHARGER_EX_PROTOCOL * ChargerExProtocol
  )
{
  EFI_STATUS Status = EFI_UNSUPPORTED;
  BOOLEAN    OffModeCharging = FALSE;

  /*
   * If the Charger Ex protocol could not be located, let PCIe to
   * to proceed with initialization
   */
  if (ChargerExProtocol == NULL)
  {
    return FALSE;
  }

  /*
   * Get the status of off mode charging
   */
  Status = ChargerExProtocol->IsOffModeCharging(&OffModeCharging);
  if EFI_ERROR (Status)
  {
    /*
     * If there is any error in detecting off mode charging state,
     * Consider that as a free ticket to boot further with PCIe init
     */
    return FALSE;
  }

  /*
   * Above function call to Charger Ex protocol would have returned
   * TRUE  - its off mode charging, so don't init PCIe to save power
   * FALSE - its a regular boot, so proceed with PCIe init
   */
  return OffModeCharging;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetDevConfig
 * @brief Acquire PCIe device config information.
 *
 * Function to get the device config information and store that in a local
 * pointer to use through out the library. This function also allocated and
 * populates root_port_info global.
 *
 * @param[in] void
 *
 * @retval EFI_SUCCESS       Acquired the dev config and copied it over to
 *                           gPcieBspCtx.
 * @retval other             Appropriate error number.
 ******************************************************************************/
STATIC EFI_STATUS PcieConfigLibGetDevConfig(VOID)
{
  DALSYS_PROPERTY_HANDLE_DECLARE (hPcieBootProperties);
  CONST CHAR8                  * pcieBspPropName = "PCIE_BSP";
  DALSYSPropertyVar              propertyVar;
  portInfo_t                   * port_info = NULL;
  EFI_STATUS 			         Status;

  /* Init DAL sys */
  DALSYS_InitMod(NULL);

  Status = DALSYS_GetDALPropertyHandleStr("/core/hwengines/pcie",
                                          hPcieBootProperties);
  if (Status != DAL_SUCCESS)
  {
     return EFI_LOAD_ERROR;
  }

  /*
   * Get propertyVar from DALsys
   */
  Status = DALSYS_GetPropertyValue(hPcieBootProperties,
                                   pcieBspPropName,
                                   0,
                                   &propertyVar);
  if (Status != DAL_SUCCESS)
  {
     return EFI_LOAD_ERROR;
  }

  gPcieBspCtx = (pcieBsp_t *)propertyVar.Val.pStruct;
  if (gPcieBspCtx == NULL)
  {
    DEBUG(( EFI_D_WARN, "%a: DALConfig returned NULL\r\n", __func__));
    return EFI_LOAD_ERROR;
  }

  /*
   * Validate against zero, as AllocateCopyPool allocates buffer of zero size
   * Better fail before accessing a zero sized buffer
   */
  if (gPcieBspCtx->rp_info->num_rp == 0)
  {
    DEBUG(( EFI_D_WARN, "%a: There are no Root ports to configure\r\n",
            __func__));
    return EFI_NOT_FOUND;
  }

  /*
   * Allocate buffer to hold runtime PCIe root port information
   */
  port_info = AllocateCopyPool(sizeof(portInfo_t) * gPcieBspCtx->rp_info->num_rp,
                               (VOID *)gPcieBspCtx->rp_info->port_info);
  if (port_info == NULL)
  {
    DEBUG(( EFI_D_WARN, "%a: AllocateCopyPool failed\r\n", __func__));
    return EFI_OUT_OF_RESOURCES;
  }

  /*
   * Copy over root port info array base pointer and number of
   * root ports to global root_port_info struct, to use it throughout
   * this library.
   */
  root_port_info.port_info = port_info;
  root_port_info.num_rp = gPcieBspCtx->rp_info->num_rp;

  return EFI_SUCCESS;
}


/***************************************************************************//**
 * @fn PcieConfigLibEnableRootPorts
 * @brief Entry Point for PCIe Config Library. Enumeration starts here.
 *
 * Function to initialize the PCIe hardware for this SoC and enumerate
 * the connected EndPoints. This function should be the entry point for this
 * library, which will perform following operation in sequence;
 *
 * 1. Obtain Device config information from DALSys and store root port info
 *    in a static global variable
 * 2. Get platform info to differentiate between virtio, RUMI and Silicon
 * 3. For each root port perform the following steps
 * 4. Initialize LDOs, clocks and PHY only incase of Silicon platform
 * 5. For all platforms (including silicon) perform the following:
 *    a. Register for a callback with ACPI Platform Dxe to give a callback
 *       while it is loading ACPI AML variable PRPx, where x=0,1,2,..9
 *    b. Perform link training and update the global root port info
 *       structure with reduced count of root port if link training fails
 *    c. Setup misc configuration, iATU and ECAM blocker by calling
 *       PcieConfigLibInitializeConfigSpace
 *    d. Setup L1ss for this root port as well as endpoint if connected
 *
 * @param[in] ImageHandle  The firmware allocated handle for the EFI image.
 * @param[in] SystemTable  A pointer to the EFI System Table.
 *
 * @retval EFI_SUCCESS     The entry point is executed successfully.
 * @retval other           Some error occurred when executing this entry point.
 ******************************************************************************/
EFI_STATUS
EFIAPI
PcieConfigLibEnableRootPorts (VOID)
{
  EFI_CHARGER_EX_PROTOCOL             * pChargerExProtocol;
  EFI_PLATFORMINFO_PROTOCOL           * hPlatformInfoProtocol;
  EFI_PLATFORMINFO_PLATFORM_INFO_TYPE   PlatformInfo;
  BOOLEAN                               EmulationPlatform = FALSE;
  UINT32                                CurrentRootPort = 0;
  UINT32                                TotalRootPort;
  EFI_EVENT                             L1ssEnableTimer;
  EFI_STATUS                            Status = EFI_SUCCESS;

  /*
   * Locate Charger Ex Protocol to find out if the device is
   * entering off mode charging
   *
   * If for some reason, the LocateProtocol failed, then continue
   * with normal boot process
   */
  Status = gBS->LocateProtocol(
           &gChargerExProtocolGuid, 
           NULL,
           (VOID **) &pChargerExProtocol);
  if (!EFI_ERROR (Status))
  {
    /*
     * Check if the device is entering off mode charging
     *
     * TRUE  - it is offmode charging, so stop PCIe Init here
     * FALSE - continue with normal PCIe init operation
     */
    if (PcieConfigLibIsOffModeCharging(pChargerExProtocol))
    {
      DEBUG(( EFI_D_WARN, "%a: Aborting PCIe Initialization\r\n", __func__));
      return EFI_ABORTED;
    }
  }

  Status = PcieConfigLibGetDevConfig();
  if EFI_ERROR (Status)
  {
    DEBUG(( EFI_D_WARN, "%a: GetDevConfig Failed\r\n", __func__));
    return Status ;
  }

  // Read the platform ID and then figure out what Phy to initialize
  Status = gBS->LocateProtocol (
             &gEfiPlatformInfoProtocolGuid,
             NULL,
             (VOID **) &hPlatformInfoProtocol);
  if EFI_ERROR (Status)
  {
    DEBUG(( EFI_D_WARN, "%a: LocateProtocol Failed\r\n", __func__));
    return Status ;
  }

  Status = hPlatformInfoProtocol->GetPlatformInfo (hPlatformInfoProtocol,
                                                   &PlatformInfo);
  if EFI_ERROR (Status)
  {
    DEBUG(( EFI_D_WARN, "%a: GetPlatformInfo Failed\r\n", __func__));
    return Status ;
  }

  /*
   * If emulation or simulation platform start configuring
   * from Link training
   */
  if (PlatformInfo.platform == EFI_PLATFORMINFO_TYPE_VIRTIO ||
      PlatformInfo.platform == EFI_PLATFORMINFO_TYPE_RUMI ||
      PlatformInfo.platform == EFI_PLATFORMINFO_TYPE_UNKNOWN)
  {
    EmulationPlatform = TRUE;
  } 
  else
  {
    /*
     * Emphasize this is not a Emulation platform
     */
    EmulationPlatform = FALSE;
    /*
     * This is silicon, turn ON LDOs
     */
    Status = PcieConfigLibInitializeLDO();
    if EFI_ERROR (Status)
    {
      DEBUG(( EFI_D_WARN, "%a: InitialzeLDO Failed\r\n", __func__));
      return Status ;
    }
  }
 
  TotalRootPort = root_port_info.num_rp;

  for (CurrentRootPort = 0; CurrentRootPort < TotalRootPort; CurrentRootPort++)
  {

    if (EmulationPlatform == FALSE)
    {    
      Status = PcieConfigLibConfigureClocks(CurrentRootPort);
      if EFI_ERROR (Status)
      {
        DEBUG(( EFI_D_WARN, "%a: ConfigureClocks Failed for RP:%u\r\n",
                __func__, CurrentRootPort));
        return Status ;
      }
    }

    Status = PcieConfigLibConfigureSMMU(CurrentRootPort);
    if EFI_ERROR (Status)
    {
      DEBUG(( EFI_D_ERROR, "%a: SMMU configuration:%u\r\n",
              __func__, CurrentRootPort));
      continue;
    }   

    /*
     * If PHY init for this port failed,
     * let us give chance to bring the other PCIe port
     *
     * so, perform "continue" instead of return from this function
     */
    Status = PcieConfigLibInitializePHY(CurrentRootPort);
    if EFI_ERROR (Status)
    {
      DEBUG(( EFI_D_ERROR, "%a: PHY Init Failed for RP:%u\r\n",
              __func__, CurrentRootPort));
      continue;
    }   
    
    Status = PcieConfigLibTrainLink(CurrentRootPort);
    if EFI_ERROR (Status) 
    {
      DEBUG(( EFI_D_WARN, "%a: Link Training Failed for RP:%u\r\n",
              __func__, CurrentRootPort));
      return Status ;
    }

    Status = PcieConfigLibInitializeConfigSpace(CurrentRootPort);
    if EFI_ERROR (Status) 
    {
      DEBUG(( EFI_D_WARN, "%a: InitializeConfigSpace Failed for RP:%u\r\n",
              __func__, CurrentRootPort));
      return Status ;
    }

    Status = PcieConfigLibSetupL1ss(CurrentRootPort);
    if EFI_ERROR (Status)
    {
      DEBUG(( EFI_D_WARN, "%a: SetupL1ss Failed for RP:%u\r\n",
              __func__, CurrentRootPort));
      return Status ;
    }
  }

  Status = gBS->CreateEvent(
                            EVT_TIMER | EVT_NOTIFY_SIGNAL,   /* Type of the event(s) */
                            TPL_CALLBACK,                    /* Task Priority Level */
                            PcieConfigLibSetupEndPointL1ssCallBack,  /* Notify Function */
                            NULL,                            /* Notification Context */
                            &L1ssEnableTimer                 /* Event pointer */
                           );
  if EFI_ERROR (Status) 
  {
    DEBUG(( EFI_D_WARN, "%a: L1ss gBS->CreateEvent Failed\r\n", __func__));
    return Status ;
  }

  Status = gBS->SetTimer(
                         L1ssEnableTimer, /* Timer Event to be signaled */
                         TimerRelative,   /* Notify relative from this point */
                         1000000          /* 10000 number of 100 ns units = 100 ms timer */
                        );
  if EFI_ERROR (Status) 
  {
    DEBUG(( EFI_D_WARN, "%a: L1ss gBS->SetTimer\r\n", __func__));
    return Status ;
  }

  /*
   *
   * BEFORE ADDING MORE CODE, REMEMBER TO CALL THE FOLLOWING FUNCTION TO CANCEL
   * THE TIMER IN THE EVENT OF ERROR CASES WITHIN THIS FUNCTION. ELSE WE ARE
   * CREATING A SITUATION WHERE UNCLOCKED REGISTER ACCESS COULD HAPPEN WITHIN
   * THE ABOVE TIMER EVENT CALLBACK
   *
   * gBS->SetTimer(L1ssEnableTimer, TimerCancel, 0);
   */
  return Status;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetNumberOfHostBridges
 * @brief returns number of root bridges to enable
 *
 * PCIe configuration Library API to get total number of Host Bridges
 *
 * @param[in]  void
 *
 * @return unsigned 32-bit value, of number of root ports present
 ******************************************************************************/
UINT32
EFIAPI
PcieConfigLibGetNumberOfHostBridges(VOID)
{
  return root_port_info.num_rp;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetNumberOfRootBridges
 * @brief returns number of root bridges to enable
 *
 * PCIe configuration Library API to get total number of root bridges per
 * the supplied host bridge index
 *
 * @param[in] UINT32 HostBridgeIndex
 *
 * @return unsigned 32-bit value, of number of root bridges for this
 *         host bridge
 ******************************************************************************/
UINT32
EFIAPI
PcieConfigLibGetNumberOfRootBridges(UINT32 HostBridgeIndex)
{
  /*
   * Return 1 as of now
   * This can be changed in future, if we have more than one
   * root port sharing:
   *  o PCI I/O space
   *  o PCI memory space
   *  o PCI prefetchable memory space
   */
  return 0x1;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetResourceAperture
 * @brief returns memory and bus resource aperture
 *
 * PCIe configuration Library API to get Bus, Memory and IO resource aperture
 * corresponding to this segment
 *
 * @param[in]  UINT32 SegmentNumber
 * @param[out] A pointer to PCI_ROOT_BRIDGE_RESOURCE_APERTURE
 *
 * @retval EFI_SUCCESS       The entry point is executed successfully.
 * @retval other             Appropriate error number.
 ******************************************************************************/
EFI_STATUS
EFIAPI
PcieConfigLibGetResourceAperture(
    UINT32 SegmentNumber,
    PCI_ROOT_BRIDGE_RESOURCE_APERTURE * ResAperture)
{
  CONST memRegions_t * mem;
  portInfo_t         * port;
  UINT64               EcamSize = 0x0;
  EFI_STATUS           Status = EFI_SUCCESS;

  if (ResAperture == NULL)
  {
    DEBUG(( EFI_D_WARN, "%a: ResAperture is NULL\r\n", __func__));
    return EFI_INVALID_PARAMETER;
  }

  if (root_port_info.port_info == NULL)
  {
    DEBUG(( EFI_D_WARN, "%a: Port Info is NULL\r\n", __func__));
    return EFI_NOT_READY;
  }

  /*
   * Each root port is implemented in its own segment,
   * so, comparing it with the available root port
   * make more sense
   */
  if(SegmentNumber >= root_port_info.num_rp)
  {
    DEBUG(( EFI_D_WARN, "%a: Invalid Segment Number\r\n", __func__));
    return EFI_INVALID_PARAMETER;
  }

  /*
   * root port index and Segment numbers are synonym for this library
   */
  port = &root_port_info.port_info[SegmentNumber];
  mem = port->mem;

  /*
   * EcamSize is calculated from:
   *
   * (number_of_buses_in_this_segment) * 1 MB
   *
   * This calculation is based on ECAM size of 1 MB
   * per bus and total number of bus is (num_lanes + 1),
   * This is because the bus numbers starts form 0 index
   */
  EcamSize = (port->num_ports + 1) * PCIE_SINGLE_BUS_ADDR_SPACE_SIZE;

  /*
   * Before proceeding further, lets define some terms of resource aperture
   *
   * Base  - Base as seen from PCIe root complex after translation
   * Start - As seen from CPU before translation
   * End   - As seen from CPU before translation
   */

  /*
   * Bus number Information
   *
   * Base  - Start bus number of this segment
   * Start - Start bus number of this segment
   * End   - End bus number of this segment
   */
  ResAperture[PciRbResTypeBus].Base = 0;
  ResAperture[PciRbResTypeBus].Start = 0;
  ResAperture[PciRbResTypeBus].End = port->num_ports;

  /*
   * Config Mem Address information
   *
   * Base  - DBI Base
   * Start - DBI Base
   * End   - Ecam size of maximum available bus under this segment
   */
  ResAperture[PciRbResTypeCfg].Base = mem[axi_reg].pa;
  ResAperture[PciRbResTypeCfg].Start = mem[axi_reg].pa;
  ResAperture[PciRbResTypeCfg].End = mem[axi_reg].pa + EcamSize - 1;

  /* Mem Mapped IO Information
   *
   * Base  - Config Mem End for this segment
   * Start - Config Mem End for this segment
   * End   - Ecam size of maximum available bus under this segment
   */
  ResAperture[PciRbResTypeMem].Base = ResAperture[PciRbResTypeCfg].End + 1;
  ResAperture[PciRbResTypeMem].Start = ResAperture[PciRbResTypeCfg].End + 1;
  ResAperture[PciRbResTypeMem].End = mem[axi_reg].pa +  mem[axi_reg].sz - PCIE_IO_SIZE - 1;

  /* IO Mapped IO Information
   *
   * Base  - Device accessible address (arbitrary 20 bit value)
   * Start - CPU accessible DBI address
   * End   - DBI end
   */
  ResAperture[PciRbResTypeIo].Base = (0x10000 * (SegmentNumber + 1));
  ResAperture[PciRbResTypeIo].Start = ResAperture[PciRbResTypeMem].End + 1;
  ResAperture[PciRbResTypeIo].End = mem[axi_reg].pa + mem[axi_reg].sz - 1;

  /*
   * Configure IO iATU windows
   */
  Status = PcieConfigLibSetupOutboundiATU (SegmentNumber,
                                           OutIo,
                                           TlpTypeIORdWr,
                                           ResAperture[PciRbResTypeIo].Start,
                                           ResAperture[PciRbResTypeIo].End,
                                           ResAperture[PciRbResTypeIo].Base );
  if EFI_ERROR (Status)
  {
    DEBUG(( EFI_D_WARN, "%a: PcieConfigLibSetupOutboundiATU Failed\r\n", __func__));
  }

  return Status;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetPcieBspInfo
 * @brief returns pointer of pcieBsp_t struct
 *
 * Function to get BSP info
 *
 * @param[in]  void
 *
 * @return Pointer to pcieBsp_t struct with BSP information fetched from Dev cfg
 ******************************************************************************/
CONST pcieBsp_t * PcieConfigLibGetPcieBspInfo(VOID){
  return gPcieBspCtx;
}

/***************************************************************************//**
 * @fn PcieConfigLibGetPciRootPortInfo
 * @brief returns pointer of rootPort_t struct
 *
 * Function to get root port info
 *
 * @param[in]  void
 *
 * @return Pointer to rootPort_t struct with root port info
 ******************************************************************************/
rootPort_t * PcieConfigLibGetPciRootPortInfo(VOID)
{
  return &root_port_info;
}
