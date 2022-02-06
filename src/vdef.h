#include "vdef/vopi_vvv.h"
#include "vdef/vopi_vxv.h"
#include "vdef/vopi_vvmv.h"
#include "vdef/vopi_vvm.h"
#include "vdef/vopi_vvmm.h"
#include "vdef/vopi_vv.h"
#include "vdef/vopf_vvv.h"
#include "vdef/vopf_vfv.h"
#include <stdint.h>
#include <riscv_vector.h>

/**
 * @brief defination of opi_vvv: (v, v)->v
 * 
 */

#define VADD_VV_II_DEF(type, _, lmul) VOPI_VVV_III_DEF (vadd, type, lmul)
#define VADD_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vadd, type, lmul)
#define VSUB_VV_II_DEF(type, _, lmul) VOPI_VVV_III_DEF (vsub, type, lmul)
#define VSUB_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vsub, type, lmul)

VOPI_VVV_DEF_GROUP(VADD)
VOPI_VVV_DEF_GROUP(VSUB)

#define VMIN_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vmin, type, lmul)
#define VMAX_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vmax, type, lmul)
#define VMINU_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_DEF(type, _, lmul) VOPI_VVV_UUU_DEF (vmaxu, type, lmul)

VOPI_VVV_III_DEF_GROUP(VMIN)
VOPI_VVV_III_DEF_GROUP(VMAX)
VOPI_VVV_UUU_DEF_GROUP(VMINU)
VOPI_VVV_UUU_DEF_GROUP(VMAXU)

#define VAND_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vand, type, lmul)
#define VAND_VV_UU_DEF(type, _, lmul)  VOPI_VVV_UUU_DEF (vand, type, lmul)
#define VOR_VV_II_DEF(type, _, lmul)   VOPI_VVV_III_DEF (vor, type, lmul)
#define VOR_VV_UU_DEF(type, _, lmul)   VOPI_VVV_UUU_DEF (vor, type, lmul)
#define VXOR_VV_II_DEF(type, _, lmul)  VOPI_VVV_III_DEF (vxor, type, lmul)
#define VXOR_VV_UU_DEF(type, _, lmul)  VOPI_VVV_UUU_DEF (vxor, type, lmul)

VOPI_VVV_DEF_GROUP(VAND)
VOPI_VVV_DEF_GROUP(VOR)
VOPI_VVV_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vrgather, type, lmul)

VOPI_VVV_IUI_DEF_GROUP(VRGATHER)
VOPI_VVV_UUU_DEF_GROUP(VRGATHER)

#define VSLL_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vsll, type, lmul)
#define VSRA_VV_IU_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_DEF(type, _, lmul) \
VOPI_VVV_UUU_DEF (vsrl, type, lmul)

VOPI_VVV_IUI_DEF_GROUP(VSLL)
VOPI_VVV_UUU_DEF_GROUP(VSLL)
VOPI_VVV_IUI_DEF_GROUP(VSRA)
VOPI_VVV_UUU_DEF_GROUP(VSRL)

/**
 * @brief defination of opi_vxv: (v, v)->v
 * 
 */

#define VADD_VX_II_DEF(type, _, lmul) VOPI_VXV_III_DEF (vadd, type, lmul)
#define VADD_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vadd, type, lmul)
#define VSUB_VX_II_DEF(type, _, lmul) VOPI_VXV_III_DEF (vsub, type, lmul)
#define VSUB_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vsub, type, lmul)
#define VRSUB_VX_II_DEF(type, _, lmul) VOPI_VXV_III_DEF (vrsub, type, lmul)
#define VRSUB_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vrsub, type, lmul)
VOPI_VXV_DEF_GROUP(VADD)
VOPI_VXV_DEF_GROUP(VSUB)
VOPI_VXV_DEF_GROUP(VRSUB)

#define VMIN_VX_II_DEF(type, _, lmul)  VOPI_VXV_III_DEF (vmin, type, lmul)
#define VMAX_VX_II_DEF(type, _, lmul)  VOPI_VXV_III_DEF (vmax, type, lmul)
#define VMINU_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vminu, type, lmul)
#define VMAXU_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vmaxu, type, lmul)
VOPI_VXV_III_DEF_GROUP(VMIN)
VOPI_VXV_III_DEF_GROUP(VMAX)
VOPI_VXV_UUU_DEF_GROUP(VMINU)
VOPI_VXV_UUU_DEF_GROUP(VMAXU)

#define VAND_VX_II_DEF(type, _, lmul)  VOPI_VXV_III_DEF (vand, type, lmul)
#define VAND_VX_UU_DEF(type, _, lmul)  VOPI_VXV_UUU_DEF (vand, type, lmul)
#define VOR_VX_II_DEF(type, _, lmul)   VOPI_VXV_III_DEF (vor, type, lmul)
#define VOR_VX_UU_DEF(type, _, lmul)   VOPI_VXV_UUU_DEF (vor, type, lmul)
#define VXOR_VX_II_DEF(type, _, lmul)  VOPI_VXV_III_DEF (vxor, type, lmul)
#define VXOR_VX_UU_DEF(type, _, lmul)  VOPI_VXV_UUU_DEF (vxor, type, lmul)
VOPI_VXV_DEF_GROUP(VAND)
VOPI_VXV_DEF_GROUP(VOR)
VOPI_VXV_DEF_GROUP(VXOR)

#define VRGATHER_VX_IU_DEF(type2, type1, lmul) VOPI_VXV_IUI_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vrgather, type, lmul)
VOPI_VXV_IUI_DEF_GROUP(VRGATHER)
VOPI_VXV_UUU_DEF_GROUP(VRGATHER)

#define VSLL_VX_IU_DEF(type2, type1, lmul) VOPI_VXV_IUI_DEF (vsll, type2, type1, lmul)
#define VSLL_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vsll, type, lmul)
#define VSRA_VX_IU_DEF(type2, type1, lmul) VOPI_VXV_IUI_DEF (vsra, type2, type1, lmul)
#define VSRL_VX_UU_DEF(type, _, lmul) VOPI_VXV_UUU_DEF (vsrl, type, lmul)
VOPI_VXV_IUI_DEF_GROUP(VSLL)
VOPI_VXV_UUU_DEF_GROUP(VSLL)
VOPI_VXV_IUI_DEF_GROUP(VSRA)
VOPI_VXV_UUU_DEF_GROUP(VSRL)

/**
 * @brief defination of opi_vvv_m: (v, v)->v
 * 
 */

#define VADD_VV_II_M_DEF(type, _, lmul) VOPI_VVV_III_M_DEF (vadd, type, lmul)
#define VADD_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vadd, type, lmul)
#define VSUB_VV_II_M_DEF(type, _, lmul) VOPI_VVV_III_M_DEF (vsub, type, lmul)
#define VSUB_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vsub, type, lmul)
VOPI_VVV_M_DEF_GROUP(VADD)
VOPI_VVV_M_DEF_GROUP(VSUB)

#define VMIN_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vmin, type, lmul)
#define VMAX_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vmax, type, lmul)
#define VMINU_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vminu, type, lmul)
#define VMAXU_VV_UU_M_DEF(type, _, lmul) VOPI_VVV_UUU_M_DEF (vmaxu, type, lmul)
VOPI_VVV_III_M_DEF_GROUP(VMIN)
VOPI_VVV_III_M_DEF_GROUP(VMAX)
VOPI_VVV_UUU_M_DEF_GROUP(VMINU)
VOPI_VVV_UUU_M_DEF_GROUP(VMAXU)

#define VAND_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vand, type, lmul)
#define VAND_VV_UU_M_DEF(type, _, lmul)  VOPI_VVV_UUU_M_DEF (vand, type, lmul)
#define VOR_VV_II_M_DEF(type, _, lmul)   VOPI_VVV_III_M_DEF (vor, type, lmul)
#define VOR_VV_UU_M_DEF(type, _, lmul)   VOPI_VVV_UUU_M_DEF (vor, type, lmul)
#define VXOR_VV_II_M_DEF(type, _, lmul)  VOPI_VVV_III_M_DEF (vxor, type, lmul)
#define VXOR_VV_UU_M_DEF(type, _, lmul)  VOPI_VVV_UUU_M_DEF (vxor, type, lmul)
VOPI_VVV_M_DEF_GROUP(VAND)
VOPI_VVV_M_DEF_GROUP(VOR)
VOPI_VVV_M_DEF_GROUP(VXOR)

#define VRGATHER_VV_IU_M_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_M_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VV_UU_M_DEF(type, _, lmul) \
VOPI_VVV_UUU_M_DEF (vrgather, type, lmul)
VOPI_VVV_IUI_M_DEF_GROUP(VRGATHER)
VOPI_VVV_UUU_M_DEF_GROUP(VRGATHER)


#define VSLL_VV_IU_M_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_M_DEF (vsll, type2, type1, lmul)
#define VSLL_VV_UU_M_DEF(type, _, lmul) \
VOPI_VVV_UUU_M_DEF (vsll, type, lmul)
#define VSRA_VV_IU_M_DEF(type2, type1, lmul) \
VOPI_VVV_IUI_M_DEF (vsra, type2, type1, lmul)
#define VSRL_VV_UU_M_DEF(type, _, lmul) \
VOPI_VVV_UUU_M_DEF (vsrl, type, lmul)

VOPI_VVV_IUI_M_DEF_GROUP(VSLL)
VOPI_VVV_UUU_M_DEF_GROUP(VSLL)
VOPI_VVV_IUI_M_DEF_GROUP(VSRA)
VOPI_VVV_UUU_M_DEF_GROUP(VSRL)

/**
 * @brief defination of opi_vxv_m: (v, v)->v
 * 
 */

#define VADD_VX_II_M_DEF(type, _, lmul) VOPI_VXV_III_M_DEF (vadd, type, lmul)
#define VADD_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vadd, type, lmul)
#define VSUB_VX_II_M_DEF(type, _, lmul) VOPI_VXV_III_M_DEF (vsub, type, lmul)
#define VSUB_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vsub, type, lmul)
#define VRSUB_VX_II_M_DEF(type, _, lmul) VOPI_VXV_III_M_DEF (vrsub, type, lmul)
#define VRSUB_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vrsub, type, lmul)
VOPI_VXV_M_DEF_GROUP(VADD)
VOPI_VXV_M_DEF_GROUP(VSUB)
VOPI_VXV_M_DEF_GROUP(VRSUB)

#define VMIN_VX_II_M_DEF(type, _, lmul)  VOPI_VXV_III_M_DEF (vmin, type, lmul)
#define VMAX_VX_II_M_DEF(type, _, lmul)  VOPI_VXV_III_M_DEF (vmax, type, lmul)
#define VMINU_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vminu, type, lmul)
#define VMAXU_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vmaxu, type, lmul)
VOPI_VXV_III_M_DEF_GROUP(VMIN)
VOPI_VXV_III_M_DEF_GROUP(VMAX)
VOPI_VXV_UUU_M_DEF_GROUP(VMINU)
VOPI_VXV_UUU_M_DEF_GROUP(VMAXU)

#define VAND_VX_II_M_DEF(type, _, lmul)  VOPI_VXV_III_M_DEF (vand, type, lmul)
#define VAND_VX_UU_M_DEF(type, _, lmul)  VOPI_VXV_UUU_M_DEF (vand, type, lmul)
#define VOR_VX_II_M_DEF(type, _, lmul)   VOPI_VXV_III_M_DEF (vor, type, lmul)
#define VOR_VX_UU_M_DEF(type, _, lmul)   VOPI_VXV_UUU_M_DEF (vor, type, lmul)
#define VXOR_VX_II_M_DEF(type, _, lmul)  VOPI_VXV_III_M_DEF (vxor, type, lmul)
#define VXOR_VX_UU_M_DEF(type, _, lmul)  VOPI_VXV_UUU_M_DEF (vxor, type, lmul)
VOPI_VXV_M_DEF_GROUP(VAND)
VOPI_VXV_M_DEF_GROUP(VOR)
VOPI_VXV_M_DEF_GROUP(VXOR)

#define VRGATHER_VX_IU_M_DEF(type2, type1, lmul) VOPI_VXV_IUI_M_DEF (vrgather, type2, type1, lmul)
#define VRGATHER_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vrgather, type, lmul)
VOPI_VXV_IUI_M_DEF_GROUP(VRGATHER)
VOPI_VXV_UUU_M_DEF_GROUP(VRGATHER)

#define VSLL_VX_IU_M_DEF(type2, type1, lmul) VOPI_VXV_IUI_M_DEF (vsll, type2, type1, lmul)
#define VSLL_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vsll, type, lmul)
#define VSRA_VX_IU_M_DEF(type2, type1, lmul) VOPI_VXV_IUI_M_DEF (vsra, type2, type1, lmul)
#define VSRL_VX_UU_M_DEF(type, _, lmul) VOPI_VXV_UUU_M_DEF (vsrl, type, lmul)
VOPI_VXV_IUI_M_DEF_GROUP(VSLL)
VOPI_VXV_UUU_M_DEF_GROUP(VSLL)
VOPI_VXV_IUI_M_DEF_GROUP(VSRA)
VOPI_VXV_UUU_M_DEF_GROUP(VSRL)

/**
 * @brief defination of opi_vvmv: (v,v,m)->v
 * 
 */

#define VMERGE_VVM_II_DEF(type, _, lmul) VOPI_VVMV_III_DEF(vmerge, type, lmul)
#define VMERGE_VVM_UU_DEF(type, _, lmul) VOPI_VVMV_UUU_DEF(vmerge, type, lmul)
VOPI_VVMV_DEF_GROUP(VMERGE)
#define VADC_VVM_II_DEF(type, _, lmul) VOPI_VVMV_III_DEF(vadc, type, lmul)
#define VADC_VVM_UU_DEF(type, _, lmul) VOPI_VVMV_UUU_DEF(vadc, type, lmul)
VOPI_VVMV_DEF_GROUP(VADC)
#define VSBC_VVM_II_DEF(type, _, lmul) VOPI_VVMV_III_DEF(vsbc, type, lmul)
#define VSBC_VVM_UU_DEF(type, _, lmul) VOPI_VVMV_UUU_DEF(vsbc, type, lmul)
VOPI_VVMV_DEF_GROUP(VSBC)

/**
 * @brief defination of opi_vvm: (v,v)->m
 * 
 */

#define VMSEQ_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmseq, type, lmul)
#define VMSEQ_VV_UU_DEF(type, lmul)   VOPI_VVM_UU_DEF(vmseq, type, lmul)
#define VMSNE_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmsne, type, lmul)
#define VMSNE_VV_UU_DEF(type, lmul)   VOPI_VVM_UU_DEF(vmsne, type, lmul)
#define VMSLTU_VV_UU_DEF(type, lmul)  VOPI_VVM_UU_DEF(vmsltu, type, lmul)
#define VMSLT_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmslt, type, lmul)
#define VMSLEU_VV_UU_DEF(type, lmul)  VOPI_VVM_UU_DEF(vmsleu, type, lmul)
#define VMSLE_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmsle, type, lmul)
#define VMADC_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmadc, type, lmul)
#define VMADC_VV_UU_DEF(type, lmul)   VOPI_VVM_UU_DEF(vmadc, type, lmul)
#define VMSBC_VV_II_DEF(type, lmul)   VOPI_VVM_II_DEF(vmsbc, type, lmul)
#define VMSBC_VV_UU_DEF(type, lmul)   VOPI_VVM_UU_DEF(vmsbc, type, lmul)

VOPI_VVM_DEF_GROUP(VMSEQ)
VOPI_VVM_DEF_GROUP(VMSNE)
VOPI_VVM_UU_DEF_GROUP(VMSLTU)
VOPI_VVM_II_DEF_GROUP(VMSLT)
VOPI_VVM_UU_DEF_GROUP(VMSLEU)
VOPI_VVM_II_DEF_GROUP(VMSLE)
VOPI_VVM_DEF_GROUP(VMADC)
VOPI_VVM_DEF_GROUP(VMSBC)

/**
 * @brief defination of opi_vvm_m: (v,v)->m
 * 
 */

#define VMSEQ_VV_II_M_DEF(type, lmul)   VOPI_VVM_II_M_DEF(vmseq, type, lmul)
#define VMSEQ_VV_UU_M_DEF(type, lmul)   VOPI_VVM_UU_M_DEF(vmseq, type, lmul)
#define VMSNE_VV_II_M_DEF(type, lmul)   VOPI_VVM_II_M_DEF(vmsne, type, lmul)
#define VMSNE_VV_UU_M_DEF(type, lmul)   VOPI_VVM_UU_M_DEF(vmsne, type, lmul)
#define VMSLTU_VV_UU_M_DEF(type, lmul)  VOPI_VVM_UU_M_DEF(vmsltu, type, lmul)
#define VMSLT_VV_II_M_DEF(type, lmul)   VOPI_VVM_II_M_DEF(vmslt, type, lmul)
#define VMSLEU_VV_UU_M_DEF(type, lmul)  VOPI_VVM_UU_M_DEF(vmsleu, type, lmul)
#define VMSLE_VV_II_M_DEF(type, lmul)   VOPI_VVM_II_M_DEF(vmsle, type, lmul)

VOPI_VVM_M_DEF_GROUP(VMSEQ)
VOPI_VVM_M_DEF_GROUP(VMSNE)
VOPI_VVM_UU_M_DEF_GROUP(VMSLTU)
VOPI_VVM_II_M_DEF_GROUP(VMSLT)
VOPI_VVM_UU_M_DEF_GROUP(VMSLEU)
VOPI_VVM_II_M_DEF_GROUP(VMSLE)

/**
 * @brief defination of opi_vvmm: (v,v,m)->m
 * 
 */

#define VMADC_VVM_II_DEF(type, lmul)  VOPI_VVMM_II_DEF(vmadc, type, lmul)
#define VMADC_VVM_UU_DEF(type, lmul)  VOPI_VVMM_UU_DEF(vmadc, type, lmul)
VOPI_VVMM_DEF_GROUP(VMADC)
#define VMSBC_VVM_II_DEF(type, lmul)  VOPI_VVMM_II_DEF(vmsbc, type, lmul)
#define VMSBC_VVM_UU_DEF(type, lmul)  VOPI_VVMM_UU_DEF(vmsbc, type, lmul)
VOPI_VVMM_DEF_GROUP(VMSBC)

/**
 * @brief defination of opi_vv: (v)->v
 * 
 */

#define VMV_V_INT_DEF(type, lmul) \
VOPI_VV_INT_DEF(vmv, type, lmul)
#define VMV_V_UINT_DEF(type, lmul) \
VOPI_VV_UINT_DEF(vmv, type, lmul)

VOPI_VV_DEF_GROUP(VMV)

/**
 * @brief defination of opf_vvv: (v,v)->v
 * 
 */

#define VFADD_VV_DEF(type, lmul) VOPF_VVV_DEF(vfadd, type, lmul)
#define VFSUB_VV_DEF(type, lmul) VOPF_VVV_DEF(vfsub, type, lmul)
#define VFMUL_VV_DEF(type, lmul) VOPF_VVV_DEF(vfmul, type, lmul)
#define VFDIV_VV_DEF(type, lmul) VOPF_VVV_DEF(vfdiv, type, lmul)
#define VFMAX_VV_DEF(type, lmul) VOPF_VVV_DEF(vfmax, type, lmul)
#define VFMIN_VV_DEF(type, lmul) VOPF_VVV_DEF(vfmin, type, lmul)
#define VFSGNJ_VV_DEF(type, lmul) VOPF_VVV_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VV_DEF(type, lmul) VOPF_VVV_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VV_DEF(type, lmul) VOPF_VVV_DEF(vfsgnjx, type, lmul)
VOPF_VVV_DEF_GROUP(VFADD)
VOPF_VVV_DEF_GROUP(VFSUB)
VOPF_VVV_DEF_GROUP(VFMUL)
VOPF_VVV_DEF_GROUP(VFDIV)
VOPF_VVV_DEF_GROUP(VFMAX)
VOPF_VVV_DEF_GROUP(VFMIN)
VOPF_VVV_DEF_GROUP(VFSGNJ)
VOPF_VVV_DEF_GROUP(VFSGNJN)
VOPF_VVV_DEF_GROUP(VFSGNJX)

/**
 * @brief defination of opf_vvv_m: (v,v)->v
 * 
 */

#define VFADD_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfadd, type, lmul)
#define VFSUB_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfsub, type, lmul)
#define VFMUL_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfmul, type, lmul)
#define VFDIV_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfdiv, type, lmul)
#define VFMAX_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfmax, type, lmul)
#define VFMIN_VV_M_DEF(type, lmul)    VOPF_VVV_M_DEF(vfmin, type, lmul)
#define VFSGNJ_VV_M_DEF(type, lmul)   VOPF_VVV_M_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VV_M_DEF(type, lmul)  VOPF_VVV_M_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VV_M_DEF(type, lmul)  VOPF_VVV_M_DEF(vfsgnjx, type, lmul)
VOPF_VVV_M_DEF_GROUP(VFADD)
VOPF_VVV_M_DEF_GROUP(VFSUB)
VOPF_VVV_M_DEF_GROUP(VFMUL)
VOPF_VVV_M_DEF_GROUP(VFDIV)
VOPF_VVV_M_DEF_GROUP(VFMAX)
VOPF_VVV_M_DEF_GROUP(VFMIN)
VOPF_VVV_M_DEF_GROUP(VFSGNJ)
VOPF_VVV_M_DEF_GROUP(VFSGNJN)
VOPF_VVV_M_DEF_GROUP(VFSGNJX)

/**
 * @brief defination of opf_vfv: (v,f)->v
 * 
 */

#define VFADD_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfadd, type, lmul)
#define VFSUB_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfsub, type, lmul)
#define VFRSUB_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfrsub, type, lmul)
#define VFMUL_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmul, type, lmul)
#define VFDIV_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfdiv, type, lmul)
#define VFRDIV_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfrdiv, type, lmul)
#define VFMAX_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmax, type, lmul)
#define VFMIN_VF_DEF(type, lmul)    VOPF_VFV_DEF(vfmin, type, lmul)
#define VFSGNJ_VF_DEF(type, lmul)   VOPF_VFV_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VF_DEF(type, lmul)  VOPF_VFV_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VF_DEF(type, lmul)  VOPF_VFV_DEF(vfsgnjx, type, lmul)
VOPF_VFV_DEF_GROUP(VFADD)
VOPF_VFV_DEF_GROUP(VFSUB)
VOPF_VFV_DEF_GROUP(VFRSUB)
VOPF_VFV_DEF_GROUP(VFMUL)
VOPF_VFV_DEF_GROUP(VFDIV)
VOPF_VFV_DEF_GROUP(VFRDIV)
VOPF_VFV_DEF_GROUP(VFMAX)
VOPF_VFV_DEF_GROUP(VFMIN)
VOPF_VFV_DEF_GROUP(VFSGNJ)
VOPF_VFV_DEF_GROUP(VFSGNJN)
VOPF_VFV_DEF_GROUP(VFSGNJX)

/**
 * @brief defination of opf_vfv_m: (v,f)->v
 * 
 */

#define VFADD_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfadd, type, lmul)
#define VFSUB_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfsub, type, lmul)
#define VFRSUB_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfrsub, type, lmul)
#define VFMUL_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmul, type, lmul)
#define VFDIV_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfdiv, type, lmul)
#define VFRDIV_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfrdiv, type, lmul)
#define VFMAX_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmax, type, lmul)
#define VFMIN_VF_M_DEF(type, lmul)    VOPF_VFV_M_DEF(vfmin, type, lmul)
#define VFSGNJ_VF_M_DEF(type, lmul)   VOPF_VFV_M_DEF(vfsgnj, type, lmul)
#define VFSGNJN_VF_M_DEF(type, lmul)  VOPF_VFV_M_DEF(vfsgnjn, type, lmul)
#define VFSGNJX_VF_M_DEF(type, lmul)  VOPF_VFV_M_DEF(vfsgnjx, type, lmul)
VOPF_VFV_M_DEF_GROUP(VFADD)
VOPF_VFV_M_DEF_GROUP(VFSUB)
VOPF_VFV_M_DEF_GROUP(VFRSUB)
VOPF_VFV_M_DEF_GROUP(VFMUL)
VOPF_VFV_M_DEF_GROUP(VFDIV)
VOPF_VFV_M_DEF_GROUP(VFRDIV)
VOPF_VFV_M_DEF_GROUP(VFMAX)
VOPF_VFV_M_DEF_GROUP(VFMIN)
VOPF_VFV_M_DEF_GROUP(VFSGNJ)
VOPF_VFV_M_DEF_GROUP(VFSGNJN)
VOPF_VFV_M_DEF_GROUP(VFSGNJX)
