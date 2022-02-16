#ifndef __SDEF_OPF_VFV_H__
#define __SDEF_OPF_VFV_H__

#include "common.h"

#define VOPF_VFV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n) { \
  {code;} \
} \

#define VOPF_VFV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \


VOPF_VFV_REF_DEF(vfadd,         FORLOOP(i, vd[i] = vs2[i]+rs1[0]))
VOPF_VFV_REF_DEF(vfsub,         FORLOOP(i, vd[i] = vs2[i]-rs1[0]))
VOPF_VFV_REF_DEF(vfrsub,        FORLOOP(i, vd[i] = rs1[0]-vs2[i]))
VOPF_VFV_REF_DEF(vfmul,         FORLOOP(i, vd[i] = vs2[i]*rs1[0]))
VOPF_VFV_REF_DEF(vfdiv,         FORLOOP(i, vd[i] = vs2[i]/rs1[0]))
VOPF_VFV_REF_DEF(vfrdiv,        FORLOOP(i, vd[i] = rs1[0]/vs2[i]))
VOPF_VFV_REF_DEF(vfmax,         FORLOOP(i, vd[i] = std::max(vs2[i],rs1[0])))
VOPF_VFV_REF_DEF(vfmin,         FORLOOP(i, vd[i] = std::min(vs2[i],rs1[0])))
VOPF_VFV_REF_DEF(vfsgnj,        FORLOOP(i, vd[i] = rs1[0]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_REF_DEF(vfsgnjn,       FORLOOP(i, vd[i] = rs1[0]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_REF_DEF(vfsgnjx,       FORLOOP(i, vd[i] = rs1[0]>0 ? vs2[i] : -vs2[i]))

VOPF_VFV_M_REF_DEF(vfadd,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+rs1[0]))
VOPF_VFV_M_REF_DEF(vfsub,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-rs1[0]))
VOPF_VFV_M_REF_DEF(vfrsub,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]-vs2[i]))
VOPF_VFV_M_REF_DEF(vfmul,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]*rs1[0]))
VOPF_VFV_M_REF_DEF(vfdiv,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]/rs1[0]))
VOPF_VFV_M_REF_DEF(vfrdiv,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]/vs2[i]))
VOPF_VFV_M_REF_DEF(vfmax,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i],rs1[0])))
VOPF_VFV_M_REF_DEF(vfmin,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i],rs1[0])))
VOPF_VFV_M_REF_DEF(vfsgnj,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_M_REF_DEF(vfsgnjn,     FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_M_REF_DEF(vfsgnjx,     FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]>0 ? vs2[i] : -vs2[i]))

#endif
