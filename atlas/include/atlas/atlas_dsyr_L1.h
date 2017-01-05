/*
 * This file generated on line 432 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_DSYR1_L1_H
   #define ATLAS_DSYR1_L1_H

#include "atlas_dr1_L1.h"

#define ATL_s1U_NU 20

#define ATL_s1L_NU 20
#define ATL_MIN_RESTRICTED_M 8
#define ATL_URGERK ATL_dgerk__900002
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
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_), lda10_ = lda9_+(lda_), lda11_ = lda10_+(lda_), lda12_ = lda11_+(lda_), lda13_ = lda12_+(lda_), lda14_ = lda13_+(lda_), lda15_ = lda14_+(lda_), lda16_ = lda15_+(lda_), lda17_ = lda16_+(lda_), lda18_ = lda17_+(lda_), lda19_ = lda18_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9], x10_=(x_)[10], x11_=(x_)[11], x12_=(x_)[12], x13_=(x_)[13], x14_=(x_)[14], x15_=(x_)[15], x16_=(x_)[16], x17_=(x_)[17], x18_=(x_)[18], x19_=(x_)[19]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9], y10_=(y_)[10], y11_=(y_)[11], y12_=(y_)[12], y13_=(y_)[13], y14_=(y_)[14], y15_=(y_)[15], y16_=(y_)[16], y17_=(y_)[17], y18_=(y_)[18], y19_=(y_)[19]; \
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
   aa[lda12_+0] += x0_*y12_; \
   aa[lda12_+1] += x1_*y12_; \
   aa[lda12_+2] += x2_*y12_; \
   aa[lda12_+3] += x3_*y12_; \
   aa[lda12_+4] += x4_*y12_; \
   aa[lda12_+5] += x5_*y12_; \
   aa[lda12_+6] += x6_*y12_; \
   aa[lda12_+7] += x7_*y12_; \
   aa[lda12_+8] += x8_*y12_; \
   aa[lda12_+9] += x9_*y12_; \
   aa[lda12_+10] += x10_*y12_; \
   aa[lda12_+11] += x11_*y12_; \
   aa[lda12_+12] += x12_*y12_; \
   aa[lda13_+0] += x0_*y13_; \
   aa[lda13_+1] += x1_*y13_; \
   aa[lda13_+2] += x2_*y13_; \
   aa[lda13_+3] += x3_*y13_; \
   aa[lda13_+4] += x4_*y13_; \
   aa[lda13_+5] += x5_*y13_; \
   aa[lda13_+6] += x6_*y13_; \
   aa[lda13_+7] += x7_*y13_; \
   aa[lda13_+8] += x8_*y13_; \
   aa[lda13_+9] += x9_*y13_; \
   aa[lda13_+10] += x10_*y13_; \
   aa[lda13_+11] += x11_*y13_; \
   aa[lda13_+12] += x12_*y13_; \
   aa[lda13_+13] += x13_*y13_; \
   aa[lda14_+0] += x0_*y14_; \
   aa[lda14_+1] += x1_*y14_; \
   aa[lda14_+2] += x2_*y14_; \
   aa[lda14_+3] += x3_*y14_; \
   aa[lda14_+4] += x4_*y14_; \
   aa[lda14_+5] += x5_*y14_; \
   aa[lda14_+6] += x6_*y14_; \
   aa[lda14_+7] += x7_*y14_; \
   aa[lda14_+8] += x8_*y14_; \
   aa[lda14_+9] += x9_*y14_; \
   aa[lda14_+10] += x10_*y14_; \
   aa[lda14_+11] += x11_*y14_; \
   aa[lda14_+12] += x12_*y14_; \
   aa[lda14_+13] += x13_*y14_; \
   aa[lda14_+14] += x14_*y14_; \
   aa[lda15_+0] += x0_*y15_; \
   aa[lda15_+1] += x1_*y15_; \
   aa[lda15_+2] += x2_*y15_; \
   aa[lda15_+3] += x3_*y15_; \
   aa[lda15_+4] += x4_*y15_; \
   aa[lda15_+5] += x5_*y15_; \
   aa[lda15_+6] += x6_*y15_; \
   aa[lda15_+7] += x7_*y15_; \
   aa[lda15_+8] += x8_*y15_; \
   aa[lda15_+9] += x9_*y15_; \
   aa[lda15_+10] += x10_*y15_; \
   aa[lda15_+11] += x11_*y15_; \
   aa[lda15_+12] += x12_*y15_; \
   aa[lda15_+13] += x13_*y15_; \
   aa[lda15_+14] += x14_*y15_; \
   aa[lda15_+15] += x15_*y15_; \
   aa[lda16_+0] += x0_*y16_; \
   aa[lda16_+1] += x1_*y16_; \
   aa[lda16_+2] += x2_*y16_; \
   aa[lda16_+3] += x3_*y16_; \
   aa[lda16_+4] += x4_*y16_; \
   aa[lda16_+5] += x5_*y16_; \
   aa[lda16_+6] += x6_*y16_; \
   aa[lda16_+7] += x7_*y16_; \
   aa[lda16_+8] += x8_*y16_; \
   aa[lda16_+9] += x9_*y16_; \
   aa[lda16_+10] += x10_*y16_; \
   aa[lda16_+11] += x11_*y16_; \
   aa[lda16_+12] += x12_*y16_; \
   aa[lda16_+13] += x13_*y16_; \
   aa[lda16_+14] += x14_*y16_; \
   aa[lda16_+15] += x15_*y16_; \
   aa[lda16_+16] += x16_*y16_; \
   aa[lda17_+0] += x0_*y17_; \
   aa[lda17_+1] += x1_*y17_; \
   aa[lda17_+2] += x2_*y17_; \
   aa[lda17_+3] += x3_*y17_; \
   aa[lda17_+4] += x4_*y17_; \
   aa[lda17_+5] += x5_*y17_; \
   aa[lda17_+6] += x6_*y17_; \
   aa[lda17_+7] += x7_*y17_; \
   aa[lda17_+8] += x8_*y17_; \
   aa[lda17_+9] += x9_*y17_; \
   aa[lda17_+10] += x10_*y17_; \
   aa[lda17_+11] += x11_*y17_; \
   aa[lda17_+12] += x12_*y17_; \
   aa[lda17_+13] += x13_*y17_; \
   aa[lda17_+14] += x14_*y17_; \
   aa[lda17_+15] += x15_*y17_; \
   aa[lda17_+16] += x16_*y17_; \
   aa[lda17_+17] += x17_*y17_; \
   aa[lda18_+0] += x0_*y18_; \
   aa[lda18_+1] += x1_*y18_; \
   aa[lda18_+2] += x2_*y18_; \
   aa[lda18_+3] += x3_*y18_; \
   aa[lda18_+4] += x4_*y18_; \
   aa[lda18_+5] += x5_*y18_; \
   aa[lda18_+6] += x6_*y18_; \
   aa[lda18_+7] += x7_*y18_; \
   aa[lda18_+8] += x8_*y18_; \
   aa[lda18_+9] += x9_*y18_; \
   aa[lda18_+10] += x10_*y18_; \
   aa[lda18_+11] += x11_*y18_; \
   aa[lda18_+12] += x12_*y18_; \
   aa[lda18_+13] += x13_*y18_; \
   aa[lda18_+14] += x14_*y18_; \
   aa[lda18_+15] += x15_*y18_; \
   aa[lda18_+16] += x16_*y18_; \
   aa[lda18_+17] += x17_*y18_; \
   aa[lda18_+18] += x18_*y18_; \
   aa[lda19_+0] += x0_*y19_; \
   aa[lda19_+1] += x1_*y19_; \
   aa[lda19_+2] += x2_*y19_; \
   aa[lda19_+3] += x3_*y19_; \
   aa[lda19_+4] += x4_*y19_; \
   aa[lda19_+5] += x5_*y19_; \
   aa[lda19_+6] += x6_*y19_; \
   aa[lda19_+7] += x7_*y19_; \
   aa[lda19_+8] += x8_*y19_; \
   aa[lda19_+9] += x9_*y19_; \
   aa[lda19_+10] += x10_*y19_; \
   aa[lda19_+11] += x11_*y19_; \
   aa[lda19_+12] += x12_*y19_; \
   aa[lda19_+13] += x13_*y19_; \
   aa[lda19_+14] += x14_*y19_; \
   aa[lda19_+15] += x15_*y19_; \
   aa[lda19_+16] += x16_*y19_; \
   aa[lda19_+17] += x17_*y19_; \
   aa[lda19_+18] += x18_*y19_; \
   aa[lda19_+19] += x19_*y19_; \
}
#define ATL_SYR1L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_), lda2_ = lda1_+(lda_), lda3_ = lda2_+(lda_), lda4_ = lda3_+(lda_), lda5_ = lda4_+(lda_), lda6_ = lda5_+(lda_), lda7_ = lda6_+(lda_), lda8_ = lda7_+(lda_), lda9_ = lda8_+(lda_), lda10_ = lda9_+(lda_), lda11_ = lda10_+(lda_), lda12_ = lda11_+(lda_), lda13_ = lda12_+(lda_), lda14_ = lda13_+(lda_), lda15_ = lda14_+(lda_), lda16_ = lda15_+(lda_), lda17_ = lda16_+(lda_), lda18_ = lda17_+(lda_), lda19_ = lda18_+(lda_); \
   const TYPE x0_=*(x_), x1_=(x_)[1], x2_=(x_)[2], x3_=(x_)[3], x4_=(x_)[4], x5_=(x_)[5], x6_=(x_)[6], x7_=(x_)[7], x8_=(x_)[8], x9_=(x_)[9], x10_=(x_)[10], x11_=(x_)[11], x12_=(x_)[12], x13_=(x_)[13], x14_=(x_)[14], x15_=(x_)[15], x16_=(x_)[16], x17_=(x_)[17], x18_=(x_)[18], x19_=(x_)[19]; \
   const TYPE y0_=*(y_), y1_=(y_)[1], y2_=(y_)[2], y3_=(y_)[3], y4_=(y_)[4], y5_=(y_)[5], y6_=(y_)[6], y7_=(y_)[7], y8_=(y_)[8], y9_=(y_)[9], y10_=(y_)[10], y11_=(y_)[11], y12_=(y_)[12], y13_=(y_)[13], y14_=(y_)[14], y15_=(y_)[15], y16_=(y_)[16], y17_=(y_)[17], y18_=(y_)[18], y19_=(y_)[19]; \
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
   aa[lda0_+12] += x12_*y0_; \
   aa[lda0_+13] += x13_*y0_; \
   aa[lda0_+14] += x14_*y0_; \
   aa[lda0_+15] += x15_*y0_; \
   aa[lda0_+16] += x16_*y0_; \
   aa[lda0_+17] += x17_*y0_; \
   aa[lda0_+18] += x18_*y0_; \
   aa[lda0_+19] += x19_*y0_; \
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
   aa[lda1_+12] += x12_*y1_; \
   aa[lda1_+13] += x13_*y1_; \
   aa[lda1_+14] += x14_*y1_; \
   aa[lda1_+15] += x15_*y1_; \
   aa[lda1_+16] += x16_*y1_; \
   aa[lda1_+17] += x17_*y1_; \
   aa[lda1_+18] += x18_*y1_; \
   aa[lda1_+19] += x19_*y1_; \
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
   aa[lda2_+12] += x12_*y2_; \
   aa[lda2_+13] += x13_*y2_; \
   aa[lda2_+14] += x14_*y2_; \
   aa[lda2_+15] += x15_*y2_; \
   aa[lda2_+16] += x16_*y2_; \
   aa[lda2_+17] += x17_*y2_; \
   aa[lda2_+18] += x18_*y2_; \
   aa[lda2_+19] += x19_*y2_; \
   aa[lda3_+3] += x3_*y3_; \
   aa[lda3_+4] += x4_*y3_; \
   aa[lda3_+5] += x5_*y3_; \
   aa[lda3_+6] += x6_*y3_; \
   aa[lda3_+7] += x7_*y3_; \
   aa[lda3_+8] += x8_*y3_; \
   aa[lda3_+9] += x9_*y3_; \
   aa[lda3_+10] += x10_*y3_; \
   aa[lda3_+11] += x11_*y3_; \
   aa[lda3_+12] += x12_*y3_; \
   aa[lda3_+13] += x13_*y3_; \
   aa[lda3_+14] += x14_*y3_; \
   aa[lda3_+15] += x15_*y3_; \
   aa[lda3_+16] += x16_*y3_; \
   aa[lda3_+17] += x17_*y3_; \
   aa[lda3_+18] += x18_*y3_; \
   aa[lda3_+19] += x19_*y3_; \
   aa[lda4_+4] += x4_*y4_; \
   aa[lda4_+5] += x5_*y4_; \
   aa[lda4_+6] += x6_*y4_; \
   aa[lda4_+7] += x7_*y4_; \
   aa[lda4_+8] += x8_*y4_; \
   aa[lda4_+9] += x9_*y4_; \
   aa[lda4_+10] += x10_*y4_; \
   aa[lda4_+11] += x11_*y4_; \
   aa[lda4_+12] += x12_*y4_; \
   aa[lda4_+13] += x13_*y4_; \
   aa[lda4_+14] += x14_*y4_; \
   aa[lda4_+15] += x15_*y4_; \
   aa[lda4_+16] += x16_*y4_; \
   aa[lda4_+17] += x17_*y4_; \
   aa[lda4_+18] += x18_*y4_; \
   aa[lda4_+19] += x19_*y4_; \
   aa[lda5_+5] += x5_*y5_; \
   aa[lda5_+6] += x6_*y5_; \
   aa[lda5_+7] += x7_*y5_; \
   aa[lda5_+8] += x8_*y5_; \
   aa[lda5_+9] += x9_*y5_; \
   aa[lda5_+10] += x10_*y5_; \
   aa[lda5_+11] += x11_*y5_; \
   aa[lda5_+12] += x12_*y5_; \
   aa[lda5_+13] += x13_*y5_; \
   aa[lda5_+14] += x14_*y5_; \
   aa[lda5_+15] += x15_*y5_; \
   aa[lda5_+16] += x16_*y5_; \
   aa[lda5_+17] += x17_*y5_; \
   aa[lda5_+18] += x18_*y5_; \
   aa[lda5_+19] += x19_*y5_; \
   aa[lda6_+6] += x6_*y6_; \
   aa[lda6_+7] += x7_*y6_; \
   aa[lda6_+8] += x8_*y6_; \
   aa[lda6_+9] += x9_*y6_; \
   aa[lda6_+10] += x10_*y6_; \
   aa[lda6_+11] += x11_*y6_; \
   aa[lda6_+12] += x12_*y6_; \
   aa[lda6_+13] += x13_*y6_; \
   aa[lda6_+14] += x14_*y6_; \
   aa[lda6_+15] += x15_*y6_; \
   aa[lda6_+16] += x16_*y6_; \
   aa[lda6_+17] += x17_*y6_; \
   aa[lda6_+18] += x18_*y6_; \
   aa[lda6_+19] += x19_*y6_; \
   aa[lda7_+7] += x7_*y7_; \
   aa[lda7_+8] += x8_*y7_; \
   aa[lda7_+9] += x9_*y7_; \
   aa[lda7_+10] += x10_*y7_; \
   aa[lda7_+11] += x11_*y7_; \
   aa[lda7_+12] += x12_*y7_; \
   aa[lda7_+13] += x13_*y7_; \
   aa[lda7_+14] += x14_*y7_; \
   aa[lda7_+15] += x15_*y7_; \
   aa[lda7_+16] += x16_*y7_; \
   aa[lda7_+17] += x17_*y7_; \
   aa[lda7_+18] += x18_*y7_; \
   aa[lda7_+19] += x19_*y7_; \
   aa[lda8_+8] += x8_*y8_; \
   aa[lda8_+9] += x9_*y8_; \
   aa[lda8_+10] += x10_*y8_; \
   aa[lda8_+11] += x11_*y8_; \
   aa[lda8_+12] += x12_*y8_; \
   aa[lda8_+13] += x13_*y8_; \
   aa[lda8_+14] += x14_*y8_; \
   aa[lda8_+15] += x15_*y8_; \
   aa[lda8_+16] += x16_*y8_; \
   aa[lda8_+17] += x17_*y8_; \
   aa[lda8_+18] += x18_*y8_; \
   aa[lda8_+19] += x19_*y8_; \
   aa[lda9_+9] += x9_*y9_; \
   aa[lda9_+10] += x10_*y9_; \
   aa[lda9_+11] += x11_*y9_; \
   aa[lda9_+12] += x12_*y9_; \
   aa[lda9_+13] += x13_*y9_; \
   aa[lda9_+14] += x14_*y9_; \
   aa[lda9_+15] += x15_*y9_; \
   aa[lda9_+16] += x16_*y9_; \
   aa[lda9_+17] += x17_*y9_; \
   aa[lda9_+18] += x18_*y9_; \
   aa[lda9_+19] += x19_*y9_; \
   aa[lda10_+10] += x10_*y10_; \
   aa[lda10_+11] += x11_*y10_; \
   aa[lda10_+12] += x12_*y10_; \
   aa[lda10_+13] += x13_*y10_; \
   aa[lda10_+14] += x14_*y10_; \
   aa[lda10_+15] += x15_*y10_; \
   aa[lda10_+16] += x16_*y10_; \
   aa[lda10_+17] += x17_*y10_; \
   aa[lda10_+18] += x18_*y10_; \
   aa[lda10_+19] += x19_*y10_; \
   aa[lda11_+11] += x11_*y11_; \
   aa[lda11_+12] += x12_*y11_; \
   aa[lda11_+13] += x13_*y11_; \
   aa[lda11_+14] += x14_*y11_; \
   aa[lda11_+15] += x15_*y11_; \
   aa[lda11_+16] += x16_*y11_; \
   aa[lda11_+17] += x17_*y11_; \
   aa[lda11_+18] += x18_*y11_; \
   aa[lda11_+19] += x19_*y11_; \
   aa[lda12_+12] += x12_*y12_; \
   aa[lda12_+13] += x13_*y12_; \
   aa[lda12_+14] += x14_*y12_; \
   aa[lda12_+15] += x15_*y12_; \
   aa[lda12_+16] += x16_*y12_; \
   aa[lda12_+17] += x17_*y12_; \
   aa[lda12_+18] += x18_*y12_; \
   aa[lda12_+19] += x19_*y12_; \
   aa[lda13_+13] += x13_*y13_; \
   aa[lda13_+14] += x14_*y13_; \
   aa[lda13_+15] += x15_*y13_; \
   aa[lda13_+16] += x16_*y13_; \
   aa[lda13_+17] += x17_*y13_; \
   aa[lda13_+18] += x18_*y13_; \
   aa[lda13_+19] += x19_*y13_; \
   aa[lda14_+14] += x14_*y14_; \
   aa[lda14_+15] += x15_*y14_; \
   aa[lda14_+16] += x16_*y14_; \
   aa[lda14_+17] += x17_*y14_; \
   aa[lda14_+18] += x18_*y14_; \
   aa[lda14_+19] += x19_*y14_; \
   aa[lda15_+15] += x15_*y15_; \
   aa[lda15_+16] += x16_*y15_; \
   aa[lda15_+17] += x17_*y15_; \
   aa[lda15_+18] += x18_*y15_; \
   aa[lda15_+19] += x19_*y15_; \
   aa[lda16_+16] += x16_*y16_; \
   aa[lda16_+17] += x17_*y16_; \
   aa[lda16_+18] += x18_*y16_; \
   aa[lda16_+19] += x19_*y16_; \
   aa[lda17_+17] += x17_*y17_; \
   aa[lda17_+18] += x18_*y17_; \
   aa[lda17_+19] += x19_*y17_; \
   aa[lda18_+18] += x18_*y18_; \
   aa[lda18_+19] += x19_*y18_; \
   aa[lda19_+19] += x19_*y19_; \
}

#endif
