#ifndef VS_UTIL_H_
#define VS_UTIL_H_

#include <cstddef>
#include <functional>
#include <optional>
#include <type_traits>
#include <utility>

#define FWD(...) std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

namespace vs
{

using Index = std::ptrdiff_t;
using SignedSize = std::ptrdiff_t;

template<typename T> constexpr auto as_signed(T t) noexcept { return std::make_signed_t<T>(t); }
template<typename T> constexpr auto as_unsigned(T t) noexcept { return std::make_unsigned_t<T>(t); }

template<typename T>
constexpr auto signed_size(const T& t) noexcept -> SignedSize
{
    return static_cast<SignedSize>(as_signed(t.size()));
}

template<typename T>
using optional_ref = std::optional<std::reference_wrapper<T>>;

template<typename T, typename U>
constexpr auto forward_like(U&& x) noexcept -> auto&&
{
    constexpr bool is_adding_const = std::is_const_v<std::remove_reference_t<T>>;
    if constexpr (std::is_lvalue_reference_v<T&&>)
    {
        if constexpr (is_adding_const)
            return std::as_const(x);
        else
            return static_cast<U&>(x);
    }
    else
    {
        if constexpr (is_adding_const)
            return std::move(std::as_const(x));
        else
            return std::move(x);
    }
}

}  // namespace vs

#endif  // VS_UTIL_H_
