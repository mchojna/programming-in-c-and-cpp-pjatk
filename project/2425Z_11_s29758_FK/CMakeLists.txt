cmake_minimum_required(VERSION 3.29)
project(2425Z_11_s29785_FK)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         11.0.2
)

FetchContent_MakeAvailable(fmt)

add_executable(2425Z_11_s29785_FK main.cpp
        db/db.cpp
        db/db.hpp)
target_link_libraries(2425Z_11_s29785_FK fmt)