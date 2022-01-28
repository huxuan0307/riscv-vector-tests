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
  // test_opivvv_m<int8_t, int8_t, int8_t>(vadd_vv_m_ref, vadd_vv_i8m1_m_vec);
  TEST_OPIVVV_GROUP(vadd);
  TEST_OPIVVV_GROUP(vsub);
  TEST_OPIVVV_III_GROUP(vmin);
  TEST_OPIVVV_III_GROUP(vmax);
  TEST_OPIVVV_UUU_GROUP(vminu);
  TEST_OPIVVV_UUU_GROUP(vmaxu);
  TEST_OPIVVV_GROUP(vand);
  TEST_OPIVVV_GROUP(vor);
  TEST_OPIVVV_GROUP(vxor);
  // TEST_OPIVVV_GROUP(vrgather);
  TEST_OPIVVV_IUI_GROUP(vsll);
  TEST_OPIVVV_UUU_GROUP(vsll);
  TEST_OPIVVV_UUU_GROUP(vsrl);
  TEST_OPIVVV_IUI_GROUP(vsra);
  TEST_OPIVV_GROUP(vmv);

  TEST_OPFVVV_GROUP(vfadd);
  TEST_OPFVVV_GROUP(vfsub);
  TEST_OPFVVV_GROUP(vfmul);
  TEST_OPFVVV_GROUP(vfdiv);
  TEST_OPFVVV_GROUP(vfmax);
  TEST_OPFVVV_GROUP(vfmin);
  TEST_OPFVVV_GROUP(vfsgnj);
  TEST_OPFVVV_GROUP(vfsgnjn);
  TEST_OPFVVV_GROUP(vfsgnjx);


  return 0;
}
