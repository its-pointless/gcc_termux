#ifndef ATL_dGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,192,416,832,1664
 * N : 25,192,416,832,1664
 * NB : 12,32,32,32,64
 */
#define ATL_dGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 108) (nb_) = 12; \
   else if ((n_) < 1248) (nb_) = 32; \
   else (nb_) = 64; \
}


#endif    /* end ifndef ATL_dGetNB_geqrf */
