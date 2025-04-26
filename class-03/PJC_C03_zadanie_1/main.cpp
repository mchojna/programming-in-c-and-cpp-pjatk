#include <iostream>
#include <vector>
#include <fmt/ranges.h>

int main()
{
    auto nums = std::vector<int>(10);

    for(auto& num: nums) {
        std::cin >> num;
    }

    fmt::println("{}", nums);

}
