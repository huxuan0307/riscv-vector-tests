#ifndef __TDEF_OPI_VVMV_H__
#define __TDEF_OPI_VVMV_H__

#include "common.h"
#include "opi_vvv.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvmv(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  debug(details, "test length: %zu\n", n);
  /* Allocate the source and result vectors */
  uint8_t *vmask   = (uint8_t*)   malloc(n*sizeof(uint8_t));
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));
  
  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd, n);
  copy_vector(vd_ref, vd, n);
  init_mask_vector(vmask, n);

  for(size_t i=0; i<n; i++) {
    debug(origin, "vd[%d]=%llx, vs1[%d]=%llx, vs2[%d]=%llx, vmask[%d]=%d\n", 
      i, vd[i], i, vs1[i], i, vs2[i], i, ((vmask[i/8] >> (i%8)) & 0x1)
    );
  }

  end = get_time();
  debug(performance, "init_vector time: %f\n", elapsed_time(start, end));

  debug(details, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, vs1, vmask, n);
  end = get_time();
  debug(performance, "reference time: %f\n", elapsed_time(start, end));

  debug(details, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, vs1, vmask, n);
  end = get_time();
  debug(performance, "vector time: %f\n", elapsed_time(start, end));

  test_result<TypeRet>(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VVMV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vvm_" #type_ret #lmul " ...\n"); \
test_opi_vvmv<type_ret, type2, type1>(op ## _vvm_ref<type_ret, type2, type1>, op ## _vvm_## type_ret ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VVMV_GROUP(op)         TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP(op)     TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP(op)     TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP(op)     TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_III_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_UUU_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(TEST_OPI_VVMV, op)
#define TEST_OPI_VVMV_IUI_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(TEST_OPI_VVMV, op)

#define TEST_OPI_VVMV_ALL() \
TEST_OPI_VVMV_GROUP(vmerge) \
TEST_OPI_VVMV_GROUP(vadc) \
TEST_OPI_VVMV_GROUP(vsbc) \

#endif
