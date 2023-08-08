#==============================================================================
# @file Loader.dsc
# SM8250 Loader package.
#
# Copyright (c) 2017 - 2019 Qualcomm Technologies, Inc. All rights reserved.
#==============================================================================

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = SM8250Pkg
  PLATFORM_GUID                  = AA99686E-4D75-3829-5220-F4874BA2F216
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT

  OUTPUT_DIRECTORY               = Build/SM8250$(VAR)/Loader

!include QcomPkg/SocPkg/8250/Common/TargetCommon.dsc.inc

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]
  QcomPkg/XBLLoader/XBLLoader.inf {
    <LibraryClasses>
      DevPrgLLib|QcomPkg/Library/NullLibs/DevPrgLLibNull/DevPrgLLibNull.inf
      DevPrgDLib|QcomPkg/Library/NullLibs/DevPrgDLibNull/DevPrgDLibNull.inf
      BootDdrTrainingLib|QcomPkg/XBLLoader/BootDdrTrainingLib.inf
      BootDebugLib|QcomPkg/XBLLoader/BootDebugLib.inf
      QusbLdrLib|QcomPkg/SocPkg/8250/Library/QusbLdrLib/QusbLdrLib.inf
      VSenseTargetLib|QcomPkg/Library/NullLibs/VSenseTargetLibNull/VSenseTargetLibNull.inf
      LoaderAptLib|QcomPkg/Library/NullLibs/LoaderAptLibNull/LoaderAptLibNull.inf
      SdccCommonLib|QcomPkg/Library/SdccCommonLib/SdccCommonReducedLib.inf
      ProcLib|QcomPkg/Library/ProcLib/ProcLib.inf
      ClockTargetLib|QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockTargetLib.inf
      TLMMTargetLib|QcomPkg/SocPkg/8250/Library/TLMMTargetLib/TLMMTargetLib.inf
      IcbTargetLib|QcomPkg/SocPkg/8250/Library/ICBTargetLib/ICBTargetLib.inf

      # Only required for XBL loader
      CPRTargetLib|QcomPkg/SocPkg/8250/Library/CPRTargetLib/Loader/CPRTargetLib.inf
      #CPRTargetLib|QcomPkg/Library/NullLibs/PowerLibNull/CprLibNull.inf
      RailwayTargetLib|QcomPkg/SocPkg/8250/Library/RailwayTargetLib/RailwayTargetLib.inf
      HashLib|QcomPkg/Library/NullLibs/CryptoDriversLibNull/CeLibNull.inf
      
      StorageProfileLib|QcomPkg/Library/StorageCommonLib/StorageProfile.inf
      StorageBootCommonLib|QcomPkg/Library/StorageCommonLib/StorageLoaderCommon.inf
      
      # I2C Library
      I2CLib|QcomPkg/Library/I2CLib/I2CLibLoader.inf
      I2CApiLib|QcomPkg/Library/I2CApiLib/I2CApiLib.inf
      I2CFWImageLib|QcomPkg/SocPkg/8250/Settings/I2C/I2CFWImageLib.inf

      #This PCD values should match with the ones defined in boot_sbl_shared.h for sbl_build_type.
      <PcdsFixedAtBuild>
        gQcomTokenSpaceGuid.PcdBuildType|0x0
        gQcomTokenSpaceGuid.SDCCDmaEnabled|TRUE
        gQcomTokenSpaceGuid.SDCCSdhciEnable|TRUE
        gQcomTokenSpaceGuid.SDCCEmmcSpeedMode|0
  }

