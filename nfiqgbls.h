/*
 * nfiqgbls.h
 *
 *  Created on: Sep 13, 2009
 *      Author: alainrc2005
 */

#ifndef NFIQGBLS_H_
#define NFIQGBLS_H_

#include "defs.h"
#include "lfs.h"
#include "mlp.h"

#ifndef DEFAULT_PPI
#define DEFAULT_PPI       500
#endif

#define NFIQ_VCTRLEN      11
#define NFIQ_NUM_CLASSES  5
#define EMPTY_IMG         1
#define EMPTY_IMG_QUAL    5
#define TOO_FEW_MINUTIAE  2
#define MIN_MINUTIAE      5
#define MIN_MINUTIAE_QUAL 5

/***********************************************************************/
/* ZNORM.C : Routines supporting Z-Normalization */
extern void znorm_fniq_featvctr(float *, float *, float *, const int);
extern int comp_znorm_stats(float **, float **, float *,
                            const int, const int);

/***********************************************************************/
/* NFIQGBLS.C : Global variables supporting NFIQ */
extern float dflt_znorm_means[];
extern float dflt_znorm_stds[];
extern char  dflt_purpose;
extern int   dflt_nInps;
extern int   dflt_nHids;
extern int   dflt_nOuts;
extern char  dflt_acfunc_hids;
extern char  dflt_acfunc_outs;
extern float dflt_wts[];

#endif /* NFIQGBLS_H_ */
