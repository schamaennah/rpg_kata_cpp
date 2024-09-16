#pragma once

#include "healing.hpp"
#include "health.hpp"

namespace rpg_kata
{
constexpr void heal(health& target_health)
{
    target_health += healing{};
}

} // namespace rpg_kata
