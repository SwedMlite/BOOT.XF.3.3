/**
 * @file:  cpr_image_target.c
 *
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * $DateTime: 2019/03/14 17:07:03 $
 * $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/CPRTargetLib/image/core/target/8250/cpr_image_target_au.c#4 $
 * $Change: 18595753 $
 */
#include "cpr_image_target.h"
#include "cpr_image.h"
#include "cpr_logs.h"
#include "cpr_smem.h"


static uint32 cpr_pte_qc_spare_fuse;

const cpr_settings* cpr_image_target_get_settings(void)
{
    int i = 0;

    cpr_settings *cpr_settings_8250 = (cpr_settings*)cpr_image_malloc(sizeof(cpr_settings));
    CPR_ASSERT(cpr_settings_8250);

    cpr_settings_8250->railsCount = 2;
    cpr_settings_8250->enablementsCount = 2;
    cpr_settings_8250->controllersCount = 2;

    cpr_settings_8250->railVVPs = (cpr_versioned_voltage_plan **) \
        cpr_image_malloc(sizeof(cpr_versioned_voltage_plan *) * \
                cpr_settings_8250->railsCount);
    for (i = 0; i < cpr_settings_8250->railsCount; i++) {
        cpr_settings_8250->railVVPs[i] = (cpr_versioned_voltage_plan *) \
            cpr_image_malloc(sizeof(cpr_versioned_voltage_plan));
    }

    cpr_settings_8250->controllers = (cpr_hal_controller **) \
        cpr_image_malloc(sizeof(cpr_hal_controller *) * \
                cpr_settings_8250->controllersCount);
    for (i = 0; i < cpr_settings_8250->controllersCount; i++) {
        cpr_settings_8250->controllers[i] = (cpr_hal_controller *) \
            cpr_image_malloc(sizeof(cpr_hal_controller));
    }

    cpr_settings_8250->rails = (cpr_rail **) cpr_image_malloc(
            sizeof(cpr_rail *) * cpr_settings_8250->railsCount);
    for (i = 0; i < cpr_settings_8250->railsCount; i++) {
        cpr_settings_8250->rails[i] =
            (cpr_rail *) cpr_image_malloc(sizeof(cpr_rail));
    }

    cpr_settings_8250->enablements = (cpr_enablement **) \
        cpr_image_malloc(sizeof(cpr_enablement *) * \
                cpr_settings_8250->enablementsCount);
    for (i = 0; i < cpr_settings_8250->enablementsCount; i++) {
        cpr_settings_8250->enablements[i] =
            (cpr_enablement *)cpr_image_malloc(sizeof(cpr_enablement));
    }

    cpr_settings_8250->miscCfg = (cpr_misc_cfg *)
        cpr_image_malloc(sizeof(cpr_misc_cfg));

    cpr_rail gfx_rail;
    gfx_rail.id = CPR_RAIL_GFX;
    cpr_smem_deserialize_settings(&gfx_rail, cpr_settings_8250, /*idx*/ 0);

    cpr_rail mm_rail;
    mm_rail.id = CPR_RAIL_MM;
    cpr_smem_deserialize_settings(&mm_rail, cpr_settings_8250, /*idx*/ 1);

    return cpr_settings_8250;
}

boolean cpr_image_target_is_turbo_mode_only(void)
{
    /*
     * CR 1050500:
     * TURBO_MODE_ONLY fuse: QC Spare 16[45] - bit 13 of 0x780324/0x784324
     */
    cpr_pte_qc_spare_fuse = CPR_HWIO_IN(SECURITY_CONTROL_CORE_REG_BASE + 0x004324);

    return ((cpr_pte_qc_spare_fuse & (1 << 13)) != 0);
}

cpr_domain_id cpr_image_target_railway_rail_to_cpr_domain(int railway_rail)
{
    switch(railway_rail)
    {
        case 0: return CPR_RAIL_MX;
        case 1: return CPR_RAIL_CX;
        case 2: return CPR_RAIL_VDDA;
        case 3: return CPR_RAIL_WLAN;
        default:
            CPR_LOG_FATAL("Unsupported rail %u", railway_rail);
            break;
    }

    CPR_ASSERT(0);

    return (cpr_domain_id)0;
}

railway_corner cpr_image_target_cpr_mode_to_railway_corner(cpr_voltage_mode mode)
{
    railway_corner map[CPR_VOLTAGE_MODE_COUNT] = {
        [CPR_VOLTAGE_MODE_OFF                ] = RAILWAY_NO_REQUEST,
        [CPR_VOLTAGE_MODE_RETENTION          ] = RAILWAY_RETENTION,
        [CPR_VOLTAGE_MODE_MIN_SVS            ] = RAILWAY_SVS_MIN,
        [CPR_VOLTAGE_MODE_LOW_SVS            ] = RAILWAY_SVS_LOW,
        [CPR_VOLTAGE_MODE_LOW_SVS_L1         ] = RAILWAY_SVS_LOW_L1,
        [CPR_VOLTAGE_MODE_LOW_SVS_L2         ] = RAILWAY_SVS_LOW_L2,
        [CPR_VOLTAGE_MODE_SVS                ] = RAILWAY_SVS,
        [CPR_VOLTAGE_MODE_SVS_L1             ] = RAILWAY_SVS_HIGH,
        [CPR_VOLTAGE_MODE_SVS_L2             ] = RAILWAY_SVS_SUPER_HIGH,
        [CPR_VOLTAGE_MODE_NOMINAL            ] = RAILWAY_NOMINAL,
        [CPR_VOLTAGE_MODE_NOMINAL_L1         ] = RAILWAY_NOMINAL_L1,
        [CPR_VOLTAGE_MODE_NOMINAL_L2         ] = RAILWAY_NOMINAL_L2,
        [CPR_VOLTAGE_MODE_TURBO              ] = RAILWAY_TURBO,
        [CPR_VOLTAGE_MODE_TURBO_L1           ] = RAILWAY_TURBO_L1,
        [CPR_VOLTAGE_MODE_SUPER_TURBO        ] = RAILWAY_SUPER_TURBO,
        [CPR_VOLTAGE_MODE_SUPER_TURBO_NO_CPR ] = RAILWAY_SUPER_TURBO_NO_CPR,
    };

    return (mode < CPR_VOLTAGE_MODE_COUNT) ? map[mode] : map[CPR_VOLTAGE_MODE_COUNT - 1];
}

cpr_voltage_mode cpr_image_target_railway_corner_to_cpr_mode(railway_corner corner)
{
    cpr_voltage_mode map[RAILWAY_CORNERS_COUNT] = {
        [RAILWAY_NO_REQUEST        ] = CPR_VOLTAGE_MODE_OFF,
        [RAILWAY_RETENTION         ] = CPR_VOLTAGE_MODE_RETENTION,
        [RAILWAY_SVS_MIN           ] = CPR_VOLTAGE_MODE_MIN_SVS,
        [RAILWAY_SVS_LOW           ] = CPR_VOLTAGE_MODE_LOW_SVS,
        [RAILWAY_SVS_LOW_L1        ] = CPR_VOLTAGE_MODE_LOW_SVS_L1,
        [RAILWAY_SVS_LOW_L2        ] = CPR_VOLTAGE_MODE_LOW_SVS_L2,
        [RAILWAY_SVS               ] = CPR_VOLTAGE_MODE_SVS,
        [RAILWAY_SVS_HIGH          ] = CPR_VOLTAGE_MODE_SVS_L1,
        [RAILWAY_SVS_SUPER_HIGH    ] = CPR_VOLTAGE_MODE_SVS_L2,
        [RAILWAY_NOMINAL           ] = CPR_VOLTAGE_MODE_NOMINAL,
        [RAILWAY_NOMINAL_L1        ] = CPR_VOLTAGE_MODE_NOMINAL_L1,
        [RAILWAY_NOMINAL_L2        ] = CPR_VOLTAGE_MODE_NOMINAL_L2,
        [RAILWAY_TURBO             ] = CPR_VOLTAGE_MODE_TURBO,
        [RAILWAY_TURBO_L1          ] = CPR_VOLTAGE_MODE_TURBO_L1,
        [RAILWAY_SUPER_TURBO       ] = CPR_VOLTAGE_MODE_SUPER_TURBO,
        [RAILWAY_SUPER_TURBO_NO_CPR] = CPR_VOLTAGE_MODE_SUPER_TURBO_NO_CPR,
    };

    return (corner < RAILWAY_CORNERS_COUNT) ? map[corner] : map[RAILWAY_CORNERS_COUNT - 1];
}

void cpr_image_target_enable_measurements(cpr_rail* rail, cpr_measurement_type type)
{
    /* TODO: set rail to PWM */
}

void cpr_image_target_disable_measurements(cpr_rail* rail, cpr_measurement_type type)
{
    /* TODO: reset rail */
}

boolean cpr_image_target_set_rail_mode(cpr_domain_id railId,
        cpr_domain_info* info)
{
    return true;
}

void cpr_image_target_extra_init(void)
{
    return;
}
