/*
==============================================================================

FILE:         VCSBSP.c

DESCRIPTION:
  This file contains VCS bsp data for DAL based driver.

==============================================================================

                             Edit History

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/VcsLib/VCSBSP.c#3 $

==============================================================================
            Copyright (c) 2017- 2019 QUALCOMM Technologies Incorporated.  All Rights Reserved.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "Drivers/VcsDxe/VCSBSP.h"

// Components used in this image
#include "Drivers/VcsDxe/RailImpls/VCSRPMhRailImpl.h"


/*=========================================================================
      Externs
==========================================================================*/


/*=========================================================================
      Macros
==========================================================================*/


/*=========================================================================
      Data Declarations
==========================================================================*/
/*
 * VCSRPMhRailImpl_MX
 */
static VCSRPMhRailImplType VCSRPMhRailImpl_MX =
{
  .szName        = "mx.lvl",
  .eDRVId        = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};


/*
 * VCSRPMhRailImpl_CX
 */
static VCSRPMhRailImplType VCSRPMhRailImpl_CX =
{
  .szName        = "cx.lvl",
  .eDRVId        = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};

static VCSRPMhRailImplType VCSRPMhRailImpl_MMCX =
{
  .szName        = "mmcx.lvl",
  .eDRVId        = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};


/*
 * VCSRPMhRailImpl_GFX
 */
static VCSRPMhRailImplType VCSRPMhRailImpl_GFX =
{
  .szName        = "gfx.lvl",
  .eDRVId        = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};

/*
 * VCSRPMhRailImpl_LPIMX
 */
static VCSRPMhRailImplType VCSRPMhRailImpl_LPIMX =
{
  .szName = "lmx.lvl",
  .eDRVId = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};


/*
 * VCSRPMhRailImpl_LPICX
 */
static VCSRPMhRailImplType VCSRPMhRailImpl_LPICX =
{
  .szName = "lcx.lvl",
  .eDRVId = RSC_DRV_HLOS,
  .bBatchCommand = TRUE,
};


/*
 * aRails
 *
 * Set of rail instances.
 */
static VCSRailNodeType aRails[] =
{
  /*-----------------------------------------------------------------------*/
  /* MX                                                   */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_mx"),
    /* no dependency */
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_MX),
  },

  /*-----------------------------------------------------------------------*/
  /* CX                                                   */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_cx"),
    VCS_DEF_RAIL_DEP_NAME("/vcs/vdd_mx"),
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_CX),
  },
  
  /*-----------------------------------------------------------------------*/
  /* MMCX                                                   */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_mm"),
    VCS_DEF_RAIL_DEP_NAME("/vcs/vdd_mx"),
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_MMCX),
  },

  /*-----------------------------------------------------------------------*/
  /* GFX                                                   */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_gx"),
	VCS_DEF_RAIL_DEP_NAME("/vcs/vdd_mx"),
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_GFX),
  },
  
  /*-----------------------------------------------------------------------*/
  /* LPI_MX                                                                */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_lpi_mx"),
    /* no dependency */
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_LPIMX),
  },

  /*-----------------------------------------------------------------------*/
  /* LPI_CX                                                                */
  /*-----------------------------------------------------------------------*/
  {
    VCS_DEF_RAIL_NAME("/vcs/vdd_lpi_cx"),
    VCS_DEF_RAIL_DEP_NAME("/vcs/vdd_lpi_mx"),
    VCS_DEF_RAIL_ATTRIBUTES(NPA_RESOURCE_DEFAULT),
    VCS_DEF_RAIL_IMPL(RPMh, &VCSRPMhRailImpl_LPICX),
  },
};


/*
 * VCS Log Default Configuration.
 */
const VCSLogType VCS_LogDefaultConfig[] =
{
  {
    /* .nLogSize = */ 4096,
  }
};


static VCSBaseType aBases[] =
{
  /* empty */
};


/*
 *  VCSBSP
 *
 *  List and length of Rail and LDO configurations.
 */
const VCSBSPType VCSBSP =
{
  VCS_DEF_ARR_FIELD(Bases, aBases),
  VCS_DEF_ARR_FIELD(Rails, aRails),
};
