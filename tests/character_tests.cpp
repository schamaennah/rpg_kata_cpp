#include <catch2/catch_test_macros.hpp>

#include <character.hpp>

namespace rpg_kata::tests
{

SCENARIO("New Characters", "[character]")
{
    WHEN("A new Character is Created")
    {
        constexpr auto new_character = character{};

        THEN("Its Health is 1000")
        {
            REQUIRE(new_character.health == health{1000});
        }
    }
}

} // namespace rpg_kata
