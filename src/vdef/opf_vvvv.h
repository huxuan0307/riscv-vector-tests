#include "common.h"

#define VOPF_VVVV_DEF(op, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec ( \
type*d, type*s2, type*s1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n - i); \
    VTYPE(type, lmul) vs1 = VLE(type, lmul, &s1[i], vl); \
    VTYPE(type, lmul) vs2 = VLE(type, lmul, &s2[i], vl); \
    VTYPE(type, lmul) vd = VLE(type, lmul, &d[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "+vr"(vd) : "vr"(vs1), "vr"(vs2)); \
    VSE(type, lmul, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVVV_M_DEF(op, type, lmul) \
void op##_vv_ ## type ## lmul ## _m_vec( \
type*d, type*s2, type*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vlmax = VSETVLMAX(type, lmul); \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type, lmul, n - i); \
    auto vmask = VLM(VTYPEM(type, lmul), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    VTYPE(type, lmul) vs1 = VLE(type, lmul, &s1[i], vl); \
    VTYPE(type, lmul) vs2 = VLE(type, lmul, &s2[i], vl); \
    VTYPE(type, lmul) vd = VLE(type, lmul, &d[i], vl); \
    __asm__(#op ".vv %0, %1, %2, %3.t;" : "+vr"(vd) : "vr"(vs1), "vr"(vs2), "vm"(vmask)); \
    vse_v_ ## type(vmask, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVVV_DEF_GROUP_IMPL(op) \
op (f32, mf2) \
op (f32, m1) \
op (f32, m2) \
op (f32, m4) \
op (f32, m8) \
op (f64, m1) \
op (f64, m2) \
op (f64, m4) \
op (f64, m8)

#define VOPF_VVVV_DEF_GROUP(op)   VOPF_VVVV_DEF_GROUP_IMPL(op ## _VVV_DEF)
#define VOPF_VVVV_M_DEF_GROUP(op) VOPF_VVVV_DEF_GROUP_IMPL(op ## _VVV_M_DEF)

/**
 * @brief defination of opf_vvvv: (v,v,v)->v
 * 
 */

#define VFMACC_VVV_DEF(type, lmul)   VOPF_VVVV_DEF(vfmacc,  type, lmul)
#define VFNMACC_VVV_DEF(type, lmul)  VOPF_VVVV_DEF(vfnmacc, type, lmul)
#define VFMSAC_VVV_DEF(type, lmul)   VOPF_VVVV_DEF(vfmsac,  type, lmul)
#define VFNMSAC_VVV_DEF(type, lmul)  VOPF_VVVV_DEF(vfnmsac, type, lmul)
#define VFMADD_VVV_DEF(type, lmul)   VOPF_VVVV_DEF(vfmadd,  type, lmul)
#define VFNMADD_VVV_DEF(type, lmul)  VOPF_VVVV_DEF(vfnmadd, type, lmul)
#define VFMSUB_VVV_DEF(type, lmul)   VOPF_VVVV_DEF(vfmsub,  type, lmul)
#define VFNMSUB_VVV_DEF(type, lmul)  VOPF_VVVV_DEF(vfnmsub, type, lmul)
VOPF_VVVV_DEF_GROUP(VFMACC)
VOPF_VVVV_DEF_GROUP(VFNMACC)
VOPF_VVVV_DEF_GROUP(VFMSAC)
VOPF_VVVV_DEF_GROUP(VFNMSAC)
VOPF_VVVV_DEF_GROUP(VFMADD)
VOPF_VVVV_DEF_GROUP(VFNMADD)
VOPF_VVVV_DEF_GROUP(VFMSUB)
VOPF_VVVV_DEF_GROUP(VFNMSUB)

/**
 * @brief defination of opf_vvvv_m: (v,v,v)->v
 * 
 */

#define VFMACC_VVV_M_DEF(type, lmul)   VOPF_VVVV_M_DEF(vfmacc,  type, lmul)
#define VFNMACC_VVV_M_DEF(type, lmul)  VOPF_VVVV_M_DEF(vfnmacc, type, lmul)
#define VFMSAC_VVV_M_DEF(type, lmul)   VOPF_VVVV_M_DEF(vfmsac,  type, lmul)
#define VFNMSAC_VVV_M_DEF(type, lmul)  VOPF_VVVV_M_DEF(vfnmsac, type, lmul)
#define VFMADD_VVV_M_DEF(type, lmul)   VOPF_VVVV_M_DEF(vfmadd,  type, lmul)
#define VFNMADD_VVV_M_DEF(type, lmul)  VOPF_VVVV_M_DEF(vfnmadd, type, lmul)
#define VFMSUB_VVV_M_DEF(type, lmul)   VOPF_VVVV_M_DEF(vfmsub,  type, lmul)
#define VFNMSUB_VVV_M_DEF(type, lmul)  VOPF_VVVV_M_DEF(vfnmsub, type, lmul)
VOPF_VVVV_M_DEF_GROUP(VFMACC)
VOPF_VVVV_M_DEF_GROUP(VFNMACC)
VOPF_VVVV_M_DEF_GROUP(VFMSAC)
VOPF_VVVV_M_DEF_GROUP(VFNMSAC)
VOPF_VVVV_M_DEF_GROUP(VFMADD)
VOPF_VVVV_M_DEF_GROUP(VFNMADD)
VOPF_VVVV_M_DEF_GROUP(VFMSUB)
VOPF_VVVV_M_DEF_GROUP(VFNMSUB)
