/***********************************************************************
 * Coldplug SD/eMMC Block Device.
 *
 * Coldplug
 * Copyright (C) 2015 QUALCOMM Technologies, Inc.
 *
 * Coldplug SD/eMMC Block Device.
 *
 ***********************************************************************/

/*===========================================================================

  EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/ColdplugLib/src/coldplug_bdev_sd.h#1 $ $DateTime: 2018/07/26 18:39:07 $ $Author: pwbldsvc $

  when         who   what, where, why
  ----------   ---   ---------------------------------------------------------
  2015-06-15   rp    Create

 ===========================================================================*/

#ifndef __COLDPLUG_BDEV_SD__H__
#define __COLDPLUG_BDEV_SD__H__

#include "coldplug_config_i.h"
#include "coldplug_bdev_ops.h"

#ifdef COLDPLUG_SD_OR_EMMC_ENABLE

void coldplug_bdev_sd_init(void);
struct coldplug_bdev_ops* coldplug_bdev_sd_get_ops(void);

#else

static inline void coldplug_bdev_sd_init(void)
{
}

static inline struct coldplug_bdev_ops* coldplug_bdev_sd_get_ops(void)
{
	return NULL;
}

#endif /* COLDPLUG_SD_OR_EMMC_ENABLE */

#endif /* __COLDPLUG_BDEV_SD__H__ */
