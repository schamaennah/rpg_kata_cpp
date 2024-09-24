#include <catch2/catch_test_macros.hpp>

#include <character_health.hpp>
#include <character_status.hpp>
#include <damage.hpp>
#include <deal_damage.hpp>

namespace rpg_kata::tests
{
inline void deal_damage(character_health& target_health,
                        const level&      attacker_level,
                        const level&      target_level)
{
    deal_damage(target_health, attacker_level, target_level, {}, {}, {}, {}, {}, {});
}

inline void deal_damage(character_health&                    target_health,
                        const std::optional<magical_object>& attacker_magical_object)
{
    deal_damage(target_health, {}, {}, {}, {}, {}, {}, {}, attacker_magical_object);
}

inline void deal_damage(thing_health&                        target_health,
                        const std::optional<magical_object>& attacker_magical_object)
{
    deal_damage({}, {}, {}, target_health, attacker_magical_object);
}

SCENARIO("Dealing Damage", "[damage]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = character_health{50};

        WHEN("Dealing Damage")
        {
            deal_damage(target_health, {}, {}, {}, {}, {}, {}, {}, {});

            THEN("1 Damage is subtracted from target Health")
            {
                REQUIRE(target_health == character_health{49});
            }
        }
        WHEN("Damage exeeds Health")
        {
            constexpr auto exeeding_damage = damage{non_negative_double{100.}};
            target_health -= exeeding_damage;

            THEN("Health becomes 0")
            {
                REQUIRE(target_health == character_health{0});
            }
            THEN("Status is Dead")
            {
                REQUIRE(status(target_health) == character_status::dead);
            }
        }
    }
    WHEN("A Character deals damage to itself")
    {
        auto new_character = character{};
        deal_damage(new_character, new_character);

        THEN("Nothing happens")
        {
            REQUIRE(new_character.health == character_health{1000});
        }
    }
    WHEN("The target is 5 or more levels above the attacker")
    {
        constexpr auto attacker_level = level{5};
        constexpr auto target_level   = level{10};
        auto           target_health  = character_health{10};
        deal_damage(target_health, attacker_level, target_level);

        THEN("The dealt damage is half")
        {
            REQUIRE(target_health == character_health{9.5});
        }
    }
    WHEN("The target is 5 or less levels below the attacker")
    {
        constexpr auto attacker_level = level{10};
        constexpr auto target_level   = level{5};
        auto           target_health  = character_health{10};
        deal_damage(target_health, attacker_level, target_level);

        THEN("The dealt damage is increased by 50%")
        {
            REQUIRE(target_health == character_health{8.5});
        }
    }
    WHEN("The target is out of range")
    {
        constexpr auto attacker_position = position{0, 0};
        constexpr auto target_position   = position{2, 2};
        auto           target_health     = character_health{10};

        deal_damage(target_health, {}, {}, attacker_position, target_position, melee, {}, {}, {});

        THEN("No damage is done")
        {
            REQUIRE(target_health == character_health{10});
        }
    }
    WHEN("Two characters have at least one faction in common")
    {
        const auto attacker_factions = factions{{1}, {2}, {3}};
        const auto target_factions   = factions{{3}, {4}, {5}};
        auto       target_health     = character_health{10};

        deal_damage(target_health, {}, {}, {}, {}, {}, attacker_factions, target_factions, {});

        THEN("No damage is done")
        {
            REQUIRE(target_health == character_health{10});
        }
    }
    GIVEN("An attacker and a Thing ")
    {
        auto target_thing_health = thing_health{non_negative_double{50}};
        auto attacker_deals_damage_with_max_range
            = [&, attacker_position = position{1, 1}, target_position = position{2, 2}](
                  const range& attacker_max_range) {
                  deal_damage(attacker_position,
                              attacker_max_range,
                              target_position,
                              target_thing_health,
                              {});
              };

        WHEN("Dealing damange to a Thing which is in range")
        {
            attacker_deals_damage_with_max_range(range{2});

            THEN("Damage is done")
            {
                REQUIRE(target_thing_health == thing_health{non_negative_double{49}});
            }
        }
        WHEN("Dealing damange to a Thing which is not in range")
        {
            attacker_deals_damage_with_max_range(range{1});

            THEN("Damage is not done")
            {
                REQUIRE(target_thing_health == thing_health{non_negative_double{50}});
            }
        }
    }
    GIVEN("A Character with a Healing Magical Object")
    {
        const auto attacker_healing_magical_object
            = std::optional<healing_magical_object>{{healing_magical_object_health{10}}};

        WHEN("It deals damage to a Character")
        {
            auto target_health = character_health{10};
            deal_damage(target_health, attacker_healing_magical_object);

            THEN("No damage is done")
            {
                REQUIRE(target_health == character_health{10});
            }
        }
        WHEN("It deals damage to a Thing")
        {
            auto target_health = thing_health{non_negative_double{10}};
            deal_damage(target_health, attacker_healing_magical_object);

            THEN("No damage is done")
            {
                REQUIRE(target_health == thing_health{non_negative_double{10}});
            }
        }
    }
    GIVEN("A Character with a Magical Weapon")
    {
        WHEN("It deals damage to a Character")
        {
            auto target_health = character_health{10};
            deal_damage(target_health, magical_weapon{});

            THEN("Damage is done")
            {
                REQUIRE(target_health == character_health{9});
            }
        }
        WHEN("It deals damage to a Thing")
        {
            auto target_health = thing_health{non_negative_double{10}};
            deal_damage(target_health, magical_weapon{});

            THEN("Damage is done")
            {
                REQUIRE(target_health == thing_health{non_negative_double{9}});
            }
        }
    }
}

} // namespace rpg_kata::tests
