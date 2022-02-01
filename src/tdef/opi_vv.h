#include <stdint.h>

#define TEST_OPI_VV(op, type, tp, lmul) \
printf("\ntest " #op "_v_v_" #tp #lmul " ...\n"); \
test_opi_vv<type, type>(op ## _v_v_ref<type>, op ## _v_v_## tp ## lmul ## _vec)

#define TEST_OPI_VV_INT_GROUP_MF8(op) \
TEST_OPI_VV(op,  int8_t,   i8,   mf8); \

#define TEST_OPI_VV_UINT_GROUP_MF8(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf8); \

#define TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV(op,  int8_t,   i8,   mf4); \
TEST_OPI_VV(op,  int16_t,  i16,  mf4); \

#define TEST_OPI_VV_UINT_GROUP_MF4(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf4); \
TEST_OPI_VV(op,  uint16_t, u16,  mf4); \

#define TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV(op,  int8_t,   i8,   mf2); \
TEST_OPI_VV(op,  int16_t,  i16,  mf2); \
TEST_OPI_VV(op,  int32_t,  i32,  mf2); \

#define TEST_OPI_VV_UINT_GROUP_MF2(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf2); \
TEST_OPI_VV(op,  uint16_t, u16,  mf2); \
TEST_OPI_VV(op,  uint32_t, u32,  mf2); \

#define TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m1);  \
TEST_OPI_VV(op,  int16_t,  i16,  m1);  \
TEST_OPI_VV(op,  int32_t,  i32,  m1);  \
TEST_OPI_VV(op,  int64_t,  i64,  m1);  \

#define TEST_OPI_VV_UINT_GROUP_M1(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m1);  \
TEST_OPI_VV(op,  uint16_t, u16,  m1);  \
TEST_OPI_VV(op,  uint32_t, u32,  m1);  \
TEST_OPI_VV(op,  uint64_t, u64,  m1);  \

#define TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m2);  \
TEST_OPI_VV(op,  int16_t,  i16,  m2);  \
TEST_OPI_VV(op,  int32_t,  i32,  m2);  \
TEST_OPI_VV(op,  int64_t,  i64,  m2);  \

#define TEST_OPI_VV_UINT_GROUP_M2(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m2);  \
TEST_OPI_VV(op,  uint16_t, u16,  m2);  \
TEST_OPI_VV(op,  uint32_t, u32,  m2);  \
TEST_OPI_VV(op,  uint64_t, u64,  m2);  \

#define TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m4);  \
TEST_OPI_VV(op,  int16_t,  i16,  m4);  \
TEST_OPI_VV(op,  int32_t,  i32,  m4);  \
TEST_OPI_VV(op,  int64_t,  i64,  m4);  \

#define TEST_OPI_VV_UINT_GROUP_M4(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m4);  \
TEST_OPI_VV(op,  uint16_t, u16,  m4);  \
TEST_OPI_VV(op,  uint32_t, u32,  m4);  \
TEST_OPI_VV(op,  uint64_t, u64,  m4);  \

#define TEST_OPI_VV_INT_GROUP_M8(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m8);  \
TEST_OPI_VV(op,  int16_t,  i16,  m8);  \
TEST_OPI_VV(op,  int32_t,  i32,  m8);  \
TEST_OPI_VV(op,  int64_t,  i64,  m8);  \

#define TEST_OPI_VV_UINT_GROUP_M8(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m8);  \
TEST_OPI_VV(op,  uint16_t, u16,  m8);  \
TEST_OPI_VV(op,  uint32_t, u32,  m8);  \
TEST_OPI_VV(op,  uint64_t, u64,  m8);  \

#define TEST_OPI_VV_GROUP_MF8(op) \
TEST_OPI_VV_INT_GROUP_MF8(op)  \
TEST_OPI_VV_UINT_GROUP_MF8(op) \

#define TEST_OPI_VV_GROUP_MF4(op) \
TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV_UINT_GROUP_MF4(op) \

#define TEST_OPI_VV_GROUP_MF2(op) \
TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV_UINT_GROUP_MF2(op) \

#define TEST_OPI_VV_GROUP_M1(op) \
TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV_UINT_GROUP_M1(op)  \

#define TEST_OPI_VV_GROUP_M2(op) \
TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV_UINT_GROUP_M2(op)  \

#define TEST_OPI_VV_GROUP_M4(op) \
TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV_UINT_GROUP_M4(op)  \

#define TEST_OPI_VV_GROUP_M8(op) \
TEST_OPI_VV_INT_GROUP_M8(op)   \
TEST_OPI_VV_UINT_GROUP_M8(op)   \

#define TEST_OPI_VV_INT_GROUP(op) \
TEST_OPI_VV_INT_GROUP_MF8(op)  \
TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV_INT_GROUP_M8(op)   \

#define TEST_OPI_VV_UINT_GROUP(op) \
TEST_OPI_VV_UINT_GROUP_MF8(op) \
TEST_OPI_VV_UINT_GROUP_MF4(op) \
TEST_OPI_VV_UINT_GROUP_MF2(op) \
TEST_OPI_VV_UINT_GROUP_M1(op)  \
TEST_OPI_VV_UINT_GROUP_M2(op)  \
TEST_OPI_VV_UINT_GROUP_M4(op)  \
TEST_OPI_VV_UINT_GROUP_M8(op)  \

#define TEST_OPI_VV_GROUP(op) \
{ \
  TEST_OPI_VV_GROUP_MF8(op) \
  TEST_OPI_VV_GROUP_MF4(op) \
  TEST_OPI_VV_GROUP_MF2(op) \
  TEST_OPI_VV_GROUP_M1(op) \
  TEST_OPI_VV_GROUP_M2(op) \
  TEST_OPI_VV_GROUP_M4(op) \
  TEST_OPI_VV_GROUP_M8(op) \
}