#ifndef __SDEF_OPI_VVW_H__
#define __SDEF_OPI_VVW_H__

#include "common.h"
#include "opi_vvv.h"

#define VOPI_VVW_REF_DEF VOPI_VVV_REF_DEF

#define VOPI_VVW_M_REF_DEF VOPI_VVV_M_REF_DEF

VOPI_VVW_REF_DEF(vwadd,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwsub,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwaddu,        FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwsubu,        FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwmul,         FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwmulu,        FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])))
VOPI_VVW_REF_DEF(vwmulsu,       FORLOOP(i, vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<std::make_unsigned_t<TypeRet>>(vs1[i])))

VOPI_VVW_M_REF_DEF(vwadd,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwsub,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwaddu,      FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) + static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwsubu,      FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) - static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwmul,       FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwmulu,      FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<TypeRet>(vs1[i])))
VOPI_VVW_M_REF_DEF(vwmulsu,     FORLOOPIF(i, VMASK(i), vd[i] = static_cast<TypeRet>(vs2[i]) * static_cast<std::make_unsigned_t<TypeRet>>(vs1[i])))

#endif
