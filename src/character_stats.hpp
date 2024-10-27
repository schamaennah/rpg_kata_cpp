#ifndef CHARACTER_STATS_HPP
#define CHARACTER_STATS_HPP

#include "character_health.hpp"
#include "character_status.hpp"
#include "damage.hpp"
#include "faction.hpp"
#include "level.hpp"

namespace rpg_kata
{
constexpr damage leveling_damage_threshold(const level& current_level)
{
    if (current_level == level{0})
    {
        return damage{};
    }

    return damage{non_negative_double{1000.} * current_level.value}
         + leveling_damage_threshold(level{current_level.value - 1});
}

inline level to_level(const factions& factions)
{
    return level{static_cast<unsigned>(factions.get_total_size() / 3) + 1U};
}

class character_stats
{
    static constexpr auto level_2_threshold = damage{non_negative_double{1000}};
    static constexpr auto level_3_threshold = level_2_threshold + damage{non_negative_double{2000}};

public:
    character_stats() = default;

    character_stats(const character_health& health, const level& level)
        : health{health}
        , level{level}
        , total_received_damage{level > rpg_kata::level{1} ? level_2_threshold
                                                           : damage{non_negative_double{0}}}
    {}

    explicit character_stats(const character_health& health)
        : character_stats{health, rpg_kata::level{}}
    {}

    explicit character_stats(const factions& factions)
        : level{to_level(factions)}
        , factions{factions}
    {}

    explicit character_stats(const character_health& health, const factions& factions)
        : health{health}
        , level{to_level(factions)}
        , factions{factions}
    {}

    constexpr void take_damage(const damage& incoming_damage)
    {
        const auto previous_total_received_damage = total_received_damage;
        const auto previous_health                = health;

        health -= incoming_damage;
        total_received_damage
            += {non_negative_double{previous_health.get().get() - health.get().get()}};

        const auto next_level_threshold = leveling_damage_threshold(level);

        if (status(health) == character_status::alive
            && previous_total_received_damage < next_level_threshold
            && total_received_damage >= next_level_threshold)
        {
            ++level;
        }
    }

    constexpr void heal(const healing& heal)
    {
        health += heal;
    }

    constexpr const auto& get_health() const
    {
        return health;
    }

    constexpr const auto& get_level() const
    {
        return level;
    }

    constexpr const factions& get_factions() const
    {
        return factions;
    }

    void join_faction(const faction& faction)
    {
        factions.join(faction);
        if (factions.get_total_size() >= 3 && level < rpg_kata::level{2})
        {
            level = rpg_kata::level{2};
        }
    }

private:
    character_health health;
    level            level;
    damage           total_received_damage;
    factions         factions;
};
} // namespace rpg_kata

#endif // CHARACTER_STATS_HPP
