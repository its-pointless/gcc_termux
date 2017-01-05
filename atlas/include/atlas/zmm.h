#ifndef ZMM_H
   #define ZMM_H

   #define ATL_mmNOMULADD
   #define ATL_mmLAT 4
   #define ATL_mmMU  4
   #define ATL_mmNU  4
   #define ATL_mmKU  2
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
void ATL_zJIK32x32x32TN32x32x0_a1_b0(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);
void ATL_zJIK32x32x32TN32x32x0_a1_b1(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);
void ATL_zJIK32x32x32TN32x32x0_a1_bX(const int M, const int N, const int K, const TYPE alpha, const TYPE *A, const int lda, const TYPE *B, const int ldb, const TYPE beta, TYPE *C, const int ldc);

   #define NBmm_b1(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, ATL_rnone, C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_b1(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, ATL_rone, (C_)+1, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define NBmm_b0(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_zJIK32x32x32TN32x32x0_a1_b0(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, ATL_rzero, C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_b0(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, ATL_rzero, (C_)+1, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define NBmm_bX(m_, n_, k_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_), ldb_, -(be_), C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_), lda_, (B_)+NBNB, ldb_, be_, (C_)+1, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_bX(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_)+NBNB, ldb_, ATL_rnone, C_, ldc_); \
   ATL_zJIK32x32x32TN32x32x0_a1_b1(m_, n_, k_, al_, (A_)+NBNB, lda_, (B_), ldb_, ATL_rone, (C_)+1, ldc_); \
   }
   #define rNBmm_b1 ATL_dJIK32x32x32TN32x32x0_a1_b1
   #define rNBmm_b0 ATL_dJIK32x32x32TN32x32x0_a1_b0
   #define rNBmm_bX ATL_dJIK32x32x32TN32x32x0_a1_bX

#endif
