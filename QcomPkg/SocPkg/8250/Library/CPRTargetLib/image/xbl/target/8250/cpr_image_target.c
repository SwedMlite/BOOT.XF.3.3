/**
 * @file:  cpr_image_target.c
 *
 * Copyright (c) 2018 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * $DateTime: 2020/02/11 03:07:12 $
 * $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/CPRTargetLib/image/xbl/target/8250/cpr_image_target.c#7 $
 * $Change: 22531373 $
 */
#include "cpr_image_target.h"
#include "cpr_logs.h"
#include "cpr.h"
#include "cpr_smem.h"
#include "cpr_utils.h"

#define LCX_LDO_HEADROOM 56*1000 //35mV
#define EBI_TURBO_MAX 924*1000 //924mV

static uint32 cpr_pte_qc_spare_fuse;

uint32 *cpr_lcx_ebi_map = NULL;

const cpr_settings* cpr_image_target_get_settings(void)
{
    extern const cpr_settings cpr_settings_8250;

    return &cpr_settings_8250;
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
        case 3: return CPR_RAIL_LPI_MX;
        case 4: return CPR_RAIL_LPI_CX;
        case 5: return CPR_RAIL_WLAN;
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
        [CPR_VOLTAGE_MODE_SVS_L0             ] = RAILWAY_SVS_L0,
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
        [RAILWAY_SVS_L0            ] = CPR_VOLTAGE_MODE_SVS_L0,
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

//Function to be called after SMEM is initialized to push out the CPR settings
//to SMEM. These settings are to be picked up by the RPM CPR driver during boot.
//Must be done before the RPM FW execution begins.
void cpr_externalize_state()
{
    CPR_LOG_INFO("Exporting CPR state");

    cpr_smem_serialize_config( cpr_utils_get_rail_state( CPR_RAIL_CX ),
            false );
    cpr_smem_serialize_config( cpr_utils_get_rail_state( CPR_RAIL_MX ),
            true );
    cpr_smem_serialize_config( cpr_utils_get_rail_state( CPR_RAIL_VDDA ),
            true );
    cpr_smem_serialize_settings( cpr_utils_get_rail_state( CPR_RAIL_GFX),
            true );
    cpr_smem_serialize_settings( cpr_utils_get_rail_state( CPR_RAIL_MM),
            true );
    cpr_smem_serialize_config( cpr_utils_get_rail_state( CPR_RAIL_LPI_CX),
            true );
    cpr_smem_serialize_config( cpr_utils_get_rail_state( CPR_RAIL_LPI_MX),
            true );

    CPR_LOG_INFO("--- Done with CPR state export ---");
}

uint8 cpr_image_get_cprf_id(cpr_rail *rail)
{
    switch (rail->id)
    {
        case CPR_RAIL_MX: return 0;
        case CPR_RAIL_CX: return 1;
        case CPR_RAIL_VDDA: return 2;
        case CPR_RAIL_LPI_CX: return 3;
        case CPR_RAIL_LPI_MX: return 4;
        case CPR_RAIL_GFX: return 5;
        case CPR_RAIL_MSS: return 6;
        case CPR_RAIL_MM: return 7;
        default: return -1;
    }
}

void cpr_image_target_reinit_ebi_voltages(void)
{
    int i;

    uint32 lcx_map[CPR_VOLTAGE_MODE_COUNT] = {0};
    uint32 ebi_map[CPR_VOLTAGE_MODE_COUNT] = {0};

    cpr_rail_state *lcx_state = cpr_utils_get_rail_state(CPR_RAIL_LPI_CX);
    cpr_rail_state *ebi_state = cpr_utils_get_rail_state(CPR_RAIL_VDDA);

    for(i = 0; i < lcx_state->modeSettingsCount; i++)
    {
        cpr_mode_settings *modeSettings = &(lcx_state->modeSettings[i]);
        cpr_submode_settings *subModes = &(modeSettings->subModes[0]);

        lcx_map[modeSettings->mode] = subModes->ceiling;
    }

    for(i = 0; i < ebi_state->modeSettingsCount; i++)
    {
        cpr_mode_settings *modeSettings = &(ebi_state->modeSettings[i]);
        cpr_submode_settings *subModes = &(modeSettings->subModes[0]);

        ebi_map[modeSettings->mode] = subModes->floor;
    }

    for(i = 0; i < ebi_state->modeSettingsCount; i++)
    {
        uint32 volt = 0;

        cpr_mode_settings *modeSettings = &(ebi_state->modeSettings[i]);
        cpr_submode_settings *subModes = &(modeSettings->subModes[0]);

        switch (modeSettings->mode)
        {
            case CPR_VOLTAGE_MODE_RETENTION:
                //Retention voltage update is handled in AOP.
                //for now just add the headroom.
                volt = lcx_map[CPR_VOLTAGE_MODE_RETENTION] + LCX_LDO_HEADROOM;
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_RETENTION]);
                break;
            case CPR_VOLTAGE_MODE_MIN_SVS:
                volt = lcx_map[CPR_VOLTAGE_MODE_MIN_SVS] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_SVS], volt);
                break;
            case CPR_VOLTAGE_MODE_LOW_SVS:
                volt = lcx_map[CPR_VOLTAGE_MODE_LOW_SVS] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_SVS], volt);
                break;
            case CPR_VOLTAGE_MODE_LOW_SVS_L1:
                volt = lcx_map[CPR_VOLTAGE_MODE_SVS] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_SVS], volt);
                break;
            case CPR_VOLTAGE_MODE_LOW_SVS_L2:
                volt = lcx_map[CPR_VOLTAGE_MODE_NOMINAL] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_SVS], volt);
                break;
            case CPR_VOLTAGE_MODE_SVS:
                volt = ebi_map[CPR_VOLTAGE_MODE_SVS];
                break;
            case CPR_VOLTAGE_MODE_SVS_L1:
                volt = lcx_map[CPR_VOLTAGE_MODE_LOW_SVS] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_TURBO], volt);
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_SVS]);
                break;
            case CPR_VOLTAGE_MODE_SVS_L2:
                volt = lcx_map[CPR_VOLTAGE_MODE_SVS] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_TURBO], volt);
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_SVS]);
                break;
            case CPR_VOLTAGE_MODE_NOMINAL:
                volt = lcx_map[CPR_VOLTAGE_MODE_NOMINAL] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_TURBO], volt);
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_SVS]);
                break;
            case CPR_VOLTAGE_MODE_NOMINAL_L1:
                volt = lcx_map[CPR_VOLTAGE_MODE_TURBO] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_TURBO], volt);
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_SVS]);
                break;
            case CPR_VOLTAGE_MODE_NOMINAL_L2:
                volt = lcx_map[CPR_VOLTAGE_MODE_TURBO] + LCX_LDO_HEADROOM;
                volt = MIN(ebi_map[CPR_VOLTAGE_MODE_TURBO], volt);
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_SVS]);
                break;
            case CPR_VOLTAGE_MODE_TURBO:
                volt = ebi_map[CPR_VOLTAGE_MODE_TURBO];
                break;
            case CPR_VOLTAGE_MODE_TURBO_L1:
                volt = lcx_map[CPR_VOLTAGE_MODE_TURBO] + LCX_LDO_HEADROOM;
                volt = MAX(volt, ebi_map[CPR_VOLTAGE_MODE_TURBO]);
                break;
            default:
                CPR_ASSERT(0);
        }

        subModes->ceiling = volt;
        subModes->current = volt;
        subModes->min = volt;
        subModes->floor = volt;
    }
}

void cpr_image_target_map_lcx_ebi_voltages()
{
    uint32 i = 0;
    uint32 j = 0;
    uint32 lcx_map[CPR_VOLTAGE_MODE_COUNT] = {0};
    uint32 ebi_map[CPR_VOLTAGE_MODE_COUNT] = {0};

    cpr_rail_state *lcx_state = NULL;
    cpr_rail_state *ebi_state = NULL;

    if (cpr_lcx_ebi_map)
        return;

    lcx_state = cpr_utils_get_rail_state(CPR_RAIL_LPI_CX);
    for(i = 0; i < lcx_state->modeSettingsCount; i++)
    {
        cpr_mode_settings *modeSettings = &(lcx_state->modeSettings[i]);
        cpr_submode_settings *subModes = &(modeSettings->subModes[0]);

        lcx_map[i] = subModes->ceiling;
    }

    cpr_lcx_ebi_map = (uint32*)
        cpr_image_malloc(sizeof(uint32) * (lcx_state->modeSettingsCount)+1);
    if (!cpr_lcx_ebi_map)
    {
        CPR_LOG_FATAL("Fatal Error: Unable allocate memory for lcx_ebi map.");
    }
    CPR_ASSERT(cpr_lcx_ebi_map);

    ebi_state = cpr_utils_get_rail_state(CPR_RAIL_VDDA);
    for(i = 0; i < ebi_state->modeSettingsCount; i++)
    {
        cpr_mode_settings *modeSettings = &(ebi_state->modeSettings[i]);
        cpr_submode_settings *subModes = &(modeSettings->subModes[0]);

        ebi_map[i] = subModes->ceiling;
    }

    for (i = 0; i < lcx_state->modeSettingsCount; i++)
    {
        for (j = 0; j < ebi_state->modeSettingsCount; j++)
        {
            if (ebi_map[j] >= (lcx_map[i] + LCX_LDO_HEADROOM))
            {
                uint32 idx = 0;
                idx = cpr_utils_get_mode_idx(
                        cpr_utils_get_rail(CPR_RAIL_VDDA),
                        CPR_VOLTAGE_MODE_SVS);
                if (ebi_map[idx] == ebi_map[j])
                    j = idx;

                idx = cpr_utils_get_mode_idx(
                        cpr_utils_get_rail(CPR_RAIL_VDDA),
                        CPR_VOLTAGE_MODE_TURBO);
                if (ebi_map[idx] == ebi_map[j])
                    j = idx;

                cpr_lcx_ebi_map[i+1] = j+1;
                break;
            }
        }
    }
}

void cpr_image_target_extra_init(void)
{
    cpr_image_target_reinit_ebi_voltages();
    cpr_image_target_map_lcx_ebi_voltages();
}
