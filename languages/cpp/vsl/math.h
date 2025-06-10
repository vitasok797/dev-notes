#ifndef VSL_MATH_H
#define VSL_MATH_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
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

}  // namespace vsl

#endif  // VSL_MATH_H
