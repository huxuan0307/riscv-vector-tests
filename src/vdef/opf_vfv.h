#ifndef __VDEF_OPF_VFV_H__
#define __VDEF_OPF_VFV_H__

#include "common.h"

#define VOPF_VFV_DEF(op, type, lmul) \
void op##_vf_ ## type ## lmul ## _vec(type*d, type*s2, type*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type, lmul, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type, lmul, n - i); \
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
    size_t vl = VSETVL(type, lmul, n - i); \
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

/**
 * @brief defination of opf_vfv: (v,f)->v
 * 
 */

#define VFADD_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfadd, type, lmul)
#define VFSUB_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfsub, type, lmul)
#define VFRSUB_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfrsub, type, lmul)
#define VFMUL_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmul, type, lmul)
#define VFDIV_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfdiv, type, lmul)
#define VFRDIV_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfrdiv, type, lmul)
#define VFMAX_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmax, type, lmul)
#define VFMIN_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmin, type, lmul)
#define VFSGNJ_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VF_DEF(type, lmul)  VOPF_VFV_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VF_DEF(type, lmul)  VOPF_VFV_DEF(vfsgnjx, type, lmul)
VOPF_VFV_DEF_GROUP(VFADD)
VOPF_VFV_DEF_GROUP(VFSUB)
VOPF_VFV_DEF_GROUP(VFRSUB)
VOPF_VFV_DEF_GROUP(VFMUL)
VOPF_VFV_DEF_GROUP(VFDIV)
VOPF_VFV_DEF_GROUP(VFRDIV)
VOPF_VFV_DEF_GROUP(VFMAX)
VOPF_VFV_DEF_GROUP(VFMIN)
VOPF_VFV_DEF_GROUP(VFSGNJ)
VOPF_VFV_DEF_GROUP(VFSGNJN)
VOPF_VFV_DEF_GROUP(VFSGNJX)

/**
 * @brief defination of opf_vfv_m: (v,f)->v
 * 
 */

#define VFADD_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfadd, type, lmul)
#define VFSUB_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfsub, type, lmul)
#define VFRSUB_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfrsub, type, lmul)
#define VFMUL_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmul, type, lmul)
#define VFDIV_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfdiv, type, lmul)
#define VFRDIV_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfrdiv, type, lmul)
#define VFMAX_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmax, type, lmul)
#define VFMIN_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmin, type, lmul)
#define VFSGNJ_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VF_M_DEF(type, lmul)  VOPF_VFV_M_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VF_M_DEF(type, lmul)  VOPF_VFV_M_DEF(vfsgnjx, type, lmul)
VOPF_VFV_M_DEF_GROUP(VFADD)
VOPF_VFV_M_DEF_GROUP(VFSUB)
VOPF_VFV_M_DEF_GROUP(VFRSUB)
VOPF_VFV_M_DEF_GROUP(VFMUL)
VOPF_VFV_M_DEF_GROUP(VFDIV)
VOPF_VFV_M_DEF_GROUP(VFRDIV)
VOPF_VFV_M_DEF_GROUP(VFMAX)
VOPF_VFV_M_DEF_GROUP(VFMIN)
VOPF_VFV_M_DEF_GROUP(VFSGNJ)
VOPF_VFV_M_DEF_GROUP(VFSGNJN)
VOPF_VFV_M_DEF_GROUP(VFSGNJX)

#endif
