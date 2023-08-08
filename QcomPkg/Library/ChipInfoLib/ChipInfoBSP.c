/*==============================================================================
  @file ChipInfoBSP.c

  ChipInfo BSP data.

================================================================================
        Copyright (c) 2016-2019 Qualcomm Technologies, Inc.
               All Rights Reserved.
            QUALCOMM Proprietary/GTDR
================================================================================

  $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/ChipInfoLib/ChipInfoBSP.c#6 $
  $DateTime: 2020/04/15 03:31:28 $
  $Author: pwbldsvc $

==============================================================================*/

/*==============================================================================
      Include Files
==============================================================================*/
#include "comdef.h"
#include "ChipInfoLocal.h"
#include "ChipInfoLoader.h"

/*==============================================================================
      Data Definitons
==============================================================================*/
//#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

/*==============================================================================
      Data Definitons
==============================================================================*/

/*
 * ChipInfoDataLUT
 *
 * Array of chip id strings, chip IDs, part numbers, and modem support.
 *
 * Various HLOS clients still expect to see the old naming convention for
 * Hana variants. Continue to report the legacy names for Hana.
 *
 * This table only needs to contain mappings for targets supported out of this warehouse.
 */
static const ChipInfoDataLUTType ChipInfoDataLUT[] =
{
  { "UNKNOWN",    CHIPINFO_ID_UNKNOWN,    CHIPINFO_PARTNUM_UNKNOWN,     CHIPINFO_MODEM_UNKNOWN    },
  { "SM8250",     CHIPINFO_ID_SDA865,     CHIPINFO_PARTNUM_SDA865,      CHIPINFO_MODEM_UNKNOWN    },
  { "SM_LAHAINA", CHIPINFO_ID_SM_LAHAINA, CHIPINFO_PARTNUM_SM_LAHAINA,  CHIPINFO_MODEM_SUPPORTED  },
  { "QRB5165", CHIPINFO_ID_QRB5165, CHIPINFO_PARTNUM_QRB5165,  CHIPINFO_MODEM_UNKNOWN  },
};


/*
 * ChipInfoArchFamilyArray
 *
 * Array of default chip ID and family IDs to use if the JTAG ID is not recognized.
 * The product family can be identified using TCSR_SOC_HW_VERSION, which is defined
 * in RTL and is therefore always available. This is typically only needed when
 * parts haven't yet been fused (e.g. RUMI or early during silicon bring up).
 *
 * This array only needs to contain information for product families being supported
 * from this warehouse.
 */
static const ChipInfoArchFamilyDataType ChipInfoArchFamilyArray[] =
{
  { CHIPINFO_ARCH_FAMILY_UNKNOWN,     0,  CHIPINFO_FAMILY_UNKNOWN,  CHIPINFO_ID_UNKNOWN     },

  { CHIPINFO_ARCH_FAMILY_HOYA,        8,  CHIPINFO_FAMILY_SDA865,   CHIPINFO_ID_SDA865      },
  { CHIPINFO_ARCH_FAMILY_HOYA,        15, CHIPINFO_FAMILY_LAHAINA,  CHIPINFO_ID_SM_LAHAINA  },
};


static ChipInfoBSPType ChipInfoBSP =
{
  .aLUT = ChipInfoDataLUT,
  .nNumLUTEntries = ARRAY_SIZE(ChipInfoDataLUT),
  .aArchFamilyData = ChipInfoArchFamilyArray,
  .nNumArchFamilyDataEntries = ARRAY_SIZE(ChipInfoArchFamilyArray),
};


/*==============================================================================
      Functions
==============================================================================*/

ChipInfoBSPType *ChipInfo_GetBSPData
(
  void
)
{
  return &ChipInfoBSP;
}
