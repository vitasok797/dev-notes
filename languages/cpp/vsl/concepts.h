#ifndef VSL_CONCEPTS_H
#define VSL_CONCEPTS_H

#include <concepts>
#include <type_traits>

namespace vsl
{

template<typename Fn, typename... Args>
concept callable = std::is_invocable_v<Fn, Args...>;

template<typename Ret, typename Fn, typename... Args>
concept callable_r = std::is_invocable_r_v<Ret, Fn, Args...>;

template<typename T>
concept numeric = std::integral<std::decay_t<T>> || std::floating_point<std::decay_t<T>>;

template<typename T, typename... Types>
concept one_of_types = (std::same_as<std::decay_t<T>, Types> || ...);

template<typename T, typename U>
concept same_type_as = std::same_as<std::decay_t<T>, U>;

}  // namespace vsl

#endif  // VSL_CONCEPTS_H
