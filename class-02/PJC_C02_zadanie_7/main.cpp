#include <iostream>
#include <fmt/ranges.h>
#include <vector>
#include <algorithm>

auto remove(std::vector<std::string>& vec) -> void;

auto main() -> int{
    auto vec = std::vector<std::string>{"Adam", "Illia", "Ewa", "Anastasia", "Illia", "Ewa", "Illia", "Maciej", "Adam", "Natalia"};
    remove(vec);

    fmt::print("{}", vec);
}

auto remove(std::vector<std::string>& vec) -> void {
    std::ranges::sort(vec);
    auto iter = std::ranges::unique(vec);
    vec.erase(iter.begin(), iter.end());
}
