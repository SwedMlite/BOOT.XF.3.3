#include "msmhwiobase.h"

#define AOP_BOOT_COOKIE 0xA0C00C1E
#define MSG_RAM_DRV_SIZE       0x400  // 1K
#define MSG_RAM_GAP_SIZE       0xFC00  // 63K
#define MSG_RAM_SECTION_SIZE   (MSG_RAM_DRV_SIZE + MSG_RAM_GAP_SIZE)
#define MSG_RAM_AOP_INFO_0 0xF

typedef struct
{
  uint32 boot_cookie_offset;   //boot cookie offset, add to msg ram base 
  uint32 sleep_stats_offset;   //sleep stats offset, add to msg ram base 
  uint32 reserved_addrs[14];
} dict_t;

typedef struct
{
  dict_t dictionary;            //dictionary for subsystems to lookup stats addresses
  uint32 boot_cookie;           //boot cookie indicating AOP is up and initialized
} aop_cookie_info_0_t;


static void clear_aop_msg_ram_cookie(void);

