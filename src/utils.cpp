#include "utils.h"
#include <limits>

void test_mask_result(const uint8_t* y, const uint8_t* y_ref, uint64_t n)
{
  uint64_t nerrs=0;
  for (uint64_t i=0; i<n; i++) {
    if (get_bit(y, i) != get_bit(y_ref, i)) {
      printf("y_vec[%4lu]=%d != y_ref[%4lu]=%d  INCORRECT RESULT !!!! \n", 
            i, get_bit(y, i), i, get_bit(y_ref, i));
      nerrs++;
      if (nerrs == 100) break;
    }
  }
  if (nerrs == 0) {
    printf ("pass !!!\n");
  }
}

void test_mask_result_with_mask(const uint8_t* y, const uint8_t* y_ref, 
  const uint8_t* mask, uint64_t n)
{
  uint64_t nerrs=0;
  for (uint64_t i=0; i<n; i++) {
    if (get_bit(mask, i) && get_bit(y, i) != get_bit(y_ref, i)) {
      printf("y_vec[%4lu]=%d != y_ref[%4lu]=%d  INCORRECT RESULT !!!! \n", 
            i, get_bit(y, i), i, get_bit(y_ref, i));
      nerrs++;
      if (nerrs == 100) break;
    }
  }
  if (nerrs == 0) {
    printf ("pass !!!\n");
  }
}

long long get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000000) + tv.tv_usec;
}

// Returns the number of seconds elapsed between the two specified times
float elapsed_time(long long start_time, long long end_time) {
  return (float) (end_time - start_time) / (1000 * 1000);
}

uint32_t rand32bit() {
  return rand() | (rand() %2==0 ? 0x80000000 : 0);
}

uint64_t rand64bit() {
  return (((uint64_t)rand32bit()) << 32) | rand32bit();
}

void init_vector(double* pv, const size_t n)
{
  for (size_t i=0; i<n; i++)
    pv[i] = (double)1000*((double)rand()/((double)RAND_MAX)*2-1);
}

void init_vector(float* pv, const size_t n)
{
  for (size_t i=0; i<n; i++)
    pv[i] = (float)1000*((float)rand()/((float)RAND_MAX)*2-1);
}

void init_vector(int64_t* pv, const size_t n)
{
  for (size_t i=0; i<n; i++) {
    uint64_t tmp = rand64bit();
    pv[i] = *(int64_t*)(&tmp);
  }
}

void init_vector(uint64_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++)
    pv[i] = rand64bit();
}

void init_vector(int32_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++) {
    uint32_t tmp = rand32bit();
    pv[i] = *(int32_t*)(&tmp);
  }
}

void init_vector(uint32_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++)
    pv[i] = rand32bit();
}

void init_vector(int16_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++) {
    uint16_t tmp = static_cast<uint16_t>(rand32bit() & 0xffff);
    pv[i] = *(int16_t*)(&tmp);
  }
}

void init_vector(uint16_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++) {
    pv[i] = static_cast<uint16_t>(rand32bit() & 0xffff);
  }
}

void init_vector(int8_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++) {
    uint8_t tmp = static_cast<uint8_t>(rand32bit() & 0xff);
    pv[i] = *(int8_t*)(&tmp);
  }
}

void init_vector(uint8_t* pv, const size_t n) {
  for (size_t i=0; i<n; i++) {
    pv[i] = static_cast<uint8_t>(rand32bit() & 0xff);
  }
}

void init_vector(bool* pv, const size_t n) {
  for (size_t i=0; i<n; i++)
    pv[i] = rand() % 2 == 0;
}

void init_mask_vector(uint8_t* pv, const size_t n) {
  for (size_t i=0; i<(n+7)/8; i++) {
    pv[i] = static_cast<uint8_t>(rand32bit() & 0xff);
  }
}