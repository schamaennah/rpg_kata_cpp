#include <catch2/catch_test_macros.hpp>

#include <heal.hpp>
#include <health.hpp>

namespace rpg_kata::tests
{

SCENARIO("Healing Health", "[healing]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = health{50};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Health is healed by 1")
            {
                REQUIRE(target_health == health{51});
            }
        }
    }
    GIVEN("Target health of 0")
    {
        auto target_health = health{0};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Nothing happens")
            {
                REQUIRE(target_health == health{0});
            }
        }
    }
    GIVEN("Target health of 950")
    {
        auto target_health = health{950};

        WHEN("Healing would exeed Health 1000")
        {
            constexpr auto exeeding_healing = healing{100};
            target_health += exeeding_healing;

            THEN("Health is capped at 1000")
            {
                REQUIRE(target_health == health{1000});
            }
        }
    }
    WHEN("Characters are not allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{4}, {5}, {6}};
        auto       target_health   = health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is not healed")
        {
            REQUIRE(target_health == health{50});
        }
    }
    WHEN("Characters are allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{3}, {4}, {5}};
        auto       target_health   = health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is healed")
        {
            REQUIRE(target_health == health{51});
        }
    }
}

} // namespace rpg_kata::tests
