#!/usr/bin/env python
# Copyright (c) 2019 Qualcomm Technologies, Inc. All rights reserved.
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.


##############################################################################
#
# PLEASE UPDATE BELOW VARIALBES AS PER YOUR SETUP:
# -----------------------------------------------
#
# COMPILER_TOOLS:     See BaseTools/Conf/tools_def.template - use the
#                     toolchain identifier corresponding to your setup
#
# TOOLS_PATH_XXX:     Path to your toolchain installation
# PREFIX_PATH_XXX:    Path to additional toolchain installation
#
# SIGN_IMAGE:         Use sectools to sign image
#
##############################################################################

COMPILER_TOOLS = "CLANG40"

TOOLS_PATH_WIN="C:\\Apps\\LLVM\\4.0.2\\bin"
PREFIX_PATH_WIN="C:\\Apps\\LLVM\\4.0.2\\tools\\bin"

TOOLS_PATH_LINUX = "/pkg/qct/software/llvm/release/arm/4.0.2/bin/"
PREFIX_PATH_LINUX = "/pkg/qct/software/llvm/release/arm/4.0.2/tools/bin/"

SIGN_IMAGE = False

TARGET = "QcomSdk"

##############################################################################
#
##############################################################################
import os
import sys
import shutil
import platform
import subprocess
from optparse import OptionParser

BUILD_FLAVORS = "DEBUG,RELEASE"
COMPILER_TOOLS_BIN = COMPILER_TOOLS + "_BIN"
COMPILER_TOOLS_PREFIX = COMPILER_TOOLS + "_ARM_PREFIX"

##############################################################################
#
##############################################################################
def sign_image():
# # Authentication
# ECHO Adding ELF header...
# SET IMAGE_HEADER_TOOL=%WORKSPACE%\Tools\image_header.py
# SET FV_IMG=%WORKSPACE%\%TARGETPKG%\Bin\QcomSdk.fv
# SET FV_ELF=%WORKSPACE%\%TARGETPKG%\Bin\unsigned\QcomSdk.elf
# 
# MKDIR %WORKSPACE%\QcomPkg\%TARGETPKG%\Bin\unsigned
# 
# COPY %WORKSPACE%\Build\%TARGETMSM%\%BUILD_FLAVOR%_%COMPILER_TOOLS%\FV\FVMAIN_COMPACT.Fv %FV_IMG%
# python %IMAGE_HEADER_TOOL% %FV_IMG% %FV_ELF% 0x0 elf 32
# 
# ECHO Generating default signed image...
# python %SECTOOLS_SCRIPTS_PATH%\sectools_builder.py -t %WORKSPACE%\%TARGETPKG%\Bin -i %FV_ELF% -g uefifv --config=%SECTOOLS_CFG_PATH%\secimagev2.xml --hash_table_algo=sha384 --soc_hw_version=0x60030000 --soc_vers=0x6003 > sectools.log
# COPY %WORKSPACE%\%TARGETPKG%\Bin\sign\default\uefifv\QcomSdk.elf %WORKSPACE%\%TARGETPKG%\Bin\QcomSdk.elf
# ECHO Done
# 
# EXIT /B 0
  pass

##############################################################################
#
##############################################################################
def make_build(options):
  build_cmd = ["build"]

  path = os.path.join(os.environ["WORKSPACE"], os.environ["TARGETPKG"])
  dsc_path = os.path.join(path, os.environ["TARGETPKG"] + ".dsc")
  log_path = os.path.join(path, "build.log")

  build_cmd.append("-p")
  build_cmd.append(dsc_path)

  build_cmd.append("-a")
  build_cmd.append(os.environ["ARCH"])

  build_cmd.append("-t")
  build_cmd.append(os.environ["COMPILER_TOOLS"])

  build_cmd.append("-b")
  build_cmd.append(options.release)

  if options.compiler_flags:
    build_cmd.append("-c")
    build_cmd.append(options.compiler_flags)

  build_cmd.append("-j")
  build_cmd.append(log_path)

  if options.build_flags:
    build_cmd += options.build_flags.strip('"').split(',')

  print os.linesep
  print "[b.py] Building with arguments:\n", build_cmd, '\n'

  new_env = os.environ.copy()
  subprocess.call(build_cmd, env=new_env)

  bin_dir = os.path.join(os.environ["WORKSPACE"], os.environ["TARGETPKG"], "Bin")
  if os.path.exists(bin_dir):
    shutil.rmtree(bin_dir)

##############################################################################
#
##############################################################################
def make_edk_tools():
  if platform.system() == "Windows":
    return

  print os.linesep
  print "[b.py] Building tools..."

  tools_path = os.path.join(os.environ["WORKSPACE"], "BaseTools")
  new_env = os.environ.copy()

  # Clean build tools if it already exists
  if os.path.isdir(os.path.join(os.environ["WORKSPACE"],"BaseTools","Source","C", "bin")):
    subprocess.call(["make", "-C", tools_path, "clean"], env=new_env)

  subprocess.call(["make", "-C", tools_path], env=new_env)
  print "[b.py] Done building tools"

##############################################################################
#
##############################################################################
def parse_and_set_edk_env(edk_output, EDK_ENV_FLAG):
  # Go through every line
  # Skip until 'ENDFLAG'
  # Then add everything in env to current env
  skipping = True
  for line in edk_output.splitlines():
    if not skipping:
      envvar = line[0:line.index('=')]
      envval = line[line.index('=')+1:]
      os.environ[envvar] = envval
    elif re.search(EDK_ENV_FLAG, line):
      skipping = False
  return

##############################################################################
#
##############################################################################
def setup_environment():
  print "[b.py] Building on " + platform.system()

  # Setup edktools and make:
  make_name = ""
  if platform.system() is "Windows":
    make_name = "nmake.exe"
    EDK_ENV_FLAG = 'EDK_ENV_STARTS_HERE'
    edk_output = subprocess.check_output('edksetup.bat --nt32 && echo ' + EDK_ENV_FLAG + ' && set', shell=True)
    parse_and_set_edk_env(edk_output, EDK_ENV_FLAG)
    os.environ["MAKE_PATH"] = "nmake.exe"
    os.environ["MAKE_FLAGS"] = "/C"
    os.environ["COMPILER_TOOLS"] = COMPILER_TOOLS + "WIN"
    os.environ["TOOLS_PATH"] = TOOLS_PATH_WIN
    os.environ[COMPILER_TOOLS_BIN] = TOOLS_PATH_WIN
    os.environ[COMPILER_TOOLS_PREFIX] = PREFIX_PATH_WIN

  else: #Linux
    make_name = "make"
    edk_command = ['bash', '-c', 'source edksetup.sh BaseTools && env']
    proc = subprocess.Popen(edk_command, stdout=subprocess.PIPE)
    for line in proc.stdout:
      (key, _, value) = line.partition("=")
      os.environ[key] = value.strip()
    proc.communicate()
    os.environ["MAKE_PATH"] = "make"
    os.environ["MAKE_FLAGS"] = ""
    os.environ["COMPILER_TOOLS"] = COMPILER_TOOLS + "LINUX"
    os.environ["TOOLS_PATH"] = TOOLS_PATH_LINUX
    os.environ[COMPILER_TOOLS_BIN] = TOOLS_PATH_LINUX
    os.environ[COMPILER_TOOLS_PREFIX] = PREFIX_PATH_LINUX

  # Setup environment variables:
  os.environ["ARCH"] = "AARCH64"
  os.environ["TARGETMSM"] = TARGET
  os.environ["TARGETPKG"] = TARGET + "Pkg"
  os.environ["USE_SECTOOLS"] = "1"
  os.environ["SECTOOLS_POLICY"] = "USES_SEC_POLICY_MULTIPLE_DEFAULT_SIGN"
  os.environ["USES_PLATFORM_IMAGE_INTEGRITY_CHECK"] = "1"
  os.environ[os.environ["SECTOOLS_POLICY"]] = "1"
  os.environ["SECTOOLS_CFG_PATH"] = os.path.join(os.environ["WORKSPACE"], "QcomSdkPkg","Tools","sectools", "config","integration")
  os.environ["SECTOOLS_SCRIPTS_PATH"] = os.path.join(os.environ["WORKSPACE"], "QcomSdkPkg","Tools","sectools")

  # Sanity - check if nmake.exe/make is in PATH
  make_found = False
  for path in os.environ["PATH"].split(os.pathsep):
    if os.path.exists(os.path.join(path, make_name)):
      make_found = True
      break
  if not make_found:
    raise NameError("[b.py] ERROR: " + make_name +\
                    " not found in PATH")

  # Sanity - check if WORKSPACE env variable is defined
  if "WORKSPACE" not in os.environ:
    raise NameError("[b.py] ERROR: Failed to setup environment variable WORKSPACE.")


  # Sanity - check if toolchain exists
  if not os.path.exists(os.environ["TOOLS_PATH"]):
    raise NameError("[b.py] ERROR: " + os.environ["TOOLS_PATH"] +\
                    " not found")


##############################################################################
#
##############################################################################
def validate_inputs(options):
  options.release  = options.release.upper()
  for flavor in options.release.split(','):
    if flavor not in BUILD_FLAVORS:
      raise NameError('[b.py] Error: Release mode "' + flavor + '" is invalid.' +\
                      ' Please see --help for more information')

##############################################################################
#
##############################################################################
def main():
  parser = OptionParser()

  parser.add_option('-b', '--build_flags',
                      action="store", default="",
                      help="Flags to be passed to the build invocation. " + \
                           "Specify multiple arguments separated by a comma or enclosed in double quotes. " + \
                           "  Example: -b -v,-n,1    Example: -b cleanall")

  parser.add_option('-c', '--compiler_flags', default="",
                      help="Extra flags to be passed to the build compiler directly. " + \
                           "Specify multiple arguments enclosed in double quotes. " + \
                           'Example: -c -DMYFLAG')

  parser.add_option('-r', "--release",
                    action="store", default="DEBUG",
                    help="Build flavor - DEBUG,RELEASE. Default flavor: DEBUG. " + \
                         'Example: -r DEBUG,RELEASE')

  (options, args) = parser.parse_args()

  try:
    validate_inputs(options)
    setup_environment()
    make_edk_tools()
    make_build(options)
    sign_image()

  except Exception as error:
    print error
    sys.exit(1)

main()

