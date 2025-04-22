#ifndef VS_DEBUG_OBJECT_WATCHER_H_
#define VS_DEBUG_OBJECT_WATCHER_H_

#include <atomic>
#include <iostream>

namespace vs::debug
{

class ObjWatcher final
{
public:
    ObjWatcher() noexcept : index_(++counter_)
    {
        std::cout << "ObjWatcher: created (" << index_ << ")" << std::endl;
    };

    ObjWatcher(const ObjWatcher& other) noexcept : index_(++counter_)
    {
        std::cout << "ObjWatcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
    };

    ObjWatcher(ObjWatcher&& other) noexcept : index_(++counter_)
    {
        other.moved_ = true;
        std::cout << "ObjWatcher: created (" << index_ << ") move from (" << other.index_ << ")" << std::endl;
    };

    ObjWatcher& operator=(const ObjWatcher& other) noexcept
    {
        moved_ = false;
        std::cout << "ObjWatcher: (" << index_ << ") copy assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    };

    ObjWatcher& operator=(ObjWatcher&& other) noexcept
    {
        moved_ = false;
        other.moved_ = true;
        std::cout << "ObjWatcher: (" << index_ << ") move assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    };

    ~ObjWatcher() noexcept
    {
        std::cout << "ObjWatcher: destroyed (" << index_ << ")";
        if (moved_) std::cout << " [moved]";
        std::cout << std::endl;
    };

private:
    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};

class CtorWatcher final
{
public:
    template<typename... Args>
    CtorWatcher(const Args&...) noexcept { std::cout << "ctor" << sizeof...(Args) << std::endl; };

    CtorWatcher(const CtorWatcher&) noexcept { std::cout << " COPY" << std::endl; };
    CtorWatcher(CtorWatcher&&) noexcept { std::cout << " move" << std::endl; };

    CtorWatcher& operator=(const CtorWatcher&) = delete;
    CtorWatcher& operator=(CtorWatcher&&) = delete;
};

}  // namespace vs::debug

#endif  // VS_DEBUG_OBJECT_WATCHER_H_
