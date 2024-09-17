#pragma once

#include "character.hpp"
#include "damage.hpp"
#include "health.hpp"
#include "level.hpp"
#include "percentage.hpp"

namespace rpg_kata
{
constexpr void deal_damage(health&      target_health,
                           const level& attacker_level,
                           const level& target_level)
{
    const auto level_gap         = target_level - attacker_level;
    const auto damage_to_be_done
        = level_gap >= level_diff{5} ? damage{} - percentage{50.} : damage{};
    target_health -= damage_to_be_done;
}

constexpr void deal_damage(const character& attacker, character& target)
{
    if (&attacker == &target)
    {
        return;
    }
    deal_damage(target.health, attacker.level, target.level);
}

} // namespace rpg_kata
