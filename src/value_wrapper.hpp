#pragma once

namespace rpg_kata
{
template <typename tag_type, unsigned initial_value>
struct value_wrapper
{
    static constexpr unsigned initial_value = initial_value;

    unsigned value = initial_value;

    bool operator==(const value_wrapper&) const = default;
};

} // namespace rpg_kata
