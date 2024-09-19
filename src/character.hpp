#pragma once

#include "health.hpp"
#include "level.hpp"
#include "position.hpp"

namespace rpg_kata
{
struct character
{
    health   health;
    level    level;
    position position;
};

} // namespace rpg_kata
