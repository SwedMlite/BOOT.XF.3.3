/*
==============================================================================

FILE:         ClockPropData.c

DESCRIPTION:
  This file contains the clock driver Properties data.

==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockLib/ClockPropData.c#3 $

==============================================================================
  Copyright (c) 2016-2018 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "Drivers/ClockDxe/ClockBSP.h"
#include "Drivers/ClockDxe/ClockDriver.h"
#include "ClockApps.h"
#include "../HALclkLib/HALclkHWIO.h"
#include "HALhwio.h"


/*=========================================================================
      Externs
==========================================================================*/


/*=========================================================================
      Data Declarations
==========================================================================*/

/*
 * Clock Log Default Configuration.
 *
 */
ClockLogType ClockLogDefaultConfig[] =
{

  {
     .nLogSize        =  4096,
     .nGlobalLogFlags =  0x90ff
  }
};

/*
 * Initial rail voltage BSP data.
 */
ClockRailConfigType ClockRailConfig[] =
{
  { "/vcs/vdd_cx",   RAIL_VOLTAGE_LEVEL_NOM },
  { "/vcs/vdd_gx",           RAIL_VOLTAGE_LEVEL_NOM },
  { "/vcs/vdd_mm", RAIL_VOLTAGE_LEVEL_NOM },
  { "/vcs/vdd_mx",   RAIL_VOLTAGE_LEVEL_NOM },
  { NULL }
};

/*
 * BIST dependencies
 */
ClockNameListType ClockBistDependencies[] =
{
    { "gcc_qupv3_wrap_0_m_ahb_clk"          },
    { "gcc_qupv3_wrap_1_m_ahb_clk"          },
    { "gcc_qupv3_wrap_2_m_ahb_clk"          },
    { "gcc_pdm_ahb_clk"                     },
    //{ "gcc_qspi_cnoc_periph_ahb_clk"        },
    { "gcc_sdcc2_ahb_clk"                   },
    { "gcc_sdcc4_ahb_clk"                   },
    { "gcc_tsif_ahb_clk"                    },
    { "gcc_boot_rom_ahb_clk"                },
    { "gcc_camera_ahb_clk"                  },
    { "gcc_disp_ahb_clk"                    },
//    { "gcc_dpm_ahb_clk"                     },
    { "gcc_gpu_cfg_ahb_clk"                 },
//    { "gcc_npu_bwmon_cfg_ahb_clk"           },
//    { "gcc_npu_cfg_ahb_clk"                 },
    { "gcc_pcie_0_cfg_ahb_clk"              },
    { "gcc_pcie_1_cfg_ahb_clk"              },
    { "gcc_pcie_2_cfg_ahb_clk"              },
    { "gcc_prng_ahb_clk"                    },
    { "gcc_qmip_camera_nrt_ahb_clk"         },
    { "gcc_qmip_camera_rt_ahb_clk"          },
    { "gcc_qmip_disp_ahb_clk"               },
    { "gcc_qmip_video_cvp_ahb_clk"          },
    { "gcc_qmip_video_vcodec_ahb_clk"       },
    { "gcc_qupv3_wrap_0_s_ahb_clk"          },
    { "gcc_qupv3_wrap_1_s_ahb_clk"          },
    { "gcc_qupv3_wrap_2_s_ahb_clk"          },
    { "gcc_ufs_card_ahb_clk"                },
    { "gcc_ufs_phy_ahb_clk"                 },
    { "gcc_video_ahb_clk"                   },
    { "gpu_cc_acd_ahb_clk"                  },
    { "gpu_cc_ahb_clk"                      },
    { "gpu_cc_crc_ahb_clk"                  },
    { "gpu_cc_acd_cxo_clk"                  },
    { "gpu_cc_cxo_clk"                      },
    { "gpu_cc_gx_cxo_clk"                   },
    { "gcc_cpuss_ahb_clk"                   },
    { "gcc_sys_noc_cpuss_ahb_clk"           },
    { "gcc_camera_xo_clk"                   },
    { "gcc_disp_xo_clk"                     },
    { "gcc_video_xo_clk"                    },
    { "npu_cc_dsp_bwmon_ahb_clk"            },
    { "video_cc_ahb_clk"                    },
    { "video_cc_xo_clk"                     },
    { "cam_cc_bps_ahb_clk"                  },
    { "cam_cc_core_ahb_clk"                 },
    { "cam_cc_cpas_ahb_clk"                 },
    { "cam_cc_icp_ahb_clk"                  },
    { "cam_cc_ife_0_ahb_clk"                },
    { "cam_cc_ife_1_ahb_clk"                },
    { "cam_cc_ife_lite_ahb_clk"             },
    { "cam_cc_ipe_0_ahb_clk"                },
    { "cam_cc_camnoc_dcd_xo_clk"            },
    { "cam_cc_qdss_debug_xo_clk"            },
    { "cam_cc_gdsc_clk"                     },
    { "disp_cc_mdss_ahb_clk"                },
    { "disp_cc_mdss_non_gdsc_ahb_clk"       },
    { "disp_cc_mdss_rscc_ahb_clk"           },
    { "disp_cc_xo_clk"                      },
//    { "npu_cc_noc_ahb_clk"                  },
//    { "npu_cc_dpm_xo_clk"                   },
//    { "npu_cc_llm_xo_clk"                   },
//    { "npu_cc_rsc_xo_clk"                   },
//    { "npu_cc_xo_clk"                       },
    { NULL }
};


/*
 * List of clocks anticipated to fail the BIST.
 */
ClockNameListType ClockBistExceptions[] =
{
  { NULL }
};

/*
 * List of clocks excluded from the BIST.
 */
ClockNameListType ClockExcludeFromBist[] =
{
  { "apcs_gold_post_acd_clk"                          },  // CPU clocks
  { "apcs_goldplus_post_acd_clk"                      },  // CPU clocks
  { "apcs_l3_post_acd_clk"                            },  // CPU clocks
  { "apcs_silver_post_acd_clk"                        },  // CPU clocks
  { "gcc_pcie_0_link_down_bcr"                        },  // Reset
  { "gcc_pcie_0_nocsr_com_phy_bcr"                    },  // Reset
  { "gcc_pcie_0_phy_bcr"                              },  // Reset
  { "gcc_pcie_0_phy_nocsr_com_phy_bcr"                },  // Reset
  { "gcc_pcie_1_link_down_bcr"                        },  // Reset
  { "gcc_pcie_1_nocsr_com_phy_bcr"                    },  // Reset
  { "gcc_pcie_1_phy_bcr"                              },  // Reset
  { "gcc_pcie_1_phy_nocsr_com_phy_bcr"                },  // Reset
  { "gcc_pcie_2_link_down_bcr"                        },  // Reset
  { "gcc_pcie_2_nocsr_com_phy_bcr"                    },  // Reset
  { "gcc_pcie_2_phy_bcr"                              },  // Reset
  { "gcc_pcie_2_phy_nocsr_com_phy_bcr"                },  // Reset
  { "gcc_pcie_phy_cfg_ahb_bcr"                        },  // Reset
  { "gcc_pcie_phy_com_bcr"                            },  // Reset
  { "gcc_qusb2phy_prim_bcr"                           },  // Reset
  { "gcc_qusb2phy_sec_bcr"                            },  // Reset
  { "gcc_usb3_dp_phy_prim_bcr"                        },  // Reset
  { "gcc_usb3_dp_phy_sec_bcr"                         },  // Reset
  { "gcc_usb3_phy_prim_bcr"                           },  // Reset
  { "gcc_usb3_phy_sec_bcr"                            },  // Reset
  { "gcc_usb3phy_phy_prim_bcr"                        },  // Reset
  { "gcc_usb3phy_phy_sec_bcr"                         },  // Reset
  { "gcc_hlos1_vote_aggre_noc_mmu_audio_tbu_clk"      },  // Special voting register for GCC
  { "gcc_hlos1_vote_aggre_noc_mmu_pcie_tbu_clk"       },  // Special voting register for GCC
  { "gcc_hlos1_vote_aggre_noc_mmu_tbu1_clk"           },  // Special voting register for GCC
  { "gcc_hlos1_vote_aggre_noc_mmu_tbu2_clk"           },  // Special voting register for GCC
  { "gcc_hlos1_vote_all_smmu_mmu_clk"                 },  // Special voting register for GCC
  { "gcc_hlos1_vote_gpu_smmu_clk"                     },  // Special voting register for GCC
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_hf0_clk"            },  // Special voting register for GCC
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_hf1_clk"            },  // Special voting register for GCC
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_sf0_clk"            },  // Special voting register for GCC
  { "gcc_hlos1_vote_mmu_tcu_clk"                      },  // Special voting register for GCC
  { "gcc_hlos1_vote_turing_mmu_tbu0_clk"              },  // Special voting register for GCC
  { "gcc_hlos1_vote_turing_mmu_tbu1_clk"              },  // Special voting register for GCC
  { "cam_cc_sbi_axi_clk"                              },  // SBI fused out
  { "cam_cc_sbi_cphy_rx_clk"                          },  // SBI fused out
  { "cam_cc_sbi_clk"                                  },  // SBI fused out
  { "cam_cc_sbi_ife_0_clk"                            },  // SBI fused out
  { "cam_cc_sbi_ife_1_clk"                            },  // SBI fused out
  { "cam_cc_sbi_csid_clk"                             },  // SBI fused out
  { "npu_cc_atb_clk"                                  },  // NPU clock
  { "npu_cc_dpm_temp_clk"                             },  // NPU clock
  { "npu_cc_dsp_axi_clk"                              },  // NPU clock
  { "npu_cc_llm_curr_clk"                             },  // NPU clock
  { "npu_cc_llm_temp_clk"                             },  // NPU clock
  { "npu_cc_noc_ahb_clk"                              },  // NPU clock
  { "npu_cc_noc_axi_clk"                              },  // NPU clock
  { "npu_cc_noc_dma_clk"                              },  // NPU clock
  { "npu_cc_s2p_clk"                                  },  // NPU clock
  { "gcc_npu_bwmon_cfg_ahb_clk"                       },  // NPU clock
  { "gcc_npu_cfg_ahb_clk"                             },  // NPU clock
  { "npu_cc_noc_ahb_clk"                              },  // NPU clock
  { "npu_cc_dpm_xo_clk"                               },  // NPU clock
  { "npu_cc_llm_xo_clk"                               },  // NPU clock
  { "npu_cc_rsc_xo_clk"                               },  // NPU clock
  { "npu_cc_xo_clk"                                   },  // NPU clock
  { "gcc_gpu_gpll0_clk_src"                           },  // GPU clock
  { "gcc_gpu_gpll0_div_clk_src"                       },  // GPU clock
  { "gpu_cc_cx_apb_clk"                               },  // GPU clock
  { "gpu_cc_cx_qdss_tsctr_clk"                        },  // GPU clock
  { "gpu_cc_gx_qdss_tsctr_clk"                        },  // GPU clock
  { "gcc_gpu_iref_en"                                 },  // GPU clock
  { "gcc_gpu_gpll0_clk_src"                           },  // GPU clock
  { "gcc_ddrss_gpu_axi_clk"                           },  // GPU clock
  { "gcc_gpu_memnoc_gfx_clk"                          },  // GPU clock
  { "gcc_gpu_snoc_dvm_gfx_clk"                        },  // GPU clock
  { "gpu_cc_cx_snoc_dvm_clk"                          },  // GPU clock
  { "gpu_cc_cx_qdss_at_clk"                           },  // GPU clock
  { "gpu_cc_cx_qdss_trig_clk"                         },  // GPU clock
  { "gpu_cc_sleep_clk"                                },  // GPU clock
  { "gpu_cc_gx_vsense_clk"                            },  // GPU clock
  { "gpu_cc_debug_clk"                                },  // GPU clock
  { "gpu_cc_cx_gmu_clk"                               },  // GPU clock
  { "gpu_cc_gx_gmu_clk"                               },  // GPU clock
  { "gpu_cc_cx_gfx3d_clk"                             },  // GPU clock
  { "gpu_cc_cx_gfx3d_slv_clk"                         },  // GPU clock
  { "gpu_cc_gx_gfx3d_clk"                             },  // GPU clock
  { "gpu_cc_spdm_gx_gfx3d_div_clk"                    },  // GPU clock
  { "gpu_cc_pll_test_clk"                             },  // GPU clock
  { "gpu_cc_cx_gfx3d_slv_clk"                         },  // GPU clock
  { NULL }
};

/*
 * List of power domain names NOT to be enabled prior to running the BIST.
 */
ClockNameListType ClockBistExcludedPowerDomainNames[] =
{
  { "gcc_hlos1_vote_aggre_noc_mmu_audio_tbu_gds"      },
  { "gcc_hlos1_vote_aggre_noc_mmu_pcie_tbu_gds"       },
  { "gcc_hlos1_vote_aggre_noc_mmu_tbu1_gds"           },
  { "gcc_hlos1_vote_aggre_noc_mmu_tbu2_gds"           },
  { "gcc_hlos1_vote_all_smmu_mmu_gds"                 },
  { "gcc_hlos1_vote_gpu_smmu_gds"                     },
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_hf0_gds"            },
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_hf1_gds"            },
  { "gcc_hlos1_vote_mmnoc_mmu_tbu_sf0_gds"            },
  { "gcc_hlos1_vote_mmu_tcu_gds"                      },
  { "gcc_hlos1_vote_turing_mmu_tbu0_gds"              },
  { "gcc_hlos1_vote_turing_mmu_tbu1_gds"              },
  { "sbi_gdsc"                                        },
  { "core_gdsc"                                       },
  { "gx_gdsc"                                         },
  { NULL }
};

DALResult  Clock_GetPropertyHandle
(
const char* str,
void** handle
)
{
    if(strcmp("ClockLogDefaults",str) == 0)
    {
        *handle = ClockLogDefaultConfig;
    }
    else if (strcmp("ClockRailConfig",str) == 0)
    {
        *handle = ClockRailConfig;
    }
    else if (strcmp("BISTDependencies",str) == 0)
    {
        *handle = ClockBistDependencies;
    }
    else if (strcmp("BISTExceptions",str) == 0)
    {
        *handle = ClockBistExceptions;
    }
    else if (strcmp("ExcludeFromBist",str) == 0)
    {
        *handle = ClockExcludeFromBist;
    }
    else if (strcmp("ExcludedPowerDomains",str) == 0)
    {
        *handle = ClockBistExcludedPowerDomainNames;
    }
    else
    {
        *handle = NULL;
        return DAL_ERROR;
    }

    return DAL_SUCCESS;
}


