#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using thing_health = value_wrapper<new_type, double, 1.>;

constexpr bool is_destroyed(const thing_health& self)
{
    return self == thing_health{0};
}

} // namespace rpg_kata
