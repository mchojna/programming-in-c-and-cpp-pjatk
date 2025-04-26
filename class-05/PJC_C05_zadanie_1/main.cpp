#include <iostream>
#include <fmt/ranges.h>
#include <map>
#include <set>
#include <string>

auto hasCycle(const std::string& current_node, std::map<std::string, std::set<std::string>>& graph, std::vector<std::string> visited) -> bool {
    auto iter = std::ranges::find(visited, current_node);

    if(iter != visited.end()) {
        return true;
    } else {
        visited.push_back(current_node);

        for(auto iter = graph[current_node].begin(); iter != graph[current_node].end(); ++iter) {
            if(hasCycle(*iter, graph, visited)) {
                return true;
            }
        }
    }
    return false;
}


auto main() -> int {
    auto graph = std::map<std::string, std::set<std::string>>();
    graph["A"] = {"B", "C"};
    graph["B"] = {"E"};
    graph["C"] = {"D"};
    graph["D"] = {"B"};
    graph["E"] = {"C"};

    // for (auto neighbor : graph["A"]) {
    //     fmt::println("{}", neighbor);
    // }

    fmt::println("{}", hasCycle((*graph.begin()).first ,graph, std::vector<std::string>()));
}