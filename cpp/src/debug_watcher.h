#ifndef VS_DEBUG_WATCHER_H_
#define VS_DEBUG_WATCHER_H_

#include <atomic>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <syncstream>

namespace vs::debug
{

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

}

using Watcher = WatcherBase<details::watcher_config>;
using CopyWatcher = WatcherBase<details::copy_watcher_config>;
using CtorWatcher = WatcherBase<details::ctor_watcher_config>;
using ThreadWatcher = WatcherBase<>;

}  // namespace vs::debug

#endif  // VS_DEBUG_WATCHER_H_
