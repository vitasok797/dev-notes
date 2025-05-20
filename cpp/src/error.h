#ifndef VS_ERROR_H_
#define VS_ERROR_H_

#include <exception>

namespace vs
{

struct nullptr_error : public std::exception
{
    auto what() const noexcept -> const char* override { return "nullptr_error"; }
};

template<typename T>
auto ptr_check(const T& ptr) -> void
{
    if (!ptr) throw nullptr_error();
}

template<typename T>
auto ptr_checked_deref(const T& ptr) -> auto&
{
    ptr_check(ptr);
    return *ptr;
}

template<typename T>
auto ptr_checked_get(const T& ptr) -> auto
{
    ptr_check(ptr);
    return ptr.get();
}

}  // namespace vs

#endif  // VS_ERROR_H_
