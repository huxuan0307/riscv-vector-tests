#ifndef __SDEF_OPF_VFM_H__
#define __SDEF_OPF_VFM_H__

#include "common.h"

#define VOPF_VFM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n \
) { \
  {code;} \
} \

#define VOPF_VFM_M_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_m_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* rs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \


VOPF_VFM_REF_DEF(vmfeq, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] == rs1[0])));
VOPF_VFM_REF_DEF(vmfle, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])));
VOPF_VFM_REF_DEF(vmflt, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])));
VOPF_VFM_REF_DEF(vmfne, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] != rs1[0])));
VOPF_VFM_REF_DEF(vmfgt, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])));
VOPF_VFM_REF_DEF(vmfge, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] >= rs1[0])));

VOPF_VFM_M_REF_DEF(vmfeq, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] == rs1[0])));
VOPF_VFM_M_REF_DEF(vmfle, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])));
VOPF_VFM_M_REF_DEF(vmflt, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])));
VOPF_VFM_M_REF_DEF(vmfne, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] != rs1[0])));
VOPF_VFM_M_REF_DEF(vmfgt, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])));
VOPF_VFM_M_REF_DEF(vmfge, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] >= rs1[0])));


#endif
