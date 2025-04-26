cmake_minimum_required(VERSION 3.29)
project(PJC_C10_zadanie_1)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(PJC_C10_zadanie_1 main.cpp)
target_link_libraries(PJC_C10_zadanie_1 sfml-graphics)

