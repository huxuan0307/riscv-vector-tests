#include <cstdint>
#include <cstddef>
#include <algorithm>

#define VOPIVVV_REF_DEF(op, code) \
template<typename Type> \
void op ## _vv_ref(Type* vd, Type* vs2, Type* vs1, size_t n) { \
  code ; \
} \

#define VOPIVV_REF_DEF(op, code) \
template<typename Type> \
void op ## _v_v_ref(Type* vd, Type* vs, size_t n) { \
  code; \
} \

#define VOPFVVV_REF_DEF(op, code) VOPIVVV_REF_DEF(op, code)

#define FORLOOP(i, code) \
for (size_t i = 0; i < n; i++) { \
  code; \
} \

VOPIVVV_REF_DEF(vadd,           FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPIVVV_REF_DEF(vsub,           FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPIVVV_REF_DEF(vmin,           FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPIVVV_REF_DEF(vminu,          FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPIVVV_REF_DEF(vmax,           FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPIVVV_REF_DEF(vmaxu,          FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPIVVV_REF_DEF(vand,           FORLOOP(i, vd[i] = vs2[i]&vs1[i]))
VOPIVVV_REF_DEF(vor ,           FORLOOP(i, vd[i] = vs2[i]|vs1[i]))
VOPIVVV_REF_DEF(vxor,           FORLOOP(i, vd[i] = vs2[i]^vs1[i]))
VOPIVVV_REF_DEF(vrgather,       FORLOOP(i, vd[i] = vs2[vs1[i]]))
VOPIVVV_REF_DEF(vsll,           FORLOOP(i, vd[i] = vs2[i]<<(vs1[i] & (sizeof(vs2[i])*8-1)) ))
VOPIVVV_REF_DEF(vsrl,           FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1)) ))
VOPIVVV_REF_DEF(vsra,           FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1)) ))

// VOPIVV_REF_DEF(vmul, vd[i]=vs2[i]*vs1[i])
// VOPIVV_REF_DEF(vmulh, vd[i] = (static_cast<__int128_t>(vs2[i])*static_cast<__int128_t>(vs1[i])) & std::numeric_limits<uint64_t>::max());
// VOPIVV_REF_DEF(vmulhu, vd[i]=vs2[i]*vs1[i])
// VOPIVV_REF_DEF(vmulhsu, vd[i]=vs2[i]*vs1[i])
// VOPIVV_REF_DEF(vdivu, vd[i]=vs2[i]/vs1[i])
// VOPIVV_REF_DEF(vdiv, vd[i]=vs2[i]/vs1[i])
// VOPIVV_REF_DEF(vremu, vd[i]=vs2[i]/vs1[i])
// VOPIVV_REF_DEF(vrem, vd[i]=vs2[i]/vs1[i])

VOPIVV_REF_DEF(vmv,             FORLOOP(i, vd[i] = vs[i]))

VOPFVVV_REF_DEF(vfadd,          FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPFVVV_REF_DEF(vfsub,          FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPFVVV_REF_DEF(vfmul,          FORLOOP(i, vd[i] = vs2[i]*vs1[i]))
VOPFVVV_REF_DEF(vfdiv,          FORLOOP(i, vd[i] = vs2[i]/vs1[i]))
VOPFVVV_REF_DEF(vfmax,          FORLOOP(i, vd[i] = std::max(vs2[i],vs1[i])))
VOPFVVV_REF_DEF(vfmin,          FORLOOP(i, vd[i] = std::min(vs2[i],vs1[i])))
VOPFVVV_REF_DEF(vfsgnj,         FORLOOP(i, vd[i] = vs1[i]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPFVVV_REF_DEF(vfsgnjn,        FORLOOP(i, vd[i] = vs1[i]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPFVVV_REF_DEF(vfsgnjx,        FORLOOP(i, vd[i] = vs1[i]>0 ? vs2[i] : -vs2[i]))

