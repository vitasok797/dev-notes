#ifndef VSL_ERROR_H
#define VSL_ERROR_H

#include <exception>

namespace vsl
{

struct nullptr_error : public std::exception
{
    auto what() const noexcept -> const char* override
    {
        return "nullptr_error";
    }
};

template<typename T>
auto check_ptr(const T& ptr) -> void
{
    if (!ptr) throw nullptr_error{};
}

template<typename T>
auto checked_deref_ptr(const T& ptr) -> decltype(auto)
{
    if (!ptr) throw nullptr_error{};
    return *ptr;
}

template<typename T>
auto checked_get_ptr(const T& ptr) -> decltype(auto)
{
    if (!ptr) throw nullptr_error{};
    return ptr.get();
}

}  // namespace vsl

#endif  // VSL_ERROR_H
