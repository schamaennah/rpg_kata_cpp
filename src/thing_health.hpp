#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using thing_health = value_wrapper<new_type, unsigned, 1>;

} // namespace rpg_kata
