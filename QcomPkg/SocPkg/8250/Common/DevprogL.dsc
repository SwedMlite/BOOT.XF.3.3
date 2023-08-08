#==============================================================================
# @file DevProgL.dsc
# SM8250 Deviceprogrammer Lite 
#
# Copyright (c) 2017-2019 Qualcomm Technologies, Inc. All rights reserved.
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

  OUTPUT_DIRECTORY               = Build/SM8250$(VAR)/DevprogL

!include QcomPkg/SocPkg/8250/Common/TargetCommon.dsc.inc

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]
  QcomPkg/XBLLoader/DevPrgL.inf {
     <LibraryClasses>
     XBLLoaderLib|QcomPkg/SocPkg/Library/XBLLoaderLib/XBLLoaderDevProgLib.inf
      SmemLib|QcomPkg/Library/NullLibs/SmemLibNull/SmemLibNull.inf
      DevPrgLLib|QcomPkg/SocPkg/Library/DevPrgLLib/DevPrgLLib.inf
      DevPrgDLib|QcomPkg/Library/NullLibs/DevPrgDLibNull/DevPrgDLibNull.inf
      BootDdrTrainingLib|QcomPkg/XBLLoader/BootDdrTrainingLibNull.inf
      BootDebugLib|QcomPkg/XBLLoader/BootDebugLibNull.inf
      VSenseTargetLib|QcomPkg/Library/NullLibs/VSenseTargetLibNull/VSenseTargetLibNull.inf
      ColdplugLib|QcomPkg/Library/NullLibs/ColdplugLibNull/ColdplugLibNull.inf
      LoaderAptLib|QcomPkg/Library/NullLibs/LoaderAptLibNull/LoaderAptLibNull.inf
      QusbTargetLib|QcomPkg/SocPkg/8250/Library/QusbTargetLib/QusbTargetLib.inf
      QusbLdrLib|QcomPkg/Library/NullLibs/QusbLdrLibNull/QusbLdrLibNull.inf
      CPRTargetLib|QcomPkg/Library/NullLibs/PowerLibNull/CprLibNull.inf
      RailwayTargetLib|QcomPkg/SocPkg/8250/Library/RailwayTargetLib/RailwayTargetLib.inf
      XcfgLoaderElf|QcomPkg/Library/XBLConfig/XcfgRamElfLib.inf
      ProcLib|QcomPkg/Library/ProcLib/ProcLib.inf
      ClockTargetLib|QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockTargetLib.inf
      TLMMTargetLib|QcomPkg/SocPkg/8250/Library/TLMMTargetLib/TLMMTargetLib.inf
      UCLib|QcomPkg/Library/UCLib_devprog/UCLib_devprog.inf
      HashLib|QcomPkg/Library/HashLib_loader/HashLibHw_loader.inf
      StorageProfileLib|QcomPkg/Library/StorageCommonLib/StorageProfileStub.inf

      <PcdsFixedAtBuild>
        gQcomTokenSpaceGuid.PcdBuildType|0x1
   }
