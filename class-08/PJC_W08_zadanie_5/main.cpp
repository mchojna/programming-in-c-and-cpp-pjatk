#include <iostream>
#include <fmt/ranges.h>

#include <fmt/format.h>

struct Point {
    int x;
    int y;
};

struct Line {
    Point first;
    Point second;
};

auto operator||(Line const& l1, Line const&l2) -> bool {
    auto a1 = static_cast<double>(l1.second.y - l1.first.y) / static_cast<double>(l1.second.x - l1.first.x);
    auto a2 = static_cast<double>(l2.second.y - l2.first.y) / static_cast<double>(l2.second.x - l2.first.x);

    return a1 == a2;
}

auto main() -> int {
    auto l1 = Line{ {3, 1}, {5, 2} }; // aforementioned points
    auto l2 = Line{ {1, 2}, {7, 5} }; // aforementioned points

    fmt::println("{}", l1 || l2);

    auto l3 = Line{ {3, 1}, {5, 1} };
    auto l4 = Line{ {1, 7}, {-9, 7} };

    fmt::println("{}", l3 || l4);

    fmt::println("{}", l1 || l4);
}