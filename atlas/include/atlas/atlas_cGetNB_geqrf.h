#ifndef ATL_cGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,128,256,320,384,576,896,1216
 * N : 25,128,256,320,384,576,896,1216
 * NB : 12,64,20,64,64,64,128,128
 */
#define ATL_cGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 76) (nb_) = 12; \
   else if ((n_) < 192) (nb_) = 64; \
   else if ((n_) < 288) (nb_) = 20; \
   else if ((n_) < 736) (nb_) = 64; \
   else (nb_) = 128; \
}


#endif    /* end ifndef ATL_cGetNB_geqrf */
