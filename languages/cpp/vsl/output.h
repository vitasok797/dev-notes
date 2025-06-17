#ifndef VSL_OUTPUT_H
#define VSL_OUTPUT_H

#include <iostream>
#include <syncstream>

namespace vsl
{

namespace detail
{

    // TODO: use vsl::ostream concept from vsl/concepts.h
    template<typename T>
    concept ostream = requires(T os) { os << ""; };

}  // namespace detail

template<typename OutputStream, typename... Values>
requires detail::ostream<OutputStream>
auto println(OutputStream& os, const Values&... values) -> void
{
    auto n = 0;
    ((os << (n++ == 0 ? "" : " ") << values), ...);
    os << std::endl;
}

template<typename... Values>
auto println(const Values&... values) -> void
{
    println(std::cout, values...);
}

template<typename OutputStream, typename... Values>
requires detail::ostream<OutputStream>
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

}  // namespace vsl

#endif  // VSL_OUTPUT_H
