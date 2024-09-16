#pragma once

#include "damage.hpp"
#include "healing.hpp"
#include "new_type.hpp"
#include "status.hpp"
#include "value_wrapper.hpp"

#include <algorithm>

namespace rpg_kata
{
using health = value_wrapper<new_type, 1000U>;

constexpr health& operator-=(health& health, const damage& damage)
{
    health.value -= std::min(health.value, damage.value);
    return health;
}

constexpr status status(const health& self)
{
    if (self == health{0})
    {
        return status::dead;
    }

    return status::alive;
}

constexpr health& operator+=(health& health, const healing& healing)
{
    health.value += healing.value;
    return health;
}

} // namespace rpg_kata
