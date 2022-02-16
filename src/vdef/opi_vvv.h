#ifndef __VDEF_OPI_VVV_H__
#define __VDEF_OPI_VVV_H__

#include "common.h"

#define VOPI_VVV_DEF(op, type2, lmul2, type1, lmul1, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _vec(type_ret*vd, type2*vs2, type1*vs1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type2, lmul2, n); \
  VTYPE(type_ret, lmul_ret) v_res; \
  for (i = 0; i < n;) { \
    vl = VSETVL(type2, lmul2, n - i); \
    VTYPE(type1, lmul1) v_vs1 = VLE(type1, lmul1, &vs1[i], vl); \
    VTYPE(type2, lmul2) v_vs2 = VLE(type2, lmul2, &vs2[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "+&vr"(v_res) : "vr"(v_vs2), "vr"(v_vs1)); \
    VSE(type_ret, lmul_ret, &vd[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPI_VVV_III_DEF(op, type, lmul) \
VOPI_VVV_DEF(op, type, lmul, type, lmul, type, lmul)
#define VOPI_VVV_UUU_DEF VOPI_VVV_III_DEF
#define VOPI_VVV_IUI_DEF(op, type2, type1, lmul) \
VOPI_VVV_DEF(op, type2, lmul, type1, lmul, type2, lmul)

#define VOPI_VVV_M_DEF(op, type2, lmul2, type1, lmul1, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _m_vec( \
type_ret*d, type2*s2, type1*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vlmax = VSETVLMAX(type2, lmul2); \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type2, lmul2, n - i); \
    auto vmask = VLM(VTYPEM(type2, lmul2), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    auto vs1 = vle_v_ ## type1(vmask, VUNDEF(type1, lmul1), &s1[i], vl); \
    auto vs2 = vle_v_ ## type2(vmask, VUNDEF(type2, lmul2), &s2[i], vl); \
    auto vres = op(vmask, VUNDEF(type_ret, lmul_ret), vs2, vs1, vl); \
    vse_v_ ## type_ret(vmask, &d[i], vres, vl); \
    i += vl; \
  } \
} \

#define VOPI_VVV_III_M_DEF(op, type, lmul) \
VOPI_VVV_M_DEF(op, type, lmul, type, lmul, type, lmul)
#define VOPI_VVV_UUU_M_DEF VOPI_VVV_III_M_DEF
#define VOPI_VVV_IUI_M_DEF(op, type2, type1, lmul) \
VOPI_VVV_M_DEF(op, type2, lmul, type1, lmul, type2, lmul)


#define VOPI_VVV_II_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (i8, i8, mf8) \
op (i8, i8, mf4) \
op (i8, i8, mf2) \
op (i8, i8, m1) \
op (i8, i8, m2) \
op (i8, i8, m4) \
op (i8, i8, m8) \
/* int16_t */ \
op (i16, i16, mf4) \
op (i16, i16, mf2) \
op (i16, i16, m1) \
op (i16, i16, m2) \
op (i16, i16, m4) \
op (i16, i16, m8) \
/* int32_t */ \
op (i32, i32, mf2) \
op (i32, i32, m1) \
op (i32, i32, m2) \
op (i32, i32, m4) \
op (i32, i32, m8) \
/* int64_t */ \
op (i64, i64, m1) \
op (i64, i64, m2) \
op (i64, i64, m4) \
op (i64, i64, m8)

#define VOPI_VVV_IU_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (i8, u8, mf8) \
op (i8, u8, mf4) \
op (i8, u8, mf2) \
op (i8, u8, m1) \
op (i8, u8, m2) \
op (i8, u8, m4) \
op (i8, u8, m8) \
/* int16_t */ \
op (i16, u16, mf4) \
op (i16, u16, mf2) \
op (i16, u16, m1) \
op (i16, u16, m2) \
op (i16, u16, m4) \
op (i16, u16, m8) \
/* int32_t */ \
op (i32, u32, mf2) \
op (i32, u32, m1) \
op (i32, u32, m2) \
op (i32, u32, m4) \
op (i32, u32, m8) \
/* int64_t */ \
op (i64, u64, m1) \
op (i64, u64, m2) \
op (i64, u64, m4) \
op (i64, u64, m8)

#define VOPI_VVV_UU_DEF_GROUP_IMPL(op) \
/* uint8_t */ \
op (u8, u8, mf8) \
op (u8, u8, mf4) \
op (u8, u8, mf2) \
op (u8, u8, m1) \
op (u8, u8, m2) \
op (u8, u8, m4) \
op (u8, u8, m8) \
/* uint16_t */ \
op (u16, u16, mf4) \
op (u16, u16, mf2) \
op (u16, u16, m1) \
op (u16, u16, m2) \
op (u16, u16, m4) \
op (u16, u16, m8) \
/* uint32_t */ \
op (u32, u32, mf2) \
op (u32, u32, m1) \
op (u32, u32, m2) \
op (u32, u32, m4) \
op (u32, u32, m8) \
/* uint64_t */ \
op (u64, u64, m1) \
op (u64, u64, m2) \
op (u64, u64, m4) \
op (u64, u64, m8)

#define VOPI_VVV_III_DEF_GROUP(op) VOPI_VVV_II_DEF_GROUP_IMPL(op ## _VV_II_DEF)
#define VOPI_VVV_UUU_DEF_GROUP(op) VOPI_VVV_UU_DEF_GROUP_IMPL(op ## _VV_UU_DEF)
#define VOPI_VVV_IUI_DEF_GROUP(op) VOPI_VVV_IU_DEF_GROUP_IMPL(op ## _VV_IU_DEF)

#define VOPI_VVV_DEF_GROUP(op) \
VOPI_VVV_III_DEF_GROUP(op) \
VOPI_VVV_UUU_DEF_GROUP(op)

#define VOPI_VVV_III_M_DEF_GROUP(op) VOPI_VVV_II_DEF_GROUP_IMPL(op ## _VV_II_M_DEF)
#define VOPI_VVV_UUU_M_DEF_GROUP(op) VOPI_VVV_UU_DEF_GROUP_IMPL(op ## _VV_UU_M_DEF)
#define VOPI_VVV_IUI_M_DEF_GROUP(op) VOPI_VVV_IU_DEF_GROUP_IMPL(op ## _VV_IU_M_DEF)

#define VOPI_VVV_M_DEF_GROUP(op) \
VOPI_VVV_III_M_DEF_GROUP(op) \
VOPI_VVV_UUU_M_DEF_GROUP(op)

/**
 * @brief defination of opi_vvv: (v, v)->v
 * 
 */

#define VADD_VV_II_DEF(type, _, lmul) VOPI_VVV_III_DEF (vadd, type, lmul)
#define VADD_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vadd, type, lmul)
#define VSUB_VV_II_DEF(type, _, lmul) VOPI_VVV_III_DEF (vsub, type, lmul)
#define VSUB_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vsub, type, lmul)

VOPI_VVV_DEF_GROUP(VADD)
VOPI_VVV_DEF_GROUP(VSUB)

#define VMIN_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vmin, type, lmul)
#define VMAX_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vmax, type, lmul)
#define VMINU_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vmaxu, type, lmul)

VOPI_VVV_III_DEF_GROUP(VMIN)
VOPI_VVV_III_DEF_GROUP(VMAX)
VOPI_VVV_UUU_DEF_GROUP(VMINU)
VOPI_VVV_UUU_DEF_GROUP(VMAXU)

#define VAND_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vand, type, lmul)
#define VAND_VV_UU_DEF(type, _, lmul)  VOPI_VVV_UUU_DEF (vand, type, lmul)
#define VOR_VV_II_DEF(type, _, lmul)   VOPI_VVV_III_DEF (vor, type, lmul)
#define VOR_VV_UU_DEF(type, _, lmul)   VOPI_VVV_UUU_DEF (vor, type, lmul)
#define VXOR_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vxor, type, lmul)
#define VXOR_VV_UU_DEF(type, _, lmul)  VOPI_VVV_UUU_DEF (vxor, type, lmul)

VOPI_VVV_DEF_GROUP(VAND)
VOPI_VVV_DEF_GROUP(VOR)
VOPI_VVV_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vrgather, type, lmul)

VOPI_VVV_IUI_DEF_GROUP(VRGATHER)
VOPI_VVV_UUU_DEF_GROUP(VRGATHER)

#define VSLL_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vsll, type, lmul)
#define VSRA_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vsrl, type, lmul)

VOPI_VVV_IUI_DEF_GROUP(VSLL)
VOPI_VVV_UUU_DEF_GROUP(VSLL)
VOPI_VVV_IUI_DEF_GROUP(VSRA)
VOPI_VVV_UUU_DEF_GROUP(VSRL)

/**
 * @brief defination of opi_vvv_m: (v, v)->v
 * 
 */

#define VADD_VV_II_M_DEF(type, _, lmul) VOPI_VVV_III_M_DEF (vadd, type, lmul)
#define VADD_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vadd, type, lmul)
#define VSUB_VV_II_M_DEF(type, _, lmul) VOPI_VVV_III_M_DEF (vsub, type, lmul)
#define VSUB_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vsub, type, lmul)
VOPI_VVV_M_DEF_GROUP(VADD)
VOPI_VVV_M_DEF_GROUP(VSUB)

#define VMIN_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vmin, type, lmul)
#define VMAX_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vmax, type, lmul)
#define VMINU_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vmaxu, type, lmul)
VOPI_VVV_III_M_DEF_GROUP(VMIN)
VOPI_VVV_III_M_DEF_GROUP(VMAX)
VOPI_VVV_UUU_M_DEF_GROUP(VMINU)
VOPI_VVV_UUU_M_DEF_GROUP(VMAXU)

#define VAND_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vand, type, lmul)
#define VAND_VV_UU_M_DEF(type, _, lmul)  VOPI_VVV_UUU_M_DEF (vand, type, lmul)
#define VOR_VV_II_M_DEF(type, _, lmul)   VOPI_VVV_III_M_DEF (vor, type, lmul)
#define VOR_VV_UU_M_DEF(type, _, lmul)   VOPI_VVV_UUU_M_DEF (vor, type, lmul)
#define VXOR_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vxor, type, lmul)
#define VXOR_VV_UU_M_DEF(type, _, lmul)  VOPI_VVV_UUU_M_DEF (vxor, type, lmul)
VOPI_VVV_M_DEF_GROUP(VAND)
VOPI_VVV_M_DEF_GROUP(VOR)
VOPI_VVV_M_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_M_DEF(type2, type1, lmul) VOPI_VVV_IUI_M_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vrgather, type, lmul)
VOPI_VVV_IUI_M_DEF_GROUP(VRGATHER)
VOPI_VVV_UUU_M_DEF_GROUP(VRGATHER)

#define VSLL_VV_IU_M_DEF(type2, type1, lmul) VOPI_VVV_IUI_M_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vsll, type, lmul)
#define VSRA_VV_IU_M_DEF(type2, type1, lmul) VOPI_VVV_IUI_M_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vsrl, type, lmul)

VOPI_VVV_IUI_M_DEF_GROUP(VSLL)
VOPI_VVV_UUU_M_DEF_GROUP(VSLL)
VOPI_VVV_IUI_M_DEF_GROUP(VSRA)
VOPI_VVV_UUU_M_DEF_GROUP(VSRL)

#endif
