/*==============================================================================
QUALCOMM Proprietary Design Data                                                
Copyright (c) 2016-2018 Qualcomm Technologies Incorporated.                     
All rights reserved.                                                            
==============================================================================*/
 
#ifndef _SHRM_LOAD_RAM_H_
#define _SHRM_LOAD_RAM_H_
 
#define RODATA_SECTION_OFFSET_FULL   0x2300
#define RODATA_SECTION_LENGTH_FULL   0x108
 
#define DATA_SECTION_OFFSET_FULL   0x2410
#define DATA_SECTION_LENGTH_FULL   0x3E8
 
#define BSS_SECTION_OFFSET_FULL   0x2800
#define BSS_SECTION_LENGTH_FULL   0x380
 
#define RESETVECTOR_TEXT_SECTION_OFFSET_FULL   0x0
#define RESETVECTOR_TEXT_SECTION_LENGTH_FULL   0xC0
 
#define DYANMICVECTORS_S_SECTION_OFFSET_FULL   0x2E0
#define DYANMICVECTORS_S_SECTION_LENGTH_FULL   0x120
 
#define MAIN_SEGMENT_SECTION_OFFSET_FULL   0x400
#define MAIN_SEGMENT_SECTION_LENGTH_FULL   0x5248
 
#define SHRM_DRAM0_TOTAL_SIZE_FULL   2160
#define SHRM_IRAM0_TOTAL_SIZE_FULL   21544
#define SHRM_TOTAL_SIZE_FULL         23704
 
/*==============================================================================
                            FUNCTION DECLARATION                                
==============================================================================*/
 
void SHRM_Full_Load_SRAM (void);
 
#endif
