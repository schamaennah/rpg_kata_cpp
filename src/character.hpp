#pragma once

#include "character_status.hpp"
#include "health.hpp"
#include "level.hpp"

namespace rpg_kata
{
struct character
{
    health           health;
    level            level;
    character_status status = character_status::alive;
};
} // namespace rpg_kata
