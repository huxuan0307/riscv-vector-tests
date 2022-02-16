#ifndef __VDEF_OPI_VX_H__
#define __VDEF_OPI_VX_H__

#include "common.h"

#define VMV_X_S_DEF(type, lmul) \
void vmv_x_s_ ## type ## lmul ## _vec (type* d, type* s, u64 n) \
{ \
  size_t rd; \
  auto vl = VSETVL(type, lmul, n); \
  VTYPE(type, lmul) vs = VLE(type, lmul, s, vl); \
  __asm__("vmv.x.s %0, %1;" : "=r"(rd) : "vr"(vs)); \
  d[0] = rd; \
} \

#define VOPI_X_V_INT_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (i8, mf8) \
op (i8, mf4) \
op (i8, mf2) \
op (i8, m1) \
op (i8, m2) \
op (i8, m4) \
op (i8, m8) \
/* int16_t */ \
op (i16, mf4) \
op (i16, mf2) \
op (i16, m1) \
op (i16, m2) \
op (i16, m4) \
op (i16, m8) \
/* int32_t */ \
op (i32, mf2) \
op (i32, m1) \
op (i32, m2) \
op (i32, m4) \
op (i32, m8) \
/* int64_t */ \
op (i64, m1) \
op (i64, m2) \
op (i64, m4) \
op (i64, m8)

#define VOPI_X_V_UINT_DEF_GROUP_IMPL(op) \
/* uint8_t */ \
op (u8, mf8) \
op (u8, mf4) \
op (u8, mf2) \
op (u8, m1) \
op (u8, m2) \
op (u8, m4) \
op (u8, m8) \
/* uint16_t */ \
op (u16, mf4) \
op (u16, mf2) \
op (u16, m1) \
op (u16, m2) \
op (u16, m4) \
op (u16, m8) \
/* uint32_t */ \
op (u32, mf2) \
op (u32, m1) \
op (u32, m2) \
op (u32, m4) \
op (u32, m8) \
/* uint64_t */ \
op (u64, m1) \
op (u64, m2) \
op (u64, m4) \
op (u64, m8)

#define VMV_X_S_DEF_GROUP() \
VOPI_X_V_INT_DEF_GROUP_IMPL   (VMV_X_S_DEF) \
VOPI_X_V_UINT_DEF_GROUP_IMPL  (VMV_X_S_DEF)

VMV_X_S_DEF_GROUP()

#endif
