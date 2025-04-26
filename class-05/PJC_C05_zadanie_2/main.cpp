#include <iostream>
#include <map>
#include <set>
#include <fmt/ranges.h>

auto main() -> int {
    auto words = std::map<int, std::set<std::string>>();

    for(auto word = std::string(); std::cin >> word && word != "stop"; ) {
        words[word.size()].insert(word);
    }

    for(auto [key, value]: words) {
        fmt::println("{} - {}", key, fmt::join(value, " "));
    }
}