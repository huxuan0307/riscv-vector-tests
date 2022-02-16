#ifndef __SDEF_OPI_VXVV_H__
#define __SDEF_OPI_VXVV_H__

#include "common.h"

#define VOPI_VXVV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VXVV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VXVV_REF_DEF(vmacc,        FORLOOP(i, vd[i] = +(rs1[0]*vs2[i])+ vd[i]))
VOPI_VXVV_REF_DEF(vnmsac,       FORLOOP(i, vd[i] = -(rs1[0]*vs2[i])+ vd[i]))
VOPI_VXVV_REF_DEF(vmadd,        FORLOOP(i, vd[i] = +(rs1[0]* vd[i])+vs2[i]))
VOPI_VXVV_REF_DEF(vnmsub,       FORLOOP(i, vd[i] = -(rs1[0]* vd[i])+vs2[i]))

VOPI_VXVV_M_REF_DEF(vmacc,      FORLOOPIF(i, VMASK(i), vd[i] = +(rs1[0]*vs2[i])+ vd[i]))
VOPI_VXVV_M_REF_DEF(vnmsac,     FORLOOPIF(i, VMASK(i), vd[i] = -(rs1[0]*vs2[i])+ vd[i]))
VOPI_VXVV_M_REF_DEF(vmadd,      FORLOOPIF(i, VMASK(i), vd[i] = +(rs1[0]* vd[i])+vs2[i]))
VOPI_VXVV_M_REF_DEF(vnmsub,     FORLOOPIF(i, VMASK(i), vd[i] = -(rs1[0]* vd[i])+vs2[i]))

#endif
