#include <iostream>
#include <fstream>
#include <filesystem>
#include <fmt/ranges.h>
#include <fmt/std.h>

auto check_unique(std::vector<std::string> const& source) -> bool {
    auto copy = source;
    std::ranges::sort(copy);
    auto [b, e] = std::ranges::unique(copy);
    copy.erase(b, e);

    if(!std::ranges::is_permutation(source, copy)) {
        return false;
    }
    return true;
}

auto check_sudoku(std::string path) -> bool {
    auto sudoku = std::fstream(path);
    auto matrix = std::vector<std::vector<std::string>>(9);
    auto element = std::string();
    auto i = 0;
    auto j = 0;

    while(sudoku >> element) {
        matrix[i].push_back(element);
        if(++j == 9) {
            i++;
            j = 0;
        }
    }

    for(auto const& row: matrix) {
        if(!check_unique(row)) {
            return false;
        }
    }

    for(int i = 0; i < 9; i++) {
        auto column = std::vector<std::string>();
        for(int j = 0; j < 9; j++) {
            column.push_back(matrix[j][i]);
        }
        if(!check_unique(column)) {
            return false;
        }
    }

    auto rec1 = std::vector<std::string>();
    auto rec2 = std::vector<std::string>();
    auto rec3 = std::vector<std::string>();

    i = 0;
    for(auto const& element: matrix) {
        auto iter = element.begin();
        rec1.insert(rec1.end(), iter, iter + 3);
        rec2.insert(rec2.end(), iter + 3, iter + 6);
        rec3.insert(rec3.end(), iter + 6, iter + 9);
        if(++i == 3) {
            if(!check_unique(rec1)) {
                return false;
            }
            if(!check_unique(rec2)) {
                return false;
            }
            if(!check_unique(rec3)) {
                return false;
            }

            rec1 = std::vector<std::string>();
            rec2 = std::vector<std::string>();
            rec3 = std::vector<std::string>();
            i = 0;
        }
    }

    return true;
}

auto main() -> int {
    auto const path = std::filesystem::path("/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJc_C06_zadanie_2/sudoku");
    for(auto const& entry: std::filesystem::directory_iterator(path)) {
        fmt::println("{}", check_sudoku(entry.path()));
    }
}
