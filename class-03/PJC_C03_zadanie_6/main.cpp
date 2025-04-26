#include <iostream>
#include <fmt/ranges.h>

namespace pjc {
    namespace ranges {
        auto sort(std::vector<int> vec) -> std::vector<int> {
            auto changes = true;
            while(changes) {
                changes = false;
                auto index = 0;

                for(int i = 1; i < vec.size(); i++) {
                    if(vec[index] > vec[i]) {
                        auto tmp = vec[i];
                        vec[i] = vec[index];
                        vec[index] = tmp;

                        index = i;
                        changes = true;
                    }else {
                        index = i;
                    }
                }
            }
            return vec;
        }
        auto reverse(const std::vector<int> vec) -> std::vector<int> {
            auto res = std::vector<int>(vec.size());
            auto size = vec.size() - 1;

            for(auto element: vec) { res[size--] = element; }
            return res;
        }
    }
}

using namespace pjc::ranges;

auto main() -> int {
    auto vec1 = std::vector<int>{8, 9, 2, 3, 0, 3, 5, 10, 23, 5, 8};
    auto res1 = pjc::ranges::sort(vec1);
    fmt::println("{}", vec1);
    fmt::println("{}\n", res1);

    auto vec2 = std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto res2 = pjc::ranges::reverse(vec2);
    fmt::println("{}", vec2);
    fmt::println("{}", res2);
}
