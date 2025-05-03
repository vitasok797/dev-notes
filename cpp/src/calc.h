#ifndef VS_CALC_H_
#define VS_CALC_H_

#include <cmath>

namespace vs
{

inline bool almost_equal(double a, double b, double abs_epsilon)
{
    return std::abs(a - b) <= abs_epsilon;
}

inline bool almost_equal_rel(double a, double b, double rel_epsilon = 1e-6)
{
	return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon);
}

}  // namespace vs

#endif  // VS_CALC_H_
