#ifndef __VDEF_OPI_VWW_H__
#define __VDEF_OPI_VWW_H__

#include "common.h"

#define VOPI_VWW_DEF(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
void op##_wv_ ## type_ret ## lmul_ret ## _vec(type_ret*d, type2*s2, type1*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type1, lmul_arg, n); \
  VTYPE(type_ret, lmul_ret) vd; \
  for (i = 0; i < n;) { \
    vl = VSETVL(type1, lmul_arg, n - i); \
    VTYPE(type1, lmul_arg) vs1 = VLE(type1, lmul_arg, &s1[i], vl); \
    VTYPE(type2, lmul_ret) vs2 = VLE(type2, lmul_ret, &s2[i], vl); \
    VTYPE(type_ret, lmul_ret) vd = op ## _wv(vs2, vs1, vl); \
    /*__asm__(#op ".wv %0, %1, %2;" : "=&vr"(vd) : "vr"(vs2), "vr"(vs1));*/ \
    VSE(type_ret, lmul_ret, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VWW_M_DEF(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
void op##_wv_ ## type_ret ## lmul_ret ## _m_vec( \
  type_ret*d, type2*s2, type1*s1, const u8* mask, u64 n) \
{ \
  size_t i; \
  size_t vlmax = VSETVLMAX(type1, lmul_arg); \
  VTYPE(type_ret, lmul_ret) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type1, lmul_arg, n - i); \
    auto vmask = VLM(VTYPEM(type1, lmul_arg), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    auto vs1 = vle_v_ ## type1(vmask, VUNDEF(type1, lmul_arg), &s1[i], vl); \
    auto vs2 = vle_v_ ## type2(vmask, VUNDEF(type2, lmul_ret), &s2[i], vl); \
    __asm__(#op ".wv %0, %1, %2, %3.t;" : "=&vr"(vd) : "vr"(vs2), "vr"(vs1), "vm"(vmask)); \
    vse_v_ ## type_ret(vmask, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VWW_III_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
VOPI_VWW_DEF(op, type_ret, type_arg, lmul_arg, type_ret, lmul_ret)
#define VOPI_VWW_UUU_DEF VOPI_VWW_III_DEF
#define VOPI_VWW_IUI_DEF VOPI_VWW_DEF

#define VOPI_VWW_III_M_DEF(op, type_arg, lmul_arg, type_ret, lmul_ret) \
VOPI_VWW_M_DEF(op, type_ret, type_arg, lmul_arg, type_ret, lmul_ret)
#define VOPI_VWW_UUU_M_DEF VOPI_VWW_III_M_DEF
#define VOPI_VWW_IUI_M_DEF VOPI_VWW_M_DEF

#define VOPI_VWW_II_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (i8,   mf8,  i16,  mf4) \
op (i8,   mf4,  i16,  mf2) \
op (i8,   mf2,  i16,  m1) \
op (i8,   m1,   i16,  m2) \
op (i8,   m2,   i16,  m4) \
op (i8,   m4,   i16,  m8) \
/* int16_t */ \
op (i16,  mf4,  i32,  mf2) \
op (i16,  mf2,  i32,  m1) \
op (i16,  m1,   i32,  m2) \
op (i16,  m2,   i32,  m4) \
op (i16,  m4,   i32,  m8) \
/* int32_t */ \
op (i32,  mf2,  i64,  m1) \
op (i32,  m1,   i64,  m2) \
op (i32,  m2,   i64,  m4) \
op (i32,  m4,   i64,  m8) \

#define VOPI_VWW_UU_DEF_GROUP_IMPL(op) \
/* uint8_t */ \
op (u8,   mf8,  u16,  mf4) \
op (u8,   mf4,  u16,  mf2) \
op (u8,   mf2,  u16,  m1) \
op (u8,   m1,   u16,  m2) \
op (u8,   m2,   u16,  m4) \
op (u8,   m4,   u16,  m8) \
/* uint16_t */ \
op (u16,  mf4,  u32,  mf2) \
op (u16,  mf2,  u32,  m1) \
op (u16,  m1,   u32,  m2) \
op (u16,  m2,   u32,  m4) \
op (u16,  m4,   u32,  m8) \
/* uint32_t */ \
op (u32,  mf2,  u64,  m1) \
op (u32,  m1,   u64,  m2) \
op (u32,  m2,   u64,  m4) \
op (u32,  m4,   u64,  m8) \

#define VOPI_VWW_IU_DEF_GROUP_IMPL(op) \
op (i8,   u8,   mf8,  i16,  mf4) \
op (i8,   u8,   mf4,  i16,  mf2) \
op (i8,   u8,   mf2,  i16,  m1) \
op (i8,   u8,   m1,   i16,  m2) \
op (i8,   u8,   m2,   i16,  m4) \
op (i8,   u8,   m4,   i16,  m8) \
op (i16,  u16,  mf4,  i32,  mf2) \
op (i16,  u16,  mf2,  i32,  m1) \
op (i16,  u16,  m1,   i32,  m2) \
op (i16,  u16,  m2,   i32,  m4) \
op (i16,  u16,  m4,   i32,  m8) \
op (i32,  u32,  mf2,  i64,  m1) \
op (i32,  u32,  m1,   i64,  m2) \
op (i32,  u32,  m2,   i64,  m4) \
op (i32,  u32,  m4,   i64,  m8) \

#define VOPI_VWW_III_DEF_GROUP(op) VOPI_VWW_II_DEF_GROUP_IMPL(op ## _WV_II_DEF)
#define VOPI_VWW_UUU_DEF_GROUP(op) VOPI_VWW_UU_DEF_GROUP_IMPL(op ## _WV_UU_DEF)
#define VOPI_VWW_IUI_DEF_GROUP(op) VOPI_VWW_IU_DEF_GROUP_IMPL(op ## _WV_IU_DEF)

#define VOPI_VWW_III_M_DEF_GROUP(op) VOPI_VWW_II_DEF_GROUP_IMPL(op ## _WV_II_M_DEF)
#define VOPI_VWW_UUU_M_DEF_GROUP(op) VOPI_VWW_UU_DEF_GROUP_IMPL(op ## _WV_UU_M_DEF)
#define VOPI_VWW_IUI_M_DEF_GROUP(op) VOPI_VWW_IU_DEF_GROUP_IMPL(op ## _WV_IU_M_DEF)

/**
 * @brief defination of opi_vww: (v, v)->wv
 * 
 */

#define VWADD_WV_II_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_DEF(vwadd,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWSUB_WV_II_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_DEF(vwsub,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWADDU_WV_UU_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_DEF(vwaddu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWSUBU_WV_UU_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_DEF(vwsubu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMUL_WV_II_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_DEF(vwmul,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMULU_WV_UU_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_DEF(vwmulu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMULSU_WV_IU_DEF(type2, type1, lmul_arg, type_ret, lmul_ret) VOPI_VWW_IUI_DEF(vwmulsu,  type2, type1,  lmul_arg, type_ret, lmul_ret)

VOPI_VWW_III_DEF_GROUP(VWADD)
VOPI_VWW_III_DEF_GROUP(VWSUB)
VOPI_VWW_UUU_DEF_GROUP(VWADDU)
VOPI_VWW_UUU_DEF_GROUP(VWSUBU)

/**
 * @brief defination of opi_vww_m: (v, v)->wv
 * 
 */

#define VWADD_WV_II_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_M_DEF(vwadd,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWSUB_WV_II_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_M_DEF(vwsub,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWADDU_WV_UU_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_M_DEF(vwaddu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWSUBU_WV_UU_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_M_DEF(vwsubu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMUL_WV_II_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)       VOPI_VWW_III_M_DEF(vwmul,    type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMULU_WV_UU_M_DEF(type_arg, lmul_arg, type_ret, lmul_ret)      VOPI_VWW_UUU_M_DEF(vwmulu,   type_arg,      lmul_arg, type_ret, lmul_ret)
#define VWMULSU_WV_IU_M_DEF(type2, type1, lmul_arg, type_ret, lmul_ret) VOPI_VWW_IUI_M_DEF(vwmulsu,  type2, type1,  lmul_arg, type_ret, lmul_ret)

VOPI_VWW_III_M_DEF_GROUP(VWADD)
VOPI_VWW_III_M_DEF_GROUP(VWSUB)
VOPI_VWW_UUU_M_DEF_GROUP(VWADDU)
VOPI_VWW_UUU_M_DEF_GROUP(VWSUBU)

#endif
