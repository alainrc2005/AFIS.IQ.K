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

/*
* ======================================================================
* NIST Guide to Available Math Software.
* Source for module SAXPY.C from package CBLAS.
* Retrieved from NETLIB on Tue Mar 14 10:55:47 2000.
* ======================================================================
*/

/*  -- translated by f2c (version 19940927).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int saxpy_(integer *n, real *sa, real *sx, integer *incx, 
	real *sy, integer *incy)
{


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i, m, ix, iy, mp1;


/*     constant times a vector plus a vector.   
       uses unrolled loop for increments equal to one.   
       jack dongarra, linpack, 3/11/78.   
       modified 12/3/93, array(1) declarations changed to array(*)   


    
   Parameter adjustments   
       Function Body */
#define SY(I) sy[(I)-1]
#define SX(I) sx[(I)-1]


    if (*n <= 0) {
	return 0;
    }
    if (*sa == 0.f) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        code for unequal increments or equal increments   
            not equal to 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i = 1; i <= *n; ++i) {
	SY(iy) += *sa * SX(ix);
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*        code for both increments equal to 1   


          clean-up loop */

L20:
    m = *n % 4;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i = 1; i <= m; ++i) {
	SY(i) += *sa * SX(i);
/* L30: */
    }
    if (*n < 4) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i = mp1; i <= *n; i += 4) {
	SY(i) += *sa * SX(i);
	SY(i + 1) += *sa * SX(i + 1);
	SY(i + 2) += *sa * SX(i + 2);
	SY(i + 3) += *sa * SX(i + 3);
/* L50: */
    }
    return 0;
} /* saxpy_ */

