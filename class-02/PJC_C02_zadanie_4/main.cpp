#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<fmt/ranges.h>

auto suffix(std::set<int> const&, std::vector<int> const&) -> bool;

auto main() -> int {
    auto set = std::set<int>{1, 2, 3, 4, 5, 7, 8, 9};
    auto vec = std::vector<int>{7, 8, 9};

    auto result  = suffix(set, vec);

    fmt::print("{}", result);
}

auto suffix(std::set<int> const& set, std::vector<int> const& vec) -> bool {
    auto iterS = --set.end() ;
    auto iterV = --vec.end() ;

    for(iterV; iterV >= vec.begin(); --iterV) {

        // fmt::print("{}, {} \n", *iterV, *iterS);

        if(*iterV != *iterS) {
            return false;
        }else {
            --iterS;
        }
    }

    return true;
}