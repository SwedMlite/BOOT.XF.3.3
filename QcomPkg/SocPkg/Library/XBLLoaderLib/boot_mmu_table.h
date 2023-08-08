#ifndef BOOT_MMU_TABLE_H
#define BOOT_MMU_TABLE_H

/*=============================================================================

                     SBL MMU Table

GENERAL DESCRIPTION
    This module contains the memory map 

Copyright 2013-2019  by Qualcomm Technologies, Inc. All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE
  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ------------------------------------------------------------
03/28/19   yps     made padd/vadd/size alignment with respective page table size
01/22/19   yps     Moved sbl_initial_memory_map into the function
03/22/18   yps     Update ddr memory block to cacheable
04/04/17   kpa     Mark SCL_SBL1_OCIMEM_DATA_BASE as non cacheable
07/20/16   kpa     Initial revision for SDM845

===========================================================================*/

/*===========================================================================

                     INCLUDE FILES FOR MODULE

===========================================================================*/
#include <boot_cache_mmu.h>
#include <boot_page_table_armv8.h>

/*=============================================================================
Memory Map Structure
  PBL only maps a limited number of memories: 
  OCIMEM, BOOT IMEM, AOP memories, APPS PBL ROM regions.
  
  With Aarch64 Page Tables, we will need to take care of all required regions.
  
  SBL (XBLLoader) is responsible to map the memory it will use such as DDR 
  and ram dump regions.  

  Memory regions greater than or equal to 1GB are placed in the Level 1 pagetables. 
  Memory regions greater than or equal to 2MB are placed in the Level 2 pagetables.
  The rest regions less than 2MB (4KB)are placed in Level 3 pagetables. 
  All regions are marked with the default domain.
=============================================================================*/



/*=============================================================================
    SBL initial Memory Map  
    This memory map is populated before DDR is intialized.
    Regions that have XPU protection turned on should be marked as 
    DEVICE memory(strongly ordered) to eliminate the processor doing 
    speculative data access and NON-EXECUTABLE to eliminate 
    speculative instruction execution.
=============================================================================*/

/* Note:  TBD
     On HoneyBadger family there are no free L2, L3 page table entries in the 
     memory map region shared by PBL.
     PBL already populates 5 L3 pagetables (4KB each) in the available 20KB 
     L3 page table space. Similarly L2 page table address space has 512 entries
     mapping whole 1 GB address space.
     bootrom only maps 1GB in L1 page table. For DDR we need to populate remaining
     L1 entries.

     Data Execution Prevention(DEP) for SBL RW region:
     All SBL region except code should be marked as non executable

     Data Execution Prevention(DEP) for SBL CODE region:
     All SBL code region should be marked as read only and exec 
     DEP already taken care of via sbl_initial_memory_map[]
*/




/*=============================================================================
    SBL1 Addtional Memory Map  
    
    Addtional memory regions that need to be mapped in SBL1. 
    This memory map is populated after DDR is intialized.
    Regions that have XPU protection turned on should be marked as 
    DEVICE memory(strongly ordered) to eliminate the processor doing 
    speculative data access and NON-EXECUTABLE to eliminate 
    speculative instruction execution.
=============================================================================*/
const struct mem_block sbl1_addtional_memory_map[] =
{ 

  /* SMEM Region, 2MB , Shared memory */ 
  MEM_BLOCK( SCL_SHARED_RAM_BASE,
             SCL_SHARED_RAM_BASE, 
             SCL_SHARED_RAM_SIZE,
             MMU_L2_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_MEM_SHARED,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),

  /*QSEE pImem Region,L2 cacheable, Non-Executable,
    marked as Executable before jumping to it. */  
  MEM_BLOCK( SCL_DDR_pIMEM_BASE,
             SCL_DDR_pIMEM_BASE, 
             SCL_DDR_pIMEM_SIZE,
             MMU_L2_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_DEVICE_NONSHARED,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),        
  /*QHEE, cacheable, Non-Executable */  
  MEM_BLOCK( SCL_QHEE_CODE_BASE,
             SCL_QHEE_CODE_BASE, 
             SCL_QHEE_TOTAL_SIZE,
             MMU_L3_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_MEM_WRITE_BACK_CACHE,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),

  /*RPM Code RAM, Cacheable, Non-Executable */  
  MEM_BLOCK( SCL_AOP_CODE_RAM_BASE,
             SCL_AOP_CODE_RAM_BASE, 
             SCL_AOP_CODE_RAM_SIZE,
             MMU_L3_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_MEM_WRITE_BACK_CACHE,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),

  /*APPSBL, cacheable, NON-Executable */  
  MEM_BLOCK( SCL_APPSBL_CODE_BASE,
             SCL_APPSBL_CODE_BASE, 
             SCL_APPSBL_TOTAL_SIZE,
             MMU_L3_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_MEM_WRITE_BACK_CACHE,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),

  /* XBLRamDump region cacheable, non-exec */  
  MEM_BLOCK( SCL_RAMDUMP_CODE_BASE,
             SCL_RAMDUMP_CODE_BASE, 
             SCL_RAMDUMP_TOTAL_SIZE,
             MMU_L3_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_WRITE, 
             MMU_PAGETABLE_MEM_WRITE_BACK_CACHE,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),
    
  /* Security control region as read-only */
  MEM_BLOCK( SECURITY_CONTROL_BASE,
             SECURITY_CONTROL_BASE, 
             QFPROM_READONLY_BLOCK_SIZE,
             MMU_L3_SECTION_MAPPING,
             MMU_PAGETABLE_MEM_READ_ONLY, 
             MMU_PAGETABLE_DEVICE_NONSHARED,
             MMU_PAGETABLE_NON_EXECUTABLE_REGION),

  /* Add addtional memory region here */
  
  /* Last Region Marker */
  { MMU_LAST_ADDRESS, MMU_LAST_ADDRESS }
};

/* MMU Pagetable Region  
   Page table region must be mapped as non-cachable to be consistent with 
   the setting in TTBR0(we set page table walk as non-cachable)
*/
struct mem_block sbl1_mmu_page_table_mem_block = 
{ 
  /* Pagetable 64KB + 32b */
  0, 0, 0,
  MMU_L3_NS_SECTION_MAPPING, MMU_PAGETABLE_MEM_READ_WRITE, 
  MMU_PAGETABLE_MEM_NON_CACHEABLE, MMU_PAGETABLE_NON_EXECUTABLE_REGION  
};

/* Memory block to describe DDR memory */
struct mem_block sbl1_ddr_mem_block = 
{
  0, 0, 0,
  MMU_L1_SECTION_MAPPING, MMU_PAGETABLE_MEM_READ_WRITE, 
  MMU_PAGETABLE_MEM_WRITE_BACK_CACHE, MMU_PAGETABLE_NON_EXECUTABLE_REGION
};

#endif  /* BOOT_MMU_TABLE_H */
