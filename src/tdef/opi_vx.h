#ifndef __TDEF_OPI_VX_H__
#define __TDEF_OPI_VX_H__

#include "common.h"

template<typename Type>
void test_opi_vx(
  void (*ref_func)(Type*, Type*, size_t), 
  void (*vector_func)(Type*, Type*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  /* Allocate the source and result vectors */
  Type  *vs     = (Type*)   malloc(n*sizeof(Type));
  Type  *rd     = (Type*)   malloc(n*sizeof(Type));
  Type  *rd_ref = (Type*)   malloc(n*sizeof(Type));
  uint8_t*n_per_loop = (uint8_t*) malloc(n*sizeof(uint8_t));
  bool  *not_zero_mask = (bool*) malloc(n*sizeof(bool));

  init_vector(vs, n);
  init_vector(rd, n, static_cast<Type>(0));
  init_vector(rd_ref, n, static_cast<Type>(0));
  init_vector(n_per_loop, n);
  init_vector(not_zero_mask, n, true);
  // first elem should not be zero
  n_per_loop[0] = 1u;
  for(size_t i=0; i<n; i++) {
    n_per_loop[i] &= 0x0f;
    not_zero_mask[i] = !(n_per_loop[i] == 0);
  }

  for(size_t i=0; i<n; i++) {
    debug(origin, "rd[%zu]=%llx, vs[%zu]=%llx\n", 
      i, rd[i], i, vs[i]
    );
  }

  end = get_time();
  
  debug(performance, "init_vector time: %f\n", elapsed_time(start, end));
  debug(details, "doing calculate\n");

  start = get_time();
  size_t loop_idx = 0;
  for (size_t i = 0; i < n;) {
    debug(origin, "n in loop[%zu]: %hhx\n", loop_idx, n_per_loop[loop_idx]);
    ref_func(&rd_ref[loop_idx], &vs[i], std::min(static_cast<size_t>(n_per_loop[loop_idx]), n-i));
    vector_func(&rd[loop_idx], &vs[i], std::min(static_cast<size_t>(n_per_loop[loop_idx]), n-i));
    i += n_per_loop[loop_idx];
    loop_idx++;
  }
  end = get_time();

  debug(performance, "reference + vector time: %f\n", elapsed_time(start, end));
  
  test_result(rd, rd_ref, loop_idx);

  free(vs); free(rd); free(rd_ref);
}

#define TEST_VMV_X_S(op, type, lmul) \
printf("\ntest vmv_x_s_" #type #lmul " ...\n"); \
test_opi_vx<type>(vmv_x_s_ref, vmv_x_s_ ## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VX(op, type, lmul) \
printf("\ntest " #op "_v_v_" #type #lmul " ...\n"); \
test_opi_vx<type, type>(op ## _v_v_ref<type>, op ## _v_v_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VX_INT_GROUP_MF8(test, op) \
test(op,  i8,   mf8); \

#define TEST_OPI_VX_UINT_GROUP_MF8(test, op) \
test(op,  u8,   mf8); \

#define TEST_OPI_VX_INT_GROUP_MF4(test, op)  \
test(op,  i8,   mf4); \
test(op,  i16,  mf4); \

#define TEST_OPI_VX_UINT_GROUP_MF4(test, op) \
test(op,  u8,   mf4); \
test(op,  u16,  mf4); \

#define TEST_OPI_VX_INT_GROUP_MF2(test, op)  \
test(op,  i8,   mf2); \
test(op,  i16,  mf2); \
test(op,  i32,  mf2); \

#define TEST_OPI_VX_UINT_GROUP_MF2(test, op) \
test(op,  u8,   mf2); \
test(op,  u16,  mf2); \
test(op,  u32,  mf2); \

#define TEST_OPI_VX_INT_GROUP_M1(test, op)   \
test(op,  i8,   m1);  \
test(op,  i16,  m1);  \
test(op,  i32,  m1);  \
test(op,  i64,  m1);  \

#define TEST_OPI_VX_UINT_GROUP_M1(test, op)  \
test(op,  u8,   m1);  \
test(op,  u16,  m1);  \
test(op,  u32,  m1);  \
test(op,  u64,  m1);  \

#define TEST_OPI_VX_INT_GROUP_M2(test, op)   \
test(op,  i8,   m2);  \
test(op,  i16,  m2);  \
test(op,  i32,  m2);  \
test(op,  i64,  m2);  \

#define TEST_OPI_VX_UINT_GROUP_M2(test, op)  \
test(op,  u8,   m2);  \
test(op,  u16,  m2);  \
test(op,  u32,  m2);  \
test(op,  u64,  m2);  \

#define TEST_OPI_VX_INT_GROUP_M4(test, op)   \
test(op,  i8,   m4);  \
test(op,  i16,  m4);  \
test(op,  i32,  m4);  \
test(op,  i64,  m4);  \

#define TEST_OPI_VX_UINT_GROUP_M4(test, op)  \
test(op,  u8,   m4);  \
test(op,  u16,  m4);  \
test(op,  u32,  m4);  \
test(op,  u64,  m4);  \

#define TEST_OPI_VX_INT_GROUP_M8(test, op)   \
test(op,  i8,   m8);  \
test(op,  i16,  m8);  \
test(op,  i32,  m8);  \
test(op,  i64,  m8);  \

#define TEST_OPI_VX_UINT_GROUP_M8(test, op)  \
test(op,  u8,   m8);  \
test(op,  u16,  m8);  \
test(op,  u32,  m8);  \
test(op,  u64,  m8);  \

#define TEST_OPI_VX_GROUP_MF8(test, op) \
TEST_OPI_VX_INT_GROUP_MF8(test, op)  \
TEST_OPI_VX_UINT_GROUP_MF8(test, op) \

#define TEST_OPI_VX_GROUP_MF4(test, op) \
TEST_OPI_VX_INT_GROUP_MF4(test, op)  \
TEST_OPI_VX_UINT_GROUP_MF4(test, op) \

#define TEST_OPI_VX_GROUP_MF2(test, op) \
TEST_OPI_VX_INT_GROUP_MF2(test, op)  \
TEST_OPI_VX_UINT_GROUP_MF2(test, op) \

#define TEST_OPI_VX_GROUP_M1(test, op) \
TEST_OPI_VX_INT_GROUP_M1(test, op)   \
TEST_OPI_VX_UINT_GROUP_M1(test, op)  \

#define TEST_OPI_VX_GROUP_M2(test, op) \
TEST_OPI_VX_INT_GROUP_M2(test, op)   \
TEST_OPI_VX_UINT_GROUP_M2(test, op)  \

#define TEST_OPI_VX_GROUP_M4(test, op) \
TEST_OPI_VX_INT_GROUP_M4(test, op)   \
TEST_OPI_VX_UINT_GROUP_M4(test, op)  \

#define TEST_OPI_VX_GROUP_M8(test, op) \
TEST_OPI_VX_INT_GROUP_M8(test, op)   \
TEST_OPI_VX_UINT_GROUP_M8(test, op)   \

#define TEST_OPI_VX_INT_GROUP(test, op) \
TEST_OPI_VX_INT_GROUP_MF8(test, op)  \
TEST_OPI_VX_INT_GROUP_MF4(test, op)  \
TEST_OPI_VX_INT_GROUP_MF2(test, op)  \
TEST_OPI_VX_INT_GROUP_M1(test, op)   \
TEST_OPI_VX_INT_GROUP_M2(test, op)   \
TEST_OPI_VX_INT_GROUP_M4(test, op)   \
TEST_OPI_VX_INT_GROUP_M8(test, op)   \

#define TEST_OPI_VX_UINT_GROUP(test, op) \
TEST_OPI_VX_UINT_GROUP_MF8(test, op) \
TEST_OPI_VX_UINT_GROUP_MF4(test, op) \
TEST_OPI_VX_UINT_GROUP_MF2(test, op) \
TEST_OPI_VX_UINT_GROUP_M1(test, op)  \
TEST_OPI_VX_UINT_GROUP_M2(test, op)  \
TEST_OPI_VX_UINT_GROUP_M4(test, op)  \
TEST_OPI_VX_UINT_GROUP_M8(test, op)  \

#define TEST_OPI_VX_GROUP(test, op) \
{ \
  TEST_OPI_VX_GROUP_MF8(test, op) \
  TEST_OPI_VX_GROUP_MF4(test, op) \
  TEST_OPI_VX_GROUP_MF2(test, op) \
  TEST_OPI_VX_GROUP_M1(test, op) \
  TEST_OPI_VX_GROUP_M2(test, op) \
  TEST_OPI_VX_GROUP_M4(test, op) \
  TEST_OPI_VX_GROUP_M8(test, op) \
}

#define TEST_OPI_VX_ALL() \
TEST_OPI_VX_GROUP(TEST_VMV_X_S, vmv) \

#endif
