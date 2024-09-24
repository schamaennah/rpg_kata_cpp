#include <catch2/catch_test_macros.hpp>

#include <magical_object.hpp>

namespace rpg_kata::tests
{
TEST_CASE("Magical Objects can be Created", "[magical object]")
{
    constexpr auto new_magical_object = magical_object{magical_object_health{100U}};
}

} // namespace rpg_kata::tests
