/*=============================================================================
  
                     SCATTER LOADING DESCRIPTION FILE
  
  Copyright 2014 - 2017, 2019 by Qualcomm Technologies, Inc. All Rights Reserved.
  
  GENERAL DESCRIPTION
  
  The scatter loading description file is used to define the SBL1 memory map.
=============================================================================*/
/*=============================================================================
  
                            EDIT HISTORY FOR FILE
   This section contains comments describing changes made to the module.
   Notice that changes are listed in reverse chronological order.
  
  
  when       who     what, where, why
  --------   ---     -------------------------------------------------------
  03/19/19   yps     Remove uart log ram region
  01/14/19   yps     Clean ld file
  07/25/17   yps     Added support to retrieve external heap base and size
  03/03/17   kpa     Added support to retrieve internal heap base and size  
  03/01/17   kpa     Added check to ensure vector table size is within limits
  01/26/17   yps     fixed CLANG38 upgrade issue
  06/02/16   rp      Remove SCL_DDR_TRAINING_DATA_BUF_SIZE from assert for SBL1_DATA_ZI
  03/26/16   kpa     move smc api code to sdi region for access in debug flow
  03/25/16   kpa     revert updates to reuse bootrom stack address space  
  03/22/16   kpa     relocate boot ZI from ocimem to L2 TCM, Relocate stack to 
                     reclaim bootrom buffer, remove SBL1_STACK,
                     Added DDR driver segment
  12/17/15   jt      Change sdcc_mmc_util from .bss to COMMON
  10/27/15   elt     Added regions for boot logger time markers
  10/07/15   plc     Add RUMI UFS symbols to correct region
  08/07/15   plc     Update for MSM8998
  08/03/15   rp	     Moved page table and shared function table to OCIMEM
  07/24/15   ck      Moved HALbimc.o to TCM region
  07/21/15   kpa     Resize XBL L2 TCM ZI buffer.
  07/15/15   bn      Moved buffers used by SDCC's clients to OCIMEM
  02/26/15   ck      Added missing busywait and rodata allocations
  02/20/15   kpa     Code cleanup. 
  02/12/15   kpa     Update Debug/SDI region.  
  02/12/15   kpa     Add assert to check RPM coderam buffer size.  
  02/12/15   kpa     Add XBL code region to rpm code ram buffer.  
  01/31/15   kpa     Updates to zero initialize OCIMEM ZI buffer.  
  01/21/15   kpa     Move pre-ddr init page tables to code ram, add ocimem buffer
  11/20/14   ck      Removed references to USB as it has moved to XBLRamDump
  10/22/14   ck      Added .bss to page table regions to ensure they are ZI
  10/01/14   kpa     Include Target_cust.h instead of boot_target_scl.h
  08/18/14   ck      Cleaned up SBL regions and added region protections
  08/08/14   ck      Renamed and resized SBL1_DLOAD_ZI as contents have moved to XBLRamDump.
  06/26/14   kedara  Update sections.
  05/15/14   kedara  Inital revision.
=============================================================================*/

#include "Target_cust.h"

PHDRS {
  CODE_IMEM PT_LOAD;
  STACK_IMEM PT_LOAD;
  RODATA_IMEM PT_LOAD;
  RWDATA_IMEM PT_LOAD;
  ZIDATA_IMEM PT_LOAD;
  ZIDATA_DDR PT_LOAD;
  BOOT_OCIMEM_DEVICEPROG_DATA PT_LOAD;
}

SECTIONS
{
  
  
  /*====================== Sections in BOOT IMEM ===============================*/
  /*  This section contains SBL1's code and ro data */
  SBL1_ROM SCL_SBL1_CODE_BASE: ALIGN(4096)
  {
    Image$$SBL1_CODE$$Base = . ;
    Image$$SBL1_VECTOR_TABLE$$Start = . ;  
    *(SBL1_VECTOR_TABLE)
    Image$$SBL1_VECTOR_TABLE$$End = . ; 
    *(.text* )
    Image$$SBL1_CODE$$End = . ;
    Image$$SBL1_CODE$$Length = Image$$SBL1_CODE$$End - Image$$SBL1_CODE$$Base ;
    ASSERT((Image$$SBL1_VECTOR_TABLE$$End - Image$$SBL1_VECTOR_TABLE$$Start) <= SCL_SBL1_VECTOR_TABLE_SIZE, "XBL Loader: SBL1_VECTOR_TABLE Region Overflow");
  } : CODE_IMEM

  SBL1_DATA_RO : ALIGN(4096)
  {
	Image$$SBL1_DATA_RO$$Base = . ;
    *(.rodata* )
    Image$$SBL1_DATA_RO$$End = . ;
    Image$$SBL1_DATA_RO$$Length = Image$$SBL1_DATA_RO$$End - Image$$SBL1_DATA_RO$$Base ;
  } : RODATA_IMEM
  
  SBL1_STACK : ALIGN(4096)
  {
    Image$$SBL1_STACK$$Base = . ;
    . = . + SCL_SBL1_STACK_SIZE;
    Image$$SBL1_STACK$$End =. ;
    Image$$SBL1_STACK_BASE$$Pointer = . ;
    Image$$SBL1_STACK$$Length = Image$$SBL1_STACK$$End - Image$$SBL1_STACK$$Base;
  } : STACK_IMEM


  SBL1_DATA_RW  : ALIGN(4096)
  {
    Image$$SBL1_DATA_RW$$Base = . ;
    Image$$SYSTEM_DEBUG_QSEE_INFO$$Base = . ;
    *(.data* )
    Image$$SBL1_DATA_RW$$End = . ;
    Image$$SBL1_DATA_RW$$Length = Image$$SBL1_DATA_RW$$End - Image$$SBL1_DATA_RW$$Base;
  }:RWDATA_IMEM


  /*====================== Sections in DDR =========================*/

  /* This section contains all ZI that can be allocated in DDR. */  
  SBL1_DDR_ZI SCL_SBL1_DDR_ZI_BASE :
  {
    Image$$SBL1_DDR_ZI$$Base = . ;   
    * (.bss.BOOT_DDR_ZI_DATA_ZONE)
    * (.bss.BOOT_DDR_ZI_ZONE)
    Image$$BOOT_DDR_PAGE_TABLE_ZONE$$Base = . ;
    * (.bss.BOOT_DDR_PAGE_TABLE_ZONE)
    Image$$BOOT_DDR_PAGE_TABLE_ZONE$$End = . ;
    Image$$BOOT_DDR_PAGE_TABLE_ZONE$$Length = Image$$BOOT_DDR_PAGE_TABLE_ZONE$$End - Image$$BOOT_DDR_PAGE_TABLE_ZONE$$Base ;
    Image$$SBL1_DDR_ZI$$End = . ;
    Image$$SBL1_DDR_ZI$$Length = Image$$SBL1_DDR_ZI$$End - Image$$SBL1_DDR_ZI$$Base;
    ASSERT(SIZEOF(SBL1_DDR_ZI) <= SCL_SBL1_DDR_ZI_SIZE, "XBL Loader: SBL1_DDR_ZI Region Overflow");
  } : ZIDATA_DDR
  
  /* This section is for DeviceProgrammer DDR buffers, they are 2MB in size.
   * Align the buffers to 2MB boundary to use L2 MMU tables to mark them
   * as Cached. They can be marked as L3 (4K) but boot has more L2 tables
   * available making it more robust. */
  SBL1_DEVICEPROG_USB_ZI : ALIGN(2M)
  {
    Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$Base = .;
    *devprgb_buffers_dd*.o* (.bss .bss.*)
    *devprgb_buffers_dd*.o* (COMMON)
  }
  Image$$SBL1_DEVICEPROGRAMMER_USB_ZI$$ZI$$Length = SIZEOF(SBL1_DEVICEPROG_USB_ZI);



 

  /*====================== BSS Section in BOOT IMEM =========================*/
  
  /* This section contains non DDR ZI. */
  /* Must be placed at EOF as it contains the *(.bss.*) catch all */

  SBL1_DATA_ZI Image$$SBL1_DATA_RW$$End: ALIGN(4096)
  {
    Image$$SBL1_DATA_ZI$$Base = . ;

    Image$$SBL1_DEVPROG_UNCACHED_ZI$$Base = . ;
    *(.bss.BOOT_UNCACHED_ZI_ZONE)
    Image$$SBL1_DEVPROG_UNCACHED_ZI$$End = . ;
    Image$$SBL1_DEVPROG_UNCACHED_ZI$$ZI$$Length= Image$$SBL1_DEVPROG_UNCACHED_ZI$$End - Image$$SBL1_DEVPROG_UNCACHED_ZI$$Base;    
    *(.bss*)
    *(COMMON)
    Image$$SBL1_DATA_ZI$$End = . ;  
    Image$$SBL1_DATA_ZI$$Length = Image$$SBL1_DATA_ZI$$End - Image$$SBL1_DATA_ZI$$Base;
    
  } : ZIDATA_IMEM 
  
  /* Ensure SBL1 regions fit inside of allocated region */
    ASSERT((SIZEOF(SBL1_ROM) + SIZEOF(SBL1_DATA_RO) + SIZEOF(SBL1_STACK) + SIZEOF(SBL1_DATA_RW) + SIZEOF(SBL1_DATA_ZI) )
             <= SCL_SBL1_IMAGE_SIZE, "XBLLoader: SBL1 Image Size Overflow");
  /*======================================================================*/


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
