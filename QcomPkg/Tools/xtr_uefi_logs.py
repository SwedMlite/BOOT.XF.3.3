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

buff_addr=0
buff_len=0

if len(sys.argv) < 2:
   print "Dump Filename required for the DDR Bank that contains the UEFI Info Block, typically first one"
   exit ()

log_file = sys.argv[1]

fp = open(log_file, "rb")

#lf = open(os.path.dirname(os.path.abspath(log_file)) + "/uart.log.txt", "wb")

fp.seek (0x1ffff038)
fcontent = fp.read(16)

(buff_addr,buff_len) = struct.unpack("@qq", fcontent)

# For now assumes that the DDR first bank base address is 0x80000000, change this if this assumption breaks
buff_addr = buff_addr - 0x80000000

print ("Addr : 0x%X  Len : 0x%X" % (buff_addr, buff_len))

fp.seek (0)
fp.seek (buff_addr)

data = fp.read (buff_len)

print data

#lf.write(data)

#lf.close ()

fp.close ()

