#include "common.h"

#define VOPIVVV_INT_DEF(op, eew, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec (INT(eew)*vd, INT(eew)*vs2, INT(eew)*vs1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(eew, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(eew, lmul, n); \
    VINT(eew, lmul) v_vs1 = VLE(eew, type, lmul, &vs1[i], vl); \
    VINT(eew, lmul) v_vs2 = VLE(eew, type, lmul, &vs2[i], vl); \
    VINT(eew, lmul) v_res = op##_vv_##type##lmul(v_vs2, v_vs1, vl); \
    VSE(eew, type, lmul, &vd[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPIVVV_UINT_DEF(op, eew, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec (UINT(eew)*vd, UINT(eew)*vs2, UINT(eew)*vs1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(eew, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(eew, lmul, n); \
    VINT(eew, lmul) v_vs1 = VLE(eew, type, lmul, &vs1[i], vl); \
    VINT(eew, lmul) v_vs2 = VLE(eew, type, lmul, &vs2[i], vl); \
    VINT(eew, lmul) v_res = op##_vv_##type##lmul(v_vs2, v_vs1, vl); \
    VSE(eew, type, lmul, &vd[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPIVVV_INT_DEF_GROUP_IMPL(op) \
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

#define VOPIVVV_UINT_DEF_GROUP_IMPL(op) \
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

#define VOPIVVV_INT_DEF_GROUP(op) \
VOPIVVV_INT_DEF_GROUP_IMPL(op ## _VV_INT_DEF)

#define VOPIVVV_UINT_DEF_GROUP(op) \
VOPIVVV_UINT_DEF_GROUP_IMPL(op ## _VV_UINT_DEF)

#define VOPIVVV_DEF_GROUP(op) \
VOPIVVV_INT_DEF_GROUP(op) \
VOPIVVV_UINT_DEF_GROUP(op)