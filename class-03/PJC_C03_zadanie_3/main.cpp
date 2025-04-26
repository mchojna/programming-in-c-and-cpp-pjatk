#include <iostream>
#include <vector>
#include <fmt/ranges.h>

namespace v1 {
    auto printLongestString(const std::vector<std::string>& vec) -> std::string {
        return std::ranges::max(vec);
    }
}

namespace v2 {
    auto printLongestString(const std::vector<std::string>& vec) -> std::string {
        return *std::ranges::max_element(vec);


    }
}

namespace v3 {
    auto printLongestString(const std::vector<std::string>& vec) -> std::string {
        return std::ranges::min(vec,
            std::ranges::greater());
    }
}

namespace v4 {
    auto printLongestString(const std::vector<std::string>& vec) -> std::string {
        return *std::ranges::min_element(vec,
            std::ranges::greater());
    }
}

using namespace v1;
using namespace v2;
using namespace v3;
using namespace v4;

int main()
{
    auto vec = std::vector<std::string>{"aaa", "bbb", "ccc", "ddd"};

    fmt::println("{}", v1::printLongestString(vec));
    fmt::println("{}", v2::printLongestString(vec));
    fmt::println("{}", v3::printLongestString(vec));
    fmt::println("{}", v4::printLongestString(vec));
}
