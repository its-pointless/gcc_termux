#ifndef ATL_sGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,192,448,960,1984
 * N : 25,192,448,960,1984
 * NB : 12,64,64,64,64
 */
#define ATL_sGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 108) (nb_) = 12; \
   else (nb_) = 64; \
}


#endif    /* end ifndef ATL_sGetNB_geqrf */
