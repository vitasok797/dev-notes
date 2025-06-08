#ifndef VSL_NON_COPYABLE_H_
#define VSL_NON_COPYABLE_H_

namespace vsl
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

}  // namespace vsl

#endif  // VSL_NON_COPYABLE_H_
