#include "common.h"

#define VOPI_VVV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n) { \
  {code;} \
} \

#define VOPI_VVV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

VOPI_VVV_REF_DEF(vadd,          FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPI_VVV_REF_DEF(vsub,          FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPI_VVV_REF_DEF(vmin,          FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vminu,         FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vmax,          FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vmaxu,         FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vand,          FORLOOP(i, vd[i] = vs2[i]&vs1[i]))
VOPI_VVV_REF_DEF(vor ,          FORLOOP(i, vd[i] = vs2[i]|vs1[i]))
VOPI_VVV_REF_DEF(vxor,          FORLOOP(i, vd[i] = vs2[i]^vs1[i]))
VOPI_VVV_REF_DEF(vrgather,      FORLOOP(i, vd[i] = vs2[vs1[i]]))
VOPI_VVV_REF_DEF(vsll,          FORLOOP(i, vd[i] = vs2[i]<<(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_REF_DEF(vsrl,          FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_REF_DEF(vsra,          FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))

VOPI_VVV_M_REF_DEF(vadd,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+vs1[i]))
VOPI_VVV_M_REF_DEF(vsub,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-vs1[i]))
VOPI_VVV_M_REF_DEF(vmin,        FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vminu,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vmax,        FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vmaxu,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vand,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]&vs1[i]))
VOPI_VVV_M_REF_DEF(vor ,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]|vs1[i]))
VOPI_VVV_M_REF_DEF(vxor,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]^vs1[i]))
VOPI_VVV_M_REF_DEF(vrgather,    FORLOOPIF(i, VMASK(i), vd[i] = vs2[vs1[i]]))
VOPI_VVV_M_REF_DEF(vsll,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]<<(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_M_REF_DEF(vsrl,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_M_REF_DEF(vsra,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))
