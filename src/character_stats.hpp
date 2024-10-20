#ifndef CHARACTER_STATS_HPP
#define CHARACTER_STATS_HPP

#include "character_health.hpp"
#include "character_status.hpp"
#include "damage.hpp"
#include "level.hpp"

namespace rpg_kata
{
class character_stats
{
    static constexpr auto level_2_threshold = damage{non_negative_double{1000}};

public:
    constexpr character_stats() = default;

    constexpr character_stats(const character_health& health, const level& level)
        : health{health}
        , level{level}
        , total_received_damage{level > rpg_kata::level{1} ? level_2_threshold
                                                           : damage{non_negative_double{0}}}
    {}

    constexpr character_stats(const character_health& health)
        : character_stats{health, rpg_kata::level{}}
    {}

    constexpr void take_damage(const damage& incoming_damage)
    {
        const auto previous_total_received_damage = total_received_damage;
        const auto previous_health                = health;

        health -= incoming_damage;
        total_received_damage
            += {non_negative_double{previous_health.get().get() - health.get().get()}};

        if (status(health) == character_status::alive
            && previous_total_received_damage < level_2_threshold
            && total_received_damage >= level_2_threshold)
        {
            level = rpg_kata::level{2};
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

private:
    character_health health;
    level            level;
    damage           total_received_damage;
};
} // namespace rpg_kata

#endif // CHARACTER_STATS_HPP
