#ifndef __TDEF_OPI_VVVV_H__
#define __TDEF_OPI_VVVV_H__

#include "common.h"
#include "opi_vvv.h"

#define test_opi_vvvv test_opi_vvv
#define test_opi_vvvv_m test_opi_vvv_m

#define TEST_OPI_VVVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opi_vvvv<type_ret, type2, type1>(op ## _vv_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VVVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul "_m" " ...\n"); \
test_opi_vvvv_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _m_vec, TEST_LENGTH)

#define TEST_OPI_VVVV_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VVVV, op)

#define TEST_OPI_VVVV_III_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_III_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_UUU_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(TEST_OPI_VVVV, op)
#define TEST_OPI_VVVV_IUI_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(TEST_OPI_VVVV, op)

#define TEST_OPI_VVVV_M_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VVVV_M, op)

#define TEST_OPI_VVVV_III_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_III_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_UUU_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2( TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(  TEST_OPI_VVVV_M, op)
#define TEST_OPI_VVVV_IUI_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(  TEST_OPI_VVVV_M, op)

#define TEST_OPI_VVVV_ALL() \
TEST_OPI_VVVV_GROUP(vmacc) \
TEST_OPI_VVVV_GROUP(vnmsac) \
TEST_OPI_VVVV_GROUP(vmadd) \
TEST_OPI_VVVV_GROUP(vnmsub) \

#define TEST_OPI_VVVV_M_ALL() \
TEST_OPI_VVVV_M_GROUP(vmacc) \
TEST_OPI_VVVV_M_GROUP(vnmsac) \
TEST_OPI_VVVV_M_GROUP(vmadd) \
TEST_OPI_VVVV_M_GROUP(vnmsub) \

#endif
