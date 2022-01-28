#include "common.h"

#define VOPFVVV_DEF(op, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec (type*vd, type*vs2, type*vs1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n); \
    VTYPE(type, lmul) v_vs1 = VLE(type, lmul, &vs1[i], vl); \
    VTYPE(type, lmul) v_vs2 = VLE(type, lmul, &vs2[i], vl); \
    VTYPE(type, lmul) v_res = op##_vv_##type##lmul(v_vs2, v_vs1, vl); \
    VSE(type, lmul, &vd[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPFVVV_DEF_GROUP_IMPL(op) \
op (f32, mf2) \
op (f32, m1) \
op (f32, m2) \
op (f32, m4) \
op (f32, m8) \
op (f64, m1) \
op (f64, m2) \
op (f64, m4) \
op (f64, m8)

#define VOPFVVV_DEF_GROUP(op) \
VOPFVVV_DEF_GROUP_IMPL(op ## _VV_DEF)
