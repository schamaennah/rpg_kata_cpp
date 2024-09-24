#include <catch2/catch_test_macros.hpp>

#include <thing.hpp>

namespace rpg_kata::tests
{
TEST_CASE("Things can be Created", "[thing]")
{
    const auto new_thing = thing{};
}

TEST_CASE("Things with zero health are Destroyed", "[thing]")
{
    REQUIRE(is_destroyed(thing_health{non_negative_double{0}}) == true);
    REQUIRE(is_destroyed(thing_health{non_negative_double{10}}) == false);
}
} // namespace rpg_kata::tests
