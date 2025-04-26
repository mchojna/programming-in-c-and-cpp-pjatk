#include <iostream>
#include <fmt/ranges.h>

template <typename T, typename U, typename = std::enable_if_t<std::conjunction_v<std::is_arithmetic<T>, std::is_arithmetic<U>>>>
auto operator*(std::vector<T> const& v1, std::vector<U> const& v2) -> std::common_type_t<T, U>  {
    std::common_type_t<T, U> number = 0;

    if(v1.size() == v2.size()) {
        for(int i = 0; i < v1.size(); i++) {
            number += (v1[i] * v2[i]);
        }
    }

    return number;
}

auto main() -> int {
    auto v1 = std::vector<float>{1.1, 2.2, 3, 4.4, 5.5};
    auto v2 = std::vector<int>{6, 7, 8, 9, 10};
    fmt::println("{}", v1 * v2);
}