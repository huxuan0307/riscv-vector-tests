#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxvv(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  printf("test length: %zu\n", n);
  /* Allocate the source and result vectors */
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n);
  copy_vector(vd_ref, vd, n);

  end = get_time();
  fprintf(stderr, "init_vector time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, rs1, n);
  end = get_time();
  fprintf(stderr, "reference time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, rs1, n);
  end = get_time();
  fprintf(stderr, "vector time: %f\n", elapsed_time(start, end));

  test_result(vd, vd_ref, n);

  free(rs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxvv_m(
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
  fprintf(stderr, "init_vector time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, rs1, vmask, n);
  end = get_time();
  fprintf(stderr, "reference time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, rs1, vmask, n);
  end = get_time();
  fprintf(stderr, "vector time: %f\n", elapsed_time(start, end));

  test_result(vd, vd_ref, n);

  free(rs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VXVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vx_" #type_ret #lmul " ...\n"); \
test_opi_vxvv<type_ret, type2, type1>(op ## _vx_ref<type_ret, type2, type1>, op ## _vx_## type_ret ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VXVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vx_" #type_ret #lmul "_m" " ...\n"); \
test_opi_vxvv_m<type_ret, type2, type1>(op ## _vx_m_ref<type_ret, type2, type1>, op ## _vx_## type_ret ## lmul ## _m_vec, TEST_LENGTH)

#define TEST_OPI_VXVV_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VXVV, op)

#define TEST_OPI_VXVV_III_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_III_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_UUU_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(TEST_OPI_VXVV, op)
#define TEST_OPI_VXVV_IUI_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(TEST_OPI_VXVV, op)

#define TEST_OPI_VXVV_M_GROUP(op)     TEST_OPI3OPS_COMMON_GROUP(TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP(op) TEST_OPI3OPS_COMMON_III_GROUP(TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP(op) TEST_OPI3OPS_COMMON_UUU_GROUP(TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP(op) TEST_OPI3OPS_COMMON_IUI_GROUP(TEST_OPI_VXVV_M, op)

#define TEST_OPI_VXVV_III_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_III_GROUP_MF8( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_III_GROUP_MF4( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_III_GROUP_MF2( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_III_GROUP_M1(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_III_GROUP_M2(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_III_GROUP_M4(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_III_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_III_GROUP_M8(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF8( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF4( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_UUU_GROUP_MF2( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M1(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M2(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M4(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_UUU_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_UUU_GROUP_M8(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_MF8(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF8( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_MF4(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF4( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_MF2(op) TEST_OPI3OPS_COMMON_IUI_GROUP_MF2( TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_M1(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M1(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_M2(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M2(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_M4(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M4(  TEST_OPI_VXVV_M, op)
#define TEST_OPI_VXVV_IUI_M_GROUP_M8(op)  TEST_OPI3OPS_COMMON_IUI_GROUP_M8(  TEST_OPI_VXVV_M, op)

#define TEST_OPI_VXVV_ALL() \
TEST_OPI_VXVV_GROUP(vmacc) \
TEST_OPI_VXVV_GROUP(vnmsac) \
TEST_OPI_VXVV_GROUP(vmadd) \
TEST_OPI_VXVV_GROUP(vnmsub) \

#define TEST_OPI_VXVV_M_ALL() \
TEST_OPI_VXVV_M_GROUP(vmacc) \
TEST_OPI_VXVV_M_GROUP(vnmsac) \
TEST_OPI_VXVV_M_GROUP(vmadd) \
TEST_OPI_VXVV_M_GROUP(vnmsub) \
