#pragma once

#include "damage.hpp"
#include "healing.hpp"
#include "new_type.hpp"
#include "non_negative_double.hpp"
#include "status.hpp"
#include "value_wrapper.hpp"

#include <algorithm>

namespace rpg_kata
{
using health_base = value_wrapper<new_type, non_negative_double, 1000.>;

class health : health_base
{
public:
    constexpr health() = default;

    explicit constexpr health(const double value)
        : health_base{std::min(non_negative_double{value}, initial_value)}
    {}

    bool                     operator==(const health&) const = default;
    friend constexpr health& operator-=(health&, const damage&);
    friend constexpr health& operator+=(health&, const healing&);
};

constexpr health& operator-=(health& health, const damage& damage)
{
    health.value -= damage.value;
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

    health_to_increase.value
        = std::min(health_to_increase.value + healing.value, health::initial_value);

    return health_to_increase;
}

} // namespace rpg_kata
