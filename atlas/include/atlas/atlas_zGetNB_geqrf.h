#ifndef ATL_zGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,64,96,128,256,512,768,896,960,1024
 * N : 25,64,96,128,256,512,768,896,960,1024
 * NB : 12,12,32,32,32,32,32,32,32,64
 */
#define ATL_zGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 80) (nb_) = 12; \
   else if ((n_) < 992) (nb_) = 32; \
   else (nb_) = 64; \
}


#endif    /* end ifndef ATL_zGetNB_geqrf */
