# @file Apriori.fdf.inc
# Apriori for LA SM8250
#
# Copyright (c) 2015 -2018 Qualcomm Technologies, Inc. All rights reserved.
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

!include QcomPkg/SocPkg/8250/Common/Apriori.fdf.inc

#
########################### APRIORI End ####################################################
#

