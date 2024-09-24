#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using magical_object_health = value_wrapper<new_type, unsigned, 1U>;

} // namespace rpg_kata
