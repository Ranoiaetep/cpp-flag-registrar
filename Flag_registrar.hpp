//
// Created by Peter Cong on 10/13/21.
//

#pragma once

#include "helper.hpp"
#include "macros.hpp"

#ifndef MAKE_REGISTER
#define MAKE_REGISTER(...) FLAG_REGISTER_MAKE_REGISTER(__VA_ARGS__)
#endif