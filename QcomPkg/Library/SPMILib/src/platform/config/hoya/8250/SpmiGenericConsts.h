#ifndef __SPMIGENERICCONSTS_H__
#define __SPMIGENERICCONSTS_H__

/* Auto-generated from SM8250 (Kona) [kona_v1.0_p3q1r17.1_M00_partitioned_rtl] */

#define SPMI_MAX_CHANNELS_SUPPORTED 512
#define SPMI_MAX_OWNER_IDS 7

#define INIT_SPMI_DEV_GENERICS { \
  .mNumChannels            = SPMI_MAX_CHANNELS_SUPPORTED, \
  .mNumPortPriorities      = 8, \
  .mNumPvcPorts            = 5, \
  .mNumPvcPortPPIDs        = 8, \
  .mNumMasters             = SPMI_MAX_OWNER_IDS, \
  .mNumProgRamRegs         = 256, \
  .mNumPicAccStatusRegs    = 16, \
  .mNumVrmIds              = 256, \
  .mNumMgpiPorts           = 8, \
}

#endif /* __SPMIGENERICCONSTS_H__ */
