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
}

} // namespace rpg_kata::tests
