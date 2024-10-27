#include <catch2/catch_test_macros.hpp>

#include <character.hpp>
#include <deal_damage.hpp>
#include <heal.hpp>

namespace rpg_kata::tests
{
SCENARIO("Leveling up from 1 to 4 by received damage", "[level]")
{
    GIVEN("A level 1 character")
    {
        const auto allied = factions{{1}};
        auto       hero   = character{.stats = character_stats{allied}};

        REQUIRE(hero.stats.get_level() == level{1});

        WHEN("When he survives 1000 damage")
        {
            const auto weapon = magical_weapon{damage{non_negative_double{500}}, {20}};
            auto       enemy  = character{.magical_object = weapon};

            deal_damage(enemy, hero);

            auto healing_object
                = std::optional<healing_magical_object>{healing_magical_object_health{6000}};

            heal(allied, hero.stats, healing_object, healing{500});

            deal_damage(enemy, hero);

            THEN("He is alive")
            {
                REQUIRE(status(hero.stats.get_health()) == character_status::alive);
            }
            THEN("He is now level 2")
            {
                REQUIRE(hero.stats.get_level() == level{2});
            }
            WHEN("When he survives additional 2000 damage")
            {
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 1500
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 2000
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 2500
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 3000

                THEN("He is alive")
                {
                    REQUIRE(status(hero.stats.get_health()) == character_status::alive);
                }
                THEN("He is now level 3")
                {
                    REQUIRE(hero.stats.get_level() == level{3});
                }
                WHEN("When he survives additional 3000 damage")
                {
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 3500
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 4000
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 4500
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 5000
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 5500
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 6000

                    THEN("He is alive")
                    {
                        REQUIRE(status(hero.stats.get_health()) == character_status::alive);
                    }
                    THEN("He is now level 4")
                    {
                        REQUIRE(hero.stats.get_level() == level{4});
                    }
                }
                WHEN("When he does not survive additional 3000 damage")
                {
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 3500
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 4000
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 4500
                    heal(allied, hero.stats, healing_object, healing{500});
                    deal_damage(enemy, hero); // 5000

                    const auto weapon    = magical_weapon{damage{non_negative_double{1000}}, {10}};
                    enemy.magical_object = weapon;

                    deal_damage(enemy, hero);

                    THEN("He is not alive")
                    {
                        REQUIRE(status(hero.stats.get_health()) == character_status::dead);
                    }
                    THEN("He is still level 3")
                    {
                        REQUIRE(hero.stats.get_level() == level{3});
                    }
                }
            }
            WHEN("When he does not survive additional 2000 damage")
            {
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 1500
                heal(allied, hero.stats, healing_object, healing{500});
                deal_damage(enemy, hero); // 2000
                heal(allied, hero.stats, healing_object, healing{500});

                const auto weapon    = magical_weapon{damage{non_negative_double{1000}}, {10}};
                enemy.magical_object = weapon;

                deal_damage(enemy, hero);

                THEN("He is not alive")
                {
                    REQUIRE(status(hero.stats.get_health()) == character_status::dead);
                }
                THEN("He is still level 2")
                {
                    REQUIRE(hero.stats.get_level() == level{2});
                }
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

SCENARIO("Leveling up from 1 to 3 by changing factions", "[level]")
{
    GIVEN("A level 1 character")
    {
        auto hero = character{};
        REQUIRE(hero.stats.get_level() == level{1});

        WHEN("When he has been part of more than 3 different factions")
        {
            hero.stats.join_faction({1});
            hero.stats.join_faction({2});
            hero.stats.join_faction({3});

            THEN("He is level 2")
            {
                REQUIRE(hero.stats.get_level() == level{2});
            }
            WHEN("When he has been part of additional 3 different factions")
            {
                hero.stats.join_faction({4});
                hero.stats.join_faction({5});
                hero.stats.join_faction({6});

                THEN("He is level 3")
                {
                    REQUIRE(hero.stats.get_level() == level{3});
                }
            }
        }
    }
}

} // namespace rpg_kata::tests
