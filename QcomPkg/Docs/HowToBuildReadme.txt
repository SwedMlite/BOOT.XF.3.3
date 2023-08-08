/** @file HowToBuildReadme.txt
   
  XBL build documentation

  Copyright (c) 2017 - 2018, Qualcomm Technologies Inc. All rights reserved. 
  
**/

/*=============================================================================
                              EDIT HISTORY


 when       who     what, where, why
 --------   ---     -----------------------------------------------------------
 03/09/18   yg      Update
 05/10/17   yps     Initial version
=============================================================================*/


UEFI Build
----------

Note:
Replace all instance of <TargetPkg> with valid target folder in QcomPkg:
e.g: QcomPkg\<TargetPkg> is QcomPkg\SocPkg\8250

 ----------------------------
|  Required Tool and Setup   |
 ----------------------------

 Toolchain versions : (common for both windows/linux)
 - Python : 2.7.3  (required in search path, use "python -V" to verify)
 - Snapdragon LLVM 4.0.2
     - Snapdragon LLVM toolchain for both Windows/Linux are available at Qualcomm Chipcode
     - Toolchain path can be updated in the file "QcomPkg/toolchainconfig.json"
   
  For Windows 7
  -------------
  1) Visual Studio 2012 or Express Edition
     Only nmake.exe is used form visual studio. nmake.exe needs to be in %PATH%
     From "QcomPkg\<TargetPkg>\" type nmake.exe to make sure build system has acess to nmake.exe

  For Linux
  ---------
  1) uuid-dev
  2) gcc
  3) g++
  4) sqlite3


 -----------------------------
|  Build Command and options  |
 -----------------------------

  Windows/Linux
  --------------
  QcomPkg\buildex.py
  This is the common build script for all packages

  Build Options
  --------------
  Usage: python buildex.py [optional arguments]... 

  Examples:
    python ../buildex.py 
    python QcomPkg/buildex.py
  
  Arguments:
  -t --target
      Provide target(s) to build, separated by a comma
      ex: python buildex.py -t SDM845Pkg

  --variant
      Provide variant(s) to build, separated by a comma
      ex: python buildex.py --variant XX,YY
      where XX, YY are variant folders in a target package folder
  
  -r --release
      Provide a release mode, one of "DEBUG" or "RELEASE". Default is to build both.

  -v --version
      Specify build version. Default is 0.

  -a --alias
      Specify the config section as listed in the file QcomPkg/aliasconfig.json to provide 
      the build params instead of manually specifying on command line

  -C --component
      Will only compile the components which proivide with this option, separeted by a comma .


  --build_flags
      Comma separated list of extra arguments to be supplied to the underlying build system (here EDK build system).
      ex: python buildex.py --build_flags cleanall,special

      Extra Build Arg options:
        These are comma separated values, within double quotes if space is needed, any valid combination of the
        values can be used
      -v       : verbose
      -m file  : Module inf file to build (relative path from root of workspace)
      -n x     : Number of threads to spawn for the build (x = 1 when need to locate error)
      cleanall : Clean all the generated files
  
  --compiler_flags
      This string is passed in its entirety to the compiler. Quotes may be used for strings
      that require a space.
      ex: python buildex.py --compiler_flags -DPRE_SIL
      ex: python buildex.py --compiler_flags "-DSOME_FLAG -DANOTHER_FLAG"
          
  -i --images
      Provide image which you want to generate,separeted by a comma
          ex: python buildex.py -i xbl,uefi,pmic


 -----------------------------
|  Some usage Examples:       |
 -----------------------------
  python buildex.py
    Default command, buildex builds all targets,variants for DEBUG and RELEASE
  
  python buildex.py -t 8250pkg --variant LAA -i uefi
    Building a specific target, variant, and single image uefi. This will build both DEBUG and RELEASE
  
  python buildex.py -t 8250pkg --variant LAB -r DEBUG
    Building a specific target, variant LAB for DEBUG
  
  python buildex.py -t 8250pkg --variant LAA -r DEBUG -C xbl_loader
    Building a specific target 8250pkg, variant LAA and sepceial component XBL_LOADER 
    for DEBUG

  python buildex.py -t 8250pkg --variant LAA -r debug --build_flags cleanall
    Clean 8250, LAA Debug image
  
  python buildex.py -a 8250laadbg
    Building a specific target 8250pkg, variant LAA for DEBUG by alias 
    option. Detail option alias please refer aliasconfig.json
