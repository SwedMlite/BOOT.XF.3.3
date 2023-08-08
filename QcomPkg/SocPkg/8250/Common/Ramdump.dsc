#==============================================================================
# @file Loader.dsc
# SM8250 Loader package.
#
# Copyright (c) 2017 - 2018 Qualcomm Technologies, Inc. All rights reserved.
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

  OUTPUT_DIRECTORY               = Build/SM8250$(VAR)/RamDump

!include QcomPkg/SocPkg/8250/Common/TargetCommon.dsc.inc

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]
#
# SEC
#
  QcomPkg/SocPkg/Library/XBLRamDumpLib/XBLRamDumpLib.inf {
    <LibraryClasses>
      IpaTargetLib|QcomPkg/SocPkg/8250/Library/IpaTargetLib/IpaTargetLib.inf
      QusbTargetLib|QcomPkg/SocPkg/8250/Library/QusbTargetLib/QusbTargetLib.inf
      SdccCommonLib|QcomPkg/Library/SdccCommonLib/SdccCommonRamdumpLib.inf
      ClockTargetLib|MdePkg/Library/BaseDebugLibNull/BaseDebugLibNull.inf
      ClockRamDumpLib|QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockRamDumpLib/ClockRamDumpLib.inf

      ArmMmuLib|ArmPkg/Library/ArmMmuLib/ArmMmuBaseLib.inf
      CacheMaintenanceLib|ArmPkg/Library/ArmCacheMaintenanceLib/ArmCacheMaintenanceLib.inf
      MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf

      UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf

      ProcLib|QcomPkg/Library/ProcLib/ProcLib.inf
      TlmmLib|QcomPkg/Library/TlmmLib/TlmmLib.inf
      TLMMTargetLib|QcomPkg/SocPkg/8250/Library/TLMMTargetLib/TLMMTargetLib.inf
      IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf

      HobLib|EmbeddedPkg/Library/PrePiHobLib/PrePiHobLib.inf
      PrePiHobListPointerLib|EmbeddedPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf
      ShLib|QcomPkg/Library/ShLib/ShLibMgr.inf
      TargetResetLib|QcomPkg/Library/NullLibs/TargetResetLibNull/TargetResetLib.inf
      ReportStatusCodeLib|QcomPkg/Library/NullLibs/PeiReportStatusCodeLibFrameworkNull/PeiReportStatusCodeLibNull.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      SerialPortLib|QcomPkg/Library/SerialPortLib/SerialPortLib.inf
      DebugLib|QcomPkg/Library/DebugLib/DebugLib.inf


      DisplayLib|QcomPkg/Library/DisplayLib/DisplayLib.inf

      HALDSILib|QcomPkg/Library/HALDSILib/HALDSILib.inf
      HALDPLibStub|QcomPkg/Library/HALDPLib/HALDPLibStub.inf
      ExternalDisplayLib|QcomPkg/Library/ExternalDisplayLib/ExternalDisplayLibStub.inf
      HALMDSSLib|QcomPkg/Library/HALMDSSLib/HALMDSS6xx.inf
      MDPLibBoot|QcomPkg/Library/MDPLib/MDPLibBoot.inf
      MDPPlatformLibBoot|QcomPkg/SocPkg/8250/Library/MDPPlatformLibBoot/MDPPlatformLibBoot.inf

      RNGLib|QcomPkg/SocPkg/Library/RNGLoaderLib/RNGLibHw.inf 
      UCLib|QcomPkg/Library/UCLib_loader/UCLib_loader.inf
      HashLib|QcomPkg/Library/HashLib_loader/HashLibHw_loader.inf 
      CryptoLib|QcomPkg/Library/CryptoLib/CryptoLib.inf
      
      I2CLib|QcomPkg/Library/I2CLib/I2CLibLoader.inf
      I2CFWImageLib|QcomPkg/SocPkg/8250/Settings/I2C/I2CFWImageLib.inf

      <PcdsFixedAtBuild>
        gQcomTokenSpaceGuid.SDCCDmaEnabled|TRUE
        gQcomTokenSpaceGuid.SDCCSdhciEnable|TRUE
        gQcomTokenSpaceGuid.SDCCEmmcSpeedMode|0
  }

