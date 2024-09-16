#include <catch2/catch_test_macros.hpp>

#include <character.hpp>

namespace rpg_kata::tests
{

TEST_CASE("Characters can be Created", "[character]")
{
    constexpr auto new_character = character{};
}

} // namespace rpg_kata
