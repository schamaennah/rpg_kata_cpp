#include <catch2/catch_test_macros.hpp>

#include <thing.hpp>

namespace rpg_kata::tests
{
TEST_CASE("Things can be Created", "[thing]")
{
    const auto new_thing = thing{};
}
} // namespace rpg_kata::tests
