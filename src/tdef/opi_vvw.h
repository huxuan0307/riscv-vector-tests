#ifndef __TDEF_OPI_VVW_H__
#define __TDEF_OPI_VVW_H__

#include "common.h"
#include "opi_vvv.h"

#define test_opi_vvw test_opi_vvv
#define test_opi_vvw_m test_opi_vvv_m

#define TEST_OPI_VVW(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vv_" #type_ret #lmul_ret " ...\n"); \
test_opi_vvw<type_ret, type2, type1>(op ## _vv_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul_ret ## _vec, TEST_LENGTH)

#define TEST_OPI_VVW_M(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vv_" #type_ret #lmul_ret "_m" " ...\n"); \
test_opi_vvw_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul_ret ## _m_vec, TEST_LENGTH)

#define TEST_OPI_VVW_III(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VVW(op, type_arg, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VVW_UUU TEST_OPI_VVW_III
#define TEST_OPI_VVW_IUI TEST_OPI_VVW

#define TEST_OPI_VVW_III_M(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VVW_M(op, type_arg, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VVW_UUU_M TEST_OPI_VVW_III_M
#define TEST_OPI_VVW_IUI_M TEST_OPI_VVW_M

#define TEST_OPI_VVW_III_GROUP_IMPL(test, op) \
test(op,  i8,   mf8,  i16,  mf4); \
test(op,  i8,   mf4,  i16,  mf2); \
test(op,  i8,   mf2,  i16,  m1); \
test(op,  i8,   m1,   i16,  m2); \
test(op,  i8,   m2,   i16,  m4); \
test(op,  i8,   m4,   i16,  m8); \
test(op,  i16,  mf4,  i32,  mf2); \
test(op,  i16,  mf2,  i32,  m1); \
test(op,  i16,  m1,   i32,  m2); \
test(op,  i16,  m2,   i32,  m4); \
test(op,  i16,  m4,   i32,  m8); \
test(op,  i32,  mf2,  i64,  m1); \
test(op,  i32,  m1,   i64,  m2); \
test(op,  i32,  m2,   i64,  m4); \
test(op,  i32,  m4,   i64,  m8); \

#define TEST_OPI_VVW_UUU_GROUP_IMPL(test, op) \
test(op,  u8,   mf8,  u16,  mf4); \
test(op,  u8,   mf4,  u16,  mf2); \
test(op,  u8,   mf2,  u16,  m1); \
test(op,  u8,   m1,   u16,  m2); \
test(op,  u8,   m2,   u16,  m4); \
test(op,  u8,   m4,   u16,  m8); \
test(op,  u16,  mf4,  u32,  mf2); \
test(op,  u16,  mf2,  u32,  m1); \
test(op,  u16,  m1,   u32,  m2); \
test(op,  u16,  m2,   u32,  m4); \
test(op,  u16,  m4,   u32,  m8); \
test(op,  u32,  mf2,  u64,  m1); \
test(op,  u32,  m1,   u64,  m2); \
test(op,  u32,  m2,   u64,  m4); \
test(op,  u32,  m4,   u64,  m8); \

#define TEST_OPI_VVW_IUI_GROUP_IMPL(test, op) \
test(op,  i8,   u8,   mf8,  i16,  mf4); \
test(op,  i8,   u8,   mf4,  i16,  mf2); \
test(op,  i8,   u8,   mf2,  i16,  m1); \
test(op,  i8,   u8,   m1,   i16,  m2); \
test(op,  i8,   u8,   m2,   i16,  m4); \
test(op,  i8,   u8,   m4,   i16,  m8); \
test(op,  i16,  u16,  mf4,  i32,  mf2); \
test(op,  i16,  u16,  mf2,  i32,  m1); \
test(op,  i16,  u16,  m1,   i32,  m2); \
test(op,  i16,  u16,  m2,   i32,  m4); \
test(op,  i16,  u16,  m4,   i32,  m8); \
test(op,  i32,  u32,  mf2,  i64,  m1); \
test(op,  i32,  u32,  m1,   i64,  m2); \
test(op,  i32,  u32,  m2,   i64,  m4); \
test(op,  i32,  u32,  m4,   i64,  m8); \

#define TEST_OPI_VVW_GROUP_IMPL(test, op) \
TEST_OPI_VVW_III_GROUP_IMPL(test, op) \
TEST_OPI_VVW_UUU_GROUP_IMPL(test, op) \

#define TEST_OPI_VVW_GROUP(op)        TEST_OPI_VVW_GROUP_IMPL(TEST_OPI_VVW, op)
#define TEST_OPI_VVW_III_GROUP(op)    TEST_OPI_VVW_III_GROUP_IMPL(TEST_OPI_VVW_III, op)
#define TEST_OPI_VVW_UUU_GROUP(op)    TEST_OPI_VVW_UUU_GROUP_IMPL(TEST_OPI_VVW_UUU, op)
#define TEST_OPI_VVW_IUI_GROUP(op)    TEST_OPI_VVW_IUI_GROUP_IMPL(TEST_OPI_VVW_IUI, op)

#define TEST_OPI_VVW_M_GROUP(op)      TEST_OPI_VVW_GROUP_IMPL(TEST_OPI_VVW_M, op)
#define TEST_OPI_VVW_III_M_GROUP(op)  TEST_OPI_VVW_III_GROUP_IMPL(TEST_OPI_VVW_III_M, op)
#define TEST_OPI_VVW_UUU_M_GROUP(op)  TEST_OPI_VVW_UUU_GROUP_IMPL(TEST_OPI_VVW_UUU_M, op)
#define TEST_OPI_VVW_IUI_M_GROUP(op)  TEST_OPI_VVW_IUI_GROUP_IMPL(TEST_OPI_VVW_IUI_M, op)

#define TEST_OPI_VVW_ALL() \
TEST_OPI_VVW_III_GROUP(vwadd) \
TEST_OPI_VVW_III_GROUP(vwsub) \
TEST_OPI_VVW_UUU_GROUP(vwaddu) \
TEST_OPI_VVW_UUU_GROUP(vwsubu) \
TEST_OPI_VVW_III_GROUP(vwmul) \
TEST_OPI_VVW_UUU_GROUP(vwmulu) \
TEST_OPI_VVW_IUI_GROUP(vwmulsu) \

#define TEST_OPI_VVW_M_ALL() \
TEST_OPI_VVW_III_M_GROUP(vwadd) \
TEST_OPI_VVW_III_M_GROUP(vwsub) \
TEST_OPI_VVW_UUU_M_GROUP(vwaddu) \
TEST_OPI_VVW_UUU_M_GROUP(vwsubu) \
TEST_OPI_VVW_III_M_GROUP(vwmul) \
TEST_OPI_VVW_UUU_M_GROUP(vwmulu) \
TEST_OPI_VVW_IUI_M_GROUP(vwmulsu) \

#endif
