#ifndef ATLAS_CMVT_L0_H
#define ATLAS_CMVT_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_cmvtk__1(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_cmvtk__1_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVTKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, 
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 0;   *minN = 0;
   *mu = 16;     *nu = 1;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 0;
   *CacheElts = 10240;
   *mvk_b0 = ATL_cmvtk__1_b0;
   return(ATL_cmvtk__1);
}

#define ATL_GetPartMVT(A_, lda_, mb_, nb_) { *(mb_) = 2544; *(nb_) = 1; }

#endif  /* end protection around header file contents */
