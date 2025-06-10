#ifndef VSL_ASYNC_H
#define VSL_ASYNC_H

#include <future>
#include <utility>

namespace vsl
{

template<typename F, typename... Params>
auto run_async(F&& f, Params&&... params)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Params>(params)...);
}

}  // namespace vsl

#endif  // VSL_ASYNC_H
