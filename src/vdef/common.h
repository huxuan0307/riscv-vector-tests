#ifndef __VDEF_COMMON_H__
#define __VDEF_COMMON_H__

#include "../config.h"
#include "../utils.h"
#include <stdint.h>
#include <riscv_vector.h>

#define CONCAT(A, B) A ## B
#define DEREF(x)     x

// scalar type
using f32 = float;
using f64 = double;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// vector type
#define VTYPE(type, lmul)   v ## type ## lmul
using vu8mf8  = vuint8mf8_t;
using vu8mf4  = vuint8mf4_t;
using vu8mf2  = vuint8mf2_t;
using vu8m1   = vuint8m1_t;
using vu8m2   = vuint8m2_t;
using vu8m4   = vuint8m4_t;
using vu8m8   = vuint8m8_t;
using vu16mf4 = vuint16mf4_t;
using vu16mf2 = vuint16mf2_t;
using vu16m1  = vuint16m1_t;
using vu16m2  = vuint16m2_t;
using vu16m4  = vuint16m4_t;
using vu16m8  = vuint16m8_t;
using vu32mf2 = vuint32mf2_t;
using vu32m1  = vuint32m1_t;
using vu32m2  = vuint32m2_t;
using vu32m4  = vuint32m4_t;
using vu32m8  = vuint32m8_t;
using vu64m1  = vuint64m1_t;
using vu64m2  = vuint64m2_t;
using vu64m4  = vuint64m4_t;
using vu64m8  = vuint64m8_t;

using vi8mf8  = vint8mf8_t;
using vi8mf4  = vint8mf4_t;
using vi8mf2  = vint8mf2_t;
using vi8m1   = vint8m1_t;
using vi8m2   = vint8m2_t;
using vi8m4   = vint8m4_t;
using vi8m8   = vint8m8_t;
using vi16mf4 = vint16mf4_t;
using vi16mf2 = vint16mf2_t;
using vi16m1  = vint16m1_t;
using vi16m2  = vint16m2_t;
using vi16m4  = vint16m4_t;
using vi16m8  = vint16m8_t;
using vi32mf2 = vint32mf2_t;
using vi32m1  = vint32m1_t;
using vi32m2  = vint32m2_t;
using vi32m4  = vint32m4_t;
using vi32m8  = vint32m8_t;
using vi64m1  = vint64m1_t;
using vi64m2  = vint64m2_t;
using vi64m4  = vint64m4_t;
using vi64m8  = vint64m8_t;

using vf32mf2 = vfloat32mf2_t;
using vf32m1  = vfloat32m1_t;
using vf32m2  = vfloat32m2_t;
using vf32m4  = vfloat32m4_t;
using vf32m8  = vfloat32m8_t;
using vf64m1  = vfloat64m1_t;
using vf64m2  = vfloat64m2_t;
using vf64m4  = vfloat64m4_t;
using vf64m8  = vfloat64m8_t;

using vb1     = vbool1_t;
using vb2     = vbool2_t;
using vb4     = vbool4_t;
using vb8     = vbool8_t;
using vb16    = vbool16_t;
using vb32    = vbool32_t;
using vb64    = vbool64_t;

#define VUNDEF(type, lmul) vundefined_##type##lmul()

#define __vtypem_i8_mf8__   64
#define __vtypem_i8_mf4__   32
#define __vtypem_i8_mf2__   16
#define __vtypem_i8_m1__    8
#define __vtypem_i8_m2__    4
#define __vtypem_i8_m4__    2
#define __vtypem_i8_m8__    1
#define __vtypem_i16_mf4__  64
#define __vtypem_i16_mf2__  32
#define __vtypem_i16_m1__   16
#define __vtypem_i16_m2__   8
#define __vtypem_i16_m4__   4
#define __vtypem_i16_m8__   2
#define __vtypem_i32_mf2__  64
#define __vtypem_i32_m1__   32
#define __vtypem_i32_m2__   16
#define __vtypem_i32_m4__   8
#define __vtypem_i32_m8__   4
#define __vtypem_i64_m1__   64
#define __vtypem_i64_m2__   32
#define __vtypem_i64_m4__   16
#define __vtypem_i64_m8__   8
#define __vtypem_u8_mf8__   64
#define __vtypem_u8_mf4__   32
#define __vtypem_u8_mf2__   16
#define __vtypem_u8_m1__    8
#define __vtypem_u8_m2__    4
#define __vtypem_u8_m4__    2
#define __vtypem_u8_m8__    1
#define __vtypem_u16_mf4__  64
#define __vtypem_u16_mf2__  32
#define __vtypem_u16_m1__   16
#define __vtypem_u16_m2__   8
#define __vtypem_u16_m4__   4
#define __vtypem_u16_m8__   2
#define __vtypem_u32_mf2__  64
#define __vtypem_u32_m1__   32
#define __vtypem_u32_m2__   16
#define __vtypem_u32_m4__   8
#define __vtypem_u32_m8__   4
#define __vtypem_u64_m1__   64
#define __vtypem_u64_m2__   32
#define __vtypem_u64_m4__   16
#define __vtypem_u64_m8__   8
#define __vtypem_f32_mf2__  64
#define __vtypem_f32_m1__   32
#define __vtypem_f32_m2__   16
#define __vtypem_f32_m4__   8
#define __vtypem_f32_m8__   4
#define __vtypem_f64_m1__   64
#define __vtypem_f64_m2__   32
#define __vtypem_f64_m4__   16
#define __vtypem_f64_m8__   8
#define VBOOL_BITS(type, lmul) DEREF(__vtypem_##type##_##lmul##__)
#define VTYPEM(type, lmul) B_PREFIX(VBOOL_BITS(type, lmul))
#define VTYPEB(bits) CONCAT(vb, bits)
#define B_PREFIX(num) CONCAT(b, num)

template<int N>
constexpr uint8_t MAX_BITS = 0;
template<>
constexpr uint8_t MAX_BITS<2> = 0x03;
template<>
constexpr uint8_t MAX_BITS<4> = 0x0f;

#define OFFSET_PER_LOOP(type, lmul) (VLEN / VBOOL_BITS(type, lmul))
#define NEWMASK(type, lmul, offset) (MAX_BITS<OFFSET_PER_LOOP(type, lmul)> << offset)
#define VSETVL(type, lmul, n) vsetvl_##type##lmul(n)
#define vsetvl_i8mf8  vsetvl_e8mf8
#define vsetvl_i8mf4  vsetvl_e8mf4
#define vsetvl_i8mf2  vsetvl_e8mf2
#define vsetvl_i8m1   vsetvl_e8m1
#define vsetvl_i8m2   vsetvl_e8m2
#define vsetvl_i8m4   vsetvl_e8m4
#define vsetvl_i8m8   vsetvl_e8m8
#define vsetvl_i16mf4 vsetvl_e16mf4
#define vsetvl_i16mf2 vsetvl_e16mf2
#define vsetvl_i16m1  vsetvl_e16m1
#define vsetvl_i16m2  vsetvl_e16m2
#define vsetvl_i16m4  vsetvl_e16m4
#define vsetvl_i16m8  vsetvl_e16m8
#define vsetvl_i32mf2 vsetvl_e32mf2
#define vsetvl_i32m1  vsetvl_e32m1
#define vsetvl_i32m2  vsetvl_e32m2
#define vsetvl_i32m4  vsetvl_e32m4
#define vsetvl_i32m8  vsetvl_e32m8
#define vsetvl_i64m1  vsetvl_e64m1
#define vsetvl_i64m2  vsetvl_e64m2
#define vsetvl_i64m4  vsetvl_e64m4
#define vsetvl_i64m8  vsetvl_e64m8
#define vsetvl_u8mf8  vsetvl_e8mf8
#define vsetvl_u8mf4  vsetvl_e8mf4
#define vsetvl_u8mf2  vsetvl_e8mf2
#define vsetvl_u8m1   vsetvl_e8m1
#define vsetvl_u8m2   vsetvl_e8m2
#define vsetvl_u8m4   vsetvl_e8m4
#define vsetvl_u8m8   vsetvl_e8m8
#define vsetvl_u16mf4 vsetvl_e16mf4
#define vsetvl_u16mf2 vsetvl_e16mf2
#define vsetvl_u16m1  vsetvl_e16m1
#define vsetvl_u16m2  vsetvl_e16m2
#define vsetvl_u16m4  vsetvl_e16m4
#define vsetvl_u16m8  vsetvl_e16m8
#define vsetvl_u32mf2 vsetvl_e32mf2
#define vsetvl_u32m1  vsetvl_e32m1
#define vsetvl_u32m2  vsetvl_e32m2
#define vsetvl_u32m4  vsetvl_e32m4
#define vsetvl_u32m8  vsetvl_e32m8
#define vsetvl_u64m1  vsetvl_e64m1
#define vsetvl_u64m2  vsetvl_e64m2
#define vsetvl_u64m4  vsetvl_e64m4
#define vsetvl_u64m8  vsetvl_e64m8
#define vsetvl_f32mf2 vsetvl_e32mf2
#define vsetvl_f32m1  vsetvl_e32m1
#define vsetvl_f32m2  vsetvl_e32m2
#define vsetvl_f32m4  vsetvl_e32m4
#define vsetvl_f32m8  vsetvl_e32m8
#define vsetvl_f64m1  vsetvl_e64m1
#define vsetvl_f64m2  vsetvl_e64m2
#define vsetvl_f64m4  vsetvl_e64m4
#define vsetvl_f64m8  vsetvl_e64m8

#define VSETVLMAX(type, lmul) vsetvlmax_##type##lmul()
#define vsetvlmax_i8mf8  vsetvlmax_e8mf8
#define vsetvlmax_i8mf4  vsetvlmax_e8mf4
#define vsetvlmax_i8mf2  vsetvlmax_e8mf2
#define vsetvlmax_i8m1   vsetvlmax_e8m1
#define vsetvlmax_i8m2   vsetvlmax_e8m2
#define vsetvlmax_i8m4   vsetvlmax_e8m4
#define vsetvlmax_i8m8   vsetvlmax_e8m8
#define vsetvlmax_i16mf4 vsetvlmax_e16mf4
#define vsetvlmax_i16mf2 vsetvlmax_e16mf2
#define vsetvlmax_i16m1  vsetvlmax_e16m1
#define vsetvlmax_i16m2  vsetvlmax_e16m2
#define vsetvlmax_i16m4  vsetvlmax_e16m4
#define vsetvlmax_i16m8  vsetvlmax_e16m8
#define vsetvlmax_i32mf2 vsetvlmax_e32mf2
#define vsetvlmax_i32m1  vsetvlmax_e32m1
#define vsetvlmax_i32m2  vsetvlmax_e32m2
#define vsetvlmax_i32m4  vsetvlmax_e32m4
#define vsetvlmax_i32m8  vsetvlmax_e32m8
#define vsetvlmax_i64m1  vsetvlmax_e64m1
#define vsetvlmax_i64m2  vsetvlmax_e64m2
#define vsetvlmax_i64m4  vsetvlmax_e64m4
#define vsetvlmax_i64m8  vsetvlmax_e64m8
#define vsetvlmax_u8mf8  vsetvlmax_e8mf8
#define vsetvlmax_u8mf4  vsetvlmax_e8mf4
#define vsetvlmax_u8mf2  vsetvlmax_e8mf2
#define vsetvlmax_u8m1   vsetvlmax_e8m1
#define vsetvlmax_u8m2   vsetvlmax_e8m2
#define vsetvlmax_u8m4   vsetvlmax_e8m4
#define vsetvlmax_u8m8   vsetvlmax_e8m8
#define vsetvlmax_u16mf4 vsetvlmax_e16mf4
#define vsetvlmax_u16mf2 vsetvlmax_e16mf2
#define vsetvlmax_u16m1  vsetvlmax_e16m1
#define vsetvlmax_u16m2  vsetvlmax_e16m2
#define vsetvlmax_u16m4  vsetvlmax_e16m4
#define vsetvlmax_u16m8  vsetvlmax_e16m8
#define vsetvlmax_u32mf2 vsetvlmax_e32mf2
#define vsetvlmax_u32m1  vsetvlmax_e32m1
#define vsetvlmax_u32m2  vsetvlmax_e32m2
#define vsetvlmax_u32m4  vsetvlmax_e32m4
#define vsetvlmax_u32m8  vsetvlmax_e32m8
#define vsetvlmax_u64m1  vsetvlmax_e64m1
#define vsetvlmax_u64m2  vsetvlmax_e64m2
#define vsetvlmax_u64m4  vsetvlmax_e64m4
#define vsetvlmax_u64m8  vsetvlmax_e64m8
#define vsetvlmax_f32mf2 vsetvlmax_e32mf2
#define vsetvlmax_f32m1  vsetvlmax_e32m1
#define vsetvlmax_f32m2  vsetvlmax_e32m2
#define vsetvlmax_f32m4  vsetvlmax_e32m4
#define vsetvlmax_f32m8  vsetvlmax_e32m8
#define vsetvlmax_f64m1  vsetvlmax_e64m1
#define vsetvlmax_f64m2  vsetvlmax_e64m2
#define vsetvlmax_f64m4  vsetvlmax_e64m4
#define vsetvlmax_f64m8  vsetvlmax_e64m8

#define VSE(type, lmul, addr, res, vl) \
vse_v_ ## type (addr, res, vl)
#define vse_v_i8        vse8
#define vse_v_u8        vse8
#define vse_v_i16       vse16
#define vse_v_u16       vse16
#define vse_v_i32       vse32
#define vse_v_u32       vse32
#define vse_v_f32       vse32
#define vse_v_i64       vse64
#define vse_v_u64       vse64
#define vse_v_f64       vse64

#define VLE(type, lmul, addr, vl) \
vle ## _v_ ## type ## lmul (addr, vl)
#define vle_v_i8mf8     vle8_v_i8mf8
#define vle_v_i8mf4     vle8_v_i8mf4
#define vle_v_i8mf2     vle8_v_i8mf2
#define vle_v_i8m1      vle8_v_i8m1
#define vle_v_i8m2      vle8_v_i8m2
#define vle_v_i8m4      vle8_v_i8m4
#define vle_v_i8m8      vle8_v_i8m8
#define vle_v_i16mf4    vle16_v_i16mf4
#define vle_v_i16mf2    vle16_v_i16mf2
#define vle_v_i16m1     vle16_v_i16m1
#define vle_v_i16m2     vle16_v_i16m2
#define vle_v_i16m4     vle16_v_i16m4
#define vle_v_i16m8     vle16_v_i16m8
#define vle_v_i32mf2    vle32_v_i32mf2
#define vle_v_i32m1     vle32_v_i32m1
#define vle_v_i32m2     vle32_v_i32m2
#define vle_v_i32m4     vle32_v_i32m4
#define vle_v_i32m8     vle32_v_i32m8
#define vle_v_i64m1     vle64_v_i64m1
#define vle_v_i64m2     vle64_v_i64m2
#define vle_v_i64m4     vle64_v_i64m4
#define vle_v_i64m8     vle64_v_i64m8
#define vle_v_u8mf8     vle8_v_u8mf8
#define vle_v_u8mf4     vle8_v_u8mf4
#define vle_v_u8mf2     vle8_v_u8mf2
#define vle_v_u8m1      vle8_v_u8m1
#define vle_v_u8m2      vle8_v_u8m2
#define vle_v_u8m4      vle8_v_u8m4
#define vle_v_u8m8      vle8_v_u8m8
#define vle_v_u16mf4    vle16_v_u16mf4
#define vle_v_u16mf2    vle16_v_u16mf2
#define vle_v_u16m1     vle16_v_u16m1
#define vle_v_u16m2     vle16_v_u16m2
#define vle_v_u16m4     vle16_v_u16m4
#define vle_v_u16m8     vle16_v_u16m8
#define vle_v_u32mf2    vle32_v_u32mf2
#define vle_v_u32m1     vle32_v_u32m1
#define vle_v_u32m2     vle32_v_u32m2
#define vle_v_u32m4     vle32_v_u32m4
#define vle_v_u32m8     vle32_v_u32m8
#define vle_v_u64m1     vle64_v_u64m1
#define vle_v_u64m2     vle64_v_u64m2
#define vle_v_u64m4     vle64_v_u64m4
#define vle_v_u64m8     vle64_v_u64m8
#define vle_v_f32mf2    vle32_v_f32mf2
#define vle_v_f32m1     vle32_v_f32m1
#define vle_v_f32m2     vle32_v_f32m2
#define vle_v_f32m4     vle32_v_f32m4
#define vle_v_f32m8     vle32_v_f32m8
#define vle_v_f64m1     vle64_v_f64m1
#define vle_v_f64m2     vle64_v_f64m2
#define vle_v_f64m4     vle64_v_f64m4
#define vle_v_f64m8     vle64_v_f64m8

#define VLM(type, addr, vl) \
VLM_IMPL(vlm_v_, type, (addr, vl))
#define VLM_IMPL(s1, s2, s3) \
s1 ## s2  s3

#define VLE_M(type, lmul, addr, vmask, vl) \
vle_v_ ## type (vmask, VUNDEF(type, lmul), addr, vl)
#define vle_v_i8        vle8
#define vle_v_u8        vle8
#define vle_v_i16       vle16
#define vle_v_u16       vle16
#define vle_v_i32       vle32
#define vle_v_u32       vle32
#define vle_v_f32       vle32
#define vle_v_i64       vle64
#define vle_v_u64       vle64
#define vle_v_f64       vle64

#endif