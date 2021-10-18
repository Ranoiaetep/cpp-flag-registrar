//
// Created by Peter Cong on 10/14/21.
//
#include <iostream>
#include <Flag_registrar.hpp>

int main()
{
    constexpr auto reg = MAKE_REGISTER("hel lo_12-?//\\[KK", "ok", "sure");
    for(const auto& [key, value] : reg)
    {
        std::cout << key << " : " << value << '\n';
    }
}