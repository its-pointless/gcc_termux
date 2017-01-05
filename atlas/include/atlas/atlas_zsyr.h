/*
 * This file generated on line 432 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_ZSYR1_H
   #define ATLAS_ZSYR1_H

#include "atlas_zr1.h"

#define ATL_s1U_NU 1

#define ATL_s1L_NU 1

#define ATL_GetPartS1 ATL_GetPartR1
#define ATL_MIN_RESTRICTED_M 0
#define ATL_URGERK ATL_zgerk__2
#define ATL_GENGERK ATL_zgerk__2

#define ATL_HER1U_nu(A_, lda_, x_, xt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0; \
   const TYPE x0r=*(x_), x0i=(x_)[1]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1]; \
   aa[lda0_+0] += x0r*xt0r-x0i*xt0i; \
   aa[lda0_+1] = 0.0; \
}
#define ATL_HER1L_nu(A_, lda_, x_, xt_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0; \
   const TYPE x0r=*(x_), x0i=(x_)[1]; \
   const TYPE xt0r=*(xt_), xt0i=(xt_)[1]; \
   aa[lda0_+0] += x0r*xt0r-x0i*xt0i; \
   aa[lda0_+1] = 0.0; \
}

#endif
