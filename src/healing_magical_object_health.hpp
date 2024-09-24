#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
class healing_magical_object_health
{
private:
    using primitive_type = unsigned;

public:
    using type           = value_wrapper<new_type>;

    explicit constexpr healing_magical_object_health(const primitive_type max_health)
        : current_health{max_health}
        , max_health{max_health}
    {}

    constexpr bool is_destroyed() const
    {
        return current_health == type{0};
    }

    constexpr healing_magical_object_health& operator--()
    {
        --current_health.value;
        return *this;
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
