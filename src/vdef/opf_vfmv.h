#ifndef __VDEF_OPF_VFMV_H__
#define __VDEF_OPF_VFMV_H__

#include "common.h"

#define VOPF_VFMV_DEF(op, type, lmul) \
void op##_vfm_ ## type ## lmul ## _vec( \
type*d, type*s2, type*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  VTYPE(type, lmul) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type, lmul, n - i); \
    auto vmask = VLM(VTYPEM(type, lmul), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    type fs1 = *s1; \
    auto vs2 = VLE(type, lmul, &s2[i], vl); \
    __asm__(#op ".vfm %0, %1, %2, %3;" : "=vr"(vd) : "vr"(vs2), "f"(fs1), "vm"(vmask)); \
    VSE(type, lmul, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VFMV_DEF_GROUP_IMPL(op) \
op (f32, mf2) \
op (f32, m1) \
op (f32, m2) \
op (f32, m4) \
op (f32, m8) \
op (f64, m1) \
op (f64, m2) \
op (f64, m4) \
op (f64, m8)

#define VOPF_VFMV_DEF_GROUP(op) VOPF_VFMV_DEF_GROUP_IMPL(op ## _VF_DEF)

/**
 * @brief defination of opf_vfmv: (v,f,m)->v
 * 
 */

#define VFMERGE_VF_DEF(type, lmul) VOPF_VFMV_DEF(vfmerge, type, lmul)

VOPF_VFMV_DEF_GROUP(VFMERGE)

#endif