#ifndef ATLAS_TYPE_H
#define ATLAS_TYPE_H

#define ATL_isize ((size_t)4)
#define ATL_ssize ((size_t)4)
#define ATL_dsize ((size_t)8)
#define ATL_csize ((size_t)8)
#define ATL_zsize ((size_t)16)
#define ATL_iMulBySize(N_) (((((size_t)(N_))) << 2))
#define ATL_sMulBySize(N_) (((((size_t)(N_))) << 2))
#define ATL_dMulBySize(N_) (((((size_t)(N_))) << 3))
#define ATL_cMulBySize(N_) (((((size_t)(N_))) << 3))
#define ATL_zMulBySize(N_) (((((size_t)(N_))) << 4))
#define ATL_ishift 2
#define ATL_iDivBySize(N_) ((N_) >> 2)
#define ATL_sshift 2
#define ATL_cshift 3
#define ATL_sDivBySize(N_) ((N_) >> 2)
#define ATL_cDivBySize(N_) ((N_) >> 3)
#define ATL_dshift 3
#define ATL_zshift 4
#define ATL_dDivBySize(N_) ((N_) >> 3)
#define ATL_zDivBySize(N_) ((N_) >> 4)

#endif
