#pragma once

#include "new_type.hpp"
#include "percentage.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using damage = value_wrapper<new_type, double, 1.>;

constexpr damage apply(const percentage& percentage, const damage& damage)
{
    return {(damage.value * percentage.value) / 100.};
}

constexpr damage operator-(const damage& self, const percentage& percentage)
{
    return damage{self.value - apply(percentage, self).value};
}

constexpr damage operator+(const damage& self, const percentage& percentage)
{
    return damage{self.value + apply(percentage, self).value};
}

} // namespace rpg_kata
