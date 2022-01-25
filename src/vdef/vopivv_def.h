#include "common.h"

#define VOPIVV_INT_DEF(op, eew, type, lmul) \
void op ## _v_v_ ## type ## lmul ## _vec (INT(eew)* vd, INT(eew)* vs, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(eew, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(eew, lmul, n); \
    VINT(eew, lmul) v_vs = VLE(eew, type, lmul, &vs[i], vl); \
    VINT(eew, lmul) v_vd = op##_v_v_##type##lmul(v_vs, vl); \
    VSE(eew, type, lmul, &vd[i], v_vd, vl); \
    i += vl; \
  } \
} \

#define VOPIVV_UINT_DEF(op, eew, type, lmul) \
void op ## _v_v_ ## type ## lmul ## _vec (UINT(eew)* vd, UINT(eew)* vs, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(eew, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(eew, lmul, n); \
    VINT(eew, lmul) v_vs = VLE(eew, type, lmul, &vs[i], vl); \
    VINT(eew, lmul) v_vd = op##_v_v_##type##lmul(v_vs, vl); \
    VSE(eew, type, lmul, &vd[i], v_vd, vl); \
    i += vl; \
  } \
} \

#define VOPIVV_INT_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (8, i8, mf8) \
op (8, i8, mf4) \
op (8, i8, mf2) \
op (8, i8, m1) \
op (8, i8, m2) \
op (8, i8, m4) \
op (8, i8, m8) \
/* int16_t */ \
op (16, i16, mf4) \
op (16, i16, mf2) \
op (16, i16, m1) \
op (16, i16, m2) \
op (16, i16, m4) \
op (16, i16, m8) \
/* int32_t */ \
op (32, i32, mf2) \
op (32, i32, m1) \
op (32, i32, m2) \
op (32, i32, m4) \
op (32, i32, m8) \
/* int64_t */ \
op (64, i64, m1) \
op (64, i64, m2) \
op (64, i64, m4) \
op (64, i64, m8)

#define VOPIVV_UINT_DEF_GROUP_IMPL(op) \
/* uint8_t */ \
op (8, u8, mf8) \
op (8, u8, mf4) \
op (8, u8, mf2) \
op (8, u8, m1) \
op (8, u8, m2) \
op (8, u8, m4) \
op (8, u8, m8) \
/* uint16_t */ \
op (16, u16, mf4) \
op (16, u16, mf2) \
op (16, u16, m1) \
op (16, u16, m2) \
op (16, u16, m4) \
op (16, u16, m8) \
/* uint32_t */ \
op (32, u32, mf2) \
op (32, u32, m1) \
op (32, u32, m2) \
op (32, u32, m4) \
op (32, u32, m8) \
/* uint64_t */ \
op (64, u64, m1) \
op (64, u64, m2) \
op (64, u64, m4) \
op (64, u64, m8)

#define VOPIVV_INT_DEF_GROUP(op) \
VOPIVV_INT_DEF_GROUP_IMPL(op ## _V_INT_DEF)

#define VOPIVV_UINT_DEF_GROUP(op) \
VOPIVV_UINT_DEF_GROUP_IMPL(op ## _V_UINT_DEF)

#define VOPIVV_DEF_GROUP(op) \
VOPIVV_INT_DEF_GROUP(op) \
VOPIVV_UINT_DEF_GROUP(op)