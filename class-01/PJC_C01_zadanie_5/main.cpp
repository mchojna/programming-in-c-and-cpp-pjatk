#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    auto vec = std::vector<int>();

    while(vec.size() < 10) {
        auto number = 0;
        std::cin >> number;
        vec.push_back(number);
    }

    auto iter = vec.begin();
    auto vec1 = std::vector<int>(iter, iter+5);
    auto vec2 = std::vector<int>(iter+5, iter+10);

    std::ranges::sort(vec1);
    std::ranges::sort(vec2);

    if(std::ranges::equal(vec1, vec2)) {
        std::cout << "True";
    }else {
        std::cout << "False";
    }
}