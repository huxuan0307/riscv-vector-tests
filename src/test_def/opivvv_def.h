#include <stdint.h>

#define TEST_OPIVVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opivvv<type_ret, type2, type1>(op ## _vv_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _vec)

#define TEST_OPIVVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul "_m" " ...\n"); \
test_opivvv_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _m_vec)


#define TEST_OPIVVV_COMMON_III_GROUP_MF8(test, op) \
test(op, i8,   i8,   i8,   mf8); \

#define TEST_OPIVVV_COMMON_III_GROUP_MF4(test, op)  \
test(op, i8,   i8,   i8,   mf4); \
test(op, i16,  i16,  i16,  mf4); \

#define TEST_OPIVVV_COMMON_III_GROUP_MF2(test, op)  \
test(op, i8,   i8,   i8,   mf2); \
test(op, i16,  i16,  i16,  mf2); \
test(op, i32,  i32,  i32,  mf2); \

#define TEST_OPIVVV_COMMON_III_GROUP_M1(test, op)   \
test(op, i8,   i8,   i8,   m1);  \
test(op, i16,  i16,  i16,  m1);  \
test(op, i32,  i32,  i32,  m1);  \
test(op, i64,  i64,  i64,  m1);  \

#define TEST_OPIVVV_COMMON_III_GROUP_M2(test, op)   \
test(op, i8,   i8,   i8,   m2);  \
test(op, i16,  i16,  i16,  m2);  \
test(op, i32,  i32,  i32,  m2);  \
test(op, i64,  i64,  i64,  m2);  \

#define TEST_OPIVVV_COMMON_III_GROUP_M4(test, op)   \
test(op, i8,   i8,   i8,   m4);  \
test(op, i16,  i16,  i16,  m4);  \
test(op, i32,  i32,  i32,  m4);  \
test(op, i64,  i64,  i64,  m4);  \

#define TEST_OPIVVV_COMMON_III_GROUP_M8(test, op)   \
test(op, i8,   i8,   i8,   m8);  \
test(op, i16,  i16,  i16,  m8);  \
test(op, i32,  i32,  i32,  m8);  \
test(op, i64,  i64,  i64,  m8);  \

#define TEST_OPIVVV_COMMON_UUU_GROUP_MF8(test, op) \
test(op, u8,   u8,   u8,   mf8); \

#define TEST_OPIVVV_COMMON_UUU_GROUP_MF4(test, op) \
test(op, u8,   u8,   u8,   mf4); \
test(op, u16,  u16,  u16,  mf4); \

#define TEST_OPIVVV_COMMON_UUU_GROUP_MF2(test, op) \
test(op, u8,   u8,   u8,   mf2); \
test(op, u16,  u16,  u16,  mf2); \
test(op, u32,  u32,  u32,  mf2); \

#define TEST_OPIVVV_COMMON_UUU_GROUP_M1(test, op)  \
test(op, u8,   u8,   u8,   m1);  \
test(op, u16,  u16,  u16,  m1);  \
test(op, u32,  u32,  u32,  m1);  \
test(op, u64,  u64,  u64,  m1);  \

#define TEST_OPIVVV_COMMON_UUU_GROUP_M2(test, op)  \
test(op, u8,   u8,   u8,   m2);  \
test(op, u16,  u16,  u16,  m2);  \
test(op, u32,  u32,  u32,  m2);  \
test(op, u64,  u64,  u64,  m2);  \

#define TEST_OPIVVV_COMMON_UUU_GROUP_M4(test, op)  \
test(op, u8,   u8,   u8,   m4);  \
test(op, u16,  u16,  u16,  m4);  \
test(op, u32,  u32,  u32,  m4);  \
test(op, u64,  u64,  u64,  m4);  \

#define TEST_OPIVVV_COMMON_UUU_GROUP_M8(test, op)  \
test(op, u8,   u8,   u8,   m8);  \
test(op, u16,  u16,  u16,  m8);  \
test(op, u32,  u32,  u32,  m8);  \
test(op, u64,  u64,  u64,  m8);  \

#define TEST_OPIVVV_COMMON_IUI_GROUP_MF8(test, op) \
test(op, i8,   u8,   i8,   mf8); \

#define TEST_OPIVVV_COMMON_IUI_GROUP_MF4(test, op) \
test(op, i8,   u8,   i8,   mf4); \
test(op, i16,  u16,  i16,  mf4); \

#define TEST_OPIVVV_COMMON_IUI_GROUP_MF2(test, op) \
test(op, i8,   u8,   i8,   mf2); \
test(op, i16,  u16,  i16,  mf2); \
test(op, i32,  u32,  i32,  mf2); \

#define TEST_OPIVVV_COMMON_IUI_GROUP_M1(test, op)  \
test(op, i8,   u8,   i8,   m1);  \
test(op, i16,  u16,  i16,  m1);  \
test(op, i32,  u32,  i32,  m1);  \
test(op, i64,  u64,  i64,  m1);  \

#define TEST_OPIVVV_COMMON_IUI_GROUP_M2(test, op)  \
test(op, i8,   u8,   i8,   m2);  \
test(op, i16,  u16,  i16,  m2);  \
test(op, i32,  u32,  i32,  m2);  \
test(op, i64,  u64,  i64,  m2);  \

#define TEST_OPIVVV_COMMON_IUI_GROUP_M4(test, op)  \
test(op, i8,   u8,   i8,   m4);  \
test(op, i16,  u16,  i16,  m4);  \
test(op, i32,  u32,  i32,  m4);  \
test(op, i64,  u64,  i64,  m4);  \

#define TEST_OPIVVV_COMMON_IUI_GROUP_M8(test, op)  \
test(op, i8,   u8,   i8,   m8);  \
test(op, i16,  u16,  i16,  m8);  \
test(op, i32,  u32,  i32,  m8);  \
test(op, i64,  u64,  i64,  m8);  \

#define TEST_OPIVVV_COMMON_GROUP_MF8(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_MF8(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_MF8(test, op) \

#define TEST_OPIVVV_COMMON_GROUP_MF4(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_MF4(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_MF4(test, op) \

#define TEST_OPIVVV_COMMON_GROUP_MF2(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_MF2(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_MF2(test, op) \

#define TEST_OPIVVV_COMMON_GROUP_M1(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_M1(test, op)   \
TEST_OPIVVV_COMMON_UUU_GROUP_M1(test, op)  \

#define TEST_OPIVVV_COMMON_GROUP_M2(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_M2(test, op)   \
TEST_OPIVVV_COMMON_UUU_GROUP_M2(test, op)  \

#define TEST_OPIVVV_COMMON_GROUP_M4(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_M4(test, op)   \
TEST_OPIVVV_COMMON_UUU_GROUP_M4(test, op)  \

#define TEST_OPIVVV_COMMON_GROUP_M8(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_M8(test, op)   \
TEST_OPIVVV_COMMON_UUU_GROUP_M8(test, op)   \

#define TEST_OPIVVV_COMMON_III_GROUP(test, op) \
TEST_OPIVVV_COMMON_III_GROUP_MF8(test, op)  \
TEST_OPIVVV_COMMON_III_GROUP_MF4(test, op)  \
TEST_OPIVVV_COMMON_III_GROUP_MF2(test, op)  \
TEST_OPIVVV_COMMON_III_GROUP_M1(test, op)   \
TEST_OPIVVV_COMMON_III_GROUP_M2(test, op)   \
TEST_OPIVVV_COMMON_III_GROUP_M4(test, op)   \
TEST_OPIVVV_COMMON_III_GROUP_M8(test, op)   \

#define TEST_OPIVVV_COMMON_UUU_GROUP(test, op) \
TEST_OPIVVV_COMMON_UUU_GROUP_MF8(test, op) \
TEST_OPIVVV_COMMON_UUU_GROUP_MF4(test, op) \
TEST_OPIVVV_COMMON_UUU_GROUP_MF2(test, op) \
TEST_OPIVVV_COMMON_UUU_GROUP_M1(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_M2(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_M4(test, op)  \
TEST_OPIVVV_COMMON_UUU_GROUP_M8(test, op)  \

#define TEST_OPIVVV_COMMON_IUI_GROUP(test, op) \
TEST_OPIVVV_COMMON_IUI_GROUP_MF8(test, op)  \
TEST_OPIVVV_COMMON_IUI_GROUP_MF4(test, op)  \
TEST_OPIVVV_COMMON_IUI_GROUP_MF2(test, op)  \
TEST_OPIVVV_COMMON_IUI_GROUP_M1(test, op)   \
TEST_OPIVVV_COMMON_IUI_GROUP_M2(test, op)   \
TEST_OPIVVV_COMMON_IUI_GROUP_M4(test, op)   \
TEST_OPIVVV_COMMON_IUI_GROUP_M8(test, op)   \

#define TEST_OPIVVV_COMMON_GROUP(test, op) \
TEST_OPIVVV_COMMON_GROUP_MF8(test, op) \
TEST_OPIVVV_COMMON_GROUP_MF4(test, op) \
TEST_OPIVVV_COMMON_GROUP_MF2(test, op) \
TEST_OPIVVV_COMMON_GROUP_M1(test, op) \
TEST_OPIVVV_COMMON_GROUP_M2(test, op) \
TEST_OPIVVV_COMMON_GROUP_M4(test, op) \
TEST_OPIVVV_COMMON_GROUP_M8(test, op) \

#define TEST_OPIVVV_GROUP(op)     TEST_OPIVVV_COMMON_GROUP(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP(op) TEST_OPIVVV_COMMON_III_GROUP(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP(op) TEST_OPIVVV_COMMON_UUU_GROUP(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP(op) TEST_OPIVVV_COMMON_IUI_GROUP(TEST_OPIVVV, op)

#define TEST_OPIVVV_III_GROUP_MF8(op) TEST_OPIVVV_COMMON_III_GROUP_MF8(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_MF4(op) TEST_OPIVVV_COMMON_III_GROUP_MF4(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_MF2(op) TEST_OPIVVV_COMMON_III_GROUP_MF2(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_M1(op)  TEST_OPIVVV_COMMON_III_GROUP_M1(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_M2(op)  TEST_OPIVVV_COMMON_III_GROUP_M2(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_M4(op)  TEST_OPIVVV_COMMON_III_GROUP_M4(TEST_OPIVVV, op)
#define TEST_OPIVVV_III_GROUP_M8(op)  TEST_OPIVVV_COMMON_III_GROUP_M8(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_MF8(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF8(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_MF4(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF4(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_MF2(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF2(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_M1(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M1(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_M2(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M2(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_M4(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M4(TEST_OPIVVV, op)
#define TEST_OPIVVV_UUU_GROUP_M8(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M8(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_MF8(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF8(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_MF4(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF4(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_MF2(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF2(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_M1(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M1(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_M2(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M2(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_M4(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M4(TEST_OPIVVV, op)
#define TEST_OPIVVV_IUI_GROUP_M8(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M8(TEST_OPIVVV, op)

#define TEST_OPIVVV_M_GROUP(op)     TEST_OPIVVV_COMMON_GROUP(TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP(op) TEST_OPIVVV_COMMON_III_GROUP(TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP(op) TEST_OPIVVV_COMMON_UUU_GROUP(TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP(op) TEST_OPIVVV_COMMON_IUI_GROUP(TEST_OPIVVV_M, op)

#define TEST_OPIVVV_III_M_GROUP_MF8(op) TEST_OPIVVV_COMMON_III_GROUP_MF8( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_MF4(op) TEST_OPIVVV_COMMON_III_GROUP_MF4( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_MF2(op) TEST_OPIVVV_COMMON_III_GROUP_MF2( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_M1(op)  TEST_OPIVVV_COMMON_III_GROUP_M1(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_M2(op)  TEST_OPIVVV_COMMON_III_GROUP_M2(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_M4(op)  TEST_OPIVVV_COMMON_III_GROUP_M4(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_III_M_GROUP_M8(op)  TEST_OPIVVV_COMMON_III_GROUP_M8(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_MF8(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF8( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_MF4(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF4( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_MF2(op) TEST_OPIVVV_COMMON_UUU_GROUP_MF2( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_M1(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M1(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_M2(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M2(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_M4(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M4(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_UUU_M_GROUP_M8(op)  TEST_OPIVVV_COMMON_UUU_GROUP_M8(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_MF8(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF8( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_MF4(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF4( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_MF2(op) TEST_OPIVVV_COMMON_IUI_GROUP_MF2( TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_M1(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M1(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_M2(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M2(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_M4(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M4(  TEST_OPIVVV_M, op)
#define TEST_OPIVVV_IUI_M_GROUP_M8(op)  TEST_OPIVVV_COMMON_IUI_GROUP_M8(  TEST_OPIVVV_M, op)



