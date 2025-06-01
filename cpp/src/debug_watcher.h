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
            std::cout << "Watcher: created (" << index_ << ")" << std::endl;
        }
    }

    Watcher(const Watcher& other) noexcept : index_{++counter_}
    {
        if (options.print_ctor_copy)
        {
            std::cout << "Watcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
        }
    }

    Watcher(Watcher&& other) noexcept : index_{++counter_}
    {
        other.moved_ = true;

        if (options.print_ctor_move)
        {
            std::cout << "Watcher: created (" << index_ << ") move from (" << other.index_ << ")" << std::endl;
        }
    }

    Watcher& operator=(const Watcher& other) noexcept
    {
        if (options.print_assign_copy)
        {
            std::cout << "Watcher: (" << index_ << ") copy assigned from (" << other.index_ << ")" << std::endl;
        }

        moved_ = false;
        return *this;
    }

    Watcher& operator=(Watcher&& other) noexcept
    {
        if (options.print_assign_move)
        {
            std::cout << "Watcher: (" << index_ << ") move assigned from (" << other.index_ << ")" << std::endl;
        }

        moved_ = false;
        other.moved_ = true;
        return *this;
    }

    ~Watcher() noexcept
    {
        if (options.print_destructor)
        {
            std::cout << "Watcher: destroyed (" << index_ << ")";
            if (moved_) std::cout << " [moved]";
            std::cout << std::endl;
        }
    }

private:
    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};

}  // namespace vs::debug

#endif  // VS_DEBUG_WATCHER_H_
