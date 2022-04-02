#ifndef __TDEF_OPF_VFM_H__
#define __TDEF_OPF_VFM_H__

#include "common.h"
#include "opi_vxm.h"

#define test_opf_vfm test_opi_vxm
#define test_opf_vfm_m test_opi_vxm_m

#define TEST_OPF_VFM(op, type, lmul) \
printf("\ntest " #op "_vf_" #type #lmul " ...\n"); \
test_opf_vfm<type, type>(op ## _vf_ref<type, type>, op ## _vf_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPF_VFM_M(op, type, lmul) \
printf("\ntest " #op "_vf_" #type #lmul "_m " " ...\n"); \
test_opf_vfm_m<type, type>(op ## _vf_m_ref<type, type>, op ## _vf_## type ## lmul ## _m_vec, TEST_LENGTH)

#define TEST_OPF_VFM_COMMON_GROUP_MF2(test, op) \
test(op, f32, mf2); \

#define TEST_OPF_VFM_COMMON_GROUP_M1(test, op) \
test(op, f32, m1); \
test(op, f64, m1); \

#define TEST_OPF_VFM_COMMON_GROUP_M2(test, op) \
test(op, f32, m2); \
test(op, f64, m2); \

#define TEST_OPF_VFM_COMMON_GROUP_M4(test, op) \
test(op, f32, m4); \
test(op, f64, m4); \

#define TEST_OPF_VFM_COMMON_GROUP_M8(test, op) \
test(op, f32, m8); \
test(op, f64, m8); \

#define TEST_OPF_VFM_COMMON_F32_GROUP(test, op) \
test(op, f32, mf2); \
test(op, f32, m1);  \
test(op, f32, m2);  \
test(op, f32, m4);  \
test(op, f32, m8);  \

#define TEST_OPF_VFM_COMMON_F64_GROUP(test, op) \
test(op, f64, m1);  \
test(op, f64, m2);  \
test(op, f64, m4);  \
test(op, f64, m8);  \

#define TEST_OPF_VFM_COMMON_GROUP(test, op) \
TEST_OPF_VFM_COMMON_GROUP_MF2(test, op) \
TEST_OPF_VFM_COMMON_GROUP_M1(test, op) \
TEST_OPF_VFM_COMMON_GROUP_M2(test, op) \
TEST_OPF_VFM_COMMON_GROUP_M4(test, op) \
TEST_OPF_VFM_COMMON_GROUP_M8(test, op) \

#define TEST_OPF_VFM_GROUP(op)      TEST_OPF_VFM_COMMON_GROUP(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_GROUP_MF2(op)  TEST_OPF_VFM_COMMON_GROUP_MF2(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_GROUP_M1(op)   TEST_OPF_VFM_COMMON_GROUP_M1(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_GROUP_M2(op)   TEST_OPF_VFM_COMMON_GROUP_M2(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_GROUP_M4(op)   TEST_OPF_VFM_COMMON_GROUP_M4(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_GROUP_M8(op)   TEST_OPF_VFM_COMMON_GROUP_M8(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_F32_GROUP(op)  TEST_OPF_VFM_COMMON_F32_GROUP(TEST_OPF_VFM, op)
#define TEST_OPF_VFM_F64_GROUP(op)  TEST_OPF_VFM_COMMON_F64_GROUP(TEST_OPF_VFM, op)

#define TEST_OPF_VFM_M_GROUP(op)      TEST_OPF_VFM_COMMON_GROUP(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_GROUP_MF2(op)  TEST_OPF_VFM_COMMON_GROUP_MF2(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_GROUP_M1(op)   TEST_OPF_VFM_COMMON_GROUP_M1(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_GROUP_M2(op)   TEST_OPF_VFM_COMMON_GROUP_M2(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_GROUP_M4(op)   TEST_OPF_VFM_COMMON_GROUP_M4(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_GROUP_M8(op)   TEST_OPF_VFM_COMMON_GROUP_M8(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_F32_GROUP(op)  TEST_OPF_VFM_COMMON_F32_GROUP(TEST_OPF_VFM_M, op)
#define TEST_OPF_VFM_M_F64_GROUP(op)  TEST_OPF_VFM_COMMON_F64_GROUP(TEST_OPF_VFM_M, op)

#define TEST_OPF_VFM_ALL() \
TEST_OPF_VFM_GROUP(vmfeq); \
TEST_OPF_VFM_GROUP(vmflt); \
TEST_OPF_VFM_GROUP(vmfle); \
TEST_OPF_VFM_GROUP(vmfne); \
TEST_OPF_VFM_GROUP(vmfgt); \
TEST_OPF_VFM_GROUP(vmfge); \

#define TEST_OPF_VFM_M_ALL() \
TEST_OPF_VFM_M_GROUP(vmfeq); \
TEST_OPF_VFM_M_GROUP(vmflt); \
TEST_OPF_VFM_M_GROUP(vmfle); \
TEST_OPF_VFM_M_GROUP(vmfne); \
TEST_OPF_VFM_M_GROUP(vmfgt); \
TEST_OPF_VFM_M_GROUP(vmfge); \

#endif
