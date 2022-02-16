#ifndef __SDEF_OPI_VVMM_H__
#define __SDEF_OPI_VVMM_H__

#include "common.h"

#define VOPI_VVMM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vvm_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

VOPI_VVMM_REF_DEF(vmadc,        FORLOOP(i, ASSIGN_BIT(vd, i, carry_out(vs2[i], vs1[i], VMASK(i)))))
VOPI_VVMM_REF_DEF(vmsbc,        FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], vs1[i], VMASK(i)))))

#endif
