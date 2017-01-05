#ifndef ATLAS_DR1_L1_H
#define ATLAS_DR1_L1_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_dgerk__900002
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 8;   *minN = 20;
   *mu = 8;     *nu = 20;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 1024;
   return(ATL_dgerk__900002);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 16; (nb_) = 20; }

#endif  /* end protection around header file contents */
