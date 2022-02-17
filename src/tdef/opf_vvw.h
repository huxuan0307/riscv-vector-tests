#ifndef __TDEF_OPF_VVW_H__
#define __TDEF_OPF_VVW_H__

#include "common.h"
#include "opf_vvv.h"

#define test_opf_vvw test_opf_vvv
#define test_opf_vvw_m test_opf_vvv_m

#define TEST_OPF_VVW(op, type_arg, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vv_" #type_ret #lmul_ret " ...\n"); \
test_opf_vvw<type_ret, type_arg, type_arg>(op ## _vv_ref<type_ret, type_arg, type_arg>, op ## _vv_## type_ret ## lmul_ret ## _vec, TEST_LENGTH)

#define TEST_OPF_VVW_M(op, type_arg, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vv_" #type_ret #lmul_ret "_m" " ...\n"); \
test_opf_vvw_m<type_ret, type_arg, type_arg>(op ## _vv_m_ref<type_ret, type_arg, type_arg>, op ## _vv_## type_ret ## lmul_ret ## _m_vec, TEST_LENGTH)

#define TEST_OPF_VVW_GROUP_IMPL(test, op) \
test(op,  f32,  mf2,  f64,  m1); \
test(op,  f32,  m1,   f64,  m2); \
test(op,  f32,  m2,   f64,  m4); \
test(op,  f32,  m4,   f64,  m8); \

#define TEST_OPF_VVW_GROUP(op)        TEST_OPF_VVW_GROUP_IMPL(TEST_OPF_VVW, op)
#define TEST_OPF_VVW_M_GROUP(op)      TEST_OPF_VVW_GROUP_IMPL(TEST_OPF_VVW_M, op)

#define TEST_OPF_VVW_ALL() \
TEST_OPF_VVW_GROUP(vfwadd) \
TEST_OPF_VVW_GROUP(vfwsub) \

#define TEST_OPF_VVW_M_ALL() \
TEST_OPF_VVW_M_GROUP(vfwadd) \
TEST_OPF_VVW_M_GROUP(vfwsub) \

#endif
