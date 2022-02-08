#include "common.h"

#define VOPI_VVWW_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n) { \
  {code;} \
} \

#define VOPI_VVWW_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPI_VVWW_REF_DEF(vwmacc,   FORLOOP(i, vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])) + vd[i]))
VOPI_VVWW_REF_DEF(vwmaccu,  FORLOOP(i, vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])) + vd[i]))
VOPI_VVWW_REF_DEF(vwmaccsu, FORLOOP(i, vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<std::make_unsigned_t<TypeRet>>(vs1[i])) + vd[i]))

VOPI_VVWW_M_REF_DEF(vwmacc,   FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])) + vd[i]))
VOPI_VVWW_M_REF_DEF(vwmaccu,  FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])) + vd[i]))
VOPI_VVWW_M_REF_DEF(vwmaccsu, FORLOOPIF(i, VMASK(i), vd[i] = +(static_cast<TypeRet>(vs2[i]) * static_cast<std::make_unsigned_t<TypeRet>>(vs1[i])) + vd[i]))
