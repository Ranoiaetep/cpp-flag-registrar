//
// Created by Peter Cong on 10/14/21.
//

#include <Flag_registrar.hpp>
#include <iostream>
#include <cassert>
#include <bitset>
#include <iomanip>

constexpr auto map1 = fr::MAKE_REGISTRAR(
        "hello", "I'm fine", "Ok", "\\??", "12345", "zZz 123");

static_assert(map1.size() == 6);
static_assert(map1["HELLO"] == fr::helper::pow(2, 0));
static_assert(map1["I?M_FINE"] == fr::helper::pow(2, 1));
static_assert(map1["OK"] == fr::helper::pow(2, 2));
static_assert(map1["???"] == fr::helper::pow(2, 3));
static_assert(map1["12345"] == fr::helper::pow(2, 4));
static_assert(map1["ZZZ_123"] == fr::helper::pow(2, 5));
static_assert(map1("HELLO", "12345", "ZZZ_123") == (1 | 16 | 32));
static_assert(map1("HELLO") == (1));
static_assert(map1() == (0));
//static_assert(map1("NOT THERE"));

using namespace fr::literals;

constexpr auto map2 = fr::make_registrar_k(
        "hello"_k, "I'm fine"_k, "Ok"_k, "\\??"_k, "12345"_k, "zZz 123"_k);

static_assert(map2.size() == 6);
static_assert(map2["HELLO"] == fr::helper::pow(2, 0));
static_assert(map2["hello"_k] == fr::helper::pow(2, 0));
static_assert(map2["I?M_FINE"] == fr::helper::pow(2, 1));
static_assert(map2["I'm fine"_k] == fr::helper::pow(2, 1));
static_assert(map2("hello"_k, "12345"_k, "zzz 123"_k) == (1 | 16 | 32));
static_assert(map2("hello"_k) == (1));
static_assert(map2() == (0));
//static_assert(map2("NOT THERE"));

int main() {
#pragma unroll 5
    for([[maybe_unused]] std::uintmax_t flag_exp = 0; const auto& [key, value] : map1)
    {
#if debug
        assert(_str == fr::helper::pow(2, flag_exp++));
#endif
        std::cout << std::setfill('0') << std::setw(2) << key;
        std::cout << " is mapped to 0x";
        std::cout << std::hex << std::setfill('0') << std::setw(8) << value;
        std::cout << std::dec << '\n';
    }
    try
    {
        map1("SOMETHING NOT THERE");
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "\"SOMETHING NOT THERE\" was not found, because " << e.what();
    }
}