#ifndef __TDEF_LSMASK_H__
#define __TDEF_LSMASK_H__

#include "common.h"
#include <riscv_vector.h>

void test_lsmask(size_t test_size = 1024) {
  
  long long start,end;

  start = get_time();

  const size_t n = test_size;
  const size_t bytes = (n+7)/8;
  debug(details, "test length: %zu\n", n);
  /* Allocate the source and result vectors */
  uint8_t *vs = (uint8_t*)malloc(bytes*sizeof(uint8_t));
  uint8_t *vd = (uint8_t*)malloc(bytes*sizeof(uint8_t));

  init_mask_vector(vs, n);
  for (size_t i=0; i<n; i++) {
    debug(origin, "vs[%zu]=%d\n", i, get_bit(vs, i));
  }

  vbool1_t vmask;
  for (size_t i=0; i<n;) {
    auto vl = vsetvl_e8m1(n - i);
    __asm__("vlm.v %0, (%1);" : "=vm"(vmask) : "r"(&vs[i/8]));
    uint8_t* vd_ptr = &vd[i/8];
    __asm__ volatile("vsm.v %0, (%1);" :: "vm"(vmask), "r"(&vd[i/8]));
    i += vl;
  }

  test_mask_result(vd, vs, n);
  free(vs); free(vd);
}

#define TEST_LSMASK() \
printf("\ntest vlm.v vsm.v ...\n"); \
test_lsmask(TEST_LENGTH)

#define TEST_LSMASK_ALL() \
TEST_LSMASK()

#endif
