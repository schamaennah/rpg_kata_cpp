#pragma once

#include "character_health.hpp"
#include "faction.hpp"
#include "healing.hpp"
#include "healing_magical_object_health.hpp"

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

constexpr void heal(healing_magical_object_health& source_health, character_health& target_health)
{
    if (source_health.is_destroyed())
    {
        return;
    }

    --source_health;
    heal(target_health);
}

} // namespace rpg_kata
