#ifndef VS_CONCEPTS_H_
#define VS_CONCEPTS_H_

#include <concepts>
#include <type_traits>

namespace vs
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

template<typename T>
concept ostream = requires(T os) { os << ""; };

}  // namespace vs

#endif  // VS_CONCEPTS_H_
