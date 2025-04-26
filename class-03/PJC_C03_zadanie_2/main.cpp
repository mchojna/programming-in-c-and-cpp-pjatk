#include <algorithm>
#include <string>
#include <vector>

#include <fmt/ranges.h>

auto main() -> int {
    auto fileNames1 = std::vector<std::string>{
        "lecture 1", "lecture 2", "lecture 3",
        "lecture 10", "lecture 11", "lecture 12",
        "lecture 35", "lecture 39", "lecture 92",
        "lecture 101", "lecture 111", "lecture 133",
        "lecture 159", "lecture 212", "lecture 221", "aaa", "zzz"
    };

    auto fileNames2 = std::vector<std::string>{
        "file1.txt", "file10.txt", "file11.txt",
        "file2.txt", "file20.txt", "file3.txt"
    };

    auto fileNames3 = std::vector<std::string>{
        "file1_part30.txt", "file10_part10.txt", "file10_part2.txt",
        "file2_part1.txt", "file20_part21.txt", "file3_part1.txt"
    };

    std::ranges::sort(fileNames3,
        [](const std::string& str1, const std::string& str2) -> bool {

        }
    );

    fmt::println("{}", fmt::join(fileNames3, "\n"));
}
