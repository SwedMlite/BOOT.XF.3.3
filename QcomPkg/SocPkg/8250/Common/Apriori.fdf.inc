# @file Apriori.fdf.inc
# Apriori for LA SM8250
#
# Copyright (c) 2015 -2019 Qualcomm Technologies, Inc. All rights reserved.
# Portions Copyright (c) 2009, Apple Inc. All rights reserved.
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#
#
#==============================================================================
#                              EDIT HISTORY
#
#
# when       who     what, where, why
# --------   ---     ----------------------------------------------------------
# 08/15/19   px      Move ResetRuntimeDxe before PmicDxe, otherwise Reset API
#                    in PmicDxe doesn't work.
# 06/05/19   av      Add priority for newly introduced SPSS load driver
# 05/08/19   jt      Load PmicDxeLa before storage
# 09/10/18   kpa     switch to DiskIo and PartitionDxe from MdeModulePkg
# 08/28/18   daisond Added DDRInfoDxe  before DisplayDxe
# 08/07/18   yw      add PILDxe after DisplayDxe, WatchdogDxe after VariableDxe
# 03/28/18   jp      Added CipherDxe
# 05/03/18   pranavj Ported SHMBridge changes to Poipu
# 03/20/18   kpa     Move FvSimpleFileSystemDxe prior to DisplayDxe
# 03/08/18   jt      Change SdccDxe for now
# 03/23/17   jp      Enabled Hash and RNG drivers
# 03/01/17   vk      Remove non LA drivers
# 04/18/16   clm     Add limits.
# 03/09/16   va      updating PmicDxe for La
# 03/04/16   bh      Move Fat/English/FVSimple under UFS/Sdcc
# 01/27/16   sm      Renamed ChargerAppLADxe to QcomChargerDxe
# 06/24/15   bh      Initial version
#
#==============================================================================

########################### APRIORI Start ####################################################
## Load order for drivers ##
## NOTE: After the APRIORI End section is where drivers must be added in order for them to
##       be included in the FD. The APRIORI just dictates a load order regardless of whether
##       the drivers are actually included in the FD or not

  APRIORI DXE {
        INF MdeModulePkg/Core/Dxe/DxeMain.inf

#
#    Arch Protocols
#
#    EfiSecurityArchProtocolGuid,
#    EfiCpuArchProtocolGuid,
#    EfiMetronomeArchProtocolGuid,
#    EfiTimerArchProtocolGuid,
#    EfiBdsArchProtocolGuid,
#    EfiWatchdogTimerArchProtocolGuid,
#    EfiRuntimeArchProtocolGuid,
#    EfiVariableArchProtocolGuid,
#    EfiVariableWriteArchProtocolGuid,
#    EfiCapsuleArchProtocolGuid,
#    EfiMonotonicCounterArchProtocolGuid,
#    EfiResetArchProtocolGuid,
#    EfiRealTimeClockArchProtocolGuid,
#

        INF QcomPkg/Drivers/EnvDxe/EnvDxe.inf

# Report Status Code Handler and Router
        INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/RscRtDxe.inf
        INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/SCHandlerRtDxe.inf

#  Arch Protocol :  EfiRuntimeArchProtocolGuid,
        INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf

#  Arch Protocol :  EfiCpuArchProtocolGuid,
        INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
        INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf

#  Arch Protocol :  EfiMetronomeArchProtocolGuid,
        INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf

#  Arch Protocol :  EfiTimerArchProtocolGuid,
        INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

        # NOTE: DAL has dependency on SMEM
        INF QcomPkg/Drivers/SmemDxe/SmemDxe.inf
        INF QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf

        INF QcomPkg/Drivers/HWIODxe/HWIODxe.inf
        INF QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
        INF QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf

        INF QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf

        #INF QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
        INF QcomPkg/Drivers/ULogDxe/ULogDxe.inf
        INF QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
    INF QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
        INF QcomPkg/Drivers/NpaDxe/NpaDxe.inf
        INF QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
        INF QcomPkg/Drivers/PdcDxe/PdcDxe.inf
    INF QcomPkg/Drivers/VcsDxe/VcsDxe.inf
        INF QcomPkg/Drivers/ClockDxe/ClockDxe.inf
        INF QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf

        INF QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
        INF QcomPkg/Drivers/TzDxe/ScmDxeLA.inf

#For I2C, the ordering should be TLMM-->PMIC-->I2C
        INF QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
                #ResetRuntimeDxe must be placed prior to PmicDxe.
                #Otherwise reset API inside PmicDxe doesn't work.
        INF QcomPkg/Drivers/ResetRuntimeDxe/ResetRuntimeDxe.inf
        INF QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf

        ## Storage stack
        #INF QcomPkg/Drivers/DiskIoDxe/DiskIoDxe.inf
        INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf

        #INF QcomPkg/Drivers/PartitionDxe/PartitionDxe.inf
        INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf

        INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
        INF MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf
        #INF QcomPkg/Drivers/SdccDxe/SdccDxe_SDBoot.inf
        INF QcomPkg/Drivers/SdccDxe/SdccDxe.inf
        INF QcomPkg/Drivers/UFSDxe/UFSDxe.inf
        INF FatPkg/EnhancedFatDxe/Fat.inf


        ## SCM and TZ Loader protocol
        INF QcomPkg/Drivers/TzDxe/TzDxeLA.inf

        ## Varible Services
#  Arch Protocol :  EfiVariableArchProtocolGuid,
#  Arch Protocol :  EfiVariableWriteArchProtocolGuid,
#PRESIL
        #INF MdeModulePkg/Universal/Variable/EmuRuntimeDxe/EmuVariableRuntimeDxe.inf
        INF QcomPkg/Drivers/VariableDxe/VariableDxe.inf

        #FeatureEnablerDxe depends on TzDxe
        INF QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

#  HW wdog driver, depends on variabledxe
        INF QcomPkg/Drivers/QcomWDogDxe/QcomWDogDxe.inf

# DDRInfo Protocol
        INF QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf

#  Arch Protocol :  EfiResetArchProtocolGuid,
        # DisplayDxe depends on storage, filesystem, variable services
        INF QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf

        INF QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
        INF QcomPkg/Drivers/PILDxe/PILDxe.inf

        INF QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf

        INF QcomPkg/Drivers/CPRDxe/CPRDxe.inf

#  Arch Protocol :  EfiWatchdogTimerArchProtocolGuid,
        INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf

#  Arch Protocol :  EfiSecurityArchProtocolGuid,
        #INF QcomPkg/Drivers/SecurityDxe/SecurityDxe.inf
        INF QcomPkg/Drivers/ASN1X509Dxe/ASN1X509Dxe.inf
        INF QcomPkg/Drivers/SecRSADxe/SecRSADxe.inf
        INF QcomPkg/Drivers/VerifiedBootDxe/VerifiedBootDxe.inf
#VerifiedBootNullDxe for presilicon/bringup validations.
        #INF QcomPkg/Drivers/VerifiedBootNullDxe/VerifiedBootNullDxe.inf (PreSil)




#QDSS Driver (Debugtrace)
        #INF QcomPkg/Drivers/QdssDxe/QdssDxe.inf

        #INF QcomPkg/Drivers/DppDxe/DppDxe.inf

#  Arch Protocol :  EfiMonotonicCounterArchProtocolGuid,
        INF QcomPkg/Drivers/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf


#  Arch Protocol :  EfiRealTimeClockArchProtocolGuid,
        INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf

        INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
        INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf

#  Arch Protocol :  EfiCapsuleArchProtocolGuid,
        INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  #INF QcomPkg/Drivers/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf

#  Arch Protocol :  EfiBdsArchProtocolGuid,
        # HIIdb and Fonts are BDS dependencies
        INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
        INF QcomPkg/Drivers/FontDxe/FontDxe.inf
        #INF MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
        INF QcomPkg/Drivers/QcomBds/QcomBds.inf

        INF QcomPkg/Drivers/SPIDxe/SPIDxe.inf
        INF QcomPkg/Drivers/I2CDxe/I2CDxe.inf


        INF QcomPkg/Drivers/AdcDxe/AdcDxe.inf
        INF QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
        INF QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
#PRESIL
        INF QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
        #INF QcomPkg/Drivers/ChargerExDxe/NullLib/ChargerExDxeNull.inf

        INF QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
        INF QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
        INF QcomPkg/Drivers/XhciDxe/XhciDxe.inf
        INF QcomPkg/Drivers/UsbBusDxe/UsbBusDxe.inf
        INF QcomPkg/Drivers/UsbKbDxe/UsbKbDxe.inf
        INF QcomPkg/Drivers/UsbMassStorageDxe/UsbMassStorageDxe.inf

        INF QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf

        #
        #  Moved ChargerDxe/AdcDxe/ButtonsDxe above DisplayDxe
        #
        INF QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
        INF QcomPkg/Drivers/TsensDxe/TsensDxe.inf


        INF QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf

        INF QcomPkg/Drivers/GpiDxe/GpiDxe.inf

#
#     Critical modules until here,
#
#     Non critical parts follow from here
#
# INF QcomPkg/Drivers/MpPowerDxe/MpPowerDxe.inf
        INF QcomPkg/Drivers/HashDxe/HashDxe.inf
        INF QcomPkg/Drivers/CipherDxe/CipherDxe.inf
        INF QcomPkg/Drivers/MacDxe/MacDxe.inf
        INF QcomPkg/Drivers/RNGDxe/RngDxe.inf
#       INF QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf

        # Console
        # HIIdb and Fonts are dependencies for these and should be loaded before
        INF QcomPkg/Drivers/SimpleTextInOutSerialDxe/SimpleTextInOutSerial.inf
        INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
        INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
        INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

  }

#
########################### APRIORI End ####################################################
#

