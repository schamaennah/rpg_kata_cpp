#pragma once

#include "position.hpp"
#include "thing_health.hpp"

#include <string>

namespace rpg_kata
{
struct thing
{
    std::string  name;
    thing_health health;
    position     position;
};
} // namespace rpg_kata
