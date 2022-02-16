#ifndef __SDEF_OPI_VXMV_H__
#define __SDEF_OPI_VXMV_H__

#include "common.h"

#define VOPI_VXMV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vxm_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPI_VXMV_REF_DEF(vmerge,       FORLOOP(i, vd[i] = VMASK(i) ? rs1[0] : vs2[i]))
VOPI_VXMV_REF_DEF(vadc,         FORLOOP(i, vd[i] = vs2[i] + rs1[0] + VMASK(i)))
VOPI_VXMV_REF_DEF(vsbc,         FORLOOP(i, vd[i] = vs2[i] - rs1[0] - VMASK(i)))

#endif
