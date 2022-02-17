#ifndef __VDEF_OPF_VVWW_H__
#define __VDEF_OPF_VVWW_H__

#include "common.h"

#define VOPF_VVWW_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _vec ( \
type_ret*d, type_arg*s2, type_arg*s1, uint64_t n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type_arg, lmul_arg, n); \
  for (i = 0; i < n;) { \
    VTYPE(type_ret, lmul_ret) vd = VLE(type_ret, lmul_ret, &d[i], vl); \
    vl = VSETVL(type_arg, lmul_arg, n - i); \
    VTYPE(type_arg, lmul_arg) vs1 = VLE(type_arg, lmul_arg, &s1[i], vl); \
    VTYPE(type_arg, lmul_arg) vs2 = VLE(type_arg, lmul_arg, &s2[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "+vr"(vd) : "vr"(vs1), "vr"(vs2)); \
    VSE(type_ret, lmul_ret, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVWW_M_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _m_vec( \
type_ret*d, type_arg*s2, type_arg*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vl = VSETVL(type_arg, lmul_arg, n); \
  for (i = 0; i < n;) { \
    VTYPE(type_ret, lmul_ret) vd = VLE(type_ret, lmul_ret, &d[i], vl); \
    vl = VSETVL(type_arg, lmul_arg, n - i); \
    auto vmask = VLM(VTYPEM(type_arg, lmul_arg), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    VTYPE(type_arg, lmul_arg) vs1 = VLE(type_arg, lmul_arg, &s1[i], vl); \
    VTYPE(type_arg, lmul_arg) vs2 = VLE(type_arg, lmul_arg, &s2[i], vl); \
    __asm__(#op ".vv %0, %1, %2, %3.t;" : "+vr"(vd) : "vr"(vs1), "vr"(vs2), "vm"(vmask)); \
    vse_v_ ## type_ret(vmask, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVWW_DEF_GROUP_IMPL(op) \
op (f32,  mf2,  f64,  m1) \
op (f32,  m1,   f64,  m2) \
op (f32,  m2,   f64,  m4) \
op (f32,  m4,   f64,  m8) \

#define VOPF_VVWW_DEF_GROUP(op)   VOPF_VVWW_DEF_GROUP_IMPL(op ## _VVW_DEF)
#define VOPF_VVWW_M_DEF_GROUP(op) VOPF_VVWW_DEF_GROUP_IMPL(op ## _VVW_M_DEF)

/**
 * @brief defination of opf_vvww: (v,v,v)->v
 * 
 */

#define VFWMACC_VVW_DEF(type_arg, lmul_arg, type_ret, lmul_ret)   VOPF_VVWW_DEF(vfwmacc,  type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWNMACC_VVW_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVWW_DEF(vfwnmacc, type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWMSAC_VVW_DEF(type_arg, lmul_arg, type_ret, lmul_ret)   VOPF_VVWW_DEF(vfwmsac,  type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWNMSAC_VVW_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVWW_DEF(vfwnmsac, type_arg, lmul_arg, type_ret, lmul_ret)

VOPF_VVWW_DEF_GROUP(VFWMACC)
VOPF_VVWW_DEF_GROUP(VFWNMACC)
VOPF_VVWW_DEF_GROUP(VFWMSAC)
VOPF_VVWW_DEF_GROUP(VFWNMSAC)

/**
 * @brief defination of opf_vvww_m: (v,v,v)->v
 * 
 */

#define VFWMACC_VVW_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)   VOPF_VVWW_M_DEF(vfwmacc,  type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWNMACC_VVW_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVWW_M_DEF(vfwnmacc, type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWMSAC_VVW_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)   VOPF_VVWW_M_DEF(vfwmsac,  type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWNMSAC_VVW_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVWW_M_DEF(vfwnmsac, type_arg, lmul_arg, type_ret, lmul_ret)

VOPF_VVWW_M_DEF_GROUP(VFWMACC)
VOPF_VVWW_M_DEF_GROUP(VFWNMACC)
VOPF_VVWW_M_DEF_GROUP(VFWMSAC)
VOPF_VVWW_M_DEF_GROUP(VFWNMSAC)

#endif
