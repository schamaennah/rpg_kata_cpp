#pragma once

#include "damage.hpp"
#include "damageable_health.hpp"
#include "healing.hpp"
#include "new_type.hpp"
#include "character_status.hpp"
#include "value_wrapper.hpp"

#include <algorithm>

namespace rpg_kata
{

using character_health_base = value_wrapper<new_type, double, 1000.>;

class character_health : character_health_base
{
public:
    constexpr character_health() = default;

    explicit constexpr character_health(const type value)
        : character_health_base{std::min(value, initial_value)}
    {}

    bool                                     operator==(const character_health&) const = default;
    friend constexpr damageable_health auto& operator-=(damageable_health auto&, const damage&);
    friend constexpr character_health&       operator+=(character_health&, const healing&);
};

constexpr character_status status(const character_health& self)
{
    if (self == character_health{0})
    {
        return character_status::dead;
    }

    return character_status::alive;
}

constexpr character_health& operator+=(character_health& health_to_increase, const healing& healing)
{
    if (status(health_to_increase) == character_status::dead)
    {
        return health_to_increase;
    }

    health_to_increase.value
        = std::min(health_to_increase.value + healing.value, character_health::initial_value);

    return health_to_increase;
}

} // namespace rpg_kata
