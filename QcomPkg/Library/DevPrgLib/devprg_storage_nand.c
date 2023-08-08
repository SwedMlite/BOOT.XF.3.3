/**************************************************************************
 * FILE: devprg_storage_nand.c
 *
 * NAND Device implementation.
 *
 * Copyright (c) 2017, 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Qualcomm Proprietary
 *
 *************************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/DevPrgLib/devprg_storage_nand.c#2 $
  $DateTime: 2019/11/08 19:31:33 $
  $Author: pwbldsvc $

when         who   what, where, why
----------   ---   ---------------------------------------------------------
2019-11-08   sa    Removed unused code.
2017-07-13   svl   Updated APIs to make devprg work on NAND.
2017-04-20   wek   Include the start and end sectors in set io options.
2017-02-02   wek   Add io options to change how data is read/write.
2017-01-25   wek   Create (partially, change history accordingly)

===========================================================================*/

#ifdef FEATURE_DEVPRG_NAND  /* { */

#error "DeviceProgrammer NAND implementation removed, please add back to enable the feature"

#else /* }{ If NAND Support is disabled (FEATURE_DEVPRG_NAND not defined)*/

#include "devprg_storage_stubs.h"
void devprg_storage_nand_init(void)
{
  devprg_storage_stub_init();
}

dp_res_t devprg_storage_nand_deinit(void)
{
  return devprg_storage_stub_deinit();
}

void *devprg_storage_nand_open(uint32 slot, uint32 partition,
                               dp_res_t *error)
{
  return devprg_storage_stub_open(slot, partition, error);
}

dp_res_t devprg_storage_nand_close(void *device)
{
  return devprg_storage_stub_close(device);
}

dp_res_t devprg_storage_nand_io_options(void *device,
                                        struct devprg_io_options *io_options)
{
  return devprg_storage_stub_io_options(device, io_options);
}

dp_res_t devprg_storage_nand_read(void *device, void *buffer,
                                  uint64 start_sector, uint64 num_sectors)
{
  return devprg_storage_stub_read(device, buffer, start_sector, num_sectors);
}

dp_res_t devprg_storage_nand_write(void *device, void *buffer,
                                   uint64 start_sector, uint64 num_sectors)
{
  return devprg_storage_stub_write(device, buffer, start_sector, num_sectors);
}

dp_res_t devprg_storage_nand_erase(void *device,
                                   uint64 start_sector, uint64 num_sectors)
{
  return devprg_storage_stub_erase(device, start_sector, num_sectors);
}

dp_res_t devprg_storage_nand_format(void *device)
{
  return devprg_storage_stub_format(device);
}

dp_res_t devprg_storage_nand_set_bootable(void *device, int enable)
{
  return devprg_storage_stub_set_bootable(device, enable);
}

dp_res_t devprg_storage_nand_get_info(void *device,
                                      struct devprg_storage_info *dev_info)
{
  return devprg_storage_stub_get_info(device, dev_info);
}

dp_res_t devprg_storage_nand_configure(uint32 slot,
                                       struct devprg_storage_cfg_data *config)
{
  return devprg_storage_stub_configure(slot, config);
}

dp_res_t devprg_storage_nand_fw_update(uint32 slot, void *buffer,
                                       uint32 size_in_bytes)
{
  return devprg_storage_stub_fw_update(slot, buffer, size_in_bytes);
}

dp_res_t devprg_storage_nand_info_raw_size(void *device, uint32 *size)
{
  return devprg_storage_stub_info_raw_size(device, size);
}

dp_res_t devprg_storage_nand_info_raw(void *device, void *buffer,
                                      uint32 *size)
{
  return devprg_storage_stub_info_raw(device, buffer, size);
}
dp_res_t devprg_storage_nand_info_raw_print(void *device, void *buffer,
                                            uint32 *size)
{
  return devprg_storage_stub_info_raw_print(device, buffer, size);
}


#endif /*  } FEATURE_DEVPRG_NAND */
