#ifndef VS_UTIL_UTIL_H_
#define VS_UTIL_UTIL_H_

#include <cstddef>
#include <functional>
#include <optional>
#include <type_traits>

namespace vs
{

using Index = std::ptrdiff_t;
using SignedSize = std::ptrdiff_t;

template<typename T> auto as_signed(T t){ return std::make_signed_t<T>(t); }
template<typename T> auto as_unsigned(T t){ return std::make_unsigned_t<T>(t); }

namespace util
{

template<typename T>
using optional_ref = std::optional<std::reference_wrapper<T>>;

}  // namespace util
}  // namespace vs

#endif  // VS_UTIL_UTIL_H_
