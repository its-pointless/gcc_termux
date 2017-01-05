#ifndef ATLAS_ZR2_L2_H
#define ATLAS_ZR2_L2_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__900003
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);

static ATL_r2kern_t ATL_GetR2Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 16;   *minN = 4;
   *mu = 16;     *nu = 4;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 2048;
   return(ATL_zger2k__900003);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 192; (nb_) = 4; }

#endif  /* end protection around header file contents */
