#include <stdint.h>


#define TEST_OPF_VVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opf_vvv<type_ret, type2, type1>(op ## _vv_ref<type_ret,type2,type1>, op ## _vv_## type_ret ## lmul ## _vec)

#define TEST_OPF_VVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul "_m" " ...\n"); \
test_opf_vvv_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret,type2,type1>, op ## _vv_## type_ret ## lmul ## _m_vec)

#define TEST_OPF_VVV_COMMON_GROUP_MF2(test, op) \
test(op, f32,  f32,  f32,  mf2); \

#define TEST_OPF_VVV_COMMON_GROUP_M1(test, op)  \
test(op, f32,  f32,  f32,  m1);  \
test(op, f64,  f64,  f64,  m1);  \

#define TEST_OPF_VVV_COMMON_GROUP_M2(test, op)  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f64,  f64,  f64,  m2);  \

#define TEST_OPF_VVV_COMMON_GROUP_M4(test, op)  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f64,  f64,  f64,  m4);  \

#define TEST_OPF_VVV_COMMON_GROUP_M8(test, op)  \
test(op, f32,  f32,  f32,  m8);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VVV_COMMON_F32_GROUP(test, op) \
test(op, f32,  f32,  f32,  mf2); \
test(op, f32,  f32,  f32,  m1);  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f32,  f32,  f32,  m8);  \

#define TEST_OPF_VVV_COMMON_F64_GROUP(test, op) \
test(op, f64,  f64,  f64,  m1);  \
test(op, f64,  f64,  f64,  m2);  \
test(op, f64,  f64,  f64,  m4);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VVV_COMMON_GROUP(test, op) \
TEST_OPF_VVV_COMMON_GROUP_MF2(test, op) \
TEST_OPF_VVV_COMMON_GROUP_M1(test, op) \
TEST_OPF_VVV_COMMON_GROUP_M2(test, op) \
TEST_OPF_VVV_COMMON_GROUP_M4(test, op) \
TEST_OPF_VVV_COMMON_GROUP_M8(test, op) \

#define TEST_OPF_VVV_GROUP(op)     TEST_OPF_VVV_COMMON_GROUP(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_GROUP_MF2(op) TEST_OPF_VVV_COMMON_GROUP_MF2(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_GROUP_M1(op)  TEST_OPF_VVV_COMMON_GROUP_M1(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_GROUP_M2(op)  TEST_OPF_VVV_COMMON_GROUP_M2(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_GROUP_M4(op)  TEST_OPF_VVV_COMMON_GROUP_M4(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_GROUP_M8(op)  TEST_OPF_VVV_COMMON_GROUP_M8(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_F32_GROUP(op) TEST_OPF_VVV_COMMON_F32_GROUP(TEST_OPF_VVV, op)
#define TEST_OPF_VVV_F64_GROUP(op) TEST_OPF_VVV_COMMON_F64_GROUP(TEST_OPF_VVV, op)

#define TEST_OPF_VVV_M_GROUP(op)     TEST_OPF_VVV_COMMON_GROUP    (TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_M_GROUP_MF2(op) TEST_OPF_VVV_COMMON_GROUP_MF2(TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_M_GROUP_M1(op)  TEST_OPF_VVV_COMMON_GROUP_M1 (TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_M_GROUP_M2(op)  TEST_OPF_VVV_COMMON_GROUP_M2 (TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_M_GROUP_M4(op)  TEST_OPF_VVV_COMMON_GROUP_M4 (TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_M_GROUP_M8(op)  TEST_OPF_VVV_COMMON_GROUP_M8 (TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_F32_M_GROUP(op) TEST_OPF_VVV_COMMON_F32_GROUP(TEST_OPF_VVV_M, op)
#define TEST_OPF_VVV_F64_M_GROUP(op) TEST_OPF_VVV_COMMON_F64_GROUP(TEST_OPF_VVV_M, op)
