#include <iostream>
#include <fmt/ranges.h>

template <typename T>
struct VectorAdder {
    std::vector<T>& destination;
};

template <typename T>
auto operator+=(std::vector<T>& vec, T const& num) -> VectorAdder<T> {
    vec.push_back(num);
    return VectorAdder<T>(vec);
}

template <typename T>
auto operator,(VectorAdder<T> adder, T const& num) -> VectorAdder<T> {
    adder.destination.push_back(num);
    return adder;
}

template <typename T>
struct VectorSubtracter {
    std::vector<T>& destination;
};

template<typename T>
auto operator-=(std::vector<T>& vec, int const& num) -> VectorSubtracter<T> {
    auto iter = std::ranges::find(vec, num);
    if(iter != vec.end()) {
        vec.erase(iter);
    }

    return VectorSubtracter<T>(vec);
}

template<typename T>
auto operator,(VectorSubtracter<T> subtracter, T const& num) -> VectorSubtracter<T> {
    auto iter = std::ranges::find(subtracter.destination, num);
    if(iter != subtracter.destination.end()) {
        subtracter.destination.erase(iter);
    }

    return subtracter;
}


auto main() -> int {
    auto vec = std::vector<int>();

    fmt::println("{}", vec);

    vec += 2, 1, 3, 7;

    fmt::println("{}", vec);

    vec -= 2, 3, 4, 5;

    fmt::println("{}", vec);
}