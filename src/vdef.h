#include "vdef/vopivvv_def.h"
#include "vdef/vopivv_def.h"
#include "vdef/vopfvvv_def.h"
#include <stdint.h>
#include <riscv_vector.h>

/**
 * @brief defination of opivvv: (v, v)->v
 * 
 */

#define VADD_VV_II_DEF(type, _, lmul) VOPIVVV_III_DEF (vadd, type, lmul)
#define VADD_VV_UU_DEF(type, _, lmul) VOPIVVV_UUU_DEF (vadd, type, lmul)
#define VSUB_VV_II_DEF(type, _, lmul) VOPIVVV_III_DEF (vsub, type, lmul)
#define VSUB_VV_UU_DEF(type, _, lmul) VOPIVVV_UUU_DEF (vsub, type, lmul)

VOPIVVV_DEF_GROUP(VADD)
VOPIVVV_DEF_GROUP(VSUB)

#define VMIN_VV_II_DEF(type, _, lmul)  VOPIVVV_III_DEF (vmin, type, lmul)
#define VMAX_VV_II_DEF(type, _, lmul)  VOPIVVV_III_DEF (vmax, type, lmul)
#define VMINU_VV_UU_DEF(type, _, lmul) VOPIVVV_UUU_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_DEF(type, _, lmul) VOPIVVV_UUU_DEF (vmaxu, type, lmul)

VOPIVVV_III_DEF_GROUP(VMIN)
VOPIVVV_III_DEF_GROUP(VMAX)
VOPIVVV_UUU_DEF_GROUP(VMINU)
VOPIVVV_UUU_DEF_GROUP(VMAXU)

#define VAND_VV_II_DEF(type, _, lmul)  VOPIVVV_III_DEF (vand, type, lmul)
#define VAND_VV_UU_DEF(type, _, lmul)  VOPIVVV_UUU_DEF (vand, type, lmul)
#define VOR_VV_II_DEF(type, _, lmul)   VOPIVVV_III_DEF (vor, type, lmul)
#define VOR_VV_UU_DEF(type, _, lmul)   VOPIVVV_UUU_DEF (vor, type, lmul)
#define VXOR_VV_II_DEF(type, _, lmul)  VOPIVVV_III_DEF (vxor, type, lmul)
#define VXOR_VV_UU_DEF(type, _, lmul)  VOPIVVV_UUU_DEF (vxor, type, lmul)

VOPIVVV_DEF_GROUP(VAND)
VOPIVVV_DEF_GROUP(VOR)
VOPIVVV_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_DEF(type2, type1, lmul) \
VOPIVVV_IUI_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_DEF(type2, type1, lmul) \
VOPIVVV_IUI_DEF (vrgather, type2, type1, lmul)

VOPIVVV_IUI_DEF_GROUP(VRGATHER)

#define VSLL_VV_IU_DEF(type2, type1, lmul) \
VOPIVVV_IUI_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_DEF(type, _, lmul) \
VOPIVVV_UUU_DEF (vsll, type, lmul)
#define VSRA_VV_IU_DEF(type2, type1, lmul) \
VOPIVVV_IUI_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_DEF(type, _, lmul) \
VOPIVVV_UUU_DEF (vsrl, type, lmul)

VOPIVVV_IUI_DEF_GROUP(VSLL)
VOPIVVV_UUU_DEF_GROUP(VSLL)
VOPIVVV_IUI_DEF_GROUP(VSRA)
VOPIVVV_UUU_DEF_GROUP(VSRL)

/**
 * @brief defination of opivvv_m: (v, v)->v
 * 
 */

#define VADD_VV_II_M_DEF(type, _, lmul) VOPIVVV_III_M_DEF (vadd, type, lmul)
#define VADD_VV_UU_M_DEF(type, _, lmul) VOPIVVV_UUU_M_DEF (vadd, type, lmul)
#define VSUB_VV_II_M_DEF(type, _, lmul) VOPIVVV_III_M_DEF (vsub, type, lmul)
#define VSUB_VV_UU_M_DEF(type, _, lmul) VOPIVVV_UUU_M_DEF (vsub, type, lmul)
VOPIVVV_M_DEF_GROUP(VADD)
VOPIVVV_M_DEF_GROUP(VSUB)

#define VMIN_VV_II_M_DEF(type, _, lmul)  VOPIVVV_III_M_DEF (vmin, type, lmul)
#define VMAX_VV_II_M_DEF(type, _, lmul)  VOPIVVV_III_M_DEF (vmax, type, lmul)
#define VMINU_VV_UU_M_DEF(type, _, lmul) VOPIVVV_UUU_M_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_M_DEF(type, _, lmul) VOPIVVV_UUU_M_DEF (vmaxu, type, lmul)
VOPIVVV_III_M_DEF_GROUP(VMIN)
VOPIVVV_III_M_DEF_GROUP(VMAX)
VOPIVVV_UUU_M_DEF_GROUP(VMINU)
VOPIVVV_UUU_M_DEF_GROUP(VMAXU)

#define VAND_VV_II_M_DEF(type, _, lmul)  VOPIVVV_III_M_DEF (vand, type, lmul)
#define VAND_VV_UU_M_DEF(type, _, lmul)  VOPIVVV_UUU_M_DEF (vand, type, lmul)
#define VOR_VV_II_M_DEF(type, _, lmul)   VOPIVVV_III_M_DEF (vor, type, lmul)
#define VOR_VV_UU_M_DEF(type, _, lmul)   VOPIVVV_UUU_M_DEF (vor, type, lmul)
#define VXOR_VV_II_M_DEF(type, _, lmul)  VOPIVVV_III_M_DEF (vxor, type, lmul)
#define VXOR_VV_UU_M_DEF(type, _, lmul)  VOPIVVV_UUU_M_DEF (vxor, type, lmul)
VOPIVVV_M_DEF_GROUP(VAND)
VOPIVVV_M_DEF_GROUP(VOR)
VOPIVVV_M_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_M_DEF(type2, type1, lmul) \
VOPIVVV_IUI_M_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_M_DEF(type2, type1, lmul) \
VOPIVVV_IUI_M_DEF (vrgather, type2, type1, lmul)
VOPIVVV_IUI_M_DEF_GROUP(VRGATHER)

#define VSLL_VV_IU_M_DEF(type2, type1, lmul) \
VOPIVVV_IUI_M_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_M_DEF(type, _, lmul) \
VOPIVVV_UUU_M_DEF (vsll, type, lmul)
#define VSRA_VV_IU_M_DEF(type2, type1, lmul) \
VOPIVVV_IUI_M_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_M_DEF(type, _, lmul) \
VOPIVVV_UUU_M_DEF (vsrl, type, lmul)

VOPIVVV_IUI_M_DEF_GROUP(VSLL)
VOPIVVV_UUU_M_DEF_GROUP(VSLL)
VOPIVVV_IUI_M_DEF_GROUP(VSRA)
VOPIVVV_UUU_M_DEF_GROUP(VSRL)

/**
 * @brief defination of opivv: (v)->v
 * 
 */

#define VMV_V_INT_DEF(type, lmul) \
VOPIVV_INT_DEF(vmv, type, lmul)
#define VMV_V_UINT_DEF(type, lmul) \
VOPIVV_UINT_DEF(vmv, type, lmul)

VOPIVV_DEF_GROUP(VMV)


/**
 * @brief defination of opfvvv: (v)->v
 * 
 */

#define VFADD_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfadd, type, lmul)
#define VFSUB_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfsub, type, lmul)
#define VFMUL_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfmul, type, lmul)
#define VFDIV_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfdiv, type, lmul)
#define VFMAX_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfmax, type, lmul)
#define VFMIN_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfmin, type, lmul)
#define VFSGNJ_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VV_DEF(type, lmul) \
VOPFVVV_DEF(vfsgnjx, type, lmul)

VOPFVVV_DEF_GROUP(VFADD)
VOPFVVV_DEF_GROUP(VFSUB)
VOPFVVV_DEF_GROUP(VFMUL)
VOPFVVV_DEF_GROUP(VFDIV)
VOPFVVV_DEF_GROUP(VFMAX)
VOPFVVV_DEF_GROUP(VFMIN)
VOPFVVV_DEF_GROUP(VFSGNJ)
VOPFVVV_DEF_GROUP(VFSGNJN)
VOPFVVV_DEF_GROUP(VFSGNJX)
