#pragma once

#include "faction.hpp"
#include "health.hpp"
#include "level.hpp"
#include "position.hpp"
#include "range.hpp"

namespace rpg_kata
{
struct character
{
    health   health;
    level    level;
    position position;
    range    max_range;
    factions factions;
};

} // namespace rpg_kata
