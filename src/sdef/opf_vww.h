#ifndef __SDEF_OPF_VWW_H__
#define __SDEF_OPF_VWW_H__

#include "common.h"

#define VOPF_VWW_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _wv_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n) { \
  {code;} \
} \

#define VOPF_VWW_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _wv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPF_VWW_REF_DEF(vfwadd,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPF_VWW_REF_DEF(vfwsub,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))

VOPF_VWW_M_REF_DEF(vfwadd,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPF_VWW_M_REF_DEF(vfwsub,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))

#endif
