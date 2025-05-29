#ifndef VS_OUTPUT_H_
#define VS_OUTPUT_H_

#include <iostream>
#include <syncstream>

namespace vs
{

namespace details
{

template<typename T>
concept ostream = requires(T os) { os << ""; };

}

template<typename OutputStream, typename... Values>
requires details::ostream<OutputStream>
auto println(OutputStream& os, const Values&... values) -> void
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

template<typename OutputStream, typename... Values>
requires details::ostream<OutputStream>
auto println_sync(OutputStream& os, const Values&... values) -> void
{
    auto synced_os = std::osyncstream{os};
    println(synced_os, values...);
}

template<typename... Values>
auto println_sync(const Values&... values) -> void
{
    println_sync(std::cout, values...);
}

}  // namespace vs

#endif  // VS_OUTPUT_H_
