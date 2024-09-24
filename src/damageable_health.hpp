#pragma once

#include "damage.hpp"
#include "thing_health.hpp"

#include <algorithm>
#include <concepts>

namespace rpg_kata
{
class character_health;

template <typename t>
concept damageable_health = std::same_as<t, character_health> || std::same_as<t, thing_health>;

constexpr damageable_health auto& operator-=(damageable_health auto& health, const damage& damage)
{
    health.value -= std::min(health.value, damage.value);
    return health;
}

} // namespace rpg_kata
