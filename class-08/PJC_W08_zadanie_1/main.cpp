#include <iostream>
#include <fmt/ranges.h>

auto operator*(std::string const& text, int const& number) -> std::string {
    auto result = std::string();
    for(int i = 0; i < number; i++) {
        result += text;
    }
    return result;
}
auto operator*(int const& number, std::string const& text) -> std::string {
    return text * number;
}

auto main() -> int {
    auto text = std::string("string");

    fmt::println("{}", text * 3);
    fmt::println("{}", 3 * text);
}