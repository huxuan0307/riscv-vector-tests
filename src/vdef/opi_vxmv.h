#include "common.h"

#define VOPI_VXMV_DEF(op, type, lmul) \
void op##_vxm_ ## type ## lmul ## _vec( \
type*d, type*s2, type*s1, const u8* mask, u64 n) \
{ \
  size_t i=0; \
  VTYPE(type, lmul) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type, lmul, n); \
    auto vmask = VLM(VTYPEM(type, lmul), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    type rs1 = *s1; \
    auto vs2 = VLE(type, lmul, &s2[i], vl); \
    __asm__(#op ".vxm %0, %1, %2, %3;" : "=vr"(vd) : "vr"(vs2), "r"(rs1), "vm"(vmask)); \
    VSE(type, lmul, &d[i], vd, vl); \
    i += vl; \
  } \
} \

#define VOPI_VXMV_III_DEF VOPI_VXMV_DEF
#define VOPI_VXMV_UUU_DEF VOPI_VXMV_DEF

#define VOPI_VXMV_II_DEF_GROUP_IMPL(op) \
/* int8_t */ \
op (i8, mf8) \
op (i8, mf4) \
op (i8, mf2) \
op (i8, m1) \
op (i8, m2) \
op (i8, m4) \
op (i8, m8) \
/* int16_t */ \
op (i16, mf4) \
op (i16, mf2) \
op (i16, m1) \
op (i16, m2) \
op (i16, m4) \
op (i16, m8) \
/* int32_t */ \
op (i32, mf2) \
op (i32, m1) \
op (i32, m2) \
op (i32, m4) \
op (i32, m8) \
/* int64_t */ \
op (i64, m1) \
op (i64, m2) \
op (i64, m4) \
op (i64, m8)

#define VOPI_VXMV_UU_DEF_GROUP_IMPL(op) \
/* uint8_t */ \
op (u8, mf8) \
op (u8, mf4) \
op (u8, mf2) \
op (u8, m1) \
op (u8, m2) \
op (u8, m4) \
op (u8, m8) \
/* uint16_t */ \
op (u16, mf4) \
op (u16, mf2) \
op (u16, m1) \
op (u16, m2) \
op (u16, m4) \
op (u16, m8) \
/* uint32_t */ \
op (u32, mf2) \
op (u32, m1) \
op (u32, m2) \
op (u32, m4) \
op (u32, m8) \
/* uint64_t */ \
op (u64, m1) \
op (u64, m2) \
op (u64, m4) \
op (u64, m8)

#define VOPI_VXMV_III_DEF_GROUP(op) VOPI_VXMV_II_DEF_GROUP_IMPL(op ## _VXM_II_DEF)
#define VOPI_VXMV_UUU_DEF_GROUP(op) VOPI_VXMV_UU_DEF_GROUP_IMPL(op ## _VXM_UU_DEF)
#define VOPI_VXMV_IUI_DEF_GROUP(op) VOPI_VXMV_IU_DEF_GROUP_IMPL(op ## _VXM_IU_DEF)

#define VOPI_VXMV_DEF_GROUP(op) \
VOPI_VXMV_III_DEF_GROUP(op) \
VOPI_VXMV_UUU_DEF_GROUP(op)

/**
 * @brief defination of opi_vxmv: (v,x,m)->v
 * 
 */

#define VMERGE_VXM_II_DEF(type, lmul) VOPI_VXMV_III_DEF(vmerge, type, lmul)
#define VMERGE_VXM_UU_DEF(type, lmul) VOPI_VXMV_UUU_DEF(vmerge, type, lmul)
VOPI_VXMV_DEF_GROUP(VMERGE)
#define VADC_VXM_II_DEF(type, lmul) VOPI_VXMV_III_DEF(vadc, type, lmul)
#define VADC_VXM_UU_DEF(type, lmul) VOPI_VXMV_UUU_DEF(vadc, type, lmul)
VOPI_VXMV_DEF_GROUP(VADC)
#define VSBC_VXM_II_DEF(type, lmul) VOPI_VXMV_III_DEF(vsbc, type, lmul)
#define VSBC_VXM_UU_DEF(type, lmul) VOPI_VXMV_UUU_DEF(vsbc, type, lmul)
VOPI_VXMV_DEF_GROUP(VSBC)
