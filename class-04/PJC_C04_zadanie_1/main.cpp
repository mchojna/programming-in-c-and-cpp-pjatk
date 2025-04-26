#include <iostream>
#include <fmt/ranges.h>

namespace pjc {
    namespace ranges {
        template <std::ranges::range Container>
        auto sort(Container container) -> std::vector<int> {
            auto changes = true;
            while(changes) {
                changes = false;
                auto index = 0;

                for(int i = 1; i < container.size(); i++) {
                    if(container[index] > container[i]) {
                        auto tmp = container[i];
                        container[i] = container[index];
                        container[index] = tmp;

                        index = i;
                        changes = true;
                    }else {
                        index = i;
                    }
                }
            }
            return container;
        }
        template <std::ranges::range Container>
        auto reverse(Container container) -> std::vector<int> {
            auto res = std::vector<int>(container.size());
            auto size = container.size() - 1;

            for(auto element: container) { res[size--] = element; }
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
