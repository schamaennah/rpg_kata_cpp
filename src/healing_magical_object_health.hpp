#pragma once

#include "healing.hpp"
#include "value_wrapper.hpp"

#include <algorithm>

namespace rpg_kata
{
class healing_magical_object_health
{
public:
    using type = value_wrapper<>;

    explicit constexpr healing_magical_object_health(const type::type max_health)
        : current_health{max_health}
        , max_health{max_health}
    {}

    constexpr bool is_destroyed() const
    {
        return current_health == type{0};
    }

    constexpr healing syphon_up_to(const healing upper_bound)
    {
        const auto syphoned_health = std::min(current_health.value, upper_bound.value);
        current_health.value -= syphoned_health;
        return healing{syphoned_health};
    }

    constexpr const type& current() const
    {
        return current_health;
    }

private:
    type current_health;
    type max_health;
};

} // namespace rpg_kata
