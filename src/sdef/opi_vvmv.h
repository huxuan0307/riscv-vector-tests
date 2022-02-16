#ifndef __SDEF_OPI_VVMV_H__
#define __SDEF_OPI_VVMV_H__

#include "common.h"

#define VOPI_VVMV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vvm_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPI_VVMV_REF_DEF(vmerge,       FORLOOP(i, vd[i] = VMASK(i) ? vs1[i] : vs2[i]))
VOPI_VVMV_REF_DEF(vadc,         FORLOOP(i, vd[i] = vs2[i] + vs1[i] + VMASK(i)))
VOPI_VVMV_REF_DEF(vsbc,         FORLOOP(i, vd[i] = vs2[i] - vs1[i] - VMASK(i)))

#endif
