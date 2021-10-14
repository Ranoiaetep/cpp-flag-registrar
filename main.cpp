//
// Created by Peter Cong on 10/14/21.
//
#include <Flag_registrar.hpp>
#include <iostream>

int main()
{
    constexpr auto map = fr::Register("1", "2", "3");
    std::cout << map.size() << '\n';
    for(auto [a, b] : map)
    {
        std::cout << a << " : " << b << '\n';
    }
    std::cout << map.at_or_default("5") << '\n';
    std::cout << map["3"].value() << '\n';
}