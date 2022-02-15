#ifndef _MY_TESTS_UTILS_
#define _MY_TESTS_UTILS_

#include <type_traits>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <time.h>
#include <sys/time.h>
#include <float.h>

bool inline get_bit(const uint8_t* bits, const size_t i) {
  return (bits[i/8] >> (i%8)) & 0x1;
}

template<typename Type>
void copy_vector(Type* dst, Type* src, uint64_t n)
{
  int i;
  for (i=0; i<n; i++) {
    dst[i]=src[i];
  }
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @param maxRelDiff : max relative difference
 * @return true : nearly equal
 * @return false : not equal
 * @ref https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
 */
inline bool near_eq(float a, float b, float maxRelDiff = FLT_EPSILON * 4) {
  float diff = std::fabs(a - b);
  a = std::fabs(a);
  b = std::fabs(b);
  float largest = std::max(a, b);
  return diff <= (largest * maxRelDiff);
}

inline bool near_eq(double a, double b, double maxRelDiff = DBL_EPSILON * 4) {
  double diff = std::fabs(a - b);
  a = std::fabs(a);
  b = std::fabs(b);
  double largest = std::max(a, b);
  return diff <= (largest * maxRelDiff);
}

template<typename Type>
void test_result(Type* y, Type* y_ref, uint64_t n)
{
  uint64_t i;
  uint64_t nerrs=0;
  /* Compute with the result to keep the compiler for marking the code as dead */
  if constexpr (std::is_floating_point<Type>::value) {
    for (i=0; i<n; i++) {
      if (!near_eq(y[i], y_ref[i]))  {
        if constexpr (std::is_same_v<float, std::remove_cv_t<Type>>) {
          printf("y_vec[%4lu]=%.8f != y_ref[%4lu]=%.8f  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        } else if constexpr (std::is_same_v<double, std::remove_cv_t<Type>>) {
          printf("y_vec[%4lu]=%.16f != y_ref[%4lu]=%.16f  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
  else {
    for (i=0; i<n; i++) {
      if (y[i] != y_ref[i]) {
        if constexpr(sizeof(Type) == 1) {
          printf("y_vec[%4lu]=%hhx != y_ref[%4lu]=%hhx  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        else if constexpr(sizeof(Type) == 2) {
          printf("y_vec[%4lu]=%hx != y_ref[%4lu]=%hx  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        else if constexpr(sizeof(Type) == 4) {
          printf("y_vec[%4lu]=%x != y_ref[%4lu]=%x  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        else if constexpr(sizeof(Type) == 8) {
          printf("y_vec[%4lu]=%lx != y_ref[%4lu]=%lx  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
}

template<typename Type>
void test_result_with_mask(Type* y, Type* y_ref, const uint8_t* mask, uint64_t n)
{
  uint64_t i;
  uint64_t nerrs=0;
  /* Compute with the result to keep the compiler for marking the code as dead */
  if (std::is_floating_point<Type>::value) {
    for (i=0; i<n; i++) {
      if (get_bit(mask, i) && !near_eq(y[i], y_ref[i]))  {
        if constexpr (std::is_same_v<float, std::remove_cv_t<Type>>) {
          printf("y_vec[%4lu]=%.8f != y_ref[%4lu]=%.8f  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        } else if constexpr (std::is_same_v<double, std::remove_cv_t<Type>>) {
          printf("y_vec[%4lu]=%.16f != y_ref[%4lu]=%.16f  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        }
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
  else {
    for (i=0; i<n; i++) {
      if (get_bit(mask, i) && y[i] != y_ref[i]) {
        printf("y_vec[%4d]=%llx != y_ref[%4d]=%llx  INCORRECT RESULT !!!! \n", i, y[i], i, y_ref[i]);
        nerrs++;
        if (nerrs == 100) break;
      }
    }
    if (nerrs == 0) {
      printf ("pass !!!\n");
    }
  }
}

void test_mask_result(const uint8_t* y, const uint8_t* y_ref, uint64_t n);

void test_mask_result_with_mask(const uint8_t* y, const uint8_t* y_ref, 
  const uint8_t* mask, uint64_t n);

long long get_time();

// Returns the number of seconds elapsed between the two specified times
float elapsed_time(long long start_time, long long end_time);
/*************************************************************************/

template<typename Type>
void init_vector(Type* pv, const size_t n, Type value) {
  for (int i=0; i<n; i++) pv[i]= value;
}

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

#define debug(flag, ...) \
debug_##flag(__VA_ARGS__)

#ifdef show_performance
#define debug_performance(...) printf(__VA_ARGS__)
#else
#define debug_performance(...)
#endif

#ifdef show_details
#define debug_details(...) printf(__VA_ARGS__)
#else
#define debug_details(...)
#endif

#ifdef show_origin
#define debug_origin(...) printf(__VA_ARGS__)
#else
#define debug_origin(...)
#endif

#endif
