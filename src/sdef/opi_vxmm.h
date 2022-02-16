#ifndef __SDEF_OPI_VXMM_H__
#define __SDEF_OPI_VXMM_H__

#include "common.h"

#define VOPI_VXMM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vxm_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* rs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VXMM_REF_DEF(vmadc,        FORLOOP(i, ASSIGN_BIT(vd, i, carry_out(vs2[i], rs1[0], VMASK(i)))))
VOPI_VXMM_REF_DEF(vmsbc,        FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], rs1[0], VMASK(i)))))

#endif
