#include <catch2/catch_test_macros.hpp>

#include <damage.hpp>

namespace rpg_kata::tests
{

SCENARIO("Dealing Damage", "[damage]")
{
    WHEN("Damage is Created")
    {
        constexpr auto new_damage = damage{};

        THEN("Damage is 1")
        {
            REQUIRE(new_damage == damage{1});
        }
    }
}

} // namespace rpg_kata::tests
