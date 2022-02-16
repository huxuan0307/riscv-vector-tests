#ifndef __SDEF_OPI_VWW_H__
#define __SDEF_OPI_VWW_H__

#include "common.h"

#define VOPI_VWW_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _wv_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n) { \
  {code;} \
} \

#define VOPI_VWW_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _wv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPI_VWW_REF_DEF(vwadd,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VWW_REF_DEF(vwsub,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VWW_REF_DEF(vwaddu,        FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VWW_REF_DEF(vwsubu,        FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))

VOPI_VWW_M_REF_DEF(vwadd,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VWW_M_REF_DEF(vwsub,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VWW_M_REF_DEF(vwaddu,      FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VWW_M_REF_DEF(vwsubu,      FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))

#endif
