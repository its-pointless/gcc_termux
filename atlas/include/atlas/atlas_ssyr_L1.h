/*
 * This file generated on line 432 of /data/data/com.termux/files/home/datlas/thread/../ATLAS//tune/blas/ger/r1hgen.c
 */
#ifndef ATLAS_SSYR1_L1_H
   #define ATLAS_SSYR1_L1_H

#include "atlas_sr1_L1.h"

#define ATL_s1U_NU 1

#define ATL_s1L_NU 1
#define ATL_MIN_RESTRICTED_M 0
#define ATL_URGERK ATL_sgerk__1
#define ATL_GENGERK ATL_sgerk__1

#define ATL_SYR1U_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0; \
   const TYPE x0_=*(x_); \
   const TYPE y0_=*(y_); \
   aa[lda0_+0] += x0_*y0_; \
}
#define ATL_SYR1L_nu(A_, lda_, x_, y_) \
{ \
   TYPE *aa=(A_); \
   ATL_CINT lda0_ = 0; \
   const TYPE x0_=*(x_); \
   const TYPE y0_=*(y_); \
   aa[lda0_+0] += x0_*y0_; \
}

#endif
