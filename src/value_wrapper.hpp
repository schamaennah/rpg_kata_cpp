#pragma once

namespace rpg_kata
{
template <typename tag_type, typename value_type = unsigned, auto initial_value = value_type{0}>
struct value_wrapper
{
    using type                          = value_type;
    static constexpr type initial_value = type{initial_value};

    type value = initial_value;

    auto operator<=>(const value_wrapper&) const = default;
};

} // namespace rpg_kata
