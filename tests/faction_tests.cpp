#include <catch2/catch_test_macros.hpp>

#include <faction.hpp>

namespace rpg_kata::tests
{

SCENARIO("Factions", "[faction]")
{
    WHEN("Two sets of factions have at least one faction in common")
    {
        const auto factions_a = factions{{1}, {2}, {3}};
        const auto factions_b = factions{{3}, {4}, {5}};

        THEN("They are allied")
        {
            REQUIRE(are_allied(factions_a, factions_b) == true);
        }
    }
    WHEN("Two sets of factions have no faction in common")
    {
        const auto factions_a = factions{{1}, {2}, {3}};
        const auto factions_b = factions{{4}, {5}, {6}};

        THEN("They are not allied")
        {
            REQUIRE(are_allied(factions_a, factions_b) == false);
        }
    }
    WHEN("Two sets of factions are empty")
    {
        const auto factions_a = factions{};
        const auto factions_b = factions{};

        THEN("They are not allied")
        {
            REQUIRE(are_allied(factions_a, factions_b) == false);
        }
    }
}

} // namespace rpg_kata::tests
