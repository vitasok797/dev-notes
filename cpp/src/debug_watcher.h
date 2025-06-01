#ifndef VS_DEBUG_WATCHER_H_
#define VS_DEBUG_WATCHER_H_

#include <atomic>
#include <iostream>
#include <optional>
#include <syncstream>

namespace vs::debug
{

struct WatcherOptions
{
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
            auto os = ostream();
            os << " constructed" << std::endl;
        }
    }

    Watcher(const Watcher& other) noexcept : index_{++counter_}
    {
        if (options.print_ctor_copy)
        {
            auto os = ostream();
            os << " copy constructed";
            os << " from (" << other.index_ << ")" << std::endl;
        }
    }

    Watcher(Watcher&& other) noexcept : index_{++counter_}
    {
        if (options.print_ctor_move)
        {
            auto os = ostream();
            os << " move constructed";
            os << " from (" << other.index_ << ")" << std::endl;
        }

        other.moved_ = true;
    }

    Watcher& operator=(const Watcher& other) noexcept
    {
        if (options.print_assign_copy)
        {
            auto os = ostream();
            os << " copy assigned";
            os << " from (" << other.index_ << ")" << std::endl;
        }

        moved_ = false;
        return *this;
    }

    Watcher& operator=(Watcher&& other) noexcept
    {
        if (options.print_assign_move)
        {
            auto os = ostream();
            os << " move assigned";
            os << " from (" << other.index_ << ")" << std::endl;
        }

        moved_ = false;
        other.moved_ = true;
        return *this;
    }

    ~Watcher() noexcept
    {
        if (options.print_destructor)
        {
            auto os = ostream();
            os << " destroyed";
            if (moved_) os << " [moved]";
            os << std::endl;
        }
    }

private:
    auto ostream() -> std::osyncstream
    {
        auto os = std::osyncstream{std::cout};
        os << "Watcher (" << index_ << ")";
        return os;
    }

    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};

}  // namespace vs::debug

#endif  // VS_DEBUG_WATCHER_H_
