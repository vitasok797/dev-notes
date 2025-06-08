#ifndef VSL_MATH_H_
#define VSL_MATH_H_

#include <algorithm>
#include <cmath>
#include <limits>
#include <optional>
#include <stdexcept>
#include <utility>

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

using TrimBounds = std::pair<std::optional<double>, std::optional<double>>;
inline constexpr auto no_trim = std::nullopt;

inline auto ftrim(double value, TrimBounds bounds) -> double
{
    auto lo = bounds.first.value_or(double_max_neg);
    auto hi = bounds.second.value_or(double_max);

    if (lo > hi)
    {
        throw std::logic_error{"ftrim bounds error (low > high)"};
    }

    return std::clamp(value, lo, hi);
}

}  // namespace vsl

#endif  // VSL_MATH_H_
