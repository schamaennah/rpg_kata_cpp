#pragma once

#include "character.hpp"
#include "character_health.hpp"
#include "damage.hpp"
#include "level.hpp"
#include "percentage.hpp"
#include "thing_health.hpp"

namespace rpg_kata
{
inline bool deal_damage_preconditions(const position&                      attacker_position,
                                      const range&                         attacker_max_range,
                                      const position&                      target_position,
                                      const std::optional<magical_object>& attacker_magical_object)
{
    const auto range = distance(attacker_position, target_position);
    const bool is_in_range = range <= attacker_max_range;
    const bool is_magical_healing_object
        = attacker_magical_object
       && std::holds_alternative<healing_magical_object>(*attacker_magical_object);

    return is_in_range && !is_magical_healing_object;
}

constexpr damage damage_from_magical_object(std::optional<magical_object>& magical_object)
{
    if (magical_object && std::holds_alternative<magical_weapon>(*magical_object))
    {
        auto& attacker_magical_weapon = std::get<magical_weapon>(*magical_object);
        --attacker_magical_weapon.health;
        return attacker_magical_weapon.damage;
    }

    return damage{};
}

inline void deal_damage(character_health&              target_health,
                        const level&                   attacker_level,
                        const level&                   target_level,
                        const position&                attacker_position,
                        const position&                target_position,
                        const range&                   attacker_max_range,
                        const factions&                attacker_factions,
                        const factions&                target_factions,
                        std::optional<magical_object>& attacker_magical_object)
{
    if (!deal_damage_preconditions(attacker_position,
                                   attacker_max_range,
                                   target_position,
                                   attacker_magical_object))
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
        const auto     damage    = damage_from_magical_object(attacker_magical_object);
        const auto level_gap = target_level - attacker_level;

        if (level_gap >= level_diff{5})
        {
            return damage - modifier;
        }
        else if (level_gap <= level_diff{-5})
        {
            return damage + modifier;
        }
        else
        {
            return damage;
        }
    }();

    target_health -= damage_to_be_done;
}

constexpr void deal_damage(character& attacker, character& target)
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
                attacker.magical_object);
}

inline void deal_damage(const position&                attacker_position,
                        const range&                   attacker_max_range,
                        const position&                target_position,
                        thing_health&                  target_health,
                        std::optional<magical_object>& attacker_magical_object)
{
    if (!deal_damage_preconditions(attacker_position,
                                   attacker_max_range,
                                   target_position,
                                   attacker_magical_object))
    {
        return;
    }

    target_health -= damage_from_magical_object(attacker_magical_object);
}

} // namespace rpg_kata
