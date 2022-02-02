#include "common.h"

#include <stdint.h>

#define TEST_OPI_VVMM(op, type, lmul) \
printf("\ntest " #op "_vvm_" #type #lmul " ...\n"); \
test_opi_vvmm<uint8_t, type, type>(op ## _vvm_ref<type, type>, op ## _vvm_## type ## lmul ## _vec)

#define TEST_OPI_VVMM_GROUP(op)         TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP(op)      TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP(op)      TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF8(op)  TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF4(op)  TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF2(op)  TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M1(op)   TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M2(op)   TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M4(op)   TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M8(op)   TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF8(op)  TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF4(op)  TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF2(op)  TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M1(op)   TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M2(op)   TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M4(op)   TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M8(op)   TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VVMM, op)
