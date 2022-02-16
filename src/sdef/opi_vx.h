#ifndef __SDEF_OPI_VX_H__
#define __SDEF_OPI_VX_H__

#include "common.h"

template<typename Type> 
void vmv_x_s_ref(Type* rd, Type* vs, size_t n) {
  [[likely]] if (n!=0) {
    rd[0] = vs[0];
  } else {
    rd[0] = rd[-1];
  }
}

#endif
