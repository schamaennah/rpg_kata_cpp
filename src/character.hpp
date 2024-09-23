#pragma once

#include "character_health.hpp"
#include "faction.hpp"
#include "level.hpp"
#include "position.hpp"
#include "range.hpp"

namespace rpg_kata
{
struct character
{
    character_health health;
    level    level;
    position position;
    range    max_range;
    factions factions;
};

} // namespace rpg_kata
