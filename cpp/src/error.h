#ifndef VS_ERROR_H_
#define VS_ERROR_H_

#include <exception>

namespace vs
{

struct nullptr_error : public std::exception
{
    auto what() const noexcept -> const char* override { return "nullptr_error"; }
};

}  // namespace vs

#endif  // VS_ERROR_H_
