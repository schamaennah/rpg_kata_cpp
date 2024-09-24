#pragma once

#include "character.hpp"
#include "character_health.hpp"
#include "damage.hpp"
#include "level.hpp"
#include "percentage.hpp"
#include "thing_health.hpp"

namespace rpg_kata
{
inline bool deal_damage_preconditions(
    const position&                              attacker_position,
    const range&                                 attacker_max_range,
    const position&                              target_position,
    const std::optional<healing_magical_object>& attacker_healing_magical_object)
{
    const auto range = distance(attacker_position, target_position);
    return !attacker_healing_magical_object && range <= attacker_max_range;
}

inline void deal_damage(
    character_health&                            target_health,
    const level&                                 attacker_level,
    const level&                                 target_level,
    const position&                              attacker_position,
    const position&                              target_position,
    const range&                                 attacker_max_range,
    const factions&                              attacker_factions,
    const factions&                              target_factions,
    const std::optional<healing_magical_object>& attacker_healing_magical_object)
{
    if (!deal_damage_preconditions(attacker_position,
                                   attacker_max_range,
                                   target_position,
                                   attacker_healing_magical_object))
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
                target.factions,
                attacker.healing_magical_object);
}

inline void deal_damage(
    const position&                              attacker_position,
    const range&                                 attacker_max_range,
    const position&                              target_position,
    thing_health&                                target_health,
    const std::optional<healing_magical_object>& attacker_healing_magical_object)
{
    if (!deal_damage_preconditions(attacker_position,
                                   attacker_max_range,
                                   target_position,
                                   attacker_healing_magical_object))
    {
        return;
    }

    target_health -= damage{};
}

} // namespace rpg_kata
