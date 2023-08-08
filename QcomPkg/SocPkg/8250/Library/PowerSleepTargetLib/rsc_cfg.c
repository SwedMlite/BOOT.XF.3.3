
#include "PowerSleepTargetLib.h"

#define NUM_SLEEP_SETS 2
#define NUM_WAKE_SETS 2

#define PSLEEP_NUM_CORES_SUPPORTED 8

#define PSLEEP_CXSD_SUPPORTED 1 

rpmh_command_set_t wake_set[NUM_WAKE_SETS] = 
{
  {
    RPMH_SET_WAKE,
    16,
    0,
    //ARC votes
    {
     {0x30000, 5, 1}, //cmd 0 CX
     {0x30010, 4, 1}, //cmd 1 MX 
     {0x300a0, 3, 1}, //cmd 2 XO
  
     //DDR votes
     {0x50000, 0x63CFE61D, 1}, //cmd 3 MC0
     {0x50004, 0x629219B3, 1}, //cmd 4 SH0
  
     //CNOC votes
     {0x50034, 0x60004001, 1}, //cmd 5 SN3
     {0x500A4, 0x60004001, 1}, //cmd 6 SN11
     {0x50074, 0x60003FFF, 1}, //cmd 7 CN0
  
     //PMIC votes
     {0x40b04, 1, 1}, //cmd 8 LDO5 EN
     {0x40b08, 7, 1}, //cmd 9 LDO5 Mode NPM
  
     //Others being voted for by UEFI active modes:
     {0x5007c, 0x60000008, 1}, //cmd 10 ACV 
     {0x50080, 0x6000000F, 1}, //cmd 11 ALC
     {0x50078, 0x60004000, 1}, //cmd 12 QUP
     {0x50028, 0x60003408, 1}, //cmd 13 SN0
     {0x5009c, 0x64ADD765, 1}, //cmd 14 MM0
     {0x500a0, 0x62570BB3, 1}, //cmd 15 MM1						   
    }
  },
  {
    RPMH_SET_WAKE,
    1,
    0,
    //Others being voted for by UEFI active modes:
    {
     {0x30080, 5, 1}, //cmd 0 MMCX
     {0x0, 0, 0}, //cmd 1  
     {0x0, 0, 0}, //cmd 2
     {0x0, 0, 0}, //cmd 3  
     {0x0, 0, 0}, //cmd 4  
     {0x0, 0, 0}, //cmd 5  
     {0x0, 0, 0}, //cmd 6  
     {0x0, 0, 0}, //cmd 7  
     {0x0, 0, 0}, //cmd 8  
     {0x0, 0, 0}, //cmd 9  
     {0x0, 0, 0}, //cmd 11  
     {0x0, 0, 0}, //cmd 12  
     {0x0, 0, 0}, //cmd 13  
     {0x0, 0, 0}, //cmd 14  
     {0x0, 0, 0}, //cmd 15  
    }
  }
};

rpmh_command_set_t sleep_set[NUM_WAKE_SETS] = 
{
  {
    RPMH_SET_SLEEP,
    16,
    0,
  
      //ARC votes
    {
     {0x30000, 0, 0}, //cmd 0 CX
     {0x30010, 1, 0}, //cmd 1 MX 
     {0x300a0, 0, 0}, //cmd 2 XO
  
     //DDR votes
     {0x50000, 0x40000000, 0}, //cmd 3 MC0
     {0x50004, 0x40000000, 0}, //cmd 4 SH0
  
     //CNOC votes
     {0x50034, 0x40000000, 0}, //cmd 5 SN3
     {0x500A4, 0x40000000, 0}, //cmd 6 SN11
     {0x50074, 0x40000000, 0}, //cmd 7 CN0
  
     //PMIC votes
     {0x40b04, 0, 0}, //cmd 8 LDO5 EN
     {0x40b08, 5, 0}, //cmd 9 LDO5 Mode NPM
  
     //Others being voted for by UEFI active modes:
     {0x5007c, 0x40000000, 0}, //cmd 10 ACV 
     {0x50080, 0x40000000, 0}, //cmd 11 ALC
     {0x50078, 0x40000000, 0}, //cmd 12 MM0
     {0x50028, 0x40000000, 0}, //cmd 13 SN0
     {0x5009c, 0x40000000, 0}, //cmd 14 MM1
     {0x500a0, 0x40000000, 0}, //cmd 15 MM0
    }
  },
  {
    RPMH_SET_SLEEP,
    1,
    0,
    //Others being voted for by UEFI active modes:
    {
     {0x30080, 0, 0}, //cmd 0 MMCX
     {0x0, 0, 0}, //cmd 1  
     {0x0, 0, 0}, //cmd 2
     {0x0, 0, 0}, //cmd 3
     {0x0, 0, 0}, //cmd 4  
     {0x0, 0, 0}, //cmd 5  
     {0x0, 0, 0}, //cmd 6  
     {0x0, 0, 0}, //cmd 7  
     {0x0, 0, 0}, //cmd 8  
     {0x0, 0, 0}, //cmd 9  
     {0x0, 0, 0}, //cmd 11  
     {0x0, 0, 0}, //cmd 12  
     {0x0, 0, 0}, //cmd 13  
     {0x0, 0, 0}, //cmd 14  
     {0x0, 0, 0}, //cmd 15  
    }
  }
};

/**
 * <!-- psleep_get_num_cores -->
 *
 * @brief Returns the # of cores supported for this target
 *
 * @return number of cores supported
 */
uint32 psleep_get_num_cores(void)
{
  return PSLEEP_NUM_CORES_SUPPORTED;
}

/**
 * <!-- psleep_cx_sd_supported -->
 *
 * @brief Returns whether or not we support CX collapse on this target
 *
 * @return TRUE if CX collapse is supported
 */
boolean psleep_cx_sd_supported(void)
{
  return PSLEEP_CXSD_SUPPORTED;
}


/**
 * <!-- psleep_rsc_cfg_get_set_cfg -->
 *
 * @brief Gets the associated static config for the give sent, and indicates how many command sets are used
 *
 * @param set : if we should retrieve the sleep or wake set
 *
 * @param num_sets : Byref var to indicate # of command sets in the returned array
 *
 * @return static config command sets for the given set
 */
rpmh_command_set_t * psleep_rsc_cfg_get_set_cfg(rpmh_set_enum set, uint32 *num_sets)
{
  rpmh_command_set_t *cmds = NULL;	
  switch(set)
  {
    case RPMH_SET_SLEEP:
      cmds = sleep_set;
      *num_sets = NUM_SLEEP_SETS; 	    
      break;
    case RPMH_SET_WAKE:
      cmds = wake_set;
      *num_sets = NUM_WAKE_SETS; 	    
      break;
    default:
      *num_sets = 0;
      break;
  }	  
  return cmds;
}

