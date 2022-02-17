#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "utils.h" 
#include "sdef.h"
#include "vdef.h"
#include "tdef.h"

int main(int argc, char *argv[])
{
  TEST_LSMASK_ALL();
  TEST_OPI_VV_ALL();
  TEST_OPI_VVV_ALL();
  TEST_OPI_VVV_M_ALL();
  TEST_OPI_VXV_ALL();
  TEST_OPI_VXV_M_ALL();
  TEST_OPI_VVM_ALL();
  TEST_OPI_VVM_M_ALL();
  TEST_OPI_VXM_ALL();
  TEST_OPI_VXM_M_ALL();
  TEST_OPI_VVW_ALL();
  TEST_OPI_VVW_M_ALL();
  TEST_OPI_VWW_ALL();
  TEST_OPI_VWW_M_ALL();
  TEST_OPI_VVVV_ALL();
  TEST_OPI_VVVV_M_ALL();
  TEST_OPI_VXVV_ALL();
  TEST_OPI_VXVV_M_ALL();
  TEST_OPI_VVMV_ALL();
  TEST_OPI_VXMV_ALL();
  TEST_OPI_VVMM_ALL();
  TEST_OPI_VXMM_ALL();
  TEST_OPI_VVWW_ALL();
  TEST_OPI_VVWW_M_ALL();
  TEST_OPI_VXWW_ALL();
  TEST_OPI_VXWW_M_ALL();
  TEST_OPF_VVV_ALL();
  TEST_OPF_VVV_M_ALL();
  TEST_OPF_VVW_ALL();
  TEST_OPF_VVW_M_ALL();
  TEST_OPF_VWW_ALL();
  TEST_OPF_VWW_M_ALL();
  TEST_OPF_VFV_ALL();
  TEST_OPF_VFV_M_ALL();
  TEST_OPF_VVVV_ALL();
  TEST_OPF_VVVV_M_ALL();
  TEST_OPF_VVWW_ALL();
  TEST_OPF_VVWW_M_ALL();
  TEST_OPI_VX_ALL();
  return 0;
}
