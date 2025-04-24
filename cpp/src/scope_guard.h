#ifndef VS_UTIL_SCOPE_GUARD_H_
#define VS_UTIL_SCOPE_GUARD_H_

#include <utility>

#define VS_SCOPE_GUARD vs::util::ScopeGuard VS_SCOPE_GUARD_UNIQ_NAME(__LINE__) = [&]()
#define VS_SCOPE_GUARD_UNIQ_NAME(line) VS_SCOPE_GUARD_UNIQ_NAME2(line)
#define VS_SCOPE_GUARD_UNIQ_NAME2(line) vs_scope_guard_##line

namespace vs::util
{

template<typename F>
class ScopeGuard final
{
public:
    [[nodiscard]] ScopeGuard(const F& f) noexcept : f_{f} {}
    [[nodiscard]] ScopeGuard(F&& f) noexcept : f_{std::forward<F>(f)} {}

    ~ScopeGuard() noexcept { if (invoke_) f_(); }

    ScopeGuard(ScopeGuard&& other) noexcept
        : f_(std::move(other.f_)), invoke_(std::exchange(other.invoke_, false))
    {}

    ScopeGuard(const ScopeGuard&) = delete;
    void operator=(const ScopeGuard&) = delete;
    void operator=(ScopeGuard&&) = delete;

    void dismiss() noexcept { invoke_ = false; }

private:
    F f_;
    bool invoke_ = true;
};

template<typename F>
[[nodiscard]] auto make_scope_guard(F&& f) noexcept
{
    return ScopeGuard<std::decay_t<F>>{std::forward<F>(f)};
}

}  // namespace vs::util

#endif  // VS_UTIL_SCOPE_GUARD_H_
