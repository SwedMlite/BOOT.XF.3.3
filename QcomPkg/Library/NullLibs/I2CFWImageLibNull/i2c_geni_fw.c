/*==================================================================================================

FILE: i2c_geni_fw

DESCRIPTION: I2C GENI FW

                      Copyright (c) 2019 Qualcomm Technologies, Incorporated.
                                        All rights reserved.
                        Qualcomm Technologies, Confidential and Proprietary.

==================================================================================================*/
/*==================================================================================================
                                    Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/Library/NullLibs/I2CFWImageLibNull/i2c_geni_fw.c#1 $

when       who     what, where, why
--------   ---     --------------------------------------------------------
01/03/19   bng     Kona FW upgrade

==================================================================================================*/

#include "I2CFWImage.h"
#include "i2c_api.h"

uint8  __attribute__ ((aligned (4))) qup_v2_5_i2c_fw[] =
{
};

i2c_status i2c_get_fw (uint8 **base_ptr, uint32 version)
{
    *base_ptr = qup_v2_5_i2c_fw;
    return I2C_SUCCESS;
}
