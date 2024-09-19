#pragma once

#include "coordinate.hpp"
#include "range.hpp"

#include <cmath>

namespace rpg_kata
{
struct position
{
    coordinate x;
    coordinate y;
};

inline range distance(const position& lhs, const position& rhs)
{
    const auto delta_x = rhs.x.value - lhs.x.value;
    const auto delta_y = rhs.y.value - lhs.y.value;
    return {std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2))};
}

} // namespace rpg_kata
