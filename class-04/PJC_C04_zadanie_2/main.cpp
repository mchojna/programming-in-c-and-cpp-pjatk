#include <iostream>
#include <fmt/ranges.h>
#include <vector>
#include <string>
#include <ranges>

template <typename Argument, typename Function>
auto mapped(std::vector<Argument> const input, Function transform) -> std::vector<std::invoke_result_t<Function, Argument>> {
    auto output = std::vector<std::invoke_result_t<Function, Argument>>(input.size());

    for(int i = 0; i < input.size(); i++) {
        output[i] = transform(input[i]);
    }

    return output;
}

auto main() -> int {
    auto strings = std::vector<std::string>{"abc", "defghi", "jk", "lmno"};
    auto chars = mapped(
            strings,
            [](std::string s) { return s.front(); }
    );
    auto sizes = mapped(
            strings,
            [](std::string s) { return s.size(); }
    );

    fmt::println("{}", chars);
    fmt::println("{}", sizes);
}