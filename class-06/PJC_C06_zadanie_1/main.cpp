#include <iostream>
#include <fstream>
#include <fmt/ranges.h>

auto checkNumberOfNumbers(std::string fname) -> void {
    auto file = std::fstream(fname);
    auto word = std::string();
    auto numberOfNumbers = 0;
    while(file >> word) {
        auto check = true;
        for(auto iter = word.begin(); iter != word.end(); ++iter) {
            if(!isnumber(*iter)) {
                check = false;
            }
        }
        if(check) {
            ++numberOfNumbers;
            fmt::print("{} ", word);
        }
    }
    fmt::println("\nnumber of numbers: {}", numberOfNumbers);
}

auto main() -> int {
    checkNumberOfNumbers("/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_1/sampleFile.txt");

}