#ifndef VS_ASYNC_H_
#define VS_ASYNC_H_

#include <future>
#include <utility>

namespace vs
{

template<typename F, typename... Params>
inline auto run_async(F&& f, Params&&... params)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Params>(params)...);
}

}  // namespace vs

#endif  // VS_ASYNC_H_
