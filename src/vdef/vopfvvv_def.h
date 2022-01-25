#include "common.h"

#define VOPFVVV_DEF(op, eew, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec (FLOAT(eew)*vd, FLOAT(eew)*vs2, FLOAT(eew)*vs1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(eew, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(eew, lmul, n); \
    VFLOAT(eew, lmul) v_vs1 = VLE(eew, type, lmul, &vs1[i], vl); \
    VFLOAT(eew, lmul) v_vs2 = VLE(eew, type, lmul, &vs2[i], vl); \
    VFLOAT(eew, lmul) v_res = op##_vv_##type##lmul(v_vs2, v_vs1, vl); \
    VSE(eew, type, lmul, &vd[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPFVVV_DEF_GROUP_IMPL(op) \
/* float_t */ \
op (32, f32, mf2) \
op (32, f32, m1) \
op (32, f32, m2) \
op (32, f32, m4) \
op (32, f32, m8) \
/* int64_t */ \
op (64, f64, m1) \
op (64, f64, m2) \
op (64, f64, m4) \
op (64, f64, m8)

#define VOPFVVV_DEF_GROUP(op) \
VOPFVVV_DEF_GROUP_IMPL(op ## _VV_DEF)
