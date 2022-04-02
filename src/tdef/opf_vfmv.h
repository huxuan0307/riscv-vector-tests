#ifndef __TDEF_OPF_VFMV_H__
#define __TDEF_OPF_VFMV_H__

#include "common.h"
#include "opi_vxmv.h"

#define test_opf_vfmv test_opi_vxmv

#define TEST_OPF_VFMV(op, type, lmul) \
printf("\ntest " #op "_vfm_" #type #lmul " ...\n"); \
test_opf_vfmv<type, type, type>(op ## _vfm_ref<type, type, type>, op ## _vfm_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPF_VFMV_GROUP_MF2(test, op) \
test(op, f32, mf2); \

#define TEST_OPF_VFMV_GROUP_M1(test, op) \
test(op, f32, m1); \
test(op, f64, m1); \

#define TEST_OPF_VFMV_GROUP_M2(test, op) \
test(op, f32, m2); \
test(op, f64, m2); \

#define TEST_OPF_VFMV_GROUP_M4(test, op) \
test(op, f32, m4); \
test(op, f64, m4); \

#define TEST_OPF_VFMV_GROUP_M8(test, op) \
test(op, f32, m8); \
test(op, f64, m8); \

#define TEST_OPF_VFMV_F32_GROUP(test, op) \
test(op, f32, mf2); \
test(op, f32, m1);  \
test(op, f32, m2);  \
test(op, f32, m4);  \
test(op, f32, m8);  \

#define TEST_OPF_VFMV_F64_GROUP(test, op) \
test(op, f64, m1);  \
test(op, f64, m2);  \
test(op, f64, m4);  \
test(op, f64, m8);  \

#define TEST_OPF_VFMV_GROUP(test, op) \
TEST_OPF_VFMV_GROUP_MF2(test, op) \
TEST_OPF_VFMV_GROUP_M1(test, op) \
TEST_OPF_VFMV_GROUP_M2(test, op) \
TEST_OPF_VFMV_GROUP_M4(test, op) \
TEST_OPF_VFMV_GROUP_M8(test, op) \

#define TEST_OPF_VFMV_ALL() \
TEST_OPF_VFMV_GROUP(TEST_OPF_VFMV, vfmerge)

#endif
