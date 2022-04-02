#ifndef __SDEF_OPF_VFMV_H__
#define __SDEF_OPF_VFMV_H__

#include "common.h"

#define VOPF_VFMV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vfm_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* fs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPF_VFMV_REF_DEF(vfmerge,       FORLOOP(i, vd[i] = VMASK(i) ? fs1[0] : vs2[i]))

#endif
