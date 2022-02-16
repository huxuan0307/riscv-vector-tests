#ifndef __SDEF_OPI_VXM_H__
#define __SDEF_OPI_VXM_H__

#include "common.h"

#define VOPI_VXM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VXM_M_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_m_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* rs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VXM_REF_DEF(vmseq,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] == rs1[0])))
VOPI_VXM_REF_DEF(vmsne,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] != rs1[0])))
VOPI_VXM_REF_DEF(vmsltu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])))
VOPI_VXM_REF_DEF(vmslt,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])))
VOPI_VXM_REF_DEF(vmsle,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])))
VOPI_VXM_REF_DEF(vmsleu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])))
VOPI_VXM_REF_DEF(vmsgtu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])))
VOPI_VXM_REF_DEF(vmsgt,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])))
VOPI_VXM_REF_DEF(vmadc,         FORLOOP(i, ASSIGN_BIT(vd, i, carry_out (vs2[i], rs1[0]))))
VOPI_VXM_REF_DEF(vmsbc,         FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], rs1[0]))))

VOPI_VXM_M_REF_DEF(vmseq,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] == rs1[0])))
VOPI_VXM_M_REF_DEF(vmsne,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] != rs1[0])))
VOPI_VXM_M_REF_DEF(vmsltu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])))
VOPI_VXM_M_REF_DEF(vmslt,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <  rs1[0])))
VOPI_VXM_M_REF_DEF(vmsle,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])))
VOPI_VXM_M_REF_DEF(vmsleu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <= rs1[0])))
VOPI_VXM_M_REF_DEF(vmsgtu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])))
VOPI_VXM_M_REF_DEF(vmsgt,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] >  rs1[0])))

#endif
