/*
===========================================================================

FILE:         railway_config.c

DESCRIPTION:
  Per target railway configurations

===========================================================================

                             Edit History

$Date: 2019/07/22 $

when       who     what, where, why
--------   ---     --------------------------------------------------------

===========================================================================
             Copyright (c) 2018 Qualcomm Technologies, Incorporated.
                    All Rights Reserved.
              QUALCOMM Proprietary and Confidential
===========================================================================
*/

/* -----------------------------------------------------------------------
**                           INCLUDES
** ----------------------------------------------------------------------- */

#include "railway_config.h"
#include "pm_ldo.h"
#include "pm_smps.h"
#include "pm_version.h" 

/* -----------------------------------------------------------------------
**                           DATA
** ----------------------------------------------------------------------- */

//
// BEGIN config data; should migrate to the system enumeration data method
//
static const railway_config_data_t temp_config_data =
{
    .rails     = (railway_rail_config_t[])
    {
        //Must init Mx first, as voting on the other rails will cause Mx changes to occur.
        {
            .vreg_name = "vddmx",

            // SMPS3C
            .pmic_chip_id   = 2,
            .pmic_peripheral_index = PM_SMPS_3,

            .pmic_volt_func = pm_smps_volt_level,

            .initial_corner = RAILWAY_NO_REQUEST,
            .default_retention_uv = 592000,
        },

        // VDDCX
        {
            .vreg_name = "vddcx",

            // SMPS3A
            .pmic_chip_id   = 0,
            .pmic_peripheral_index = PM_SMPS_3,

            .pmic_volt_func = pm_smps_volt_level,

            .initial_corner = RAILWAY_NO_REQUEST,
            .default_retention_uv = 352000,
        },

        // VDDA_EBI
        {
            .vreg_name = "vdda_ebi",

            // SMPS6C
            .pmic_chip_id   = 2,
            .pmic_peripheral_index = PM_SMPS_6,

            .pmic_volt_func = pm_smps_volt_level,

            .initial_corner = RAILWAY_RETENTION,
            .default_retention_uv = 352000,
        },

        // VDD_LPI_MX
        {
            .vreg_name = "vdd_lpi_mx",

            // LDO4A
            .pmic_chip_id   = 0,
            .pmic_peripheral_index = PM_LDO_4,

            .pmic_volt_func = NULL, // This rail is to just support PMIC driver to query corner voltage, and Railway driver does not call PMIC API to program its voltage.

            .initial_corner = RAILWAY_NO_REQUEST,
            .default_retention_uv = 752000,
        },

        // VDD_LPI_CX
        {
            .vreg_name = "vdd_lpi_cx",

            // LDO11A
            .pmic_chip_id   = 0,
            .pmic_peripheral_index = PM_LDO_11,

            .pmic_volt_func = pm_ldo_volt_level,

            .initial_corner = RAILWAY_NO_REQUEST,
            .default_retention_uv = 408000,
        },

#if 0
        // VDDA_WLAN
        {
            .vreg_name = "vdda_wlan",

            // LDO1A
            .pmic_chip_id   = 0,
            .pmic_peripheral_index = PM_LDO_1,

            .pmic_volt_func = NULL, // This rail is to just support PMIC driver to query corner voltage, and Railway driver does not call PMIC API to program its voltage.
                                    // WLAN voltage is programmed by PMIC driver in pm_config_ssc_active_and_retention_level().

            .initial_corner = RAILWAY_NO_REQUEST,
            .default_retention_uv = 592000,
        },
#endif
    },

    .num_rails = 5,
};
//
// END config data
//

const railway_config_data_t * const RAILWAY_CONFIG_DATA = &temp_config_data;

