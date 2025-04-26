#include <iostream>
#include <fmt/ranges.h>
#include <algorithm>

auto reversedWords(std::string str) -> std::string;

auto main() -> int {

    fmt::println(
            "{}\n{}\n{}\n{}",
            reversedWords("Ala ma kota"),
            reversedWords("Ala"),
            reversedWords(""),
            reversedWords("1 2 3")
    );
}

auto reversedWords(std::string str) -> std::string {

    auto text = std::string(""); // niepotrzebne ""

    auto vec = std::vector<std::string>();

    for(int i = 0; i < str.size(); i++) {
        if(str[i] != ' ') {
            text.insert(text.end(), str[i]); // text += str[i]
        } else {
            vec.insert(vec.end(), text);
            text = std::string("");

            vec.insert(vec.end(), " ");
        }
    }
    vec.insert(vec.end(), text);

    std::ranges::reverse(vec);

    auto result = std::string("");

    for(int i = 0; i < vec.size(); i++) {
        result.append(vec[i]);
    }

    return result;
}