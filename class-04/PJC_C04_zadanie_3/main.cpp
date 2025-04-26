#include <iostream>
#include <fmt/ranges.h>


template <typename Function>
auto chunkedApply(std::vector<int>, Function function) -> void{

}

auto main() -> int {
    auto const ofSize5 = std::vector<int>{1, 2, 3, 4, 5};
    auto const ofSize7 = std::vector<int>{1, 2, 3, 4, 5, 6, 7};

    chunkedApply(ofSize5, [](int const a, int const b) {fmt::print("[{} {}]", a, b);});

    fmt::println("");

    chunkedApply(ofSize7, [](int const a, int const b, int const c) {
        fmt::print("[{} {} {}]", a, b, c);
    });

    auto const ofSize8 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8};

    chunkedApply(ofSize8, [](int const a, int const b, int const c) {
        fmt::print("[{} {} {}]", a, b, c);
    });
}
