#pragma once

#include "character.hpp"
#include "damage.hpp"
#include "health.hpp"

namespace rpg_kata
{
constexpr void deal_damage(health& target_health)
{
    target_health -= damage{};
}

constexpr void deal_damage(const character& attacker, character& target)
{
    if (&attacker == &target)
    {
        return;
    }
    deal_damage(target.health);
}

} // namespace rpg_kata
