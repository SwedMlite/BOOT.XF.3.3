## @file
# GNU/Linux makefile for 'DevicePath' module build.
#
# Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
ARCH ?= IA32
MAKEROOT ?= ..

APPNAME = DevicePath

OBJECTS = DevicePath.o UefiDevicePathLib.o DevicePathFromText.o  DevicePathUtilities.o

include $(MAKEROOT)/Makefiles/app.makefile

LIBS = -lCommon
#ifeq ($(CYGWIN), CYGWIN)
#  LIBS += -L/lib/e2fsprogs -luuid
#endif

#ifeq ($(LINUX), Linux)
#  LIBS += -luuid
#endif

