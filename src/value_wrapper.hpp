#pragma once

#include <compare>

namespace rpg_kata
{
template <typename tag_type,
          typename value_type      = unsigned,
          value_type initial_value = value_type{0}>
struct value_wrapper
{
    using type                          = value_type;
    static constexpr type initial_value = initial_value;

    type value = initial_value;

    std::partial_ordering operator<=>(const value_wrapper&) const = default;
};

} // namespace rpg_kata
