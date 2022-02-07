#include "common.h"

#define VOPI_VVVV_DEF(op, type2, lmul2, type1, lmul1, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _vec(type_ret*d, type2*s2, type1*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type2, lmul2, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type2, lmul2, n); \
    VTYPE(type1, lmul1) vs1 = VLE(type1, lmul1, &s1[i], vl); \
    VTYPE(type2, lmul2) vs2 = VLE(type2, lmul2, &s2[i], vl); \
    VTYPE(type_ret, lmul_ret) vd = VLE(type_ret, lmul_ret, &d[i], vl); \
    __asm__(#op ".vv %0, %1, %2;" : "+&vr"(vd) : "vr"(vs1), "vr"(vs2)); \
    VSE(type_ret, lmul_ret, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VVVV_III_DEF(op, type, lmul) \
VOPI_VVVV_DEF(op, type, lmul, type, lmul, type, lmul)
#define VOPI_VVVV_UUU_DEF VOPI_VVVV_III_DEF
#define VOPI_VVVV_IUI_DEF(op, type2, type1, lmul) \
VOPI_VVVV_DEF(op, type2, lmul, type1, lmul, type2, lmul)

#define VOPI_VVVV_M_DEF(op, type2, lmul2, type1, lmul1, type_ret, lmul_ret) \
void op##_vv_ ## type_ret ## lmul_ret ## _m_vec( \
type_ret*d, type2*s2, type1*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vlmax = VSETVLMAX(type2, lmul2); \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type2, lmul2, n); \
    auto vmask = VLM(VTYPEM(type2, lmul2), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    VTYPE(type1, lmul1) vs1 = VLE(type1, lmul1, &s1[i], vl); \
    VTYPE(type2, lmul2) vs2 = VLE(type2, lmul2, &s2[i], vl); \
    VTYPE(type_ret, lmul_ret) vd = VLE(type_ret, lmul_ret, &d[i], vl); \
    __asm__(#op ".vv %0, %1, %2, %3.t;" : "+&vr"(vd) : "vr"(vs1), "vr"(vs2), "vm"(vmask)); \
    vse_v_ ## type_ret(vmask, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VVVV_III_M_DEF(op, type, lmul) \
VOPI_VVVV_M_DEF(op, type, lmul, type, lmul, type, lmul)
#define VOPI_VVVV_UUU_M_DEF VOPI_VVVV_III_M_DEF
#define VOPI_VVVV_IUI_M_DEF(op, type2, type1, lmul) \
VOPI_VVVV_M_DEF(op, type2, lmul, type1, lmul, type2, lmul)

#define VOPI_VVVV_II_DEF_GROUP_IMPL(op) \
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

#define VOPI_VVVV_IU_DEF_GROUP_IMPL(op) \
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

#define VOPI_VVVV_UU_DEF_GROUP_IMPL(op) \
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

#define VOPI_VVVV_III_DEF_GROUP(op) VOPI_VVVV_II_DEF_GROUP_IMPL(op ## _VVV_II_DEF)
#define VOPI_VVVV_UUU_DEF_GROUP(op) VOPI_VVVV_UU_DEF_GROUP_IMPL(op ## _VVV_UU_DEF)
#define VOPI_VVVV_IUI_DEF_GROUP(op) VOPI_VVVV_IU_DEF_GROUP_IMPL(op ## _VVV_IU_DEF)

#define VOPI_VVVV_DEF_GROUP(op) \
VOPI_VVVV_III_DEF_GROUP(op) \
VOPI_VVVV_UUU_DEF_GROUP(op)

#define VOPI_VVVV_III_M_DEF_GROUP(op) VOPI_VVVV_II_DEF_GROUP_IMPL(op ## _VVV_II_M_DEF)
#define VOPI_VVVV_UUU_M_DEF_GROUP(op) VOPI_VVVV_UU_DEF_GROUP_IMPL(op ## _VVV_UU_M_DEF)
#define VOPI_VVVV_IUI_M_DEF_GROUP(op) VOPI_VVVV_IU_DEF_GROUP_IMPL(op ## _VVV_IU_M_DEF)

#define VOPI_VVVV_M_DEF_GROUP(op) \
VOPI_VVVV_III_M_DEF_GROUP(op) \
VOPI_VVVV_UUU_M_DEF_GROUP(op)
