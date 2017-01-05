#ifndef ATLAS_DMVT_L2_H
#define ATLAS_DMVT_L2_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

#endif
void ATL_dmvtk__900003(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__900003_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

static ATL_mvkern_t ATL_GetMVTKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, 
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 8;   *minN = 12;
   *mu = 8;     *nu = 12;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 9216;
   *mvk_b0 = ATL_dmvtk__900003_b0;
   return(ATL_dmvtk__900003);
}

#define ATL_GetPartMVT(A_, lda_, mb_, nb_) { *(mb_) = 352; *(nb_) = 12; }

#endif  /* end protection around header file contents */
