#include "vdef/vopivvv_def.h"
#include "vdef/vopivv_def.h"
#include "vdef/vopfvvv_def.h"
#include <stdint.h>
#include <riscv_vector.h>

/**
 * @brief defination of opivvv: (v, v)->v
 * 
 */

#define VADD_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vadd, eew, type, lmul)
#define VADD_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vadd, eew, type, lmul)

#define VSUB_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vsub, eew, type, lmul)
#define VSUB_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vsub, eew, type, lmul)

VOPIVVV_DEF_GROUP(VADD)
VOPIVVV_DEF_GROUP(VSUB)

#define VMIN_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vmin, eew, type, lmul)
#define VMINU_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vminu, eew, type, lmul)

#define VMAX_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vmax, eew, type, lmul)
#define VMAXU_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vmaxu, eew, type, lmul)

VOPIVVV_INT_DEF_GROUP(VMIN)
VOPIVVV_UINT_DEF_GROUP(VMINU)
VOPIVVV_INT_DEF_GROUP(VMAX)
VOPIVVV_UINT_DEF_GROUP(VMAXU)

#define VAND_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vand, eew, type, lmul)
#define VAND_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vand, eew, type, lmul)
#define VOR_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vor, eew, type, lmul)
#define VOR_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vor, eew, type, lmul)
#define VXOR_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vxor, eew, type, lmul)
#define VXOR_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vxor, eew, type, lmul)

VOPIVVV_DEF_GROUP(VAND)
VOPIVVV_DEF_GROUP(VOR)
VOPIVVV_DEF_GROUP(VXOR)

#define VRGATHER_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vrgather, eew, type, lmul)
#define VRGATHER_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vrgather, eew, type, lmul)

VOPIVVV_DEF_GROUP(VRGATHER)

#define VSLL_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vsll, eew, type, lmul)
#define VSLL_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vsll, eew, type, lmul)

#define VSRL_VV_UINT_DEF(eew, type, lmul) \
VOPIVVV_UINT_DEF (vsrl, eew, type, lmul)
#define VSRA_VV_INT_DEF(eew, type, lmul) \
VOPIVVV_INT_DEF  (vsra, eew, type, lmul)

VOPIVVV_DEF_GROUP(VSLL)
VOPIVVV_UINT_DEF_GROUP(VSRL)
VOPIVVV_INT_DEF_GROUP(VSRA)

/**
 * @brief defination of opivv: (v)->v
 * 
 */

#define VMV_V_INT_DEF(eew, type, lmul) \
VOPIVV_INT_DEF(vmv, eew, type, lmul)
#define VMV_V_UINT_DEF(eew, type, lmul) \
VOPIVV_UINT_DEF(vmv, eew, type, lmul)

VOPIVV_DEF_GROUP(VMV)

#define VFADD_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfadd, eew, type, lmul)
#define VFSUB_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfsub, eew, type, lmul)
#define VFMUL_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfmul, eew, type, lmul)
#define VFDIV_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfdiv, eew, type, lmul)
#define VFMAX_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfmax, eew, type, lmul)
#define VFMIN_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfmin, eew, type, lmul)
#define VFSGNJ_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfsgnj, eew, type, lmul)
#define VFSGNJN_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfsgnjn, eew, type, lmul)
#define VFSGNJX_VV_DEF(eew, type, lmul) \
VOPFVVV_DEF(vfsgnjx, eew, type, lmul)

VOPFVVV_DEF_GROUP(VFADD)
VOPFVVV_DEF_GROUP(VFSUB)
VOPFVVV_DEF_GROUP(VFMUL)
VOPFVVV_DEF_GROUP(VFDIV)
VOPFVVV_DEF_GROUP(VFMAX)
VOPFVVV_DEF_GROUP(VFMIN)
VOPFVVV_DEF_GROUP(VFSGNJ)
VOPFVVV_DEF_GROUP(VFSGNJN)
VOPFVVV_DEF_GROUP(VFSGNJX)




