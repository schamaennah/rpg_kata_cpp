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

class factions
{
public:
    factions() = default;

    explicit factions(const std::initializer_list<faction>& values)
        : current{values}
        , total{values}
    {}

    constexpr const auto& get_current() const
    {
        return current;
    }

    auto get_total_size() const
    {
        return total.size();
    }

    void join(const faction& faction)
    {
        current.insert(faction);
        total.insert(faction);
    }

    void leave(const faction& faction)
    {
        current.erase(faction);
    }

private:
    std::set<faction> current;
    std::set<faction> total;
};

constexpr bool are_allied(const factions& lhs, const factions& rhs)
{
    return std::ranges::any_of(lhs.get_current(),
                               [&](const auto& faction)
                               { return rhs.get_current().contains(faction); });
}

} // namespace rpg_kata
