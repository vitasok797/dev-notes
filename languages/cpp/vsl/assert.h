#ifndef VSL_ASSERT_H
#define VSL_ASSERT_H

#include <exception>
#include <iostream>
#include <source_location>

#define VSL_ASSERT(type, expr, ...) (static_cast<bool>(expr) ? static_cast<void>(0) : \
    vsl::assert_fail(type, #expr, std::source_location::current() __VA_OPT__(,) __VA_ARGS__))

#define VSL_EXPECTS(...) VSL_ASSERT("Expects", __VA_ARGS__)
#define VSL_ENSURES(...) VSL_ASSERT("Ensures", __VA_ARGS__)

#define EXPECTS VSL_EXPECTS
#define ENSURES VSL_ENSURES

namespace vsl
{

[[noreturn]]
inline auto assert_fail(        //
    const char* type,           //
    const char* expr,           //
    const auto& location,       //
    const char* desc = nullptr  //
    ) noexcept -> void          //
{
    std::cerr << "Assertion failed" << "\n";
    std::cerr << type << ": " << expr << "\n";

    if (desc)
    {
        std::cerr << "Description: " << desc << "\n";
    }

    std::cerr << "Location: ";
    std::cerr << location.file_name() << ":" << location.line();
    std::cerr << " \"" << location.function_name() << "\"\n";

    std::cerr << std::endl;

    std::terminate();
}

}  // namespace vsl

#endif  // VSL_ASSERT_H
