#ifndef SMM_H
   #define SMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 3
   #define ATL_mmMU  4
   #define ATL_mmNU  2
   #define ATL_mmKU  8
   #define MB 64
   #define NB 64
   #define KB 64
   #define NBNB 4096
   #define MBNB 4096
   #define MBKB 4096
   #define NBKB 4096
   #define NB2 128
   #define NBNB2 8192

   #define ATL_MulByNB(N_) ((N_) << 6)
   #define ATL_DivByNB(N_) ((N_) >> 6)
   #define ATL_MulByNBNB(N_) ((N_) << 12)
   #define NBmm ATL_sJIK64x64x64TN64x64x0_a1_b1
   #define NBmm_b1 ATL_sJIK64x64x64TN64x64x0_a1_b1
   #define NBmm_b0 ATL_sJIK64x64x64TN64x64x0_a1_b0
   #define NBmm_bX ATL_sJIK64x64x64TN64x64x0_a1_bX

#endif
