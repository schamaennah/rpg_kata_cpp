#pragma once

#include <algorithm>
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

constexpr bool are_allied(const factions& lhs, const factions& rhs)
{
    return std::ranges::any_of(lhs, [&](const auto& faction) { return rhs.contains(faction); });
}

} // namespace rpg_kata
