//
// Created by Peter Cong on 10/14/21.
//
#include <Flag_registrar.hpp>
#include <iostream>

int main()
{
    auto map = fr::Register("1", "2", "3");
    std::cout << map.size() << '\n';
    for(auto [a, b] : static_cast<decltype(map)::Data>(map))
    {
        std::cout << a << " : " << b << '\n';
    }
    std::cout << map["2"].value() << '\n';
    std::cout << map["3"].value() << '\n';
}