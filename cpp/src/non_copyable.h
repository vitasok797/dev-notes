#ifndef VS_NON_COPYABLE_H_
#define VS_NON_COPYABLE_H_

namespace vs
{

class NonCopyable
{
public:
    NonCopyable() = default;

    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    NonCopyable(NonCopyable&&) noexcept = default;
    NonCopyable& operator=(NonCopyable&&) noexcept = default;

    ~NonCopyable() = default;
};

}  // namespace vs

#endif  // VS_NON_COPYABLE_H_
