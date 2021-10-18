//
// Created by Peter Cong on 10/14/21.
//

#include <Flag_registrar.hpp>
#include <iostream>
#include <cassert>
#include <bitset>
#include <iomanip>

constexpr auto map = MAKE_REGISTER(
        "hello", "I'm fine", "Ok", "\\??", "12345", "zZz 123");

static_assert(map.size() == 6);
static_assert(map["HELLO"] == fr::helper::pow(2, 0));
static_assert(map["I?M_FINE"] == fr::helper::pow(2, 1));
static_assert(map["OK"] == fr::helper::pow(2, 2));
static_assert(map["???"] == fr::helper::pow(2, 3));
static_assert(map["12345"] == fr::helper::pow(2, 4));
static_assert(map["ZZZ_123"] == fr::helper::pow(2, 5));

int main() {
#pragma unroll 5
    for([[maybe_unused]] std::uintmax_t flag_exp = 0; const auto& [key, value] : map)
    {
#if debug
        assert(value == fr::helper::pow(2, flag_exp++));
#endif
        std::cout << std::setfill('0') << std::setw(2) << key;
        std::cout << " is mapped to 0x";
        std::cout << std::hex << std::setfill('0') << std::setw(8) << value;
        std::cout << std::dec << '\n';
    }
}