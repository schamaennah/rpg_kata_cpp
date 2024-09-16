#pragma once

#include "damage.hpp"
#include "health.hpp"

namespace rpg_kata
{
constexpr void deal_damage(health& target_health)
{
    target_health -= damage{};
}

} // namespace rpg_kata
