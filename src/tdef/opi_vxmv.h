#ifndef __TDEF_OPI_VXMV_H__
#define __TDEF_OPI_VXMV_H__

#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxmv(
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
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n);
  copy_vector(vd_ref, vd, n);
  init_mask_vector(vmask, n);

  end = get_time();
  debug(performance, "init_vector time: %f\n", elapsed_time(start, end));

  debug(details, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, rs1, vmask, n);
  end = get_time();
  debug(performance, "reference time: %f\n", elapsed_time(start, end));

  debug(details, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, rs1, vmask, n);
  end = get_time();
  debug(performance, "vector time: %f\n", elapsed_time(start, end));

  test_result<TypeRet>(vd, vd_ref, n);

  free(rs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VXMV(op, type, lmul) \
printf("\ntest " #op "_vxm_" #type #lmul " ...\n"); \
test_opi_vxmv<type, type, type>(op ## _vxm_ref<type, type, type>, op ## _vxm_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VXMV_GROUP(op)         TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP(op)     TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP(op)     TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_MF8(op) TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_MF4(op) TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_MF2(op) TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_M1(op)  TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_M2(op)  TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_M4(op)  TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_III_GROUP_M8(op)  TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_MF8(op) TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_MF4(op) TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_MF2(op) TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_M1(op)  TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_M2(op)  TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_M4(op)  TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VXMV, op)
#define TEST_OPI_VXMV_UUU_GROUP_M8(op)  TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VXMV, op)

#define TEST_OPI_VXMV_ALL() \
TEST_OPI_VXMV_GROUP(vmerge) \
TEST_OPI_VXMV_GROUP(vadc) \
TEST_OPI_VXMV_GROUP(vsbc) \

#endif
