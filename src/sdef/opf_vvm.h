#ifndef __SDEF_OPF_VVM_H__
#define __SDEF_OPF_VVM_H__

#include "common.h"
#include "opi_vvm.h"

#define VOPF_VVM_REF_DEF(op, code)    VOPI_VVM_REF_DEF(op, code)
#define VOPF_VVM_M_REF_DEF(op, code)  VOPI_VVM_M_REF_DEF(op, code)

VOPF_VVM_REF_DEF(vmfeq, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] == vs1[i])))
VOPF_VVM_REF_DEF(vmfle, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPF_VVM_REF_DEF(vmflt, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPF_VVM_REF_DEF(vmfne, FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] != vs1[i])))

VOPF_VVM_M_REF_DEF(vmfeq, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] == vs1[i])))
VOPF_VVM_M_REF_DEF(vmfle, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPF_VVM_M_REF_DEF(vmflt, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPF_VVM_M_REF_DEF(vmfne, FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, vs2[i] != vs1[i])))


#endif
