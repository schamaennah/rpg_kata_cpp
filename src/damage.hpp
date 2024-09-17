#pragma once

#include "new_type.hpp"
#include "non_negative_double.hpp"
#include "percentage.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
class health;

using damage = value_wrapper<new_type, non_negative_double, 1.>;

constexpr damage operator-(const damage& self, const percentage& percentage)
{
    return {non_negative_double{self.value.get() - (self.value.get() * percentage.value) / 100.}};
}

} // namespace rpg_kata
