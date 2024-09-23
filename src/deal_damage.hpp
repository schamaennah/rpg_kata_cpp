#pragma once

#include "character.hpp"
#include "character_health.hpp"
#include "damage.hpp"
#include "level.hpp"
#include "percentage.hpp"

namespace rpg_kata
{
inline void deal_damage(character_health& target_health,
                        const level&      attacker_level,
                        const level&      target_level,
                        const position&   attacker_position,
                        const position&   target_position,
                        const range&      attacker_max_range,
                        const factions&   attacker_factions,
                        const factions&   target_factions)
{
    const auto range = distance(attacker_position, target_position);

    if (range > attacker_max_range)
    {
        return;
    }

    if (are_allied(attacker_factions, target_factions))
    {
        return;
    }

    const auto damage_to_be_done = [&]
    {
        constexpr auto modifier  = percentage{50};
        const auto level_gap = target_level - attacker_level;
        if (level_gap >= level_diff{5})
        {
            return damage{} - modifier;
        }
        else if (level_gap <= level_diff{-5})
        {
            return damage{} + modifier;
        }
        else
        {
            return damage{};
        }
    }();

    target_health -= damage_to_be_done;
}

constexpr void deal_damage(const character& attacker, character& target)
{
    if (&attacker == &target)
    {
        return;
    }

    deal_damage(target.health,
                attacker.level,
                target.level,
                attacker.position,
                target.position,
                attacker.max_range,
                attacker.factions,
                target.factions);
}

} // namespace rpg_kata
