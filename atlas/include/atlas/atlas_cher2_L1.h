/*
 * This file generated on line 445 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r2hgen.c
 */
#ifndef ATLAS_CSYR2_L1_H
   #define ATLAS_CSYR2_L1_H

#include "atlas_cr2_L1.h"

#define ATL_s2U_NU 12

#define ATL_s2L_NU 12
#define ATL_MIN_RESTRICTED_M 8
#define ATL_URGERK ATL_cger2k__900002
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
             ATL_cger2k_Nlt8(M, nr, one, X, 1, Y+(n+n), 1, one, W, 1, Z+(n+n), 1, A+(n+n)*lda, lda);
      } /* end if (FNU) */
      else
         gerk(M, N, X, Y, W, Z, A, lda);
   } /* end if can call optimized kernel */
   else
      ATL_cger2k_Mlt16(M, N, one, X, 1, Y, 1, one, W, 1, Z, 1, A, lda);
}

#define ATL_HER2U_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_), lda2_ = lda1_+(lda_)+(lda_), lda3_ = lda2_+(lda_)+(lda_), lda4_ = lda3_+(lda_)+(lda_), lda5_ = lda4_+(lda_)+(lda_), lda6_ = lda5_+(lda_)+(lda_), lda7_ = lda6_+(lda_)+(lda_), lda8_ = lda7_+(lda_)+(lda_), lda9_ = lda8_+(lda_)+(lda_), lda10_ = lda9_+(lda_)+(lda_), lda11_ = lda10_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3], x2r=(x_)[4], x2i=(x_)[5], x3r=(x_)[6], x3i=(x_)[7], x4r=(x_)[8], x4i=(x_)[9], x5r=(x_)[10], x5i=(x_)[11], x6r=(x_)[12], x6i=(x_)[13], x7r=(x_)[14], x7i=(x_)[15], x8r=(x_)[16], x8i=(x_)[17], x9r=(x_)[18], x9i=(x_)[19], x10r=(x_)[20], x10i=(x_)[21], x11r=(x_)[22], x11i=(x_)[23]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3], xt2r=(xt_)[4], xt2i=(xt_)[5], xt3r=(xt_)[6], xt3i=(xt_)[7], xt4r=(xt_)[8], xt4i=(xt_)[9], xt5r=(xt_)[10], xt5i=(xt_)[11], xt6r=(xt_)[12], xt6i=(xt_)[13], xt7r=(xt_)[14], xt7i=(xt_)[15], xt8r=(xt_)[16], xt8i=(xt_)[17], xt9r=(xt_)[18], xt9i=(xt_)[19], xt10r=(xt_)[20], xt10i=(xt_)[21], xt11r=(xt_)[22], xt11i=(xt_)[23]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3], y2r=(y_)[4], y2i=(y_)[5], y3r=(y_)[6], y3i=(y_)[7], y4r=(y_)[8], y4i=(y_)[9], y5r=(y_)[10], y5i=(y_)[11], y6r=(y_)[12], y6i=(y_)[13], y7r=(y_)[14], y7i=(y_)[15], y8r=(y_)[16], y8i=(y_)[17], y9r=(y_)[18], y9i=(y_)[19], y10r=(y_)[20], y10i=(y_)[21], y11r=(y_)[22], y11i=(y_)[23]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3], yt2r=(yt_)[4], yt2i=(yt_)[5], yt3r=(yt_)[6], yt3i=(yt_)[7], yt4r=(yt_)[8], yt4i=(yt_)[9], yt5r=(yt_)[10], yt5i=(yt_)[11], yt6r=(yt_)[12], yt6i=(yt_)[13], yt7r=(yt_)[14], yt7i=(yt_)[15], yt8r=(yt_)[16], yt8i=(yt_)[17], yt9r=(yt_)[18], yt9i=(yt_)[19], yt10r=(yt_)[20], yt10i=(yt_)[21], yt11r=(yt_)[22], yt11i=(yt_)[23]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda1_+0] += x0r*yt1r-x0i*yt1i + y0r*xt1r-y0i*xt1i; \
   aa[lda1_+1] += x0r*yt1i+x0i*yt1r + y0r*xt1i+y0i*xt1r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
   aa[lda2_+0] += x0r*yt2r-x0i*yt2i + y0r*xt2r-y0i*xt2i; \
   aa[lda2_+1] += x0r*yt2i+x0i*yt2r + y0r*xt2i+y0i*xt2r; \
   aa[lda2_+2] += x1r*yt2r-x1i*yt2i + y1r*xt2r-y1i*xt2i; \
   aa[lda2_+3] += x1r*yt2i+x1i*yt2r + y1r*xt2i+y1i*xt2r; \
   aa[lda2_+4] += x2r*yt2r-x2i*yt2i + y2r*xt2r-y2i*xt2i; \
   aa[lda2_+5] = 0.0; \
   aa[lda3_+0] += x0r*yt3r-x0i*yt3i + y0r*xt3r-y0i*xt3i; \
   aa[lda3_+1] += x0r*yt3i+x0i*yt3r + y0r*xt3i+y0i*xt3r; \
   aa[lda3_+2] += x1r*yt3r-x1i*yt3i + y1r*xt3r-y1i*xt3i; \
   aa[lda3_+3] += x1r*yt3i+x1i*yt3r + y1r*xt3i+y1i*xt3r; \
   aa[lda3_+4] += x2r*yt3r-x2i*yt3i + y2r*xt3r-y2i*xt3i; \
   aa[lda3_+5] += x2r*yt3i+x2i*yt3r + y2r*xt3i+y2i*xt3r; \
   aa[lda3_+6] += x3r*yt3r-x3i*yt3i + y3r*xt3r-y3i*xt3i; \
   aa[lda3_+7] = 0.0; \
   aa[lda4_+0] += x0r*yt4r-x0i*yt4i + y0r*xt4r-y0i*xt4i; \
   aa[lda4_+1] += x0r*yt4i+x0i*yt4r + y0r*xt4i+y0i*xt4r; \
   aa[lda4_+2] += x1r*yt4r-x1i*yt4i + y1r*xt4r-y1i*xt4i; \
   aa[lda4_+3] += x1r*yt4i+x1i*yt4r + y1r*xt4i+y1i*xt4r; \
   aa[lda4_+4] += x2r*yt4r-x2i*yt4i + y2r*xt4r-y2i*xt4i; \
   aa[lda4_+5] += x2r*yt4i+x2i*yt4r + y2r*xt4i+y2i*xt4r; \
   aa[lda4_+6] += x3r*yt4r-x3i*yt4i + y3r*xt4r-y3i*xt4i; \
   aa[lda4_+7] += x3r*yt4i+x3i*yt4r + y3r*xt4i+y3i*xt4r; \
   aa[lda4_+8] += x4r*yt4r-x4i*yt4i + y4r*xt4r-y4i*xt4i; \
   aa[lda4_+9] = 0.0; \
   aa[lda5_+0] += x0r*yt5r-x0i*yt5i + y0r*xt5r-y0i*xt5i; \
   aa[lda5_+1] += x0r*yt5i+x0i*yt5r + y0r*xt5i+y0i*xt5r; \
   aa[lda5_+2] += x1r*yt5r-x1i*yt5i + y1r*xt5r-y1i*xt5i; \
   aa[lda5_+3] += x1r*yt5i+x1i*yt5r + y1r*xt5i+y1i*xt5r; \
   aa[lda5_+4] += x2r*yt5r-x2i*yt5i + y2r*xt5r-y2i*xt5i; \
   aa[lda5_+5] += x2r*yt5i+x2i*yt5r + y2r*xt5i+y2i*xt5r; \
   aa[lda5_+6] += x3r*yt5r-x3i*yt5i + y3r*xt5r-y3i*xt5i; \
   aa[lda5_+7] += x3r*yt5i+x3i*yt5r + y3r*xt5i+y3i*xt5r; \
   aa[lda5_+8] += x4r*yt5r-x4i*yt5i + y4r*xt5r-y4i*xt5i; \
   aa[lda5_+9] += x4r*yt5i+x4i*yt5r + y4r*xt5i+y4i*xt5r; \
   aa[lda5_+10] += x5r*yt5r-x5i*yt5i + y5r*xt5r-y5i*xt5i; \
   aa[lda5_+11] = 0.0; \
   aa[lda6_+0] += x0r*yt6r-x0i*yt6i + y0r*xt6r-y0i*xt6i; \
   aa[lda6_+1] += x0r*yt6i+x0i*yt6r + y0r*xt6i+y0i*xt6r; \
   aa[lda6_+2] += x1r*yt6r-x1i*yt6i + y1r*xt6r-y1i*xt6i; \
   aa[lda6_+3] += x1r*yt6i+x1i*yt6r + y1r*xt6i+y1i*xt6r; \
   aa[lda6_+4] += x2r*yt6r-x2i*yt6i + y2r*xt6r-y2i*xt6i; \
   aa[lda6_+5] += x2r*yt6i+x2i*yt6r + y2r*xt6i+y2i*xt6r; \
   aa[lda6_+6] += x3r*yt6r-x3i*yt6i + y3r*xt6r-y3i*xt6i; \
   aa[lda6_+7] += x3r*yt6i+x3i*yt6r + y3r*xt6i+y3i*xt6r; \
   aa[lda6_+8] += x4r*yt6r-x4i*yt6i + y4r*xt6r-y4i*xt6i; \
   aa[lda6_+9] += x4r*yt6i+x4i*yt6r + y4r*xt6i+y4i*xt6r; \
   aa[lda6_+10] += x5r*yt6r-x5i*yt6i + y5r*xt6r-y5i*xt6i; \
   aa[lda6_+11] += x5r*yt6i+x5i*yt6r + y5r*xt6i+y5i*xt6r; \
   aa[lda6_+12] += x6r*yt6r-x6i*yt6i + y6r*xt6r-y6i*xt6i; \
   aa[lda6_+13] = 0.0; \
   aa[lda7_+0] += x0r*yt7r-x0i*yt7i + y0r*xt7r-y0i*xt7i; \
   aa[lda7_+1] += x0r*yt7i+x0i*yt7r + y0r*xt7i+y0i*xt7r; \
   aa[lda7_+2] += x1r*yt7r-x1i*yt7i + y1r*xt7r-y1i*xt7i; \
   aa[lda7_+3] += x1r*yt7i+x1i*yt7r + y1r*xt7i+y1i*xt7r; \
   aa[lda7_+4] += x2r*yt7r-x2i*yt7i + y2r*xt7r-y2i*xt7i; \
   aa[lda7_+5] += x2r*yt7i+x2i*yt7r + y2r*xt7i+y2i*xt7r; \
   aa[lda7_+6] += x3r*yt7r-x3i*yt7i + y3r*xt7r-y3i*xt7i; \
   aa[lda7_+7] += x3r*yt7i+x3i*yt7r + y3r*xt7i+y3i*xt7r; \
   aa[lda7_+8] += x4r*yt7r-x4i*yt7i + y4r*xt7r-y4i*xt7i; \
   aa[lda7_+9] += x4r*yt7i+x4i*yt7r + y4r*xt7i+y4i*xt7r; \
   aa[lda7_+10] += x5r*yt7r-x5i*yt7i + y5r*xt7r-y5i*xt7i; \
   aa[lda7_+11] += x5r*yt7i+x5i*yt7r + y5r*xt7i+y5i*xt7r; \
   aa[lda7_+12] += x6r*yt7r-x6i*yt7i + y6r*xt7r-y6i*xt7i; \
   aa[lda7_+13] += x6r*yt7i+x6i*yt7r + y6r*xt7i+y6i*xt7r; \
   aa[lda7_+14] += x7r*yt7r-x7i*yt7i + y7r*xt7r-y7i*xt7i; \
   aa[lda7_+15] = 0.0; \
   aa[lda8_+0] += x0r*yt8r-x0i*yt8i + y0r*xt8r-y0i*xt8i; \
   aa[lda8_+1] += x0r*yt8i+x0i*yt8r + y0r*xt8i+y0i*xt8r; \
   aa[lda8_+2] += x1r*yt8r-x1i*yt8i + y1r*xt8r-y1i*xt8i; \
   aa[lda8_+3] += x1r*yt8i+x1i*yt8r + y1r*xt8i+y1i*xt8r; \
   aa[lda8_+4] += x2r*yt8r-x2i*yt8i + y2r*xt8r-y2i*xt8i; \
   aa[lda8_+5] += x2r*yt8i+x2i*yt8r + y2r*xt8i+y2i*xt8r; \
   aa[lda8_+6] += x3r*yt8r-x3i*yt8i + y3r*xt8r-y3i*xt8i; \
   aa[lda8_+7] += x3r*yt8i+x3i*yt8r + y3r*xt8i+y3i*xt8r; \
   aa[lda8_+8] += x4r*yt8r-x4i*yt8i + y4r*xt8r-y4i*xt8i; \
   aa[lda8_+9] += x4r*yt8i+x4i*yt8r + y4r*xt8i+y4i*xt8r; \
   aa[lda8_+10] += x5r*yt8r-x5i*yt8i + y5r*xt8r-y5i*xt8i; \
   aa[lda8_+11] += x5r*yt8i+x5i*yt8r + y5r*xt8i+y5i*xt8r; \
   aa[lda8_+12] += x6r*yt8r-x6i*yt8i + y6r*xt8r-y6i*xt8i; \
   aa[lda8_+13] += x6r*yt8i+x6i*yt8r + y6r*xt8i+y6i*xt8r; \
   aa[lda8_+14] += x7r*yt8r-x7i*yt8i + y7r*xt8r-y7i*xt8i; \
   aa[lda8_+15] += x7r*yt8i+x7i*yt8r + y7r*xt8i+y7i*xt8r; \
   aa[lda8_+16] += x8r*yt8r-x8i*yt8i + y8r*xt8r-y8i*xt8i; \
   aa[lda8_+17] = 0.0; \
   aa[lda9_+0] += x0r*yt9r-x0i*yt9i + y0r*xt9r-y0i*xt9i; \
   aa[lda9_+1] += x0r*yt9i+x0i*yt9r + y0r*xt9i+y0i*xt9r; \
   aa[lda9_+2] += x1r*yt9r-x1i*yt9i + y1r*xt9r-y1i*xt9i; \
   aa[lda9_+3] += x1r*yt9i+x1i*yt9r + y1r*xt9i+y1i*xt9r; \
   aa[lda9_+4] += x2r*yt9r-x2i*yt9i + y2r*xt9r-y2i*xt9i; \
   aa[lda9_+5] += x2r*yt9i+x2i*yt9r + y2r*xt9i+y2i*xt9r; \
   aa[lda9_+6] += x3r*yt9r-x3i*yt9i + y3r*xt9r-y3i*xt9i; \
   aa[lda9_+7] += x3r*yt9i+x3i*yt9r + y3r*xt9i+y3i*xt9r; \
   aa[lda9_+8] += x4r*yt9r-x4i*yt9i + y4r*xt9r-y4i*xt9i; \
   aa[lda9_+9] += x4r*yt9i+x4i*yt9r + y4r*xt9i+y4i*xt9r; \
   aa[lda9_+10] += x5r*yt9r-x5i*yt9i + y5r*xt9r-y5i*xt9i; \
   aa[lda9_+11] += x5r*yt9i+x5i*yt9r + y5r*xt9i+y5i*xt9r; \
   aa[lda9_+12] += x6r*yt9r-x6i*yt9i + y6r*xt9r-y6i*xt9i; \
   aa[lda9_+13] += x6r*yt9i+x6i*yt9r + y6r*xt9i+y6i*xt9r; \
   aa[lda9_+14] += x7r*yt9r-x7i*yt9i + y7r*xt9r-y7i*xt9i; \
   aa[lda9_+15] += x7r*yt9i+x7i*yt9r + y7r*xt9i+y7i*xt9r; \
   aa[lda9_+16] += x8r*yt9r-x8i*yt9i + y8r*xt9r-y8i*xt9i; \
   aa[lda9_+17] += x8r*yt9i+x8i*yt9r + y8r*xt9i+y8i*xt9r; \
   aa[lda9_+18] += x9r*yt9r-x9i*yt9i + y9r*xt9r-y9i*xt9i; \
   aa[lda9_+19] = 0.0; \
   aa[lda10_+0] += x0r*yt10r-x0i*yt10i + y0r*xt10r-y0i*xt10i; \
   aa[lda10_+1] += x0r*yt10i+x0i*yt10r + y0r*xt10i+y0i*xt10r; \
   aa[lda10_+2] += x1r*yt10r-x1i*yt10i + y1r*xt10r-y1i*xt10i; \
   aa[lda10_+3] += x1r*yt10i+x1i*yt10r + y1r*xt10i+y1i*xt10r; \
   aa[lda10_+4] += x2r*yt10r-x2i*yt10i + y2r*xt10r-y2i*xt10i; \
   aa[lda10_+5] += x2r*yt10i+x2i*yt10r + y2r*xt10i+y2i*xt10r; \
   aa[lda10_+6] += x3r*yt10r-x3i*yt10i + y3r*xt10r-y3i*xt10i; \
   aa[lda10_+7] += x3r*yt10i+x3i*yt10r + y3r*xt10i+y3i*xt10r; \
   aa[lda10_+8] += x4r*yt10r-x4i*yt10i + y4r*xt10r-y4i*xt10i; \
   aa[lda10_+9] += x4r*yt10i+x4i*yt10r + y4r*xt10i+y4i*xt10r; \
   aa[lda10_+10] += x5r*yt10r-x5i*yt10i + y5r*xt10r-y5i*xt10i; \
   aa[lda10_+11] += x5r*yt10i+x5i*yt10r + y5r*xt10i+y5i*xt10r; \
   aa[lda10_+12] += x6r*yt10r-x6i*yt10i + y6r*xt10r-y6i*xt10i; \
   aa[lda10_+13] += x6r*yt10i+x6i*yt10r + y6r*xt10i+y6i*xt10r; \
   aa[lda10_+14] += x7r*yt10r-x7i*yt10i + y7r*xt10r-y7i*xt10i; \
   aa[lda10_+15] += x7r*yt10i+x7i*yt10r + y7r*xt10i+y7i*xt10r; \
   aa[lda10_+16] += x8r*yt10r-x8i*yt10i + y8r*xt10r-y8i*xt10i; \
   aa[lda10_+17] += x8r*yt10i+x8i*yt10r + y8r*xt10i+y8i*xt10r; \
   aa[lda10_+18] += x9r*yt10r-x9i*yt10i + y9r*xt10r-y9i*xt10i; \
   aa[lda10_+19] += x9r*yt10i+x9i*yt10r + y9r*xt10i+y9i*xt10r; \
   aa[lda10_+20] += x10r*yt10r-x10i*yt10i + y10r*xt10r-y10i*xt10i; \
   aa[lda10_+21] = 0.0; \
   aa[lda11_+0] += x0r*yt11r-x0i*yt11i + y0r*xt11r-y0i*xt11i; \
   aa[lda11_+1] += x0r*yt11i+x0i*yt11r + y0r*xt11i+y0i*xt11r; \
   aa[lda11_+2] += x1r*yt11r-x1i*yt11i + y1r*xt11r-y1i*xt11i; \
   aa[lda11_+3] += x1r*yt11i+x1i*yt11r + y1r*xt11i+y1i*xt11r; \
   aa[lda11_+4] += x2r*yt11r-x2i*yt11i + y2r*xt11r-y2i*xt11i; \
   aa[lda11_+5] += x2r*yt11i+x2i*yt11r + y2r*xt11i+y2i*xt11r; \
   aa[lda11_+6] += x3r*yt11r-x3i*yt11i + y3r*xt11r-y3i*xt11i; \
   aa[lda11_+7] += x3r*yt11i+x3i*yt11r + y3r*xt11i+y3i*xt11r; \
   aa[lda11_+8] += x4r*yt11r-x4i*yt11i + y4r*xt11r-y4i*xt11i; \
   aa[lda11_+9] += x4r*yt11i+x4i*yt11r + y4r*xt11i+y4i*xt11r; \
   aa[lda11_+10] += x5r*yt11r-x5i*yt11i + y5r*xt11r-y5i*xt11i; \
   aa[lda11_+11] += x5r*yt11i+x5i*yt11r + y5r*xt11i+y5i*xt11r; \
   aa[lda11_+12] += x6r*yt11r-x6i*yt11i + y6r*xt11r-y6i*xt11i; \
   aa[lda11_+13] += x6r*yt11i+x6i*yt11r + y6r*xt11i+y6i*xt11r; \
   aa[lda11_+14] += x7r*yt11r-x7i*yt11i + y7r*xt11r-y7i*xt11i; \
   aa[lda11_+15] += x7r*yt11i+x7i*yt11r + y7r*xt11i+y7i*xt11r; \
   aa[lda11_+16] += x8r*yt11r-x8i*yt11i + y8r*xt11r-y8i*xt11i; \
   aa[lda11_+17] += x8r*yt11i+x8i*yt11r + y8r*xt11i+y8i*xt11r; \
   aa[lda11_+18] += x9r*yt11r-x9i*yt11i + y9r*xt11r-y9i*xt11i; \
   aa[lda11_+19] += x9r*yt11i+x9i*yt11r + y9r*xt11i+y9i*xt11r; \
   aa[lda11_+20] += x10r*yt11r-x10i*yt11i + y10r*xt11r-y10i*xt11i; \
   aa[lda11_+21] += x10r*yt11i+x10i*yt11r + y10r*xt11i+y10i*xt11r; \
   aa[lda11_+22] += x11r*yt11r-x11i*yt11i + y11r*xt11r-y11i*xt11i; \
   aa[lda11_+23] = 0.0; \
}
#define ATL_HER2L_nu(A_, lda_, x_, y_, xt_, yt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0, lda1_ = lda0_+(lda_)+(lda_), lda2_ = lda1_+(lda_)+(lda_), lda3_ = lda2_+(lda_)+(lda_), lda4_ = lda3_+(lda_)+(lda_), lda5_ = lda4_+(lda_)+(lda_), lda6_ = lda5_+(lda_)+(lda_), lda7_ = lda6_+(lda_)+(lda_), lda8_ = lda7_+(lda_)+(lda_), lda9_ = lda8_+(lda_)+(lda_), lda10_ = lda9_+(lda_)+(lda_), lda11_ = lda10_+(lda_)+(lda_); \
   const TYPE x0r=*(x_), x0i=(x_)[1], x1r=(x_)[2], x1i=(x_)[3], x2r=(x_)[4], x2i=(x_)[5], x3r=(x_)[6], x3i=(x_)[7], x4r=(x_)[8], x4i=(x_)[9], x5r=(x_)[10], x5i=(x_)[11], x6r=(x_)[12], x6i=(x_)[13], x7r=(x_)[14], x7i=(x_)[15], x8r=(x_)[16], x8i=(x_)[17], x9r=(x_)[18], x9i=(x_)[19], x10r=(x_)[20], x10i=(x_)[21], x11r=(x_)[22], x11i=(x_)[23]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1], xt1r=(xt_)[2], xt1i=(xt_)[3], xt2r=(xt_)[4], xt2i=(xt_)[5], xt3r=(xt_)[6], xt3i=(xt_)[7], xt4r=(xt_)[8], xt4i=(xt_)[9], xt5r=(xt_)[10], xt5i=(xt_)[11], xt6r=(xt_)[12], xt6i=(xt_)[13], xt7r=(xt_)[14], xt7i=(xt_)[15], xt8r=(xt_)[16], xt8i=(xt_)[17], xt9r=(xt_)[18], xt9i=(xt_)[19], xt10r=(xt_)[20], xt10i=(xt_)[21], xt11r=(xt_)[22], xt11i=(xt_)[23]; \
   const TYPE y0r=*(y_), y0i=(y_)[1], y1r=(y_)[2], y1i=(y_)[3], y2r=(y_)[4], y2i=(y_)[5], y3r=(y_)[6], y3i=(y_)[7], y4r=(y_)[8], y4i=(y_)[9], y5r=(y_)[10], y5i=(y_)[11], y6r=(y_)[12], y6i=(y_)[13], y7r=(y_)[14], y7i=(y_)[15], y8r=(y_)[16], y8i=(y_)[17], y9r=(y_)[18], y9i=(y_)[19], y10r=(y_)[20], y10i=(y_)[21], y11r=(y_)[22], y11i=(y_)[23]; \
   const TYPE yt0r=*(yt_), yt0i=(yt_)[1], yt1r=(yt_)[2], yt1i=(yt_)[3], yt2r=(yt_)[4], yt2i=(yt_)[5], yt3r=(yt_)[6], yt3i=(yt_)[7], yt4r=(yt_)[8], yt4i=(yt_)[9], yt5r=(yt_)[10], yt5i=(yt_)[11], yt6r=(yt_)[12], yt6i=(yt_)[13], yt7r=(yt_)[14], yt7i=(yt_)[15], yt8r=(yt_)[16], yt8i=(yt_)[17], yt9r=(yt_)[18], yt9i=(yt_)[19], yt10r=(yt_)[20], yt10i=(yt_)[21], yt11r=(yt_)[22], yt11i=(yt_)[23]; \
   aa[lda0_+0] += x0r*yt0r-x0i*yt0i + y0r*xt0r-y0i*xt0i; \
   aa[lda0_+1] = 0.0; \
   aa[lda0_+2] += x1r*yt0r-x1i*yt0i + y1r*xt0r-y1i*xt0i; \
   aa[lda0_+3] += x1r*yt0i+x1i*yt0r + y1r*xt0i+y1i*xt0r; \
   aa[lda0_+4] += x2r*yt0r-x2i*yt0i + y2r*xt0r-y2i*xt0i; \
   aa[lda0_+5] += x2r*yt0i+x2i*yt0r + y2r*xt0i+y2i*xt0r; \
   aa[lda0_+6] += x3r*yt0r-x3i*yt0i + y3r*xt0r-y3i*xt0i; \
   aa[lda0_+7] += x3r*yt0i+x3i*yt0r + y3r*xt0i+y3i*xt0r; \
   aa[lda0_+8] += x4r*yt0r-x4i*yt0i + y4r*xt0r-y4i*xt0i; \
   aa[lda0_+9] += x4r*yt0i+x4i*yt0r + y4r*xt0i+y4i*xt0r; \
   aa[lda0_+10] += x5r*yt0r-x5i*yt0i + y5r*xt0r-y5i*xt0i; \
   aa[lda0_+11] += x5r*yt0i+x5i*yt0r + y5r*xt0i+y5i*xt0r; \
   aa[lda0_+12] += x6r*yt0r-x6i*yt0i + y6r*xt0r-y6i*xt0i; \
   aa[lda0_+13] += x6r*yt0i+x6i*yt0r + y6r*xt0i+y6i*xt0r; \
   aa[lda0_+14] += x7r*yt0r-x7i*yt0i + y7r*xt0r-y7i*xt0i; \
   aa[lda0_+15] += x7r*yt0i+x7i*yt0r + y7r*xt0i+y7i*xt0r; \
   aa[lda0_+16] += x8r*yt0r-x8i*yt0i + y8r*xt0r-y8i*xt0i; \
   aa[lda0_+17] += x8r*yt0i+x8i*yt0r + y8r*xt0i+y8i*xt0r; \
   aa[lda0_+18] += x9r*yt0r-x9i*yt0i + y9r*xt0r-y9i*xt0i; \
   aa[lda0_+19] += x9r*yt0i+x9i*yt0r + y9r*xt0i+y9i*xt0r; \
   aa[lda0_+20] += x10r*yt0r-x10i*yt0i + y10r*xt0r-y10i*xt0i; \
   aa[lda0_+21] += x10r*yt0i+x10i*yt0r + y10r*xt0i+y10i*xt0r; \
   aa[lda0_+22] += x11r*yt0r-x11i*yt0i + y11r*xt0r-y11i*xt0i; \
   aa[lda0_+23] += x11r*yt0i+x11i*yt0r + y11r*xt0i+y11i*xt0r; \
   aa[lda1_+2] += x1r*yt1r-x1i*yt1i + y1r*xt1r-y1i*xt1i; \
   aa[lda1_+3] = 0.0; \
   aa[lda1_+4] += x2r*yt1r-x2i*yt1i + y2r*xt1r-y2i*xt1i; \
   aa[lda1_+5] += x2r*yt1i+x2i*yt1r + y2r*xt1i+y2i*xt1r; \
   aa[lda1_+6] += x3r*yt1r-x3i*yt1i + y3r*xt1r-y3i*xt1i; \
   aa[lda1_+7] += x3r*yt1i+x3i*yt1r + y3r*xt1i+y3i*xt1r; \
   aa[lda1_+8] += x4r*yt1r-x4i*yt1i + y4r*xt1r-y4i*xt1i; \
   aa[lda1_+9] += x4r*yt1i+x4i*yt1r + y4r*xt1i+y4i*xt1r; \
   aa[lda1_+10] += x5r*yt1r-x5i*yt1i + y5r*xt1r-y5i*xt1i; \
   aa[lda1_+11] += x5r*yt1i+x5i*yt1r + y5r*xt1i+y5i*xt1r; \
   aa[lda1_+12] += x6r*yt1r-x6i*yt1i + y6r*xt1r-y6i*xt1i; \
   aa[lda1_+13] += x6r*yt1i+x6i*yt1r + y6r*xt1i+y6i*xt1r; \
   aa[lda1_+14] += x7r*yt1r-x7i*yt1i + y7r*xt1r-y7i*xt1i; \
   aa[lda1_+15] += x7r*yt1i+x7i*yt1r + y7r*xt1i+y7i*xt1r; \
   aa[lda1_+16] += x8r*yt1r-x8i*yt1i + y8r*xt1r-y8i*xt1i; \
   aa[lda1_+17] += x8r*yt1i+x8i*yt1r + y8r*xt1i+y8i*xt1r; \
   aa[lda1_+18] += x9r*yt1r-x9i*yt1i + y9r*xt1r-y9i*xt1i; \
   aa[lda1_+19] += x9r*yt1i+x9i*yt1r + y9r*xt1i+y9i*xt1r; \
   aa[lda1_+20] += x10r*yt1r-x10i*yt1i + y10r*xt1r-y10i*xt1i; \
   aa[lda1_+21] += x10r*yt1i+x10i*yt1r + y10r*xt1i+y10i*xt1r; \
   aa[lda1_+22] += x11r*yt1r-x11i*yt1i + y11r*xt1r-y11i*xt1i; \
   aa[lda1_+23] += x11r*yt1i+x11i*yt1r + y11r*xt1i+y11i*xt1r; \
   aa[lda2_+4] += x2r*yt2r-x2i*yt2i + y2r*xt2r-y2i*xt2i; \
   aa[lda2_+5] = 0.0; \
   aa[lda2_+6] += x3r*yt2r-x3i*yt2i + y3r*xt2r-y3i*xt2i; \
   aa[lda2_+7] += x3r*yt2i+x3i*yt2r + y3r*xt2i+y3i*xt2r; \
   aa[lda2_+8] += x4r*yt2r-x4i*yt2i + y4r*xt2r-y4i*xt2i; \
   aa[lda2_+9] += x4r*yt2i+x4i*yt2r + y4r*xt2i+y4i*xt2r; \
   aa[lda2_+10] += x5r*yt2r-x5i*yt2i + y5r*xt2r-y5i*xt2i; \
   aa[lda2_+11] += x5r*yt2i+x5i*yt2r + y5r*xt2i+y5i*xt2r; \
   aa[lda2_+12] += x6r*yt2r-x6i*yt2i + y6r*xt2r-y6i*xt2i; \
   aa[lda2_+13] += x6r*yt2i+x6i*yt2r + y6r*xt2i+y6i*xt2r; \
   aa[lda2_+14] += x7r*yt2r-x7i*yt2i + y7r*xt2r-y7i*xt2i; \
   aa[lda2_+15] += x7r*yt2i+x7i*yt2r + y7r*xt2i+y7i*xt2r; \
   aa[lda2_+16] += x8r*yt2r-x8i*yt2i + y8r*xt2r-y8i*xt2i; \
   aa[lda2_+17] += x8r*yt2i+x8i*yt2r + y8r*xt2i+y8i*xt2r; \
   aa[lda2_+18] += x9r*yt2r-x9i*yt2i + y9r*xt2r-y9i*xt2i; \
   aa[lda2_+19] += x9r*yt2i+x9i*yt2r + y9r*xt2i+y9i*xt2r; \
   aa[lda2_+20] += x10r*yt2r-x10i*yt2i + y10r*xt2r-y10i*xt2i; \
   aa[lda2_+21] += x10r*yt2i+x10i*yt2r + y10r*xt2i+y10i*xt2r; \
   aa[lda2_+22] += x11r*yt2r-x11i*yt2i + y11r*xt2r-y11i*xt2i; \
   aa[lda2_+23] += x11r*yt2i+x11i*yt2r + y11r*xt2i+y11i*xt2r; \
   aa[lda3_+6] += x3r*yt3r-x3i*yt3i + y3r*xt3r-y3i*xt3i; \
   aa[lda3_+7] = 0.0; \
   aa[lda3_+8] += x4r*yt3r-x4i*yt3i + y4r*xt3r-y4i*xt3i; \
   aa[lda3_+9] += x4r*yt3i+x4i*yt3r + y4r*xt3i+y4i*xt3r; \
   aa[lda3_+10] += x5r*yt3r-x5i*yt3i + y5r*xt3r-y5i*xt3i; \
   aa[lda3_+11] += x5r*yt3i+x5i*yt3r + y5r*xt3i+y5i*xt3r; \
   aa[lda3_+12] += x6r*yt3r-x6i*yt3i + y6r*xt3r-y6i*xt3i; \
   aa[lda3_+13] += x6r*yt3i+x6i*yt3r + y6r*xt3i+y6i*xt3r; \
   aa[lda3_+14] += x7r*yt3r-x7i*yt3i + y7r*xt3r-y7i*xt3i; \
   aa[lda3_+15] += x7r*yt3i+x7i*yt3r + y7r*xt3i+y7i*xt3r; \
   aa[lda3_+16] += x8r*yt3r-x8i*yt3i + y8r*xt3r-y8i*xt3i; \
   aa[lda3_+17] += x8r*yt3i+x8i*yt3r + y8r*xt3i+y8i*xt3r; \
   aa[lda3_+18] += x9r*yt3r-x9i*yt3i + y9r*xt3r-y9i*xt3i; \
   aa[lda3_+19] += x9r*yt3i+x9i*yt3r + y9r*xt3i+y9i*xt3r; \
   aa[lda3_+20] += x10r*yt3r-x10i*yt3i + y10r*xt3r-y10i*xt3i; \
   aa[lda3_+21] += x10r*yt3i+x10i*yt3r + y10r*xt3i+y10i*xt3r; \
   aa[lda3_+22] += x11r*yt3r-x11i*yt3i + y11r*xt3r-y11i*xt3i; \
   aa[lda3_+23] += x11r*yt3i+x11i*yt3r + y11r*xt3i+y11i*xt3r; \
   aa[lda4_+8] += x4r*yt4r-x4i*yt4i + y4r*xt4r-y4i*xt4i; \
   aa[lda4_+9] = 0.0; \
   aa[lda4_+10] += x5r*yt4r-x5i*yt4i + y5r*xt4r-y5i*xt4i; \
   aa[lda4_+11] += x5r*yt4i+x5i*yt4r + y5r*xt4i+y5i*xt4r; \
   aa[lda4_+12] += x6r*yt4r-x6i*yt4i + y6r*xt4r-y6i*xt4i; \
   aa[lda4_+13] += x6r*yt4i+x6i*yt4r + y6r*xt4i+y6i*xt4r; \
   aa[lda4_+14] += x7r*yt4r-x7i*yt4i + y7r*xt4r-y7i*xt4i; \
   aa[lda4_+15] += x7r*yt4i+x7i*yt4r + y7r*xt4i+y7i*xt4r; \
   aa[lda4_+16] += x8r*yt4r-x8i*yt4i + y8r*xt4r-y8i*xt4i; \
   aa[lda4_+17] += x8r*yt4i+x8i*yt4r + y8r*xt4i+y8i*xt4r; \
   aa[lda4_+18] += x9r*yt4r-x9i*yt4i + y9r*xt4r-y9i*xt4i; \
   aa[lda4_+19] += x9r*yt4i+x9i*yt4r + y9r*xt4i+y9i*xt4r; \
   aa[lda4_+20] += x10r*yt4r-x10i*yt4i + y10r*xt4r-y10i*xt4i; \
   aa[lda4_+21] += x10r*yt4i+x10i*yt4r + y10r*xt4i+y10i*xt4r; \
   aa[lda4_+22] += x11r*yt4r-x11i*yt4i + y11r*xt4r-y11i*xt4i; \
   aa[lda4_+23] += x11r*yt4i+x11i*yt4r + y11r*xt4i+y11i*xt4r; \
   aa[lda5_+10] += x5r*yt5r-x5i*yt5i + y5r*xt5r-y5i*xt5i; \
   aa[lda5_+11] = 0.0; \
   aa[lda5_+12] += x6r*yt5r-x6i*yt5i + y6r*xt5r-y6i*xt5i; \
   aa[lda5_+13] += x6r*yt5i+x6i*yt5r + y6r*xt5i+y6i*xt5r; \
   aa[lda5_+14] += x7r*yt5r-x7i*yt5i + y7r*xt5r-y7i*xt5i; \
   aa[lda5_+15] += x7r*yt5i+x7i*yt5r + y7r*xt5i+y7i*xt5r; \
   aa[lda5_+16] += x8r*yt5r-x8i*yt5i + y8r*xt5r-y8i*xt5i; \
   aa[lda5_+17] += x8r*yt5i+x8i*yt5r + y8r*xt5i+y8i*xt5r; \
   aa[lda5_+18] += x9r*yt5r-x9i*yt5i + y9r*xt5r-y9i*xt5i; \
   aa[lda5_+19] += x9r*yt5i+x9i*yt5r + y9r*xt5i+y9i*xt5r; \
   aa[lda5_+20] += x10r*yt5r-x10i*yt5i + y10r*xt5r-y10i*xt5i; \
   aa[lda5_+21] += x10r*yt5i+x10i*yt5r + y10r*xt5i+y10i*xt5r; \
   aa[lda5_+22] += x11r*yt5r-x11i*yt5i + y11r*xt5r-y11i*xt5i; \
   aa[lda5_+23] += x11r*yt5i+x11i*yt5r + y11r*xt5i+y11i*xt5r; \
   aa[lda6_+12] += x6r*yt6r-x6i*yt6i + y6r*xt6r-y6i*xt6i; \
   aa[lda6_+13] = 0.0; \
   aa[lda6_+14] += x7r*yt6r-x7i*yt6i + y7r*xt6r-y7i*xt6i; \
   aa[lda6_+15] += x7r*yt6i+x7i*yt6r + y7r*xt6i+y7i*xt6r; \
   aa[lda6_+16] += x8r*yt6r-x8i*yt6i + y8r*xt6r-y8i*xt6i; \
   aa[lda6_+17] += x8r*yt6i+x8i*yt6r + y8r*xt6i+y8i*xt6r; \
   aa[lda6_+18] += x9r*yt6r-x9i*yt6i + y9r*xt6r-y9i*xt6i; \
   aa[lda6_+19] += x9r*yt6i+x9i*yt6r + y9r*xt6i+y9i*xt6r; \
   aa[lda6_+20] += x10r*yt6r-x10i*yt6i + y10r*xt6r-y10i*xt6i; \
   aa[lda6_+21] += x10r*yt6i+x10i*yt6r + y10r*xt6i+y10i*xt6r; \
   aa[lda6_+22] += x11r*yt6r-x11i*yt6i + y11r*xt6r-y11i*xt6i; \
   aa[lda6_+23] += x11r*yt6i+x11i*yt6r + y11r*xt6i+y11i*xt6r; \
   aa[lda7_+14] += x7r*yt7r-x7i*yt7i + y7r*xt7r-y7i*xt7i; \
   aa[lda7_+15] = 0.0; \
   aa[lda7_+16] += x8r*yt7r-x8i*yt7i + y8r*xt7r-y8i*xt7i; \
   aa[lda7_+17] += x8r*yt7i+x8i*yt7r + y8r*xt7i+y8i*xt7r; \
   aa[lda7_+18] += x9r*yt7r-x9i*yt7i + y9r*xt7r-y9i*xt7i; \
   aa[lda7_+19] += x9r*yt7i+x9i*yt7r + y9r*xt7i+y9i*xt7r; \
   aa[lda7_+20] += x10r*yt7r-x10i*yt7i + y10r*xt7r-y10i*xt7i; \
   aa[lda7_+21] += x10r*yt7i+x10i*yt7r + y10r*xt7i+y10i*xt7r; \
   aa[lda7_+22] += x11r*yt7r-x11i*yt7i + y11r*xt7r-y11i*xt7i; \
   aa[lda7_+23] += x11r*yt7i+x11i*yt7r + y11r*xt7i+y11i*xt7r; \
   aa[lda8_+16] += x8r*yt8r-x8i*yt8i + y8r*xt8r-y8i*xt8i; \
   aa[lda8_+17] = 0.0; \
   aa[lda8_+18] += x9r*yt8r-x9i*yt8i + y9r*xt8r-y9i*xt8i; \
   aa[lda8_+19] += x9r*yt8i+x9i*yt8r + y9r*xt8i+y9i*xt8r; \
   aa[lda8_+20] += x10r*yt8r-x10i*yt8i + y10r*xt8r-y10i*xt8i; \
   aa[lda8_+21] += x10r*yt8i+x10i*yt8r + y10r*xt8i+y10i*xt8r; \
   aa[lda8_+22] += x11r*yt8r-x11i*yt8i + y11r*xt8r-y11i*xt8i; \
   aa[lda8_+23] += x11r*yt8i+x11i*yt8r + y11r*xt8i+y11i*xt8r; \
   aa[lda9_+18] += x9r*yt9r-x9i*yt9i + y9r*xt9r-y9i*xt9i; \
   aa[lda9_+19] = 0.0; \
   aa[lda9_+20] += x10r*yt9r-x10i*yt9i + y10r*xt9r-y10i*xt9i; \
   aa[lda9_+21] += x10r*yt9i+x10i*yt9r + y10r*xt9i+y10i*xt9r; \
   aa[lda9_+22] += x11r*yt9r-x11i*yt9i + y11r*xt9r-y11i*xt9i; \
   aa[lda9_+23] += x11r*yt9i+x11i*yt9r + y11r*xt9i+y11i*xt9r; \
   aa[lda10_+20] += x10r*yt10r-x10i*yt10i + y10r*xt10r-y10i*xt10i; \
   aa[lda10_+21] = 0.0; \
   aa[lda10_+22] += x11r*yt10r-x11i*yt10i + y11r*xt10r-y11i*xt10i; \
   aa[lda10_+23] += x11r*yt10i+x11i*yt10r + y11r*xt10i+y11i*xt10r; \
   aa[lda11_+22] += x11r*yt11r-x11i*yt11i + y11r*xt11r-y11i*xt11i; \
   aa[lda11_+23] = 0.0; \
}

#endif
