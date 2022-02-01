#include "common.h"

#define VOPI_VXV_DEF(op, type2, lmul2, type1, type_ret, lmul_ret) \
void op##_vx_ ## type_ret ## lmul_ret ## _vec(type_ret*d, type2*s2, type1*s1, u64 n) \
{ \
  size_t i; \
  size_t vl = VSETVL(type2, lmul2, n); \
  for (i = 0; i < n;) { \
    vl = VSETVL(type2, lmul2, n); \
    type1 rs1 = *s1; \
    VTYPE(type2, lmul2) vs2 = VLE(type2, lmul2, &s2[i], vl); \
    VTYPE(type_ret, lmul_ret) v_res = op##_vx_##type_ret##lmul_ret(vs2, rs1, vl); \
    VSE(type_ret, lmul_ret, &d[i], v_res, vl); \
    i += vl; \
  } \
} \

#define VOPI_VXV_III_DEF(op, type, lmul) \
VOPI_VXV_DEF(op, type, lmul, type, type, lmul)
#define VOPI_VXV_UUU_DEF VOPI_VXV_III_DEF
#define VOPI_VXV_IUI_DEF(op, type2, type1, lmul) \
VOPI_VXV_DEF(op, type2, lmul, type1, type2, lmul)

#define VOPI_VXV_M_DEF(op, type2, lmul2, type1, type_ret, lmul_ret) \
void op##_vx_ ## type_ret ## lmul_ret ## _m_vec( \ 
type_ret*d, type2*s2, type1*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  size_t vlmax = VSETVLMAX(type2, lmul2); \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type2, lmul2, n); \
    auto vmask = VLM(VTYPEM(type2, lmul2), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    auto rs1 = *s1; \
    auto vs2 = vle_v_ ## type2(vmask, VUNDEF(type2, lmul2), &s2[i], vl); \
    auto vres = op(vmask, VUNDEF(type_ret, lmul_ret), vs2, rs1, vl); \
    vse_v_ ## type_ret(vmask, &d[i], vres, vl); \
    i += vl; \
  } \
} \

#define VOPI_VXV_III_M_DEF(op, type, lmul) \
VOPI_VXV_M_DEF(op, type, lmul, type, type, lmul)
#define VOPI_VXV_UUU_M_DEF VOPI_VXV_III_M_DEF
#define VOPI_VXV_IUI_M_DEF(op, type2, type1, lmul) \
VOPI_VXV_M_DEF(op, type2, lmul, type1, type2, lmul)

#define VOPI_VXV_II_DEF_GROUP_IMPL(op) \
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

#define VOPI_VXV_IU_DEF_GROUP_IMPL(op) \
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

#define VOPI_VXV_UU_DEF_GROUP_IMPL(op) \
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

#define VOPI_VXV_III_DEF_GROUP(op) VOPI_VXV_II_DEF_GROUP_IMPL(op ## _VX_II_DEF)
#define VOPI_VXV_UUU_DEF_GROUP(op) VOPI_VXV_UU_DEF_GROUP_IMPL(op ## _VX_UU_DEF)
#define VOPI_VXV_IUI_DEF_GROUP(op) VOPI_VXV_IU_DEF_GROUP_IMPL(op ## _VX_IU_DEF)
#define VOPI_VXV_DEF_GROUP(op) \
VOPI_VXV_III_DEF_GROUP(op) \
VOPI_VXV_UUU_DEF_GROUP(op)

#define VOPI_VXV_III_M_DEF_GROUP(op) VOPI_VXV_II_DEF_GROUP_IMPL(op ## _VX_II_M_DEF)
#define VOPI_VXV_UUU_M_DEF_GROUP(op) VOPI_VXV_UU_DEF_GROUP_IMPL(op ## _VX_UU_M_DEF)
#define VOPI_VXV_IUI_M_DEF_GROUP(op) VOPI_VXV_IU_DEF_GROUP_IMPL(op ## _VX_IU_M_DEF)
#define VOPI_VXV_M_DEF_GROUP(op) \
VOPI_VXV_III_M_DEF_GROUP(op) \
VOPI_VXV_UUU_M_DEF_GROUP(op)
