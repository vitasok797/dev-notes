#ifndef VS_DEBUG_TYPE_INFO_H_
#define VS_DEBUG_TYPE_INFO_H_

#include <string_view>
#include <type_traits>

#define VS_REF_INFO(x) VS_IS_VALUE(x) << VS_IS_REF(x) << VS_IS_RVALUE_REF(x)
#define VS_IS_VALUE(x) (std::is_reference_v<decltype(x)> ? "" : "VAL")
#define VS_IS_REF(x) (std::is_lvalue_reference_v<decltype(x)> ? "REF" : "")
#define VS_IS_RVALUE_REF(x) (std::is_rvalue_reference_v<decltype(x)> ? "RVAL_REF" : "")

#define VS_TYPE_INFO(x) vs::debug::get_type_info<decltype(x)>()

#ifdef _MSC_VER
#define VS_FUNC_INFO(x) __FUNCSIG__
#else
#define VS_FUNC_INFO(x) __PRETTY_FUNCTION__
#endif

namespace vs::debug
{

template <typename T>
constexpr auto get_type_info()
{
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto vs::debug::get_type_info() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto vs::debug::get_type_info() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl vs::debug::get_type_info<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

}  // namespace vs::debug

#endif  // VS_DEBUG_TYPE_INFO_H_
