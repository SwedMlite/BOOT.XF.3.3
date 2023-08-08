/** @file DDRInfoTest.c
   
  Test for UEFI DDR Info test.

  Copyright (c) 2017 Qualcomm Technologies Inc. All rights reserved.
  
**/

/*=============================================================================
                              EDIT HISTORY


 when         who       what, where, why
 --------     ---       -----------------------------------------------------------
 12/18/12     dj        Add ddr info protocal
 09/26/2017   daisond   Use max ddr channels received from GetDDRDetails module
 04/19/2017   daisond   Initial Revision
=============================================================================*/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/TestInterface.h>
#include <Library/PrintLib.h>
#include <Library/PcdLib.h>
#include <Protocol/EFIDDRGetConfig.h>
#include <Protocol/EFIHWIO.h>
#include <ddr_info_util.h>

#define LOOP_COUNT_FOR_FREQ_SCALING_TEST 10

UINT32 mul_wid = 0xFCA01979;
UINT32 mul_zid = 0xBA031903;

void srand_uefi (UINT32 seed)
{
  if (seed != 0 && seed != 0x464FFFFF) {
    mul_wid = seed;
  }
  else {
    mul_wid = 0xFCA01979;
  }
  mul_zid = 0xBA031903;
}

UINT32 rand_uefi ()
{
    mul_zid = 36969 * (mul_zid & 65535) + (mul_zid >> 16);
    mul_wid = 18000 * (mul_wid & 65535) + (mul_wid >> 16);
    return ((mul_zid << 16) + mul_wid);
}


STATIC
EFI_STATUS
DDRInfoProtocolTest (VOID)
{
  EFI_STATUS                  Status = EFI_NOT_FOUND;
  EFI_DDRGETINFO_PROTOCOL   *pDDRGetInfoProtocol = NULL;
  EFI_HWIO_PROTOCOL         *HWIOProtocol = NULL;
  ddr_details_entry           *pDDREntry = NULL;
  ddr_freq_plan_entry         *pDDRFreqTbl = NULL;
  UINT32 ddr_channel = 0, rank = 0, ddr_freq = 0, ddr_max_enabled_freq = 0, set_ddr_freq = 200000, freq_index=0;
  UINT32 idx = 0;
  UINT8* Addr;
  
  Status = gBS->LocateProtocol(&gEfiDDRGetInfoProtocolGuid, NULL, (VOID**)&pDDRGetInfoProtocol);
  if (EFI_ERROR(Status) || (&pDDRGetInfoProtocol == NULL))
  {
    DEBUG((EFI_D_ERROR, "Locate EFI_DDRGETINFO_PROTOCOL failed, Status =  (0x%x)\r\n", Status));
    return EFI_NOT_FOUND;
  }
  
  Status = gBS->LocateProtocol(&gEfiHwioProtocolGuid, NULL, (void**)&HWIOProtocol);
  if ((EFI_SUCCESS != Status) || (HWIOProtocol == NULL))
  {
    DEBUG ((EFI_D_ERROR, "ERROR: Failed to locate HWIO Protocol: 0x%08x\n", Status));
    return EFI_NOT_FOUND;
  }

  Status = HWIOProtocol->MapRegion(HWIOProtocol, "+MCCC_MCCC_MSTR", (UINT8**) &Addr);
  if (EFI_SUCCESS != Status)
  {
    DEBUG ((EFI_D_ERROR, "ERROR: Failed to map MCCC_MCCC_MSTR base address: 0x%08x\n", Status));
    return EFI_NOT_FOUND;
  }
  
  pDDREntry = AllocatePool (sizeof (ddr_details_entry));
  if (pDDREntry == NULL) 
      return EFI_OUT_OF_RESOURCES;
  
  pDDRFreqTbl = AllocatePool (sizeof (ddr_freq_plan_entry));
  if (pDDRFreqTbl == NULL)
	  return EFI_OUT_OF_RESOURCES;

  Status = pDDRGetInfoProtocol->GetDDRDetails(pDDRGetInfoProtocol, pDDREntry);
  if (Status != EFI_SUCCESS)
  {
    if (EFI_ERROR (Status))
    {
      DEBUG((EFI_D_WARN, "Failed to get DDR details"));
    }
	return Status;
  }

  Status = pDDRGetInfoProtocol->GetDDRFreqTable(pDDRGetInfoProtocol, pDDRFreqTbl);
  if (Status != EFI_SUCCESS)
  {
    if (EFI_ERROR (Status))
    {
      DEBUG((EFI_D_WARN, "Failed to get DDR Freq Table"));
    }
	return Status;
  }
  
  Status = pDDRGetInfoProtocol->GetDDRFreq(pDDRGetInfoProtocol, &ddr_freq);
  if (Status != EFI_SUCCESS)
  {
    if (EFI_ERROR (Status))
    {
      DEBUG((EFI_D_WARN, "Failed to get DDR Current Freq"));
    }
	return Status;
  }
  
  Status = pDDRGetInfoProtocol->GetDDRMaxEnabledFreq(pDDRGetInfoProtocol, &ddr_max_enabled_freq);
  if (Status != EFI_SUCCESS)
  {
    if (EFI_ERROR (Status))
    {
      DEBUG((EFI_D_WARN, "Failed to get DDR Max Enabled Freq"));
    }
	return Status;
  }
 
  AsciiPrint("                                 \n");
  AsciiPrint("Number of DDR Channels          :");
  AsciiPrint("0x%016lx\n", pDDREntry->num_channels);  
  AsciiPrint("Manufacturer Id                 :");
  AsciiPrint("0x%016lx\n", pDDREntry->manufacturer_id);
  AsciiPrint("Device Type                     :");
  AsciiPrint("0x%016lx\n", pDDREntry->device_type);
  AsciiPrint("                                 \n");

  for(ddr_channel=0; ddr_channel<pDDREntry->num_channels; ddr_channel++)
  {
    for(rank=0; rank < 2; rank++)
    {
      AsciiPrint("Revision Id1 (CH %d, Rank %d)     :", ddr_channel, rank);
      AsciiPrint("0x%016lx\n", pDDREntry->ddr_params[ddr_channel].revision_id1[rank]);

      AsciiPrint("Revision Id2 (CH %d, Rank %d)     :", ddr_channel, rank);
      AsciiPrint("0x%016lx\n", pDDREntry->ddr_params[ddr_channel].revision_id2[rank]);

      AsciiPrint("Width (CH %d, Rank %d)            :", ddr_channel, rank);
      AsciiPrint("0x%016lx\n", pDDREntry->ddr_params[ddr_channel].width[rank]);

      AsciiPrint("Density (CH %d, Rank %d)          :", ddr_channel, rank);
      AsciiPrint("0x%016lx\n", pDDREntry->ddr_params[ddr_channel].density[rank]);
    }
    AsciiPrint("                                 \n");
  } 
  AsciiPrint("                    \n");
  AsciiPrint("DDR Frequency Table:\n");
  AsciiPrint("DDR Freq\t Enable   \n");
  AsciiPrint("========\t ======   \n");
  for(idx=0; idx < pDDRFreqTbl->num_ddr_freqs; idx++)
  {
      AsciiPrint("%d\t\t ", pDDRFreqTbl->ddr_freq[idx].freq_khz);
      AsciiPrint("  %d\n", pDDRFreqTbl->ddr_freq[idx].enable);
  }
  AsciiPrint("\nDDR Max Enabled Freq: %d ", ddr_max_enabled_freq);
  AsciiPrint("                    \n");
  AsciiPrint("                    \n");
  
  ddr_setlowbandwidth();  
  ddr_uefi_display_init();
  ddr_uefi_display_off();
  AsciiPrint("                                 \n");
  
  for(freq_index = 2; freq_index<=13; freq_index++)
  {
        if(pDDRFreqTbl->ddr_freq[freq_index].enable == TRUE)
        {
            set_ddr_freq = pDDRFreqTbl->ddr_freq[freq_index].freq_khz;
        }
        else
        {
            continue;
        }
      AsciiPrint("DDR Set Frequency                 :");
      AsciiPrint("%d MHz\n", set_ddr_freq/1000);
      Status = pDDRGetInfoProtocol->SetDDRFreq(pDDRGetInfoProtocol, set_ddr_freq);
      if (Status != EFI_SUCCESS)
      {
            if (EFI_ERROR (Status))
            {
                  DEBUG((EFI_D_WARN, "Failed to set DDR Freq"));
            }
            return Status;
      }
      idx = 0;
      while(1)
      {
            ddr_freq = 0, 
            Status = pDDRGetInfoProtocol->GetDDRFreq(pDDRGetInfoProtocol, &ddr_freq);
            if (Status != EFI_SUCCESS)
            {
                  if (EFI_ERROR (Status))
                  {
                        DEBUG((EFI_D_WARN, "Failed to get DDR Current Freq"));
                  }
                  return Status;
            }
            idx++;
            /*DDR frequency read is in the range of set DDR frequency +5 or -5 */
            if(( (ddr_freq <= ((set_ddr_freq/1000)+5)) && (ddr_freq >= ((set_ddr_freq/1000)-5)) ) || (idx == 100))
                  break;
      }
      AsciiPrint("DDR Current Frequency             :");
      AsciiPrint("%d MHz\n", ddr_freq);
      AsciiPrint("                                 \n");     
  }
  
  for(freq_index = 13; freq_index>=2; freq_index--)
  {
        if(pDDRFreqTbl->ddr_freq[freq_index].enable == TRUE)
        {
            set_ddr_freq = pDDRFreqTbl->ddr_freq[freq_index].freq_khz;
        }
        else
        {
            continue;
        }
      AsciiPrint("DDR Set Frequency                 :");
      AsciiPrint("%d MHz\n", set_ddr_freq/1000);
      Status = pDDRGetInfoProtocol->SetDDRFreq(pDDRGetInfoProtocol, set_ddr_freq);
      if (Status != EFI_SUCCESS)
      {
            if (EFI_ERROR (Status))
            {
                  DEBUG((EFI_D_WARN, "Failed to set DDR Freq"));
            }
            return Status;
      }
      idx = 0;
      while(1)
      {
            ddr_freq = 0, 
            Status = pDDRGetInfoProtocol->GetDDRFreq(pDDRGetInfoProtocol, &ddr_freq);
            if (Status != EFI_SUCCESS)
            {
                  if (EFI_ERROR (Status))
                  {
                        DEBUG((EFI_D_WARN, "Failed to get DDR Current Freq"));
                  }
                  return Status;
            }
            idx++;
            /*DDR frequency read is in the range of set DDR frequency +5 or -5 */
            if(( (ddr_freq <= ((set_ddr_freq/1000)+5)) && (ddr_freq >= ((set_ddr_freq/1000)-5)) ) || (idx == 100))
                  break;
      }
      AsciiPrint("DDR Current Frequency             :");
      AsciiPrint("%d MHz\n", ddr_freq);
      AsciiPrint("                                 \n");     
  }
  ddr_uefi_display_on();
  
  return EFI_SUCCESS;
}

/**
  Entry point for the application

  @param[in] ImageHandle    Image handle 
  @param[in] SystemTable    Pointer to the System Table
  
  @retval EFI_SUCCESS       Execution successful
  @retval other             Error occurred

**/
EFI_STATUS
EFIAPI
DDRInfoTestMain 
(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
)
{
  EFI_STATUS  Status;
  TEST_START("DDRInfoTest");

  Status = DDRInfoProtocolTest();

  TestStatus("DDRInfoTest", Status);
  TEST_STOP("DDRInfoTest");
  return EFI_SUCCESS;
}
