import subprocess
import re
from optparse import OptionParser
import os.path
import sys

def processArgs ():
    parser = OptionParser("usage: %prog [options]")
    parser.add_option("-i", "--input", dest="input", action="store", help="Input data ELF, INPUT, REQUIRED")
    parser.add_option("-o", "--output", dest="output", action="store", help="Output filename with location, OUTPUT, REQUIRED")
    parser.add_option("-d", "--objdump", dest="objdump", action="store", help="path and name of objdump program to use, INPUT, OPTIONAL (default=\"objdump\")")
    parser.add_option("-s", "--start-section", dest="startSection", action="store", help="Start of data section to keep, INPUT, REQUIRED")
    parser.add_option("-e", "--end-section", dest="endSection", action="store", help="Last section to keep, INPUT, REQUIRED")
    parser.add_option("-v", "--verbose", action="store_true", dest="verbose", default=False, help="verbose?, INPUT, OPTIONAL")
    (options, args) = parser.parse_args()
    if options.input is None or options.output is None or options.startSection is None or options.endSection is None:
        parser.print_help()
        exit()
    else:
        if not os.path.isfile(options.input):
            sys.exit("{} does not exist".format(options.input))
    if options.objdump is None:
        options.objdump = "objdump"
    return (options, args)

if __name__ == "__main__":
    (options, args) = processArgs()

    #run objdump, parse output
    try:
        p = subprocess.Popen([options.objdump, options.input, "-h"], stdout=subprocess.PIPE)
    except:
        sys.exit(msg="ObjDump failed")    
    out, err = p.communicate()
    if options.verbose:
        print out
    m = re.search(options.startSection+"\s+\w+\s+(\w+)\s+", out)
    if m is None or m.group(0) is None:
        sys.exit("Failed to find section: {}".format(options.startSection))
    startAddr = int(m.group(1), 16)

    m = re.search("\.devcfg_struct_pointers\s+\w+\s+(\w+)\s+", out)
    if m is None or m.group(0) is None:
        sys.exit("Failed to find section: {}".format(options.startSection))
    structPtrsAddr = int(m.group(1), 16)
    m = re.search("\.devcfg_prop_bin\s+\w+\s+(\w+)\s+", out)
    if m is None or m.group(0) is None:
        sys.exit("Failed to find section: {}".format(options.startSection))
    propBinAddr = int(m.group(1), 16)
    m = re.search("\.devcfg_driverlist\s+\w+\s+(\w+)\s+", out)
    if m is None or m.group(0) is None:
        sys.exit("Failed to find section: {}".format(options.startSection))
    deviceListAddr = int(m.group(1), 16)

    m = re.search(options.endSection+"\s+(\w+)\s+(\w+)\s+", out)
    if m is None or m.group(0) is None:
        sys.exit("Failed to find section: {}".format(options.endSection))
    endAddr = int(m.group(1), 16) + int(m.group(2), 16)

    startFileOffset = 0x1ff0 #default value if default offset is used in case it cannot be found, 0x2000-0x10
    p = subprocess.Popen([options.objdump, options.input, "-p"], stdout=subprocess.PIPE)
    out, err = p.communicate()
    if options.verbose:
        print out
    m = re.search("\s+LOAD\s+off\s+(\w+)\s+vaddr\s+0x\w*"+format(startAddr,"x"), out)
    if m is None or m.group(0) is None:
        print("Failed to find file offset for vaddr/paddr: 0x{}; default 0x1FF0 is used".format(format(startAddr,"x")))
    else:
        startFileOffset = int(m.group(1), 16)

    #read elf from startAddr to endAddr
    if options.verbose:
        print "{0} starts at 0x{1:x}".format(options.startSection, startAddr)
        print "{0} ends at 0x{1:x}".format(options.endSection, endAddr)
        print "Reading/Copying ELF from 0x{0:x} to 0x{1:x}".format(startFileOffset, startFileOffset+endAddr-startAddr)
    inputFH = open(options.input, "rb")
    inputFH.seek(startFileOffset)
    blob = inputFH.read(endAddr-startAddr)
    inputFH.close

    blobBytes = bytearray(blob)

    #replace the 2nd, 3rd, and 4th words of the bin
    blobBytes[4] = (0x000000FF & structPtrsAddr) >> 0
    blobBytes[5] = (0x0000FF00 & structPtrsAddr) >> 8
    blobBytes[6] = (0x00FF0000 & structPtrsAddr) >> 16
    blobBytes[7] = (0xFF000000 & structPtrsAddr) >> 24

    blobBytes[8] = (0x000000FF & propBinAddr) >> 0
    blobBytes[9] = (0x0000FF00 & propBinAddr) >> 8
    blobBytes[10] = (0x00FF0000 & propBinAddr) >> 16
    blobBytes[11] = (0xFF000000 & propBinAddr) >> 24

    blobBytes[12] = (0x000000FF & deviceListAddr) >> 0
    blobBytes[13] = (0x0000FF00 & deviceListAddr) >> 8
    blobBytes[14] = (0x00FF0000 & deviceListAddr) >> 16
    blobBytes[15] = (0xFF000000 & deviceListAddr) >> 24

    #write to bin file
    outputFH = open(options.output, "wb")
    outputFH.write(blobBytes)
    outputFH.close
