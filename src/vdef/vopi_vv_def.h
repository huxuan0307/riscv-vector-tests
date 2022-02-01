#include "common.h"

#define VOPI_VV_INT_DEF(op, type, lmul) \
void op ## _v_v_ ## type ## lmul ## _vec (type* vd, type* vs, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n); \
    VTYPE(type, lmul) v_vs = VLE(type, lmul, &vs[i], vl); \
    VTYPE(type, lmul) v_vd = op##_v_v_##type##lmul(v_vs, vl); \
    VSE(type, lmul, &vd[i], v_vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VV_UINT_DEF(op, type, lmul) \
void op ## _v_v_ ## type ## lmul ## _vec (type* vd, type* vs, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n); \
    VTYPE(type, lmul) v_vs = VLE(type, lmul, &vs[i], vl); \
    VTYPE(type, lmul) v_vd = op##_v_v_##type##lmul(v_vs, vl); \
    VSE(type, lmul, &vd[i], v_vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VV_INT_DEF_GROUP_IMPL(op) \
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

#define VOPI_VV_UINT_DEF_GROUP_IMPL(op) \
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

#define VOPI_VV_INT_DEF_GROUP(op) \
VOPI_VV_INT_DEF_GROUP_IMPL(op ## _V_INT_DEF)

#define VOPI_VV_UINT_DEF_GROUP(op) \
VOPI_VV_UINT_DEF_GROUP_IMPL(op ## _V_UINT_DEF)

#define VOPI_VV_DEF_GROUP(op) \
VOPI_VV_INT_DEF_GROUP(op) \
VOPI_VV_UINT_DEF_GROUP(op)
