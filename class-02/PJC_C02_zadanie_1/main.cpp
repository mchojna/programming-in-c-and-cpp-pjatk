#include <iostream>
#include <vector>
#include <fmt/ranges.h>
#include <algorithm>

auto main() -> int {
    auto vec = std::vector<int>();

    while(vec.size() < 7) {
        auto number = 0;
        std::cin >> number;
        vec.push_back(number);
    }

    fmt::print("{}\n", vec);

    std::ranges::sort(vec);
    vec.erase(vec.begin(), vec.begin() + 1);
    vec.erase(vec.end()-1, vec.end());

    fmt::print("{}", vec);
}