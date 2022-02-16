#ifndef __TDEF_OPI_VXMM_H__
#define __TDEF_OPI_VXMM_H__

#include "common.h"

template<typename TypeSrc2, typename TypeSrc1>
void test_opi_vxmm(
  void (*ref_func)(uint8_t*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t), 
  void (*vector_func)(uint8_t*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  debug(details, "test length: %zu\n", n);
  /* Allocate the source and result vectors */
  uint8_t  *vmask  = (uint8_t*)   malloc(n*sizeof(uint8_t));
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  uint8_t  *vd     = (uint8_t*)   malloc(n*sizeof(uint8_t));
  uint8_t  *vd_ref = (uint8_t*)   malloc(n*sizeof(uint8_t));

  init_mask_vector(vmask, n);
  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<uint8_t>(0));
  init_vector(vd_ref, n, static_cast<uint8_t>(0));

  for(size_t i=0; i<n; i++) {
    debug(origin, "vd[%zu]=%llx, rs1[0]=%llx, vs2[%zu]=%llx, vmask[%zu]=%d\n", 
      i, vd[i], i, rs1[0], i, vs2[i], i, ((vmask[i/8] >> (i%8)) & 0x1)
    );
  }

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

  test_mask_result(vd, vd_ref, n);

  free(vmask); free(rs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VXMM(op, type, lmul) \
printf("\ntest " #op "_vxm_" #type #lmul " ...\n"); \
test_opi_vxmm<type, type>(op ## _vxm_ref<type, type>, op ## _vxm_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VXMM_GROUP(op)         TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP(op)      TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP(op)      TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_MF8(op)  TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_MF4(op)  TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_MF2(op)  TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_M1(op)   TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_M2(op)   TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_M4(op)   TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_II_GROUP_M8(op)   TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_MF8(op)  TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_MF4(op)  TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_MF2(op)  TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_M1(op)   TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_M2(op)   TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_M4(op)   TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VXMM, op)
#define TEST_OPI_VXMM_UU_GROUP_M8(op)   TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VXMM, op)

#define TEST_OPI_VXMM_ALL() \
TEST_OPI_VXMM_GROUP(vmadc) \
TEST_OPI_VXMM_GROUP(vmsbc) \

#endif
