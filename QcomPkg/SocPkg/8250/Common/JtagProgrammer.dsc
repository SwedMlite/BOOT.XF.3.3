#==============================================================================
# @file JtagProgrammer.dsc
# SM8250 JtagProgrammer
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

  OUTPUT_DIRECTORY               = Build/SM8250$(VAR)/JtagProgrammer

!include QcomPkg/SocPkg/8250/Common/TargetCommon.dsc.inc

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]
  QcomPkg/Library/JtagProgrammerLib/JtagProgrammer.inf {
      <LibraryClasses>
        ClockTargetLib|QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockTargetLib.inf
	    ProcLib|QcomPkg/Library/ProcLib/ProcLib.inf
	StorageProfileLib|QcomPkg/Library/StorageCommonLib/StorageProfileStub.inf
      
      <PcdsFixedAtBuild>
        gQcomTokenSpaceGuid.PcdBuildType|0x4
        gQcomTokenSpaceGuid.SDCCDmaEnabled|FALSE
        gQcomTokenSpaceGuid.SDCCSdhciEnable|TRUE
        gQcomTokenSpaceGuid.SDCCEmmcSpeedMode|0
   }

