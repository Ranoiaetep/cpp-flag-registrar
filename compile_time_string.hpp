//
// Created by Peter Cong on 10/18/21.
//

#pragma once

#include <cstdint>
#include <utility>
#include <string_view>
#include <array>

namespace fr::helper
{
    template<std::size_t N>
    struct Compile_time_string
    {
        using Size [[maybe_unused]] = std::integral_constant<int, N>;

        constexpr explicit(false) Compile_time_string(const char (&str)[N]);

        template<auto ... Ns>
        static constexpr auto char_arr_to_arr(const char (&str)[N], std::index_sequence<Ns ...>);

        constexpr explicit(false) operator std::string_view() const;

        std::array<char, N> _str;

        static constexpr auto format = [](char c)
        {
            if (c >= 'a' && c <= 'z')
                return static_cast<char>(c - 32);
            if (c == ' ' || c == '-' || c == '_')
                return '_';
            if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9'))
                return '?';
            return c;
        };
    };
} // namespace fr::helper

#include "compile_time_string.tpp"