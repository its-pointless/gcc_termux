/*
 * This file generated on line 432 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_CSYR1_L1_H
   #define ATLAS_CSYR1_L1_H

#include "atlas_cr1_L1.h"

#define ATL_s1U_NU 2

#define ATL_s1L_NU 2
#define ATL_MIN_RESTRICTED_M 8
#define ATL_URGERK ATL_cgerk__900003
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY;
   ATL_INT CEL;
   ATL_r1kern_t gerk;
   const TYPE one[2] = {ATL_rone, ATL_rzero};
   gerk = ATL_GetR1Kern(M, N, A, lda, &i, &nu, &minM, &minN,
                        &aX, &aX2A, &aY, &FNU, &CEL);
   if (aX2A)
      aX = ((size_t)A) % ATL_Cachelen == ((size_t)X) % ATL_Cachelen;
   else
      aX = (aX) ? (((size_t)X)/aX)*aX == (size_t)X : 1;
   aY = (aY) ? (((size_t)Y)/aY)*aY == (size_t)Y : 1;
   if (M >= minM && N >= minN && aX && aY)
   {
      if (FNU)
      {
          ATL_CINT n = (N/nu)*nu, nr=N-n;
          gerk(M, n, X, Y, A, lda);
          if (nr)
             ATL_cgerk_axpy(M, nr, one, X, 1, Y+(n+n), 1, A+(n+n)*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_cgerk_Mlt16(M, N, one, X, 1, Y, 1, A, lda);
}

#define ATL_HER1U_nu(A_, lda_, x_, xt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3]; \
   aa[lda0_+0] += x0r*xt0r-x0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda1_+0] += x0r*xt1r-x0i*xt1i; \
   aa[lda1_+1] += x0r*xt1i+x0i*xt1r; \
   aa[lda1_+2] += x1r*xt1r-x1i*xt1i; \
   aa[lda1_+3] = 0.0; \
}
#define ATL_HER1L_nu(A_, lda_, x_, xt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3]; \
   aa[lda0_+0] += x0r*xt0r-x0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda0_+2] += x1r*xt0r-x1i*xt0i; \
   aa[lda0_+3] += x1r*xt0i+x1i*xt0r; \
   aa[lda1_+2] += x1r*xt1r-x1i*xt1i; \
   aa[lda1_+3] = 0.0; \
}

#endif
