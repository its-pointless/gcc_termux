/*
 * This file generated on line 432 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_DSYR1_L2_H
   #define ATLAS_DSYR1_L2_H

#include "atlas_dr1_L2.h"

#define ATL_s1U_NU 12

#define ATL_s1L_NU 12
#define ATL_MIN_RESTRICTED_M 8
#define ATL_URGERK ATL_dgerk__900003
static void ATL_GENGERK(ATL_CINT M, ATL_CINT N, const TYPE *X,
                        const TYPE *Y, TYPE *A, ATL_CINT lda)
{
   int nu, minM, minN, i, FNU, aX, aX2A, aY;
   ATL_INT CEL;
   ATL_r1kern_t gerk;
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
             ATL_dgerk_axpy(M, nr, ATL_rone, X, 1, Y+n, 1, A+n*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_dgerk_Mlt16(M, N, ATL_rone, X, 1, Y, 1, A, lda);
}

#define ATL_SYR1U_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_), lda10_ = lda9_+(lda_), lda11_ = lda10_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9], x10_=(x_)[10], x11_=(x_)[11]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9], y10_=(y_)[10], y11_=(y_)[11]; \
   aa[lda0_+0] += x0_*y0_; \
   aa[lda1_+0] += x0_*y1_; \
   aa[lda1_+1] += x1_*y1_; \
   aa[lda2_+0] += x0_*y2_; \
   aa[lda2_+1] += x1_*y2_; \
   aa[lda2_+2] += x2_*y2_; \
   aa[lda3_+0] += x0_*y3_; \
   aa[lda3_+1] += x1_*y3_; \
   aa[lda3_+2] += x2_*y3_; \
   aa[lda3_+3] += x3_*y3_; \
   aa[lda4_+0] += x0_*y4_; \
   aa[lda4_+1] += x1_*y4_; \
   aa[lda4_+2] += x2_*y4_; \
   aa[lda4_+3] += x3_*y4_; \
   aa[lda4_+4] += x4_*y4_; \
   aa[lda5_+0] += x0_*y5_; \
   aa[lda5_+1] += x1_*y5_; \
   aa[lda5_+2] += x2_*y5_; \
   aa[lda5_+3] += x3_*y5_; \
   aa[lda5_+4] += x4_*y5_; \
   aa[lda5_+5] += x5_*y5_; \
   aa[lda6_+0] += x0_*y6_; \
   aa[lda6_+1] += x1_*y6_; \
   aa[lda6_+2] += x2_*y6_; \
   aa[lda6_+3] += x3_*y6_; \
   aa[lda6_+4] += x4_*y6_; \
   aa[lda6_+5] += x5_*y6_; \
   aa[lda6_+6] += x6_*y6_; \
   aa[lda7_+0] += x0_*y7_; \
   aa[lda7_+1] += x1_*y7_; \
   aa[lda7_+2] += x2_*y7_; \
   aa[lda7_+3] += x3_*y7_; \
   aa[lda7_+4] += x4_*y7_; \
   aa[lda7_+5] += x5_*y7_; \
   aa[lda7_+6] += x6_*y7_; \
   aa[lda7_+7] += x7_*y7_; \
   aa[lda8_+0] += x0_*y8_; \
   aa[lda8_+1] += x1_*y8_; \
   aa[lda8_+2] += x2_*y8_; \
   aa[lda8_+3] += x3_*y8_; \
   aa[lda8_+4] += x4_*y8_; \
   aa[lda8_+5] += x5_*y8_; \
   aa[lda8_+6] += x6_*y8_; \
   aa[lda8_+7] += x7_*y8_; \
   aa[lda8_+8] += x8_*y8_; \
   aa[lda9_+0] += x0_*y9_; \
   aa[lda9_+1] += x1_*y9_; \
   aa[lda9_+2] += x2_*y9_; \
   aa[lda9_+3] += x3_*y9_; \
   aa[lda9_+4] += x4_*y9_; \
   aa[lda9_+5] += x5_*y9_; \
   aa[lda9_+6] += x6_*y9_; \
   aa[lda9_+7] += x7_*y9_; \
   aa[lda9_+8] += x8_*y9_; \
   aa[lda9_+9] += x9_*y9_; \
   aa[lda10_+0] += x0_*y10_; \
   aa[lda10_+1] += x1_*y10_; \
   aa[lda10_+2] += x2_*y10_; \
   aa[lda10_+3] += x3_*y10_; \
   aa[lda10_+4] += x4_*y10_; \
   aa[lda10_+5] += x5_*y10_; \
   aa[lda10_+6] += x6_*y10_; \
   aa[lda10_+7] += x7_*y10_; \
   aa[lda10_+8] += x8_*y10_; \
   aa[lda10_+9] += x9_*y10_; \
   aa[lda10_+10] += x10_*y10_; \
   aa[lda11_+0] += x0_*y11_; \
   aa[lda11_+1] += x1_*y11_; \
   aa[lda11_+2] += x2_*y11_; \
   aa[lda11_+3] += x3_*y11_; \
   aa[lda11_+4] += x4_*y11_; \
   aa[lda11_+5] += x5_*y11_; \
   aa[lda11_+6] += x6_*y11_; \
   aa[lda11_+7] += x7_*y11_; \
   aa[lda11_+8] += x8_*y11_; \
   aa[lda11_+9] += x9_*y11_; \
   aa[lda11_+10] += x10_*y11_; \
   aa[lda11_+11] += x11_*y11_; \
}
#define ATL_SYR1L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_), lda10_ = lda9_+(lda_), lda11_ = lda10_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9], x10_=(x_)[10], x11_=(x_)[11]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9], y10_=(y_)[10], y11_=(y_)[11]; \
   aa[lda0_+0] += x0_*y0_; \
   aa[lda0_+1] += x1_*y0_; \
   aa[lda0_+2] += x2_*y0_; \
   aa[lda0_+3] += x3_*y0_; \
   aa[lda0_+4] += x4_*y0_; \
   aa[lda0_+5] += x5_*y0_; \
   aa[lda0_+6] += x6_*y0_; \
   aa[lda0_+7] += x7_*y0_; \
   aa[lda0_+8] += x8_*y0_; \
   aa[lda0_+9] += x9_*y0_; \
   aa[lda0_+10] += x10_*y0_; \
   aa[lda0_+11] += x11_*y0_; \
   aa[lda1_+1] += x1_*y1_; \
   aa[lda1_+2] += x2_*y1_; \
   aa[lda1_+3] += x3_*y1_; \
   aa[lda1_+4] += x4_*y1_; \
   aa[lda1_+5] += x5_*y1_; \
   aa[lda1_+6] += x6_*y1_; \
   aa[lda1_+7] += x7_*y1_; \
   aa[lda1_+8] += x8_*y1_; \
   aa[lda1_+9] += x9_*y1_; \
   aa[lda1_+10] += x10_*y1_; \
   aa[lda1_+11] += x11_*y1_; \
   aa[lda2_+2] += x2_*y2_; \
   aa[lda2_+3] += x3_*y2_; \
   aa[lda2_+4] += x4_*y2_; \
   aa[lda2_+5] += x5_*y2_; \
   aa[lda2_+6] += x6_*y2_; \
   aa[lda2_+7] += x7_*y2_; \
   aa[lda2_+8] += x8_*y2_; \
   aa[lda2_+9] += x9_*y2_; \
   aa[lda2_+10] += x10_*y2_; \
   aa[lda2_+11] += x11_*y2_; \
   aa[lda3_+3] += x3_*y3_; \
   aa[lda3_+4] += x4_*y3_; \
   aa[lda3_+5] += x5_*y3_; \
   aa[lda3_+6] += x6_*y3_; \
   aa[lda3_+7] += x7_*y3_; \
   aa[lda3_+8] += x8_*y3_; \
   aa[lda3_+9] += x9_*y3_; \
   aa[lda3_+10] += x10_*y3_; \
   aa[lda3_+11] += x11_*y3_; \
   aa[lda4_+4] += x4_*y4_; \
   aa[lda4_+5] += x5_*y4_; \
   aa[lda4_+6] += x6_*y4_; \
   aa[lda4_+7] += x7_*y4_; \
   aa[lda4_+8] += x8_*y4_; \
   aa[lda4_+9] += x9_*y4_; \
   aa[lda4_+10] += x10_*y4_; \
   aa[lda4_+11] += x11_*y4_; \
   aa[lda5_+5] += x5_*y5_; \
   aa[lda5_+6] += x6_*y5_; \
   aa[lda5_+7] += x7_*y5_; \
   aa[lda5_+8] += x8_*y5_; \
   aa[lda5_+9] += x9_*y5_; \
   aa[lda5_+10] += x10_*y5_; \
   aa[lda5_+11] += x11_*y5_; \
   aa[lda6_+6] += x6_*y6_; \
   aa[lda6_+7] += x7_*y6_; \
   aa[lda6_+8] += x8_*y6_; \
   aa[lda6_+9] += x9_*y6_; \
   aa[lda6_+10] += x10_*y6_; \
   aa[lda6_+11] += x11_*y6_; \
   aa[lda7_+7] += x7_*y7_; \
   aa[lda7_+8] += x8_*y7_; \
   aa[lda7_+9] += x9_*y7_; \
   aa[lda7_+10] += x10_*y7_; \
   aa[lda7_+11] += x11_*y7_; \
   aa[lda8_+8] += x8_*y8_; \
   aa[lda8_+9] += x9_*y8_; \
   aa[lda8_+10] += x10_*y8_; \
   aa[lda8_+11] += x11_*y8_; \
   aa[lda9_+9] += x9_*y9_; \
   aa[lda9_+10] += x10_*y9_; \
   aa[lda9_+11] += x11_*y9_; \
   aa[lda10_+10] += x10_*y10_; \
   aa[lda10_+11] += x11_*y10_; \
   aa[lda11_+11] += x11_*y11_; \
}

#endif
