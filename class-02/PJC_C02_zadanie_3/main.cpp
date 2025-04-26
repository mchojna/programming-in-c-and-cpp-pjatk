#include<iostream>
#include<fmt/ranges.h>

auto show(std::vector<int> const& vec, int num) -> void;

auto main() -> int {
    auto vec = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    show(vec, 1);
    show(vec, 2);
    show(vec, 3);
    show(vec, 4);
    show(vec, 5);
}

auto show(std::vector<int> const& vec, int num) -> void {
    for(auto iter = vec.begin();
        iter < vec.end();
        iter += num
        ) {
        fmt::print("{} ", *iter);
    }
    fmt::println("\n");
}