#ifndef ATLAS_CMVN_L1_H
#define ATLAS_CMVN_L1_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_cmvnk__900002(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_cmvnk__900002_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   *minM = 8;   *minN = 12;
   *mu = 8;     *nu = 12;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 1720;
   *mvk_b0 = ATL_cmvnk__900002_b0;
   *DOTBASED = 0;
   return(ATL_cmvnk__900002);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 64; *(nb_) = 12; }

#endif  /* end protection around header file contents */
