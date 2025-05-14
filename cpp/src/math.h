#ifndef VS_MATH_H_
#define VS_MATH_H_

#include <cmath>

namespace vs
{

inline auto almost_equal(double a, double b, double abs_epsilon) -> bool
{
    return std::abs(a - b) <= abs_epsilon;
}

inline auto almost_equal_rel(double a, double b, double rel_epsilon = 1e-6) -> bool
{
    return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon);
}

}  // namespace vs

#endif  // VS_MATH_H_
