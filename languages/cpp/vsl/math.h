#ifndef VSL_MATH_H_
#define VSL_MATH_H_

#include <cmath>
#include <limits>

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

}  // namespace vsl

#endif  // VSL_MATH_H_
