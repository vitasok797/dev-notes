#ifndef VS_THREAD_H_
#define VS_THREAD_H_

#include <future>
#include <utility>

namespace vs
{

template<typename F, typename... Param>
inline auto run_async(F&& f, Param&&... param)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Param>(param)...);
}

}  // namespace vs

#endif  // VS_THREAD_H_
