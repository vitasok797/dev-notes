#ifndef VS_OBJECT_WATCHER_H_
#define VS_OBJECT_WATCHER_H_

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
    }

    ObjWatcher(const ObjWatcher& other) noexcept : index_(++counter_)
    {
        std::cout << "ObjWatcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
    }

    ObjWatcher(ObjWatcher&& other) noexcept : index_(++counter_)
    {
        other.moved_ = true;
        std::cout << "ObjWatcher: created (" << index_ << ") move from (" << other.index_ << ")" << std::endl;
    }

    ObjWatcher& operator=(const ObjWatcher& other) noexcept
    {
        moved_ = false;
        std::cout << "ObjWatcher: (" << index_ << ") copy assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    }

    ObjWatcher& operator=(ObjWatcher&& other) noexcept
    {
        moved_ = false;
        other.moved_ = true;
        std::cout << "ObjWatcher: (" << index_ << ") move assigned from (" << other.index_ << ")" << std::endl;
        return *this;
    }

    ~ObjWatcher() noexcept
    {
        std::cout << "ObjWatcher: destroyed (" << index_ << ")";
        if (moved_) std::cout << " [moved]";
        std::cout << std::endl;
    }

private:
    static inline std::atomic<size_t> counter_ = 0;
    size_t index_;
    bool moved_ = false;
};

class CopyWatcher final
{
public:
    CopyWatcher() = default;
    CopyWatcher(int index) : index_(index) {}

    CopyWatcher(const CopyWatcher& other) noexcept : index_(other.index_)
    {
        print_message("COPIED");
    }

    CopyWatcher& operator=(const CopyWatcher& other) noexcept
    {
        index_ = other.index_;
        print_message("COPIED (ASSIGN)");
        return *this;
    }

    CopyWatcher(CopyWatcher&&) noexcept = default;
    CopyWatcher& operator=(CopyWatcher&&) noexcept = default;

    ~CopyWatcher() = default;

private:
    auto print_message(const char* operation_desc) noexcept -> void
    {
        std::cout << ">>> " << operation_desc;
        if (index_ > 0) std::cout << " [" << index_ << "]";
        std::cout << std::endl;
    }

    int index_ = 0;
};

class CtorWatcher final
{
public:
    CtorWatcher() noexcept { std::cout << "ctor0" << std::endl; }
    CtorWatcher(const int&) noexcept { std::cout << "ctor1" << std::endl; }
    CtorWatcher(const int&, const int&) noexcept { std::cout << "ctor2" << std::endl; }

    CtorWatcher(const CtorWatcher&) noexcept { std::cout << " COPY" << std::endl; }
    CtorWatcher(CtorWatcher&&) noexcept { std::cout << " move" << std::endl; }

    CtorWatcher& operator=(const CtorWatcher&) = delete;
    CtorWatcher& operator=(CtorWatcher&&) = delete;
};

}  // namespace vs::debug

#endif  // VS_OBJECT_WATCHER_H_
