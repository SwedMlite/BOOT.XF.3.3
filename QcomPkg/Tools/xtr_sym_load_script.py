#
# Copyright (c) 2019 Qualcomm Technologies, Inc.  
# All Rights Reserved.
# Qualcomm Technologies Proprietary and Confidential. 
#

import os
import sys
import stat
import commands
import string
import pdb
import struct

script_addr=0
script_len=0
offset=0

if len(sys.argv) < 2:
   print "Dump Filename required for the DDR Bank that contains the UEFI Info Block, typically first one"
   exit ()

log_file = sys.argv[1]

fp = open(log_file, "rb")

#lf = open(os.path.dirname(os.path.abspath(log_file)) + "/uart.log.txt", "wb")

fp.seek (0x1ffff0A0)
fcontent = fp.read(16)

(offset,script_len,script_addr) = struct.unpack("@LLQ", fcontent)

# For now assumes that the DDR first bank base address is 0x80000000, change this if this assumption breaks
script_addr = script_addr - 0x80000000

print ("Addr : 0x%X  Len : 0x%X" % (script_addr, script_len))

fp.seek (0)
fp.seek (script_addr)

data = fp.read (script_len)

print data

#lf.write(data)

#lf.close ()

fp.close ()

