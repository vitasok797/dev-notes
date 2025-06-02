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
    bool print_ctor0 = true;
    bool print_ctor_copy = true;
    bool print_ctor_move = true;
    bool print_assign_copy = true;
    bool print_assign_move = true;
    bool print_destructor = true;
};

template<WatcherOptions options = {}>
class Watcher final
{
public:
    Watcher() noexcept : index_{++counter_}
    {
        if (options.print_ctor0)
        {
            print_event("constructed");
        }
    }

    Watcher(const std::string& marker) noexcept : marker_{marker}
    {
        if (options.print_ctor0)
        {
            print_event("constructed");
        }
    }

    Watcher(const Watcher& other) noexcept :
        index_{++counter_},
        marker_{other.marker_}
    {
        if (options.print_ctor_copy)
        {
            print_event("COPY constructed", &other);
        }
    }

    Watcher(Watcher&& other) noexcept :
        index_{++counter_},
        marker_{other.marker_}
    {
        if (options.print_ctor_move)
        {
            print_event("move constructed", &other);
        }

        other.moved_ = true;
    }

    Watcher& operator=(const Watcher& other) noexcept
    {
        if (options.print_assign_copy)
        {
            print_event("COPY assigned", &other);
        }

        moved_ = false;
        return *this;
    }

    Watcher& operator=(Watcher&& other) noexcept
    {
        if (options.print_assign_move)
        {
            print_event("move assigned", &other);
        }

        moved_ = false;
        other.moved_ = true;
        return *this;
    }

    ~Watcher() noexcept
    {
        if (options.print_destructor)
        {
            print_event("destroyed");
        }
    }

private:
    auto print_event(std::string_view event_desc, const Watcher* other = nullptr) const -> void
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

}  // namespace vs::debug

#endif  // VS_DEBUG_WATCHER_H_
