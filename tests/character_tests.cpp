#include <catch2/catch_test_macros.hpp>

#include <character.hpp>
#include <status.hpp>

namespace rpg_kata::tests
{

SCENARIO("New Characters", "[character]")
{
    WHEN("A new Character is Created")
    {
        const auto new_character = character{};

        THEN("Its Health is 1000")
        {
            REQUIRE(new_character.health == health{1000});
        }
        THEN("Its Level is 1")
        {
            REQUIRE(new_character.level == level{1});
        }
        THEN("It's Alive")
        {
            REQUIRE(status(new_character.health) == status::alive);
        }
        THEN("It belongs to no Factions")
        {
            REQUIRE(new_character.factions.empty());
        }
    }
}

} // namespace rpg_kata
