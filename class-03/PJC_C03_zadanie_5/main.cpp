#include <iostream>
#include <fmt/ranges.h>

auto example1(std::vector<std::string> left, std::vector<std::string> right) -> void {
    std::ranges::sort(left);
    auto duplicates = std::ranges::unique(left);
    left.erase(duplicates.begin(), duplicates.end());

    std::ranges::sort(right);
    duplicates = std::ranges::unique(right);
    right.erase(duplicates.begin(), duplicates.end());

    if (left.size() < right.size()) {
        for (auto i = 0; i < right.size(); i++) {
            for (auto j = 0; j < right.size() - 1 - i; j++) {
                // both start with a digit or both start with a letter
                if ((right[j].front() >= '0' and
                     right[j].front() <= '9' and
                     right[j + 1].front() >= '0' and
                     right[j + 1].front() <= '9')
                    or
                    ((right[j].front() < '0' or
                     right[j].front() > '9') and
                     (right[j + 1].front() < '0' or
                     right[j + 1].front() > '9'))) {
                    if (right[j] > right[j + 1]) {
                        std::ranges::swap(right[j], right[j + 1]);
                    }
                } else { // leading digits last
                    if (right[j].front() >= '0' and right[j].front() <= '9') {
                        std::ranges::swap(right[j], right[j + 1]);
                    }
                }
            }
        }
    } else {
        for (auto i = 0; i < left.size(); i++) {
            for (auto j = 0; j < left.size() - 1 - i; j++) {
                // both start with a digit or both start with a letter
                if ((left[j].front() >= '0' and
                     left[j].front() <= '9' and
                     left[j + 1].front() >= '0' and
                     left[j + 1].front() <= '9')
                    or
                    ((left[j].front() < '0' or
                      left[j].front() > '9') and
                     (left[j + 1].front() < '0' or
                      left[j + 1].front() > '9'))) {
                    if (left[j] > left[j + 1]) {
                        std::ranges::swap(left[j], left[j + 1]);
                    }
                } else { // leading digits last
                    if (left[j].front() >= '0' and left[j].front() <= '9') {
                        std::ranges::swap(left[j], left[j + 1]);
                    }
                }
            }
        }
    }

    fmt::println("[example 1]: {}, {}", left, right);
}

auto example2(std::vector<std::string> left, std::vector<std::string> right) -> void {

    auto remove_duplicates = [](std::vector<std::string>& str) -> void {
        std::ranges::sort(str);
        auto duplicates = std::ranges::unique(str);
        str.erase(duplicates.begin(), duplicates.end());
    };

    remove_duplicates(left);
    remove_duplicates(right);

    auto start_with_digit = [](std::vector<std::string> vec, int n) -> bool {
        return vec[n].front() >= '0' and vec[n].front() <= '9' and vec[n + 1].front() >= '0' and vec[n + 1].front() <= '9';
    };

    auto start_with_letter = [](std::vector<std::string> vec, int n) -> bool {
        return vec[n].front() < '0' and vec[n].front() > '9' and vec[n + 1].front() < '0' and vec[n + 1].front() > '9';
    };

    auto loop_and_swap = [start_with_digit, start_with_letter](std::vector<std::string>& vec) -> void {
        for (auto i = 0; i < vec.size(); i++) {
            for (auto j = 0; j < vec.size() - 1 - i; j++) {
                if (start_with_digit(vec, j) or start_with_letter(vec, j)) {
                    if (vec[j] > vec[j + 1]) {
                        std::ranges::swap(vec[j], vec[j + 1]);
                    }
                } else {
                    if (vec[j].front() >= '0' and vec[j].front() <= '9') {
                        std::ranges::swap(vec[j], vec[j + 1]);
                    }
                }
            }
        }
    };

    if (left.size() < right.size()) {
        loop_and_swap(right);
    } else {
        loop_and_swap(left);
    }

    fmt::println("[example 2]: {}, {}", left, right);
}

auto main() -> int {
    auto vec1 = std::vector<std::string>{"bbb", "1aaa", "ccc",  "aaa","aaa"};
    auto vec2 = std::vector<std::string>{"ddd", "ggg","eee", "2ddd","ddd", "jjj"};
    example1(vec1, vec2 );

    auto vec3 = std::vector<std::string>{"bbb", "1aaa", "ccc",  "aaa","aaa"};
    auto vec4 = std::vector<std::string>{"ddd", "ggg","eee", "2ddd","ddd", "jjj"};
    example2(vec3, vec4 );
}