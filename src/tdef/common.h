#ifndef __TDEF_COMMON_H__
#define __TDEF_COMMON_H__

#include "../config.h"
#include "../utils.h"
#include <cstdint>
#include <sstream>

#ifndef TEST_LENGTH
#define TEST_LENGTH 1024
#endif

#define TEST_OPI3OPS_COMMON_III_GROUP_MF8(test, op) \
test(op, i8,   i8,   i8,   mf8); \

#define TEST_OPI3OPS_COMMON_III_GROUP_MF4(test, op)  \
test(op, i8,   i8,   i8,   mf4); \
test(op, i16,  i16,  i16,  mf4); \

#define TEST_OPI3OPS_COMMON_III_GROUP_MF2(test, op)  \
test(op, i8,   i8,   i8,   mf2); \
test(op, i16,  i16,  i16,  mf2); \
test(op, i32,  i32,  i32,  mf2); \

#define TEST_OPI3OPS_COMMON_III_GROUP_M1(test, op)   \
test(op, i8,   i8,   i8,   m1);  \
test(op, i16,  i16,  i16,  m1);  \
test(op, i32,  i32,  i32,  m1);  \
test(op, i64,  i64,  i64,  m1);  \

#define TEST_OPI3OPS_COMMON_III_GROUP_M2(test, op)   \
test(op, i8,   i8,   i8,   m2);  \
test(op, i16,  i16,  i16,  m2);  \
test(op, i32,  i32,  i32,  m2);  \
test(op, i64,  i64,  i64,  m2);  \

#define TEST_OPI3OPS_COMMON_III_GROUP_M4(test, op)   \
test(op, i8,   i8,   i8,   m4);  \
test(op, i16,  i16,  i16,  m4);  \
test(op, i32,  i32,  i32,  m4);  \
test(op, i64,  i64,  i64,  m4);  \

#define TEST_OPI3OPS_COMMON_III_GROUP_M8(test, op)   \
test(op, i8,   i8,   i8,   m8);  \
test(op, i16,  i16,  i16,  m8);  \
test(op, i32,  i32,  i32,  m8);  \
test(op, i64,  i64,  i64,  m8);  \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(test, op) \
test(op, u8,   u8,   u8,   mf8); \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(test, op) \
test(op, u8,   u8,   u8,   mf4); \
test(op, u16,  u16,  u16,  mf4); \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(test, op) \
test(op, u8,   u8,   u8,   mf2); \
test(op, u16,  u16,  u16,  mf2); \
test(op, u32,  u32,  u32,  mf2); \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_M1(test, op)  \
test(op, u8,   u8,   u8,   m1);  \
test(op, u16,  u16,  u16,  m1);  \
test(op, u32,  u32,  u32,  m1);  \
test(op, u64,  u64,  u64,  m1);  \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_M2(test, op)  \
test(op, u8,   u8,   u8,   m2);  \
test(op, u16,  u16,  u16,  m2);  \
test(op, u32,  u32,  u32,  m2);  \
test(op, u64,  u64,  u64,  m2);  \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_M4(test, op)  \
test(op, u8,   u8,   u8,   m4);  \
test(op, u16,  u16,  u16,  m4);  \
test(op, u32,  u32,  u32,  m4);  \
test(op, u64,  u64,  u64,  m4);  \

#define TEST_OPI3OPS_COMMON_UUU_GROUP_M8(test, op)  \
test(op, u8,   u8,   u8,   m8);  \
test(op, u16,  u16,  u16,  m8);  \
test(op, u32,  u32,  u32,  m8);  \
test(op, u64,  u64,  u64,  m8);  \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(test, op) \
test(op, i8,   u8,   i8,   mf8); \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(test, op) \
test(op, i8,   u8,   i8,   mf4); \
test(op, i16,  u16,  i16,  mf4); \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(test, op) \
test(op, i8,   u8,   i8,   mf2); \
test(op, i16,  u16,  i16,  mf2); \
test(op, i32,  u32,  i32,  mf2); \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_M1(test, op)  \
test(op, i8,   u8,   i8,   m1);  \
test(op, i16,  u16,  i16,  m1);  \
test(op, i32,  u32,  i32,  m1);  \
test(op, i64,  u64,  i64,  m1);  \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_M2(test, op)  \
test(op, i8,   u8,   i8,   m2);  \
test(op, i16,  u16,  i16,  m2);  \
test(op, i32,  u32,  i32,  m2);  \
test(op, i64,  u64,  i64,  m2);  \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_M4(test, op)  \
test(op, i8,   u8,   i8,   m4);  \
test(op, i16,  u16,  i16,  m4);  \
test(op, i32,  u32,  i32,  m4);  \
test(op, i64,  u64,  i64,  m4);  \

#define TEST_OPI3OPS_COMMON_IUI_GROUP_M8(test, op)  \
test(op, i8,   u8,   i8,   m8);  \
test(op, i16,  u16,  i16,  m8);  \
test(op, i32,  u32,  i32,  m8);  \
test(op, i64,  u64,  i64,  m8);  \

#define TEST_OPI3OPS_COMMON_GROUP_MF8(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_MF8(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(test, op) \

#define TEST_OPI3OPS_COMMON_GROUP_MF4(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_MF4(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(test, op) \

#define TEST_OPI3OPS_COMMON_GROUP_MF2(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_MF2(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(test, op) \

#define TEST_OPI3OPS_COMMON_GROUP_M1(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_M1(test, op)   \
TEST_OPI3OPS_COMMON_UUU_GROUP_M1(test, op)  \

#define TEST_OPI3OPS_COMMON_GROUP_M2(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_M2(test, op)   \
TEST_OPI3OPS_COMMON_UUU_GROUP_M2(test, op)  \

#define TEST_OPI3OPS_COMMON_GROUP_M4(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_M4(test, op)   \
TEST_OPI3OPS_COMMON_UUU_GROUP_M4(test, op)  \

#define TEST_OPI3OPS_COMMON_GROUP_M8(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_M8(test, op)   \
TEST_OPI3OPS_COMMON_UUU_GROUP_M8(test, op)   \

#define TEST_OPI3OPS_COMMON_III_GROUP(test, op) \
TEST_OPI3OPS_COMMON_III_GROUP_MF8(test, op)  \
TEST_OPI3OPS_COMMON_III_GROUP_MF4(test, op)  \
TEST_OPI3OPS_COMMON_III_GROUP_MF2(test, op)  \
TEST_OPI3OPS_COMMON_III_GROUP_M1(test, op)   \
TEST_OPI3OPS_COMMON_III_GROUP_M2(test, op)   \
TEST_OPI3OPS_COMMON_III_GROUP_M4(test, op)   \
TEST_OPI3OPS_COMMON_III_GROUP_M8(test, op)   \

#define TEST_OPI3OPS_COMMON_UUU_GROUP(test, op) \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(test, op) \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(test, op) \
TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(test, op) \
TEST_OPI3OPS_COMMON_UUU_GROUP_M1(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_M2(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_M4(test, op)  \
TEST_OPI3OPS_COMMON_UUU_GROUP_M8(test, op)  \

#define TEST_OPI3OPS_COMMON_IUI_GROUP(test, op) \
TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(test, op)  \
TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(test, op)  \
TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(test, op)  \
TEST_OPI3OPS_COMMON_IUI_GROUP_M1(test, op)   \
TEST_OPI3OPS_COMMON_IUI_GROUP_M2(test, op)   \
TEST_OPI3OPS_COMMON_IUI_GROUP_M4(test, op)   \
TEST_OPI3OPS_COMMON_IUI_GROUP_M8(test, op)   \

#define TEST_OPI3OPS_COMMON_GROUP(test, op) \
TEST_OPI3OPS_COMMON_GROUP_MF8(test, op) \
TEST_OPI3OPS_COMMON_GROUP_MF4(test, op) \
TEST_OPI3OPS_COMMON_GROUP_MF2(test, op) \
TEST_OPI3OPS_COMMON_GROUP_M1(test, op) \
TEST_OPI3OPS_COMMON_GROUP_M2(test, op) \
TEST_OPI3OPS_COMMON_GROUP_M4(test, op) \
TEST_OPI3OPS_COMMON_GROUP_M8(test, op) \

#define TEST_OPI1OP_COMMON_I_GROUP_MF8(test, op) \
test(op, i8,  mf8); \

#define TEST_OPI1OP_COMMON_I_GROUP_MF4(test, op)  \
test(op, i8,  mf4); \
test(op, i16, mf4); \

#define TEST_OPI1OP_COMMON_I_GROUP_MF2(test, op)  \
test(op, i8,  mf2); \
test(op, i16, mf2); \
test(op, i32, mf2); \

#define TEST_OPI1OP_COMMON_I_GROUP_M1(test, op)   \
test(op, i8,  m1);  \
test(op, i16, m1);  \
test(op, i32, m1);  \
test(op, i64, m1);  \

#define TEST_OPI1OP_COMMON_I_GROUP_M2(test, op)   \
test(op, i8,  m2);  \
test(op, i16, m2);  \
test(op, i32, m2);  \
test(op, i64, m2);  \

#define TEST_OPI1OP_COMMON_I_GROUP_M4(test, op)   \
test(op, i8,  m4);  \
test(op, i16, m4);  \
test(op, i32, m4);  \
test(op, i64, m4);  \

#define TEST_OPI1OP_COMMON_I_GROUP_M8(test, op)   \
test(op, i8,  m8);  \
test(op, i16, m8);  \
test(op, i32, m8);  \
test(op, i64, m8);  \

#define TEST_OPI1OP_COMMON_U_GROUP_MF8(test, op) \
test(op, u8,  mf8); \

#define TEST_OPI1OP_COMMON_U_GROUP_MF4(test, op) \
test(op, u8,  mf4); \
test(op, u16, mf4); \

#define TEST_OPI1OP_COMMON_U_GROUP_MF2(test, op) \
test(op, u8,  mf2); \
test(op, u16, mf2); \
test(op, u32, mf2); \

#define TEST_OPI1OP_COMMON_U_GROUP_M1(test, op)  \
test(op, u8,  m1);  \
test(op, u16, m1);  \
test(op, u32, m1);  \
test(op, u64, m1);  \

#define TEST_OPI1OP_COMMON_U_GROUP_M2(test, op)  \
test(op, u8,  m2);  \
test(op, u16, m2);  \
test(op, u32, m2);  \
test(op, u64, m2);  \

#define TEST_OPI1OP_COMMON_U_GROUP_M4(test, op)  \
test(op, u8,  m4);  \
test(op, u16, m4);  \
test(op, u32, m4);  \
test(op, u64, m4);  \

#define TEST_OPI1OP_COMMON_U_GROUP_M8(test, op)  \
test(op, u8,  m8);  \
test(op, u16, m8);  \
test(op, u32, m8);  \
test(op, u64, m8);  \

#define TEST_OPI1OP_COMMON_GROUP_MF8(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_MF8(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_MF8(test, op) \

#define TEST_OPI1OP_COMMON_GROUP_MF4(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_MF4(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_MF4(test, op) \

#define TEST_OPI1OP_COMMON_GROUP_MF2(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_MF2(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_MF2(test, op) \

#define TEST_OPI1OP_COMMON_GROUP_M1(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_M1(test, op)   \
TEST_OPI1OP_COMMON_U_GROUP_M1(test, op)  \

#define TEST_OPI1OP_COMMON_GROUP_M2(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_M2(test, op)   \
TEST_OPI1OP_COMMON_U_GROUP_M2(test, op)  \

#define TEST_OPI1OP_COMMON_GROUP_M4(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_M4(test, op)   \
TEST_OPI1OP_COMMON_U_GROUP_M4(test, op)  \

#define TEST_OPI1OP_COMMON_GROUP_M8(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_M8(test, op)   \
TEST_OPI1OP_COMMON_U_GROUP_M8(test, op)   \

#define TEST_OPI1OP_COMMON_I_GROUP(test, op) \
TEST_OPI1OP_COMMON_I_GROUP_MF8(test, op)  \
TEST_OPI1OP_COMMON_I_GROUP_MF4(test, op)  \
TEST_OPI1OP_COMMON_I_GROUP_MF2(test, op)  \
TEST_OPI1OP_COMMON_I_GROUP_M1(test, op)   \
TEST_OPI1OP_COMMON_I_GROUP_M2(test, op)   \
TEST_OPI1OP_COMMON_I_GROUP_M4(test, op)   \
TEST_OPI1OP_COMMON_I_GROUP_M8(test, op)   \

#define TEST_OPI1OP_COMMON_U_GROUP(test, op) \
TEST_OPI1OP_COMMON_U_GROUP_MF8(test, op) \
TEST_OPI1OP_COMMON_U_GROUP_MF4(test, op) \
TEST_OPI1OP_COMMON_U_GROUP_MF2(test, op) \
TEST_OPI1OP_COMMON_U_GROUP_M1(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_M2(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_M4(test, op)  \
TEST_OPI1OP_COMMON_U_GROUP_M8(test, op)  \

#define TEST_OPI1OP_COMMON_GROUP(test, op) \
TEST_OPI1OP_COMMON_GROUP_MF8(test, op) \
TEST_OPI1OP_COMMON_GROUP_MF4(test, op) \
TEST_OPI1OP_COMMON_GROUP_MF2(test, op) \
TEST_OPI1OP_COMMON_GROUP_M1(test, op) \
TEST_OPI1OP_COMMON_GROUP_M2(test, op) \
TEST_OPI1OP_COMMON_GROUP_M4(test, op) \
TEST_OPI1OP_COMMON_GROUP_M8(test, op) \

#endif
