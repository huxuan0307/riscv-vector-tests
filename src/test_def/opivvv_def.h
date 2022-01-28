#include <stdint.h>

#define TEST_OPIVVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opivvv<type_ret, type2, type1>(op ## _vv_ref<type_ret, type2, type1>, op ## _vv_## type_ret ## lmul ## _vec)


#define TEST_OPIVVV_III_GROUP_MF8(op) \
TEST_OPIVVV(op, i8,   i8,   i8,   mf8); \

#define TEST_OPIVVV_III_GROUP_MF4(op)  \
TEST_OPIVVV(op, i8,   i8,   i8,   mf4); \
TEST_OPIVVV(op, i16,  i16,  i16,  mf4); \

#define TEST_OPIVVV_III_GROUP_MF2(op)  \
TEST_OPIVVV(op, i8,   i8,   i8,   mf2); \
TEST_OPIVVV(op, i16,  i16,  i16,  mf2); \
TEST_OPIVVV(op, i32,  i32,  i32,  mf2); \

#define TEST_OPIVVV_III_GROUP_M1(op)   \
TEST_OPIVVV(op, i8,   i8,   i8,   m1);  \
TEST_OPIVVV(op, i16,  i16,  i16,  m1);  \
TEST_OPIVVV(op, i32,  i32,  i32,  m1);  \
TEST_OPIVVV(op, i64,  i64,  i64,  m1);  \

#define TEST_OPIVVV_III_GROUP_M2(op)   \
TEST_OPIVVV(op, i8,   i8,   i8,   m2);  \
TEST_OPIVVV(op, i16,  i16,  i16,  m2);  \
TEST_OPIVVV(op, i32,  i32,  i32,  m2);  \
TEST_OPIVVV(op, i64,  i64,  i64,  m2);  \

#define TEST_OPIVVV_III_GROUP_M4(op)   \
TEST_OPIVVV(op, i8,   i8,   i8,   m4);  \
TEST_OPIVVV(op, i16,  i16,  i16,  m4);  \
TEST_OPIVVV(op, i32,  i32,  i32,  m4);  \
TEST_OPIVVV(op, i64,  i64,  i64,  m4);  \

#define TEST_OPIVVV_III_GROUP_M8(op)   \
TEST_OPIVVV(op, i8,   i8,   i8,   m8);  \
TEST_OPIVVV(op, i16,  i16,  i16,  m8);  \
TEST_OPIVVV(op, i32,  i32,  i32,  m8);  \
TEST_OPIVVV(op, i64,  i64,  i64,  m8);  \

#define TEST_OPIVVV_UUU_GROUP_MF8(op) \
TEST_OPIVVV(op, u8,   u8,   u8,   mf8); \

#define TEST_OPIVVV_UUU_GROUP_MF4(op) \
TEST_OPIVVV(op, u8,   u8,   u8,   mf4); \
TEST_OPIVVV(op, u16,  u16,  u16,  mf4); \

#define TEST_OPIVVV_UUU_GROUP_MF2(op) \
TEST_OPIVVV(op, u8,   u8,   u8,   mf2); \
TEST_OPIVVV(op, u16,  u16,  u16,  mf2); \
TEST_OPIVVV(op, u32,  u32,  u32,  mf2); \

#define TEST_OPIVVV_UUU_GROUP_M1(op)  \
TEST_OPIVVV(op, u8,   u8,   u8,   m1);  \
TEST_OPIVVV(op, u16,  u16,  u16,  m1);  \
TEST_OPIVVV(op, u32,  u32,  u32,  m1);  \
TEST_OPIVVV(op, u64,  u64,  u64,  m1);  \

#define TEST_OPIVVV_UUU_GROUP_M2(op)  \
TEST_OPIVVV(op, u8,   u8,   u8,   m2);  \
TEST_OPIVVV(op, u16,  u16,  u16,  m2);  \
TEST_OPIVVV(op, u32,  u32,  u32,  m2);  \
TEST_OPIVVV(op, u64,  u64,  u64,  m2);  \

#define TEST_OPIVVV_UUU_GROUP_M4(op)  \
TEST_OPIVVV(op, u8,   u8,   u8,   m4);  \
TEST_OPIVVV(op, u16,  u16,  u16,  m4);  \
TEST_OPIVVV(op, u32,  u32,  u32,  m4);  \
TEST_OPIVVV(op, u64,  u64,  u64,  m4);  \

#define TEST_OPIVVV_UUU_GROUP_M8(op)  \
TEST_OPIVVV(op, u8,   u8,   u8,   m8);  \
TEST_OPIVVV(op, u16,  u16,  u16,  m8);  \
TEST_OPIVVV(op, u32,  u32,  u32,  m8);  \
TEST_OPIVVV(op, u64,  u64,  u64,  m8);  \

#define TEST_OPIVVV_IUI_GROUP_MF8(op) \
TEST_OPIVVV(op, i8,   u8,   i8,   mf8); \

#define TEST_OPIVVV_IUI_GROUP_MF4(op) \
TEST_OPIVVV(op, i8,   u8,   i8,   mf4); \
TEST_OPIVVV(op, i16,  u16,  i16,  mf4); \

#define TEST_OPIVVV_IUI_GROUP_MF2(op) \
TEST_OPIVVV(op, i8,   u8,   i8,   mf2); \
TEST_OPIVVV(op, i16,  u16,  i16,  mf2); \
TEST_OPIVVV(op, i32,  u32,  i32,  mf2); \

#define TEST_OPIVVV_IUI_GROUP_M1(op)  \
TEST_OPIVVV(op, i8,   u8,   i8,   m1);  \
TEST_OPIVVV(op, i16,  u16,  i16,  m1);  \
TEST_OPIVVV(op, i32,  u32,  i32,  m1);  \
TEST_OPIVVV(op, i64,  u64,  i64,  m1);  \

#define TEST_OPIVVV_IUI_GROUP_M2(op)  \
TEST_OPIVVV(op, i8,   u8,   i8,   m2);  \
TEST_OPIVVV(op, i16,  u16,  i16,  m2);  \
TEST_OPIVVV(op, i32,  u32,  i32,  m2);  \
TEST_OPIVVV(op, i64,  u64,  i64,  m2);  \

#define TEST_OPIVVV_IUI_GROUP_M4(op)  \
TEST_OPIVVV(op, i8,   u8,   i8,   m4);  \
TEST_OPIVVV(op, i16,  u16,  i16,  m4);  \
TEST_OPIVVV(op, i32,  u32,  i32,  m4);  \
TEST_OPIVVV(op, i64,  u64,  i64,  m4);  \

#define TEST_OPIVVV_IUI_GROUP_M8(op)  \
TEST_OPIVVV(op, i8,   u8,   i8,   m8);  \
TEST_OPIVVV(op, i16,  u16,  i16,  m8);  \
TEST_OPIVVV(op, i32,  u32,  i32,  m8);  \
TEST_OPIVVV(op, i64,  u64,  i64,  m8);  \



#define TEST_OPIVVV_GROUP_MF8(op) \
TEST_OPIVVV_III_GROUP_MF8(op)  \
TEST_OPIVVV_UUU_GROUP_MF8(op) \

#define TEST_OPIVVV_GROUP_MF4(op) \
TEST_OPIVVV_III_GROUP_MF4(op)  \
TEST_OPIVVV_UUU_GROUP_MF4(op) \

#define TEST_OPIVVV_GROUP_MF2(op) \
TEST_OPIVVV_III_GROUP_MF2(op)  \
TEST_OPIVVV_UUU_GROUP_MF2(op) \

#define TEST_OPIVVV_GROUP_M1(op) \
TEST_OPIVVV_III_GROUP_M1(op)   \
TEST_OPIVVV_UUU_GROUP_M1(op)  \

#define TEST_OPIVVV_GROUP_M2(op) \
TEST_OPIVVV_III_GROUP_M2(op)   \
TEST_OPIVVV_UUU_GROUP_M2(op)  \

#define TEST_OPIVVV_GROUP_M4(op) \
TEST_OPIVVV_III_GROUP_M4(op)   \
TEST_OPIVVV_UUU_GROUP_M4(op)  \

#define TEST_OPIVVV_GROUP_M8(op) \
TEST_OPIVVV_III_GROUP_M8(op)   \
TEST_OPIVVV_UUU_GROUP_M8(op)   \

#define TEST_OPIVVV_III_GROUP(op) \
TEST_OPIVVV_III_GROUP_MF8(op)  \
TEST_OPIVVV_III_GROUP_MF4(op)  \
TEST_OPIVVV_III_GROUP_MF2(op)  \
TEST_OPIVVV_III_GROUP_M1(op)   \
TEST_OPIVVV_III_GROUP_M2(op)   \
TEST_OPIVVV_III_GROUP_M4(op)   \
TEST_OPIVVV_III_GROUP_M8(op)   \

#define TEST_OPIVVV_UUU_GROUP(op) \
TEST_OPIVVV_UUU_GROUP_MF8(op) \
TEST_OPIVVV_UUU_GROUP_MF4(op) \
TEST_OPIVVV_UUU_GROUP_MF2(op) \
TEST_OPIVVV_UUU_GROUP_M1(op)  \
TEST_OPIVVV_UUU_GROUP_M2(op)  \
TEST_OPIVVV_UUU_GROUP_M4(op)  \
TEST_OPIVVV_UUU_GROUP_M8(op)  \

#define TEST_OPIVVV_IUI_GROUP(op) \
TEST_OPIVVV_IUI_GROUP_MF8(op)  \
TEST_OPIVVV_IUI_GROUP_MF4(op)  \
TEST_OPIVVV_IUI_GROUP_MF2(op)  \
TEST_OPIVVV_IUI_GROUP_M1(op)   \
TEST_OPIVVV_IUI_GROUP_M2(op)   \
TEST_OPIVVV_IUI_GROUP_M4(op)   \
TEST_OPIVVV_IUI_GROUP_M8(op)   \

#define TEST_OPIVVV_GROUP(op) \
{ \
  TEST_OPIVVV_GROUP_MF8(op) \
  TEST_OPIVVV_GROUP_MF4(op) \
  TEST_OPIVVV_GROUP_MF2(op) \
  TEST_OPIVVV_GROUP_M1(op) \
  TEST_OPIVVV_GROUP_M2(op) \
  TEST_OPIVVV_GROUP_M4(op) \
  TEST_OPIVVV_GROUP_M8(op) \
}
