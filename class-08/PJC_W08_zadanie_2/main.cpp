#include <iostream>
#include <fmt/ranges.h>

auto operator/(std::string const& text, int number) -> std::vector<std::string> {
    auto result = std::vector<std::string>();

    auto int size = text.size() / number;
    if(text.size() % number + text.size() / number >= number) {
        size += 1;
    }

    auto startIter = text.begin();

    while(number != 0) {
        if(number == 1) {
            result.emplace_back(startIter, text.end());
        } else if(startIter + size <= text.end()) {
            result.emplace_back(startIter, startIter + size);
        } else {
            result.emplace_back("");
        }

        startIter += size;
        number--;
    }

    return result;
}

auto main() -> int {
    auto const text = std::string("jakiesprzykladowedlugieslowo");
    for(auto i = 1; i <= text.size(); i++) {
        fmt::println("[{}]: {}", i, text / i);
    }
}
