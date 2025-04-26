#include <iostream>
#include <fmt/ranges.h>

auto sortBiggerHalf(std::vector<int>& vec) -> void;

auto main() -> int {
    auto firstHalfBigger  = std::vector<int>{3, 2, 1, 0, 1, 0};
    auto secondHalfBigger = std::vector<int>{3, 2, 1, 6, 5, 4};
    auto bothHalvesSame   = std::vector<int>{5, 4, 5, 4};

    sortBiggerHalf(firstHalfBigger);
    sortBiggerHalf(secondHalfBigger);
    sortBiggerHalf(bothHalvesSame);

    fmt::println(
            "{}\n{}\n{}",
            firstHalfBigger,
            secondHalfBigger,
            bothHalvesSame
    );
}

auto sortBiggerHalf(std::vector<int>& vec) -> void {
    // auto firstHalf = std::vector<int>(vec.begin(), vec.begin() + vec.size() / 2);
    // auto secondHalf = std::vector<int>(vec.begin() + vec.size() / 2, vec.end());

    auto firstSum = 0;
    auto secondSum = 0;

    for(auto i = 0; i < vec.size() / 2; i++) {
        firstSum += vec[i];
    }

    for(auto i = vec.size() / 2; i < vec.size(); i++) {
        secondSum += vec[i];
    }

    if(firstSum >= secondSum) {
        std::ranges::sort(vec.begin(), vec.begin() + vec.size() / 2);
    }else {
        std::ranges::sort(vec.begin() + vec.size() / 2, vec.end());
    }
};
