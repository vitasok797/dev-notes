#ifndef VS_THREAD_H_
#define VS_THREAD_H_

#include <future>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <utility>

namespace vs
{

template<typename F, typename... Param>
inline auto run_async(F&& f, Param&&... param)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Param>(param)...);
}

inline auto get_cur_thread_num() -> int
{
    static auto mutex = std::mutex{};
    auto scope_lock = std::scoped_lock(mutex);

    static auto next_num = 1;
    static auto thread_nums = std::unordered_map<std::thread::id, int>{};

    auto cur_id = std::this_thread::get_id();
    auto [item, inserted] = thread_nums.insert({cur_id, next_num});

    if (inserted) ++next_num;

    return item->second;
}

}  // namespace vs

#endif  // VS_THREAD_H_
