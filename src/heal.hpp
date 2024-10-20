#pragma once

#include "character_stats.hpp"
#include "faction.hpp"
#include "healing.hpp"
#include "healing_magical_object.hpp"

namespace rpg_kata
{
constexpr void heal(character_stats& target_stats)
{
    target_stats.heal(healing{});
}

constexpr void heal(const factions&                        healer_factions,
                    const factions&                        target_factions,
                    character_stats&                       target_stats,
                    std::optional<healing_magical_object>& healing_magical_object,
                    const healing&                         amount)
{
    if (!are_allied(healer_factions, target_factions))
    {
        return;
    }

    if (!healing_magical_object)
    {
        heal(target_stats);
        return;
    }

    if (healing_magical_object->health.is_destroyed())
    {
        heal(target_stats);
        return;
    }

    const auto actual_healing_amount = healing_magical_object->health.syphon_up_to(amount);
    target_stats.heal(actual_healing_amount);
}

} // namespace rpg_kata
