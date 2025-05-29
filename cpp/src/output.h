#ifndef VS_OUTPUT_H_
#define VS_OUTPUT_H_

#include <iostream>

namespace vs
{

template<typename... Values>
auto println(std::ostream& os, const Values&... values) -> void
{
    if constexpr (sizeof...(values) > 0)
    {
        auto n = 0;
        ((os << (n++ == 0 ? "" : " ") << values), ...);
    }
    os << std::endl;
}

template<typename... Values>
auto println(const Values&... values) -> void
{
    println(std::cout, values...);
}

}  // namespace vs

#endif  // VS_OUTPUT_H_
