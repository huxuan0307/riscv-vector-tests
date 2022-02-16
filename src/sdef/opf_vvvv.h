#ifndef __SDEF_OPF_VVVV_H__
#define __SDEF_OPF_VVVV_H__

#include "common.h"
#include "opi_vvvv.h"

#define VOPF_VVVV_REF_DEF(op, code)   VOPI_VVVV_REF_DEF(op, code)
#define VOPF_VVVV_M_REF_DEF(op, code) VOPI_VVVV_M_REF_DEF(op, code)

VOPF_VVVV_REF_DEF(vfmacc,   FORLOOP(i, vd[i] = +(vs1[i] * vs2[i]) +  vd[i]))
VOPF_VVVV_REF_DEF(vfnmacc,  FORLOOP(i, vd[i] = -(vs1[i] * vs2[i]) -  vd[i]))
VOPF_VVVV_REF_DEF(vfmsac,   FORLOOP(i, vd[i] = +(vs1[i] * vs2[i]) -  vd[i]))
VOPF_VVVV_REF_DEF(vfnmsac,  FORLOOP(i, vd[i] = -(vs1[i] * vs2[i]) +  vd[i]))
VOPF_VVVV_REF_DEF(vfmadd,   FORLOOP(i, vd[i] = +(vs1[i] *  vd[i]) + vs2[i]))
VOPF_VVVV_REF_DEF(vfnmadd,  FORLOOP(i, vd[i] = -(vs1[i] *  vd[i]) - vs2[i]))
VOPF_VVVV_REF_DEF(vfmsub,   FORLOOP(i, vd[i] = +(vs1[i] *  vd[i]) - vs2[i]))
VOPF_VVVV_REF_DEF(vfnmsub,  FORLOOP(i, vd[i] = -(vs1[i] *  vd[i]) + vs2[i]))

VOPF_VVVV_M_REF_DEF(vfmacc,   FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i] * vs2[i]) +  vd[i]))
VOPF_VVVV_M_REF_DEF(vfnmacc,  FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i] * vs2[i]) -  vd[i]))
VOPF_VVVV_M_REF_DEF(vfmsac,   FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i] * vs2[i]) -  vd[i]))
VOPF_VVVV_M_REF_DEF(vfnmsac,  FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i] * vs2[i]) +  vd[i]))
VOPF_VVVV_M_REF_DEF(vfmadd,   FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i] *  vd[i]) + vs2[i]))
VOPF_VVVV_M_REF_DEF(vfnmadd,  FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i] *  vd[i]) - vs2[i]))
VOPF_VVVV_M_REF_DEF(vfmsub,   FORLOOPIF(i, VMASK(i), vd[i] = +(vs1[i] *  vd[i]) - vs2[i]))
VOPF_VVVV_M_REF_DEF(vfnmsub,  FORLOOPIF(i, VMASK(i), vd[i] = -(vs1[i] *  vd[i]) + vs2[i])) 

#endif
