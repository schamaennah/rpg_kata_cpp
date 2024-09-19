#pragma once

#include "faction.hpp"
#include "healing.hpp"
#include "health.hpp"

namespace rpg_kata
{
constexpr void heal(health& target_health)
{
    target_health += healing{};
}

constexpr void heal(const factions& attacker_factions,
                    const factions& target_factions,
                    health&         target_health)
{
    if (!are_allied(attacker_factions, target_factions))
    {
        return;
    }

    heal(target_health);
}

} // namespace rpg_kata
