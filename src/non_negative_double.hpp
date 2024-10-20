#pragma once

#include <algorithm>

namespace rpg_kata
{
class non_negative_double
{
public:
    constexpr explicit non_negative_double(const double value = 0.0)
        : value{value < 0.0 ? 0.0 : value}
    {}

    constexpr auto operator<=>(const non_negative_double&) const = default;

    constexpr double get() const
    {
        return value;
    }

    constexpr non_negative_double& operator-=(const non_negative_double other)
    {
        value -= std::min(value, other.value);
        return *this;
    }

    constexpr non_negative_double operator+(const unsigned other) const
    {
        return non_negative_double{value + other};
    }

    constexpr non_negative_double& operator+=(const non_negative_double other)
    {
        value += other.value;
        return *this;
    }

private:
    double value;
};

} // namespace rpg_kata
