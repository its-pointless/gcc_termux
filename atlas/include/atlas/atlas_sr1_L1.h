#ifndef ATLAS_SR1_L1_H
#define ATLAS_SR1_L1_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_sgerk__1
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 0;   *minN = 0;
   *mu = 16;     *nu = 1;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 0;
   *CacheElts = 3194;
   return(ATL_sgerk__1);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 784; (nb_) = 1; }

#endif  /* end protection around header file contents */
