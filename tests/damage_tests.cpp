#include <catch2/catch_test_macros.hpp>

#include <deal_damage.hpp>
#include <health.hpp>

namespace rpg_kata::tests
{

SCENARIO("Dealing Damage", "[damage]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = health{50};

        WHEN("Dealing Damage")
        {
            deal_damage(target_health);

            THEN("1 Damage is subtracted from target Health")
            {
                REQUIRE(target_health == health{49});
            }
        }
    }
}

} // namespace rpg_kata::tests
