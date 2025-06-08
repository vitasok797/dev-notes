#ifndef VSL_SCOPE_GUARD_H_
#define VSL_SCOPE_GUARD_H_

#include <type_traits>
#include <utility>

#define VSL_SCOPE_GUARD vsl::ScopeGuard VSL_SCOPE_GUARD_UNIQ_NAME(__LINE__) = [&]()
#define VSL_SCOPE_GUARD_UNIQ_NAME(line) VSL_SCOPE_GUARD_UNIQ_NAME2(line)
#define VSL_SCOPE_GUARD_UNIQ_NAME2(line) vsl_scope_guard_##line

namespace vsl
{

template<typename F>
class ScopeGuard final
{
public:
    [[nodiscard]] ScopeGuard(const F& f) noexcept : f_{f} {}
    [[nodiscard]] ScopeGuard(F&& f) noexcept : f_{std::move(f)} {}

    ScopeGuard(ScopeGuard&& other) noexcept
        : f_{std::move(other.f_)}, invoke_{std::exchange(other.invoke_, false)}
    {}

    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;
    ScopeGuard& operator=(ScopeGuard&&) = delete;

    ~ScopeGuard() noexcept { if (invoke_) f_(); }

    auto dismiss() noexcept -> void { invoke_ = false; }

private:
    F f_;
    bool invoke_ = true;
};

template<typename F>
[[nodiscard]] auto make_scope_guard(F&& f) noexcept
{
    return ScopeGuard<std::decay_t<F>>{std::forward<F>(f)};
}

}  // namespace vsl

#endif  // VSL_SCOPE_GUARD_H_
