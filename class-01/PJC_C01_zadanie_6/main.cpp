#include <iostream>
#include <vector>

auto sumOfTwo(std::vector<int> vec, int val) -> bool {

    for(auto i = 0; i < vec.size(); i++) {
        for(auto j = i + 1; j < vec.size(); j++) {
            if(vec[i] + vec[j] == val) {

                std::cout << "vec[" << i << "] + vec[" << j << "] = " << val;

                return true;
            }
        }
    }
    return false;
}

auto main() -> int {
    // auto vec = std::vector<int>{2, 4, 5, 8, 9, 11, 13, 16};
    auto vec = std::vector<int>{2, 4, 5, 8, 9, 11, 13, 15};
    sumOfTwo(vec, 21);
}