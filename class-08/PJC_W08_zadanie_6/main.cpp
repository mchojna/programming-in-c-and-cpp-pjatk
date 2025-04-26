#include <iostream>
#include <fmt/ranges.h>
#include <fmt/format.h>
#include <fmt/color.h>

struct Text {
    std::string text;
    bool copy = false;
    bool overwrite = false;

    Text(std::string const& t): text(t) {};

    Text(Text const& t): text(t.text), copy(true) {};

    auto operator=(Text const& t) {
        text = t.text;
        overwrite = true;
    }

};

auto format_as(Text const& text) -> std::string {
    if(text.copy || text.overwrite) {
        return fmt::format("{}{}{}",
                "\"",
                fmt::styled(text.text, fmt::emphasis::italic),
                "\" - someone, somewhere"
            );
    } else {
        return text.text;
    }
}

auto main() -> int {
    {
        auto original = Text("hello!");
        auto copy     = original;

        fmt::println("{}", original);
        fmt::println("{}", copy);
    }

    std::cout << "\n";
    //...
    {
        auto original = Text("hello!");
        auto another  = Text("there!");

        fmt::println("{}", original);
        fmt::println("{}", another);

        another = original; // assignment

        fmt::println("{}", original);
        fmt::println("{}", another);
    }
}