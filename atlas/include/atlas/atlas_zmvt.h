#ifndef ATLAS_ZMVT_L0_H
#define ATLAS_ZMVT_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

#endif
void ATL_zmvtk__900001(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_zmvtk__900001_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

static ATL_mvkern_t ATL_GetMVTKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, 
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 4;   *minN = 4;
   *mu = 4;     *nu = 4;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 5120;
   *mvk_b0 = ATL_zmvtk__900001_b0;
   return(ATL_zmvtk__900001);
}

#define ATL_GetPartMVT(A_, lda_, mb_, nb_) { *(mb_) = 508; *(nb_) = 4; }

#endif  /* end protection around header file contents */
