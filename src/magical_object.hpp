#pragma once

#include "healing_magical_object.hpp"
#include "magical_weapon.hpp"

#include <variant>

namespace rpg_kata
{
using magical_object = std::variant<magical_weapon, healing_magical_object>;

} // namespace rpg_kata
