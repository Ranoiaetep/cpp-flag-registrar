//
// Created by Peter Cong on 10/13/21.
//

#pragma once

#include "helper.hpp"
#include "macros.hpp"

#ifndef MAKE_REGISTRAR
#define MAKE_REGISTRAR(...) FLAG_REGISTER_MAKE_REGISTRAR(__VA_ARGS__)
#endif