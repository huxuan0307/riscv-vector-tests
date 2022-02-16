#ifndef __SDEF_OPI_VXWW_H__
#define __SDEF_OPI_VXWW_H__

#include "common.h"

#define VOPI_VXWW_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VXWW_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VXWW_REF_DEF(vwmacc,   FORLOOP(i, vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPI_VXWW_REF_DEF(vwmaccu,  FORLOOP(i, vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPI_VXWW_REF_DEF(vwmaccsu, FORLOOP(i, vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<std::make_unsigned_t<TypeRet>>(vs2[i])) + vd[i]))
VOPI_VXWW_REF_DEF(vwmaccus, FORLOOP(i, vd[i] = +(static_cast<std::make_unsigned_t<TypeRet>>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))

VOPI_VXWW_M_REF_DEF(vwmacc,   FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPI_VXWW_M_REF_DEF(vwmaccu,  FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))
VOPI_VXWW_M_REF_DEF(vwmaccsu, FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(rs1[0]) * static_cast<std::make_unsigned_t<TypeRet>>(vs2[i])) + vd[i]))
VOPI_VXWW_M_REF_DEF(vwmaccus, FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<std::make_unsigned_t<TypeRet>>(rs1[0]) * static_cast<TypeRet>(vs2[i])) + vd[i]))

#endif
