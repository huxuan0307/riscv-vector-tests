#include "common.h"

#define VOPF_VFV_DEF(op, type, lmul) \
void op##_vf_ ## type ## lmul ## _vec(type*d, type*s2, type*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n); \
    type fs1 = *s1; \
    VTYPE(type, lmul) vs2 = VLE(type, lmul, &s2[i], vl); \
    VTYPE(type, lmul) v_res = op##_vf_##type##lmul(vs2, fs1, vl); \
    VSE(type, lmul, &d[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPF_VFV_M_DEF(op, type, lmul) \
void op##_vf_ ## type ## lmul ## _m_vec( \
type*d, type*s2, type*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vlmax = VSETVLMAX(type, lmul); \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type, lmul, n); \
    auto vmask = VLM(VTYPEM(type, lmul), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    auto rs1 = *s1; \
    auto vs2 = vle_v_ ## type(vmask, VUNDEF(type, lmul), &s2[i], vl); \
    auto vres = op(vmask, VUNDEF(type, lmul), vs2, rs1, vl); \
    vse_v_ ## type(vmask, &d[i], vres, vl); \
    i += vl; \
  } \
} \

#define VOPF_VFV_DEF_GROUP_IMPL(op) \
op (f32, mf2) \
op (f32, m1) \
op (f32, m2) \
op (f32, m4) \
op (f32, m8) \
op (f64, m1) \
op (f64, m2) \
op (f64, m4) \
op (f64, m8)

#define VOPF_VFV_DEF_GROUP(op)    VOPF_VFV_DEF_GROUP_IMPL(op ## _VF_DEF)
#define VOPF_VFV_M_DEF_GROUP(op)  VOPF_VFV_DEF_GROUP_IMPL(op ## _VF_M_DEF)
