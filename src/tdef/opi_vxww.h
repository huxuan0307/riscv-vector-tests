#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxww(
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
  init_vector(vd,  n);
  copy_vector(vd_ref, vd, n);

#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%4lu]=%llx, rs1[%4lu]=%llx, vs2[%4lu]=%llx\n", 
      i, vd[i], 0, rs1[0], i, vs2[i]
    );
  }
#endif

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
void test_opi_vxww_m(
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

#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%4lu]=%llx, rs1[%4lu]=%llx, vs2[%4lu]=%llx, vmask[%d]=%d\n", 
      i, vd[i], 0, rs1[0], i, vs2[i], i, ((vmask[i/8] >> (i%8)) & 0x1)
    );
  }
#endif

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

#define TEST_OPI_VXWW(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vx_" #type_ret #lmul_ret " ...\n"); \
test_opi_vxww<type_ret, type2, type1>(op ## _vx_ref<type_ret, type2, type1>, op ## _vx_## type_ret ## lmul_ret ## _vec, TEST_LENGTH)

#define TEST_OPI_VXWW_M(op, type2, type1, lmul_arg, type_ret, lmul_ret) \
printf("\ntest " #op "_vx_" #type_ret #lmul_ret "_m" " ...\n"); \
test_opi_vxww_m<type_ret, type2, type1>(op ## _vx_m_ref<type_ret, type2, type1>, op ## _vx_## type_ret ## lmul_ret ## _m_vec, TEST_LENGTH)

#define TEST_OPI_VXWW_III(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VXWW(op, type_arg, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VXWW_UUU TEST_OPI_VXWW_III
#define TEST_OPI_VXWW_IUI TEST_OPI_VXWW
#define TEST_OPI_VXWW_UII TEST_OPI_VXWW

#define TEST_OPI_VXWW_III_M(op, type_arg, lmul_arg, type_ret, lmul_ret) \
TEST_OPI_VXWW_M(op, type_arg, type_arg, lmul_arg, type_ret, lmul_ret)
#define TEST_OPI_VXWW_UUU_M TEST_OPI_VXWW_III_M
#define TEST_OPI_VXWW_IUI_M TEST_OPI_VXWW_M
#define TEST_OPI_VXWW_UII_M TEST_OPI_VXWW_M

#define TEST_OPI_VXWW_III_GROUP_IMPL(test, op) \
test(op,  i8,   mf8,  i16,  mf4); \
test(op,  i8,   mf4,  i16,  mf2); \
test(op,  i8,   mf2,  i16,  m1); \
test(op,  i8,   m1,   i16,  m2); \
test(op,  i8,   m2,   i16,  m4); \
test(op,  i8,   m4,   i16,  m8); \
test(op,  i16,  mf4,  i32,  mf2); \
test(op,  i16,  mf2,  i32,  m1); \
test(op,  i16,  m1,   i32,  m2); \
test(op,  i16,  m2,   i32,  m4); \
test(op,  i16,  m4,   i32,  m8); \
test(op,  i32,  mf2,  i64,  m1); \
test(op,  i32,  m1,   i64,  m2); \
test(op,  i32,  m2,   i64,  m4); \
test(op,  i32,  m4,   i64,  m8); \

#define TEST_OPI_VXWW_UUU_GROUP_IMPL(test, op) \
test(op,  u8,   mf8,  u16,  mf4); \
test(op,  u8,   mf4,  u16,  mf2); \
test(op,  u8,   mf2,  u16,  m1); \
test(op,  u8,   m1,   u16,  m2); \
test(op,  u8,   m2,   u16,  m4); \
test(op,  u8,   m4,   u16,  m8); \
test(op,  u16,  mf4,  u32,  mf2); \
test(op,  u16,  mf2,  u32,  m1); \
test(op,  u16,  m1,   u32,  m2); \
test(op,  u16,  m2,   u32,  m4); \
test(op,  u16,  m4,   u32,  m8); \
test(op,  u32,  mf2,  u64,  m1); \
test(op,  u32,  m1,   u64,  m2); \
test(op,  u32,  m2,   u64,  m4); \
test(op,  u32,  m4,   u64,  m8); \

#define TEST_OPI_VXWW_IUI_GROUP_IMPL(test, op) \
test(op,  i8,   u8,   mf8,  i16,  mf4); \
test(op,  i8,   u8,   mf4,  i16,  mf2); \
test(op,  i8,   u8,   mf2,  i16,  m1); \
test(op,  i8,   u8,   m1,   i16,  m2); \
test(op,  i8,   u8,   m2,   i16,  m4); \
test(op,  i8,   u8,   m4,   i16,  m8); \
test(op,  i16,  u16,  mf4,  i32,  mf2); \
test(op,  i16,  u16,  mf2,  i32,  m1); \
test(op,  i16,  u16,  m1,   i32,  m2); \
test(op,  i16,  u16,  m2,   i32,  m4); \
test(op,  i16,  u16,  m4,   i32,  m8); \
test(op,  i32,  u32,  mf2,  i64,  m1); \
test(op,  i32,  u32,  m1,   i64,  m2); \
test(op,  i32,  u32,  m2,   i64,  m4); \
test(op,  i32,  u32,  m4,   i64,  m8); \

#define TEST_OPI_VXWW_UII_GROUP_IMPL(test, op) \
test(op,  u8,   i8,   mf8,  i16,  mf4); \
test(op,  u8,   i8,   mf4,  i16,  mf2); \
test(op,  u8,   i8,   mf2,  i16,  m1); \
test(op,  u8,   i8,   m1,   i16,  m2); \
test(op,  u8,   i8,   m2,   i16,  m4); \
test(op,  u8,   i8,   m4,   i16,  m8); \
test(op,  u16,  i16,  mf4,  i32,  mf2); \
test(op,  u16,  i16,  mf2,  i32,  m1); \
test(op,  u16,  i16,  m1,   i32,  m2); \
test(op,  u16,  i16,  m2,   i32,  m4); \
test(op,  u16,  i16,  m4,   i32,  m8); \
test(op,  u32,  i32,  mf2,  i64,  m1); \
test(op,  u32,  i32,  m1,   i64,  m2); \
test(op,  u32,  i32,  m2,   i64,  m4); \
test(op,  u32,  i32,  m4,   i64,  m8); \

#define TEST_OPI_VXWW_GROUP_IMPL(test, op) \
TEST_OPI_VXWW_III_GROUP_IMPL(test, op) \
TEST_OPI_VXWW_UUU_GROUP_IMPL(test, op) \

#define TEST_OPI_VXWW_GROUP(op)        TEST_OPI_VXWW_GROUP_IMPL(TEST_OPI_VXWW, op)
#define TEST_OPI_VXWW_III_GROUP(op)    TEST_OPI_VXWW_III_GROUP_IMPL(TEST_OPI_VXWW_III, op)
#define TEST_OPI_VXWW_UUU_GROUP(op)    TEST_OPI_VXWW_UUU_GROUP_IMPL(TEST_OPI_VXWW_UUU, op)
#define TEST_OPI_VXWW_IUI_GROUP(op)    TEST_OPI_VXWW_IUI_GROUP_IMPL(TEST_OPI_VXWW_IUI, op)
#define TEST_OPI_VXWW_UII_GROUP(op)    TEST_OPI_VXWW_UII_GROUP_IMPL(TEST_OPI_VXWW_UII, op)

#define TEST_OPI_VXWW_M_GROUP(op)      TEST_OPI_VXWW_GROUP_IMPL(TEST_OPI_VXWW_M, op)
#define TEST_OPI_VXWW_III_M_GROUP(op)  TEST_OPI_VXWW_III_GROUP_IMPL(TEST_OPI_VXWW_III_M, op)
#define TEST_OPI_VXWW_UUU_M_GROUP(op)  TEST_OPI_VXWW_UUU_GROUP_IMPL(TEST_OPI_VXWW_UUU_M, op)
#define TEST_OPI_VXWW_IUI_M_GROUP(op)  TEST_OPI_VXWW_IUI_GROUP_IMPL(TEST_OPI_VXWW_IUI_M, op)
#define TEST_OPI_VXWW_UII_M_GROUP(op)  TEST_OPI_VXWW_UII_GROUP_IMPL(TEST_OPI_VXWW_UII_M, op)

#define TEST_OPI_VXWW_ALL() \
TEST_OPI_VXWW_III_GROUP(vwmacc) \
TEST_OPI_VXWW_UUU_GROUP(vwmaccu) \
TEST_OPI_VXWW_IUI_GROUP(vwmaccus) \
TEST_OPI_VXWW_UII_GROUP(vwmaccsu) \

#define TEST_OPI_VXWW_M_ALL() \
TEST_OPI_VXWW_III_M_GROUP(vwmacc) \
TEST_OPI_VXWW_UUU_M_GROUP(vwmaccu) \
TEST_OPI_VXWW_IUI_M_GROUP(vwmaccus) \
TEST_OPI_VXWW_UII_M_GROUP(vwmaccsu) \
