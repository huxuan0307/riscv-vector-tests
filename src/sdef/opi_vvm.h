#ifndef __SDEF_OPI_VVM_H__
#define __SDEF_OPI_VVM_H__

#include "common.h"

#define VOPI_VVM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VVM_M_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VVM_REF_DEF(vmseq,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] == vs1[i])))
VOPI_VVM_REF_DEF(vmsne,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] != vs1[i])))
VOPI_VVM_REF_DEF(vmsltu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPI_VVM_REF_DEF(vmslt,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPI_VVM_REF_DEF(vmsleu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPI_VVM_REF_DEF(vmsle,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPI_VVM_REF_DEF(vmadc,         FORLOOP(i, ASSIGN_BIT(vd, i, carry_out(vs2[i], vs1[i]))))
VOPI_VVM_REF_DEF(vmsbc,         FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], vs1[i]))))

VOPI_VVM_M_REF_DEF(vmseq,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] == vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsne,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] != vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsltu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <  vs1[i]))))
VOPI_VVM_M_REF_DEF(vmslt,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <  vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsleu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <= vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsle,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <= vs1[i]))))

#endif
