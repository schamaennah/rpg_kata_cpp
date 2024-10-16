#pragma once

#include "character_health.hpp"
#include "faction.hpp"
#include "healing.hpp"
#include "healing_magical_object.hpp"

namespace rpg_kata
{
constexpr void heal(character_health& target_health)
{
    target_health += healing{};
}

constexpr void heal(const factions&                        healer_factions,
                    const factions&                        target_factions,
                    character_health&                      target_health,
                    std::optional<healing_magical_object>& healing_magical_object,
                    const healing&                         amount)
{
    if (!are_allied(healer_factions, target_factions))
    {
        return;
    }

    if (!healing_magical_object)
    {
        heal(target_health);
        return;
    }

    if (healing_magical_object->health.is_destroyed())
    {
        heal(target_health);
        return;
    }

    const auto actual_healing_amount = healing_magical_object->health.syphon_up_to(amount);
    target_health += actual_healing_amount;
}

} // namespace rpg_kata
