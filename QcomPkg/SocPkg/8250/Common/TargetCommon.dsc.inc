#==============================================================================
# @file Common_855.dscinc
# SM8250 Loader package.
#
# Copyright (c) 2017 - 2019 Qualcomm Technologies, Inc. All rights reserved.
# Portions Copyright (c) 2009 - 2010, Apple Inc. All rights reserved.
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#==============================================================================


!include QcomPkg/SocPkg/Common/Common.dsc.inc
!include QcomPkg/SocPkg/8250/$(VAR)/Variant.dsc.inc
[LibraryClasses.common]
  UartSettingsLib|QcomPkg/SocPkg/8250/Settings/UART/UartSettingsLib.inf
  DALGenLibLoader|QcomPkg/SocPkg/8250/Settings/DALConfig/DALGenLibLoader_LA.inf
  DALGenLibTools|QcomPkg/SocPkg/8250/Settings/DALConfig/DALGenLibTools.inf
  DALConfigLoaderLib|QcomPkg/SocPkg/8250/Settings/DALConfig/DALConfigLoaderLib_LA.inf
  DALConfigToolsLib|QcomPkg/SocPkg/8250/Settings/DALConfig/DALConfigToolsLib.inf
  SpiNorCommonLib|QcomPkg/Library/NullLibs/SpiNorCommonLibNull/SpiNorCommonNullLib.inf
  UfsTargetBootLib|QcomPkg/SocPkg/8250/Library/UfsTargetLib/UfsTargetBootLib.inf
  UfsTargetJtagLib|QcomPkg/SocPkg/8250/Library/UfsTargetLib/UfsTargetJtagLib.inf
  IcbTargetLib|QcomPkg/SocPkg/8250/Library/ICBTargetLib/ICBTargetLib.inf
  IcbCfgLib|QcomPkg/Library/ICBLib/ICBLib.inf
  ChipInfoTargetLib|QcomPkg/SocPkg/8250/Library/ChipInfoTargetLib/ChipInfoTargetLib.inf
  QusbDciCommonLib|QcomPkg/SocPkg/8250/Library/QusbDciCommonLib/QusbDciCommonLib.inf
  UsbSharedLib|QcomPkg/SocPkg/8250/Library/UsbSharedLib/UsbSharedLibLoader.inf
  TsensTargetLib|QcomPkg/SocPkg/8250/Library/TsensTargetLib/TsensTargetLib.inf
  TsensLoaderLib|QcomPkg/Library/TsensLib/TsensLoaderLib.inf
  PmicLib|QcomPkg/SocPkg/8250/Library/PmicLib/PmicLib.inf
  #PmicLib|QcomPkg/Library/NullLibs/PmicLibNull/PmicLibNull.inf
  PmicLoaderLib|QcomPkg/SocPkg/8250/Library/PmicLib/loader/PmicLoaderLib.inf
  #PmicLoaderLib|QcomPkg/Library/NullLibs/PmicLibNull/PmicLoaderLibNull.inf
  # SPMI Library
  SPMILib|QcomPkg/SocPkg/8250/Library/SPMILib/SPMILib.inf
  CPRTargetLib|QcomPkg/SocPkg/8250/Library/CPRTargetLib/Loader/CPRTargetLib.inf
  RailwayTargetLib|QcomPkg/SocPkg/8250/Library/RailwayTargetLib/RailwayTargetLib.inf
  PrngLib|QcomPkg/SocPkg/Library/RNGLoaderLib/RNGLibHw.inf
  I2CFWImageLib|QcomPkg/SocPkg/8250/Settings/I2C/I2CFWImageLib.inf
  SdccTargetLib|QcomPkg/SocPkg/8250/Library/SdccTargetLib/SdccLoaderTargetLib.inf
  SdccClockLib|QcomPkg/SocPkg/8250/Library/SdccClockLib/SdccLoaderClockLib.inf

[BuildOptions.AARCH64]
  GCC:*_*_AARCH64_ARCHCC_FLAGS  == -mllvm -inline-threshold-multicaller-size=20 -mtune=cortex-a53 -DMDEPKG_NDEBUG -DQCOM_EDK2_PATCH $(FEATURE_FLAGS) -I$(WORKSPACE)/QcomPkg/SocPkg/Include -I$(WORKSPACE)/QcomPkg/SocPkg/8250/Include -include $(WORKSPACE)/QcomPkg/SocPkg/8250/Include/Target_cust.h
  GCC:*_*_AARCH64_ARCHPP_FLAGS  == -DMDEPKG_NDEBUG -DQCOM_EDK2_PATCH $(FEATURE_FLAGS) -I$(WORKSPACE)/QcomPkg/SocPkg/Include -I$(WORKSPACE)/QcomPkg/SocPkg/8250/Include -include $(WORKSPACE)/QcomPkg/SocPkg/8250/Include/Target_cust.h

!if $(PRODMODE) == "PRODMODE"
  GCC:*_*_*_CC_FLAGS = -DPRODMODE
!endif
