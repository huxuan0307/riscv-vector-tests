#include "common.h"

#define VOPI_VXM_DEF(op, type2, lmul2, type1, lmul1) \
void op##_vx_ ## type2 ## lmul2 ## _vec( \
u8*d, type2*s2, type1*s1, u64 n) \
{ \
  size_t i=0; \
  VTYPEB(VBOOL_BITS(type2, lmul2)) vd; \
  for (i = 0; i < n;) { \
    size_t vl = VSETVL(type2, lmul2, n - i); \
    type1 rs1 = *s1; \
    auto vs2 = VLE(type2, lmul2, &s2[i], vl); \
    __asm__(#op ".vx %0, %1, %2;" : "=vr"(vd) : "vr"(vs2), "r"(rs1)); \
    auto offset = i % 8; \
    if (OFFSET_PER_LOOP(type2, lmul2) >= 8) { \
      vsm(&d[i/8], vd, vl); \
    } \
    else { \
      uint8_t new_res; \
      __asm__("vmv.x.s %0, %1;" : "=r"(new_res) : "vr"(vd)); \
      new_res <<= offset; \
      auto old_res = d[i/8] & ~NEWMASK(type2, lmul2, offset); \
      d[i/8] = new_res | old_res; \
    } \
    i += vl; \
  } \
} \

#define VOPI_VXM_M_DEF(op, type2, lmul2, type1, lmul1) \
void op##_vx_ ## type2 ## lmul2 ## _m_vec( \
  u8*d, type2*s2, type1*s1, const u8* mask, u64 n \
) { \
  size_t i=0; \
  size_t vl = VSETVL(type2, lmul2, n); \
  VTYPEB(VBOOL_BITS(type2, lmul2)) vd; \
  for (i = 0; i < n;) { \
    auto vmask = VLM(VTYPEM(type2, lmul2), &mask[i/8], vl); \
    auto offset = i % 8; \
    __asm__("vsrl.vx %0, %1, %2;" : "=vm"(vmask) : "vm"(vmask), "r"(offset)); \
    vl = VSETVL(type2, lmul2, n - i); \
    type1 rs1 = *s1; \
    auto vs2 = VLE(type2, lmul2, &s2[i], vl); \
    __asm__(#op ".vx %0, %1, %2, %3.t;" : "=vr"(vd) : "vr"(vs2), "r"(rs1), "vm"(vmask)); \
    if (OFFSET_PER_LOOP(type2, lmul2) >= 8) { \
      vsm(&d[i/8], vd, vl); \
    } \
    else { \
      uint8_t new_res; \
      __asm__("vmv.x.s %0, %1;" : "=r"(new_res) : "vr"(vd)); \
      new_res <<= offset; \
      auto old_res = d[i/8] & ~NEWMASK(type2, lmul2, offset); \
      d[i/8] = new_res | old_res; \
    } \
    i += vl; \
  } \
} \

#define VOPI_VXM_II_DEF(op, type, lmul) \
VOPI_VXM_DEF(op, type, lmul, type, lmul)
#define VOPI_VXM_UU_DEF VOPI_VXM_II_DEF
#define VOPI_VXM_II_M_DEF(op, type, lmul) \
VOPI_VXM_M_DEF(op, type, lmul, type, lmul)
#define VOPI_VXM_UU_M_DEF VOPI_VXM_II_M_DEF

#define VOPI_VXM_II_DEF_GROUP_IMPL(op) \
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

#define VOPI_VXM_UU_DEF_GROUP_IMPL(op) \
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

#define VOPI_VXM_II_DEF_GROUP(op) VOPI_VXM_II_DEF_GROUP_IMPL(op ## _VX_II_DEF)
#define VOPI_VXM_UU_DEF_GROUP(op) VOPI_VXM_UU_DEF_GROUP_IMPL(op ## _VX_UU_DEF)
#define VOPI_VXM_IU_DEF_GROUP(op) VOPI_VXM_IU_DEF_GROUP_IMPL(op ## _VX_IU_DEF)

#define VOPI_VXM_II_M_DEF_GROUP(op) VOPI_VXM_II_DEF_GROUP_IMPL(op ## _VX_II_M_DEF)
#define VOPI_VXM_UU_M_DEF_GROUP(op) VOPI_VXM_UU_DEF_GROUP_IMPL(op ## _VX_UU_M_DEF)
#define VOPI_VXM_IU_M_DEF_GROUP(op) VOPI_VXM_IU_DEF_GROUP_IMPL(op ## _VX_IU_M_DEF)

#define VOPI_VXM_DEF_GROUP(op) \
VOPI_VXM_II_DEF_GROUP(op) \
VOPI_VXM_UU_DEF_GROUP(op)

#define VOPI_VXM_M_DEF_GROUP(op) \
VOPI_VXM_II_M_DEF_GROUP(op) \
VOPI_VXM_UU_M_DEF_GROUP(op)

/**
 * @brief defination of opi_vxm: (v,x)->m
 * 
 */

#define VMSEQ_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmseq, type, lmul)
#define VMSEQ_VX_UU_DEF(type, lmul)   VOPI_VXM_UU_DEF(vmseq, type, lmul)
#define VMSNE_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmsne, type, lmul)
#define VMSNE_VX_UU_DEF(type, lmul)   VOPI_VXM_UU_DEF(vmsne, type, lmul)
#define VMSLTU_VX_UU_DEF(type, lmul)  VOPI_VXM_UU_DEF(vmsltu, type, lmul)
#define VMSLT_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmslt, type, lmul)
#define VMSLEU_VX_UU_DEF(type, lmul)  VOPI_VXM_UU_DEF(vmsleu, type, lmul)
#define VMSLE_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmsle, type, lmul)
#define VMSGTU_VX_UU_DEF(type, lmul)  VOPI_VXM_UU_DEF(vmsgtu, type, lmul)
#define VMSGT_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmsgt, type, lmul)
#define VMADC_VX_UU_DEF(type, lmul)   VOPI_VXM_UU_DEF(vmadc, type, lmul)
#define VMADC_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmadc, type, lmul)
#define VMSBC_VX_UU_DEF(type, lmul)   VOPI_VXM_UU_DEF(vmsbc, type, lmul)
#define VMSBC_VX_II_DEF(type, lmul)   VOPI_VXM_II_DEF(vmsbc, type, lmul)

VOPI_VXM_DEF_GROUP(VMSEQ)
VOPI_VXM_DEF_GROUP(VMSNE)
VOPI_VXM_UU_DEF_GROUP(VMSLTU)
VOPI_VXM_II_DEF_GROUP(VMSLT)
VOPI_VXM_UU_DEF_GROUP(VMSLEU)
VOPI_VXM_II_DEF_GROUP(VMSLE)
VOPI_VXM_UU_DEF_GROUP(VMSGTU)
VOPI_VXM_II_DEF_GROUP(VMSGT)
VOPI_VXM_DEF_GROUP(VMADC)
VOPI_VXM_DEF_GROUP(VMSBC)

/**
 * @brief defination of opi_vxm_m: (v,x)->m
 * 
 */

#define VMSEQ_VX_II_M_DEF(type, lmul)   VOPI_VXM_II_M_DEF(vmseq, type, lmul)
#define VMSEQ_VX_UU_M_DEF(type, lmul)   VOPI_VXM_UU_M_DEF(vmseq, type, lmul)
#define VMSNE_VX_II_M_DEF(type, lmul)   VOPI_VXM_II_M_DEF(vmsne, type, lmul)
#define VMSNE_VX_UU_M_DEF(type, lmul)   VOPI_VXM_UU_M_DEF(vmsne, type, lmul)
#define VMSLTU_VX_UU_M_DEF(type, lmul)  VOPI_VXM_UU_M_DEF(vmsltu, type, lmul)
#define VMSLT_VX_II_M_DEF(type, lmul)   VOPI_VXM_II_M_DEF(vmslt, type, lmul)
#define VMSLEU_VX_UU_M_DEF(type, lmul)  VOPI_VXM_UU_M_DEF(vmsleu, type, lmul)
#define VMSLE_VX_II_M_DEF(type, lmul)   VOPI_VXM_II_M_DEF(vmsle, type, lmul)
#define VMSGTU_VX_UU_M_DEF(type, lmul)  VOPI_VXM_UU_M_DEF(vmsgtu, type, lmul)
#define VMSGT_VX_II_M_DEF(type, lmul)   VOPI_VXM_II_M_DEF(vmsgt, type, lmul)

VOPI_VXM_M_DEF_GROUP(VMSEQ)
VOPI_VXM_M_DEF_GROUP(VMSNE)
VOPI_VXM_UU_M_DEF_GROUP(VMSLTU)
VOPI_VXM_II_M_DEF_GROUP(VMSLT)
VOPI_VXM_UU_M_DEF_GROUP(VMSLEU)
VOPI_VXM_II_M_DEF_GROUP(VMSLE)
VOPI_VXM_UU_M_DEF_GROUP(VMSGTU)
VOPI_VXM_II_M_DEF_GROUP(VMSGT)
