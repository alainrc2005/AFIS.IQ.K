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
* Fullsource for module SSYR2.C from package CBLAS.
* Retrieved from NETLIB on Tue Mar 14 10:28:02 2000.
*
* UPDATED: 03/09/2005 by MDG
* ======================================================================
*/

#include "f2c.h"
#include <stdio.h>  /* Added by MDG on 03-09-05 */

/* Subroutine */ int xerbla_(char *srname, integer *info)
{
/*  -- LAPACK auxiliary routine (version 2.0) --   
       Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,   
       Courant Institute, Argonne National Lab, and Rice University   
       September 30, 1994   


    Purpose   
    =======   

    XERBLA  is an error handler for the LAPACK routines.   
    It is called by an LAPACK routine if an input parameter has an   
    invalid value.  A message is printed and execution stops.   

    Installers may consider modifying the STOP statement in order to   
    call system-specific exception-handling facilities.   

    Arguments   
    =========   

    SRNAME  (input) CHARACTER*6   
            The name of the routine which called XERBLA.   

    INFO    (input) INTEGER   
            The position of the invalid parameter in the parameter list   

            of the calling routine.   

   ===================================================================== 
*/

/*
    printf("** On entry to %6s, parameter number %2i had an illegal value\n",
		srname, *info);
*/

    /* %2ld added by MDG on 03-09-05 */
    printf("** On entry to %6s, parameter number %2ld had an illegal value\n",
		srname, *info);


/*     End of XERBLA */

    return 0;
} /* xerbla_ */

