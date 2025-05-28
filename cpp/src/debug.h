#ifndef VS_DEBUG_H_
#define VS_DEBUG_H_

#include <atomic>
#include <iostream>
#include <mutex>
#include <optional>
#include <string_view>
#include <thread>
#include <type_traits>
#include <unordered_map>

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

inline auto get_thread_num() -> int
{
    static auto mutex = std::mutex{};
    static auto next_thread_num = 0;
    static auto threads = std::unordered_map<std::thread::id, int>{};

    auto thread_id = std::this_thread::get_id();
    auto scope_lock = std::scoped_lock(mutex);
    auto [item, inserted] = threads.insert({thread_id, next_thread_num});
    if (inserted) ++next_thread_num;
    return item->second;
}

inline auto get_thread_unique_num() -> int
{
    static auto next_thread_num = std::atomic<int>{0};
    static thread_local auto thread_num = next_thread_num.fetch_add(1);
    return thread_num;
}

}  // namespace vs::debug

#endif  // VS_DEBUG_H_
