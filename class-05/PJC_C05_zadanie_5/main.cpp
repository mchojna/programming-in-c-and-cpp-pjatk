#include <iostream>
#include <map>
#include <set>
#include <fmt/ranges.h>

auto largestAnagramGroupsFrom(std::string const& text) -> std::vector<std::set<std::string>> {
    auto anagrams = std::map<std::string, std::set<std::string>>();
    auto largest = 0;

    auto result = std::vector<std::set<std::string>>();

    auto word = std::string();

    for(auto const& c: text) {
        if(isalpha(c)) {
            word += tolower(c);
        } else {
            auto copy = word;
            std::ranges::sort(word);
            anagrams[word].insert(copy);

            if(anagrams[word].size() > largest) largest++;

            word = "";
        }
    }

    for(auto const& [key, value]: anagrams) {
        if(value.size() == largest) {
            result.push_back(value);
        }
    }

    return result;
}

auto main() -> int {
    auto text = std::string("In life, we find ourselves perplexed by twists and turns, and what comes next; we wonder where our path will lead and hope for guidance, in our need. But sometimes all we need to do is simply change our point of view, for 'listen' can become 'silent' too, and 'love' can turn into 'vole' anew. There’s 'evil' hiding in 'live' and 'cinema' in 'iceman' lives; to look for the positive, and let our hearts be lighter, but let’s focus on the good and be a little kinder. We can find 'heart' in 'earth' below and 'care' in 'race' - it’s apropos; 'strained' can be 'disrate,' and that’s okay, for tomorrow is a brand new day. So let’s embrace the twists and turns and all the lessons that life confirms, for every problem, there’s a clue, and an anagram to guide us through. For completeness, let’s add a few more, made-up, words: elov arce.");
    fmt::println("{}", largestAnagramGroupsFrom(text));
}