#ifndef _TCS_RESOURCE_H_
#define _TCS_RESOURCE_H_
/*============================================================================
  FILE:         tcs_resource.h
  
  OVERVIEW:     This file provides the types for the PDC TCS driver
 
  DEPENDENCIES: None

                Copyright (c) 2016 Qualcomm Technologies, Inc. (QTI).
                All Rights Reserved.
                Qualcomm Confidential and Proprietary.
                Export of this technology or software is regulated by the U.S. Government.
                Diversion contrary to U.S. law prohibited.
=============================================================================
$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/Library/PdcTargetLib/tcs/src/config/845/display/tcs_resource.h#3 $
$DateTime: 2018/08/09 14:39:37 $
============================================================================*/

/*===========================================================================
 *                            TYPES AND DEFINITIONS
 *===========================================================================*/
/* Number of commands per TCS; assumed to be the same for all */
#define NUM_COMMANDS_PER_TCS  4

/* Enum for the intended usage of each TCS */
typedef enum 
{
  TCS_NUM_SLEEP0        = 0,            /* TCS 0 - Sleep: CX retention */
  TCS_NUM_SLEEP1,                       /* TCS 1 - Sleep: CX off */
  TCS_NUM_TOTAL_SLEEPS,                 /* Number of sleep TCS's */
  
  TCS_NUM_WAKE0 = TCS_NUM_TOTAL_SLEEPS, /* TCS 3 - Wake:  resources to MOL */
  
  TCS_NUM_TOTAL                         /* Total TCS's: */
}tcs_usage;

/* General purpose index values which match the order in g_pdcResourceList */
typedef enum 
{
  RES_IDX_CX = 0,
  RES_IDX_MX,
  RES_IDX_XO,

  TCS_TOTAL_RESOURCE_NUM
}resource_index;

#endif /* _TCS_RESOURCE_H_ */

