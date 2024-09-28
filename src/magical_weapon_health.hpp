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

constexpr bool is_destroyed(const magical_weapon_health& health)
{
    return health == magical_weapon_health{0};
}

} // namespace rpg_kata
