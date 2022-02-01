#include "test_def/opi_vvv_def.h"
#include "test_def/opi_vxv_def.h"
#include "test_def/opi_vv_def.h"
#include "test_def/opf_vvv_def.h"
#include "test_def/test_template.h"

#define TEST_OPIVV_ALL() \
TEST_OPIVV_GROUP(vmv) \

#define TEST_OPIVVV_ALL() \
TEST_OPIVVV_GROUP(vadd) \
TEST_OPIVVV_GROUP(vsub) \
TEST_OPIVVV_III_GROUP(vmin) \
TEST_OPIVVV_III_GROUP(vmax) \
TEST_OPIVVV_UUU_GROUP(vminu) \
TEST_OPIVVV_UUU_GROUP(vmaxu) \
TEST_OPIVVV_GROUP(vand) \
TEST_OPIVVV_GROUP(vor) \
TEST_OPIVVV_GROUP(vxor) \
/*TEST_OPIVVV_GROUP(vrgather)*/ \
TEST_OPIVVV_IUI_GROUP(vsll) \
TEST_OPIVVV_UUU_GROUP(vsll) \
TEST_OPIVVV_UUU_GROUP(vsrl) \
TEST_OPIVVV_IUI_GROUP(vsra) \

#define TEST_OPI_VXV_ALL() \
TEST_OPI_VXV_GROUP(vadd) \
TEST_OPI_VXV_GROUP(vsub) \
TEST_OPI_VXV_GROUP(vrsub) \
TEST_OPI_VXV_III_GROUP(vmin) \
TEST_OPI_VXV_III_GROUP(vmax) \
TEST_OPI_VXV_UUU_GROUP(vminu) \
TEST_OPI_VXV_UUU_GROUP(vmaxu) \
TEST_OPI_VXV_GROUP(vand) \
TEST_OPI_VXV_GROUP(vor) \
TEST_OPI_VXV_GROUP(vxor) \
TEST_OPI_VXV_IUI_GROUP(vsll) \
TEST_OPI_VXV_UUU_GROUP(vsll) \
TEST_OPI_VXV_UUU_GROUP(vsrl) \
TEST_OPI_VXV_IUI_GROUP(vsra) \


#define TEST_OPFVVV_ALL() \
TEST_OPFVVV_GROUP(vfadd) \
TEST_OPFVVV_GROUP(vfsub) \
TEST_OPFVVV_GROUP(vfmul) \
TEST_OPFVVV_GROUP(vfdiv) \
TEST_OPFVVV_GROUP(vfmax) \
TEST_OPFVVV_GROUP(vfmin) \
TEST_OPFVVV_GROUP(vfsgnj) \
TEST_OPFVVV_GROUP(vfsgnjn) \
TEST_OPFVVV_GROUP(vfsgnjx) \

#define TEST_OPFVVV_M_ALL() \
TEST_OPFVVV_M_GROUP(vfadd) \
TEST_OPFVVV_M_GROUP(vfsub) \
TEST_OPFVVV_M_GROUP(vfmul) \
TEST_OPFVVV_M_GROUP(vfdiv) \
TEST_OPFVVV_M_GROUP(vfmax) \
TEST_OPFVVV_M_GROUP(vfmin) \
TEST_OPFVVV_M_GROUP(vfsgnj) \
TEST_OPFVVV_M_GROUP(vfsgnjn) \
TEST_OPFVVV_M_GROUP(vfsgnjx) \

#define TEST_OPIVVV_M_ALL() \
TEST_OPIVVV_M_GROUP(vadd)\
TEST_OPIVVV_M_GROUP(vsub)\
TEST_OPIVVV_III_M_GROUP(vmin)\
TEST_OPIVVV_III_M_GROUP(vmax)\
TEST_OPIVVV_UUU_M_GROUP(vminu)\
TEST_OPIVVV_UUU_M_GROUP(vmaxu)\
TEST_OPIVVV_M_GROUP(vand)\
TEST_OPIVVV_M_GROUP(vor)\
TEST_OPIVVV_M_GROUP(vxor)\
/*TEST_OPIVVV_M_GROUP(vrgather)*/\
TEST_OPIVVV_IUI_M_GROUP(vsll)\
TEST_OPIVVV_UUU_M_GROUP(vsll)\
TEST_OPIVVV_UUU_M_GROUP(vsrl)\
TEST_OPIVVV_IUI_M_GROUP(vsra)\

