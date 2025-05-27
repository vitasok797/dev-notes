#ifndef VS_OBJECT_WATCHER_H_
#define VS_OBJECT_WATCHER_H_

#include <atomic>
#include <iostream>
#include <optional>

namespace vs::debug
{

class ObjWatcher final
{
public:
    ObjWatcher() noexcept : index_{++counter_}
    {
        std::cout << "ObjWatcher: created (" << index_ << ")" << std::endl;
    }

    ObjWatcher(const ObjWatcher& other) noexcept : index_{++counter_}
    {
        std::cout << "ObjWatcher: created (" << index_ << ") copy from (" << other.index_ << ")" << std::endl;
    }

    ObjWatcher(ObjWatcher&& other) noexcept : index_{++counter_}
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

template<typename T = int>
class CopyWatcher final
{
public:
    CopyWatcher() = default;
    CopyWatcher(T marker) noexcept : marker_{std::move(marker)} {}

    CopyWatcher(const CopyWatcher& other) noexcept : marker_{other.marker_}
    {
        print_message("COPIED");
    }

    CopyWatcher& operator=(const CopyWatcher& other) noexcept
    {
        marker_ = other.marker_;
        print_message("COPIED(=)");
        return *this;
    }

    CopyWatcher(CopyWatcher&&) noexcept = default;
    CopyWatcher& operator=(CopyWatcher&&) noexcept = default;

    ~CopyWatcher() = default;

private:
    auto print_message(const char* operation_desc) noexcept -> void
    {
        std::cout << ">>> " << operation_desc;
        if (marker_) std::cout << " [" << *marker_ << "]";
        std::cout << std::endl;
    }

    std::optional<T> marker_{};
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

    ~CtorWatcher() = default;
};

}  // namespace vs::debug

#endif  // VS_OBJECT_WATCHER_H_
