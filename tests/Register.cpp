//
// Created by Peter Cong on 10/14/21.
//

#include <Flag_registrar.hpp>
#include <iostream>
#include <cassert>
#include <bitset>
#include <iomanip>

constexpr auto map = fr::Register(
        "0","1","2","3","4","5","6","7",
        "8","9","10","11","12","13","14","15",
        "16","17","18","19","20","21","22","23",
        "24","25","26","27","28","29","30","31");
static_assert(map.size() == 32);
static_assert(*map["0"] == fr::helper::pow(2, 0));
static_assert(*map["1"] == fr::helper::pow(2, 1));
static_assert(*map["2"] == fr::helper::pow(2, 2));
static_assert(*map["3"] == fr::helper::pow(2, 3));
static_assert(*map["4"] == fr::helper::pow(2, 4));
static_assert(*map["5"] == fr::helper::pow(2, 5));
static_assert(*map["6"] == fr::helper::pow(2, 6));
static_assert(*map["7"] == fr::helper::pow(2, 7));
static_assert(*map["15"] == fr::helper::pow(2, 15));

int main() {
    for([[maybe_unused]] std::uintmax_t flag_exp = 0; auto& [key, value] : map)
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