#ifndef ATLAS_CMVN_L0_H
#define ATLAS_CMVN_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_cmvnk__1(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_cmvnk__1_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 0;   *minN = 0;
   *mu = 1;     *nu = 16;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 0;
   *CacheElts = 0;
   *mvk_b0 = ATL_cmvnk__1_b0;
   *DOTBASED = 0;
   return(ATL_cmvnk__1);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 0; *(nb_) = 0; }

#endif  /* end protection around header file contents */
