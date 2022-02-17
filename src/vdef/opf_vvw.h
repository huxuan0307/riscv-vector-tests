#ifndef __VDEF_OPF_VVW_H__
#define __VDEF_OPF_VVW_H__

#include "common.h"

#define VOPF_VVW_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _vec(type_ret*d, type_arg*s2, type_arg*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type_arg, lmul_arg, n); \
  VTYPE(type_ret, lmul_ret) vd; \
  for (i = 0; i < n;) { \
    vl = VSETVL(type_arg, lmul_arg, n - i); \
    VTYPE(type_arg, lmul_arg) vs1 = VLE(type_arg, lmul_arg, &s1[i], vl); \
    VTYPE(type_arg, lmul_arg) vs2 = VLE(type_arg, lmul_arg, &s2[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "=&vr"(vd) : "vr"(vs2), "vr"(vs1)); \
    VSE(type_ret, lmul_ret, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVW_M_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _m_vec( \
  type_ret*d, type_arg*s2, type_arg*s1, const u8* mask, u64 n) \
{ \
  size_t i; \
  size_t vlmax = VSETVLMAX(type_arg, lmul_arg); \
  VTYPE(type_ret, lmul_ret) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type_arg, lmul_arg, n - i); \
    auto vmask = VLM(VTYPEM(type_arg, lmul_arg), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    auto vs1 = vle_v_ ## type_arg(vmask, VUNDEF(type_arg, lmul_arg), &s1[i], vl); \
    auto vs2 = vle_v_ ## type_arg(vmask, VUNDEF(type_arg, lmul_arg), &s2[i], vl); \
    __asm__(#op ".vv %0, %1, %2, %3.t;" : "=&vr"(vd) : "vr"(vs2), "vr"(vs1), "vm"(vmask)); \
    vse_v_ ## type_ret(vmask, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPF_VVW_DEF_GROUP_IMPL(op) \
op (f32,  mf2,  f64,  m1) \
op (f32,  m1,   f64,  m2) \
op (f32,  m2,   f64,  m4) \
op (f32,  m4,   f64,  m8) \

#define VOPF_VVW_DEF_GROUP(op)    VOPF_VVW_DEF_GROUP_IMPL(op ## _VV_DEF)
#define VOPF_VVW_M_DEF_GROUP(op)  VOPF_VVW_DEF_GROUP_IMPL(op ## _VV_M_DEF)

/**
 * @brief defination of opf_vvw: (v, v)->wv
 * 
 */

#define VFWADD_VV_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVW_DEF(vfwadd, type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWSUB_VV_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVW_DEF(vfwsub, type_arg, lmul_arg, type_ret, lmul_ret)
VOPF_VVW_DEF_GROUP(VFWADD)
VOPF_VVW_DEF_GROUP(VFWSUB)

/**
 * @brief defination of opf_vvw_m: (v, v)->wv
 * 
 */

#define VFWADD_VV_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVW_M_DEF(vfwadd, type_arg, lmul_arg, type_ret, lmul_ret)
#define VFWSUB_VV_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)  VOPF_VVW_M_DEF(vfwsub, type_arg, lmul_arg, type_ret, lmul_ret)
VOPF_VVW_M_DEF_GROUP(VFWADD)
VOPF_VVW_M_DEF_GROUP(VFWSUB)

#endif
