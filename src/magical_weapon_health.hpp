#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using magical_weapon_health = value_wrapper<new_type>;

constexpr magical_weapon_health& operator--(magical_weapon_health& health)
{
    if (health.value == 0)
    {
        return health;
    }
    --health.value;
    return health;
}

} // namespace rpg_kata
