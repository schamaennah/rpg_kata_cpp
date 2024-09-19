#include <catch2/catch_test_macros.hpp>

#include <damage.hpp>
#include <deal_damage.hpp>
#include <health.hpp>
#include <status.hpp>

namespace rpg_kata::tests
{

SCENARIO("Dealing Damage", "[damage]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = health{50};

        WHEN("Dealing Damage")
        {
            deal_damage(target_health, {}, {});

            THEN("1 Damage is subtracted from target Health")
            {
                REQUIRE(target_health == health{49});
            }
        }
        WHEN("Damage exeeds Health")
        {
            constexpr auto exeeding_damage = damage{non_negative_double{100.}};
            target_health -= exeeding_damage;

            THEN("Health becomes 0")
            {
                REQUIRE(target_health == health{0});
            }
            THEN("Status is Dead")
            {
                REQUIRE(status(target_health) == status::dead);
            }
        }
    }
    WHEN("A Character deals damage to itself")
    {
        auto new_character = character{};
        deal_damage(new_character, new_character);

        THEN("Nothing happens")
        {
            REQUIRE(new_character.health == health{1000});
        }
    }
    WHEN("The target is 5 or more levels above the attacker")
    {
        constexpr auto attacker_level = level{5};
        constexpr auto target_level   = level{10};
        auto           target_health  = health{10};
        deal_damage(target_health, attacker_level, target_level);

        THEN("The dealt damage is half")
        {
            REQUIRE(target_health == health{9.5});
        }
    }
    WHEN("The target is 5 or less levels below the attacker")
    {
        constexpr auto attacker_level = level{10};
        constexpr auto target_level   = level{5};
        auto           target_health  = health{10};
        deal_damage(target_health, attacker_level, target_level);

        THEN("The dealt damage is increased by 50%")
        {
            REQUIRE(target_health == health{8.5});
        }
    }
}

} // namespace rpg_kata::tests
