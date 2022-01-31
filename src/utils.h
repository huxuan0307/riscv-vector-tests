#ifndef _MY_TESTS_UTILS_
#define _MY_TESTS_UTILS_

#include <type_traits>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <time.h>
#include <sys/time.h>

template<typename Type>
void copy_vector(Type* dst, Type* src, uint64_t n)
{
  int i;
  for (i=0; i<n; i++) {
    dst[i]=src[i];
  }
}

template<typename Type>
void test_result(Type* y, Type* y_ref, uint64_t nrows)
{
  uint64_t row;
  uint64_t nerrs=0;
  /* Compute with the result to keep the compiler for marking the code as dead */
  if (std::is_floating_point<Type>::value) {
    for (row=0; row<nrows; row++) {
      double error = y[row] - y_ref[row];
      if (fabs(error) > 0.0000001)  {
        printf("y_vec[%ld]=%.16f != y_ref[%ld]=%.16f  INCORRECT RESULT !!!! \n", row, y[row], row, y_ref[row]);
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
  else {
    for (row=0; row<nrows; row++) {
      if (y[row] != y_ref[row]) {
        printf("y_vec[%4d]=%llx != y_ref[%4d]=%llx  INCORRECT RESULT !!!! \n", row, y[row], row, y_ref[row]);
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
}

long long get_time();

// Returns the number of seconds elapsed between the two specified times
float elapsed_time(long long start_time, long long end_time);
/*************************************************************************/

template<typename Type>
void init_vector(Type* pv, const size_t n, Type value) {
  for (int i=0; i<n; i++) pv[i]= value;
}

void init_vector(double *pv, long n, double value);

uint32_t rand32bit();

uint64_t rand64bit();

void init_vector(double* pv, const size_t n);
void init_vector(float* pv, const size_t n);
void init_vector(int64_t* pv, const size_t n);
void init_vector(uint64_t* pv, const size_t n);
void init_vector(int32_t* pv, const size_t n);
void init_vector(uint32_t* pv, const size_t n);
void init_vector(int16_t* pv, const size_t n);
void init_vector(uint16_t* pv, const size_t n);
void init_vector(int8_t* pv, const size_t n);
void init_vector(uint8_t* pv, const size_t n);
void init_vector(bool* pv, const size_t n);
void init_mask_vector(uint8_t* pv, const size_t n);

#endif
