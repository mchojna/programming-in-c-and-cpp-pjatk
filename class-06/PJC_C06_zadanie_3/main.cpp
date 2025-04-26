#include <iostream>
#include <fstream>
#include <fmt/ranges.h>

auto replace(std::fstream& file, const std::string& replacement) -> void {
    auto text = std::string();
    auto line = std::string();

    auto element = std::string();
    char c = ' ';

    while(file.get(c)) {
        text += c;
    }

    // auto result = std::string();
    // auto word = std::string();
    // for(int i = 0; i < text.size(); i++) {
    //     if (isnumber(text[i])) {
    //         result += text[i];
    //
    //         result += word;
    //
    //         word = "";
    //     } else {
    //         word += text[i];
    //     }
    // }

    // fmt::println("{}", result);

    // while(file >> element) {
    //     auto isNumber = true;
    //     for(char& iter : element) {
    //         if(!isnumber(iter)) {
    //             isNumber = false;
    //         }
    //     }
    //     if(isNumber) {
    //         element = text;
    //     }
    //     textToWrite += element;
    //     textToWrite += " ";
    // }
    // fmt::println("{}", textToWrite);
}

auto main() -> int {
    auto file = std::fstream("/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_3/cmake-build-debug/sampleFile.txt");
    replace(file, "hello");
}