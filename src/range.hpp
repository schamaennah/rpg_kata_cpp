#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

#include <limits>

namespace rpg_kata
{
using range = value_wrapper<new_type, double, std::numeric_limits<double>::max()>;

constexpr auto melee = range{2};
}
