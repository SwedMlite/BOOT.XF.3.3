#ifndef __DDR_SDI_H__
#define __DDR_SDI_H__

/*=============================================================================

                              DDR HAL
                            Header File
GENERAL DESCRIPTION
This is the header file that describe the DDR status registers to be logged during clock/voltage switch.
this can be extended to log any other BIMC/PHY registers that aid in debugging .

Copyright (c) 2014-2015 Qualcomm Technologies, Inc. 
All rights reserved.


===========================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ------------------------------------------------------------
10/02/17   rp      Initial revision.
=============================================================================*/
/*==============================================================================
                                  INCLUDES
==============================================================================*/

/*==============================================================================
                                  MACROS
==============================================================================*/
#define SDI_REG_LOG_START_ADDR 0x146BF200

#define SDI_COOKIES_STRUCT_BASE 0x146BF610
#define PASS1_ENTER_COOKIE      0x146BF634
#define PASS2_COOKIE            0x146BF638
#define PASS1_EXIT_COOKIE       0x146BF63C
/*==============================================================================
                                  DATA
==============================================================================*/

extern uint64 ddr_sdi_reg_log_addr[];

typedef enum
{
  DDR_PASS1_START = 0xCAFECAFE,
  DDR_CLOCKS_INITIALIZED = 0xBA53BA11,
  DDR_PASS1_INITIALIZED_TWICE = 0xBADDFACE,
  FREEZE_IO_NOT_SET_WDOG_SR_SET = 0xDEADBAE0,
  FREEZE_IO_NOT_SET_WDOG_SR_NOT_SET = 0xDEADBAE1,
  DDR_WENT_INTO_WDOG_SR = 0xCAFED00D,
  DDR_BROUGHT_OUT_OF_SR = 0xCAB0CAFE,
  DDR_NOT_BROUGHT_OUT_OF_SR = 0xCAB0DEAD,
  DDR_TEST_PASSED = 0xCAFE1111,
  DDR_TEST_FAILED = 0xDEAD0000,
  DDR_FULLY_INIT_PASS2_START = 0xDEADBABE,
  DDR_FULLY_INIT_PASS2_COMPLETE = 0xDEADD00D,
  DDR_RECOVER_PASS2_START = 0xCAFECAB0,
  DDR_RECOVER_PASS2_COMPLETE = 0xCAFEBABE,
  DPCC_MC4_GDSCR_PWR_ON_SET = 0xCAB01111,
  DPCC_MC4_GDSCR_PWR_ON_NOT_SET = 0xCAB00000,
  DPCC_MC5_GDSCR_PWR_ON_SET = 0xCAB0FFFF,
  DPCC_MC5_GDSCR_PWR_ON_NOT_SET = 0xCAB0AAAA,
  DDR_PASS1_EXIT_PREARES_SET = 0xC01DCAFE,
  DDR_PASS1_EXIT_PREARES_NOT_SET = 0xAC1DFACE,
  DDR_PASS1_BEFORE_SDI_REG_DUMP = 0xDCFCDCFC,
  DDR_PASS1_AFTER_SDI_REG_DUMP = 0x5B5B7777,  
  UNUSED = 0xFFFFFFFF,
} SDI_COOKIE_VALUES;


typedef struct
{
  SDI_COOKIE_VALUES p_cookie_value;
}SDIInfo; 

typedef struct
{
  SDIInfo *pass1_enter_cookie;
  SDIInfo *pass2_cookie;
  SDIInfo *pass1_exit_cookie;
  void *sdi_csr_log;
}DDR_SDI_LOGS;

/*==============================================================================
                                  FUNCTIONS
==============================================================================*/

void ddr_sdi_save_reg_log (void);

#endif  // __DDR_SDI_H__