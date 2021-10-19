//
// Created by Peter Cong on 10/18/21.
//

#pragma once

namespace fr
{
    template<helper::Compile_time_string ... str>
    constexpr auto make_registrar()
    {
        return helper::Registrar(
                helper::register_helper(
                        helper::make_binary_sequence<sizeof...(str)>(), static_cast<std::string_view>(str).substr(0,
                                                                                                                  typename decltype(str)::Size() - 1) ...));
    }

    constexpr auto make_registrar_k(std::same_as<std::string_view> auto ... str)
    {
        return helper::Registrar(
                helper::register_helper(
                        helper::make_binary_sequence<sizeof...(str)>(), str ...));
    }

    namespace literals
    {
        template<fr::helper::Compile_time_string S>
        constexpr auto operator "" _k()
        {
            return std::string_view(S._str.begin());
        }
    }
}