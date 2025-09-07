#ifndef VSL_MATH_H
#define VSL_MATH_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <concepts>
#include <limits>
#include <numbers>
#include <stdexcept>
#include <type_traits>
#include <utility>

#define INF HUGE_VAL

namespace vsl
{

inline constexpr auto double_max = std::numeric_limits<double>::max();
inline constexpr auto double_max_neg = -std::numeric_limits<double>::max();

inline auto almost_equal(double a, double b, double abs_epsilon) -> bool
{
    return std::abs(a - b) <= abs_epsilon;
}

inline auto almost_equal_rel(double a, double b, double rel_epsilon = 1e-6) -> bool
{
    return std::abs(a - b) <= (std::fmax(std::abs(a), std::abs(b)) * rel_epsilon);
}

inline auto ftrim(double value, std::pair<double, double> bounds) -> double
{
    auto [lo, hi] = bounds;
    if (lo > hi)
    {
        throw std::logic_error{"ftrim bounds error (low > high)"};
    }
    return std::clamp(value, lo, hi);
}

template<typename A, typename B>
    requires std::signed_integral<A> && std::signed_integral<B>
auto ceil_div(A a, B b) noexcept -> std::common_type_t<A, B>
{
    // TODO: use EXPECTS from vsl/assert.h
    assert(a >= 0);
    assert(b > 0);

    return a / b + (a % b ? 1 : 0);
}

}  // namespace vsl

#endif  // VSL_MATH_H
