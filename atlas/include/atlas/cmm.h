#ifndef CMM_H
   #define CMM_H

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
void ATL_cJIK64x64x64TN64x64x0_a1_b0(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);
void ATL_cJIK64x64x64TN64x64x0_a1_b1(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);
void ATL_cJIK64x64x64TN64x64x0_a1_bX(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);

   #define NBmm_b1(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, ATL_rnone, C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_b1(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, ATL_rone, (C_)+1, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define NBmm_b0(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_cJIK64x64x64TN64x64x0_a1_b0(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, ATL_rzero, C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_b0(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, ATL_rzero, (C_)+1, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define NBmm_bX(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, -(be_), C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, be_, (C_)+1, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_cJIK64x64x64TN64x64x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define rNBmm_b1 ATL_sJIK64x64x64TN64x64x0_a1_b1
   #define rNBmm_b0 ATL_sJIK64x64x64TN64x64x0_a1_b0
   #define rNBmm_bX ATL_sJIK64x64x64TN64x64x0_a1_bX

#endif
