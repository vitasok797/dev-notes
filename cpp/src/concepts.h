#ifndef VS_CONCEPTS_H_
#define VS_CONCEPTS_H_

#include <concepts>
#include <type_traits>

namespace vs
{

template<typename T, typename U>
concept same_type_as = std::same_as<std::decay_t<T>, U>;

}  // namespace vs

#endif  // VS_CONCEPTS_H_
