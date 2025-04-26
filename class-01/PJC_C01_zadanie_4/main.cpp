#include <iostream>
#include <vector>

auto addElement1(std::vector<int> vector) {
    vector.push_back(10);
}

auto addElement2(std::vector<int> &vector) {
    vector.push_back(10);
}

auto main() -> int {
    auto ints = std::vector<int>();
    std::cout << ints.size() << "\n";
    addElement1(ints);
    std::cout << ints.size() << "\n";
    addElement2(ints);
    std::cout << ints.size() << "\n";
}