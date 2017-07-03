/*******************************************************************************

License: 
This software was developed at the National Institute of Standards and 
Technology (NIST) by employees of the Federal Government in the course 
of their official duties. Pursuant to title 17 Section 105 of the 
United States Code, this software is not subject to copyright protection 
and is in the public domain. NIST assumes no responsibility  whatsoever for 
its use by other parties, and makes no guarantees, expressed or implied, 
about its quality, reliability, or any other characteristic. 

Disclaimer: 
This software was developed to promote biometric standards and biometric
technology testing for the Federal Government in accordance with the USA
PATRIOT Act and the Enhanced Border Security and Visa Entry Reform Act.
Specific hardware and software products identified in this software were used
in order to perform the software development.  In no case does such
identification imply recommendation or endorsement by the National Institute
of Standards and Technology, nor does it imply that the products and equipment
identified are necessarily the best available for the purpose.  

*******************************************************************************/

#ifndef _MLPCLA_H
#define _MLPCLA_H

/*****************************************************************/
/* Author: Michael D. Garris                                     */
/* Date:   03/17/2005                                            */
/*                                                               */
/* To handle proper prototyping and argument passing to CLAPCK   */
/* routines used by MLP library codes.  E.g. MLP codes are       */
/* written in single percision integer while the CBLAS routines  */
/* are written using long ints.                                  */
/*****************************************************************/

/* Definitions from f2c.h */
#ifndef F2C_INCLUDE
typedef long int integer;
typedef float real;
typedef double doublereal;
#endif

/* Cblas library routines used by MLP library codes */
extern int sgemv_(char *, integer *, integer *, real *, 
	    real *, integer *, real *, integer *, real *, real *, integer *);
extern int sscal_(integer *, real *, real *, integer *);
extern int saxpy_(integer *, real *, real *, integer *, real *, integer *);
extern doublereal sdot_(integer *, real *, integer *, real *, integer *);
extern doublereal snrm2_(integer *, real *, integer *);

/* mlpcla.c */
extern int mlp_sgemv(char, int, int, float, float *, int, float *,
                     int, float, float *, int);
extern int mlp_sscal(int, float, float *, int);
extern int mlp_saxpy(int, float, float *, int, float *, int);
extern float mlp_sdot(int, float *, int, float *, int);
extern float mlp_snrm2(int, float *, int);


#endif /* !_MLPCLA_H */
