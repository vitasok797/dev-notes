#ifndef VS_DEBUG_H_
#define VS_DEBUG_H_

#include <atomic>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <syncstream>
#include <type_traits>

#define VS_REF_INFO(x) VS_IS_VALUE(x) << VS_IS_REF(x) << VS_IS_RVALUE_REF(x)
#define VS_IS_VALUE(x) (std::is_reference_v<decltype(x)> ? "" : "VAL")
#define VS_IS_REF(x) (std::is_lvalue_reference_v<decltype(x)> ? "REF" : "")
#define VS_IS_RVALUE_REF(x) (std::is_rvalue_reference_v<decltype(x)> ? "RVAL_REF" : "")

#define VS_TYPE_INFO(x) vs::debug::get_type_info<decltype(x)>()

#ifdef _MSC_VER
#define VS_FUNC_INFO __FUNCSIG__
#else
#define VS_FUNC_INFO __PRETTY_FUNCTION__
#endif

namespace vs::debug
{

template<typename T>
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

inline auto get_thread_unique_num() -> int
{
    static auto next_thread_num = std::atomic<int>{0};
    static thread_local auto thread_num = next_thread_num.fetch_add(1);
    return thread_num;
}

template<typename... Values>
void println_sync(const Values&... values)
{
    auto os = std::osyncstream{std::cout};
    os << "[" << get_thread_unique_num() << "]";
    ((os << " " << values), ...);
    os << std::endl;
}

struct WatcherOptions
{
    bool print_mark = true;
    bool print_thread = true;
    bool print_identity = true;
    bool print_other = true;
    bool print_ctor = true;
    bool print_ctor_copy = true;
    bool print_ctor_move = true;
    bool print_assign_copy = true;
    bool print_assign_move = true;
    bool print_destructor = true;
};

template<WatcherOptions options = {}>
class WatcherBase final
{
public:
    WatcherBase() noexcept : index_{++counter_}
    {
        if (options.print_ctor)
        {
            print_event("constructed");
        }
    }

    WatcherBase(int) noexcept : index_{++counter_}
    {
        if (options.print_ctor)
        {
            print_event("constructed ctor1");
        }
    }

    WatcherBase(int, int) noexcept : index_{++counter_}
    {
        if (options.print_ctor)
        {
            print_event("constructed ctor2");
        }
    }

    WatcherBase(const std::string& marker) noexcept : marker_{marker}
    {
        if (options.print_ctor)
        {
            print_event("constructed");
        }
    }

    WatcherBase(const WatcherBase& other) noexcept :
        index_{++counter_},
        marker_{other.marker_}
    {
        if (options.print_ctor_copy)
        {
            print_event("COPY constructed", &other);
        }
    }

    WatcherBase(WatcherBase&& other) noexcept :
        index_{++counter_},
        marker_{other.marker_}
    {
        if (options.print_ctor_move)
        {
            print_event("move constructed", &other);
        }

        other.moved_ = true;
    }

    WatcherBase& operator=(const WatcherBase& other) noexcept
    {
        if (options.print_assign_copy)
        {
            print_event("COPY assigned", &other);
        }

        moved_ = false;
        return *this;
    }

    WatcherBase& operator=(WatcherBase&& other) noexcept
    {
        if (options.print_assign_move)
        {
            print_event("move assigned", &other);
        }

        moved_ = false;
        other.moved_ = true;
        return *this;
    }

    ~WatcherBase() noexcept
    {
        if (options.print_destructor)
        {
            print_event("destroyed");
        }
    }

private:
    auto print_event(std::string_view event_desc, const WatcherBase* other = nullptr) const -> void
    {
        auto os = std::osyncstream{std::cout};

        if (options.print_mark)
        {
            os << ">>> ";
        }

        if (options.print_thread)
        {
            os << "[" << get_thread_unique_num() << "] ";
        }

        if (options.print_identity)
        {
            output_identity(os);
            os << " ";
        }

        os << event_desc;

        if (other && options.print_other)
        {
            os << " from ";
            other->output_identity(os);
        }

        os << std::endl;
    }

    auto output_identity(std::osyncstream& os) const -> void
    {
        os << "(";
        if (marker_)
        {
            os << "\"" << *marker_ << "\"";
        }
        else
        {
            os << index_;
        }
        if (moved_) os << ", moved";
        os << ")";
    }

    static inline std::atomic<size_t> counter_ = 0;
    size_t index_ = 0;
    std::optional<std::string> marker_{};
    bool moved_ = false;
};

namespace details
{

inline constexpr auto watcher_config = vs::debug::WatcherOptions
{
    .print_thread = false,
};

inline constexpr auto copy_watcher_config = vs::debug::WatcherOptions
{
    .print_thread = false,
    .print_identity = false,
    .print_ctor = false,
    .print_ctor_move = false,
    .print_assign_move = false,
    .print_destructor = false,
};

inline constexpr auto ctor_watcher_config = vs::debug::WatcherOptions
{
    .print_thread = false,
    .print_identity = false,
    .print_other = false,
    .print_assign_copy = false,
    .print_assign_move = false,
    .print_destructor = false,
};

}  // namespace details

using Watcher = WatcherBase<details::watcher_config>;
using CopyWatcher = WatcherBase<details::copy_watcher_config>;
using CtorWatcher = WatcherBase<details::ctor_watcher_config>;
using ThreadWatcher = WatcherBase<>;

}  // namespace vs::debug

#endif  // VS_DEBUG_H_
