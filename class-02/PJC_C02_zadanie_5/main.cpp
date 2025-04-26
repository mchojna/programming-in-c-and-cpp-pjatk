#include <iostream>
#include <fmt/ranges.h>
#include <algorithm>

auto isPalindrome(std::string) -> bool;

auto main() -> int {
    fmt::print(
        "{}\n{}\n{}",
        isPalindrome("Kajak"),
        isPalindrome("ala"),
        isPalindrome("programowanie")
    );
}

auto isPalindrome(std::string str) -> bool {
    auto copy = str;
    std::ranges::reverse(copy);

    if(str == copy) {
        return true;
    }else {
        return false;
    }
}