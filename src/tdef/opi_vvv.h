#include "common.h"

#include <stdint.h>

#define TEST_OPI_VVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opi_vvv<type_ret, type2, type1>(op ## _vv_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _vec)

#define TEST_OPI_VVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul "_m" " ...\n"); \
test_opi_vvv_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _m_vec)

#define TEST_OPI_VVV_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VVV, op)

#define TEST_OPI_VVV_III_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_III_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_UUU_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(TEST_OPI_VVV, op)
#define TEST_OPI_VVV_IUI_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(TEST_OPI_VVV, op)

#define TEST_OPI_VVV_M_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VVV_M, op)

#define TEST_OPI_VVV_III_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_III_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_UUU_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2( TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(  TEST_OPI_VVV_M, op)
#define TEST_OPI_VVV_IUI_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(  TEST_OPI_VVV_M, op)