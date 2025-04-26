#include<iostream>
#include<vector>
#include<fmt/ranges.h>

auto dotProduct(std::vector<int> const& vec1, std::vector<int> const& vec2) -> int;

auto main() -> int {
    auto result = dotProduct(
        {1,2,3,4,5},
        {1,2,3,4,5}
        );

    fmt::print("{}", result);
}

auto dotProduct(std::vector<int> const &vec1, std::vector<int> const &vec2) -> int {
    auto result = 0;

    for(int i = 0; i < vec1.size(); i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}
