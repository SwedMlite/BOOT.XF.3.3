
/*! \file  pm_config_pam.c
 *  
 *  \brief  File Contains the PMIC NPA PAM Data
 *  \details  This file contains the PAM data for the PMIC NPA layer.
 *  
 *    Platform: SM8250.XX.1.0
 *    Revision: NO REVISIONS (Working Set)
 *    Template Version: 
 *    $Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Settings/PMIC/pm_config_pam.c#8 $ 
 *    $DateTime: 2019/10/02 10:51:08 $  $Author: pwbldsvc $
 *  
 *  &copy; Copyright Aug. 7, 2019 Qualcomm Technologies Incorporated, All Rights Reserved
 */

/*===========================================================================

                        INCLUDE HEADER FILES

===========================================================================*/

#include "pmapp_npa.h"
#include "pm_prm_device_defs.h"
#include "npa_remote_resource.h"

/*===========================================================================

                        MACRO DEFINITIONS

===========================================================================*/


#define PMIC_NPA_CLIENT_NODE_DISP_EXT_DP "/node/pmic/client/disp_ext_dp"
#define PMIC_NPA_CLIENT_NODE_DISP_PRIM "/node/pmic/client/disp_prim"
#define PMIC_NPA_CLIENT_NODE_DISP_PRIM_AMOLED "/node/pmic/client/disp_prim_amoled"
#define PMIC_NPA_CLIENT_NODE_SD "/node/pmic/client/sd"
#define PMIC_NPA_CLIENT_NODE_UFS0 "/node/pmic/client/ufs0"
#define PMIC_NPA_CLIENT_NODE_UFS_CARD "/node/pmic/client/ufs_card"
#define PMIC_NPA_CLIENT_NODE_USB_HS1 "/node/pmic/client/usb_hs1"
#define PMIC_NPA_CLIENT_NODE_USB_SS1 "/node/pmic/client/usb_ss1"

/*===========================================================================

                        VARIABLES DEFINITION

===========================================================================*/

/*************************** DISP_EXT_DP Client ***************************/

const pm_prm_vreg_data_type
pm_pam_disp_ext_dp_a_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_disp_ext_dp_a_ldo18 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 912, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 912, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 912, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_pam_client_cfg_type
pm_pam_disp_ext_dp_rails_info [] = 
{
    { (void*)pm_pam_disp_ext_dp_a_ldo9, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_disp_ext_dp_a_ldo18, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_disp_ext_dp [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 9 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 18 ),
};

/*************************** DISP_PRIM Client ***************************/

const pm_prm_vreg_data_type
pm_pam_disp_prim_a_ldo5 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_disp_prim_a_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_pam_client_cfg_type
pm_pam_disp_prim_rails_info [] = 
{
    { (void*)pm_pam_disp_prim_a_ldo5, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_disp_prim_a_ldo9, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_disp_prim [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 5 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 9 ),
};


/*************************** DISP_PRIM_AMOLED Client ***************************/

const pm_prm_vreg_data_type
pm_pam_disp_prim_amoled_a_ldo14 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1800, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 1800, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1800, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_disp_prim_amoled_c_ldo11 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 3296, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 3296, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 3296, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_pam_client_cfg_type
pm_pam_disp_prim_amoled_rails_info [] = 
{
    { (void*)pm_pam_disp_prim_amoled_a_ldo14, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_disp_prim_amoled_c_ldo11, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_disp_prim_amoled [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 14 ),
    PM_PRM_CLIENT_VREG_DEP ( c,  ldo, 11 ),
};

/*************************** SD Client ***************************/

const pm_prm_vreg_data_type
pm_pam_sd_c_ldo6 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1800, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 1800, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1800, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 2952, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 2952, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_sd_c_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 2960, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_pam_client_cfg_type
pm_pam_sd_rails_info [] = 
{
    { (void*)pm_pam_sd_c_ldo6, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_sd_c_ldo9, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_sd [] =
{
    PM_PRM_CLIENT_VREG_DEP ( c,  ldo, 6 ),
    PM_PRM_CLIENT_VREG_DEP ( c,  ldo, 9 ),
};

/*************************** UFS0 Client ***************************/

const pm_prm_vreg_data_type
pm_pam_ufs0_a_ldo5 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_ufs0_a_ldo6 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_ufs0_a_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_ufs0_a_ldo17 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 2504, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 2504, PM_PRM_DEV_DISABLE }, // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 2504, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_pam_client_cfg_type
pm_pam_ufs0_rails_info [] = 
{
    { (void*)pm_pam_ufs0_a_ldo5, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_ufs0_a_ldo6, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_ufs0_a_ldo9, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_ufs0_a_ldo17, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_ufs0 [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 5 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 6 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 9 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 17 ),
};

/*************************** UFS_CARD Client ***************************/

const pm_prm_vreg_data_type
pm_pam_ufs_card_a_ldo5 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_ufs_card_a_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_vreg_data_type
pm_pam_ufs_card_c_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 2960, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_ACTIVE
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE },  // GENERIC_MV
    { PM_PRM_VREG_MODE_NPM, 2960, PM_PRM_DEV_ENABLE }  // GENERIC_HV
};

const pm_prm_pam_client_cfg_type
pm_pam_ufs_card_rails_info [] = 
{
    { (void*)pm_pam_ufs_card_a_ldo5, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_ufs_card_a_ldo9, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_ufs_card_c_ldo9, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_ufs_card [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 5 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 9 ),
    PM_PRM_CLIENT_VREG_DEP ( c,  ldo, 9 ),
};

/*************************** USB_HS1 Client ***************************/

const pm_prm_vreg_data_type
pm_pam_usb_hs1_a_ldo2 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 3072, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 3072, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 3072, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_usb_hs1_a_ldo5 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 880, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 880, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_usb_hs1_a_ldo12 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1800, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 1800, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1800, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_pam_client_cfg_type
pm_pam_usb_hs1_rails_info [] = 
{
    { (void*)pm_pam_usb_hs1_a_ldo2, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_usb_hs1_a_ldo5, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_usb_hs1_a_ldo12, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_usb_hs1 [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 2 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 5 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 12 ),
};

/*************************** USB_SS1 Client ***************************/

const pm_prm_vreg_data_type
pm_pam_usb_ss1_a_ldo9 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 1200, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 1200, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_vreg_data_type
pm_pam_usb_ss1_a_ldo18 [] =
{
     /*     mode    voltage(mV)  enable*/ 
    { PM_PRM_VREG_MODE_LPM, 912, PM_PRM_DEV_DISABLE },  // GENERIC_OFF
    { PM_PRM_VREG_MODE_LPM, 912, PM_PRM_DEV_ENABLE },  // GENERIC_STANDBY
    { PM_PRM_VREG_MODE_NPM, 912, PM_PRM_DEV_ENABLE }  // GENERIC_ACTIVE
};

const pm_prm_pam_client_cfg_type
pm_pam_usb_ss1_rails_info [] = 
{
    { (void*)pm_pam_usb_ss1_a_ldo9, PM_PRM_RSRC_VRM_VREG },
    { (void*)pm_pam_usb_ss1_a_ldo18, PM_PRM_RSRC_VRM_VREG },
}; 

npa_node_dependency
pm_pam_deps_usb_ss1 [] =
{
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 9 ),
    PM_PRM_CLIENT_VREG_DEP ( a,  ldo, 18 ),
};


/*************************** NPA NODE RESOURCE ***************************/


const pm_prm_node_resource_info
pm_prm_pam_rsrcs [] =
{   
   {
     PMIC_NPA_GROUP_ID_DISP_EXT_DP,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_ACTIVE,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_disp_ext_dp_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_DISP_EXT_DP, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_disp_ext_dp,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_disp_ext_dp),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_DISP_PRIM,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_ACTIVE,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_disp_prim_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_DISP_PRIM, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_disp_prim,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_disp_prim),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_DISP_PRIM_AMOLED,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_ACTIVE,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_disp_prim_amoled_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_DISP_PRIM_AMOLED, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_disp_prim_amoled,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_disp_prim_amoled),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_SD,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_HV,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_sd_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_SD, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_sd,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_sd),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_UFS0,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_HV,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_ufs0_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_UFS0, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_ufs0,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_ufs0),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_UFS_CARD,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_HV,   // Maximum Value
    NPA_RESOURCE_SINGLE_CLIENT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_ufs_card_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_UFS_CARD, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_ufs_card,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_ufs_card),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_USB_HS1,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_ACTIVE,   // Maximum Value
    NPA_RESOURCE_DEFAULT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_usb_hs1_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_USB_HS1, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_usb_hs1,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_usb_hs1),  // Deps Count
   },
   {
     PMIC_NPA_GROUP_ID_USB_SS1,  // Resource Name
    PMIC_NPA_MODE_ID_GENERIC_ACTIVE,   // Maximum Value
    NPA_RESOURCE_DEFAULT | NPA_RESOURCE_DRIVER_UNCONDITIONAL, // Resource Attribute
    (void*) pm_pam_usb_ss1_rails_info, // Resource User Data
    PMIC_NPA_CLIENT_NODE_USB_SS1, // Node Name
    NPA_NODE_DEFAULT,  // Node Attributes
    NULL,
    pm_pam_deps_usb_ss1,  // Node Dependency
    NPA_ARRAY_SIZE(pm_pam_deps_usb_ss1),  // Deps Count
   },
};

uint32 num_of_pam_rsrcs [] = { sizeof(pm_prm_pam_rsrcs) / sizeof(pm_prm_node_resource_info) };


/*************************** Device Layer Resources ***************************/

pm_prm_rsrc_data_type
pm_prm_device_rsrc_data [] =
{
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 2, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_2),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 5, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_5),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 6, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_6),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 9, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_9),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 12, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_12),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 14, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_14),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 17, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_17),
    PM_PRM_DEV_RSRC_VREG ( a, ldo, 18, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_18),
    PM_PRM_DEV_RSRC_VREG ( c, ldo, 6, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_6),
    PM_PRM_DEV_RSRC_VREG ( c, ldo, 9, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_9),
    PM_PRM_DEV_RSRC_VREG ( c, ldo, 11, PM_PRM_RSRC_LDO,  PM_PRM_RPMH, PM_LDO_11),
    PM_PRM_DEV_RSRC_CLK  ( ., vreg, sp, PM_PRM_RSRC_CLK,PM_PRM_RPMH, PM_CLK_TYPE_INVALID),
    PM_PRM_DEV_RSRC_CLK  ( a, gpio, 8, PM_PRM_RSRC_CLK, PM_PRM_RPMH, PM_CLK_TYPE_INVALID),
};

pm_prm_resource_type
pm_prm_device_rsrcs [] =
{
    {
     pm_prm_device_rsrc_data, 
     sizeof(pm_prm_device_rsrc_data)/sizeof(pm_prm_rsrc_data_type), //Number of Resources
        13
    }
};
