#ifndef DMM_H
   #define DMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 3
   #define ATL_mmMU  4
   #define ATL_mmNU  5
   #define ATL_mmKU  1
   #define MB 32
   #define NB 32
   #define KB 32
   #define NBNB 1024
   #define MBNB 1024
   #define MBKB 1024
   #define NBKB 1024
   #define NB2 64
   #define NBNB2 2048

   #define ATL_MulByNB(N_) ((N_) << 5)
   #define ATL_DivByNB(N_) ((N_) >> 5)
   #define ATL_MulByNBNB(N_) ((N_) << 10)

#endif
