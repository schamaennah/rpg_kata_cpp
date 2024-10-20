#pragma once

#include "character_stats.hpp"
#include "faction.hpp"
#include "magical_object.hpp"
#include "position.hpp"
#include "range.hpp"

#include <optional>

namespace rpg_kata
{
struct character
{
    character_stats               stats;
    position position;
    range    max_range;
    factions factions;
    std::optional<magical_object> magical_object;
};

} // namespace rpg_kata
