#pragma once

#include "new_type.hpp"
#include "value_wrapper.hpp"

namespace rpg_kata
{
class magical_object_health
{
private:
    using primitive_type = unsigned;
    using type           = value_wrapper<new_type>;

public:
    explicit constexpr magical_object_health(const primitive_type max_health)
        : current_health{max_health}
        , max_health{max_health}
    {}

private:
    type current_health;
    type max_health;
};

} // namespace rpg_kata
