#pragma once

#include "damage.hpp"
#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using health = value_wrapper<new_type, 1000U>;

constexpr health& operator-=(health& health, const damage& damage)
{
    health.value -= damage.value;
    return health;
}

} // namespace rpg_kata
