#include "common.h"

#define VOPI_VVVV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VVVV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VVVV_REF_DEF(vmacc,        FORLOOP(i, vd[i] = +(vs1[i]*vs2[i])+ vd[i]))
VOPI_VVVV_REF_DEF(vnmsac,       FORLOOP(i, vd[i] = -(vs1[i]*vs2[i])+ vd[i]))
VOPI_VVVV_REF_DEF(vmadd,        FORLOOP(i, vd[i] = +(vs1[i]* vd[i])+vs2[i]))
VOPI_VVVV_REF_DEF(vnmsub,       FORLOOP(i, vd[i] = -(vs1[i]* vd[i])+vs2[i]))

VOPI_VVVV_M_REF_DEF(vmacc,      FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i]*vs2[i])+ vd[i]))
VOPI_VVVV_M_REF_DEF(vnmsac,     FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i]*vs2[i])+ vd[i]))
VOPI_VVVV_M_REF_DEF(vmadd,      FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i]* vd[i])+vs2[i]))
VOPI_VVVV_M_REF_DEF(vnmsub,     FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i]* vd[i])+vs2[i]))
