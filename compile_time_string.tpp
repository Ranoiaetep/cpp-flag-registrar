//
// Created by Peter Cong on 10/18/21.
//

#pragma once

#include <cstdint>
#include <utility>
#include <array>
#include <string_view>

#ifndef FLAG_REGISTER_CUSTOM_FORMATTER
#define FLAG_REGISTER_FORMATTER Compile_time_string<N>::format
#endif

namespace fr::helper
{
    template<std::size_t N>
    constexpr Compile_time_string<N>::Compile_time_string(const char (&str)[N])
            : _str(char_arr_to_arr(str, std::make_index_sequence<N - 1>{}))
    {}

    template<std::size_t N>
    template<auto ... Ns>
    constexpr auto
    Compile_time_string<N>::char_arr_to_arr(const char (&str)[N], std::index_sequence<Ns ...>)
    {
        return std::array{FLAG_REGISTER_FORMATTER(str[Ns])..., '\0'};
    }

    template<std::size_t N>
    constexpr Compile_time_string<N>::operator std::string_view() const
    {
        return std::string_view(_str.begin(), _str.end());
    }
}