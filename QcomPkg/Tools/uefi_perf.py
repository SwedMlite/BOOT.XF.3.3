#============================================================================
#
#/** @file uefi_perf.py
#
# GENERAL DESCRIPTION
#   Generate readable perf breakdown of drivers spending time during boot
#
#  Copyright (c) 2018-2019 Qualcomm Technologies, Inc.  All Rights Reserved.
#  Qualcomm Technologies Proprietary and Confidential.
#
#**/
#
#----------------------------------------------------------------------------
#
#                      EDIT HISTORY FOR FILE
#
#  This section contains comments describing changes made to the module.
#  Notice that changes are listed in reverse chronological order.
#
# when       who       what, where, why
# --------   ---       ------------------------------------------------------
# 03/28/19    yg       Multiple instance logs support
# 10/29/18    yg       Initial revision
#
#============================================================================
import os
import sys
import stat
import commands
import re
import string
import pdb
import re

from glob import glob

PROCESS_SKIP_TILL_UEFI_START = 1
PROCESS_DRIVER_LOADS  = 2

PRINT_CONSOLE_OUT_FORMAT_STRING = "%5d   %4d   %s" 
CSV_OUT_FORMAT_STRING  = "%5d,%4d,%s\n"

addr = 0

drvr_ts = 0
prev_drvr_ts = 0
drvr_name = ""
prev_drvr_name = ""
uefi_start_ts = 0

# Matches the driver loading logs in UART log output
# TODO : Handle the bad logs that doesn't print a newline and the driver loading
#        log is mixed with the bad logs
drvr_load_log_re = re.compile(r'^-\s0x([0-9a-fA-F]+)\s\[\s*(\d+)\]\s(\S*)[.]efi$')

uefi_start_re = re.compile(r'^UEFI Start\s*\[\s*(\d+)\]\s*(.*)')

generic_ts_re = re.compile(r'^.*\[\s*(\d+)\]\s*(.*)')

if len(sys.argv) < 2:
   print "Usage: uefi_perf.py <log file path>"
   print "       Log file should have UEFI Start, driver loading addresses and "
   print "       the abs timestamps\n"
   exit ()

log_file = sys.argv[1]

fp = open(log_file)
wp = open(log_file + ".csv", "wb")

process_state = PROCESS_SKIP_TILL_UEFI_START

################################################################################
#
#     Print function
#
################################################################################
def print_out_perf_val (driver_ts, duration, name):
  print (PRINT_CONSOLE_OUT_FORMAT_STRING % (driver_ts, duration, name))
  out_str = CSV_OUT_FORMAT_STRING % (driver_ts, duration, name)
  wp.write (out_str)

################################################################################
#
#     Main processing
#
################################################################################
while 1:
  line = fp.readline()
  if not line:
    break

  line = line.strip()

#  pdb.set_trace()

  if len(line) == 0:
    continue
  
#  Skip everything till we get to interesting point of logs
  if string.find(line.upper(), "UEFI Start".upper()) != -1:
    uefi_start_match = uefi_start_re.search(line)
    uefi_start_ts = int(uefi_start_match.group(1))
    drvr_ts = uefi_start_ts
    drvr_name = "Uefi SEC"
    process_state = PROCESS_DRIVER_LOADS
    wp.write ("\n")
    print "\n"
    continue

#
# Process the interesting part of the map
#
  if process_state == PROCESS_DRIVER_LOADS:
    drvr_log_match = drvr_load_log_re.search(line)

    if drvr_log_match:
      addr = int(drvr_log_match.group(1), 16)

      prev_drvr_ts = drvr_ts
      prev_drvr_name = drvr_name

      drvr_ts = int(drvr_log_match.group(2))
      drvr_name = drvr_log_match.group(3)
      
      if prev_drvr_ts != 0:
        print_out_perf_val (prev_drvr_ts, drvr_ts - prev_drvr_ts, prev_drvr_name)

    else:
      generic_ts_log_match = generic_ts_re.search(line)

      if generic_ts_log_match:
        prev_drvr_ts = drvr_ts
        prev_drvr_name = drvr_name

        drvr_ts = int(generic_ts_log_match.group(1))
        drvr_name = generic_ts_log_match.group(2)

        if prev_drvr_ts != 0:
          print_out_perf_val (prev_drvr_ts, drvr_ts - prev_drvr_ts, prev_drvr_name)

        if string.find(line.upper(), "UEFI End".upper()) != -1:
          print_out_perf_val (drvr_ts, drvr_ts - uefi_start_ts, drvr_name)
          process_state = PROCESS_SKIP_TILL_UEFI_START
          drvr_ts = 0



if drvr_ts != 0:
  print (PRINT_CONSOLE_OUT_FORMAT_STRING % (drvr_ts, drvr_ts - prev_drvr_ts, drvr_name))

wp.close ()
fp.close ()


