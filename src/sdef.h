#include <cstdint>
#include <cstddef>
#include <algorithm>
#include <type_traits>

#define ASSIGN_BIT(vr, i, val) ((vr[i/8] &= ~(1 << i%8)) |= ((val) << i%8))

template<typename Type>
bool carry_out(Type a, Type b, bool carry_in = false) {
  using TypeU = std::make_unsigned_t<Type>;
  TypeU s = *reinterpret_cast<TypeU*>(&a)
          + *reinterpret_cast<TypeU*>(&b) + carry_in;
  return carry_in
    ? (s <= *reinterpret_cast<TypeU*>(&a))
    : (s <  *reinterpret_cast<TypeU*>(&a));
}

template<typename Type>
bool borrow_out(Type a, Type b, bool borrow_in = false) {
  using TypeU = std::make_unsigned_t<Type>;
  return borrow_in 
    ? (*reinterpret_cast<TypeU*>(&a) <= *reinterpret_cast<TypeU*>(&b))
    : (*reinterpret_cast<TypeU*>(&a) <  *reinterpret_cast<TypeU*>(&b));
}

#define VOPI_VVV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n) { \
  {code;} \
} \

#define VOPI_VXV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n) { \
  {code;} \
} \

#define VOPI_VVV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

#define VOPI_VXV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vx_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

#define VOPF_VVV_REF_DEF(op, code)    VOPI_VVV_REF_DEF(op, code)
#define VOPF_VVV_M_REF_DEF(op, code)  VOPI_VVV_M_REF_DEF(op, code)

#define VOPI_VVMV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vvm_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* vs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

#define VOPI_VVM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, size_t n \
) { \
  {code;} \
} \

#define VOPI_VVM_M_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vv_m_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

#define VOPI_VVMM_REF_DEF(op, code) \
template<typename TypeSrc2, typename TypeSrc1> \
void op ## _vvm_ref( \
  uint8_t* vd, TypeSrc2* vs2, TypeSrc1* vs1, const uint8_t* vmask, size_t n \
) { \
  {code;} \
} \

#define VOPF_VFV_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_ref(TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, size_t n) { \
  {code;} \
} \

#define VOPF_VFV_M_REF_DEF(op, code) \
template<typename TypeRet, typename TypeSrc2, typename TypeSrc1> \
void op ## _vf_m_ref( \
  TypeRet* vd, TypeSrc2* vs2, TypeSrc1* rs1, \
  const uint8_t* vmask, size_t n) { \
  {code;} \
} \

#define VOPI_VV_REF_DEF(op, code) \
template<typename Type> \
void op ## _v_v_ref(Type* vd, Type* vs, size_t n) { \
  {code;} \
} \

#define FORLOOP(i, code) \
for (size_t i = 0; i < n; i++) { \
  {code;} \
} \

#define FORLOOPIF(i, condition, code) \
for (size_t i = 0; i < n; i++) { \
  if (condition) {code;} \
} \

#define VMASK(i)    ((vmask[i/8] >> (i%8)) & 0x1)

VOPI_VVV_REF_DEF(vadd,          FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPI_VVV_REF_DEF(vsub,          FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPI_VVV_REF_DEF(vmin,          FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vminu,         FORLOOP(i, vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vmax,          FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vmaxu,         FORLOOP(i, vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_REF_DEF(vand,          FORLOOP(i, vd[i] = vs2[i]&vs1[i]))
VOPI_VVV_REF_DEF(vor ,          FORLOOP(i, vd[i] = vs2[i]|vs1[i]))
VOPI_VVV_REF_DEF(vxor,          FORLOOP(i, vd[i] = vs2[i]^vs1[i]))
VOPI_VVV_REF_DEF(vrgather,      FORLOOP(i, vd[i] = vs2[vs1[i]]))
VOPI_VVV_REF_DEF(vsll,          FORLOOP(i, vd[i] = vs2[i]<<(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_REF_DEF(vsrl,          FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_REF_DEF(vsra,          FORLOOP(i, vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))

VOPI_VVV_M_REF_DEF(vadd,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+vs1[i]))
VOPI_VVV_M_REF_DEF(vsub,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-vs1[i]))
VOPI_VVV_M_REF_DEF(vmin,        FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vminu,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vmax,        FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vmaxu,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], vs1[i])))
VOPI_VVV_M_REF_DEF(vand,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]&vs1[i]))
VOPI_VVV_M_REF_DEF(vor ,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]|vs1[i]))
VOPI_VVV_M_REF_DEF(vxor,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]^vs1[i]))
VOPI_VVV_M_REF_DEF(vrgather,    FORLOOPIF(i, VMASK(i), vd[i] = vs2[vs1[i]]))
VOPI_VVV_M_REF_DEF(vsll,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]<<(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_M_REF_DEF(vsrl,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))
VOPI_VVV_M_REF_DEF(vsra,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(vs1[i] & (sizeof(vs2[i])*8-1))))

VOPI_VXV_REF_DEF(vadd,          FORLOOP(i, vd[i] = vs2[i]+rs1[0]))
VOPI_VXV_REF_DEF(vsub,          FORLOOP(i, vd[i] = vs2[i]-rs1[0]))
VOPI_VXV_REF_DEF(vrsub,         FORLOOP(i, vd[i] = rs1[0]-vs2[i]))
VOPI_VXV_REF_DEF(vmin,          FORLOOP(i, vd[i] = std::min(vs2[i], rs1[0])))
VOPI_VXV_REF_DEF(vminu,         FORLOOP(i, vd[i] = std::min(vs2[i], rs1[0])))
VOPI_VXV_REF_DEF(vmax,          FORLOOP(i, vd[i] = std::max(vs2[i], rs1[0])))
VOPI_VXV_REF_DEF(vmaxu,         FORLOOP(i, vd[i] = std::max(vs2[i], rs1[0])))
VOPI_VXV_REF_DEF(vand,          FORLOOP(i, vd[i] = vs2[i]&rs1[0]))
VOPI_VXV_REF_DEF(vor ,          FORLOOP(i, vd[i] = vs2[i]|rs1[0]))
VOPI_VXV_REF_DEF(vxor,          FORLOOP(i, vd[i] = vs2[i]^rs1[0]))
VOPI_VXV_REF_DEF(vrgather,      FORLOOP(i, vd[i] = vs2[rs1[0]]))
VOPI_VXV_REF_DEF(vsll,          FORLOOP(i, vd[i] = vs2[i]<<(rs1[0] & (sizeof(vs2[i])*8-1))))
VOPI_VXV_REF_DEF(vsrl,          FORLOOP(i, vd[i] = vs2[i]>>(rs1[0] & (sizeof(vs2[i])*8-1))))
VOPI_VXV_REF_DEF(vsra,          FORLOOP(i, vd[i] = vs2[i]>>(rs1[0] & (sizeof(vs2[i])*8-1))))

VOPI_VXV_M_REF_DEF(vadd,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+rs1[0]))
VOPI_VXV_M_REF_DEF(vsub,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-rs1[0]))
VOPI_VXV_M_REF_DEF(vrsub,       FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]-vs2[i]))
VOPI_VXV_M_REF_DEF(vmin,        FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], rs1[0])))
VOPI_VXV_M_REF_DEF(vminu,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i], rs1[0])))
VOPI_VXV_M_REF_DEF(vmax,        FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], rs1[0])))
VOPI_VXV_M_REF_DEF(vmaxu,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i], rs1[0])))
VOPI_VXV_M_REF_DEF(vand,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]&rs1[0]))
VOPI_VXV_M_REF_DEF(vor ,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]|rs1[0]))
VOPI_VXV_M_REF_DEF(vxor,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]^rs1[0]))
VOPI_VXV_M_REF_DEF(vrgather,    FORLOOPIF(i, VMASK(i), vd[i] = vs2[rs1[0]]))
VOPI_VXV_M_REF_DEF(vsll,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]<<(rs1[0] & (sizeof(vs2[i])*8-1))))
VOPI_VXV_M_REF_DEF(vsrl,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(rs1[0] & (sizeof(vs2[i])*8-1))))
VOPI_VXV_M_REF_DEF(vsra,        FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]>>(rs1[0] & (sizeof(vs2[i])*8-1))))

VOPI_VVMV_REF_DEF(vmerge,       FORLOOP(i, vd[i] = VMASK(i) ? vs1[i] : vs2[i]))
VOPI_VVMV_REF_DEF(vadc,         FORLOOP(i, vd[i] = vs2[i] + vs1[i] + VMASK(i)))
VOPI_VVMV_REF_DEF(vsbc,         FORLOOP(i, vd[i] = vs2[i] - vs1[i] - VMASK(i)))

VOPI_VVM_REF_DEF(vmseq,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] == vs1[i])))
VOPI_VVM_REF_DEF(vmsne,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] != vs1[i])))
VOPI_VVM_REF_DEF(vmsltu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPI_VVM_REF_DEF(vmslt,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <  vs1[i])))
VOPI_VVM_REF_DEF(vmsleu,        FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPI_VVM_REF_DEF(vmsle,         FORLOOP(i, ASSIGN_BIT(vd, i, vs2[i] <= vs1[i])))
VOPI_VVM_REF_DEF(vmadc,         FORLOOP(i, ASSIGN_BIT(vd, i, carry_out(vs2[i], vs1[i]))))
VOPI_VVM_REF_DEF(vmsbc,         FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], vs1[i]))))

VOPI_VVM_M_REF_DEF(vmseq,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] == vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsne,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] != vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsltu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <  vs1[i]))))
VOPI_VVM_M_REF_DEF(vmslt,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <  vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsleu,      FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <= vs1[i]))))
VOPI_VVM_M_REF_DEF(vmsle,       FORLOOPIF(i, VMASK(i), ASSIGN_BIT(vd, i, (vs2[i] <= vs1[i]))))

VOPI_VVMM_REF_DEF(vmadc,        FORLOOP(i, ASSIGN_BIT(vd, i, carry_out(vs2[i], vs1[i], VMASK(i)))))
VOPI_VVMM_REF_DEF(vmsbc,        FORLOOP(i, ASSIGN_BIT(vd, i, borrow_out(vs2[i], vs1[i], VMASK(i)))))

VOPI_VV_REF_DEF(vmv,            FORLOOP(i, vd[i] = vs[i]))

VOPF_VVV_REF_DEF(vfadd,         FORLOOP(i, vd[i] = vs2[i]+vs1[i]))
VOPF_VVV_REF_DEF(vfsub,         FORLOOP(i, vd[i] = vs2[i]-vs1[i]))
VOPF_VVV_REF_DEF(vfmul,         FORLOOP(i, vd[i] = vs2[i]*vs1[i]))
VOPF_VVV_REF_DEF(vfdiv,         FORLOOP(i, vd[i] = vs2[i]/vs1[i]))
VOPF_VVV_REF_DEF(vfmax,         FORLOOP(i, vd[i] = std::max(vs2[i],vs1[i])))
VOPF_VVV_REF_DEF(vfmin,         FORLOOP(i, vd[i] = std::min(vs2[i],vs1[i])))
VOPF_VVV_REF_DEF(vfsgnj,        FORLOOP(i, vd[i] = vs1[i]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_REF_DEF(vfsgnjn,       FORLOOP(i, vd[i] = vs1[i]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_REF_DEF(vfsgnjx,       FORLOOP(i, vd[i] = vs1[i]>0 ? vs2[i] : -vs2[i]))

VOPF_VVV_M_REF_DEF(vfadd,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+vs1[i]))
VOPF_VVV_M_REF_DEF(vfsub,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-vs1[i]))
VOPF_VVV_M_REF_DEF(vfmul,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]*vs1[i]))
VOPF_VVV_M_REF_DEF(vfdiv,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]/vs1[i]))
VOPF_VVV_M_REF_DEF(vfmax,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i],vs1[i])))
VOPF_VVV_M_REF_DEF(vfmin,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i],vs1[i])))
VOPF_VVV_M_REF_DEF(vfsgnj,      FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_M_REF_DEF(vfsgnjn,     FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VVV_M_REF_DEF(vfsgnjx,     FORLOOPIF(i, VMASK(i), vd[i] = vs1[i]>0 ? vs2[i] : -vs2[i]))

VOPF_VFV_REF_DEF(vfadd,         FORLOOP(i, vd[i] = vs2[i]+rs1[0]))
VOPF_VFV_REF_DEF(vfsub,         FORLOOP(i, vd[i] = vs2[i]-rs1[0]))
VOPF_VFV_REF_DEF(vfrsub,        FORLOOP(i, vd[i] = rs1[0]-vs2[i]))
VOPF_VFV_REF_DEF(vfmul,         FORLOOP(i, vd[i] = vs2[i]*rs1[0]))
VOPF_VFV_REF_DEF(vfdiv,         FORLOOP(i, vd[i] = vs2[i]/rs1[0]))
VOPF_VFV_REF_DEF(vfrdiv,        FORLOOP(i, vd[i] = rs1[0]/vs2[i]))
VOPF_VFV_REF_DEF(vfmax,         FORLOOP(i, vd[i] = std::max(vs2[i],rs1[0])))
VOPF_VFV_REF_DEF(vfmin,         FORLOOP(i, vd[i] = std::min(vs2[i],rs1[0])))
VOPF_VFV_REF_DEF(vfsgnj,        FORLOOP(i, vd[i] = rs1[0]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_REF_DEF(vfsgnjn,       FORLOOP(i, vd[i] = rs1[0]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_REF_DEF(vfsgnjx,       FORLOOP(i, vd[i] = rs1[0]>0 ? vs2[i] : -vs2[i]))

VOPF_VFV_M_REF_DEF(vfadd,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]+rs1[0]))
VOPF_VFV_M_REF_DEF(vfsub,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]-rs1[0]))
VOPF_VFV_M_REF_DEF(vfrsub,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]-vs2[i]))
VOPF_VFV_M_REF_DEF(vfmul,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]*rs1[0]))
VOPF_VFV_M_REF_DEF(vfdiv,       FORLOOPIF(i, VMASK(i), vd[i] = vs2[i]/rs1[0]))
VOPF_VFV_M_REF_DEF(vfrdiv,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]/vs2[i]))
VOPF_VFV_M_REF_DEF(vfmax,       FORLOOPIF(i, VMASK(i), vd[i] = std::max(vs2[i],rs1[0])))
VOPF_VFV_M_REF_DEF(vfmin,       FORLOOPIF(i, VMASK(i), vd[i] = std::min(vs2[i],rs1[0])))
VOPF_VFV_M_REF_DEF(vfsgnj,      FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]>0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_M_REF_DEF(vfsgnjn,     FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]<0 ? fabs(vs2[i]) : -fabs(vs2[i])))
VOPF_VFV_M_REF_DEF(vfsgnjx,     FORLOOPIF(i, VMASK(i), vd[i] = rs1[0]>0 ? vs2[i] : -vs2[i]))