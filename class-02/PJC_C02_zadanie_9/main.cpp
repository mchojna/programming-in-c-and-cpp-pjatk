#include<iostream>
#include<vector>
#include<fmt/ranges.h>

auto main() -> int {
    auto x = 13;
    fmt::println("{0}, {0}, {0}", x);

    fmt::println("The simplest C++ program is: \"auto main() -> int {{ }}\"");

    auto vec = std::vector<int>{1, 7, 1, 3, 7};
    fmt::println("{}\n${}$", vec, fmt::join(vec, " - "));

    fmt::println("{0}{1}{0}", '?', "I'm enclosed in question marks");

    fmt::println("{:.3}", 1.337);
    fmt::println("{0}\n{0:#b}\n{0:#x}\n{0:#o}", 10);

    fmt::println("{:#<20}", "Hello!");
    fmt::println("{:#>20}", "Hello!");
    fmt::println("{:#^20}", "Hello!");
}