#include <cstdio>
#include "../utils.h"

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvvv(
  void (*ref_func)(TypeRet*, TypeSrc2*, TypeSrc1*, int), 
  void (*vector_func)(TypeRet*, TypeSrc2*, TypeSrc1*, int),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  /* Allocate the source and result vectors */
  TypeSrc1 *vs1    = (TypeSrc1*)  malloc(n*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  TypeRet  *vd_old = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd     = (TypeRet*)   malloc(n*sizeof(TypeRet));
  TypeRet  *vd_ref = (TypeRet*)   malloc(n*sizeof(TypeRet));

  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd_old,  n);
  copy_result(vd_ref, vd_old, n);
  copy_result(vd, vd_old, n);

  end = get_time();
  printf("init_vector time: %f\n", elapsed_time(start, end));

  printf ("doing reference calculate\n");
  start = get_time();

  ref_func(vd_ref, vs2, vs1, n);

  end = get_time();
  printf("reference time: %f\n", elapsed_time(start, end));

  printf ("doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs2, vs1, n);
  end = get_time();
  printf("vector time: %f\n", elapsed_time(start, end));

  printf ("done\n");
  test_result(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvv(
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

  test_result(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define test_opf_vvv test_opi_vvv

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

template<typename TypeSrc2, typename TypeSrc1>
void test_opi_vxm(
  void (*ref_func)(uint8_t*, TypeSrc2*, TypeSrc1*, size_t), 
  void (*vector_func)(uint8_t*, TypeSrc2*, TypeSrc1*, size_t),
  size_t test_size = 1024
) {

  long long start,end;

  start = get_time();

  const size_t n = test_size;
  printf("test length: %zu\n", n);
  /* Allocate the source and result vectors */
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  uint8_t  *vd     = (uint8_t*)   malloc(n*sizeof(uint8_t));
  uint8_t  *vd_ref = (uint8_t*)   malloc(n*sizeof(uint8_t));

  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<uint8_t>(0));
  init_vector(vd_ref, n, static_cast<uint8_t>(0));
#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%4lu]=%d, rs1[%4lu]=%llx, vs2[%4lu]=%llx\n", 
      i, get_bit(vd, i), 0, rs1[0], i, vs2[i]
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

  test_mask_result(vd, vd_ref, n);

  free(rs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeSrc2, typename TypeSrc1>
void test_opi_vxm_m(
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
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  uint8_t  *vd     = (uint8_t*)   malloc(n*sizeof(uint8_t));
  uint8_t  *vd_ref = (uint8_t*)   malloc(n*sizeof(uint8_t));

  init_mask_vector(vmask, n);
  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<uint8_t>(0));
  init_vector(vd_ref, n, static_cast<uint8_t>(0));
#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%4lu]=%d, rs1[%4lu]=%llx, vs2[%4lu]=%llx, vmask[%4lu]=%d\n", 
      i, get_bit(vd, i), 0, rs1[0], i, vs2[i], i, get_bit(vmask, i)
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

  test_mask_result_with_mask(vd, vd_ref, vmask, n);

  free(rs1); free(vs2); free(vd); free(vd_ref);
}

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

template<typename TypeSrc2, typename TypeSrc1>
void test_opi_vxmm(
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
  TypeSrc1 *rs1    = (TypeSrc1*)  malloc(1*sizeof(TypeSrc1));
  TypeSrc2 *vs2    = (TypeSrc2*)  malloc(n*sizeof(TypeSrc2));
  uint8_t  *vd     = (uint8_t*)   malloc(n*sizeof(uint8_t));
  uint8_t  *vd_ref = (uint8_t*)   malloc(n*sizeof(uint8_t));

  init_mask_vector(vmask, n);
  init_vector(rs1, 1);
  init_vector(vs2, n);
  init_vector(vd, n, static_cast<uint8_t>(0));
  init_vector(vd_ref, n, static_cast<uint8_t>(0));
#ifdef SHOW_ORIGIN
  for(size_t i=0; i<n; i++) {
    printf("vd[%zu]=%llx, rs1[0]=%llx, vs2[%zu]=%llx, vmask[%zu]=%d\n", 
      i, vd[i], i, rs1[0], i, vs2[i], i, ((vmask[i/8] >> (i%8)) & 0x1)
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

  test_result(vd, vd_ref, (n+7)/8);

  free(vmask); free(rs1); free(vs2); free(vd); free(vd_ref);
}

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxv(
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

#define test_opf_vfv test_opi_vxv

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vxv_m(
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

#define test_opf_vfv_m test_opi_vxv_m

template<typename TypeRet, typename TypeSrc2, typename TypeSrc1>
void test_opi_vvv_m(
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
  
  init_vector(vs1, n);
  init_vector(vs2, n);
  init_vector(vd, n);
  copy_vector(vd_ref, vd, n);
  init_mask_vector(vmask, n);

#ifdef SHOW_ORIGIN
  for(size_t i=0; i<100; i++) {
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

  test_result(vd, vd_ref, n);

  free(vs1); free(vs2); free(vd); free(vd_ref);
}

#define test_opi_vvmv test_opi_vvv_m
#define test_opf_vvv_m test_opi_vvv_m

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
  fprintf(stderr, "init_vector time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing reference calculate\n");
  start = get_time();
  ref_func(vd_ref, vs1, n);
  end = get_time();
  fprintf(stderr, "reference time: %f\n", elapsed_time(start, end));

  fprintf(stderr, "doing vector calculate\n");
  start = get_time();
  vector_func(vd, vs1, n);
  end = get_time();
  fprintf(stderr, "vector time: %f\n", elapsed_time(start, end));
  
  test_result(vd, vd_ref, n);

  free(vs1); free(vd); free(vd_ref);
}
