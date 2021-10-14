//
// Created by Peter Cong on 10/13/21.
//

#pragma once

#include <Static_map.hpp>
#include <utility>
#include <type_traits>
#include <concepts>

namespace fr
{
    namespace helper
    {
        consteval std::uintmax_t pow(std::integral auto base, std::integral auto exponent)
        {
            if (exponent >= 1)
            {
                return base * pow(base, exponent - 1);
            } else
            {
                return 1;
            }
        }

        template<auto ... ints>
        constexpr auto make_binary_sequence_helper(std::integer_sequence<std::uintmax_t, ints...>)
        {
            return std::integer_sequence<std::uintmax_t, pow(2, ints)...>{};
        }

        template<std::size_t N>
        constexpr auto make_binary_sequence()
        {
            return make_binary_sequence_helper(std::make_integer_sequence<std::uintmax_t, N>{});
        }

        template<std::size_t N>
        using binary_sequence = decltype(make_binary_sequence<N>());

        static_assert(
                std::is_same_v<binary_sequence<5>, std::integer_sequence<std::uintmax_t, 0b1, 0b10, 0b100, 0b1000, 0b10000>>);

        template<typename ... Flags, auto ... ints>
        constexpr auto Register_helper(std::integer_sequence<std::uintmax_t, ints...>, Flags ... flags)
        {
            using result = sm::Static_map<std::string_view, std::uintmax_t, sizeof...(Flags)>;
            return result(typename result::Data{std::pair{flags, ints}...});
        }
    }

//    template<typename ... Flags>
    constexpr auto Register(auto ... flags)
    {
        return helper::Register_helper(helper::binary_sequence<sizeof...(flags)>{}, static_cast<std::string_view>(flags)...);
    }
}