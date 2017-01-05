#ifndef ATLAS_CR2_L0_H
#define ATLAS_CR2_L0_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const float*, const float*, const float*,
    const float*, float*, ATL_CINT);
void ATL_cger2k__900001
   (ATL_CINT, ATL_CINT, const float*, const float*, const float*,
    const float*, float*, ATL_CINT);

static ATL_r2kern_t ATL_GetR2Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 1;   *minN = 2;
   *mu = 1;     *nu = 2;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 7168;
   return(ATL_cger2k__900001);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 1193; (nb_) = 2; }

#endif  /* end protection around header file contents */
