#==============================================================================
# @file Core.dsc
# SM8250 Core package.
#
# Copyright (c) 2015 - 2018 Qualcomm Technologies, Inc. All rights reserved.
# Portions Copyright (c) 2009 - 2010, Apple Inc. All rights reserved.
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#==============================================================================

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = SM8250Pkg
  PLATFORM_GUID                  = DEC768DC-64F2-4731-93C7-0FBD752817BD 
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  SUPPORTED_ARCHITECTURES        = ARM|AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = QcomPkg/SocPkg/8250/LAA/Core.fdf

[Defines.ARM]
  OUTPUT_DIRECTORY               = Build/SM8250LAA/Core_32

[Defines.AARCH64]
  OUTPUT_DIRECTORY               = Build/SM8250LAA/Core

!include QcomPkg/SocPkg/8250/Common/Core.dsc.inc