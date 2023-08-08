/*******************************************************************************
 *
 * Copyright (c) 2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * QUALCOMM Proprietary and Confidential.
 *
 * THIS IS AUTO-GENERATED CPR CONFIG FILE FOR 8250.
 *
 * DateTime: 2020/08/05 13:15:28
 *
 *******************************************************************************/

#include "cpr_data.h"
#include "cpr_image_target_init.h"
#include "cpr_target_hwio.h"


//hash value of Voltage Plan file (extracted all cell values)
static char voltage_plan_hash_value[] = "75A6673B313C6F031FB64929947A1748";


/*******************************************************************************
********************************************************************************
**
** Voltage Plan Data
**
********************************************************************************
********************************************************************************/

static cpr_fuse_data  fuses_0 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_margin_cfg margins_60510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   20000, .closedLoop =       0, .maxFloorToCeil =      0 } }
};


static cpr_fuse_data  fuses_1694016851 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR2_TARG_VOLT_SVS) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_margin_cfg margins_510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =       0, .maxFloorToCeil =      0 } }
};


static cpr_fuse_data  fuses_2382754154 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR2_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


/*
 * VDDA Voltage Plan
 */
static cpr_voltage_plan voltage_plan_28862369798 =
{
    .modesCount      = 13,
    .tempAdjCfg      = NULL,
    .kvCfg           = NULL,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS_L1,
                                                    CPR_VOLTAGE_MODE_LOW_SVS_L2,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L2,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // MIN_SVS
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 700000, .freqDelta =       0, .fuses = &fuses_1694016851, .quotients = NULL, .margins = &margins_60510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  800000, .floor =  700000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // SVS_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 876000, .freqDelta =       0, .fuses = &fuses_2382754154, .quotients = NULL, .margins = &margins_510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  924000, .floor =  876000, .freq =       0, .interplEnabled = 0} } },

        // TURBO_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_version  ver_ANY_1_0_1_255 = { .foundry = CPR_FOUNDRY_ANY, .min = CPR_CHIPINFO_VERSION(1,0), .max = CPR_CHIPINFO_VERSION(1,255) };


static cpr_margin_cfg margins_1772052 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   30000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 3, .openLoop =   30000, .closedLoop =  100000, .maxFloorToCeil =  40000 },
                                  { .cprRevMin = 4, .cprRevMax = 7, .openLoop =       0, .closedLoop =  100000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_10566508410 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  342 },
                                      { .ro = 10, .quotient =  314 },
                                      { .ro = 11, .quotient =  579 },
                                      { .ro = 15, .quotient =  246 } },
};


static cpr_fuse_data  fuses_3666170035 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_SVSP) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_OFFSET_SVSP) } } },
};


static cpr_margin_cfg margins_1832052 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   40000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 3, .openLoop =   40000, .closedLoop =  100000, .maxFloorToCeil =  40000 },
                                  { .cprRevMin = 4, .cprRevMax = 7, .openLoop =       0, .closedLoop =  100000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_8317677713 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  885 },
                                      { .ro =  4, .quotient =  435 },
                                      { .ro =  6, .quotient =  477 } },
};


static cpr_fuse_data  fuses_1142532938 =
{
    .volt       = (cpr_fuse[]) { {.count = 2, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_NOM_4_2), CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR3_TARG_VOLT_NOM_1_0) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_margin_cfg margins_1952052 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   40000, .closedLoop =  108000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 3, .openLoop =   40000, .closedLoop =  108000, .maxFloorToCeil =  40000 },
                                  { .cprRevMin = 4, .cprRevMax = 7, .openLoop =       0, .closedLoop =  108000, .maxFloorToCeil =  40000 } }
};


static cpr_fuse_data  fuses_3114445330 =
{
    .volt       = (cpr_fuse[]) { {.count = 2, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_NOM_4_2), CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR3_TARG_VOLT_NOM_1_0) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_1562052 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   20000, .closedLoop =   90000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 3, .openLoop =   20000, .closedLoop =   90000, .maxFloorToCeil =  40000 },
                                  { .cprRevMin = 4, .cprRevMax = 7, .openLoop =       0, .closedLoop =   90000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_5429091337 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  985 },
                                      { .ro =  4, .quotient =  505 },
                                      { .ro =  6, .quotient =  541 } },
};


static cpr_fuse_data  fuses_4170416617 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR3_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_margin_cfg margins_1556052 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   20000, .closedLoop =   88000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 3, .openLoop =   20000, .closedLoop =   88000, .maxFloorToCeil =  52000 },
                                  { .cprRevMin = 4, .cprRevMax = 7, .openLoop =       0, .closedLoop =   88000, .maxFloorToCeil =  52000 } }
};


static cpr_fuse_data  fuses_8073460590 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR3_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_OFFSET_TUR) } } },
};


static cpr_margin_cfg margins_744030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =   68000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =       0, .closedLoop =   68000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_5334690195 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient = 1049 },
                                      { .ro =  4, .quotient =  551 },
                                      { .ro =  6, .quotient =  579 } },
};


static cpr_fuse_data  fuses_3964037928 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_LSB, CPR3_TARG_VOLT_SUT) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW16_MSB, CPR3_TARG_VOLT_OFFSET_SUT) } } },
};


static cpr_kv_cfg  kvs_33437363675 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  290 },
                                { .ro =  2, .kv =  252 },
                                { .ro =  3, .kv =    0 },
                                { .ro =  4, .kv =  161 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =  162 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =  168 },
                                { .ro = 11, .kv =  234 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =    0 },
                                { .ro = 15, .kv =  153 } },
};


/*
 * MX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_18144006517 =
{
    .modesCount      = 8,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_33437363675,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  512000, .floor =  512000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3666170035, .quotients = &quotients_10566508410, .margins = &margins_1772052,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L2
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_1142532938, .quotients = &quotients_8317677713, .margins = &margins_1832052,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  806000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3114445330, .quotients = &quotients_8317677713, .margins = &margins_1952052,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_4170416617, .quotients = &quotients_5429091337, .margins = &margins_1562052,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  852000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_8073460590, .quotients = &quotients_5429091337, .margins = &margins_1556052,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  852000, .floor =  800000, .freq =       0, .interplEnabled = 0} } },

        // TURBO_L1
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_3964037928, .quotients = &quotients_5334690195, .margins = &margins_744030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  884000, .floor =  800000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_234510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   -7000, .closedLoop =   43000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_13633927841 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  9, .quotient =  167 },
                                      { .ro = 11, .quotient =  224 },
                                      { .ro = 14, .quotient =  341 },
                                      { .ro = 15, .quotient =  190 } },
};


static cpr_fuse_data  fuses_2871295804 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_SVS2) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_MSB, CPR6_TARG_VOLT_OFFSET_SVS2) } } },
};


static cpr_margin_cfg margins_252510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -11000, .closedLoop =   49000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_7761367675 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  9, .quotient =  260 },
                                      { .ro = 11, .quotient =  326 },
                                      { .ro = 14, .quotient =  474 },
                                      { .ro = 15, .quotient =  307 } },
};


static cpr_fuse_data  fuses_3704899208 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_SVS) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_MSB, CPR6_TARG_VOLT_OFFSET_SVS) } } },
};


static cpr_margin_cfg margins_388510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =    1000, .closedLoop =   69000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_5808593466 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  9, .quotient =  352 },
                                      { .ro = 11, .quotient =  427 },
                                      { .ro = 14, .quotient =  606 } },
};


static cpr_fuse_data  fuses_3950427257 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_OFFSET_SVSP) } } },
};


static cpr_margin_cfg margins_408510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =    1000, .closedLoop =   73000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11305325705 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  660 },
                                      { .ro =  3, .quotient =  725 },
                                      { .ro =  5, .quotient =  593 },
                                      { .ro =  7, .quotient =  663 },
                                      { .ro = 12, .quotient =  680 },
                                      { .ro = 13, .quotient =  614 } },
};


static cpr_fuse_data  fuses_3044147479 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_NOM) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_732510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   85000, .closedLoop =   85000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_12443715829 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  793 },
                                      { .ro =  3, .quotient =  848 },
                                      { .ro =  5, .quotient =  713 },
                                      { .ro =  7, .quotient =  776 },
                                      { .ro = 12, .quotient =  837 },
                                      { .ro = 13, .quotient =  754 } },
};


static cpr_fuse_data  fuses_4306377963 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW18_LSB, CPR6_TARG_VOLT_OFFSET_TUR) } } },
};


static cpr_kv_cfg  kvs_36443367230 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  216 },
                                { .ro =  2, .kv =    0 },
                                { .ro =  3, .kv =  214 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =  200 },
                                { .ro =  6, .kv =    0 },
                                { .ro =  7, .kv =  204 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =  221 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =  238 },
                                { .ro = 12, .kv =  229 },
                                { .ro = 13, .kv =  213 },
                                { .ro = 14, .kv =  300 },
                                { .ro = 15, .kv =  248 } },
};


/*
 * MM Voltage Plan
 */
static cpr_voltage_plan voltage_plan_9802866628 =
{
    .modesCount      = 5,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_36443367230,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_2871295804, .quotients = &quotients_13633927841, .margins = &margins_234510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_3704899208, .quotients = &quotients_7761367675, .margins = &margins_252510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_3950427257, .quotients = &quotients_5808593466, .margins = &margins_388510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 45} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3044147479, .quotients = &quotients_11305325705, .margins = &margins_408510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_4306377963, .quotients = &quotients_12443715829, .margins = &margins_732510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  904000, .floor =  712000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_version  ver_ANY_2_0_2_255 = { .foundry = CPR_FOUNDRY_ANY, .min = CPR_CHIPINFO_VERSION(2,0), .max = CPR_CHIPINFO_VERSION(2,255) };


static cpr_margin_cfg margins_522030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =   59000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   44000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_6610077381 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  326 },
                                      { .ro =  2, .quotient =  263 },
                                      { .ro = 14, .quotient =  343 },
                                      { .ro = 15, .quotient =  206 } },
};


static cpr_fuse_data  fuses_2367745890 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_SVS3) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_MSB, CPR0_TARG_VOLT_OFFSET_SVS3) } } },
};


static cpr_margin_cfg margins_2306030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   64000, .closedLoop =  199000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   49000, .closedLoop =  184000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_6299897944 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  431 },
                                      { .ro =  2, .quotient =  347 },
                                      { .ro = 14, .quotient =  473 } },
};


static cpr_fuse_data  fuses_5815244772 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_SVS) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_MSB, CPR0_TARG_VOLT_OFFSET_SVS) } } },
};


static cpr_margin_cfg margins_2460030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   68000, .closedLoop =  212000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   53000, .closedLoop =  197000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_5194719836 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  519 },
                                      { .ro =  2, .quotient =  423 },
                                      { .ro = 14, .quotient =  591 } },
};


static cpr_margin_cfg margins_992030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =  106000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   91000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_4899082825 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  508 },
                                      { .ro =  2, .quotient =  557 },
                                      { .ro = 14, .quotient =  786 } },
};


static cpr_fuse_data  fuses_2317888483 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_NOM) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_margin_cfg margins_962030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =  103000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   88000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_8608835402 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  587 },
                                      { .ro =  2, .quotient =  631 },
                                      { .ro = 14, .quotient =  939 } },
};


static cpr_margin_cfg margins_784030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =   84000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   69000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_6697576589 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  638 },
                                      { .ro =  2, .quotient =  671 },
                                      { .ro = 14, .quotient = 1009 } },
};


static cpr_margin_cfg margins_824030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =       0, .closedLoop =   88000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   73000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_6029187693 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  710 },
                                      { .ro =  2, .quotient =  747 },
                                      { .ro = 14, .quotient = 1125 } },
};


static cpr_fuse_data  fuses_6501131299 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_SUT) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_OFFSET_SUT) } } },
};


static cpr_kv_cfg  kvs_36955321786 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =  177 },
                                { .ro =  1, .kv =  227 },
                                { .ro =  2, .kv =  183 },
                                { .ro =  3, .kv =    0 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =    0 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =    0 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =  281 },
                                { .ro = 15, .kv =  262 } },
};


/*
 * CX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_13857388116 =
{
    .modesCount      = 8,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_36955321786,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_2367745890, .quotients = &quotients_6610077381, .margins = &margins_522030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_5815244772, .quotients = &quotients_6299897944, .margins = &margins_2306030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_5194719836, .margins = &margins_2460030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 45} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_2317888483, .quotients = &quotients_4899082825, .margins = &margins_992030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_8608835402, .margins = &margins_962030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  852000, .floor =  688000, .freq =       0, .interplEnabled = 36} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_6697576589, .margins = &margins_784030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  884000, .floor =  712000, .freq =       0, .interplEnabled = 60} } },

        // TURBO_L1
        {.fref = 888000, .freqDelta =       0, .fuses = &fuses_6501131299, .quotients = &quotients_6029187693, .margins = &margins_824030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  952000, .floor =  756000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_175510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   36000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_16827190411 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  234 },
                                      { .ro =  2, .quotient =  278 },
                                      { .ro =  4, .quotient =  200 },
                                      { .ro =  6, .quotient =  236 },
                                      { .ro = 14, .quotient =  341 },
                                      { .ro = 15, .quotient =  190 } },
};


static cpr_margin_cfg margins_220510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   45000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_15517318755 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  314 },
                                      { .ro =  2, .quotient =  365 },
                                      { .ro =  4, .quotient =  274 },
                                      { .ro =  6, .quotient =  317 },
                                      { .ro = 14, .quotient =  474 },
                                      { .ro = 15, .quotient =  307 } },
};


static cpr_margin_cfg margins_330510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   -5000, .closedLoop =   61000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_12888842546 =
{
    .count = 5,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  394 },
                                      { .ro =  2, .quotient =  452 },
                                      { .ro =  4, .quotient =  348 },
                                      { .ro =  6, .quotient =  398 },
                                      { .ro = 14, .quotient =  606 } },
};


static cpr_margin_cfg margins_270510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   55000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11570532166 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  660 },
                                      { .ro =  2, .quotient =  556 },
                                      { .ro =  5, .quotient =  593 },
                                      { .ro =  6, .quotient =  495 },
                                      { .ro = 12, .quotient =  680 },
                                      { .ro = 13, .quotient =  614 } },
};


static cpr_margin_cfg margins_250510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   51000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_13215831966 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  740 },
                                      { .ro =  2, .quotient =  623 },
                                      { .ro =  5, .quotient =  665 },
                                      { .ro =  6, .quotient =  557 },
                                      { .ro = 12, .quotient =  774 },
                                      { .ro = 13, .quotient =  698 } },
};


static cpr_margin_cfg margins_302510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   59000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_17780212324 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  793 },
                                      { .ro =  2, .quotient =  668 },
                                      { .ro =  5, .quotient =  713 },
                                      { .ro =  6, .quotient =  598 },
                                      { .ro = 12, .quotient =  837 },
                                      { .ro = 13, .quotient =  754 } },
};


static cpr_margin_cfg margins_307510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   60000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_11364712478 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  882 },
                                      { .ro =  2, .quotient =  743 },
                                      { .ro =  5, .quotient =  792 },
                                      { .ro =  6, .quotient =  667 },
                                      { .ro = 12, .quotient =  941 },
                                      { .ro = 13, .quotient =  848 } },
};


static cpr_kv_cfg  kvs_34460596781 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =  187 },
                                { .ro =  1, .kv =  208 },
                                { .ro =  2, .kv =  193 },
                                { .ro =  3, .kv =    0 },
                                { .ro =  4, .kv =  171 },
                                { .ro =  5, .kv =  206 },
                                { .ro =  6, .kv =  182 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =    0 },
                                { .ro = 12, .kv =  222 },
                                { .ro = 13, .kv =  208 },
                                { .ro = 14, .kv =  300 },
                                { .ro = 15, .kv =  250 } },
};


/*
 * CX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_15738514936 =
{
    .modesCount      = 8,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_34460596781,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_2367745890, .quotients = &quotients_16827190411, .margins = &margins_175510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_5815244772, .quotients = &quotients_15517318755, .margins = &margins_220510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_12888842546, .margins = &margins_330510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 45} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_2317888483, .quotients = &quotients_11570532166, .margins = &margins_270510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_13215831966, .margins = &margins_250510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  872000, .floor =  688000, .freq =       0, .interplEnabled = 36} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_17780212324, .margins = &margins_302510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  904000, .floor =  712000, .freq =       0, .interplEnabled = 60} } },

        // TURBO_L1
        {.fref = 888000, .freqDelta =       0, .fuses = &fuses_6501131299, .quotients = &quotients_11364712478, .margins = &margins_307510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  972000, .floor =  756000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_1072030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =   54000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   85000, .closedLoop =   39000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_7762150352 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  326 },
                                      { .ro =  3, .quotient =  383 },
                                      { .ro =  6, .quotient =  211 },
                                      { .ro =  9, .quotient =  174 },
                                      { .ro = 11, .quotient =  225 },
                                      { .ro = 14, .quotient =  343 } },
};


static cpr_margin_cfg margins_1622030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =  109000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   85000, .closedLoop =   94000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_15930203146 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  431 },
                                      { .ro =  3, .quotient =  493 },
                                      { .ro =  6, .quotient =  290 },
                                      { .ro =  9, .quotient =  269 },
                                      { .ro = 11, .quotient =  328 },
                                      { .ro = 14, .quotient =  473 } },
};


static cpr_margin_cfg margins_1532030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   85000, .closedLoop =   85000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_14130033802 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  519 },
                                      { .ro =  3, .quotient =  590 },
                                      { .ro =  6, .quotient =  362 },
                                      { .ro =  9, .quotient =  348 },
                                      { .ro = 11, .quotient =  419 },
                                      { .ro = 14, .quotient =  591 } },
};


static cpr_quotient_cfg  quotients_5308297050 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  508 },
                                      { .ro =  2, .quotient =  557 },
                                      { .ro =  6, .quotient =  479 },
                                      { .ro = 14, .quotient =  786 } },
};


static cpr_margin_cfg margins_1544030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   85000, .closedLoop =   85000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_10465050593 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  638 },
                                      { .ro =  2, .quotient =  671 },
                                      { .ro =  6, .quotient =  584 },
                                      { .ro = 14, .quotient = 1009 } },
};


static cpr_kv_cfg  kvs_30044557987 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =  177 },
                                { .ro =  1, .kv =  227 },
                                { .ro =  2, .kv =  173 },
                                { .ro =  3, .kv =  231 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =  170 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =  211 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =  230 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =  281 },
                                { .ro = 15, .kv =    0 } },
};


/*
 * MM Voltage Plan
 */
static cpr_voltage_plan voltage_plan_12602973459 =
{
    .modesCount      = 5,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_30044557987,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_2871295804, .quotients = &quotients_7762150352, .margins = &margins_1072030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_3704899208, .quotients = &quotients_15930203146, .margins = &margins_1622030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_3950427257, .quotients = &quotients_14130033802, .margins = &margins_1532030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 45} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3044147479, .quotients = &quotients_5308297050, .margins = &margins_1532030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_4306377963, .quotients = &quotients_10465050593, .margins = &margins_1544030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  884000, .floor =  712000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_230510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   47000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_16091256850 =
{
    .count = 5,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  278 },
                                      { .ro =  5, .quotient =  284 },
                                      { .ro =  6, .quotient =  236 },
                                      { .ro = 12, .quotient =  341 },
                                      { .ro = 13, .quotient =  293 } },
};


static cpr_fuse_data  fuses_3216257589 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_SVS3) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_MSB, CPR1_TARG_VOLT_OFFSET_SVS2) } } },
};


static cpr_margin_cfg margins_255510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   52000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_8703469307 =
{
    .count = 5,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  365 },
                                      { .ro =  5, .quotient =  381 },
                                      { .ro =  6, .quotient =  317 },
                                      { .ro = 12, .quotient =  447 },
                                      { .ro = 13, .quotient =  393 } },
};


static cpr_fuse_data  fuses_5290104314 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_SVS) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_MSB, CPR1_TARG_VOLT_OFFSET_SVS) } } },
};


static cpr_quotient_cfg  quotients_12606628408 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  536 },
                                      { .ro =  2, .quotient =  452 },
                                      { .ro =  5, .quotient =  477 },
                                      { .ro =  6, .quotient =  398 },
                                      { .ro = 12, .quotient =  553 },
                                      { .ro = 13, .quotient =  493 } },
};


static cpr_fuse_data  fuses_2973793400 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW26_LSB, CPR1_TARG_VOLT_SVSP) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_305510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   62000, .maxFloorToCeil =  40000 } }
};


static cpr_margin_cfg margins_235510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   48000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11365741856 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  587 },
                                      { .ro =  2, .quotient =  495 },
                                      { .ro =  5, .quotient =  526 },
                                      { .ro =  6, .quotient =  438 },
                                      { .ro = 12, .quotient =  606 },
                                      { .ro = 13, .quotient =  543 } },
};


static cpr_fuse_data  fuses_3251849405 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_OFFSET_TUR) } } },
};


static cpr_margin_cfg margins_275510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   56000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_8745327652 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  556 },
                                      { .ro =  3, .quotient =  725 },
                                      { .ro =  6, .quotient =  495 },
                                      { .ro =  7, .quotient =  663 },
                                      { .ro = 12, .quotient =  680 },
                                      { .ro = 13, .quotient =  614 } },
};


static cpr_fuse_data  fuses_5003898097 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_NOM) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_240510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   49000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_15860687498 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  623 },
                                      { .ro =  3, .quotient =  798 },
                                      { .ro =  6, .quotient =  557 },
                                      { .ro =  7, .quotient =  731 },
                                      { .ro = 12, .quotient =  774 },
                                      { .ro = 13, .quotient =  698 } },
};


static cpr_fuse_data  fuses_2994076081 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_MSB, CPR1_TARG_VOLT_OFFSET_SVS3) } } },
};


static cpr_margin_cfg margins_262510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   51000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_13299691923 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  668 },
                                      { .ro =  3, .quotient =  848 },
                                      { .ro =  6, .quotient =  598 },
                                      { .ro =  7, .quotient =  776 },
                                      { .ro = 12, .quotient =  837 },
                                      { .ro = 13, .quotient =  754 } },
};


static cpr_fuse_data  fuses_1947409653 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_OFFSET_TUR) } } },
};


static cpr_margin_cfg margins_287510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =  -15000, .closedLoop =   56000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_9893439965 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  743 },
                                      { .ro =  3, .quotient =  930 },
                                      { .ro =  6, .quotient =  667 },
                                      { .ro =  7, .quotient =  852 },
                                      { .ro = 12, .quotient =  941 },
                                      { .ro = 13, .quotient =  848 } },
};


static cpr_fuse_data  fuses_7629238025 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_SUT) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_OFFSET_SUT) } } },
};


static cpr_kv_cfg  kvs_35239998080 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  229 },
                                { .ro =  2, .kv =  193 },
                                { .ro =  3, .kv =  207 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =  218 },
                                { .ro =  6, .kv =  188 },
                                { .ro =  7, .kv =  196 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =    0 },
                                { .ro = 12, .kv =  236 },
                                { .ro = 13, .kv =  218 },
                                { .ro = 14, .kv =    0 },
                                { .ro = 15, .kv =    0 } },
};


/*
 * GFX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_20949076712 =
{
    .modesCount      = 10,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_35239998080,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L0,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // MIN_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_3216257589, .quotients = &quotients_16091256850, .margins = &margins_230510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_3216257589, .quotients = &quotients_16091256850, .margins = &margins_230510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_5290104314, .quotients = &quotients_8703469307, .margins = &margins_255510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L0
        {.fref = 668000, .freqDelta =       0, .fuses = &fuses_2973793400, .quotients = &quotients_12606628408, .margins = &margins_230510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  780000, .floor =  584000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_2973793400, .quotients = &quotients_12606628408, .margins = &margins_305510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L2
        {.fref = 712000, .freqDelta =       0, .fuses = &fuses_3251849405, .quotients = &quotients_11365741856, .margins = &margins_235510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  828000, .floor =  624000, .freq =       0, .interplEnabled = 42} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_5003898097, .quotients = &quotients_8745327652, .margins = &margins_275510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_2994076081, .quotients = &quotients_15860687498, .margins = &margins_240510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  872000, .floor =  688000, .freq =       0, .interplEnabled = 36} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_1947409653, .quotients = &quotients_13299691923, .margins = &margins_262510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  904000, .floor =  712000, .freq =       0, .interplEnabled = 60} } },

        // TURBO_L1
        {.fref = 888000, .freqDelta =       0, .fuses = &fuses_7629238025, .quotients = &quotients_9893439965, .margins = &margins_287510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  972000, .floor =  756000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_fuse_data  fuses_4033748028 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR4_TARG_VOLT_NOM) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


static cpr_fuse_data  fuses_2606158213 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR4_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = NULL,
};


/*
 * LPI_MX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_8900074785 =
{
    .modesCount      = 4,
    .tempAdjCfg      = NULL,
    .kvCfg           = NULL,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_4033748028, .quotients = NULL, .margins = &margins_510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_2606158213, .quotients = NULL, .margins = &margins_510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  872000, .floor =  800000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_351510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   12000, .closedLoop =   55000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_14715894283 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  240 },
                                      { .ro =  3, .quotient =  293 },
                                      { .ro =  5, .quotient =  205 },
                                      { .ro =  7, .quotient =  250 },
                                      { .ro = 12, .quotient =  243 },
                                      { .ro = 14, .quotient =  241 } },
};


static cpr_fuse_data  fuses_3591947972 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR5_TARG_VOLT_SVS3) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_MSB, CPR5_TARG_VOLT_OFFSET_SVS3) } } },
};


static cpr_margin_cfg margins_421510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   12000, .closedLoop =   69000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_18965660421 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  328 },
                                      { .ro =  3, .quotient =  398 },
                                      { .ro =  5, .quotient =  284 },
                                      { .ro =  7, .quotient =  343 },
                                      { .ro = 12, .quotient =  341 },
                                      { .ro = 14, .quotient =  341 } },
};


static cpr_fuse_data  fuses_707170720 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_MSB, CPR5_TARG_VOLT_OFFSET_SVS2) } } },
};


static cpr_margin_cfg margins_337510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =    4000, .closedLoop =   57000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_10093605264 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  432 },
                                      { .ro =  3, .quotient =  500 },
                                      { .ro =  5, .quotient =  381 },
                                      { .ro =  7, .quotient =  443 },
                                      { .ro = 12, .quotient =  447 },
                                      { .ro = 14, .quotient =  474 } },
};


static cpr_fuse_data  fuses_4480305658 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR5_TARG_VOLT_SVS) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_MSB, CPR5_TARG_VOLT_OFFSET_SVS) } } },
};


static cpr_margin_cfg margins_406510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   12000, .closedLoop =   66000, .maxFloorToCeil =  40000 } }
};


static cpr_fuse_data  fuses_4698560082 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR5_TARG_VOLT_NOM) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_MSB, CPR5_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_327510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =   55000, .maxFloorToCeil =  52000 } }
};


static cpr_fuse_data  fuses_4800099391 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR5_TARG_VOLT_TUR) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 2, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_MSB, CPR5_TARG_VOLT_OFFSET_TUR_3_2), CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW17_LSB, CPR5_TARG_VOLT_OFFSET_TUR_1_0) } } },
};


static cpr_kv_cfg  kvs_38971790019 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  236 },
                                { .ro =  2, .kv =  190 },
                                { .ro =  3, .kv =  240 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =  217 },
                                { .ro =  6, .kv =  180 },
                                { .ro =  7, .kv =  225 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =    0 },
                                { .ro = 12, .kv =  240 },
                                { .ro = 13, .kv =  214 },
                                { .ro = 14, .kv =  282 },
                                { .ro = 15, .kv =    0 } },
};


/*
 * LPI_CX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_13089863594 =
{
    .modesCount      = 6,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_38971790019,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // MIN_SVS
        {.fref = 520000, .freqDelta =       0, .fuses = &fuses_3591947972, .quotients = &quotients_14715894283, .margins = &margins_351510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  608000, .floor =  480000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 576000, .freqDelta =       0, .fuses = &fuses_707170720, .quotients = &quotients_18965660421, .margins = &margins_421510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  504000, .freq =       0, .interplEnabled = 50} } },

        // SVS
        {.fref = 624000, .freqDelta =       0, .fuses = &fuses_4480305658, .quotients = &quotients_10093605264, .margins = &margins_337510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  736000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_4698560082, .quotients = &quotients_8745327652, .margins = &margins_406510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  648000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_4800099391, .quotients = &quotients_13299691923, .margins = &margins_327510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  904000, .floor =  712000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_769040 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 1, .openLoop =   20000, .closedLoop =   47000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 2, .cprRevMax = 2, .openLoop =   10000, .closedLoop =   47000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   -5000, .closedLoop =   32000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_6172470196 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  159 },
                                      { .ro =  3, .quotient =  282 },
                                      { .ro =  4, .quotient =  123 },
                                      { .ro =  9, .quotient =   96 },
                                      { .ro = 11, .quotient =  139 },
                                      { .ro = 15, .quotient =  108 } },
};


static cpr_fuse_data  fuses_3215175064 =
{
    .volt       = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_LSB, CPR1_TARG_VOLT_SVS3) } } },
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_MSB, CPR1_TARG_VOLT_OFFSET_SVS3) } } },
};


static cpr_margin_cfg margins_934040 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 1, .openLoop =   20000, .closedLoop =   60000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 2, .cprRevMax = 2, .openLoop =    5000, .closedLoop =   60000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -10000, .closedLoop =   45000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11543589914 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  233 },
                                      { .ro =  3, .quotient =  383 },
                                      { .ro =  4, .quotient =  189 },
                                      { .ro =  9, .quotient =  174 },
                                      { .ro = 11, .quotient =  225 },
                                      { .ro = 15, .quotient =  206 } },
};


static cpr_fuse_data  fuses_2995158606 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW15_MSB, CPR1_TARG_VOLT_OFFSET_SVS2) } } },
};


static cpr_margin_cfg margins_1069040 = {
    .count = 3,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 1, .openLoop =   20000, .closedLoop =   71000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 2, .cprRevMax = 2, .openLoop =       0, .closedLoop =   71000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  -15000, .closedLoop =   56000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11569655587 =
{
    .count = 6,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  314 },
                                      { .ro =  3, .quotient =  493 },
                                      { .ro =  4, .quotient =  260 },
                                      { .ro =  9, .quotient =  269 },
                                      { .ro = 11, .quotient =  328 },
                                      { .ro = 14, .quotient =  473 } },
};


static cpr_margin_cfg margins_1142030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   30000, .closedLoop =  103000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   15000, .closedLoop =   88000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_12237371318 =
{
    .count = 5,
    .quots = (cpr_quotient[]) { { .ro =  0, .quotient =  380 },
                                      { .ro =  3, .quotient =  590 },
                                      { .ro =  4, .quotient =  322 },
                                      { .ro =  6, .quotient =  362 },
                                      { .ro = 14, .quotient =  591 } },
};


static cpr_fuse_data  fuses_2379285428 =
{
    .volt       = NULL,
    .quot       = NULL,
    .rosel      = NULL,
    .quotOffset = NULL,
    .voltOffset = (cpr_fuse[]) { {.count = 1, .data = (struct raw_fuse_data[]) { CPR_FUSE_MAPPING(QFPROM_CORR_CALIB_ROW14_LSB, CPR0_TARG_VOLT_OFFSET_NOM) } } },
};


static cpr_margin_cfg margins_1398030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   46000, .closedLoop =  119000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   31000, .closedLoop =  104000, .maxFloorToCeil =  40000 } }
};


static cpr_margin_cfg margins_1958030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   81000, .closedLoop =  154000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   66000, .closedLoop =  139000, .maxFloorToCeil =  40000 } }
};


static cpr_margin_cfg margins_1772030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   80000, .closedLoop =  152000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   45000, .closedLoop =  117000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_3669787938 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  557 },
                                      { .ro =  3, .quotient =  740 },
                                      { .ro =  6, .quotient =  479 } },
};


static cpr_margin_cfg margins_1686030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   69000, .closedLoop =  134000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   54000, .closedLoop =  119000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_10123695534 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  631 },
                                      { .ro =  3, .quotient =  823 },
                                      { .ro =  6, .quotient =  546 } },
};


static cpr_margin_cfg margins_1566030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   62000, .closedLoop =  125000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   47000, .closedLoop =  110000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_9981130095 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  671 },
                                      { .ro =  3, .quotient =  867 },
                                      { .ro =  6, .quotient =  584 } },
};


static cpr_margin_cfg margins_1494030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =   50000, .closedLoop =  125000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =   35000, .closedLoop =  110000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_4779938346 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  2, .quotient =  747 },
                                      { .ro =  3, .quotient =  948 },
                                      { .ro =  6, .quotient =  648 } },
};


static cpr_kv_cfg  kvs_33245330358 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =  180 },
                                { .ro =  1, .kv =    0 },
                                { .ro =  2, .kv =  172 },
                                { .ro =  3, .kv =  177 },
                                { .ro =  4, .kv =  218 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =  168 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =  163 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =  215 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =  289 },
                                { .ro = 15, .kv =  186 } },
};


/*
 * GFX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_21769369217 =
{
    .modesCount      = 10,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_33245330358,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L0,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // MIN_SVS
        {.fref = 516000, .freqDelta =       0, .fuses = &fuses_3215175064, .quotients = &quotients_6172470196, .margins = &margins_769040,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  612000, .floor =  484000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 572000, .freqDelta =       0, .fuses = &fuses_2995158606, .quotients = &quotients_11543589914, .margins = &margins_934040,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  500000, .freq =       0, .interplEnabled = 50} } },

        // SVS
        {.fref = 628000, .freqDelta =       0, .fuses = &fuses_5290104314, .quotients = &quotients_11569655587, .margins = &margins_1069040,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  732000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L0
        {.fref = 668000, .freqDelta =       0, .fuses = &fuses_2379285428, .quotients = &quotients_12237371318, .margins = &margins_1142030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  780000, .floor =  584000, .freq =       0, .interplEnabled = 45} } },

        // SVS_L1
        {.fref = 684000, .freqDelta =       0, .fuses = &fuses_2379285428, .quotients = &quotients_12237371318, .margins = &margins_1398030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  600000, .freq =       0, .interplEnabled = 45} } },

        // SVS_L2
        {.fref = 712000, .freqDelta =       0, .fuses = &fuses_2379285428, .quotients = &quotients_12237371318, .margins = &margins_1958030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  806000, .floor =  624000, .freq =       0, .interplEnabled = 45} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_5003898097, .quotients = &quotients_3669787938, .margins = &margins_1772030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  652000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_0, .quotients = &quotients_10123695534, .margins = &margins_1686030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  852000, .floor =  688000, .freq =       0, .interplEnabled = 36} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_1947409653, .quotients = &quotients_9981130095, .margins = &margins_1566030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  884000, .floor =  712000, .freq =       0, .interplEnabled = 60} } },

        // TURBO_L1
        {.fref = 888000, .freqDelta =       0, .fuses = &fuses_7629238025, .quotients = &quotients_4779938346, .margins = &margins_1494030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  952000, .floor =  756000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_300014 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 7, .openLoop =  100000, .closedLoop =       0, .maxFloorToCeil =      0 } }
};


/*
 * LPI_MX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_7978261066 =
{
    .modesCount      = 4,
    .tempAdjCfg      = NULL,
    .kvCfg           = NULL,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_4033748028, .quotients = NULL, .margins = &margins_300014,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_2606158213, .quotients = NULL, .margins = &margins_300014,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  848000, .floor =  800000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_1652030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_8405909993 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  231 },
                                      { .ro =  3, .quotient =  282 },
                                      { .ro = 14, .quotient =  224 } },
};


static cpr_quotient_cfg  quotients_3270158949 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  326 },
                                      { .ro =  3, .quotient =  383 },
                                      { .ro = 14, .quotient =  343 } },
};


static cpr_quotient_cfg  quotients_6082795524 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  431 },
                                      { .ro =  3, .quotient =  493 },
                                      { .ro = 14, .quotient =  473 } },
};


static cpr_quotient_cfg  quotients_2698386154 =
{
    .count = 2,
    .quots = (cpr_quotient[]) { { .ro =  6, .quotient =  479 },
                                      { .ro =  7, .quotient =  649 } },
};


static cpr_margin_cfg margins_1664030 = {
    .count = 2,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 2, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  12000 },
                                  { .cprRevMin = 3, .cprRevMax = 7, .openLoop =  100000, .closedLoop =  100000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_6757208219 =
{
    .count = 2,
    .quots = (cpr_quotient[]) { { .ro =  6, .quotient =  584 },
                                      { .ro =  7, .quotient =  765 } },
};


static cpr_kv_cfg  kvs_30291495762 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  215 },
                                { .ro =  2, .kv =    0 },
                                { .ro =  3, .kv =  218 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =  162 },
                                { .ro =  7, .kv =  179 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =    0 },
                                { .ro = 11, .kv =    0 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =  272 },
                                { .ro = 15, .kv =    0 } },
};


/*
 * LPI_CX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_13570562393 =
{
    .modesCount      = 6,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_30291495762,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_TURBO },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // MIN_SVS
        {.fref = 520000, .freqDelta =       0, .fuses = &fuses_3591947972, .quotients = &quotients_8405909993, .margins = &margins_1652030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  608000, .floor =  480000, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref = 576000, .freqDelta =       0, .fuses = &fuses_707170720, .quotients = &quotients_3270158949, .margins = &margins_1652030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  672000, .floor =  504000, .freq =       0, .interplEnabled = 50} } },

        // SVS
        {.fref = 624000, .freqDelta =       0, .fuses = &fuses_4480305658, .quotients = &quotients_6082795524, .margins = &margins_1652030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  736000, .floor =  552000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_4698560082, .quotients = &quotients_2698386154, .margins = &margins_1652030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  816000, .floor =  648000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_4800099391, .quotients = &quotients_6757208219, .margins = &margins_1664030,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  880000, .floor =  712000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_540510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =  100000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_5730980563 =
{
    .count = 3,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  611 },
                                      { .ro = 10, .quotient =  330 },
                                      { .ro = 11, .quotient =  590 } },
};


static cpr_margin_cfg margins_395510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =   71000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_6991099530 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  744 },
                                      { .ro =  2, .quotient =  885 },
                                      { .ro = 10, .quotient =  406 },
                                      { .ro = 11, .quotient =  702 } },
};


static cpr_margin_cfg margins_375510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =   67000, .maxFloorToCeil =  40000 } }
};


static cpr_quotient_cfg  quotients_11399431474 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  828 },
                                      { .ro =  2, .quotient =  979 },
                                      { .ro = 10, .quotient =  452 },
                                      { .ro = 11, .quotient =  787 } },
};


static cpr_margin_cfg margins_382510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =   66000, .maxFloorToCeil =  52000 } }
};


static cpr_margin_cfg margins_402510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =       0, .closedLoop =   70000, .maxFloorToCeil =  52000 } }
};


static cpr_quotient_cfg  quotients_10180672154 =
{
    .count = 4,
    .quots = (cpr_quotient[]) { { .ro =  1, .quotient =  934 },
                                      { .ro =  2, .quotient = 1046 },
                                      { .ro = 10, .quotient =  517 },
                                      { .ro = 11, .quotient =  851 } },
};


static cpr_kv_cfg  kvs_36769019966 =
{
    .count = 16,
    .kvs   = (cpr_kv[]) { { .ro =  0, .kv =    0 },
                                { .ro =  1, .kv =  314 },
                                { .ro =  2, .kv =  286 },
                                { .ro =  3, .kv =    0 },
                                { .ro =  4, .kv =    0 },
                                { .ro =  5, .kv =    0 },
                                { .ro =  6, .kv =    0 },
                                { .ro =  7, .kv =    0 },
                                { .ro =  8, .kv =    0 },
                                { .ro =  9, .kv =    0 },
                                { .ro = 10, .kv =  185 },
                                { .ro = 11, .kv =  253 },
                                { .ro = 12, .kv =    0 },
                                { .ro = 13, .kv =    0 },
                                { .ro = 14, .kv =    0 },
                                { .ro = 15, .kv =    0 } },
};


/*
 * MX Voltage Plan
 */
static cpr_voltage_plan voltage_plan_22054072562 =
{
    .modesCount      = 8,
    .tempAdjCfg      = NULL,
    .kvCfg           = &kvs_36769019966,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  592000, .floor =  512000, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  752000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3666170035, .quotients = &quotients_5730980563, .margins = &margins_540510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  796000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L2
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_1142532938, .quotients = &quotients_5730980563, .margins = &margins_540510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  828000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref = 752000, .freqDelta =       0, .fuses = &fuses_3114445330, .quotients = &quotients_6991099530, .margins = &margins_395510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  840000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_4170416617, .quotients = &quotients_11399431474, .margins = &margins_375510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  872000, .floor =  752000, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 800000, .freqDelta =       0, .fuses = &fuses_8073460590, .quotients = &quotients_11399431474, .margins = &margins_382510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  872000, .floor =  800000, .freq =       0, .interplEnabled = 0} } },

        // TURBO_L1
        {.fref = 832000, .freqDelta =       0, .fuses = &fuses_3964037928, .quotients = &quotients_10180672154, .margins = &margins_402510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  904000, .floor =  800000, .freq =       0, .interplEnabled = 0} } }},
};


static cpr_margin_cfg margins_90510 = {
    .count = 1,
    .data = (cpr_margin_data[]) { { .cprRevMin = 0, .cprRevMax = 255, .openLoop =   30000, .closedLoop =       0, .maxFloorToCeil =      0 } }
};


/*
 * VDDA Voltage Plan
 */
static cpr_voltage_plan voltage_plan_26483590419 =
{
    .modesCount      = 13,
    .tempAdjCfg      = NULL,
    .kvCfg           = NULL,
    .supportedModes  = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_RETENTION,
                                                    CPR_VOLTAGE_MODE_MIN_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS,
                                                    CPR_VOLTAGE_MODE_LOW_SVS_L1,
                                                    CPR_VOLTAGE_MODE_LOW_SVS_L2,
                                                    CPR_VOLTAGE_MODE_SVS,
                                                    CPR_VOLTAGE_MODE_SVS_L1,
                                                    CPR_VOLTAGE_MODE_SVS_L2,
                                                    CPR_VOLTAGE_MODE_NOMINAL,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L1,
                                                    CPR_VOLTAGE_MODE_NOMINAL_L2,
                                                    CPR_VOLTAGE_MODE_TURBO,
                                                    CPR_VOLTAGE_MODE_TURBO_L1 },
    .modes           = (struct cpr_voltage_data[]) {
        // RETENTION
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  352000, .floor =  352000, .freq =       0, .interplEnabled = 0} } },

        // MIN_SVS
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // LOW_SVS_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // SVS
        {.fref = 700000, .freqDelta =       0, .fuses = &fuses_1694016851, .quotients = NULL, .margins = &margins_90510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  800000, .floor =  700000, .freq =       0, .interplEnabled = 0} } },

        // SVS_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // SVS_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // NOMINAL_L2
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } },

        // TURBO
        {.fref = 876000, .freqDelta =       0, .fuses = &fuses_2382754154, .quotients = NULL, .margins = &margins_510,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =  924000, .floor =  876000, .freq =       0, .interplEnabled = 0} } },

        // TURBO_L1
        {.fref =      0, .freqDelta =       0, .fuses = &fuses_0, .quotients = NULL, .margins = NULL,
         .marginTempBands = {0},
         .subModesCount   = 1,
         .subModes        = (cpr_freq_data[]){ {.ceiling =       0, .floor =       0, .freq =       0, .interplEnabled = 0} } }},
};


/*
 * Aging configs
 */

static cpr_aging_cfg  aging_cfg_mm =
{
    .cprRevMinToRun       = 0,
    .modeToRun            = CPR_VOLTAGE_MODE_TURBO,
    .sensorID             = 17,
    .kv                   = 135,
    .scalingFactor        = 10,
    .marginLimit          = 15000,
    .bypassSensorIDs      = NULL,
    .bypassSensorIDsCount = 0,
    .fusePackingFactor    = 1,
    .fuse                 = {.count = 1, .data = (struct raw_fuse_data[]) {
                                 {SECURITY_CONTROL_BASE | (0x784324 & (SECURITY_CONTROL_BASE_SIZE - 1)), 8, (1<<15) | (1<<14) | (1<<13) | (1<<12) | (1<<11) | (1<<10) | (1<<9) | (1<<8)} } }
};


static cpr_aging_cfg  aging_cfg_cx =
{
    .cprRevMinToRun       = 0,
    .modeToRun            = CPR_VOLTAGE_MODE_TURBO_L1,
    .sensorID             = 16,
    .kv                   = 125,
    .scalingFactor        = 10,
    .marginLimit          = 15000,
    .bypassSensorIDs      = NULL,
    .bypassSensorIDsCount = 0,
    .fusePackingFactor    = 1,
    .fuse                 = {.count = 1, .data = (struct raw_fuse_data[]) {
                                 {SECURITY_CONTROL_BASE | (0x784304 & (SECURITY_CONTROL_BASE_SIZE - 1)), 12, (1<<19) | (1<<18) | (1<<17) | (1<<16) | (1<<15) | (1<<14) | (1<<13) | (1<<12)} } }
};


static cpr_aging_cfg  aging_cfg_gfx =
{
    .cprRevMinToRun       = 0,
    .modeToRun            = CPR_VOLTAGE_MODE_TURBO_L1,
    .sensorID             = 0,
    .kv                   = 125,
    .scalingFactor        = 15,
    .marginLimit          = 15000,
    .bypassSensorIDs      = NULL,
    .bypassSensorIDsCount = 0,
    .fusePackingFactor    = 1,
    .fuse                 = {.count = 1, .data = (struct raw_fuse_data[]) {
                                 {SECURITY_CONTROL_BASE | (0x78430C & (SECURITY_CONTROL_BASE_SIZE - 1)), 12, (1<<19) | (1<<18) | (1<<17) | (1<<16) | (1<<15) | (1<<14) | (1<<13) | (1<<12)} } }
};


static cpr_aging_cfg  aging_cfg_mx =
{
    .cprRevMinToRun       = 0,
    .modeToRun            = CPR_VOLTAGE_MODE_TURBO,
    .sensorID             = 2,
    .kv                   = 143,
    .scalingFactor        = 10,
    .marginLimit          = 15000,
    .bypassSensorIDs      = NULL,
    .bypassSensorIDsCount = 0,
    .fusePackingFactor    = 1,
    .fuse                 = {.count = 1, .data = (struct raw_fuse_data[]) {
                                 {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 5, (1<<12) | (1<<11) | (1<<10) | (1<<9) | (1<<8) | (1<<7) | (1<<6) | (1<<5)} } }
};


/*
 * Versioned Voltage Plans
 */

static cpr_versioned_voltage_plan vdda_vvp = {
    .rail     = CPR_RAIL_VDDA,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_28862369798 },

        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_26483590419 },
     },
    .count    = 2,
    .agingCfg = NULL
};


static cpr_versioned_voltage_plan lpi_cx_vvp = {
    .rail     = CPR_RAIL_LPI_CX,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_13089863594 },

        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_13570562393 },
     },
    .count    = 2,
    .agingCfg = NULL
};


static cpr_versioned_voltage_plan mm_vvp = {
    .rail     = CPR_RAIL_MM,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_9802866628 },

        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_12602973459 },
     },
    .count    = 2,
    .agingCfg = &aging_cfg_mm
};


static cpr_versioned_voltage_plan cx_vvp = {
    .rail     = CPR_RAIL_CX,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_13857388116 },

        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_15738514936 },
     },
    .count    = 2,
    .agingCfg = &aging_cfg_cx
};


static cpr_versioned_voltage_plan gfx_vvp = {
    .rail     = CPR_RAIL_GFX,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_20949076712 },

        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_21769369217 },
     },
    .count    = 2,
    .agingCfg = &aging_cfg_gfx
};


static cpr_versioned_voltage_plan lpi_mx_vvp = {
    .rail     = CPR_RAIL_LPI_MX,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_8900074785 },

        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_7978261066 },
     },
    .count    = 2,
    .agingCfg = NULL
};


static cpr_versioned_voltage_plan mx_vvp = {
    .rail     = CPR_RAIL_MX,
    .list     = (struct voltage_plan_list[]) {
        { .version = &ver_ANY_1_0_1_255, .cfg = &voltage_plan_18144006517 },

        { .version = &ver_ANY_2_0_2_255, .cfg = &voltage_plan_22054072562 },
     },
    .count    = 2,
    .agingCfg = &aging_cfg_mx
};

/*******************************************************************************
********************************************************************************
**
** Enablement Config Data
**
********************************************************************************
********************************************************************************/

/*
 * CPR Controller Thread Config
 */

static cpr_hal_thread_cfg cx_thread_cfg = {
    .upThresh     = 2,
    .dnThresh     = 2,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53 },
    .sensorsCount = 54,
};


static cpr_hal_thread  cx_thread = {
    .id   = 0,
    .cfg  = &cx_thread_cfg,
};


static cpr_hal_thread_cfg gfx_thread_cfg = {
    .upThresh     = 2,
    .dnThresh     = 2,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 },
    .sensorsCount = 28,
};


static cpr_hal_thread  gfx_thread = {
    .id   = 0,
    .cfg  = &gfx_thread_cfg,
};


static cpr_hal_thread_cfg lpi_cx_thread_cfg = {
    .upThresh     = 2,
    .dnThresh     = 2,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 2,3,6,7 },
    .sensorsCount = 4,
};


static cpr_hal_thread  lpi_cx_thread = {
    .id   = 0,
    .cfg  = &lpi_cx_thread_cfg,
};


static cpr_hal_thread_cfg lpi_mx_thread_cfg = {
    .upThresh     = 0,
    .dnThresh     = 0,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 0,1,4,5 },
    .sensorsCount = 4,
};


static cpr_hal_thread  lpi_mx_thread = {
    .id   = 1,
    .cfg  = &lpi_mx_thread_cfg,
};


static cpr_hal_thread_cfg mm_thread_cfg = {
    .upThresh     = 2,
    .dnThresh     = 2,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 },
    .sensorsCount = 20,
};


static cpr_hal_thread  mm_thread = {
    .id   = 0,
    .cfg  = &mm_thread_cfg,
};


static cpr_hal_thread_cfg mx_thread_cfg = {
    .upThresh     = 2,
    .dnThresh     = 2,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 0,1,2,5,6,9,10,11,12,13 },
    .sensorsCount = 10,
};


static cpr_hal_thread  mx_thread = {
    .id   = 0,
    .cfg  = &mx_thread_cfg,
};


static cpr_hal_thread_cfg vdda_thread_cfg = {
    .upThresh     = 0,
    .dnThresh     = 0,
    .consecUp     = 0,
    .consecDn     = 0,
    .sensors      = (uint8[]){ 3,4,7,8 },
    .sensorsCount = 4,
};


static cpr_hal_thread  vdda_thread = {
    .id   = 1,
    .cfg  = &vdda_thread_cfg,
};


/*
 * CPR Controller Config
 */

static cpr_hal_controller_cfg cx_cpr3_controller_cfg = {
    .stepQuotMin         = 8,
    .stepQuotMax         = 12,
    .sensorsTotal        = 54,
    .bypassSensors       = NULL,
    .bypassSensorsCount  = 0,
    .disableSensors      = (uint8[]){ 1,3,4,5,8,9,10,12,13,30,31,32,42,45,46,49,50 },
    .disableSensorsCount = 17,
    .refClk              = NULL,
    .ahbClk              = NULL,
};


static cpr_hal_controller  cx_cpr3_controller = {
    .base                = 0x628000,
    .type                = CPR_CONTROLLER_TYPE_HW_CL_ONLY,
    .cfg                 = &cx_cpr3_controller_cfg,
    .threads             = (cpr_hal_thread*[]){ &cx_thread },
    .threadsCount        = 1,
};


static cpr_hal_controller_cfg gpu_cpr_controller_cfg = {
    .stepQuotMin         = 8,
    .stepQuotMax         = 19,
    .sensorsTotal        = 28,
    .bypassSensors       = NULL,
    .bypassSensorsCount  = 0,
    .disableSensors      = NULL,
    .disableSensorsCount = 0,
    .refClk              = NULL,
    .ahbClk              = NULL,
};


static cpr_hal_controller  gpu_cpr_controller = {
    .base                = 0x3d9a000,
    .type                = CPR_CONTROLLER_TYPE_HW_CL_ONLY,
    .cfg                 = &gpu_cpr_controller_cfg,
    .threads             = (cpr_hal_thread*[]){ &gfx_thread },
    .threadsCount        = 1,
};


static cpr_hal_controller_cfg lpass_cpr3_controller_cfg = {
    .stepQuotMin         = 8,
    .stepQuotMax         = 13,
    .sensorsTotal        = 8,
    .bypassSensors       = (uint8[]){ 0,1,4,5 },
    .bypassSensorsCount  = 4,
    .disableSensors      = (uint8[]){ 0,1,4,5 },
    .disableSensorsCount = 4,
    .refClk              = NULL,
    .ahbClk              = NULL,
};


static cpr_hal_controller  lpass_cpr3_controller = {
    .base                = 0x33b0000,
    .type                = CPR_CONTROLLER_TYPE_HW_CL_ONLY,
    .cfg                 = &lpass_cpr3_controller_cfg,
    .threads             = (cpr_hal_thread*[]){ &lpi_cx_thread, &lpi_mx_thread },
    .threadsCount        = 2,
};


static cpr_hal_controller_cfg mmcx_cpr3_controller_cfg = {
    .stepQuotMin         = 8,
    .stepQuotMax         = 13,
    .sensorsTotal        = 20,
    .bypassSensors       = NULL,
    .bypassSensorsCount  = 0,
    .disableSensors      = NULL,
    .disableSensorsCount = 0,
    .refClk              = NULL,
    .ahbClk              = NULL,
};


static cpr_hal_controller  mmcx_cpr3_controller = {
    .base                = 0x630000,
    .type                = CPR_CONTROLLER_TYPE_HW_CL_ONLY,
    .cfg                 = &mmcx_cpr3_controller_cfg,
    .threads             = (cpr_hal_thread*[]){ &mm_thread },
    .threadsCount        = 1,
};


static cpr_hal_controller_cfg mx_cpr3_controller_cfg = {
    .stepQuotMin         = 7,
    .stepQuotMax         = 13,
    .sensorsTotal        = 14,
    .bypassSensors       = (uint8[]){ 3,4,7,8 },
    .bypassSensorsCount  = 4,
    .disableSensors      = (uint8[]){ 0,3,4,6,7,8,10,12,13 },
    .disableSensorsCount = 9,
    .refClk              = NULL,
    .ahbClk              = NULL,
};


static cpr_hal_controller  mx_cpr3_controller = {
    .base                = 0x62c000,
    .type                = CPR_CONTROLLER_TYPE_HW_CL_ONLY,
    .cfg                 = &mx_cpr3_controller_cfg,
    .threads             = (cpr_hal_thread*[]){ &mx_thread, &vdda_thread },
    .threadsCount        = 2,
};


/*
 * HAL Rail Config
 */

static cpr_rail cpr_rail_cx_cfg = {
    .id               = CPR_RAIL_CX,
    .name             = "CX",
    .hal              = { .controller = &cx_cpr3_controller, .thread = &cx_thread },
    .interruptId      = 0,
    .settleModes      = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_NOMINAL, CPR_VOLTAGE_MODE_TURBO },
    .settleModesCount = 2,
};


static cpr_rail cpr_rail_gfx_cfg = {
    .id               = CPR_RAIL_GFX,
    .name             = "GFX",
    .hal              = { .controller = &gpu_cpr_controller, .thread = &gfx_thread },
    .interruptId      = 0,
    .settleModes      = NULL,
    .settleModesCount = 0,
};


static cpr_rail cpr_rail_lpi_cx_cfg = {
    .id               = CPR_RAIL_LPI_CX,
    .name             = "LPI_CX",
    .hal              = { .controller = &lpass_cpr3_controller, .thread = &lpi_cx_thread },
    .interruptId      = 0,
    .settleModes      = NULL,
    .settleModesCount = 0,
};


static cpr_rail cpr_rail_lpi_mx_cfg = {
    .id               = CPR_RAIL_LPI_MX,
    .name             = "LPI_MX",
    .hal              = { .controller = &lpass_cpr3_controller, .thread = &lpi_mx_thread },
    .interruptId      = 0,
    .settleModes      = NULL,
    .settleModesCount = 0,
};


static cpr_rail cpr_rail_mm_cfg = {
    .id               = CPR_RAIL_MM,
    .name             = "MM",
    .hal              = { .controller = &mmcx_cpr3_controller, .thread = &mm_thread },
    .interruptId      = 0,
    .settleModes      = NULL,
    .settleModesCount = 0,
};


static cpr_rail cpr_rail_mx_cfg = {
    .id               = CPR_RAIL_MX,
    .name             = "MX",
    .hal              = { .controller = &mx_cpr3_controller, .thread = &mx_thread },
    .interruptId      = 0,
    .settleModes      = (cpr_voltage_mode[]) { CPR_VOLTAGE_MODE_NOMINAL, CPR_VOLTAGE_MODE_TURBO },
    .settleModesCount = 2,
};


static cpr_rail cpr_rail_vdda_cfg = {
    .id               = CPR_RAIL_VDDA,
    .name             = "VDDA",
    .hal              = { .controller = &mx_cpr3_controller, .thread = &vdda_thread },
    .interruptId      = 0,
    .settleModes      = NULL,
    .settleModesCount = 0,
};


/*
 * Rail Enablement Config
 */

static cpr_enablement cpr_rail_cx_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_CX,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_cx_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_CX,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_gfx_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_GFX,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_HW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 0,
};


static cpr_enablement cpr_rail_gfx_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_GFX,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_HW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 0,
};


static cpr_enablement cpr_rail_lpi_cx_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_LPI_CX,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_lpi_cx_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_LPI_CX,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_lpi_mx_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_LPI_MX,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_OPEN_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 8000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_lpi_mx_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_LPI_MX,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_OPEN_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 8000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_mm_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_MM,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_HW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 0,
};


static cpr_enablement cpr_rail_mm_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_MM,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_HW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 0,
};


static cpr_enablement cpr_rail_mx_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_MX,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_mx_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_MX,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_SW_CLOSED_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_vdda_enablement_1_0_1_255 =
{
    .id                = CPR_RAIL_VDDA,
    .version           = &ver_ANY_1_0_1_255,
    .funcId            = CPR_INIT_OPEN_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_enablement cpr_rail_vdda_enablement_2_0_2_255 =
{
    .id                = CPR_RAIL_VDDA,
    .version           = &ver_ANY_2_0_2_255,
    .funcId            = CPR_INIT_OPEN_LOOP,
    .fuseMultiplier    = 10000,
    .stepSize          = 4000,
    .railCPRRevFuse    = {.count = 1, .data = (struct raw_fuse_data[]) {
                   {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } },
    .enable            = 1,
};


static cpr_misc_cfg misc_cfg = {
    .cprRev = {.count = 1, .data = (struct raw_fuse_data[]) { {SECURITY_CONTROL_BASE | (0x7842F8 & (SECURITY_CONTROL_BASE_SIZE - 1)), 13, (1<<15) | (1<<14) | (1<<13)} } }
};


cpr_settings cpr_settings_8250 =
{
    .hashValue        = voltage_plan_hash_value,

    .railVVPs         = (cpr_versioned_voltage_plan*[]) { &cx_vvp, &gfx_vvp, &lpi_cx_vvp, &lpi_mx_vvp, &mm_vvp, &mx_vvp, &vdda_vvp },
    .rails            = (cpr_rail*[]) { &cpr_rail_cx_cfg, &cpr_rail_gfx_cfg, &cpr_rail_lpi_cx_cfg, &cpr_rail_lpi_mx_cfg, &cpr_rail_mm_cfg, &cpr_rail_mx_cfg, &cpr_rail_vdda_cfg },
    .railsCount       = 7,

    .controllers      = (cpr_hal_controller*[]) { &cx_cpr3_controller, &gpu_cpr_controller, &lpass_cpr3_controller, &mmcx_cpr3_controller, &mx_cpr3_controller },
    .controllersCount = 5,

    .enablements      = (cpr_enablement*[]) { &cpr_rail_cx_enablement_1_0_1_255, &cpr_rail_cx_enablement_2_0_2_255, &cpr_rail_gfx_enablement_1_0_1_255, &cpr_rail_gfx_enablement_2_0_2_255, &cpr_rail_lpi_cx_enablement_1_0_1_255, &cpr_rail_lpi_cx_enablement_2_0_2_255, &cpr_rail_lpi_mx_enablement_1_0_1_255, &cpr_rail_lpi_mx_enablement_2_0_2_255, &cpr_rail_mm_enablement_1_0_1_255, &cpr_rail_mm_enablement_2_0_2_255, &cpr_rail_mx_enablement_1_0_1_255, &cpr_rail_mx_enablement_2_0_2_255, &cpr_rail_vdda_enablement_1_0_1_255, &cpr_rail_vdda_enablement_2_0_2_255 },
    .enablementsCount = 14,

    .miscCfg          = &misc_cfg,
};

