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
            deal_damage(target_health);

            THEN("1 Damage is subtracted from target Health")
            {
                REQUIRE(target_health == health{49});
            }
        }
        WHEN("Damage exeeds Health")
        {
            constexpr auto exeeding_damage = damage{100};
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
}

} // namespace rpg_kata::tests
