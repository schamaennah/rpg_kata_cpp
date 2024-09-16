#pragma once

namespace rpg_kata
{
struct health
{
    unsigned value = 1000;

    bool operator==(const health&) const& = default;
};

} // namespace rpg_kata
