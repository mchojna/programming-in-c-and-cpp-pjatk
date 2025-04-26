#include <iostream>
#include "fmt/base.h"

auto reduceAdjacentWhitespaces(std::string str) -> std::string  {
    std::ranges::replace_if(str, []())
}

int main() {
    fmt::println(
        "[{}]\n[{}]\n[{}]\n[{}]",
        reduceAdjacentWhitespaces("Abc"),
        reduceAdjacentWhitespaces("A b c"),
        reduceAdjacentWhitespaces("   A\tb c      "),
        reduceAdjacentWhitespaces("A\t\tb\n \n  \t c")
    );
}
