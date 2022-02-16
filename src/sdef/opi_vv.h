#ifndef __SDEF_OPI_VV_H__
#define __SDEF_OPI_VV_H__

#include "common.h"

#define VOPI_VV_REF_DEF(op, code) \
template<typename Type> \
void op ## _v_v_ref(Type* vd, Type* vs, size_t n) { \
  {code;} \
} \

VOPI_VV_REF_DEF(vmv,            FORLOOP(i, vd[i] = vs[i]))

#endif
