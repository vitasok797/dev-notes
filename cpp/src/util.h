#ifndef VS_UTIL_UTIL_H_
#define VS_UTIL_UTIL_H_

#include <type_traits>

namespace vs::util
{

template<class T> auto as_signed  (T t){ return std::make_signed_t<T>(t); }
template<class T> auto as_unsigned(T t){ return std::make_unsigned_t<T>(t); }

}  // namespace vs::util

#endif  // VS_UTIL_UTIL_H_
