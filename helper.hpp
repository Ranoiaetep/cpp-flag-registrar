//
// Created by Peter Cong on 10/14/21.
//

#pragma once

#include <cstdint>
#include <concepts>
#include <utility>
#include <string_view>
#include <Static_map.hpp>

namespace fr::helper
{
    constexpr std::uintmax_t pow(std::integral auto base, std::integral auto exponent);

    template<auto ... ints>
    constexpr auto make_binary_sequence_helper(std::integer_sequence<std::uintmax_t, ints...> /*unused*/);

    template<std::size_t N>
    constexpr auto make_binary_sequence();

    template<typename ... Flags, auto ... ints>
    constexpr auto register_helper(std::integer_sequence<std::uintmax_t, ints...> /*unused*/, Flags ... flags);

    constexpr auto make_register(std::convertible_to<std::string_view> auto ... flags);

    template<std::size_t N>
    struct Registrar : sm::Static_map<std::string_view, std::uintmax_t, N>
    {
        constexpr explicit Registrar(sm::Static_map<std::string_view, std::uintmax_t, N> sm)
        : sm::Static_map<std::string_view, std::uintmax_t, N>(sm)
        {}

        constexpr std::uintmax_t operator()(auto && ... sv) const
        {
            if constexpr(sizeof...(sv) > 0)
                return ((0 | sm::Static_map<std::string_view, std::uintmax_t, N>::operator[](decltype(sv)(sv))) | ...);
            else
                return 0;
        }
    };
} // namespace fr::helper

constexpr std::uintmax_t fr::helper::pow(std::integral auto base, std::integral auto exponent)
{
    return exponent < 1 ? 1 : base * pow(base, exponent - 1);
}

template<auto ... ints>
constexpr auto fr::helper::make_binary_sequence_helper(std::integer_sequence<std::uintmax_t, ints...> /*unused*/)
{
    return std::integer_sequence<std::uintmax_t, pow(2, ints)...>{};
}

template<std::size_t N>
constexpr auto fr::helper::make_binary_sequence()
{
    return make_binary_sequence_helper(std::make_integer_sequence<std::uintmax_t, N>{});
}

namespace fr::helper
{
    template<std::size_t N>
    using Binary_sequence = decltype(make_binary_sequence<N>());
}

template<typename ... Flags, auto ... ints>
constexpr auto fr::helper::register_helper(std::integer_sequence<std::uintmax_t, ints...> /*unused*/, Flags ... flags)
{
    using Result = sm::Static_map<std::string_view, std::uintmax_t, sizeof...(Flags)>;
    return Result(typename Result::Data{std::pair{flags, ints}...});
}

constexpr auto fr::helper::make_register(std::convertible_to<std::string_view> auto ... flags)
{
    return helper::register_helper(helper::make_binary_sequence<sizeof...(flags)>(), static_cast<std::string_view>(flags)...);
}