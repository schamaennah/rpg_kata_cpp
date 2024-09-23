#pragma once

#include "faction.hpp"
#include "healing.hpp"
#include "character_health.hpp"

namespace rpg_kata
{
constexpr void heal(character_health& target_health)
{
    target_health += healing{};
}

constexpr void heal(const factions& attacker_factions,
                    const factions& target_factions,
                    character_health&         target_health)
{
    if (!are_allied(attacker_factions, target_factions))
    {
        return;
    }

    heal(target_health);
}

} // namespace rpg_kata
