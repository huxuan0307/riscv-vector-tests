#ifndef __SDEF_OPF_VVWW_H__
#define __SDEF_OPF_VVWW_H__

#include "common.h"

#define VOPF_VVWW_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n \
) { \
  {code;} \
} \

#define VOPF_VVWW_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPF_VVWW_REF_DEF(vfwmacc,    FORLOOP(i, vd[i] = +(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPF_VVWW_REF_DEF(vfwnmacc,   FORLOOP(i, vd[i] = -(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) - vd[i]))
VOPF_VVWW_REF_DEF(vfwmsac,    FORLOOP(i, vd[i] = +(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) - vd[i]))
VOPF_VVWW_REF_DEF(vfwnmsac,   FORLOOP(i, vd[i] = -(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) + vd[i]))

VOPF_VVWW_M_REF_DEF(vfwmacc,  FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPF_VVWW_M_REF_DEF(vfwnmacc, FORLOOPIF(i, VMASK(i), vd[i] = -(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) - vd[i]))
VOPF_VVWW_M_REF_DEF(vfwmsac,  FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) - vd[i]))
VOPF_VVWW_M_REF_DEF(vfwnmsac, FORLOOPIF(i, VMASK(i), vd[i] = -(static_cast<TypeRet>(vs1[i]) * static_cast<TypeRet>(vs2[i])) + vd[i]))

#endif
