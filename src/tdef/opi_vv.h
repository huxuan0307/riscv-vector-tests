#ifndef __TDEF_OPI_VV_H__
#define __TDEF_OPI_VV_H__

#include "common.h"

template<typename TypeRet, typename TypeSrc1>
void test_opi_vv(
  void (*ref_func)(TypeRet*, TypeSrc1*, size_t), 
  void (*vector_func)(TypeRet*, TypeSrc1*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  /* Allocate the source and result vectors */
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(vs1, n);

  end = get_time();
  debug(performance, "init_vector time: %f\n", elapsed_time(start, end));

  debug(details, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs1, n);
  end = get_time();
  debug(performance, "reference time: %f\n", elapsed_time(start, end));

  debug(details, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs1, n);
  end = get_time();
  debug(performance, "vector time: %f\n", elapsed_time(start, end));
  
  test_result(vd, vd_ref, n);

  free(vs1); free(vd); free(vd_ref);
}

#define TEST_OPI_VV(op, type, tp, lmul) \
printf("\ntest " #op "_v_v_" #tp #lmul " ...\n"); \
test_opi_vv<type, type>(op ## _v_v_ref<type>, op ## _v_v_## tp ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VV_INT_GROUP_MF8(op) \
TEST_OPI_VV(op,  int8_t,   i8,   mf8); \

#define TEST_OPI_VV_UINT_GROUP_MF8(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf8); \

#define TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV(op,  int8_t,   i8,   mf4); \
TEST_OPI_VV(op,  int16_t,  i16,  mf4); \

#define TEST_OPI_VV_UINT_GROUP_MF4(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf4); \
TEST_OPI_VV(op,  uint16_t, u16,  mf4); \

#define TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV(op,  int8_t,   i8,   mf2); \
TEST_OPI_VV(op,  int16_t,  i16,  mf2); \
TEST_OPI_VV(op,  int32_t,  i32,  mf2); \

#define TEST_OPI_VV_UINT_GROUP_MF2(op) \
TEST_OPI_VV(op,  uint8_t,  u8,   mf2); \
TEST_OPI_VV(op,  uint16_t, u16,  mf2); \
TEST_OPI_VV(op,  uint32_t, u32,  mf2); \

#define TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m1);  \
TEST_OPI_VV(op,  int16_t,  i16,  m1);  \
TEST_OPI_VV(op,  int32_t,  i32,  m1);  \
TEST_OPI_VV(op,  int64_t,  i64,  m1);  \

#define TEST_OPI_VV_UINT_GROUP_M1(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m1);  \
TEST_OPI_VV(op,  uint16_t, u16,  m1);  \
TEST_OPI_VV(op,  uint32_t, u32,  m1);  \
TEST_OPI_VV(op,  uint64_t, u64,  m1);  \

#define TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m2);  \
TEST_OPI_VV(op,  int16_t,  i16,  m2);  \
TEST_OPI_VV(op,  int32_t,  i32,  m2);  \
TEST_OPI_VV(op,  int64_t,  i64,  m2);  \

#define TEST_OPI_VV_UINT_GROUP_M2(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m2);  \
TEST_OPI_VV(op,  uint16_t, u16,  m2);  \
TEST_OPI_VV(op,  uint32_t, u32,  m2);  \
TEST_OPI_VV(op,  uint64_t, u64,  m2);  \

#define TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m4);  \
TEST_OPI_VV(op,  int16_t,  i16,  m4);  \
TEST_OPI_VV(op,  int32_t,  i32,  m4);  \
TEST_OPI_VV(op,  int64_t,  i64,  m4);  \

#define TEST_OPI_VV_UINT_GROUP_M4(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m4);  \
TEST_OPI_VV(op,  uint16_t, u16,  m4);  \
TEST_OPI_VV(op,  uint32_t, u32,  m4);  \
TEST_OPI_VV(op,  uint64_t, u64,  m4);  \

#define TEST_OPI_VV_INT_GROUP_M8(op)   \
TEST_OPI_VV(op,  int8_t,   i8,   m8);  \
TEST_OPI_VV(op,  int16_t,  i16,  m8);  \
TEST_OPI_VV(op,  int32_t,  i32,  m8);  \
TEST_OPI_VV(op,  int64_t,  i64,  m8);  \

#define TEST_OPI_VV_UINT_GROUP_M8(op)  \
TEST_OPI_VV(op,  uint8_t,  u8,   m8);  \
TEST_OPI_VV(op,  uint16_t, u16,  m8);  \
TEST_OPI_VV(op,  uint32_t, u32,  m8);  \
TEST_OPI_VV(op,  uint64_t, u64,  m8);  \

#define TEST_OPI_VV_GROUP_MF8(op) \
TEST_OPI_VV_INT_GROUP_MF8(op)  \
TEST_OPI_VV_UINT_GROUP_MF8(op) \

#define TEST_OPI_VV_GROUP_MF4(op) \
TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV_UINT_GROUP_MF4(op) \

#define TEST_OPI_VV_GROUP_MF2(op) \
TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV_UINT_GROUP_MF2(op) \

#define TEST_OPI_VV_GROUP_M1(op) \
TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV_UINT_GROUP_M1(op)  \

#define TEST_OPI_VV_GROUP_M2(op) \
TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV_UINT_GROUP_M2(op)  \

#define TEST_OPI_VV_GROUP_M4(op) \
TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV_UINT_GROUP_M4(op)  \

#define TEST_OPI_VV_GROUP_M8(op) \
TEST_OPI_VV_INT_GROUP_M8(op)   \
TEST_OPI_VV_UINT_GROUP_M8(op)   \

#define TEST_OPI_VV_INT_GROUP(op) \
TEST_OPI_VV_INT_GROUP_MF8(op)  \
TEST_OPI_VV_INT_GROUP_MF4(op)  \
TEST_OPI_VV_INT_GROUP_MF2(op)  \
TEST_OPI_VV_INT_GROUP_M1(op)   \
TEST_OPI_VV_INT_GROUP_M2(op)   \
TEST_OPI_VV_INT_GROUP_M4(op)   \
TEST_OPI_VV_INT_GROUP_M8(op)   \

#define TEST_OPI_VV_UINT_GROUP(op) \
TEST_OPI_VV_UINT_GROUP_MF8(op) \
TEST_OPI_VV_UINT_GROUP_MF4(op) \
TEST_OPI_VV_UINT_GROUP_MF2(op) \
TEST_OPI_VV_UINT_GROUP_M1(op)  \
TEST_OPI_VV_UINT_GROUP_M2(op)  \
TEST_OPI_VV_UINT_GROUP_M4(op)  \
TEST_OPI_VV_UINT_GROUP_M8(op)  \

#define TEST_OPI_VV_GROUP(op) \
{ \
  TEST_OPI_VV_GROUP_MF8(op) \
  TEST_OPI_VV_GROUP_MF4(op) \
  TEST_OPI_VV_GROUP_MF2(op) \
  TEST_OPI_VV_GROUP_M1(op) \
  TEST_OPI_VV_GROUP_M2(op) \
  TEST_OPI_VV_GROUP_M4(op) \
  TEST_OPI_VV_GROUP_M8(op) \
}

#define TEST_OPI_VV_ALL() \
TEST_OPI_VV_GROUP(vmv) \

#endif
