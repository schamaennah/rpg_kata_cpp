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

constexpr health& operator+=(health& health_to_increase, const healing& healing)
{
    if (status(health_to_increase) == status::dead)
    {
        return health_to_increase;
    }

    health_to_increase.value += healing.value;
    return health_to_increase;
}

} // namespace rpg_kata
