#include <catch2/catch_test_macros.hpp>

#include <healing_magical_object.hpp>

namespace rpg_kata::tests
{
TEST_CASE("Magical Objects can be Created", "[magical object]")
{
    constexpr auto new_magical_object = healing_magical_object{healing_magical_object_health{100U}};
}

TEST_CASE("Magical Objects with zero health are Destroyed", "[magical object]")
{
    REQUIRE(healing_magical_object_health{0}.is_destroyed() == true);
    REQUIRE(healing_magical_object_health{10}.is_destroyed() == false);
}

} // namespace rpg_kata::tests
