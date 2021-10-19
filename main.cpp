//
// Created by Peter Cong on 10/14/21.
//
#include <iostream>
#include <Flag_registrar.hpp>

using namespace fr::literals;

int main()
{
    MAKE_REGISTRAR(foo, "ok");
    constexpr auto reg1 = fr::make_registrar<"hel lo_12-?//\\[KK", "ok", "sure">();
    constexpr auto reg2 = fr::make_registrar_k("hel lo_12-?//\\[KK"_k, "ok"_k, "sure"_k);
    for(const auto& [key, value] : reg1)
    {
        std::cout << key << " : ";
        for(int c : key)
        {
            std::cout << c << ".";
        }
        std::cout << " : " << value << '\n';
    }
    for(const auto& [key, value] : reg2)
    {
        std::cout << key << " : ";
        for(int c : key)
        {
            std::cout << c << ".";
        }
        std::cout << " : " << value << '\n';
    }
    auto s = "ok"_k;
    for(int c : s)
    {
        std::cout << c << ".";
    }
    std::cout << reg2["ok"_k];
}