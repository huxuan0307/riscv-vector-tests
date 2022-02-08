#include "common.h"

#define VOPF_VVV_REF_DEF(op, code)    VOPI_VVV_REF_DEF(op, code)
#define VOPF_VVV_M_REF_DEF(op, code)  VOPI_VVV_M_REF_DEF(op, code)

VOPF_VVV_REF_DEF(vfadd,         FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPF_VVV_REF_DEF(vfsub,         FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPF_VVV_REF_DEF(vfmul,         FORLOOP(i, vd[i] = vs2[i]*vs1[i]))
VOPF_VVV_REF_DEF(vfdiv,         FORLOOP(i, vd[i] = vs2[i]/vs1[i]))
VOPF_VVV_REF_DEF(vfmax,         FORLOOP(i, vd[i] = std::max(vs2[i],vs1[i])))
VOPF_VVV_REF_DEF(vfmin,         FORLOOP(i, vd[i] = std::min(vs2[i],vs1[i])))
VOPF_VVV_REF_DEF(vfsgnj,        FORLOOP(i, vd[i] = vs1[i]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_REF_DEF(vfsgnjn,       FORLOOP(i, vd[i] = vs1[i]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_REF_DEF(vfsgnjx,       FORLOOP(i, vd[i] = vs1[i]>0 ? vs2[i] : -vs2[i]))

VOPF_VVV_M_REF_DEF(vfadd,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+vs1[i]))
VOPF_VVV_M_REF_DEF(vfsub,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-vs1[i]))
VOPF_VVV_M_REF_DEF(vfmul,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]*vs1[i]))
VOPF_VVV_M_REF_DEF(vfdiv,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]/vs1[i]))
VOPF_VVV_M_REF_DEF(vfmax,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i],vs1[i])))
VOPF_VVV_M_REF_DEF(vfmin,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i],vs1[i])))
VOPF_VVV_M_REF_DEF(vfsgnj,      FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_M_REF_DEF(vfsgnjn,     FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_M_REF_DEF(vfsgnjx,     FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]>0 ? vs2[i] : -vs2[i]))
