#ifndef __TDEF_OPI_VVM_H__
#define __TDEF_OPI_VVM_H__

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
  debug(details, "test length: %zu\n", n);
  /* Allocate the source and result vectors */
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(vs1, n);
  init_vector(vs2, n);

  for(size_t i=0; i<n; i++) {
    const char* int_flag = nullptr;
    if constexpr(sizeof(TypeSrc2) == 1) {
      int_flag = "%hhx";
    } else if constexpr(sizeof(TypeSrc2) == 2) {
      int_flag = "%hx";
    } else if constexpr(sizeof(TypeSrc2) == 4) {
      int_flag = "%lx";
    } else {
      int_flag = "%llx";
    }
    std::ostringstream oss;
    oss << "vs1[%zu]=" << int_flag << ", vs2[%zu]=" << int_flag << "\n";
    std::string format = oss.str();
    debug(origin, format.data(), 
      i, vs1[i], i, vs2[i]
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

  test_mask_result(vd, vd_ref, n);

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
  debug(details, "test length: %zu\n", n);
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

  for(size_t i=0; i<n; i++) {
    debug(origin, "vd[%4lu]=%llx, vs1[%4lu]=%llx, vs2[%4lu]=%llx, vmask[%4lu]=%d\n", 
      i, get_bit(vd, i), i, vs1[i], i, vs2[i], i, get_bit(vmask, i)
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

  test_mask_result_with_mask(vd, vd_ref, vmask, n);

  free(vmask); free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define TEST_OPI_VVM(op, type, lmul) \
printf("\ntest " #op "_vv_" #type #lmul " ...\n"); \
test_opi_vvm<uint8_t, type, type>(op ## _vv_ref<type, type>, op ## _vv_## type ## lmul ## _vec, TEST_LENGTH)

#define TEST_OPI_VVM_M(op, type, lmul) \
printf("\ntest " #op "_vv_" #type #lmul "_m " " ...\n"); \
test_opi_vvm_m<type, type>(op ## _vv_m_ref<type, type>, op ## _vv_## type ## lmul ## _m_vec, TEST_LENGTH)

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

#define TEST_OPI_VVM_ALL() \
TEST_OPI_VVM_GROUP(vmseq) \
TEST_OPI_VVM_GROUP(vmsne) \
TEST_OPI_VVM_UU_GROUP(vmsltu) \
TEST_OPI_VVM_II_GROUP(vmslt) \
TEST_OPI_VVM_UU_GROUP(vmsleu) \
TEST_OPI_VVM_II_GROUP(vmsle) \
TEST_OPI_VVM_GROUP(vmadc) \
TEST_OPI_VVM_GROUP(vmsbc) \

#define TEST_OPI_VVM_M_ALL() \
TEST_OPI_VVM_M_GROUP(vmseq) \
TEST_OPI_VVM_M_GROUP(vmsne) \
TEST_OPI_VVM_UU_M_GROUP(vmsltu) \
TEST_OPI_VVM_II_M_GROUP(vmslt) \
TEST_OPI_VVM_UU_M_GROUP(vmsleu) \
TEST_OPI_VVM_II_M_GROUP(vmsle) \

#endif
