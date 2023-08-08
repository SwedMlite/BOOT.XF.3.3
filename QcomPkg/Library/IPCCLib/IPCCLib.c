/*
===========================================================================
*/
/**
  @file IPCCLib.c

  IPC Controller UEFI Library.
*/
/*
  ====================================================================

  Copyright (c) 2018 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/IPCCLib/IPCCLib.c#2 $
  $DateTime: 2020/02/21 02:36:31 $
  $Author: pwbldsvc $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include <Library/PcdLib.h>
#include "IPCCLib.h"
#include "IPCCHWIO.h"
#include "HALhwio.h"
#include "DalDevice.h"
#include "DALDeviceId.h"
#include "DDIHWIO.h"

/*=========================================================================
      Static defiintions
==========================================================================*/

static uintptr_t nIPCCSendAddress = 0;

/*=========================================================================
      Functions
==========================================================================*/


/* =========================================================================
**  Function : IPCCLib_Trigger
** =========================================================================*/

IPCCErr 
IPCCLib_Trigger
(
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  IPCC_Protocol eProtocol;
  uint32_t nIdx, nSigEn;
  IPCC_Signal nMaxSig = PcdGet32(PcdIPCCLibTotalSignals);
  IPCC_Client eLocalClient;
  DalDeviceHandle* phHWIO = NULL;
  DALResult eResult;

  /*-------------------------------------------------------------------------*/

  if( eCID >= IPCC_C_TOTAL ||
      nSignalLow > nSignalHigh ||
      nSignalHigh >= nMaxSig )
  {
    return IPCC_EARG;
  }

  if( nIPCCSendAddress == 0 )
  {
    DALSYS_InitMod(NULL);

    eResult = DAL_DeviceAttach(DALDEVICEID_HWIO, &phHWIO);

    if ( DAL_SUCCESS != eResult )
    {
      return IPCC_ENOTFOUND;
    }

    DalHWIO_MapRegion(phHWIO, "IPC_ROUTER_TOP", (uint8 **)&nIPCCSendAddress);

    eProtocol = PcdGet32(PcdIPCCLibProtocol);
    eLocalClient = PcdGet32(PcdIPCCLibLocalClient);

    nIPCCSendAddress += HWIO_OFFSI2(IPC_SEND, eProtocol, eLocalClient);
  }

  /* Trigger outgoing interrupt */
  /* For now, trigger one-by-one, but ideally we can use Global trigger mask */
  for( nIdx = nSignalLow; nIdx <= nSignalHigh; nIdx++ )
  {
    nSigEn = ( eCID << HWIO_SHFT(IPC_SEND, CLIENT_ID) ) | nIdx;
    if( nIPCCSendAddress != 0 )
    {
      out_dword(nIPCCSendAddress, nSigEn);
    }
  }

  return IPCC_EOK;
}
