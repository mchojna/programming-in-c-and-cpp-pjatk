#include <iostream>
#include <filesystem>
#include <fmt/ranges.h>

#include "fmt/os.h"

auto main() -> int {
    auto fileName = std::string();
    std::getline(std::cin, fileName);
    auto path = std::filesystem::path(fileName);

    // 1
    auto counter = 0;
    for(auto const& entry: std::filesystem::directory_iterator(path)) {
        counter += 1;
    }
    fmt::println("{}", counter);

    // 2



    // 3

}
