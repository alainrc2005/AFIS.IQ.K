/*
 * nfiq.h
 *
 *  Created on: Sep 13, 2009
 *      Author: alainrc2005
 */

#ifndef NFIQ_H_
#define NFIQ_H_

#define Windows

#ifdef Windows
#define NBIS_API __declspec(dllexport)
#else
#define NBIS_API
#endif

/***********************************************************************
************************************************************************
#cat: comp_nfiq - Routine computes NFIQ given an input image.
#cat:             This routine uses default statistics for Z-Normalization
#cat:             and default weights for MLP classification.

   Input:
      idata       - grayscale fingerprint image data
      iw          - image pixel width
      ih          - image pixel height
      id          - image pixel depth (should always be 8)
      ippi        - image scan density in pix/inch
                    If scan density is unknown (pass in -1),
                    then default density of 500ppi is used.
   Output:
      onfiq       - resulting NFIQ value
      oconf       - max output class MLP activation
   Return Code:
      Zero        - successful completion
      EMPTY_IMG   - empty image detected (feature vector set to 0's)
      TOO_FEW_MINUTIAE - too few minutiae detected from fingerprint image,
                    indicating poor quality fingerprint
      Negative    - system error
************************************************************************/
int NBIS_API ImageQuality(int *onfiq, float *oconf, unsigned char *idata,
              const int iw, const int ih, const int id, const int ippi);


typedef enum _PixelFormatType
{
	 Format32bppArgb = 0x26200a,
	 Format32bppRgb = 0x22009,
	 Format24bppRgb = 0x21808
} PixelFormatType;

void NBIS_API FastBitmapToRaw(PixelFormatType pixelformat, int width, int height, int stride, unsigned char * scan, unsigned char * barray);

#endif /* NFIQ_H_ */
