#include <iostream>
#include <utility>
#include <fmt/ranges.h>

struct Class {
    std::string name;
    auto static inline vector = std::vector<std::string>();

    Class(std::string const& name): name(name) {
        vector.push_back(name);
        // fmt::println("{} created", this->name);
    };
    Class(Class const& other): name(other.name) {
        vector.push_back(other.name);
        // fmt::println("{} copied", this->name);
    };
    auto operator=(const Class& other) -> Class& {
        auto it = std::find(vector.rbegin(), vector.rbegin(), this->name);
        if (it != vector.rend()) {
            vector.erase(std::next(it).base());
        }

        // fmt::println("{} reference", this->name);
        vector.push_back(other.name);
        if(this == &other) {
            return *this;
        }
        this->name = other.name;
        return *this;
    };
    ~Class() {
        auto it = std::find(vector.rbegin(), vector.rbegin(), this->name);
        if (it != vector.rend()) {
            vector.erase(std::next(it).base());
        }
        // fmt::println("{} deleted", this->name);
    };

    auto static printExtent() -> void {
        for(auto elem: vector) {
            fmt::print("{} ", elem);
        }
        fmt::println("");
    };
};

auto main() -> int {
    auto c1 = Class("c1");
    Class::printExtent();

    {
        auto c2 = Class("c2");
        Class::printExtent();
    }

    Class::printExtent();

    auto c3 = Class("c3");
    Class::printExtent();

    c3 = c1;
    Class::printExtent();

    {
        Class::printExtent();

        auto c4 = Class("c4");
        Class::printExtent();

        auto c5 = c4;
        Class::printExtent();
    }

    Class::printExtent();

    auto c6 = Class("c6");
    Class::printExtent();

    auto c7 = Class("c7");
}