#pragma once

#include "thing_health.hpp"

#include <string>

namespace rpg_kata
{
struct thing
{
    std::string  name;
    thing_health health;
};
} // namespace rpg_kata
