#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvmm(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  printf("test length: %zu\n", n);
  /* Allocate the source and result vectors */
  uint8_t *vmask   = (uint8_t*)   malloc(n*sizeof(uint8_t));
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_mask_vector(vmask, n);
  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<TypeRet>(0));
  init_vector(vd_ref, n, static_cast<TypeRet>(0));
#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%d]=%llx, vs1[%d]=%llx, vs2[%d]=%llx, vmask[%d]=%d\n", 
      i, vd[i], i, vs1[i], i, vs2[i], i, ((vmask[i/8] >> (i%8)) & 0x1)
    );
  }
#endif

  end = get_time();
  fprintf(stderr, "init_vector time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, vs1, vmask, n);
  end = get_time();
  fprintf(stderr, "reference time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, vs1, vmask, n);
  end = get_time();
  fprintf(stderr, "vector time: %f\n", elapsed_time(start, end));

  test_result(vd, vd_ref, (n+7)/8);

  free(vmask); free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VVMM(op, type, lmul) \
printf("\ntest " #op "_vvm_" #type #lmul " ...\n"); \
test_opi_vvmm<uint8_t, type, type>(op ## _vvm_ref<type, type>, op ## _vvm_## type ## lmul ## _vec)

#define TEST_OPI_VVMM_GROUP(op)         TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP(op)      TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP(op)      TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF8(op)  TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF4(op)  TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_MF2(op)  TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M1(op)   TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M2(op)   TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M4(op)   TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_II_GROUP_M8(op)   TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF8(op)  TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF4(op)  TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_MF2(op)  TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M1(op)   TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M2(op)   TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M4(op)   TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VVMM, op)
#define TEST_OPI_VVMM_UU_GROUP_M8(op)   TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VVMM, op)

#define TEST_OPI_VVMM_ALL() \
TEST_OPI_VVMM_GROUP(vmadc) \
TEST_OPI_VVMM_GROUP(vmsbc) \
