//------------------------------------------------------------------------------ 
//
//  Copyright (c) 2019, Qualcomm Technologies Inc. All rights reserved.
//  Portions Copyright (c) 2011-2013, ARM Limited. All rights reserved.
//
//  This program and the accompanying materials
//  are licensed and made available under the terms and conditions of the BSD License
//  which accompanies this distribution.  The full text of the license may be found at
//  http://opensource.org/licenses/bsd-license.php
//
//  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
//  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
//
//------------------------------------------------------------------------------

//=============================================================================
//                              EDIT HISTORY
//
//  $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/Library/XBLSdiLib/ModuleEntryPoint.S#2 $
//  $DateTime: 2019/01/28 19:49:38 $
//  $Author: pwbldsvc $
//
// when       who     what, where, why
// --------   ---     ---------------------------------------------------------
// 01/28/19   ds   Initial revision
//
//============================================================================


//


.text
.align 3

GCC_ASM_IMPORT (XBLSdiMain)
GCC_ASM_EXPORT (_ModuleEntryPoint)
GCC_ASM_EXPORT (_QCModuleEntry)

  
_QCModuleEntry:
_ModuleEntryPoint:
  b XBLSdiMain
  
dead:  
  b dead                      /* We should never get here */

