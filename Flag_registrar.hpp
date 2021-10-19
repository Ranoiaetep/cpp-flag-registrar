//
// Created by Peter Cong on 10/13/21.
//

#pragma once

#include "helper.hpp"
#include "compile_time_string.hpp"
#include <array>
#include <string_view>

#ifndef MAKE_REGISTRAR
#define MAKE_REGISTRAR(...) make_registrar<__VA_ARGS__>()
#endif

namespace fr
{
    template<helper::Compile_time_string ... str>
    constexpr auto make_registrar();

    constexpr auto make_registrar_k(std::same_as<std::string_view> auto ... str);

    namespace literals
    {
        template<fr::helper::Compile_time_string S>
        constexpr auto operator "" _k();
    }
}

#include "Flag_registrar.tpp"