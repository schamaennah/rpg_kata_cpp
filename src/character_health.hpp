#pragma once

#include "character_status.hpp"
#include "damage.hpp"
#include "healing.hpp"
#include "new_type.hpp"
#include "non_negative_double.hpp"
#include "value_wrapper.hpp"

#include <algorithm>

namespace rpg_kata
{
class character_health
{
public:
    using type = value_wrapper<new_type, non_negative_double, 1000.>;

    constexpr character_health() = default;

    explicit constexpr character_health(const double value)
        : current{std::min(non_negative_double{value}, type::initial_value)}
    {}

    constexpr bool operator==(const character_health& other) const
    {
        return current == other.current;
    }

    friend constexpr character_health& operator-=(character_health&, const damage&);
    friend constexpr character_health& operator+=(character_health&, const healing&);

    constexpr const auto& get() const
    {
        return current.value;
    }

    void level_up()
    {
        max = type{non_negative_double{1500.}};
    }

private:
    type current;
    type max;
};

constexpr character_health& operator-=(character_health& health, const damage& damage)
{
    health.current.value -= damage.value;
    return health;
}

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

    health_to_increase.current.value
        = std::min(health_to_increase.current.value + healing.value, health_to_increase.max.value);

    return health_to_increase;
}

} // namespace rpg_kata
