#ifndef VS_DEBUG_WATCHER_H_
#define VS_DEBUG_WATCHER_H_

#include <atomic>
#include <iostream>
#include <optional>
#include <syncstream>

namespace vs::debug
{

class Watcher final
{
public:
    Watcher() noexcept : index_{++counter_}
    {
        std::cout << "Watcher: created (" << index_ << ")" << std::endl;
    }

    Watcher(const Watcher& other) noexcept : index_{++counter_}
    {
        std::cout << "Watcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
    }

    Watcher(Watcher&& other) noexcept : index_{++counter_}
    {
        other.moved_ = true;
        std::cout << "Watcher: created (" << index_ << ") move from (" << other.index_ << ")" << std::endl;
    }

    Watcher& operator=(const Watcher& other) noexcept
    {
        moved_ = false;
        std::cout << "Watcher: (" << index_ << ") copy assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    }

    Watcher& operator=(Watcher&& other) noexcept
    {
        moved_ = false;
        other.moved_ = true;
        std::cout << "Watcher: (" << index_ << ") move assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    }

    ~Watcher() noexcept
    {
        std::cout << "Watcher: destroyed (" << index_ << ")";
        if (moved_) std::cout << " [moved]";
        std::cout << std::endl;
    }

private:
    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};

}  // namespace vs::debug

#endif  // VS_DEBUG_WATCHER_H_
