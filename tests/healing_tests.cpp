#include <catch2/catch_test_macros.hpp>

#include <character_health.hpp>
#include <heal.hpp>
#include <healing_magical_object.hpp>
#include <healing_magical_object_health.hpp>

namespace rpg_kata::tests
{

SCENARIO("Healing Health", "[healing]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = character_health{50};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Health is healed by 1")
            {
                REQUIRE(target_health == character_health{51});
            }
        }
    }
    GIVEN("Target health of 0")
    {
        auto target_health = character_health{0};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Nothing happens")
            {
                REQUIRE(target_health == character_health{0});
            }
        }
    }
    GIVEN("Target health of 950")
    {
        auto target_health = character_health{950};

        WHEN("Healing would exeed Health 1000")
        {
            constexpr auto exeeding_healing = healing{100};
            target_health += exeeding_healing;

            THEN("Health is capped at 1000")
            {
                REQUIRE(target_health == character_health{1000});
            }
        }
    }
    WHEN("Characters are not allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{4}, {5}, {6}};
        auto       target_health   = character_health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is not healed")
        {
            REQUIRE(target_health == character_health{50});
        }
    }
    WHEN("Characters are allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{3}, {4}, {5}};
        auto       target_health   = character_health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is healed")
        {
            REQUIRE(target_health == character_health{51});
        }
    }
    GIVEN("A Healing Magical Object with Health")
    {
        auto source_health = healing_magical_object_health{10};
        auto target_health = character_health{50};

        WHEN("Used for healing")
        {
            heal(source_health, target_health, healing{1});
            THEN("Character gained health from the Magical Object")
            {
                REQUIRE(source_health.current() == healing_magical_object_health::type{9});
                REQUIRE(target_health == character_health{51});
            }
        }
        WHEN("Used for healing more than it can")
        {
            heal(source_health, target_health, healing{100});
            THEN("Character still gains some health from the Magical Object")
            {
                REQUIRE(source_health.current() == healing_magical_object_health::type{0});
                REQUIRE(target_health == character_health{60});
            }
        }
        WHEN("Used for healing a healthy Character")
        {
            auto full_target_health = character_health{};
            heal(source_health, target_health, healing{100});
            THEN("Character gains nothing and the Healing Magical Object gets wasted")
            {
                REQUIRE(source_health.current() == healing_magical_object_health::type{0});
                REQUIRE(full_target_health == character_health{});
            }
        }
    }
    GIVEN("A destroyed Healing Magical Object")
    {
        auto source_health = healing_magical_object_health{0};
        auto target_health = character_health{50};

        WHEN("Used for healing")
        {
            heal(source_health, target_health, healing{1});
            THEN("Nothing happens")
            {
                REQUIRE(source_health.current() == healing_magical_object_health::type{0});
                REQUIRE(target_health == character_health{50});
            }
        }
    }
}

} // namespace rpg_kata::tests
