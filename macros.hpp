//
// Created by Peter Cong on 10/17/21.
//

#pragma once

#include <boost/hana.hpp>
#include <boost/preprocessor.hpp>

#ifndef FLAG_REGISTER_CUSTOM_FORMATTER
#define FLAG_REGISTER_FORMATTER fr::helper::format
#else
    #define FLAG_REGISTER_FORMATTER FLAG_REGISTER_CUSTOM_FORMATTER
#endif

#define FLAG_REGISTER_FORMAT_STRING(_1, _2, S) \
        (boost::hana::fold_left(BOOST_HANA_STRING(S), \
            boost::hana::string_c<>, \
            [](auto result, auto c) \
                {return result + boost::hana::string_c<FLAG_REGISTER_FORMATTER(c)>;}).c_str())
        /**/

#define FLAG_REGISTER_MAKE_REGISTRAR(...) \
        fr::helper::Registrar(fr::helper::make_register BOOST_PP_SEQ_TO_TUPLE( \
            BOOST_PP_SEQ_FOR_EACH(FLAG_REGISTER_FORMAT_STRING, _1, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))))
        /**/