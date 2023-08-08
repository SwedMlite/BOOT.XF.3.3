#ifndef __VCSSWEVT_H__
#define __VCSSWEVT_H__
/*
===========================================================================
*/
/**
  @file VCSSWEVT.h

  This header provides a variety of preprocessor definitions, type, data, and
  function declarations for QDSS event logging.

  This file provides an abstraction layer for QDSS tracer features.

*/
/*
  ====================================================================

  Copyright (c) 2017- 2019 QUALCOMM Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header: //components/rel/boot.xf/3.2/QcomPkg/Drivers/VcsDxe/VCSSWEVT.h#1 $
  $DateTime: 2019/03/27 17:31:08 $
  $Author: pwbldsvc $
  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/


#ifdef VCS_TRACER_SWEVT
#include "tracer.h"
#include "VCSSWEventId.h"
#endif


/*=========================================================================
      Macros
==========================================================================*/


#ifdef VCS_TRACER_SWEVT
#define VCS_SWEvent(...)  \
  tracer_event_simple_vargs(__VA_ARGS__);
#else
#define VCS_SWEvent(...)
#endif


#endif // __VCSSWEVT_H__

