#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using level = value_wrapper<new_type, unsigned, 1U>;

using level_diff = value_wrapper<new_type, signed>;

constexpr level_diff operator-(const level& lhs, const level& rhs)
{
    return level_diff{static_cast<level_diff::type>(lhs.value)
                      - static_cast<level_diff::type>(rhs.value)};
}

} // namespace rpg_kata
