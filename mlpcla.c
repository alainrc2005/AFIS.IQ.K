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

/*****************************************************************/
/* File:   mlpcla.c                                              */
/* Author: Michael D. Garris                                     */
/* Date:   03/17/2005                                            */
/*                                                               */
/* To handle proper prototyping and argument passing to CLAPCK   */
/* routines used by MLP library codes.  E.g. MLP codes are       */
/* written in single percision integer while the CBLAS routines  */
/* are written using long ints.                                  */
/*****************************************************************/

#include "mlpcla.h"


/*****************************************************************/
int mlp_sgemv(char trans, int m, int n, float alpha, 
	float *a, int lda, float *x, int incx, float beta, float *y, 
	int incy)
{
   int ret;
   integer t_m, t_n, t_lda, t_incx, t_incy;

   t_m = (integer)m;
   t_n = (integer)n;
   t_lda = (integer)lda;
   t_incx = (integer)incx;
   t_incy = (integer)incy;

   ret = sgemv_(&trans, &t_m, &t_n, &alpha, a, &t_lda, x, &t_incx,
                &beta, y, &t_incy);

   return(ret);
}

/*****************************************************************/
int mlp_sscal(int n, float sa, float *sx, int incx)
{
   int ret;
   integer t_n, t_incx;

   t_n = (integer)n;
   t_incx = (integer)incx;

   ret = sscal_(&t_n, &sa, sx, &t_incx);

   return(ret);
}

/*****************************************************************/
int mlp_saxpy(int n, float sa, float *sx, int incx, float *sy, int incy)
{
   int ret;
   integer t_n, t_incx, t_incy;

   t_n = (integer)n;
   t_incx = (integer)incx;
   t_incy = (integer)incy;

   ret = saxpy_(&t_n, &sa, sx, &t_incx, sy, &t_incy);

   return(ret);
}

/*****************************************************************/
float mlp_sdot(int n, float *sx, int incx, float *sy, int incy)
{
   double dret;
   float fret;
   integer t_n, t_incx, t_incy;

   t_n = (integer)n;
   t_incx = (integer)incx;
   t_incy = (integer)incy;

   dret = sdot_(&t_n, sx, &t_incx, sy, &t_incy);

   fret = (float)dret;

   return(fret);
}

/*****************************************************************/
float mlp_snrm2(int n, float *x, int incx)
{
   double dret;
   float fret;
   integer t_n, t_incx;

   t_n = (integer)n;
   t_incx = (integer)incx;

   dret = snrm2_(&t_n, x, &t_incx);

   fret = (float)dret;

   return(fret);
}

