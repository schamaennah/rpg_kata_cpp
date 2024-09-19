#pragma once

#include <compare>
#include <cstddef>
#include <set>

namespace rpg_kata
{
using faction_id = std::size_t;

struct faction
{
    faction_id id = 0;

    std::strong_ordering operator<=>(const faction&) const = default;
};

using factions = std::set<faction>;

} // namespace rpg_kata
