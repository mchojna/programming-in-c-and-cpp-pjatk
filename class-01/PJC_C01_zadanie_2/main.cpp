#include<iostream>
#include<algorithm>
auto main() -> int {
    auto text = std::string();

    std::cin >> text;

    std::cout << text[0] << "\n";
    // std::cout << text.front() << "\n";
    std::cout << "'" << text[text.size()-1] << "'\n";
    // std::cout << "'" << text.back() << "'\n";
    std::cout << text.size() << "\n";
    std::cout << "\"" << text[text.size() / 2] << "\"\n";
    std::cout << "[" << text << "]\n";
    std::ranges::sort(text);
    std::cout << text;
}