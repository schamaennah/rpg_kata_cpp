#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using health = value_wrapper<new_type, 1000U>;

} // namespace rpg_kata
