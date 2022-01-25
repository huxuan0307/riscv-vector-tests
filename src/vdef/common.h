#ifndef __VDEF_COMMON_H__
#define __VDEF_COMMON_H__

#include <stdint.h>
// scalar type
#define UINT(x) uint##x##_t 
#define INT(x) int##x##_t
#define FLOAT(x) float##x##_t

// vector type
#define VINT(eew, lmul)     vint##eew##lmul##_t
#define VFLOAT(eew, lmul)   vfloat##eew##lmul##_t
#define VBOOL(eew)          vbool##eew##_t

#define VSETVL(eew, lmul, n) vsetvl_e##eew##lmul(n)
#define VSETVLMAX(eew, lmul) vsetvlmax_e##eew##lmul()

#define VSE(eew, type, lmul, addr, res, vl) \
vse ## eew ## _v_ ## type ## lmul (addr, res, vl)

#define VLE(eew, type, lmul, addr, vl) \
vle ## eew ## _v_ ## type ## lmul (addr, vl)

#endif