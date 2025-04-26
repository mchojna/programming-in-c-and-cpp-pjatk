cmake_minimum_required(VERSION 3.29)
project(PJC_C07_zadanie_1)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         11.0.2
)

FetchContent_MakeAvailable(fmt)

add_executable(PJC_C07_zadanie_1 main.cpp)
target_link_libraries(PJC_C07_zadanie_1 fmt)