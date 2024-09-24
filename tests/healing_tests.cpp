#include <catch2/catch_test_macros.hpp>

#include <character_health.hpp>
#include <heal.hpp>
#include <healing_magical_object.hpp>
#include <healing_magical_object_health.hpp>

namespace rpg_kata::tests
{
constexpr void heal(const factions&   healer_factions,
                    const factions&   target_factions,
                    character_health& target_health)
{
    auto healer_healing_magical_object = std::optional<healing_magical_object>{};
    heal(healer_factions, target_factions, target_health, healer_healing_magical_object, {});
}

constexpr void heal(character_health&                      target_health,
                    std::optional<healing_magical_object>& healer_healing_magical_object,
                    const healing&                         amount)
{
    heal({{1}}, {{1}}, target_health, healer_healing_magical_object, amount);
}

SCENARIO("Healing Health", "[healing]")
{
    GIVEN("Target health of 50")
    {
        auto target_health = character_health{50};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Health is healed by 1")
            {
                REQUIRE(target_health == character_health{51});
            }
        }
    }
    GIVEN("Target health of 0")
    {
        auto target_health = character_health{0};

        WHEN("Healing")
        {
            heal(target_health);

            THEN("Nothing happens")
            {
                REQUIRE(target_health == character_health{0});
            }
        }
    }
    GIVEN("Target health of 950")
    {
        auto target_health = character_health{950};

        WHEN("Healing would exeed Health 1000")
        {
            constexpr auto exeeding_healing = healing{100};
            target_health += exeeding_healing;

            THEN("Health is capped at 1000")
            {
                REQUIRE(target_health == character_health{1000});
            }
        }
    }
    WHEN("Characters are not allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{4}, {5}, {6}};
        auto       target_health   = character_health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is not healed")
        {
            REQUIRE(target_health == character_health{50});
        }
    }
    WHEN("Characters are allied")
    {
        const auto healer_factions = factions{{1}, {2}, {3}};
        const auto target_factions = factions{{3}, {4}, {5}};
        auto       target_health   = character_health{50};

        heal(healer_factions, target_factions, target_health);

        THEN("Target is healed")
        {
            REQUIRE(target_health == character_health{51});
        }
    }
    GIVEN("A Healing Magical Object with Health")
    {
        auto healer_healing_magical_object
            = std::optional<healing_magical_object>{healing_magical_object_health{10}};

        auto target_health = character_health{50};

        WHEN("Used for healing")
        {
            heal(target_health, healer_healing_magical_object, healing{6});

            THEN("Character gained health from the Magical Object")
            {
                REQUIRE(healer_healing_magical_object->health.current()
                        == healing_magical_object_health::type{4});

                REQUIRE(target_health == character_health{56});
            }
        }
        WHEN("Used for healing more than it can")
        {
            heal(target_health, healer_healing_magical_object, healing{100});
            THEN("Character still gains some health from the Magical Object")
            {
                REQUIRE(healer_healing_magical_object->health.current()
                        == healing_magical_object_health::type{0});

                REQUIRE(target_health == character_health{60});
            }
        }
        WHEN("Used for healing a healthy Character")
        {
            auto full_target_health = character_health{};
            heal(full_target_health, healer_healing_magical_object, healing{100});

            THEN("Character gains nothing and the Healing Magical Object gets wasted")
            {
                REQUIRE(healer_healing_magical_object->health.current()
                        == healing_magical_object_health::type{0});

                REQUIRE(full_target_health == character_health{});
            }
        }
    }
    GIVEN("A destroyed Healing Magical Object")
    {
        auto healer_healing_magical_object
            = std::optional<healing_magical_object>{healing_magical_object_health{0}};

        auto target_health = character_health{50};

        WHEN("Used for healing")
        {
            heal(target_health, healer_healing_magical_object, healing{6});
            THEN("Only the default healing is healed")
            {
                REQUIRE(healer_healing_magical_object->health.current()
                        == healing_magical_object_health::type{0});

                REQUIRE(target_health == character_health{51});
            }
        }
    }
}

} // namespace rpg_kata::tests
