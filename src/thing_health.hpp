#pragma once

#include "damage.hpp"
#include "new_type.hpp"
#include "non_negative_double.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using thing_health = value_wrapper<new_type, non_negative_double, 1.>;

constexpr thing_health& operator-=(thing_health& self, const damage& damage)
{
    self.value -= damage.value;
    return self;
}

} // namespace rpg_kata
