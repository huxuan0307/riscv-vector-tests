#ifndef __TDEF_OPF_VVVV_H__
#define __TDEF_OPF_VVVV_H__

#include "common.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opf_vvvv(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  debug(details, "test length: %zu\n", n);
  /* Allocate the source and result vectors */
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd,  n);
  copy_vector(vd_ref, vd, n);

  for(size_t i=0; i<n; i++) {
    debug(origin, "vd[%4lu]=%.16f, vs1[%4lu]=%.16f, vs2[%4lu]=%.16f\n", 
      i, vd[i], i, vs1[i], i, vs2[i]
    );
  }

  end = get_time();
  debug(performance, "init_vector time: %f\n", elapsed_time(start, end));

  debug(details, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs2, vs1, n);
  end = get_time();
  debug(performance, "reference time: %f\n", elapsed_time(start, end));

  debug(details, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, vs1, n);
  end = get_time();
  debug(performance, "vector time: %f\n", elapsed_time(start, end));

  test_result(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opf_vvvv_m(
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
    debug(origin, "vd[%d]=%.16f, vs1[%d]=%.16f, vs2[%d]=%.16f, vmask[%d]=%d\n", 
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

  test_result(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPF_VVVV(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul " ...\n"); \
test_opf_vvvv<type_ret, type2, type1>(op ## _vv_ref<type_ret,type2,type1>, op ## _vv_## type_ret ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPF_VVVV_M(op, type2, type1, type_ret, lmul) \
printf("\ntest " #op "_vv_" #type_ret #lmul "_m" " ...\n"); \
test_opf_vvvv_m<type_ret, type2, type1>(op ## _vv_m_ref<type_ret,type2,type1>, op ## _vv_## type_ret ## lmul ## _m_vec, TEST_LENGTH)

#define TEST_OPF_VVVV_COMMON_GROUP_MF2(test, op) \
test(op, f32,  f32,  f32,  mf2); \

#define TEST_OPF_VVVV_COMMON_GROUP_M1(test, op)  \
test(op, f32,  f32,  f32,  m1);  \
test(op, f64,  f64,  f64,  m1);  \

#define TEST_OPF_VVVV_COMMON_GROUP_M2(test, op)  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f64,  f64,  f64,  m2);  \

#define TEST_OPF_VVVV_COMMON_GROUP_M4(test, op)  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f64,  f64,  f64,  m4);  \

#define TEST_OPF_VVVV_COMMON_GROUP_M8(test, op)  \
test(op, f32,  f32,  f32,  m8);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VVVV_COMMON_F32_GROUP(test, op) \
test(op, f32,  f32,  f32,  mf2); \
test(op, f32,  f32,  f32,  m1);  \
test(op, f32,  f32,  f32,  m2);  \
test(op, f32,  f32,  f32,  m4);  \
test(op, f32,  f32,  f32,  m8);  \

#define TEST_OPF_VVVV_COMMON_F64_GROUP(test, op) \
test(op, f64,  f64,  f64,  m1);  \
test(op, f64,  f64,  f64,  m2);  \
test(op, f64,  f64,  f64,  m4);  \
test(op, f64,  f64,  f64,  m8);  \

#define TEST_OPF_VVVV_COMMON_GROUP(test, op) \
TEST_OPF_VVVV_COMMON_GROUP_MF2(test, op) \
TEST_OPF_VVVV_COMMON_GROUP_M1(test, op) \
TEST_OPF_VVVV_COMMON_GROUP_M2(test, op) \
TEST_OPF_VVVV_COMMON_GROUP_M4(test, op) \
TEST_OPF_VVVV_COMMON_GROUP_M8(test, op) \

#define TEST_OPF_VVVV_GROUP(op)     TEST_OPF_VVVV_COMMON_GROUP(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_GROUP_MF2(op) TEST_OPF_VVVV_COMMON_GROUP_MF2(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_GROUP_M1(op)  TEST_OPF_VVVV_COMMON_GROUP_M1(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_GROUP_M2(op)  TEST_OPF_VVVV_COMMON_GROUP_M2(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_GROUP_M4(op)  TEST_OPF_VVVV_COMMON_GROUP_M4(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_GROUP_M8(op)  TEST_OPF_VVVV_COMMON_GROUP_M8(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_F32_GROUP(op) TEST_OPF_VVVV_COMMON_F32_GROUP(TEST_OPF_VVVV, op)
#define TEST_OPF_VVVV_F64_GROUP(op) TEST_OPF_VVVV_COMMON_F64_GROUP(TEST_OPF_VVVV, op)

#define TEST_OPF_VVVV_M_GROUP(op)     TEST_OPF_VVVV_COMMON_GROUP    (TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_M_GROUP_MF2(op) TEST_OPF_VVVV_COMMON_GROUP_MF2(TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_M_GROUP_M1(op)  TEST_OPF_VVVV_COMMON_GROUP_M1 (TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_M_GROUP_M2(op)  TEST_OPF_VVVV_COMMON_GROUP_M2 (TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_M_GROUP_M4(op)  TEST_OPF_VVVV_COMMON_GROUP_M4 (TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_M_GROUP_M8(op)  TEST_OPF_VVVV_COMMON_GROUP_M8 (TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_F32_M_GROUP(op) TEST_OPF_VVVV_COMMON_F32_GROUP(TEST_OPF_VVVV_M, op)
#define TEST_OPF_VVVV_F64_M_GROUP(op) TEST_OPF_VVVV_COMMON_F64_GROUP(TEST_OPF_VVVV_M, op)

#define TEST_OPF_VVVV_ALL() \
TEST_OPF_VVVV_GROUP(vfmacc) \
TEST_OPF_VVVV_GROUP(vfnmacc) \
TEST_OPF_VVVV_GROUP(vfmsac) \
TEST_OPF_VVVV_GROUP(vfnmsac) \
TEST_OPF_VVVV_GROUP(vfmadd) \
TEST_OPF_VVVV_GROUP(vfnmadd) \
TEST_OPF_VVVV_GROUP(vfmsub) \
TEST_OPF_VVVV_GROUP(vfnmsub) \

#define TEST_OPF_VVVV_M_ALL() \
TEST_OPF_VVVV_M_GROUP(vfmacc) \
TEST_OPF_VVVV_M_GROUP(vfnmacc) \
TEST_OPF_VVVV_M_GROUP(vfmsac) \
TEST_OPF_VVVV_M_GROUP(vfnmsac) \
TEST_OPF_VVVV_M_GROUP(vfmadd) \
TEST_OPF_VVVV_M_GROUP(vfnmadd) \
TEST_OPF_VVVV_M_GROUP(vfmsub) \
TEST_OPF_VVVV_M_GROUP(vfnmsub) \

#endif
