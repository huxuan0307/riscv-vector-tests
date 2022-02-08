#ifndef __SDEF_COMMON_H__
#define __SDEF_COMMON_H__

#include <cstdint>
#include <cstddef>
#include <algorithm>
#include <type_traits>

#define ASSIGN_BIT(vr, i, val) ((vr[i/8] &= ~(1 << i%8)) |= ((val) << i%8))

#define VMASK(i)    ((vmask[i/8] >> (i%8)) & 0x1)

#define FORLOOP(i, code) \
for (size_t i = 0; i < n; i++) { \
  {code;} \
} \

#define FORLOOPIF(i, condition, code) \
for (size_t i = 0; i < n; i++) { \
  if (condition) {code;} \
} \

template<typename Type>
bool inline carry_out(Type a, Type b, bool carry_in = false) {
  using TypeU = std::make_unsigned_t<Type>;
  TypeU s = *reinterpret_cast<TypeU*>(&a)
          + *reinterpret_cast<TypeU*>(&b) + carry_in;
  return carry_in
    ? (s <= *reinterpret_cast<TypeU*>(&a))
    : (s <  *reinterpret_cast<TypeU*>(&a));
}

template<typename Type>
bool inline borrow_out(Type a, Type b, bool borrow_in = false) {
  using TypeU = std::make_unsigned_t<Type>;
  return borrow_in 
    ? (*reinterpret_cast<TypeU*>(&a) <= *reinterpret_cast<TypeU*>(&b))
    : (*reinterpret_cast<TypeU*>(&a) <  *reinterpret_cast<TypeU*>(&b));
}

#endif
