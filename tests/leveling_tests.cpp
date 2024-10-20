#include <catch2/catch_test_macros.hpp>

#include <character.hpp>
#include <deal_damage.hpp>
#include <heal.hpp>

namespace rpg_kata::tests
{
SCENARIO("Leveling up from 1 to 2", "[level]")
{
    GIVEN("A level 1 character")
    {
        const auto allied = factions{{1}};
        auto       hero   = character{.factions = allied};

        REQUIRE(hero.stats.get_level() == level{1});

        WHEN("When he survives 1000 damage")
        {
            const auto weapon = magical_weapon{damage{non_negative_double{500}}, {10}};
            auto       enemy  = character{.magical_object = weapon};

            deal_damage(enemy, hero);

            auto healing_object
                = std::optional<healing_magical_object>{healing_magical_object_health{1000}};

            heal(allied, hero.factions, hero.stats, healing_object, healing{500});

            deal_damage(enemy, hero);

            THEN("He is alive")
            {
                REQUIRE(status(hero.stats.get_health()) == character_status::alive);
            }
            THEN("He is now level 2")
            {
                REQUIRE(hero.stats.get_level() == level{2});
            }
        }
        WHEN("When he does not survive 1000 damage")
        {
            const auto weapon = magical_weapon{damage{non_negative_double{1000}}, {10}};
            auto       enemy  = character{.magical_object = weapon};

            deal_damage(enemy, hero);

            THEN("He is not alive")
            {
                REQUIRE(status(hero.stats.get_health()) == character_status::dead);
            }
            THEN("He is still level 1")
            {
                REQUIRE(hero.stats.get_level() == level{1});
            }
        }
    }
}

} // namespace rpg_kata::tests
