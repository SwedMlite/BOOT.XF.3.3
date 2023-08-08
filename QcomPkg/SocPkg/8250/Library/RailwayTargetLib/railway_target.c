/**
 * @file:  railway_target.c
 * @brief: Railway target specific config and initialization.
 *
 * Copyright (c) 2015-2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Qualcomm Confidential and Proprietary
 *
 * $DateTime: 2020/05/11 03:07:14 $
 * $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/RailwayTargetLib/railway_target.c#3 $
 * $Change: 23791896 $
 */
#include "railway_config.h"
#include "CoreVerify.h"
#include "railway.h"
#include "cpr_fuses_hwio.h"
#include "msmhwio.h"
#include "msg_ram.h"

/* -----------------------------------------------------------------------
**                           FUNCTIONS
** ----------------------------------------------------------------------- */

#if 0
extern int wlan_rail_id;
volatile uint32 wlan_fuse_value;
#endif

typedef struct
{
    uint32 address;
    uint8 offset;
    uint8 mask;
} fuse_t;

typedef struct
{
    const uint32 *retention_table;
    const fuse_t  fuse;
} pvs_data_t;

#if 0
// WLAN uses the same table as the mx rail
static const uint32 vddwlan_pvs_retention_data[8] =
{
    /* 000 */ 644000,
    /* 001 */ 644000,
    /* 010 */ 592000,
    /* 011 */ 540000,
    /* 100 */ 488000,
    /* 101 */ 488000,
    /* 110 */ 488000,
    /* 111 */ 644000
};

// WLAN uses the same fuse as the mx rail
static pvs_data_t vddwlan_pvs_data =
{
    /* .retention_data  */ vddwlan_pvs_retention_data,
    /* .fuse            */ { HWIO_ADDR(QFPROM_RAW_PTE_ROW3_LSB), 17, 0x7 }   //correct address 0x780148 bit[17:19]
};
#endif

static uint32 read_fuse_value(const fuse_t *fuse)
{
    return ( __inpdw(fuse->address) >> fuse->offset ) & (uint32)fuse->mask;
}

static uint32 set_sleep_voltage(int rail_id, pvs_data_t *pvs_data_ptr)
{
    uint32 lookup_val = read_fuse_value( &pvs_data_ptr->fuse );
    CORE_VERIFY(lookup_val < 8);

    railway_set_retention_voltage(rail_id, pvs_data_ptr->retention_table[lookup_val]);

    return lookup_val;
}

void railway_target_init(void)
{
	clear_aop_msg_ram_cookie();               //Clear boot cookie in msg_ram
#if 0
    wlan_rail_id = rail_id("vdda_wlan");
    CORE_VERIFY(RAIL_NOT_SUPPORTED_BY_RAILWAY!=wlan_rail_id);

    wlan_fuse_value = set_sleep_voltage(wlan_rail_id, &vddwlan_pvs_data);
#endif
}
static void clear_aop_msg_ram_cookie(void)
{
    aop_cookie_info_0_t *info = (aop_cookie_info_0_t *)((AOP_SS_MSG_RAM_END_ADDRESS_BASE + 1) - (MSG_RAM_SECTION_SIZE));
	uint32 *boot_cookie = (uint32 *)(&(info->boot_cookie));
    *boot_cookie = 0;
    return;
}