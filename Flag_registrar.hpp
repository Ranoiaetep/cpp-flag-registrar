//
// Created by Peter Cong on 10/13/21.
//

#pragma once

#include <Static_map.hpp>
#include <concepts>
#include <string_view>
#include "helper.hpp"

namespace fr
{
    constexpr auto Register(std::convertible_to<std::string_view> auto ... flags);
} // namespace fr

[[maybe_unused]] constexpr auto fr::Register(std::convertible_to<std::string_view> auto ... flags)
{
    return helper::register_helper(
            helper::Binary_sequence<sizeof...(flags)>{},
            static_cast<std::string_view>(flags)...);
}