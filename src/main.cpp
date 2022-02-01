#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "utils.h" 
#include "sdef.h"
#include "vdef.h"
#include "test_def.h"

int main(int argc, char *argv[])
{
  TEST_OPI_VXV_ALL();
  TEST_OPIVV_ALL();
  TEST_OPIVVV_ALL();
  TEST_OPFVVV_ALL();
  TEST_OPIVVV_M_ALL();
  TEST_OPFVVV_M_ALL();


  return 0;
}
