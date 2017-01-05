#ifndef ATLAS_ZR1_L0_H
#define ATLAS_ZR1_L0_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_zgerk__2
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 0;   *minN = 0;
   *mu = 2;     *nu = 1;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 0;
   *CacheElts = 901;
   return(ATL_zgerk__2);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 224; (nb_) = 1; }

#endif  /* end protection around header file contents */
