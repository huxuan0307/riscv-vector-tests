#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvm(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  printf("test length: %zu\n", n);
  /* Allocate the source and result vectors */
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(vs1, n);
  init_vector(vs2, n);

  end = get_time();
  fprintf(stderr, "init_vector time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, vs1, n);
  end = get_time();
  fprintf(stderr, "reference time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, vs1, n);
  end = get_time();
  fprintf(stderr, "vector time: %f\n", elapsed_time(start, end));

  test_result(vd, vd_ref, (n+7)/8);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeSrc2, typename TypeSrc1>
void test_opi_vvm_m(
  void (*ref_func)(uint8_t*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t), 
  void (*vector_func)(uint8_t*, TypeSrc2*, TypeSrc1*, const uint8_t*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  printf("test length: %zu\n", n);
  /* Allocate the source and result vectors */
  uint8_t  *vmask  = (uint8_t*)   malloc(n*sizeof(uint8_t));
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  uint8_t  *vd     = (uint8_t*)   malloc(n*sizeof(uint8_t));
  uint8_t  *vd_ref = (uint8_t*)   malloc(n*sizeof(uint8_t));

  init_mask_vector(vmask, n);
  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<uint8_t>(0));
  init_vector(vd_ref, n, static_cast<uint8_t>(0));
#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%4lu]=%d, vs1[%4lu]=%llx, vs2[%4lu]=%llx, vmask[%4lu]=%d\n", 
      i, get_bit(vd, i), i, vs1[i], i, vs2[i], i, get_bit(vmask, i)
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

  test_mask_result_with_mask(vd, vd_ref, vmask, n);

  free(vmask); free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VVM(op, type, lmul) \
printf("\ntest " #op "_vv_" #type #lmul " ...\n"); \
test_opi_vvm<uint8_t, type, type>(op ## _vv_ref<type, type>, op ## _vv_## type ## lmul ## _vec)

#define TEST_OPI_VVM_M(op, type, lmul) \
printf("\ntest " #op "_vv_" #type #lmul "_m " " ...\n"); \
test_opi_vvm_m<type, type>(op ## _vv_m_ref<type, type>, op ## _vv_## type ## lmul ## _m_vec)

#define TEST_OPI_VVM_GROUP(op)          TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP(op)       TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP(op)       TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_MF8(op)   TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_MF4(op)   TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_MF2(op)   TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_M1(op)    TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_M2(op)    TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_M4(op)    TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_II_GROUP_M8(op)    TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_MF8(op)   TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_MF4(op)   TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_MF2(op)   TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_M1(op)    TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_M2(op)    TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_M4(op)    TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VVM, op)
#define TEST_OPI_VVM_UU_GROUP_M8(op)    TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VVM, op)

#define TEST_OPI_VVM_M_GROUP(op)          TEST_OPI1OP_COMMON_GROUP(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP(op)       TEST_OPI1OP_COMMON_I_GROUP(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP(op)       TEST_OPI1OP_COMMON_U_GROUP(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_MF8(op)   TEST_OPI1OP_COMMON_I_GROUP_MF8(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_MF4(op)   TEST_OPI1OP_COMMON_I_GROUP_MF4(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_MF2(op)   TEST_OPI1OP_COMMON_I_GROUP_MF2(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_M1(op)    TEST_OPI1OP_COMMON_I_GROUP_M1(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_M2(op)    TEST_OPI1OP_COMMON_I_GROUP_M2(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_M4(op)    TEST_OPI1OP_COMMON_I_GROUP_M4(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_II_M_GROUP_M8(op)    TEST_OPI1OP_COMMON_I_GROUP_M8(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_MF8(op)   TEST_OPI1OP_COMMON_U_GROUP_MF8(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_MF4(op)   TEST_OPI1OP_COMMON_U_GROUP_MF4(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_MF2(op)   TEST_OPI1OP_COMMON_U_GROUP_MF2(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_M1(op)    TEST_OPI1OP_COMMON_U_GROUP_M1(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_M2(op)    TEST_OPI1OP_COMMON_U_GROUP_M2(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_M4(op)    TEST_OPI1OP_COMMON_U_GROUP_M4(TEST_OPI_VVM_M, op)
#define TEST_OPI_VVM_UU_M_GROUP_M8(op)    TEST_OPI1OP_COMMON_U_GROUP_M8(TEST_OPI_VVM_M, op)


