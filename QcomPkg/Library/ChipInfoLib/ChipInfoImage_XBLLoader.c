/*
 ===============================================================================

FILE: ChipInfoImage.c

DESCRIPTION:  Image-specific implementations of external functions used by
              ChipInfo which are accessed using different APIs on each image

 ================================================================================
 Copyright (c) 2017, 2019 Qualcomm Technologies Incorporated.
 All Rights Reserved.
 QUALCOMM Proprietary and Confidential
 ================================================================================

 $Header: //components/rel/boot.xf/3.2/QcomPkg/Library/ChipInfoLib/ChipInfoImage_XBLLoader.c#1 $
 $DateTime: 2019/01/25 13:38:10 $
 $Author: pwbldsvc $

 =============================================================================*/

/*=============================================================================
  Include Files
  =============================================================================*/
#include "ChipInfoImage.h"
#include "PlatformInfoDefs.h"
#include <string.h>
#include "smem.h"
#include "DALSys.h"

/*=============================================================================
  Macros
  =============================================================================*/


/*=============================================================================
  Data definitions
  =============================================================================*/


/*=============================================================================
  Functions
  =============================================================================*/
DalPlatformInfoSMemType *
ChipInfo_GetSocInfo
(
  void
)
{
  // SMEM-reading is not needed on XBL loader
  return NULL;
}

void
ChipInfo_UnmapSMem
(
  void
)
{
  // Nothing to unmap
  return;
}

void *
ChipInfo_malloc
(
  uint32 nSize
)
{
  // No dynamic allocation is necessary in XBL Loader.
  return NULL;
}


void *
ChipInfo_memcpy
(
  void *restrict pDest,
  uint32 nDestLen,
  const void *restrict pSrc,
  uint32 nSrcLen
)
{
  // No non-string buffers will be copied in XBL loader..
  return NULL;
}


char *
ChipInfo_strcpy
(
  char *szDest,
  const char *szSrc,
  uint32 nDestLen
)
{
  if (szDest == NULL || szSrc == NULL || nDestLen == 0)
  {
    return NULL;
  }

  strlcpy(szDest, szSrc, nDestLen);
  return szDest;
}
