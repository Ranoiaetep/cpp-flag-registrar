cmake_minimum_required(VERSION 3.20)
project(cpp_flag_registrar)

set(CMAKE_CXX_COMPILER "g++-11")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(cpp-static-map)

add_library(Flag_registrar INTERFACE Flag_registrar.hpp)
target_include_directories(Flag_registrar INTERFACE ./)
link_libraries(Flag_registrar)
#link_libraries(Static_map)
target_link_libraries(Flag_registrar INTERFACE Static_map)

add_executable(main main.cpp)

include(CTest)
include(CMakeDependentOption)
cmake_dependent_option(FLAG_REGISTRAR_BUILD_TESTS "Build Flag Registrar Tests" ON
        "BUILD_TESTING;CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR" OFF)
cmake_dependent_option(FLAG_REGISTRAR_BUILD_PACKAGE "Build Flag Registrar Packages" ON
        "CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    if (BUILD_TESTING)
        add_subdirectory(tests)
    endif ()
endif()
