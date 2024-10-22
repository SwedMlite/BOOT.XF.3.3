#ifndef CHIPINFODEFSLEGACY_H
#define CHIPINFODEFSLEGACY_H

/*
===========================================================================

FILE:         DDIChipInfo.h

DESCRIPTION:
  Type definitions used with the legacy DalChipInfo driver.
  These are only included here to prevent breaking builds. Please use the
  definitions from ChipInfoDefs.h for any new development.
===========================================================================
             Copyright (c) 2011,2014,2016-2017, 2019 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
============================================================================
*/

#include "ChipInfoDefs.h"


/**
  @addtogroup macros
  @{
*/

/**
 * Maximum length of a chip id string.  Can be used by clients when
 * declaring space for DalChip_GetChipIdString.
 */
#define DALCHIPINFO_MAX_ID_LENGTH CHIPINFO_MAX_ID_LENGTH


/**
 * Maximum length of a processor name string.  Can be used by
 * clients when declaring space for
 * DalChip_GetProcessorNameString.
 */
#define DALCHIPINFO_MAX_NAME_LENGTH CHIPINFO_MAX_NAME_LENGTH


/**
 * Macro to generate the hardware version number from a given major
 * and minor number.  Used when comparing against return value of
 * hw_version().  For example to check if this is at least version 1.2:
 *   DalChipInfo_GetVersion(h, &version);
 *   if (version >= DALCHIPINFO_VERSION(1,2)) ...
 */
#define DALCHIPINFO_VERSION(major, minor)  CHIPINFO_VERSION((major),(minor))

#define DALCHIPINFO_VERSION_UNKNOWN CHIPINFO_VERSION_UNKNOWN

/**
 * Masks used to indicate which modem
 * hardware is supported on the platform.
 */
#define DALCHIPINFO_MODEM_1X         CHIPINFO_MODEM_1X
#define DALCHIPINFO_MODEM_EVDO       CHIPINFO_MODEM_EVDO
#define DALCHIPINFO_MODEM_GSM        CHIPINFO_MODEM_GSM
#define DALCHIPINFO_MODEM_UMTS       CHIPINFO_MODEM_UMTS
#define DALCHIPINFO_MODEM_CGPS       CHIPINFO_MODEM_CGPS
#define DALCHIPINFO_MODEM_EVDO_REVA  CHIPINFO_MODEM_EVDO_REVA
#define DALCHIPINFO_MODEM_EVDO_REVB  CHIPINFO_MODEM_EVDO_REVB
#define DALCHIPINFO_MODEM_LTE        CHIPINFO_MODEM_LTE
#define DALCHIPINFO_MODEM_GNSS       CHIPINFO_MODEM_GNSS
#define DALCHIPINFO_MODEM_EHRPD      CHIPINFO_MODEM_EHRPD

/**
 * Map legacy Chip IDs to their new versions
 */
#define DALCHIPINFO_ID_UNKNOWN    CHIPINFO_ID_UNKNOWN
#define DALCHIPINFO_ID_MDM1000    CHIPINFO_ID_MDM1000
#define DALCHIPINFO_ID_ESM6235    CHIPINFO_ID_ESM6235
#define DALCHIPINFO_ID_QSC6240    CHIPINFO_ID_QSC6240
#define DALCHIPINFO_ID_MSM6245    CHIPINFO_ID_MSM6245
#define DALCHIPINFO_ID_MSM6255    CHIPINFO_ID_MSM6255
#define DALCHIPINFO_ID_MSM6255A   CHIPINFO_ID_MSM6255A
#define DALCHIPINFO_ID_MSM6260    CHIPINFO_ID_MSM6260
#define DALCHIPINFO_ID_MSM6246    CHIPINFO_ID_MSM6246
#define DALCHIPINFO_ID_QSC6270    CHIPINFO_ID_QSC6270
#define DALCHIPINFO_ID_MSM6280    CHIPINFO_ID_MSM6280
#define DALCHIPINFO_ID_MSM6290    CHIPINFO_ID_MSM6290
#define DALCHIPINFO_ID_MSM7200    CHIPINFO_ID_MSM7200
#define DALCHIPINFO_ID_MSM7201    CHIPINFO_ID_MSM7201
#define DALCHIPINFO_ID_ESM7205    CHIPINFO_ID_ESM7205
#define DALCHIPINFO_ID_ESM7206    CHIPINFO_ID_ESM7206
#define DALCHIPINFO_ID_MSM7200A   CHIPINFO_ID_MSM7200A
#define DALCHIPINFO_ID_MSM7201A   CHIPINFO_ID_MSM7201A
#define DALCHIPINFO_ID_ESM7205A   CHIPINFO_ID_ESM7205A
#define DALCHIPINFO_ID_ESM7206A   CHIPINFO_ID_ESM7206A
#define DALCHIPINFO_ID_ESM7225    CHIPINFO_ID_ESM7225
#define DALCHIPINFO_ID_MSM7225    CHIPINFO_ID_MSM7225
#define DALCHIPINFO_ID_MSM7500    CHIPINFO_ID_MSM7500
#define DALCHIPINFO_ID_MSM7500A   CHIPINFO_ID_MSM7500A
#define DALCHIPINFO_ID_MSM7525    CHIPINFO_ID_MSM7525
#define DALCHIPINFO_ID_MSM7600    CHIPINFO_ID_MSM7600
#define DALCHIPINFO_ID_MSM7601    CHIPINFO_ID_MSM7601
#define DALCHIPINFO_ID_MSM7625    CHIPINFO_ID_MSM7625
#define DALCHIPINFO_ID_MSM7800    CHIPINFO_ID_MSM7800
#define DALCHIPINFO_ID_MDM8200    CHIPINFO_ID_MDM8200
#define DALCHIPINFO_ID_QSD8650    CHIPINFO_ID_QSD8650
#define DALCHIPINFO_ID_MDM8900    CHIPINFO_ID_MDM8900
#define DALCHIPINFO_ID_QST1000    CHIPINFO_ID_QST1000
#define DALCHIPINFO_ID_QST1005    CHIPINFO_ID_QST1005
#define DALCHIPINFO_ID_QST1100    CHIPINFO_ID_QST1100
#define DALCHIPINFO_ID_QST1105    CHIPINFO_ID_QST1105
#define DALCHIPINFO_ID_QST1500    CHIPINFO_ID_QST1500
#define DALCHIPINFO_ID_QST1600    CHIPINFO_ID_QST1600
#define DALCHIPINFO_ID_QST1700    CHIPINFO_ID_QST1700
#define DALCHIPINFO_ID_QSD8250    CHIPINFO_ID_QSD8250
#define DALCHIPINFO_ID_QSD8550    CHIPINFO_ID_QSD8550
#define DALCHIPINFO_ID_QSD8850    CHIPINFO_ID_QSD8850
#define DALCHIPINFO_ID_MDM2000    CHIPINFO_ID_MDM2000
#define DALCHIPINFO_ID_MSM7227    CHIPINFO_ID_MSM7227
#define DALCHIPINFO_ID_MSM7627    CHIPINFO_ID_MSM7627
#define DALCHIPINFO_ID_QSC6165    CHIPINFO_ID_QSC6165
#define DALCHIPINFO_ID_QSC6175    CHIPINFO_ID_QSC6175
#define DALCHIPINFO_ID_QSC6185    CHIPINFO_ID_QSC6185
#define DALCHIPINFO_ID_QSC6195    CHIPINFO_ID_QSC6195
#define DALCHIPINFO_ID_QSC6285    CHIPINFO_ID_QSC6285
#define DALCHIPINFO_ID_QSC6295    CHIPINFO_ID_QSC6295
#define DALCHIPINFO_ID_QSC6695    CHIPINFO_ID_QSC6695
#define DALCHIPINFO_ID_ESM6246    CHIPINFO_ID_ESM6246
#define DALCHIPINFO_ID_ESM6290    CHIPINFO_ID_ESM6290
#define DALCHIPINFO_ID_ESC6270    CHIPINFO_ID_ESC6270
#define DALCHIPINFO_ID_ESC6240    CHIPINFO_ID_ESC6240
#define DALCHIPINFO_ID_MDM8220    CHIPINFO_ID_MDM8220
#define DALCHIPINFO_ID_MDM9200    CHIPINFO_ID_MDM9200
#define DALCHIPINFO_ID_MDM9600    CHIPINFO_ID_MDM9600
#define DALCHIPINFO_ID_MSM7630    CHIPINFO_ID_MSM7630
#define DALCHIPINFO_ID_MSM7230    CHIPINFO_ID_MSM7230
#define DALCHIPINFO_ID_ESM7227    CHIPINFO_ID_ESM7227
#define DALCHIPINFO_ID_MSM7625D1  CHIPINFO_ID_MSM7625D1
#define DALCHIPINFO_ID_MSM7225D1  CHIPINFO_ID_MSM7225D1
#define DALCHIPINFO_ID_QSD8250A   CHIPINFO_ID_QSD8250A
#define DALCHIPINFO_ID_QSD8650A   CHIPINFO_ID_QSD8650A
#define DALCHIPINFO_ID_MSM7625D2  CHIPINFO_ID_MSM7625D2
#define DALCHIPINFO_ID_MSM7227D1  CHIPINFO_ID_MSM7227D1
#define DALCHIPINFO_ID_MSM7627D1  CHIPINFO_ID_MSM7627D1
#define DALCHIPINFO_ID_MSM7627D2  CHIPINFO_ID_MSM7627D2
#define DALCHIPINFO_ID_MSM8260    CHIPINFO_ID_MSM8260
#define DALCHIPINFO_ID_MSM8660    CHIPINFO_ID_MSM8660
#define DALCHIPINFO_ID_MDM8200A   CHIPINFO_ID_MDM8200A
#define DALCHIPINFO_ID_QSC6155    CHIPINFO_ID_QSC6155
#define DALCHIPINFO_ID_MSM8255    CHIPINFO_ID_MSM8255
#define DALCHIPINFO_ID_MSM8655    CHIPINFO_ID_MSM8655
#define DALCHIPINFO_ID_ESC6295    CHIPINFO_ID_ESC6295
#define DALCHIPINFO_ID_MDM3000    CHIPINFO_ID_MDM3000
#define DALCHIPINFO_ID_MDM6200    CHIPINFO_ID_MDM6200
#define DALCHIPINFO_ID_MDM6600    CHIPINFO_ID_MDM6600
#define DALCHIPINFO_ID_MDM6210    CHIPINFO_ID_MDM6210
#define DALCHIPINFO_ID_MDM6610    CHIPINFO_ID_MDM6610
#define DALCHIPINFO_ID_QSD8672    CHIPINFO_ID_QSD8672
#define DALCHIPINFO_ID_MDM6215    CHIPINFO_ID_MDM6215
#define DALCHIPINFO_ID_MDM6615    CHIPINFO_ID_MDM6615
#define DALCHIPINFO_ID_APQ8055    CHIPINFO_ID_APQ8055
#define DALCHIPINFO_ID_APQ8060    CHIPINFO_ID_APQ8060
#define DALCHIPINFO_ID_MSM8960    CHIPINFO_ID_MSM8960
#define DALCHIPINFO_ID_MSM7225A   CHIPINFO_ID_MSM7225A
#define DALCHIPINFO_ID_MSM7625A   CHIPINFO_ID_MSM7625A
#define DALCHIPINFO_ID_MSM7227A   CHIPINFO_ID_MSM7227A
#define DALCHIPINFO_ID_MSM7627A   CHIPINFO_ID_MSM7627A
#define DALCHIPINFO_ID_ESM7227A   CHIPINFO_ID_ESM7227A
#define DALCHIPINFO_ID_QSC6195D2  CHIPINFO_ID_QSC6195D2
#define DALCHIPINFO_ID_FSM9200    CHIPINFO_ID_FSM9200
#define DALCHIPINFO_ID_FSM9800    CHIPINFO_ID_FSM9800
#define DALCHIPINFO_ID_MSM7225AD1 CHIPINFO_ID_MSM7225AD1
#define DALCHIPINFO_ID_MSM7227AD1 CHIPINFO_ID_MSM7227AD1
#define DALCHIPINFO_ID_MSM7225AA   CHIPINFO_ID_MSM7225AA
#define DALCHIPINFO_ID_MSM7225AAD1 CHIPINFO_ID_MSM7225AAD1
#define DALCHIPINFO_ID_MSM7625AA   CHIPINFO_ID_MSM7625AA
#define DALCHIPINFO_ID_MSM7227AA   CHIPINFO_ID_MSM7227AA
#define DALCHIPINFO_ID_MSM7227AAD1 CHIPINFO_ID_MSM7227AAD1
#define DALCHIPINFO_ID_MSM7627AA   CHIPINFO_ID_MSM7627AA
#define DALCHIPINFO_ID_MDM9615     CHIPINFO_ID_MDM9615
#define DALCHIPINFO_ID_MDM9615M    CHIPINFO_ID_MDM9615
#define DALCHIPINFO_ID_MDM8215     CHIPINFO_ID_MDM8215
#define DALCHIPINFO_ID_MDM9215     CHIPINFO_ID_MDM9215
#define DALCHIPINFO_ID_MDM9215M    CHIPINFO_ID_MDM9215
#define DALCHIPINFO_ID_APQ8064     CHIPINFO_ID_APQ8064
#define DALCHIPINFO_ID_QSC6270D1   CHIPINFO_ID_QSC6270D1
#define DALCHIPINFO_ID_QSC6240D1   CHIPINFO_ID_QSC6240D1
#define DALCHIPINFO_ID_ESC6270D1   CHIPINFO_ID_ESC6270D1
#define DALCHIPINFO_ID_ESC6240D1   CHIPINFO_ID_ESC6240D1
#define DALCHIPINFO_ID_MDM6270     CHIPINFO_ID_MDM6270
#define DALCHIPINFO_ID_MDM6270D1   CHIPINFO_ID_MDM6270D1
#define DALCHIPINFO_ID_MSM8930     CHIPINFO_ID_MSM8930
#define DALCHIPINFO_ID_MSM8630     CHIPINFO_ID_MSM8630
#define DALCHIPINFO_ID_MSM8230     CHIPINFO_ID_MSM8230
#define DALCHIPINFO_ID_APQ8030     CHIPINFO_ID_APQ8030
#define DALCHIPINFO_ID_MSM8627     CHIPINFO_ID_MSM8627
#define DALCHIPINFO_ID_MSM8227     CHIPINFO_ID_MSM8227
#define DALCHIPINFO_ID_MSM8660A    CHIPINFO_ID_MSM8660A
#define DALCHIPINFO_ID_MSM8260A    CHIPINFO_ID_MSM8260A
#define DALCHIPINFO_ID_APQ8060A    CHIPINFO_ID_APQ8060A
#define DALCHIPINFO_ID_MPQ8062     CHIPINFO_ID_MPQ8062
#define DALCHIPINFO_ID_MSM8974     CHIPINFO_ID_MSM8974
#define DALCHIPINFO_ID_MSM8225     CHIPINFO_ID_MSM8225
#define DALCHIPINFO_ID_MSM8225D1   CHIPINFO_ID_MSM8225D1
#define DALCHIPINFO_ID_MSM8625     CHIPINFO_ID_MSM8625
#define DALCHIPINFO_ID_MPQ8064     CHIPINFO_ID_MPQ8064
#define DALCHIPINFO_ID_MSM7225AB   CHIPINFO_ID_MSM7225AB
#define DALCHIPINFO_ID_MSM7225ABD1 CHIPINFO_ID_MSM7225ABD1
#define DALCHIPINFO_ID_MSM7625AB   CHIPINFO_ID_MSM7625AB
#define DALCHIPINFO_ID_MDM9625     CHIPINFO_ID_MDM9625
#define DALCHIPINFO_ID_MSM7125A    CHIPINFO_ID_MSM7125A
#define DALCHIPINFO_ID_MSM7127A    CHIPINFO_ID_MSM7127A
#define DALCHIPINFO_ID_MSM8125AB   CHIPINFO_ID_MSM8125AB
#define DALCHIPINFO_ID_MSM8960AB   CHIPINFO_ID_MSM8960AB
#define DALCHIPINFO_ID_APQ8060AB   CHIPINFO_ID_APQ8060AB
#define DALCHIPINFO_ID_MSM8260AB   CHIPINFO_ID_MSM8260AB
#define DALCHIPINFO_ID_MSM8660AB   CHIPINFO_ID_MSM8660AB
#define DALCHIPINFO_ID_MSM8930AA   CHIPINFO_ID_MSM8930AA
#define DALCHIPINFO_ID_MSM8630AA   CHIPINFO_ID_MSM8630AA
#define DALCHIPINFO_ID_MSM8230AA   CHIPINFO_ID_MSM8230AA
#define DALCHIPINFO_ID_MSM8626     CHIPINFO_ID_MSM8626
#define DALCHIPINFO_ID_MPQ8092     CHIPINFO_ID_MPQ8092
#define DALCHIPINFO_ID_MSM8610     CHIPINFO_ID_MSM8610
#define DALCHIPINFO_ID_MDM8225     CHIPINFO_ID_MDM8225
#define DALCHIPINFO_ID_MDM9225     CHIPINFO_ID_MDM9225
#define DALCHIPINFO_ID_MDM9225M    CHIPINFO_ID_MDM9225M
#define DALCHIPINFO_ID_MDM8225M    CHIPINFO_ID_MDM8225M
#define DALCHIPINFO_ID_MDM9625M    CHIPINFO_ID_MDM9625M
#define DALCHIPINFO_ID_APQ8064_V2PRIME   CHIPINFO_ID_APQ8064_V2PRIME
#define DALCHIPINFO_ID_MSM8930AB   CHIPINFO_ID_MSM8930AB
#define DALCHIPINFO_ID_MSM8630AB   CHIPINFO_ID_MSM8630AB
#define DALCHIPINFO_ID_MSM8230AB   CHIPINFO_ID_MSM8230AB
#define DALCHIPINFO_ID_APQ8030AB   CHIPINFO_ID_APQ8030AB
#define DALCHIPINFO_ID_MSM8226     CHIPINFO_ID_MSM8226
#define DALCHIPINFO_ID_MSM8526     CHIPINFO_ID_MSM8526
#define DALCHIPINFO_ID_APQ8030AA   CHIPINFO_ID_APQ8030AA
#define DALCHIPINFO_ID_MSM8110     CHIPINFO_ID_MSM8110
#define DALCHIPINFO_ID_MSM8210     CHIPINFO_ID_MSM8210
#define DALCHIPINFO_ID_MSM8810     CHIPINFO_ID_MSM8810
#define DALCHIPINFO_ID_MSM8212     CHIPINFO_ID_MSM8212
#define DALCHIPINFO_ID_MSM8612     CHIPINFO_ID_MSM8612
#define DALCHIPINFO_ID_MSM8112     CHIPINFO_ID_MSM8112
#define DALCHIPINFO_ID_MSM8125     CHIPINFO_ID_MSM8125
#define DALCHIPINFO_ID_MSM8225Q    CHIPINFO_ID_MSM8225Q
#define DALCHIPINFO_ID_MSM8625Q    CHIPINFO_ID_MSM8625Q
#define DALCHIPINFO_ID_MSM8125Q    CHIPINFO_ID_MSM8125Q
#define DALCHIPINFO_ID_MDM9310     CHIPINFO_ID_MDM9310
#define DALCHIPINFO_ID_APQ8064_SLOW_PRIME CHIPINFO_ID_APQ8064_SLOW_PRIME
#define DALCHIPINFO_ID_MDM8110M    CHIPINFO_ID_MDM8110M
#define DALCHIPINFO_ID_MDM8615M    CHIPINFO_ID_MDM8615M
#define DALCHIPINFO_ID_MDM9320     CHIPINFO_ID_MDM9320
#define DALCHIPINFO_ID_MDM9225_1   CHIPINFO_ID_MDM9225_1
#define DALCHIPINFO_ID_MDM9225M_1  CHIPINFO_ID_MDM9225M_1
#define DALCHIPINFO_ID_APQ8084     CHIPINFO_ID_APQ8084
#define DALCHIPINFO_ID_MSM8130     CHIPINFO_ID_MSM8130
#define DALCHIPINFO_ID_MSM8130AA   CHIPINFO_ID_MSM8130AA
#define DALCHIPINFO_ID_MSM8130AB   CHIPINFO_ID_MSM8130AB
#define DALCHIPINFO_ID_MSM8627AA   CHIPINFO_ID_MSM8627AA
#define DALCHIPINFO_ID_MSM8227AA   CHIPINFO_ID_MSM8227AA
#define DALCHIPINFO_ID_APQ8074     CHIPINFO_ID_APQ8074
#define DALCHIPINFO_ID_MSM8274     CHIPINFO_ID_MSM8274
#define DALCHIPINFO_ID_MSM8674     CHIPINFO_ID_MSM8674
#define DALCHIPINFO_ID_MDM9635     CHIPINFO_ID_MDM9635
#define DALCHIPINFO_ID_FSM9900     CHIPINFO_ID_FSM9900
#define DALCHIPINFO_ID_FSM9965     CHIPINFO_ID_FSM9965
#define DALCHIPINFO_ID_FSM9955     CHIPINFO_ID_FSM9955
#define DALCHIPINFO_ID_FSM9950     CHIPINFO_ID_FSM9950
#define DALCHIPINFO_ID_FSM9915     CHIPINFO_ID_FSM9915
#define DALCHIPINFO_ID_FSM9910     CHIPINFO_ID_FSM9910
#define DALCHIPINFO_ID_MSM8974_PRO CHIPINFO_ID_MSM8974_PRO
#define DALCHIPINFO_ID_MSM8962     CHIPINFO_ID_MSM8962
#define DALCHIPINFO_ID_MSM8262     CHIPINFO_ID_MSM8262
#define DALCHIPINFO_ID_APQ8062     CHIPINFO_ID_APQ8062
#define DALCHIPINFO_ID_MSM8126     CHIPINFO_ID_MSM8126
#define DALCHIPINFO_ID_APQ8026     CHIPINFO_ID_APQ8026
#define DALCHIPINFO_ID_MSM8926     CHIPINFO_ID_MSM8926
#define DALCHIPINFO_ID_MSM8326     CHIPINFO_ID_MSM8326
#define DALCHIPINFO_ID_MSM8916     CHIPINFO_ID_MSM8916
#define DALCHIPINFO_ID_MSM8994     CHIPINFO_ID_MSM8994
#define DALCHIPINFO_ID_APQ8074_AA  CHIPINFO_ID_APQ8074_AA
#define DALCHIPINFO_ID_APQ8074_AB  CHIPINFO_ID_APQ8074_AB
#define DALCHIPINFO_ID_APQ8074_PRO CHIPINFO_ID_APQ8074_PRO
#define DALCHIPINFO_ID_MSM8274_AA  CHIPINFO_ID_MSM8274_AA
#define DALCHIPINFO_ID_MSM8274_AB  CHIPINFO_ID_MSM8274_AB
#define DALCHIPINFO_ID_MSM8274_PRO CHIPINFO_ID_MSM8274_PRO
#define DALCHIPINFO_ID_MSM8674_AA  CHIPINFO_ID_MSM8674_AA
#define DALCHIPINFO_ID_MSM8674_AB  CHIPINFO_ID_MSM8674_AB
#define DALCHIPINFO_ID_MSM8674_PRO CHIPINFO_ID_MSM8674_PRO
#define DALCHIPINFO_ID_MSM8974_AA  CHIPINFO_ID_MSM8974_AA
#define DALCHIPINFO_ID_MSM8974_AB  CHIPINFO_ID_MSM8974_AB
#define DALCHIPINFO_ID_APQ8028     CHIPINFO_ID_APQ8028
#define DALCHIPINFO_ID_MSM8128     CHIPINFO_ID_MSM8128
#define DALCHIPINFO_ID_MSM8228     CHIPINFO_ID_MSM8228
#define DALCHIPINFO_ID_MSM8528     CHIPINFO_ID_MSM8528
#define DALCHIPINFO_ID_MSM8628     CHIPINFO_ID_MSM8628
#define DALCHIPINFO_ID_MSM8928     CHIPINFO_ID_MSM8928
#define DALCHIPINFO_ID_MSM8510     CHIPINFO_ID_MSM8510
#define DALCHIPINFO_ID_MSM8512     CHIPINFO_ID_MSM8512
#define DALCHIPINFO_ID_MDM9630     CHIPINFO_ID_MDM9630
#define DALCHIPINFO_ID_MDM9635M    CHIPINFO_ID_MDM9635
#define DALCHIPINFO_ID_MDM9230     CHIPINFO_ID_MDM9230
#define DALCHIPINFO_ID_MDM9235M    CHIPINFO_ID_MDM9235M
#define DALCHIPINFO_ID_MDM8630     CHIPINFO_ID_MDM8630
#define DALCHIPINFO_ID_MDM9330     CHIPINFO_ID_MDM9330
#define DALCHIPINFO_ID_MPQ8091     CHIPINFO_ID_MPQ8091
#define DALCHIPINFO_ID_MSM8936     CHIPINFO_ID_MSM8936
#define DALCHIPINFO_ID_MDM9240     CHIPINFO_ID_MDM9240
#define DALCHIPINFO_ID_MDM9340     CHIPINFO_ID_MDM9340
#define DALCHIPINFO_ID_MDM9640     CHIPINFO_ID_MDM9640
#define DALCHIPINFO_ID_MDM9245M    CHIPINFO_ID_MDM9245M
#define DALCHIPINFO_ID_MDM9645M    CHIPINFO_ID_MDM9645M
#define DALCHIPINFO_ID_MSM8939     CHIPINFO_ID_MSM8939
#define DALCHIPINFO_ID_APQ8036     CHIPINFO_ID_APQ8036
#define DALCHIPINFO_ID_APQ8039     CHIPINFO_ID_APQ8039
#define DALCHIPINFO_ID_MSM8236     CHIPINFO_ID_MSM8236
#define DALCHIPINFO_ID_MSM8636     CHIPINFO_ID_MSM8636
#define DALCHIPINFO_ID_APQ8064_AU  CHIPINFO_ID_APQ8064_AU
#define DALCHIPINFO_ID_MSM8909     CHIPINFO_ID_MSM8909
#define DALCHIPINFO_ID_MSM8996     CHIPINFO_ID_MSM8996
#define DALCHIPINFO_ID_APQ8016     CHIPINFO_ID_APQ8016
#define DALCHIPINFO_ID_MSM8216     CHIPINFO_ID_MSM8216
#define DALCHIPINFO_ID_MSM8116     CHIPINFO_ID_MSM8116
#define DALCHIPINFO_ID_MSM8616     CHIPINFO_ID_MSM8616
#define DALCHIPINFO_ID_MSM8992     CHIPINFO_ID_MSM8992
#define DALCHIPINFO_ID_APQ8092     CHIPINFO_ID_APQ8092
#define DALCHIPINFO_ID_APQ8094     CHIPINFO_ID_APQ8094
#define DALCHIPINFO_ID_FSM9008     CHIPINFO_ID_FSM9008
#define DALCHIPINFO_ID_FSM9010     CHIPINFO_ID_FSM9010
#define DALCHIPINFO_ID_FSM9016     CHIPINFO_ID_FSM9016
#define DALCHIPINFO_ID_FSM9055     CHIPINFO_ID_FSM9055
#define DALCHIPINFO_ID_MSM8209     CHIPINFO_ID_MSM8209
#define DALCHIPINFO_ID_MSM8208     CHIPINFO_ID_MSM8208
#define DALCHIPINFO_ID_MDM9209     CHIPINFO_ID_MDM9209
#define DALCHIPINFO_ID_MDM9309     CHIPINFO_ID_MDM9309
#define DALCHIPINFO_ID_MDM9609     CHIPINFO_ID_MDM9609
#define DALCHIPINFO_ID_MSM8239     CHIPINFO_ID_MSM8239
#define DALCHIPINFO_ID_MSM8952     CHIPINFO_ID_MSM8952
#define DALCHIPINFO_ID_APQ8009     CHIPINFO_ID_APQ8009
#define DALCHIPINFO_ID_MSM8956     CHIPINFO_ID_MSM8956
#define DALCHIPINFO_ID_QDF2432     CHIPINFO_ID_QDF2432
#define DALCHIPINFO_ID_MSM8929     CHIPINFO_ID_MSM8929
#define DALCHIPINFO_ID_MSM8629     CHIPINFO_ID_MSM8629
#define DALCHIPINFO_ID_MSM8229     CHIPINFO_ID_MSM8229
#define DALCHIPINFO_ID_APQ8029     CHIPINFO_ID_APQ8029
#define DALCHIPINFO_ID_QCA9618     CHIPINFO_ID_QCA9618
#define DALCHIPINFO_ID_IPQ4018     CHIPINFO_ID_QCA9618
#define DALCHIPINFO_ID_QCA9619     CHIPINFO_ID_QCA9619
#define DALCHIPINFO_ID_IPQ4019     CHIPINFO_ID_QCA9619
#define DALCHIPINFO_ID_APQ8056     CHIPINFO_ID_APQ8056
#define DALCHIPINFO_ID_MSM8609     CHIPINFO_ID_MSM8609
#define DALCHIPINFO_ID_FSM9916     CHIPINFO_ID_FSM9916
#define DALCHIPINFO_ID_APQ8076     CHIPINFO_ID_APQ8076
#define DALCHIPINFO_ID_MSM8976     CHIPINFO_ID_MSM8976
#define DALCHIPINFO_ID_MDM9650     CHIPINFO_ID_MDM9650
#define DALCHIPINFO_ID_IPQ8065     CHIPINFO_ID_IPQ8065
#define DALCHIPINFO_ID_IPQ8069     CHIPINFO_ID_IPQ8069
#define DALCHIPINFO_ID_MSM8939_BC  CHIPINFO_ID_MSM8939_BC
#define DALCHIPINFO_ID_MDM9250     CHIPINFO_ID_MDM9250
#define DALCHIPINFO_ID_MDM9255     CHIPINFO_ID_MDM9255
#define DALCHIPINFO_ID_MDM9350     CHIPINFO_ID_MDM9350
#define DALCHIPINFO_ID_MDM9655     CHIPINFO_ID_MDM9655
#define DALCHIPINFO_ID_IPQ4028     CHIPINFO_ID_IPQ4028
#define DALCHIPINFO_ID_IPQ4029     CHIPINFO_ID_IPQ4029
#define DALCHIPINFO_ID_APQ8052     CHIPINFO_ID_APQ8052
#define DALCHIPINFO_ID_MDM9607     CHIPINFO_ID_MDM9607
#define DALCHIPINFO_ID_APQ8096     CHIPINFO_ID_APQ8096
#define DALCHIPINFO_ID_MSM8998     CHIPINFO_ID_MSM8998
#define DALCHIPINFO_ID_MSM8953     CHIPINFO_ID_MSM8953
#define DALCHIPINFO_ID_MSM8937     CHIPINFO_ID_MSM8937
#define DALCHIPINFO_ID_APQ8037     CHIPINFO_ID_APQ8037
#define DALCHIPINFO_ID_MDM8207     CHIPINFO_ID_MDM8207
#define DALCHIPINFO_ID_MDM9207     CHIPINFO_ID_MDM9207
#define DALCHIPINFO_ID_MDM9307     CHIPINFO_ID_MDM9307
#define DALCHIPINFO_ID_MDM9628     CHIPINFO_ID_MDM9628
#define DALCHIPINFO_ID_MSM8909W    CHIPINFO_ID_MSM8909W
#define DALCHIPINFO_ID_APQ8009W    CHIPINFO_ID_APQ8009W
#define DALCHIPINFO_ID_MSM8996L    CHIPINFO_ID_MSM8996L
#define DALCHIPINFO_ID_MSM8917     CHIPINFO_ID_MSM8917
#define DALCHIPINFO_ID_APQ8053     CHIPINFO_ID_APQ8053
#define DALCHIPINFO_ID_MSM8996SG   CHIPINFO_ID_MSM8996SG
#define DALCHIPINFO_ID_MSM8997     CHIPINFO_ID_MSM8997
#define DALCHIPINFO_ID_APQ8017     CHIPINFO_ID_APQ8017
#define DALCHIPINFO_ID_MSM8217     CHIPINFO_ID_MSM8217
#define DALCHIPINFO_ID_MSM8617     CHIPINFO_ID_MSM8617
#define DALCHIPINFO_ID_MSM8996AU   CHIPINFO_ID_MSM8996AU
#define DALCHIPINFO_ID_APQ8096AU   CHIPINFO_ID_APQ8096AU
#define DALCHIPINFO_ID_APQ8096SG   CHIPINFO_ID_APQ8096SG
#define DALCHIPINFO_ID_MSM8940     CHIPINFO_ID_MSM8940
#define DALCHIPINFO_ID_MDM9665     CHIPINFO_ID_MDM9665
#define DALCHIPINFO_ID_MSM8996SGAU CHIPINFO_ID_MSM8996SGAU
#define DALCHIPINFO_ID_APQ8096SGAU CHIPINFO_ID_APQ8096SGAU
#define DALCHIPINFO_ID_SDM660      CHIPINFO_ID_SDM660
#define DALCHIPINFO_ID_SDM630      CHIPINFO_ID_SDM630
#define DALCHIPINFO_ID_APQ8098     CHIPINFO_ID_APQ8098
#define DALCHIPINFO_ID_MSM8920     CHIPINFO_ID_MSM8920
#define DALCHIPINFO_ID_SDM845      CHIPINFO_ID_SDM845
#define DALCHIPINFO_ID_MDM9206     CHIPINFO_ID_MDM9206
#define DALCHIPINFO_ID_IPQ8074     CHIPINFO_ID_IPQ8074
#define DALCHIPINFO_ID_SDA660      CHIPINFO_ID_SDA660
#define DALCHIPINFO_ID_SDM658      CHIPINFO_ID_SDM658
#define DALCHIPINFO_ID_SDA658      CHIPINFO_ID_SDA658
#define DALCHIPINFO_ID_SDA630      CHIPINFO_ID_SDA630
#define DALCHIPINFO_ID_SDM830      CHIPINFO_ID_SDM830
#define DALCHIPINFO_ID_SDX50M      CHIPINFO_ID_SDX50M
#define DALCHIPINFO_ID_QCA6290     CHIPINFO_ID_QCA6290
#define DALCHIPINFO_ID_MSM8905     CHIPINFO_ID_MSM8905
#define DALCHIPINFO_ID_SDC830      CHIPINFO_ID_SDC830
#define DALCHIPINFO_NUM_IDS        CHIPINFO_NUM_IDS

/**
 * Map legacy famliy IDs to their new versions
 */
#define DALCHIPINFO_FAMILY_UNKNOWN     CHIPINFO_FAMILY_UNKNOWN
#define DALCHIPINFO_FAMILY_MSM6246     CHIPINFO_FAMILY_MSM6246
#define DALCHIPINFO_FAMILY_MSM6260     CHIPINFO_FAMILY_MSM6260
#define DALCHIPINFO_FAMILY_QSC6270     CHIPINFO_FAMILY_QSC6270
#define DALCHIPINFO_FAMILY_MSM6280     CHIPINFO_FAMILY_MSM6280
#define DALCHIPINFO_FAMILY_MSM6290     CHIPINFO_FAMILY_MSM6290
#define DALCHIPINFO_FAMILY_MSM7200     CHIPINFO_FAMILY_MSM7200
#define DALCHIPINFO_FAMILY_MSM7500     CHIPINFO_FAMILY_MSM7500
#define DALCHIPINFO_FAMILY_MSM7600     CHIPINFO_FAMILY_MSM7600
#define DALCHIPINFO_FAMILY_MSM7625     CHIPINFO_FAMILY_MSM7625
#define DALCHIPINFO_FAMILY_MSM7X30     CHIPINFO_FAMILY_MSM7X30
#define DALCHIPINFO_FAMILY_MSM7800     CHIPINFO_FAMILY_MSM7800
#define DALCHIPINFO_FAMILY_MDM8200     CHIPINFO_FAMILY_MDM8200
#define DALCHIPINFO_FAMILY_QSD8650     CHIPINFO_FAMILY_QSD8650
#define DALCHIPINFO_FAMILY_MSM7627     CHIPINFO_FAMILY_MSM7627
#define DALCHIPINFO_FAMILY_QSC6695     CHIPINFO_FAMILY_QSC6695
#define DALCHIPINFO_FAMILY_MDM9X00     CHIPINFO_FAMILY_MDM9X00
#define DALCHIPINFO_FAMILY_QSD8650A    CHIPINFO_FAMILY_QSD8650A
#define DALCHIPINFO_FAMILY_MSM8X60     CHIPINFO_FAMILY_MSM8X60
#define DALCHIPINFO_FAMILY_MDM8200A    CHIPINFO_FAMILY_MDM8200A
#define DALCHIPINFO_FAMILY_QSD8672     CHIPINFO_FAMILY_QSD8672
#define DALCHIPINFO_FAMILY_MDM6615     CHIPINFO_FAMILY_MDM6615
#define DALCHIPINFO_FAMILY_MSM8660     CHIPINFO_FAMILY_MSM8X60
#define DALCHIPINFO_FAMILY_MSM8960     CHIPINFO_FAMILY_MSM8960
#define DALCHIPINFO_FAMILY_MSM7625A    CHIPINFO_FAMILY_MSM7625A
#define DALCHIPINFO_FAMILY_MSM7627A    CHIPINFO_FAMILY_MSM7627A
#define DALCHIPINFO_FAMILY_MDM9X15     CHIPINFO_FAMILY_MDM9X15
#define DALCHIPINFO_FAMILY_MSM8930     CHIPINFO_FAMILY_MSM8930
#define DALCHIPINFO_FAMILY_MSM8630     CHIPINFO_FAMILY_MSM8930
#define DALCHIPINFO_FAMILY_MSM8230     CHIPINFO_FAMILY_MSM8930
#define DALCHIPINFO_FAMILY_APQ8030     CHIPINFO_FAMILY_MSM8930
#define DALCHIPINFO_FAMILY_MSM8627     CHIPINFO_FAMILY_MSM8627
#define DALCHIPINFO_FAMILY_MSM8227     CHIPINFO_FAMILY_MSM8627
#define DALCHIPINFO_FAMILY_MSM8974     CHIPINFO_FAMILY_MSM8974
#define DALCHIPINFO_FAMILY_MSM8625     CHIPINFO_FAMILY_MSM8625
#define DALCHIPINFO_FAMILY_MSM8225     CHIPINFO_FAMILY_MSM8625
#define DALCHIPINFO_FAMILY_APQ8064     CHIPINFO_FAMILY_APQ8064
#define DALCHIPINFO_FAMILY_MDM9x25     CHIPINFO_FAMILY_MDM9x25
#define DALCHIPINFO_FAMILY_MSM8960AB   CHIPINFO_FAMILY_MSM8960AB
#define DALCHIPINFO_FAMILY_MSM8930AB   CHIPINFO_FAMILY_MSM8930AB
#define DALCHIPINFO_FAMILY_MSM8x10     CHIPINFO_FAMILY_MSM8x10
#define DALCHIPINFO_FAMILY_MPQ8092     CHIPINFO_FAMILY_MPQ8092
#define DALCHIPINFO_FAMILY_MSM8x26     CHIPINFO_FAMILY_MSM8x26
#define DALCHIPINFO_FAMILY_MSM8225Q    CHIPINFO_FAMILY_MSM8225Q
#define DALCHIPINFO_FAMILY_MSM8625Q    CHIPINFO_FAMILY_MSM8625Q
#define DALCHIPINFO_FAMILY_APQ8x94     CHIPINFO_FAMILY_APQ8x94
#define DALCHIPINFO_FAMILY_APQ8084     CHIPINFO_FAMILY_APQ8x94
#define DALCHIPINFO_FAMILY_MSM8x32     CHIPINFO_FAMILY_MSM8x32
#define DALCHIPINFO_FAMILY_MDM9x35     CHIPINFO_FAMILY_MDM9x35
#define DALCHIPINFO_FAMILY_MSM8974_PRO CHIPINFO_FAMILY_MSM8974_PRO
#define DALCHIPINFO_FAMILY_FSM9900     CHIPINFO_FAMILY_FSM9900
#define DALCHIPINFO_FAMILY_MSM8x62     CHIPINFO_FAMILY_MSM8x62
#define DALCHIPINFO_FAMILY_MSM8926     CHIPINFO_FAMILY_MSM8926
#define DALCHIPINFO_FAMILY_MSM8994     CHIPINFO_FAMILY_MSM8994
#define DALCHIPINFO_FAMILY_IPQ8064     CHIPINFO_FAMILY_IPQ8064
#define DALCHIPINFO_FAMILY_MSM8916     CHIPINFO_FAMILY_MSM8916
#define DALCHIPINFO_FAMILY_MSM8936     CHIPINFO_FAMILY_MSM8936
#define DALCHIPINFO_FAMILY_MDM9x45     CHIPINFO_FAMILY_MDM9x45
#define DALCHIPINFO_FAMILY_MSM8996     CHIPINFO_FAMILY_MSM8996
#define DALCHIPINFO_FAMILY_APQ8096     CHIPINFO_FAMILY_MSM8996
#define DALCHIPINFO_FAMILY_MSM8992     CHIPINFO_FAMILY_MSM8992
#define DALCHIPINFO_FAMILY_MSM8909     CHIPINFO_FAMILY_MSM8909
#define DALCHIPINFO_FAMILY_FSM90xx     CHIPINFO_FAMILY_FSM90xx
#define DALCHIPINFO_FAMILY_MSM8952     CHIPINFO_FAMILY_MSM8952
#define DALCHIPINFO_FAMILY_QDF2432     CHIPINFO_FAMILY_QDF2432
#define DALCHIPINFO_FAMILY_MSM8929     CHIPINFO_FAMILY_MSM8929
#define DALCHIPINFO_FAMILY_MSM8956     CHIPINFO_FAMILY_MSM8956
#define DALCHIPINFO_FAMILY_MSM8976     CHIPINFO_FAMILY_MSM8956
#define DALCHIPINFO_FAMILY_QCA961x     CHIPINFO_FAMILY_QCA961x
#define DALCHIPINFO_FAMILY_IPQ40xx     CHIPINFO_FAMILY_QCA961x
#define DALCHIPINFO_FAMILY_MDM9x55     CHIPINFO_FAMILY_MDM9x55
#define DALCHIPINFO_FAMILY_MDM9x07     CHIPINFO_FAMILY_MDM9x07
#define DALCHIPINFO_FAMILY_MSM8998     CHIPINFO_FAMILY_MSM8998
#define DALCHIPINFO_FAMILY_MSM8953     CHIPINFO_FAMILY_MSM8953
#define DALCHIPINFO_FAMILY_MSM8993     CHIPINFO_FAMILY_MSM8993
#define DALCHIPINFO_FAMILY_MSM8937     CHIPINFO_FAMILY_MSM8937
#define DALCHIPINFO_FAMILY_MSM8917     CHIPINFO_FAMILY_MSM8917
#define DALCHIPINFO_FAMILY_MSM8996SG   CHIPINFO_FAMILY_MSM8996SG
#define DALCHIPINFO_FAMILY_MSM8997     CHIPINFO_FAMILY_MSM8997
#define DALCHIPINFO_FAMILY_MSM8940     CHIPINFO_FAMILY_MSM8940
#define DALCHIPINFO_FAMILY_MDM9x65     CHIPINFO_FAMILY_MDM9x65
#define DALCHIPINFO_FAMILY_SDM660      CHIPINFO_FAMILY_SDM660
#define DALCHIPINFO_FAMILY_SDM630      CHIPINFO_FAMILY_SDM630
#define DALCHIPINFO_FAMILY_MSM8920     CHIPINFO_FAMILY_MSM8920
#define DALCHIPINFO_FAMILY_SDM845      CHIPINFO_FAMILY_SDM845
#define DALCHIPINFO_FAMILY_IPQ807x     CHIPINFO_FAMILY_IPQ807x
#define DALCHIPINFO_FAMILY_SDM830      CHIPINFO_FAMILY_SDM830
#define DALCHIPINFO_NUM_FAMILIES       CHIPINFO_NUM_FAMILIES

/**
 * Map legacy foundry IDs to their new versions
 */
#define DALCHIPINFO_FOUNDRYID_UNKNOWN     CHIPINFO_FOUNDRYID_UNKNOWN
#define DALCHIPINFO_FOUNDRYID_TSMC        CHIPINFO_FOUNDRYID_TSMC
#define DALCHIPINFO_FOUNDRYID_GF          CHIPINFO_FOUNDRYID_GF
#define DALCHIPINFO_FOUNDRYID_SS          CHIPINFO_FOUNDRYID_SS
#define DALCHIPINFO_FOUNDRYID_IBM         CHIPINFO_FOUNDRYID_IBM
#define DALCHIPINFO_FOUNDRYID_UMC         CHIPINFO_FOUNDRYID_UMC
#define DALCHIPINFO_NUM_FOUNDRYIDS        CHIPINFO_NUM_FOUNDRYIDS

/**
  @}
*/ /* end_group macros */


/* ============================================================================
**             Public Data Structures used by the ChipInfo Dal
** ========================================================================== */
/**
  @addtogroup data_structures
  @{
*/

/**
 * Chip version. See ChipInfoDefs.h.
 */
typedef ChipInfoVersionType DalChipInfoVersionType;

/**
 * Supported modems. See ChipInfoDefs.h.
 */
typedef ChipInfoModemType DalChipInfoModemType;

/**
 * Chip identification type. See ChipInfoDefs.h.
 */
typedef ChipInfoIdType DalChipInfoIdType;

/**
 * Chip Family type. See ChipInfoDefs.h.
*/
typedef ChipInfoFamilyType DalChipInfoFamilyType;

/**
 * Chip serial number. See ChipInfoDefs.h
 */
typedef ChipInfoSerialNumType DalChipInfoSerialNumType;

/**
 * Serial number as read from QFPROM. See ChipInfoDefs.h
 */
typedef ChipInfoQFPROMChipIdType DalChipInfoQFPROMChipIdType;

/**
 * Chip Foundry type. See ChipInfoDefs.h.
 */
typedef ChipInfoFoundryIdType DalChipInfoFoundryIdType;


/**
  @}
*/ /* end_group Data Structures */

#endif /* CHIPINFODEFSLEGACY_H  */
