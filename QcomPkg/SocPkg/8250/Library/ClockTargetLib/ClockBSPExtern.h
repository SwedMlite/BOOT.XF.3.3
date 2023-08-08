#ifndef __CLOCKBSPEXTERN_H__
#define __CLOCKBSPEXTERN_H__

/*
==============================================================================

FILE:         ClockBSPExtern.h

DESCRIPTION:
  Auto-generated externs for data in ClockBSP.c.

==============================================================================

$Header: //components/rel/boot.xf/3.2/QcomPkg/SocPkg/8250/Library/ClockTargetLib/ClockBSPExtern.h#4 $

==============================================================================
            Copyright (c) 2019 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================

*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockBSP.h"


/*=========================================================================
      Externs
==========================================================================*/

extern ClockBSPType ClockBSP;

extern ClockSourceNodeType ClockSource_AOSSCC_AOSSCCPLL0;
extern ClockSourceNodeType ClockSource_AOSSCC_AOSSCCPLL1;
extern ClockSourceNodeType ClockSource_GCC_GPLL0;
extern ClockSourceNodeType ClockSource_GCC_GPLL1;
extern ClockSourceNodeType ClockSource_GCC_GPLL10;
extern ClockSourceNodeType ClockSource_GCC_GPLL2;
extern ClockSourceNodeType ClockSource_GCC_GPLL3;
extern ClockSourceNodeType ClockSource_GCC_GPLL4;
extern ClockSourceNodeType ClockSource_GCC_GPLL5;
extern ClockSourceNodeType ClockSource_GCC_GPLL6;
extern ClockSourceNodeType ClockSource_GCC_GPLL7;
extern ClockSourceNodeType ClockSource_GCC_GPLL8;
extern ClockSourceNodeType ClockSource_GCC_GPLL9;

extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCAOP;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCEUDAT;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCIBI;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCRO;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSPMIAODSER;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSWAO;
extern ClockDomainNodeType ClockDomain_AOSSCC_AOSSCCSWAOTS;
extern ClockDomainNodeType ClockDomain_GCC_GCCACC;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCCDSPNOC;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOC;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCNORTHSF;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCSF;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCSOUTHSF;
extern ClockDomainNodeType ClockDomain_GCC_GCCAGGRENOCWESTSF;
extern ClockDomainNodeType ClockDomain_GCC_GCCCE1;
extern ClockDomainNodeType ClockDomain_GCC_GCCCFGNOCLPASS;
extern ClockDomainNodeType ClockDomain_GCC_GCCCNOCPERIPH;
extern ClockDomainNodeType ClockDomain_GCC_GCCCONFIGNOC;
extern ClockDomainNodeType ClockDomain_GCC_GCCCPUSSGPLL0;
extern ClockDomainNodeType ClockDomain_GCC_GCCDDRMCCH0ROOT;
extern ClockDomainNodeType ClockDomain_GCC_GCCDDRMCCH1ROOT;
extern ClockDomainNodeType ClockDomain_GCC_GCCDPM;
extern ClockDomainNodeType ClockDomain_GCC_GCCGPUMEMNOCGFX;
extern ClockDomainNodeType ClockDomain_GCC_GCCIPA2X;
extern ClockDomainNodeType ClockDomain_GCC_GCCMEMNOC;
extern ClockDomainNodeType ClockDomain_GCC_GCCMMNOCHFQX;
extern ClockDomainNodeType ClockDomain_GCC_GCCMMNOCSFQX;
extern ClockDomainNodeType ClockDomain_GCC_GCCMMSSQMCORE;
extern ClockDomainNodeType ClockDomain_GCC_GCCMMUTCU;
extern ClockDomainNodeType ClockDomain_GCC_GCCNPUDMA;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBA;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBB;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSATBC;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSSTM;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSTRACECLKIN;
extern ClockDomainNodeType ClockDomain_GCC_GCCQDSSTRIG;
extern ClockDomainNodeType ClockDomain_GCC_GCCQSPICORE;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0CORE2X;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S0;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S1;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S2;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S3;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S4;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S5;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S6;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP0S7;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1CORE2X;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S0;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S1;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S2;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S3;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S4;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP1S5;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2CORE2X;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S0;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S1;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S2;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S3;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S4;
extern ClockDomainNodeType ClockDomain_GCC_GCCQUPV3WRAP2S5;
extern ClockDomainNodeType ClockDomain_GCC_GCCSDCC2APPS;
extern ClockDomainNodeType ClockDomain_GCC_GCCSDCC4APPS;
extern ClockDomainNodeType ClockDomain_GCC_GCCSHRM;
extern ClockDomainNodeType ClockDomain_GCC_GCCSYSNOC;
extern ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCGCAXI;
extern ClockDomainNodeType ClockDomain_GCC_GCCSYSNOCSFAXI;
extern ClockDomainNodeType ClockDomain_GCC_GCCTURINGAXI;
extern ClockDomainNodeType ClockDomain_GCC_GCCTURINGQ6AXI;
extern ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYAXI;
extern ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYICECORE;
extern ClockDomainNodeType ClockDomain_GCC_GCCUFSPHYUNIPROCORE;
extern ClockDomainNodeType ClockDomain_GCC_GCCUSB30PRIMMASTER;
extern ClockDomainNodeType ClockDomain_GCC_GCCVSENSOR;
extern ClockDomainNodeType ClockDomain_GPUCC_GPUCCRBCPR;

#endif /* __CLOCKBSPEXTERN_H__ */

