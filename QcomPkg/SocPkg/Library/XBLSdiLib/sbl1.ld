/*=============================================================================
  
                     SCATTER LOADING DESCRIPTION FILE
  
  Copyright 2018-2019 by Qualcomm Technologies, Inc. All Rights Reserved.
  
  GENERAL DESCRIPTION
  
  The scatter loading description file is used to define the SBL1 memory map.
=============================================================================*/
/*=============================================================================
  
                            EDIT HISTORY FOR FILE
   This section contains comments describing changes made to the module.
   Notice that changes are listed in reverse chronological order.
  
  
  when       who     what, where, why
  --------   ---     -------------------------------------------------------
  11/28/18   ds      Inital version.
=============================================================================*/

#include "Target_cust.h"

PHDRS {
  BOOT_SYSTEM_DEBUG PT_LOAD;
  BOOT_SYSTEM_DEBUG_DATA PT_LOAD;
}

SECTIONS
{

  /* This section contains the system debug image code that came from SDI.
     It is placed in RPM Code RAM memory above RPM FW. */
  SYSTEM_DEBUG_CO_RO SCL_SYSTEM_DEBUG_CO_RO_BASE:
  {
    *ModuleEntryPoint*.o*(.text*);
    KEEP(*(.text* ));
    KEEP(*(.rodata* ));
    KEEP(*(.constdata* ));
    
    ASSERT(SIZEOF(SYSTEM_DEBUG_CO_RO) <= SCL_SYSTEM_DEBUG_CO_RO_SIZE, "XBL Loader: SYSTEM_DEBUG_CO_RO Region Overflow");
  } : BOOT_SYSTEM_DEBUG
  
  /* section contains system debug related data and placed above system debug 
     related CO+RO in OCIMEM.
   */
  SYSTEM_DEBUG_DATA SCL_SYSTEM_DEBUG_DATA_BASE : ALIGN(8)
  {
    KEEP(*(.data*));
    KEEP(*(.bss*));
    
    //ASSERT(SIZEOF(SYSTEM_DEBUG_DATA) <= SCL_SYSTEM_DEBUG_DATA_SIZE, "XBL Loader: SYSTEM_DEBUG_DATA Region Overflow");	
  } : BOOT_SYSTEM_DEBUG_DATA

  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) }
  .debug_ranges   0 : { *(.debug_ranges) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
  /DISCARD/ : { *(.ARM.exidx*) *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) *(.init) *(.fini) }
}
