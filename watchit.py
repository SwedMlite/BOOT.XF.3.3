#!/usr/bin/env python


#                          EDIT HISTORY FOR MODULE
#
# This section contains comments describing changes made to the module.
# Notice that changes are listed in reverse chronological order.
#
# when       who     what, where, why
# --------   ---     -----------------------------------------------------------
# 03/18/19   yps     Update build file hash
# 01/18/19   kpa     Update protocol folder hash.
# 01/17/19   kpa     Update build file hash, block protocol folder edits
# 08/03/16   vk      Update build file hash
# 08/03/16   yps     Update build file hash
# 06/22/16   bh      Update build file hash
# 01/12/16   et      Update build file hash
# 10/21/15   ck      Added one comdef.h check
# 09/30/15   ck      Added cross target logic
# 09/29/15   ck      Added warning as error logic
# 09/24/15   ck      Added logic to print error count after successful copyright check
# 09/22/15   ck      Added Qcom Copyright feature
# 09/10/15   ck      Added buildit.py protection
# 09/08/15   ck      Added missing CR LF removal logic from self hash check
# 08/26/15   ck      Added logic to create temp file without CR or LF when checking hash
# 08/24/15   ck      Initial release


from optparse import OptionParser
import shutil
import os
import sys
import locale
import stat
import platform
import subprocess
import tempfile


GENERAL_ERROR_CODE = 1
WATCHIT_SELF_CHECK_ERROR_CODE = 2
BUILD_SCRIPTS_CHECK_ERROR_CODE = 3
CROSS_TARGET_CHECK_ERROR_CODE = 4
WARNING_AS_ERROR_CHECK_ERROR_CODE = 5
DAL_TARGET_CHECK_ERROR_CODE = 6
TARGET_DRIVER_REFERENCE_COMMON_CODE_ERROR_CODE = 7
TARGET_SPECIFIC_COMMON_CODE_ERROR_CODE = 8
GENERATE_WATCHIT_HASH_VALUE_ERROR_CODE = 9
QCOM_COPYRIGHT_CHECK_ERROR_CODE = 10
ONE_COMDEF_CHECK_ERROR_CODE = 11
FOLDER_FILES_CHECK_ERROR_CODE = 12

# build_files_sha1 structure, <File Name>, <Hash>, <mandatory Existance>
build_files_sha1=[["buildex.py", "5dfab176d472dc14bb18a9a722d105148f61351a", True]]

folder_files_sha=[
["EFIAcpiPlatform.h", "1cab738511a0264ef63425c862e00c28baeb1a38", True],
["EFIAcpiPlatformTest.h", "a413595e281730ef0bdbacb604369b07962bcf5c", True],
["EFIAdapterInformation.h", "36949696513272e91498ab4f6703863481a7cc2f", True],
["EFIAdapterInformationRegister.h", "b288b33140552647abc5f00c762f27475d58894a", True],
["EFIAdc.h", "a98a95aefbb777430fb7a952a3a76520326f7ceb", True],
["EFIASN1X509.h", "20b82bae4bcdd745331f5ffbe1b369b23e53f755", True],
["EFIAuthentication.h", "2283c9df400cb513548764929ae02ddef052ffbe", True],
["EFIBootConfig.h", "843ab2b0b4d9985679f33e81d1f1a2e4ce27ec05", True],
["EFIBootModeMgmt.h", "ae889301f7a3268edb431b50b10ce695f6bc2d53", True],
["EFICapsule.h", "99c70f3c7e76f2309cd20774734a583f9042d379", True],
["EFICardInfo.h", "e083b72011921cbec98e495f59916066b5e9369e", True],
["EFICate.h", "14847787e25768e0aad04239ed62604f3ec57265", True],
["EFICharger.h", "220019e960c9434bf0ad63ac3324102948f05095", True],
["EFIChargerEx.h", "69d19610105dbe2b9ceb3d49e0247f7edc80a999", True],
["EFIChargerExtn.h", "20f10316cef331300ffdb58cce2159922155c383", True],
["EFIChargerTask.h", "0a3759ae232f0ff10ae3c0cb3fc1f6a26c55c9b9", True],
["EFIChipInfo.h", "ebad75a2cc5b1e3a5cdb630d9b627089dcfabe1c", True],
["EFIChipInfoTypes.h", "b085adba259ccb2f517a11e49dbc66dd3beea752", True],
["EFICipher.h", "f53ecb0cf2ad28320182cd360a3fe141cc4af616", True],
["EFIClock.h", "c7c33d793af2655dd924466e852016a8f212e00f", True],
["EFICmdDb.h", "0acccba7153dd684a459b198f56b94c046c28825", True],
["EFICryptoSelect.h", "958720c9259d911130850881590975cbe8835af5", True],
["EFIDALSYSProtocol.h", "13dcec1214a5a0a35b644723eb1a0faf6e1ce205", True],
["EFIDALTF.h", "e3770369bd0b2459cad7c3d296883b99e563046d", True],
["EFIDDRGetConfig.h", "8219ea2dd711e735ab8c9ecf0a9333cdfb8f9c6a", True],
["EFIDebug.h", "2c3af6bcc4e27eacee5ac5f0630c97f7bf4fb2be", True],
["EFIDisplayPwr.h", "bfdd14e7b86ed956b591f77d838d01cf4d8be9bc", True],
["EFIDisplayPwrCtrl.h", "1ebea62eb050dbfad2007a4f18a65e4639dd461f", True],
["EFIDisplayUtils.h", "7e61f46002c8661fd5b9958e22a71d1ca417232b", True],
["EFIDmov.h", "6aedd067fc9488d7ee40d341afca97448212bbec", True],
["EFIDpp.h", "146f8fbac8644130d52becbe902d10c99f0977d6", True],
["EFIEmmcErase.h", "879c3cc55efc93394ae55380d34e4a9e8c314547", True],
["EFIEmmcSecureErase.h", "ee0cffea754c772a2f06df94bc527aa0db69ab82", True],
["EFIEncryption.h", "e556d68e4b89ce18a2ff17b42a54fac4c60d2b3b", True],
["EFIEraseBlock.h", "38e7e9cba37908df3cb235c29625d3050ac6e1d4", True],
["EFIFeatureEnabler.h", "4b9502319f91f2dda9e639b13b4e978fe55956b0", True],
["EFIGLink.h", "18086914b7c98b2a48c672d4f5124d1ad21144ac", True],
["EFIGpiProtocol.h", "6694000e7bd629ddc5b832eb1c07f9a31d5697ec", True],
["EFIHALIOMMUProtocol.h", "4f3aabb979d8621e0b4449f00a32230b90e9ab10", True],
["EFIHWIO.h", "e307ef3cd8ff11380bb8530c6ceaefb138c93893", True],
["EFII2C.h", "643a1eaa4201714cf26a305b7f60fc9af862b27a", True],
["EFIIci.h", "62b7a66013ca4b839dd069e7d5d143ffed72db4c", True],
["EFIKernelInterface.h", "d1eba4b7b6e0eb471272e503f65f88223bc6520a", True],
["EFILimits.h", "4e8bf7e3024598f8454eb2a0cc58639611a796e4", True],
["EFIMac.h", "349e4d188c984acf5a898d3aa049e98416b9cb58", True],
["EFIMeasureBoot.h", "6f56cbe3bff3b36d27369a0c0ec4a73941208d9a", True],
["EFIMemoryMap.h", "0ee5382e861ef20462962bb8d67b819505e98cee", True],
["EFIMorPpi.h", "997b14594cb5f7468f3b66ed7704b392f79a2004", True],
["EFIMpIoService.h", "edb0a9d34841dae9c6200413aed94401127f80bb", True],
["EFIMpSchedService.h", "d957e7850ca5d5ba367c93cf1fb69e96aefc5f7b", True],
["EFINpa.h", "5329c5c729a9f9762b66289a8865b8f7b1e8ac58", True],
["EFIPIL.h", "a7f3f83c4ca41e09cf18ef7a7f1e307a9d8041ce", True],
["EFIPILProxy.h", "f8e2793e60319fa765c22e72f0b7f4a288c51d31", True],
["EFIPlatformInfo.h", "338b78efe7d09be2b7adf619fcf6272307beb973", True],
["EFIPlatformInfoTypes.h", "67638bf53712cc2b63e2dcecc64c48e61aeee083", True],
["EFIPmicAb.h", "3706f8278d809bc2c34cd53b091808f73c988968", True],
["EFIPmicBms.h", "99c975416d5f912993bd502ddf3dabc946141f9e", True],
["EFIPmicBmsVm.h", "595ec4550343499a0a23fe41e0cd9d76c6190a2a", True],
["EFIPmicClkBuff.h", "483c1e4ce1d43bf9adabd38be9f0ea5ed8ec9aef", True],
["EFIPmicFg.h", "baed68a70ac1080e637d79d955b7f952e791d681", True],
["EFIPmicGlink.h", "38de7b84c6abcb6abfaca7e1ab005b9dadad962d", True],
["EFIPmicGpio.h", "aa514d559e58e753563734773d44d16b55ba2c75", True],
["EFIPmicHaptics.h", "2aec40b98f497ad11ccbb97f72336af1922b9111", True],
["EFIPmicIbb.h", "0767b08488fcd8500453564bbb0f6131d897accc", True],
["EFIPmicLab.h", "4f07beb0a9f27f60718b18abd064fdca7dd9c2a2", True],
["EFIPmicLbc.h", "50a99852ba1dd4ae623a688f76465140edda7439", True],
["EFIPmicLcdb.h", "2743fe8c9e7958ed3ae9979ed7b900a911bd9bdb", True],
["EFIPmicLpg.h", "bfe5048f03c795b0d4e144634bed8e132af24893", True],
["EFIPmicMipiBif.h", "89adbbcd6077cf79ebe0e146b046005ecec23a81", True],
["EFIPmicNpaTest.h", "8f4e0fdeeffebe4bf15d53fbcd697fac430f4dfb", True],
["EFIPmicOledb.h", "68f0ef38c7317246720819c8a40b7f3b44f6ab64", True],
["EFIPmicPon.h", "ab64f34dfb7673c5c6becbeb1379e9725750ebac", True],
["EFIPmicPwm.h", "0f2213b62fbdf83ab322b09834129dfc68d77350", True],
["EFIPmicPwrOn.h", "88bb1113dc33088a7b70a26fd53ca70ccbc0bbfe", True],
["EFIPmicRgbLed.h", "1af8e645943ef14df54ed42b3cdd4def77b9f835", True],
["EFIPmicRTC.h", "937dd1a9d177be7dd8c6940ca6138766e19eaeef", True],
["EFIPmicSchg.h", "cd6149701e7884de0fbd4813a8a7d2e1ba8ff0f0", True],
["EFIPmicSmbchg.h", "acfe8e547c26ae05227715eb05f75e20a8e69c35", True],
["EFIPmicTest.h", "55430c1da4bf6f4bd1806acf75891dff5f3c593c", True],
["EFIPmicUsb.h", "4d4d82e5dafda7975a9be40784d459e126990afb", True],
["EFIPmicVersion.h", "4a745ec68cae56f83c6f44b3834376e1bc3d5f6b", True],
["EFIPmicVib.h", "8b58621cc848c6a6fdbc759a10e46fa4ae8a38dd", True],
["EFIPmicVreg.h", "98e95c29f90eefb16f5dc4fe3721ef22b1168c07", True],
["EFIPmicWled.h", "50ef8561cc504313e092d6f147732ff88db1512d", True],
["EFIPsleepInterface.h", "1c742550070edc31c680ac66c6a7ee23f983399b", True],
["EFIPwrUtils.h", "e2ff6cd7b1caaea44261b8a41bf3e543ff623871", True],
["EFIQcomCharger.h", "e1536610463210b393d3a9a1f76b36528ec863c4", True],
["EFIQcomEnv.h", "5b20266cc89a8d94493803fcdadc44cc0f0df833", True],
["EFIQcomHardwareInterrupt.h", "f196bf3a7be68d753b0e9f56f7ea539319bce339", True],
["EFIQcomWDog.h", "336f97922c052522e1c90b06d7d0407d9c1d9814", True],
["EFIQdss.h", "6ccf954404c46bcfde95198e700b971287426ea6", True],
["EFIQseecom.h", "51975357ee154926c9095ddd140544e0c4551fee", True],
["EFIRamPartition.h", "2cced8f5594827f7f37781da1528b933341a5779", True],
["EFIRawFileSystem.h", "2238a2875c4c9502c13d92f39f63a587bca5ce80", True],
["EFIResetReason.h", "7ffa1dc4321549a0a8cfd43ad88e7a39ebd77a28", True],
["EFIRng.h", "96e88d0dcc6c00b4353804b15114fec024c4eba3", True],
["EFIRpm.h", "d4f132e0fe250906cf52ba254e282e0cf2619a3c", True],
["EFIRpmb.h", "5745cc562029a1a47d4ad3b71c9d541592dd972f", True],
["EFIRpmh.h", "7691253f9a193ff018576923d43b416315108e73", True],
["EFIRpmServices.h", "d641a0c75c18d35b2be1b1ebe2a476465fd9c4f5", True],
["EFIScm.h", "f48916cdfdfa0144196be9dd524faf840e3661f2", True],
["EFIScmModeSwitch.h", "f7d0b388e65f1d40bb425ff51eb06bb02fcbe4c5", True],
["EFISdccConfig.h", "5293b7772f8cf2a6a911298abda4bcad90cfa575", True],
["EFISecRSA.h", "9ab1fa3ebce6c6ca3fb362ae4772034f29e46b56", True],
["EFIShmBridge.h", "d158b61df2708b3ec9ff640256df4f19d75471fa", True],
["EFISmd.h", "5d9f5c3b681cd1f6ed5ab92baa3408c4a9f073d0", True],
["EFISmem.h", "e3c7c53f5170a007b5c917831f5e5a53b6f79b7b", True],
["EFISMMUProtocol.h", "5e2fa6b4c0e7c32d372e845bb0233b42bb791559", True],
["EFISPI.h", "20bbf7e819414bb330083c44af71700b0bbf6a37", True],
["EFISPMI.h", "7892d8c2fa9f343c681cd88cecf25b5d1991cc40", True],
["EFIStorageWriteProtect.h", "91673361e4a01edad3d19ffde36840acc8ea1d38", True],
["EFITlmm.h", "559ed88bd27ae595e58b664f2e77d78e4622af50", True],
["EFIToolSupport.h", "64f7e314e9b2b0d9a207120c5e16baefd9098d06", True],
["EFITrEE.h", "48434ba510e22f2e6b1dc229b91571077793b335", True],
["EFITsens.h", "004285593117e9c8ed882837bfc0b4f77576043b", True],
["EFITzeLoader.h", "d6a4510a35aa78de1db8aa3ff8211129ebc7e950", True],
["EFIULog.h", "31b88a824c3639f868e183c878a6951e0499fa23", True],
["EFIUsb2HostController.h", "86d66eab04c78f4a92b4eab4bb5cb8a72b4b8d86", True],
["EFIUsbConfig.h", "83d035819e1d946c9948b6598ee4e0c5e511592e", True],
["EFIUsbDevice.h", "0e01353410155bc3fefadc36f5be15cbb30d90eb", True],
["EFIUsbEx.h", "3d0482dc99ab40244937a07548bd5c85561a98f1", True],
["EFIUsbfnChgSrv.h", "3ec3abbbbb1eeb7e91684bd54a888188adad1a24", True],
["EFIUsbfnIo.h", "d8a10f229eb88e65b863f1e2056d42f51725fd87", True],
["EFIUsbInitProtocol.h", "aac8db0ef62d7bbc1459656d5a06e84edebb342d", True],
["EFIUsbIo.h", "d6b45ec76b91f66e4fcee3053d3d99ea56369114", True],
["EFIUsbMsdPeripheral.h", "bee772f332a69f0c0c9d5937b989a1238193cb86", True],
["EFIUsbPortTest.h", "f053a79b4e656c4965b25bc6dd07a20d2306cedc", True],
["EFIUsbPortTestHelper.h", "4b9cbeed27dcab14b0dabf2a2357bc01824be6cd", True],
["EFIUsbPwrCtrl.h", "e41f56c8b89a1c5e3b037fae9babad0eb750343e", True],
["EFIVariableServices.h", "2fd1a6dee41243e6646bbf9395a39ad5a8b0eda8", True],
["EFIVcs.h", "4e2ebd96e7876799114d8d58564a5d6bdcb4bb53", True],
["EFIVerifiedBoot.h", "12c6d0fd81a6cc7a5c256fdd19dff836cf6be300", True],
["EfiWinAcpiUpdate.h", "5389a1c74dd9b855b0be33e5b2c0c9c018de410c", True],
["EFIWriteProtect.h", "7f175508dfee1928a61693e54faa9b98e4d0dea0", True]]

folder_files_list = ['EFIAcpiPlatform.h', 'EFIAcpiPlatformTest.h', 'EFIAdapterInformation.h', 'EFIAdapterInformationRegister.h',
'EFIAdc.h', 'EFIASN1X509.h', 'EFIAuthentication.h', 'EFIBootConfig.h', 'EFIBootModeMgmt.h','EFICapsule.h',
'EFICardInfo.h', 'EFICate.h', 'EFICharger.h', 'EFIChargerEx.h', 'EFIChargerExtn.h', 'EFIChargerTask.h', 'EFIChipInfo.h',
'EFIChipInfoTypes.h', 'EFICipher.h', 'EFIClock.h', 'EFICmdDb.h', 'EFICryptoSelect.h', 'EFIDALSYSProtocol.h',
'EFIDALTF.h', 'EFIDDRGetConfig.h', 'EFIDebug.h', 'EFIDisplayPwr.h', 'EFIDisplayPwrCtrl.h', 'EFIDisplayUtils.h',
'EFIDmov.h', 'EFIDpp.h', 'EFIEmmcErase.h', 'EFIEmmcSecureErase.h', 'EFIEncryption.h', 'EFIEraseBlock.h', 'EFIFeatureEnabler.h',
'EFIGLink.h', 'EFIGpiProtocol.h', 'EFIHALIOMMUProtocol.h', 'EFIHWIO.h', 'EFII2C.h', 'EFIIci.h',
'EFIKernelInterface.h', 'EFILimits.h', 'EFIMac.h', 'EFIMeasureBoot.h', 'EFIMemoryMap.h', 'EFIMorPpi.h', 'EFIMpIoService.h', 
'EFIMpSchedService.h', 'EFINpa.h', 'EFIPIL.h', 'EFIPILProxy.h', 'EFIPlatformInfo.h', 'EFIPlatformInfoTypes.h', 'EFIPmicAb.h', 
'EFIPmicBms.h', 'EFIPmicBmsVm.h','EFIPmicClkBuff.h', 'EFIPmicFg.h', 'EFIPmicGlink.h', 'EFIPmicGpio.h', 'EFIPmicHaptics.h', 
'EFIPmicIbb.h', 'EFIPmicLab.h', 'EFIPmicLbc.h', 'EFIPmicLcdb.h', 'EFIPmicLpg.h', 'EFIPmicMipiBif.h', 'EFIPmicNpaTest.h', 'EFIPmicOledb.h',
'EFIPmicPon.h', 'EFIPmicPwm.h', 'EFIPmicPwrOn.h', 'EFIPmicRgbLed.h', 'EFIPmicRTC.h', 'EFIPmicSchg.h', 'EFIPmicSmbchg.h', 'EFIPmicTest.h',
'EFIPmicUsb.h', 'EFIPmicVersion.h', 'EFIPmicVib.h', 'EFIPmicVreg.h', 'EFIPmicWled.h', 'EFIPsleepInterface.h', 'EFIPwrUtils.h',
'EFIQcomCharger.h', 'EFIQcomEnv.h', 'EFIQcomHardwareInterrupt.h', 'EFIQcomWDog.h', 'EFIQdss.h', 'EFIQseecom.h', 'EFIRamPartition.h', 
'EFIRawFileSystem.h', 'EFIResetReason.h', 'EFIRng.h', 'EFIRpm.h', 'EFIRpmb.h', 'EFIRpmh.h', 'EFIRpmServices.h', 'EFIScm.h', 
'EFIScmModeSwitch.h', 'EFISdccConfig.h', 'EFISecRSA.h', 'EFIShmBridge.h', 'EFISmd.h', 'EFISmem.h', 'EFISMMUProtocol.h',
'EFISPI.h', 'EFISPMI.h', 'EFIStorageWriteProtect.h', 'EFITlmm.h', 'EFIToolSupport.h', 'EFITrEE.h', 'EFITsens.h', 'EFITzeLoader.h',
'EFIULog.h', 'EFIUsb2HostController.h', 'EFIUsbConfig.h', 'EFIUsbDevice.h', 'EFIUsbEx.h', 'EFIUsbfnChgSrv.h', 'EFIUsbfnIo.h', 
'EFIUsbInitProtocol.h', 'EFIUsbIo.h', 'EFIUsbMsdPeripheral.h', 'EFIUsbPortTest.h', 'EFIUsbPortTestHelper.h', 'EFIUsbPwrCtrl.h',
'EFIVariableServices.h', 'EFIVcs.h', 'EFIVerifiedBoot.h','EfiWinAcpiUpdate.h', 'EFIWriteProtect.h']

# Target prefixes.  Folders that start with these strings are possible targets.
target_prefixes=["Msm", "Mdm", "SDM"]

# Target suffixes. Folders that begin with a target prefix and end with one of
# these suffixes denotes a target folder.
target_suffixes=["Pkg"]


##############################################################################
# main
##############################################################################
def main():

  parser = OptionParser()

  parser.add_option("-a", "--all",
                    action="store_true",
                    dest="enable_all_features",
                    default=False,
                    help="Enables all features except self check hash.  " + \
                         "That must be enabled on its own.  " + \
                         "Default is Off")

  parser.add_option("-b", "--build-hash-check",
                    action="store_true",
                    dest="enable_build_hash_check",
                    default=False,
                    help="Enables hash check of build files.  " + \
                         "Default is Off")
  
  parser.add_option("-f", "--folder-hash-check",
                    action="store_true",
                    dest="enable_Folder_hash_check",
                    default=False,
                    help="Checks for protocol update.  " + \
                         "Default is Off")						 

  parser.add_option("-c", "--cross-target-check",
                    action="store_true",
                    dest="enable_cross_target_check",
                    default=False,
                    help="Enables check to ensure targets are not referencing " + \
                         "code from other targets.  " + \
                         "Default is Off")

  parser.add_option("-d", "--dal-target-check",
                    action="store_true",
                    dest="enable_dal_target_check",
                    default=False,
                    help="Enables check to ensure DAL config files are set " + \
                         "to proper target.  " + \
                         "Default is Off")

  parser.add_option("-e", "--eval-dir",
                    action="store",
                    type="string",
                    dest="evaluation_dir",
                    default="boot_images/QcomPkg",
                    help="Base directory of where to start evaluation.  " + \
                         "Default is boot_images/QcomPkg")
  parser.add_option("-p", "--eval-intended-folder",
                    action="store",
                    type="string",
                    dest="evaluation_dir1",
                    default="boot_images/QcomPkg/Include/Protocol",
                    help="Intended directory of where to start evaluation.  " + \
                         "Default is boot_images/QcomPkg/Include/Protocol")						 

  parser.add_option("-g", "--generate-watchit-hash-value",
                    action="store_true",
                    dest="enable_generate_watchit_hash_value",
                    default=False,
                    help="Displays this file's hash value.  " + \
                         "Default is Off")

  parser.add_option("-o", "--one-comdef",
                    action="store_true",
                    dest="enable_one_comdef_check",
                    default=False,
                    help="Ensure there is only one comdef.h file in branch.  " + \
                         "Default is Off")

  parser.add_option("-q", "--qcom-copyright-dir",
                    action="store",
                    type="string",
                    dest="qcom_copyright_dir",
                    default="",
                    help="Enables the Qcom Copyright scan option and starts " + \
                         "evaluating from directory specified.  Evaluation " + \
                         "is recursive.")

  parser.add_option("--qcom-copyright-threshold",
                    action="store",
                    type="string",
                    dest="qcom_copyright_threshold",
                    default="0",
                    help="Number of Qcom Copyright errors allowed before fault " + \
                         "is triggered.")

  parser.add_option("-s", "--self-hash-check",
                    action="store",
                    type="string",
                    dest="watchit_hash_value",
                    help="Enables watchit self check.  Hash value supplied " + \
                         "is compared against this file's hash.")

  parser.add_option("-t", "--target-drivers-check",
                    action="store_true",
                    dest="enable_target_drivers_check",
                    default=False,
                    help="Enables target driver schema check.  " + \
                         "Default is Off")

  parser.add_option("-u", "--update-build-hash-values",
                    action="store_true",
                    dest="enable_update_build_hash_values",
                    default=False,
                    help="Automatically updates watchit's build file hash values." + \
                         "Default is Off")

  parser.add_option("-w", "--warning-as-error-disable-check",
                    action="store_true",
                    dest="enable_warning_as_error_check",
                    default=False,
                    help="Enables check to ensure warning as error is not " + \
                         "disabled in any INF file.  " + \
                         "Default is Off")

  (options, args) = parser.parse_args()


  # All defaults need to be OS agnostic.
  options.evaluation_dir = convert_directory_seperators(options.evaluation_dir)

  # Assign openssl_path based on operating system
  try:
    openssl_path = determine_openssl_path(options.evaluation_dir)
  except Exception as error:
    print error
    sys.exit(GENERAL_ERROR_CODE)


  # Generate and display the hash value of this file
  if (options.enable_generate_watchit_hash_value):
    try:
      print "WatchIt hash value" + ("." * 4),
      result = generate_watchit_hash_value(openssl_path)
      print result
    except Exception as error:
      print error
      sys.exit(GENERATE_WATCHIT_HASH_VALUE_ERROR_CODE)


  # Check hash of this watchit.py file.
  if (options.watchit_hash_value):
    try:
      print "Executing watchit self check" + ("." * 27),
      watchit_self_check(openssl_path,
                         options.watchit_hash_value)
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(WATCHIT_SELF_CHECK_ERROR_CODE)


  # Check the hash of the build script files to ensure 
  if (options.enable_all_features or options.enable_build_hash_check):
    try:
      print "Executing build scripts check" + ("." * 26),
      build_scripts_check(options.evaluation_dir,
                          openssl_path)
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(BUILD_SCRIPTS_CHECK_ERROR_CODE)

  # Check the hash of the build script files to ensure 
  if (options.enable_all_features or options.enable_Folder_hash_check):
    try:
      print "Executing folder check : Checking if made updates any in intended folder" + ("." * 12),
      folder_files_check(options.evaluation_dir1,
                          openssl_path)
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(FOLDER_FILES_CHECK_ERROR_CODE)
	  
	  
  # Check that targets are not referencing code from other targets
  if (options.enable_all_features or options.enable_cross_target_check):
    try:
      print "Executing cross target check" + ("." * 27),
      failure_list = cross_target_check(options.evaluation_dir)
    except Exception as error:
      print error
      sys.exit(CROSS_TARGET_CHECK_ERROR_CODE)

    if len(failure_list) == 0:
      print "PASSED"
    else:
      print "ERROR"
      for entry in failure_list:
        print "   File: " + entry[0] + "  Line:" + str(entry[1])
      sys.exit(CROSS_TARGET_CHECK_ERROR_CODE)


  # Check that warning as error is not turned off in any INF files
  if (options.enable_all_features or options.enable_warning_as_error_check):
    try:
      print "Executing warning as error disable check" + ("." * 15),
      failure_list = warning_as_error_check(options.evaluation_dir)
    except Exception as error:
      print error
      sys.exit(WARNING_AS_ERROR_CHECK_ERROR_CODE)

    if len(failure_list) == 0:
      print "PASSED"
    else:
      print "ERROR"
      for entry in failure_list:
        print "   File: " + entry[0] + "  Line:" + str(entry[1])
      sys.exit(WARNING_AS_ERROR_CHECK_ERROR_CODE)


  # Check that dal config files for a target are proper
  if (options.enable_all_features or options.enable_dal_target_check):
    try:
      print "Executing DAL target check" + ("." * 29),
      dal_target_check()
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(DAL_TARGET_CHECK_ERROR_CODE)


  # Check target drivers
  if (options.enable_all_features or options.enable_target_drivers_check):
    try:
      print "Executing target driver reference common code check" + ("." * 4),
      target_driver_reference_common_code_check()
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(TARGET_DRIVER_REFERENCE_COMMON_CODE_ERROR_CODE)

    try:
      print "Executing target specific common code check" + ("." * 12),
      target_specific_common_code_check()
      print "PASSED"
    except Exception as error:
      print error
      sys.exit(TARGET_SPECIFIC_COMMON_CODE_ERROR_CODE)


  # Check that only one comdef.h file exists
  if (options.enable_all_features or options.enable_one_comdef_check):
    try:
      print "Executing one comdef.h check" + ("." * 4),
      comdef_list = one_comdef_check(options.evaluation_dir)
    except Exception as error:
      print error
      sys.exit(ONE_COMDEF_CHECK_ERROR_CODE)

    if len(comdef_list) == 1:
      print "PASSED"
    elif len(comdef_list) < 1:
      print "ERROR"
      print "  comdef.h file could not be found"
      sys.exit(ONE_COMDEF_CHECK_ERROR_CODE)
    else:
      print "ERROR"
      for entry in comdef_list:
        print "  File: " + entry
      sys.exit(ONE_COMDEF_CHECK_ERROR_CODE)


  # Check Qcom Copyrights
  # Only execute copyright check if directory is given.  This is why it cannot
  # be executed with the -a (all) argument.
  if (len(options.qcom_copyright_dir)):
    try:
      print "Executing Qcom Copyright check starting from: " + \
            options.qcom_copyright_dir + ("." * 6),
      error_count = qcom_copyright_check(options.qcom_copyright_dir,
                                         options.qcom_copyright_threshold)
      print "PASSED (" + error_count + ")"
    except Exception as error:
      print error
      sys.exit(QCOM_COPYRIGHT_CHECK_ERROR_CODE)


  return


##############################################################################
# one_comdef_check
##############################################################################
# Make sure only one comdef.h file exists.
def one_comdef_check(evaluation_dir):

  comdef_file_locations = []

  for root, directories, files in os.walk(evaluation_dir):  
    for current_file in files:
      if current_file == 'comdef.h':
        comdef_file_locations.append(os.path.join(root,
                                                  current_file))

  return comdef_file_locations          


##############################################################################
# cross_target_check
##############################################################################
# Make sure a target does not have any pointers to another target.
# I.E. Referencing headers in 8996 from 8998.
def cross_target_check(evaluation_dir):

  failure_list = []
  target_list = []

  # Scan evaluation_dir for target directories.  When one is found investigate
  # all files inside of that folder for pointers to another target.
  directory_list = next(os.walk(evaluation_dir))[1]

  # Create a list of targets
  for current_directory in directory_list:
    if any(current_directory.startswith(prefix) for prefix in target_prefixes):
      if any(current_directory.endswith(suffix) for suffix in target_suffixes):
        target_list.append(current_directory)


  # Walk each target directory inspecting each file for references to
  # other targets
  for current_target in target_list:
    # Create a error target list which is target list minus target under test
    error_target_list = target_list
    error_target_list.remove(current_target)
    
    for root, directories, files in os.walk(os.path.join(evaluation_dir,
                                                         current_target)):
      for current_file in files:
        current_file = os.path.join(root, current_file)
        with open(current_file) as file:
          current_line = 0
          comment_block = False
          for line in file:
            current_line += 1
            # Determine if line contains a reference to a target
            if any(target in line for target in error_target_list):
              failure_list.append([current_file, current_line])                  
              
  return failure_list
               
               
##############################################################################
# warning_as_error_check
##############################################################################
# Ensure warnings as errors are not being disabled via INF and DSC files.
def warning_as_error_check(evaluation_dir):

  failure_list = []

  # Find all .dsc and .inf files
  for root, directories, files in os.walk(evaluation_dir):
    for current_file in files:
      if current_file.lower().endswith(".dsc") or \
         current_file.lower().endswith(".inf"):
        current_file = os.path.join(root, current_file)
        with open(current_file) as file:
          current_line = 0
          for line in file:
            current_line += 1
            # Determine if line contains "-Wno-error"
            if "-wno-error" in line.lower():
              failure_list.append([current_file, current_line])                  
              
  return failure_list


##############################################################################
# update_build_scripts_sha1_values
##############################################################################
# Updates watchit's internal build_script hash values
def update_build_scripts_sha1_values():
  return


##############################################################################
# build_scripts_check
##############################################################################
# Check digest of build scripts and compare against hardwired values.
# Reject if they do not match.
def build_scripts_check(evaluation_dir,
                        openssl_path):

  # Generate base directory of where build files exist
  base_directory = determine_boot_images_path(evaluation_dir)
  if not base_directory:
    raise NameError("ERROR: watchit::build_scripts_check: " + \
                    "Unable to determine base directory from " + \
                    "evaluation directory: " + evaluation_dir)
  base_directory = os.path.join(base_directory,
                                "QcomPkg")


  # Check that each build file exists and its digest is correct
  for current_entry in build_files_sha1:
    # Convert directory seperator to proper one for os.
    current_entry[0] = convert_directory_seperators(current_entry[0])

    # Check if file exists, if it doesn't and mandatory existance field 
    # is true then error
    if (not os.path.isfile(os.path.join(base_directory,
                                        current_entry[0]))):
      if (current_entry[2]):
        raise NameError("ERROR: watchit::build_scripts_check: " + \
                        "File does not exist but marked mandatory: " + \
                        os.path.join(base_directory, current_entry[0]))
      else:
        continue


    # Create temp file stripped of CR and LF
    temp_file = create_cr_lf_stripped_temp_file(os.path.join(base_directory,
                                                             current_entry[0]))


    # If an exception occurs delete the temp file before leaving function
    try:
      calculated_value = calculate_sha1(openssl_path,
                                        temp_file.name)
      #Uncomment to print hash for updating
      #print calculated_value
    except Exception as error:
      os.remove(temp_file.name)
      raise error

    # Delete the temp file
    os.remove(temp_file.name)

    # Check if hash value is present in output
    if not current_entry[1] == calculated_value:
      raise NameError("FAILED")


  return



##############################################################################
# folder_files_check
##############################################################################
# Check digest of build scripts and compare against hardwired values.
# Reject if they do not match.
def folder_files_check(evaluation_dir1,
                        openssl_path):
  base_directory = evaluation_dir1								
  print base_directory + '\n'
  cwd = os.getcwd()
  basedir = os.path.join(cwd, base_directory)
  basedir = convert_directory_seperators(basedir)
  for (dirpath, dirnames, filenames) in os.walk(basedir):    
    for current_file in filenames:
      if not current_file in folder_files_list:
		print (current_file, 'newly added FILE so erroring out now')
		raise NameError("FAILED")	

  # Check that each build file exists and its digest is correct
  for current_entry in folder_files_sha:
    # Convert directory seperator to proper one for os.
    current_entry[0] = convert_directory_seperators(current_entry[0]) 
    # Check if file exists, if it doesn't and mandatory existance field 
    # is true then error
    if (not os.path.isfile(os.path.join(base_directory,
                                        current_entry[0]))):
      if (current_entry[2]):
        raise NameError("ERROR: watchit::folder_files_check: " + \
                        "File does not exist but marked mandatory: " + \
                        os.path.join(base_directory, current_entry[0]))
      else:
        continue


    # Create temp file stripped of CR and LF
    temp_file = create_cr_lf_stripped_temp_file(os.path.join(base_directory,
                                                             current_entry[0]))


    # If an exception occurs delete the temp file before leaving function
    try:
      calculated_value = calculate_sha1(openssl_path,
                                        temp_file.name)
      #Uncomment to print hash for updating
      print calculated_value
    except Exception as error:
      os.remove(temp_file.name)
      raise error

    # Delete the temp file
    os.remove(temp_file.name)

    # Check if hash value is present in output
    if not current_entry[1] == calculated_value:
      print current_entry[0] + ' file modifed'	
      raise NameError("FAILED")


  return


##############################################################################
# dal_target_check
##############################################################################
# Evaluate DAL XML files for proper target
def dal_target_check():
  return


##############################################################################
# generate_watchit_hash_value
##############################################################################
def generate_watchit_hash_value(openssl_path):

 # Create temp file stripped of CR and LF
  temp_file = create_cr_lf_stripped_temp_file(os.path.realpath(__file__))


  # If an exception occurs delete the temp file before leaving function
  try:
    calculated_value = calculate_sha1(openssl_path,
                                      temp_file.name)
  except Exception as error:
    os.remove(temp_file.name)
    raise error


  # Delete the temp file
  os.remove(temp_file.name)

  return calculated_value


##############################################################################
# watchit_self_check
##############################################################################
# Watchit self hash check using user supplied hash value  
def watchit_self_check(openssl_path,
                       user_hash_value):

  # Create temp file stripped of CR and LF
  temp_file = create_cr_lf_stripped_temp_file(os.path.realpath(__file__))

  calculated_value = calculate_sha1(openssl_path,
                                    temp_file.name)

  # Check if user supplied hash matches
  if not user_hash_value == calculated_value:
    raise NameError("FAILED")


  return


##############################################################################
# target_driver_reference_common_code_check
##############################################################################
# Check target specific drivers for pulling in common code directly.
def target_driver_reference_common_code_check():
  return


##############################################################################
# target_specific_common_code_check
##############################################################################
# Check for target specific drivers in common folder
def target_specific_common_code_check():
  return


##############################################################################
# create_cr_lf_stripped_temp_file
##############################################################################
# Because of OS CR vs CRLF differences create a temp file that is
# stripped of CR and LF.
def create_cr_lf_stripped_temp_file(original_file):
  temp_file = tempfile.NamedTemporaryFile(delete=False)
  with open(original_file, "r") as file:
    for line in file:
      temp_file.write(line.replace("\n", "").replace("\r", ""))
  temp_file.flush()
  temp_file.close()

  return temp_file


##############################################################################
# calculate_sha1
##############################################################################
def calculate_sha1(openssl_path,
                   file_path):

  if not os.path.isfile(openssl_path):
    raise NameError("ERROR: watchit::calculate_sha1: " + \
                    "OpenSSL could not be found.")


  # Use openssl to calculate sha1 value of file
  try:
    openssl_result = subprocess.check_output([openssl_path,
                                              "dgst",
                                              "-sha1",
                                              file_path])
  except:
    raise NameError("ERROR: watchit::calculate_sha1: " + \
                    "OpenSSL returned an error.")


  # Result will have file name, equal size, then hash value
  # Make sure equal sign is in result
  if not "=" in openssl_result:
    raise NameError("ERROR: watchit::calculate_sha1: " + \
                    "OpenSSL result is not in proper format.")


  return openssl_result.split('=',1)[1].lstrip().rstrip()


##############################################################################
# convert_directory_seperators
##############################################################################
# Convert all directory seperators to proper one for executing OS
def convert_directory_seperators(path_to_convert):
  converted_path = path_to_convert.replace("/", os.sep)
  converted_path = converted_path.replace("\\", os.sep)

  return converted_path


##############################################################################
# determine_boot_images_path
##############################################################################
def determine_boot_images_path(evaluation_dir):

  # Make sure evaluation directory has a boot_images directory
  if not 'boot_images' in evaluation_dir:
    raise NameError("ERROR: watchit::determine_boot_images_path: " + \
                    "evaluation directory not in repository: " + \
                    evaluation_dir);


  return evaluation_dir.split('boot_images',1)[0] + 'boot_images'


##############################################################################
# determine_openssl_path
##############################################################################
def determine_openssl_path(evaluation_dir):

  # If executing on a windows machine set openssl_path to point to exe in
  # branch.  Linux assign to return value of "which".
  openssl_path = ""

  if (platform.system().lower() == "linux"):
    try:
      which_result = subprocess.check_output(["which",
                                              "openssl"]).lstrip().rstrip()
    except:
      raise NameError("ERROR: watchit::determine_openssl_path: " + \
                      "which returned an error.")

    if len(which_result):
      openssl_path = which_result
    else:
      raise NameError("ERROR: watchit::determine_openssl_path: " + \
                      "Unable to locate OpenSSL on system.")


  elif (platform.system().lower() == "windows"):
    # Obtain boot_images (base) path from evaluation_dir
    base_directory = determine_boot_images_path(evaluation_dir)
    if not base_directory:
      raise NameError("ERROR: watchit::determine_openssl_path: " + \
                      "Unable to determine base directory from " + \
                      "evaluation directory: " + evaluation_dir)

    openssl_path = os.path.join(base_directory,
                                "QcomPkg",
                                "Tools",
                                "sectools",
                                "bin",
                                "WIN",
                                "openssl.exe")
  else:
    # OpenSSL could not be found, raise error
    raise NameError("ERROR: watchit::determine_openssl_path: " + \
                    "Unable to locate OpenSSL on system.")


  return openssl_path


##############################################################################
# qcom_copyright_check
##############################################################################
def qcom_copyright_check(qcom_copyright_dir,
                         qcom_copyright_threshold):

  # Make sure starting directory exists
  if not os.path.isdir(qcom_copyright_dir):
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "Directory specified does not exist: " + \
                    qcom_copyright_dir)


  # Ensure threshold is greater than or equal to 0
  if qcom_copyright_threshold < 0:
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "Threshold supplied is invalid: " + \
                    qcom_copyright_threshold)


  # Watchit is closer to the base than the copyright script so it is ok
  # to start searching for the copyright script from here.
  script_path = ""
  base_directory = os.path.dirname(os.path.realpath(__file__))
  for root, directories, files in os.walk(base_directory):  
    for current_file in files:
      if current_file == 'QcomCopyright.py':
        script_path = os.path.join(root,
                                   'QcomCopyright.py')

  if not len(script_path):
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "Unable to locate QcomCopyright.py script")


  # Execute copyright script with appropriate arguments and collect output
  try:
    # Absolute path must be given as execution location of this script and
    # copyright script are different
    script_result = subprocess.check_output(["python",
                                             script_path,
                                             "-s",
                                             "-c",
                                             "-d" + os.path.abspath(qcom_copyright_dir),
                                             "-r"])
  except:
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "QcomCopyright.py returned an error.")
    
    
  # Result will have "Total errors: " and then value
  # Make sure line is in the output
  if not "Total errors:" in script_result:
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "QcomCopyright.py result is not in proper format.")
    
    
  total_errors = script_result.split('Total errors:',1)[1].lstrip().rstrip()


  # Compare total_errors against threshold
  if total_errors > qcom_copyright_threshold:
    raise NameError("ERROR: watchit::qcom_copyright_check: " + \
                    "Total errors (" + total_errors + ") exceeds " + \
                    "threshold of (" + qcom_copyright_threshold + ")")

  return total_errors
  

main()
