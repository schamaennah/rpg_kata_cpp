#pragma once

#include "character_health.hpp"
#include "faction.hpp"
#include "level.hpp"
#include "magical_object.hpp"
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
    magical_object magical_object = {magical_object_health{1U}};
};

} // namespace rpg_kata
