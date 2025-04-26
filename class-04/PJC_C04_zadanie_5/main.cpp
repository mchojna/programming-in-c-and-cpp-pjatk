#include <iostream>
#include <set>
#include <fmt/base.h>
#include <fmt/ranges.h>

template<std::ranges::range T>
auto chunk(T input, int n) -> std::vector<T> {
    auto length = 0;
    for(int i = 0; i < input.size(); i+=n) {
        length += 1;
    }

    auto output = std::vector<T>(length);
    auto iter = output.begin();

    for(int i = 0; i < input.size(); i++) {
        if(input.size() - n > n) {

        }


        for(int j = 0; j < output.size(); j++) {

        }


        *iter = {1, 2, 3};
        ++iter;
    }


    return output;
}

auto main() -> int {
    auto v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // auto v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};
    auto v3 = std::set<float>{1.41, 1.61, 1.73, 2.72, 3.14};

    auto v1by3 = chunk(v1, 3);
    auto v1by2 = chunk(v1, 2);

    // auto v2by5 = chunk(v2, 5);
    // auto v2by1 = chunk(v2, 1);

    // auto v3by2 = chunk(v3, 2);
    // auto v3by3 = chunk(v3, 3);

    fmt::println("{}", v1by3);
    fmt::println("{}", v1by2);
    // fmt::println("{}", v2by5);
    // fmt::println("{}", v2by1);
    // fmt::println("{}", v3by2);
    // fmt::println("{}", v3by3);
}