#ifndef ATLAS_DR1_L2_H
#define ATLAS_DR1_L2_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_dgerk__900003
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 8;   *minN = 12;
   *mu = 8;     *nu = 12;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 8192;
   return(ATL_dgerk__900003);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 312; (nb_) = 12; }

#endif  /* end protection around header file contents */
