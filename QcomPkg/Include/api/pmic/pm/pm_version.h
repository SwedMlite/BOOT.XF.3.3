#ifndef __PM_VERSION_H__
#define __PM_VERSION_H__
/*! \file 
 *  \n
 *  \brief  pm_version.h ---- PMIC Version 
 *  \n
 *  \n This header file contains enums and API definitions for PMIC version 
 *      detection
 *  \n
 *  \n &copy; Copyright 2015-2019 QUALCOMM Technologies Incorporated, All Rights Reserved
 */
/* ======================================================================= */

/* =======================================================================
                             Edit History
  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.


when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
06/21/18   cs      Added new PMIC models to support SMB2351
02/23/18   aab     Added new PMIC models
11/19/17   aab     Updated PMIC models to support SDM855
07/21/17   sv      Updated PMIC models to support SDM670
11/03/15   al      Updated PMIc models
10/01/15   al      Updated PMIC model types 
08/26/15   aab     Updated pm_model_type 
01/07/15   aab     Updated pm_model_type 
04/16/13   kt      Added pm_get_pbs_info API.
01/28/13   kt      Adding pm_get_pmic_info API to get the pmic device info.  
01/28/13   kt      Removing pm_set_hardware_version and pm_get_hardware_version APIs. 
12/06/12   hw      Remove comdef.h and use com_dtypes.h
09/19/12   vk      Add PM8019
03/10/12   wra     Removed old PMIC versions and added Badger PMIC versions. 
                    Reduced hardware versions in enumeration
10/18/11   jtn/mpt Add PM8821 and PM8038
04/04/11   hw      Added pm_get_hardware_version and pm_set_hardware_version API
02/08/11   hw      Merging changes from the PMIC Distributed Driver Arch branch
07/05/10   wra     Added pm_model_type entry for the PM8921 and PM8018
07/05/10   wra     Added file header and pm_model_type entry for the PM8901 
                   and ISL9519
=============================================================================*/
/*===========================================================================

                        HEADER FILES

===========================================================================*/
#include "com_dtypes.h"
#include "pm_err_flags.h"

/*===========================================================================

                        TYPE DEFINITIONS 

===========================================================================*/

/** 
  @enum pm_model_type
  @brief This enum gives the PMIC model type values (Peripheral
  Subtype values) for different PMIC Models. 
 */
typedef enum
{
   PMIC_IS_UNKNOWN   = 0,
   PMIC_IS_PM8941    = 1,
   PMIC_IS_PM8841    = 2,
   PMIC_IS_PM8019    = 3,
   PMIC_IS_PM8026    = 4,
   PMIC_IS_PM8110    = 5,
   PMIC_IS_PMA8084   = 6,
   PMIC_IS_PMI8962   = 7,
   PMIC_IS_PMD9635   = 8,
   PMIC_IS_PM8994    = 9,
   PMIC_IS_PMI8994   = 10,
   PMIC_IS_PM8916    = 11,
   PMIC_IS_PM8004    = 12,
   PMIC_IS_PMF2432   = PMIC_IS_PMA8084, // TODO: Determine if the model number is changing
   PMIC_IS_PM2433    = 14,
   PMIC_IS_PM8950    = 16,
   PMIC_IS_PMK8001   = 18,
   PMIC_IS_PMI8996   = 19,
   PMIC_IS_PM8998    = 20,
   PMIC_IS_PMI8998   = 21,
   PMIC_IS_PM8005    = 24,
   PMIC_IS_PM660L    = 26,
   PMIC_IS_PM660     = 27,
   PMIC_IS_SMB1355   = 28, 
   PMIC_IS_PM855     = 30,
   PMIC_IS_PM8150    = PMIC_IS_PM855,
   PMIC_IS_PM8250    = PMIC_IS_PM855,
   PMIC_IS_PM855L    = 31,
   PMIC_IS_PM8150L   = PMIC_IS_PM855L,
   PMIC_IS_PM6150L   = PMIC_IS_PM855L,
   PMIC_IS_PM855B    = 32,
   PMIC_IS_PM8150B   = PMIC_IS_PM855B,
   PMIC_IS_PMK8002   = 33,
   PMIC_IS_PMX24     = 34,
   PMIC_IS_SMB1390   = 35, 
   PMIC_IS_PM8009    = 36, 
   PMIC_IS_PMI632    = 37, 
   PMIC_IS_PM855P    = 38,
   PMIC_IS_PM855A    = 39,
   PMIC_IS_PM6150A   = PMIC_IS_PM855A,
   PMIC_IS_PM8150A   = PMIC_IS_PM855A,
   PMIC_IS_PM6150    = 40,
   PMIC_IS_SMB2351   = 41,
   PMIC_IS_PMX55     = 42,
   PMIC_IS_INVALID   = 0x7FFFFFFF,
} pm_model_type;





enum
{
  PMIC_A = 0,
  PMIC_B = 1,
  PMIC_C = 2,
  PMIC_D = 3,
  PMIC_E = 4,
  PMIC_F = 5,
  PMIC_G = 6,
  PMIC_INDEX_MAX = 7,
};


typedef enum
{
  PM_GRID_REV_0,
  PM_GRID_REV_1,
  PM_GRID_REV_2,
  PM_GRID_REV_MAX,
}pm_grid_revision_type;


/** 
  @struct pm_device_info_type
  @brief Stores the PMIC's Model type value, the All Layer
  Revision number and the Metal Revision number. Please refer
  to pm_model_type enum above to get more info on which PMIC
  model type value represents which PMIC.For example, for
  PM8019 v2.1 the PMIC model type value is 3 (since PM8019
  model type value is 3 as per pm_model_type enum), All layer
  revision number is '2' and Metal revision number is '1'.
 */
typedef struct
{
  pm_model_type  ePmicModel;             /**< PMIC device model type */
  uint32         nPmicAllLayerRevision;  /**< PMIC device all layer revision number */
  uint32         nPmicMetalRevision;     /**< PMIC device metal revision number */
} pm_device_info_type;

/**
  @brief Number of LOT IDs. Each Lot id represents an Ascii 
         value.
 */
#define PM_PBS_INFO_NUM_LOT_IDS   12

/*  
  @struct pm_pbs_info_mfgid_type  
  @brief  Stores the PMIC Manufacture ID Info. 
          Major Version, Minor Version and Shrink/Non-Shrink info. 
 */ 
typedef struct 
{ 
  uint32  major : 4;                        /* FT Major revision */ 
  uint32  minor : 3;                        /* FT Minor revision */ 
  uint32  shrink : 1;                       /* FT Shrink/Non-Shrink */ 
  uint32  reserved : 24;                    /* FT Shrink/Non-Shrink */ 
} pm_pbs_info_mfgid_type; 


/** 
  @struct pm_pbs_info_type 
  @brief Stores the PMIC PBS related information such as PBS Lot
         ID, ROM Version, RAM Version, Fab Id, Wafer Id, X
         coord, Y coord and Test PGM Rev. PBS ROM/RAM Revision
         id and Variant (or Branch) id are stored in last 16
         bits(upper and lower 8 bits) of rom_version and
         ram_version.
 */
typedef struct
{
  uint8          lot_id[PM_PBS_INFO_NUM_LOT_IDS];  /**< PBS lot id */
  uint32         rom_version;                      /**< PBS ROM Version number */
  uint32         ram_version;                      /**< PBS RAM Version number */
  uint32         fab_id;                           /**< PBS Fab Id */
  uint32         wafer_id;                         /**< PBS Wafer Id */
  uint32         x_coord;                          /**< PBS X Coord */
  uint32         y_coord;                          /**< PBS Y Coord */
  uint32         test_pgm_rev;                     /**< PBS Test PGM Rev */
  pm_pbs_info_mfgid_type  mfg_id;                  /**< PBS MGF ID */
} pm_pbs_info_type;

/*===========================================================================

                        API PROTOTYPE

===========================================================================*/
/** 
 * @name pm_ft_get_pmic_model 
 * @deprecated New code should use the pm_get_pmic_model api.
 */
#define pm_ft_get_pmic_model pm_get_pmic_model
/** 
 * @name pm_ft_get_rev_id 
 * @deprecated New code should use the pm_get_pmic_revision api.
 */
#define pm_ft_get_rev_id pm_get_pmic_revision

/** 
 * @name pm_get_pmic_model 
 *  
 * @brief This function returns the PMIC's model type value.
 *        For example, the API returns '1' for PM8941, '2'
 *        for PM8841 and so on. Please refer to pm_model_type
 *        enum above to get more info on which PMIC model type
 *        value represents which PMIC.
 * 
 * @param[in] pmic_device_index.Primary PMIC:0 Secondary PMIC:1 
 *
 * @return  pm_model_type 
 *          Returns valid PMIC model/tier type if successful
 *          Returns PMIC_IS_INVALID under error conditions (like
 *          invalid device index param).
 *
 */
pm_model_type pm_get_pmic_model(uint8 pmic_device_index);



/** 
 * @name pm_get_pmic_revision 
 *  
 * @brief This function returns the PMIC's All Layer revision
 *        number. For example, the API returs '1' for PMIC v1.x,
 *        '2' for PMIC v2.x  and so on.
 * 
 * @param[in] pmic_device_index.Primary PMIC:0 Secondary PMIC:1
 *
 * @return  uint8 
 *          Returns valid PMIC All Layer revision number if
 *          successful.
 *          Returns 0 under error conditions (like invalid
 *          device index param).
 *
 */
uint8 pm_get_pmic_revision(uint8 pmic_device_index);

/** 
 * @name pm_get_pmic_info 
 *  
 * @brief This function returns information about PMIC device 
 *        for a specific device index in the pmic_device_info
 *        argument. This API returns PMIC's model type value,
 *        All layer revision number and Metal revision number in
 *        pmic_device_info structure. Please refer to
 *        pm_device_info_type structure above for more info. For
 *        example, for PM8019 v2.1 the PMIC model type value is
 *        3 (since PM8019 model type value is 3 as per
 *        pm_model_type enum), All layer revision number is '2'
 *        and Metal revision number is '1'.
 * 
 * @param[in]  pmic_device_index.Primary PMIC:0 Secondary PMIC:1
 * @param[out] pmic_device_info:  
 *                Variable to return to the caller with PMIC
 *                device info. Please refer to
 *                pm_device_info_type structure above for more
 *                info on this structure.
 *
 * @return  pm_err_flag_type 
 *          PM_ERR_FLAG_FEATURE_NOT_SUPPORTED = Error in
 *          collecting and placing PMIC info.
 *          PM_ERR_FLAG_SUCCESS = SUCCESS.
 *
 */
pm_err_flag_type pm_get_pmic_info(uint8 pmic_device_index, pm_device_info_type* pmic_device_info);

/** 
 * @name pm_get_pbs_info 
 *  
 * @brief This function returns information about PMIC device 
 *        PBS Lot ID, ROM Version, RAM Version, Fab Id, Wafer
 *        Id, X coord, Y coord and test pgm rev for a specific
 *        device index in the pbs_info argument.
 * 
 * @param[in]  pmic_device_index.Primary PMIC:0 Secondary PMIC:1
 * @param[out] pbs_info:  
 *                Variable to return to the caller with PMIC
 *                device PBS info. Please refer to
 *                pm_pbs_info_type structure above for more info
 *                on this structure.
 *
 * @return  pm_err_flag_type 
 *          PM_ERR_FLAG_INVALID_PARAMETER
 *          PM_ERR_FLAG_INVALID = Error in collecting and placing PBS info.
 *          PM_ERR_FLAG_SUCCESS
 */
pm_err_flag_type pm_get_pbs_info(uint8 pmic_device_index, pm_pbs_info_type* pbs_info);

/** 
 * @name pm_get_primary_pmic_index 
 *  
 * @brief This function returns the primary pmic index
 * 
 * @return  primary pmic index
 *
 */
uint32
pm_get_primary_pmic_index(void);


#endif // __PM_VERSION_H__
