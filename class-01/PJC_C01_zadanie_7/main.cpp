#include <iostream>
#include <vector>
#include <string>

auto boxPrint(std::vector<std::string> vec, char format = '*') {
    auto height = vec.size();
    auto width = 0;
    for(auto const element: vec) {
        if(element.size() > width) {
            width = element.size();
        }
    }

    height += 2;
    width += 2;

    for(auto i = 0; i < height; i++) {
        for(auto j = 0; j < width; j++) {
            if(i == 0 || j == 0 || i == height -1 || j == width - 1) {
                std::cout << format;
            } else if (vec[i - 1].size() > j - 1) {
                std::cout << vec[i - 1][j - 1];
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // for(auto i = -1; i < height; i++) {
    //     for(auto j = -1; j < width; j++) {
    //         if(i == -1 || j == -1 || i == height -2 || j == width - 2) {
    //             std::cout << format;
    //         } else if (vec[i].size() > j) {
    //             std::cout << vec[i][j];
    //         } else {
    //             std::cout << " ";
    //         }
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "\n";
}

auto main() -> int {
    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});
    boxPrint({"a", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}, '#');
}