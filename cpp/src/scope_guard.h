#include <utility>

#define SCOPE_GUARD ScopeGuard SCOPE_GUARD_UNIQ_NAME(__LINE__) = [&]()
#define SCOPE_GUARD_UNIQ_NAME(line) SCOPE_GUARD_UNIQ_NAME2(line)
#define SCOPE_GUARD_UNIQ_NAME2(line) scope_guard_##line

template<typename F>
class ScopeGuard
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
