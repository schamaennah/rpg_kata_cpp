#pragma once

#include "new_type.hpp"
#include "non_negative_double.hpp"
#include "percentage.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
using damage = value_wrapper<new_type, non_negative_double, 0.>;

constexpr damage apply(const percentage& percentage, const damage& subject_damage)
{
    return {non_negative_double{(subject_damage.value.get() * percentage.value) / 100.}};
}

constexpr damage operator-(const damage& self, const percentage& percentage)
{
    return {non_negative_double{self.value.get() - apply(percentage, self).value.get()}};
}

constexpr damage operator+(const damage& self, const percentage& percentage)
{
    return {non_negative_double{self.value.get() + apply(percentage, self).value.get()}};
}

constexpr damage& operator+=(damage& self, const damage& other)
{
    self.value += other.value;
    return self;
}

constexpr damage operator+(const damage& self, const damage& other)
{
    return {self.value + other.value};
}

} // namespace rpg_kata
