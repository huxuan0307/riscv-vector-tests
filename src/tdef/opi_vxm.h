#include "common.h"

#include <stdint.h>

#define TEST_OPI_VXM(op, type, lmul) \
printf("\ntest " #op "_vx_" #type #lmul " ...\n"); \
test_opi_vxm<type, type>(op ## _vx_ref<type, type>, op ## _vx_## type ## lmul ## _vec)

#define TEST_OPI_VXM_M(op, type, lmul) \
printf("\ntest " #op "_vx_" #type #lmul "_m " " ...\n"); \
test_opi_vxm_m<type, type>(op ## _vx_m_ref<type, type>, op ## _vx_## type ## lmul ## _m_vec)

#define TEST_OPI_VXM_GROUP(op)          TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP(op)       TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP(op)       TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_MF8(op)   TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_MF4(op)   TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_MF2(op)   TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_M1(op)    TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_M2(op)    TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_M4(op)    TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_II_GROUP_M8(op)    TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_MF8(op)   TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_MF4(op)   TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_MF2(op)   TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_M1(op)    TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_M2(op)    TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_M4(op)    TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VXM, op)
#define TEST_OPI_VXM_UU_GROUP_M8(op)    TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VXM, op)

#define TEST_OPI_VXM_M_GROUP(op)          TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP(op)       TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP(op)       TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_MF8(op)   TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_MF4(op)   TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_MF2(op)   TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_M1(op)    TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_M2(op)    TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_M4(op)    TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_II_M_GROUP_M8(op)    TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_MF8(op)   TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_MF4(op)   TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_MF2(op)   TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_M1(op)    TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_M2(op)    TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_M4(op)    TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VXM_M, op)
#define TEST_OPI_VXM_UU_M_GROUP_M8(op)    TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VXM_M, op)