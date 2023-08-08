#ifndef __DDR_CORES_H__
#define __DDR_CORES_H__

/*******************************************************************************
 QUALCOMM Proprietary Design Data
 Copyright (c) 2014,2018, Qualcomm Technologies Incorporated.
 All rights reserved.
 ******************************************************************************/
/*==============================================================================
                              EDIT HISTORY
$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/DSFTargetLib/interface/header/itf_ds/ddr_cores.h#1 $
$DateTime: 2018/08/27 16:13:18 $
$Author: pwbldsvc $
==============================================================================*/

// Core Version
#define TARGET_CORE_ARCH_SHIFT  24
#define TARGET_CORE_MAJOR_SHIFT 16
#define TARGET_CORE_MINOR_SHIFT 8

#define TARGET_CORE_VER(arch, major, minor, patch) \
( \
    (arch << TARGET_CORE_ARCH_SHIFT) | \
    (major << TARGET_CORE_MAJOR_SHIFT) | \
    (minor << TARGET_CORE_MINOR_SHIFT) | \
    patch \
)


#endif /* __DDR_CORES_H__ */
