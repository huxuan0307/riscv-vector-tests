#include <stdint.h>

typedef float float32_t;
typedef double float64_t;

#define TEST_OPFVVV(op, type, tp, lmul) \
printf("\ntest " #op "_vv_" #tp #lmul " ...\n"); \
test_opivvv<type, type, type>(op ## _vv_ref<type>, op ## _vv_## tp ## lmul ## _vec)

#define TEST_OPFVVV_GROUP_MF2(op) \
TEST_OPFVVV(op,  float32_t, f32,  mf2); \

#define TEST_OPFVVV_GROUP_M1(op)  \
TEST_OPFVVV(op,  float32_t, f32,  m1);  \
TEST_OPFVVV(op,  float64_t, f64,  m1);  \

#define TEST_OPFVVV_GROUP_M2(op)  \
TEST_OPFVVV(op,  float32_t, f32,  m2);  \
TEST_OPFVVV(op,  float64_t, f64,  m2);  \

#define TEST_OPFVVV_GROUP_M4(op)  \
TEST_OPFVVV(op,  float32_t, f32,  m4);  \
TEST_OPFVVV(op,  float64_t, f64,  m4);  \

#define TEST_OPFVVV_GROUP_M8(op)  \
TEST_OPFVVV(op,  float32_t, f32,  m8);  \
TEST_OPFVVV(op,  float64_t, f64,  m8);  \

#define TEST_OPFVVV_F32_GROUP(op) \
TEST_OPFVVV(op,  float32_t, f32,  mf2); \
TEST_OPFVVV(op,  float32_t, f32,  m1);  \
TEST_OPFVVV(op,  float32_t, f32,  m2);  \
TEST_OPFVVV(op,  float32_t, f32,  m4);  \
TEST_OPFVVV(op,  float32_t, f32,  m8);  \

#define TEST_OPFVVV_F64_GROUP(op) \
TEST_OPFVVV(op,  float64_t, f64,  m1);  \
TEST_OPFVVV(op,  float64_t, f64,  m2);  \
TEST_OPFVVV(op,  float64_t, f64,  m4);  \
TEST_OPFVVV(op,  float64_t, f64,  m8);  \

#define TEST_OPFVVV_GROUP(op) \
{ \
  TEST_OPFVVV_GROUP_MF2(op) \
  TEST_OPFVVV_GROUP_M1(op) \
  TEST_OPFVVV_GROUP_M2(op) \
  TEST_OPFVVV_GROUP_M4(op) \
  TEST_OPFVVV_GROUP_M8(op) \
}
