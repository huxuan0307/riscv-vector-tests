#ifndef __VDEF_OPF_VVM_H__
#define __VDEF_OPF_VVM_H__

#include "common.h"

#define VOPF_VVM_DEF(op, type, lmul) \
void op##_vv_ ## type ## lmul ## _vec( \
  u8*d, type*s2, type*s1, u64 n \
) { \
  size_t i=0; \
  size_t vl = VSETVL(type, lmul, n); \
  VTYPEB(VBOOL_BITS(type, lmul)) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type, lmul, n - i); \
    debug(vl, "vl[%zu]=%zu\n", i, vl); \
    auto vs1 = VLE(type, lmul, &s1[i], vl); \
    auto vs2 = VLE(type, lmul, &s2[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "=vr"(vd) : "vr"(vs2), "vr"(vs1)); \
    auto offset = i % 8; \
    if (OFFSET_PER_LOOP(type, lmul) >= 8) { \
      vsm(&d[i/8], vd, vl); \
    } \
    else { \
      uint8_t new_res; \
      __asm__("vmv.x.s %0, %1;" : "=r"(new_res) : "vr"(vd)); \
      new_res <<= offset; \
      auto old_res = d[i/8] & ~NEWMASK(type, lmul, offset); \
      d[i/8] = new_res | old_res; \
    } \
    i += vl; \
  } \
} \

#define VOPF_VVM_M_DEF(op, type, lmul) \
void op##_vv_ ## type ## lmul ## _m_vec( \
  u8*d, type*s2, type*s1, const u8* mask, u64 n \
) { \
  size_t i=0; \
  size_t vl = VSETVL(type, lmul, n); \
  VTYPEB(VBOOL_BITS(type, lmul)) vd; \
  VTYPEB(VBOOL_BITS(type, lmul)) vd2; \
  for (i = 0; i < n;) { \
    auto vmask = VLM(VTYPEM(type, lmul), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    vl = VSETVL(type, lmul, n - i); \
    auto vs1 = VLE(type, lmul, &s1[i], vl); \
    auto vs2 = VLE(type, lmul, &s2[i], vl); \
    vd = op(vmask, vd2, vs2, vs1, vl); \
    if (OFFSET_PER_LOOP(type, lmul) >= 8) { \
      vsm(&d[i/8], vd, vl); \
    } \
    else { \
      uint8_t new_res; \
      __asm__("vmv.x.s %0, %1;" : "=r"(new_res) : "vr"(vd)); \
      new_res <<= offset; \
      auto old_res = d[i/8] & ~NEWMASK(type, lmul, offset); \
      d[i/8] = new_res | old_res; \
    } \
    i += vl; \
  } \
} \

#define VOPF_VVM_DEF_GROUP_IMPL(op) \
op (f32, mf2) \
op (f32, m1) \
op (f32, m2) \
op (f32, m4) \
op (f32, m8) \
op (f64, m1) \
op (f64, m2) \
op (f64, m4) \
op (f64, m8)

#define VOPF_VVM_DEF_GROUP(op) VOPF_VVM_DEF_GROUP_IMPL(op ## _VV_DEF)
#define VOPF_VVM_M_DEF_GROUP(op) VOPF_VVM_DEF_GROUP_IMPL(op ## _VV_M_DEF)

/**
 * @brief defination of opf_vvm: (v,v)->m
 * 
 */

#define VMFEQ_VV_DEF(type, lmul) VOPF_VVM_DEF(vmfeq, type, lmul)
#define VMFLE_VV_DEF(type, lmul) VOPF_VVM_DEF(vmfle, type, lmul)
#define VMFLT_VV_DEF(type, lmul) VOPF_VVM_DEF(vmflt, type, lmul)
#define VMFNE_VV_DEF(type, lmul) VOPF_VVM_DEF(vmfne, type, lmul)

VOPF_VVM_DEF_GROUP(VMFEQ)
VOPF_VVM_DEF_GROUP(VMFLE)
VOPF_VVM_DEF_GROUP(VMFLT)
VOPF_VVM_DEF_GROUP(VMFNE)

/**
 * @brief defination of opf_vvm_m: (v,v)->m
 * 
 */

#define VMFEQ_VV_M_DEF(type, lmul) VOPF_VVM_M_DEF(vmfeq, type, lmul)
#define VMFLE_VV_M_DEF(type, lmul) VOPF_VVM_M_DEF(vmfle, type, lmul)
#define VMFLT_VV_M_DEF(type, lmul) VOPF_VVM_M_DEF(vmflt, type, lmul)
#define VMFNE_VV_M_DEF(type, lmul) VOPF_VVM_M_DEF(vmfne, type, lmul)

VOPF_VVM_M_DEF_GROUP(VMFEQ)
VOPF_VVM_M_DEF_GROUP(VMFLE)
VOPF_VVM_M_DEF_GROUP(VMFLT)
VOPF_VVM_M_DEF_GROUP(VMFNE)

// VOPF_VVM_DEF(vmfeq, f32, m1)

// void vmfeq_vv_f32m1_vec(u8 *d, f32 *s2, f32 *s1, u64 n)
// {
//   VTYPEB(VBOOL_BITS(f32, m1))
//   vd;
//   for (i = 0; i < n;)
//   {
//     size_t vl = VSETVL(f32, m1, n - i);
//     debug(vl, "vl[%zu]=%zu\n", i, vl);
//     auto vs1 = VLE(f32, m1, &s1[i], vl);
//     auto vs2 = VLE(f32, m1, &s2[i], vl);
//     __asm__("vmfeq"
//             ".vv %0, %1, %2;"
//             : "=vr"(vd)
//             : "vr"(vs2), "vr"(vs1));
//     auto offset = i % 8;
//     if (OFFSET_PER_LOOP(f32, m1) >= 8)
//     {
//       vsm(&d[i / 8], vd, vl);
//     }
//     else
//     {
//       uint8_t new_res;
//       __asm__("vmv.x.s %0, %1;"
//               : "=r"(new_res)
//               : "vr"(vd));
//       new_res <<= offset;
//       auto old_res = d[i / 8] & ~NEWMASK(f32, m1, offset);
//       d[i / 8] = new_res | old_res;
//     }
//     i += vl;
//   }
// }

#endif
