/*
 * This file generated on line 445 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r2hgen.c
 */
#ifndef ATLAS_ZSYR2_H
   #define ATLAS_ZSYR2_H

#include "atlas_zr2.h"

#define ATL_s2U_NU 2

#define ATL_s2L_NU 2

#define ATL_GetPartS2 ATL_GetPartR2
#define ATL_MIN_RESTRICTED_M 1
#define ATL_URGERK ATL_zger2k__900001
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, const TYPE *W, const TYPE *Z,
                        TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY, aW, aZ;
   ATL_INT CEL;
   ATL_r2kern_t gerk;
   const TYPE one[2] = {ATL_rone, ATL_rzero};
   gerk = ATL_GetR2Kern(M, N, A, lda, &i, &nu, &minM, &minN,
                        &aX, &aX2A, &aY, &FNU, &CEL);
   if (aX2A)
   {
      aX = ((size_t)A) % ATL_Cachelen == ((size_t)X) % ATL_Cachelen;
      aW = ((size_t)A) % ATL_Cachelen == ((size_t)W) % ATL_Cachelen;
   }   else
   {
      aW = (aX) ? (((size_t)W)/aX)*aX == (size_t)W : 1;
      aX = (aX) ? (((size_t)X)/aX)*aX == (size_t)X : 1;
   }
   aZ = (aY) ? (((size_t)Z)/aY)*aY == (size_t)Z : 1;
   aY = (aY) ? (((size_t)Y)/aY)*aY == (size_t)Y : 1;
   if (M >= minM && N >= minN && aX && aY && aW && aZ)
   {
      if (FNU)
      {
          ATL_CINT n = (N/nu)*nu, nr=N-n;
          gerk(M, n, X, Y, W, Z, A, lda);
          if (nr)
             ATL_zger2k_Nlt8(M, nr, one, X, 1, Y+(n+n), 1, one, W, 1, Z+(n+n), 1, A+(n+n)*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, W, Z, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_zger2k_Mlt16(M, N, one, X, 1, Y, 1, one, W, 1, Z, 1, A, lda);
}

#define ATL_HER2U_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda1_+0] += x0r*yt1r-x0i*yt1i + y0r*xt1r-y0i*xt1i; \
   aa[lda1_+1] += x0r*yt1i+x0i*yt1r + y0r*xt1i+y0i*xt1r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
}
#define ATL_HER2L_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda0_+2] += x1r*yt0r-x1i*yt0i + y1r*xt0r-y1i*xt0i; \
   aa[lda0_+3] += x1r*yt0i+x1i*yt0r + y1r*xt0i+y1i*xt0r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
}

#endif
