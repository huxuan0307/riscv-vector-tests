#ifndef __TDEF_OPF_VFV_H__
#define __TDEF_OPF_VFV_H__

#include "common.h"
#include "opi_vxv.h"

#define test_opf_vfv test_opi_vxv
#define test_opf_vfv_m test_opi_vxv_m

#define TEST_OPF_VFV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vf_" #type_ret #lmul " ...\n"); \
test_opf_vfv<type_ret, type2, type1>(op ## _vf_ref<type_ret,type2,type1>, op ## _vf_## type_ret ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPF_VFV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vf_" #type_ret #lmul "_m" " ...\n"); \
test_opf_vfv_m<type_ret, type2, type1>(op ## _vf_m_ref<type_ret,type2,type1>, op ## _vf_## type_ret ## lmul ## _m_vec, TEST_LENGTH)

#define TEST_OPF_VFV_COMMON_GROUP_MF2(test, op) \
test(op, f32,  f32,  f32,  mf2); \

#define TEST_OPF_VFV_COMMON_GROUP_M1(test, op)  \
test(op, f32,  f32,  f32,  m1);  \
test(op, f64,  f64,  f64,  m1);  \

#define TEST_OPF_VFV_COMMON_GROUP_M2(test, op)  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f64,  f64,  f64,  m2);  \

#define TEST_OPF_VFV_COMMON_GROUP_M4(test, op)  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f64,  f64,  f64,  m4);  \

#define TEST_OPF_VFV_COMMON_GROUP_M8(test, op)  \
test(op, f32,  f32,  f32,  m8);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VFV_COMMON_F32_GROUP(test, op) \
test(op, f32,  f32,  f32,  mf2); \
test(op, f32,  f32,  f32,  m1);  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f32,  f32,  f32,  m8);  \

#define TEST_OPF_VFV_COMMON_F64_GROUP(test, op) \
test(op, f64,  f64,  f64,  m1);  \
test(op, f64,  f64,  f64,  m2);  \
test(op, f64,  f64,  f64,  m4);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VFV_COMMON_GROUP(test, op) \
TEST_OPF_VFV_COMMON_GROUP_MF2(test, op) \
TEST_OPF_VFV_COMMON_GROUP_M1(test, op) \
TEST_OPF_VFV_COMMON_GROUP_M2(test, op) \
TEST_OPF_VFV_COMMON_GROUP_M4(test, op) \
TEST_OPF_VFV_COMMON_GROUP_M8(test, op) \

#define TEST_OPF_VFV_GROUP(op)     TEST_OPF_VFV_COMMON_GROUP(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_GROUP_MF2(op) TEST_OPF_VFV_COMMON_GROUP_MF2(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_GROUP_M1(op)  TEST_OPF_VFV_COMMON_GROUP_M1(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_GROUP_M2(op)  TEST_OPF_VFV_COMMON_GROUP_M2(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_GROUP_M4(op)  TEST_OPF_VFV_COMMON_GROUP_M4(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_GROUP_M8(op)  TEST_OPF_VFV_COMMON_GROUP_M8(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_F32_GROUP(op) TEST_OPF_VFV_COMMON_F32_GROUP(TEST_OPF_VFV, op)
#define TEST_OPF_VFV_F64_GROUP(op) TEST_OPF_VFV_COMMON_F64_GROUP(TEST_OPF_VFV, op)

#define TEST_OPF_VFV_M_GROUP(op)     TEST_OPF_VFV_COMMON_GROUP    (TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_M_GROUP_MF2(op) TEST_OPF_VFV_COMMON_GROUP_MF2(TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_M_GROUP_M1(op)  TEST_OPF_VFV_COMMON_GROUP_M1 (TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_M_GROUP_M2(op)  TEST_OPF_VFV_COMMON_GROUP_M2 (TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_M_GROUP_M4(op)  TEST_OPF_VFV_COMMON_GROUP_M4 (TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_M_GROUP_M8(op)  TEST_OPF_VFV_COMMON_GROUP_M8 (TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_F32_M_GROUP(op) TEST_OPF_VFV_COMMON_F32_GROUP(TEST_OPF_VFV_M, op)
#define TEST_OPF_VFV_F64_M_GROUP(op) TEST_OPF_VFV_COMMON_F64_GROUP(TEST_OPF_VFV_M, op)

#define TEST_OPF_VFV_ALL() \
TEST_OPF_VFV_GROUP(vfadd) \
TEST_OPF_VFV_GROUP(vfsub) \
TEST_OPF_VFV_GROUP(vfrsub) \
TEST_OPF_VFV_GROUP(vfmul) \
TEST_OPF_VFV_GROUP(vfdiv) \
TEST_OPF_VFV_GROUP(vfrdiv) \
TEST_OPF_VFV_GROUP(vfmax) \
TEST_OPF_VFV_GROUP(vfmin) \
TEST_OPF_VFV_GROUP(vfsgnj) \
TEST_OPF_VFV_GROUP(vfsgnjn) \
TEST_OPF_VFV_GROUP(vfsgnjx) \

#define TEST_OPF_VFV_M_ALL() \
TEST_OPF_VFV_M_GROUP(vfadd) \
TEST_OPF_VFV_M_GROUP(vfsub) \
TEST_OPF_VFV_M_GROUP(vfrsub) \
TEST_OPF_VFV_M_GROUP(vfmul) \
TEST_OPF_VFV_M_GROUP(vfdiv) \
TEST_OPF_VFV_M_GROUP(vfrdiv) \
TEST_OPF_VFV_M_GROUP(vfmax) \
TEST_OPF_VFV_M_GROUP(vfmin) \
TEST_OPF_VFV_M_GROUP(vfsgnj) \
TEST_OPF_VFV_M_GROUP(vfsgnjn) \
TEST_OPF_VFV_M_GROUP(vfsgnjx) \

#endif
