#ifndef ATLAS_SMVT_L1_H
#define ATLAS_SMVT_L1_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_smvtk__900003(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvtk__900003_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVTKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, 
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 2;   *minN = 2;
   *mu = 2;     *nu = 2;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 3112;
   *mvk_b0 = ATL_smvtk__900003_b0;
   return(ATL_smvtk__900003);
}

#define ATL_GetPartMVT(A_, lda_, mb_, nb_) { *(mb_) = 518; *(nb_) = 2; }

#endif  /* end protection around header file contents */
