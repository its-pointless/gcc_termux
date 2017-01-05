/*
 * This file generated on line 445 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r2hgen.c
 */
#ifndef ATLAS_DSYR2_L1_H
   #define ATLAS_DSYR2_L1_H

#include "atlas_dr2_L1.h"

#define ATL_s2U_NU 2

#define ATL_s2L_NU 2
#define ATL_MIN_RESTRICTED_M 2
#define ATL_URGERK ATL_dger2k__900001
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, const TYPE *W, const TYPE *Z,
                        TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY, aW, aZ;
   ATL_INT CEL;
   ATL_r2kern_t gerk;
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
             ATL_dger2k_Nlt8(M, nr, ATL_rone, X, 1, Y+n, 1, ATL_rone, W, 1, Z+n, 1, A+n*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, W, Z, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_dger2k_Mlt16(M, N, ATL_rone, X, 1, Y, 1, ATL_rone, W, 1, Z, 1, A, lda);
}

#define ATL_SYR2U_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1]; \
   const TYPE y0_=*(y_), y1_=(y_)[1]; \
   aa[lda0_+0] += x0_*y0_ + y0_*x0_; \
   aa[lda1_+0] += x0_*y1_ + y0_*x1_; \
   aa[lda1_+1] += x1_*y1_ + y1_*x1_; \
}
#define ATL_SYR2L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1]; \
   const TYPE y0_=*(y_), y1_=(y_)[1]; \
   aa[lda0_+0] += x0_*y0_ + y0_*x0_; \
   aa[lda0_+1] += x1_*y0_ + y1_*x0_; \
   aa[lda1_+1] += x1_*y1_ + y1_*x1_; \
}

#endif
