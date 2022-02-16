#ifndef __TDEF_OPI_VWW_H__
#define __TDEF_OPI_VWW_H__

#include "common.h"
#include "opi_vvv.h"

#define test_opi_vww test_opi_vvv
#define test_opi_vww_m test_opi_vvv_m

#define TEST_OPI_VWW(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_wv_" #type_ret #lmul_ret " ...\n"); \
test_opi_vww<type_ret, type2, type1>(op ## _wv_ref<type_ret, type2, type1>, op ## _wv_## type_ret ## lmul_ret ## _vec, TEST_LENGTH)

#define TEST_OPI_VWW_M(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vv_" #type_ret #lmul_ret "_m" " ...\n"); \
test_opi_vww_m<type_ret, type2, type1>(op ## _wv_m_ref<type_ret, type2, type1>, op ## _wv_## type_ret ## lmul_ret ## _m_vec, TEST_LENGTH)

#define TEST_OPI_VWW_III(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VWW(op, type_ret, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VWW_UUU TEST_OPI_VWW_III
#define TEST_OPI_VWW_IUI TEST_OPI_VWW

#define TEST_OPI_VWW_III_M(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VWW_M(op, type_ret, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VWW_UUU_M TEST_OPI_VWW_III_M
#define TEST_OPI_VWW_IUI_M TEST_OPI_VWW_M

#define TEST_OPI_VWW_III_GROUP_IMPL(test, op) \
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

#define TEST_OPI_VWW_UUU_GROUP_IMPL(test, op) \
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

#define TEST_OPI_VWW_IUI_GROUP_IMPL(test, op) \
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

#define TEST_OPI_VWW_GROUP_IMPL(test, op) \
TEST_OPI_VWW_III_GROUP_IMPL(test, op) \
TEST_OPI_VWW_UUU_GROUP_IMPL(test, op) \

#define TEST_OPI_VWW_GROUP(op)        TEST_OPI_VWW_GROUP_IMPL(TEST_OPI_VWW, op)
#define TEST_OPI_VWW_III_GROUP(op)    TEST_OPI_VWW_III_GROUP_IMPL(TEST_OPI_VWW_III, op)
#define TEST_OPI_VWW_UUU_GROUP(op)    TEST_OPI_VWW_UUU_GROUP_IMPL(TEST_OPI_VWW_UUU, op)
#define TEST_OPI_VWW_IUI_GROUP(op)    TEST_OPI_VWW_IUI_GROUP_IMPL(TEST_OPI_VWW_IUI, op)

#define TEST_OPI_VWW_M_GROUP(op)      TEST_OPI_VWW_GROUP_IMPL(TEST_OPI_VWW_M, op)
#define TEST_OPI_VWW_III_M_GROUP(op)  TEST_OPI_VWW_III_GROUP_IMPL(TEST_OPI_VWW_III_M, op)
#define TEST_OPI_VWW_UUU_M_GROUP(op)  TEST_OPI_VWW_UUU_GROUP_IMPL(TEST_OPI_VWW_UUU_M, op)
#define TEST_OPI_VWW_IUI_M_GROUP(op)  TEST_OPI_VWW_IUI_GROUP_IMPL(TEST_OPI_VWW_IUI_M, op)

#define TEST_OPI_VWW_ALL() \
TEST_OPI_VWW_III_GROUP(vwadd) \
TEST_OPI_VWW_III_GROUP(vwsub) \
TEST_OPI_VWW_UUU_GROUP(vwaddu) \
TEST_OPI_VWW_UUU_GROUP(vwsubu) \

#define TEST_OPI_VWW_M_ALL() \
TEST_OPI_VWW_III_M_GROUP(vwadd) \
TEST_OPI_VWW_III_M_GROUP(vwsub) \
TEST_OPI_VWW_UUU_M_GROUP(vwaddu) \
TEST_OPI_VWW_UUU_M_GROUP(vwsubu) \

#endif
